//***************************************************************************
// Copyright 2007-2020 Universidade do Porto - Faculdade de Engenharia      *
// Laboratório de Sistemas e Tecnologia Subaquática (LSTS)                  *
//***************************************************************************
// This file is part of DUNE: Unified Navigation Environment.               *
//                                                                          *
// Commercial Licence Usage                                                 *
// Licencees holding valid commercial DUNE licences may use this file in    *
// accordance with the commercial licence agreement provided with the       *
// Software or, alternatively, in accordance with the terms contained in a  *
// written agreement between you and Faculdade de Engenharia da             *
// Universidade do Porto. For licensing terms, conditions, and further      *
// information contact lsts@fe.up.pt.                                       *
//                                                                          *
// Modified European Union Public Licence - EUPL v.1.1 Usage                *
// Alternatively, this file may be used under the terms of the Modified     *
// EUPL, Version 1.1 only (the "Licence"), appearing in the file LICENCE.md *
// included in the packaging of this file. You may not use this work        *
// except in compliance with the Licence. Unless required by applicable     *
// law or agreed to in writing, software distributed under the Licence is   *
// distributed on an "AS IS" basis, WITHOUT WARRANTIES OR CONDITIONS OF     *
// ANY KIND, either express or implied. See the Licence for the specific    *
// language governing permissions and limitations at                        *
// https://github.com/LSTS/dune/blob/master/LICENCE.md and                  *
// http://ec.europa.eu/idabc/eupl.html.                                     *
//***************************************************************************
// Author: Luis Venancio                                                    *
//***************************************************************************

#include <DUNE/Navigation/Localization.hpp>

namespace DUNE
{
  namespace Navigation
  {
    using Tasks::DF_KEEP_TIME;

    Localization::Localization(const std::string& name, Tasks::Context& ctx):
      Tasks::Periodic(name, ctx),
      m_accel_filter(WMAFilter<3>(c_wma_filter, m_data.accel)),
      m_agvel_filter(WMAFilter<3>(c_wma_filter, m_data.agvel)),
      m_depth_filter(WMAFilter<1>(c_wma_filter, m_data.depth)),
      m_euler_filter(WMAFilter<3>(c_wma_filter, m_data.euler))
    {
      param("Entity Labels", m_entity_labels)
      .size(NUM_DEV)
      .defaultValue("")
      .description("Entity Labels for localization messages");

      param("Entity Label - Altitude - Simulation", m_elabel_alt_sim)
      .defaultValue("")
      .description("Entity label for altitude device in simulation");

      param("Time Thresholds", m_time_thresh)
      .size(NUM_TIMER-1)
      .defaultValue("")
      .description("Timeouts for sensor devices");

      param("Distance Between DVL and CG", m_dist_dvl_cg)
      .units(Units::Meter)
      .defaultValue("0.3")
      .minimumValue("0.0")
      .description("Distance between DVL and vehicle Center of Gravity");

      param("Distance Between GPS and CG", m_dist_gps_cg)
      .units(Units::Meter)
      .defaultValue("0.28")
      .minimumValue("0.0")
      .description("Distance between GPS and vehicle Center of Gravity");

      param("DVL absolute thresholds", m_dvl_abs_thresh)
      .defaultValue("")
      .size(2)
      .description("DVL absolute thresholds");

      param("DVL relative thresholds", m_dvl_rel_thresh)
      .defaultValue("")
      .size(2)
      .description("DVL relative thresholds");

      param("DVL relative threshold time window", m_dvl_time_rel_thresh)
      .units(Units::Second)
      .defaultValue("1.0")
      .minimumValue("0.0")
      .description("DVL relative threshold time window to be applied");

      param("GPS Moving Average Samples", m_avg_gps_samples)
      .defaultValue("7")
      .minimumValue("5")
      .description("Number of moving average samples to smooth maximum GPS HACC.");

      param("Altitude Attitude Compensation", m_alt_attitude_compensation)
      .defaultValue("false")
      .description("Enable or disable attitude compensation for altitude");

      param("Altitude EMA gain", m_alt_ema_gain)
      .defaultValue("1.0")
      .description("Exponential moving average filter gain used in altitude");

      param("GPS Maximum HDOP", m_max_hdop)
      .defaultValue("5.0")
      .minimumValue("3.0")
      .maximumValue("10.0")
      .description("Maximum Horizontal Dilution of Precision value accepted for GPS fixes");

      param("GPS Maximum HACC", m_max_hacc)
      .defaultValue("14.0")
      .minimumValue("3.0")
      .maximumValue("100.0")
      .description("Maximum Horizontal Accuracy Estimate value accepted for GPS fixes");

      param("GPS Maximum Dynamic HACC factor", m_gps_hacc_factor)
      .defaultValue("2.0")
      .minimumValue("1.5")
      .maximumValue("10.0")
      .description("Maximum Horizontal Accuracy Estimate Moving Average factor");

      // Do not use the declination offset when simulating.
      m_use_declination = !m_ctx.profiles.isSelected("Simulation");
      m_declination_defined = false;
      
      // reset();

      // Timer setup
      // for (size_t i = 0; i < NUM_TIMER - 1; ++i)
      //   m_timer[i].setTop(m_args.time_thresh[i]);
    }

    void
    Localization::onResourceInitialization(void)
    {
      m_return = false;
      m_update_kalman = false;
      m_avg_gps = new Math::MovingAverage<double>(m_avg_gps_samples);
    }

    void
    Localization::onEntityResolution()
    {
      // Resolve entities.
      for (size_t i = 0; i < NUM_DEV-1; ++i)
      {
        try
        {
          m_entity_id[i] = resolveEntity(m_entity_labels[i]);
        }
        catch (...)
        {
          m_entity_id[i] = std::numeric_limits<unsigned>::max();
        }
      }

      // Set timers
      for (size_t i = 0; i < NUM_TIMER - 1; ++i)
        m_timer[i].setTop(m_time_thresh[i]);

      if (m_ctx.profiles.isSelected("Simulation"))
        m_entity_id[DEV_ALT] = resolveEntity(m_elabel_alt_sim);
    }

    void
    Localization::consume(const IMC::GpsFix* msg)
    {
      Concurrency::ScopedRWLock(m_data_lock, true);
      m_data.gps_hacc = -1.0;

      // GpsFix validation.
      m_gps_rej.reason = std::numeric_limits<uint8_t>::max();
      m_gps_rej.utc_time = msg->utc_time;
      m_gps_rej.setTimeStamp(msg->getTimeStamp());

      // Check fix validity.
      if ((msg->validity & IMC::GpsFix::GFV_VALID_POS) == 0)
      {
        m_gps_rej.reason = IMC::GpsFixRejection::RR_INVALID;
        dispatch(m_gps_rej, DF_KEEP_TIME);
        return;
      }

      double max_hacc = m_avg_gps->mean();
      m_avg_gps->update(msg->hacc);
      if (m_avg_gps->sampleSize() > 2 && msg->hacc > m_gps_hacc_factor * max_hacc)
      {
        m_gps_rej.reason = IMC::GpsFixRejection::RR_ABOVE_THRESHOLD;
        dispatch(m_gps_rej, DF_KEEP_TIME);
        return;
      }

      // Check if we have valid Horizontal Accuracy index.
      if (msg->validity & IMC::GpsFix::GFV_VALID_HACC)
      {
        // For updating kalman gps parameters
        m_data.gps_hacc = msg->hacc;

        // Check if it is above Maximum Horizontal Accuracy.
        if (msg->hacc > m_max_hacc)
        {
          m_gps_rej.reason = IMC::GpsFixRejection::RR_ABOVE_MAX_HACC;
          dispatch(m_gps_rej, DF_KEEP_TIME);
          return;
        }
      }
      else
      {
        // Horizontal Dilution of Precision.
        if (msg->hdop > m_max_hdop)
        {
          m_gps_rej.reason = IMC::GpsFixRejection::RR_ABOVE_MAX_HDOP;
          dispatch(m_gps_rej, DF_KEEP_TIME);
          return;
        }
      }

      // Speed over ground.
      if (msg->validity & IMC::GpsFix::GFV_VALID_SOG)
        m_data.gps_sog = msg->sog;

      // Check current declination value.
      checkDeclination(msg->lat, msg->lon, msg->height);

      m_data.gps_geo[GEO_LAT] = msg->lat;
      m_data.gps_geo[GEO_LON] = msg->lon;
      m_data.gps_geo[GEO_HEI] = msg->height;
    }
    
    void
    Localization::checkDeclination(double lat, double lon, double height)
    {
      if (!m_declination_defined && m_use_declination)
      {
        // Compute declination value
        // -- note: this is done only once, thus the short-lived wmm object
        Coordinates::WMM wmm(m_ctx.dir_cfg);
        m_declination = wmm.declination(lat, lon, height);
        m_declination_defined = true;
      }
    }

    double
    Localization::get(unsigned quant, unsigned ax)
    {
      Concurrency::ScopedRWLock(m_data_lock, false);
      switch (quant)
      {
        case QT_ACCELERATION:
          return m_data.accel[ax];
        case QT_ANGULAR_VELOCITY:
          return m_data.agvel[ax];
        case QT_DEPTH:
          return m_data.depth[0];
        case QT_DEPTH_OFFSET:
          return m_data.depth_offset;
        case QT_EULER_ANGLES:
          return m_data.euler[ax];
        case QT_GPS_GEO:
          return m_data.gps_geo[ax];
        case QT_GPS_SOG:
          return m_data.gps_sog;
        case QT_GPS_HACC:
          return m_data.gps_hacc;
        default:
          return -1;
      }

      return -1;
    }

      // bool
      // got(unsigned quant)
      // {
      //   switch (quant)
      //   {
      //   case QT_ACCELERATION:
      //     return m_accel_filter.gotReadings();
      //   case QT_ANGULAR_VELOCITY:
      //     return m_agvel_filter.gotReadings();
      //   case QT_DEPTH:
      //     return m_depth_filter.gotReadings();
      //   case QT_EULER_ANGLES:
      //     return m_euler_filter.gotReadings();
      //   default:
      //     return false;
      //   }

      //   return false;
      // }

      // void
      // reset()
      // {
      //   Concurrency::ScopedRWLock(m_data_lock, true);
      //   m_data.reset();
      // }

      // void
      // updateFilter(unsigned quant)
      // {
      //   Concurrency::ScopedRWLock(m_data_lock, true);
      //   switch (quant)
      //   {
      //     case QT_ACCELERATION:
      //       return m_accel_filter.update();
      //     case QT_ANGULAR_VELOCITY:
      //       return m_agvel_filter.update();
      //     case QT_DEPTH:
      //       return m_depth_filter.update();
      //     case QT_EULER_ANGLES:
      //       return m_depth_filter.update();
      //     default:
      //       return;
      //   }

      //   return;
      // }

      // void
      // updateAll()
      // {
      //   for (size_t i = 0; i < 4; ++i)
      //     updateFilter(i);
      // }
  }
}
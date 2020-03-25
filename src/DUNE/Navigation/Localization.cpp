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
      m_avg_gps(NULL)
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
      m_sane = true;

      m_dvl_val_bits = IMC::GroundVelocity::VAL_VEL_X
                        | IMC::GroundVelocity::VAL_VEL_Y
                        | IMC::GroundVelocity::VAL_VEL_Z;

      bind<IMC::Acceleration>(this);
      bind<IMC::AngularVelocity>(this);
      bind<IMC::DataSanity>(this);
      bind<IMC::Depth>(this);
      bind<IMC::DepthOffset>(this);
      bind<IMC::Distance>(this);
      bind<IMC::EulerAngles>(this);
      bind<IMC::EulerAnglesDelta>(this);
      bind<IMC::GpsFix>(this);
      bind<IMC::GroundVelocity>(this);
      bind<IMC::Rpm>(this);
      bind<IMC::UsblFixExtended>(this);
      bind<IMC::WaterVelocity>(this);
    }

    void
    Localization::onResourceInitialization(void)
    {
      reset();

      // Timer setup
      for (size_t i = 0; i < NUM_TIMER; ++i)
        m_timer[i].setTop(m_time_thresh[i]);

      m_avg_gps = new Math::MovingAverage<double>(m_avg_gps_samples);

      m_accel_filter = new WMAFilter<3>(c_wma_filter, m_data.accel);
      m_agvel_filter = new WMAFilter<3>(c_wma_filter, m_data.agvel);
      m_depth_filter = new WMAFilter<1>(c_wma_filter, m_data.depth);
      m_edelta_filter = new WMAFilter<3>(c_wma_filter, m_data.edelta);
      m_euler_filter = new WMAFilter<3>(c_wma_filter, m_data.euler);
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

      if (m_ctx.profiles.isSelected("Simulation"))
        m_entity_id[DEV_ALT] = resolveEntity(m_elabel_alt_sim);
    }

    void
    Localization::onResourceRelease()
    {
      Memory::clear(m_avg_gps);
      Memory::clear(m_accel_filter);
      Memory::clear(m_agvel_filter);
      Memory::clear(m_depth_filter);
      Memory::clear(m_edelta_filter);
      Memory::clear(m_euler_filter);
    }

    void
    Localization::consume(const IMC::Acceleration* msg)
    {
      if (msg->getSourceEntity() != m_entity_id[DEV_AHRS])
        return;

      if (std::fabs(msg->x) > c_max_accel ||
          std::fabs(msg->y) > c_max_accel ||
          std::fabs(msg->z) > c_max_accel)
      {
        err(DTR("received acceleration beyond range: %f, %f, %f"),
            msg->x, msg->y, msg->z);

        return;
      }

      Concurrency::ScopedRWLock(m_data_lock, true);
      m_accel_filter->add({msg->x, msg->y, msg->z});
    }

    void
    Localization::consume(const IMC::AngularVelocity* msg)
    {
      if (msg->getSourceEntity() != m_entity_id[DEV_AHRS])
        return;

      if (std::fabs(msg->x) > c_max_agvel ||
          std::fabs(msg->y) > c_max_agvel ||
          std::fabs(msg->z) > c_max_agvel)
      {
        war(DTR("received angular velocity beyond range: %f, %f, %f"),
            msg->x, msg->y, msg->z);

        return;
      }

      Concurrency::ScopedRWLock(m_data_lock, true);
      m_agvel_filter->add({msg->x, msg->y, msg->z});
    }

    void
    Localization::consume(const IMC::DataSanity* msg)
    {
      if (msg->getSourceEntity() != m_entity_id[DEV_DVL])
        return;

      if (msg->sane == IMC::DataSanity::DS_NOT_SANE)
      {
        m_timer[TM_SAN].reset();
        m_sane = false;
      }
      else
      {
        m_sane = true;
      }
    }

    void
    Localization::consume(const IMC::Depth* msg)
    {
      if (msg->getSourceEntity() != m_entity_id[DEV_DEPTH] && !m_timer[TM_MAIN_DEPTH].overflow())
        return;

      if (msg->getSourceEntity() == m_entity_id[DEV_DEPTH])
        m_timer[TM_MAIN_DEPTH].reset();

      Concurrency::ScopedRWLock(m_data_lock, true);
      m_depth_filter->add({msg->value + m_depth_offset});
      m_timer[TM_DEPTH].reset();
    }

    void
    Localization::consume(const IMC::DepthOffset* msg)
    {
      if (msg->getSourceEntity() != m_entity_id[DEV_DEPTH])
        return;

      m_depth_offset = msg->value;
    }

    void
    Localization::consume(const IMC::Distance* msg)
    {
      if (msg->getSourceEntity() != m_entity_id[DEV_ALT])
        return;

      if (msg->validity == IMC::Distance::DV_INVALID)
        return;

      // Reset altitude timer.
      m_timer[TM_ALT].reset();

      if (!m_sane)
        return;

      Concurrency::ScopedRWLock(m_data_lock, true);
      float value = msg->value;
      if (m_alt_attitude_compensation)
        value *= std::cos(m_data.euler[AXIS_X]) * std::cos(m_data.euler[AXIS_Y]);

      // Initialize altitude.
      if (m_data.altitude < 0.0)
        m_data.altitude = value;
      else
        // Exponential moving average.
        m_data.altitude += m_alt_ema_gain * (value - m_data.altitude);
    }

    void
    Localization::consume(const IMC::EulerAngles* msg)
    {
      if (msg->getSourceEntity() != m_entity_id[DEV_AHRS])
        return;

      if (std::fabs(msg->phi) > Math::c_pi ||
          std::fabs(msg->theta) > Math::c_pi ||
          std::fabs(msg->psi) > Math::c_pi)
      {
        war(DTR("received euler angles beyond range: %f, %f, %f"),
            msg->phi, msg->theta, msg->psi);
        return;
      }

      Concurrency::ScopedRWLock(m_data_lock, true);
      // Heading buffer maintains sign.
      double psi;
      psi = m_data.euler[AXIS_Z] + Math::Angles::minSignedAngle(m_data.euler[AXIS_Z], msg->psi);

      if (m_declination_defined && m_use_declination)
        psi += m_declination;

      m_euler_filter->add({msg->phi, msg->theta, psi});
      m_timer[TM_EULER].reset();
    }

    void
    Localization::consume(const IMC::EulerAnglesDelta* msg)
    {
      if (msg->getSourceEntity() != m_entity_id[DEV_IMU])
        return;

      if (std::fabs(msg->x) > Math::c_pi / 10.0 ||
          std::fabs(msg->y) > Math::c_pi / 10.0 ||
          std::fabs(msg->z) > Math::c_pi / 10.0)
      {
        war(DTR("received euler angles delta beyond range: %f, %f, %f"),
            msg->x, msg->y, msg->z);
        return;
      }

      Concurrency::ScopedRWLock(m_data_lock, true);
      m_edelta_filter->add({msg->x, msg->y, msg->z});
      m_data.edelta_ts = msg->timestep;
    }

    void
    Localization::consume(const IMC::GpsFix* msg)
    {
      Concurrency::ScopedRWLock(m_data_lock, true);

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
        m_data.gps.hacc = msg->hacc;

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
        m_data.gps.sog = msg->sog;

      // Check current declination value.
      checkDeclination(msg->lat, msg->lon, msg->height);

      m_data.gps.pos[GEO_LAT] = msg->lat;
      m_data.gps.pos[GEO_LON] = msg->lon;
      m_data.gps.pos[GEO_HEI] = msg->height;
    }

    void
    Localization::consume(const IMC::GroundVelocity* msg)
    {
      Concurrency::ScopedRWLock(m_data_lock, true);
      std::array<double, 2> new_pos;
      if (!validDVL(msg, new_pos))
        return;

      // Rever uso da valid flag vs timer
      m_timer[TM_DVL].reset();
      m_valid_gv = true;

      // Store accepted msg.
      m_data.gvel = new_pos;
    }

    void
    Localization::consume(const IMC::Rpm* msg)
    {
      Concurrency::ScopedRWLock(m_data_lock, true);
      m_data.rpm = msg->value;
    }

    void
    Localization::consume(const IMC::UsblFixExtended* msg)
    {
      if (msg->target != getSystemName())
        return;

      Concurrency::ScopedRWLock(m_data_lock, true);
      m_data.usbl[GEO_LAT] = msg->lat;
      m_data.usbl[GEO_LON] = msg->lon;
      m_data.usbl[GEO_HEI] = msg->z;
      m_data.usbl_acc = msg->accuracy;
    }

    void
    Localization::consume(const IMC::WaterVelocity* msg)
    {
      Concurrency::ScopedRWLock(m_data_lock, true);
      std::array<double, 2> new_pos;
      if (!validDVL(msg, new_pos))
        return;

      m_timer[TM_DVL].reset();
      m_valid_wv = true;

      // Store accepted msg.
      m_data.wvel = new_pos;
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

    bool
    Localization::validDVL(const IMC::Message* msg, std::array<double, 2>& new_pos)
    {
      // TODO: Declare these globally
      double tstep;
      std::array<double, 2> old_pos;

      if (msg->getId() == DUNE_IMC_GROUNDVELOCITY)
      {
        auto m = static_cast<const IMC::GroundVelocity*>(msg);
        if (m->validity != m_dvl_val_bits)
          return false;

        tstep = m_dvl_gv_tstep.getDelta();
        old_pos = m_data.gvel;
        new_pos = {m->x,
                   m->y - m_dist_dvl_cg * m_data.agvel[AXIS_Z]};
        m_dvl_rej.type = IMC::DvlRejection::TYPE_GV;
      }
      else if (msg->getId() == DUNE_IMC_WATERVELOCITY)
      {
        auto m = static_cast<const IMC::WaterVelocity*>(msg);
        if (m->validity != m_dvl_val_bits)
          return false;

        tstep = m_dvl_wv_tstep.getDelta();
        old_pos = m_data.wvel;       
        new_pos = {m->x,
                   m->y - m_dist_dvl_cg * m_data.agvel[AXIS_Z]};
        m_dvl_rej.type = IMC::DvlRejection::TYPE_WV;
      }
      else
      {
        return false;
      }

      m_dvl_rej.setTimeStamp(msg->getTimeStamp());

      // Check if we have a valid time delta.
      if ((tstep > 0) && (tstep < m_dvl_time_rel_thresh))
      {
        // Innovation threshold checking in the x-axis.
        if (std::abs(new_pos[AXIS_X] - old_pos[AXIS_X]) > m_dvl_rel_thresh[AXIS_X])
        {
          m_dvl_rej.reason = IMC::DvlRejection::RR_INNOV_THRESHOLD_X;
          m_dvl_rej.value = std::abs(new_pos[AXIS_X] - old_pos[AXIS_X]);
          m_dvl_rej.timestep = tstep;
          dispatch(m_dvl_rej, DF_KEEP_TIME);
          return false;
        }

        // Innovation threshold checking in the y-axis.
        if (std::abs(new_pos[AXIS_Y] - old_pos[AXIS_Y]) > m_dvl_rel_thresh[AXIS_Y])
        {
          m_dvl_rej.reason = IMC::DvlRejection::RR_INNOV_THRESHOLD_Y;
          m_dvl_rej.value = std::abs(new_pos[AXIS_Y] - old_pos[AXIS_Y]);
          m_dvl_rej.timestep = tstep;
          dispatch(m_dvl_rej, DF_KEEP_TIME);
          return false;
        }
      }

      // Absolute filter.
      if (std::abs(new_pos[AXIS_X]) > m_dvl_abs_thresh[AXIS_X])
      {
        m_dvl_rej.reason = IMC::DvlRejection::RR_ABS_THRESHOLD_X;
        m_dvl_rej.value = std::abs(new_pos[AXIS_X]);
        m_dvl_rej.timestep = 0.0;
        dispatch(m_dvl_rej, DF_KEEP_TIME);
        return false;
      }

      if (std::abs(new_pos[AXIS_Y]) > m_dvl_abs_thresh[AXIS_Y])
      {
        m_dvl_rej.reason = IMC::DvlRejection::RR_ABS_THRESHOLD_Y;
        m_dvl_rej.value = std::abs(new_pos[AXIS_Y]);
        m_dvl_rej.timestep = 0.0;
        dispatch(m_dvl_rej, DF_KEEP_TIME);
        return false;
      }

      return true;
    }

    double
    Localization::get(unsigned quant, unsigned ax)
    {
      Concurrency::ScopedRWLock(m_data_lock, false);
      switch (quant)
      {
        case QT_ACCEL:
          return m_data.accel[ax];
        case QT_AGVEL:
          return m_data.agvel[ax];

        //! Get vehicle altitude.
        //! Negative value denotes invalid estimate.
        //! @return altitude value.
        case QT_ALTITUDE:
          if (!m_sane)
          {
            if (m_timer[TM_SAN].overflow())
              m_data.altitude = -1.0;
            else
              m_data.altitude = 0.0;

            return m_data.altitude;
          }

          if (m_timer[TM_ALT].overflow())
            m_data.altitude = -1.0;

          return m_data.altitude;

        case QT_DEPTH:
          return m_data.depth[0];
        case QT_DEPTH_OFFSET:
          return m_data.depth_offset;
        case QT_EDELTA:
          return m_data.edelta[ax];
        case QT_EDELTA_TS:
          return m_data.edelta_ts;
        case QT_EULER:
          return m_data.euler[ax];
        case QT_GPS_POS:
          return m_data.gps.pos[ax];
        case QT_GPS_SOG:
          return m_data.gps.sog;
        case QT_GPS_HACC:
          return m_data.gps.hacc;
        case QT_GPS_HDOP:
          return m_data.gps.hdop;
        case QT_GRVEL:
          return m_data.gvel[ax];
        case QT_RPM:
          return m_data.rpm;
        case QT_WTVEL:
          return m_data.wvel[ax];
        default:
          return 0;
      }

      return 0;
    }

    bool
    Localization::got(unsigned quant)
    {
      switch (quant)
      {
      case QT_ACCEL:
        return m_accel_filter->gotReadings();
      case QT_AGVEL:
        return m_agvel_filter->gotReadings();
      case QT_DEPTH:
        return m_depth_filter->gotReadings();
      case QT_EDELTA:
        return m_edelta_filter->gotReadings();
      case QT_EULER:
        return m_euler_filter->gotReadings();
      default:
        return false;
      }

      return false;
    }

    bool
    Localization::gotReadings(unsigned quant)
    {
      switch (quant)
      {
      case QT_ACCEL:
        return m_accel_filter->got();
      case QT_AGVEL:
        return m_agvel_filter->got();
      case QT_DEPTH:
        return m_depth_filter->got();
      case QT_EDELTA:
        return m_edelta_filter->got();
      case QT_EULER:
        return m_euler_filter->got();
      default:
        return false;
      }

      return false;
    }

    void
    Localization::reset()
    {
      Concurrency::ScopedRWLock(m_data_lock, true);
      m_data.reset();
    }

    void
    Localization::resetFilters()
    {
      m_accel_filter->reset();
      m_agvel_filter->reset();
      m_depth_filter->reset();
      m_edelta_filter->reset();
      m_euler_filter->reset();
    }

    void
    Localization::updateFilter(unsigned quant)
    {
      Concurrency::ScopedRWLock(m_data_lock, true);
      switch (quant)
      {
        case QT_ACCEL:
          return m_accel_filter->update();
        case QT_AGVEL:
          return m_agvel_filter->update();
        case QT_DEPTH:
          return m_depth_filter->update();
        case QT_EDELTA:
          return m_edelta_filter->update();
        case QT_EULER:
          return m_euler_filter->update();
        default:
          return;
      }

      return;
    }

    void
    Localization::updateFilters()
    {
      for (size_t i = 0; i < 5; ++i)
        updateFilter(i);
    }
  }
}
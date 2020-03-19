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

#ifndef DUNE_NAVIGATION_LOCALIZATION_HPP_INCLUDED_
#define DUNE_NAVIGATION_LOCALIZATION_HPP_INCLUDED_

// ISO C++ 98 headers.
#include <cmath>
#include <limits>

// DUNE headers.
#include <DUNE/Coordinates/BodyFixedFrame.hpp>
#include <DUNE/Coordinates/WGS84.hpp>
#include <DUNE/Coordinates/WMM.hpp>
#include <DUNE/IMC/Definitions.hpp>
#include <DUNE/Memory.hpp>
#include <DUNE/Math/Angles.hpp>
#include <DUNE/Math/Derivative.hpp>
#include <DUNE/Math/MovingAverage.hpp>
#include <DUNE/Time/Clock.hpp>
#include <DUNE/Time/Counter.hpp>
#include <DUNE/Time/Delta.hpp>
#include <DUNE/Tasks/Periodic.hpp>
#include <DUNE/Tasks/Task.hpp>
#include <DUNE/Utils/String.hpp>

namespace DUNE
{
  namespace Navigation
  {
    // Export DLL Symbol.
    class DUNE_DLL_SYM Localization;

    //! Weighted Moving Average filter value
    static const float c_wma_filter = 0.1f;
    //! Maximum acceleration reading
    static const float c_max_accel = 30.0f;
    //! Maximum acceleration reading
    static const float c_max_agvel = Math::c_pi*5.0;
    //! Maximum euler angles
    static const float c_max_euler = Math::c_pi;
    //! Maximum euler angles delta 
    static const float c_max_edelta = Math::c_pi/10.0;

    //! Simple weighted moving average for specific use case
    //! Allows WMA in multiple values
    //! TODO: Derive from moving average class
    template<size_t N>
    class WMAFilter
    {
    public:
      WMAFilter(const float weight, std::array<double, N>& arr):
      m_value(arr),
      m_weight(weight)
      {
        reset();
      }

      //! Reset values and readings
      void
      reset()
      {
        m_value.fill(0.0);
        m_readings = 0.0;
      }

      //! Adds one, multi-value, reading
      void
      add(const std::array<double, N>& arr)
      {
        if (arr.size() != N)
          throw;

        for (size_t i = 0; i < N; ++i)
          m_value[i] = (m_value[i]*m_readings + arr[i])/(m_readings + 1);

        ++m_readings;
      }

      //! Update
      void
      update()
      {
        m_readings = m_weight;
      }

      bool
      gotReadings()
      {
        return m_readings > m_weight;
      }

      bool
      got()
      {
        return m_readings != 0.0;
      }

    private:
      std::array<double, N>& m_value;
      float m_weight;
      float m_readings;
    };

    //! Device axes.
    enum Axes
    {
      //! X-axis.
      AXIS_X = 0,
      //! Y-axis.
      AXIS_Y = 1,
      //! Z-axis.
      AXIS_Z = 2
    };

    enum Geo
    {
      //! Lat.
      GEO_LAT = 0,
      //! Lon.
      GEO_LON = 1,
      //! Height.
      GEO_HEI = 2
    };

    enum Quantity
    {
      QT_DEPTH = 0,
      QT_ACCEL,
      QT_AGVEL,
      QT_EULER,
      QT_EDELTA,
      QT_ALTITUDE,
      QT_DEPTH_OFFSET,
      QT_RPM,
      QT_GPS_POS,
      QT_GPS_GEO,
      QT_GPS_SOG,
      QT_GPS_HACC,
      QT_GPS_HDOP,
      QT_USBL,
      QT_GRVEL,
      QT_WTVEL,
      QT_SANITY,
      NUM_QUANT
    };

    enum Devices
    {
      DEV_AHRS = 0,
      DEV_DEPTH,
      DEV_DVL,
      DEV_ALT,
      DEV_IMU,
      NUM_DEV
    };

    enum Timers
    {
      TM_GPS = 0,
      TM_DVL,
      TM_ALT,
      TM_SAN,
      TM_MAIN_DEPTH,
      TM_DEPTH,
      TM_EULER,
      TM_EDELTA,
      NUM_TIMER
    };

    struct Data
    {
      //! Localization information
      std::array<double, 3> accel;
      std::array<double, 3> agvel;
      std::array<double, 3> euler;
      std::array<double, 3> edelta;
      double edelta_ts;

      std::array<double, 1> depth;
      double depth_offset;

      double altitude;
      double rpm;

      // GPS
      struct
      {
        std::array<double, 3> pos;
        std::array<double, 3> geo;
        double sog;
        double hacc;
        double hdop;
      }gps;

      std::array<double, 6> usbl;
      std::array<double, 2> gvel;
      std::array<double, 2> wvel;

      void
      reset()
      {
        accel.fill(0.0);
        agvel.fill(0.0);
        euler.fill(0.0);
        edelta.fill(0.0);
        depth.fill(0.0);

        edelta_ts = 0.0;
        depth_offset = 0.0;
        altitude = -1.0;
        rpm = 0.0;

        gps.pos.fill(0.0);
        gps.geo.fill(0.0);
        gps.sog = 0.0;
        gps.hacc = 0.0;
        gps.hdop = 0.0;
        usbl.fill(0.0);

        gvel.fill(0.0);
        wvel.fill(0.0);
      }
    };

    class Localization: public Tasks::Periodic
    {
    public:
      
      Localization(const std::string& name, Tasks::Context& ctx);

      ~Localization() = default;

      //! Initialize resources.
      virtual void
      onResourceInitialization();

      //! Resolve entities.
      virtual void
      onEntityResolution();

      //! Release allocated resources.
      virtual void
      onResourceRelease();

      virtual void
      consume(const IMC::Acceleration* msg);
      
      virtual void
      consume(const IMC::EulerAngles* msg);

      virtual void
      consume(const IMC::GpsFix* msg);

      double
      get(unsigned quant, unsigned ax = 0);
      
      bool
      got(unsigned quant);
    
      void
      reset();
      
      void
      updateFilter(unsigned quant);

      void
      updateAll();

      void
      resetAll();

      //! Routine to check current declination value using WMM.
      //! @param[in] lat vehicle current latitude.
      //! @param[in] lon vehicle current longitude.
      //! @param[in] height vehicle current height.
      void
      checkDeclination(double lat, double lon, double height);

    protected:
      //! Arguments
      //! Entity labels of localization devices
      std::vector<std::string> m_entity_labels;
      //! Entity label of altitude device in simulation
      std::string m_elabel_alt_sim;
      //! Entity id's of localization devices
      unsigned m_entity_id[NUM_DEV];
      //! Flag for attitude compensation in altitude readings
      bool m_alt_attitude_compensation;
      //! Flag for declination correction in AHRS readings
      bool m_use_declination;
      //! Exponential moving average filter gain used in altitude
      float m_alt_ema_gain;
      //! Distance between GPS and vehicle Center of Gravity
      float m_dist_gps_cg;
      //! Distance between DVL and vehicle Center of Gravity
      float m_dist_dvl_cg;
      //! DVL relative threshold time window to be applied
      float m_dvl_time_rel_thresh;
      //! DVL readings absolute thresholds
      std::vector<float> m_dvl_abs_thresh;
      //! DVL readings relative thresholds
      std::vector<float> m_dvl_rel_thresh;
      //! Device timeouts
      std::vector<float> m_time_thresh;      
      //! Number of samples to average GPS.
      unsigned m_avg_gps_samples;

      //! Timers
      Time::Counter<double> m_timer[NUM_TIMER];
      //! Declination value.
      float m_declination;
      //! Flag for declination defined
      bool m_declination_defined;

      //! GPS
      //! GPS rejection message
      IMC::GpsFixRejection m_gps_rej;
      //! Moving Average for GpsFix.
      Math::MovingAverage<double>* m_avg_gps;
      //! Maximum HACC Moving Average factor.
      float m_gps_hacc_factor;
      //! Maximum horizontal dilution of precision.
      float m_max_hdop;
      //! Maximum valid horizontal accuracy estimate.
      float m_max_hacc;

      //Return from func
      bool m_return;
      //Update kalman
      bool m_update_kalman;

    private:
      //! Data
      Data m_data;
      //! Altitutde sanity
      bool m_sane;
      //! Data read write lock
      Concurrency::RWLock m_data_lock;
      //! Filters
      WMAFilter<3> m_accel_filter;
      WMAFilter<3> m_agvel_filter;
      WMAFilter<1> m_depth_filter;
      WMAFilter<3> m_euler_filter;
    };
  }
}

#endif
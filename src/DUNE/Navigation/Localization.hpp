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

#include <DUNE/DUNE.hpp>

namespace DUNE
{
  namespace Navigation
  {
    //! Weighted Moving Average filter value.
    static const float c_wma_filter = 0.1f;

    //! Simple weighted moving average for specific use case
    //! Allows WMA in multiple values
    //! TODO: Derive from moving average class
    template<unsigned N>
    class WMAFilter
    {
    public:
      WMAFilter(const float a_weight):
      m_weight(a_weight)
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
      WMAFilter<N>&
      operator+=(const std::array<double, N>& arr)
      {
        if (arr.size() != N)
          throw;

        for (unsigned i = 0; i < N; ++i)
          m_value[i] += arr[i];

        ++m_readings;

        return *this;
      }

      //! Returns the average in the specified index
      double
      operator[](const unsigned index)
      {
        if (index >= N)
          throw;

        return m_readings ? (m_value[index]/m_readings) : 0.0;
      }

      //! Update
      void
      update()
      {
        for (unsigned i = 0; i < N; ++i)
            m_value[i] =  (*this)[i] * m_weight;

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
      std::array<double, N> m_value;
      float m_weight;
      float m_readings;
    };

      struct Arguments
      {
        //! Position process noise when tactical grade IMU is enabled.
        float pos_noise;
        //! LBL measurement noise when tactical grade IMU enabled.
        float lbl_noise;
        //! GPS measurement noise covariance values.
        std::vector<double> gps_noise;
        //! USBL measurement noise covariance value.
        double usbl_noise;
        //! IMU entity label.
        std::string elabel_imu;
        //! Number of samples to average forward speed.
        unsigned navg_speed;
        //! Revolutions to speed factor.
        float rpm_ini;
        //! Maximum revolutions to speed variation.
        float rpm_max;
        //! Heading bias uncertainty alignment threshold.
        double alignment_index;
        //! Heading alignment sensor diff threshold
        double alignment_diff;
        //! Diff threshold - buffer of values for threshold validation
        double heading_buffer_value;
        //! Abort if navigation exceeds maximum uncertainty.
        bool abort;
        //! Activate RPM to m/s estimation
        bool rpm_estimation;
        //!  Activate RPM to m/s % limit on estimation
        bool speed_relation_Limit;
        //!  Value RPM to m/s limit on estimation
        double speed_relation_limit_value;
        //!  Distance of Depth sensor to the veicle pitch rotation axis 
        float distance_depth_sensor;
      };

    class Localization
    {
    public:
      Localization():
      m_acceleration(WMAFilter<3>(c_wma_filter)),
      m_ang_velocity(WMAFilter<3>(c_wma_filter)),
      m_euler(WMAFilter<3>(c_wma_filter)),
      m_euler_delta(WMAFilter<3>(c_wma_filter)),
      m_depth(WMAFilter<1>(c_wma_filter))
      {
        reset();
      }

      ~Localization() = default;

      void
      reset()
      {
        m_acceleration.reset();
        m_ang_velocity.reset();
        m_euler.reset();
        m_euler_delta.reset();
        m_depth.reset();

        m_edelta_ts = 0.0;
        m_depth_offset = 0.0;
        m_altitude = -1.0;
        m_rpm = 0.0;
        m_gps_hacc = 0.0;

        m_gps = {0.0, 0.0, 0.0, 0.0, 0.0, 0.0};
        m_usbl = {0.0, 0.0, 0.0, 0.0, 0.0, 0.0};

        m_gnd_velocity = {0.0, 0.0};
        m_wtr_velocity = {0.0, 0.0};
      }

      WMAFilter<3> m_acceleration;
      WMAFilter<3> m_ang_velocity;
      WMAFilter<3> m_euler;
      WMAFilter<3> m_euler_delta;
      double m_edelta_ts;

      WMAFilter<1> m_depth;
      double m_depth_offset;

      double m_altitude;
      double m_rpm;

      std::array<double, 6> m_gps;
      double m_gps_hacc;

      std::array<double, 6> m_usbl;
      std::array<double, 2> m_gnd_velocity;
      std::array<double, 2> m_wtr_velocity;
    };
  }
}

#endif
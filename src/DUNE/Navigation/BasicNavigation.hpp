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
// Author: José Braga                                                       *
//***************************************************************************

#ifndef DUNE_NAVIGATION_BASIC_NAVIGATION_HPP_INCLUDED_
#define DUNE_NAVIGATION_BASIC_NAVIGATION_HPP_INCLUDED_

// DUNE headers.
#include <DUNE/Navigation/KalmanFilter.hpp>
#include <DUNE/Navigation/Ranging.hpp>
#include <DUNE/Navigation/StreamEstimator.hpp>
#include <DUNE/Navigation/Localization.hpp>

namespace DUNE
{
  namespace Navigation
  {
    // Export DLL Symbol.
    class DUNE_DLL_SYM BasicNavigation;

    //! Navigation task states.
    enum SMStates
    {
      //! Idle state.
      SM_STATE_IDLE,
      //! Booting state.
      SM_STATE_BOOT,
      //! Normal state.
      SM_STATE_NORMAL,
      //! Unsafe state.
      SM_STATE_UNSAFE
    };

    //! Navigation base filter states.
    enum StateIndexes
    {
      //! Vehicle north displacement (m).
      STATE_X = 0,
      //! Vehicle east displacement (m).
      STATE_Y = 1
    };

    //! Abstract base class for navigation tasks.
    //!
    //! This task is responsible to gather data from sensors and compute an estimate of
    //! the position of the system.
    //!
    //! The navigation filter uses sensor data from GPS, LBL, DVL, AHRS, IMU and
    //! Pressure sensor.
    //! The state of the system is computed by means of an extended Kalman Filter
    //! algorithm.
    //! The estimated state is stored in the EstimatedState IMC message. The filter
    //! estimates, when possible, the outside stream velocity and stores it in a
    //! EstimatedStreamVelocity IMC message. Some of the state covariance parameters
    //! are stored inside NavigationUncertainty IMC message.
    //!
    //! Some pre-filtering is done by rejecting GPS fixes and LBL ranges as well as
    //! applying a moving average filter to the altitude DVL measurements.
    class BasicNavigation: public Navigation::Localization
    {
    public:
      //! Constructor.
      //! @param[in] name name.
      //! @param[in] ctx context.
      BasicNavigation(const std::string& name, Tasks::Context& ctx);

      //! Destructor.
      virtual
      ~BasicNavigation(void);

      //! Update internal parameters.
      virtual void
      onUpdateParameters(void);

      //! Resolve entities.
      virtual void
      onEntityResolution(void);

      //! Initialize resources.
      virtual void
      onResourceInitialization(void);

      //! Release allocated resources.
      virtual void
      onResourceRelease(void);

      void
      consume(const IMC::GpsFix* msg);

      void
      consume(const IMC::LblConfig* msg);

      void
      consume(const IMC::LblRange* msg);

      void
      consume(const IMC::Rpm* msg);

      void
      consume(const IMC::UsblFixExtended* msg);

    protected:

      //! Get heading rate value.
      //! @return heading rate.
      inline double
      getHeadingRate(bool use_imu)
      {
        double pitch = get(QT_EULER, AXIS_Y);

        // Avoid division by zero.
        if (!std::cos(pitch))
          return 0;

        double roll = get(QT_EULER, AXIS_X);
        double p, q, r;

        if (use_imu)
        {
          if (!gotReadings(QT_EDELTA))
            return 0.0;

          // Make sure the following corresponds to angular velocity in all IMUs.
          p = get(QT_EDELTA, AXIS_X) / get(QT_EDELTA_TS);
          q = get(QT_EDELTA, AXIS_Y) / get(QT_EDELTA_TS);
          r = get(QT_EDELTA, AXIS_Z) / get(QT_EDELTA_TS);
        }
        else
        {
          p = get(QT_AGVEL, AXIS_X);
          q = get(QT_AGVEL, AXIS_Y);
          r = get(QT_AGVEL, AXIS_Z);
        }

        extractEarthRotation(p, q, r);

        return (std::sin(roll) * q + std::cos(roll) * r) / std::cos(pitch);
      }

      //! Get AHRS Entity Id.
      //! @return AHRS entity id.
      inline unsigned
      getAhrsId(void) const
      {
        return m_entity_id[DEV_AHRS];
      }

      //! Routine to compute LBL rejection value.
      //! @param[in] exp_range expected LBL range value.
      //! @return LBL rejection value.
      inline double
      getLblRejectionValue(double exp_range) const
      {
        return m_lbl_reject_constants[0] + m_lbl_reject_constants[1] * exp_range * exp_range;
      }

      //! This function checks if navigation must reject all lbl.
      //! @return true if LBL is to be rejected, false otherwise.
      inline bool
      rejectLbl(void) const
      {
        return m_reject_all_lbl;
      }

      //! Routine to get navigation time step.
      //! @return time step.
      inline double
      getTimeStep(void)
      {
        return m_delta.getDelta();
      }

      //! Routine to reset navigation.
      virtual void
      reset(void);

      //! Routine to setup navigation.
      virtual bool
      setup(void);

      //! Method invoked when LblConfig message is received.
      virtual void
      onConsumeLblConfig(void);

      //! Routine to update navigation filter parameters when a GpsFix message is received.
      //! @param[in] hacc GPS Sensor horizontal accuracy index.
      virtual void
      updateKalmanGpsParameters(double hacc);

      //! Routine to assign EKF filter output variables when a GpsFix message is received.
      //! @param[in] x vehicle north displacement (m).
      //! @param[in] y vehicle east displacement (m).
      virtual void
      runKalmanGPS(double x, double y);

      //! Routine to assign EKF filter output variables when a GpsFix message is received.
      //! @param[in] beacon beacon id.
      //! @param[in] range range to beacon.
      //! @param[in] dx distance along x-axis.
      //! @param[in] dy distance along y-axis.
      //! @param[in] exp_range expected range.
      virtual void
      runKalmanLBL(int beacon, float range, double dx, double dy, double exp_range);

      //! Routine to assign EKF filter output variables when a DVL velocity message is received.
      virtual void
      runKalmanDVL(void);

      //! Routine to assign EKF filter output variables when a UsblFixExtended message is received.
      //! @param[in] x vehicle north displacement (m).
      //! @param[in] y vehicle east displacement (m).
      virtual void
      runKalmanUSBL(double x, double y);

      //! Get EKF output matrix speed indexes.
      //! @param[out] u forward speed state index.
      //! @param[out] v transversal speed state index.
      virtual void
      getSpeedOutputStates(unsigned* u, unsigned* v) = 0;

      //! Get number of EKF outputs.
      //! @return number of outputs.
      virtual unsigned
      getNumberOutputs(void) = 0;

      //! Routine called to assign common dispatch messages.
      void
      onDispatchNavigation(void);

      //! Routine to check if navigation task is active.
      //! @return true if active, false otherwise.
      bool
      isActive(void);

      //! Routine to report navigation messages to the bus.
      void
      reportToBus(void);

      //! Routine to check navigation uncertainty.
      //! @param[in] abort abort if position uncertainty is exceeded.
      void
      checkUncertainty(bool abort = true);

      bool
      gpsDisable()
      {
        if (m_gps_disable)
          return true;

        if (m_gps_disable_aligned && m_aligned)
          return true;

        return false;
      }

      //! Kalman Filter matrices.
      Navigation::KalmanFilter m_kal;
      //! Ranging data.
      Navigation::Ranging m_ranging;
      //! Stream Estimator.
      Navigation::StreamEstimator m_stream_filter;
      //! Kalman Filter process noise covariance matrix parameters.
      std::vector<double> m_process_noise;
      //! Kalman Filter measurement noise covariance matrix parameters.
      std::vector<double> m_measure_noise;
      //! Kalman Filter state covariance matrix parameters.
      std::vector<double> m_state_cov;
      //! Estimated state message.
      IMC::EstimatedState m_estate;
      //! LBL range acceptance.
      IMC::LblRangeAcceptance m_lbl_ac;
      //! Navigation Uncertainty log.
      IMC::NavigationUncertainty m_uncertainty;
      //! Navigation Data log.
      IMC::NavigationData m_navdata;
      //! Vertical displacement in the NED frame to the origin height above ellipsoid
      double m_last_z;
      //! Dead reckoning mode.
      bool m_dead_reckoning;
      //! Vehicle is aligned.
      bool m_aligned;
      //! LBL threshold.
      float m_lbl_threshold;
      //! Heading value (rad).
      double m_heading;
      //! Heading value of IMU (rad).
      double m_heading_imu;
      //! Received LBL fix.
      bool m_lbl_reading;
      //! Derivative for heave.
      Math::Derivative<double> m_deriv_heave;

      //! GPS disable for debug
      bool m_gps_disable;
      //! Disable GPS when aligned
      bool m_gps_disable_aligned;

    private:
      //! Routine to filter earth rotation effect from angular velocity values.
      //! @param[out] p angular velocity along the x-axis.
      //! @param[out] q angular velocity along the y-axis.
      //! @param[out] r angular velocity along the z-axis.
      void
      extractEarthRotation(double& p, double& q, double& r);

      //! Routine to start navigation
      //! @param[in] msg GpsFix IMC message
      void
      startNavigation(const IMC::GpsFix* msg);

      //! Routine to correct LBL positions. This method must be invoked whenever
      //! a new navigation reference is created to correct transducers positions.
      void
      correctLBL(void);

      //! True if this task is active.
      bool m_active;
      //! Task state machine.
      SMStates m_navstate;
      //! Time step delta.
      Time::Delta m_delta;
      //! Maximum distance to reference.
      float m_max_dis2ref;
      //! Horizontal position variance threshold value.
      float m_max_hpos_var;
      //! Navigation Startup point.
      IMC::GpsFix* m_origin;
      //! Displacement between LBL and GPS.
      float m_dist_lbl_gps;
      //! Always reject LblRanges.
      bool m_reject_all_lbl;
      //! Use a Depth sensor.
      bool m_depth_sensor;
      //! LBL rejection constants.
      std::vector<float> m_lbl_reject_constants;
      //! Moving Average for heave.
      Math::MovingAverage<double>* m_avg_heave;
      //! Number of samples to average heave.
      unsigned m_avg_heave_samples;
    };
  }
}

#endif

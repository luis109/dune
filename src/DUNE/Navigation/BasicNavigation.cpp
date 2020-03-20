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
// Author: Pedro Calado (Altitude filter)                                   *
//***************************************************************************

// Local headers.
#include <DUNE/Navigation/BasicNavigation.hpp>

namespace DUNE
{
  namespace Navigation
  {
    using Tasks::DF_KEEP_TIME;

    static std::string
    getUncertaintyMessage(double hpos_var)
    {
      using Utils::String;
      return String::str(DTR("position uncertainty is %0.2f m"),
                         std::sqrt(hpos_var));
    }

    BasicNavigation::BasicNavigation(const std::string& name, Tasks::Context& ctx):
      Navigation::Localization(name, ctx),
      m_active(false),
      m_origin(NULL),
      m_avg_heave(NULL)
    {
      // Declare configuration parameters.
      param("Maximum Distance to Reference", m_max_dis2ref)
      .units(Units::Meter)
      .defaultValue("1000")
      .minimumValue("500")
      .description("Maximum allowed distance to 'EstimatedState' reference");

      param(DTR_RT("Maximum Horizontal Position Variance"), m_max_hpos_var)
      .visibility(Tasks::Parameter::VISIBILITY_USER)
      .units(Units::SquareMeter)
      .defaultValue("500.0")
      .minimumValue("100.0")
      .description("Maximum allowed horizontal position estimation variance");

      param("Reject all LBL ranges", m_reject_all_lbl)
      .defaultValue("false")
      .description("Boolean variable that defines if vehicle rejects all LblRanges");

      param("LBL Expected Range Rejection Constants", m_lbl_reject_constants)
      .defaultValue("")
      .size(2)
      .description("Constants used in current LBL rejection scheme");

      param("Disable GPS for debug", m_gps_disable)
      .defaultValue("false")
      .description("Disable GPS for debug");

      param("Depth Sensor", m_depth_sensor)
      .defaultValue("true")
      .description("This variable signals that a depth sensor device is installed on system");

      param("Distance Between LBL and GPS", m_dist_lbl_gps)
      .units(Units::Meter)
      .defaultValue("0.50")
      .minimumValue("0.0")
      .description("Distance between LBL receiver and GPS in the vehicle");

      param("LBL Threshold", m_lbl_threshold)
      .defaultValue("4.0")
      .minimumValue("2.0")
      .description("LBL Threshold value for the LBL level check rejection scheme");

      param("Heave Moving Average Samples", m_avg_heave_samples)
      .defaultValue("40")
      .minimumValue("10")
      .description("Number of moving average samples to smooth heave");

      m_dead_reckoning = false;
      m_aligned = false;
      m_rpm = 0;
      m_lbl_reading = false;

      // Register callbacks.
      bind<IMC::LblConfig>(this);
      bind<IMC::LblRange>(this);
      bind<IMC::Rpm>(this);
      bind<IMC::UsblFixExtended>(this);
    }

    BasicNavigation::~BasicNavigation(void)
    { }

    void
    BasicNavigation::onUpdateParameters(void)
    {
      // Distance DVL to vehicle Center of Gravity is 0 in Simulation.
      if (m_ctx.profiles.isSelected("Simulation"))
      {
        m_dist_dvl_cg = 0.0;
        m_dist_lbl_gps = 0.0;
      }
    }

    void
    BasicNavigation::onResourceInitialization()
    {
      Localization::onResourceInitialization();
      m_avg_heave = new Math::MovingAverage<double>(m_avg_heave_samples);
      reset();
    }

    void
    BasicNavigation::onEntityResolution()
    { 
      Localization::onEntityResolution();
    }

    void
    BasicNavigation::onResourceRelease()
    {
      Localization::onResourceRelease();
      Memory::clear(m_origin);
      Memory::clear(m_avg_heave);
    }

    void
    BasicNavigation::consume(const IMC::GpsFix* msg)
    {
      if (m_gps_disable == true)
        return;

      if (msg->type == IMC::GpsFix::GFT_MANUAL_INPUT)
        return;

      Localization::consume(msg);
      
      if (m_gps_rej.reason == std::numeric_limits<uint8_t>::max())
      {
        if (msg->validity & IMC::GpsFix::GFV_VALID_HACC)
          updateKalmanGpsParameters(get(QT_GPS_HACC));
      }
      else
      {
        if (m_gps_rej.reason == IMC::GpsFixRejection::RR_ABOVE_MAX_HACC)
          updateKalmanGpsParameters(get(QT_GPS_HACC));
        
        return;
      }

      // Start navigation if filter not active.
      if (!m_active)
      {
        // Navigation self-initialisation.
        startNavigation(msg);
        return;
      }

      // Not sure about altitude.
      double x = 0.0;
      double y = 0.0;
      Coordinates::WGS84::displacement(m_origin->lat, m_origin->lon, m_origin->height,
                                       msg->lat, msg->lon, msg->height,
                                       &x, &y, &m_last_z);

      // Stream Estimator.
      IMC::EstimatedStreamVelocity stream;
      if (m_stream_filter.consume(m_estate, msg, stream))
        dispatch(stream);

      // Correct for roll angle.
      y += std::sin(get(QT_EULER, AXIS_X)) * m_dist_gps_cg;

      // Check distance to current LLH origin.
      if (Math::norm(x, y) > m_max_dis2ref)
      {
        // Redefine origin.
        Memory::replace(m_origin, new IMC::GpsFix(*msg));

        // Recalculate LBL positions.
        m_ranging.updateOrigin(msg);

        // Save message to cache.
        IMC::CacheControl cop;
        cop.op = IMC::CacheControl::COP_STORE;
        cop.message.set(*msg);
        dispatch(cop);

        // Save reference in EstimatedState message.
        m_estate.lat = msg->lat;
        m_estate.lon = msg->lon;
        m_estate.height = msg->height;

        // Set position estimate at the origin.
        m_kal.setState(STATE_X, 0);
        m_kal.setState(STATE_Y, 0);

        spew("defined new navigation reference");
        return;
      }

      // Call GPS EKF functions to assign output values.
      runKalmanGPS(x, y);
    }

    void
    BasicNavigation::consume(const IMC::LblConfig* msg)
    {
      if (msg->op != IMC::LblConfig::OP_SET_CFG)
          return;

      // Save message to cache.
      IMC::CacheControl cop;
      cop.op = IMC::CacheControl::COP_STORE;
      cop.message.set(*msg);
      dispatch(cop);

      m_ranging.setup(msg);

      onConsumeLblConfig();
    }

    void
    BasicNavigation::consume(const IMC::LblRange* msg)
    {
      if (!m_active)
        return;

      // LBL range validation.
      m_lbl_ac.id = msg->id;
      m_lbl_ac.range = msg->range;
      m_lbl_ac.setTimeStamp(msg->getTimeStamp());

      // Get beacon position.
      uint8_t beacon = msg->id;
      float range = msg->range;

      if (!m_ranging.exists(beacon) || (beacon > m_ranging.getSize() - 1) || (rejectLbl()))
      {
        m_lbl_ac.acceptance = IMC::LblRangeAcceptance::RR_NO_INFO;
        dispatch(m_lbl_ac, DF_KEEP_TIME);
        return;
      }

      // Reject LBL ranges when GPS is available.
      if (!m_timer[TM_GPS].overflow())
      {
        m_lbl_ac.acceptance = IMC::LblRangeAcceptance::RR_AT_SURFACE;
        dispatch(m_lbl_ac, DF_KEEP_TIME);
        return;
      }

      double x = 0.0;
      double y = 0.0;
      double z = 0.0;

      m_ranging.getLocation(beacon, &x, &y, &z);

      // Compute expected range.
      double dx = m_kal.getState(STATE_X) + m_dist_lbl_gps * std::cos(get(QT_EULER, AXIS_Z)) - x;
      double dy = m_kal.getState(STATE_Y) + m_dist_lbl_gps * std::sin(get(QT_EULER, AXIS_Z)) - y;
      double dz = get(QT_DEPTH) - z;
      double exp_range = std::sqrt(dx * dx + dy * dy + dz * dz);

      runKalmanLBL((int)beacon, range, dx, dy, exp_range);
    }

    void
    BasicNavigation::consume(const IMC::Rpm* msg)
    {
      m_rpm = msg->value;
      m_stream_filter.consume(msg);
    }

    void
    BasicNavigation::consume(const IMC::UsblFixExtended* msg)
    {
      if (msg->target != getSystemName())
        return;

      double x = 0.0;
      double y = 0.0;
      Coordinates::WGS84::displacement(m_origin->lat, m_origin->lon, 0.0,
                                       msg->lat, msg->lon, 0.0,
                                       &x, &y);

      runKalmanUSBL(x, y);
    }

    void
    BasicNavigation::startNavigation(const IMC::GpsFix* msg)
    {
      Memory::replace(m_origin, new IMC::GpsFix(*msg));

      // Save message to cache.
      IMC::CacheControl cop;
      cop.op = IMC::CacheControl::COP_STORE;
      cop.message.set(*msg);
      dispatch(cop);

      m_active = setup();

      m_navstate = SM_STATE_BOOT;
      setEntityState(IMC::EntityState::ESTA_BOOT, Status::CODE_WAIT_CONVERGE);
    }

    void
    BasicNavigation::reset(void)
    {
      m_last_z = 0.0;

      m_heading = 0.0;
      resetAltitude();

      m_navstate = SM_STATE_IDLE;
      setEntityState(IMC::EntityState::ESTA_BOOT, Status::CODE_WAIT_GPS_FIX);

      m_valid_gv = false;
      m_valid_wv = false;

      resetFilters();
    }

    bool
    BasicNavigation::setup(void)
    {
      reset();

      if (m_origin == NULL)
        return false;

      m_estate.lat = m_origin->lat;
      m_estate.lon = m_origin->lon;
      m_estate.height = m_origin->height;

      // Set position of the vehicle at the origin and reset filter state.
      m_kal.resetState();

      // Possibly correct LBL locations.
      m_ranging.updateOrigin(m_origin);

      spew("setup completed");
      return true;
    }

    void
    BasicNavigation::onConsumeLblConfig(void)
    {
      // do nothing.
    }

    void
    BasicNavigation::updateKalmanGpsParameters(double hacc)
    {
      (void) hacc;
    }

    void
    BasicNavigation::runKalmanGPS(double x, double y)
    {
      // do nothing.
      (void)x;
      (void)y;
    }

    void
    BasicNavigation::runKalmanLBL(int beacon, float range, double dx, double dy, double exp_range)
    {
      // "Outlier Rejection for Autonomous Acoustic Navigation"
      // Jerome Vaganay, John J. Leonard and James G. Bellingham. MIT
      Math::Matrix H(1, 2, 0.0);
      H(0, 0) = dx / exp_range;
      H(0, 1) = dy / exp_range;
      Math::Matrix P(2, 2, 0.0);
      P = m_kal.getCovariance(STATE_X, STATE_Y, STATE_X, STATE_Y);

      double k = getLblRejectionValue(exp_range);
      double R = std::max(k, (H * P * transpose (H))(0));

      double d = range - exp_range;
      m_navdata.lbl_rej_level = (d * (1 / ((H * P * transpose (H))(0) + R)) * d);

      // Is rejection level above maximum threshold?
      if (m_navdata.lbl_rej_level >= m_lbl_threshold)
      {
        m_lbl_ac.acceptance = IMC::LblRangeAcceptance::RR_ABOVE_THRESHOLD;
        dispatch(m_lbl_ac, DF_KEEP_TIME);
        return;
      }
      else
      {
        unsigned index = getNumberOutputs() + beacon;

        // Define measurements matrix.
        m_kal.setObservation(index, STATE_X, dx / exp_range);
        m_kal.setObservation(index, STATE_Y, dy / exp_range);

        // Define Output matrix.
        m_kal.setOutput(index, range);
        m_kal.setInnovation(index, range - exp_range);
        m_lbl_ac.acceptance = IMC::LblRangeAcceptance::RR_ACCEPTED;
        dispatch(m_lbl_ac, DF_KEEP_TIME);
        m_lbl_reading = true;
      }
    }

    void
    BasicNavigation::runKalmanDVL(void)
    {
      // Use Ground Velocity messages if they are valid.
      // Water Velocity messages otherwise.
      unsigned u;
      unsigned v;

      getSpeedOutputStates(&u, &v);

      if (m_valid_gv)
      {
        m_kal.setOutput(u, get(QT_GRVEL, AXIS_X));
        m_kal.setOutput(v, get(QT_GRVEL, AXIS_Y));
      }
      else if (m_valid_wv)
      {
        m_kal.setOutput(u, get(QT_WTVEL, AXIS_X));
        m_kal.setOutput(v, get(QT_WTVEL, AXIS_Y));
      }
    }

    void
    BasicNavigation::runKalmanUSBL(double x, double y)
    {
      // do nothing.
      (void)x;
      (void)y;
    }

    void
    BasicNavigation::onDispatchNavigation(void)
    {
      m_estate.x = m_kal.getState(STATE_X);
      m_estate.y = m_kal.getState(STATE_Y);
      m_estate.z = m_last_z + get(QT_DEPTH);
      m_estate.phi = Math::Angles::normalizeRadian(get(QT_EULER, AXIS_X));
      m_estate.theta = Math::Angles::normalizeRadian(get(QT_EULER, AXIS_Y));
      m_estate.p = get(QT_AGVEL, AXIS_X);
      m_estate.q = get(QT_AGVEL, AXIS_Y);
      m_estate.alt = get(QT_ALTITUDE);
      m_estate.depth = get(QT_DEPTH);
      m_estate.w = m_avg_heave->update(m_deriv_heave.update(m_estate.depth));

      // Velocity in the navigation frame.
      Coordinates::BodyFixedFrame::toInertialFrame(m_estate.phi, m_estate.theta, m_estate.psi,
                                                   m_estate.u, m_estate.v, m_estate.w,
                                                   &m_estate.vx, &m_estate.vy, &m_estate.vz);

      m_uncertainty.x = m_kal.getCovariance(STATE_X, STATE_X);
      m_uncertainty.y = m_kal.getCovariance(STATE_Y, STATE_Y);
      m_navdata.cyaw = m_heading;
    }

    bool
    BasicNavigation::isActive(void)
    {
      if (m_active)
        return true;

      if (got(QT_EULER))
      {
        IMC::EstimatedState estate;
        estate.lat = get(QT_GPS_GEO, GEO_LAT);
        estate.lon = get(QT_GPS_GEO, GEO_LON);
        estate.height = get(QT_GPS_GEO, GEO_HEI);
        estate.phi = Math::Angles::normalizeRadian(get(QT_EULER, AXIS_X));
        estate.theta = Math::Angles::normalizeRadian(get(QT_EULER, AXIS_Y));
        estate.psi = Math::Angles::normalizeRadian(get(QT_EULER, AXIS_Z));
        estate.depth = get(QT_DEPTH);
        estate.alt = get(QT_ALTITUDE);
        m_heading = estate.psi;
        updateFilter(QT_EULER);
        updateFilter(QT_DEPTH);

        if (got(QT_AGVEL))
        {
          m_estate.p = get(QT_AGVEL, AXIS_X);
          m_estate.q = get(QT_AGVEL, AXIS_Y);
          m_estate.r = get(QT_AGVEL, AXIS_Z);
          updateFilter(QT_AGVEL);
        }

        dispatch(estate);
      }

      return false;
    }

    void
    BasicNavigation::reportToBus(void)
    {
      double tstamp = Time::Clock::getSinceEpoch();
      m_estate.setTimeStamp(tstamp);
      m_uncertainty.setTimeStamp(tstamp);
      m_navdata.setTimeStamp(tstamp);

      dispatch(m_estate, DF_KEEP_TIME);
      dispatch(m_uncertainty, DF_KEEP_TIME);
      dispatch(m_navdata, DF_KEEP_TIME);
    }

    void
    BasicNavigation::checkUncertainty(bool abort)
    {
      // Compute maximum horizontal position variance value.
      float hpos_var = std::max(m_kal.getCovariance(STATE_X, STATE_X), m_kal.getCovariance(STATE_Y, STATE_Y));

      // Check if it exceeds the specified threshold value.
      if (hpos_var > m_max_hpos_var)
      {
        switch (m_navstate)
        {
          case SM_STATE_BOOT:
            // do nothing
            break;
          case SM_STATE_NORMAL:
            if (abort)
            {
              setEntityState(IMC::EntityState::ESTA_ERROR, getUncertaintyMessage(hpos_var));
              m_navstate = SM_STATE_UNSAFE; // Change state
            }
            break;
          case SM_STATE_UNSAFE:
            // do nothing;
            break;
          default:
            spew("caught unexpected navigation state transition");
            break;
        }
      }
      else
      {
        switch (m_navstate)
        {
          case SM_STATE_BOOT:
            setEntityState(IMC::EntityState::ESTA_NORMAL, Status::CODE_ACTIVE);
            break;
          case SM_STATE_NORMAL:
            if (m_depth_sensor && m_timer[TM_DEPTH].overflow())
            {
              setEntityState(IMC::EntityState::ESTA_ERROR, Utils::String::str(DTR("no measurements available: %s"), DTR("Depth")));
              return;
            }

            if (m_timer[TM_EULER].overflow())
            {
              setEntityState(IMC::EntityState::ESTA_ERROR, Utils::String::str(DTR("no measurements available: %s"), DTR("Euler Angles")));
              return;
            }

            if (m_dead_reckoning)
            {
              if (m_aligned)
                setEntityState(IMC::EntityState::ESTA_NORMAL, Status::CODE_ALIGNED);
              else
                setEntityState(IMC::EntityState::ESTA_NORMAL, Status::CODE_NOT_ALIGNED);
            }
            else
            {
              setEntityState(IMC::EntityState::ESTA_NORMAL, Status::CODE_ACTIVE);
            }
            break;
          case SM_STATE_UNSAFE:
            setEntityState(IMC::EntityState::ESTA_NORMAL, Status::CODE_ACTIVE);
            break;
          default:
            spew("caught unexpected navigation state transition");
            break;
        }
        m_navstate = SM_STATE_NORMAL;
      }
    }

    void
    BasicNavigation::extractEarthRotation(double& p, double& q, double& r)
    {
      // Insert euler angles into row matrix.
      Math::Matrix ea(3,1);
      ea(0) = Math::Angles::normalizeRadian(get(QT_EULER, AXIS_X));
      ea(1) = Math::Angles::normalizeRadian(get(QT_EULER, AXIS_Y));
      ea(2) = Math::Angles::normalizeRadian(get(QT_EULER, AXIS_Z));

      // Earth rotation vector.
      Math::Matrix we(3,1);
      we(0) = Math::c_earth_rotation * std::cos(get(QT_GPS_GEO, GEO_LAT));
      we(1) = 0.0;
      we(2) = - Math::c_earth_rotation * std::sin(get(QT_GPS_GEO, GEO_LAT));

      // Sensed angular velocities due to Earth rotation effect.
      Math::Matrix av(3,1);
      av = transpose(ea.toDCM()) * we;

      // Extract from angular velocities measurements.
      p -= av(0);
      q -= av(1);
      r -= av(2);
    }
  }
}

//***************************************************************************
// Copyright 2007-2023 Universidade do Porto - Faculdade de Engenharia      *
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
// Author: Luis Venâncio                                                    *
//***************************************************************************

#include <DUNE/Coordinates.hpp>
#include <DUNE/Maneuvers/SwarmLeader.hpp>

namespace DUNE
{
  namespace Maneuvers
  {
    using namespace DUNE::IMC;

    SwarmLeader::SwarmLeader(const std::string& name, Tasks::Context& ctx):
      Maneuver(name, ctx)
    {
      bindToManeuver<SwarmLeader, IMC::VehicleFormation>();
      bind<IMC::EstimatedState>(this, true);
    }

    SwarmLeader::~SwarmLeader(void)
    { }

    void
    SwarmLeader::onUpdateParameters(void)
    {
      
    }

    bool
    SwarmLeader::initParticipants(const IMC::VehicleFormation* maneuver)
    {
      int idx = 0;
      int local_addr = getSystemId();

      inf(DTR("parsing vehicle participants"));

      const IMC::MessageList<IMC::VehicleFormationParticipant>* list = &maneuver->participants;

      IMC::MessageList<IMC::VehicleFormationParticipant>::const_iterator itr;
      for(itr = list->begin(); itr != list->end(); itr++)
      {
        try
        {
          inf("%s", resolveSystemId((*itr)->vid));
        }
        catch (...)
        {
          signalError(DTR("invalid formation participant"));
          return false;
        }

        Participant p;
        p.vid = (*itr)->vid;
        p.x = (*itr)->off_x;
        p.y = (*itr)->off_y;
        p.z = (*itr)->off_z;

        m_participants.push_back(p);

        if (m_addr2idx.find(p.vid) != m_addr2idx.end())
        {
          signalError(DTR("repeated vehicles in participant list"));
          return false;
        }

        if (p.vid == local_addr)
        {
          signalError(DTR("leader vehicle in participant list"));
          return false;
        }

        m_addr2idx[p.vid] = idx;
        ++idx;
      }

      if (m_participants.size() < 1)
      {
        signalError(DTR("not enough vehicles in formation (at least 1 is required)"));
        return false;
      }

      return true;
    }

    bool
    SwarmLeader::initTrajectory(const IMC::VehicleFormation* maneuver)
    {
      TPoint begin;

      toLocalCoordinates(maneuver->lat, maneuver->lon, &begin.x, &begin.y);
      begin.z = maneuver->z;
      begin.t = 0;

      const IMC::MessageList<IMC::TrajectoryPoint>* list = &maneuver->points;

      IMC::MessageList<IMC::TrajectoryPoint>::const_iterator itr;

      for(itr = list->begin(); itr != list->end(); itr++)
      {
        TPoint p;
        p.x = (*itr)->x + begin.x;
        p.y = (*itr)->y + begin.y;
        p.z = maneuver->z + (*itr)->z;
        p.t = (*itr)->t;
        m_traj.push_back(p);
      }

      if (m_traj.size() < 2)
      {
        signalError(DTR("too few trajectory points"));
        return false;
      }

      return true;
    }

    void
    SwarmLeader::consume(const IMC::VehicleFormation* msg)
    {
      if (!initParticipants(msg) || !initTrajectory(msg))
        return;

      setControl(IMC::CL_PATH);

      m_path.end_lat = msg->lat;
      m_path.end_lon = msg->lon;

      m_path.end_z_units = msg->z_units;
      m_path.end_z = msg->z;

      m_path.speed = msg->speed;
      m_path.speed_units = msg->speed_units;

      m_approach = true; // signal approach stage

      onInit(msg);
    }

    void
    SwarmLeader::onPathControlState(const IMC::PathControlState* pcs)
    {
      if (pcs->flags & IMC::PathControlState::FL_NEAR)
      {
        if (m_approach)
          m_approach = false;

        onPathCompletion();
      }
    }

    void
    SwarmLeader::consume(const IMC::EstimatedState* msg)
    {
      step(*msg);
      m_estate = *msg;
      m_rlat = msg->lat;
      m_rlon = msg->lon;
    }

    void
    SwarmLeader::toLocalCoordinates(double lat, double lon, double* x, double* y)
    {
      Coordinates::WGS84::displacement(m_rlat, m_rlon, 0, lat, lon, 0, x, y);
    }

    void
    SwarmLeader::fromLocalCoordinates(double x, double y, double* lat, double* lon)
    {
      *lat = m_rlat;
      *lon = m_rlon;
      Coordinates::WGS84::displace(x, y, lat, lon);
    }

    void
    SwarmLeader::onManeuverDeactivation(void)
    {
      onReset();

      m_approach = false;
      m_traj.clear();
      m_participants.clear();
      m_addr2idx.clear();
    }

    void
    SwarmLeader::desiredPath(const TPoint& s, const TPoint& e, double radius)
    {
      m_path.start_lat = m_rlat;
      m_path.start_lon = m_rlon;
      Coordinates::WGS84::displace(s.x, s.y, &m_path.start_lat, &m_path.start_lon);
      m_path.start_z = s.z;

      m_path.end_lat = m_rlat;
      m_path.end_lon = m_rlon;
      Coordinates::WGS84::displace(e.x, e.y, &m_path.end_lat, &m_path.end_lon);
      m_path.end_z = e.z;

      m_path.lradius = radius;
      m_path.flags = 0; // IMC::DesiredPath::FL_START;

      dispatch(m_path);
    }

    void
    SwarmLeader::desiredSpeed(double value, uint8_t units)
    {
      m_path.speed = value;
      m_path.speed_units = units;

      IMC::DesiredSpeed speed;
      speed.value = value;
      speed.speed_units = units;
      dispatch(speed);
    }

    SwarmLeader::TPoint
    SwarmLeader::point(int t_index, int f_index) const
    {
      TPoint p = m_traj[t_index];

      if (f_index >= 0)
      {
        const Participant& v = participant(f_index);

        double bearing;
        double range;

        Coordinates::toPolar(v, &bearing, &range);

        if ((size_t)t_index == 0)
        {
          TPoint start;
          start.x = m_estate.x;
          start.y = m_estate.y;
          start.z = m_estate.depth;

          bearing += Coordinates::getBearing(start, p);
        }
        else
        {
          bearing += Coordinates::getBearing(m_traj[t_index - 1], p);
        }

        // if ((size_t)t_index < trajectory_points() - 1)
        //   bearing += Coordinates::getBearing(p, m_traj[t_index + 1]);
        // else
        //   bearing += Coordinates::getBearing(m_traj[t_index - 2], p);

        Coordinates::displace(p, bearing, range);
        p.z += v.z;
      }

      return p;
    }

    float
    SwarmLeader::bearing(int t_index) const
    {
      TPoint p = m_traj[t_index];

      if ((size_t)t_index == 0)
      {
        TPoint start;
        start.x = m_estate.x;
        start.y = m_estate.y;
        start.z = m_estate.depth;

        return Coordinates::getBearing(start, p);
      }
      else
      {
        return Coordinates::getBearing(m_traj[t_index - 1], p);
      }

      return 0;
    }
  }
}

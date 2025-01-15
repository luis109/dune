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

#ifndef DUNE_MANEUVERS_SWARM_LEADER_HPP_INCLUDED_
#define DUNE_MANEUVERS_SWARM_LEADER_HPP_INCLUDED_

// ISO C++ 98 headers.
#include <vector>
#include <map>

// DUNE headers.
#include <DUNE/IMC.hpp>
#include <DUNE/Maneuvers/Maneuver.hpp>

namespace DUNE
{
  namespace Maneuvers
  {
    // Export DLL Symbol.
    // class DUNE_DLL_SYM LeaderFollowers;

    //! Abstract base class for vehicle formation maneuver tasks.
    class SwarmLeader: public Maneuver
    {
    public:
      //! Constructor.
      //! @param name name.
      //! @param ctx context.
      SwarmLeader(const std::string& name, Tasks::Context& ctx);

      //! Destructor.
      virtual
      ~SwarmLeader(void);

      virtual void
      onUpdateParameters(void);

      //! Consumer for IMC::VehicleFormation message.
      //! @param msg vehicle formation message
      void
      consume(const IMC::VehicleFormation* msg);

      //! Method invoked on maneuver startup.
      //! By default the base class implementation does nothing.
      //! @param msg vehicle formation message
      virtual void
      onInit(const IMC::VehicleFormation* msg)
      {
        (void)msg;
      }

      //! Consumer for IMC::EstimatedState message.
      //! @param msg message
      void
      consume(const IMC::EstimatedState* msg);

      //! Inherited from Maneuver class.
      //! @param pcs path control state message
      void
      onPathControlState(const IMC::PathControlState* pcs);

      //! Abstract method called upon path completion.
      //! This will not be called in approach stage (see isApproaching()).
      virtual void
      onPathCompletion(void) = 0;

      //! Abstract method invoked for trajectory control.
      //! This will be invoked periodically according to the
      //! control step period (see controlPeriod()) after
      //! the initial approach stage has concluded (see isApproaching()).
      virtual void
      step(const IMC::EstimatedState& state) = 0;

      //! Method called upon maneuver deactivation.
      void
      onManeuverDeactivation(void);

      //! Method invoked on maneuver reset.
      //! By default the base class implementation does nothing.
      virtual void
      onReset(void)
      { }

      //! Trajectory point.
      struct TPoint
      {
        double x; //!< X coordinate offset (North).
        double y; //!< Y coordinate offset (East).
        double z; //!< Z coordinate offset (Down).
        double t; //!< time coordinate offset.
      };

      //! Get a point in the trajectory.
      //! @param t_index index of point
      //! @param f_index formation index (vehicle)
      //! @return corresponding traj. point, optionally displaced by formation index offsets
      TPoint
      point(int t_index, int f_index = -1) const;

      //! Get number of points in the trajetory.
      inline size_t
      trajectory_points(void) const
      {
        return m_traj.size();
      }

      //! Get number of points in the trajetory.
      inline const TPoint&
      trajectory_point(int index) const
      {
        return m_traj[index];
      }

      //! Participant data (per vehicle in the formation).
      struct Participant
      {
        int vid; //!< IMC id
        double x; //!< Along-track offset.
        double y; //!< Cross-track offset.
        double z; //!< Depth offset.
      };

      //! Get number of participants in formation.
      //! @return number of participants in formation
      inline size_t
      participants() const
      {
        return m_participants.size();
      }

      //! Get configuration of a vehicle in formation.
      //! @param index formation index
      //! @return participant data for specified formation index
      inline const Participant&
      participant(int index) const
      {
        return m_participants[index];
      }

      //! Get index of given IMC address in formation.
      //! @return formation index.
      inline int
      formation_index(int addr) const
      {
        std::map<int, int>::const_iterator itr = m_addr2idx.find(addr);

        if (itr == m_addr2idx.end())
          return 0xFFFF;

        return itr->second;
      }

      //! Check if maneuver is still in approach stage (i.e. moving to the initial point).
      //! @return true if maneuver is in approach state, false otherwise.
      inline bool
      isApproaching(void) const
      {
        return m_approach;
      }

      void
      desiredPath(const TPoint& start, const TPoint& end, double radius = -1);

      void
      desiredSpeed(double value, uint8_t speed_units);

      void
      toLocalCoordinates(double lat, double lon, double* x, double* y);

      void
      fromLocalCoordinates(double x, double y, double* lat, double* lon);

      IMC::DesiredPath
      getDesiredPath()
      {
        return m_path;
      }

    private:
      std::vector<TPoint> m_traj; //!< Trajectory points.
      std::vector<Participant> m_participants; //!< Trajectory points.
      std::map<int, int> m_addr2idx;
      bool m_approach; //!< Approach stage flag.
      double m_rlat; // Reference latitude set.
      double m_rlon; // Reference longitude set.
      IMC::DesiredPath m_path;
      IMC::DesiredZ m_depth;
      IMC::EstimatedState m_estate;

      bool
      initParticipants(const IMC::VehicleFormation*);

      bool
      initTrajectory(const IMC::VehicleFormation*);
    };
  }
}

#endif

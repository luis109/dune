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
// Author: Luís Venâncio                                                    *
//***************************************************************************

// DUNE headers.
#include <DUNE/DUNE.hpp>

namespace Autonomy
{
  //! %TREX is responsible to interact with MBARI's T-REX
  namespace Swarm
  {
    using DUNE_NAMESPACES;

    //! %Task arguments
    struct Arguments
    {
      //! T-REX IMC identifier.
      std::string follower_label;
      //! Time threshold after which communication with TREX is considered lost
      uint16_t connection_timeout;
      //! Threshold (meters) after which the vehicle is considered to have arrived
      //! at destination in the vertical plane.
      uint16_t altitude_interval;
    };

    struct Task : public DUNE::Tasks::Task
    {
      //! Task arguments.
      Arguments m_args;
      //! Follower entity id
      unsigned int m_follower_id;
      //! Swarm acoustic protocol
      Swarm::AcousticProtocol m_aprot;
      //! Reference latitude
      float m_ref_lat;
      //! Reference longitude
      float m_ref_lon;
      //! Plan execution started
      bool m_started;
      //! Reference timer
      Counter<double> m_ref_timer;

      Task(const std::string& name, Tasks::Context& ctx) :
        DUNE::Tasks::Task(name, ctx),
        m_aprot(this),
        m_ref_lat(0),
        m_ref_lon(0),
        m_started(false)
      {
        // Define configuration parameters.
        paramActive(Tasks::Parameter::SCOPE_GLOBAL,
                    Tasks::Parameter::VISIBILITY_USER, false);

        param("Follower Label", m_args.follower_label)
        .defaultValue("Follower");

        param("Connection Timeout", m_args.connection_timeout)
        .defaultValue("60")
        .minimumValue("0");

        param("FollowReference altitude interval", m_args.altitude_interval)
        .defaultValue("2")
        .minimumValue("0");

        // Register consumers.
        bind<IMC::VehicleState>(this);
        bind<IMC::PlanControlState>(this);
        bind<IMC::Abort>(this);
        bind<IMC::PlanControl>(this);
        bind<IMC::UamRxFrame>(this);
      }

      void
      onUpdateParameters(void)
      {
        
      }

      void
      onEntityReservation(void)
      {
        m_follower_id = reserveEntity(m_args.follower_label);
      }

      void
      updateEntityState(void)
      {
        if (!isActive()) {
          setEntityState(IMC::EntityState::ESTA_NORMAL, Status::CODE_IDLE);
          return;
        }
      }

      void
      onResourceInitialization(void)
      {
        m_ref_timer.setTop(5);
      }

      void
      consume(const IMC::VehicleState * msg)
      {
        // if the vehicle is in error mode, T-REX payload becomes inactive
        if (msg->op_mode == IMC::VehicleState::VS_ERROR)
          requestDeactivation();
      }

      void
      consume(const IMC::PlanControlState * msg)
      {
        
      }

      void
      consume(const IMC::Abort* msg)
      {
        if (msg->getDestination() != getSystemId())
          return;

        war(DTR("Abort detected. Disabling TREX control..."));
        requestDeactivation();
      }

      void
      consume(const IMC::PlanControl* msg)
      {
        // if (msg->type == PlanControl::PC_REQUEST && msg->op == PlanControl::PC_STOP)
        // {
        //   m_trex_control = m_last_plan_state.plan_id == "trex_plan"
        //   && m_last_plan_state.state == IMC::PlanControlState::PCS_EXECUTING;

        //   if (m_trex_control)
        //   {
        //     requestDeactivation();
        //     war(DTR("Stop TREX detected. Disabling TREX control..."));
        //   }
        // }
      }

      void
      consume(const IMC::UamRxFrame * msg)
      {
        war("RECEIVED");
        if (!m_aprot.validate(msg))
          return;

        war("VALIDATED");
        switch (msg->data[1])
        {
          case CODE_NEXT:
            recvNext(msg);
            break;
          default:
            debug("Invalid acoustic code: %u", msg->data[1]);
            break;
        }
      }

      void
      recvNext(const IMC::UamRxFrame* msg)
      {
        Point p;
        std::memcpy(&p, &msg->data[2], sizeof(p));

        m_ref_lat = p.lat;
        m_ref_lon = p.lon;

        if (m_started)
          return;

        startExecution();
        m_started = true;
      }

      void
      onActivation(void)
      {
        inf("%s", DTR(Status::getString(Status::CODE_ACTIVE)));
        setEntityState(IMC::EntityState::ESTA_NORMAL, Status::CODE_ACTIVE);
      }

      void
      onDeactivation(void)
      {
        inf("%s", DTR(Status::getString(Status::CODE_IDLE)));
        setEntityState(IMC::EntityState::ESTA_NORMAL, Status::CODE_IDLE);
      }

      // Start a FollowReference maneuver that is controlled by TREX
      void
      startExecution(void)
      {
        inf("Starting Follower plan...");
        IMC::PlanControl startPlan;
        startPlan.type = IMC::PlanControl::PC_REQUEST;
        startPlan.op = IMC::PlanControl::PC_START;
        startPlan.plan_id = "follower_plan";
        IMC::FollowReference man;
        man.control_ent = 255;
        man.control_src = m_follower_id;
        man.altitude_interval = m_args.altitude_interval;
        man.timeout = m_args.connection_timeout + 10;

        IMC::PlanSpecification spec;

        spec.plan_id = "follower_plan";
        spec.start_man_id = "follow_0";

        IMC::PlanManeuver pm;
        pm.data.set(man);
        pm.maneuver_id = "follow_0";
        spec.maneuvers.push_back(pm);
        startPlan.arg.set(spec);
        startPlan.request_id = 0;
        startPlan.flags = 0;
        startPlan.setDestination(m_ctx.resolver.id());
        dispatch(startPlan);
      }

      // Stop ongoing FollowReference maneuver
      void
      stopExecution(void)
      {
        inf("Stopping Follower plan...");
        IMC::PlanControl stopPlan;
        stopPlan.type = IMC::PlanControl::PC_REQUEST;
        stopPlan.op = IMC::PlanControl::PC_STOP;
        stopPlan.plan_id = "follower_plan";
        dispatch(stopPlan);
      }

      void
      sendReference()
      {
        if (!m_started)
          return;

        IMC::DesiredZ z;
        z.z_units = IMC::ZUnits::Z_DEPTH;
        z.value = 0.0;

        IMC::DesiredSpeed speed;
        speed.speed_units = IMC::SpeedUnits::SUNITS_METERS_PS;
        speed.value = 1.0;

        IMC::Reference ref;
        ref.setSource(m_follower_id);
        ref.setSourceEntity(255);
        ref.lat = m_ref_lat;
        ref.lon = m_ref_lon;
        ref.z.set(&z);
        ref.speed.set(&speed);
        ref.flags = IMC::Reference::FLAG_LOCATION | 
                     IMC::Reference::FLAG_Z | 
                     IMC::Reference::FLAG_SPEED;

        dispatch(ref);
      }

      void
      onMain(void)
      {
        while (!stopping())
        {
          waitForMessages(1.0);

          if (m_ref_timer.overflow())
          {
            sendReference();
            m_ref_timer.reset();
          }
        }
      }
    };
  }
}

DUNE_TASK

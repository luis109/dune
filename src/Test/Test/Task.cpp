//***************************************************************************
// Copyright 2007-2026 Universidade do Porto - Faculdade de Engenharia      *
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
// Author: Test (do not commit!)                                            *
//***************************************************************************

// DUNE headers.
#include <DUNE/DUNE.hpp>
// #include <Transports/CommManager/TransmissionIdGenerator.hpp>
#if defined(DUNE_USING_DCCL)
#include <DUNE/Encoders/DCCL/CodecDCCL.hpp>
#endif

namespace Test
{
  //! Insert short task description here.
  //!
  //! Insert explanation on task behaviour here.
  //! @author Test (do not commit!)
  namespace Test
  {
    //! Insert short task description here.
    //!
    //! Insert explanation on task behaviour here.
    //! @author Test (do not commit!)
    using DUNE_NAMESPACES;
    // using namespace Transports::CommManager;

    const uint8_t c_max_maneuvers = 5;

    struct Task: public DUNE::Tasks::Task
    {
      Time::Counter<double> m_timer;
      IMC::PlanSpecification m_spec;
      IMC::TransmissionRequest m_request;
#if defined(DUNE_USING_DCCL)
      dccl::Codec m_dccl;
      DUNE::Encoders::DCCL::CodecDCCL m_codec_dccl;
#endif

      //! Constructor.
      //! @param[in] name task name.
      //! @param[in] ctx context.
      Task(const std::string& name, Tasks::Context& ctx):
        DUNE::Tasks::Task(name, ctx),
        m_timer(120.0)
#if defined(DUNE_USING_DCCL)
      , m_codec_dccl(m_dccl)
#endif
      {
      }

      //! Update internal state with new parameter values.
      void
      onUpdateParameters(void)
      {
      }

      //! Reserve entity identifiers.
      void
      onEntityReservation(void)
      {
      }

      //! Resolve entity names.
      void
      onEntityResolution(void)
      {
      }

      //! Acquire resources.
      void
      onResourceAcquisition(void)
      {
      }

      //! Initialize resources.
      void
      onResourceInitialization(void)
      {
        const std::string plan_name = "fragment_test_plan";
        m_spec.plan_id = plan_name;

        std::string last_man_name;
        for (unsigned i = 0; i < c_max_maneuvers; ++i)
        {
          // Set initial maneuver id
          std::string maneuver_name = String::str("test_maneuver_%u", i);
          if (m_spec.start_man_id.empty())
            m_spec.start_man_id = maneuver_name;
          
          IMC::Maneuver* maneuver = getGoto().clone();

          IMC::PlanManeuver pm;
          pm.maneuver_id = maneuver_name;
          pm.data.set(maneuver);
          m_spec.maneuvers.push_back(pm);
          if (!last_man_name.empty())
          {
            // Add transition from previous maneuver
            IMC::PlanTransition pt;
            pt.source_man = last_man_name;
            pt.dest_man = maneuver_name;
            pt.conditions = "ManeuverIsDone";
            m_spec.transitions.push_back(pt);
          }

          last_man_name = maneuver_name;
          Memory::clear(maneuver);
        }

        war("PlanSpecification with size %u created.", m_spec.getPayloadSerializationSize());


        m_request.setDestination(getSystemId());
        m_request.comm_mean = IMC::TransmissionRequest::CMEAN_ACOUSTIC;
        m_request.data_mode = IMC::TransmissionRequest::DMODE_INLINEMSG_DCCL;
        m_request.deadline = Clock::getSinceEpoch() + 30.0;
        m_request.req_id = 30;
        m_request.destination = "lauv-noptilus-3";
        m_request.msg_data.set(m_spec);
      }

      IMC::Goto
      getGoto()
      {
        IMC::Goto goto_man;

        goto_man.lat = Angles::radians(41.1850); 
        goto_man.lon = Angles::radians(-8.7062);
        goto_man.z = 0;
        goto_man.z_units = ZUnits::Z_DEPTH;
        goto_man.speed = 1.0;
        goto_man.speed_units = SpeedUnits::SUNITS_METERS_PS;
        return goto_man;
      }

      //! Release resources.
      void
      onResourceRelease(void)
      {
      }

      //! Main loop.
      void
      onMain(void)
      {
        Time::Delay::wait(5.0);
        // Send first message
        m_request.deadline = Clock::getSinceEpoch() + 30.0;

        // Unfragmented msg
        // IMC::Temperature temp_msg;
        // m_request.msg_data.set(temp_msg);

        dispatch(m_request);
        war("TransmissionRequest with msg payload size %u sent.", m_spec.getPayloadSerializationSize());

        while (!stopping())
        {
          waitForMessages(1.0);

          // if (m_timer.overflow())
          // {
          //   m_request.deadline = Clock::getSinceEpoch() + 30.0;
          //   m_request.req_id = TransmissionIdGenerator::createId();
          //   dispatch(m_request);
          //   war("TransmissionRequest with msg payload size %u sent.", m_spec.getPayloadSerializationSize());
          //   m_timer.reset();
          // }
        }
      }
    };
  }
}

DUNE_TASK

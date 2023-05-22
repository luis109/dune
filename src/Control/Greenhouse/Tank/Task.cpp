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
// Author: Luis Venancio                                                    *
//***************************************************************************

// DUNE headers.
#include <DUNE/DUNE.hpp>

namespace Control::Greenhouse
{
  //! This task controls tank levels, nutrients and irrigation.
  //!
  //! @author Luis Venancio
  namespace Tank
  {
    using DUNE_NAMESPACES;

    //! %Task arguments.
    struct Arguments
    {
      //! Irrigation motor id
      int irrigation_mtr_id;
      //! Air motor id
      int air_mtr_id;
    };

    //! %Grow Monitor task.
    struct Task: public DUNE::Tasks::Periodic
    {
      //! State machine states
      enum TankStates
      {
        TS_NORMAL,
        TS_EMPTYING,
        TS_REFFILING,
        TS_NUTRIENT_BALANCE,
        TS_PH_BALANCE
      };

      //! Task arguments.
      Arguments m_args;
      //! Current desired irrigation
      IMC::DesiredIrrigation m_dirrigation;
      //! Current desired air flow
      IMC::DesiredAirFlow m_dairflow;
      //! Current tank state
      TankStates m_tstate;

      Task(const std::string& name, Tasks::Context& ctx):
        Tasks::Periodic(name, ctx),
        m_tstate(TS_NORMAL)
      {
        param("Motor Id -- Irrigation", m_args.irrigation_mtr_id)
        .defaultValue("0")
        .description("Irrigation motor id");

        param("Motor Id -- Air", m_args.air_mtr_id)
        .defaultValue("0")
        .description("Air motor id");

        bind<IMC::DesiredIrrigation>(this);
        bind<IMC::DesiredAirFlow>(this);
      }

      void
      onUpdateParameters(void)
      {
      } 

      void
      onResourceRelease(void)
      {
      }

      void
      onEntityResolution(void)
      {
      }

      void
      onResourceInitialization(void)
      {
      }

      void
      consume(const IMC::DesiredIrrigation* msg)
      {
        m_dirrigation = *msg;
      }

      void
      consume(const IMC::DesiredAirFlow* msg)
      {
        m_dairflow = *msg;
      }

      void
      setTankPumps()
      {
        IMC::SetThrusterActuation ta;

        ta.id = m_args.irrigation_mtr_id;
        ta.value = m_dirrigation.value;
        dispatch(ta);

        ta.id = m_args.air_mtr_id;
        ta.value = m_dairflow.value;
        dispatch(ta);
      }

      void
      stateMachine()
      {
        switch (m_tstate)
        {
          case TS_NORMAL:
            setTankPumps();
            break;

          case TS_EMPTYING:
            // Empty tank, watch water level
            m_tstate = TS_REFFILING;
            break;

          case TS_REFFILING:
            // Refill tank, watch water level
            m_tstate = TS_NUTRIENT_BALANCE;
            break;

          case TS_NUTRIENT_BALANCE:
            // Act nutrient pumps for set amount of time each, 
            // use seperate timers. Change state when all timers done
            m_tstate = TS_PH_BALANCE;
            break;

          case TS_PH_BALANCE:
            // Balance ph, watch Ph message until it enters range
            m_tstate = TS_NORMAL;
            break;
          
          default:
            m_tstate = TS_NORMAL;
            break;
        }
      }

      void
      task(void)
      {
        stateMachine();
      }
    };
  }
}

DUNE_TASK

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
  namespace Environment
  {
    using DUNE_NAMESPACES;

    //! %Task arguments.
    struct Arguments
    {
      //! Light power channel name
      int light_pwr_chn;
    };

    //! %Grow Monitor task.
    struct Task: public DUNE::Tasks::Task
    {
      //! Task arguments.
      Arguments m_args;
      //! Power control for lights
      IMC::PowerChannelControl m_light_pwr;

      Task(const std::string& name, Tasks::Context& ctx):
        Tasks::Task(name, ctx)
      {

        param("Power Channel -- Light", m_args.light_pwr_chn)
        .defaultValue("")
        .description("Light power channel name");

        bind<IMC::DesiredLight>(this);
      }

      void
      onUpdateParameters(void)
      {
        if (paramChanged(m_args.light_pwr_chn))
          m_light_pwr.name = m_args.light_pwr_chn;
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
      consume(const IMC::DesiredLight* msg)
      {
        setLight(msg->value > 0);
      }

      void
      setLight(bool state)
      {
        if (state)
          m_light_pwr.op = IMC::PowerChannelControl::PCC_OP_SCHED_ON;
        else
          m_light_pwr.op = IMC::PowerChannelControl::PCC_OP_SCHED_OFF;

        dispatch(m_light_pwr);
      }

      void
      onMain(void)
      {
        while (!stopping())
        {
          waitForMessages(1.0);
        }
      }
    };
  }
}

DUNE_TASK

//***************************************************************************
// Copyright 2007-2025 Universidade do Porto - Faculdade de Engenharia      *
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
// Author: Eduardo Marques                                                  *
//***************************************************************************

// ISO C++ 98 headers.
#include <iomanip>

// DUNE headers.
#include <DUNE/DUNE.hpp>

namespace Simulators
{
  namespace Receiver
  {
    using DUNE_NAMESPACES;
    //! %Task arguments.
    struct Arguments
    {
    };

    //! %GPS simulator task.
    struct Task: public Tasks::Task
    {
      IMC::Temperature m_temp;

      Task(const std::string& name, Tasks::Context& ctx):
        Tasks::Task(name, ctx)
      {
        // bind<IMC::Temperature>(this, &Task::validateTemperature);
        bind<IMC::Temperature>(this);
        // bind<IMC::Temperature>(this, &Task::consume, nullptr); //static_cast<bool (Task::*)(const IMC::Temperature*)>(nullptr)
        bindUnfiltered<IMC::Temperature>(this);
      }

      bool
      validateTemperature(const IMC::Temperature* msg)
      {
        return msg->getSource() == getSystemId();
      }

      void
      onUpdateParameters(void)
      {
        
      }

      void
      onResourceInitialization(void)
      {
      }

      void
      consume(const IMC::Temperature* msg)
      {
        msg->getSourceEntity();
        std::string str = resolveEntity(msg->getSourceEntity());
        war("Received from: %s", str.c_str());
      }

      void
      onMain(void)
      {
        while(!stopping())
        {
          waitForMessages(1.0);
        }
      }
    };
  }
}

DUNE_TASK

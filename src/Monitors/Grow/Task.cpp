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

// Platform headers.
#if defined(DUNE_SYS_HAS_TIME_H)
#  include <time.h>
#endif

namespace Monitors
{
  //! This task is responsible for monitoring plant growth status.
  //!
  //! @author Luis Venancio
  namespace Grow
  {
    using DUNE_NAMESPACES;

    //! Number of seconds in a day.
    static const float c_sec_per_day = 86400;

    //! %Task arguments.
    struct Arguments
    {
      //! Date of grow start
      std::vector<int> start_date;
      //! Time in vegetative stage
      int vegetative_days;
      //! Time in flowering stage
      int flowering_days;
    };

    //! %Grow Monitor task.
    struct Task: public DUNE::Tasks::Task
    {
      //! Task arguments.
      Arguments m_args;
      //! Grow start date in UNIX time
      double m_start_time;

      Task(const std::string& name, Tasks::Context& ctx):
        Tasks::Task(name, ctx)
      {
        param("Start Date", m_args.start_date)
        .defaultValue("")
        .size(3)
        .description("Time of grow start (year, month(0-11), day(0-31))");

        param("Vegetative Days", m_args.vegetative_days)
        .defaultValue("0")
        .description("Time in vegetative stage, in days");

        param("Flowering Days", m_args.flowering_days)
        .defaultValue("0")
        .description("Time in flowering stage, in days");
      }

      void
      onUpdateParameters(void)
      {
        if (paramChanged(m_args.start_date))
        {
          struct tm t;

          // tm_year is set in years after 1900
          t.tm_year = m_args.start_date[0] - 1900;
          t.tm_mon = m_args.start_date[1];
          t.tm_mday = m_args.start_date[2];
          t.tm_hour = 0;
          t.tm_min = 0;
          t.tm_sec = 0;

          m_start_time = mktime(&t);
        }
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
        // Days since grow start
        double days;
        days = (Time::Clock::getSinceEpoch() - m_start_time) / c_sec_per_day;
        inf("Days difference: %f", days);
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

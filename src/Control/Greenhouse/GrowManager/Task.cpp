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

namespace Control::Greenhouse
{
  //! This task dispatches the desired environmental levels for the grow.
  //!
  //! @author Luis Venancio
  namespace GrowManager
  {
    using DUNE_NAMESPACES;

    //! Number of seconds in a day.
    static const float c_sec_per_hour = 3600;

    //! %Task arguments.
    struct Arguments
    {
      //! Light turn on time
      std::vector<int> light_turn_on;
      //! Vegetative light time, in hours
      int veg_light_time;
      //! Flowering light time, in hours
      int flw_light_time;
    };

    //! %Grow Monitor task.
    struct Task: public DUNE::Tasks::Task
    {
      //! Task arguments.
      Arguments m_args;
      //! Time of next light turn on
      double m_next_light_on;
      //! Time of next light turn off
      double m_next_light_off;

      //! Plant stage (this should be the PlantState message)
      bool m_plant_stage;

      Task(const std::string& name, Tasks::Context& ctx):
        Tasks::Task(name, ctx)
      {
        param("Light On Time", m_args.light_turn_on)
        .defaultValue("9, 0, 0")
        .size(3)
        .description("Light turn on time (hour (0-23), min(0-59), sec(0-59))");

        param("Vegetative Light Time", m_args.veg_light_time)
        .defaultValue("18")
        .description("Vegetative light time, in hours");

        param("Flowering Light Time", m_args.flw_light_time)
        .defaultValue("12")
        .description("Flowering light time, in hours");

        m_plant_stage = true;
      }

      void
      onUpdateParameters(void)
      {
        // Initialize tm struct
        time_t now = Time::Clock::getSinceEpoch();
        struct tm* start = localtime(&now);

        // Get timestamp of lights on, for today
        start->tm_hour = m_args.light_turn_on[0];
        start->tm_min = m_args.light_turn_on[1];
        start->tm_sec = m_args.light_turn_on[2];
        m_next_light_on = mktime(start);

        // Get timestamp of next lights off
        start->tm_hour += m_plant_stage ? m_args.flw_light_time : m_args.veg_light_time;
        m_next_light_off = mktime(start);

        // Check where we are now in light cycle and recalculate if needed
        if(now > m_next_light_off)
        {
          m_next_light_on += 24 * c_sec_per_hour;
          m_next_light_off += 24 * c_sec_per_hour;
        }
        else if (now > m_next_light_on)
        {
          m_next_light_on += 24 * c_sec_per_hour;
        }

        std::string next_light_on = Time::Format::getTimeDate(m_next_light_on);
        std::string next_light_off = Time::Format::getTimeDate(m_next_light_off);

        war("Next light on: %s", next_light_on.c_str());
        war("Next light off: %s", next_light_off.c_str());
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
      checkLightCycle()
      {
        double now = Time::Clock::getSinceEpoch();
        
        if (now > m_next_light_on)
        {
          // TURN LIGHT ON
          war("LIGHT TURN ON");
          m_next_light_on += 24 * c_sec_per_hour;
        }

        if (now > m_next_light_off)
        {
          // TURN LIGHT OFF
          war("LIGHT TURN OFF");
          m_next_light_off = m_next_light_on + m_plant_stage ? m_args.flw_light_time : m_args.veg_light_time;
        }
      }

      void
      printTM(tm &time)
      {
        std::cout << "sec: " << time.tm_sec << "\n";
        std::cout << "min: " << time.tm_min << "\n";
        std::cout << "hour: " << time.tm_hour << "\n";
        std::cout << "day: " << time.tm_mday << "\n";
        std::cout << "month: " << time.tm_mon << "\n";
        std::cout << "year: " << time.tm_year << "\n";
        std::cout << "\n";
      }
 
      void
      onMain(void)
      {
        while (!stopping())
        {
          waitForMessages(1.0);
          checkLightCycle();
        }
      }
    };
  }
}

DUNE_TASK

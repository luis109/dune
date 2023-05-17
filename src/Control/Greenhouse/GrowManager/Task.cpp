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
      //! Light periods, in hours, by plant stage
      struct
      {
        int seedling;
        int vegetative;
        int flowering;
      }period;
    };

    //! %Grow Monitor task.
    struct Task: public DUNE::Tasks::Task
    {
      //! Task arguments.
      Arguments m_args;
      //! Current Plant State
      IMC::PlantState m_pstate;
      //! Time of next light turn on
      double m_next_light_on;
      //! Time of next light turn off
      double m_next_light_off;
      //! Light period by stage
      std::map<IMC::PlantState::PlantStageEnum, double> m_light_period;

      Task(const std::string& name, Tasks::Context& ctx):
        Tasks::Task(name, ctx)
      {
        param("Light On Time", m_args.light_turn_on)
        .defaultValue("9, 0, 0")
        .size(3)
        .description("Light turn on time (hour (0-23), min(0-59), sec(0-59))");

        param("Light Period -- Seedling", m_args.period.seedling)
        .defaultValue("18")
        .minimumValue("1")
        .maximumValue("23")
        .description("Seedling \'light on\' period, in hours");

        param("Light Period -- Vegetative", m_args.period.vegetative)
        .defaultValue("18")
        .minimumValue("1")
        .maximumValue("23")
        .description("Vegetative \'light on\' period, in hours");

        param("Light Period -- Flowering", m_args.period.flowering)
        .defaultValue("12")
        .minimumValue("1")
        .maximumValue("23")
        .description("Flowering \'light on\' period, in hours");

        bind<IMC::PlantState>(this);
      }

      void
      onUpdateParameters(void)
      {
        if (paramChanged(m_args.period.seedling) ||
            paramChanged(m_args.period.vegetative) ||
            paramChanged(m_args.period.flowering))
        {
          m_light_period[IMC::PlantState::STG_SEEDLING] = m_args.period.seedling;
          m_light_period[IMC::PlantState::STG_VEGETATIVE] = m_args.period.vegetative;
          m_light_period[IMC::PlantState::STG_FLOWRING] = m_args.period.flowering;
          m_light_period[IMC::PlantState::STG_HARVESTING] = m_args.period.flowering;

          initializeLightCycle(); 
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
      }

      void
      consume(const IMC::PlantState* msg)
      {
        m_pstate = *msg;
      }

      void
      initializeLightCycle()
      {
        // Get off period
        double off_period = 24 * c_sec_per_hour - lightPeriod();

        // Initialize tm struct
        time_t now = Time::Clock::getSinceEpoch();
        struct tm* start = localtime(&now);

        // Get timestamp of lights on, for today
        start->tm_hour = m_args.light_turn_on[0];
        start->tm_min = m_args.light_turn_on[1];
        start->tm_sec = m_args.light_turn_on[2];
        m_next_light_on = mktime(start);

        // Correctly set next light on and off times
        if (now < m_next_light_on)
        {
          if(now < m_next_light_on - off_period)
          {
            // TURN LIGHT ON
            setLight(1);
            m_next_light_off = m_next_light_on - off_period;
          }
          else
          {
            // TURN LIGHT OFF
            setLight(0);
            m_next_light_off = m_next_light_on + lightPeriod();
          }
        }
        else
        {
          m_next_light_on += 24 * c_sec_per_hour;
          if (now > m_next_light_on - off_period)
          {
            // TURN LIGHT OFF
            setLight(0);
            m_next_light_off = m_next_light_on + lightPeriod();
          }
          else
          {
            // TURN LIGHT ON
            setLight(1);
            m_next_light_off = m_next_light_on - off_period;
          }
        }

        outputLightSchedule();
      }

      void
      checkLightCycle()
      {
        double now = Time::Clock::getSinceEpoch();
        
        if (now > m_next_light_on)
        {
          // TURN LIGHT ON
          setLight(1);
          m_next_light_on += 24 * c_sec_per_hour;

          outputLightSchedule();
        }

        if (now > m_next_light_off)
        {
          // TURN LIGHT OFF
          setLight(0);
          m_next_light_off = m_next_light_on + lightPeriod();

          outputLightSchedule();
        }
      }

      double
      lightPeriod()
      {
        double hours = m_light_period[static_cast<IMC::PlantState::PlantStageEnum>(m_pstate.stage)];
        return  hours * c_sec_per_hour;
      }

      void
      outputLightSchedule()
      {
        std::string next_light_on = Time::Format::getTimeDate(m_next_light_on);
        std::string next_light_off = Time::Format::getTimeDate(m_next_light_off);

        debug("Next light on: %s", next_light_on.c_str());
        debug("Next light off: %s", next_light_off.c_str());
      }

      void
      setLight(double level)
      {
        IMC::DesiredLight dlight;
        dlight.value = level;
        dispatch(dlight);

        debug("Set light to: %f", level);
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

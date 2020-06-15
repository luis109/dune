//***************************************************************************
// Copyright 2007-2020 Universidade do Porto - Faculdade de Engenharia      *
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
// Author: Ricardo Martins                                                  *
//***************************************************************************

// DUNE headers.
#include <DUNE/DUNE.hpp>

namespace Navigation
{
  namespace AUV
  {
    namespace Ranger
    {
      using DUNE_NAMESPACES;

      //! Task arguments.
      struct Arguments
      {
        //! Ping periodicity.
        double ping_period;
        //! Stealth mode
        bool stealth;
      };

      struct Task: public DUNE::Tasks::Task
      {
        //! Current LBL configuration.
        IMC::LblConfig m_lbl_config;
        //! Cursor.
        MessageList<IMC::LblBeacon>::const_iterator m_cursor;
        //! Timer.
        Time::Counter<double> m_timer;
        //! Navigation entity id
        uint32_t m_nav_eid;
        //! Last usbl position
        IMC::UsblPositionExtended m_last_usbl;
        //! Task arguments.
        Arguments m_args;

        //! Constructor.
        //! @param[in] name task name.
        //! @param[in] ctx context.
        Task(const std::string& name, Tasks::Context& ctx):
          DUNE::Tasks::Task(name, ctx)
        {
          paramActive(Tasks::Parameter::SCOPE_MANEUVER,
                      Tasks::Parameter::VISIBILITY_USER);

          param("Ping Periodicity", m_args.ping_period)
          .visibility(Tasks::Parameter::VISIBILITY_USER)
          .units(Units::Second)
          .defaultValue("2")
          .minimumValue("2");

          param("Stealth Mode", m_args.stealth)
          .defaultValue("false");

          bind<IMC::LblConfig>(this);
          bind<IMC::UamRxRange>(this);
          bind<IMC::UsblPositionExtended>(this);
          bind<IMC::GpsFix>(this);
          bind<IMC::EntityState>(this);
        }

        //! Update internal state with new parameter values.
        void
        onUpdateParameters(void)
        {
          if (paramChanged(m_args.ping_period))
            m_timer.setTop(m_args.ping_period);
        }

        //! Initialize resources.
        void
        onResourceInitialization(void)
        {
          setEntityState(IMC::EntityState::ESTA_NORMAL, Status::CODE_IDLE);
        }

        void
        onEntityResolution()
        {
          try
          {
            m_nav_eid = resolveEntity("Navigation");
          }
          catch (...)
          {
            m_nav_eid = std::numeric_limits<unsigned>::max();
          }
        }

        void
        onActivation(void)
        {
          m_timer.reset();
          setEntityState(IMC::EntityState::ESTA_NORMAL, Status::CODE_ACTIVE);
        }

        void
        onDeactivation(void)
        {
          setEntityState(IMC::EntityState::ESTA_NORMAL, Status::CODE_IDLE);
        }

        void
        consume(const IMC::LblConfig* msg)
        {
          if (msg->op == IMC::LblConfig::OP_SET_CFG)
          {
            m_lbl_config = *msg;
            m_cursor = m_lbl_config.beacons.begin();
          }
          else if (msg->op == IMC::LblConfig::OP_GET_CFG)
          {
            IMC::LblConfig cfg(m_lbl_config);
            cfg.op = IMC::LblConfig::OP_CUR_CFG;
            cfg.setSource(getSystemId());
            cfg.setSourceEntity(getEntityId());
            dispatchReply(*msg, cfg);
          }
        }

        void
        consume(const IMC::EntityState* msg)
        {
          if (!m_args.stealth)
            return;

          if (msg->getSourceEntity() != m_nav_eid)
            return;

          // no beacon set -> broadcast | if beacon(s) set -> ping that beacon(s)
          if (msg->state == IMC::EntityState::ESTA_BOOT)
            m_lbl_config.beacons.empty() ? pingReversed("broadcast") : pingNextBeacon(true);
        }

        void
        consume(const IMC::UamRxRange* msg)
        {
          unsigned id = 0;

          getBeacon(msg->sys, id);

          IMC::LblRange range;
          range.id = id;
          range.range = msg->value;
          dispatch(range);
        }

        void
        consume(const IMC::GpsFix* msg)
        {
          if (msg->getSource() == getSystemId())
            return;
          
          unsigned int id;
          std::string beacon_name = resolveSystemId(msg->getSource());
          IMC::LblBeacon* beacon = getBeacon(beacon_name, id);

          if (beacon != NULL)
          {
            // Update existing beacon
            beacon->lat = msg->lat;
            beacon->lon = msg->lon;
          }
          else
          {
            // Create new beacon
            IMC::LblBeacon new_beacon;
            new_beacon.beacon = beacon_name;
            new_beacon.lat = msg->lat;
            new_beacon.lon = msg->lon;

            m_lbl_config.op = IMC::LblConfig::OP_SET_CFG;
            m_lbl_config.beacons.push_back(new_beacon);
            m_cursor = m_lbl_config.beacons.begin();

            beacon = *m_cursor;
          }

          // Allow sending fix when setting beacon
          if (m_last_usbl.target == beacon_name)
          {
            if (std::abs(m_last_usbl.getTimeStamp() - msg->getTimeStamp()) < 10.0)
              sendUsblFix(beacon, &m_last_usbl);
          }
        }

        void
        consume(const IMC::UsblPositionExtended* msg)
        {
          m_last_usbl = *msg;

          unsigned dummy;
          IMC::LblBeacon* beacon = getBeacon(msg->target, dummy);
          if (beacon == NULL)
            return;

          sendUsblFix(beacon, msg);
        }

        void
        sendUsblFix(IMC::LblBeacon* beacon, const IMC::UsblPositionExtended* msg)
        {
          double lat = beacon->lat;
          double lon = beacon->lon;
          double dep = beacon->depth;
          WGS84::displace(-msg->n, -msg->e, -msg->d, &lat, &lon, &dep);

          IMC::UsblFixExtended fix;
          fix.target = getSystemName();
          fix.lat = lat;
          fix.lon = lon;
          fix.z = dep;
          fix.z_units = IMC::ZUnits::Z_DEPTH;
          dispatch(fix);
        }

        IMC::LblBeacon*
        getBeacon(std::string name, unsigned &id)
        {
          id = 0;
          
          MessageList<IMC::LblBeacon>::const_iterator itr = m_lbl_config.beacons.begin();
          for (; itr < m_lbl_config.beacons.end(); ++itr)
          {
            if ((*itr) == NULL)
              continue;

            if ((*itr)->beacon == name)
              return *itr;

            ++id;
          }

          return NULL;
        }

        void
        ping(const std::string& sys_name)
        {
          IMC::AcousticRequest tx;
          tx.setDestination(getSystemId());
          tx.destination = sys_name;
          tx.type = IMC::AcousticRequest::TYPE_RANGE;
          
          dispatch(tx);
        }

        void
        pingReversed(const std::string& sys_name)
        {
          IMC::AcousticRequest tx;
          tx.setDestination(getSystemId());
          tx.destination = sys_name;
          tx.type = IMC::AcousticRequest::TYPE_REVERSE_RANGE;
          
          dispatch(tx);
        }

        const IMC::LblBeacon*
        getNextBeacon(void)
        {
          for (size_t i = 0; i < m_lbl_config.beacons.size(); ++i)
          {
            if (*m_cursor != NULL)
            {
              const IMC::LblBeacon* beacon = *m_cursor;
              if (++m_cursor == m_lbl_config.beacons.end())
                m_cursor = m_lbl_config.beacons.begin();
              return beacon;
            }
          }

          return NULL;
        }

        void
        pingNextBeacon(bool reversed = false)
        {
          const IMC::LblBeacon* beacon = getNextBeacon();

          if (beacon == NULL)
            return;

          if (reversed)
            pingReversed(beacon->beacon);
          else
            ping(beacon->beacon);
        }

        void
        wait(void)
        {
          double delay = m_timer.getRemaining();
          if (delay < 0 || delay > 1.0)
            delay = 1.0;
          waitForMessages(delay);
        }

        //! Main loop.
        void
        onMain(void)
        {
          while (!stopping())
          {
            wait();
            
            if (!isActive())
              continue;

            if (m_timer.overflow())
            {
              // if in stealth ask for beacon position
              pingNextBeacon(m_args.stealth);
              m_timer.reset();
            }
          }
        }
      };
    }
  }
}

DUNE_TASK

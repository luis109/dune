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

#ifndef POWER_GHPB_MOTOR_CHANNELS_HPP_INCLUDED_
#define POWER_GHPB_MOTOR_CHANNELS_HPP_INCLUDED_

// DUNE headers.
#include <DUNE/DUNE.hpp>

namespace Power
{
  namespace GHPB
  {
    using DUNE_NAMESPACES;

    struct MotorChannel
    {
      unsigned id;
      int speed;
    };

    class MotorChannels
    {
    public:
      MotorChannels(void)
      { }

      ~MotorChannels(void)
      {
        clear();
      }

      void
      clear(void)
      {
        std::map<unsigned, MotorChannel*>::iterator itr = m_by_id.begin();
        for (; itr != m_by_id.end(); ++itr)
          delete itr->second;

        m_by_id.clear();
      }

      void
      add(unsigned id, MotorChannel* channel)
      {
        channel->id = id;
        m_by_id[id] = channel;
      }

      std::map<unsigned, MotorChannel*>::const_iterator
      begin(void) const
      {
        return m_by_id.begin();
      }

      std::map<unsigned, MotorChannel*>::const_iterator
      end(void) const
      {
        return m_by_id.end();
      }

      std::map<unsigned, MotorChannel*>::iterator
      begin(void)
      {
        return m_by_id.begin();
      }

      std::map<unsigned, MotorChannel*>::iterator
      end(void)
      {
        return m_by_id.end();
      }

    private:
      std::map<unsigned, MotorChannel*> m_by_id;
    };
  }
}

#endif

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

#ifndef POWER_GHPB_NMEA_SENTENCE_HPP_INCLUDED_
#define POWER_GHPB_NMEA_SENTENCE_HPP_INCLUDED_

// DUNE headers.
#include <DUNE/DUNE.hpp>

namespace Power
{
  namespace GHPB
  {
    using DUNE_NAMESPACES;

    static const unsigned c_nmea_max_fields = 8;
    static const unsigned c_nmea_max_field_length = 32;
    static const unsigned c_nmea_max_length = c_nmea_max_fields * c_nmea_max_field_length;

    typedef char NMEAFields[c_nmea_max_fields][c_nmea_max_field_length];

    class NMEASentence
    {
      public:
        //! Empty initializer
        NMEASentence();

        //! Initialize with sentence
        NMEASentence(const char* sentence);

        //! Initialize with fields
        NMEASentence(const NMEAFields fields);

        //! Reset NMEA sentence
        void
        reset();

        //! Set NMEA sentence and get fields
        bool
        setSentence(const char* sentence);

        //! Add field and make sentence
        void
        addField(const char* field);

        //! Add numeric field and make sentence
        void
        addField(const char field);

        //! Add numeric field and make sentence
        void
        addField(const uint16_t field);

        //! Get field
        bool
        getField(uint8_t index, char* field);

        uint8_t
        getMaxFields()
        {
          return m_field_index;
        }

        //! Get NMEA sentence
        void
        getSentence(char* sentence);

        //! Check if sentence is valid
        //! @param sentence sentence to check
        //! @return true if valid, false otherwise
        static bool
        checkSentence(const char* sentence);

      private:
        //! NMEA sentence field array
        NMEAFields m_fields;
        //! Field index
        uint8_t m_field_index;
        //! Full NMEA sentence
        char m_sentence[c_nmea_max_length];

        //! Fill in fields from sentence
        void
        makeFields();

        //! Fill in fields from sentence
        void
        makeSentence();
    };
  }
}
#endif
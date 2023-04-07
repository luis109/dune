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

// Local headers.
#include "NMEASentence.hpp"

namespace Power
{
  namespace GHPB
  {
    uint8_t 
    xor_check(const char *data)
    {
      uint8_t csum = 0x00;
      uint8_t t = 0;

      while (data[t] != '\0')
      {
        csum ^= data[t];
        t++;
      }
      return csum;
    }

    NMEASentence::NMEASentence()
    {
      reset();
    }

    NMEASentence::NMEASentence(const char* sentence):
      NMEASentence()
    {
      printf("constructor got sentence\n");
      if (!checkSentence(sentence))
        return;

      printf("constructor sentence checked OK\n");
      strcpy(m_sentence, sentence);
      makeFields();

      // Debug
      // makeSentence();
    }

    NMEASentence::NMEASentence(const NMEAFields fields):
      NMEASentence()
    {
      for (uint8_t i = 0; i < c_nmea_max_fields; i++)
        strcpy(m_fields[i], fields[i]);
      makeSentence();

      // Debug
      // makeFields();
    }

    void
    NMEASentence::reset()
    {
      m_field_index = 0;

      memset(m_sentence,'\0', c_nmea_max_length);

      for (uint8_t i = 0; i < c_nmea_max_fields; i++)
        memset(m_fields[i],'\0', c_nmea_max_field_length);
    }

    bool
    NMEASentence::checkSentence(const char* sentence)
    {
      if (sentence[0] == '\0')
        return false;

      if (sentence[0] != '$')
        return false;

      std::string str(sentence);
      std::string msg = str.substr(1, str.find("*")-1);

      uint16_t csum;
      std::stringstream csum_bfr;
      csum_bfr << std::hex << str.substr(str.find("*") + 1, 2);
      csum_bfr >> csum;

      // sscanf(&sentence[1], "%[^*]*%x%*s", str, &csum);
      if (csum != (uint16_t)xor_check(msg.c_str()))
        return false;

      return true;
    }

    void
    NMEASentence::makeFields()
    {
      std::string str(m_sentence);

      // Strip '$' and checksum
      str = str.substr(1, str.find('*') - 1);

      // Restart index
      m_field_index = 0;

      // Seperate fields
      std::string bfr;
      std::stringstream ss(str);
      while(getline(ss, bfr, ','))
      {
        strcpy(m_fields[m_field_index], bfr.c_str());
        m_field_index++;
      }

      // for (uint8_t i = 0; i < m_field_index; i++)
      // {
      //   printf("makeFields Field %u: %s\n", i, m_fields[i]);
      // }
    }

    void
    NMEASentence::makeSentence()
    {
      // Build sentence with fields only
      char str[c_nmea_max_length];
      uint8_t lenght;

      lenght = sprintf(str, "%s", m_fields[0]);
      for (uint8_t i = 1; i < m_field_index; i++)
        lenght += sprintf(&str[lenght], ",%s", m_fields[i]);

      sprintf(m_sentence, "$%s*%02x\n", str, xor_check(str));
    }

    bool
    NMEASentence::setSentence(const char* sentence)
    {
      if (!checkSentence(sentence))
        return false;

      strcpy(m_sentence, sentence);
      makeFields();
      return true;
    }

    void
    NMEASentence::addField(const char* field)
    {
      sprintf(m_fields[m_field_index], "%s", field);
      m_field_index++;

      makeSentence();
    }

    void
    NMEASentence::addField(const char field)
    {
      sprintf(m_fields[m_field_index], "%c", field);
      m_field_index++;

      makeSentence();
    }

    void
    NMEASentence::addField(const uint16_t field)
    {
      sprintf(m_fields[m_field_index], "%u", field);
      m_field_index++;

      makeSentence();
    }

    bool
    NMEASentence::getField(uint8_t index, char* field)
    {
      if (index >= m_field_index)
        return false;

      strcpy(field, m_fields[index]);
      return true;
    }

    void
    NMEASentence::getSentence(char* sentence)
    {
      strcpy(sentence, m_sentence);
    }
  }
}
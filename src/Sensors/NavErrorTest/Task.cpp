//***************************************************************************
// Copyright 2007-2017 Universidade do Porto - Faculdade de Engenharia      *
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
// Author: Luis Venâncio                                                    *
//***************************************************************************

// DUNE headers.
#include <DUNE/DUNE.hpp>

namespace Sensors
{
  namespace NavErrorTest
  {
    using DUNE_NAMESPACES;

    static const float c_timestep = 0.01f;

    struct Task: public Tasks::Task
    {

      /****************************/
      /* Generic member variables */
      unsigned m_nav_eid;
      unsigned m_gps_eid;
      IMC::GpsFix m_last_gps;
      IMC::EstimatedState m_last_state;
      Time::Delta m_delta;

      /*************************/
      /* Euler message holders */
      IMC::Distance m_distance;
      IMC::Distance m_integrated;
      IMC::Distance m_mavg_dist;

      /**************************/
      /*********Counters********/
      unsigned m_num_gps;
      unsigned m_num_estate;

      /************************/
      /*****Moving Average****/
      MovingAverage<double> m_average = MovingAverage<double>(10);

      //! Constructor.
      //! @param[in] name task name.
      //! @param[in] ctx context.
      Task(const std::string& name, Tasks::Context& ctx):
        Tasks::Task(name, ctx)
      {
        bind<IMC::EstimatedState>(this);
        bind<IMC::GpsFix>(this);
      }

      //! Reserve entity identifiers.
      void
      onEntityReservation(void)
      {
        m_distance.setSourceEntity(reserveEntity(String::str("%s.distance", getEntityLabel())));
        m_integrated.setSourceEntity(reserveEntity(String::str("%s.integration", getEntityLabel())));
        m_mavg_dist.setSourceEntity(reserveEntity(String::str("%s.average", getEntityLabel())));
      }

      //! Resolve entity names.
      void
      onEntityResolution(void)
      {
        try
        {
          m_gps_eid = resolveEntity("GPS");
          m_nav_eid = resolveEntity("Navigation");
        }
        catch (...)
        {
          throw RestartNeeded("missing entity labels", 30);
        }
      }

      void
      onResourceAcquisition(void)
      {
        m_num_gps = 0;
        m_num_estate = 0;

        m_distance.value = 0;
        m_integrated.value = 0;
      }

      void
      consume(const IMC::EstimatedState* msg)
      {
        if (msg->getSource() != getSystemId())
          return;

        if (msg->getSourceEntity() != m_nav_eid)
          return;

        m_last_state = *msg;
        ++m_num_estate;

        double lat = 0, lon = 0;
        float hae = 0;
        Coordinates::toWGS84(m_last_state, lat, lon, hae);
        m_distance.value = WGS84::distance(lat, lon, hae, 
                                            m_last_gps.lat, 
                                            m_last_gps.lon, 
                                            m_last_gps.height);
        m_integrated.value += m_distance.value;
        m_mavg_dist.value = m_average.update(m_distance.value);


        m_distance.setTimeStamp();
        m_integrated.setTimeStamp(m_distance.getTimeStamp());
        m_mavg_dist.setTimeStamp(m_distance.getTimeStamp());

        dispatch(m_distance, DF_KEEP_TIME);
        dispatch(m_integrated, DF_KEEP_TIME);
        dispatch(m_mavg_dist, DF_KEEP_TIME);
      }

      void
      consume(const IMC::GpsFix* msg)
      {
        if (msg->getSource() != getSystemId())
          return;

        // Check fix validity.
        if ((msg->validity & IMC::GpsFix::GFV_VALID_POS) == 0)
          return;

        // Check if we have valid Horizontal Accuracy index.
        if (msg->validity & IMC::GpsFix::GFV_VALID_HACC && msg->hacc > 20)
          return;
        else if (msg->hdop > 4)
          return;

        m_last_gps = *msg;
        ++m_num_gps;
      }

      //! Main loop.
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
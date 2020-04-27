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

// Standard headers
#include <csignal>

// DUNE headers.
#include <DUNE/DUNE.hpp>
#include <DUNE/Parsers/Exceptions.hpp>

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
      IMC::GpsFix m_origin;
      IMC::EstimatedState m_last_state;
      unsigned m_test_num;
      std::string m_dat_path;
      std::vector<std::string> m_test_param;
      bool m_valid;
      bool m_aligned;

      /*************************/
      /* Euler message holders */
      double m_integrated;
      IMC::Distance m_distance;
      IMC::Distance m_intavg_dist;
      IMC::Distance m_mavg_dist;
      IMC::EulerAngles m_bearing;

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
        param("Test Number", m_test_num)
        .defaultValue("0")
        .description("Test number");

        param("Path To Data Folder", m_dat_path)
        .defaultValue("")
        .description("Path to output data folder");

        param("Testing Parameters", m_test_param)
        .defaultValue("")
        .description("Parameters being tested");

        bind<IMC::EstimatedState>(this);
        bind<IMC::GpsFix>(this);
        bind<IMC::DevDataText>(this);
      }

      //! Reserve entity identifiers.
      void
      onEntityReservation(void)
      {
        m_distance.setSourceEntity(reserveEntity(String::str("%s.distance", getEntityLabel())));
        m_intavg_dist.setSourceEntity(reserveEntity(String::str("%s.integration", getEntityLabel())));
        m_mavg_dist.setSourceEntity(reserveEntity(String::str("%s.average", getEntityLabel())));
        m_bearing.setSourceEntity(reserveEntity(String::str("%s.bearing", getEntityLabel())));
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
        m_valid = true;
        m_aligned = false;

        m_num_gps = 0;
        m_num_estate = 0;

        m_integrated = 0;
        m_distance.value = 0;
        m_intavg_dist.value = 0;
      }

      void
      consume(const IMC::DevDataText* msg)
      {
        if (msg->getSourceEntity() != m_nav_eid)
          return;

        if (String::startsWith(msg->value, "GPS disabled"))
        {
          m_aligned = true;
          return;
        }

        if (!String::startsWith(msg->value, "shutdown"))
          return;

        // inf("Stop in NavErrorTest: %f", Time::Clock::get());
        m_valid = false;
        inf("%s", msg->value.c_str());
        inf("%s", m_ctx.config.files().back().c_str());
        std::raise(SIGINT);
      }

      void
      consume(const IMC::EstimatedState* msg)
      {
        if (msg->getSource() != getSystemId())
          return;

        if (msg->getSourceEntity() != m_nav_eid)
          return;

        if (!m_aligned)
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
        m_integrated += m_distance.value;
        m_intavg_dist.value = m_integrated / (double)m_num_estate;
        m_mavg_dist.value = m_average.update(m_distance.value);


        m_distance.setTimeStamp();
        m_intavg_dist.setTimeStamp(m_distance.getTimeStamp());
        m_mavg_dist.setTimeStamp(m_distance.getTimeStamp());

        dispatch(m_distance, DF_KEEP_TIME);
        dispatch(m_intavg_dist, DF_KEEP_TIME);
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
        
        if (m_num_gps == 0)
        {
          m_origin = *msg;
        }
        else
        {
          IMC::EstimatedState aux[2];
          try
          {
            Coordinates::WGS84::displacement(m_origin.lat, m_origin.lon, m_origin.height,
                                          m_last_gps.lat, m_last_gps.lon, m_last_gps.height,
                                          &aux[0].x, &aux[0].y, &aux[0].z);

            Coordinates::WGS84::displacement(m_origin.lat, m_origin.lon, m_origin.height,
                                          msg->lat, msg->lon, msg->height,
                                          &aux[1].x, &aux[1].y, &aux[1].z);

            m_bearing.psi = getBearing(aux[0], aux[1]);
            dispatch(m_bearing);
          }
          catch(...)
          {
            IMC::DevDataText shutdown;
            shutdown.value = "shutdown: Coordinates NavErrorTest";
            dispatch(shutdown);
          }
        }

        m_last_gps = *msg;
        ++m_num_gps;
      }

      void
      outResult()
      {
        std::vector<double> parameters;
        std::string file_name = "test_" + String::str(m_test_num) + ".dat";
        std::string file_path = m_dat_path + "/" + file_name;
        std::FILE* fd = std::fopen(file_path.c_str(), "w+");

        if (!m_valid)
          m_intavg_dist.value = -1;
        
        
        for (auto itr = m_test_param.begin(); itr != m_test_param.end(); ++itr)
        {
          std::vector<double> local_param;
          m_ctx.config.get("Navigation.AUV.Navigation", 
                          *itr, 
                          "0, 0", local_param);
          
          parameters.insert(parameters.end(), local_param.begin(), local_param.end());
        }

        if (fd == 0)
          throw FileOpenError(file_name, System::Error::getLastMessage());
        else
        {
          fprintf(fd, "%d ", m_test_num);
          auto itr = parameters.begin();
          for (; itr != parameters.end(); ++itr)
          {
            fprintf(fd, "%e ", *itr);
          }
          fprintf(fd, "%f\n", m_intavg_dist.value);
        }
      }

      //! Main loop.
      void
      onMain(void)
      {
        while(!stopping())
        {
          waitForMessages(1.0);
        }
        
        outResult();
      }
    };
  }
}

DUNE_TASK
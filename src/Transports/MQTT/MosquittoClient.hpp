//***************************************************************************
// Copyright 2007-2022 Universidade do Porto - Faculdade de Engenharia      *
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

#ifndef TRANSPORTS_MQTT_MOSQUITTO_CLIENT_HPP_INCLUDED_
#define TRANSPORTS_MQTT_MOSQUITTO_CLIENT_HPP_INCLUDED_

// DUNE headers.
#include <DUNE/DUNE.hpp>
#ifdef DUNE_USING_MOSQUITTO
#include <mosquitto.h>
#endif


namespace Transports
{
  //! Insert short task description here.
  //!
  //! Insert explanation on task behaviour here.
  //! @author Luis Venancio
  namespace MQTT
  {
    using DUNE_NAMESPACES;

    //! Maximum topic length (in bytes)
    const uint32_t c_max_topic = 65536;
    //! Maximum payload length (in bytes)
    // TODO: This is too much!!
    // const uint32_t c_max_payload = 268435455; // 255 MB
    const uint32_t c_max_payload = 1048576; // 1 MB

    class MosquittoClient: public Concurrency::Thread
    {
    public:
      //! Arguments
      struct
      Arguments
      {
        //! Client id
        std::string client_id;
        //! Broker address
        Address address;
        //! Broker port
        int port;
        //! Broker ping period (in seconds).
        //! Broker pings if no other messages were exchanged in this interval
        int keepalive;
        //! Message retain flag
        bool retain;

        //! User. For user + password authetication
        std::string usr;
        //! Password. For user + password authetication
        std::string pw;
      };

      //! Constructor.
      //! @param[in] task parent task.
      MosquittoClient(Tasks::Task* task, const Arguments* args):
      m_task(task),
      m_args(args)
      {
#ifdef DUNE_USING_MOSQUITTO
        // Clear errors
        m_err_str.clear();
        //required by mosquitto_lib_init()
        mosquitto_threaded_set(m_mosq, true);

        // Initialize library
	      mosquitto_lib_init();
        try
        {
          m_mosq = mosquitto_new(m_args->client_id.c_str(), true, this);
        }
        catch(const std::exception& e)
        {
          throw std::runtime_error(String::str("Client error: %s", e.what()).c_str());
        }

        // Authetication
        setAuthentication();

        // Callbacks
        setCallbacks();

        // Connect to broker
        connect();
#else
        throw RestartNeeded("Mosquitto option disabled or no library found", 10);
#endif
      }

      //! Destructor.
      ~MosquittoClient(void)
      {
#ifdef DUNE_USING_MOSQUITTO
        // libmosquitto cleanup
		    mosquitto_destroy(m_mosq);
        mosquitto_lib_cleanup();
#endif
      }

      void
      subscribe(std::string topic)
      {
#ifdef DUNE_USING_MOSQUITTO
        checkRC(mosquitto_subscribe(m_mosq, NULL, topic.c_str(), 0));
#else
        (void) topic;
        throw RestartNeeded("Mosquitto option disabled or no library found", 10);
#endif
      }

      void
      subscribe(std::vector<std::string> topics)
      {
        for(unsigned i = 0; i < topics.size(); i++)
          subscribe(topics[i]);
      }

      bool
      poll(std::string& topic, std::string& payload)
      {
#ifdef DUNE_USING_MOSQUITTO
        mosquitto_message msg;

        if (!m_queue.pop(msg))
          return false;

        // TODO: Sanitize string
        topic = std::string(msg.topic);
        payload = std::string((char*)msg.payload, msg.payloadlen);
        
        return true;
#else
        (void) topic;
        (void) payload;
        throw RestartNeeded("Mosquitto option disabled or no library found", 10);
#endif
      }

      bool
      poll(char* topic, uint8_t* payload, uint32_t* payload_length)
      {
#ifdef DUNE_USING_MOSQUITTO
        mosquitto_message msg;

        if (!m_queue.pop(msg))
          return false;

        std::strcpy(topic, msg.topic);
        std::memcpy(payload, (uint8_t*)msg.payload, msg.payloadlen);
        *payload_length = msg.payloadlen;
        
        return true;
#else
        (void) topic;
        (void) payload;
        (void) payload_length;
        throw RestartNeeded("Mosquitto option disabled or no library found", 10);
#endif
      }

      void
      publish(std::string topic, uint8_t* payload, uint32_t payload_length)
      {
#ifdef DUNE_USING_MOSQUITTO
        checkRC(mosquitto_publish(m_mosq, NULL, topic.c_str(), 
                                  payload_length, payload, 0, m_args->retain));
        m_task->spew("sent: %s: %s", topic.c_str(), sanitize(std::string((char*)payload, payload_length).c_str()).c_str());
#else
        (void) topic;
        (void) payload;
        (void) payload_length;
        throw RestartNeeded("Mosquitto option disabled or no library found", 10);
#endif
      }

      void
      publish(std::string topic, std::string payload)
      {
        publish(topic, (uint8_t*)payload.c_str(), payload.size());
      }

      //! Main loop
      void
      run(void)
      {
        while (!isStopping())
        {
#ifdef DUNE_USING_MOSQUITTO
          checkRC(mosquitto_loop(m_mosq, -1, 1));
#else
          throw RestartNeeded("Mosquitto option disabled or no library found", 10);
#endif
        }
      }

      bool
      hasError(std::string& err_msg)
      {
#ifdef DUNE_USING_MOSQUITTO
        if (!m_err_str.empty())
        {
          err_msg = m_err_str;
          m_err_str.clear();
          return true;
        }

        return false;
#else
        (void) err_msg;
        throw RestartNeeded("Mosquitto option disabled or no library found", 10);
#endif
      }

    private:
      //! Task
      Tasks::Task* m_task;
      //! Arguments
      const Arguments* m_args;
#ifdef DUNE_USING_MOSQUITTO
      //! Mosquitto instance
	    mosquitto *m_mosq;
      //! Message queue
      TSQueue<mosquitto_message> m_queue;
      //! Error string. Since the client runs on a separate thread 
      //! the string is used as a flag to poll for client error.
      std::string m_err_str;
#endif

      void
      setAuthentication()
      {
#ifdef DUNE_USING_MOSQUITTO
        // TODO: Certificate authentication, as default
        // User + password login
        const char* user = m_args->usr.empty() ? NULL : m_args->usr.c_str();
        const char* password = m_args->pw.empty() ? NULL : m_args->pw.c_str();
        checkRC(mosquitto_username_pw_set(m_mosq, user, password));
#else
        throw RestartNeeded("Mosquitto option disabled or no library found", 10);
#endif
      }

      void
      connect()
      {
#ifdef DUNE_USING_MOSQUITTO
        checkRC(mosquitto_connect(m_mosq, m_args->address.str().c_str(), 
                                          m_args->port, 
                                          m_args->keepalive));
#else
        throw RestartNeeded("Mosquitto option disabled or no library found", 10);
#endif
      }

      void
      setCallbacks()
      {
#ifdef DUNE_USING_MOSQUITTO
        mosquitto_connect_callback_set(m_mosq, on_connect);
        mosquitto_disconnect_callback_set(m_mosq, on_disconnect);
        mosquitto_message_callback_set(m_mosq, on_message);
        mosquitto_publish_callback_set(m_mosq, on_publish);
        mosquitto_subscribe_callback_set(m_mosq, on_subscribe);
        mosquitto_unsubscribe_callback_set(m_mosq, on_unsubscribe);
#else
        throw RestartNeeded("Mosquitto option disabled or no library found", 10);
#endif
      }

      // CALLBACKS
      //! Connect callback function
      static void 
      on_connect(struct mosquitto *mosq, void *obj, int rc)
      {
#ifdef DUNE_USING_MOSQUITTO
        (void) mosq;
        MosquittoClient* self = (MosquittoClient*) obj;

        self->m_task->inf("Connected to broker");
        self->checkRC(rc);
#else
        (void) mosq;
        (void) obj;
        (void) rc;
        throw RestartNeeded("Mosquitto option disabled or no library found", 10);
#endif
      }
      
      //! Disconnect callback function
      static void
      on_disconnect(struct mosquitto *mosq, void *obj, int rc)
      {
#ifdef DUNE_USING_MOSQUITTO
        (void) mosq;
        MosquittoClient* self = (MosquittoClient*)obj;
        
        self->m_task->inf("Disconnected from broker");
        self->checkRC(rc);
#else
        (void) mosq;
        (void) obj;
        (void) rc;
        throw RestartNeeded("Mosquitto option disabled or no library found", 10);
#endif
      }
      
      //! Message callback function
      static void
      on_message(struct mosquitto *mosq, void *obj, const struct mosquitto_message *msg)
      {
#ifdef DUNE_USING_MOSQUITTO
        (void) mosq;
        MosquittoClient* self = (MosquittoClient*)obj;

        mosquitto_message bfr;
        mosquitto_message_copy(&bfr, msg);
        self->m_queue.push(bfr);
        self->m_task->spew("recv: %s: %s", msg->topic, sanitize(std::string((char*)msg->payload, msg->payloadlen).c_str()).c_str());
#else
        (void) mosq;
        (void) obj;
        (void) msg;
        throw RestartNeeded("Mosquitto option disabled or no library found", 10);
#endif
      }

      //! Publish callback function
      static void
      on_publish(struct mosquitto *mosq, void *obj, int msg_id)
      {
#ifdef DUNE_USING_MOSQUITTO
        (void) mosq;
        MosquittoClient* self = (MosquittoClient*)obj;

        self->m_task->spew("Published msg id: %d", msg_id);
#else
        (void) mosq;
        (void) obj;
        (void) msg_id;
        throw RestartNeeded("Mosquitto option disabled or no library found", 10);
#endif
      }

      //! Subscribe callback function
      static void 
      on_subscribe(struct mosquitto *mosq, void *obj, int msg_id, int sub_count, const int * granted_qos)
      {
#ifdef DUNE_USING_MOSQUITTO
        (void) mosq;
        MosquittoClient* self = (MosquittoClient*)obj;

        (void) msg_id;
        self->m_task->inf("Granted subscriptions: %d", sub_count);
        (void) granted_qos;
#else
        (void) mosq;
        (void) obj;
        (void) msg_id;
        (void) sub_count;
        (void) granted_qos;
        throw RestartNeeded("Mosquitto option disabled or no library found", 10);
#endif
      }
      
      //! Subscribe callback function
      static void 
      on_unsubscribe(struct mosquitto *mosq, void *obj, int msg_id)
      {
#ifdef DUNE_USING_MOSQUITTO
        (void) mosq;
        MosquittoClient* self = (MosquittoClient*)obj;

        (void) msg_id;
        self->m_task->inf("Unsubscribed from topic");
#else
        (void) mosq;
        (void) obj;
        (void) msg_id;
        throw RestartNeeded("Mosquitto option disabled or no library found", 10);
#endif
      }

      void
      checkRC(unsigned rc)
      {
#ifdef DUNE_USING_MOSQUITTO
        if (rc && m_err_str.empty())
        {
          m_err_str = String::str("Client Error: %s", mosquitto_strerror(rc));
        }
#else
        (void) rc;
        throw RestartNeeded("Mosquitto option disabled or no library found", 10);
#endif
      }
    };
  }
}

#endif
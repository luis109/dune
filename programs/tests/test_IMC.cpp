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
// Author: Ricardo Martins                                                  *
//***************************************************************************
// Automatically generated.                                                 *
//***************************************************************************
// IMC XML MD5: 940c845def4491a3e2c46b5656c7d41a                            *
//***************************************************************************

// DUNE headers.
#include <DUNE/DUNE.hpp>

using DUNE_NAMESPACES;

#include "Test.hpp"

int
main(void)
{
  Test test("IMC Serialization/Deserialization");

  {
    IMC::EntityState msg;
    msg.setTimeStamp(0.8852177704317112);
    msg.setSource(26185U);
    msg.setSourceEntity(56U);
    msg.setDestination(9170U);
    msg.setDestinationEntity(191U);
    msg.state = 224U;
    msg.flags = 253U;
    msg.description.assign("QOFYHXYQLJINKWVHFRPZUACJUEURDNVRGCKHRNWQAVSIQLHCBPYBDFDKCADDATBMXEOJZOESMEDSYSEPWZRWHHIMEYQQYPTLFESRGAXWPJCIBEPNJULVHVFWTXOMAMMGFUTUQTNWZJZCNVGVPHXXJNCAYBLKXLHWQQTMUGIIRSRMUOIPFUBSF");

    try
    {
      Utils::ByteBuffer bfr;
      IMC::Packet::serialize(&msg, bfr);
      IMC::Message* msg_d = IMC::Packet::deserialize(bfr.getBuffer(), bfr.getSize());
      test.boolean("EntityState #0", msg == *msg_d);
      delete msg_d;
    }
    catch (IMC::InvalidMessageSize& e)
    {
      (void)e;
      test.boolean("msg #0", msg.getSerializationSize() > DUNE_IMC_CONST_MAX_SIZE);
    }
  }

  {
    IMC::EntityState msg;
    msg.setTimeStamp(0.7331183435681684);
    msg.setSource(50521U);
    msg.setSourceEntity(155U);
    msg.setDestination(16369U);
    msg.setDestinationEntity(87U);
    msg.state = 20U;
    msg.flags = 46U;
    msg.description.assign("KGMLPMBTAIJAVHJNMECCACEDCUOEEAFXPOPFHZBWIVCWBDUDIXRWYYRQTRYRRCUBTLBVDJKZQWXQ");

    try
    {
      Utils::ByteBuffer bfr;
      IMC::Packet::serialize(&msg, bfr);
      IMC::Message* msg_d = IMC::Packet::deserialize(bfr.getBuffer(), bfr.getSize());
      test.boolean("EntityState #1", msg == *msg_d);
      delete msg_d;
    }
    catch (IMC::InvalidMessageSize& e)
    {
      (void)e;
      test.boolean("msg #1", msg.getSerializationSize() > DUNE_IMC_CONST_MAX_SIZE);
    }
  }

  {
    IMC::EntityState msg;
    msg.setTimeStamp(0.42882047570319504);
    msg.setSource(48376U);
    msg.setSourceEntity(93U);
    msg.setDestination(36170U);
    msg.setDestinationEntity(142U);
    msg.state = 27U;
    msg.flags = 83U;
    msg.description.assign("DRTDGGJYFHLRLKQMKXYUOKANNFZRREGMRIULXVLPPHIVBTJUOHWGGVLZSVLAAEFTCXBSMV");

    try
    {
      Utils::ByteBuffer bfr;
      IMC::Packet::serialize(&msg, bfr);
      IMC::Message* msg_d = IMC::Packet::deserialize(bfr.getBuffer(), bfr.getSize());
      test.boolean("EntityState #2", msg == *msg_d);
      delete msg_d;
    }
    catch (IMC::InvalidMessageSize& e)
    {
      (void)e;
      test.boolean("msg #2", msg.getSerializationSize() > DUNE_IMC_CONST_MAX_SIZE);
    }
  }

  {
    IMC::QueryEntityState msg;
    msg.setTimeStamp(0.0990185904817581);
    msg.setSource(21478U);
    msg.setSourceEntity(213U);
    msg.setDestination(30655U);
    msg.setDestinationEntity(120U);

    try
    {
      Utils::ByteBuffer bfr;
      IMC::Packet::serialize(&msg, bfr);
      IMC::Message* msg_d = IMC::Packet::deserialize(bfr.getBuffer(), bfr.getSize());
      test.boolean("QueryEntityState #0", msg == *msg_d);
      delete msg_d;
    }
    catch (IMC::InvalidMessageSize& e)
    {
      (void)e;
      test.boolean("msg #0", msg.getSerializationSize() > DUNE_IMC_CONST_MAX_SIZE);
    }
  }

  {
    IMC::QueryEntityState msg;
    msg.setTimeStamp(0.9491114669072992);
    msg.setSource(35621U);
    msg.setSourceEntity(186U);
    msg.setDestination(11953U);
    msg.setDestinationEntity(160U);

    try
    {
      Utils::ByteBuffer bfr;
      IMC::Packet::serialize(&msg, bfr);
      IMC::Message* msg_d = IMC::Packet::deserialize(bfr.getBuffer(), bfr.getSize());
      test.boolean("QueryEntityState #1", msg == *msg_d);
      delete msg_d;
    }
    catch (IMC::InvalidMessageSize& e)
    {
      (void)e;
      test.boolean("msg #1", msg.getSerializationSize() > DUNE_IMC_CONST_MAX_SIZE);
    }
  }

  {
    IMC::QueryEntityState msg;
    msg.setTimeStamp(0.8107719488426307);
    msg.setSource(39863U);
    msg.setSourceEntity(185U);
    msg.setDestination(42932U);
    msg.setDestinationEntity(18U);

    try
    {
      Utils::ByteBuffer bfr;
      IMC::Packet::serialize(&msg, bfr);
      IMC::Message* msg_d = IMC::Packet::deserialize(bfr.getBuffer(), bfr.getSize());
      test.boolean("QueryEntityState #2", msg == *msg_d);
      delete msg_d;
    }
    catch (IMC::InvalidMessageSize& e)
    {
      (void)e;
      test.boolean("msg #2", msg.getSerializationSize() > DUNE_IMC_CONST_MAX_SIZE);
    }
  }

  {
    IMC::EntityInfo msg;
    msg.setTimeStamp(0.49270680334087835);
    msg.setSource(30092U);
    msg.setSourceEntity(127U);
    msg.setDestination(33186U);
    msg.setDestinationEntity(134U);
    msg.id = 149U;
    msg.label.assign("WRUPHFOKDNAQTLRGRQCATRBCMVIENITAWEMHIXWWBAPFLMXWEYIFZEBQGNMJSIMQITIOUJPWZQJUHVTSFJYTWSXDQRIKDSLZGHSQODCYKNUVKJYGTRZFULNJVLCAZFLUKDCKYATTUGWHBLNDZPEAQJBYBPEBXPGCEUJFJVHFAPMFDUUIOMZZAYFVGGWPLXNKCGONCNVCOZOESVCLBYZQSHHBY");
    msg.component.assign("MXCYKTKCWMGQMJWMFYIRVKMIQBODPIPYKSQRWWZCZXFSZLPEANVJUKZEQHJUZNYZGVBLXWLXHSHEITQSPBIPLUOULPERDVCHOFRQSVTFGBHPMSRYCJBTFKGJQNXHDACOTFUZWYFTSTFLEOEBRLMCSVDAXIYNBTRPXWZGNIFPNYDVNRCOODBHLUNZLNMTRZMGYMAGNJJRWWGGJHQIVUXOOBQBEFXSIVCTKGSAJ");
    msg.act_time = 31316U;
    msg.deact_time = 59942U;

    try
    {
      Utils::ByteBuffer bfr;
      IMC::Packet::serialize(&msg, bfr);
      IMC::Message* msg_d = IMC::Packet::deserialize(bfr.getBuffer(), bfr.getSize());
      test.boolean("EntityInfo #0", msg == *msg_d);
      delete msg_d;
    }
    catch (IMC::InvalidMessageSize& e)
    {
      (void)e;
      test.boolean("msg #0", msg.getSerializationSize() > DUNE_IMC_CONST_MAX_SIZE);
    }
  }

  {
    IMC::EntityInfo msg;
    msg.setTimeStamp(0.4441447386968417);
    msg.setSource(18975U);
    msg.setSourceEntity(106U);
    msg.setDestination(39178U);
    msg.setDestinationEntity(243U);
    msg.id = 30U;
    msg.label.assign("IPOHXHQWPWQBZVDAJTSZCXKWS");
    msg.component.assign("HCKYFDOZDFIKMNBATSBHUNEAOLDEKHJADKIMKVAFWKAPXSWUDCANZQBCTUPOHPGRGJZQSJYIRWQPPFOEMSIBWMVEZLB");
    msg.act_time = 27823U;
    msg.deact_time = 26974U;

    try
    {
      Utils::ByteBuffer bfr;
      IMC::Packet::serialize(&msg, bfr);
      IMC::Message* msg_d = IMC::Packet::deserialize(bfr.getBuffer(), bfr.getSize());
      test.boolean("EntityInfo #1", msg == *msg_d);
      delete msg_d;
    }
    catch (IMC::InvalidMessageSize& e)
    {
      (void)e;
      test.boolean("msg #1", msg.getSerializationSize() > DUNE_IMC_CONST_MAX_SIZE);
    }
  }

  {
    IMC::EntityInfo msg;
    msg.setTimeStamp(0.9363624549769861);
    msg.setSource(49606U);
    msg.setSourceEntity(171U);
    msg.setDestination(64520U);
    msg.setDestinationEntity(154U);
    msg.id = 14U;
    msg.label.assign("CTVDNJUHUNZBMOFNCRMOUKNTTZXPLTSSNUABURCKIETYFPYYMSAQRZNRPQRUDZBKHORETXFGKLGEZBVYJTAFVNBQNUPFJICYFXVDYRGNOPMQBMKGRYPHJRCAVKUSVIKWWWCOLOIHKDMGADLWTEDWJJPBOZKAQSXEAALFEAJXHNXYOIF");
    msg.component.assign("ZWOMRXXLMKRNRQTBGIPSLKMRIJIMFRXJXDIZBAUDEXUUQAOGAVRWQRZHESVPBSPCNAEZGPHMUVMYUFXCPYHBHDYQMEG");
    msg.act_time = 5566U;
    msg.deact_time = 16047U;

    try
    {
      Utils::ByteBuffer bfr;
      IMC::Packet::serialize(&msg, bfr);
      IMC::Message* msg_d = IMC::Packet::deserialize(bfr.getBuffer(), bfr.getSize());
      test.boolean("EntityInfo #2", msg == *msg_d);
      delete msg_d;
    }
    catch (IMC::InvalidMessageSize& e)
    {
      (void)e;
      test.boolean("msg #2", msg.getSerializationSize() > DUNE_IMC_CONST_MAX_SIZE);
    }
  }

  {
    IMC::QueryEntityInfo msg;
    msg.setTimeStamp(0.7999611100389042);
    msg.setSource(20896U);
    msg.setSourceEntity(225U);
    msg.setDestination(49460U);
    msg.setDestinationEntity(14U);
    msg.id = 70U;

    try
    {
      Utils::ByteBuffer bfr;
      IMC::Packet::serialize(&msg, bfr);
      IMC::Message* msg_d = IMC::Packet::deserialize(bfr.getBuffer(), bfr.getSize());
      test.boolean("QueryEntityInfo #0", msg == *msg_d);
      delete msg_d;
    }
    catch (IMC::InvalidMessageSize& e)
    {
      (void)e;
      test.boolean("msg #0", msg.getSerializationSize() > DUNE_IMC_CONST_MAX_SIZE);
    }
  }

  {
    IMC::QueryEntityInfo msg;
    msg.setTimeStamp(0.893343621594687);
    msg.setSource(1396U);
    msg.setSourceEntity(188U);
    msg.setDestination(45664U);
    msg.setDestinationEntity(89U);
    msg.id = 243U;

    try
    {
      Utils::ByteBuffer bfr;
      IMC::Packet::serialize(&msg, bfr);
      IMC::Message* msg_d = IMC::Packet::deserialize(bfr.getBuffer(), bfr.getSize());
      test.boolean("QueryEntityInfo #1", msg == *msg_d);
      delete msg_d;
    }
    catch (IMC::InvalidMessageSize& e)
    {
      (void)e;
      test.boolean("msg #1", msg.getSerializationSize() > DUNE_IMC_CONST_MAX_SIZE);
    }
  }

  {
    IMC::QueryEntityInfo msg;
    msg.setTimeStamp(0.8564679388817192);
    msg.setSource(44051U);
    msg.setSourceEntity(220U);
    msg.setDestination(17098U);
    msg.setDestinationEntity(66U);
    msg.id = 193U;

    try
    {
      Utils::ByteBuffer bfr;
      IMC::Packet::serialize(&msg, bfr);
      IMC::Message* msg_d = IMC::Packet::deserialize(bfr.getBuffer(), bfr.getSize());
      test.boolean("QueryEntityInfo #2", msg == *msg_d);
      delete msg_d;
    }
    catch (IMC::InvalidMessageSize& e)
    {
      (void)e;
      test.boolean("msg #2", msg.getSerializationSize() > DUNE_IMC_CONST_MAX_SIZE);
    }
  }

  {
    IMC::EntityList msg;
    msg.setTimeStamp(0.3566534661962746);
    msg.setSource(56635U);
    msg.setSourceEntity(76U);
    msg.setDestination(42625U);
    msg.setDestinationEntity(85U);
    msg.op = 120U;
    msg.list.assign("CDRBQPUSGMWKVPIIWQNSTNBFCHFXXTWBOSJOINHVPKELHTRRWKCABTGNYUKQGDTWRZLZRRQRARJZFELDGXCFZNTSULAACNENZMUVXJEKBXBMYXNASUAJXHYBGOBIWBFJVIRPCZAB");

    try
    {
      Utils::ByteBuffer bfr;
      IMC::Packet::serialize(&msg, bfr);
      IMC::Message* msg_d = IMC::Packet::deserialize(bfr.getBuffer(), bfr.getSize());
      test.boolean("EntityList #0", msg == *msg_d);
      delete msg_d;
    }
    catch (IMC::InvalidMessageSize& e)
    {
      (void)e;
      test.boolean("msg #0", msg.getSerializationSize() > DUNE_IMC_CONST_MAX_SIZE);
    }
  }

  {
    IMC::EntityList msg;
    msg.setTimeStamp(0.4197117763620023);
    msg.setSource(5487U);
    msg.setSourceEntity(235U);
    msg.setDestination(20548U);
    msg.setDestinationEntity(200U);
    msg.op = 104U;
    msg.list.assign("YFHPMDAPEBYJWQBIUYKAEQLBHEMSSWJFUXAGNORCDIYDGSEAMBFMEZZXIUYSIXXFEBKQKITJYBHKULZPVFDCGWBZBVWAEVTSHOJBDQGPWNFNTNRNOTSHQMCSHXLDPOZPDXZTJXDVFLLXYWODKTCORUXWLGWJMRZHVPTQRURYOUCAMHRCQCGTMIDILYKVJAWKNIIVGACQOWOJNNYQEMVUEPZNRLNZFUAOMS");

    try
    {
      Utils::ByteBuffer bfr;
      IMC::Packet::serialize(&msg, bfr);
      IMC::Message* msg_d = IMC::Packet::deserialize(bfr.getBuffer(), bfr.getSize());
      test.boolean("EntityList #1", msg == *msg_d);
      delete msg_d;
    }
    catch (IMC::InvalidMessageSize& e)
    {
      (void)e;
      test.boolean("msg #1", msg.getSerializationSize() > DUNE_IMC_CONST_MAX_SIZE);
    }
  }

  {
    IMC::EntityList msg;
    msg.setTimeStamp(0.18321524325465388);
    msg.setSource(57567U);
    msg.setSourceEntity(170U);
    msg.setDestination(63340U);
    msg.setDestinationEntity(178U);
    msg.op = 123U;
    msg.list.assign("KHTXLPUTXSKFYXZEQCJQRMOOAVBWPKOPXDWLZYINIJNWJRMYXQNKJJQTGISDIRJBZV");

    try
    {
      Utils::ByteBuffer bfr;
      IMC::Packet::serialize(&msg, bfr);
      IMC::Message* msg_d = IMC::Packet::deserialize(bfr.getBuffer(), bfr.getSize());
      test.boolean("EntityList #2", msg == *msg_d);
      delete msg_d;
    }
    catch (IMC::InvalidMessageSize& e)
    {
      (void)e;
      test.boolean("msg #2", msg.getSerializationSize() > DUNE_IMC_CONST_MAX_SIZE);
    }
  }

  {
    IMC::CpuUsage msg;
    msg.setTimeStamp(0.0893188201775198);
    msg.setSource(9352U);
    msg.setSourceEntity(56U);
    msg.setDestination(52935U);
    msg.setDestinationEntity(226U);
    msg.value = 45U;

    try
    {
      Utils::ByteBuffer bfr;
      IMC::Packet::serialize(&msg, bfr);
      IMC::Message* msg_d = IMC::Packet::deserialize(bfr.getBuffer(), bfr.getSize());
      test.boolean("CpuUsage #0", msg == *msg_d);
      delete msg_d;
    }
    catch (IMC::InvalidMessageSize& e)
    {
      (void)e;
      test.boolean("msg #0", msg.getSerializationSize() > DUNE_IMC_CONST_MAX_SIZE);
    }
  }

  {
    IMC::CpuUsage msg;
    msg.setTimeStamp(0.07098776372926108);
    msg.setSource(53966U);
    msg.setSourceEntity(247U);
    msg.setDestination(1692U);
    msg.setDestinationEntity(213U);
    msg.value = 208U;

    try
    {
      Utils::ByteBuffer bfr;
      IMC::Packet::serialize(&msg, bfr);
      IMC::Message* msg_d = IMC::Packet::deserialize(bfr.getBuffer(), bfr.getSize());
      test.boolean("CpuUsage #1", msg == *msg_d);
      delete msg_d;
    }
    catch (IMC::InvalidMessageSize& e)
    {
      (void)e;
      test.boolean("msg #1", msg.getSerializationSize() > DUNE_IMC_CONST_MAX_SIZE);
    }
  }

  {
    IMC::CpuUsage msg;
    msg.setTimeStamp(0.3930636690274528);
    msg.setSource(39200U);
    msg.setSourceEntity(252U);
    msg.setDestination(48337U);
    msg.setDestinationEntity(28U);
    msg.value = 101U;

    try
    {
      Utils::ByteBuffer bfr;
      IMC::Packet::serialize(&msg, bfr);
      IMC::Message* msg_d = IMC::Packet::deserialize(bfr.getBuffer(), bfr.getSize());
      test.boolean("CpuUsage #2", msg == *msg_d);
      delete msg_d;
    }
    catch (IMC::InvalidMessageSize& e)
    {
      (void)e;
      test.boolean("msg #2", msg.getSerializationSize() > DUNE_IMC_CONST_MAX_SIZE);
    }
  }

  {
    IMC::TransportBindings msg;
    msg.setTimeStamp(0.9172641425496207);
    msg.setSource(14221U);
    msg.setSourceEntity(241U);
    msg.setDestination(21133U);
    msg.setDestinationEntity(171U);
    msg.consumer.assign("EQCWNCCRCBIAGIFSRGWRPKOMDKKAVSPLXTLBMAJMHYYKWEMPYCQNXWNYULBJTTUUONWBSTZJBCAVHNIYRPRZIMABEKXZXQNFTMIVODXDEAESZUUQTZHLTIZALQGXMJJAGASNHWDUFQTJIRHEGHOFREHZCGUGG");
    msg.message_id = 47173U;

    try
    {
      Utils::ByteBuffer bfr;
      IMC::Packet::serialize(&msg, bfr);
      IMC::Message* msg_d = IMC::Packet::deserialize(bfr.getBuffer(), bfr.getSize());
      test.boolean("TransportBindings #0", msg == *msg_d);
      delete msg_d;
    }
    catch (IMC::InvalidMessageSize& e)
    {
      (void)e;
      test.boolean("msg #0", msg.getSerializationSize() > DUNE_IMC_CONST_MAX_SIZE);
    }
  }

  {
    IMC::TransportBindings msg;
    msg.setTimeStamp(0.2000217437265679);
    msg.setSource(8486U);
    msg.setSourceEntity(80U);
    msg.setDestination(2747U);
    msg.setDestinationEntity(227U);
    msg.consumer.assign("ILREBGXZUFAQEPFBRZZXYVBCGEQVFITCYOFFOJGSYIANPTINDLWSXYZWGVEQHPJKCJPOHATQSAZLQAWJKDYLURCWBVAIAHXVZBOXOVXODZMRKNTSGDVMOQEEHUPUDMNWFZDCBEJH");
    msg.message_id = 54350U;

    try
    {
      Utils::ByteBuffer bfr;
      IMC::Packet::serialize(&msg, bfr);
      IMC::Message* msg_d = IMC::Packet::deserialize(bfr.getBuffer(), bfr.getSize());
      test.boolean("TransportBindings #1", msg == *msg_d);
      delete msg_d;
    }
    catch (IMC::InvalidMessageSize& e)
    {
      (void)e;
      test.boolean("msg #1", msg.getSerializationSize() > DUNE_IMC_CONST_MAX_SIZE);
    }
  }

  {
    IMC::TransportBindings msg;
    msg.setTimeStamp(0.14531881785856016);
    msg.setSource(61151U);
    msg.setSourceEntity(95U);
    msg.setDestination(42307U);
    msg.setDestinationEntity(140U);
    msg.consumer.assign("JTWSIKJUCA");
    msg.message_id = 35355U;

    try
    {
      Utils::ByteBuffer bfr;
      IMC::Packet::serialize(&msg, bfr);
      IMC::Message* msg_d = IMC::Packet::deserialize(bfr.getBuffer(), bfr.getSize());
      test.boolean("TransportBindings #2", msg == *msg_d);
      delete msg_d;
    }
    catch (IMC::InvalidMessageSize& e)
    {
      (void)e;
      test.boolean("msg #2", msg.getSerializationSize() > DUNE_IMC_CONST_MAX_SIZE);
    }
  }

  {
    IMC::RestartSystem msg;
    msg.setTimeStamp(0.5609534379978232);
    msg.setSource(48601U);
    msg.setSourceEntity(229U);
    msg.setDestination(23256U);
    msg.setDestinationEntity(164U);
    msg.type = 163U;

    try
    {
      Utils::ByteBuffer bfr;
      IMC::Packet::serialize(&msg, bfr);
      IMC::Message* msg_d = IMC::Packet::deserialize(bfr.getBuffer(), bfr.getSize());
      test.boolean("RestartSystem #0", msg == *msg_d);
      delete msg_d;
    }
    catch (IMC::InvalidMessageSize& e)
    {
      (void)e;
      test.boolean("msg #0", msg.getSerializationSize() > DUNE_IMC_CONST_MAX_SIZE);
    }
  }

  {
    IMC::RestartSystem msg;
    msg.setTimeStamp(0.17113622562288988);
    msg.setSource(62340U);
    msg.setSourceEntity(158U);
    msg.setDestination(60772U);
    msg.setDestinationEntity(2U);
    msg.type = 155U;

    try
    {
      Utils::ByteBuffer bfr;
      IMC::Packet::serialize(&msg, bfr);
      IMC::Message* msg_d = IMC::Packet::deserialize(bfr.getBuffer(), bfr.getSize());
      test.boolean("RestartSystem #1", msg == *msg_d);
      delete msg_d;
    }
    catch (IMC::InvalidMessageSize& e)
    {
      (void)e;
      test.boolean("msg #1", msg.getSerializationSize() > DUNE_IMC_CONST_MAX_SIZE);
    }
  }

  {
    IMC::RestartSystem msg;
    msg.setTimeStamp(0.6308868923900555);
    msg.setSource(57414U);
    msg.setSourceEntity(84U);
    msg.setDestination(62147U);
    msg.setDestinationEntity(159U);
    msg.type = 162U;

    try
    {
      Utils::ByteBuffer bfr;
      IMC::Packet::serialize(&msg, bfr);
      IMC::Message* msg_d = IMC::Packet::deserialize(bfr.getBuffer(), bfr.getSize());
      test.boolean("RestartSystem #2", msg == *msg_d);
      delete msg_d;
    }
    catch (IMC::InvalidMessageSize& e)
    {
      (void)e;
      test.boolean("msg #2", msg.getSerializationSize() > DUNE_IMC_CONST_MAX_SIZE);
    }
  }

  {
    IMC::DevCalibrationControl msg;
    msg.setTimeStamp(0.016756593687724086);
    msg.setSource(46682U);
    msg.setSourceEntity(11U);
    msg.setDestination(39854U);
    msg.setDestinationEntity(58U);
    msg.op = 114U;

    try
    {
      Utils::ByteBuffer bfr;
      IMC::Packet::serialize(&msg, bfr);
      IMC::Message* msg_d = IMC::Packet::deserialize(bfr.getBuffer(), bfr.getSize());
      test.boolean("DevCalibrationControl #0", msg == *msg_d);
      delete msg_d;
    }
    catch (IMC::InvalidMessageSize& e)
    {
      (void)e;
      test.boolean("msg #0", msg.getSerializationSize() > DUNE_IMC_CONST_MAX_SIZE);
    }
  }

  {
    IMC::DevCalibrationControl msg;
    msg.setTimeStamp(0.3620787703114947);
    msg.setSource(34815U);
    msg.setSourceEntity(180U);
    msg.setDestination(43513U);
    msg.setDestinationEntity(116U);
    msg.op = 167U;

    try
    {
      Utils::ByteBuffer bfr;
      IMC::Packet::serialize(&msg, bfr);
      IMC::Message* msg_d = IMC::Packet::deserialize(bfr.getBuffer(), bfr.getSize());
      test.boolean("DevCalibrationControl #1", msg == *msg_d);
      delete msg_d;
    }
    catch (IMC::InvalidMessageSize& e)
    {
      (void)e;
      test.boolean("msg #1", msg.getSerializationSize() > DUNE_IMC_CONST_MAX_SIZE);
    }
  }

  {
    IMC::DevCalibrationControl msg;
    msg.setTimeStamp(0.4622863872015106);
    msg.setSource(55449U);
    msg.setSourceEntity(233U);
    msg.setDestination(267U);
    msg.setDestinationEntity(24U);
    msg.op = 55U;

    try
    {
      Utils::ByteBuffer bfr;
      IMC::Packet::serialize(&msg, bfr);
      IMC::Message* msg_d = IMC::Packet::deserialize(bfr.getBuffer(), bfr.getSize());
      test.boolean("DevCalibrationControl #2", msg == *msg_d);
      delete msg_d;
    }
    catch (IMC::InvalidMessageSize& e)
    {
      (void)e;
      test.boolean("msg #2", msg.getSerializationSize() > DUNE_IMC_CONST_MAX_SIZE);
    }
  }

  {
    IMC::DevCalibrationState msg;
    msg.setTimeStamp(0.5989157047570925);
    msg.setSource(1017U);
    msg.setSourceEntity(205U);
    msg.setDestination(24219U);
    msg.setDestinationEntity(181U);
    msg.total_steps = 131U;
    msg.step_number = 102U;
    msg.step.assign("BLEVNASLCMSNFCVSLMKXULGPFQP");
    msg.flags = 45U;

    try
    {
      Utils::ByteBuffer bfr;
      IMC::Packet::serialize(&msg, bfr);
      IMC::Message* msg_d = IMC::Packet::deserialize(bfr.getBuffer(), bfr.getSize());
      test.boolean("DevCalibrationState #0", msg == *msg_d);
      delete msg_d;
    }
    catch (IMC::InvalidMessageSize& e)
    {
      (void)e;
      test.boolean("msg #0", msg.getSerializationSize() > DUNE_IMC_CONST_MAX_SIZE);
    }
  }

  {
    IMC::DevCalibrationState msg;
    msg.setTimeStamp(0.5394096839407896);
    msg.setSource(33842U);
    msg.setSourceEntity(184U);
    msg.setDestination(50794U);
    msg.setDestinationEntity(126U);
    msg.total_steps = 249U;
    msg.step_number = 242U;
    msg.step.assign("HKUQEVJOPPQQPHCXEYPHOKFHBNXYPZFVLIPGVZKGBAMHJVSTMOGQVONWOHRFXGRJCHWCAMGXVMCMKBCAHOALDFMRNBQRFUTCRAEYLIKILDSTOIZKJYZTCTJDEWNSPABNISEDLFUZSSXYMGQANJEDXLNWDNBTRPTUVIINRKVBJBEKFBOWFDZTLTWDSXOSXLJJSWUPGYECUWZQD");
    msg.flags = 205U;

    try
    {
      Utils::ByteBuffer bfr;
      IMC::Packet::serialize(&msg, bfr);
      IMC::Message* msg_d = IMC::Packet::deserialize(bfr.getBuffer(), bfr.getSize());
      test.boolean("DevCalibrationState #1", msg == *msg_d);
      delete msg_d;
    }
    catch (IMC::InvalidMessageSize& e)
    {
      (void)e;
      test.boolean("msg #1", msg.getSerializationSize() > DUNE_IMC_CONST_MAX_SIZE);
    }
  }

  {
    IMC::DevCalibrationState msg;
    msg.setTimeStamp(0.9389669852972992);
    msg.setSource(56702U);
    msg.setSourceEntity(196U);
    msg.setDestination(43702U);
    msg.setDestinationEntity(221U);
    msg.total_steps = 212U;
    msg.step_number = 143U;
    msg.step.assign("ZGEFSFYYCHADPAWDVTUSHQLENFTOAMXGJQJVUIGLINJXYPZKOLOEAPGNAF");
    msg.flags = 158U;

    try
    {
      Utils::ByteBuffer bfr;
      IMC::Packet::serialize(&msg, bfr);
      IMC::Message* msg_d = IMC::Packet::deserialize(bfr.getBuffer(), bfr.getSize());
      test.boolean("DevCalibrationState #2", msg == *msg_d);
      delete msg_d;
    }
    catch (IMC::InvalidMessageSize& e)
    {
      (void)e;
      test.boolean("msg #2", msg.getSerializationSize() > DUNE_IMC_CONST_MAX_SIZE);
    }
  }

  {
    IMC::EntityActivationState msg;
    msg.setTimeStamp(0.8414230830525374);
    msg.setSource(34134U);
    msg.setSourceEntity(224U);
    msg.setDestination(63063U);
    msg.setDestinationEntity(241U);
    msg.state = 223U;
    msg.error.assign("GRBMLWCFRSOPKDXXBDRVSACTEFPFAPANWRUJQIPQKIVGZQNILHZWUQCYCEKDXKZCFXYUZSYWVTTKYATQZZRGOSINLTDHXBFNPUCGEKBBRMBBELQENJMS");

    try
    {
      Utils::ByteBuffer bfr;
      IMC::Packet::serialize(&msg, bfr);
      IMC::Message* msg_d = IMC::Packet::deserialize(bfr.getBuffer(), bfr.getSize());
      test.boolean("EntityActivationState #0", msg == *msg_d);
      delete msg_d;
    }
    catch (IMC::InvalidMessageSize& e)
    {
      (void)e;
      test.boolean("msg #0", msg.getSerializationSize() > DUNE_IMC_CONST_MAX_SIZE);
    }
  }

  {
    IMC::EntityActivationState msg;
    msg.setTimeStamp(0.6211357199011827);
    msg.setSource(62287U);
    msg.setSourceEntity(30U);
    msg.setDestination(5483U);
    msg.setDestinationEntity(53U);
    msg.state = 147U;
    msg.error.assign("JJXOSSEWUKHGGOQBOYFHPDCDXZFPZPUZLDLGQSKTLPTBBKQHRRILGAQVFNSRUMIIFYIHCCQRXLZCOAUCPOJFIZHNGJDVBKHOTCIYMTQNFEBPKMYRYDGHQVECXBJTJMVCENUZSALKTDSCAUNPNEAJVXLNRONFRPZIWVCSOGWJXYGEXFQEGTVVYIMMSEPVYHBIZKAAWJSATFBXDMGWL");

    try
    {
      Utils::ByteBuffer bfr;
      IMC::Packet::serialize(&msg, bfr);
      IMC::Message* msg_d = IMC::Packet::deserialize(bfr.getBuffer(), bfr.getSize());
      test.boolean("EntityActivationState #1", msg == *msg_d);
      delete msg_d;
    }
    catch (IMC::InvalidMessageSize& e)
    {
      (void)e;
      test.boolean("msg #1", msg.getSerializationSize() > DUNE_IMC_CONST_MAX_SIZE);
    }
  }

  {
    IMC::EntityActivationState msg;
    msg.setTimeStamp(0.8686610904778373);
    msg.setSource(50042U);
    msg.setSourceEntity(185U);
    msg.setDestination(20828U);
    msg.setDestinationEntity(236U);
    msg.state = 172U;
    msg.error.assign("BDXNVBMAYXTPDMUQYSJDEPBTYQFOXUFGPAYOPHDDRJZRMHBMGWAKZREXHCFOHJSQVBHADKWZEXJMVHNWKGLSWVBYUIGFQNCLNLIMUKAWTGIUCMPNCRXTISDTSGFPWPKANLEVONPNLYEVRYZRLBKRLTOKSKFPEVCMRMXTFJQUCUHOUJCSQFQNIAXGFAWSSOUOBHLGSTJFDHZQ");

    try
    {
      Utils::ByteBuffer bfr;
      IMC::Packet::serialize(&msg, bfr);
      IMC::Message* msg_d = IMC::Packet::deserialize(bfr.getBuffer(), bfr.getSize());
      test.boolean("EntityActivationState #2", msg == *msg_d);
      delete msg_d;
    }
    catch (IMC::InvalidMessageSize& e)
    {
      (void)e;
      test.boolean("msg #2", msg.getSerializationSize() > DUNE_IMC_CONST_MAX_SIZE);
    }
  }

  {
    IMC::QueryEntityActivationState msg;
    msg.setTimeStamp(0.35319252936784795);
    msg.setSource(48543U);
    msg.setSourceEntity(204U);
    msg.setDestination(33817U);
    msg.setDestinationEntity(131U);

    try
    {
      Utils::ByteBuffer bfr;
      IMC::Packet::serialize(&msg, bfr);
      IMC::Message* msg_d = IMC::Packet::deserialize(bfr.getBuffer(), bfr.getSize());
      test.boolean("QueryEntityActivationState #0", msg == *msg_d);
      delete msg_d;
    }
    catch (IMC::InvalidMessageSize& e)
    {
      (void)e;
      test.boolean("msg #0", msg.getSerializationSize() > DUNE_IMC_CONST_MAX_SIZE);
    }
  }

  {
    IMC::QueryEntityActivationState msg;
    msg.setTimeStamp(0.881969866191422);
    msg.setSource(37781U);
    msg.setSourceEntity(188U);
    msg.setDestination(51893U);
    msg.setDestinationEntity(220U);

    try
    {
      Utils::ByteBuffer bfr;
      IMC::Packet::serialize(&msg, bfr);
      IMC::Message* msg_d = IMC::Packet::deserialize(bfr.getBuffer(), bfr.getSize());
      test.boolean("QueryEntityActivationState #1", msg == *msg_d);
      delete msg_d;
    }
    catch (IMC::InvalidMessageSize& e)
    {
      (void)e;
      test.boolean("msg #1", msg.getSerializationSize() > DUNE_IMC_CONST_MAX_SIZE);
    }
  }

  {
    IMC::QueryEntityActivationState msg;
    msg.setTimeStamp(0.060965154828727885);
    msg.setSource(46724U);
    msg.setSourceEntity(0U);
    msg.setDestination(60846U);
    msg.setDestinationEntity(87U);

    try
    {
      Utils::ByteBuffer bfr;
      IMC::Packet::serialize(&msg, bfr);
      IMC::Message* msg_d = IMC::Packet::deserialize(bfr.getBuffer(), bfr.getSize());
      test.boolean("QueryEntityActivationState #2", msg == *msg_d);
      delete msg_d;
    }
    catch (IMC::InvalidMessageSize& e)
    {
      (void)e;
      test.boolean("msg #2", msg.getSerializationSize() > DUNE_IMC_CONST_MAX_SIZE);
    }
  }

  {
    IMC::VehicleOperationalLimits msg;
    msg.setTimeStamp(0.09957916420864044);
    msg.setSource(26272U);
    msg.setSourceEntity(15U);
    msg.setDestination(6764U);
    msg.setDestinationEntity(114U);
    msg.op = 5U;
    msg.speed_min = 0.0599904617917123;
    msg.speed_max = 0.6600859090527635;
    msg.long_accel = 0.43122698771031487;
    msg.alt_max_msl = 0.13418643226047888;
    msg.dive_fraction_max = 0.4564488329159573;
    msg.climb_fraction_max = 0.5913006643805112;
    msg.bank_max = 0.14136224784607498;
    msg.p_max = 0.13867512597992326;
    msg.pitch_min = 0.9516717380539603;
    msg.pitch_max = 0.7032028627841902;
    msg.q_max = 0.7884123178128204;
    msg.g_min = 0.0012107663812014335;
    msg.g_max = 0.6027504994418594;
    msg.g_lat_max = 0.6298764783979165;
    msg.rpm_min = 0.022435102726644507;
    msg.rpm_max = 0.17067751012424537;
    msg.rpm_rate_max = 0.6684318525299674;

    try
    {
      Utils::ByteBuffer bfr;
      IMC::Packet::serialize(&msg, bfr);
      IMC::Message* msg_d = IMC::Packet::deserialize(bfr.getBuffer(), bfr.getSize());
      test.boolean("VehicleOperationalLimits #0", msg == *msg_d);
      delete msg_d;
    }
    catch (IMC::InvalidMessageSize& e)
    {
      (void)e;
      test.boolean("msg #0", msg.getSerializationSize() > DUNE_IMC_CONST_MAX_SIZE);
    }
  }

  {
    IMC::VehicleOperationalLimits msg;
    msg.setTimeStamp(0.2917209260576601);
    msg.setSource(54723U);
    msg.setSourceEntity(108U);
    msg.setDestination(12481U);
    msg.setDestinationEntity(185U);
    msg.op = 26U;
    msg.speed_min = 0.29001019876968004;
    msg.speed_max = 0.04758403480629747;
    msg.long_accel = 0.8619228279663302;
    msg.alt_max_msl = 0.31614447717740246;
    msg.dive_fraction_max = 0.7615443316056875;
    msg.climb_fraction_max = 0.22661726142482097;
    msg.bank_max = 0.7453137104490658;
    msg.p_max = 0.5479288945699242;
    msg.pitch_min = 0.7502144289043511;
    msg.pitch_max = 0.11082829361213387;
    msg.q_max = 0.6751745355305963;
    msg.g_min = 0.3503802612325366;
    msg.g_max = 0.2165604377811997;
    msg.g_lat_max = 0.9268209760938797;
    msg.rpm_min = 0.11685762646578823;
    msg.rpm_max = 0.08688276738674217;
    msg.rpm_rate_max = 0.8647648373008328;

    try
    {
      Utils::ByteBuffer bfr;
      IMC::Packet::serialize(&msg, bfr);
      IMC::Message* msg_d = IMC::Packet::deserialize(bfr.getBuffer(), bfr.getSize());
      test.boolean("VehicleOperationalLimits #1", msg == *msg_d);
      delete msg_d;
    }
    catch (IMC::InvalidMessageSize& e)
    {
      (void)e;
      test.boolean("msg #1", msg.getSerializationSize() > DUNE_IMC_CONST_MAX_SIZE);
    }
  }

  {
    IMC::VehicleOperationalLimits msg;
    msg.setTimeStamp(0.9237808804420002);
    msg.setSource(35955U);
    msg.setSourceEntity(232U);
    msg.setDestination(48717U);
    msg.setDestinationEntity(183U);
    msg.op = 205U;
    msg.speed_min = 0.10100841304595642;
    msg.speed_max = 0.6739316196703248;
    msg.long_accel = 0.4006715198076799;
    msg.alt_max_msl = 0.2536868599560813;
    msg.dive_fraction_max = 0.6142312003418374;
    msg.climb_fraction_max = 0.7090197005831237;
    msg.bank_max = 0.14700847372976245;
    msg.p_max = 0.23483816120715106;
    msg.pitch_min = 0.5111537442453221;
    msg.pitch_max = 0.4743364110266638;
    msg.q_max = 0.11717424496430395;
    msg.g_min = 0.6726885020680043;
    msg.g_max = 0.9357946083289148;
    msg.g_lat_max = 0.922232800768206;
    msg.rpm_min = 0.4959922493060598;
    msg.rpm_max = 0.28987176172831375;
    msg.rpm_rate_max = 0.8844738012753518;

    try
    {
      Utils::ByteBuffer bfr;
      IMC::Packet::serialize(&msg, bfr);
      IMC::Message* msg_d = IMC::Packet::deserialize(bfr.getBuffer(), bfr.getSize());
      test.boolean("VehicleOperationalLimits #2", msg == *msg_d);
      delete msg_d;
    }
    catch (IMC::InvalidMessageSize& e)
    {
      (void)e;
      test.boolean("msg #2", msg.getSerializationSize() > DUNE_IMC_CONST_MAX_SIZE);
    }
  }

  {
    IMC::MsgList msg;
    msg.setTimeStamp(0.6177678203554017);
    msg.setSource(28766U);
    msg.setSourceEntity(236U);
    msg.setDestination(19608U);
    msg.setDestinationEntity(209U);
    IMC::DesiredZ tmp_msg_0;
    tmp_msg_0.value = 0.554367945528926;
    tmp_msg_0.z_units = 37U;
    msg.msgs.push_back(tmp_msg_0);

    try
    {
      Utils::ByteBuffer bfr;
      IMC::Packet::serialize(&msg, bfr);
      IMC::Message* msg_d = IMC::Packet::deserialize(bfr.getBuffer(), bfr.getSize());
      test.boolean("MsgList #0", msg == *msg_d);
      delete msg_d;
    }
    catch (IMC::InvalidMessageSize& e)
    {
      (void)e;
      test.boolean("msg #0", msg.getSerializationSize() > DUNE_IMC_CONST_MAX_SIZE);
    }
  }

  {
    IMC::MsgList msg;
    msg.setTimeStamp(0.42596175883195275);
    msg.setSource(55262U);
    msg.setSourceEntity(84U);
    msg.setDestination(52001U);
    msg.setDestinationEntity(88U);

    try
    {
      Utils::ByteBuffer bfr;
      IMC::Packet::serialize(&msg, bfr);
      IMC::Message* msg_d = IMC::Packet::deserialize(bfr.getBuffer(), bfr.getSize());
      test.boolean("MsgList #1", msg == *msg_d);
      delete msg_d;
    }
    catch (IMC::InvalidMessageSize& e)
    {
      (void)e;
      test.boolean("msg #1", msg.getSerializationSize() > DUNE_IMC_CONST_MAX_SIZE);
    }
  }

  {
    IMC::MsgList msg;
    msg.setTimeStamp(0.3697444131946722);
    msg.setSource(44962U);
    msg.setSourceEntity(211U);
    msg.setDestination(54796U);
    msg.setDestinationEntity(178U);
    IMC::AngularVelocity tmp_msg_0;
    tmp_msg_0.time = 0.009809504130859237;
    tmp_msg_0.x = 0.78123858523704;
    tmp_msg_0.y = 0.7722637396176494;
    tmp_msg_0.z = 0.1903637878951887;
    msg.msgs.push_back(tmp_msg_0);

    try
    {
      Utils::ByteBuffer bfr;
      IMC::Packet::serialize(&msg, bfr);
      IMC::Message* msg_d = IMC::Packet::deserialize(bfr.getBuffer(), bfr.getSize());
      test.boolean("MsgList #2", msg == *msg_d);
      delete msg_d;
    }
    catch (IMC::InvalidMessageSize& e)
    {
      (void)e;
      test.boolean("msg #2", msg.getSerializationSize() > DUNE_IMC_CONST_MAX_SIZE);
    }
  }

  {
    IMC::SimulatedState msg;
    msg.setTimeStamp(0.4244695423012318);
    msg.setSource(49795U);
    msg.setSourceEntity(193U);
    msg.setDestination(42674U);
    msg.setDestinationEntity(23U);
    msg.lat = 0.4933737141709239;
    msg.lon = 0.5255405626486985;
    msg.height = 0.8973363159078029;
    msg.x = 0.9466521479482705;
    msg.y = 0.05929902453522795;
    msg.z = 0.7725787147028894;
    msg.phi = 0.5248080828122891;
    msg.theta = 0.3974019807313074;
    msg.psi = 0.34216018655940694;
    msg.u = 0.2796628563222542;
    msg.v = 0.6911982176113629;
    msg.w = 0.9024229230300342;
    msg.p = 0.3711995528875318;
    msg.q = 0.1219254500565915;
    msg.r = 0.3162063230544132;
    msg.svx = 0.8766073363914029;
    msg.svy = 0.7521044279449791;
    msg.svz = 0.5869561689352023;

    try
    {
      Utils::ByteBuffer bfr;
      IMC::Packet::serialize(&msg, bfr);
      IMC::Message* msg_d = IMC::Packet::deserialize(bfr.getBuffer(), bfr.getSize());
      test.boolean("SimulatedState #0", msg == *msg_d);
      delete msg_d;
    }
    catch (IMC::InvalidMessageSize& e)
    {
      (void)e;
      test.boolean("msg #0", msg.getSerializationSize() > DUNE_IMC_CONST_MAX_SIZE);
    }
  }

  {
    IMC::SimulatedState msg;
    msg.setTimeStamp(0.2009135973139935);
    msg.setSource(10998U);
    msg.setSourceEntity(5U);
    msg.setDestination(11735U);
    msg.setDestinationEntity(94U);
    msg.lat = 0.08703948967425656;
    msg.lon = 0.9294652502758517;
    msg.height = 0.39394672689092314;
    msg.x = 0.2500968585281923;
    msg.y = 0.8860210039365095;
    msg.z = 0.17447264032788856;
    msg.phi = 0.744451784900037;
    msg.theta = 0.9572194387532582;
    msg.psi = 0.8030296614217239;
    msg.u = 0.5231559848548263;
    msg.v = 0.7947596383445493;
    msg.w = 0.44768579614160064;
    msg.p = 0.6499963119151613;
    msg.q = 0.22668748466764332;
    msg.r = 0.5342042927572888;
    msg.svx = 0.46778754898668806;
    msg.svy = 0.751767657147129;
    msg.svz = 0.17989317181135134;

    try
    {
      Utils::ByteBuffer bfr;
      IMC::Packet::serialize(&msg, bfr);
      IMC::Message* msg_d = IMC::Packet::deserialize(bfr.getBuffer(), bfr.getSize());
      test.boolean("SimulatedState #1", msg == *msg_d);
      delete msg_d;
    }
    catch (IMC::InvalidMessageSize& e)
    {
      (void)e;
      test.boolean("msg #1", msg.getSerializationSize() > DUNE_IMC_CONST_MAX_SIZE);
    }
  }

  {
    IMC::SimulatedState msg;
    msg.setTimeStamp(0.29324717143621115);
    msg.setSource(59532U);
    msg.setSourceEntity(228U);
    msg.setDestination(9362U);
    msg.setDestinationEntity(13U);
    msg.lat = 0.9746111605853931;
    msg.lon = 0.4658336811540462;
    msg.height = 0.3137776774896509;
    msg.x = 0.9017871566358517;
    msg.y = 0.5527075830867796;
    msg.z = 0.24658545012170907;
    msg.phi = 0.21072424413900437;
    msg.theta = 0.08403141408762627;
    msg.psi = 0.5147887434053554;
    msg.u = 0.3855103877930547;
    msg.v = 0.0719171885768165;
    msg.w = 0.16060339416440073;
    msg.p = 0.7165988759270621;
    msg.q = 0.296186787441573;
    msg.r = 0.7918254387155067;
    msg.svx = 0.3784647162611281;
    msg.svy = 0.9415942457038682;
    msg.svz = 0.84154777473813;

    try
    {
      Utils::ByteBuffer bfr;
      IMC::Packet::serialize(&msg, bfr);
      IMC::Message* msg_d = IMC::Packet::deserialize(bfr.getBuffer(), bfr.getSize());
      test.boolean("SimulatedState #2", msg == *msg_d);
      delete msg_d;
    }
    catch (IMC::InvalidMessageSize& e)
    {
      (void)e;
      test.boolean("msg #2", msg.getSerializationSize() > DUNE_IMC_CONST_MAX_SIZE);
    }
  }

  {
    IMC::LeakSimulation msg;
    msg.setTimeStamp(0.042538886255037656);
    msg.setSource(39830U);
    msg.setSourceEntity(43U);
    msg.setDestination(5644U);
    msg.setDestinationEntity(199U);
    msg.op = 45U;
    msg.entities.assign("NHGWUBRJXNQVTDOJGZLXXHMVSLJKGBKEIUOOTKSKWFNFPDKGFWDYVYNPY");

    try
    {
      Utils::ByteBuffer bfr;
      IMC::Packet::serialize(&msg, bfr);
      IMC::Message* msg_d = IMC::Packet::deserialize(bfr.getBuffer(), bfr.getSize());
      test.boolean("LeakSimulation #0", msg == *msg_d);
      delete msg_d;
    }
    catch (IMC::InvalidMessageSize& e)
    {
      (void)e;
      test.boolean("msg #0", msg.getSerializationSize() > DUNE_IMC_CONST_MAX_SIZE);
    }
  }

  {
    IMC::LeakSimulation msg;
    msg.setTimeStamp(0.42061161832133365);
    msg.setSource(44527U);
    msg.setSourceEntity(28U);
    msg.setDestination(51187U);
    msg.setDestinationEntity(137U);
    msg.op = 232U;
    msg.entities.assign("EGINJTCONCWVIODJYACVEWNLDUOOHKMQDXJALKKEUGUOXKTMDZMRUEHVY");

    try
    {
      Utils::ByteBuffer bfr;
      IMC::Packet::serialize(&msg, bfr);
      IMC::Message* msg_d = IMC::Packet::deserialize(bfr.getBuffer(), bfr.getSize());
      test.boolean("LeakSimulation #1", msg == *msg_d);
      delete msg_d;
    }
    catch (IMC::InvalidMessageSize& e)
    {
      (void)e;
      test.boolean("msg #1", msg.getSerializationSize() > DUNE_IMC_CONST_MAX_SIZE);
    }
  }

  {
    IMC::LeakSimulation msg;
    msg.setTimeStamp(0.5884985035331305);
    msg.setSource(49059U);
    msg.setSourceEntity(232U);
    msg.setDestination(29151U);
    msg.setDestinationEntity(113U);
    msg.op = 189U;
    msg.entities.assign("ZRMEQCADOSDYXIBKXTNKZNRXGZMXFUCKQSVMVAHERNHMCDRDLGFIZUMLOXPKKKQHDBPOTLJRXBJACEVVFAQRHGKTJWCOOELZGMEYJKWTSBFPZRNEUFZLOWBOTYFWMFUIMCCEHHRPDVTQGGGETQRQMUVYASIODELPYIMWTGLJQPVJASTDIZGSDUNIPVNKWLIBNC");

    try
    {
      Utils::ByteBuffer bfr;
      IMC::Packet::serialize(&msg, bfr);
      IMC::Message* msg_d = IMC::Packet::deserialize(bfr.getBuffer(), bfr.getSize());
      test.boolean("LeakSimulation #2", msg == *msg_d);
      delete msg_d;
    }
    catch (IMC::InvalidMessageSize& e)
    {
      (void)e;
      test.boolean("msg #2", msg.getSerializationSize() > DUNE_IMC_CONST_MAX_SIZE);
    }
  }

  {
    IMC::UASimulation msg;
    msg.setTimeStamp(0.7537743382920142);
    msg.setSource(32012U);
    msg.setSourceEntity(66U);
    msg.setDestination(38112U);
    msg.setDestinationEntity(147U);
    msg.type = 134U;
    msg.speed = 58203U;
    const signed char tmp_msg_0[] = {-33, 79, 66, -61, -4, 71, 9, 31, 12, 125, 11, 88, 103, 88, -74, 20, 120, -85, -8, -43, -23, 104, -8, -24, 19, 9, 79, -89, 66, -61, 8, -62, -128, 125, 101, 8, 118, -110, -59, -55, 26, 74, 72, 16, -50, -111, 20, 55, 61, -106, 3, 19, -117, -16, -28, 72, 83, 121, -49, 49, -110, -9, -52, -60, -6, 52, 102, -114, 10, -23, 29, -44, 98, 0, -60, -52, -101, 115, 98, -31, -93, 71, 114, -57, -17, -25, 98, 92, 45, 125, -11, 86, 65, -89, 115, 76, -72, 55, 47, -83, 68, 10, -55, -37, 78, -110, -90, 81, 9, -101, 13, -46, -67, 7, -104, 23, -86, -114, 109, -80, 81, -90, 58, -2, 3, 41, 57, 84, -45, -91, -90, 22, -81, 107, -126, 70, 88, 7, -29, -55, 54, -49, -53, 91, 90, -80, -82, 37, -37, -90, -87, -17, -62, 56, -15, 38, -66, -67, -16, 108, -33, -60, -55, 18, 15, 119, -38, -49, 99, -124, 122};
    msg.data.assign(tmp_msg_0, tmp_msg_0 + sizeof(tmp_msg_0));

    try
    {
      Utils::ByteBuffer bfr;
      IMC::Packet::serialize(&msg, bfr);
      IMC::Message* msg_d = IMC::Packet::deserialize(bfr.getBuffer(), bfr.getSize());
      test.boolean("UASimulation #0", msg == *msg_d);
      delete msg_d;
    }
    catch (IMC::InvalidMessageSize& e)
    {
      (void)e;
      test.boolean("msg #0", msg.getSerializationSize() > DUNE_IMC_CONST_MAX_SIZE);
    }
  }

  {
    IMC::UASimulation msg;
    msg.setTimeStamp(0.6540281531620546);
    msg.setSource(41131U);
    msg.setSourceEntity(13U);
    msg.setDestination(42136U);
    msg.setDestinationEntity(17U);
    msg.type = 217U;
    msg.speed = 40113U;
    const signed char tmp_msg_0[] = {100, 16, 104, -64, 34, -61, -118, -92, -103, -83, -89, -99};
    msg.data.assign(tmp_msg_0, tmp_msg_0 + sizeof(tmp_msg_0));

    try
    {
      Utils::ByteBuffer bfr;
      IMC::Packet::serialize(&msg, bfr);
      IMC::Message* msg_d = IMC::Packet::deserialize(bfr.getBuffer(), bfr.getSize());
      test.boolean("UASimulation #1", msg == *msg_d);
      delete msg_d;
    }
    catch (IMC::InvalidMessageSize& e)
    {
      (void)e;
      test.boolean("msg #1", msg.getSerializationSize() > DUNE_IMC_CONST_MAX_SIZE);
    }
  }

  {
    IMC::UASimulation msg;
    msg.setTimeStamp(0.4622658875100192);
    msg.setSource(7487U);
    msg.setSourceEntity(242U);
    msg.setDestination(5328U);
    msg.setDestinationEntity(212U);
    msg.type = 153U;
    msg.speed = 43987U;
    const signed char tmp_msg_0[] = {117, 64, 112, -58, 51, 118, 110, 35, -66, 15, -30, -28, 81, 120, -104, 41, 118, -8, 112, -69, -73, 4, -41, -89, -116, 76, 100, -118, 69, -57, -76, 8, 97, -1, 78, 103, -52, 72, -37, 79, -57, -118, -26, -25, -71, 107, -128, 81, -121, -53, 4, -16, -20, 2, -76, -30, -59, -115, -75, 71, 17, -31, 64, -15, -112, 37, 85, -47, -16, -126, -46, 67, 78, -64, -126, -97, -109, 68, 41, -72, 75, 101, -76, -73, -45, -126, 6, -66, -37, -99, 27, 15, -59, -49, 125, 1, 69, 21, -41, -65, -113, 53, -52, 9, -109, 55, -124, 70, -76, 120, -58, 80, -110, -108};
    msg.data.assign(tmp_msg_0, tmp_msg_0 + sizeof(tmp_msg_0));

    try
    {
      Utils::ByteBuffer bfr;
      IMC::Packet::serialize(&msg, bfr);
      IMC::Message* msg_d = IMC::Packet::deserialize(bfr.getBuffer(), bfr.getSize());
      test.boolean("UASimulation #2", msg == *msg_d);
      delete msg_d;
    }
    catch (IMC::InvalidMessageSize& e)
    {
      (void)e;
      test.boolean("msg #2", msg.getSerializationSize() > DUNE_IMC_CONST_MAX_SIZE);
    }
  }

  {
    IMC::DynamicsSimParam msg;
    msg.setTimeStamp(0.8056912411225119);
    msg.setSource(13686U);
    msg.setSourceEntity(224U);
    msg.setDestination(27928U);
    msg.setDestinationEntity(239U);
    msg.op = 32U;
    msg.tas2acc_pgain = 0.8864406724956126;
    msg.bank2p_pgain = 0.7310105567609291;

    try
    {
      Utils::ByteBuffer bfr;
      IMC::Packet::serialize(&msg, bfr);
      IMC::Message* msg_d = IMC::Packet::deserialize(bfr.getBuffer(), bfr.getSize());
      test.boolean("DynamicsSimParam #0", msg == *msg_d);
      delete msg_d;
    }
    catch (IMC::InvalidMessageSize& e)
    {
      (void)e;
      test.boolean("msg #0", msg.getSerializationSize() > DUNE_IMC_CONST_MAX_SIZE);
    }
  }

  {
    IMC::DynamicsSimParam msg;
    msg.setTimeStamp(0.5112257052425357);
    msg.setSource(42951U);
    msg.setSourceEntity(13U);
    msg.setDestination(6887U);
    msg.setDestinationEntity(169U);
    msg.op = 159U;
    msg.tas2acc_pgain = 0.32343716929436606;
    msg.bank2p_pgain = 0.7059445018698624;

    try
    {
      Utils::ByteBuffer bfr;
      IMC::Packet::serialize(&msg, bfr);
      IMC::Message* msg_d = IMC::Packet::deserialize(bfr.getBuffer(), bfr.getSize());
      test.boolean("DynamicsSimParam #1", msg == *msg_d);
      delete msg_d;
    }
    catch (IMC::InvalidMessageSize& e)
    {
      (void)e;
      test.boolean("msg #1", msg.getSerializationSize() > DUNE_IMC_CONST_MAX_SIZE);
    }
  }

  {
    IMC::DynamicsSimParam msg;
    msg.setTimeStamp(0.40858524250814243);
    msg.setSource(25935U);
    msg.setSourceEntity(205U);
    msg.setDestination(48193U);
    msg.setDestinationEntity(135U);
    msg.op = 252U;
    msg.tas2acc_pgain = 0.37779900216895423;
    msg.bank2p_pgain = 0.7519844636776879;

    try
    {
      Utils::ByteBuffer bfr;
      IMC::Packet::serialize(&msg, bfr);
      IMC::Message* msg_d = IMC::Packet::deserialize(bfr.getBuffer(), bfr.getSize());
      test.boolean("DynamicsSimParam #2", msg == *msg_d);
      delete msg_d;
    }
    catch (IMC::InvalidMessageSize& e)
    {
      (void)e;
      test.boolean("msg #2", msg.getSerializationSize() > DUNE_IMC_CONST_MAX_SIZE);
    }
  }

  {
    IMC::StorageUsage msg;
    msg.setTimeStamp(0.9056788154016805);
    msg.setSource(41041U);
    msg.setSourceEntity(215U);
    msg.setDestination(29531U);
    msg.setDestinationEntity(96U);
    msg.available = 4247114657U;
    msg.value = 171U;

    try
    {
      Utils::ByteBuffer bfr;
      IMC::Packet::serialize(&msg, bfr);
      IMC::Message* msg_d = IMC::Packet::deserialize(bfr.getBuffer(), bfr.getSize());
      test.boolean("StorageUsage #0", msg == *msg_d);
      delete msg_d;
    }
    catch (IMC::InvalidMessageSize& e)
    {
      (void)e;
      test.boolean("msg #0", msg.getSerializationSize() > DUNE_IMC_CONST_MAX_SIZE);
    }
  }

  {
    IMC::StorageUsage msg;
    msg.setTimeStamp(0.3128478108535976);
    msg.setSource(10333U);
    msg.setSourceEntity(60U);
    msg.setDestination(13475U);
    msg.setDestinationEntity(144U);
    msg.available = 94746525U;
    msg.value = 210U;

    try
    {
      Utils::ByteBuffer bfr;
      IMC::Packet::serialize(&msg, bfr);
      IMC::Message* msg_d = IMC::Packet::deserialize(bfr.getBuffer(), bfr.getSize());
      test.boolean("StorageUsage #1", msg == *msg_d);
      delete msg_d;
    }
    catch (IMC::InvalidMessageSize& e)
    {
      (void)e;
      test.boolean("msg #1", msg.getSerializationSize() > DUNE_IMC_CONST_MAX_SIZE);
    }
  }

  {
    IMC::StorageUsage msg;
    msg.setTimeStamp(0.5849742581099522);
    msg.setSource(29771U);
    msg.setSourceEntity(97U);
    msg.setDestination(27885U);
    msg.setDestinationEntity(47U);
    msg.available = 221460000U;
    msg.value = 231U;

    try
    {
      Utils::ByteBuffer bfr;
      IMC::Packet::serialize(&msg, bfr);
      IMC::Message* msg_d = IMC::Packet::deserialize(bfr.getBuffer(), bfr.getSize());
      test.boolean("StorageUsage #2", msg == *msg_d);
      delete msg_d;
    }
    catch (IMC::InvalidMessageSize& e)
    {
      (void)e;
      test.boolean("msg #2", msg.getSerializationSize() > DUNE_IMC_CONST_MAX_SIZE);
    }
  }

  {
    IMC::CacheControl msg;
    msg.setTimeStamp(0.11904137571667484);
    msg.setSource(19447U);
    msg.setSourceEntity(89U);
    msg.setDestination(6569U);
    msg.setDestinationEntity(161U);
    msg.op = 158U;
    msg.snapshot.assign("XMDICCZOBZIMLPHHWJRWMTACSSIRPBHSFXXCLVVZSBEJLROSSRIKPOPAKLXNCVBNGMHYWDVJELPNNVGUJFODVQUELENNPCBUGORUAXTXSAZPIYYABGKFKBWEETQDZWQMNVHMFCPOUISMZFQDMVKBQDYAVCYXIZXFGUHKRPRCQZUOJTAWJREXCWQTYWBIGVGOJMYEH");
    IMC::StationKeepingExtended tmp_msg_0;
    tmp_msg_0.lat = 0.33226662995948486;
    tmp_msg_0.lon = 0.3352790419724109;
    tmp_msg_0.z = 0.29919418457021896;
    tmp_msg_0.z_units = 52U;
    tmp_msg_0.radius = 0.469807986068835;
    tmp_msg_0.duration = 16762U;
    tmp_msg_0.speed = 0.16481497872557427;
    tmp_msg_0.speed_units = 40U;
    tmp_msg_0.popup_period = 26986U;
    tmp_msg_0.popup_duration = 45904U;
    tmp_msg_0.flags = 116U;
    tmp_msg_0.custom.assign("PJAFRGTHSNTTOKINRXEUGGJLGQVEZMSFXLQBZHCORYJHEOAUGZTLUIWFMFEWWKYMMPEUAEYZMQLBWNPNDOXXVQDXIQJRIOMIJMGHGFIRJHGHCJDPCQTOZYOKKWPMXIYEJBNDTHLBLFOTUCKEXDVRFYWNXD");
    msg.message.set(tmp_msg_0);

    try
    {
      Utils::ByteBuffer bfr;
      IMC::Packet::serialize(&msg, bfr);
      IMC::Message* msg_d = IMC::Packet::deserialize(bfr.getBuffer(), bfr.getSize());
      test.boolean("CacheControl #0", msg == *msg_d);
      delete msg_d;
    }
    catch (IMC::InvalidMessageSize& e)
    {
      (void)e;
      test.boolean("msg #0", msg.getSerializationSize() > DUNE_IMC_CONST_MAX_SIZE);
    }
  }

  {
    IMC::CacheControl msg;
    msg.setTimeStamp(0.7062381210655879);
    msg.setSource(32170U);
    msg.setSourceEntity(30U);
    msg.setDestination(56637U);
    msg.setDestinationEntity(172U);
    msg.op = 72U;
    msg.snapshot.assign("FRHQCWEHVIGMFKSDUBPYVAGQGLIGFNXFOCLRFIRPJGFWKNQBNIIZQFDFEKQKWMVHPJRMUWQIAMDBKDWGYSPYZJJCDMPDBKPMTLJIOJZSHKNMXNAEEDLNTJXABJOUOUSLAGYPYFAHOONEHLGOSTXUSXDMVPXMHZCXURQQCSUYLDSTEBICOEKDWTLZSLRVXYLNABRERWJKVTJZWNIEVSEZZC");
    IMC::DesiredHeading tmp_msg_0;
    tmp_msg_0.value = 0.7538514275187109;
    msg.message.set(tmp_msg_0);

    try
    {
      Utils::ByteBuffer bfr;
      IMC::Packet::serialize(&msg, bfr);
      IMC::Message* msg_d = IMC::Packet::deserialize(bfr.getBuffer(), bfr.getSize());
      test.boolean("CacheControl #1", msg == *msg_d);
      delete msg_d;
    }
    catch (IMC::InvalidMessageSize& e)
    {
      (void)e;
      test.boolean("msg #1", msg.getSerializationSize() > DUNE_IMC_CONST_MAX_SIZE);
    }
  }

  {
    IMC::CacheControl msg;
    msg.setTimeStamp(0.08981298113798264);
    msg.setSource(11796U);
    msg.setSourceEntity(21U);
    msg.setDestination(52265U);
    msg.setDestinationEntity(96U);
    msg.op = 108U;
    msg.snapshot.assign("YBMVFGZOFZRRJWDYMPNXRUOUUEXPUBCDQAEEOXQQAKPFLIXWYTZVCJIBOBCCERVZCXYLFWLMIBDUGSETV");
    IMC::Pulse tmp_msg_0;
    msg.message.set(tmp_msg_0);

    try
    {
      Utils::ByteBuffer bfr;
      IMC::Packet::serialize(&msg, bfr);
      IMC::Message* msg_d = IMC::Packet::deserialize(bfr.getBuffer(), bfr.getSize());
      test.boolean("CacheControl #2", msg == *msg_d);
      delete msg_d;
    }
    catch (IMC::InvalidMessageSize& e)
    {
      (void)e;
      test.boolean("msg #2", msg.getSerializationSize() > DUNE_IMC_CONST_MAX_SIZE);
    }
  }

  {
    IMC::LoggingControl msg;
    msg.setTimeStamp(0.20173871327644644);
    msg.setSource(1624U);
    msg.setSourceEntity(246U);
    msg.setDestination(60704U);
    msg.setDestinationEntity(108U);
    msg.op = 146U;
    msg.name.assign("ZECRSMSVUPJMBNLDLKVSMSCQIPQPOVOUFSJLRXDUHUKXAKDBIGNMYKKTVGEXZJBZBKEJNAMEHRKIHPCDFNQEFVBWQAGWZBSQIELVZCTBWJHYAPLDZHYPGOMOAQDAXJIDWDBUCWPSPLVSXIJBLTMVDEKCGEHGDAFYYCEYVZXXNIPYCXIIEZWXAKSWWOUSRLNJX");

    try
    {
      Utils::ByteBuffer bfr;
      IMC::Packet::serialize(&msg, bfr);
      IMC::Message* msg_d = IMC::Packet::deserialize(bfr.getBuffer(), bfr.getSize());
      test.boolean("LoggingControl #0", msg == *msg_d);
      delete msg_d;
    }
    catch (IMC::InvalidMessageSize& e)
    {
      (void)e;
      test.boolean("msg #0", msg.getSerializationSize() > DUNE_IMC_CONST_MAX_SIZE);
    }
  }

  {
    IMC::LoggingControl msg;
    msg.setTimeStamp(0.08618886676738269);
    msg.setSource(14214U);
    msg.setSourceEntity(227U);
    msg.setDestination(1100U);
    msg.setDestinationEntity(115U);
    msg.op = 162U;
    msg.name.assign("WNDKEPKQLZYEXYIDCAUHAEJAJDVOKBTMOMCASMHZCOUNVNGFBIUHPLXLCSRFDJTNLNJIFCWSZOTFVQNZHWCQSOUJXAXQDIRXTCCYMYSBGXMZQVINQFSGEZKUWGIFYNVKWMHHXAOLQRVCBMPIMRDSYUAIEIPDFBYWYDYOQORETGBRWVPXJWCKNGU");

    try
    {
      Utils::ByteBuffer bfr;
      IMC::Packet::serialize(&msg, bfr);
      IMC::Message* msg_d = IMC::Packet::deserialize(bfr.getBuffer(), bfr.getSize());
      test.boolean("LoggingControl #1", msg == *msg_d);
      delete msg_d;
    }
    catch (IMC::InvalidMessageSize& e)
    {
      (void)e;
      test.boolean("msg #1", msg.getSerializationSize() > DUNE_IMC_CONST_MAX_SIZE);
    }
  }

  {
    IMC::LoggingControl msg;
    msg.setTimeStamp(0.5437903675539082);
    msg.setSource(47800U);
    msg.setSourceEntity(86U);
    msg.setDestination(33132U);
    msg.setDestinationEntity(159U);
    msg.op = 195U;
    msg.name.assign("ZUWAQTSKIFZPERDVSKJUCYZCGXRZYTXRSJNYTIVHKACBIMTEYWDQTHRASFLYAPTNHGLMDPHWWNJODPPDB");

    try
    {
      Utils::ByteBuffer bfr;
      IMC::Packet::serialize(&msg, bfr);
      IMC::Message* msg_d = IMC::Packet::deserialize(bfr.getBuffer(), bfr.getSize());
      test.boolean("LoggingControl #2", msg == *msg_d);
      delete msg_d;
    }
    catch (IMC::InvalidMessageSize& e)
    {
      (void)e;
      test.boolean("msg #2", msg.getSerializationSize() > DUNE_IMC_CONST_MAX_SIZE);
    }
  }

  {
    IMC::LogBookEntry msg;
    msg.setTimeStamp(0.9304626664890326);
    msg.setSource(33885U);
    msg.setSourceEntity(170U);
    msg.setDestination(54905U);
    msg.setDestinationEntity(102U);
    msg.type = 35U;
    msg.htime = 0.37018533590845815;
    msg.context.assign("BCVKVEBCTWRYMHKOLQRXLWJMJUPUYYJNFRSLJCQMILRACJPXRGOAXMWYMZOVIFDIALJNYXPQXFOBFDHSUZPBXVXZPCJ");
    msg.text.assign("CEEZDJRLUBFOGGFJUKARTBTKPNYXXXVWIBVGCFXETCPJHQZNSUAEILOEMIHVDTWBNHYDTYNNJOSPAAFOCRYLNMCSWMSMKDPBZURMNOSJXSAWAENZMQAEKBHQHELOCRXUQUGQKXRCHIUEUYKSYUBYFTXIFIXILIKBBSAWLVWOMDAZLSDKDTVVMLQGTDIZFRWOWRWPJQNSNYGZXHCRGQTFJVQGGLYLRYDTGJFZMCQOZFKDHV");

    try
    {
      Utils::ByteBuffer bfr;
      IMC::Packet::serialize(&msg, bfr);
      IMC::Message* msg_d = IMC::Packet::deserialize(bfr.getBuffer(), bfr.getSize());
      test.boolean("LogBookEntry #0", msg == *msg_d);
      delete msg_d;
    }
    catch (IMC::InvalidMessageSize& e)
    {
      (void)e;
      test.boolean("msg #0", msg.getSerializationSize() > DUNE_IMC_CONST_MAX_SIZE);
    }
  }

  {
    IMC::LogBookEntry msg;
    msg.setTimeStamp(0.6635691224159198);
    msg.setSource(37968U);
    msg.setSourceEntity(219U);
    msg.setDestination(43878U);
    msg.setDestinationEntity(19U);
    msg.type = 249U;
    msg.htime = 0.5553678432982524;
    msg.context.assign("NXVTMNAPESPXQQTMAAMBOEQLFNOTFUUEHYNLDSCDEBCJPIZKYIVXJOZQNZIKQAXCVIKCPQADSXBSTSQVQT");
    msg.text.assign("SBSOKINFDMLNWLEVMFMESIZYJFCMZJTGRGXOQQUMZQKVSQULZGQFOXDZBTRJNHEYVHEUKUBTAHWXPKXYZYSIXAJASLHHHAPCEIOATBUCMCRWIBCUTVTOJFRCDEZIHXYKQKYV");

    try
    {
      Utils::ByteBuffer bfr;
      IMC::Packet::serialize(&msg, bfr);
      IMC::Message* msg_d = IMC::Packet::deserialize(bfr.getBuffer(), bfr.getSize());
      test.boolean("LogBookEntry #1", msg == *msg_d);
      delete msg_d;
    }
    catch (IMC::InvalidMessageSize& e)
    {
      (void)e;
      test.boolean("msg #1", msg.getSerializationSize() > DUNE_IMC_CONST_MAX_SIZE);
    }
  }

  {
    IMC::LogBookEntry msg;
    msg.setTimeStamp(0.0016330354527464008);
    msg.setSource(3959U);
    msg.setSourceEntity(4U);
    msg.setDestination(43272U);
    msg.setDestinationEntity(168U);
    msg.type = 107U;
    msg.htime = 0.8954659276805762;
    msg.context.assign("FJITWNVJGNGQAJTYKBQKISYFYAVRMXJMVROBMRBWTUTDUWA");
    msg.text.assign("NWNTKGIUMGZQLSTTDYKBZNWGSDDZATKHWEHMBOMVFUQJAKFKCBYNUCDYBEFQUSWXFBFMRZDDZEUXVXRRDWLONITFFNUHPXFVIHEHVVPOYAXOUJBGGSPYJCUQCZKXRJJCHCUG");

    try
    {
      Utils::ByteBuffer bfr;
      IMC::Packet::serialize(&msg, bfr);
      IMC::Message* msg_d = IMC::Packet::deserialize(bfr.getBuffer(), bfr.getSize());
      test.boolean("LogBookEntry #2", msg == *msg_d);
      delete msg_d;
    }
    catch (IMC::InvalidMessageSize& e)
    {
      (void)e;
      test.boolean("msg #2", msg.getSerializationSize() > DUNE_IMC_CONST_MAX_SIZE);
    }
  }

  {
    IMC::LogBookControl msg;
    msg.setTimeStamp(0.42645006999508794);
    msg.setSource(20632U);
    msg.setSourceEntity(170U);
    msg.setDestination(13050U);
    msg.setDestinationEntity(36U);
    msg.command = 34U;
    msg.htime = 0.12690549535589657;

    try
    {
      Utils::ByteBuffer bfr;
      IMC::Packet::serialize(&msg, bfr);
      IMC::Message* msg_d = IMC::Packet::deserialize(bfr.getBuffer(), bfr.getSize());
      test.boolean("LogBookControl #0", msg == *msg_d);
      delete msg_d;
    }
    catch (IMC::InvalidMessageSize& e)
    {
      (void)e;
      test.boolean("msg #0", msg.getSerializationSize() > DUNE_IMC_CONST_MAX_SIZE);
    }
  }

  {
    IMC::LogBookControl msg;
    msg.setTimeStamp(0.7775810886776442);
    msg.setSource(24652U);
    msg.setSourceEntity(50U);
    msg.setDestination(39896U);
    msg.setDestinationEntity(3U);
    msg.command = 108U;
    msg.htime = 0.22262355484789487;

    try
    {
      Utils::ByteBuffer bfr;
      IMC::Packet::serialize(&msg, bfr);
      IMC::Message* msg_d = IMC::Packet::deserialize(bfr.getBuffer(), bfr.getSize());
      test.boolean("LogBookControl #1", msg == *msg_d);
      delete msg_d;
    }
    catch (IMC::InvalidMessageSize& e)
    {
      (void)e;
      test.boolean("msg #1", msg.getSerializationSize() > DUNE_IMC_CONST_MAX_SIZE);
    }
  }

  {
    IMC::LogBookControl msg;
    msg.setTimeStamp(0.9379864583679599);
    msg.setSource(51060U);
    msg.setSourceEntity(101U);
    msg.setDestination(27814U);
    msg.setDestinationEntity(215U);
    msg.command = 168U;
    msg.htime = 0.7556693543235674;

    try
    {
      Utils::ByteBuffer bfr;
      IMC::Packet::serialize(&msg, bfr);
      IMC::Message* msg_d = IMC::Packet::deserialize(bfr.getBuffer(), bfr.getSize());
      test.boolean("LogBookControl #2", msg == *msg_d);
      delete msg_d;
    }
    catch (IMC::InvalidMessageSize& e)
    {
      (void)e;
      test.boolean("msg #2", msg.getSerializationSize() > DUNE_IMC_CONST_MAX_SIZE);
    }
  }

  {
    IMC::ReplayControl msg;
    msg.setTimeStamp(0.5802707822543438);
    msg.setSource(9296U);
    msg.setSourceEntity(252U);
    msg.setDestination(46422U);
    msg.setDestinationEntity(95U);
    msg.op = 237U;
    msg.file.assign("DVROJZQAYPSXTNVWJSAPFSDHWKHWUQCFSYZSOCNUJQUTHATRXYJBMDRTEOQPKXVFGHMBKOXIXZMUHIWCTCRKAKZNKJDNACSZRMVVDIEUQDDJFBNWZUCREEBPQWIKGLQWBJNJLIAEULYUAFLBNGVMEESXJIRQHXKIIC");

    try
    {
      Utils::ByteBuffer bfr;
      IMC::Packet::serialize(&msg, bfr);
      IMC::Message* msg_d = IMC::Packet::deserialize(bfr.getBuffer(), bfr.getSize());
      test.boolean("ReplayControl #0", msg == *msg_d);
      delete msg_d;
    }
    catch (IMC::InvalidMessageSize& e)
    {
      (void)e;
      test.boolean("msg #0", msg.getSerializationSize() > DUNE_IMC_CONST_MAX_SIZE);
    }
  }

  {
    IMC::ReplayControl msg;
    msg.setTimeStamp(0.3138360762648391);
    msg.setSource(56135U);
    msg.setSourceEntity(229U);
    msg.setDestination(43852U);
    msg.setDestinationEntity(12U);
    msg.op = 150U;
    msg.file.assign("TDXGMJRNWTLXCMSWLTNGQEOUKUWQBSUJLWUYYKSDDHPAPFNUYIIGPEABADKGTQARGWXOFGOURLSXHPYSJUEBLVCZWKWXIIDVTTAKHFVOKPQHQQQEAYOZPIQXTZOBVNVQJGIPDBUPVBNLSFZUEGZFWINLRFMYRMFABOVBMHHZEMRCZOKKCMGJVDSAKSCLVIFAPFUJMLADMEYSOE");

    try
    {
      Utils::ByteBuffer bfr;
      IMC::Packet::serialize(&msg, bfr);
      IMC::Message* msg_d = IMC::Packet::deserialize(bfr.getBuffer(), bfr.getSize());
      test.boolean("ReplayControl #1", msg == *msg_d);
      delete msg_d;
    }
    catch (IMC::InvalidMessageSize& e)
    {
      (void)e;
      test.boolean("msg #1", msg.getSerializationSize() > DUNE_IMC_CONST_MAX_SIZE);
    }
  }

  {
    IMC::ReplayControl msg;
    msg.setTimeStamp(0.8943687511631582);
    msg.setSource(4645U);
    msg.setSourceEntity(105U);
    msg.setDestination(23364U);
    msg.setDestinationEntity(225U);
    msg.op = 118U;
    msg.file.assign("FSGGBOCNUPCTYLBTLTKSRNXVBQOYQEVNOJJVLNMLQOOVLALNZZNICHVLPXZEJOWACGQBMSXAHTHKMCHFDLZQAZWKRFSYCIHTNUUWTRWEPBDFDAKHUXWYUUHXXMMWJOVJVPIPUROFRPYGQYSYEJRZNRTBMXPE");

    try
    {
      Utils::ByteBuffer bfr;
      IMC::Packet::serialize(&msg, bfr);
      IMC::Message* msg_d = IMC::Packet::deserialize(bfr.getBuffer(), bfr.getSize());
      test.boolean("ReplayControl #2", msg == *msg_d);
      delete msg_d;
    }
    catch (IMC::InvalidMessageSize& e)
    {
      (void)e;
      test.boolean("msg #2", msg.getSerializationSize() > DUNE_IMC_CONST_MAX_SIZE);
    }
  }

  {
    IMC::ClockControl msg;
    msg.setTimeStamp(0.32595567691413274);
    msg.setSource(29923U);
    msg.setSourceEntity(180U);
    msg.setDestination(48347U);
    msg.setDestinationEntity(125U);
    msg.op = 229U;
    msg.clock = 0.29999968168591806;
    msg.tz = 121;

    try
    {
      Utils::ByteBuffer bfr;
      IMC::Packet::serialize(&msg, bfr);
      IMC::Message* msg_d = IMC::Packet::deserialize(bfr.getBuffer(), bfr.getSize());
      test.boolean("ClockControl #0", msg == *msg_d);
      delete msg_d;
    }
    catch (IMC::InvalidMessageSize& e)
    {
      (void)e;
      test.boolean("msg #0", msg.getSerializationSize() > DUNE_IMC_CONST_MAX_SIZE);
    }
  }

  {
    IMC::ClockControl msg;
    msg.setTimeStamp(0.9439612404274291);
    msg.setSource(52153U);
    msg.setSourceEntity(7U);
    msg.setDestination(60274U);
    msg.setDestinationEntity(187U);
    msg.op = 87U;
    msg.clock = 0.9098115275734602;
    msg.tz = 8;

    try
    {
      Utils::ByteBuffer bfr;
      IMC::Packet::serialize(&msg, bfr);
      IMC::Message* msg_d = IMC::Packet::deserialize(bfr.getBuffer(), bfr.getSize());
      test.boolean("ClockControl #1", msg == *msg_d);
      delete msg_d;
    }
    catch (IMC::InvalidMessageSize& e)
    {
      (void)e;
      test.boolean("msg #1", msg.getSerializationSize() > DUNE_IMC_CONST_MAX_SIZE);
    }
  }

  {
    IMC::ClockControl msg;
    msg.setTimeStamp(0.5315650025855083);
    msg.setSource(55407U);
    msg.setSourceEntity(253U);
    msg.setDestination(2348U);
    msg.setDestinationEntity(251U);
    msg.op = 122U;
    msg.clock = 0.8702625356521658;
    msg.tz = -54;

    try
    {
      Utils::ByteBuffer bfr;
      IMC::Packet::serialize(&msg, bfr);
      IMC::Message* msg_d = IMC::Packet::deserialize(bfr.getBuffer(), bfr.getSize());
      test.boolean("ClockControl #2", msg == *msg_d);
      delete msg_d;
    }
    catch (IMC::InvalidMessageSize& e)
    {
      (void)e;
      test.boolean("msg #2", msg.getSerializationSize() > DUNE_IMC_CONST_MAX_SIZE);
    }
  }

  {
    IMC::HistoricCTD msg;
    msg.setTimeStamp(0.14350518121415456);
    msg.setSource(37767U);
    msg.setSourceEntity(79U);
    msg.setDestination(2097U);
    msg.setDestinationEntity(172U);
    msg.conductivity = 0.5322667257356993;
    msg.temperature = 0.18998137775094226;
    msg.depth = 0.3501006530856552;

    try
    {
      Utils::ByteBuffer bfr;
      IMC::Packet::serialize(&msg, bfr);
      IMC::Message* msg_d = IMC::Packet::deserialize(bfr.getBuffer(), bfr.getSize());
      test.boolean("HistoricCTD #0", msg == *msg_d);
      delete msg_d;
    }
    catch (IMC::InvalidMessageSize& e)
    {
      (void)e;
      test.boolean("msg #0", msg.getSerializationSize() > DUNE_IMC_CONST_MAX_SIZE);
    }
  }

  {
    IMC::HistoricCTD msg;
    msg.setTimeStamp(0.45536273718491793);
    msg.setSource(33997U);
    msg.setSourceEntity(78U);
    msg.setDestination(31017U);
    msg.setDestinationEntity(87U);
    msg.conductivity = 0.8517115550066695;
    msg.temperature = 0.35620929002972457;
    msg.depth = 0.5193136786069079;

    try
    {
      Utils::ByteBuffer bfr;
      IMC::Packet::serialize(&msg, bfr);
      IMC::Message* msg_d = IMC::Packet::deserialize(bfr.getBuffer(), bfr.getSize());
      test.boolean("HistoricCTD #1", msg == *msg_d);
      delete msg_d;
    }
    catch (IMC::InvalidMessageSize& e)
    {
      (void)e;
      test.boolean("msg #1", msg.getSerializationSize() > DUNE_IMC_CONST_MAX_SIZE);
    }
  }

  {
    IMC::HistoricCTD msg;
    msg.setTimeStamp(0.6224955808795657);
    msg.setSource(32925U);
    msg.setSourceEntity(168U);
    msg.setDestination(7549U);
    msg.setDestinationEntity(65U);
    msg.conductivity = 0.12821808368650356;
    msg.temperature = 0.8003131257612403;
    msg.depth = 0.48263461539479613;

    try
    {
      Utils::ByteBuffer bfr;
      IMC::Packet::serialize(&msg, bfr);
      IMC::Message* msg_d = IMC::Packet::deserialize(bfr.getBuffer(), bfr.getSize());
      test.boolean("HistoricCTD #2", msg == *msg_d);
      delete msg_d;
    }
    catch (IMC::InvalidMessageSize& e)
    {
      (void)e;
      test.boolean("msg #2", msg.getSerializationSize() > DUNE_IMC_CONST_MAX_SIZE);
    }
  }

  {
    IMC::HistoricTelemetry msg;
    msg.setTimeStamp(0.38633601170333154);
    msg.setSource(55872U);
    msg.setSourceEntity(79U);
    msg.setDestination(42850U);
    msg.setDestinationEntity(251U);
    msg.altitude = 0.13974103499277102;
    msg.roll = 14725U;
    msg.pitch = 56351U;
    msg.yaw = 50084U;
    msg.speed = -25653;

    try
    {
      Utils::ByteBuffer bfr;
      IMC::Packet::serialize(&msg, bfr);
      IMC::Message* msg_d = IMC::Packet::deserialize(bfr.getBuffer(), bfr.getSize());
      test.boolean("HistoricTelemetry #0", msg == *msg_d);
      delete msg_d;
    }
    catch (IMC::InvalidMessageSize& e)
    {
      (void)e;
      test.boolean("msg #0", msg.getSerializationSize() > DUNE_IMC_CONST_MAX_SIZE);
    }
  }

  {
    IMC::HistoricTelemetry msg;
    msg.setTimeStamp(0.6477569770220888);
    msg.setSource(50641U);
    msg.setSourceEntity(131U);
    msg.setDestination(6913U);
    msg.setDestinationEntity(3U);
    msg.altitude = 0.6312347438064251;
    msg.roll = 19967U;
    msg.pitch = 51090U;
    msg.yaw = 58172U;
    msg.speed = 30665;

    try
    {
      Utils::ByteBuffer bfr;
      IMC::Packet::serialize(&msg, bfr);
      IMC::Message* msg_d = IMC::Packet::deserialize(bfr.getBuffer(), bfr.getSize());
      test.boolean("HistoricTelemetry #1", msg == *msg_d);
      delete msg_d;
    }
    catch (IMC::InvalidMessageSize& e)
    {
      (void)e;
      test.boolean("msg #1", msg.getSerializationSize() > DUNE_IMC_CONST_MAX_SIZE);
    }
  }

  {
    IMC::HistoricTelemetry msg;
    msg.setTimeStamp(0.5946146116067295);
    msg.setSource(47496U);
    msg.setSourceEntity(79U);
    msg.setDestination(16775U);
    msg.setDestinationEntity(5U);
    msg.altitude = 0.5783141871199867;
    msg.roll = 5047U;
    msg.pitch = 8717U;
    msg.yaw = 54135U;
    msg.speed = -18350;

    try
    {
      Utils::ByteBuffer bfr;
      IMC::Packet::serialize(&msg, bfr);
      IMC::Message* msg_d = IMC::Packet::deserialize(bfr.getBuffer(), bfr.getSize());
      test.boolean("HistoricTelemetry #2", msg == *msg_d);
      delete msg_d;
    }
    catch (IMC::InvalidMessageSize& e)
    {
      (void)e;
      test.boolean("msg #2", msg.getSerializationSize() > DUNE_IMC_CONST_MAX_SIZE);
    }
  }

  {
    IMC::HistoricSonarData msg;
    msg.setTimeStamp(0.7497794643845539);
    msg.setSource(14137U);
    msg.setSourceEntity(234U);
    msg.setDestination(41118U);
    msg.setDestinationEntity(87U);
    msg.altitude = 0.8701773623058281;
    msg.width = 0.79688871859971;
    msg.length = 0.9627363519849951;
    msg.bearing = 0.1498544467044829;
    msg.pxl = -7712;
    msg.encoding = 108U;
    const signed char tmp_msg_0[] = {2, -14, -41, 46, -82, 113, -51, 112, -115, -116, 76, 39, -20, -96, 35, -60, 30, 69, 62, -7, -64, -92, 42, 97, -100, -57, 123, 32, -68, -127, 113, -77, -75, -121, -75, 38, -6, -19, 63, -31, 60, -9, 80, 35, 109, -101, 0, -3, -78, -95, 39, -116, 17, 72, 47, -4, -69, -112, -108, -111, 53, -70, 93, 61, -112, -102, -48, -72, 83, 54, 126, -58, -69, -55, 16, -95, 19, -109, 48, 92, 62, -76, -108, 97, 123, -118, -55, 50, 77, 8, 49, 99, 43, 107, -127, -90, 45, 41, -115, -26, 20, 86, 72, -96, -70, 23, -22, -106, 2, -82, 41, 52, -109, 27, 107, 60, -92, 72, -88, -106, -38, 11, 70, -33, -48, 114, -50, 23, -121};
    msg.sonar_data.assign(tmp_msg_0, tmp_msg_0 + sizeof(tmp_msg_0));

    try
    {
      Utils::ByteBuffer bfr;
      IMC::Packet::serialize(&msg, bfr);
      IMC::Message* msg_d = IMC::Packet::deserialize(bfr.getBuffer(), bfr.getSize());
      test.boolean("HistoricSonarData #0", msg == *msg_d);
      delete msg_d;
    }
    catch (IMC::InvalidMessageSize& e)
    {
      (void)e;
      test.boolean("msg #0", msg.getSerializationSize() > DUNE_IMC_CONST_MAX_SIZE);
    }
  }

  {
    IMC::HistoricSonarData msg;
    msg.setTimeStamp(0.23079191355776285);
    msg.setSource(9337U);
    msg.setSourceEntity(56U);
    msg.setDestination(14541U);
    msg.setDestinationEntity(136U);
    msg.altitude = 0.5130552603528524;
    msg.width = 0.33109874374094783;
    msg.length = 0.5715948718066712;
    msg.bearing = 0.22993081442308982;
    msg.pxl = 2254;
    msg.encoding = 245U;
    const signed char tmp_msg_0[] = {9, -103, -71, -91, 3, -66, -122, -109, 42, -95, 47, 75, 21, -15, 73, 114, 19, 76, -102, -37, -22, 87, -28, 62, 120, -110, -105, -100, 36, -94, -56, -32, -77, -108, -87, 67, 91, -88, 35, 37, 39, -59, -66, -117, -48, -32, 85, 93, -121, 111, -107, 8, -61, 8, 53, 103, -62, -1, 57, 101, -41, -49, -32, -66, 106, 88, -50, -3, -76, -35, 13, -53, 81, 106, 48, -99, 115, 62, 91, -99, 49, 97, 123, -65, -65, -101, 96, 126, -16, 88, -114, 17, 56, 81, 75, -105, 73, 75, 13, -67, -28, 64, -39, -128, -16, 126, 76, -40, 123, -49, 119, 4, -87, -122, 89, 109, 122, 67, -122, -110, -81, -30, -37, -86, -86, 20, -99, 92, -62, -33, -43, 0, -126, -96, 7, -3, 84, 113, 85, -128, 96, 95, -10, 29, -18, 57, 18, -32, -122, 94, -71, -105, -118, -110, -16, -29, 60, 120, 10, 5, 37, 98, -72, -102, 18, -93, -61, -45, -66, -47, 41, 8, -49, -45, -80, -106, 73, -126, 125, -96, -50, 53, 90, 38, -106, -97, -101, -80, -76, 45, -16, 73, 104, -52, -14, 19, 76, -116, 54, -75, -86, 64, -68, 9, -29, 16, -50, -65, 29, -124, 103, -123, 95, -47, 73, 12, 80, 8, 124, -106, -80, -53, 17, -40, -68, -109, -70, -56, -69, 73, -120, -73, -40, -112, 57};
    msg.sonar_data.assign(tmp_msg_0, tmp_msg_0 + sizeof(tmp_msg_0));

    try
    {
      Utils::ByteBuffer bfr;
      IMC::Packet::serialize(&msg, bfr);
      IMC::Message* msg_d = IMC::Packet::deserialize(bfr.getBuffer(), bfr.getSize());
      test.boolean("HistoricSonarData #1", msg == *msg_d);
      delete msg_d;
    }
    catch (IMC::InvalidMessageSize& e)
    {
      (void)e;
      test.boolean("msg #1", msg.getSerializationSize() > DUNE_IMC_CONST_MAX_SIZE);
    }
  }

  {
    IMC::HistoricSonarData msg;
    msg.setTimeStamp(0.9484966784165549);
    msg.setSource(11271U);
    msg.setSourceEntity(0U);
    msg.setDestination(50548U);
    msg.setDestinationEntity(244U);
    msg.altitude = 0.5770856202910611;
    msg.width = 0.056323974501840235;
    msg.length = 0.4629667753902854;
    msg.bearing = 0.2680444633414234;
    msg.pxl = -20445;
    msg.encoding = 234U;
    const signed char tmp_msg_0[] = {-61, -99, 110, 0, 69, 72, 118, 124, 51, 113, 17, 108, 46, -32, 124, -33, 7, 36, -56, -88, 112, 4, 118, 125, -24, -16, 123, 78, -27, -114, 76, -115, 44, -32, -36, 9, 112, 49, -53, 78, 51, 80, -110, -11, 32, -59, 77, 22, 109, 72, 29, 55, -38, 83, -81, -109, -48, 45, -122, 92, -34, 44, 24, -106, 5, 122, -117, -110, 21, 80, -57, -56, 74, -25, 117, -14, -33, 45, -23, 61, 86, -25, -124, 75, -25, 109, -67, -68, 84, 93, 11, 67, 11, -77, -125, -109, 23, 44, 39, -28, -107, -50, -71, 48, -55, -3, -114, 108, 78, -115, 49, -75, -90, -83, -119, 50, 89, 110, 39, -16, 77, 1, 71, 72, 125, -100, -98, 108, -55, 102, -117, 16, -87, 98, -57, -121, -45, -67, -120, -62, -58, 35, -72, -81, 95, 123, 111, -97, -36, -2, 14, 122, -90, -115, -87, 24, -67, 47, -42, 95, 57, -8, -67, 62, 5, -70, -89, 103, 59, -101, -76, -55, 12, -3, 19};
    msg.sonar_data.assign(tmp_msg_0, tmp_msg_0 + sizeof(tmp_msg_0));

    try
    {
      Utils::ByteBuffer bfr;
      IMC::Packet::serialize(&msg, bfr);
      IMC::Message* msg_d = IMC::Packet::deserialize(bfr.getBuffer(), bfr.getSize());
      test.boolean("HistoricSonarData #2", msg == *msg_d);
      delete msg_d;
    }
    catch (IMC::InvalidMessageSize& e)
    {
      (void)e;
      test.boolean("msg #2", msg.getSerializationSize() > DUNE_IMC_CONST_MAX_SIZE);
    }
  }

  {
    IMC::HistoricEvent msg;
    msg.setTimeStamp(0.9137451591740926);
    msg.setSource(33450U);
    msg.setSourceEntity(35U);
    msg.setDestination(64128U);
    msg.setDestinationEntity(100U);
    msg.text.assign("QXKLMVCVUTHAARJSGCMRMDOGFCZWHWZYOBIXUZKFWZWKEZHGRPASWLXWSVSNXCRDEFNNVODHXDOJQHLIAPJOWTRAZS");
    msg.type = 193U;

    try
    {
      Utils::ByteBuffer bfr;
      IMC::Packet::serialize(&msg, bfr);
      IMC::Message* msg_d = IMC::Packet::deserialize(bfr.getBuffer(), bfr.getSize());
      test.boolean("HistoricEvent #0", msg == *msg_d);
      delete msg_d;
    }
    catch (IMC::InvalidMessageSize& e)
    {
      (void)e;
      test.boolean("msg #0", msg.getSerializationSize() > DUNE_IMC_CONST_MAX_SIZE);
    }
  }

  {
    IMC::HistoricEvent msg;
    msg.setTimeStamp(0.8518707080444298);
    msg.setSource(17470U);
    msg.setSourceEntity(194U);
    msg.setDestination(27524U);
    msg.setDestinationEntity(69U);
    msg.text.assign("ZGTSVYXUHQVGETWNPPTXLULHYMBFEFLXMJSBJERWANNMUUKRQGHJBRSMGICISYNBVGQZRYKEPD");
    msg.type = 128U;

    try
    {
      Utils::ByteBuffer bfr;
      IMC::Packet::serialize(&msg, bfr);
      IMC::Message* msg_d = IMC::Packet::deserialize(bfr.getBuffer(), bfr.getSize());
      test.boolean("HistoricEvent #1", msg == *msg_d);
      delete msg_d;
    }
    catch (IMC::InvalidMessageSize& e)
    {
      (void)e;
      test.boolean("msg #1", msg.getSerializationSize() > DUNE_IMC_CONST_MAX_SIZE);
    }
  }

  {
    IMC::HistoricEvent msg;
    msg.setTimeStamp(0.9659162178386838);
    msg.setSource(27616U);
    msg.setSourceEntity(205U);
    msg.setDestination(51128U);
    msg.setDestinationEntity(206U);
    msg.text.assign("VHLAHXMDDQBRAKVLCLFVTAQBFLKLYYKKLFFNZMSXWBRMRCDWZATDHPBEFLNSOCEWHYXIUPLWVEUZSTKSBVZFUJIHSJENDANKBYBHQGGTQEJGNXYCINOGHICIDCATTMQCVVJIBGONLHUQEYGZTWFZPSEIFAAQTMI");
    msg.type = 27U;

    try
    {
      Utils::ByteBuffer bfr;
      IMC::Packet::serialize(&msg, bfr);
      IMC::Message* msg_d = IMC::Packet::deserialize(bfr.getBuffer(), bfr.getSize());
      test.boolean("HistoricEvent #2", msg == *msg_d);
      delete msg_d;
    }
    catch (IMC::InvalidMessageSize& e)
    {
      (void)e;
      test.boolean("msg #2", msg.getSerializationSize() > DUNE_IMC_CONST_MAX_SIZE);
    }
  }

  {
    IMC::VerticalProfile msg;
    msg.setTimeStamp(0.5483708487858729);
    msg.setSource(26619U);
    msg.setSourceEntity(33U);
    msg.setDestination(13423U);
    msg.setDestinationEntity(168U);
    msg.parameter = 33U;
    msg.numsamples = 147U;
    IMC::ProfileSample tmp_msg_0;
    tmp_msg_0.depth = 38730U;
    tmp_msg_0.avg = 0.7719361496514128;
    msg.samples.push_back(tmp_msg_0);
    msg.lat = 0.6346433906583282;
    msg.lon = 0.25813070844252384;

    try
    {
      Utils::ByteBuffer bfr;
      IMC::Packet::serialize(&msg, bfr);
      IMC::Message* msg_d = IMC::Packet::deserialize(bfr.getBuffer(), bfr.getSize());
      test.boolean("VerticalProfile #0", msg == *msg_d);
      delete msg_d;
    }
    catch (IMC::InvalidMessageSize& e)
    {
      (void)e;
      test.boolean("msg #0", msg.getSerializationSize() > DUNE_IMC_CONST_MAX_SIZE);
    }
  }

  {
    IMC::VerticalProfile msg;
    msg.setTimeStamp(0.204472915984504);
    msg.setSource(12894U);
    msg.setSourceEntity(178U);
    msg.setDestination(39949U);
    msg.setDestinationEntity(186U);
    msg.parameter = 44U;
    msg.numsamples = 58U;
    msg.lat = 0.2761164622034886;
    msg.lon = 0.7705150935900161;

    try
    {
      Utils::ByteBuffer bfr;
      IMC::Packet::serialize(&msg, bfr);
      IMC::Message* msg_d = IMC::Packet::deserialize(bfr.getBuffer(), bfr.getSize());
      test.boolean("VerticalProfile #1", msg == *msg_d);
      delete msg_d;
    }
    catch (IMC::InvalidMessageSize& e)
    {
      (void)e;
      test.boolean("msg #1", msg.getSerializationSize() > DUNE_IMC_CONST_MAX_SIZE);
    }
  }

  {
    IMC::VerticalProfile msg;
    msg.setTimeStamp(0.29687987460094256);
    msg.setSource(60575U);
    msg.setSourceEntity(140U);
    msg.setDestination(62924U);
    msg.setDestinationEntity(42U);
    msg.parameter = 171U;
    msg.numsamples = 88U;
    IMC::ProfileSample tmp_msg_0;
    tmp_msg_0.depth = 7299U;
    tmp_msg_0.avg = 0.8041084480827717;
    msg.samples.push_back(tmp_msg_0);
    msg.lat = 0.522479020159972;
    msg.lon = 0.6166071729144438;

    try
    {
      Utils::ByteBuffer bfr;
      IMC::Packet::serialize(&msg, bfr);
      IMC::Message* msg_d = IMC::Packet::deserialize(bfr.getBuffer(), bfr.getSize());
      test.boolean("VerticalProfile #2", msg == *msg_d);
      delete msg_d;
    }
    catch (IMC::InvalidMessageSize& e)
    {
      (void)e;
      test.boolean("msg #2", msg.getSerializationSize() > DUNE_IMC_CONST_MAX_SIZE);
    }
  }

  {
    IMC::ProfileSample msg;
    msg.setTimeStamp(0.30627432941296173);
    msg.setSource(23156U);
    msg.setSourceEntity(137U);
    msg.setDestination(41097U);
    msg.setDestinationEntity(50U);
    msg.depth = 17684U;
    msg.avg = 0.6050265109633619;

    try
    {
      Utils::ByteBuffer bfr;
      IMC::Packet::serialize(&msg, bfr);
      IMC::Message* msg_d = IMC::Packet::deserialize(bfr.getBuffer(), bfr.getSize());
      test.boolean("ProfileSample #0", msg == *msg_d);
      delete msg_d;
    }
    catch (IMC::InvalidMessageSize& e)
    {
      (void)e;
      test.boolean("msg #0", msg.getSerializationSize() > DUNE_IMC_CONST_MAX_SIZE);
    }
  }

  {
    IMC::ProfileSample msg;
    msg.setTimeStamp(0.19473338178167887);
    msg.setSource(716U);
    msg.setSourceEntity(132U);
    msg.setDestination(24276U);
    msg.setDestinationEntity(166U);
    msg.depth = 29906U;
    msg.avg = 0.5092511477716922;

    try
    {
      Utils::ByteBuffer bfr;
      IMC::Packet::serialize(&msg, bfr);
      IMC::Message* msg_d = IMC::Packet::deserialize(bfr.getBuffer(), bfr.getSize());
      test.boolean("ProfileSample #1", msg == *msg_d);
      delete msg_d;
    }
    catch (IMC::InvalidMessageSize& e)
    {
      (void)e;
      test.boolean("msg #1", msg.getSerializationSize() > DUNE_IMC_CONST_MAX_SIZE);
    }
  }

  {
    IMC::ProfileSample msg;
    msg.setTimeStamp(0.5124286706436393);
    msg.setSource(16830U);
    msg.setSourceEntity(35U);
    msg.setDestination(11357U);
    msg.setDestinationEntity(75U);
    msg.depth = 62836U;
    msg.avg = 0.5768570338986461;

    try
    {
      Utils::ByteBuffer bfr;
      IMC::Packet::serialize(&msg, bfr);
      IMC::Message* msg_d = IMC::Packet::deserialize(bfr.getBuffer(), bfr.getSize());
      test.boolean("ProfileSample #2", msg == *msg_d);
      delete msg_d;
    }
    catch (IMC::InvalidMessageSize& e)
    {
      (void)e;
      test.boolean("msg #2", msg.getSerializationSize() > DUNE_IMC_CONST_MAX_SIZE);
    }
  }

  {
    IMC::Heartbeat msg;
    msg.setTimeStamp(0.9319321542412066);
    msg.setSource(37584U);
    msg.setSourceEntity(163U);
    msg.setDestination(19721U);
    msg.setDestinationEntity(189U);

    try
    {
      Utils::ByteBuffer bfr;
      IMC::Packet::serialize(&msg, bfr);
      IMC::Message* msg_d = IMC::Packet::deserialize(bfr.getBuffer(), bfr.getSize());
      test.boolean("Heartbeat #0", msg == *msg_d);
      delete msg_d;
    }
    catch (IMC::InvalidMessageSize& e)
    {
      (void)e;
      test.boolean("msg #0", msg.getSerializationSize() > DUNE_IMC_CONST_MAX_SIZE);
    }
  }

  {
    IMC::Heartbeat msg;
    msg.setTimeStamp(0.8597778475348635);
    msg.setSource(41337U);
    msg.setSourceEntity(10U);
    msg.setDestination(63488U);
    msg.setDestinationEntity(51U);

    try
    {
      Utils::ByteBuffer bfr;
      IMC::Packet::serialize(&msg, bfr);
      IMC::Message* msg_d = IMC::Packet::deserialize(bfr.getBuffer(), bfr.getSize());
      test.boolean("Heartbeat #1", msg == *msg_d);
      delete msg_d;
    }
    catch (IMC::InvalidMessageSize& e)
    {
      (void)e;
      test.boolean("msg #1", msg.getSerializationSize() > DUNE_IMC_CONST_MAX_SIZE);
    }
  }

  {
    IMC::Heartbeat msg;
    msg.setTimeStamp(0.8636909645619487);
    msg.setSource(6861U);
    msg.setSourceEntity(90U);
    msg.setDestination(51112U);
    msg.setDestinationEntity(120U);

    try
    {
      Utils::ByteBuffer bfr;
      IMC::Packet::serialize(&msg, bfr);
      IMC::Message* msg_d = IMC::Packet::deserialize(bfr.getBuffer(), bfr.getSize());
      test.boolean("Heartbeat #2", msg == *msg_d);
      delete msg_d;
    }
    catch (IMC::InvalidMessageSize& e)
    {
      (void)e;
      test.boolean("msg #2", msg.getSerializationSize() > DUNE_IMC_CONST_MAX_SIZE);
    }
  }

  {
    IMC::Announce msg;
    msg.setTimeStamp(0.03995167261686461);
    msg.setSource(5613U);
    msg.setSourceEntity(202U);
    msg.setDestination(57509U);
    msg.setDestinationEntity(171U);
    msg.sys_name.assign("WJQFQGMBJWDDAZUAXFXPIOSRAJRWJZZHHQSSULEZPEWUQMSUZRRIEBORPSBBCXGLLKDAAKINSMYVIVCQBZEVJNKZJHGTTBDYCZEOOZYFUMLAAIMDYQUYICCSYUSPATVPPYMJXCPEWCWIFQUPCMTNGKERPVELGFHOZYXDNNKHWYDVSMGWUAIKFDVGIKXTBPXGLHKFTOXCNWFBKHGIJMDOBURQAWEKLNVLG");
    msg.sys_type = 137U;
    msg.owner = 52188U;
    msg.lat = 0.155983654979016;
    msg.lon = 0.5594692952113098;
    msg.height = 0.10997308962037444;
    msg.services.assign("AKMTTPNBDLPJBJGWDJMSJBGYCFDBASLJFZLXUGBNCZUIQUMNPTCGWJRRHMOZNYOXDXZOBMNUMIDSVLBQYGTKXGHESHVYTMOOZVIETRVVFEPIPGUXVVXSXSWISFWYFSCRUCQLGFACZDQQJZHNOOMHDSEWEJQXCWEKKHZCURJMFGRDVAHWAOBUITXFWNRKAYHEFRQEQWPTLDPWHYBITDKNROZQYAK");

    try
    {
      Utils::ByteBuffer bfr;
      IMC::Packet::serialize(&msg, bfr);
      IMC::Message* msg_d = IMC::Packet::deserialize(bfr.getBuffer(), bfr.getSize());
      test.boolean("Announce #0", msg == *msg_d);
      delete msg_d;
    }
    catch (IMC::InvalidMessageSize& e)
    {
      (void)e;
      test.boolean("msg #0", msg.getSerializationSize() > DUNE_IMC_CONST_MAX_SIZE);
    }
  }

  {
    IMC::Announce msg;
    msg.setTimeStamp(0.30971100152393705);
    msg.setSource(40526U);
    msg.setSourceEntity(193U);
    msg.setDestination(30212U);
    msg.setDestinationEntity(200U);
    msg.sys_name.assign("UTNHCVURMXXMNOXGQICXIXJJGYDVMBQRGTYFFECAPBAKTNHMDNHJAAGOWL");
    msg.sys_type = 217U;
    msg.owner = 62006U;
    msg.lat = 0.9377392340038332;
    msg.lon = 0.9103415277028617;
    msg.height = 0.5998532497730485;
    msg.services.assign("QPXXJTXLFUZVOJYWVBDJWIOIFCIGMRGCCDZEZVVHWFSNQHYZBTXEAMPLPXLVNCECWXYUDSUTSZOEYSOSXZTCHSZUSYUASXQOFGDBENENROPLNIILJWXVHRBGNGPQGBCFJMJSPAKAFYUBKRJEHHGFKNFTHGQQDDAVIZKMZFDIPPMNYMBRWABVKWTQHAOTPHCYFLRJJOLKVBUHKUSKWIE");

    try
    {
      Utils::ByteBuffer bfr;
      IMC::Packet::serialize(&msg, bfr);
      IMC::Message* msg_d = IMC::Packet::deserialize(bfr.getBuffer(), bfr.getSize());
      test.boolean("Announce #1", msg == *msg_d);
      delete msg_d;
    }
    catch (IMC::InvalidMessageSize& e)
    {
      (void)e;
      test.boolean("msg #1", msg.getSerializationSize() > DUNE_IMC_CONST_MAX_SIZE);
    }
  }

  {
    IMC::Announce msg;
    msg.setTimeStamp(0.22790413036894042);
    msg.setSource(14427U);
    msg.setSourceEntity(247U);
    msg.setDestination(53274U);
    msg.setDestinationEntity(118U);
    msg.sys_name.assign("YFNKUMQSTFQOSJAQCQVAPDGNWCNYLADURQOYRIJMWFRQLCFIKGBXZPUHTZDXVJPGEHWHYJUXXKOSRZPCMNBRYEKHZQSLTNJIBBWWWXIXZAZYOHMYGDRZFDLQPPDAHBCXFJZKNADEUPEMUKVEUXJDETEFGZGTQCSRYBASXCRWMXTFCKKEVINPVZWTIBSVKVJGOONLMHJSGALOP");
    msg.sys_type = 19U;
    msg.owner = 56859U;
    msg.lat = 0.08747461235428333;
    msg.lon = 0.8558524311785838;
    msg.height = 0.5724377517293757;
    msg.services.assign("MWKELSGGIAOKLAYRCQRAGUVJURNAEAGBEGSDJHBXHQKQVOMBNPNUJPPURFSXVQICZHEJZDSVIOVHGAFYDRLPOZLFZKCMITBOPHNNIRXCCGEFDQQYEVCTSABMWLDXLWLYXBSWCOXJNCKIYATRQOEPZJMIWWNHQMOEEUSTRSQDVGZFVCBJTFHNHTUFLYXD");

    try
    {
      Utils::ByteBuffer bfr;
      IMC::Packet::serialize(&msg, bfr);
      IMC::Message* msg_d = IMC::Packet::deserialize(bfr.getBuffer(), bfr.getSize());
      test.boolean("Announce #2", msg == *msg_d);
      delete msg_d;
    }
    catch (IMC::InvalidMessageSize& e)
    {
      (void)e;
      test.boolean("msg #2", msg.getSerializationSize() > DUNE_IMC_CONST_MAX_SIZE);
    }
  }

  {
    IMC::AnnounceService msg;
    msg.setTimeStamp(0.4352855726762713);
    msg.setSource(21677U);
    msg.setSourceEntity(238U);
    msg.setDestination(8550U);
    msg.setDestinationEntity(240U);
    msg.service.assign("VCMNWOFMAVNHYWWSPZROMYVJBGXEHHIGPJRQTPFSOFSHOQDMTLAQDKKBGCGLACBDKVUYHJABMXUXXZICAZKUSYDWFQWMFGGXOGWAZMICHPUIKRWTDNAJZBYARDINQFGRMBSOCDUOEPTXVRQRMPWQDVNEYKVEDNLKBFQWCSRXSECEOFFNKOLPEAXGJLILIEJYUHNVXPVZPNTLURUQZEVEZUHBAKJBTYUNJTCLCOYHZZBMXYHSLFJDTJISPWGKRT");
    msg.service_type = 151U;

    try
    {
      Utils::ByteBuffer bfr;
      IMC::Packet::serialize(&msg, bfr);
      IMC::Message* msg_d = IMC::Packet::deserialize(bfr.getBuffer(), bfr.getSize());
      test.boolean("AnnounceService #0", msg == *msg_d);
      delete msg_d;
    }
    catch (IMC::InvalidMessageSize& e)
    {
      (void)e;
      test.boolean("msg #0", msg.getSerializationSize() > DUNE_IMC_CONST_MAX_SIZE);
    }
  }

  {
    IMC::AnnounceService msg;
    msg.setTimeStamp(0.3788414494274578);
    msg.setSource(43046U);
    msg.setSourceEntity(223U);
    msg.setDestination(26180U);
    msg.setDestinationEntity(144U);
    msg.service.assign("QCAEBBJINAJDQLAYFHYORQSQFWWTKOAYZDHBBOPZIVXKLQAKXMPRIVKRENCXNEHKCVVGHIVOMKDTVANPUTGPRBMFJJROPLEUMHXNKGSKZRHONNJCGEHWUCJZCXSJJVJP");
    msg.service_type = 244U;

    try
    {
      Utils::ByteBuffer bfr;
      IMC::Packet::serialize(&msg, bfr);
      IMC::Message* msg_d = IMC::Packet::deserialize(bfr.getBuffer(), bfr.getSize());
      test.boolean("AnnounceService #1", msg == *msg_d);
      delete msg_d;
    }
    catch (IMC::InvalidMessageSize& e)
    {
      (void)e;
      test.boolean("msg #1", msg.getSerializationSize() > DUNE_IMC_CONST_MAX_SIZE);
    }
  }

  {
    IMC::AnnounceService msg;
    msg.setTimeStamp(0.8958450399954454);
    msg.setSource(1233U);
    msg.setSourceEntity(0U);
    msg.setDestination(9706U);
    msg.setDestinationEntity(242U);
    msg.service.assign("HSDGUDVTODMWOVUUUKNAGSEGZRHXFNYXBWFFHEGPYIYXTXCYWKILLQXXQVWUKTNAGBOZOEVPJUUWMVCSTMIJCHPJLNSWMTGRPWFYJBP");
    msg.service_type = 227U;

    try
    {
      Utils::ByteBuffer bfr;
      IMC::Packet::serialize(&msg, bfr);
      IMC::Message* msg_d = IMC::Packet::deserialize(bfr.getBuffer(), bfr.getSize());
      test.boolean("AnnounceService #2", msg == *msg_d);
      delete msg_d;
    }
    catch (IMC::InvalidMessageSize& e)
    {
      (void)e;
      test.boolean("msg #2", msg.getSerializationSize() > DUNE_IMC_CONST_MAX_SIZE);
    }
  }

  {
    IMC::RSSI msg;
    msg.setTimeStamp(0.6440461597560879);
    msg.setSource(40671U);
    msg.setSourceEntity(226U);
    msg.setDestination(48825U);
    msg.setDestinationEntity(87U);
    msg.value = 0.2661687458514831;

    try
    {
      Utils::ByteBuffer bfr;
      IMC::Packet::serialize(&msg, bfr);
      IMC::Message* msg_d = IMC::Packet::deserialize(bfr.getBuffer(), bfr.getSize());
      test.boolean("RSSI #0", msg == *msg_d);
      delete msg_d;
    }
    catch (IMC::InvalidMessageSize& e)
    {
      (void)e;
      test.boolean("msg #0", msg.getSerializationSize() > DUNE_IMC_CONST_MAX_SIZE);
    }
  }

  {
    IMC::RSSI msg;
    msg.setTimeStamp(0.8120680627974962);
    msg.setSource(9373U);
    msg.setSourceEntity(13U);
    msg.setDestination(24181U);
    msg.setDestinationEntity(25U);
    msg.value = 0.015644945050478865;

    try
    {
      Utils::ByteBuffer bfr;
      IMC::Packet::serialize(&msg, bfr);
      IMC::Message* msg_d = IMC::Packet::deserialize(bfr.getBuffer(), bfr.getSize());
      test.boolean("RSSI #1", msg == *msg_d);
      delete msg_d;
    }
    catch (IMC::InvalidMessageSize& e)
    {
      (void)e;
      test.boolean("msg #1", msg.getSerializationSize() > DUNE_IMC_CONST_MAX_SIZE);
    }
  }

  {
    IMC::RSSI msg;
    msg.setTimeStamp(0.541953685286944);
    msg.setSource(52760U);
    msg.setSourceEntity(28U);
    msg.setDestination(25510U);
    msg.setDestinationEntity(66U);
    msg.value = 0.33533053019277814;

    try
    {
      Utils::ByteBuffer bfr;
      IMC::Packet::serialize(&msg, bfr);
      IMC::Message* msg_d = IMC::Packet::deserialize(bfr.getBuffer(), bfr.getSize());
      test.boolean("RSSI #2", msg == *msg_d);
      delete msg_d;
    }
    catch (IMC::InvalidMessageSize& e)
    {
      (void)e;
      test.boolean("msg #2", msg.getSerializationSize() > DUNE_IMC_CONST_MAX_SIZE);
    }
  }

  {
    IMC::VSWR msg;
    msg.setTimeStamp(0.09320220205505947);
    msg.setSource(8423U);
    msg.setSourceEntity(102U);
    msg.setDestination(29885U);
    msg.setDestinationEntity(80U);
    msg.value = 0.8578312111123542;

    try
    {
      Utils::ByteBuffer bfr;
      IMC::Packet::serialize(&msg, bfr);
      IMC::Message* msg_d = IMC::Packet::deserialize(bfr.getBuffer(), bfr.getSize());
      test.boolean("VSWR #0", msg == *msg_d);
      delete msg_d;
    }
    catch (IMC::InvalidMessageSize& e)
    {
      (void)e;
      test.boolean("msg #0", msg.getSerializationSize() > DUNE_IMC_CONST_MAX_SIZE);
    }
  }

  {
    IMC::VSWR msg;
    msg.setTimeStamp(0.526050684882864);
    msg.setSource(13754U);
    msg.setSourceEntity(125U);
    msg.setDestination(62660U);
    msg.setDestinationEntity(247U);
    msg.value = 0.9127741810233305;

    try
    {
      Utils::ByteBuffer bfr;
      IMC::Packet::serialize(&msg, bfr);
      IMC::Message* msg_d = IMC::Packet::deserialize(bfr.getBuffer(), bfr.getSize());
      test.boolean("VSWR #1", msg == *msg_d);
      delete msg_d;
    }
    catch (IMC::InvalidMessageSize& e)
    {
      (void)e;
      test.boolean("msg #1", msg.getSerializationSize() > DUNE_IMC_CONST_MAX_SIZE);
    }
  }

  {
    IMC::VSWR msg;
    msg.setTimeStamp(0.21608113316589683);
    msg.setSource(55897U);
    msg.setSourceEntity(112U);
    msg.setDestination(65500U);
    msg.setDestinationEntity(207U);
    msg.value = 0.41930032286316077;

    try
    {
      Utils::ByteBuffer bfr;
      IMC::Packet::serialize(&msg, bfr);
      IMC::Message* msg_d = IMC::Packet::deserialize(bfr.getBuffer(), bfr.getSize());
      test.boolean("VSWR #2", msg == *msg_d);
      delete msg_d;
    }
    catch (IMC::InvalidMessageSize& e)
    {
      (void)e;
      test.boolean("msg #2", msg.getSerializationSize() > DUNE_IMC_CONST_MAX_SIZE);
    }
  }

  {
    IMC::LinkLevel msg;
    msg.setTimeStamp(0.6662367883960565);
    msg.setSource(17781U);
    msg.setSourceEntity(3U);
    msg.setDestination(47003U);
    msg.setDestinationEntity(250U);
    msg.value = 0.6673464654692827;

    try
    {
      Utils::ByteBuffer bfr;
      IMC::Packet::serialize(&msg, bfr);
      IMC::Message* msg_d = IMC::Packet::deserialize(bfr.getBuffer(), bfr.getSize());
      test.boolean("LinkLevel #0", msg == *msg_d);
      delete msg_d;
    }
    catch (IMC::InvalidMessageSize& e)
    {
      (void)e;
      test.boolean("msg #0", msg.getSerializationSize() > DUNE_IMC_CONST_MAX_SIZE);
    }
  }

  {
    IMC::LinkLevel msg;
    msg.setTimeStamp(0.10722117238128481);
    msg.setSource(10329U);
    msg.setSourceEntity(169U);
    msg.setDestination(63819U);
    msg.setDestinationEntity(27U);
    msg.value = 0.8701917413583364;

    try
    {
      Utils::ByteBuffer bfr;
      IMC::Packet::serialize(&msg, bfr);
      IMC::Message* msg_d = IMC::Packet::deserialize(bfr.getBuffer(), bfr.getSize());
      test.boolean("LinkLevel #1", msg == *msg_d);
      delete msg_d;
    }
    catch (IMC::InvalidMessageSize& e)
    {
      (void)e;
      test.boolean("msg #1", msg.getSerializationSize() > DUNE_IMC_CONST_MAX_SIZE);
    }
  }

  {
    IMC::LinkLevel msg;
    msg.setTimeStamp(0.5317550337762714);
    msg.setSource(53884U);
    msg.setSourceEntity(209U);
    msg.setDestination(8871U);
    msg.setDestinationEntity(90U);
    msg.value = 0.8953898495964092;

    try
    {
      Utils::ByteBuffer bfr;
      IMC::Packet::serialize(&msg, bfr);
      IMC::Message* msg_d = IMC::Packet::deserialize(bfr.getBuffer(), bfr.getSize());
      test.boolean("LinkLevel #2", msg == *msg_d);
      delete msg_d;
    }
    catch (IMC::InvalidMessageSize& e)
    {
      (void)e;
      test.boolean("msg #2", msg.getSerializationSize() > DUNE_IMC_CONST_MAX_SIZE);
    }
  }

  {
    IMC::Sms msg;
    msg.setTimeStamp(0.10983342181069078);
    msg.setSource(4008U);
    msg.setSourceEntity(193U);
    msg.setDestination(49493U);
    msg.setDestinationEntity(34U);
    msg.number.assign("KWQWLRCZGSQVWAFQEVBSWJKRMHQEEGLNOAZTWZDVCKQMYXAHCXLYGNIWVASORENAXEZVYMPJIFHFRDFIUHIBNIRRMZWSXVSSTKGLTC");
    msg.timeout = 34772U;
    msg.contents.assign("LTQFXDZXTHDFEYGLQBOIWVJRLSPFAIUJBPOINLKAHNHPKDHEYADBTGIRUAJJPBCBJDECTDHMXSWZPBDYLVGAPGJUXQGHSU");

    try
    {
      Utils::ByteBuffer bfr;
      IMC::Packet::serialize(&msg, bfr);
      IMC::Message* msg_d = IMC::Packet::deserialize(bfr.getBuffer(), bfr.getSize());
      test.boolean("Sms #0", msg == *msg_d);
      delete msg_d;
    }
    catch (IMC::InvalidMessageSize& e)
    {
      (void)e;
      test.boolean("msg #0", msg.getSerializationSize() > DUNE_IMC_CONST_MAX_SIZE);
    }
  }

  {
    IMC::Sms msg;
    msg.setTimeStamp(0.14025700076804648);
    msg.setSource(32937U);
    msg.setSourceEntity(65U);
    msg.setDestination(31075U);
    msg.setDestinationEntity(45U);
    msg.number.assign("VARDUTAZXMEVLYQNAIMJDKYFJAWPMYLCDWWDMWOJTVHGWHNFPKJXZAAINGDYAUJUUHRYFCELSGAQRULNWHFCRQKMOLPMBPUDZOEXWDROHCZGYQKXVAERUREVHTGSKMAIIFEGCTXLYKNBECHWBNILNULMTJUKZQBSIORBGMXBYOZGFXTZNMRPDW");
    msg.timeout = 52502U;
    msg.contents.assign("ZRGZVZAAHWURLFFBXKSRVACNCVFJSXGHEIONAPHQWNPRNLKMOCBOAIMELLFWIEENLGOXXYYGNVJJKAPEVKPVMYWJPPCUWDXOWIOKNWBMMROTSDDRSRVTYURZVYADPTZETPRILFZPFJZXYMUBWTBRXKQHHVSHLIJFUUTSGNCGLWQQYPQSNQJVYQQMODMDJUGOAKCIBBQXETHZYTSATSGBHEDGUXTFCUJQDLKLOEXMCKHFWIZEAZGBHSDFDIC");

    try
    {
      Utils::ByteBuffer bfr;
      IMC::Packet::serialize(&msg, bfr);
      IMC::Message* msg_d = IMC::Packet::deserialize(bfr.getBuffer(), bfr.getSize());
      test.boolean("Sms #1", msg == *msg_d);
      delete msg_d;
    }
    catch (IMC::InvalidMessageSize& e)
    {
      (void)e;
      test.boolean("msg #1", msg.getSerializationSize() > DUNE_IMC_CONST_MAX_SIZE);
    }
  }

  {
    IMC::Sms msg;
    msg.setTimeStamp(0.9492888710675536);
    msg.setSource(4855U);
    msg.setSourceEntity(218U);
    msg.setDestination(44655U);
    msg.setDestinationEntity(227U);
    msg.number.assign("QZSYXRKYYEG");
    msg.timeout = 33644U;
    msg.contents.assign("GCHVPXQHLLKJLDQUCOWZLMCWDUMYJGREHKFWGGAYQIJECUUQEJSUOZHVXFRBRKSQTXZTSYULDIXWOODFPCOILRBKJZOVXZWDTZMTKPFXQMOLBODGNBEVQWTDAATFMQNPKGWZHPVVPJCHSWA");

    try
    {
      Utils::ByteBuffer bfr;
      IMC::Packet::serialize(&msg, bfr);
      IMC::Message* msg_d = IMC::Packet::deserialize(bfr.getBuffer(), bfr.getSize());
      test.boolean("Sms #2", msg == *msg_d);
      delete msg_d;
    }
    catch (IMC::InvalidMessageSize& e)
    {
      (void)e;
      test.boolean("msg #2", msg.getSerializationSize() > DUNE_IMC_CONST_MAX_SIZE);
    }
  }

  {
    IMC::SmsTx msg;
    msg.setTimeStamp(0.8704357322680212);
    msg.setSource(55094U);
    msg.setSourceEntity(62U);
    msg.setDestination(41321U);
    msg.setDestinationEntity(239U);
    msg.seq = 339253231U;
    msg.destination.assign("XQNOSXBRMZPBYSDHRFCEJRGYXCEVMPQGBEQDGZWZSUXYCSIYMKKTTOMDBDAFBJUHFIEBGLWPYJDZSMBYBFOZJVNRRQKUVINCXZVVMTHMOIIHXEZXARNIXSUTRKNOJQLEXSOFGIIPNOLHCJCSPSMDWW");
    msg.timeout = 48287U;
    const signed char tmp_msg_0[] = {-105, -101, 24, -29, -17, 3, -106, 38, -124, -95, -78, 71, -101, -2, 108, -4, 52, 26, -9, 94, -53, 55, 35, 69, -13, 74, 101, 81, 53, -67, 78, -123, 77, 115, 100, 16, -111, -7, -126, 48, 18, -30, -76, 41, 80, 78, 114, 86, 23, 16, -92, 58, -62, 115, 102, -16, -15, -102, -30, -83, -24, -33, 46, -89, -52, -42, -31, -39, -103, -2, -72, -40, 28, 20, 65, 89, -68, -16, -18, 70, -32, -81, 40, -114, -73, -82, 35, 45, 15, -72, 37, 64, 101, -45, 118, 80, -48, 21, -14, 2, 12, -71, 26, -114, 49, -35, -31, 76, -67, 30, -115, -85, 21, -81, 58, 56, -85, -2, -99, 8, 95, 100, -108, 48, -40, -119, 106, 95, -37, 30, 124, 70, 92, -34, -84, -75, -8, 56, 85, -70, -120, -69, 55, 88, -68, -77, 124, 44, -102, 120, 114, 40, 97, -26, 98, 84, 107, 33, -123, 36, 112, 11, -55, 49, -9, 33, -15, 77, -110, 115, 73, -28, 122, -61, -107, 33, 6, -26, 12, -68, 13, 3, 61, 15, -13, -105, -23, 94, 23, -106, 37, 28, -64, 114, 43, -79, 90, 82, 35, 92, -28, 26, 76, 45, -124, 76, -90, 35, -113, 3, -74, -68, 46, 17, 97, -72, -52, -26, -13, -63, 96, -34, 32, -114, -26, -36, 27, 36};
    msg.data.assign(tmp_msg_0, tmp_msg_0 + sizeof(tmp_msg_0));

    try
    {
      Utils::ByteBuffer bfr;
      IMC::Packet::serialize(&msg, bfr);
      IMC::Message* msg_d = IMC::Packet::deserialize(bfr.getBuffer(), bfr.getSize());
      test.boolean("SmsTx #0", msg == *msg_d);
      delete msg_d;
    }
    catch (IMC::InvalidMessageSize& e)
    {
      (void)e;
      test.boolean("msg #0", msg.getSerializationSize() > DUNE_IMC_CONST_MAX_SIZE);
    }
  }

  {
    IMC::SmsTx msg;
    msg.setTimeStamp(0.052779792943627446);
    msg.setSource(52932U);
    msg.setSourceEntity(93U);
    msg.setDestination(45772U);
    msg.setDestinationEntity(22U);
    msg.seq = 4197560927U;
    msg.destination.assign("DIYRXKZGGHXIVRSJHLASFUOTBIBXDSTFNRSUXPJUBBEMETJQKZAOONGPUVJCSERGNYJXFIPCWWDQGCEKVOFJDYAMJAQFIQRGVLOCCLSZANWFEZQMBSOBQWXPGOWDYFAALLJWMIUVHZMCLBTDYURKZTXPMNHDVCSDLZENTYILQLFEQYIPWZRAYTUNMECJOIUISFS");
    msg.timeout = 36893U;
    const signed char tmp_msg_0[] = {105, -51, -91, 52, -125, 18, 117, -9, -34, -39, -94, 40, -78, -80, -23, -85, -62, 34, 122, 13, -32, -112, -72, 26, 39, -22, 47, -89, -111, -83, -75, -84, 79, 91, -102, -84, 11, 47, -6, -64, -125, 12, -81, -30, -123, 105, -28, -8, -67, -34, -34, 122, 4, -52, 89, 83, 47, 53, -14, -93, -15, 86, 105, 7, -102, -60, -75, 100, 95, -108, 126, 68, -9, -70, -97, -56, 24, -10, -40, 77, -71, -32, 90, 35, -62, 66, -59, -76, 35, -92, -120, 44, 89, 47, 86, 51, 41, -1, -67, -23, 19, 14, 108, -45, 39, -107, 58, 117, -93, -95, 89, 123, 8, -40, 43, 41, 108, -76, 120, 4, -78, -122, 13, -109, 39, -77, -86, 46, 60, -94, -128, -58, 76, 6, 21, -99, -51, -13, 96, 92, -70, -13, 97, -98, 62, 43, 81, -31, -20, 108, -111, 103, 49, 90, 29, 25, -83, 106, -114, -34, 22, -35, -96, -5, -93, 76, 4, 69, 116, 75, -120, -81, 108, -4, -111, -54, -125, -58, 101, -43, 123, 27, -67, -124, -65, -97, 80, 120, 27, -17, -55, 82, 124, -21, 38, -35, -115, -87, 9, -125, 72, 5, -15, -14, 58, -47, 41, -126, 40, 75, -55, 26, -98, -29, -30, -97, 20, -6, 107, 29, -65, -88, 49, 42, 22, 48, 101, 118, -126, -19, 90, -28, 42, -98, 67, 69, 1, -32, -107, -54, 89};
    msg.data.assign(tmp_msg_0, tmp_msg_0 + sizeof(tmp_msg_0));

    try
    {
      Utils::ByteBuffer bfr;
      IMC::Packet::serialize(&msg, bfr);
      IMC::Message* msg_d = IMC::Packet::deserialize(bfr.getBuffer(), bfr.getSize());
      test.boolean("SmsTx #1", msg == *msg_d);
      delete msg_d;
    }
    catch (IMC::InvalidMessageSize& e)
    {
      (void)e;
      test.boolean("msg #1", msg.getSerializationSize() > DUNE_IMC_CONST_MAX_SIZE);
    }
  }

  {
    IMC::SmsTx msg;
    msg.setTimeStamp(0.7468711533621621);
    msg.setSource(20626U);
    msg.setSourceEntity(13U);
    msg.setDestination(63363U);
    msg.setDestinationEntity(173U);
    msg.seq = 455445979U;
    msg.destination.assign("KLHCDLQHUQWSSFMTCRVLQMPBXHLYHYGOZMGKBTNHVUWZWFMXBPWTGTIAKSXALVCEIRLJPPFJEMBTZCFHGNQZEXJFMRKQLGGGMBNQIIEVDRLOW");
    msg.timeout = 48526U;
    const signed char tmp_msg_0[] = {102, -107, 112, -16, 51, -100, 115, -58, 15, 8, 97, 23, -50, -126, -100, -38, 77, 38, 8, -56, 121, 4, -63, -15, 63, -66, 90, -41, -29, -100, 73, 8, -81, 100, -104, -126, -89, -75, -39, 56, -27, -86, 71, 13};
    msg.data.assign(tmp_msg_0, tmp_msg_0 + sizeof(tmp_msg_0));

    try
    {
      Utils::ByteBuffer bfr;
      IMC::Packet::serialize(&msg, bfr);
      IMC::Message* msg_d = IMC::Packet::deserialize(bfr.getBuffer(), bfr.getSize());
      test.boolean("SmsTx #2", msg == *msg_d);
      delete msg_d;
    }
    catch (IMC::InvalidMessageSize& e)
    {
      (void)e;
      test.boolean("msg #2", msg.getSerializationSize() > DUNE_IMC_CONST_MAX_SIZE);
    }
  }

  {
    IMC::SmsRx msg;
    msg.setTimeStamp(0.3383807919774485);
    msg.setSource(2764U);
    msg.setSourceEntity(76U);
    msg.setDestination(49778U);
    msg.setDestinationEntity(236U);
    msg.source.assign("BEZPAPGWBMLMUFQOFLUTMGBSTQ");
    const signed char tmp_msg_0[] = {-85, 18, 116, -35, 19, 29, 77, -120, -121, -114, 44, -42, -51, -44, 123, -6, -89, -53, 10, -39, -21, -52, 51, 4, -42, -48, 63, -63, 50, -38, -100, -105, -123, 59, -10, -80, 110, 13, -96, -100, -21, -56, 82, 49, 21, 76, -59, -106, 28, -20, 88, 59, 42, -109, 92, 62, 121, -78, 14, -64, -53, 112, 3, -108, -42, 87, -118, -82, -45, 124, -52, -81, -40, -1, -25, 89, -82, -90, -93, 23, 91, -87, -92, 43, 47, -62, 116, 3, -90, 113, 121, -10, 56, -109, 46, -15, -80, 115, -108, -40, 81, -56, -58, -2, 0, 22, -120, 18, 92, 12, -40, -74, -102, 46, -21, -96, 78, 81, 7, -79, -21, 103, -79, -122, 51, -36, -84, -61, 61, -126, -119, 53, 111, 125, -63, -11, -52, -84, 34, 54, -9, -121, -9, -125, 4, 31, 45, -17, 98, -97, 9, -68, 13, -24, -76, 80, -6, -103, 120, -7, 58, -4, -25, 22, -85, -98, -39, 78, -99, -24, -49, 7, 58, 77, -7, 34, -70, 84, -68, -110, 55, -102, 12, -62, 73, -8};
    msg.data.assign(tmp_msg_0, tmp_msg_0 + sizeof(tmp_msg_0));

    try
    {
      Utils::ByteBuffer bfr;
      IMC::Packet::serialize(&msg, bfr);
      IMC::Message* msg_d = IMC::Packet::deserialize(bfr.getBuffer(), bfr.getSize());
      test.boolean("SmsRx #0", msg == *msg_d);
      delete msg_d;
    }
    catch (IMC::InvalidMessageSize& e)
    {
      (void)e;
      test.boolean("msg #0", msg.getSerializationSize() > DUNE_IMC_CONST_MAX_SIZE);
    }
  }

  {
    IMC::SmsRx msg;
    msg.setTimeStamp(0.6181897164661481);
    msg.setSource(61771U);
    msg.setSourceEntity(90U);
    msg.setDestination(56641U);
    msg.setDestinationEntity(132U);
    msg.source.assign("ORPYITTQPLGGVAUDRRXNFLRREKTWJTJOVDUYZYGZEFJTROOVKKHQKPTJZVITMCMFXJYDEXQHFVHNAXTRMPSGFWLLFHLNNVOCZZIBQBGGEATVEMPGOWOCCISIPWWKNUOFCNDMYYADNGCZBZHWSXXHFHBCUDJFDLKUCXJAXQYUFZHSACWPBSWBZMUABIMQSYQEN");
    const signed char tmp_msg_0[] = {-29, -60, -42, -100, -8, 42, -3, -72, -93, -17, 5, -113, 32, 86, -96, -3, 43, 6, 6, 71, -33, -68, 121, -122, 105, 46, -80, 82, -81, -104, -119, 52, 70, 86, 47, -4, 101, 103};
    msg.data.assign(tmp_msg_0, tmp_msg_0 + sizeof(tmp_msg_0));

    try
    {
      Utils::ByteBuffer bfr;
      IMC::Packet::serialize(&msg, bfr);
      IMC::Message* msg_d = IMC::Packet::deserialize(bfr.getBuffer(), bfr.getSize());
      test.boolean("SmsRx #1", msg == *msg_d);
      delete msg_d;
    }
    catch (IMC::InvalidMessageSize& e)
    {
      (void)e;
      test.boolean("msg #1", msg.getSerializationSize() > DUNE_IMC_CONST_MAX_SIZE);
    }
  }

  {
    IMC::SmsRx msg;
    msg.setTimeStamp(0.026900144176519314);
    msg.setSource(38415U);
    msg.setSourceEntity(149U);
    msg.setDestination(6185U);
    msg.setDestinationEntity(195U);
    msg.source.assign("PBROAUPRUJEYOYFEXTVVPPOHEEQLPIOGFWNTSZBFJYASYUZMMGKNOLCNQSUMBLKSNHAGNGSQMWZCWNMWYODVHCKBDKDOXFRQPVGJQIKJNRGFRCBGDTEGTPTPMYZUSYILSAXCSTNAIILMFNRTMDUXHOIUYVVJIHGWWAEFDDRZPJBXCBTEFKXIHCMGOPWKYRXIAFERLDQOLRLUNTMCCHTHIKVUDWXLJ");
    const signed char tmp_msg_0[] = {76, -69, 34, -17, 62, 112, 53, 26, 47, -91, 35, 122, -16, 17, -18, -20, 95, -61, -10, 17, 107, 82, -14, 60, 103, -71, 119, -85, 68, 89, -29, 106, 2, 40, 74, -106, 116, -7, -115, 26, 5, -64, -90, 9, 47, -56, -47, 20, -64, -75, 62, -54, 100, 10, -53, -122, 54, -85, 106, -16, 94, 12, 69, 81, 67, 45, 81, -124, 109, 116, -119, 94, 61, -13, -38, -39, -100, 94, 46, 113, 92, -88, 122, 69, -61, 59, -97, -67, -124, -81, 44, 79, -73, -59, 105, -61, 51, -74, 92, 104, -63, -115, 49, -9, -127, -84, -17, 29, -87, -13, 43, -9, 118, 114, -117, -61, 115, -59, 50, 102, 31, -81, -34, -15, 35, 33, 104, -117, 115, 114, 108, 120, 63, -117, -39, -116, -3, 46, -54, 107, 20, -118, -122, 8, 52, -114, 94, 51, -120, 102, -105, 84, 42, 88, 18, 6, 57, 13, -105, 102, 59, 17, -51, -119, 67, -90, -80, -60, -89, -37, 110, 92, -50, -24, -63, -81, 65, 60, 8, 60, -95, 10, -41, 14, 15, 27};
    msg.data.assign(tmp_msg_0, tmp_msg_0 + sizeof(tmp_msg_0));

    try
    {
      Utils::ByteBuffer bfr;
      IMC::Packet::serialize(&msg, bfr);
      IMC::Message* msg_d = IMC::Packet::deserialize(bfr.getBuffer(), bfr.getSize());
      test.boolean("SmsRx #2", msg == *msg_d);
      delete msg_d;
    }
    catch (IMC::InvalidMessageSize& e)
    {
      (void)e;
      test.boolean("msg #2", msg.getSerializationSize() > DUNE_IMC_CONST_MAX_SIZE);
    }
  }

  {
    IMC::SmsState msg;
    msg.setTimeStamp(0.03883845500252092);
    msg.setSource(17218U);
    msg.setSourceEntity(106U);
    msg.setDestination(8358U);
    msg.setDestinationEntity(144U);
    msg.seq = 1387998515U;
    msg.state = 23U;
    msg.error.assign("LFVUWFCVCRLIGYHZEJKXMRJQIQOKJRTNVUXHZBNVEBQGCXVKTHPFGKPAHNWLLFZBXPWGNKZCNTNNPGRIGFXFBSDGMAMUEMYAUUZQPMGAHJYIQTDEOWEBIYWDMCSORWXRWXJGYXQSCVUDZDYJPAETPYMOW");

    try
    {
      Utils::ByteBuffer bfr;
      IMC::Packet::serialize(&msg, bfr);
      IMC::Message* msg_d = IMC::Packet::deserialize(bfr.getBuffer(), bfr.getSize());
      test.boolean("SmsState #0", msg == *msg_d);
      delete msg_d;
    }
    catch (IMC::InvalidMessageSize& e)
    {
      (void)e;
      test.boolean("msg #0", msg.getSerializationSize() > DUNE_IMC_CONST_MAX_SIZE);
    }
  }

  {
    IMC::SmsState msg;
    msg.setTimeStamp(0.6969294911266063);
    msg.setSource(34716U);
    msg.setSourceEntity(251U);
    msg.setDestination(7948U);
    msg.setDestinationEntity(86U);
    msg.seq = 3132506025U;
    msg.state = 245U;
    msg.error.assign("OISNYWUEEAWACZHPNYXFJB");

    try
    {
      Utils::ByteBuffer bfr;
      IMC::Packet::serialize(&msg, bfr);
      IMC::Message* msg_d = IMC::Packet::deserialize(bfr.getBuffer(), bfr.getSize());
      test.boolean("SmsState #1", msg == *msg_d);
      delete msg_d;
    }
    catch (IMC::InvalidMessageSize& e)
    {
      (void)e;
      test.boolean("msg #1", msg.getSerializationSize() > DUNE_IMC_CONST_MAX_SIZE);
    }
  }

  {
    IMC::SmsState msg;
    msg.setTimeStamp(0.13773705674717507);
    msg.setSource(25413U);
    msg.setSourceEntity(19U);
    msg.setDestination(22144U);
    msg.setDestinationEntity(182U);
    msg.seq = 201450073U;
    msg.state = 54U;
    msg.error.assign("TQOISLNXETDZUKUHMQRCOREGEDLPDDHCAIRHUPVJKSWTHYCAPJVSJMXDWCXJYFCMOT");

    try
    {
      Utils::ByteBuffer bfr;
      IMC::Packet::serialize(&msg, bfr);
      IMC::Message* msg_d = IMC::Packet::deserialize(bfr.getBuffer(), bfr.getSize());
      test.boolean("SmsState #2", msg == *msg_d);
      delete msg_d;
    }
    catch (IMC::InvalidMessageSize& e)
    {
      (void)e;
      test.boolean("msg #2", msg.getSerializationSize() > DUNE_IMC_CONST_MAX_SIZE);
    }
  }

  {
    IMC::TextMessage msg;
    msg.setTimeStamp(0.18571365220631608);
    msg.setSource(12421U);
    msg.setSourceEntity(180U);
    msg.setDestination(56810U);
    msg.setDestinationEntity(192U);
    msg.origin.assign("UTACOIZECYDSJNXFVQIZIMEJFSLAYMWPNTWXMTNZOEOPHLRFJDYRUWAWRWRMFLTHEPCLRCBYPEGUSAOPJMPHGXSHFMYDLIBXRXIVBYATIAPOXCXORZYSQWFTLTRGCKKKDUBGQXCNUKHHQSIHAJYFFAANDJQOKKBLULUNIYZCWNBUWQBDZFNZZTE");
    msg.text.assign("YYXIJFJGOBEEGCSALCIQDHGXPPDWDSKHIPPCOHFLPBMEKBTIAMNHKAPIOTWKHDLFUAGITRRSTQXLFSVNNIWCSVLYICSJPOSEEDQYNAXJTZXXCWBYONMVGMONOYJRBVRRZOKBCHMQGERCFFLKBQDLZBQMDVAXWBHVEJYXYUWMGLIWSFPTSXQEHLFPZAHTCAUEOZZNFDVRKKUUMGUZDIPVNNAWUDRYRAMSTJKZTOQCLMYUZ");

    try
    {
      Utils::ByteBuffer bfr;
      IMC::Packet::serialize(&msg, bfr);
      IMC::Message* msg_d = IMC::Packet::deserialize(bfr.getBuffer(), bfr.getSize());
      test.boolean("TextMessage #0", msg == *msg_d);
      delete msg_d;
    }
    catch (IMC::InvalidMessageSize& e)
    {
      (void)e;
      test.boolean("msg #0", msg.getSerializationSize() > DUNE_IMC_CONST_MAX_SIZE);
    }
  }

  {
    IMC::TextMessage msg;
    msg.setTimeStamp(0.8457272221790617);
    msg.setSource(20238U);
    msg.setSourceEntity(219U);
    msg.setDestination(47100U);
    msg.setDestinationEntity(254U);
    msg.origin.assign("ENZMESRMHIOXPDSCIOSTQSWMZETEAHLAHDLCGPHLJOBVIDYSGSAULZBNJOSOVIGDGUGRIQANEVTJTUVGHDSQRIMTJFDNMFXFQNYQZRKZ");
    msg.text.assign("ZKJFEFWMRHNDIDRWRFTTAERYJNWMZUERKKAUYSGFZAKXCNNCHDUSWTZVPIGIVZWOJQGMSLQIBETSKMNPJVNFQUGDADVVBPMTGMKGMSJYHBLPIRQQIYUGZXHDACTPVSQQGVJWNCNLZSJLROYJUKFAZUKDCABWHRQZRETMYXMXCTMOBQVHOZSGKPINOKLBYVBHODHEAQCTBFBAYFLSPOCNUXHFXGCXWRHCDLATJYI");

    try
    {
      Utils::ByteBuffer bfr;
      IMC::Packet::serialize(&msg, bfr);
      IMC::Message* msg_d = IMC::Packet::deserialize(bfr.getBuffer(), bfr.getSize());
      test.boolean("TextMessage #1", msg == *msg_d);
      delete msg_d;
    }
    catch (IMC::InvalidMessageSize& e)
    {
      (void)e;
      test.boolean("msg #1", msg.getSerializationSize() > DUNE_IMC_CONST_MAX_SIZE);
    }
  }

  {
    IMC::TextMessage msg;
    msg.setTimeStamp(0.9267462470116701);
    msg.setSource(39164U);
    msg.setSourceEntity(104U);
    msg.setDestination(28550U);
    msg.setDestinationEntity(141U);
    msg.origin.assign("NEAPUHAHICJCCLOGVGMXVAIXGJRGT");
    msg.text.assign("FAVZATCWRTNQINHDBDJZOYXMKJXUSZAPUGUFJISGRINFOVYJPTOSKLRCDWAQBGAEXISZUKUBPQCVHMNWLWGDAUOZPVCQNUVPOVHLKFXPBEAAWCDXLBIRBQMOMUFVGHKLTFJIVBNYETFQWPNBTEFOHQSNJJTH");

    try
    {
      Utils::ByteBuffer bfr;
      IMC::Packet::serialize(&msg, bfr);
      IMC::Message* msg_d = IMC::Packet::deserialize(bfr.getBuffer(), bfr.getSize());
      test.boolean("TextMessage #2", msg == *msg_d);
      delete msg_d;
    }
    catch (IMC::InvalidMessageSize& e)
    {
      (void)e;
      test.boolean("msg #2", msg.getSerializationSize() > DUNE_IMC_CONST_MAX_SIZE);
    }
  }

  {
    IMC::IridiumMsgRx msg;
    msg.setTimeStamp(0.2202209000681271);
    msg.setSource(11478U);
    msg.setSourceEntity(176U);
    msg.setDestination(15017U);
    msg.setDestinationEntity(2U);
    msg.origin.assign("MFMQZOYLFGPIPYNBAJLNBRFHPLXGHGDBRURMUZIWJCMCECSTUAGNRLWZDSGWCBMVVXO");
    msg.htime = 0.25070287361684307;
    msg.lat = 0.9579080438155396;
    msg.lon = 0.08427961797069605;
    const signed char tmp_msg_0[] = {-74, 102, -64, 114, -68, -46, 94, -89, 96, -118, 17, -59, 108, -6, 78, -22, 61, -98, -34, -29, -50, 118, -34, -2, 72, 11, -15, -107, -117, -17, 85, -98, -126, -101, -87, -5, 6, 45, -3, 90, 66, -87, -52, 112, -85, -69, 123, -26, -49, -48, -62, -78, 39, 40, -90, 111, -27, -26, 58, -80, 76, 92, 50, 26, -85, -1, 38, -61, 73};
    msg.data.assign(tmp_msg_0, tmp_msg_0 + sizeof(tmp_msg_0));

    try
    {
      Utils::ByteBuffer bfr;
      IMC::Packet::serialize(&msg, bfr);
      IMC::Message* msg_d = IMC::Packet::deserialize(bfr.getBuffer(), bfr.getSize());
      test.boolean("IridiumMsgRx #0", msg == *msg_d);
      delete msg_d;
    }
    catch (IMC::InvalidMessageSize& e)
    {
      (void)e;
      test.boolean("msg #0", msg.getSerializationSize() > DUNE_IMC_CONST_MAX_SIZE);
    }
  }

  {
    IMC::IridiumMsgRx msg;
    msg.setTimeStamp(0.4994877052820377);
    msg.setSource(4587U);
    msg.setSourceEntity(115U);
    msg.setDestination(61290U);
    msg.setDestinationEntity(189U);
    msg.origin.assign("PLMWUTGLVIZBIGUREQIJFSSFKFZZMXGBJMGTSPUEVHPRAHTMJJHVLEYYWQWJWLKSBPAKXCJQDOBDAXQDEYDYMBHDHBECIRNTMWKRHQFLAGXQOZFXYXNIAFPTYZEHKICLTYOXZNCRQUNHGIERXIFJOUXZIKGZCMRNPOLTSTMBCGHVMOEOUVVYKULCCQWDWSRGS");
    msg.htime = 0.6638419934486789;
    msg.lat = 0.44655918463565314;
    msg.lon = 0.05624209706215855;
    const signed char tmp_msg_0[] = {103, -17, -116, -84, 38, 16, -126, -57, 41, -103, 3, -43, 49, -99, 8, 105, -116, 18, -23, 21, -75, 20, 106, -49, -64, -79, -84, -88, 83, 89, 66, 113, -23, 13, 102, -98, -34, 32, 110, 124, -128, -62, 110, -85, -6, -36, -19, 113, -87, 5, -60, -3, -51, 81, 25, 6, -82, -19, 7, -18, -25, -125, -63, 2, -86, -9, 7, -29, 9, 1, -7, 80, -105, -19, 92, -104, -24, 15, 124, 35, 61, 25, 80, -7, 79, 122, 126, 121, 8, -9, -59, 4, 106, 102, 125, 54, -6, -124, -50, -126, -86, 94, 86, 105, -110, -70, 40, -41, 35, 24, 38, -107, 9, -25, 9, 40, -34, 33, -26, -44};
    msg.data.assign(tmp_msg_0, tmp_msg_0 + sizeof(tmp_msg_0));

    try
    {
      Utils::ByteBuffer bfr;
      IMC::Packet::serialize(&msg, bfr);
      IMC::Message* msg_d = IMC::Packet::deserialize(bfr.getBuffer(), bfr.getSize());
      test.boolean("IridiumMsgRx #1", msg == *msg_d);
      delete msg_d;
    }
    catch (IMC::InvalidMessageSize& e)
    {
      (void)e;
      test.boolean("msg #1", msg.getSerializationSize() > DUNE_IMC_CONST_MAX_SIZE);
    }
  }

  {
    IMC::IridiumMsgRx msg;
    msg.setTimeStamp(0.4545501766113119);
    msg.setSource(19243U);
    msg.setSourceEntity(10U);
    msg.setDestination(51882U);
    msg.setDestinationEntity(7U);
    msg.origin.assign("CFTNJSURAWNEIQKJMMYFEIMFDGUVDZMJQBBAPPJHHSZNTTLUWGTLIFMRWOPSLCNASNVXBFFSVQLQNZPKKTXDPTOLFUBXDPZFAHROJZGII");
    msg.htime = 0.7175449041493084;
    msg.lat = 0.3023641355128748;
    msg.lon = 0.6240304808690255;
    const signed char tmp_msg_0[] = {-58, -48, 12, 25, 42, 5, -127, 79, -18, 81, -75, -110, 100, 37, -34, -78, 85, 30, 50, 72, 117, 109, -7, 49, 11, 22, 28, -83, -81, 1, 22, -86, 63, -81, 121, -10, -4, -8, 71, 112, -3, 63, -11, 32, 109, -60, 81, -64, -10, 77, 62, -113, 27, -83, 119, -43, 121, 99, -75, -128, -76, -103, 64, 51, -68, 1, -109, 0, -83, -68, 43, 120, -27, 31, -128, 42, -29, -26, 29, 119, 11, 17, 77, -14, 1, 20, -80, 36, -93, 79, -13, 1, 39, 63, -84, 56, -29, -40, 86, 69, 50, 18, -37, 112, -79, -23, 15, -77, 86, 81, -68, -73, 104, -97, -25, 9, 27, 101, 22, 53, -41, -46, -84, -88, -66, 56, 10, -78, -101, -54, -6, 31, -118, 36, 83, 58, 99, 53, -61, -121};
    msg.data.assign(tmp_msg_0, tmp_msg_0 + sizeof(tmp_msg_0));

    try
    {
      Utils::ByteBuffer bfr;
      IMC::Packet::serialize(&msg, bfr);
      IMC::Message* msg_d = IMC::Packet::deserialize(bfr.getBuffer(), bfr.getSize());
      test.boolean("IridiumMsgRx #2", msg == *msg_d);
      delete msg_d;
    }
    catch (IMC::InvalidMessageSize& e)
    {
      (void)e;
      test.boolean("msg #2", msg.getSerializationSize() > DUNE_IMC_CONST_MAX_SIZE);
    }
  }

  {
    IMC::IridiumMsgTx msg;
    msg.setTimeStamp(0.011309780629604416);
    msg.setSource(55509U);
    msg.setSourceEntity(15U);
    msg.setDestination(21586U);
    msg.setDestinationEntity(66U);
    msg.req_id = 19841U;
    msg.ttl = 51509U;
    msg.destination.assign("KQKPINKDTJOLWND");
    const signed char tmp_msg_0[] = {-93, 61, -91, -100, 63, -73, 10, -102, 99, 78, -25, 99, -120, -16, 27, 8, -58, 13, 45, -33, -73, 16, -7, -54, -6, -105, 123, 85, -43, -49, 46, -42, -28, 106, 8, 5, -20, 28, 114, -77, 122, -43, -127, -11, -87, 74, -33, 50, -48, 93, -97, -83, -16, -50, -2, -73, -44, -44, 81, -45, 41, -120, -115, 123, -114, -57, 102, 4, -6, -36, 123, 88, 65, 101, -98, -116, 43, 101, 91, -17, -125, 66, 16, 39, 48, -10, 9, 40, -124, 91, -67, 38, -27, 7, 8, -38, -124, -123, 68, 63, 112, 13, 102, 6, -23, -8, -7, -36, -85, -72, 1, 5, -90, -104, 121, 37, -3, 113, 58, 39, 25, 34, 54, -43, -103, -128, -106, -116, 72, 76, -54, -39, -65, 79, -125, 9, -17, 91, 51, -115, -14, 70, 33, 70, 52, 94, 33, 43, -71, -102, -31, 41, -81, -13, -95, -25, 83, -17, -58, -97, 32, 24, -66, -84, -108, -45, -5, 79, -85, -28, -63, 33, 56, -7, 31};
    msg.data.assign(tmp_msg_0, tmp_msg_0 + sizeof(tmp_msg_0));

    try
    {
      Utils::ByteBuffer bfr;
      IMC::Packet::serialize(&msg, bfr);
      IMC::Message* msg_d = IMC::Packet::deserialize(bfr.getBuffer(), bfr.getSize());
      test.boolean("IridiumMsgTx #0", msg == *msg_d);
      delete msg_d;
    }
    catch (IMC::InvalidMessageSize& e)
    {
      (void)e;
      test.boolean("msg #0", msg.getSerializationSize() > DUNE_IMC_CONST_MAX_SIZE);
    }
  }

  {
    IMC::IridiumMsgTx msg;
    msg.setTimeStamp(0.14931715935727852);
    msg.setSource(49093U);
    msg.setSourceEntity(168U);
    msg.setDestination(63416U);
    msg.setDestinationEntity(143U);
    msg.req_id = 14435U;
    msg.ttl = 41207U;
    msg.destination.assign("RSJGBKJMUFBOLTQNLDJQIMBNUEELLTSMVGXVHFZTDAFIIQSKAWDBQZYXVFAHGKVOOZCTEFZSHCFWMDZBNAHZGJCWSJZEYDDEAYUHRHCUQOMGLVPJPPWUVOYDCXJOLONOPXGNMPNCDWFXWANEXISCBIXIAXTAKGSCRNKOPTHURHRNLVDBUQKYYDNPYQBWRGOIXUPMZUTIZBGSWVPBVVSAEEHGIQLQMQPYCEZJCFRHKSRFXLKRWMTMJEYIK");
    const signed char tmp_msg_0[] = {-2, -118, -13, -18, -57, 34, 99, -41, -103, -32, 11, 110, -93, 57, -75, -126, -62, -72, 74, -87, -127, -108, -52, 77, 8, 97, 69, 48, -17, 17, 104, 68, 71, -4, 61, -78, 113, -37, -77, 23, 87, -51, -25, 39, -90, 121, 25, 85, -75, 37, 36, 2, 97, 87, 52, -30, 99, -68, -58, 70, -106, 39, -112, 40, -85, 123, 35, 39, 11, 47, -35, -21, -77, 102, -97, -126, 13, -27, 33, 88, -124, -71, -54, 55, 24, -47, -69, 86, -8, -23, 43, -42, 113, 123, -40, 43, -115, 91, -117, 20, -63, 122, -115, -11, 66, 33, -25, -46, 53, -82, 29, -62, 79, -99, -123, 118, 36, -25, 47, -81, 93, -37, 53, 4, -62, -41, -20, -52, 94, 123, 46, -91, 102, 4, 46, -118, -95, -66, -39, 30, -56, 15, -62, -1, -98, 11, -126, 80, -120, -112, 83, -107, 79, 74, -9, -124, 48, -114, -35, -81, -57, 111, -126, -27, 57, -91, 44, -32, 6, 15, -79, 100, -81, 93, 113, 1, -101, 80, -125, 109, -49, -112, 19, 7, 52, 82, -109, 82, -57, 71, -41, -111, 32, -58, -64, -93, -91, -27, 30, -58, -116};
    msg.data.assign(tmp_msg_0, tmp_msg_0 + sizeof(tmp_msg_0));

    try
    {
      Utils::ByteBuffer bfr;
      IMC::Packet::serialize(&msg, bfr);
      IMC::Message* msg_d = IMC::Packet::deserialize(bfr.getBuffer(), bfr.getSize());
      test.boolean("IridiumMsgTx #1", msg == *msg_d);
      delete msg_d;
    }
    catch (IMC::InvalidMessageSize& e)
    {
      (void)e;
      test.boolean("msg #1", msg.getSerializationSize() > DUNE_IMC_CONST_MAX_SIZE);
    }
  }

  {
    IMC::IridiumMsgTx msg;
    msg.setTimeStamp(0.9043793803722304);
    msg.setSource(35658U);
    msg.setSourceEntity(251U);
    msg.setDestination(42862U);
    msg.setDestinationEntity(177U);
    msg.req_id = 39311U;
    msg.ttl = 13799U;
    msg.destination.assign("RUTTYBUSETSUMJDSHX");
    const signed char tmp_msg_0[] = {119, -57, 92, 97, 67, 108, -120, -125, -41, 32, 95, -79, -65, 4, 37, 108, 125, 74, 43, -76, 19, -7, 43, -39, 91, -97, 37, 49, 123, 69, 34, 61, 91, -31, -40, -128, 92, -62, -88, 6, 74, -124, -75, -88, 93, 38, 105, -119, -123, 24, -1, -125, 40, 35, -92, 102, -108, -78, -126};
    msg.data.assign(tmp_msg_0, tmp_msg_0 + sizeof(tmp_msg_0));

    try
    {
      Utils::ByteBuffer bfr;
      IMC::Packet::serialize(&msg, bfr);
      IMC::Message* msg_d = IMC::Packet::deserialize(bfr.getBuffer(), bfr.getSize());
      test.boolean("IridiumMsgTx #2", msg == *msg_d);
      delete msg_d;
    }
    catch (IMC::InvalidMessageSize& e)
    {
      (void)e;
      test.boolean("msg #2", msg.getSerializationSize() > DUNE_IMC_CONST_MAX_SIZE);
    }
  }

  {
    IMC::IridiumTxStatus msg;
    msg.setTimeStamp(0.19083086261731752);
    msg.setSource(25218U);
    msg.setSourceEntity(213U);
    msg.setDestination(45237U);
    msg.setDestinationEntity(101U);
    msg.req_id = 16977U;
    msg.status = 21U;
    msg.text.assign("XNOLLMQJXLDHUMBHQLHUUPISDKFANAPRKGSERLBXETNJATOGJCFWMTOIFFQHMSYCZWXCSYTIOBWJCD");

    try
    {
      Utils::ByteBuffer bfr;
      IMC::Packet::serialize(&msg, bfr);
      IMC::Message* msg_d = IMC::Packet::deserialize(bfr.getBuffer(), bfr.getSize());
      test.boolean("IridiumTxStatus #0", msg == *msg_d);
      delete msg_d;
    }
    catch (IMC::InvalidMessageSize& e)
    {
      (void)e;
      test.boolean("msg #0", msg.getSerializationSize() > DUNE_IMC_CONST_MAX_SIZE);
    }
  }

  {
    IMC::IridiumTxStatus msg;
    msg.setTimeStamp(0.3006297657869681);
    msg.setSource(39460U);
    msg.setSourceEntity(116U);
    msg.setDestination(19082U);
    msg.setDestinationEntity(124U);
    msg.req_id = 20599U;
    msg.status = 215U;
    msg.text.assign("MVSMRYTTDGXYCPWHTNMEQEIVQZYJWJQRCRELBQMEOMJSDJFGJMHBMTDBALWAWKOPOPLXYVRVDPESFILHGKCZJGCNAUZMLHYTBUGNMOYGFXSSFPTUHUOWAYNSUDNTDTUNCHOWAZRKXORCVHSCVGYUVQOLOZJPXEKYXKXIEXJOPZVUUNWZAGKRCPLQPBQSARXBXTAQQMLUGIRICVDHEKCIIBKILRDZDEKNJAWFWIBV");

    try
    {
      Utils::ByteBuffer bfr;
      IMC::Packet::serialize(&msg, bfr);
      IMC::Message* msg_d = IMC::Packet::deserialize(bfr.getBuffer(), bfr.getSize());
      test.boolean("IridiumTxStatus #1", msg == *msg_d);
      delete msg_d;
    }
    catch (IMC::InvalidMessageSize& e)
    {
      (void)e;
      test.boolean("msg #1", msg.getSerializationSize() > DUNE_IMC_CONST_MAX_SIZE);
    }
  }

  {
    IMC::IridiumTxStatus msg;
    msg.setTimeStamp(0.010436926710562955);
    msg.setSource(31395U);
    msg.setSourceEntity(252U);
    msg.setDestination(36849U);
    msg.setDestinationEntity(100U);
    msg.req_id = 19432U;
    msg.status = 200U;
    msg.text.assign("VIUEAHVLNDIJDXOHXKJPLLOWOWERWIIFJGGJOOSTRAYPMTOPHFGQGUACSSFOREUPXGMVXZUZJKNHWAMCWRKQWUJDWZSBFEFNIXAVUTWJBYDQMRFWHYEQCCJDG");

    try
    {
      Utils::ByteBuffer bfr;
      IMC::Packet::serialize(&msg, bfr);
      IMC::Message* msg_d = IMC::Packet::deserialize(bfr.getBuffer(), bfr.getSize());
      test.boolean("IridiumTxStatus #2", msg == *msg_d);
      delete msg_d;
    }
    catch (IMC::InvalidMessageSize& e)
    {
      (void)e;
      test.boolean("msg #2", msg.getSerializationSize() > DUNE_IMC_CONST_MAX_SIZE);
    }
  }

  {
    IMC::GroupMembershipState msg;
    msg.setTimeStamp(0.8292159861970072);
    msg.setSource(28239U);
    msg.setSourceEntity(99U);
    msg.setDestination(34712U);
    msg.setDestinationEntity(66U);
    msg.group_name.assign("XQYLZBUGYJUFRDMUSHXKPNNFKEQABLVAIETWBALI");
    msg.links = 3841256887U;

    try
    {
      Utils::ByteBuffer bfr;
      IMC::Packet::serialize(&msg, bfr);
      IMC::Message* msg_d = IMC::Packet::deserialize(bfr.getBuffer(), bfr.getSize());
      test.boolean("GroupMembershipState #0", msg == *msg_d);
      delete msg_d;
    }
    catch (IMC::InvalidMessageSize& e)
    {
      (void)e;
      test.boolean("msg #0", msg.getSerializationSize() > DUNE_IMC_CONST_MAX_SIZE);
    }
  }

  {
    IMC::GroupMembershipState msg;
    msg.setTimeStamp(0.0827807649093566);
    msg.setSource(47813U);
    msg.setSourceEntity(214U);
    msg.setDestination(55237U);
    msg.setDestinationEntity(2U);
    msg.group_name.assign("QSXQCUGTTIHWLBMPMNSGUAONWDVZFFDTMJIUOWVMDVNQAGWEXBTUGCQPEESRPIBZMOZGTKPYRFAJWGUVEGDCEHZNUTNKCXTOLNEWCKVHYUNJYIJATUACWLHKQEKPYFJYJDLFNXKCGOLASPRDXYFVFRHGOONFAQPVCSJXPYQ");
    msg.links = 2387659839U;

    try
    {
      Utils::ByteBuffer bfr;
      IMC::Packet::serialize(&msg, bfr);
      IMC::Message* msg_d = IMC::Packet::deserialize(bfr.getBuffer(), bfr.getSize());
      test.boolean("GroupMembershipState #1", msg == *msg_d);
      delete msg_d;
    }
    catch (IMC::InvalidMessageSize& e)
    {
      (void)e;
      test.boolean("msg #1", msg.getSerializationSize() > DUNE_IMC_CONST_MAX_SIZE);
    }
  }

  {
    IMC::GroupMembershipState msg;
    msg.setTimeStamp(0.724107651583343);
    msg.setSource(46003U);
    msg.setSourceEntity(3U);
    msg.setDestination(59311U);
    msg.setDestinationEntity(54U);
    msg.group_name.assign("BIKVJNYQFLCXDAIBDECIOABTPPSSMZFBTOPPHVPMQPJMKVSDHKQNIBEZZKZUFADPIESRYITLYMOAWRTYHOCIRLIAWGMXOFHVSYCNZKDEDUYKORMFTKRWIGZYBEAWHTLXCVXWLQVJPODITHLUBCSJGQCDD");
    msg.links = 2448211238U;

    try
    {
      Utils::ByteBuffer bfr;
      IMC::Packet::serialize(&msg, bfr);
      IMC::Message* msg_d = IMC::Packet::deserialize(bfr.getBuffer(), bfr.getSize());
      test.boolean("GroupMembershipState #2", msg == *msg_d);
      delete msg_d;
    }
    catch (IMC::InvalidMessageSize& e)
    {
      (void)e;
      test.boolean("msg #2", msg.getSerializationSize() > DUNE_IMC_CONST_MAX_SIZE);
    }
  }

  {
    IMC::SystemGroup msg;
    msg.setTimeStamp(0.5283748020925756);
    msg.setSource(49338U);
    msg.setSourceEntity(51U);
    msg.setDestination(31603U);
    msg.setDestinationEntity(215U);
    msg.groupname.assign("MVNIGNNONZMYUPBZLPMERUHSWEAQRKKYXXGAAPLSPOTTUJJWRLAFIKZPFZGHHVPRMJWFWBDYOSNHBXAOHPCQFIHUVTNYZZIDDBLKUCUYBJUONLWSWGIWMOEKPKIEFIZ");
    msg.action = 11U;
    msg.grouplist.assign("NOTXUSWFYGFMJSJKMMRIJNUIKHETZWEMBHFQXCTEBPQPHDKQVHMEHXZWH");

    try
    {
      Utils::ByteBuffer bfr;
      IMC::Packet::serialize(&msg, bfr);
      IMC::Message* msg_d = IMC::Packet::deserialize(bfr.getBuffer(), bfr.getSize());
      test.boolean("SystemGroup #0", msg == *msg_d);
      delete msg_d;
    }
    catch (IMC::InvalidMessageSize& e)
    {
      (void)e;
      test.boolean("msg #0", msg.getSerializationSize() > DUNE_IMC_CONST_MAX_SIZE);
    }
  }

  {
    IMC::SystemGroup msg;
    msg.setTimeStamp(0.7025776416319115);
    msg.setSource(39828U);
    msg.setSourceEntity(59U);
    msg.setDestination(16564U);
    msg.setDestinationEntity(179U);
    msg.groupname.assign("UDGBPGOFHMVJSARGDFFWTSPVWLQFTZSHQIQOYRWUBDLLWIMCSHZWKZJFUPAVQJTBHEEJAKCAKBFDG");
    msg.action = 130U;
    msg.grouplist.assign("UZKZESHQSGYVIBALVIKZLHTUAVPEGFXJJDBEDOMDNAHOWNQTTSEQWRYGVRBFBHMUXXTVDWTYCZODJHGLSKBJQYMTFYESCFXIUGXGXERMQWPCJFTOVQXHPPHHZNEZOAPWERUINVWMYLARGAJIYQZRJSUXNMFCNKIAYLWGJSSCCDMQNPDFUOCFZUFPYYKDJVAPMUTRI");

    try
    {
      Utils::ByteBuffer bfr;
      IMC::Packet::serialize(&msg, bfr);
      IMC::Message* msg_d = IMC::Packet::deserialize(bfr.getBuffer(), bfr.getSize());
      test.boolean("SystemGroup #1", msg == *msg_d);
      delete msg_d;
    }
    catch (IMC::InvalidMessageSize& e)
    {
      (void)e;
      test.boolean("msg #1", msg.getSerializationSize() > DUNE_IMC_CONST_MAX_SIZE);
    }
  }

  {
    IMC::SystemGroup msg;
    msg.setTimeStamp(0.1366720300583164);
    msg.setSource(48989U);
    msg.setSourceEntity(202U);
    msg.setDestination(21814U);
    msg.setDestinationEntity(111U);
    msg.groupname.assign("YEBXDTUZYKQCWWMTMWUNDVIVDBERVRESMURSXLPCRPRTOKIKEVHRFPLFWHZMOTR");
    msg.action = 249U;
    msg.grouplist.assign("DEQOUBIVKHKNRAHIVKKQWOGISCCLNXICAXYPBLSQYGMGRDQNDEYEQIOSPQRSOEBOKAZRRCJRYBAGKTYWEZLZPXEHDFMAYWBHAWUVQIHJDQMDMHQF");

    try
    {
      Utils::ByteBuffer bfr;
      IMC::Packet::serialize(&msg, bfr);
      IMC::Message* msg_d = IMC::Packet::deserialize(bfr.getBuffer(), bfr.getSize());
      test.boolean("SystemGroup #2", msg == *msg_d);
      delete msg_d;
    }
    catch (IMC::InvalidMessageSize& e)
    {
      (void)e;
      test.boolean("msg #2", msg.getSerializationSize() > DUNE_IMC_CONST_MAX_SIZE);
    }
  }

  {
    IMC::LinkLatency msg;
    msg.setTimeStamp(0.006674718447784889);
    msg.setSource(33588U);
    msg.setSourceEntity(43U);
    msg.setDestination(2672U);
    msg.setDestinationEntity(22U);
    msg.value = 0.24619276047222882;
    msg.sys_src = 64142U;

    try
    {
      Utils::ByteBuffer bfr;
      IMC::Packet::serialize(&msg, bfr);
      IMC::Message* msg_d = IMC::Packet::deserialize(bfr.getBuffer(), bfr.getSize());
      test.boolean("LinkLatency #0", msg == *msg_d);
      delete msg_d;
    }
    catch (IMC::InvalidMessageSize& e)
    {
      (void)e;
      test.boolean("msg #0", msg.getSerializationSize() > DUNE_IMC_CONST_MAX_SIZE);
    }
  }

  {
    IMC::LinkLatency msg;
    msg.setTimeStamp(0.03421793646970028);
    msg.setSource(56273U);
    msg.setSourceEntity(199U);
    msg.setDestination(50385U);
    msg.setDestinationEntity(162U);
    msg.value = 0.08859421178561122;
    msg.sys_src = 25019U;

    try
    {
      Utils::ByteBuffer bfr;
      IMC::Packet::serialize(&msg, bfr);
      IMC::Message* msg_d = IMC::Packet::deserialize(bfr.getBuffer(), bfr.getSize());
      test.boolean("LinkLatency #1", msg == *msg_d);
      delete msg_d;
    }
    catch (IMC::InvalidMessageSize& e)
    {
      (void)e;
      test.boolean("msg #1", msg.getSerializationSize() > DUNE_IMC_CONST_MAX_SIZE);
    }
  }

  {
    IMC::LinkLatency msg;
    msg.setTimeStamp(0.3164383706535342);
    msg.setSource(28042U);
    msg.setSourceEntity(203U);
    msg.setDestination(56360U);
    msg.setDestinationEntity(169U);
    msg.value = 0.9509797494510314;
    msg.sys_src = 294U;

    try
    {
      Utils::ByteBuffer bfr;
      IMC::Packet::serialize(&msg, bfr);
      IMC::Message* msg_d = IMC::Packet::deserialize(bfr.getBuffer(), bfr.getSize());
      test.boolean("LinkLatency #2", msg == *msg_d);
      delete msg_d;
    }
    catch (IMC::InvalidMessageSize& e)
    {
      (void)e;
      test.boolean("msg #2", msg.getSerializationSize() > DUNE_IMC_CONST_MAX_SIZE);
    }
  }

  {
    IMC::ExtendedRSSI msg;
    msg.setTimeStamp(0.0030595347680214546);
    msg.setSource(37947U);
    msg.setSourceEntity(84U);
    msg.setDestination(7548U);
    msg.setDestinationEntity(52U);
    msg.value = 0.5331180885969037;
    msg.units = 249U;

    try
    {
      Utils::ByteBuffer bfr;
      IMC::Packet::serialize(&msg, bfr);
      IMC::Message* msg_d = IMC::Packet::deserialize(bfr.getBuffer(), bfr.getSize());
      test.boolean("ExtendedRSSI #0", msg == *msg_d);
      delete msg_d;
    }
    catch (IMC::InvalidMessageSize& e)
    {
      (void)e;
      test.boolean("msg #0", msg.getSerializationSize() > DUNE_IMC_CONST_MAX_SIZE);
    }
  }

  {
    IMC::ExtendedRSSI msg;
    msg.setTimeStamp(0.8216399990587793);
    msg.setSource(47930U);
    msg.setSourceEntity(186U);
    msg.setDestination(54302U);
    msg.setDestinationEntity(52U);
    msg.value = 0.40995292373869474;
    msg.units = 96U;

    try
    {
      Utils::ByteBuffer bfr;
      IMC::Packet::serialize(&msg, bfr);
      IMC::Message* msg_d = IMC::Packet::deserialize(bfr.getBuffer(), bfr.getSize());
      test.boolean("ExtendedRSSI #1", msg == *msg_d);
      delete msg_d;
    }
    catch (IMC::InvalidMessageSize& e)
    {
      (void)e;
      test.boolean("msg #1", msg.getSerializationSize() > DUNE_IMC_CONST_MAX_SIZE);
    }
  }

  {
    IMC::ExtendedRSSI msg;
    msg.setTimeStamp(0.7240206532861948);
    msg.setSource(54514U);
    msg.setSourceEntity(67U);
    msg.setDestination(4477U);
    msg.setDestinationEntity(162U);
    msg.value = 0.3202299585163141;
    msg.units = 96U;

    try
    {
      Utils::ByteBuffer bfr;
      IMC::Packet::serialize(&msg, bfr);
      IMC::Message* msg_d = IMC::Packet::deserialize(bfr.getBuffer(), bfr.getSize());
      test.boolean("ExtendedRSSI #2", msg == *msg_d);
      delete msg_d;
    }
    catch (IMC::InvalidMessageSize& e)
    {
      (void)e;
      test.boolean("msg #2", msg.getSerializationSize() > DUNE_IMC_CONST_MAX_SIZE);
    }
  }

  {
    IMC::HistoricData msg;
    msg.setTimeStamp(0.22779743963349863);
    msg.setSource(44749U);
    msg.setSourceEntity(31U);
    msg.setDestination(27604U);
    msg.setDestinationEntity(76U);
    msg.base_lat = 0.40820552773557184;
    msg.base_lon = 0.2872202442018972;
    msg.base_time = 0.6547569852937495;
    IMC::RemoteCommand tmp_msg_0;
    tmp_msg_0.original_source = 36383U;
    tmp_msg_0.destination = 8842U;
    tmp_msg_0.timeout = 0.46655919680903;
    IMC::SoiPlan tmp_tmp_msg_0_0;
    tmp_tmp_msg_0_0.plan_id = 11862U;
    IMC::SoiWaypoint tmp_tmp_tmp_msg_0_0_0;
    tmp_tmp_tmp_msg_0_0_0.lat = 0.15455940951933456;
    tmp_tmp_tmp_msg_0_0_0.lon = 0.6658507785900071;
    tmp_tmp_tmp_msg_0_0_0.eta = 1136007734U;
    tmp_tmp_tmp_msg_0_0_0.duration = 15122U;
    tmp_tmp_msg_0_0.waypoints.push_back(tmp_tmp_tmp_msg_0_0_0);
    tmp_msg_0.cmd.set(tmp_tmp_msg_0_0);
    msg.data.push_back(tmp_msg_0);

    try
    {
      Utils::ByteBuffer bfr;
      IMC::Packet::serialize(&msg, bfr);
      IMC::Message* msg_d = IMC::Packet::deserialize(bfr.getBuffer(), bfr.getSize());
      test.boolean("HistoricData #0", msg == *msg_d);
      delete msg_d;
    }
    catch (IMC::InvalidMessageSize& e)
    {
      (void)e;
      test.boolean("msg #0", msg.getSerializationSize() > DUNE_IMC_CONST_MAX_SIZE);
    }
  }

  {
    IMC::HistoricData msg;
    msg.setTimeStamp(0.08706867909596361);
    msg.setSource(9014U);
    msg.setSourceEntity(240U);
    msg.setDestination(52740U);
    msg.setDestinationEntity(120U);
    msg.base_lat = 0.16252030588318467;
    msg.base_lon = 0.9357194832565481;
    msg.base_time = 0.8712587755561836;
    IMC::HistoricSample tmp_msg_0;
    tmp_msg_0.sys_id = 25683U;
    tmp_msg_0.priority = 29;
    tmp_msg_0.x = 30879;
    tmp_msg_0.y = 31990;
    tmp_msg_0.z = 16893;
    tmp_msg_0.t = -19600;
    IMC::IdleManeuver tmp_tmp_msg_0_0;
    tmp_tmp_msg_0_0.duration = 30359U;
    tmp_tmp_msg_0_0.custom.assign("DZCGKNSBTWGLWWMLDJDPY");
    tmp_msg_0.sample.set(tmp_tmp_msg_0_0);
    msg.data.push_back(tmp_msg_0);

    try
    {
      Utils::ByteBuffer bfr;
      IMC::Packet::serialize(&msg, bfr);
      IMC::Message* msg_d = IMC::Packet::deserialize(bfr.getBuffer(), bfr.getSize());
      test.boolean("HistoricData #1", msg == *msg_d);
      delete msg_d;
    }
    catch (IMC::InvalidMessageSize& e)
    {
      (void)e;
      test.boolean("msg #1", msg.getSerializationSize() > DUNE_IMC_CONST_MAX_SIZE);
    }
  }

  {
    IMC::HistoricData msg;
    msg.setTimeStamp(0.33096880662748196);
    msg.setSource(23735U);
    msg.setSourceEntity(137U);
    msg.setDestination(20042U);
    msg.setDestinationEntity(30U);
    msg.base_lat = 0.5749031152065914;
    msg.base_lon = 0.964703117112759;
    msg.base_time = 0.8171564780241248;
    IMC::RemoteCommand tmp_msg_0;
    tmp_msg_0.original_source = 46325U;
    tmp_msg_0.destination = 39874U;
    tmp_msg_0.timeout = 0.371797260892586;
    IMC::VehicleCommand tmp_tmp_msg_0_0;
    tmp_tmp_msg_0_0.type = 109U;
    tmp_tmp_msg_0_0.request_id = 51496U;
    tmp_tmp_msg_0_0.command = 219U;
    IMC::PopUp tmp_tmp_tmp_msg_0_0_0;
    tmp_tmp_tmp_msg_0_0_0.timeout = 58785U;
    tmp_tmp_tmp_msg_0_0_0.lat = 0.08118650427251994;
    tmp_tmp_tmp_msg_0_0_0.lon = 0.44296014798559236;
    tmp_tmp_tmp_msg_0_0_0.z = 0.5256571105757362;
    tmp_tmp_tmp_msg_0_0_0.z_units = 88U;
    tmp_tmp_tmp_msg_0_0_0.speed = 0.41315117720748407;
    tmp_tmp_tmp_msg_0_0_0.speed_units = 4U;
    tmp_tmp_tmp_msg_0_0_0.duration = 2007U;
    tmp_tmp_tmp_msg_0_0_0.radius = 0.7176020350276098;
    tmp_tmp_tmp_msg_0_0_0.flags = 51U;
    tmp_tmp_tmp_msg_0_0_0.custom.assign("IPCKQLSSZTYOZHRSDTYCWZBAHNFDJZOUDPLWWNNCPYIWWHFOKLBJL");
    tmp_tmp_msg_0_0.maneuver.set(tmp_tmp_tmp_msg_0_0_0);
    tmp_tmp_msg_0_0.calib_time = 56849U;
    tmp_tmp_msg_0_0.info.assign("BRQYEJNBZQODSTSHFFWVUNMUMUXALTHBPMLMRYXTJQBLOCJCPZCVGBJGEPPDCQZXCB");
    tmp_msg_0.cmd.set(tmp_tmp_msg_0_0);
    msg.data.push_back(tmp_msg_0);

    try
    {
      Utils::ByteBuffer bfr;
      IMC::Packet::serialize(&msg, bfr);
      IMC::Message* msg_d = IMC::Packet::deserialize(bfr.getBuffer(), bfr.getSize());
      test.boolean("HistoricData #2", msg == *msg_d);
      delete msg_d;
    }
    catch (IMC::InvalidMessageSize& e)
    {
      (void)e;
      test.boolean("msg #2", msg.getSerializationSize() > DUNE_IMC_CONST_MAX_SIZE);
    }
  }

  {
    IMC::CompressedHistory msg;
    msg.setTimeStamp(0.31315518297253275);
    msg.setSource(15978U);
    msg.setSourceEntity(161U);
    msg.setDestination(56642U);
    msg.setDestinationEntity(2U);
    msg.base_lat = 0.11972816970718803;
    msg.base_lon = 0.33145194821054647;
    msg.base_time = 0.41968232248077064;
    const signed char tmp_msg_0[] = {80, 124, -13, -28, 42, -13, 6, -9, 14, -61, 106, -43, 46, 122, -119, 29, -71, -71, 76, 85, -2, 16, -25, 88, 58, 2, 53, -67, 50, -123};
    msg.data.assign(tmp_msg_0, tmp_msg_0 + sizeof(tmp_msg_0));

    try
    {
      Utils::ByteBuffer bfr;
      IMC::Packet::serialize(&msg, bfr);
      IMC::Message* msg_d = IMC::Packet::deserialize(bfr.getBuffer(), bfr.getSize());
      test.boolean("CompressedHistory #0", msg == *msg_d);
      delete msg_d;
    }
    catch (IMC::InvalidMessageSize& e)
    {
      (void)e;
      test.boolean("msg #0", msg.getSerializationSize() > DUNE_IMC_CONST_MAX_SIZE);
    }
  }

  {
    IMC::CompressedHistory msg;
    msg.setTimeStamp(0.002906155727358861);
    msg.setSource(41343U);
    msg.setSourceEntity(156U);
    msg.setDestination(3386U);
    msg.setDestinationEntity(93U);
    msg.base_lat = 0.6215589697386823;
    msg.base_lon = 0.3847277436892166;
    msg.base_time = 0.9108493460212631;
    const signed char tmp_msg_0[] = {64, -18, -60, -106, 62, -93, 119, -38, -84, -122, -34, -57, 54, -54, -70, -104, -42, -43, -69, -24, -52, 19, 55, -108, -9, 50, 101, -43, 13, 20, 59, 14, -61, -27, 79, 110, -41, 51, -71, 26, 70, 34, 76, -85, 79, -110, -18, -85, -61, 74, 10, -24, 1, 44, 81, -99, 126, -82, 99, -64, 77, 37, -60, -17, -33, 87, -83, 57, -118, 27, -6, 71, 113, -83, 90, -67, -80, 19, 115, 57, 56, 75, -60, -105, 24, -11, 120, 10, 106, -79, -11, -8, -34, 74, -103, -59, 38, -106, -55, -20, -56, -80, -61, 17, 124, -1, 36, 17, -65, -12, 99, 16, 83, 41, 90, -62, 46, -83, -78, 67, 81, -3, -13, -5, -21, -16, 96, 118, -85, 123, -112, 93, 60, -2, -32, 115, -93, 66, -7, -48, -37, -117, 63, -114, -59, -64, 43, 87, -51, -54, 80, -70, -47, -87, -63, -96, -42, 116, -87, -75, 9, -60, -77, -23, -43, 71, -19, -56, 100, -70, -74, 104, 27, 40, 26, -88, 75, 84, -42, 15, -97, 42, -84, 9, -97, 13, 48, -43, -3, 108, 82, -25, -88, 10, -127, 29, -53, 59, -48, 17, -120, -90, -79, -42, -72, -127, 54, 116, 54, 65, -110, 75, -58, 95, -28, 112, -103, 53, -11, -33, -10, -65, -40, -117, -99, 82, -84, 16, -94, 64, 89, -96};
    msg.data.assign(tmp_msg_0, tmp_msg_0 + sizeof(tmp_msg_0));

    try
    {
      Utils::ByteBuffer bfr;
      IMC::Packet::serialize(&msg, bfr);
      IMC::Message* msg_d = IMC::Packet::deserialize(bfr.getBuffer(), bfr.getSize());
      test.boolean("CompressedHistory #1", msg == *msg_d);
      delete msg_d;
    }
    catch (IMC::InvalidMessageSize& e)
    {
      (void)e;
      test.boolean("msg #1", msg.getSerializationSize() > DUNE_IMC_CONST_MAX_SIZE);
    }
  }

  {
    IMC::CompressedHistory msg;
    msg.setTimeStamp(0.9975680635761333);
    msg.setSource(47160U);
    msg.setSourceEntity(194U);
    msg.setDestination(64355U);
    msg.setDestinationEntity(212U);
    msg.base_lat = 0.2710562687705317;
    msg.base_lon = 0.3894469985480308;
    msg.base_time = 0.2652116603031517;
    const signed char tmp_msg_0[] = {-126, -83, 2, 63, 49, -17, -22, -115, -73, 116, -10, 15, -85, 1, -48, 115, -50, 122, 72, -32, -15, 57, 57, 27, 38, -16, 124, -88, -113, 112, 21, 45, -66, -80, -35, -48, 64, -1, 110, -36, -38, 87, 124, 39, 29, 37, -39, -75, 23, 89, -67, 109, 0, -93, 17, -15, 18, 43, 49, -28, 98, -90, -126, 48, 115, 71, -122, -71, 124, -20, -85, -4, 100, 40, -42, -50, -25, -106, -120, 123, 20, -53, -75, -61, -6, 54, 96, -25, 104, 8, 71, 25, -128, -84, -7, 120, 99, -34, 12, -91, -23, -98, 108, 37, -68, -74, -60, -86, 41, -109, 86, 41, -74, -54, 31, 88, 121, 67, 111, -68, 36, -109, 41, -77, 2, -10, 45, -20, 101, 39, -70, -1, 67, -75, 113, 75, -102, -44, 22, 39, -44, 13, 50, -11, 50, -16, -17, 4, -84, 90, -18, -24, 10, 106, -77, -72, -89, 16, -112, -32, 120, -46, 72, 110, 32, -1, 14, -48, -92, 82, -100, -44, 90, 4, 49, 99, 63, -12, 90, -32, 9, -116, 49, 28, -10, -43, 126, 115, 73, 46, -96, -112, -94, -91, 55, 78, -29, -79, -41, 78, -83, -50, -95, 80, 60, -60, 7, 23, 123, -1, 109, 124, -98, -40, -97, 23, 14, 56, -110, -82, -94, -90, -112};
    msg.data.assign(tmp_msg_0, tmp_msg_0 + sizeof(tmp_msg_0));

    try
    {
      Utils::ByteBuffer bfr;
      IMC::Packet::serialize(&msg, bfr);
      IMC::Message* msg_d = IMC::Packet::deserialize(bfr.getBuffer(), bfr.getSize());
      test.boolean("CompressedHistory #2", msg == *msg_d);
      delete msg_d;
    }
    catch (IMC::InvalidMessageSize& e)
    {
      (void)e;
      test.boolean("msg #2", msg.getSerializationSize() > DUNE_IMC_CONST_MAX_SIZE);
    }
  }

  {
    IMC::HistoricSample msg;
    msg.setTimeStamp(0.3354053358783755);
    msg.setSource(55662U);
    msg.setSourceEntity(120U);
    msg.setDestination(18459U);
    msg.setDestinationEntity(201U);
    msg.sys_id = 13364U;
    msg.priority = -66;
    msg.x = 29517;
    msg.y = -13112;
    msg.z = -19750;
    msg.t = 26802;
    IMC::MapFeature tmp_msg_0;
    tmp_msg_0.id.assign("FEGAHZFKMCVDEAYIEDZQNEONMTPSPPAKINYIRUJHBCCKDWSKKHFD");
    tmp_msg_0.feature_type = 185U;
    tmp_msg_0.rgb_red = 89U;
    tmp_msg_0.rgb_green = 181U;
    tmp_msg_0.rgb_blue = 142U;
    msg.sample.set(tmp_msg_0);

    try
    {
      Utils::ByteBuffer bfr;
      IMC::Packet::serialize(&msg, bfr);
      IMC::Message* msg_d = IMC::Packet::deserialize(bfr.getBuffer(), bfr.getSize());
      test.boolean("HistoricSample #0", msg == *msg_d);
      delete msg_d;
    }
    catch (IMC::InvalidMessageSize& e)
    {
      (void)e;
      test.boolean("msg #0", msg.getSerializationSize() > DUNE_IMC_CONST_MAX_SIZE);
    }
  }

  {
    IMC::HistoricSample msg;
    msg.setTimeStamp(0.39563249110660803);
    msg.setSource(17831U);
    msg.setSourceEntity(74U);
    msg.setDestination(53564U);
    msg.setDestinationEntity(122U);
    msg.sys_id = 28525U;
    msg.priority = -108;
    msg.x = 28024;
    msg.y = -20303;
    msg.z = -28917;
    msg.t = 30386;
    IMC::TrexToken tmp_msg_0;
    tmp_msg_0.timeline.assign("GASSOSRKZPQMNSYCIDEAITGIYUVJUXCCTPAALMNIXRDIHWUCZEHVJZVGXLULKFBNZWOWRGJMREKUZHZOCYBUNJJPPEVDINNYOIQOBXLUFOHGHSRJEGALPXIASKSNKSJU");
    tmp_msg_0.predicate.assign("FROZDIUYXTFZIAXTBPIKCASDXVNNNUPJGQUOHSQJYBJJYKVYKPIFWTCKTQKSRIMXIDQXUPZCRLFQZDYHZNHSZQEUZPMFWDLGWGTRAEUFSHGHTPYBOCMACPQTAJPJXOWYVTTEEDYWVVBBWLHMEQWIONHPECZOJRDDBQLOVBPDVXOHBRMNTWCWWFGBAMHFCMESLNKHCGYFMGGEUAMMRJ");
    msg.sample.set(tmp_msg_0);

    try
    {
      Utils::ByteBuffer bfr;
      IMC::Packet::serialize(&msg, bfr);
      IMC::Message* msg_d = IMC::Packet::deserialize(bfr.getBuffer(), bfr.getSize());
      test.boolean("HistoricSample #1", msg == *msg_d);
      delete msg_d;
    }
    catch (IMC::InvalidMessageSize& e)
    {
      (void)e;
      test.boolean("msg #1", msg.getSerializationSize() > DUNE_IMC_CONST_MAX_SIZE);
    }
  }

  {
    IMC::HistoricSample msg;
    msg.setTimeStamp(0.8201157780194815);
    msg.setSource(32464U);
    msg.setSourceEntity(230U);
    msg.setDestination(31970U);
    msg.setDestinationEntity(10U);
    msg.sys_id = 8635U;
    msg.priority = 111;
    msg.x = 23518;
    msg.y = -9989;
    msg.z = -28132;
    msg.t = 9848;
    IMC::AcousticSystems tmp_msg_0;
    tmp_msg_0.list.assign("IVPOFXDPTHVEAUPEQLOWLAZITMQBIXCWXAKJQNEKWAGGLUDNALWBVSOCPDDWXTSJSIKRTBRPEZFOXITFKDMSPJCHYXJHNRDRSXIOPYC");
    msg.sample.set(tmp_msg_0);

    try
    {
      Utils::ByteBuffer bfr;
      IMC::Packet::serialize(&msg, bfr);
      IMC::Message* msg_d = IMC::Packet::deserialize(bfr.getBuffer(), bfr.getSize());
      test.boolean("HistoricSample #2", msg == *msg_d);
      delete msg_d;
    }
    catch (IMC::InvalidMessageSize& e)
    {
      (void)e;
      test.boolean("msg #2", msg.getSerializationSize() > DUNE_IMC_CONST_MAX_SIZE);
    }
  }

  {
    IMC::HistoricDataQuery msg;
    msg.setTimeStamp(0.518491161130084);
    msg.setSource(27847U);
    msg.setSourceEntity(162U);
    msg.setDestination(3492U);
    msg.setDestinationEntity(44U);
    msg.req_id = 6197U;
    msg.type = 120U;
    msg.max_size = 6092U;
    IMC::HistoricData tmp_msg_0;
    tmp_msg_0.base_lat = 0.5505401010798466;
    tmp_msg_0.base_lon = 0.8684289512437807;
    tmp_msg_0.base_time = 0.310367125886127;
    msg.data.set(tmp_msg_0);

    try
    {
      Utils::ByteBuffer bfr;
      IMC::Packet::serialize(&msg, bfr);
      IMC::Message* msg_d = IMC::Packet::deserialize(bfr.getBuffer(), bfr.getSize());
      test.boolean("HistoricDataQuery #0", msg == *msg_d);
      delete msg_d;
    }
    catch (IMC::InvalidMessageSize& e)
    {
      (void)e;
      test.boolean("msg #0", msg.getSerializationSize() > DUNE_IMC_CONST_MAX_SIZE);
    }
  }

  {
    IMC::HistoricDataQuery msg;
    msg.setTimeStamp(0.029744982552890598);
    msg.setSource(42161U);
    msg.setSourceEntity(85U);
    msg.setDestination(37356U);
    msg.setDestinationEntity(76U);
    msg.req_id = 26783U;
    msg.type = 122U;
    msg.max_size = 43798U;
    IMC::HistoricData tmp_msg_0;
    tmp_msg_0.base_lat = 0.6246376850965382;
    tmp_msg_0.base_lon = 0.8247727567566723;
    tmp_msg_0.base_time = 0.8968871685694259;
    IMC::RemoteCommand tmp_tmp_msg_0_0;
    tmp_tmp_msg_0_0.original_source = 21547U;
    tmp_tmp_msg_0_0.destination = 27881U;
    tmp_tmp_msg_0_0.timeout = 0.8822069288254728;
    IMC::RemoteActionsRequest tmp_tmp_tmp_msg_0_0_0;
    tmp_tmp_tmp_msg_0_0_0.op = 5U;
    tmp_tmp_tmp_msg_0_0_0.actions.assign("OIAJDRENYEKPGPMMEDYVFWLNXGCQMBBXMQVRMIFLLKIYDJVQEVXYLOQASVFPCNRLWWZDBARYJFXKUQPFFCOXOGGSPPVHIKLATESVJTUVLBYBXUIPZTSDAYXGAOLZZQUIMSBNONMBYAHHORTXUIRMBDGZHNQCOGKBA");
    tmp_tmp_msg_0_0.cmd.set(tmp_tmp_tmp_msg_0_0_0);
    tmp_msg_0.data.push_back(tmp_tmp_msg_0_0);
    msg.data.set(tmp_msg_0);

    try
    {
      Utils::ByteBuffer bfr;
      IMC::Packet::serialize(&msg, bfr);
      IMC::Message* msg_d = IMC::Packet::deserialize(bfr.getBuffer(), bfr.getSize());
      test.boolean("HistoricDataQuery #1", msg == *msg_d);
      delete msg_d;
    }
    catch (IMC::InvalidMessageSize& e)
    {
      (void)e;
      test.boolean("msg #1", msg.getSerializationSize() > DUNE_IMC_CONST_MAX_SIZE);
    }
  }

  {
    IMC::HistoricDataQuery msg;
    msg.setTimeStamp(0.6853809534666611);
    msg.setSource(54625U);
    msg.setSourceEntity(165U);
    msg.setDestination(12455U);
    msg.setDestinationEntity(218U);
    msg.req_id = 53506U;
    msg.type = 63U;
    msg.max_size = 46340U;
    IMC::HistoricData tmp_msg_0;
    tmp_msg_0.base_lat = 0.5753053452966546;
    tmp_msg_0.base_lon = 0.5902536888516974;
    tmp_msg_0.base_time = 0.4733028589990993;
    msg.data.set(tmp_msg_0);

    try
    {
      Utils::ByteBuffer bfr;
      IMC::Packet::serialize(&msg, bfr);
      IMC::Message* msg_d = IMC::Packet::deserialize(bfr.getBuffer(), bfr.getSize());
      test.boolean("HistoricDataQuery #2", msg == *msg_d);
      delete msg_d;
    }
    catch (IMC::InvalidMessageSize& e)
    {
      (void)e;
      test.boolean("msg #2", msg.getSerializationSize() > DUNE_IMC_CONST_MAX_SIZE);
    }
  }

  {
    IMC::RemoteCommand msg;
    msg.setTimeStamp(0.9653941468695321);
    msg.setSource(9999U);
    msg.setSourceEntity(152U);
    msg.setDestination(19973U);
    msg.setDestinationEntity(147U);
    msg.original_source = 8133U;
    msg.destination = 3566U;
    msg.timeout = 0.9021657571520941;
    IMC::IoEvent tmp_msg_0;
    tmp_msg_0.type = 70U;
    tmp_msg_0.error.assign("QPOXJFPULDCNUSXXAGOTXORNBWKBITYNEGIYICIRKHWDBOKIIBSTJOECCSZEUMWOHARACHLUYCPYLYPOPGKWSZPCEHJQFXBGDHCSVKIHRJLQJRCKLXSNGVXFDJULYAAMONVUQTVSRMNZBHRAMWYBDVFYKFUBPESWNWDTVDMFYRRQDPKSXGJZIZSHWEXBQUZOMIJFGXVRFECLZYEHTQAPMPGMKDVVTUUATFIJZGLWKNQFGAQWEZLTQJENANM");
    msg.cmd.set(tmp_msg_0);

    try
    {
      Utils::ByteBuffer bfr;
      IMC::Packet::serialize(&msg, bfr);
      IMC::Message* msg_d = IMC::Packet::deserialize(bfr.getBuffer(), bfr.getSize());
      test.boolean("RemoteCommand #0", msg == *msg_d);
      delete msg_d;
    }
    catch (IMC::InvalidMessageSize& e)
    {
      (void)e;
      test.boolean("msg #0", msg.getSerializationSize() > DUNE_IMC_CONST_MAX_SIZE);
    }
  }

  {
    IMC::RemoteCommand msg;
    msg.setTimeStamp(0.9648359020452273);
    msg.setSource(39731U);
    msg.setSourceEntity(8U);
    msg.setDestination(21532U);
    msg.setDestinationEntity(159U);
    msg.original_source = 62808U;
    msg.destination = 17496U;
    msg.timeout = 0.20283125482480335;
    IMC::UsblPositionExtended tmp_msg_0;
    tmp_msg_0.target.assign("AMGHNTHTCPWVOWSDOPXBPRCKAJMEFWDQSMAVUQGGMGIOXKWENMXNEKVKLTVNSURZIWOFTQFODXAUYFGQWLIUFBALHBLVATXFLRJZOFDEHVPRGEGFTMYHTNMUPUQWISOKZNLCZCZFJHKONYYWAXCQSUNQYNHDJDYKVVISNBSKITZKGXXIOOQMVYCESDWBCBUBPISQRRJPYIICFCHHGUTCJJELWLYRPVZHJBZLRPXAMYRGUDEBEZBDDT");
    tmp_msg_0.x = 0.7130970023416582;
    tmp_msg_0.y = 0.014882225694220264;
    tmp_msg_0.z = 0.4190769588291503;
    tmp_msg_0.n = 0.872170081518179;
    tmp_msg_0.e = 0.323530485871224;
    tmp_msg_0.d = 0.4277995835604216;
    tmp_msg_0.phi = 0.22669418281834497;
    tmp_msg_0.theta = 0.00588670971353733;
    tmp_msg_0.psi = 0.5403989880628488;
    tmp_msg_0.accuracy = 0.7150579501128452;
    msg.cmd.set(tmp_msg_0);

    try
    {
      Utils::ByteBuffer bfr;
      IMC::Packet::serialize(&msg, bfr);
      IMC::Message* msg_d = IMC::Packet::deserialize(bfr.getBuffer(), bfr.getSize());
      test.boolean("RemoteCommand #1", msg == *msg_d);
      delete msg_d;
    }
    catch (IMC::InvalidMessageSize& e)
    {
      (void)e;
      test.boolean("msg #1", msg.getSerializationSize() > DUNE_IMC_CONST_MAX_SIZE);
    }
  }

  {
    IMC::RemoteCommand msg;
    msg.setTimeStamp(0.7550968696562012);
    msg.setSource(33993U);
    msg.setSourceEntity(12U);
    msg.setDestination(41111U);
    msg.setDestinationEntity(179U);
    msg.original_source = 9601U;
    msg.destination = 40021U;
    msg.timeout = 0.9544005649733536;
    IMC::GpsNavData tmp_msg_0;
    tmp_msg_0.itow = 4187693876U;
    tmp_msg_0.lat = 0.6458119613606509;
    tmp_msg_0.lon = 0.6408813595897267;
    tmp_msg_0.height_ell = 0.05803951276545738;
    tmp_msg_0.height_sea = 0.31202374951338097;
    tmp_msg_0.hacc = 0.10299501960698332;
    tmp_msg_0.vacc = 0.6792447213745805;
    tmp_msg_0.vel_n = 0.15415667058442928;
    tmp_msg_0.vel_e = 0.6277594630797114;
    tmp_msg_0.vel_d = 0.30627743458431067;
    tmp_msg_0.speed = 0.9276650639981417;
    tmp_msg_0.gspeed = 0.8299907244273087;
    tmp_msg_0.heading = 0.955082603667825;
    tmp_msg_0.sacc = 0.013001685662927365;
    tmp_msg_0.cacc = 0.252809049304797;
    msg.cmd.set(tmp_msg_0);

    try
    {
      Utils::ByteBuffer bfr;
      IMC::Packet::serialize(&msg, bfr);
      IMC::Message* msg_d = IMC::Packet::deserialize(bfr.getBuffer(), bfr.getSize());
      test.boolean("RemoteCommand #2", msg == *msg_d);
      delete msg_d;
    }
    catch (IMC::InvalidMessageSize& e)
    {
      (void)e;
      test.boolean("msg #2", msg.getSerializationSize() > DUNE_IMC_CONST_MAX_SIZE);
    }
  }

  {
    IMC::CommSystemsQuery msg;
    msg.setTimeStamp(0.7679107473505898);
    msg.setSource(48684U);
    msg.setSourceEntity(186U);
    msg.setDestination(1996U);
    msg.setDestinationEntity(141U);
    msg.type = 143U;
    msg.comm_interface = 35867U;
    msg.model = 7512U;
    msg.list.assign("XWJGHCHCCIJMZEQPAYXQZEYXLJWQPJSIZNKDHPTSZMCURMGZMXFBRMDJLTTPVNRHOTAYWIDPIQKAONYVOIMLRJCACUVZAECFGGHDGDNFOYSBDUVOSVSGZUAYWBTALDIUXVNLLAMYFPTPTYYNRHTUJFKNUXQWIEVFDBBHECZMLHRIDFOFVNEWEYCBSHGBKKUZJSVPBNXLTKAEMQGOFX");

    try
    {
      Utils::ByteBuffer bfr;
      IMC::Packet::serialize(&msg, bfr);
      IMC::Message* msg_d = IMC::Packet::deserialize(bfr.getBuffer(), bfr.getSize());
      test.boolean("CommSystemsQuery #0", msg == *msg_d);
      delete msg_d;
    }
    catch (IMC::InvalidMessageSize& e)
    {
      (void)e;
      test.boolean("msg #0", msg.getSerializationSize() > DUNE_IMC_CONST_MAX_SIZE);
    }
  }

  {
    IMC::CommSystemsQuery msg;
    msg.setTimeStamp(0.30758759053360707);
    msg.setSource(21337U);
    msg.setSourceEntity(230U);
    msg.setDestination(5379U);
    msg.setDestinationEntity(157U);
    msg.type = 41U;
    msg.comm_interface = 917U;
    msg.model = 58743U;
    msg.list.assign("JHVIBFMCZKPFQBPNVMBYNGZOZXRWPEEUQAHGKSTXZNYSTQTQBZGIJSENWMZCQLCWKLDFGOUDMJZBVDPVEVM");

    try
    {
      Utils::ByteBuffer bfr;
      IMC::Packet::serialize(&msg, bfr);
      IMC::Message* msg_d = IMC::Packet::deserialize(bfr.getBuffer(), bfr.getSize());
      test.boolean("CommSystemsQuery #1", msg == *msg_d);
      delete msg_d;
    }
    catch (IMC::InvalidMessageSize& e)
    {
      (void)e;
      test.boolean("msg #1", msg.getSerializationSize() > DUNE_IMC_CONST_MAX_SIZE);
    }
  }

  {
    IMC::CommSystemsQuery msg;
    msg.setTimeStamp(0.5000502614622744);
    msg.setSource(55707U);
    msg.setSourceEntity(82U);
    msg.setDestination(54368U);
    msg.setDestinationEntity(82U);
    msg.type = 252U;
    msg.comm_interface = 9343U;
    msg.model = 19230U;
    msg.list.assign("HJEOBVFXCYIQKFKRFLPEUNDTUKPDXEUBNGQVRIPMQGHQVXLSQLSAONAZHTGMNMDIYYFWLPXFQGZAZZCBSYDRWROEPMBGSVPCLBJSYKTJPHBJMLTYJCOIUYFVROXIIRBQEQORB");

    try
    {
      Utils::ByteBuffer bfr;
      IMC::Packet::serialize(&msg, bfr);
      IMC::Message* msg_d = IMC::Packet::deserialize(bfr.getBuffer(), bfr.getSize());
      test.boolean("CommSystemsQuery #2", msg == *msg_d);
      delete msg_d;
    }
    catch (IMC::InvalidMessageSize& e)
    {
      (void)e;
      test.boolean("msg #2", msg.getSerializationSize() > DUNE_IMC_CONST_MAX_SIZE);
    }
  }

  {
    IMC::TelemetryMsg msg;
    msg.setTimeStamp(0.9817650425260853);
    msg.setSource(44879U);
    msg.setSourceEntity(219U);
    msg.setDestination(13208U);
    msg.setDestinationEntity(236U);
    msg.type = 52U;
    msg.req_id = 90139063U;
    msg.ttl = 64047U;
    msg.code = 61U;
    msg.destination.assign("BMWFRSARUINZLDZAEWNOILCLIONLYPQDSIHHOQTDOVVAKTWHZJKTTGITJOFXCNRXHULQBDCKXPDNWBSMXYRFBCEOEDRWXJQKNHPQPVKKFGPFMYRVMTHUVRZTEGPFGNVJMDSHEIDSSAXEXBHAUIBYVROGHIAFUGJZIJMJ");
    msg.source.assign("UYKPBSQVVIQPNNOZHJEKISHCZNQWFTHAYFQAUGMLJDPVWPRVHPCYKYSBCRAHNRRJRFVQSFCZYEDGIUMERACIHUYZCWQGOSUHXWKDSYWWRSGMOUDCIFLDSLLTZDJVGMWSCZBXMBRYTWNKEOBHKKLDTANAMBJMXPOSQIKUQMTMKOJWGOEDYBEDZDBKIFXX");
    msg.acknowledge = 165U;
    msg.status = 21U;
    const signed char tmp_msg_0[] = {-66, 61, -19, -67, 49, -93, 40, 81, 108, 82, -97, -111, 60, -24, -35, 45, 101, -30, 112, 63, 17, -81, 53, 50, 117, -75, 87, -97, 98, -105, 121, 76, -23, 31, 21, 98, 12, 87, -84, 113, 45, -106, 95, 28, -35, 123, 4, -66, -21, -24, 5, 120, 73, 102, -9, 110, 86, 60, -64, 78, 111, -54, 71, -97, 102, 23, 45, 99, -112, 87, -81, 11, -90, -19, 101, -82, -60, -72, 81, 117, 89, -99, 30, -123, -65, 121, 15, -120, 32, 19, -31, 1, -96, -68, 103, -77, -5, -98, 41, -65, 72, 27, -103, -3, 3, 96, 34, -29, 58, 52, -88, -69, -82, -88, -17, 41, 108, 72, -95, 55, 71, -12, 122, 54, -105, 19, 89, 2, -46, -116, 89, -82, 7, -38, 74, 66, -117, 74, 114, -98, 76, 56, 112, 85, 91, 55, 76, 15, 117, 18, 92, 39, 60, 31, 79, 94, 0, 100, 8, 57, 32, -53, 71, 69, 103, 103, -99, -24, 37, 57, -17, -83, -28, 17, -86, -113, -104};
    msg.data.assign(tmp_msg_0, tmp_msg_0 + sizeof(tmp_msg_0));

    try
    {
      Utils::ByteBuffer bfr;
      IMC::Packet::serialize(&msg, bfr);
      IMC::Message* msg_d = IMC::Packet::deserialize(bfr.getBuffer(), bfr.getSize());
      test.boolean("TelemetryMsg #0", msg == *msg_d);
      delete msg_d;
    }
    catch (IMC::InvalidMessageSize& e)
    {
      (void)e;
      test.boolean("msg #0", msg.getSerializationSize() > DUNE_IMC_CONST_MAX_SIZE);
    }
  }

  {
    IMC::TelemetryMsg msg;
    msg.setTimeStamp(0.34246174866866363);
    msg.setSource(14519U);
    msg.setSourceEntity(12U);
    msg.setDestination(35914U);
    msg.setDestinationEntity(72U);
    msg.type = 101U;
    msg.req_id = 1396278890U;
    msg.ttl = 58846U;
    msg.code = 189U;
    msg.destination.assign("QTYMZLHCGIJNFVDBKLXYZICEXZYRPVNCENYOPXWDJCIENSSVGWYDQZOLTOWFCBQDKPCTKRMRIRWXURXMWLBKGVESSTPYZWLUFKQWSAENCDJJFTOOKJPEDOEUXZUR");
    msg.source.assign("BGMDDICVENJZNCJTNTIZEQMUHCQALFMYRLPTXXQGXVYZOINWXKTBPBMVGUGOJUQK");
    msg.acknowledge = 124U;
    msg.status = 102U;
    const signed char tmp_msg_0[] = {-95, 26, -78, 10, -21, -31, 69, 65, 12, -28, 8, -91, 72, -93, -126, -66, 61, 45, -112, 68, 17, -43, 37, -36, -23, 90, -30, -71, 17, -33, -58, 41, 12, -13, -40, -82, 8, -24, -64, 97, 46, 101, -28, 36, -98, -108, -32, 23, -98, -100, 1, -117, 29, -90, 49, 94, 0, -23, -121, 122, -64, 63, -17, 5, -45, -69, 4, -72, -127, -91, -39, 53, -9, -51, 72, -105, 18, -53, -98, 73, 53, 114, 21, 86, -54, 113, 68, -52, -44, 59, 79, -115, 123, 79, -105, -19, 21, 87, -74, 93, -26, -30, 35, 96, -4, -72, 53, 109, 45, -120, 87, 6, -30, -43, -43, -29, 121, -94, 89, 82, 78, -14, -42, -37, -79};
    msg.data.assign(tmp_msg_0, tmp_msg_0 + sizeof(tmp_msg_0));

    try
    {
      Utils::ByteBuffer bfr;
      IMC::Packet::serialize(&msg, bfr);
      IMC::Message* msg_d = IMC::Packet::deserialize(bfr.getBuffer(), bfr.getSize());
      test.boolean("TelemetryMsg #1", msg == *msg_d);
      delete msg_d;
    }
    catch (IMC::InvalidMessageSize& e)
    {
      (void)e;
      test.boolean("msg #1", msg.getSerializationSize() > DUNE_IMC_CONST_MAX_SIZE);
    }
  }

  {
    IMC::TelemetryMsg msg;
    msg.setTimeStamp(0.17275637736367888);
    msg.setSource(30445U);
    msg.setSourceEntity(5U);
    msg.setDestination(42685U);
    msg.setDestinationEntity(239U);
    msg.type = 110U;
    msg.req_id = 1436110247U;
    msg.ttl = 36457U;
    msg.code = 5U;
    msg.destination.assign("VHUVOMENVRDAQGHUNIDEHSKPYPIQGIJBSMCVXAEUJQVNLHQOITHIUMHGSCMGTFQCSLDNOBHZWTWKUQCFEBEMXXUXFYAGWGFQOCWOYWRBKRPOLEAVPXXOQNDOVGJFIDFZWBEINCYZFDHFTXCAEWYYMVLPVZA");
    msg.source.assign("YKEUIIMLYEUGCNJFBPHBIWIOOLRQQIHNNGAMTDBCCZYMGSLLWFWPMTPQRMVWYJGNPQDEYIPXKRVYKPCQDWVCOOTZKYTUIEAKPHYMRJLJNYKMNEBWRBDVTFCXACWVGGUNXUAMLNQJARNOHHV");
    msg.acknowledge = 52U;
    msg.status = 197U;
    const signed char tmp_msg_0[] = {-31, -45, -112, 9, 67, 85, -11, -111, -92, -30, -47, -86, -109, 49, -61, -102, -85, 76, 73, -122, 53, 59, 5, 21, 27, -116, -15, -119, 86, 60, -90, 106, 93, -7, -51, 8};
    msg.data.assign(tmp_msg_0, tmp_msg_0 + sizeof(tmp_msg_0));

    try
    {
      Utils::ByteBuffer bfr;
      IMC::Packet::serialize(&msg, bfr);
      IMC::Message* msg_d = IMC::Packet::deserialize(bfr.getBuffer(), bfr.getSize());
      test.boolean("TelemetryMsg #2", msg == *msg_d);
      delete msg_d;
    }
    catch (IMC::InvalidMessageSize& e)
    {
      (void)e;
      test.boolean("msg #2", msg.getSerializationSize() > DUNE_IMC_CONST_MAX_SIZE);
    }
  }

  {
    IMC::LblRange msg;
    msg.setTimeStamp(0.31397796615185036);
    msg.setSource(59902U);
    msg.setSourceEntity(33U);
    msg.setDestination(45250U);
    msg.setDestinationEntity(85U);
    msg.id = 225U;
    msg.range = 0.9399561344384211;

    try
    {
      Utils::ByteBuffer bfr;
      IMC::Packet::serialize(&msg, bfr);
      IMC::Message* msg_d = IMC::Packet::deserialize(bfr.getBuffer(), bfr.getSize());
      test.boolean("LblRange #0", msg == *msg_d);
      delete msg_d;
    }
    catch (IMC::InvalidMessageSize& e)
    {
      (void)e;
      test.boolean("msg #0", msg.getSerializationSize() > DUNE_IMC_CONST_MAX_SIZE);
    }
  }

  {
    IMC::LblRange msg;
    msg.setTimeStamp(0.8115359120617972);
    msg.setSource(52860U);
    msg.setSourceEntity(146U);
    msg.setDestination(36681U);
    msg.setDestinationEntity(78U);
    msg.id = 16U;
    msg.range = 0.9072813447792891;

    try
    {
      Utils::ByteBuffer bfr;
      IMC::Packet::serialize(&msg, bfr);
      IMC::Message* msg_d = IMC::Packet::deserialize(bfr.getBuffer(), bfr.getSize());
      test.boolean("LblRange #1", msg == *msg_d);
      delete msg_d;
    }
    catch (IMC::InvalidMessageSize& e)
    {
      (void)e;
      test.boolean("msg #1", msg.getSerializationSize() > DUNE_IMC_CONST_MAX_SIZE);
    }
  }

  {
    IMC::LblRange msg;
    msg.setTimeStamp(0.2783271175188954);
    msg.setSource(34121U);
    msg.setSourceEntity(48U);
    msg.setDestination(41978U);
    msg.setDestinationEntity(122U);
    msg.id = 208U;
    msg.range = 0.08860354685665994;

    try
    {
      Utils::ByteBuffer bfr;
      IMC::Packet::serialize(&msg, bfr);
      IMC::Message* msg_d = IMC::Packet::deserialize(bfr.getBuffer(), bfr.getSize());
      test.boolean("LblRange #2", msg == *msg_d);
      delete msg_d;
    }
    catch (IMC::InvalidMessageSize& e)
    {
      (void)e;
      test.boolean("msg #2", msg.getSerializationSize() > DUNE_IMC_CONST_MAX_SIZE);
    }
  }

  {
    IMC::LblBeacon msg;
    msg.setTimeStamp(0.17687532506861747);
    msg.setSource(61977U);
    msg.setSourceEntity(2U);
    msg.setDestination(3876U);
    msg.setDestinationEntity(234U);
    msg.beacon.assign("SZEYJDCIXRKFMGKZJPMIGOLVVHVBLFPYIABYKOIRZHSQPUOOKBNIZFPHYHPOSCQREVLXVXADDQJTHPFRRCDQIREPQEIXJUSIEYTEUXBFYQGYOFHUWWMOFHGTDWPVLIEVGQNENNEYCOXNDVWJFPYCQNMOSBTGAWWCSMUTLKFAJILMNMWHWKX");
    msg.lat = 0.9160045309876292;
    msg.lon = 0.2248311479481121;
    msg.depth = 0.2386580130127013;
    msg.query_channel = 33U;
    msg.reply_channel = 123U;
    msg.transponder_delay = 95U;

    try
    {
      Utils::ByteBuffer bfr;
      IMC::Packet::serialize(&msg, bfr);
      IMC::Message* msg_d = IMC::Packet::deserialize(bfr.getBuffer(), bfr.getSize());
      test.boolean("LblBeacon #0", msg == *msg_d);
      delete msg_d;
    }
    catch (IMC::InvalidMessageSize& e)
    {
      (void)e;
      test.boolean("msg #0", msg.getSerializationSize() > DUNE_IMC_CONST_MAX_SIZE);
    }
  }

  {
    IMC::LblBeacon msg;
    msg.setTimeStamp(0.3378767679691759);
    msg.setSource(38407U);
    msg.setSourceEntity(51U);
    msg.setDestination(65231U);
    msg.setDestinationEntity(197U);
    msg.beacon.assign("NCWMXALGQPUYDZPKBIRURZTUMMMLEJGCYUPATQJKNGMFXINYVEWHVWMIQZXIZQMEKILZOWVXHWMHWFNCARCWYGBBKE");
    msg.lat = 0.7458306633174079;
    msg.lon = 0.24386948854350543;
    msg.depth = 0.5941877868295692;
    msg.query_channel = 102U;
    msg.reply_channel = 58U;
    msg.transponder_delay = 216U;

    try
    {
      Utils::ByteBuffer bfr;
      IMC::Packet::serialize(&msg, bfr);
      IMC::Message* msg_d = IMC::Packet::deserialize(bfr.getBuffer(), bfr.getSize());
      test.boolean("LblBeacon #1", msg == *msg_d);
      delete msg_d;
    }
    catch (IMC::InvalidMessageSize& e)
    {
      (void)e;
      test.boolean("msg #1", msg.getSerializationSize() > DUNE_IMC_CONST_MAX_SIZE);
    }
  }

  {
    IMC::LblBeacon msg;
    msg.setTimeStamp(0.5301674446344413);
    msg.setSource(3892U);
    msg.setSourceEntity(150U);
    msg.setDestination(57709U);
    msg.setDestinationEntity(188U);
    msg.beacon.assign("SNGKQTLXFSKDZNVZMNUCGTUJJYHMAXFZJHREGLEBURWLOFCNTXHDBDHARDYWKFJJCARQEJTZEKEIFOFHPKKOOMCSIVZGIDP");
    msg.lat = 0.8166001428141528;
    msg.lon = 0.5473205800256917;
    msg.depth = 0.4434580334093382;
    msg.query_channel = 227U;
    msg.reply_channel = 8U;
    msg.transponder_delay = 179U;

    try
    {
      Utils::ByteBuffer bfr;
      IMC::Packet::serialize(&msg, bfr);
      IMC::Message* msg_d = IMC::Packet::deserialize(bfr.getBuffer(), bfr.getSize());
      test.boolean("LblBeacon #2", msg == *msg_d);
      delete msg_d;
    }
    catch (IMC::InvalidMessageSize& e)
    {
      (void)e;
      test.boolean("msg #2", msg.getSerializationSize() > DUNE_IMC_CONST_MAX_SIZE);
    }
  }

  {
    IMC::LblConfig msg;
    msg.setTimeStamp(0.07830560000153197);
    msg.setSource(5431U);
    msg.setSourceEntity(155U);
    msg.setDestination(21196U);
    msg.setDestinationEntity(116U);
    msg.op = 22U;

    try
    {
      Utils::ByteBuffer bfr;
      IMC::Packet::serialize(&msg, bfr);
      IMC::Message* msg_d = IMC::Packet::deserialize(bfr.getBuffer(), bfr.getSize());
      test.boolean("LblConfig #0", msg == *msg_d);
      delete msg_d;
    }
    catch (IMC::InvalidMessageSize& e)
    {
      (void)e;
      test.boolean("msg #0", msg.getSerializationSize() > DUNE_IMC_CONST_MAX_SIZE);
    }
  }

  {
    IMC::LblConfig msg;
    msg.setTimeStamp(0.45797170425355094);
    msg.setSource(46549U);
    msg.setSourceEntity(164U);
    msg.setDestination(49615U);
    msg.setDestinationEntity(23U);
    msg.op = 84U;
    IMC::LblBeacon tmp_msg_0;
    tmp_msg_0.beacon.assign("CZFTXPYIQGGUBCMNMXUUNLO");
    tmp_msg_0.lat = 0.5681422687255753;
    tmp_msg_0.lon = 0.28517542789397843;
    tmp_msg_0.depth = 0.6136124252762551;
    tmp_msg_0.query_channel = 60U;
    tmp_msg_0.reply_channel = 26U;
    tmp_msg_0.transponder_delay = 113U;
    msg.beacons.push_back(tmp_msg_0);

    try
    {
      Utils::ByteBuffer bfr;
      IMC::Packet::serialize(&msg, bfr);
      IMC::Message* msg_d = IMC::Packet::deserialize(bfr.getBuffer(), bfr.getSize());
      test.boolean("LblConfig #1", msg == *msg_d);
      delete msg_d;
    }
    catch (IMC::InvalidMessageSize& e)
    {
      (void)e;
      test.boolean("msg #1", msg.getSerializationSize() > DUNE_IMC_CONST_MAX_SIZE);
    }
  }

  {
    IMC::LblConfig msg;
    msg.setTimeStamp(0.22709541540045441);
    msg.setSource(51274U);
    msg.setSourceEntity(143U);
    msg.setDestination(15043U);
    msg.setDestinationEntity(93U);
    msg.op = 130U;
    IMC::LblBeacon tmp_msg_0;
    tmp_msg_0.beacon.assign("NMMVUOXBJCFXZMDVKMZTFEZVAFYEVCBJPWAWXEJKMVTWGQKIYMFIZAVYWAUCARXIFDEGBPRLCIYQSMUJBPBNHCWDXPMRBGICDR");
    tmp_msg_0.lat = 0.8309568923182494;
    tmp_msg_0.lon = 0.0004339544953848584;
    tmp_msg_0.depth = 0.7482165908440604;
    tmp_msg_0.query_channel = 197U;
    tmp_msg_0.reply_channel = 238U;
    tmp_msg_0.transponder_delay = 185U;
    msg.beacons.push_back(tmp_msg_0);

    try
    {
      Utils::ByteBuffer bfr;
      IMC::Packet::serialize(&msg, bfr);
      IMC::Message* msg_d = IMC::Packet::deserialize(bfr.getBuffer(), bfr.getSize());
      test.boolean("LblConfig #2", msg == *msg_d);
      delete msg_d;
    }
    catch (IMC::InvalidMessageSize& e)
    {
      (void)e;
      test.boolean("msg #2", msg.getSerializationSize() > DUNE_IMC_CONST_MAX_SIZE);
    }
  }

  {
    IMC::AcousticMessage msg;
    msg.setTimeStamp(0.48698033259401563);
    msg.setSource(64501U);
    msg.setSourceEntity(20U);
    msg.setDestination(39963U);
    msg.setDestinationEntity(162U);
    IMC::VtolState tmp_msg_0;
    tmp_msg_0.state = 15U;
    msg.message.set(tmp_msg_0);

    try
    {
      Utils::ByteBuffer bfr;
      IMC::Packet::serialize(&msg, bfr);
      IMC::Message* msg_d = IMC::Packet::deserialize(bfr.getBuffer(), bfr.getSize());
      test.boolean("AcousticMessage #0", msg == *msg_d);
      delete msg_d;
    }
    catch (IMC::InvalidMessageSize& e)
    {
      (void)e;
      test.boolean("msg #0", msg.getSerializationSize() > DUNE_IMC_CONST_MAX_SIZE);
    }
  }

  {
    IMC::AcousticMessage msg;
    msg.setTimeStamp(0.5199873294462031);
    msg.setSource(921U);
    msg.setSourceEntity(43U);
    msg.setDestination(41666U);
    msg.setDestinationEntity(64U);
    IMC::Phycocyanin tmp_msg_0;
    tmp_msg_0.value = 0.39304483122884804;
    msg.message.set(tmp_msg_0);

    try
    {
      Utils::ByteBuffer bfr;
      IMC::Packet::serialize(&msg, bfr);
      IMC::Message* msg_d = IMC::Packet::deserialize(bfr.getBuffer(), bfr.getSize());
      test.boolean("AcousticMessage #1", msg == *msg_d);
      delete msg_d;
    }
    catch (IMC::InvalidMessageSize& e)
    {
      (void)e;
      test.boolean("msg #1", msg.getSerializationSize() > DUNE_IMC_CONST_MAX_SIZE);
    }
  }

  {
    IMC::AcousticMessage msg;
    msg.setTimeStamp(0.6877088971195671);
    msg.setSource(6297U);
    msg.setSourceEntity(125U);
    msg.setDestination(52259U);
    msg.setDestinationEntity(78U);
    IMC::SetPWM tmp_msg_0;
    tmp_msg_0.id = 51U;
    tmp_msg_0.period = 3552755459U;
    tmp_msg_0.duty_cycle = 2031874195U;
    msg.message.set(tmp_msg_0);

    try
    {
      Utils::ByteBuffer bfr;
      IMC::Packet::serialize(&msg, bfr);
      IMC::Message* msg_d = IMC::Packet::deserialize(bfr.getBuffer(), bfr.getSize());
      test.boolean("AcousticMessage #2", msg == *msg_d);
      delete msg_d;
    }
    catch (IMC::InvalidMessageSize& e)
    {
      (void)e;
      test.boolean("msg #2", msg.getSerializationSize() > DUNE_IMC_CONST_MAX_SIZE);
    }
  }

  {
    IMC::SimAcousticMessage msg;
    msg.setTimeStamp(0.3478967145299964);
    msg.setSource(10693U);
    msg.setSourceEntity(65U);
    msg.setDestination(61674U);
    msg.setDestinationEntity(199U);
    msg.lat = 0.12381514621517042;
    msg.lon = 0.27907624430006206;
    msg.depth = 0.7727682220747554;
    msg.sentence.assign("JWAITOHJSPFYHXITVFIWUKDGENTFAFBECEFPYSGQCBETHRELXJTNZGUQTRGYYKOVKZZVZZIALQFZAASTRQZWWMJQARKXPZQXKWDFNPOKMKBYLEJOFEBASBUUONPWVEDDJHBXIJRCDHUPUZUSHMHNNUCCGSVWSGVXLQCNOIXNMJRLYKOGPIWLXRMMQWCAAGKEBXEDSRBDBB");
    msg.txtime = 0.5176948896069637;
    msg.modem_type.assign("PBVXWIQLPGFHKNGARMDCULFEFCBBEJQTRGOOJLVRAFBYVIJDXESIZWNAXHPQLGNRRITMAUBCZBQAMQDMMTBVIKBZTOVCFXFUTDGYWJZSQJGSNUONMMZZQAXTNISVRWKEYZORXLRADIWEVCLOJWWYLMKDTHHPJYWNCOPJPSZPKXUMLYIKHXAYPUJTDUUYZPGGBHOCK");
    msg.sys_src.assign("UFPZJSKHTAJPRWLWZFZBDFGDCPPWBXOOHMPVYDDRSPQTNGZEMYFXNZULKSEMTNTIUSUCXEVFYETRHRTQADSLR");
    msg.seq = 41326U;
    msg.sys_dst.assign("ZDDLRMYJPEZWPEVVNETNMXMVHTNSMGIBCUBUWXLEURJRBDYZWWRYJDQQNBLRSJAGHVQBHPQMFUULCZII");
    msg.flags = 207U;
    const signed char tmp_msg_0[] = {4, 100, -74, -105, 18, -100, 69, -59, 123, -25, -15};
    msg.data.assign(tmp_msg_0, tmp_msg_0 + sizeof(tmp_msg_0));

    try
    {
      Utils::ByteBuffer bfr;
      IMC::Packet::serialize(&msg, bfr);
      IMC::Message* msg_d = IMC::Packet::deserialize(bfr.getBuffer(), bfr.getSize());
      test.boolean("SimAcousticMessage #0", msg == *msg_d);
      delete msg_d;
    }
    catch (IMC::InvalidMessageSize& e)
    {
      (void)e;
      test.boolean("msg #0", msg.getSerializationSize() > DUNE_IMC_CONST_MAX_SIZE);
    }
  }

  {
    IMC::SimAcousticMessage msg;
    msg.setTimeStamp(0.35639679420892967);
    msg.setSource(52389U);
    msg.setSourceEntity(147U);
    msg.setDestination(35432U);
    msg.setDestinationEntity(24U);
    msg.lat = 0.5233556904292379;
    msg.lon = 0.7379124525195823;
    msg.depth = 0.6703508531087043;
    msg.sentence.assign("YFKYJOBMNGDLJFNRCFIDYTJKQCZSQSERTMTEGJKHYTIRCQSBCURWMNMPVNRWDVJFNEVHPWEFPXJSGYTPIZKZUJJUPCFRQXBPZYPODHGOUMNBXHQWKBVIARFGDPNQNVQKWWRXXVYIWGOOKLHAQYTVYOFXCLSXZMPMGBHUEAXIDWNEUUZGDWVIRECA");
    msg.txtime = 0.8591697607421279;
    msg.modem_type.assign("WYIXVYLBKEFJTTZDJNEMPBLHFZHTEUJDVLXLVTSPDRFOVLOGWFRUEXIZSQNTYZOWCOKSGXOVIRMLFYRZKCVEM");
    msg.sys_src.assign("KBXPOMBCNQPAUZFLZGRULQIBASPICWIWOAAIORYMROWGGYOHNZDBVDNYGKUJREMZFIOLTNESKUTKNULVYYFRVZWAJRZDBEHCSEPTQLWHJPNCWHOSFSXDEVUFYHUMTJTRFLNTNDXVLSKXRBBJVMZRKJXIQ");
    msg.seq = 51124U;
    msg.sys_dst.assign("NOLYCSQYAQVUKWJHGRZXNQYDLUATPXFBFMSPEIKZYIKXXQENBOXKHZJORPTRAKMGVYTRMZTGMFIWKNOKGJLWVZCJFUCVSJDICLHSLSBHVOGIJGF");
    msg.flags = 113U;
    const signed char tmp_msg_0[] = {31, -74, -90, -51, -12, 73, 22, 58, 88, -50, -120, -45, 34, -116, 111, 96, -12, 94, 6, 118, 27, 85, -116, 109, -78, 94, 126, 23, 93, 1, 93, 34, -56, 67, 50, -5, -55, -62, -47, -93, -39, 101, -73, 66, -60, 62, -103, 86, -89, -79, -83, -119, -39, -127, -4, 36, -59, -107, -109, -103, 81, 20, 33, 0, 76, 72, 5, -35, 105, -120, -118, 88, 9, 38, -37, 106, -16, -54, 80, -61, 95, 77, -120, -37, -85, -47, -42, -22, 22, -39, 92, 125, -1, -58, 54, -123, 46, -31, 11, 89, -114, -97, 53, -43, 9, 80, 124, -116, -32, -27, -103, 11, -94, 56, -4, 55, -122, -32, 43, 111, 3, 88, -114, -58, -87, -58, 28, -28, -128, 87, 107, 50, -83, 121, -25, -86, -43, 85, -114, 121, 83, -22, -121, 5, -109, 66, -19, -21, 30, 101, -78, -68, -14, 34, -31, -78, 14, 62, 107, 113, 121, 67, 109, 90, -116, -29, 126, 29, 66, 120, 84, 2, 59, -121, 122, -21, 8, -126, -24, -28, 25, -99, 75, 66, 81, 35};
    msg.data.assign(tmp_msg_0, tmp_msg_0 + sizeof(tmp_msg_0));

    try
    {
      Utils::ByteBuffer bfr;
      IMC::Packet::serialize(&msg, bfr);
      IMC::Message* msg_d = IMC::Packet::deserialize(bfr.getBuffer(), bfr.getSize());
      test.boolean("SimAcousticMessage #1", msg == *msg_d);
      delete msg_d;
    }
    catch (IMC::InvalidMessageSize& e)
    {
      (void)e;
      test.boolean("msg #1", msg.getSerializationSize() > DUNE_IMC_CONST_MAX_SIZE);
    }
  }

  {
    IMC::SimAcousticMessage msg;
    msg.setTimeStamp(0.6392712395040268);
    msg.setSource(45248U);
    msg.setSourceEntity(223U);
    msg.setDestination(56842U);
    msg.setDestinationEntity(0U);
    msg.lat = 0.9067815372759906;
    msg.lon = 0.5196111803025898;
    msg.depth = 0.7662053921554821;
    msg.sentence.assign("ZTBDNIAKWAZKYHGXTQQEABMKEPNVVSCIJOBPQCESDMVHCLUKJURNNBTOCYMSCSNAJSPDOWIBJXAENDXTTVVJIALCGTBOIXYAXPMZBNOGECVIQXDWA");
    msg.txtime = 0.5488104014690828;
    msg.modem_type.assign("PNQOFESRQMFNIBHSAREDPINOSCNJXPKPKOYLVUOVATXEYCZEBLAZWAMYMZRTNDKWJXNWBGPXDPSJHWFDUWODYBCTPVKTEXTTCRHDSWQWQRNEXFIVOVMFBEJAHKITPDLFQLORSISQULHIXMFGWYSABARUZHFYCFYUVIODQMTDJZQZGAOTHLCJWLA");
    msg.sys_src.assign("EGNHAWKZKDCSPVJDLEOMWTPUTHJUJGJXBYLBVYBDTOHWCLYGQSMZDPWRNCMYHFANGNIPODLKKIFTHOLQDENLOZJXVHEUABCIXVYJQFYQRETCTVUUSRMVXQYXHGZGOTNMATRQLUAKNMEGLSJBHPHNESIDRFFIKQZBWSP");
    msg.seq = 37602U;
    msg.sys_dst.assign("YXWHNMZQMTDHTARDTNIIDUTPLVJFUQPCEQZLBEHSFWAOYUDMRUNTKMTFHBGSOCMNPLZKDEQQUYEBMXIDNXLSZKKNYHXCBWXXGPTZFRGVEZWRIZOFCJJQHVBSJPGNJZQIBDYSLOPAKRXKJXFCJAWUBGXAGAZLAMGAJHSHOOYMFPQXEBIJAVQWDGVCLRGOTRLVMSWWS");
    msg.flags = 109U;
    const signed char tmp_msg_0[] = {59, -63, -98, 111, -40, 61, 2, 106, -97, 26, 47, 126, 88, 78, 92, 93, -8, 59, -44, -91, 34, -119, -17, -60, 100, 76, -11, -64, 91, 87, -98, -64, -37, 82, 101, 12, 93, 99, 0, -111, -82, -65, -9, -117, 98, 73, 75, 50, -29, 73, 123, 15, 99, -10, -28, -72, -72, 60, 98, 6, -122, 22, 76, 85, -41, -84, 11, -83, -113, 90, -107, -30, -115, 54, 19, 74, 26, 40, -17, -5, 75, -79, -30, -63, -83, -15, 96, 70};
    msg.data.assign(tmp_msg_0, tmp_msg_0 + sizeof(tmp_msg_0));

    try
    {
      Utils::ByteBuffer bfr;
      IMC::Packet::serialize(&msg, bfr);
      IMC::Message* msg_d = IMC::Packet::deserialize(bfr.getBuffer(), bfr.getSize());
      test.boolean("SimAcousticMessage #2", msg == *msg_d);
      delete msg_d;
    }
    catch (IMC::InvalidMessageSize& e)
    {
      (void)e;
      test.boolean("msg #2", msg.getSerializationSize() > DUNE_IMC_CONST_MAX_SIZE);
    }
  }

  {
    IMC::AcousticOperation msg;
    msg.setTimeStamp(0.05759954648142729);
    msg.setSource(64460U);
    msg.setSourceEntity(143U);
    msg.setDestination(13884U);
    msg.setDestinationEntity(14U);
    msg.op = 87U;
    msg.system.assign("FPINDMXSDXUEHKMEVSSCSZVACXJJAEIKTVGOKJQUFTHQFEMDGLGLLCWDHAVSQCUAUPXCGAMFWJNYUWEZBIZSXUDKOPYRBQOLTQLREFBHVIFBU");
    msg.range = 0.4490078814441345;
    IMC::Current tmp_msg_0;
    tmp_msg_0.value = 0.2638848937951048;
    msg.msg.set(tmp_msg_0);

    try
    {
      Utils::ByteBuffer bfr;
      IMC::Packet::serialize(&msg, bfr);
      IMC::Message* msg_d = IMC::Packet::deserialize(bfr.getBuffer(), bfr.getSize());
      test.boolean("AcousticOperation #0", msg == *msg_d);
      delete msg_d;
    }
    catch (IMC::InvalidMessageSize& e)
    {
      (void)e;
      test.boolean("msg #0", msg.getSerializationSize() > DUNE_IMC_CONST_MAX_SIZE);
    }
  }

  {
    IMC::AcousticOperation msg;
    msg.setTimeStamp(0.9230191321685749);
    msg.setSource(27585U);
    msg.setSourceEntity(119U);
    msg.setDestination(3655U);
    msg.setDestinationEntity(161U);
    msg.op = 155U;
    msg.system.assign("RNQIAXPXBLSHSCSEWFADPZJMQNYDUTJQSYWWUBFMOEWMYDJZDKVDOZACXCXZT");
    msg.range = 0.733657578679455;
    IMC::SoiCommand tmp_msg_0;
    tmp_msg_0.type = 44U;
    tmp_msg_0.command = 45U;
    tmp_msg_0.settings.assign("QTAESNLYCZRMXGCKBXHJUKQOOYYUTPCUCALMKPPTEBPUBODILIVOYPEVKZQEMGTQEYUTVHLMZNFMMNBYFUIWRJLHQCXSXXQJVORQKADZDBRQOHBVJNKIMWJJPPNDLZKYBOSTWREGDDNWDCRLGVUARJFOWNTFUXXMPVIASZFHNRPUQZNVZBS");
    IMC::SoiPlan tmp_tmp_msg_0_0;
    tmp_tmp_msg_0_0.plan_id = 49474U;
    IMC::SoiWaypoint tmp_tmp_tmp_msg_0_0_0;
    tmp_tmp_tmp_msg_0_0_0.lat = 0.40379574649025995;
    tmp_tmp_tmp_msg_0_0_0.lon = 0.059628464589797314;
    tmp_tmp_tmp_msg_0_0_0.eta = 1154057880U;
    tmp_tmp_tmp_msg_0_0_0.duration = 11869U;
    tmp_tmp_msg_0_0.waypoints.push_back(tmp_tmp_tmp_msg_0_0_0);
    tmp_msg_0.plan.set(tmp_tmp_msg_0_0);
    tmp_msg_0.info.assign("EFODUCRBSXQCITELWMVUBNXNZHXSIWDOUZ");
    msg.msg.set(tmp_msg_0);

    try
    {
      Utils::ByteBuffer bfr;
      IMC::Packet::serialize(&msg, bfr);
      IMC::Message* msg_d = IMC::Packet::deserialize(bfr.getBuffer(), bfr.getSize());
      test.boolean("AcousticOperation #1", msg == *msg_d);
      delete msg_d;
    }
    catch (IMC::InvalidMessageSize& e)
    {
      (void)e;
      test.boolean("msg #1", msg.getSerializationSize() > DUNE_IMC_CONST_MAX_SIZE);
    }
  }

  {
    IMC::AcousticOperation msg;
    msg.setTimeStamp(0.04847802286878622);
    msg.setSource(25271U);
    msg.setSourceEntity(88U);
    msg.setDestination(41410U);
    msg.setDestinationEntity(193U);
    msg.op = 115U;
    msg.system.assign("XLTKYDZIIAHBIAGEXQNTZOUXNZYEHBOCGUAMRVIHUP");
    msg.range = 0.33420819943002367;
    IMC::FormationMonitor tmp_msg_0;
    tmp_msg_0.ax_cmd = 0.659033211665917;
    tmp_msg_0.ay_cmd = 0.8005867459789646;
    tmp_msg_0.az_cmd = 0.49322849565902216;
    tmp_msg_0.ax_des = 0.16804496669470126;
    tmp_msg_0.ay_des = 0.48003598271522663;
    tmp_msg_0.az_des = 0.6233543443501415;
    tmp_msg_0.virt_err_x = 0.014427892961493716;
    tmp_msg_0.virt_err_y = 0.33068038071634753;
    tmp_msg_0.virt_err_z = 0.9272227752115298;
    tmp_msg_0.surf_fdbk_x = 0.30070084165162014;
    tmp_msg_0.surf_fdbk_y = 0.5117005027440268;
    tmp_msg_0.surf_fdbk_z = 0.5790974438552419;
    tmp_msg_0.surf_unkn_x = 0.18364289786107701;
    tmp_msg_0.surf_unkn_y = 0.0033069359555152333;
    tmp_msg_0.surf_unkn_z = 0.48875625958331603;
    tmp_msg_0.ss_x = 0.5888054241916244;
    tmp_msg_0.ss_y = 0.6532083409318707;
    tmp_msg_0.ss_z = 0.6783434320437194;
    IMC::RelativeState tmp_tmp_msg_0_0;
    tmp_tmp_msg_0_0.s_id.assign("OWYQUYOPGJLJXRPURVSZVDTLNLLNYFOYDALFQWCPFWIMWGAFTOTIASVJ");
    tmp_tmp_msg_0_0.dist = 0.008037263118685356;
    tmp_tmp_msg_0_0.err = 0.9351716005859957;
    tmp_tmp_msg_0_0.ctrl_imp = 0.4206814994025172;
    tmp_tmp_msg_0_0.rel_dir_x = 0.5375140033928897;
    tmp_tmp_msg_0_0.rel_dir_y = 0.5927759883285199;
    tmp_tmp_msg_0_0.rel_dir_z = 0.8943977172302916;
    tmp_tmp_msg_0_0.err_x = 0.3569267038005589;
    tmp_tmp_msg_0_0.err_y = 0.6340786775269277;
    tmp_tmp_msg_0_0.err_z = 0.7205689433701253;
    tmp_tmp_msg_0_0.rf_err_x = 0.8288074197817471;
    tmp_tmp_msg_0_0.rf_err_y = 0.8192665151069213;
    tmp_tmp_msg_0_0.rf_err_z = 0.728801698201892;
    tmp_tmp_msg_0_0.rf_err_vx = 0.2601724682226857;
    tmp_tmp_msg_0_0.rf_err_vy = 0.0454533606215074;
    tmp_tmp_msg_0_0.rf_err_vz = 0.8694423706686891;
    tmp_tmp_msg_0_0.ss_x = 0.8580949467373213;
    tmp_tmp_msg_0_0.ss_y = 0.5459380117282217;
    tmp_tmp_msg_0_0.ss_z = 0.15188783600463018;
    tmp_tmp_msg_0_0.virt_err_x = 0.23470419477843119;
    tmp_tmp_msg_0_0.virt_err_y = 0.955648905354638;
    tmp_tmp_msg_0_0.virt_err_z = 0.7078983843289246;
    tmp_msg_0.rel_state.push_back(tmp_tmp_msg_0_0);
    msg.msg.set(tmp_msg_0);

    try
    {
      Utils::ByteBuffer bfr;
      IMC::Packet::serialize(&msg, bfr);
      IMC::Message* msg_d = IMC::Packet::deserialize(bfr.getBuffer(), bfr.getSize());
      test.boolean("AcousticOperation #2", msg == *msg_d);
      delete msg_d;
    }
    catch (IMC::InvalidMessageSize& e)
    {
      (void)e;
      test.boolean("msg #2", msg.getSerializationSize() > DUNE_IMC_CONST_MAX_SIZE);
    }
  }

  {
    IMC::AcousticSystemsQuery msg;
    msg.setTimeStamp(0.14522306258397288);
    msg.setSource(14427U);
    msg.setSourceEntity(97U);
    msg.setDestination(15995U);
    msg.setDestinationEntity(209U);

    try
    {
      Utils::ByteBuffer bfr;
      IMC::Packet::serialize(&msg, bfr);
      IMC::Message* msg_d = IMC::Packet::deserialize(bfr.getBuffer(), bfr.getSize());
      test.boolean("AcousticSystemsQuery #0", msg == *msg_d);
      delete msg_d;
    }
    catch (IMC::InvalidMessageSize& e)
    {
      (void)e;
      test.boolean("msg #0", msg.getSerializationSize() > DUNE_IMC_CONST_MAX_SIZE);
    }
  }

  {
    IMC::AcousticSystemsQuery msg;
    msg.setTimeStamp(0.8478377857215884);
    msg.setSource(11239U);
    msg.setSourceEntity(35U);
    msg.setDestination(7245U);
    msg.setDestinationEntity(80U);

    try
    {
      Utils::ByteBuffer bfr;
      IMC::Packet::serialize(&msg, bfr);
      IMC::Message* msg_d = IMC::Packet::deserialize(bfr.getBuffer(), bfr.getSize());
      test.boolean("AcousticSystemsQuery #1", msg == *msg_d);
      delete msg_d;
    }
    catch (IMC::InvalidMessageSize& e)
    {
      (void)e;
      test.boolean("msg #1", msg.getSerializationSize() > DUNE_IMC_CONST_MAX_SIZE);
    }
  }

  {
    IMC::AcousticSystemsQuery msg;
    msg.setTimeStamp(0.3464312210587769);
    msg.setSource(41349U);
    msg.setSourceEntity(4U);
    msg.setDestination(30782U);
    msg.setDestinationEntity(36U);

    try
    {
      Utils::ByteBuffer bfr;
      IMC::Packet::serialize(&msg, bfr);
      IMC::Message* msg_d = IMC::Packet::deserialize(bfr.getBuffer(), bfr.getSize());
      test.boolean("AcousticSystemsQuery #2", msg == *msg_d);
      delete msg_d;
    }
    catch (IMC::InvalidMessageSize& e)
    {
      (void)e;
      test.boolean("msg #2", msg.getSerializationSize() > DUNE_IMC_CONST_MAX_SIZE);
    }
  }

  {
    IMC::AcousticSystems msg;
    msg.setTimeStamp(0.8702084327726902);
    msg.setSource(52151U);
    msg.setSourceEntity(124U);
    msg.setDestination(19357U);
    msg.setDestinationEntity(74U);
    msg.list.assign("QVRMXXTFJSMPETPZQXHGOSSGZQIOOCIBMUUFNEKMEUOLLQAAGSWXFSGQMAULVCCJYNCXWUKHQRXLEVYPAZCNXEHKRYID");

    try
    {
      Utils::ByteBuffer bfr;
      IMC::Packet::serialize(&msg, bfr);
      IMC::Message* msg_d = IMC::Packet::deserialize(bfr.getBuffer(), bfr.getSize());
      test.boolean("AcousticSystems #0", msg == *msg_d);
      delete msg_d;
    }
    catch (IMC::InvalidMessageSize& e)
    {
      (void)e;
      test.boolean("msg #0", msg.getSerializationSize() > DUNE_IMC_CONST_MAX_SIZE);
    }
  }

  {
    IMC::AcousticSystems msg;
    msg.setTimeStamp(0.29042777064592407);
    msg.setSource(42151U);
    msg.setSourceEntity(143U);
    msg.setDestination(40791U);
    msg.setDestinationEntity(38U);
    msg.list.assign("AGWWLOXXHIOAEBCWBKJZPVYKJZUVONXNPUZVAN");

    try
    {
      Utils::ByteBuffer bfr;
      IMC::Packet::serialize(&msg, bfr);
      IMC::Message* msg_d = IMC::Packet::deserialize(bfr.getBuffer(), bfr.getSize());
      test.boolean("AcousticSystems #1", msg == *msg_d);
      delete msg_d;
    }
    catch (IMC::InvalidMessageSize& e)
    {
      (void)e;
      test.boolean("msg #1", msg.getSerializationSize() > DUNE_IMC_CONST_MAX_SIZE);
    }
  }

  {
    IMC::AcousticSystems msg;
    msg.setTimeStamp(0.551484111732995);
    msg.setSource(57303U);
    msg.setSourceEntity(253U);
    msg.setDestination(50670U);
    msg.setDestinationEntity(141U);
    msg.list.assign("KWFTGLTJZBHOEYMGZXKWVTMJYRDZNBBBPVIRFCYDMGVQTOTQJGKLWUNXZSSYUIXEGGUDTUQLQSYVEJAPDNSQLURIHVUORGDVQMAYYWWZAKIALPJZUSZZBVHGPFWCWVCTJMIHJOKCMSVOKSXRDNFDXJFYNXPIIHEBJDWRRSNXRPOKEMNPKUMHIALYVODUACAWLTNOHQXXBPCLEINQSZENSQMEHE");

    try
    {
      Utils::ByteBuffer bfr;
      IMC::Packet::serialize(&msg, bfr);
      IMC::Message* msg_d = IMC::Packet::deserialize(bfr.getBuffer(), bfr.getSize());
      test.boolean("AcousticSystems #2", msg == *msg_d);
      delete msg_d;
    }
    catch (IMC::InvalidMessageSize& e)
    {
      (void)e;
      test.boolean("msg #2", msg.getSerializationSize() > DUNE_IMC_CONST_MAX_SIZE);
    }
  }

  {
    IMC::AcousticLink msg;
    msg.setTimeStamp(0.35082057574634673);
    msg.setSource(30469U);
    msg.setSourceEntity(212U);
    msg.setDestination(38880U);
    msg.setDestinationEntity(123U);
    msg.peer.assign("QXJHQLRWLBSHOAKBQOMIUCGSU");
    msg.rssi = 0.9789558815590427;
    msg.integrity = 1351U;

    try
    {
      Utils::ByteBuffer bfr;
      IMC::Packet::serialize(&msg, bfr);
      IMC::Message* msg_d = IMC::Packet::deserialize(bfr.getBuffer(), bfr.getSize());
      test.boolean("AcousticLink #0", msg == *msg_d);
      delete msg_d;
    }
    catch (IMC::InvalidMessageSize& e)
    {
      (void)e;
      test.boolean("msg #0", msg.getSerializationSize() > DUNE_IMC_CONST_MAX_SIZE);
    }
  }

  {
    IMC::AcousticLink msg;
    msg.setTimeStamp(0.03516672600307569);
    msg.setSource(58744U);
    msg.setSourceEntity(144U);
    msg.setDestination(39124U);
    msg.setDestinationEntity(228U);
    msg.peer.assign("PIQZBUDTWBSNHEOBWLNPASGEGKHRPQZSBDDGJTSJENXAQFIRKXFFTEJYAFJEQWRZIXFMDDIBUODVYDKJHOCRRYXMZANPZGXOSYKUUFLIZWRFQOTIOESRQXQAGWCIPIVGKHYVMJGHBMAWOPNYKOUNCQWVCFVRLUVKTLAMOSKELWXCWHUVILNZCPPJHQMXDBVCZCEBGLUUYJUMAFGNJBTGAXMLDVTWECRZMHMIDSKHXFOCSZTNNYAS");
    msg.rssi = 0.9676914886893547;
    msg.integrity = 20734U;

    try
    {
      Utils::ByteBuffer bfr;
      IMC::Packet::serialize(&msg, bfr);
      IMC::Message* msg_d = IMC::Packet::deserialize(bfr.getBuffer(), bfr.getSize());
      test.boolean("AcousticLink #1", msg == *msg_d);
      delete msg_d;
    }
    catch (IMC::InvalidMessageSize& e)
    {
      (void)e;
      test.boolean("msg #1", msg.getSerializationSize() > DUNE_IMC_CONST_MAX_SIZE);
    }
  }

  {
    IMC::AcousticLink msg;
    msg.setTimeStamp(0.18111928537438848);
    msg.setSource(58113U);
    msg.setSourceEntity(38U);
    msg.setDestination(8457U);
    msg.setDestinationEntity(3U);
    msg.peer.assign("LUCHFYPRZMKEIHHHSPOGBMNRYKQSXKRSLOWXTPTFDIMTZKVFXSCCEVMSWHHLWOAJMADOFASRBQEWGWCDMHEUAOYUNYIPXCXRIPNONJFVGEJKZYMGZBPWJTDHLWNBRKEI");
    msg.rssi = 0.806612036470586;
    msg.integrity = 35332U;

    try
    {
      Utils::ByteBuffer bfr;
      IMC::Packet::serialize(&msg, bfr);
      IMC::Message* msg_d = IMC::Packet::deserialize(bfr.getBuffer(), bfr.getSize());
      test.boolean("AcousticLink #2", msg == *msg_d);
      delete msg_d;
    }
    catch (IMC::InvalidMessageSize& e)
    {
      (void)e;
      test.boolean("msg #2", msg.getSerializationSize() > DUNE_IMC_CONST_MAX_SIZE);
    }
  }

  {
    IMC::AcousticRequest msg;
    msg.setTimeStamp(0.5036248852379621);
    msg.setSource(57070U);
    msg.setSourceEntity(6U);
    msg.setDestination(23823U);
    msg.setDestinationEntity(163U);
    msg.req_id = 31400U;
    msg.destination.assign("GESGRZIVEWPOZLWQGRPSVJTRFHVNIDKMRPBQEYGTODXHSFKVHKMAWCUUUIPQAZEMKDDCYLMPSOSNYECLXBNIDVGRWGTCFJISTDRFHWAANLDQSZXGVVBQJIKJEBRQECNTAUFORUPBYALJMLITTUBUHQPXFXVTGSOZYLLEDKEDZJLOFNVPYHZSRPJTYJQ");
    msg.timeout = 0.5303466458046472;
    msg.range = 0.9603374718948299;
    msg.type = 171U;
    IMC::FollowReference tmp_msg_0;
    tmp_msg_0.control_src = 35973U;
    tmp_msg_0.control_ent = 78U;
    tmp_msg_0.timeout = 0.24769106089497095;
    tmp_msg_0.loiter_radius = 0.3912870797262741;
    tmp_msg_0.altitude_interval = 0.24326625222320197;
    msg.msg.set(tmp_msg_0);

    try
    {
      Utils::ByteBuffer bfr;
      IMC::Packet::serialize(&msg, bfr);
      IMC::Message* msg_d = IMC::Packet::deserialize(bfr.getBuffer(), bfr.getSize());
      test.boolean("AcousticRequest #0", msg == *msg_d);
      delete msg_d;
    }
    catch (IMC::InvalidMessageSize& e)
    {
      (void)e;
      test.boolean("msg #0", msg.getSerializationSize() > DUNE_IMC_CONST_MAX_SIZE);
    }
  }

  {
    IMC::AcousticRequest msg;
    msg.setTimeStamp(0.7619122439549717);
    msg.setSource(63176U);
    msg.setSourceEntity(213U);
    msg.setDestination(9893U);
    msg.setDestinationEntity(75U);
    msg.req_id = 55507U;
    msg.destination.assign("KSEPCYKUTC");
    msg.timeout = 0.9891079268299491;
    msg.range = 0.54971837006607;
    msg.type = 150U;
    IMC::DesiredPitch tmp_msg_0;
    tmp_msg_0.value = 0.5873775950415379;
    msg.msg.set(tmp_msg_0);

    try
    {
      Utils::ByteBuffer bfr;
      IMC::Packet::serialize(&msg, bfr);
      IMC::Message* msg_d = IMC::Packet::deserialize(bfr.getBuffer(), bfr.getSize());
      test.boolean("AcousticRequest #1", msg == *msg_d);
      delete msg_d;
    }
    catch (IMC::InvalidMessageSize& e)
    {
      (void)e;
      test.boolean("msg #1", msg.getSerializationSize() > DUNE_IMC_CONST_MAX_SIZE);
    }
  }

  {
    IMC::AcousticRequest msg;
    msg.setTimeStamp(0.12666571928680548);
    msg.setSource(9164U);
    msg.setSourceEntity(82U);
    msg.setDestination(54119U);
    msg.setDestinationEntity(4U);
    msg.req_id = 48429U;
    msg.destination.assign("XZQPQQRZRYUQIGSTYYRBLPGMFEUZQEFHDDIZFWBWYAGTVPHVUVHCJESJAMXVHZQNL");
    msg.timeout = 0.02216475642778659;
    msg.range = 0.09196297154427935;
    msg.type = 77U;
    IMC::CloseSession tmp_msg_0;
    tmp_msg_0.sessid = 4275716911U;
    msg.msg.set(tmp_msg_0);

    try
    {
      Utils::ByteBuffer bfr;
      IMC::Packet::serialize(&msg, bfr);
      IMC::Message* msg_d = IMC::Packet::deserialize(bfr.getBuffer(), bfr.getSize());
      test.boolean("AcousticRequest #2", msg == *msg_d);
      delete msg_d;
    }
    catch (IMC::InvalidMessageSize& e)
    {
      (void)e;
      test.boolean("msg #2", msg.getSerializationSize() > DUNE_IMC_CONST_MAX_SIZE);
    }
  }

  {
    IMC::AcousticStatus msg;
    msg.setTimeStamp(0.5662147018243036);
    msg.setSource(56844U);
    msg.setSourceEntity(157U);
    msg.setDestination(29699U);
    msg.setDestinationEntity(29U);
    msg.req_id = 45931U;
    msg.type = 70U;
    msg.status = 209U;
    msg.info.assign("MZQNHOXVGGNCAQQNRIKGIVEPLVQUPXHPSRXLDNVBAKTLAMRKFXPOHBUPQFVMTRTVZLBOBHGOOUYQNTCAXXKPCSJOBWYJQTDFCZFGFIANFZOWXSCHWMIGXORJCZESSMYEJFTUDUORHMHREKWTKMZLJIWDLILJVHRZKDYEZAGYUYFDAXGCLCZUYHCMNEIIHDPEDSWNQCEDMUVSIMTWSJWYEPSTWUBKABERYWSGKPRKVFVBI");
    msg.range = 0.6396104685638363;

    try
    {
      Utils::ByteBuffer bfr;
      IMC::Packet::serialize(&msg, bfr);
      IMC::Message* msg_d = IMC::Packet::deserialize(bfr.getBuffer(), bfr.getSize());
      test.boolean("AcousticStatus #0", msg == *msg_d);
      delete msg_d;
    }
    catch (IMC::InvalidMessageSize& e)
    {
      (void)e;
      test.boolean("msg #0", msg.getSerializationSize() > DUNE_IMC_CONST_MAX_SIZE);
    }
  }

  {
    IMC::AcousticStatus msg;
    msg.setTimeStamp(0.42589121771060856);
    msg.setSource(48455U);
    msg.setSourceEntity(192U);
    msg.setDestination(55627U);
    msg.setDestinationEntity(2U);
    msg.req_id = 15289U;
    msg.type = 123U;
    msg.status = 65U;
    msg.info.assign("LLFVEQATJIPA");
    msg.range = 0.5918723290459144;

    try
    {
      Utils::ByteBuffer bfr;
      IMC::Packet::serialize(&msg, bfr);
      IMC::Message* msg_d = IMC::Packet::deserialize(bfr.getBuffer(), bfr.getSize());
      test.boolean("AcousticStatus #1", msg == *msg_d);
      delete msg_d;
    }
    catch (IMC::InvalidMessageSize& e)
    {
      (void)e;
      test.boolean("msg #1", msg.getSerializationSize() > DUNE_IMC_CONST_MAX_SIZE);
    }
  }

  {
    IMC::AcousticStatus msg;
    msg.setTimeStamp(0.10729177460152628);
    msg.setSource(39055U);
    msg.setSourceEntity(144U);
    msg.setDestination(17715U);
    msg.setDestinationEntity(144U);
    msg.req_id = 2390U;
    msg.type = 226U;
    msg.status = 104U;
    msg.info.assign("GJKCDRYEGLUKDCDTUZZPVSDYEDRMXTHZUAYL");
    msg.range = 0.8571500054731251;

    try
    {
      Utils::ByteBuffer bfr;
      IMC::Packet::serialize(&msg, bfr);
      IMC::Message* msg_d = IMC::Packet::deserialize(bfr.getBuffer(), bfr.getSize());
      test.boolean("AcousticStatus #2", msg == *msg_d);
      delete msg_d;
    }
    catch (IMC::InvalidMessageSize& e)
    {
      (void)e;
      test.boolean("msg #2", msg.getSerializationSize() > DUNE_IMC_CONST_MAX_SIZE);
    }
  }

  {
    IMC::AcousticRelease msg;
    msg.setTimeStamp(0.8542047586147843);
    msg.setSource(20412U);
    msg.setSourceEntity(12U);
    msg.setDestination(11480U);
    msg.setDestinationEntity(167U);
    msg.system.assign("JZBLBOTJVPWGYOESALKXAIAAJNWMFZXWTIUGXDHMKISNFEORHKMKFHRUUDLIUZDKNMDDPQADXXWJYVCMBTCVFFDAQIPNHJJBOOPTLSZCJUEQNPPLCRTKVYEJEBHAVCZWCSQYLBYRKIBZDVNUQUZQM");
    msg.op = 153U;

    try
    {
      Utils::ByteBuffer bfr;
      IMC::Packet::serialize(&msg, bfr);
      IMC::Message* msg_d = IMC::Packet::deserialize(bfr.getBuffer(), bfr.getSize());
      test.boolean("AcousticRelease #0", msg == *msg_d);
      delete msg_d;
    }
    catch (IMC::InvalidMessageSize& e)
    {
      (void)e;
      test.boolean("msg #0", msg.getSerializationSize() > DUNE_IMC_CONST_MAX_SIZE);
    }
  }

  {
    IMC::AcousticRelease msg;
    msg.setTimeStamp(0.0026430510795830697);
    msg.setSource(38974U);
    msg.setSourceEntity(245U);
    msg.setDestination(55286U);
    msg.setDestinationEntity(42U);
    msg.system.assign("LHYMJXYRQJOSRDFHHOKCHWBKQSPDAIWFCPILUAZDTYWBMBXCQANKYSTCAUZHARZWCSQXJATEQUKLLLWZUPEFRVCJXXRTGZKVVFIWMQTNZSJG");
    msg.op = 238U;

    try
    {
      Utils::ByteBuffer bfr;
      IMC::Packet::serialize(&msg, bfr);
      IMC::Message* msg_d = IMC::Packet::deserialize(bfr.getBuffer(), bfr.getSize());
      test.boolean("AcousticRelease #1", msg == *msg_d);
      delete msg_d;
    }
    catch (IMC::InvalidMessageSize& e)
    {
      (void)e;
      test.boolean("msg #1", msg.getSerializationSize() > DUNE_IMC_CONST_MAX_SIZE);
    }
  }

  {
    IMC::AcousticRelease msg;
    msg.setTimeStamp(0.4312306566057824);
    msg.setSource(7449U);
    msg.setSourceEntity(242U);
    msg.setDestination(45673U);
    msg.setDestinationEntity(68U);
    msg.system.assign("TMEJTUDTSIWILXGRMEWBWRNYADANDOPHUSXIYSIXPGMZZZYNXIIMPYUPSCQNHAQLUPCTLNRGROULIGZLEJFOVDJWKLCPALMUWTQONLFFCLYWPTCLPEUGQVDZXCXTRGYQKMKZHXFXECODFOAVSNXRYQQHOMZAHYBJTJHMSBVSEJWKWDBPEMVVO");
    msg.op = 127U;

    try
    {
      Utils::ByteBuffer bfr;
      IMC::Packet::serialize(&msg, bfr);
      IMC::Message* msg_d = IMC::Packet::deserialize(bfr.getBuffer(), bfr.getSize());
      test.boolean("AcousticRelease #2", msg == *msg_d);
      delete msg_d;
    }
    catch (IMC::InvalidMessageSize& e)
    {
      (void)e;
      test.boolean("msg #2", msg.getSerializationSize() > DUNE_IMC_CONST_MAX_SIZE);
    }
  }

  {
    IMC::Rpm msg;
    msg.setTimeStamp(0.7024353103440056);
    msg.setSource(52008U);
    msg.setSourceEntity(79U);
    msg.setDestination(8770U);
    msg.setDestinationEntity(153U);
    msg.value = -21202;

    try
    {
      Utils::ByteBuffer bfr;
      IMC::Packet::serialize(&msg, bfr);
      IMC::Message* msg_d = IMC::Packet::deserialize(bfr.getBuffer(), bfr.getSize());
      test.boolean("Rpm #0", msg == *msg_d);
      delete msg_d;
    }
    catch (IMC::InvalidMessageSize& e)
    {
      (void)e;
      test.boolean("msg #0", msg.getSerializationSize() > DUNE_IMC_CONST_MAX_SIZE);
    }
  }

  {
    IMC::Rpm msg;
    msg.setTimeStamp(0.11761981188978232);
    msg.setSource(11007U);
    msg.setSourceEntity(196U);
    msg.setDestination(2388U);
    msg.setDestinationEntity(29U);
    msg.value = -7746;

    try
    {
      Utils::ByteBuffer bfr;
      IMC::Packet::serialize(&msg, bfr);
      IMC::Message* msg_d = IMC::Packet::deserialize(bfr.getBuffer(), bfr.getSize());
      test.boolean("Rpm #1", msg == *msg_d);
      delete msg_d;
    }
    catch (IMC::InvalidMessageSize& e)
    {
      (void)e;
      test.boolean("msg #1", msg.getSerializationSize() > DUNE_IMC_CONST_MAX_SIZE);
    }
  }

  {
    IMC::Rpm msg;
    msg.setTimeStamp(0.3355211875717541);
    msg.setSource(58690U);
    msg.setSourceEntity(108U);
    msg.setDestination(65386U);
    msg.setDestinationEntity(162U);
    msg.value = -3919;

    try
    {
      Utils::ByteBuffer bfr;
      IMC::Packet::serialize(&msg, bfr);
      IMC::Message* msg_d = IMC::Packet::deserialize(bfr.getBuffer(), bfr.getSize());
      test.boolean("Rpm #2", msg == *msg_d);
      delete msg_d;
    }
    catch (IMC::InvalidMessageSize& e)
    {
      (void)e;
      test.boolean("msg #2", msg.getSerializationSize() > DUNE_IMC_CONST_MAX_SIZE);
    }
  }

  {
    IMC::Voltage msg;
    msg.setTimeStamp(0.936149756505039);
    msg.setSource(21835U);
    msg.setSourceEntity(221U);
    msg.setDestination(22210U);
    msg.setDestinationEntity(185U);
    msg.value = 0.8840413595652915;

    try
    {
      Utils::ByteBuffer bfr;
      IMC::Packet::serialize(&msg, bfr);
      IMC::Message* msg_d = IMC::Packet::deserialize(bfr.getBuffer(), bfr.getSize());
      test.boolean("Voltage #0", msg == *msg_d);
      delete msg_d;
    }
    catch (IMC::InvalidMessageSize& e)
    {
      (void)e;
      test.boolean("msg #0", msg.getSerializationSize() > DUNE_IMC_CONST_MAX_SIZE);
    }
  }

  {
    IMC::Voltage msg;
    msg.setTimeStamp(0.919929271674944);
    msg.setSource(54070U);
    msg.setSourceEntity(79U);
    msg.setDestination(32909U);
    msg.setDestinationEntity(43U);
    msg.value = 0.37399973465628655;

    try
    {
      Utils::ByteBuffer bfr;
      IMC::Packet::serialize(&msg, bfr);
      IMC::Message* msg_d = IMC::Packet::deserialize(bfr.getBuffer(), bfr.getSize());
      test.boolean("Voltage #1", msg == *msg_d);
      delete msg_d;
    }
    catch (IMC::InvalidMessageSize& e)
    {
      (void)e;
      test.boolean("msg #1", msg.getSerializationSize() > DUNE_IMC_CONST_MAX_SIZE);
    }
  }

  {
    IMC::Voltage msg;
    msg.setTimeStamp(0.008690569261018743);
    msg.setSource(14683U);
    msg.setSourceEntity(113U);
    msg.setDestination(32254U);
    msg.setDestinationEntity(89U);
    msg.value = 0.1679639221023964;

    try
    {
      Utils::ByteBuffer bfr;
      IMC::Packet::serialize(&msg, bfr);
      IMC::Message* msg_d = IMC::Packet::deserialize(bfr.getBuffer(), bfr.getSize());
      test.boolean("Voltage #2", msg == *msg_d);
      delete msg_d;
    }
    catch (IMC::InvalidMessageSize& e)
    {
      (void)e;
      test.boolean("msg #2", msg.getSerializationSize() > DUNE_IMC_CONST_MAX_SIZE);
    }
  }

  {
    IMC::Current msg;
    msg.setTimeStamp(0.5373951864726805);
    msg.setSource(47889U);
    msg.setSourceEntity(153U);
    msg.setDestination(30677U);
    msg.setDestinationEntity(86U);
    msg.value = 0.4495497256293963;

    try
    {
      Utils::ByteBuffer bfr;
      IMC::Packet::serialize(&msg, bfr);
      IMC::Message* msg_d = IMC::Packet::deserialize(bfr.getBuffer(), bfr.getSize());
      test.boolean("Current #0", msg == *msg_d);
      delete msg_d;
    }
    catch (IMC::InvalidMessageSize& e)
    {
      (void)e;
      test.boolean("msg #0", msg.getSerializationSize() > DUNE_IMC_CONST_MAX_SIZE);
    }
  }

  {
    IMC::Current msg;
    msg.setTimeStamp(0.6883948664552696);
    msg.setSource(48004U);
    msg.setSourceEntity(114U);
    msg.setDestination(47758U);
    msg.setDestinationEntity(191U);
    msg.value = 0.8333108764866621;

    try
    {
      Utils::ByteBuffer bfr;
      IMC::Packet::serialize(&msg, bfr);
      IMC::Message* msg_d = IMC::Packet::deserialize(bfr.getBuffer(), bfr.getSize());
      test.boolean("Current #1", msg == *msg_d);
      delete msg_d;
    }
    catch (IMC::InvalidMessageSize& e)
    {
      (void)e;
      test.boolean("msg #1", msg.getSerializationSize() > DUNE_IMC_CONST_MAX_SIZE);
    }
  }

  {
    IMC::Current msg;
    msg.setTimeStamp(0.11277455448246876);
    msg.setSource(60450U);
    msg.setSourceEntity(11U);
    msg.setDestination(31893U);
    msg.setDestinationEntity(158U);
    msg.value = 0.5313811054055367;

    try
    {
      Utils::ByteBuffer bfr;
      IMC::Packet::serialize(&msg, bfr);
      IMC::Message* msg_d = IMC::Packet::deserialize(bfr.getBuffer(), bfr.getSize());
      test.boolean("Current #2", msg == *msg_d);
      delete msg_d;
    }
    catch (IMC::InvalidMessageSize& e)
    {
      (void)e;
      test.boolean("msg #2", msg.getSerializationSize() > DUNE_IMC_CONST_MAX_SIZE);
    }
  }

  {
    IMC::GpsFix msg;
    msg.setTimeStamp(0.6644545612535047);
    msg.setSource(56889U);
    msg.setSourceEntity(116U);
    msg.setDestination(20598U);
    msg.setDestinationEntity(9U);
    msg.validity = 31766U;
    msg.type = 156U;
    msg.utc_year = 25742U;
    msg.utc_month = 166U;
    msg.utc_day = 247U;
    msg.utc_time = 0.5305710727570858;
    msg.lat = 0.27771813753931995;
    msg.lon = 0.04908193296608376;
    msg.height = 0.01123992988058553;
    msg.satellites = 254U;
    msg.cog = 0.20404250614797215;
    msg.sog = 0.11725840451857661;
    msg.hdop = 0.1869220301704465;
    msg.vdop = 0.16431555206617976;
    msg.hacc = 0.39541500624731696;
    msg.vacc = 0.617789717539783;

    try
    {
      Utils::ByteBuffer bfr;
      IMC::Packet::serialize(&msg, bfr);
      IMC::Message* msg_d = IMC::Packet::deserialize(bfr.getBuffer(), bfr.getSize());
      test.boolean("GpsFix #0", msg == *msg_d);
      delete msg_d;
    }
    catch (IMC::InvalidMessageSize& e)
    {
      (void)e;
      test.boolean("msg #0", msg.getSerializationSize() > DUNE_IMC_CONST_MAX_SIZE);
    }
  }

  {
    IMC::GpsFix msg;
    msg.setTimeStamp(0.32655444047333604);
    msg.setSource(25241U);
    msg.setSourceEntity(216U);
    msg.setDestination(27618U);
    msg.setDestinationEntity(42U);
    msg.validity = 33987U;
    msg.type = 243U;
    msg.utc_year = 4381U;
    msg.utc_month = 49U;
    msg.utc_day = 98U;
    msg.utc_time = 0.0910278585785177;
    msg.lat = 0.5062825884835831;
    msg.lon = 0.9777355630192854;
    msg.height = 0.6140189754532401;
    msg.satellites = 42U;
    msg.cog = 0.7735631017398041;
    msg.sog = 0.384690424576816;
    msg.hdop = 0.2433287948158258;
    msg.vdop = 0.6417584146924471;
    msg.hacc = 0.5028534080011012;
    msg.vacc = 0.016982241506117712;

    try
    {
      Utils::ByteBuffer bfr;
      IMC::Packet::serialize(&msg, bfr);
      IMC::Message* msg_d = IMC::Packet::deserialize(bfr.getBuffer(), bfr.getSize());
      test.boolean("GpsFix #1", msg == *msg_d);
      delete msg_d;
    }
    catch (IMC::InvalidMessageSize& e)
    {
      (void)e;
      test.boolean("msg #1", msg.getSerializationSize() > DUNE_IMC_CONST_MAX_SIZE);
    }
  }

  {
    IMC::GpsFix msg;
    msg.setTimeStamp(0.45655749313428595);
    msg.setSource(5660U);
    msg.setSourceEntity(203U);
    msg.setDestination(4569U);
    msg.setDestinationEntity(113U);
    msg.validity = 44636U;
    msg.type = 63U;
    msg.utc_year = 25419U;
    msg.utc_month = 228U;
    msg.utc_day = 195U;
    msg.utc_time = 0.7498059545541232;
    msg.lat = 0.952277221776246;
    msg.lon = 0.6622340185373118;
    msg.height = 0.8336511742252282;
    msg.satellites = 124U;
    msg.cog = 0.4408061794617367;
    msg.sog = 0.910669374012472;
    msg.hdop = 0.5427624855069417;
    msg.vdop = 0.7950346567094044;
    msg.hacc = 0.5412267766821957;
    msg.vacc = 0.5011107533002116;

    try
    {
      Utils::ByteBuffer bfr;
      IMC::Packet::serialize(&msg, bfr);
      IMC::Message* msg_d = IMC::Packet::deserialize(bfr.getBuffer(), bfr.getSize());
      test.boolean("GpsFix #2", msg == *msg_d);
      delete msg_d;
    }
    catch (IMC::InvalidMessageSize& e)
    {
      (void)e;
      test.boolean("msg #2", msg.getSerializationSize() > DUNE_IMC_CONST_MAX_SIZE);
    }
  }

  {
    IMC::EulerAngles msg;
    msg.setTimeStamp(0.5059706780133624);
    msg.setSource(12527U);
    msg.setSourceEntity(28U);
    msg.setDestination(29639U);
    msg.setDestinationEntity(68U);
    msg.time = 0.23175413805488;
    msg.phi = 0.4475098562875649;
    msg.theta = 0.46906149082153425;
    msg.psi = 0.716320058699371;
    msg.psi_magnetic = 0.28570074210126095;

    try
    {
      Utils::ByteBuffer bfr;
      IMC::Packet::serialize(&msg, bfr);
      IMC::Message* msg_d = IMC::Packet::deserialize(bfr.getBuffer(), bfr.getSize());
      test.boolean("EulerAngles #0", msg == *msg_d);
      delete msg_d;
    }
    catch (IMC::InvalidMessageSize& e)
    {
      (void)e;
      test.boolean("msg #0", msg.getSerializationSize() > DUNE_IMC_CONST_MAX_SIZE);
    }
  }

  {
    IMC::EulerAngles msg;
    msg.setTimeStamp(0.014802258959654035);
    msg.setSource(42011U);
    msg.setSourceEntity(70U);
    msg.setDestination(6371U);
    msg.setDestinationEntity(34U);
    msg.time = 0.08415108914647285;
    msg.phi = 0.8729280218912794;
    msg.theta = 0.7709896500927098;
    msg.psi = 0.5570597688490424;
    msg.psi_magnetic = 0.18842823953655152;

    try
    {
      Utils::ByteBuffer bfr;
      IMC::Packet::serialize(&msg, bfr);
      IMC::Message* msg_d = IMC::Packet::deserialize(bfr.getBuffer(), bfr.getSize());
      test.boolean("EulerAngles #1", msg == *msg_d);
      delete msg_d;
    }
    catch (IMC::InvalidMessageSize& e)
    {
      (void)e;
      test.boolean("msg #1", msg.getSerializationSize() > DUNE_IMC_CONST_MAX_SIZE);
    }
  }

  {
    IMC::EulerAngles msg;
    msg.setTimeStamp(0.7075459585425461);
    msg.setSource(40432U);
    msg.setSourceEntity(163U);
    msg.setDestination(49033U);
    msg.setDestinationEntity(66U);
    msg.time = 0.5247297259379355;
    msg.phi = 0.19581172194052188;
    msg.theta = 0.5680420902259354;
    msg.psi = 0.4495174919191438;
    msg.psi_magnetic = 0.738672445298608;

    try
    {
      Utils::ByteBuffer bfr;
      IMC::Packet::serialize(&msg, bfr);
      IMC::Message* msg_d = IMC::Packet::deserialize(bfr.getBuffer(), bfr.getSize());
      test.boolean("EulerAngles #2", msg == *msg_d);
      delete msg_d;
    }
    catch (IMC::InvalidMessageSize& e)
    {
      (void)e;
      test.boolean("msg #2", msg.getSerializationSize() > DUNE_IMC_CONST_MAX_SIZE);
    }
  }

  {
    IMC::EulerAnglesDelta msg;
    msg.setTimeStamp(0.17720157860959296);
    msg.setSource(36436U);
    msg.setSourceEntity(102U);
    msg.setDestination(16175U);
    msg.setDestinationEntity(147U);
    msg.time = 0.36265366197536586;
    msg.x = 0.518589403221001;
    msg.y = 0.21699098045593157;
    msg.z = 0.7639371833850986;
    msg.timestep = 0.36408182561361646;

    try
    {
      Utils::ByteBuffer bfr;
      IMC::Packet::serialize(&msg, bfr);
      IMC::Message* msg_d = IMC::Packet::deserialize(bfr.getBuffer(), bfr.getSize());
      test.boolean("EulerAnglesDelta #0", msg == *msg_d);
      delete msg_d;
    }
    catch (IMC::InvalidMessageSize& e)
    {
      (void)e;
      test.boolean("msg #0", msg.getSerializationSize() > DUNE_IMC_CONST_MAX_SIZE);
    }
  }

  {
    IMC::EulerAnglesDelta msg;
    msg.setTimeStamp(0.8391412438655855);
    msg.setSource(39067U);
    msg.setSourceEntity(134U);
    msg.setDestination(27348U);
    msg.setDestinationEntity(228U);
    msg.time = 0.5981665528489534;
    msg.x = 0.6604548389534205;
    msg.y = 0.4274723842712578;
    msg.z = 0.007935448709235127;
    msg.timestep = 0.09760069753089617;

    try
    {
      Utils::ByteBuffer bfr;
      IMC::Packet::serialize(&msg, bfr);
      IMC::Message* msg_d = IMC::Packet::deserialize(bfr.getBuffer(), bfr.getSize());
      test.boolean("EulerAnglesDelta #1", msg == *msg_d);
      delete msg_d;
    }
    catch (IMC::InvalidMessageSize& e)
    {
      (void)e;
      test.boolean("msg #1", msg.getSerializationSize() > DUNE_IMC_CONST_MAX_SIZE);
    }
  }

  {
    IMC::EulerAnglesDelta msg;
    msg.setTimeStamp(0.03991314515062172);
    msg.setSource(1493U);
    msg.setSourceEntity(170U);
    msg.setDestination(41116U);
    msg.setDestinationEntity(178U);
    msg.time = 0.670749591320393;
    msg.x = 0.36784809834253307;
    msg.y = 0.3096799337894647;
    msg.z = 0.37914932579212435;
    msg.timestep = 0.6760444664130961;

    try
    {
      Utils::ByteBuffer bfr;
      IMC::Packet::serialize(&msg, bfr);
      IMC::Message* msg_d = IMC::Packet::deserialize(bfr.getBuffer(), bfr.getSize());
      test.boolean("EulerAnglesDelta #2", msg == *msg_d);
      delete msg_d;
    }
    catch (IMC::InvalidMessageSize& e)
    {
      (void)e;
      test.boolean("msg #2", msg.getSerializationSize() > DUNE_IMC_CONST_MAX_SIZE);
    }
  }

  {
    IMC::AngularVelocity msg;
    msg.setTimeStamp(0.27594668223043983);
    msg.setSource(64271U);
    msg.setSourceEntity(0U);
    msg.setDestination(37722U);
    msg.setDestinationEntity(232U);
    msg.time = 0.7432217221915105;
    msg.x = 0.21845548221704048;
    msg.y = 0.1843931936841633;
    msg.z = 0.04200564509933291;

    try
    {
      Utils::ByteBuffer bfr;
      IMC::Packet::serialize(&msg, bfr);
      IMC::Message* msg_d = IMC::Packet::deserialize(bfr.getBuffer(), bfr.getSize());
      test.boolean("AngularVelocity #0", msg == *msg_d);
      delete msg_d;
    }
    catch (IMC::InvalidMessageSize& e)
    {
      (void)e;
      test.boolean("msg #0", msg.getSerializationSize() > DUNE_IMC_CONST_MAX_SIZE);
    }
  }

  {
    IMC::AngularVelocity msg;
    msg.setTimeStamp(0.07331779721372289);
    msg.setSource(12945U);
    msg.setSourceEntity(236U);
    msg.setDestination(16479U);
    msg.setDestinationEntity(116U);
    msg.time = 0.4362412119277985;
    msg.x = 0.16030903530374374;
    msg.y = 0.4322184019319162;
    msg.z = 0.5244062645668888;

    try
    {
      Utils::ByteBuffer bfr;
      IMC::Packet::serialize(&msg, bfr);
      IMC::Message* msg_d = IMC::Packet::deserialize(bfr.getBuffer(), bfr.getSize());
      test.boolean("AngularVelocity #1", msg == *msg_d);
      delete msg_d;
    }
    catch (IMC::InvalidMessageSize& e)
    {
      (void)e;
      test.boolean("msg #1", msg.getSerializationSize() > DUNE_IMC_CONST_MAX_SIZE);
    }
  }

  {
    IMC::AngularVelocity msg;
    msg.setTimeStamp(0.8768808480821026);
    msg.setSource(32114U);
    msg.setSourceEntity(188U);
    msg.setDestination(53079U);
    msg.setDestinationEntity(101U);
    msg.time = 0.035326577526916814;
    msg.x = 0.8147269771028608;
    msg.y = 0.053705557030730766;
    msg.z = 0.6791381347433562;

    try
    {
      Utils::ByteBuffer bfr;
      IMC::Packet::serialize(&msg, bfr);
      IMC::Message* msg_d = IMC::Packet::deserialize(bfr.getBuffer(), bfr.getSize());
      test.boolean("AngularVelocity #2", msg == *msg_d);
      delete msg_d;
    }
    catch (IMC::InvalidMessageSize& e)
    {
      (void)e;
      test.boolean("msg #2", msg.getSerializationSize() > DUNE_IMC_CONST_MAX_SIZE);
    }
  }

  {
    IMC::Acceleration msg;
    msg.setTimeStamp(0.09351064817718957);
    msg.setSource(20980U);
    msg.setSourceEntity(45U);
    msg.setDestination(44961U);
    msg.setDestinationEntity(197U);
    msg.time = 0.7299330398583065;
    msg.x = 0.14616022386155003;
    msg.y = 0.7833188499784633;
    msg.z = 0.9386451566578858;

    try
    {
      Utils::ByteBuffer bfr;
      IMC::Packet::serialize(&msg, bfr);
      IMC::Message* msg_d = IMC::Packet::deserialize(bfr.getBuffer(), bfr.getSize());
      test.boolean("Acceleration #0", msg == *msg_d);
      delete msg_d;
    }
    catch (IMC::InvalidMessageSize& e)
    {
      (void)e;
      test.boolean("msg #0", msg.getSerializationSize() > DUNE_IMC_CONST_MAX_SIZE);
    }
  }

  {
    IMC::Acceleration msg;
    msg.setTimeStamp(0.7949054047413158);
    msg.setSource(5843U);
    msg.setSourceEntity(36U);
    msg.setDestination(44149U);
    msg.setDestinationEntity(65U);
    msg.time = 0.8986189074020252;
    msg.x = 0.9109603568842288;
    msg.y = 0.05451856157702639;
    msg.z = 0.1642364343022088;

    try
    {
      Utils::ByteBuffer bfr;
      IMC::Packet::serialize(&msg, bfr);
      IMC::Message* msg_d = IMC::Packet::deserialize(bfr.getBuffer(), bfr.getSize());
      test.boolean("Acceleration #1", msg == *msg_d);
      delete msg_d;
    }
    catch (IMC::InvalidMessageSize& e)
    {
      (void)e;
      test.boolean("msg #1", msg.getSerializationSize() > DUNE_IMC_CONST_MAX_SIZE);
    }
  }

  {
    IMC::Acceleration msg;
    msg.setTimeStamp(0.6077871556784188);
    msg.setSource(55648U);
    msg.setSourceEntity(141U);
    msg.setDestination(16061U);
    msg.setDestinationEntity(216U);
    msg.time = 0.4109208528119235;
    msg.x = 0.02389903811783256;
    msg.y = 0.38658817435975235;
    msg.z = 0.6586070911648819;

    try
    {
      Utils::ByteBuffer bfr;
      IMC::Packet::serialize(&msg, bfr);
      IMC::Message* msg_d = IMC::Packet::deserialize(bfr.getBuffer(), bfr.getSize());
      test.boolean("Acceleration #2", msg == *msg_d);
      delete msg_d;
    }
    catch (IMC::InvalidMessageSize& e)
    {
      (void)e;
      test.boolean("msg #2", msg.getSerializationSize() > DUNE_IMC_CONST_MAX_SIZE);
    }
  }

  {
    IMC::MagneticField msg;
    msg.setTimeStamp(0.9316476064994027);
    msg.setSource(14299U);
    msg.setSourceEntity(152U);
    msg.setDestination(42575U);
    msg.setDestinationEntity(87U);
    msg.time = 0.09051187586320952;
    msg.x = 0.44246950734287693;
    msg.y = 0.8801826541128296;
    msg.z = 0.16833128555124222;

    try
    {
      Utils::ByteBuffer bfr;
      IMC::Packet::serialize(&msg, bfr);
      IMC::Message* msg_d = IMC::Packet::deserialize(bfr.getBuffer(), bfr.getSize());
      test.boolean("MagneticField #0", msg == *msg_d);
      delete msg_d;
    }
    catch (IMC::InvalidMessageSize& e)
    {
      (void)e;
      test.boolean("msg #0", msg.getSerializationSize() > DUNE_IMC_CONST_MAX_SIZE);
    }
  }

  {
    IMC::MagneticField msg;
    msg.setTimeStamp(0.03668603632349288);
    msg.setSource(60236U);
    msg.setSourceEntity(38U);
    msg.setDestination(35924U);
    msg.setDestinationEntity(137U);
    msg.time = 0.9963196786154269;
    msg.x = 0.6208290367153586;
    msg.y = 0.6925759325432241;
    msg.z = 0.16281088377735053;

    try
    {
      Utils::ByteBuffer bfr;
      IMC::Packet::serialize(&msg, bfr);
      IMC::Message* msg_d = IMC::Packet::deserialize(bfr.getBuffer(), bfr.getSize());
      test.boolean("MagneticField #1", msg == *msg_d);
      delete msg_d;
    }
    catch (IMC::InvalidMessageSize& e)
    {
      (void)e;
      test.boolean("msg #1", msg.getSerializationSize() > DUNE_IMC_CONST_MAX_SIZE);
    }
  }

  {
    IMC::MagneticField msg;
    msg.setTimeStamp(0.4353722713827788);
    msg.setSource(3359U);
    msg.setSourceEntity(97U);
    msg.setDestination(25667U);
    msg.setDestinationEntity(239U);
    msg.time = 0.7398509930171472;
    msg.x = 0.970626128498441;
    msg.y = 0.6528095747367039;
    msg.z = 0.9905464664110033;

    try
    {
      Utils::ByteBuffer bfr;
      IMC::Packet::serialize(&msg, bfr);
      IMC::Message* msg_d = IMC::Packet::deserialize(bfr.getBuffer(), bfr.getSize());
      test.boolean("MagneticField #2", msg == *msg_d);
      delete msg_d;
    }
    catch (IMC::InvalidMessageSize& e)
    {
      (void)e;
      test.boolean("msg #2", msg.getSerializationSize() > DUNE_IMC_CONST_MAX_SIZE);
    }
  }

  {
    IMC::GroundVelocity msg;
    msg.setTimeStamp(0.09265355515757134);
    msg.setSource(278U);
    msg.setSourceEntity(22U);
    msg.setDestination(59475U);
    msg.setDestinationEntity(167U);
    msg.validity = 216U;
    msg.x = 0.11678470783643802;
    msg.y = 0.12121983005432957;
    msg.z = 0.6390556788416786;

    try
    {
      Utils::ByteBuffer bfr;
      IMC::Packet::serialize(&msg, bfr);
      IMC::Message* msg_d = IMC::Packet::deserialize(bfr.getBuffer(), bfr.getSize());
      test.boolean("GroundVelocity #0", msg == *msg_d);
      delete msg_d;
    }
    catch (IMC::InvalidMessageSize& e)
    {
      (void)e;
      test.boolean("msg #0", msg.getSerializationSize() > DUNE_IMC_CONST_MAX_SIZE);
    }
  }

  {
    IMC::GroundVelocity msg;
    msg.setTimeStamp(0.3022908072327034);
    msg.setSource(1619U);
    msg.setSourceEntity(180U);
    msg.setDestination(63713U);
    msg.setDestinationEntity(196U);
    msg.validity = 65U;
    msg.x = 0.5495170483583386;
    msg.y = 0.6771399813965293;
    msg.z = 0.23490721778315182;

    try
    {
      Utils::ByteBuffer bfr;
      IMC::Packet::serialize(&msg, bfr);
      IMC::Message* msg_d = IMC::Packet::deserialize(bfr.getBuffer(), bfr.getSize());
      test.boolean("GroundVelocity #1", msg == *msg_d);
      delete msg_d;
    }
    catch (IMC::InvalidMessageSize& e)
    {
      (void)e;
      test.boolean("msg #1", msg.getSerializationSize() > DUNE_IMC_CONST_MAX_SIZE);
    }
  }

  {
    IMC::GroundVelocity msg;
    msg.setTimeStamp(0.24906047419480604);
    msg.setSource(53943U);
    msg.setSourceEntity(40U);
    msg.setDestination(5702U);
    msg.setDestinationEntity(100U);
    msg.validity = 133U;
    msg.x = 0.3109324959205889;
    msg.y = 0.7983631627532175;
    msg.z = 0.5016367238488552;

    try
    {
      Utils::ByteBuffer bfr;
      IMC::Packet::serialize(&msg, bfr);
      IMC::Message* msg_d = IMC::Packet::deserialize(bfr.getBuffer(), bfr.getSize());
      test.boolean("GroundVelocity #2", msg == *msg_d);
      delete msg_d;
    }
    catch (IMC::InvalidMessageSize& e)
    {
      (void)e;
      test.boolean("msg #2", msg.getSerializationSize() > DUNE_IMC_CONST_MAX_SIZE);
    }
  }

  {
    IMC::WaterVelocity msg;
    msg.setTimeStamp(0.8753843052841108);
    msg.setSource(11454U);
    msg.setSourceEntity(148U);
    msg.setDestination(48649U);
    msg.setDestinationEntity(27U);
    msg.validity = 135U;
    msg.x = 0.40994487079071884;
    msg.y = 0.03296780389187626;
    msg.z = 0.8915560846095927;

    try
    {
      Utils::ByteBuffer bfr;
      IMC::Packet::serialize(&msg, bfr);
      IMC::Message* msg_d = IMC::Packet::deserialize(bfr.getBuffer(), bfr.getSize());
      test.boolean("WaterVelocity #0", msg == *msg_d);
      delete msg_d;
    }
    catch (IMC::InvalidMessageSize& e)
    {
      (void)e;
      test.boolean("msg #0", msg.getSerializationSize() > DUNE_IMC_CONST_MAX_SIZE);
    }
  }

  {
    IMC::WaterVelocity msg;
    msg.setTimeStamp(0.06125737545070997);
    msg.setSource(61673U);
    msg.setSourceEntity(197U);
    msg.setDestination(51740U);
    msg.setDestinationEntity(189U);
    msg.validity = 214U;
    msg.x = 0.1321001446563267;
    msg.y = 0.44964239778646087;
    msg.z = 0.9343235834819604;

    try
    {
      Utils::ByteBuffer bfr;
      IMC::Packet::serialize(&msg, bfr);
      IMC::Message* msg_d = IMC::Packet::deserialize(bfr.getBuffer(), bfr.getSize());
      test.boolean("WaterVelocity #1", msg == *msg_d);
      delete msg_d;
    }
    catch (IMC::InvalidMessageSize& e)
    {
      (void)e;
      test.boolean("msg #1", msg.getSerializationSize() > DUNE_IMC_CONST_MAX_SIZE);
    }
  }

  {
    IMC::WaterVelocity msg;
    msg.setTimeStamp(0.2839030035708211);
    msg.setSource(49725U);
    msg.setSourceEntity(88U);
    msg.setDestination(14549U);
    msg.setDestinationEntity(161U);
    msg.validity = 16U;
    msg.x = 0.6502943504445592;
    msg.y = 0.12921853579250453;
    msg.z = 0.5966078723466717;

    try
    {
      Utils::ByteBuffer bfr;
      IMC::Packet::serialize(&msg, bfr);
      IMC::Message* msg_d = IMC::Packet::deserialize(bfr.getBuffer(), bfr.getSize());
      test.boolean("WaterVelocity #2", msg == *msg_d);
      delete msg_d;
    }
    catch (IMC::InvalidMessageSize& e)
    {
      (void)e;
      test.boolean("msg #2", msg.getSerializationSize() > DUNE_IMC_CONST_MAX_SIZE);
    }
  }

  {
    IMC::VelocityDelta msg;
    msg.setTimeStamp(0.6878083853737308);
    msg.setSource(59177U);
    msg.setSourceEntity(133U);
    msg.setDestination(19322U);
    msg.setDestinationEntity(147U);
    msg.time = 0.7700025428093296;
    msg.x = 0.28265941195747457;
    msg.y = 0.09329398348414353;
    msg.z = 0.3369192045173459;

    try
    {
      Utils::ByteBuffer bfr;
      IMC::Packet::serialize(&msg, bfr);
      IMC::Message* msg_d = IMC::Packet::deserialize(bfr.getBuffer(), bfr.getSize());
      test.boolean("VelocityDelta #0", msg == *msg_d);
      delete msg_d;
    }
    catch (IMC::InvalidMessageSize& e)
    {
      (void)e;
      test.boolean("msg #0", msg.getSerializationSize() > DUNE_IMC_CONST_MAX_SIZE);
    }
  }

  {
    IMC::VelocityDelta msg;
    msg.setTimeStamp(0.46602628380648814);
    msg.setSource(30365U);
    msg.setSourceEntity(129U);
    msg.setDestination(41171U);
    msg.setDestinationEntity(212U);
    msg.time = 0.4886026227316498;
    msg.x = 0.24460543073784835;
    msg.y = 0.9979759607114227;
    msg.z = 0.6178177354208548;

    try
    {
      Utils::ByteBuffer bfr;
      IMC::Packet::serialize(&msg, bfr);
      IMC::Message* msg_d = IMC::Packet::deserialize(bfr.getBuffer(), bfr.getSize());
      test.boolean("VelocityDelta #1", msg == *msg_d);
      delete msg_d;
    }
    catch (IMC::InvalidMessageSize& e)
    {
      (void)e;
      test.boolean("msg #1", msg.getSerializationSize() > DUNE_IMC_CONST_MAX_SIZE);
    }
  }

  {
    IMC::VelocityDelta msg;
    msg.setTimeStamp(0.35458550761940166);
    msg.setSource(12031U);
    msg.setSourceEntity(146U);
    msg.setDestination(39111U);
    msg.setDestinationEntity(64U);
    msg.time = 0.7358833448209703;
    msg.x = 0.9906351330501602;
    msg.y = 0.6400550430573446;
    msg.z = 0.06934092023531357;

    try
    {
      Utils::ByteBuffer bfr;
      IMC::Packet::serialize(&msg, bfr);
      IMC::Message* msg_d = IMC::Packet::deserialize(bfr.getBuffer(), bfr.getSize());
      test.boolean("VelocityDelta #2", msg == *msg_d);
      delete msg_d;
    }
    catch (IMC::InvalidMessageSize& e)
    {
      (void)e;
      test.boolean("msg #2", msg.getSerializationSize() > DUNE_IMC_CONST_MAX_SIZE);
    }
  }

  {
    IMC::Distance msg;
    msg.setTimeStamp(0.818333488493442);
    msg.setSource(5724U);
    msg.setSourceEntity(78U);
    msg.setDestination(43503U);
    msg.setDestinationEntity(246U);
    msg.validity = 227U;
    IMC::BeamConfig tmp_msg_0;
    tmp_msg_0.beam_width = 0.013231894042765258;
    tmp_msg_0.beam_height = 0.6320248381914272;
    msg.beam_config.push_back(tmp_msg_0);
    msg.value = 0.04333894348539191;

    try
    {
      Utils::ByteBuffer bfr;
      IMC::Packet::serialize(&msg, bfr);
      IMC::Message* msg_d = IMC::Packet::deserialize(bfr.getBuffer(), bfr.getSize());
      test.boolean("Distance #0", msg == *msg_d);
      delete msg_d;
    }
    catch (IMC::InvalidMessageSize& e)
    {
      (void)e;
      test.boolean("msg #0", msg.getSerializationSize() > DUNE_IMC_CONST_MAX_SIZE);
    }
  }

  {
    IMC::Distance msg;
    msg.setTimeStamp(0.3316256241951536);
    msg.setSource(53004U);
    msg.setSourceEntity(251U);
    msg.setDestination(14443U);
    msg.setDestinationEntity(94U);
    msg.validity = 80U;
    msg.value = 0.179550917761938;

    try
    {
      Utils::ByteBuffer bfr;
      IMC::Packet::serialize(&msg, bfr);
      IMC::Message* msg_d = IMC::Packet::deserialize(bfr.getBuffer(), bfr.getSize());
      test.boolean("Distance #1", msg == *msg_d);
      delete msg_d;
    }
    catch (IMC::InvalidMessageSize& e)
    {
      (void)e;
      test.boolean("msg #1", msg.getSerializationSize() > DUNE_IMC_CONST_MAX_SIZE);
    }
  }

  {
    IMC::Distance msg;
    msg.setTimeStamp(0.7809980006262663);
    msg.setSource(10500U);
    msg.setSourceEntity(251U);
    msg.setDestination(64430U);
    msg.setDestinationEntity(72U);
    msg.validity = 217U;
    IMC::BeamConfig tmp_msg_0;
    tmp_msg_0.beam_width = 0.9548890500539265;
    tmp_msg_0.beam_height = 0.26438937451093003;
    msg.beam_config.push_back(tmp_msg_0);
    msg.value = 0.6241954586628067;

    try
    {
      Utils::ByteBuffer bfr;
      IMC::Packet::serialize(&msg, bfr);
      IMC::Message* msg_d = IMC::Packet::deserialize(bfr.getBuffer(), bfr.getSize());
      test.boolean("Distance #2", msg == *msg_d);
      delete msg_d;
    }
    catch (IMC::InvalidMessageSize& e)
    {
      (void)e;
      test.boolean("msg #2", msg.getSerializationSize() > DUNE_IMC_CONST_MAX_SIZE);
    }
  }

  {
    IMC::Temperature msg;
    msg.setTimeStamp(0.11857331307177199);
    msg.setSource(5342U);
    msg.setSourceEntity(244U);
    msg.setDestination(13710U);
    msg.setDestinationEntity(177U);
    msg.value = 0.5184188483011783;

    try
    {
      Utils::ByteBuffer bfr;
      IMC::Packet::serialize(&msg, bfr);
      IMC::Message* msg_d = IMC::Packet::deserialize(bfr.getBuffer(), bfr.getSize());
      test.boolean("Temperature #0", msg == *msg_d);
      delete msg_d;
    }
    catch (IMC::InvalidMessageSize& e)
    {
      (void)e;
      test.boolean("msg #0", msg.getSerializationSize() > DUNE_IMC_CONST_MAX_SIZE);
    }
  }

  {
    IMC::Temperature msg;
    msg.setTimeStamp(0.24303741068150064);
    msg.setSource(15156U);
    msg.setSourceEntity(238U);
    msg.setDestination(39833U);
    msg.setDestinationEntity(44U);
    msg.value = 0.7439158974965292;

    try
    {
      Utils::ByteBuffer bfr;
      IMC::Packet::serialize(&msg, bfr);
      IMC::Message* msg_d = IMC::Packet::deserialize(bfr.getBuffer(), bfr.getSize());
      test.boolean("Temperature #1", msg == *msg_d);
      delete msg_d;
    }
    catch (IMC::InvalidMessageSize& e)
    {
      (void)e;
      test.boolean("msg #1", msg.getSerializationSize() > DUNE_IMC_CONST_MAX_SIZE);
    }
  }

  {
    IMC::Temperature msg;
    msg.setTimeStamp(0.24599601896739787);
    msg.setSource(19867U);
    msg.setSourceEntity(150U);
    msg.setDestination(11557U);
    msg.setDestinationEntity(82U);
    msg.value = 0.9252776182157747;

    try
    {
      Utils::ByteBuffer bfr;
      IMC::Packet::serialize(&msg, bfr);
      IMC::Message* msg_d = IMC::Packet::deserialize(bfr.getBuffer(), bfr.getSize());
      test.boolean("Temperature #2", msg == *msg_d);
      delete msg_d;
    }
    catch (IMC::InvalidMessageSize& e)
    {
      (void)e;
      test.boolean("msg #2", msg.getSerializationSize() > DUNE_IMC_CONST_MAX_SIZE);
    }
  }

  {
    IMC::Pressure msg;
    msg.setTimeStamp(0.8139248871719298);
    msg.setSource(21801U);
    msg.setSourceEntity(53U);
    msg.setDestination(14250U);
    msg.setDestinationEntity(48U);
    msg.value = 0.6202942983787205;

    try
    {
      Utils::ByteBuffer bfr;
      IMC::Packet::serialize(&msg, bfr);
      IMC::Message* msg_d = IMC::Packet::deserialize(bfr.getBuffer(), bfr.getSize());
      test.boolean("Pressure #0", msg == *msg_d);
      delete msg_d;
    }
    catch (IMC::InvalidMessageSize& e)
    {
      (void)e;
      test.boolean("msg #0", msg.getSerializationSize() > DUNE_IMC_CONST_MAX_SIZE);
    }
  }

  {
    IMC::Pressure msg;
    msg.setTimeStamp(0.11486987393384951);
    msg.setSource(38276U);
    msg.setSourceEntity(154U);
    msg.setDestination(28849U);
    msg.setDestinationEntity(54U);
    msg.value = 0.8632658271614599;

    try
    {
      Utils::ByteBuffer bfr;
      IMC::Packet::serialize(&msg, bfr);
      IMC::Message* msg_d = IMC::Packet::deserialize(bfr.getBuffer(), bfr.getSize());
      test.boolean("Pressure #1", msg == *msg_d);
      delete msg_d;
    }
    catch (IMC::InvalidMessageSize& e)
    {
      (void)e;
      test.boolean("msg #1", msg.getSerializationSize() > DUNE_IMC_CONST_MAX_SIZE);
    }
  }

  {
    IMC::Pressure msg;
    msg.setTimeStamp(0.7283788485331294);
    msg.setSource(21531U);
    msg.setSourceEntity(51U);
    msg.setDestination(24308U);
    msg.setDestinationEntity(225U);
    msg.value = 0.9354800652395122;

    try
    {
      Utils::ByteBuffer bfr;
      IMC::Packet::serialize(&msg, bfr);
      IMC::Message* msg_d = IMC::Packet::deserialize(bfr.getBuffer(), bfr.getSize());
      test.boolean("Pressure #2", msg == *msg_d);
      delete msg_d;
    }
    catch (IMC::InvalidMessageSize& e)
    {
      (void)e;
      test.boolean("msg #2", msg.getSerializationSize() > DUNE_IMC_CONST_MAX_SIZE);
    }
  }

  {
    IMC::Depth msg;
    msg.setTimeStamp(0.8896244063310601);
    msg.setSource(20426U);
    msg.setSourceEntity(30U);
    msg.setDestination(48148U);
    msg.setDestinationEntity(186U);
    msg.value = 0.10458511004642557;

    try
    {
      Utils::ByteBuffer bfr;
      IMC::Packet::serialize(&msg, bfr);
      IMC::Message* msg_d = IMC::Packet::deserialize(bfr.getBuffer(), bfr.getSize());
      test.boolean("Depth #0", msg == *msg_d);
      delete msg_d;
    }
    catch (IMC::InvalidMessageSize& e)
    {
      (void)e;
      test.boolean("msg #0", msg.getSerializationSize() > DUNE_IMC_CONST_MAX_SIZE);
    }
  }

  {
    IMC::Depth msg;
    msg.setTimeStamp(0.6946753092956874);
    msg.setSource(51160U);
    msg.setSourceEntity(146U);
    msg.setDestination(63569U);
    msg.setDestinationEntity(47U);
    msg.value = 0.13329965923794607;

    try
    {
      Utils::ByteBuffer bfr;
      IMC::Packet::serialize(&msg, bfr);
      IMC::Message* msg_d = IMC::Packet::deserialize(bfr.getBuffer(), bfr.getSize());
      test.boolean("Depth #1", msg == *msg_d);
      delete msg_d;
    }
    catch (IMC::InvalidMessageSize& e)
    {
      (void)e;
      test.boolean("msg #1", msg.getSerializationSize() > DUNE_IMC_CONST_MAX_SIZE);
    }
  }

  {
    IMC::Depth msg;
    msg.setTimeStamp(0.9999097612575424);
    msg.setSource(14211U);
    msg.setSourceEntity(230U);
    msg.setDestination(65204U);
    msg.setDestinationEntity(222U);
    msg.value = 0.1359352146302535;

    try
    {
      Utils::ByteBuffer bfr;
      IMC::Packet::serialize(&msg, bfr);
      IMC::Message* msg_d = IMC::Packet::deserialize(bfr.getBuffer(), bfr.getSize());
      test.boolean("Depth #2", msg == *msg_d);
      delete msg_d;
    }
    catch (IMC::InvalidMessageSize& e)
    {
      (void)e;
      test.boolean("msg #2", msg.getSerializationSize() > DUNE_IMC_CONST_MAX_SIZE);
    }
  }

  {
    IMC::DepthOffset msg;
    msg.setTimeStamp(0.5129225199687717);
    msg.setSource(33178U);
    msg.setSourceEntity(213U);
    msg.setDestination(25430U);
    msg.setDestinationEntity(98U);
    msg.value = 0.02873187734972671;

    try
    {
      Utils::ByteBuffer bfr;
      IMC::Packet::serialize(&msg, bfr);
      IMC::Message* msg_d = IMC::Packet::deserialize(bfr.getBuffer(), bfr.getSize());
      test.boolean("DepthOffset #0", msg == *msg_d);
      delete msg_d;
    }
    catch (IMC::InvalidMessageSize& e)
    {
      (void)e;
      test.boolean("msg #0", msg.getSerializationSize() > DUNE_IMC_CONST_MAX_SIZE);
    }
  }

  {
    IMC::DepthOffset msg;
    msg.setTimeStamp(0.3771865680388682);
    msg.setSource(19816U);
    msg.setSourceEntity(0U);
    msg.setDestination(38320U);
    msg.setDestinationEntity(208U);
    msg.value = 0.46267686979804734;

    try
    {
      Utils::ByteBuffer bfr;
      IMC::Packet::serialize(&msg, bfr);
      IMC::Message* msg_d = IMC::Packet::deserialize(bfr.getBuffer(), bfr.getSize());
      test.boolean("DepthOffset #1", msg == *msg_d);
      delete msg_d;
    }
    catch (IMC::InvalidMessageSize& e)
    {
      (void)e;
      test.boolean("msg #1", msg.getSerializationSize() > DUNE_IMC_CONST_MAX_SIZE);
    }
  }

  {
    IMC::DepthOffset msg;
    msg.setTimeStamp(0.2219768695846832);
    msg.setSource(23773U);
    msg.setSourceEntity(213U);
    msg.setDestination(62899U);
    msg.setDestinationEntity(13U);
    msg.value = 0.3796673946863971;

    try
    {
      Utils::ByteBuffer bfr;
      IMC::Packet::serialize(&msg, bfr);
      IMC::Message* msg_d = IMC::Packet::deserialize(bfr.getBuffer(), bfr.getSize());
      test.boolean("DepthOffset #2", msg == *msg_d);
      delete msg_d;
    }
    catch (IMC::InvalidMessageSize& e)
    {
      (void)e;
      test.boolean("msg #2", msg.getSerializationSize() > DUNE_IMC_CONST_MAX_SIZE);
    }
  }

  {
    IMC::SoundSpeed msg;
    msg.setTimeStamp(0.7882587885102326);
    msg.setSource(63833U);
    msg.setSourceEntity(191U);
    msg.setDestination(24844U);
    msg.setDestinationEntity(227U);
    msg.value = 0.5810254380075324;

    try
    {
      Utils::ByteBuffer bfr;
      IMC::Packet::serialize(&msg, bfr);
      IMC::Message* msg_d = IMC::Packet::deserialize(bfr.getBuffer(), bfr.getSize());
      test.boolean("SoundSpeed #0", msg == *msg_d);
      delete msg_d;
    }
    catch (IMC::InvalidMessageSize& e)
    {
      (void)e;
      test.boolean("msg #0", msg.getSerializationSize() > DUNE_IMC_CONST_MAX_SIZE);
    }
  }

  {
    IMC::SoundSpeed msg;
    msg.setTimeStamp(0.42220461830685563);
    msg.setSource(31339U);
    msg.setSourceEntity(177U);
    msg.setDestination(58429U);
    msg.setDestinationEntity(176U);
    msg.value = 0.6686599023033899;

    try
    {
      Utils::ByteBuffer bfr;
      IMC::Packet::serialize(&msg, bfr);
      IMC::Message* msg_d = IMC::Packet::deserialize(bfr.getBuffer(), bfr.getSize());
      test.boolean("SoundSpeed #1", msg == *msg_d);
      delete msg_d;
    }
    catch (IMC::InvalidMessageSize& e)
    {
      (void)e;
      test.boolean("msg #1", msg.getSerializationSize() > DUNE_IMC_CONST_MAX_SIZE);
    }
  }

  {
    IMC::SoundSpeed msg;
    msg.setTimeStamp(0.7254942374742398);
    msg.setSource(25936U);
    msg.setSourceEntity(119U);
    msg.setDestination(37517U);
    msg.setDestinationEntity(129U);
    msg.value = 0.8049142956362308;

    try
    {
      Utils::ByteBuffer bfr;
      IMC::Packet::serialize(&msg, bfr);
      IMC::Message* msg_d = IMC::Packet::deserialize(bfr.getBuffer(), bfr.getSize());
      test.boolean("SoundSpeed #2", msg == *msg_d);
      delete msg_d;
    }
    catch (IMC::InvalidMessageSize& e)
    {
      (void)e;
      test.boolean("msg #2", msg.getSerializationSize() > DUNE_IMC_CONST_MAX_SIZE);
    }
  }

  {
    IMC::WaterDensity msg;
    msg.setTimeStamp(0.18089603139788335);
    msg.setSource(55916U);
    msg.setSourceEntity(237U);
    msg.setDestination(34597U);
    msg.setDestinationEntity(128U);
    msg.value = 0.10893628065122352;

    try
    {
      Utils::ByteBuffer bfr;
      IMC::Packet::serialize(&msg, bfr);
      IMC::Message* msg_d = IMC::Packet::deserialize(bfr.getBuffer(), bfr.getSize());
      test.boolean("WaterDensity #0", msg == *msg_d);
      delete msg_d;
    }
    catch (IMC::InvalidMessageSize& e)
    {
      (void)e;
      test.boolean("msg #0", msg.getSerializationSize() > DUNE_IMC_CONST_MAX_SIZE);
    }
  }

  {
    IMC::WaterDensity msg;
    msg.setTimeStamp(0.15861523265233146);
    msg.setSource(42751U);
    msg.setSourceEntity(8U);
    msg.setDestination(42430U);
    msg.setDestinationEntity(103U);
    msg.value = 0.9700113272015569;

    try
    {
      Utils::ByteBuffer bfr;
      IMC::Packet::serialize(&msg, bfr);
      IMC::Message* msg_d = IMC::Packet::deserialize(bfr.getBuffer(), bfr.getSize());
      test.boolean("WaterDensity #1", msg == *msg_d);
      delete msg_d;
    }
    catch (IMC::InvalidMessageSize& e)
    {
      (void)e;
      test.boolean("msg #1", msg.getSerializationSize() > DUNE_IMC_CONST_MAX_SIZE);
    }
  }

  {
    IMC::WaterDensity msg;
    msg.setTimeStamp(0.036066311956279185);
    msg.setSource(23858U);
    msg.setSourceEntity(191U);
    msg.setDestination(57871U);
    msg.setDestinationEntity(228U);
    msg.value = 0.7859419893239097;

    try
    {
      Utils::ByteBuffer bfr;
      IMC::Packet::serialize(&msg, bfr);
      IMC::Message* msg_d = IMC::Packet::deserialize(bfr.getBuffer(), bfr.getSize());
      test.boolean("WaterDensity #2", msg == *msg_d);
      delete msg_d;
    }
    catch (IMC::InvalidMessageSize& e)
    {
      (void)e;
      test.boolean("msg #2", msg.getSerializationSize() > DUNE_IMC_CONST_MAX_SIZE);
    }
  }

  {
    IMC::Conductivity msg;
    msg.setTimeStamp(0.09970848184818015);
    msg.setSource(45482U);
    msg.setSourceEntity(135U);
    msg.setDestination(24457U);
    msg.setDestinationEntity(199U);
    msg.value = 0.9338824926488186;

    try
    {
      Utils::ByteBuffer bfr;
      IMC::Packet::serialize(&msg, bfr);
      IMC::Message* msg_d = IMC::Packet::deserialize(bfr.getBuffer(), bfr.getSize());
      test.boolean("Conductivity #0", msg == *msg_d);
      delete msg_d;
    }
    catch (IMC::InvalidMessageSize& e)
    {
      (void)e;
      test.boolean("msg #0", msg.getSerializationSize() > DUNE_IMC_CONST_MAX_SIZE);
    }
  }

  {
    IMC::Conductivity msg;
    msg.setTimeStamp(0.8264066087187742);
    msg.setSource(61855U);
    msg.setSourceEntity(80U);
    msg.setDestination(13413U);
    msg.setDestinationEntity(4U);
    msg.value = 0.0959712335078945;

    try
    {
      Utils::ByteBuffer bfr;
      IMC::Packet::serialize(&msg, bfr);
      IMC::Message* msg_d = IMC::Packet::deserialize(bfr.getBuffer(), bfr.getSize());
      test.boolean("Conductivity #1", msg == *msg_d);
      delete msg_d;
    }
    catch (IMC::InvalidMessageSize& e)
    {
      (void)e;
      test.boolean("msg #1", msg.getSerializationSize() > DUNE_IMC_CONST_MAX_SIZE);
    }
  }

  {
    IMC::Conductivity msg;
    msg.setTimeStamp(0.31344805981988855);
    msg.setSource(31197U);
    msg.setSourceEntity(225U);
    msg.setDestination(29744U);
    msg.setDestinationEntity(76U);
    msg.value = 0.6236736525333456;

    try
    {
      Utils::ByteBuffer bfr;
      IMC::Packet::serialize(&msg, bfr);
      IMC::Message* msg_d = IMC::Packet::deserialize(bfr.getBuffer(), bfr.getSize());
      test.boolean("Conductivity #2", msg == *msg_d);
      delete msg_d;
    }
    catch (IMC::InvalidMessageSize& e)
    {
      (void)e;
      test.boolean("msg #2", msg.getSerializationSize() > DUNE_IMC_CONST_MAX_SIZE);
    }
  }

  {
    IMC::Salinity msg;
    msg.setTimeStamp(0.117725272064095);
    msg.setSource(43876U);
    msg.setSourceEntity(27U);
    msg.setDestination(58957U);
    msg.setDestinationEntity(114U);
    msg.value = 0.29951756686941655;

    try
    {
      Utils::ByteBuffer bfr;
      IMC::Packet::serialize(&msg, bfr);
      IMC::Message* msg_d = IMC::Packet::deserialize(bfr.getBuffer(), bfr.getSize());
      test.boolean("Salinity #0", msg == *msg_d);
      delete msg_d;
    }
    catch (IMC::InvalidMessageSize& e)
    {
      (void)e;
      test.boolean("msg #0", msg.getSerializationSize() > DUNE_IMC_CONST_MAX_SIZE);
    }
  }

  {
    IMC::Salinity msg;
    msg.setTimeStamp(0.3269451201419983);
    msg.setSource(26413U);
    msg.setSourceEntity(79U);
    msg.setDestination(6702U);
    msg.setDestinationEntity(75U);
    msg.value = 0.0017062074302869323;

    try
    {
      Utils::ByteBuffer bfr;
      IMC::Packet::serialize(&msg, bfr);
      IMC::Message* msg_d = IMC::Packet::deserialize(bfr.getBuffer(), bfr.getSize());
      test.boolean("Salinity #1", msg == *msg_d);
      delete msg_d;
    }
    catch (IMC::InvalidMessageSize& e)
    {
      (void)e;
      test.boolean("msg #1", msg.getSerializationSize() > DUNE_IMC_CONST_MAX_SIZE);
    }
  }

  {
    IMC::Salinity msg;
    msg.setTimeStamp(0.36745183982005236);
    msg.setSource(44137U);
    msg.setSourceEntity(245U);
    msg.setDestination(51693U);
    msg.setDestinationEntity(39U);
    msg.value = 0.025788415945371512;

    try
    {
      Utils::ByteBuffer bfr;
      IMC::Packet::serialize(&msg, bfr);
      IMC::Message* msg_d = IMC::Packet::deserialize(bfr.getBuffer(), bfr.getSize());
      test.boolean("Salinity #2", msg == *msg_d);
      delete msg_d;
    }
    catch (IMC::InvalidMessageSize& e)
    {
      (void)e;
      test.boolean("msg #2", msg.getSerializationSize() > DUNE_IMC_CONST_MAX_SIZE);
    }
  }

  {
    IMC::WindSpeed msg;
    msg.setTimeStamp(0.8649657707379885);
    msg.setSource(4611U);
    msg.setSourceEntity(41U);
    msg.setDestination(18767U);
    msg.setDestinationEntity(39U);
    msg.direction = 0.783209415865111;
    msg.speed = 0.6895368901002413;
    msg.turbulence = 0.3114881494359353;

    try
    {
      Utils::ByteBuffer bfr;
      IMC::Packet::serialize(&msg, bfr);
      IMC::Message* msg_d = IMC::Packet::deserialize(bfr.getBuffer(), bfr.getSize());
      test.boolean("WindSpeed #0", msg == *msg_d);
      delete msg_d;
    }
    catch (IMC::InvalidMessageSize& e)
    {
      (void)e;
      test.boolean("msg #0", msg.getSerializationSize() > DUNE_IMC_CONST_MAX_SIZE);
    }
  }

  {
    IMC::WindSpeed msg;
    msg.setTimeStamp(0.8242941680530997);
    msg.setSource(56077U);
    msg.setSourceEntity(128U);
    msg.setDestination(14238U);
    msg.setDestinationEntity(97U);
    msg.direction = 0.5550017539012155;
    msg.speed = 0.6391578358971668;
    msg.turbulence = 0.4705571146253572;

    try
    {
      Utils::ByteBuffer bfr;
      IMC::Packet::serialize(&msg, bfr);
      IMC::Message* msg_d = IMC::Packet::deserialize(bfr.getBuffer(), bfr.getSize());
      test.boolean("WindSpeed #1", msg == *msg_d);
      delete msg_d;
    }
    catch (IMC::InvalidMessageSize& e)
    {
      (void)e;
      test.boolean("msg #1", msg.getSerializationSize() > DUNE_IMC_CONST_MAX_SIZE);
    }
  }

  {
    IMC::WindSpeed msg;
    msg.setTimeStamp(0.2130307897895356);
    msg.setSource(34945U);
    msg.setSourceEntity(233U);
    msg.setDestination(45796U);
    msg.setDestinationEntity(67U);
    msg.direction = 0.6655016128407601;
    msg.speed = 0.8154781255555987;
    msg.turbulence = 0.2594255093005031;

    try
    {
      Utils::ByteBuffer bfr;
      IMC::Packet::serialize(&msg, bfr);
      IMC::Message* msg_d = IMC::Packet::deserialize(bfr.getBuffer(), bfr.getSize());
      test.boolean("WindSpeed #2", msg == *msg_d);
      delete msg_d;
    }
    catch (IMC::InvalidMessageSize& e)
    {
      (void)e;
      test.boolean("msg #2", msg.getSerializationSize() > DUNE_IMC_CONST_MAX_SIZE);
    }
  }

  {
    IMC::RelativeHumidity msg;
    msg.setTimeStamp(0.4506876744564494);
    msg.setSource(33541U);
    msg.setSourceEntity(245U);
    msg.setDestination(43004U);
    msg.setDestinationEntity(233U);
    msg.value = 0.5716312565458275;

    try
    {
      Utils::ByteBuffer bfr;
      IMC::Packet::serialize(&msg, bfr);
      IMC::Message* msg_d = IMC::Packet::deserialize(bfr.getBuffer(), bfr.getSize());
      test.boolean("RelativeHumidity #0", msg == *msg_d);
      delete msg_d;
    }
    catch (IMC::InvalidMessageSize& e)
    {
      (void)e;
      test.boolean("msg #0", msg.getSerializationSize() > DUNE_IMC_CONST_MAX_SIZE);
    }
  }

  {
    IMC::RelativeHumidity msg;
    msg.setTimeStamp(0.3974952286299489);
    msg.setSource(43150U);
    msg.setSourceEntity(226U);
    msg.setDestination(47017U);
    msg.setDestinationEntity(31U);
    msg.value = 0.19698404924399204;

    try
    {
      Utils::ByteBuffer bfr;
      IMC::Packet::serialize(&msg, bfr);
      IMC::Message* msg_d = IMC::Packet::deserialize(bfr.getBuffer(), bfr.getSize());
      test.boolean("RelativeHumidity #1", msg == *msg_d);
      delete msg_d;
    }
    catch (IMC::InvalidMessageSize& e)
    {
      (void)e;
      test.boolean("msg #1", msg.getSerializationSize() > DUNE_IMC_CONST_MAX_SIZE);
    }
  }

  {
    IMC::RelativeHumidity msg;
    msg.setTimeStamp(0.9426069934155792);
    msg.setSource(17523U);
    msg.setSourceEntity(54U);
    msg.setDestination(48983U);
    msg.setDestinationEntity(147U);
    msg.value = 0.8574244917294344;

    try
    {
      Utils::ByteBuffer bfr;
      IMC::Packet::serialize(&msg, bfr);
      IMC::Message* msg_d = IMC::Packet::deserialize(bfr.getBuffer(), bfr.getSize());
      test.boolean("RelativeHumidity #2", msg == *msg_d);
      delete msg_d;
    }
    catch (IMC::InvalidMessageSize& e)
    {
      (void)e;
      test.boolean("msg #2", msg.getSerializationSize() > DUNE_IMC_CONST_MAX_SIZE);
    }
  }

  {
    IMC::DevDataText msg;
    msg.setTimeStamp(0.03603157929456291);
    msg.setSource(22253U);
    msg.setSourceEntity(137U);
    msg.setDestination(48075U);
    msg.setDestinationEntity(199U);
    msg.value.assign("ZZLZFJVQPVDQDEUYIRXOMVYJAIJAGFVVVWCCWOJYXERVMJDCGBLPUQKFMKZTYJNFRGEGCUWPHMEIDRYNASFHXNQXKQGERXBEGTXZGTCELMPCHSNGVLZFSBHQIFHKYJCENDLSAYXMIWITJFGCNQAXASKKTFTRJAKNPLWARBZOZHSWRYDPNEOQSBWGEKXWUSDDIZMNPDCCRIAYHTUPTSSBPOBPVUMLKHXLUTOJVUYKMWOONHBLBQIUTU");

    try
    {
      Utils::ByteBuffer bfr;
      IMC::Packet::serialize(&msg, bfr);
      IMC::Message* msg_d = IMC::Packet::deserialize(bfr.getBuffer(), bfr.getSize());
      test.boolean("DevDataText #0", msg == *msg_d);
      delete msg_d;
    }
    catch (IMC::InvalidMessageSize& e)
    {
      (void)e;
      test.boolean("msg #0", msg.getSerializationSize() > DUNE_IMC_CONST_MAX_SIZE);
    }
  }

  {
    IMC::DevDataText msg;
    msg.setTimeStamp(0.6493522208518957);
    msg.setSource(10199U);
    msg.setSourceEntity(207U);
    msg.setDestination(53570U);
    msg.setDestinationEntity(60U);
    msg.value.assign("UGYBFGWBPGQPSFTZRSYHEILHXOAFQVRNFHLOILNWVUGNDGCYEOTUWMPPQSULTIMBFELRYJINIJLEOPFQHSDCHACDHAYUQDWQSXJHODRXKJDSPYAUJLATKWMWKQCXMGEAZCPIMIKWBCDRFMTQDOKOBJVIECWHGMYNDJBNDTXKMEPGRGYQRJNKVZFHORZFYGSWVSXTTTORTBWZSVMULVENPAZSBFKJUYALVXIPLQOCRX");

    try
    {
      Utils::ByteBuffer bfr;
      IMC::Packet::serialize(&msg, bfr);
      IMC::Message* msg_d = IMC::Packet::deserialize(bfr.getBuffer(), bfr.getSize());
      test.boolean("DevDataText #1", msg == *msg_d);
      delete msg_d;
    }
    catch (IMC::InvalidMessageSize& e)
    {
      (void)e;
      test.boolean("msg #1", msg.getSerializationSize() > DUNE_IMC_CONST_MAX_SIZE);
    }
  }

  {
    IMC::DevDataText msg;
    msg.setTimeStamp(0.5956180728671842);
    msg.setSource(55104U);
    msg.setSourceEntity(191U);
    msg.setDestination(53686U);
    msg.setDestinationEntity(38U);
    msg.value.assign("HLOAIOOIQGQQMCEDEQBHESIWNORYYBZGSNYLINZKFMFJXGLUCCKXZYXLZUVFVGLBSZDUTEKACWYCTNVYCTFUNSDDBMKIHOFRBKQXNZRADMTPMWFSJHAVJRCMJSEREZSPPTJWGYESQWDPOAIXQOPUZLBPURIAWWLXHGHAVJSVNQYHOPAEOFRGDJLKPRWIOKVKTUULVTXTMNEEPIGPDFZQJAHTIKKWXBBHZVUQJVDBFRGXCYTRAYNS");

    try
    {
      Utils::ByteBuffer bfr;
      IMC::Packet::serialize(&msg, bfr);
      IMC::Message* msg_d = IMC::Packet::deserialize(bfr.getBuffer(), bfr.getSize());
      test.boolean("DevDataText #2", msg == *msg_d);
      delete msg_d;
    }
    catch (IMC::InvalidMessageSize& e)
    {
      (void)e;
      test.boolean("msg #2", msg.getSerializationSize() > DUNE_IMC_CONST_MAX_SIZE);
    }
  }

  {
    IMC::DevDataBinary msg;
    msg.setTimeStamp(0.8606338332411411);
    msg.setSource(18423U);
    msg.setSourceEntity(171U);
    msg.setDestination(28870U);
    msg.setDestinationEntity(159U);
    const signed char tmp_msg_0[] = {47, -92, 15, -124, 113, -45, -103, -90, -123, -101, 65, 17, 77, 91, -108, -91, 86, 42, 65, -2, -21, -61, 103, -68, 58, -99, -36, -22, -88, 2, 11, 77, -76, 71, -12, 33, -72, -79, 78, 39, 122, -110, -53, 24, 36, 2, 48, 101, 101, 63, 76, 41, -8, 23, -65, 97, -93, -79, -31, -34, 38, -113, -114, -52, 31, -126, -62, 25, 119, -3, 43, 101, -52, 54, -31, -59, -126, -77, -40, -74, -118, -8, 27, 58, -87, -100, -33, -79, 85, -101, -86, 80, 9, 107, -99, -28, -69, -56, -48, 113, -54, 67, -84, 126, 28, -53, -100, 60, 87, -111, 119, 65, 99, -35, -70, -46, 41, -30, -21, -12, -90, 95, -18, -65, -61, 92, 49, -35, 11, 51, -117, -73, -97, 2, -47, 30, -94, -79, -114, -73, -126, -120, 75, 77, -82, -86, 90, -12, -1, 10, -125, -45, 9, -57, -53, -37, -71, -46, -75, -86, -17, 0, 80, -29, -92, -6, -72, -70, -123, -122, -113, 106, -94, 18, 80, -26, 46, 39, 31, 14, -105, -102, 119, 67, 18, 34, 99, 105, 126, -44, 9, 50, -9, 73, -107, -103, 67, -27, 19, 78, 94, 32, -127, -49, -43, 111, -102, 88, 89, -35, -23, 68, -38, 16, 109, -120, 34, -48, 10, -91, -53, -104, 84, -79};
    msg.value.assign(tmp_msg_0, tmp_msg_0 + sizeof(tmp_msg_0));

    try
    {
      Utils::ByteBuffer bfr;
      IMC::Packet::serialize(&msg, bfr);
      IMC::Message* msg_d = IMC::Packet::deserialize(bfr.getBuffer(), bfr.getSize());
      test.boolean("DevDataBinary #0", msg == *msg_d);
      delete msg_d;
    }
    catch (IMC::InvalidMessageSize& e)
    {
      (void)e;
      test.boolean("msg #0", msg.getSerializationSize() > DUNE_IMC_CONST_MAX_SIZE);
    }
  }

  {
    IMC::DevDataBinary msg;
    msg.setTimeStamp(0.044092775620230396);
    msg.setSource(10171U);
    msg.setSourceEntity(109U);
    msg.setDestination(43736U);
    msg.setDestinationEntity(10U);
    const signed char tmp_msg_0[] = {77, 52, -63, 19, -56, 8, 102, -103, 51, 99, 27, -40, -28, -125, 42, -73, -118, 103, 62, -110, 107, -119, 59, -34, 99, -110, 56, -83, -122, 97, -100, 21, -119, 50, 123, -95, 54, 36, 64, 31, 79, 44, -78, -19, -22, 34, -62, -79, -111, -8, 44, 114, -121, 12, 20, 102, 36, -90, -60, 21, 53, -75, -46, 100, 84, -83, -93, -97, 34, -123, 9, -84, 12, -72, -5, -115, -37, -50, -22, -83, -32, 99, -80, -95, 32, 82, 111, -35, 19, 105, -35, 13, 119, 10, -1, -40, 39, -61};
    msg.value.assign(tmp_msg_0, tmp_msg_0 + sizeof(tmp_msg_0));

    try
    {
      Utils::ByteBuffer bfr;
      IMC::Packet::serialize(&msg, bfr);
      IMC::Message* msg_d = IMC::Packet::deserialize(bfr.getBuffer(), bfr.getSize());
      test.boolean("DevDataBinary #1", msg == *msg_d);
      delete msg_d;
    }
    catch (IMC::InvalidMessageSize& e)
    {
      (void)e;
      test.boolean("msg #1", msg.getSerializationSize() > DUNE_IMC_CONST_MAX_SIZE);
    }
  }

  {
    IMC::DevDataBinary msg;
    msg.setTimeStamp(0.7196852174144444);
    msg.setSource(19620U);
    msg.setSourceEntity(175U);
    msg.setDestination(23741U);
    msg.setDestinationEntity(188U);
    const signed char tmp_msg_0[] = {-38, -44, -96, -17, -38, -91, -70, -90, 31, 59, -73, 25, 85, 70, 126, 11, -85, 113, 103, -11, 72, 91, -12, -25, -33, 84, 48, 14, 101, -7, 97, 56, 15, 56, 5, -24, 90, -42, 47, 106, 34, -77, 64, -105, -66, -59, -106, -81, 22, -71, -88, 109, -12, -25, -24, -65, -85, -33, 34, -57, -114, 109, -108, -52, 123, 25, -78, -17, -79, -33, -84, 7, -58, -54, -128, 75, -125, -93, 65, 25, 51, -50, -80, 108, 122, 17, 126, -120, 98, 52, -58, 10, 76, -63, -107, -43, 30, -8, -116, -100, 83, 57, -104, -69, -15, -57, 107, -109, -10, 112, 94, 21, 101, 39, 34, -76, -89, -4, -128, -59, -126, 9, -114, 122, 79, 41, -65, -79, 112, -93, 27, -107, 100, -111, -24, 25, 17, 34, -61, 92, 53, -18, 69, -126, 61, 68, 125, 80, 112, -38, -12, -112, -92, -95, -86, 65, 5, -45, -101, -115, 100, 107, -48, 76, -90, -89, -37, 68, 19, 96, -27, 110, 69, -28, 101, 106, -92, -110, 118, -84, 86, -103, -44, -44, 103, 109, -76, -91, -53, -57, -121, -113, -113, -112, -23, 0, -67, -116, -103, -14, -103, -55, -30, -66, -10, -30, 88, -4, 76, 110, -7, 60, 65, -106, -85, 0, -10, 42, 60, -36, 52, 19, -116, 30, 16, -99, -54, -32, 58, -44, -69, 24, -72, -6, 14, 125, 18, 3, 1, 18, 69, 40, 119, -107, -95, 18, -92, -8, 58, 89, -3};
    msg.value.assign(tmp_msg_0, tmp_msg_0 + sizeof(tmp_msg_0));

    try
    {
      Utils::ByteBuffer bfr;
      IMC::Packet::serialize(&msg, bfr);
      IMC::Message* msg_d = IMC::Packet::deserialize(bfr.getBuffer(), bfr.getSize());
      test.boolean("DevDataBinary #2", msg == *msg_d);
      delete msg_d;
    }
    catch (IMC::InvalidMessageSize& e)
    {
      (void)e;
      test.boolean("msg #2", msg.getSerializationSize() > DUNE_IMC_CONST_MAX_SIZE);
    }
  }

  {
    IMC::Force msg;
    msg.setTimeStamp(0.3475335457231241);
    msg.setSource(26109U);
    msg.setSourceEntity(169U);
    msg.setDestination(17810U);
    msg.setDestinationEntity(235U);
    msg.value = 0.4186315792410472;

    try
    {
      Utils::ByteBuffer bfr;
      IMC::Packet::serialize(&msg, bfr);
      IMC::Message* msg_d = IMC::Packet::deserialize(bfr.getBuffer(), bfr.getSize());
      test.boolean("Force #0", msg == *msg_d);
      delete msg_d;
    }
    catch (IMC::InvalidMessageSize& e)
    {
      (void)e;
      test.boolean("msg #0", msg.getSerializationSize() > DUNE_IMC_CONST_MAX_SIZE);
    }
  }

  {
    IMC::Force msg;
    msg.setTimeStamp(0.31894831058111117);
    msg.setSource(14920U);
    msg.setSourceEntity(20U);
    msg.setDestination(44106U);
    msg.setDestinationEntity(216U);
    msg.value = 0.9539287964984992;

    try
    {
      Utils::ByteBuffer bfr;
      IMC::Packet::serialize(&msg, bfr);
      IMC::Message* msg_d = IMC::Packet::deserialize(bfr.getBuffer(), bfr.getSize());
      test.boolean("Force #1", msg == *msg_d);
      delete msg_d;
    }
    catch (IMC::InvalidMessageSize& e)
    {
      (void)e;
      test.boolean("msg #1", msg.getSerializationSize() > DUNE_IMC_CONST_MAX_SIZE);
    }
  }

  {
    IMC::Force msg;
    msg.setTimeStamp(0.007180079649042326);
    msg.setSource(46740U);
    msg.setSourceEntity(241U);
    msg.setDestination(58793U);
    msg.setDestinationEntity(190U);
    msg.value = 0.1522625568546655;

    try
    {
      Utils::ByteBuffer bfr;
      IMC::Packet::serialize(&msg, bfr);
      IMC::Message* msg_d = IMC::Packet::deserialize(bfr.getBuffer(), bfr.getSize());
      test.boolean("Force #2", msg == *msg_d);
      delete msg_d;
    }
    catch (IMC::InvalidMessageSize& e)
    {
      (void)e;
      test.boolean("msg #2", msg.getSerializationSize() > DUNE_IMC_CONST_MAX_SIZE);
    }
  }

  {
    IMC::SonarData msg;
    msg.setTimeStamp(0.10680232718386085);
    msg.setSource(20669U);
    msg.setSourceEntity(129U);
    msg.setDestination(4467U);
    msg.setDestinationEntity(242U);
    msg.type = 132U;
    msg.frequency = 3799704081U;
    msg.min_range = 27590U;
    msg.max_range = 49265U;
    msg.bits_per_point = 128U;
    msg.scale_factor = 0.8192407643059981;
    IMC::BeamConfig tmp_msg_0;
    tmp_msg_0.beam_width = 0.1409800507047243;
    tmp_msg_0.beam_height = 0.8154209253503706;
    msg.beam_config.push_back(tmp_msg_0);
    const signed char tmp_msg_1[] = {55, 74, -49, -41, -23, -8, -32, -107, -55, 93, 26, 122, 64, -112, -117, -49, 53, 51, 123, 82, 20, -60, -121, 121, -113, 115, -110, 13, -78, -52, -51, -41, 100, 14, -69, -32, -70, -13, 16, 2, 55, 61, -58, -95, 120, -100, 24, 55, -104, -97, -26, 20, -99, 23, 76, -62, 106, -113, 22, 91, -57, -75, -83, 98, -8, 52, -111, -43, 17, -6, -83, -64, -41, 68, 111, -72, -56, -117, 34, -27, -11, 119, -38, 69, 47, -14, -16, -119, 1, -11, 18, 108, 19, -74, -124, 42, 66};
    msg.data.assign(tmp_msg_1, tmp_msg_1 + sizeof(tmp_msg_1));

    try
    {
      Utils::ByteBuffer bfr;
      IMC::Packet::serialize(&msg, bfr);
      IMC::Message* msg_d = IMC::Packet::deserialize(bfr.getBuffer(), bfr.getSize());
      test.boolean("SonarData #0", msg == *msg_d);
      delete msg_d;
    }
    catch (IMC::InvalidMessageSize& e)
    {
      (void)e;
      test.boolean("msg #0", msg.getSerializationSize() > DUNE_IMC_CONST_MAX_SIZE);
    }
  }

  {
    IMC::SonarData msg;
    msg.setTimeStamp(0.7518126576252661);
    msg.setSource(64667U);
    msg.setSourceEntity(100U);
    msg.setDestination(54092U);
    msg.setDestinationEntity(28U);
    msg.type = 4U;
    msg.frequency = 4125947462U;
    msg.min_range = 40430U;
    msg.max_range = 34182U;
    msg.bits_per_point = 4U;
    msg.scale_factor = 0.4444471149809498;
    const signed char tmp_msg_0[] = {-22, 37, 75, -26, -122, 112, -43, -13, 56, -91, 66, 24, -126, 100, -69, -122, 95, -110, -97, 86, -81, 98, -100, 80, -71, -89, -46, 14, -50, 61, -50, -117, -128, -23, -48, 8, 17, 74, 102, -110, 8, 5, -12, -97, 61, 35, -79, 30, 13, -38, 26, -21, 117, -99, -77, -108, -56, 69, 66, -11, 50, -45, -67, 45, 14, -35, 33, 96, -29, -42, 97, -72, -124, -44, -45, -64, -103, -17, -41, 37, -52, 38, 43, -107, 46, 38, 0, -111, 79, 64, -25, -41, -107, -7};
    msg.data.assign(tmp_msg_0, tmp_msg_0 + sizeof(tmp_msg_0));

    try
    {
      Utils::ByteBuffer bfr;
      IMC::Packet::serialize(&msg, bfr);
      IMC::Message* msg_d = IMC::Packet::deserialize(bfr.getBuffer(), bfr.getSize());
      test.boolean("SonarData #1", msg == *msg_d);
      delete msg_d;
    }
    catch (IMC::InvalidMessageSize& e)
    {
      (void)e;
      test.boolean("msg #1", msg.getSerializationSize() > DUNE_IMC_CONST_MAX_SIZE);
    }
  }

  {
    IMC::SonarData msg;
    msg.setTimeStamp(0.272713151072037);
    msg.setSource(10291U);
    msg.setSourceEntity(182U);
    msg.setDestination(5651U);
    msg.setDestinationEntity(125U);
    msg.type = 212U;
    msg.frequency = 3269657849U;
    msg.min_range = 41451U;
    msg.max_range = 60265U;
    msg.bits_per_point = 120U;
    msg.scale_factor = 0.6261416041509186;
    IMC::BeamConfig tmp_msg_0;
    tmp_msg_0.beam_width = 0.2908248420245144;
    tmp_msg_0.beam_height = 0.11546560914469473;
    msg.beam_config.push_back(tmp_msg_0);
    const signed char tmp_msg_1[] = {-72, 50, 73, 67, 41, -70, 113, 107, 35, 25, 126, 79, -63, 11, 93, -84};
    msg.data.assign(tmp_msg_1, tmp_msg_1 + sizeof(tmp_msg_1));

    try
    {
      Utils::ByteBuffer bfr;
      IMC::Packet::serialize(&msg, bfr);
      IMC::Message* msg_d = IMC::Packet::deserialize(bfr.getBuffer(), bfr.getSize());
      test.boolean("SonarData #2", msg == *msg_d);
      delete msg_d;
    }
    catch (IMC::InvalidMessageSize& e)
    {
      (void)e;
      test.boolean("msg #2", msg.getSerializationSize() > DUNE_IMC_CONST_MAX_SIZE);
    }
  }

  {
    IMC::Pulse msg;
    msg.setTimeStamp(0.6201140793537723);
    msg.setSource(16350U);
    msg.setSourceEntity(68U);
    msg.setDestination(27663U);
    msg.setDestinationEntity(50U);

    try
    {
      Utils::ByteBuffer bfr;
      IMC::Packet::serialize(&msg, bfr);
      IMC::Message* msg_d = IMC::Packet::deserialize(bfr.getBuffer(), bfr.getSize());
      test.boolean("Pulse #0", msg == *msg_d);
      delete msg_d;
    }
    catch (IMC::InvalidMessageSize& e)
    {
      (void)e;
      test.boolean("msg #0", msg.getSerializationSize() > DUNE_IMC_CONST_MAX_SIZE);
    }
  }

  {
    IMC::Pulse msg;
    msg.setTimeStamp(0.7993699110335976);
    msg.setSource(8797U);
    msg.setSourceEntity(228U);
    msg.setDestination(28833U);
    msg.setDestinationEntity(80U);

    try
    {
      Utils::ByteBuffer bfr;
      IMC::Packet::serialize(&msg, bfr);
      IMC::Message* msg_d = IMC::Packet::deserialize(bfr.getBuffer(), bfr.getSize());
      test.boolean("Pulse #1", msg == *msg_d);
      delete msg_d;
    }
    catch (IMC::InvalidMessageSize& e)
    {
      (void)e;
      test.boolean("msg #1", msg.getSerializationSize() > DUNE_IMC_CONST_MAX_SIZE);
    }
  }

  {
    IMC::Pulse msg;
    msg.setTimeStamp(0.8570659751749997);
    msg.setSource(1044U);
    msg.setSourceEntity(17U);
    msg.setDestination(37833U);
    msg.setDestinationEntity(22U);

    try
    {
      Utils::ByteBuffer bfr;
      IMC::Packet::serialize(&msg, bfr);
      IMC::Message* msg_d = IMC::Packet::deserialize(bfr.getBuffer(), bfr.getSize());
      test.boolean("Pulse #2", msg == *msg_d);
      delete msg_d;
    }
    catch (IMC::InvalidMessageSize& e)
    {
      (void)e;
      test.boolean("msg #2", msg.getSerializationSize() > DUNE_IMC_CONST_MAX_SIZE);
    }
  }

  {
    IMC::PulseDetectionControl msg;
    msg.setTimeStamp(0.4851192306764336);
    msg.setSource(15497U);
    msg.setSourceEntity(27U);
    msg.setDestination(22509U);
    msg.setDestinationEntity(155U);
    msg.op = 226U;

    try
    {
      Utils::ByteBuffer bfr;
      IMC::Packet::serialize(&msg, bfr);
      IMC::Message* msg_d = IMC::Packet::deserialize(bfr.getBuffer(), bfr.getSize());
      test.boolean("PulseDetectionControl #0", msg == *msg_d);
      delete msg_d;
    }
    catch (IMC::InvalidMessageSize& e)
    {
      (void)e;
      test.boolean("msg #0", msg.getSerializationSize() > DUNE_IMC_CONST_MAX_SIZE);
    }
  }

  {
    IMC::PulseDetectionControl msg;
    msg.setTimeStamp(0.20855889112218406);
    msg.setSource(28519U);
    msg.setSourceEntity(86U);
    msg.setDestination(42051U);
    msg.setDestinationEntity(77U);
    msg.op = 227U;

    try
    {
      Utils::ByteBuffer bfr;
      IMC::Packet::serialize(&msg, bfr);
      IMC::Message* msg_d = IMC::Packet::deserialize(bfr.getBuffer(), bfr.getSize());
      test.boolean("PulseDetectionControl #1", msg == *msg_d);
      delete msg_d;
    }
    catch (IMC::InvalidMessageSize& e)
    {
      (void)e;
      test.boolean("msg #1", msg.getSerializationSize() > DUNE_IMC_CONST_MAX_SIZE);
    }
  }

  {
    IMC::PulseDetectionControl msg;
    msg.setTimeStamp(0.3359655896140594);
    msg.setSource(64001U);
    msg.setSourceEntity(218U);
    msg.setDestination(18875U);
    msg.setDestinationEntity(162U);
    msg.op = 232U;

    try
    {
      Utils::ByteBuffer bfr;
      IMC::Packet::serialize(&msg, bfr);
      IMC::Message* msg_d = IMC::Packet::deserialize(bfr.getBuffer(), bfr.getSize());
      test.boolean("PulseDetectionControl #2", msg == *msg_d);
      delete msg_d;
    }
    catch (IMC::InvalidMessageSize& e)
    {
      (void)e;
      test.boolean("msg #2", msg.getSerializationSize() > DUNE_IMC_CONST_MAX_SIZE);
    }
  }

  {
    IMC::FuelLevel msg;
    msg.setTimeStamp(0.2787340046092909);
    msg.setSource(65465U);
    msg.setSourceEntity(167U);
    msg.setDestination(26101U);
    msg.setDestinationEntity(210U);
    msg.value = 0.643559870997646;
    msg.confidence = 0.4298692682911136;
    msg.opmodes.assign("NGLUPKGOOUHTNLHYCFMWOXKYKIGNEWDAJKVTDJFUHJIRIOLSBBZWYZTXWGRYHNPLPZVZOUDLBDZWZTERPEXIVQVCSPXFCQGOXQDNEDSWOOSEQJOBJBJVZIPYQPOMRRAZMQVBFQEPEPFAXDFUWMYZGA");

    try
    {
      Utils::ByteBuffer bfr;
      IMC::Packet::serialize(&msg, bfr);
      IMC::Message* msg_d = IMC::Packet::deserialize(bfr.getBuffer(), bfr.getSize());
      test.boolean("FuelLevel #0", msg == *msg_d);
      delete msg_d;
    }
    catch (IMC::InvalidMessageSize& e)
    {
      (void)e;
      test.boolean("msg #0", msg.getSerializationSize() > DUNE_IMC_CONST_MAX_SIZE);
    }
  }

  {
    IMC::FuelLevel msg;
    msg.setTimeStamp(0.9329639214022989);
    msg.setSource(40382U);
    msg.setSourceEntity(207U);
    msg.setDestination(16283U);
    msg.setDestinationEntity(176U);
    msg.value = 0.35069983377636815;
    msg.confidence = 0.8152183802496589;
    msg.opmodes.assign("MIZIKJLCCJTRULOCMTVNFIYDVBBPLUSDIHACLHANEBNTAPGIRXJYFZPZAZDGFHBIQCKNXPGXFFNLSUFNXXOIJSQMEKVTKOUFPESJVZQVVWYDRRBBAZCKSKEZZPYHWSLNCYWRBJKLTQVEGQRYNKHTOVBOAWOTJHDLHMELMXOPGNQZGDPMGXQRDEAASFIBXHRFDCWQUSHTTLAPGHRERXIFXMZCWEWEDYQYSGUMAQOWOTJKGYNIJD");

    try
    {
      Utils::ByteBuffer bfr;
      IMC::Packet::serialize(&msg, bfr);
      IMC::Message* msg_d = IMC::Packet::deserialize(bfr.getBuffer(), bfr.getSize());
      test.boolean("FuelLevel #1", msg == *msg_d);
      delete msg_d;
    }
    catch (IMC::InvalidMessageSize& e)
    {
      (void)e;
      test.boolean("msg #1", msg.getSerializationSize() > DUNE_IMC_CONST_MAX_SIZE);
    }
  }

  {
    IMC::FuelLevel msg;
    msg.setTimeStamp(0.8866150543038301);
    msg.setSource(52007U);
    msg.setSourceEntity(228U);
    msg.setDestination(16434U);
    msg.setDestinationEntity(36U);
    msg.value = 0.5727006304292529;
    msg.confidence = 0.2365218669623177;
    msg.opmodes.assign("SYWLWVFROJSFXYPDHVMWMQCATYULXBCIIOKYGJPJTBJQVNSWEHPZZXHGDPBRUOOHEXQUHXOEPCVMGNARLKKBTJUKRMWTASEZWMRSVDHIZUPEXLMSFKIUYMKCJFQIDSTPUVXUCKJZIBOZLATHSRWYTOPCBZZZRXEYDTY");

    try
    {
      Utils::ByteBuffer bfr;
      IMC::Packet::serialize(&msg, bfr);
      IMC::Message* msg_d = IMC::Packet::deserialize(bfr.getBuffer(), bfr.getSize());
      test.boolean("FuelLevel #2", msg == *msg_d);
      delete msg_d;
    }
    catch (IMC::InvalidMessageSize& e)
    {
      (void)e;
      test.boolean("msg #2", msg.getSerializationSize() > DUNE_IMC_CONST_MAX_SIZE);
    }
  }

  {
    IMC::GpsNavData msg;
    msg.setTimeStamp(0.5485475090368591);
    msg.setSource(58524U);
    msg.setSourceEntity(125U);
    msg.setDestination(33834U);
    msg.setDestinationEntity(222U);
    msg.itow = 2766316949U;
    msg.lat = 0.25193746065767564;
    msg.lon = 0.8503842801085436;
    msg.height_ell = 0.9457925486959694;
    msg.height_sea = 0.7818293370951602;
    msg.hacc = 0.9346758702250741;
    msg.vacc = 0.8732771652960805;
    msg.vel_n = 0.24704503492001517;
    msg.vel_e = 0.2999744466223022;
    msg.vel_d = 0.5053709155969607;
    msg.speed = 0.5537305709969634;
    msg.gspeed = 0.04026374288234402;
    msg.heading = 0.8063477407471562;
    msg.sacc = 0.40736681715657075;
    msg.cacc = 0.8570817501462827;

    try
    {
      Utils::ByteBuffer bfr;
      IMC::Packet::serialize(&msg, bfr);
      IMC::Message* msg_d = IMC::Packet::deserialize(bfr.getBuffer(), bfr.getSize());
      test.boolean("GpsNavData #0", msg == *msg_d);
      delete msg_d;
    }
    catch (IMC::InvalidMessageSize& e)
    {
      (void)e;
      test.boolean("msg #0", msg.getSerializationSize() > DUNE_IMC_CONST_MAX_SIZE);
    }
  }

  {
    IMC::GpsNavData msg;
    msg.setTimeStamp(0.1222807978476792);
    msg.setSource(29217U);
    msg.setSourceEntity(155U);
    msg.setDestination(44208U);
    msg.setDestinationEntity(196U);
    msg.itow = 3781643789U;
    msg.lat = 0.13974458829626124;
    msg.lon = 0.8384426869907212;
    msg.height_ell = 0.4155419568358085;
    msg.height_sea = 0.9407041487692684;
    msg.hacc = 0.3291853500610553;
    msg.vacc = 0.3877217502202006;
    msg.vel_n = 0.05490720803875737;
    msg.vel_e = 0.4849891107040696;
    msg.vel_d = 0.022266254041639066;
    msg.speed = 0.7832345520368218;
    msg.gspeed = 0.26992916839627357;
    msg.heading = 0.3539323705104659;
    msg.sacc = 0.17349408601876248;
    msg.cacc = 0.667439114142261;

    try
    {
      Utils::ByteBuffer bfr;
      IMC::Packet::serialize(&msg, bfr);
      IMC::Message* msg_d = IMC::Packet::deserialize(bfr.getBuffer(), bfr.getSize());
      test.boolean("GpsNavData #1", msg == *msg_d);
      delete msg_d;
    }
    catch (IMC::InvalidMessageSize& e)
    {
      (void)e;
      test.boolean("msg #1", msg.getSerializationSize() > DUNE_IMC_CONST_MAX_SIZE);
    }
  }

  {
    IMC::GpsNavData msg;
    msg.setTimeStamp(0.8878093578962106);
    msg.setSource(1182U);
    msg.setSourceEntity(109U);
    msg.setDestination(38669U);
    msg.setDestinationEntity(64U);
    msg.itow = 949097561U;
    msg.lat = 0.35608352577368385;
    msg.lon = 0.04318004570212364;
    msg.height_ell = 0.06924844531178365;
    msg.height_sea = 0.023781265345553138;
    msg.hacc = 0.2763476563584002;
    msg.vacc = 0.8441033146924686;
    msg.vel_n = 0.4045952108697126;
    msg.vel_e = 0.2876796334348388;
    msg.vel_d = 0.13164184364088027;
    msg.speed = 0.8124314798585042;
    msg.gspeed = 0.6785676113974809;
    msg.heading = 0.7054257763709622;
    msg.sacc = 0.36042797827276996;
    msg.cacc = 0.15650651486546052;

    try
    {
      Utils::ByteBuffer bfr;
      IMC::Packet::serialize(&msg, bfr);
      IMC::Message* msg_d = IMC::Packet::deserialize(bfr.getBuffer(), bfr.getSize());
      test.boolean("GpsNavData #2", msg == *msg_d);
      delete msg_d;
    }
    catch (IMC::InvalidMessageSize& e)
    {
      (void)e;
      test.boolean("msg #2", msg.getSerializationSize() > DUNE_IMC_CONST_MAX_SIZE);
    }
  }

  {
    IMC::ServoPosition msg;
    msg.setTimeStamp(0.44884242699041543);
    msg.setSource(36370U);
    msg.setSourceEntity(39U);
    msg.setDestination(19514U);
    msg.setDestinationEntity(111U);
    msg.id = 115U;
    msg.value = 0.2567404090957578;

    try
    {
      Utils::ByteBuffer bfr;
      IMC::Packet::serialize(&msg, bfr);
      IMC::Message* msg_d = IMC::Packet::deserialize(bfr.getBuffer(), bfr.getSize());
      test.boolean("ServoPosition #0", msg == *msg_d);
      delete msg_d;
    }
    catch (IMC::InvalidMessageSize& e)
    {
      (void)e;
      test.boolean("msg #0", msg.getSerializationSize() > DUNE_IMC_CONST_MAX_SIZE);
    }
  }

  {
    IMC::ServoPosition msg;
    msg.setTimeStamp(0.9200535794696857);
    msg.setSource(2141U);
    msg.setSourceEntity(240U);
    msg.setDestination(9084U);
    msg.setDestinationEntity(54U);
    msg.id = 178U;
    msg.value = 0.8335966502851904;

    try
    {
      Utils::ByteBuffer bfr;
      IMC::Packet::serialize(&msg, bfr);
      IMC::Message* msg_d = IMC::Packet::deserialize(bfr.getBuffer(), bfr.getSize());
      test.boolean("ServoPosition #1", msg == *msg_d);
      delete msg_d;
    }
    catch (IMC::InvalidMessageSize& e)
    {
      (void)e;
      test.boolean("msg #1", msg.getSerializationSize() > DUNE_IMC_CONST_MAX_SIZE);
    }
  }

  {
    IMC::ServoPosition msg;
    msg.setTimeStamp(0.16840205791284235);
    msg.setSource(28056U);
    msg.setSourceEntity(148U);
    msg.setDestination(29365U);
    msg.setDestinationEntity(184U);
    msg.id = 51U;
    msg.value = 0.8447204575735584;

    try
    {
      Utils::ByteBuffer bfr;
      IMC::Packet::serialize(&msg, bfr);
      IMC::Message* msg_d = IMC::Packet::deserialize(bfr.getBuffer(), bfr.getSize());
      test.boolean("ServoPosition #2", msg == *msg_d);
      delete msg_d;
    }
    catch (IMC::InvalidMessageSize& e)
    {
      (void)e;
      test.boolean("msg #2", msg.getSerializationSize() > DUNE_IMC_CONST_MAX_SIZE);
    }
  }

  {
    IMC::DeviceState msg;
    msg.setTimeStamp(0.728328621209155);
    msg.setSource(14526U);
    msg.setSourceEntity(208U);
    msg.setDestination(43547U);
    msg.setDestinationEntity(13U);
    msg.x = 0.050923480435671076;
    msg.y = 0.06435370243980487;
    msg.z = 0.44061949653091226;
    msg.phi = 0.13985068900602005;
    msg.theta = 0.0314252795090294;
    msg.psi = 0.9109583526810363;

    try
    {
      Utils::ByteBuffer bfr;
      IMC::Packet::serialize(&msg, bfr);
      IMC::Message* msg_d = IMC::Packet::deserialize(bfr.getBuffer(), bfr.getSize());
      test.boolean("DeviceState #0", msg == *msg_d);
      delete msg_d;
    }
    catch (IMC::InvalidMessageSize& e)
    {
      (void)e;
      test.boolean("msg #0", msg.getSerializationSize() > DUNE_IMC_CONST_MAX_SIZE);
    }
  }

  {
    IMC::DeviceState msg;
    msg.setTimeStamp(0.26793323915147194);
    msg.setSource(20344U);
    msg.setSourceEntity(117U);
    msg.setDestination(15608U);
    msg.setDestinationEntity(172U);
    msg.x = 0.9041037286169208;
    msg.y = 0.655823713521196;
    msg.z = 0.5525499786119991;
    msg.phi = 0.7909672786699543;
    msg.theta = 0.7680904045870649;
    msg.psi = 0.5610306308179641;

    try
    {
      Utils::ByteBuffer bfr;
      IMC::Packet::serialize(&msg, bfr);
      IMC::Message* msg_d = IMC::Packet::deserialize(bfr.getBuffer(), bfr.getSize());
      test.boolean("DeviceState #1", msg == *msg_d);
      delete msg_d;
    }
    catch (IMC::InvalidMessageSize& e)
    {
      (void)e;
      test.boolean("msg #1", msg.getSerializationSize() > DUNE_IMC_CONST_MAX_SIZE);
    }
  }

  {
    IMC::DeviceState msg;
    msg.setTimeStamp(0.5569590715389775);
    msg.setSource(45754U);
    msg.setSourceEntity(59U);
    msg.setDestination(22836U);
    msg.setDestinationEntity(66U);
    msg.x = 0.38822106229777475;
    msg.y = 0.28718991615981504;
    msg.z = 0.8632217339921426;
    msg.phi = 0.8168215335546561;
    msg.theta = 0.936048189798961;
    msg.psi = 0.6601447586035452;

    try
    {
      Utils::ByteBuffer bfr;
      IMC::Packet::serialize(&msg, bfr);
      IMC::Message* msg_d = IMC::Packet::deserialize(bfr.getBuffer(), bfr.getSize());
      test.boolean("DeviceState #2", msg == *msg_d);
      delete msg_d;
    }
    catch (IMC::InvalidMessageSize& e)
    {
      (void)e;
      test.boolean("msg #2", msg.getSerializationSize() > DUNE_IMC_CONST_MAX_SIZE);
    }
  }

  {
    IMC::BeamConfig msg;
    msg.setTimeStamp(0.04644661722891241);
    msg.setSource(41525U);
    msg.setSourceEntity(51U);
    msg.setDestination(60106U);
    msg.setDestinationEntity(112U);
    msg.beam_width = 0.1199938463754815;
    msg.beam_height = 0.32677532224292016;

    try
    {
      Utils::ByteBuffer bfr;
      IMC::Packet::serialize(&msg, bfr);
      IMC::Message* msg_d = IMC::Packet::deserialize(bfr.getBuffer(), bfr.getSize());
      test.boolean("BeamConfig #0", msg == *msg_d);
      delete msg_d;
    }
    catch (IMC::InvalidMessageSize& e)
    {
      (void)e;
      test.boolean("msg #0", msg.getSerializationSize() > DUNE_IMC_CONST_MAX_SIZE);
    }
  }

  {
    IMC::BeamConfig msg;
    msg.setTimeStamp(0.6907907161398179);
    msg.setSource(56502U);
    msg.setSourceEntity(112U);
    msg.setDestination(46970U);
    msg.setDestinationEntity(193U);
    msg.beam_width = 0.37496790710708183;
    msg.beam_height = 0.40973055852647244;

    try
    {
      Utils::ByteBuffer bfr;
      IMC::Packet::serialize(&msg, bfr);
      IMC::Message* msg_d = IMC::Packet::deserialize(bfr.getBuffer(), bfr.getSize());
      test.boolean("BeamConfig #1", msg == *msg_d);
      delete msg_d;
    }
    catch (IMC::InvalidMessageSize& e)
    {
      (void)e;
      test.boolean("msg #1", msg.getSerializationSize() > DUNE_IMC_CONST_MAX_SIZE);
    }
  }

  {
    IMC::BeamConfig msg;
    msg.setTimeStamp(0.34440610617060785);
    msg.setSource(5214U);
    msg.setSourceEntity(23U);
    msg.setDestination(8055U);
    msg.setDestinationEntity(233U);
    msg.beam_width = 0.5893700160298989;
    msg.beam_height = 0.05275050570844375;

    try
    {
      Utils::ByteBuffer bfr;
      IMC::Packet::serialize(&msg, bfr);
      IMC::Message* msg_d = IMC::Packet::deserialize(bfr.getBuffer(), bfr.getSize());
      test.boolean("BeamConfig #2", msg == *msg_d);
      delete msg_d;
    }
    catch (IMC::InvalidMessageSize& e)
    {
      (void)e;
      test.boolean("msg #2", msg.getSerializationSize() > DUNE_IMC_CONST_MAX_SIZE);
    }
  }

  {
    IMC::DataSanity msg;
    msg.setTimeStamp(0.5853927477666683);
    msg.setSource(61313U);
    msg.setSourceEntity(35U);
    msg.setDestination(16290U);
    msg.setDestinationEntity(234U);
    msg.sane = 175U;

    try
    {
      Utils::ByteBuffer bfr;
      IMC::Packet::serialize(&msg, bfr);
      IMC::Message* msg_d = IMC::Packet::deserialize(bfr.getBuffer(), bfr.getSize());
      test.boolean("DataSanity #0", msg == *msg_d);
      delete msg_d;
    }
    catch (IMC::InvalidMessageSize& e)
    {
      (void)e;
      test.boolean("msg #0", msg.getSerializationSize() > DUNE_IMC_CONST_MAX_SIZE);
    }
  }

  {
    IMC::DataSanity msg;
    msg.setTimeStamp(0.060814132405867416);
    msg.setSource(60532U);
    msg.setSourceEntity(141U);
    msg.setDestination(44892U);
    msg.setDestinationEntity(171U);
    msg.sane = 157U;

    try
    {
      Utils::ByteBuffer bfr;
      IMC::Packet::serialize(&msg, bfr);
      IMC::Message* msg_d = IMC::Packet::deserialize(bfr.getBuffer(), bfr.getSize());
      test.boolean("DataSanity #1", msg == *msg_d);
      delete msg_d;
    }
    catch (IMC::InvalidMessageSize& e)
    {
      (void)e;
      test.boolean("msg #1", msg.getSerializationSize() > DUNE_IMC_CONST_MAX_SIZE);
    }
  }

  {
    IMC::DataSanity msg;
    msg.setTimeStamp(0.7608813547538666);
    msg.setSource(47809U);
    msg.setSourceEntity(65U);
    msg.setDestination(13985U);
    msg.setDestinationEntity(28U);
    msg.sane = 208U;

    try
    {
      Utils::ByteBuffer bfr;
      IMC::Packet::serialize(&msg, bfr);
      IMC::Message* msg_d = IMC::Packet::deserialize(bfr.getBuffer(), bfr.getSize());
      test.boolean("DataSanity #2", msg == *msg_d);
      delete msg_d;
    }
    catch (IMC::InvalidMessageSize& e)
    {
      (void)e;
      test.boolean("msg #2", msg.getSerializationSize() > DUNE_IMC_CONST_MAX_SIZE);
    }
  }

  {
    IMC::RhodamineDye msg;
    msg.setTimeStamp(0.9543286645835294);
    msg.setSource(54122U);
    msg.setSourceEntity(166U);
    msg.setDestination(58314U);
    msg.setDestinationEntity(23U);
    msg.value = 0.6558284177261239;

    try
    {
      Utils::ByteBuffer bfr;
      IMC::Packet::serialize(&msg, bfr);
      IMC::Message* msg_d = IMC::Packet::deserialize(bfr.getBuffer(), bfr.getSize());
      test.boolean("RhodamineDye #0", msg == *msg_d);
      delete msg_d;
    }
    catch (IMC::InvalidMessageSize& e)
    {
      (void)e;
      test.boolean("msg #0", msg.getSerializationSize() > DUNE_IMC_CONST_MAX_SIZE);
    }
  }

  {
    IMC::RhodamineDye msg;
    msg.setTimeStamp(0.79441463291613);
    msg.setSource(55361U);
    msg.setSourceEntity(80U);
    msg.setDestination(2928U);
    msg.setDestinationEntity(184U);
    msg.value = 0.5292548364525316;

    try
    {
      Utils::ByteBuffer bfr;
      IMC::Packet::serialize(&msg, bfr);
      IMC::Message* msg_d = IMC::Packet::deserialize(bfr.getBuffer(), bfr.getSize());
      test.boolean("RhodamineDye #1", msg == *msg_d);
      delete msg_d;
    }
    catch (IMC::InvalidMessageSize& e)
    {
      (void)e;
      test.boolean("msg #1", msg.getSerializationSize() > DUNE_IMC_CONST_MAX_SIZE);
    }
  }

  {
    IMC::RhodamineDye msg;
    msg.setTimeStamp(0.193648236689983);
    msg.setSource(38540U);
    msg.setSourceEntity(231U);
    msg.setDestination(13237U);
    msg.setDestinationEntity(100U);
    msg.value = 0.8749733197537234;

    try
    {
      Utils::ByteBuffer bfr;
      IMC::Packet::serialize(&msg, bfr);
      IMC::Message* msg_d = IMC::Packet::deserialize(bfr.getBuffer(), bfr.getSize());
      test.boolean("RhodamineDye #2", msg == *msg_d);
      delete msg_d;
    }
    catch (IMC::InvalidMessageSize& e)
    {
      (void)e;
      test.boolean("msg #2", msg.getSerializationSize() > DUNE_IMC_CONST_MAX_SIZE);
    }
  }

  {
    IMC::CrudeOil msg;
    msg.setTimeStamp(0.18724455444203925);
    msg.setSource(25236U);
    msg.setSourceEntity(75U);
    msg.setDestination(15062U);
    msg.setDestinationEntity(22U);
    msg.value = 0.7404989308583807;

    try
    {
      Utils::ByteBuffer bfr;
      IMC::Packet::serialize(&msg, bfr);
      IMC::Message* msg_d = IMC::Packet::deserialize(bfr.getBuffer(), bfr.getSize());
      test.boolean("CrudeOil #0", msg == *msg_d);
      delete msg_d;
    }
    catch (IMC::InvalidMessageSize& e)
    {
      (void)e;
      test.boolean("msg #0", msg.getSerializationSize() > DUNE_IMC_CONST_MAX_SIZE);
    }
  }

  {
    IMC::CrudeOil msg;
    msg.setTimeStamp(0.8697110942516526);
    msg.setSource(51632U);
    msg.setSourceEntity(244U);
    msg.setDestination(30376U);
    msg.setDestinationEntity(103U);
    msg.value = 0.37091326855085094;

    try
    {
      Utils::ByteBuffer bfr;
      IMC::Packet::serialize(&msg, bfr);
      IMC::Message* msg_d = IMC::Packet::deserialize(bfr.getBuffer(), bfr.getSize());
      test.boolean("CrudeOil #1", msg == *msg_d);
      delete msg_d;
    }
    catch (IMC::InvalidMessageSize& e)
    {
      (void)e;
      test.boolean("msg #1", msg.getSerializationSize() > DUNE_IMC_CONST_MAX_SIZE);
    }
  }

  {
    IMC::CrudeOil msg;
    msg.setTimeStamp(0.7639486373850075);
    msg.setSource(3696U);
    msg.setSourceEntity(219U);
    msg.setDestination(15353U);
    msg.setDestinationEntity(126U);
    msg.value = 0.6407931149580507;

    try
    {
      Utils::ByteBuffer bfr;
      IMC::Packet::serialize(&msg, bfr);
      IMC::Message* msg_d = IMC::Packet::deserialize(bfr.getBuffer(), bfr.getSize());
      test.boolean("CrudeOil #2", msg == *msg_d);
      delete msg_d;
    }
    catch (IMC::InvalidMessageSize& e)
    {
      (void)e;
      test.boolean("msg #2", msg.getSerializationSize() > DUNE_IMC_CONST_MAX_SIZE);
    }
  }

  {
    IMC::FineOil msg;
    msg.setTimeStamp(0.8027479974566291);
    msg.setSource(22352U);
    msg.setSourceEntity(251U);
    msg.setDestination(31350U);
    msg.setDestinationEntity(152U);
    msg.value = 0.9931123796538215;

    try
    {
      Utils::ByteBuffer bfr;
      IMC::Packet::serialize(&msg, bfr);
      IMC::Message* msg_d = IMC::Packet::deserialize(bfr.getBuffer(), bfr.getSize());
      test.boolean("FineOil #0", msg == *msg_d);
      delete msg_d;
    }
    catch (IMC::InvalidMessageSize& e)
    {
      (void)e;
      test.boolean("msg #0", msg.getSerializationSize() > DUNE_IMC_CONST_MAX_SIZE);
    }
  }

  {
    IMC::FineOil msg;
    msg.setTimeStamp(0.5085260065665596);
    msg.setSource(40623U);
    msg.setSourceEntity(162U);
    msg.setDestination(41086U);
    msg.setDestinationEntity(236U);
    msg.value = 0.2858841609935918;

    try
    {
      Utils::ByteBuffer bfr;
      IMC::Packet::serialize(&msg, bfr);
      IMC::Message* msg_d = IMC::Packet::deserialize(bfr.getBuffer(), bfr.getSize());
      test.boolean("FineOil #1", msg == *msg_d);
      delete msg_d;
    }
    catch (IMC::InvalidMessageSize& e)
    {
      (void)e;
      test.boolean("msg #1", msg.getSerializationSize() > DUNE_IMC_CONST_MAX_SIZE);
    }
  }

  {
    IMC::FineOil msg;
    msg.setTimeStamp(0.36206749510630054);
    msg.setSource(50971U);
    msg.setSourceEntity(202U);
    msg.setDestination(1774U);
    msg.setDestinationEntity(54U);
    msg.value = 0.8103307387073888;

    try
    {
      Utils::ByteBuffer bfr;
      IMC::Packet::serialize(&msg, bfr);
      IMC::Message* msg_d = IMC::Packet::deserialize(bfr.getBuffer(), bfr.getSize());
      test.boolean("FineOil #2", msg == *msg_d);
      delete msg_d;
    }
    catch (IMC::InvalidMessageSize& e)
    {
      (void)e;
      test.boolean("msg #2", msg.getSerializationSize() > DUNE_IMC_CONST_MAX_SIZE);
    }
  }

  {
    IMC::Turbidity msg;
    msg.setTimeStamp(0.1307746430169513);
    msg.setSource(60481U);
    msg.setSourceEntity(36U);
    msg.setDestination(8037U);
    msg.setDestinationEntity(54U);
    msg.value = 0.7381244182787808;

    try
    {
      Utils::ByteBuffer bfr;
      IMC::Packet::serialize(&msg, bfr);
      IMC::Message* msg_d = IMC::Packet::deserialize(bfr.getBuffer(), bfr.getSize());
      test.boolean("Turbidity #0", msg == *msg_d);
      delete msg_d;
    }
    catch (IMC::InvalidMessageSize& e)
    {
      (void)e;
      test.boolean("msg #0", msg.getSerializationSize() > DUNE_IMC_CONST_MAX_SIZE);
    }
  }

  {
    IMC::Turbidity msg;
    msg.setTimeStamp(0.9831689369550841);
    msg.setSource(44661U);
    msg.setSourceEntity(135U);
    msg.setDestination(50733U);
    msg.setDestinationEntity(232U);
    msg.value = 0.23574412091218577;

    try
    {
      Utils::ByteBuffer bfr;
      IMC::Packet::serialize(&msg, bfr);
      IMC::Message* msg_d = IMC::Packet::deserialize(bfr.getBuffer(), bfr.getSize());
      test.boolean("Turbidity #1", msg == *msg_d);
      delete msg_d;
    }
    catch (IMC::InvalidMessageSize& e)
    {
      (void)e;
      test.boolean("msg #1", msg.getSerializationSize() > DUNE_IMC_CONST_MAX_SIZE);
    }
  }

  {
    IMC::Turbidity msg;
    msg.setTimeStamp(0.35585310061806763);
    msg.setSource(33125U);
    msg.setSourceEntity(167U);
    msg.setDestination(36124U);
    msg.setDestinationEntity(182U);
    msg.value = 0.3908132007784023;

    try
    {
      Utils::ByteBuffer bfr;
      IMC::Packet::serialize(&msg, bfr);
      IMC::Message* msg_d = IMC::Packet::deserialize(bfr.getBuffer(), bfr.getSize());
      test.boolean("Turbidity #2", msg == *msg_d);
      delete msg_d;
    }
    catch (IMC::InvalidMessageSize& e)
    {
      (void)e;
      test.boolean("msg #2", msg.getSerializationSize() > DUNE_IMC_CONST_MAX_SIZE);
    }
  }

  {
    IMC::Chlorophyll msg;
    msg.setTimeStamp(0.7433374437000226);
    msg.setSource(59116U);
    msg.setSourceEntity(74U);
    msg.setDestination(9161U);
    msg.setDestinationEntity(159U);
    msg.value = 0.9931835754826625;

    try
    {
      Utils::ByteBuffer bfr;
      IMC::Packet::serialize(&msg, bfr);
      IMC::Message* msg_d = IMC::Packet::deserialize(bfr.getBuffer(), bfr.getSize());
      test.boolean("Chlorophyll #0", msg == *msg_d);
      delete msg_d;
    }
    catch (IMC::InvalidMessageSize& e)
    {
      (void)e;
      test.boolean("msg #0", msg.getSerializationSize() > DUNE_IMC_CONST_MAX_SIZE);
    }
  }

  {
    IMC::Chlorophyll msg;
    msg.setTimeStamp(0.9629673504056789);
    msg.setSource(50163U);
    msg.setSourceEntity(251U);
    msg.setDestination(23232U);
    msg.setDestinationEntity(254U);
    msg.value = 0.3095354162246676;

    try
    {
      Utils::ByteBuffer bfr;
      IMC::Packet::serialize(&msg, bfr);
      IMC::Message* msg_d = IMC::Packet::deserialize(bfr.getBuffer(), bfr.getSize());
      test.boolean("Chlorophyll #1", msg == *msg_d);
      delete msg_d;
    }
    catch (IMC::InvalidMessageSize& e)
    {
      (void)e;
      test.boolean("msg #1", msg.getSerializationSize() > DUNE_IMC_CONST_MAX_SIZE);
    }
  }

  {
    IMC::Chlorophyll msg;
    msg.setTimeStamp(0.4627500542168913);
    msg.setSource(23307U);
    msg.setSourceEntity(127U);
    msg.setDestination(50582U);
    msg.setDestinationEntity(223U);
    msg.value = 0.6626700788868024;

    try
    {
      Utils::ByteBuffer bfr;
      IMC::Packet::serialize(&msg, bfr);
      IMC::Message* msg_d = IMC::Packet::deserialize(bfr.getBuffer(), bfr.getSize());
      test.boolean("Chlorophyll #2", msg == *msg_d);
      delete msg_d;
    }
    catch (IMC::InvalidMessageSize& e)
    {
      (void)e;
      test.boolean("msg #2", msg.getSerializationSize() > DUNE_IMC_CONST_MAX_SIZE);
    }
  }

  {
    IMC::Fluorescein msg;
    msg.setTimeStamp(0.4984414403698232);
    msg.setSource(7283U);
    msg.setSourceEntity(185U);
    msg.setDestination(41544U);
    msg.setDestinationEntity(149U);
    msg.value = 0.44523913771311274;

    try
    {
      Utils::ByteBuffer bfr;
      IMC::Packet::serialize(&msg, bfr);
      IMC::Message* msg_d = IMC::Packet::deserialize(bfr.getBuffer(), bfr.getSize());
      test.boolean("Fluorescein #0", msg == *msg_d);
      delete msg_d;
    }
    catch (IMC::InvalidMessageSize& e)
    {
      (void)e;
      test.boolean("msg #0", msg.getSerializationSize() > DUNE_IMC_CONST_MAX_SIZE);
    }
  }

  {
    IMC::Fluorescein msg;
    msg.setTimeStamp(0.7763545840875815);
    msg.setSource(4511U);
    msg.setSourceEntity(240U);
    msg.setDestination(12524U);
    msg.setDestinationEntity(58U);
    msg.value = 0.7652054371622958;

    try
    {
      Utils::ByteBuffer bfr;
      IMC::Packet::serialize(&msg, bfr);
      IMC::Message* msg_d = IMC::Packet::deserialize(bfr.getBuffer(), bfr.getSize());
      test.boolean("Fluorescein #1", msg == *msg_d);
      delete msg_d;
    }
    catch (IMC::InvalidMessageSize& e)
    {
      (void)e;
      test.boolean("msg #1", msg.getSerializationSize() > DUNE_IMC_CONST_MAX_SIZE);
    }
  }

  {
    IMC::Fluorescein msg;
    msg.setTimeStamp(0.689053955522701);
    msg.setSource(50893U);
    msg.setSourceEntity(162U);
    msg.setDestination(3879U);
    msg.setDestinationEntity(108U);
    msg.value = 0.7933825205276906;

    try
    {
      Utils::ByteBuffer bfr;
      IMC::Packet::serialize(&msg, bfr);
      IMC::Message* msg_d = IMC::Packet::deserialize(bfr.getBuffer(), bfr.getSize());
      test.boolean("Fluorescein #2", msg == *msg_d);
      delete msg_d;
    }
    catch (IMC::InvalidMessageSize& e)
    {
      (void)e;
      test.boolean("msg #2", msg.getSerializationSize() > DUNE_IMC_CONST_MAX_SIZE);
    }
  }

  {
    IMC::Phycocyanin msg;
    msg.setTimeStamp(0.8917735093430048);
    msg.setSource(57464U);
    msg.setSourceEntity(46U);
    msg.setDestination(37737U);
    msg.setDestinationEntity(177U);
    msg.value = 0.9672887614792862;

    try
    {
      Utils::ByteBuffer bfr;
      IMC::Packet::serialize(&msg, bfr);
      IMC::Message* msg_d = IMC::Packet::deserialize(bfr.getBuffer(), bfr.getSize());
      test.boolean("Phycocyanin #0", msg == *msg_d);
      delete msg_d;
    }
    catch (IMC::InvalidMessageSize& e)
    {
      (void)e;
      test.boolean("msg #0", msg.getSerializationSize() > DUNE_IMC_CONST_MAX_SIZE);
    }
  }

  {
    IMC::Phycocyanin msg;
    msg.setTimeStamp(0.7309323353775827);
    msg.setSource(5845U);
    msg.setSourceEntity(148U);
    msg.setDestination(9810U);
    msg.setDestinationEntity(24U);
    msg.value = 0.7647482183303814;

    try
    {
      Utils::ByteBuffer bfr;
      IMC::Packet::serialize(&msg, bfr);
      IMC::Message* msg_d = IMC::Packet::deserialize(bfr.getBuffer(), bfr.getSize());
      test.boolean("Phycocyanin #1", msg == *msg_d);
      delete msg_d;
    }
    catch (IMC::InvalidMessageSize& e)
    {
      (void)e;
      test.boolean("msg #1", msg.getSerializationSize() > DUNE_IMC_CONST_MAX_SIZE);
    }
  }

  {
    IMC::Phycocyanin msg;
    msg.setTimeStamp(0.4319564106728605);
    msg.setSource(26866U);
    msg.setSourceEntity(196U);
    msg.setDestination(9642U);
    msg.setDestinationEntity(235U);
    msg.value = 0.860333071765488;

    try
    {
      Utils::ByteBuffer bfr;
      IMC::Packet::serialize(&msg, bfr);
      IMC::Message* msg_d = IMC::Packet::deserialize(bfr.getBuffer(), bfr.getSize());
      test.boolean("Phycocyanin #2", msg == *msg_d);
      delete msg_d;
    }
    catch (IMC::InvalidMessageSize& e)
    {
      (void)e;
      test.boolean("msg #2", msg.getSerializationSize() > DUNE_IMC_CONST_MAX_SIZE);
    }
  }

  {
    IMC::Phycoerythrin msg;
    msg.setTimeStamp(0.2041038011937848);
    msg.setSource(9891U);
    msg.setSourceEntity(9U);
    msg.setDestination(11894U);
    msg.setDestinationEntity(70U);
    msg.value = 0.45329785671534895;

    try
    {
      Utils::ByteBuffer bfr;
      IMC::Packet::serialize(&msg, bfr);
      IMC::Message* msg_d = IMC::Packet::deserialize(bfr.getBuffer(), bfr.getSize());
      test.boolean("Phycoerythrin #0", msg == *msg_d);
      delete msg_d;
    }
    catch (IMC::InvalidMessageSize& e)
    {
      (void)e;
      test.boolean("msg #0", msg.getSerializationSize() > DUNE_IMC_CONST_MAX_SIZE);
    }
  }

  {
    IMC::Phycoerythrin msg;
    msg.setTimeStamp(0.46646604461923025);
    msg.setSource(23353U);
    msg.setSourceEntity(94U);
    msg.setDestination(42881U);
    msg.setDestinationEntity(102U);
    msg.value = 0.995467172354958;

    try
    {
      Utils::ByteBuffer bfr;
      IMC::Packet::serialize(&msg, bfr);
      IMC::Message* msg_d = IMC::Packet::deserialize(bfr.getBuffer(), bfr.getSize());
      test.boolean("Phycoerythrin #1", msg == *msg_d);
      delete msg_d;
    }
    catch (IMC::InvalidMessageSize& e)
    {
      (void)e;
      test.boolean("msg #1", msg.getSerializationSize() > DUNE_IMC_CONST_MAX_SIZE);
    }
  }

  {
    IMC::Phycoerythrin msg;
    msg.setTimeStamp(0.3717534024284712);
    msg.setSource(22626U);
    msg.setSourceEntity(227U);
    msg.setDestination(33351U);
    msg.setDestinationEntity(237U);
    msg.value = 0.7981836706825856;

    try
    {
      Utils::ByteBuffer bfr;
      IMC::Packet::serialize(&msg, bfr);
      IMC::Message* msg_d = IMC::Packet::deserialize(bfr.getBuffer(), bfr.getSize());
      test.boolean("Phycoerythrin #2", msg == *msg_d);
      delete msg_d;
    }
    catch (IMC::InvalidMessageSize& e)
    {
      (void)e;
      test.boolean("msg #2", msg.getSerializationSize() > DUNE_IMC_CONST_MAX_SIZE);
    }
  }

  {
    IMC::GpsFixRtk msg;
    msg.setTimeStamp(0.3632428449784536);
    msg.setSource(41639U);
    msg.setSourceEntity(203U);
    msg.setDestination(41365U);
    msg.setDestinationEntity(66U);
    msg.validity = 45248U;
    msg.type = 48U;
    msg.tow = 2811721627U;
    msg.base_lat = 0.5421554275536656;
    msg.base_lon = 0.3400381198412187;
    msg.base_height = 0.49280257139707884;
    msg.n = 0.3429079630153691;
    msg.e = 0.9968422279718178;
    msg.d = 0.49756460715782014;
    msg.v_n = 0.39182081072420794;
    msg.v_e = 0.5569096103063601;
    msg.v_d = 0.2620120187318471;
    msg.satellites = 67U;
    msg.iar_hyp = 10151U;
    msg.iar_ratio = 0.5022384476660469;

    try
    {
      Utils::ByteBuffer bfr;
      IMC::Packet::serialize(&msg, bfr);
      IMC::Message* msg_d = IMC::Packet::deserialize(bfr.getBuffer(), bfr.getSize());
      test.boolean("GpsFixRtk #0", msg == *msg_d);
      delete msg_d;
    }
    catch (IMC::InvalidMessageSize& e)
    {
      (void)e;
      test.boolean("msg #0", msg.getSerializationSize() > DUNE_IMC_CONST_MAX_SIZE);
    }
  }

  {
    IMC::GpsFixRtk msg;
    msg.setTimeStamp(0.9761831015560027);
    msg.setSource(51979U);
    msg.setSourceEntity(76U);
    msg.setDestination(7086U);
    msg.setDestinationEntity(158U);
    msg.validity = 63017U;
    msg.type = 53U;
    msg.tow = 1291147040U;
    msg.base_lat = 0.9349493039522295;
    msg.base_lon = 0.8194635267040706;
    msg.base_height = 0.1454790700971087;
    msg.n = 0.8148689480551382;
    msg.e = 0.7391700645466895;
    msg.d = 0.2809678856324339;
    msg.v_n = 0.3857583368103552;
    msg.v_e = 0.3905636995078158;
    msg.v_d = 0.04102794543436894;
    msg.satellites = 47U;
    msg.iar_hyp = 26824U;
    msg.iar_ratio = 0.527410452971514;

    try
    {
      Utils::ByteBuffer bfr;
      IMC::Packet::serialize(&msg, bfr);
      IMC::Message* msg_d = IMC::Packet::deserialize(bfr.getBuffer(), bfr.getSize());
      test.boolean("GpsFixRtk #1", msg == *msg_d);
      delete msg_d;
    }
    catch (IMC::InvalidMessageSize& e)
    {
      (void)e;
      test.boolean("msg #1", msg.getSerializationSize() > DUNE_IMC_CONST_MAX_SIZE);
    }
  }

  {
    IMC::GpsFixRtk msg;
    msg.setTimeStamp(0.09737989056722096);
    msg.setSource(31894U);
    msg.setSourceEntity(135U);
    msg.setDestination(33196U);
    msg.setDestinationEntity(72U);
    msg.validity = 15680U;
    msg.type = 135U;
    msg.tow = 2268922736U;
    msg.base_lat = 0.5810665738346054;
    msg.base_lon = 0.8401080900045165;
    msg.base_height = 0.9266575877082975;
    msg.n = 0.28618400818858203;
    msg.e = 0.5511099851103503;
    msg.d = 0.4525812451759865;
    msg.v_n = 0.35109555301913886;
    msg.v_e = 0.22599689799210632;
    msg.v_d = 0.16411429711020453;
    msg.satellites = 230U;
    msg.iar_hyp = 11372U;
    msg.iar_ratio = 0.7534110945298602;

    try
    {
      Utils::ByteBuffer bfr;
      IMC::Packet::serialize(&msg, bfr);
      IMC::Message* msg_d = IMC::Packet::deserialize(bfr.getBuffer(), bfr.getSize());
      test.boolean("GpsFixRtk #2", msg == *msg_d);
      delete msg_d;
    }
    catch (IMC::InvalidMessageSize& e)
    {
      (void)e;
      test.boolean("msg #2", msg.getSerializationSize() > DUNE_IMC_CONST_MAX_SIZE);
    }
  }

  {
    IMC::ExternalNavData msg;
    msg.setTimeStamp(0.8082730351329166);
    msg.setSource(20065U);
    msg.setSourceEntity(183U);
    msg.setDestination(64145U);
    msg.setDestinationEntity(44U);
    IMC::EstimatedState tmp_msg_0;
    tmp_msg_0.lat = 0.15750967244943492;
    tmp_msg_0.lon = 0.12788003716685103;
    tmp_msg_0.height = 0.6570949225400454;
    tmp_msg_0.x = 0.5021537684861546;
    tmp_msg_0.y = 0.07868008170109653;
    tmp_msg_0.z = 0.1191081241325298;
    tmp_msg_0.phi = 0.7188367271836485;
    tmp_msg_0.theta = 0.4326729781918769;
    tmp_msg_0.psi = 0.059410870974578756;
    tmp_msg_0.u = 0.3209685260084073;
    tmp_msg_0.v = 0.1894736012956495;
    tmp_msg_0.w = 0.8281136748630908;
    tmp_msg_0.vx = 0.0692963584328885;
    tmp_msg_0.vy = 0.3315528545503078;
    tmp_msg_0.vz = 0.07370827428772131;
    tmp_msg_0.p = 0.8810807896739354;
    tmp_msg_0.q = 0.8829296056745276;
    tmp_msg_0.r = 0.19269834496229488;
    tmp_msg_0.depth = 0.6906978021163062;
    tmp_msg_0.alt = 0.480845155558403;
    msg.state.set(tmp_msg_0);
    msg.type = 212U;

    try
    {
      Utils::ByteBuffer bfr;
      IMC::Packet::serialize(&msg, bfr);
      IMC::Message* msg_d = IMC::Packet::deserialize(bfr.getBuffer(), bfr.getSize());
      test.boolean("ExternalNavData #0", msg == *msg_d);
      delete msg_d;
    }
    catch (IMC::InvalidMessageSize& e)
    {
      (void)e;
      test.boolean("msg #0", msg.getSerializationSize() > DUNE_IMC_CONST_MAX_SIZE);
    }
  }

  {
    IMC::ExternalNavData msg;
    msg.setTimeStamp(0.12400106544604239);
    msg.setSource(11449U);
    msg.setSourceEntity(237U);
    msg.setDestination(64423U);
    msg.setDestinationEntity(37U);
    IMC::EstimatedState tmp_msg_0;
    tmp_msg_0.lat = 0.3235041179456526;
    tmp_msg_0.lon = 0.5493496335749269;
    tmp_msg_0.height = 0.17734292324437306;
    tmp_msg_0.x = 0.2360451177660854;
    tmp_msg_0.y = 0.42943115496301465;
    tmp_msg_0.z = 0.9371610206018799;
    tmp_msg_0.phi = 0.4066818269316482;
    tmp_msg_0.theta = 0.4130155036555251;
    tmp_msg_0.psi = 0.234819652503647;
    tmp_msg_0.u = 0.7069905432677995;
    tmp_msg_0.v = 0.7082263606535907;
    tmp_msg_0.w = 0.21733355378167885;
    tmp_msg_0.vx = 0.8977765154583208;
    tmp_msg_0.vy = 0.8934467562144716;
    tmp_msg_0.vz = 0.17863795809953353;
    tmp_msg_0.p = 0.3347265204704907;
    tmp_msg_0.q = 0.30198408088967565;
    tmp_msg_0.r = 0.14442052108228276;
    tmp_msg_0.depth = 0.8167307907093968;
    tmp_msg_0.alt = 0.21961598136321747;
    msg.state.set(tmp_msg_0);
    msg.type = 121U;

    try
    {
      Utils::ByteBuffer bfr;
      IMC::Packet::serialize(&msg, bfr);
      IMC::Message* msg_d = IMC::Packet::deserialize(bfr.getBuffer(), bfr.getSize());
      test.boolean("ExternalNavData #1", msg == *msg_d);
      delete msg_d;
    }
    catch (IMC::InvalidMessageSize& e)
    {
      (void)e;
      test.boolean("msg #1", msg.getSerializationSize() > DUNE_IMC_CONST_MAX_SIZE);
    }
  }

  {
    IMC::ExternalNavData msg;
    msg.setTimeStamp(0.3501897208225647);
    msg.setSource(3442U);
    msg.setSourceEntity(12U);
    msg.setDestination(58405U);
    msg.setDestinationEntity(50U);
    IMC::EstimatedState tmp_msg_0;
    tmp_msg_0.lat = 0.4079766725701841;
    tmp_msg_0.lon = 0.17122660338962137;
    tmp_msg_0.height = 0.11292080439240315;
    tmp_msg_0.x = 0.6620509421998242;
    tmp_msg_0.y = 0.854668556470995;
    tmp_msg_0.z = 0.6227556568955354;
    tmp_msg_0.phi = 0.09051743662850831;
    tmp_msg_0.theta = 0.5262383669629079;
    tmp_msg_0.psi = 0.6564588707833541;
    tmp_msg_0.u = 0.4115516917687465;
    tmp_msg_0.v = 0.11384697330982396;
    tmp_msg_0.w = 0.14423026531957073;
    tmp_msg_0.vx = 0.5048676503404684;
    tmp_msg_0.vy = 0.31049750169448465;
    tmp_msg_0.vz = 0.75325595203797;
    tmp_msg_0.p = 0.8501464141741386;
    tmp_msg_0.q = 0.5378588491076369;
    tmp_msg_0.r = 0.6569527994081217;
    tmp_msg_0.depth = 0.8833981924510512;
    tmp_msg_0.alt = 0.6377877223936365;
    msg.state.set(tmp_msg_0);
    msg.type = 207U;

    try
    {
      Utils::ByteBuffer bfr;
      IMC::Packet::serialize(&msg, bfr);
      IMC::Message* msg_d = IMC::Packet::deserialize(bfr.getBuffer(), bfr.getSize());
      test.boolean("ExternalNavData #2", msg == *msg_d);
      delete msg_d;
    }
    catch (IMC::InvalidMessageSize& e)
    {
      (void)e;
      test.boolean("msg #2", msg.getSerializationSize() > DUNE_IMC_CONST_MAX_SIZE);
    }
  }

  {
    IMC::DissolvedOxygen msg;
    msg.setTimeStamp(0.758358289342173);
    msg.setSource(63147U);
    msg.setSourceEntity(229U);
    msg.setDestination(34418U);
    msg.setDestinationEntity(175U);
    msg.value = 0.061465482871014276;

    try
    {
      Utils::ByteBuffer bfr;
      IMC::Packet::serialize(&msg, bfr);
      IMC::Message* msg_d = IMC::Packet::deserialize(bfr.getBuffer(), bfr.getSize());
      test.boolean("DissolvedOxygen #0", msg == *msg_d);
      delete msg_d;
    }
    catch (IMC::InvalidMessageSize& e)
    {
      (void)e;
      test.boolean("msg #0", msg.getSerializationSize() > DUNE_IMC_CONST_MAX_SIZE);
    }
  }

  {
    IMC::DissolvedOxygen msg;
    msg.setTimeStamp(0.9863534128095555);
    msg.setSource(56125U);
    msg.setSourceEntity(204U);
    msg.setDestination(14822U);
    msg.setDestinationEntity(80U);
    msg.value = 0.7187304288520794;

    try
    {
      Utils::ByteBuffer bfr;
      IMC::Packet::serialize(&msg, bfr);
      IMC::Message* msg_d = IMC::Packet::deserialize(bfr.getBuffer(), bfr.getSize());
      test.boolean("DissolvedOxygen #1", msg == *msg_d);
      delete msg_d;
    }
    catch (IMC::InvalidMessageSize& e)
    {
      (void)e;
      test.boolean("msg #1", msg.getSerializationSize() > DUNE_IMC_CONST_MAX_SIZE);
    }
  }

  {
    IMC::DissolvedOxygen msg;
    msg.setTimeStamp(0.9311668450887721);
    msg.setSource(10760U);
    msg.setSourceEntity(221U);
    msg.setDestination(5869U);
    msg.setDestinationEntity(48U);
    msg.value = 0.534862817074162;

    try
    {
      Utils::ByteBuffer bfr;
      IMC::Packet::serialize(&msg, bfr);
      IMC::Message* msg_d = IMC::Packet::deserialize(bfr.getBuffer(), bfr.getSize());
      test.boolean("DissolvedOxygen #2", msg == *msg_d);
      delete msg_d;
    }
    catch (IMC::InvalidMessageSize& e)
    {
      (void)e;
      test.boolean("msg #2", msg.getSerializationSize() > DUNE_IMC_CONST_MAX_SIZE);
    }
  }

  {
    IMC::AirSaturation msg;
    msg.setTimeStamp(0.7560870964775739);
    msg.setSource(49641U);
    msg.setSourceEntity(209U);
    msg.setDestination(44413U);
    msg.setDestinationEntity(192U);
    msg.value = 0.8214282878100879;

    try
    {
      Utils::ByteBuffer bfr;
      IMC::Packet::serialize(&msg, bfr);
      IMC::Message* msg_d = IMC::Packet::deserialize(bfr.getBuffer(), bfr.getSize());
      test.boolean("AirSaturation #0", msg == *msg_d);
      delete msg_d;
    }
    catch (IMC::InvalidMessageSize& e)
    {
      (void)e;
      test.boolean("msg #0", msg.getSerializationSize() > DUNE_IMC_CONST_MAX_SIZE);
    }
  }

  {
    IMC::AirSaturation msg;
    msg.setTimeStamp(0.06772348966320485);
    msg.setSource(3287U);
    msg.setSourceEntity(217U);
    msg.setDestination(63086U);
    msg.setDestinationEntity(245U);
    msg.value = 0.752453021867932;

    try
    {
      Utils::ByteBuffer bfr;
      IMC::Packet::serialize(&msg, bfr);
      IMC::Message* msg_d = IMC::Packet::deserialize(bfr.getBuffer(), bfr.getSize());
      test.boolean("AirSaturation #1", msg == *msg_d);
      delete msg_d;
    }
    catch (IMC::InvalidMessageSize& e)
    {
      (void)e;
      test.boolean("msg #1", msg.getSerializationSize() > DUNE_IMC_CONST_MAX_SIZE);
    }
  }

  {
    IMC::AirSaturation msg;
    msg.setTimeStamp(0.8566695235211792);
    msg.setSource(36600U);
    msg.setSourceEntity(61U);
    msg.setDestination(50480U);
    msg.setDestinationEntity(253U);
    msg.value = 0.1256171525680454;

    try
    {
      Utils::ByteBuffer bfr;
      IMC::Packet::serialize(&msg, bfr);
      IMC::Message* msg_d = IMC::Packet::deserialize(bfr.getBuffer(), bfr.getSize());
      test.boolean("AirSaturation #2", msg == *msg_d);
      delete msg_d;
    }
    catch (IMC::InvalidMessageSize& e)
    {
      (void)e;
      test.boolean("msg #2", msg.getSerializationSize() > DUNE_IMC_CONST_MAX_SIZE);
    }
  }

  {
    IMC::Throttle msg;
    msg.setTimeStamp(0.5028288987639747);
    msg.setSource(44038U);
    msg.setSourceEntity(204U);
    msg.setDestination(49270U);
    msg.setDestinationEntity(27U);
    msg.value = 0.7422128745361274;

    try
    {
      Utils::ByteBuffer bfr;
      IMC::Packet::serialize(&msg, bfr);
      IMC::Message* msg_d = IMC::Packet::deserialize(bfr.getBuffer(), bfr.getSize());
      test.boolean("Throttle #0", msg == *msg_d);
      delete msg_d;
    }
    catch (IMC::InvalidMessageSize& e)
    {
      (void)e;
      test.boolean("msg #0", msg.getSerializationSize() > DUNE_IMC_CONST_MAX_SIZE);
    }
  }

  {
    IMC::Throttle msg;
    msg.setTimeStamp(0.5597543363509977);
    msg.setSource(32520U);
    msg.setSourceEntity(124U);
    msg.setDestination(36253U);
    msg.setDestinationEntity(235U);
    msg.value = 0.35233686666388664;

    try
    {
      Utils::ByteBuffer bfr;
      IMC::Packet::serialize(&msg, bfr);
      IMC::Message* msg_d = IMC::Packet::deserialize(bfr.getBuffer(), bfr.getSize());
      test.boolean("Throttle #1", msg == *msg_d);
      delete msg_d;
    }
    catch (IMC::InvalidMessageSize& e)
    {
      (void)e;
      test.boolean("msg #1", msg.getSerializationSize() > DUNE_IMC_CONST_MAX_SIZE);
    }
  }

  {
    IMC::Throttle msg;
    msg.setTimeStamp(0.22848393363886466);
    msg.setSource(59430U);
    msg.setSourceEntity(240U);
    msg.setDestination(59155U);
    msg.setDestinationEntity(89U);
    msg.value = 0.8688747618019838;

    try
    {
      Utils::ByteBuffer bfr;
      IMC::Packet::serialize(&msg, bfr);
      IMC::Message* msg_d = IMC::Packet::deserialize(bfr.getBuffer(), bfr.getSize());
      test.boolean("Throttle #2", msg == *msg_d);
      delete msg_d;
    }
    catch (IMC::InvalidMessageSize& e)
    {
      (void)e;
      test.boolean("msg #2", msg.getSerializationSize() > DUNE_IMC_CONST_MAX_SIZE);
    }
  }

  {
    IMC::PH msg;
    msg.setTimeStamp(0.13955915291965704);
    msg.setSource(51571U);
    msg.setSourceEntity(182U);
    msg.setDestination(53222U);
    msg.setDestinationEntity(123U);
    msg.value = 0.6993625098567058;

    try
    {
      Utils::ByteBuffer bfr;
      IMC::Packet::serialize(&msg, bfr);
      IMC::Message* msg_d = IMC::Packet::deserialize(bfr.getBuffer(), bfr.getSize());
      test.boolean("PH #0", msg == *msg_d);
      delete msg_d;
    }
    catch (IMC::InvalidMessageSize& e)
    {
      (void)e;
      test.boolean("msg #0", msg.getSerializationSize() > DUNE_IMC_CONST_MAX_SIZE);
    }
  }

  {
    IMC::PH msg;
    msg.setTimeStamp(0.6059315433349791);
    msg.setSource(37778U);
    msg.setSourceEntity(29U);
    msg.setDestination(11976U);
    msg.setDestinationEntity(166U);
    msg.value = 0.8970202008516682;

    try
    {
      Utils::ByteBuffer bfr;
      IMC::Packet::serialize(&msg, bfr);
      IMC::Message* msg_d = IMC::Packet::deserialize(bfr.getBuffer(), bfr.getSize());
      test.boolean("PH #1", msg == *msg_d);
      delete msg_d;
    }
    catch (IMC::InvalidMessageSize& e)
    {
      (void)e;
      test.boolean("msg #1", msg.getSerializationSize() > DUNE_IMC_CONST_MAX_SIZE);
    }
  }

  {
    IMC::PH msg;
    msg.setTimeStamp(0.004449216764794484);
    msg.setSource(38196U);
    msg.setSourceEntity(154U);
    msg.setDestination(37307U);
    msg.setDestinationEntity(210U);
    msg.value = 0.5419621373360475;

    try
    {
      Utils::ByteBuffer bfr;
      IMC::Packet::serialize(&msg, bfr);
      IMC::Message* msg_d = IMC::Packet::deserialize(bfr.getBuffer(), bfr.getSize());
      test.boolean("PH #2", msg == *msg_d);
      delete msg_d;
    }
    catch (IMC::InvalidMessageSize& e)
    {
      (void)e;
      test.boolean("msg #2", msg.getSerializationSize() > DUNE_IMC_CONST_MAX_SIZE);
    }
  }

  {
    IMC::Redox msg;
    msg.setTimeStamp(0.09723466987463059);
    msg.setSource(57012U);
    msg.setSourceEntity(155U);
    msg.setDestination(62712U);
    msg.setDestinationEntity(8U);
    msg.value = 0.30419329020095576;

    try
    {
      Utils::ByteBuffer bfr;
      IMC::Packet::serialize(&msg, bfr);
      IMC::Message* msg_d = IMC::Packet::deserialize(bfr.getBuffer(), bfr.getSize());
      test.boolean("Redox #0", msg == *msg_d);
      delete msg_d;
    }
    catch (IMC::InvalidMessageSize& e)
    {
      (void)e;
      test.boolean("msg #0", msg.getSerializationSize() > DUNE_IMC_CONST_MAX_SIZE);
    }
  }

  {
    IMC::Redox msg;
    msg.setTimeStamp(0.572980982370841);
    msg.setSource(34218U);
    msg.setSourceEntity(81U);
    msg.setDestination(30947U);
    msg.setDestinationEntity(59U);
    msg.value = 0.2306449536295162;

    try
    {
      Utils::ByteBuffer bfr;
      IMC::Packet::serialize(&msg, bfr);
      IMC::Message* msg_d = IMC::Packet::deserialize(bfr.getBuffer(), bfr.getSize());
      test.boolean("Redox #1", msg == *msg_d);
      delete msg_d;
    }
    catch (IMC::InvalidMessageSize& e)
    {
      (void)e;
      test.boolean("msg #1", msg.getSerializationSize() > DUNE_IMC_CONST_MAX_SIZE);
    }
  }

  {
    IMC::Redox msg;
    msg.setTimeStamp(0.9865371970495579);
    msg.setSource(49860U);
    msg.setSourceEntity(194U);
    msg.setDestination(39760U);
    msg.setDestinationEntity(164U);
    msg.value = 0.07075762410466357;

    try
    {
      Utils::ByteBuffer bfr;
      IMC::Packet::serialize(&msg, bfr);
      IMC::Message* msg_d = IMC::Packet::deserialize(bfr.getBuffer(), bfr.getSize());
      test.boolean("Redox #2", msg == *msg_d);
      delete msg_d;
    }
    catch (IMC::InvalidMessageSize& e)
    {
      (void)e;
      test.boolean("msg #2", msg.getSerializationSize() > DUNE_IMC_CONST_MAX_SIZE);
    }
  }

  {
    IMC::CameraZoom msg;
    msg.setTimeStamp(0.4452189374577532);
    msg.setSource(5333U);
    msg.setSourceEntity(72U);
    msg.setDestination(22183U);
    msg.setDestinationEntity(44U);
    msg.id = 214U;
    msg.zoom = 105U;
    msg.action = 70U;

    try
    {
      Utils::ByteBuffer bfr;
      IMC::Packet::serialize(&msg, bfr);
      IMC::Message* msg_d = IMC::Packet::deserialize(bfr.getBuffer(), bfr.getSize());
      test.boolean("CameraZoom #0", msg == *msg_d);
      delete msg_d;
    }
    catch (IMC::InvalidMessageSize& e)
    {
      (void)e;
      test.boolean("msg #0", msg.getSerializationSize() > DUNE_IMC_CONST_MAX_SIZE);
    }
  }

  {
    IMC::CameraZoom msg;
    msg.setTimeStamp(0.8584006744529069);
    msg.setSource(50365U);
    msg.setSourceEntity(226U);
    msg.setDestination(5580U);
    msg.setDestinationEntity(146U);
    msg.id = 30U;
    msg.zoom = 16U;
    msg.action = 136U;

    try
    {
      Utils::ByteBuffer bfr;
      IMC::Packet::serialize(&msg, bfr);
      IMC::Message* msg_d = IMC::Packet::deserialize(bfr.getBuffer(), bfr.getSize());
      test.boolean("CameraZoom #1", msg == *msg_d);
      delete msg_d;
    }
    catch (IMC::InvalidMessageSize& e)
    {
      (void)e;
      test.boolean("msg #1", msg.getSerializationSize() > DUNE_IMC_CONST_MAX_SIZE);
    }
  }

  {
    IMC::CameraZoom msg;
    msg.setTimeStamp(0.3950918092555933);
    msg.setSource(16261U);
    msg.setSourceEntity(186U);
    msg.setDestination(35341U);
    msg.setDestinationEntity(109U);
    msg.id = 228U;
    msg.zoom = 158U;
    msg.action = 221U;

    try
    {
      Utils::ByteBuffer bfr;
      IMC::Packet::serialize(&msg, bfr);
      IMC::Message* msg_d = IMC::Packet::deserialize(bfr.getBuffer(), bfr.getSize());
      test.boolean("CameraZoom #2", msg == *msg_d);
      delete msg_d;
    }
    catch (IMC::InvalidMessageSize& e)
    {
      (void)e;
      test.boolean("msg #2", msg.getSerializationSize() > DUNE_IMC_CONST_MAX_SIZE);
    }
  }

  {
    IMC::SetThrusterActuation msg;
    msg.setTimeStamp(0.48855805577274647);
    msg.setSource(43896U);
    msg.setSourceEntity(87U);
    msg.setDestination(24322U);
    msg.setDestinationEntity(196U);
    msg.id = 156U;
    msg.value = 0.3987781441775692;

    try
    {
      Utils::ByteBuffer bfr;
      IMC::Packet::serialize(&msg, bfr);
      IMC::Message* msg_d = IMC::Packet::deserialize(bfr.getBuffer(), bfr.getSize());
      test.boolean("SetThrusterActuation #0", msg == *msg_d);
      delete msg_d;
    }
    catch (IMC::InvalidMessageSize& e)
    {
      (void)e;
      test.boolean("msg #0", msg.getSerializationSize() > DUNE_IMC_CONST_MAX_SIZE);
    }
  }

  {
    IMC::SetThrusterActuation msg;
    msg.setTimeStamp(0.4338360477897748);
    msg.setSource(59214U);
    msg.setSourceEntity(192U);
    msg.setDestination(46559U);
    msg.setDestinationEntity(42U);
    msg.id = 96U;
    msg.value = 0.18667199580170746;

    try
    {
      Utils::ByteBuffer bfr;
      IMC::Packet::serialize(&msg, bfr);
      IMC::Message* msg_d = IMC::Packet::deserialize(bfr.getBuffer(), bfr.getSize());
      test.boolean("SetThrusterActuation #1", msg == *msg_d);
      delete msg_d;
    }
    catch (IMC::InvalidMessageSize& e)
    {
      (void)e;
      test.boolean("msg #1", msg.getSerializationSize() > DUNE_IMC_CONST_MAX_SIZE);
    }
  }

  {
    IMC::SetThrusterActuation msg;
    msg.setTimeStamp(0.03991330186715125);
    msg.setSource(23840U);
    msg.setSourceEntity(135U);
    msg.setDestination(52132U);
    msg.setDestinationEntity(34U);
    msg.id = 49U;
    msg.value = 0.31442201924370705;

    try
    {
      Utils::ByteBuffer bfr;
      IMC::Packet::serialize(&msg, bfr);
      IMC::Message* msg_d = IMC::Packet::deserialize(bfr.getBuffer(), bfr.getSize());
      test.boolean("SetThrusterActuation #2", msg == *msg_d);
      delete msg_d;
    }
    catch (IMC::InvalidMessageSize& e)
    {
      (void)e;
      test.boolean("msg #2", msg.getSerializationSize() > DUNE_IMC_CONST_MAX_SIZE);
    }
  }

  {
    IMC::SetServoPosition msg;
    msg.setTimeStamp(0.8809221998868182);
    msg.setSource(19901U);
    msg.setSourceEntity(225U);
    msg.setDestination(21943U);
    msg.setDestinationEntity(254U);
    msg.id = 153U;
    msg.value = 0.7579327103251593;

    try
    {
      Utils::ByteBuffer bfr;
      IMC::Packet::serialize(&msg, bfr);
      IMC::Message* msg_d = IMC::Packet::deserialize(bfr.getBuffer(), bfr.getSize());
      test.boolean("SetServoPosition #0", msg == *msg_d);
      delete msg_d;
    }
    catch (IMC::InvalidMessageSize& e)
    {
      (void)e;
      test.boolean("msg #0", msg.getSerializationSize() > DUNE_IMC_CONST_MAX_SIZE);
    }
  }

  {
    IMC::SetServoPosition msg;
    msg.setTimeStamp(0.06925770327681424);
    msg.setSource(32102U);
    msg.setSourceEntity(205U);
    msg.setDestination(1050U);
    msg.setDestinationEntity(51U);
    msg.id = 63U;
    msg.value = 0.5282492061223119;

    try
    {
      Utils::ByteBuffer bfr;
      IMC::Packet::serialize(&msg, bfr);
      IMC::Message* msg_d = IMC::Packet::deserialize(bfr.getBuffer(), bfr.getSize());
      test.boolean("SetServoPosition #1", msg == *msg_d);
      delete msg_d;
    }
    catch (IMC::InvalidMessageSize& e)
    {
      (void)e;
      test.boolean("msg #1", msg.getSerializationSize() > DUNE_IMC_CONST_MAX_SIZE);
    }
  }

  {
    IMC::SetServoPosition msg;
    msg.setTimeStamp(0.8733972895175472);
    msg.setSource(11174U);
    msg.setSourceEntity(229U);
    msg.setDestination(38685U);
    msg.setDestinationEntity(163U);
    msg.id = 185U;
    msg.value = 0.8604848273521477;

    try
    {
      Utils::ByteBuffer bfr;
      IMC::Packet::serialize(&msg, bfr);
      IMC::Message* msg_d = IMC::Packet::deserialize(bfr.getBuffer(), bfr.getSize());
      test.boolean("SetServoPosition #2", msg == *msg_d);
      delete msg_d;
    }
    catch (IMC::InvalidMessageSize& e)
    {
      (void)e;
      test.boolean("msg #2", msg.getSerializationSize() > DUNE_IMC_CONST_MAX_SIZE);
    }
  }

  {
    IMC::SetControlSurfaceDeflection msg;
    msg.setTimeStamp(0.08220982987472447);
    msg.setSource(31068U);
    msg.setSourceEntity(62U);
    msg.setDestination(36258U);
    msg.setDestinationEntity(64U);
    msg.id = 245U;
    msg.angle = 0.39480048153076763;

    try
    {
      Utils::ByteBuffer bfr;
      IMC::Packet::serialize(&msg, bfr);
      IMC::Message* msg_d = IMC::Packet::deserialize(bfr.getBuffer(), bfr.getSize());
      test.boolean("SetControlSurfaceDeflection #0", msg == *msg_d);
      delete msg_d;
    }
    catch (IMC::InvalidMessageSize& e)
    {
      (void)e;
      test.boolean("msg #0", msg.getSerializationSize() > DUNE_IMC_CONST_MAX_SIZE);
    }
  }

  {
    IMC::SetControlSurfaceDeflection msg;
    msg.setTimeStamp(0.16487455517556504);
    msg.setSource(23854U);
    msg.setSourceEntity(118U);
    msg.setDestination(36423U);
    msg.setDestinationEntity(171U);
    msg.id = 200U;
    msg.angle = 0.2717274255156459;

    try
    {
      Utils::ByteBuffer bfr;
      IMC::Packet::serialize(&msg, bfr);
      IMC::Message* msg_d = IMC::Packet::deserialize(bfr.getBuffer(), bfr.getSize());
      test.boolean("SetControlSurfaceDeflection #1", msg == *msg_d);
      delete msg_d;
    }
    catch (IMC::InvalidMessageSize& e)
    {
      (void)e;
      test.boolean("msg #1", msg.getSerializationSize() > DUNE_IMC_CONST_MAX_SIZE);
    }
  }

  {
    IMC::SetControlSurfaceDeflection msg;
    msg.setTimeStamp(0.07216155933666846);
    msg.setSource(57374U);
    msg.setSourceEntity(159U);
    msg.setDestination(6549U);
    msg.setDestinationEntity(192U);
    msg.id = 206U;
    msg.angle = 0.2714186025119707;

    try
    {
      Utils::ByteBuffer bfr;
      IMC::Packet::serialize(&msg, bfr);
      IMC::Message* msg_d = IMC::Packet::deserialize(bfr.getBuffer(), bfr.getSize());
      test.boolean("SetControlSurfaceDeflection #2", msg == *msg_d);
      delete msg_d;
    }
    catch (IMC::InvalidMessageSize& e)
    {
      (void)e;
      test.boolean("msg #2", msg.getSerializationSize() > DUNE_IMC_CONST_MAX_SIZE);
    }
  }

  {
    IMC::RemoteActionsRequest msg;
    msg.setTimeStamp(0.6466991169236384);
    msg.setSource(37457U);
    msg.setSourceEntity(166U);
    msg.setDestination(65446U);
    msg.setDestinationEntity(236U);
    msg.op = 145U;
    msg.actions.assign("NWIXEMZEMIPPAESYGENVCJKCPYSBSTXNYBDPQ");

    try
    {
      Utils::ByteBuffer bfr;
      IMC::Packet::serialize(&msg, bfr);
      IMC::Message* msg_d = IMC::Packet::deserialize(bfr.getBuffer(), bfr.getSize());
      test.boolean("RemoteActionsRequest #0", msg == *msg_d);
      delete msg_d;
    }
    catch (IMC::InvalidMessageSize& e)
    {
      (void)e;
      test.boolean("msg #0", msg.getSerializationSize() > DUNE_IMC_CONST_MAX_SIZE);
    }
  }

  {
    IMC::RemoteActionsRequest msg;
    msg.setTimeStamp(0.27390532551206237);
    msg.setSource(16051U);
    msg.setSourceEntity(91U);
    msg.setDestination(50999U);
    msg.setDestinationEntity(111U);
    msg.op = 194U;
    msg.actions.assign("ARKKJELTUPVUFAHSIBCIBFIMJTWXLXUVKYMJSAZBLEMAOSSFWLUGCRFCBGFGTQZHIQGFBPTNCYFBJWGVENCMZKXRPYRAXRSZWTWVQOHZXINQETQMWAMQCBKADRRRNHPXEOILDLDAILJOYJVGYZLDMKSZDSCXHZDSLBKUZOTJYWXXUWRNHHMOIWTVQAPPJGNC");

    try
    {
      Utils::ByteBuffer bfr;
      IMC::Packet::serialize(&msg, bfr);
      IMC::Message* msg_d = IMC::Packet::deserialize(bfr.getBuffer(), bfr.getSize());
      test.boolean("RemoteActionsRequest #1", msg == *msg_d);
      delete msg_d;
    }
    catch (IMC::InvalidMessageSize& e)
    {
      (void)e;
      test.boolean("msg #1", msg.getSerializationSize() > DUNE_IMC_CONST_MAX_SIZE);
    }
  }

  {
    IMC::RemoteActionsRequest msg;
    msg.setTimeStamp(0.6807255333607192);
    msg.setSource(51771U);
    msg.setSourceEntity(104U);
    msg.setDestination(871U);
    msg.setDestinationEntity(52U);
    msg.op = 143U;
    msg.actions.assign("CZRFBSCQCYFYZMUFOXJHEWCYWEGTFWPVZXEJTNVAUCLAGXVDBMIYQPUAUPDAOISPTYQAELSUMQLMPLQVXKOUKBGTRESUHNCDQTTWIRHLMEWZWSISJSMIAOXKQNBBBCBNELUBYQRBAFOEOVIEHLXHDFULZZGFGIJGRINYKJKMYCTJXRMWVYWKKNORKHHREGZBXHNJTCPNTVFPKALIHDQCWVSNDPUJDSFAMGHRODOVLMQXVZPSNZWJRADGFY");

    try
    {
      Utils::ByteBuffer bfr;
      IMC::Packet::serialize(&msg, bfr);
      IMC::Message* msg_d = IMC::Packet::deserialize(bfr.getBuffer(), bfr.getSize());
      test.boolean("RemoteActionsRequest #2", msg == *msg_d);
      delete msg_d;
    }
    catch (IMC::InvalidMessageSize& e)
    {
      (void)e;
      test.boolean("msg #2", msg.getSerializationSize() > DUNE_IMC_CONST_MAX_SIZE);
    }
  }

  {
    IMC::RemoteActions msg;
    msg.setTimeStamp(0.20065748477848466);
    msg.setSource(41636U);
    msg.setSourceEntity(202U);
    msg.setDestination(9593U);
    msg.setDestinationEntity(190U);
    msg.actions.assign("QUVREGHMESACJMTMCFKTJKY");

    try
    {
      Utils::ByteBuffer bfr;
      IMC::Packet::serialize(&msg, bfr);
      IMC::Message* msg_d = IMC::Packet::deserialize(bfr.getBuffer(), bfr.getSize());
      test.boolean("RemoteActions #0", msg == *msg_d);
      delete msg_d;
    }
    catch (IMC::InvalidMessageSize& e)
    {
      (void)e;
      test.boolean("msg #0", msg.getSerializationSize() > DUNE_IMC_CONST_MAX_SIZE);
    }
  }

  {
    IMC::RemoteActions msg;
    msg.setTimeStamp(0.17388123265541167);
    msg.setSource(44584U);
    msg.setSourceEntity(181U);
    msg.setDestination(23771U);
    msg.setDestinationEntity(113U);
    msg.actions.assign("QDDEOEMRSRASYKXTSXHFYEXGEFJCA");

    try
    {
      Utils::ByteBuffer bfr;
      IMC::Packet::serialize(&msg, bfr);
      IMC::Message* msg_d = IMC::Packet::deserialize(bfr.getBuffer(), bfr.getSize());
      test.boolean("RemoteActions #1", msg == *msg_d);
      delete msg_d;
    }
    catch (IMC::InvalidMessageSize& e)
    {
      (void)e;
      test.boolean("msg #1", msg.getSerializationSize() > DUNE_IMC_CONST_MAX_SIZE);
    }
  }

  {
    IMC::RemoteActions msg;
    msg.setTimeStamp(0.6860672772899857);
    msg.setSource(45236U);
    msg.setSourceEntity(23U);
    msg.setDestination(9503U);
    msg.setDestinationEntity(121U);
    msg.actions.assign("UPULLPAABOSEQHFCEVXWZPXFVPTQXKSSDIMVTFPJRKENKBTDPUVROMETXFFGHXWYKGNUBSMAPNHJIWRTAUYJARGHZTJOAKVGZIILZCZISZUEJSNITSVWQVDGBBSVIOYIJMRJMWWHMOQQBPGCYCZEAMHECOUXGYYRWCDNDZUOBTRMGIYELQUMPHARNQELVEQLWAGLGKJXKCUFFNYFQTKBYONNKLSPLX");

    try
    {
      Utils::ByteBuffer bfr;
      IMC::Packet::serialize(&msg, bfr);
      IMC::Message* msg_d = IMC::Packet::deserialize(bfr.getBuffer(), bfr.getSize());
      test.boolean("RemoteActions #2", msg == *msg_d);
      delete msg_d;
    }
    catch (IMC::InvalidMessageSize& e)
    {
      (void)e;
      test.boolean("msg #2", msg.getSerializationSize() > DUNE_IMC_CONST_MAX_SIZE);
    }
  }

  {
    IMC::ButtonEvent msg;
    msg.setTimeStamp(0.1846301376380347);
    msg.setSource(18899U);
    msg.setSourceEntity(2U);
    msg.setDestination(64860U);
    msg.setDestinationEntity(25U);
    msg.button = 214U;
    msg.value = 202U;

    try
    {
      Utils::ByteBuffer bfr;
      IMC::Packet::serialize(&msg, bfr);
      IMC::Message* msg_d = IMC::Packet::deserialize(bfr.getBuffer(), bfr.getSize());
      test.boolean("ButtonEvent #0", msg == *msg_d);
      delete msg_d;
    }
    catch (IMC::InvalidMessageSize& e)
    {
      (void)e;
      test.boolean("msg #0", msg.getSerializationSize() > DUNE_IMC_CONST_MAX_SIZE);
    }
  }

  {
    IMC::ButtonEvent msg;
    msg.setTimeStamp(0.49409763711309296);
    msg.setSource(42077U);
    msg.setSourceEntity(177U);
    msg.setDestination(26298U);
    msg.setDestinationEntity(169U);
    msg.button = 100U;
    msg.value = 111U;

    try
    {
      Utils::ByteBuffer bfr;
      IMC::Packet::serialize(&msg, bfr);
      IMC::Message* msg_d = IMC::Packet::deserialize(bfr.getBuffer(), bfr.getSize());
      test.boolean("ButtonEvent #1", msg == *msg_d);
      delete msg_d;
    }
    catch (IMC::InvalidMessageSize& e)
    {
      (void)e;
      test.boolean("msg #1", msg.getSerializationSize() > DUNE_IMC_CONST_MAX_SIZE);
    }
  }

  {
    IMC::ButtonEvent msg;
    msg.setTimeStamp(0.4325566924197155);
    msg.setSource(33641U);
    msg.setSourceEntity(157U);
    msg.setDestination(4146U);
    msg.setDestinationEntity(207U);
    msg.button = 16U;
    msg.value = 56U;

    try
    {
      Utils::ByteBuffer bfr;
      IMC::Packet::serialize(&msg, bfr);
      IMC::Message* msg_d = IMC::Packet::deserialize(bfr.getBuffer(), bfr.getSize());
      test.boolean("ButtonEvent #2", msg == *msg_d);
      delete msg_d;
    }
    catch (IMC::InvalidMessageSize& e)
    {
      (void)e;
      test.boolean("msg #2", msg.getSerializationSize() > DUNE_IMC_CONST_MAX_SIZE);
    }
  }

  {
    IMC::LcdControl msg;
    msg.setTimeStamp(0.3739727264073658);
    msg.setSource(38389U);
    msg.setSourceEntity(107U);
    msg.setDestination(7005U);
    msg.setDestinationEntity(137U);
    msg.op = 37U;
    msg.text.assign("WFISCMTVADCMAPAONPFJBSTCZYKYQRNRSZJSCEADOJXZJEIREKENBLXWFLVEFUJIVHWYIOUGVMLZEDIEZXUPYMCASUQCQXAUYQBEFVOQWFMNYPLBMIDWQCZOGMPSTRTKXMUTIFVWXHVRZDGPSPRJTVOQRKJZBYBHJKVHKLNSROSLDNHHMIJUALGKOHKDXHAHOKPJOTTVTURWQGKAQLFUQXFNFBDZBLIGIXGNNLCPDCS");

    try
    {
      Utils::ByteBuffer bfr;
      IMC::Packet::serialize(&msg, bfr);
      IMC::Message* msg_d = IMC::Packet::deserialize(bfr.getBuffer(), bfr.getSize());
      test.boolean("LcdControl #0", msg == *msg_d);
      delete msg_d;
    }
    catch (IMC::InvalidMessageSize& e)
    {
      (void)e;
      test.boolean("msg #0", msg.getSerializationSize() > DUNE_IMC_CONST_MAX_SIZE);
    }
  }

  {
    IMC::LcdControl msg;
    msg.setTimeStamp(0.7677012950935281);
    msg.setSource(25153U);
    msg.setSourceEntity(99U);
    msg.setDestination(58347U);
    msg.setDestinationEntity(101U);
    msg.op = 24U;
    msg.text.assign("MULXXHPAVSAUCLBKZKJXFAXSCGQBKPBAPZVYTPIZSYTGJTURNQWENDKSYAUEEGSKHMDZHWSCCJVDLYONESWWGZVTLQMMYMRAVNVERPFTBNCTTPKROQIVMBPTLRQGXDRXXUHAISZJGXFAKZGCNFIVDHFQVHJNIXWJJLFEDQR");

    try
    {
      Utils::ByteBuffer bfr;
      IMC::Packet::serialize(&msg, bfr);
      IMC::Message* msg_d = IMC::Packet::deserialize(bfr.getBuffer(), bfr.getSize());
      test.boolean("LcdControl #1", msg == *msg_d);
      delete msg_d;
    }
    catch (IMC::InvalidMessageSize& e)
    {
      (void)e;
      test.boolean("msg #1", msg.getSerializationSize() > DUNE_IMC_CONST_MAX_SIZE);
    }
  }

  {
    IMC::LcdControl msg;
    msg.setTimeStamp(0.4156274476675643);
    msg.setSource(25058U);
    msg.setSourceEntity(164U);
    msg.setDestination(45391U);
    msg.setDestinationEntity(185U);
    msg.op = 209U;
    msg.text.assign("CDIPPYBJMFYBVXKXZBCXMUYHIULRTOWJIDOFKJTBZVSSVQFQTCUZBANGKEGRXAJJDTPGDNOEOLXWMOKSKTNEBPNTIFHHOQSMXQMUIAEMJPGGCEOMVOJQFPQSNDXV");

    try
    {
      Utils::ByteBuffer bfr;
      IMC::Packet::serialize(&msg, bfr);
      IMC::Message* msg_d = IMC::Packet::deserialize(bfr.getBuffer(), bfr.getSize());
      test.boolean("LcdControl #2", msg == *msg_d);
      delete msg_d;
    }
    catch (IMC::InvalidMessageSize& e)
    {
      (void)e;
      test.boolean("msg #2", msg.getSerializationSize() > DUNE_IMC_CONST_MAX_SIZE);
    }
  }

  {
    IMC::PowerOperation msg;
    msg.setTimeStamp(0.3820811616800115);
    msg.setSource(57979U);
    msg.setSourceEntity(215U);
    msg.setDestination(24373U);
    msg.setDestinationEntity(15U);
    msg.op = 200U;
    msg.time_remain = 0.9378720327828771;
    msg.sched_time = 0.8493319672472547;

    try
    {
      Utils::ByteBuffer bfr;
      IMC::Packet::serialize(&msg, bfr);
      IMC::Message* msg_d = IMC::Packet::deserialize(bfr.getBuffer(), bfr.getSize());
      test.boolean("PowerOperation #0", msg == *msg_d);
      delete msg_d;
    }
    catch (IMC::InvalidMessageSize& e)
    {
      (void)e;
      test.boolean("msg #0", msg.getSerializationSize() > DUNE_IMC_CONST_MAX_SIZE);
    }
  }

  {
    IMC::PowerOperation msg;
    msg.setTimeStamp(0.8704002279155691);
    msg.setSource(1567U);
    msg.setSourceEntity(178U);
    msg.setDestination(3043U);
    msg.setDestinationEntity(56U);
    msg.op = 6U;
    msg.time_remain = 0.3257334013617489;
    msg.sched_time = 0.6543103344619823;

    try
    {
      Utils::ByteBuffer bfr;
      IMC::Packet::serialize(&msg, bfr);
      IMC::Message* msg_d = IMC::Packet::deserialize(bfr.getBuffer(), bfr.getSize());
      test.boolean("PowerOperation #1", msg == *msg_d);
      delete msg_d;
    }
    catch (IMC::InvalidMessageSize& e)
    {
      (void)e;
      test.boolean("msg #1", msg.getSerializationSize() > DUNE_IMC_CONST_MAX_SIZE);
    }
  }

  {
    IMC::PowerOperation msg;
    msg.setTimeStamp(0.9566792157270833);
    msg.setSource(18001U);
    msg.setSourceEntity(85U);
    msg.setDestination(47530U);
    msg.setDestinationEntity(230U);
    msg.op = 250U;
    msg.time_remain = 0.2521043758278966;
    msg.sched_time = 0.162416106039888;

    try
    {
      Utils::ByteBuffer bfr;
      IMC::Packet::serialize(&msg, bfr);
      IMC::Message* msg_d = IMC::Packet::deserialize(bfr.getBuffer(), bfr.getSize());
      test.boolean("PowerOperation #2", msg == *msg_d);
      delete msg_d;
    }
    catch (IMC::InvalidMessageSize& e)
    {
      (void)e;
      test.boolean("msg #2", msg.getSerializationSize() > DUNE_IMC_CONST_MAX_SIZE);
    }
  }

  {
    IMC::PowerChannelControl msg;
    msg.setTimeStamp(0.652434356133311);
    msg.setSource(25725U);
    msg.setSourceEntity(184U);
    msg.setDestination(30734U);
    msg.setDestinationEntity(184U);
    msg.name.assign("GBDAGKQPTBWRDRUMSFEVDGZSJWYIVXCMOMDVFNZXRYJTTMNUWIGGCWVHPCHGMFLHWEZVOKEFDDVOCLHWPBZJSWZCPABJOZDEKMSUQGUXQKQSGIAFOFWBUGTYLXBNKOBEJDNEIBFAHLVIRTORAXFPXVWXLARRYPKBWUCUIZQLJAUNGVFJXSJYC");
    msg.op = 122U;
    msg.sched_time = 0.30446802328730704;

    try
    {
      Utils::ByteBuffer bfr;
      IMC::Packet::serialize(&msg, bfr);
      IMC::Message* msg_d = IMC::Packet::deserialize(bfr.getBuffer(), bfr.getSize());
      test.boolean("PowerChannelControl #0", msg == *msg_d);
      delete msg_d;
    }
    catch (IMC::InvalidMessageSize& e)
    {
      (void)e;
      test.boolean("msg #0", msg.getSerializationSize() > DUNE_IMC_CONST_MAX_SIZE);
    }
  }

  {
    IMC::PowerChannelControl msg;
    msg.setTimeStamp(0.6506662732155315);
    msg.setSource(3967U);
    msg.setSourceEntity(212U);
    msg.setDestination(23503U);
    msg.setDestinationEntity(31U);
    msg.name.assign("WJPPXVPLSJIETGJHOLFHHOIVKQYJNTXQGVMTVVBHVOIYDFNKNAEGEVIRZKCTFYJZDNIYAZJYXZSKQBGTOXLZHZBUUHYAGCSRUDCYJKFSCDIDUMUDXGCXVHFOBBYBZGCNBLHKQPZQXWWNYZIOEYCGRPRUJTRDMFMSKLEUFLEULDFHMMMIGMQCCUARPMZTOWTLSQPWAKPBXETSAXJENIPVNQECAJTWAKBRPMRLHSQWONF");
    msg.op = 225U;
    msg.sched_time = 0.800831458594262;

    try
    {
      Utils::ByteBuffer bfr;
      IMC::Packet::serialize(&msg, bfr);
      IMC::Message* msg_d = IMC::Packet::deserialize(bfr.getBuffer(), bfr.getSize());
      test.boolean("PowerChannelControl #1", msg == *msg_d);
      delete msg_d;
    }
    catch (IMC::InvalidMessageSize& e)
    {
      (void)e;
      test.boolean("msg #1", msg.getSerializationSize() > DUNE_IMC_CONST_MAX_SIZE);
    }
  }

  {
    IMC::PowerChannelControl msg;
    msg.setTimeStamp(0.2591047334060813);
    msg.setSource(18520U);
    msg.setSourceEntity(150U);
    msg.setDestination(47184U);
    msg.setDestinationEntity(61U);
    msg.name.assign("ZIZNILFPWU");
    msg.op = 100U;
    msg.sched_time = 0.4345940622576683;

    try
    {
      Utils::ByteBuffer bfr;
      IMC::Packet::serialize(&msg, bfr);
      IMC::Message* msg_d = IMC::Packet::deserialize(bfr.getBuffer(), bfr.getSize());
      test.boolean("PowerChannelControl #2", msg == *msg_d);
      delete msg_d;
    }
    catch (IMC::InvalidMessageSize& e)
    {
      (void)e;
      test.boolean("msg #2", msg.getSerializationSize() > DUNE_IMC_CONST_MAX_SIZE);
    }
  }

  {
    IMC::QueryPowerChannelState msg;
    msg.setTimeStamp(0.8956447002925892);
    msg.setSource(8130U);
    msg.setSourceEntity(1U);
    msg.setDestination(62329U);
    msg.setDestinationEntity(202U);

    try
    {
      Utils::ByteBuffer bfr;
      IMC::Packet::serialize(&msg, bfr);
      IMC::Message* msg_d = IMC::Packet::deserialize(bfr.getBuffer(), bfr.getSize());
      test.boolean("QueryPowerChannelState #0", msg == *msg_d);
      delete msg_d;
    }
    catch (IMC::InvalidMessageSize& e)
    {
      (void)e;
      test.boolean("msg #0", msg.getSerializationSize() > DUNE_IMC_CONST_MAX_SIZE);
    }
  }

  {
    IMC::QueryPowerChannelState msg;
    msg.setTimeStamp(0.4023183100504393);
    msg.setSource(3331U);
    msg.setSourceEntity(195U);
    msg.setDestination(42011U);
    msg.setDestinationEntity(45U);

    try
    {
      Utils::ByteBuffer bfr;
      IMC::Packet::serialize(&msg, bfr);
      IMC::Message* msg_d = IMC::Packet::deserialize(bfr.getBuffer(), bfr.getSize());
      test.boolean("QueryPowerChannelState #1", msg == *msg_d);
      delete msg_d;
    }
    catch (IMC::InvalidMessageSize& e)
    {
      (void)e;
      test.boolean("msg #1", msg.getSerializationSize() > DUNE_IMC_CONST_MAX_SIZE);
    }
  }

  {
    IMC::QueryPowerChannelState msg;
    msg.setTimeStamp(0.42598028445787905);
    msg.setSource(22755U);
    msg.setSourceEntity(119U);
    msg.setDestination(35082U);
    msg.setDestinationEntity(181U);

    try
    {
      Utils::ByteBuffer bfr;
      IMC::Packet::serialize(&msg, bfr);
      IMC::Message* msg_d = IMC::Packet::deserialize(bfr.getBuffer(), bfr.getSize());
      test.boolean("QueryPowerChannelState #2", msg == *msg_d);
      delete msg_d;
    }
    catch (IMC::InvalidMessageSize& e)
    {
      (void)e;
      test.boolean("msg #2", msg.getSerializationSize() > DUNE_IMC_CONST_MAX_SIZE);
    }
  }

  {
    IMC::PowerChannelState msg;
    msg.setTimeStamp(0.23082031810806902);
    msg.setSource(22008U);
    msg.setSourceEntity(211U);
    msg.setDestination(4205U);
    msg.setDestinationEntity(49U);
    msg.name.assign("RLJCZQQWTEYGUETWKIXENYEFDERPHBPBEXWPGRNWETENCSVGDAQHQBJSLFVTAIQRIWLUQVWPDOLZVKUFQXLAIJBXOPQKKHFHRYCIWWJMCWDPYUVIOAGESISRYDZXSZDASRMBKPY");
    msg.state = 151U;

    try
    {
      Utils::ByteBuffer bfr;
      IMC::Packet::serialize(&msg, bfr);
      IMC::Message* msg_d = IMC::Packet::deserialize(bfr.getBuffer(), bfr.getSize());
      test.boolean("PowerChannelState #0", msg == *msg_d);
      delete msg_d;
    }
    catch (IMC::InvalidMessageSize& e)
    {
      (void)e;
      test.boolean("msg #0", msg.getSerializationSize() > DUNE_IMC_CONST_MAX_SIZE);
    }
  }

  {
    IMC::PowerChannelState msg;
    msg.setTimeStamp(0.37094915300330356);
    msg.setSource(20222U);
    msg.setSourceEntity(217U);
    msg.setDestination(48826U);
    msg.setDestinationEntity(24U);
    msg.name.assign("FIPEALRQMPQHKJSFTYQFJUWKGXQVTAHRTPHANLCUSKZDBDUGMGIUSHGQISBBJYUMRWXQQPZDBNTVWPLHVIEJVQFSWJCOYBMMRNABSUWEWKDTDMRTEOZVENOIORHPPVFNHSVHFIDJZNBEHJCULLCPHIDOFEMGEYWNXWZSVOLYFRGCRNIYVKXZRSBFPBKAZMEPVOYTXJWYJDZCCXCIKMUYFEX");
    msg.state = 26U;

    try
    {
      Utils::ByteBuffer bfr;
      IMC::Packet::serialize(&msg, bfr);
      IMC::Message* msg_d = IMC::Packet::deserialize(bfr.getBuffer(), bfr.getSize());
      test.boolean("PowerChannelState #1", msg == *msg_d);
      delete msg_d;
    }
    catch (IMC::InvalidMessageSize& e)
    {
      (void)e;
      test.boolean("msg #1", msg.getSerializationSize() > DUNE_IMC_CONST_MAX_SIZE);
    }
  }

  {
    IMC::PowerChannelState msg;
    msg.setTimeStamp(0.07642756860405808);
    msg.setSource(5489U);
    msg.setSourceEntity(111U);
    msg.setDestination(42115U);
    msg.setDestinationEntity(58U);
    msg.name.assign("SSTSTGPFOQPJOHSTUBPPMQRKTBYYHPIMAITDMXMFRNTJJVRDOVXRKCJRNDCQNIALSUAYUZYCKJTKQELYEEZGWOAMXAKVLKYJHEBFAAMPOLNIYZZEZCUNNXGUQWYEONQEXFQHMLDUGCUDVEKIJIRRFSVIDCHQGWFRNOZBWDQVLTEGCXHIGUXCLCLDJLWGKVJTAHAYFPNPWLSWINMXVDPUOIUJGGBHWQOKBFRBVW");
    msg.state = 110U;

    try
    {
      Utils::ByteBuffer bfr;
      IMC::Packet::serialize(&msg, bfr);
      IMC::Message* msg_d = IMC::Packet::deserialize(bfr.getBuffer(), bfr.getSize());
      test.boolean("PowerChannelState #2", msg == *msg_d);
      delete msg_d;
    }
    catch (IMC::InvalidMessageSize& e)
    {
      (void)e;
      test.boolean("msg #2", msg.getSerializationSize() > DUNE_IMC_CONST_MAX_SIZE);
    }
  }

  {
    IMC::LedBrightness msg;
    msg.setTimeStamp(0.5489796963860588);
    msg.setSource(27240U);
    msg.setSourceEntity(96U);
    msg.setDestination(13664U);
    msg.setDestinationEntity(143U);
    msg.name.assign("FMPUVMHDERSFWWBUPDIVURTOJLSJDCIUSNCJBTGVHQAIZRSBMJYVRAXBBEKKNCFZKQZQVFLGTSZWACZXEVQYTYTPAHDJVLLRRKOPJFIOLGHAQIWUDZOTCCRYUSHGCILDPNMQOHOARMEUVKSLXX");
    msg.value = 107U;

    try
    {
      Utils::ByteBuffer bfr;
      IMC::Packet::serialize(&msg, bfr);
      IMC::Message* msg_d = IMC::Packet::deserialize(bfr.getBuffer(), bfr.getSize());
      test.boolean("LedBrightness #0", msg == *msg_d);
      delete msg_d;
    }
    catch (IMC::InvalidMessageSize& e)
    {
      (void)e;
      test.boolean("msg #0", msg.getSerializationSize() > DUNE_IMC_CONST_MAX_SIZE);
    }
  }

  {
    IMC::LedBrightness msg;
    msg.setTimeStamp(0.7911051655697608);
    msg.setSource(34644U);
    msg.setSourceEntity(35U);
    msg.setDestination(8083U);
    msg.setDestinationEntity(180U);
    msg.name.assign("PJYJIKZUGVEVUNCPNFCGRLERVOSKCENCFYGYURNQZERRBTETYNPUAPYSPXHWFUVZCXVTXBJIBAQKLYOLIOKCNXBKKZYHMQSGWOJMNDMHMDYSOVAADEAZYKAVBGEXUZBPMJWDPGWQZTIIROEIXDTEOKRTWDKVFSJURXXHRDXMUZNWIMSYQWLQUOFLJORNLFFQENFHTQQCLIKSTFAM");
    msg.value = 60U;

    try
    {
      Utils::ByteBuffer bfr;
      IMC::Packet::serialize(&msg, bfr);
      IMC::Message* msg_d = IMC::Packet::deserialize(bfr.getBuffer(), bfr.getSize());
      test.boolean("LedBrightness #1", msg == *msg_d);
      delete msg_d;
    }
    catch (IMC::InvalidMessageSize& e)
    {
      (void)e;
      test.boolean("msg #1", msg.getSerializationSize() > DUNE_IMC_CONST_MAX_SIZE);
    }
  }

  {
    IMC::LedBrightness msg;
    msg.setTimeStamp(0.26120117401333465);
    msg.setSource(19785U);
    msg.setSourceEntity(184U);
    msg.setDestination(30663U);
    msg.setDestinationEntity(223U);
    msg.name.assign("NGMTFMKHEDBEJAPDXIOXKONRHTPWZXLWYHKNUJIHVLODSQCICAAHSZBMBWDTVQPYZRSXCFXJBGEOCVKIOFPTELSQHRFPSWYRAIURKYBWDSYHMMVZEVDSACUDDZI");
    msg.value = 196U;

    try
    {
      Utils::ByteBuffer bfr;
      IMC::Packet::serialize(&msg, bfr);
      IMC::Message* msg_d = IMC::Packet::deserialize(bfr.getBuffer(), bfr.getSize());
      test.boolean("LedBrightness #2", msg == *msg_d);
      delete msg_d;
    }
    catch (IMC::InvalidMessageSize& e)
    {
      (void)e;
      test.boolean("msg #2", msg.getSerializationSize() > DUNE_IMC_CONST_MAX_SIZE);
    }
  }

  {
    IMC::QueryLedBrightness msg;
    msg.setTimeStamp(0.4139737969410947);
    msg.setSource(300U);
    msg.setSourceEntity(220U);
    msg.setDestination(18330U);
    msg.setDestinationEntity(79U);
    msg.name.assign("OKEIHRCLUGVWHSZUAKYBVJBODGQIKVEXATH");

    try
    {
      Utils::ByteBuffer bfr;
      IMC::Packet::serialize(&msg, bfr);
      IMC::Message* msg_d = IMC::Packet::deserialize(bfr.getBuffer(), bfr.getSize());
      test.boolean("QueryLedBrightness #0", msg == *msg_d);
      delete msg_d;
    }
    catch (IMC::InvalidMessageSize& e)
    {
      (void)e;
      test.boolean("msg #0", msg.getSerializationSize() > DUNE_IMC_CONST_MAX_SIZE);
    }
  }

  {
    IMC::QueryLedBrightness msg;
    msg.setTimeStamp(0.9139077551456858);
    msg.setSource(38037U);
    msg.setSourceEntity(120U);
    msg.setDestination(49883U);
    msg.setDestinationEntity(31U);
    msg.name.assign("PQZWYPOFYCLNHBOTMHVSKMZPQEIORXFZCDCDQKKQWXHYFODQPMGAJBJBCPYSXJVDAEFVSFIEAUNMJRVMHTBGLUBAKUPCDFHILVREFENKKSENOXFSEUWTZHFTLGYKORNCTDAMYOLIAHFUZGDRLXGCRQJMBDKSCKZISZMBLGLBNVZRWSCQXIPVTAEVMJQH");

    try
    {
      Utils::ByteBuffer bfr;
      IMC::Packet::serialize(&msg, bfr);
      IMC::Message* msg_d = IMC::Packet::deserialize(bfr.getBuffer(), bfr.getSize());
      test.boolean("QueryLedBrightness #1", msg == *msg_d);
      delete msg_d;
    }
    catch (IMC::InvalidMessageSize& e)
    {
      (void)e;
      test.boolean("msg #1", msg.getSerializationSize() > DUNE_IMC_CONST_MAX_SIZE);
    }
  }

  {
    IMC::QueryLedBrightness msg;
    msg.setTimeStamp(0.191617134434502);
    msg.setSource(40265U);
    msg.setSourceEntity(73U);
    msg.setDestination(52178U);
    msg.setDestinationEntity(170U);
    msg.name.assign("TCWEZWBHYMAUVTKFLNUNFVUYYBJWDDDNRJKLCPFQDHIAPOSYJCTGHAULQXFINSXGVMAEJTQGZKFZPHYOTUOOWAYMXEJGHGBJVOSWUVXDQGNXQTSEZYIRXSZVFZVHKHPAJBNBUNCAPLDDRHZUKCOQMIJPIGVJBU");

    try
    {
      Utils::ByteBuffer bfr;
      IMC::Packet::serialize(&msg, bfr);
      IMC::Message* msg_d = IMC::Packet::deserialize(bfr.getBuffer(), bfr.getSize());
      test.boolean("QueryLedBrightness #2", msg == *msg_d);
      delete msg_d;
    }
    catch (IMC::InvalidMessageSize& e)
    {
      (void)e;
      test.boolean("msg #2", msg.getSerializationSize() > DUNE_IMC_CONST_MAX_SIZE);
    }
  }

  {
    IMC::SetLedBrightness msg;
    msg.setTimeStamp(0.9289985435725325);
    msg.setSource(57135U);
    msg.setSourceEntity(93U);
    msg.setDestination(36787U);
    msg.setDestinationEntity(131U);
    msg.name.assign("PCAROWBAOPRRFUNMGEIG");
    msg.value = 226U;

    try
    {
      Utils::ByteBuffer bfr;
      IMC::Packet::serialize(&msg, bfr);
      IMC::Message* msg_d = IMC::Packet::deserialize(bfr.getBuffer(), bfr.getSize());
      test.boolean("SetLedBrightness #0", msg == *msg_d);
      delete msg_d;
    }
    catch (IMC::InvalidMessageSize& e)
    {
      (void)e;
      test.boolean("msg #0", msg.getSerializationSize() > DUNE_IMC_CONST_MAX_SIZE);
    }
  }

  {
    IMC::SetLedBrightness msg;
    msg.setTimeStamp(0.15743480819542321);
    msg.setSource(58583U);
    msg.setSourceEntity(10U);
    msg.setDestination(46714U);
    msg.setDestinationEntity(35U);
    msg.name.assign("AKGTSKKDFHTSLBHCZRPMAXGNXFVQSYCYZYOCFWNRZLIZWROANTGBRLSVGZMATQEOQOQNJGUQXENKTXIDJFDZJHLQULYMVETYDTDRIUPALIVMPKHEQYROEOHKNAVSFKYHZVXCGOQFEDQPSWCGZFEHBDGINCHXTWPVEDUDMWLGZEWZU");
    msg.value = 167U;

    try
    {
      Utils::ByteBuffer bfr;
      IMC::Packet::serialize(&msg, bfr);
      IMC::Message* msg_d = IMC::Packet::deserialize(bfr.getBuffer(), bfr.getSize());
      test.boolean("SetLedBrightness #1", msg == *msg_d);
      delete msg_d;
    }
    catch (IMC::InvalidMessageSize& e)
    {
      (void)e;
      test.boolean("msg #1", msg.getSerializationSize() > DUNE_IMC_CONST_MAX_SIZE);
    }
  }

  {
    IMC::SetLedBrightness msg;
    msg.setTimeStamp(0.030012212328522803);
    msg.setSource(46290U);
    msg.setSourceEntity(131U);
    msg.setDestination(63280U);
    msg.setDestinationEntity(77U);
    msg.name.assign("FNQQPVPHGVNXVCUZHXGBREFRJHGMOZFFQUGCJJCSTMRVHKAOAJNSMSUFPMMFDRDDRJOXEJJMCGKTBIYYFZUOTPWGUOYZGQWNICVQBZZRMCETGMKJBAZGDDMSXTPYKWZBXVHSXSWSKFIYDDVKWAEKDAILORPSQRBLVNTXLLTCNZUORUIGWWCPLDEJFLDSJKU");
    msg.value = 27U;

    try
    {
      Utils::ByteBuffer bfr;
      IMC::Packet::serialize(&msg, bfr);
      IMC::Message* msg_d = IMC::Packet::deserialize(bfr.getBuffer(), bfr.getSize());
      test.boolean("SetLedBrightness #2", msg == *msg_d);
      delete msg_d;
    }
    catch (IMC::InvalidMessageSize& e)
    {
      (void)e;
      test.boolean("msg #2", msg.getSerializationSize() > DUNE_IMC_CONST_MAX_SIZE);
    }
  }

  {
    IMC::SetPWM msg;
    msg.setTimeStamp(0.5459066418856142);
    msg.setSource(64711U);
    msg.setSourceEntity(68U);
    msg.setDestination(58415U);
    msg.setDestinationEntity(41U);
    msg.id = 204U;
    msg.period = 1481184781U;
    msg.duty_cycle = 1513795824U;

    try
    {
      Utils::ByteBuffer bfr;
      IMC::Packet::serialize(&msg, bfr);
      IMC::Message* msg_d = IMC::Packet::deserialize(bfr.getBuffer(), bfr.getSize());
      test.boolean("SetPWM #0", msg == *msg_d);
      delete msg_d;
    }
    catch (IMC::InvalidMessageSize& e)
    {
      (void)e;
      test.boolean("msg #0", msg.getSerializationSize() > DUNE_IMC_CONST_MAX_SIZE);
    }
  }

  {
    IMC::SetPWM msg;
    msg.setTimeStamp(0.907035605057544);
    msg.setSource(2866U);
    msg.setSourceEntity(251U);
    msg.setDestination(4321U);
    msg.setDestinationEntity(56U);
    msg.id = 185U;
    msg.period = 633126846U;
    msg.duty_cycle = 3370678611U;

    try
    {
      Utils::ByteBuffer bfr;
      IMC::Packet::serialize(&msg, bfr);
      IMC::Message* msg_d = IMC::Packet::deserialize(bfr.getBuffer(), bfr.getSize());
      test.boolean("SetPWM #1", msg == *msg_d);
      delete msg_d;
    }
    catch (IMC::InvalidMessageSize& e)
    {
      (void)e;
      test.boolean("msg #1", msg.getSerializationSize() > DUNE_IMC_CONST_MAX_SIZE);
    }
  }

  {
    IMC::SetPWM msg;
    msg.setTimeStamp(0.3031055484878574);
    msg.setSource(63064U);
    msg.setSourceEntity(198U);
    msg.setDestination(52029U);
    msg.setDestinationEntity(115U);
    msg.id = 23U;
    msg.period = 2315897464U;
    msg.duty_cycle = 695443528U;

    try
    {
      Utils::ByteBuffer bfr;
      IMC::Packet::serialize(&msg, bfr);
      IMC::Message* msg_d = IMC::Packet::deserialize(bfr.getBuffer(), bfr.getSize());
      test.boolean("SetPWM #2", msg == *msg_d);
      delete msg_d;
    }
    catch (IMC::InvalidMessageSize& e)
    {
      (void)e;
      test.boolean("msg #2", msg.getSerializationSize() > DUNE_IMC_CONST_MAX_SIZE);
    }
  }

  {
    IMC::PWM msg;
    msg.setTimeStamp(0.1428693046334807);
    msg.setSource(22776U);
    msg.setSourceEntity(197U);
    msg.setDestination(15436U);
    msg.setDestinationEntity(127U);
    msg.id = 111U;
    msg.period = 2101887326U;
    msg.duty_cycle = 427435808U;

    try
    {
      Utils::ByteBuffer bfr;
      IMC::Packet::serialize(&msg, bfr);
      IMC::Message* msg_d = IMC::Packet::deserialize(bfr.getBuffer(), bfr.getSize());
      test.boolean("PWM #0", msg == *msg_d);
      delete msg_d;
    }
    catch (IMC::InvalidMessageSize& e)
    {
      (void)e;
      test.boolean("msg #0", msg.getSerializationSize() > DUNE_IMC_CONST_MAX_SIZE);
    }
  }

  {
    IMC::PWM msg;
    msg.setTimeStamp(0.28974500069042697);
    msg.setSource(38574U);
    msg.setSourceEntity(0U);
    msg.setDestination(23599U);
    msg.setDestinationEntity(45U);
    msg.id = 17U;
    msg.period = 3300700371U;
    msg.duty_cycle = 3077678908U;

    try
    {
      Utils::ByteBuffer bfr;
      IMC::Packet::serialize(&msg, bfr);
      IMC::Message* msg_d = IMC::Packet::deserialize(bfr.getBuffer(), bfr.getSize());
      test.boolean("PWM #1", msg == *msg_d);
      delete msg_d;
    }
    catch (IMC::InvalidMessageSize& e)
    {
      (void)e;
      test.boolean("msg #1", msg.getSerializationSize() > DUNE_IMC_CONST_MAX_SIZE);
    }
  }

  {
    IMC::PWM msg;
    msg.setTimeStamp(0.9253618787217236);
    msg.setSource(58227U);
    msg.setSourceEntity(237U);
    msg.setDestination(21797U);
    msg.setDestinationEntity(74U);
    msg.id = 178U;
    msg.period = 1378841042U;
    msg.duty_cycle = 1145595003U;

    try
    {
      Utils::ByteBuffer bfr;
      IMC::Packet::serialize(&msg, bfr);
      IMC::Message* msg_d = IMC::Packet::deserialize(bfr.getBuffer(), bfr.getSize());
      test.boolean("PWM #2", msg == *msg_d);
      delete msg_d;
    }
    catch (IMC::InvalidMessageSize& e)
    {
      (void)e;
      test.boolean("msg #2", msg.getSerializationSize() > DUNE_IMC_CONST_MAX_SIZE);
    }
  }

  {
    IMC::EstimatedState msg;
    msg.setTimeStamp(0.5558380503290697);
    msg.setSource(38936U);
    msg.setSourceEntity(165U);
    msg.setDestination(17011U);
    msg.setDestinationEntity(249U);
    msg.lat = 0.6143674754729386;
    msg.lon = 0.4151762428750957;
    msg.height = 0.39468039856443793;
    msg.x = 0.8504333263380005;
    msg.y = 0.23601020807058726;
    msg.z = 0.8884883833620686;
    msg.phi = 0.33311770744313196;
    msg.theta = 0.9533319135556008;
    msg.psi = 0.4177115377366164;
    msg.u = 0.7112722946563675;
    msg.v = 0.95897837525814;
    msg.w = 0.5828409072893455;
    msg.vx = 0.6119506478834504;
    msg.vy = 0.8060302437752678;
    msg.vz = 0.8349327363641283;
    msg.p = 0.21832169848323357;
    msg.q = 0.34217078930033507;
    msg.r = 0.7103800969318431;
    msg.depth = 0.9734572468063774;
    msg.alt = 0.7767356158256095;

    try
    {
      Utils::ByteBuffer bfr;
      IMC::Packet::serialize(&msg, bfr);
      IMC::Message* msg_d = IMC::Packet::deserialize(bfr.getBuffer(), bfr.getSize());
      test.boolean("EstimatedState #0", msg == *msg_d);
      delete msg_d;
    }
    catch (IMC::InvalidMessageSize& e)
    {
      (void)e;
      test.boolean("msg #0", msg.getSerializationSize() > DUNE_IMC_CONST_MAX_SIZE);
    }
  }

  {
    IMC::EstimatedState msg;
    msg.setTimeStamp(0.9598789557025077);
    msg.setSource(38193U);
    msg.setSourceEntity(232U);
    msg.setDestination(15658U);
    msg.setDestinationEntity(114U);
    msg.lat = 0.22303778941905417;
    msg.lon = 0.21102534053920075;
    msg.height = 0.9163286950666195;
    msg.x = 0.3876234353538699;
    msg.y = 0.7747269943729143;
    msg.z = 0.7811844665742055;
    msg.phi = 0.6633097329213338;
    msg.theta = 0.7858724526497617;
    msg.psi = 0.4382704606636716;
    msg.u = 0.0318266235062985;
    msg.v = 0.8024966687205883;
    msg.w = 0.1085187977642803;
    msg.vx = 0.34704613504856674;
    msg.vy = 0.017161260104412213;
    msg.vz = 0.6817458371025737;
    msg.p = 0.5214005416109389;
    msg.q = 0.998268116235065;
    msg.r = 0.5773625830151774;
    msg.depth = 0.027182289677639804;
    msg.alt = 0.5658713696904056;

    try
    {
      Utils::ByteBuffer bfr;
      IMC::Packet::serialize(&msg, bfr);
      IMC::Message* msg_d = IMC::Packet::deserialize(bfr.getBuffer(), bfr.getSize());
      test.boolean("EstimatedState #1", msg == *msg_d);
      delete msg_d;
    }
    catch (IMC::InvalidMessageSize& e)
    {
      (void)e;
      test.boolean("msg #1", msg.getSerializationSize() > DUNE_IMC_CONST_MAX_SIZE);
    }
  }

  {
    IMC::EstimatedState msg;
    msg.setTimeStamp(0.1323697849470954);
    msg.setSource(45799U);
    msg.setSourceEntity(167U);
    msg.setDestination(36922U);
    msg.setDestinationEntity(84U);
    msg.lat = 0.565718429599038;
    msg.lon = 0.0735935846453386;
    msg.height = 0.21367678261072254;
    msg.x = 0.11301080867321889;
    msg.y = 0.15906376487556895;
    msg.z = 0.27623766454638055;
    msg.phi = 0.5251138120355427;
    msg.theta = 0.9059572377284245;
    msg.psi = 0.7211173121428669;
    msg.u = 0.7731847123727695;
    msg.v = 0.3896233376091699;
    msg.w = 0.5751258796039259;
    msg.vx = 0.0928022579847062;
    msg.vy = 0.009062909983728495;
    msg.vz = 0.05932618589927929;
    msg.p = 0.2894330432103881;
    msg.q = 0.3287173599095812;
    msg.r = 0.2569145472938007;
    msg.depth = 0.3128253492484736;
    msg.alt = 0.3680733923979317;

    try
    {
      Utils::ByteBuffer bfr;
      IMC::Packet::serialize(&msg, bfr);
      IMC::Message* msg_d = IMC::Packet::deserialize(bfr.getBuffer(), bfr.getSize());
      test.boolean("EstimatedState #2", msg == *msg_d);
      delete msg_d;
    }
    catch (IMC::InvalidMessageSize& e)
    {
      (void)e;
      test.boolean("msg #2", msg.getSerializationSize() > DUNE_IMC_CONST_MAX_SIZE);
    }
  }

  {
    IMC::EstimatedStreamVelocity msg;
    msg.setTimeStamp(0.08574009725146803);
    msg.setSource(47380U);
    msg.setSourceEntity(22U);
    msg.setDestination(17536U);
    msg.setDestinationEntity(157U);
    msg.x = 0.11706858943417298;
    msg.y = 0.11412493767467169;
    msg.z = 0.7115756213648586;

    try
    {
      Utils::ByteBuffer bfr;
      IMC::Packet::serialize(&msg, bfr);
      IMC::Message* msg_d = IMC::Packet::deserialize(bfr.getBuffer(), bfr.getSize());
      test.boolean("EstimatedStreamVelocity #0", msg == *msg_d);
      delete msg_d;
    }
    catch (IMC::InvalidMessageSize& e)
    {
      (void)e;
      test.boolean("msg #0", msg.getSerializationSize() > DUNE_IMC_CONST_MAX_SIZE);
    }
  }

  {
    IMC::EstimatedStreamVelocity msg;
    msg.setTimeStamp(0.7478190776862549);
    msg.setSource(48059U);
    msg.setSourceEntity(163U);
    msg.setDestination(62643U);
    msg.setDestinationEntity(247U);
    msg.x = 0.6889297655228761;
    msg.y = 0.9088101881782475;
    msg.z = 0.6884024812548539;

    try
    {
      Utils::ByteBuffer bfr;
      IMC::Packet::serialize(&msg, bfr);
      IMC::Message* msg_d = IMC::Packet::deserialize(bfr.getBuffer(), bfr.getSize());
      test.boolean("EstimatedStreamVelocity #1", msg == *msg_d);
      delete msg_d;
    }
    catch (IMC::InvalidMessageSize& e)
    {
      (void)e;
      test.boolean("msg #1", msg.getSerializationSize() > DUNE_IMC_CONST_MAX_SIZE);
    }
  }

  {
    IMC::EstimatedStreamVelocity msg;
    msg.setTimeStamp(0.7420023756054959);
    msg.setSource(55547U);
    msg.setSourceEntity(118U);
    msg.setDestination(59980U);
    msg.setDestinationEntity(186U);
    msg.x = 0.3240778762962859;
    msg.y = 0.6111434507869398;
    msg.z = 0.05190918111386511;

    try
    {
      Utils::ByteBuffer bfr;
      IMC::Packet::serialize(&msg, bfr);
      IMC::Message* msg_d = IMC::Packet::deserialize(bfr.getBuffer(), bfr.getSize());
      test.boolean("EstimatedStreamVelocity #2", msg == *msg_d);
      delete msg_d;
    }
    catch (IMC::InvalidMessageSize& e)
    {
      (void)e;
      test.boolean("msg #2", msg.getSerializationSize() > DUNE_IMC_CONST_MAX_SIZE);
    }
  }

  {
    IMC::IndicatedSpeed msg;
    msg.setTimeStamp(0.4003091815155301);
    msg.setSource(15285U);
    msg.setSourceEntity(181U);
    msg.setDestination(55750U);
    msg.setDestinationEntity(70U);
    msg.value = 0.24723336117890782;

    try
    {
      Utils::ByteBuffer bfr;
      IMC::Packet::serialize(&msg, bfr);
      IMC::Message* msg_d = IMC::Packet::deserialize(bfr.getBuffer(), bfr.getSize());
      test.boolean("IndicatedSpeed #0", msg == *msg_d);
      delete msg_d;
    }
    catch (IMC::InvalidMessageSize& e)
    {
      (void)e;
      test.boolean("msg #0", msg.getSerializationSize() > DUNE_IMC_CONST_MAX_SIZE);
    }
  }

  {
    IMC::IndicatedSpeed msg;
    msg.setTimeStamp(0.2213165077986301);
    msg.setSource(41455U);
    msg.setSourceEntity(216U);
    msg.setDestination(60976U);
    msg.setDestinationEntity(96U);
    msg.value = 0.8769931904988616;

    try
    {
      Utils::ByteBuffer bfr;
      IMC::Packet::serialize(&msg, bfr);
      IMC::Message* msg_d = IMC::Packet::deserialize(bfr.getBuffer(), bfr.getSize());
      test.boolean("IndicatedSpeed #1", msg == *msg_d);
      delete msg_d;
    }
    catch (IMC::InvalidMessageSize& e)
    {
      (void)e;
      test.boolean("msg #1", msg.getSerializationSize() > DUNE_IMC_CONST_MAX_SIZE);
    }
  }

  {
    IMC::IndicatedSpeed msg;
    msg.setTimeStamp(0.15177841656418523);
    msg.setSource(44201U);
    msg.setSourceEntity(73U);
    msg.setDestination(36742U);
    msg.setDestinationEntity(132U);
    msg.value = 0.8492767657917691;

    try
    {
      Utils::ByteBuffer bfr;
      IMC::Packet::serialize(&msg, bfr);
      IMC::Message* msg_d = IMC::Packet::deserialize(bfr.getBuffer(), bfr.getSize());
      test.boolean("IndicatedSpeed #2", msg == *msg_d);
      delete msg_d;
    }
    catch (IMC::InvalidMessageSize& e)
    {
      (void)e;
      test.boolean("msg #2", msg.getSerializationSize() > DUNE_IMC_CONST_MAX_SIZE);
    }
  }

  {
    IMC::TrueSpeed msg;
    msg.setTimeStamp(0.015145193271943413);
    msg.setSource(617U);
    msg.setSourceEntity(56U);
    msg.setDestination(42814U);
    msg.setDestinationEntity(46U);
    msg.value = 0.6367069569853723;

    try
    {
      Utils::ByteBuffer bfr;
      IMC::Packet::serialize(&msg, bfr);
      IMC::Message* msg_d = IMC::Packet::deserialize(bfr.getBuffer(), bfr.getSize());
      test.boolean("TrueSpeed #0", msg == *msg_d);
      delete msg_d;
    }
    catch (IMC::InvalidMessageSize& e)
    {
      (void)e;
      test.boolean("msg #0", msg.getSerializationSize() > DUNE_IMC_CONST_MAX_SIZE);
    }
  }

  {
    IMC::TrueSpeed msg;
    msg.setTimeStamp(0.793969922023949);
    msg.setSource(7250U);
    msg.setSourceEntity(188U);
    msg.setDestination(8499U);
    msg.setDestinationEntity(180U);
    msg.value = 0.07574184875576018;

    try
    {
      Utils::ByteBuffer bfr;
      IMC::Packet::serialize(&msg, bfr);
      IMC::Message* msg_d = IMC::Packet::deserialize(bfr.getBuffer(), bfr.getSize());
      test.boolean("TrueSpeed #1", msg == *msg_d);
      delete msg_d;
    }
    catch (IMC::InvalidMessageSize& e)
    {
      (void)e;
      test.boolean("msg #1", msg.getSerializationSize() > DUNE_IMC_CONST_MAX_SIZE);
    }
  }

  {
    IMC::TrueSpeed msg;
    msg.setTimeStamp(0.7092413817608687);
    msg.setSource(48703U);
    msg.setSourceEntity(248U);
    msg.setDestination(14533U);
    msg.setDestinationEntity(208U);
    msg.value = 0.13161240934668006;

    try
    {
      Utils::ByteBuffer bfr;
      IMC::Packet::serialize(&msg, bfr);
      IMC::Message* msg_d = IMC::Packet::deserialize(bfr.getBuffer(), bfr.getSize());
      test.boolean("TrueSpeed #2", msg == *msg_d);
      delete msg_d;
    }
    catch (IMC::InvalidMessageSize& e)
    {
      (void)e;
      test.boolean("msg #2", msg.getSerializationSize() > DUNE_IMC_CONST_MAX_SIZE);
    }
  }

  {
    IMC::NavigationUncertainty msg;
    msg.setTimeStamp(0.11316462548126949);
    msg.setSource(1480U);
    msg.setSourceEntity(68U);
    msg.setDestination(45485U);
    msg.setDestinationEntity(175U);
    msg.x = 0.7956519041616666;
    msg.y = 0.6954509813375639;
    msg.z = 0.5428426855336633;
    msg.phi = 0.732876375816457;
    msg.theta = 0.8217230153283869;
    msg.psi = 0.7616426219574303;
    msg.p = 0.7455356238955733;
    msg.q = 0.623770041755188;
    msg.r = 0.6890923446219432;
    msg.u = 0.6205004490691189;
    msg.v = 0.5197180354380356;
    msg.w = 0.24870595002826468;
    msg.bias_psi = 0.2742763622452121;
    msg.bias_r = 0.4924038265685676;

    try
    {
      Utils::ByteBuffer bfr;
      IMC::Packet::serialize(&msg, bfr);
      IMC::Message* msg_d = IMC::Packet::deserialize(bfr.getBuffer(), bfr.getSize());
      test.boolean("NavigationUncertainty #0", msg == *msg_d);
      delete msg_d;
    }
    catch (IMC::InvalidMessageSize& e)
    {
      (void)e;
      test.boolean("msg #0", msg.getSerializationSize() > DUNE_IMC_CONST_MAX_SIZE);
    }
  }

  {
    IMC::NavigationUncertainty msg;
    msg.setTimeStamp(0.5943182367517658);
    msg.setSource(50127U);
    msg.setSourceEntity(75U);
    msg.setDestination(158U);
    msg.setDestinationEntity(121U);
    msg.x = 0.7580302672606778;
    msg.y = 0.9385067552672502;
    msg.z = 0.8505463992888365;
    msg.phi = 0.525518705956819;
    msg.theta = 0.9662115109896569;
    msg.psi = 0.9077892528208992;
    msg.p = 0.1668423352336641;
    msg.q = 0.4644528430905921;
    msg.r = 0.9527058768511043;
    msg.u = 0.13900948312855355;
    msg.v = 0.2781555354946226;
    msg.w = 0.37132157431406543;
    msg.bias_psi = 0.8014545507698773;
    msg.bias_r = 0.8428000066180603;

    try
    {
      Utils::ByteBuffer bfr;
      IMC::Packet::serialize(&msg, bfr);
      IMC::Message* msg_d = IMC::Packet::deserialize(bfr.getBuffer(), bfr.getSize());
      test.boolean("NavigationUncertainty #1", msg == *msg_d);
      delete msg_d;
    }
    catch (IMC::InvalidMessageSize& e)
    {
      (void)e;
      test.boolean("msg #1", msg.getSerializationSize() > DUNE_IMC_CONST_MAX_SIZE);
    }
  }

  {
    IMC::NavigationUncertainty msg;
    msg.setTimeStamp(0.12943900942880282);
    msg.setSource(5181U);
    msg.setSourceEntity(106U);
    msg.setDestination(58677U);
    msg.setDestinationEntity(95U);
    msg.x = 0.7153185322454768;
    msg.y = 0.8144077981573747;
    msg.z = 0.09706345543054362;
    msg.phi = 0.4497321375822224;
    msg.theta = 0.43493344025114067;
    msg.psi = 0.5065678848660858;
    msg.p = 0.5437094005122846;
    msg.q = 0.9950846225313366;
    msg.r = 0.7728649013834638;
    msg.u = 0.797040182066585;
    msg.v = 0.757028753559371;
    msg.w = 0.8521506668358058;
    msg.bias_psi = 0.3812072008169274;
    msg.bias_r = 0.5039838469960568;

    try
    {
      Utils::ByteBuffer bfr;
      IMC::Packet::serialize(&msg, bfr);
      IMC::Message* msg_d = IMC::Packet::deserialize(bfr.getBuffer(), bfr.getSize());
      test.boolean("NavigationUncertainty #2", msg == *msg_d);
      delete msg_d;
    }
    catch (IMC::InvalidMessageSize& e)
    {
      (void)e;
      test.boolean("msg #2", msg.getSerializationSize() > DUNE_IMC_CONST_MAX_SIZE);
    }
  }

  {
    IMC::NavigationData msg;
    msg.setTimeStamp(0.4582723706630264);
    msg.setSource(45489U);
    msg.setSourceEntity(99U);
    msg.setDestination(37580U);
    msg.setDestinationEntity(140U);
    msg.bias_psi = 0.6856250276683656;
    msg.bias_r = 0.6952921952498857;
    msg.cog = 0.9632396681847862;
    msg.cyaw = 0.6804959965326267;
    msg.lbl_rej_level = 0.5808404151138246;
    msg.gps_rej_level = 0.9948173614325653;
    msg.custom_x = 0.5337380913238345;
    msg.custom_y = 0.9288381449884685;
    msg.custom_z = 0.44565074572978847;

    try
    {
      Utils::ByteBuffer bfr;
      IMC::Packet::serialize(&msg, bfr);
      IMC::Message* msg_d = IMC::Packet::deserialize(bfr.getBuffer(), bfr.getSize());
      test.boolean("NavigationData #0", msg == *msg_d);
      delete msg_d;
    }
    catch (IMC::InvalidMessageSize& e)
    {
      (void)e;
      test.boolean("msg #0", msg.getSerializationSize() > DUNE_IMC_CONST_MAX_SIZE);
    }
  }

  {
    IMC::NavigationData msg;
    msg.setTimeStamp(0.8225297690848524);
    msg.setSource(19135U);
    msg.setSourceEntity(27U);
    msg.setDestination(19610U);
    msg.setDestinationEntity(163U);
    msg.bias_psi = 0.594196431421436;
    msg.bias_r = 0.6531630457884652;
    msg.cog = 0.44511745974537187;
    msg.cyaw = 0.5269378271939709;
    msg.lbl_rej_level = 0.08735729315809271;
    msg.gps_rej_level = 0.9211306373699854;
    msg.custom_x = 0.3426290326039796;
    msg.custom_y = 0.012235468138785177;
    msg.custom_z = 0.18098585566078218;

    try
    {
      Utils::ByteBuffer bfr;
      IMC::Packet::serialize(&msg, bfr);
      IMC::Message* msg_d = IMC::Packet::deserialize(bfr.getBuffer(), bfr.getSize());
      test.boolean("NavigationData #1", msg == *msg_d);
      delete msg_d;
    }
    catch (IMC::InvalidMessageSize& e)
    {
      (void)e;
      test.boolean("msg #1", msg.getSerializationSize() > DUNE_IMC_CONST_MAX_SIZE);
    }
  }

  {
    IMC::NavigationData msg;
    msg.setTimeStamp(0.3169462288560012);
    msg.setSource(23549U);
    msg.setSourceEntity(74U);
    msg.setDestination(235U);
    msg.setDestinationEntity(204U);
    msg.bias_psi = 0.21501456041363198;
    msg.bias_r = 0.13383592170287617;
    msg.cog = 0.07313799824449962;
    msg.cyaw = 0.3939542697873567;
    msg.lbl_rej_level = 0.650412454427345;
    msg.gps_rej_level = 0.7701326798516658;
    msg.custom_x = 0.5499385691935913;
    msg.custom_y = 0.4665771445016069;
    msg.custom_z = 0.0879435998445739;

    try
    {
      Utils::ByteBuffer bfr;
      IMC::Packet::serialize(&msg, bfr);
      IMC::Message* msg_d = IMC::Packet::deserialize(bfr.getBuffer(), bfr.getSize());
      test.boolean("NavigationData #2", msg == *msg_d);
      delete msg_d;
    }
    catch (IMC::InvalidMessageSize& e)
    {
      (void)e;
      test.boolean("msg #2", msg.getSerializationSize() > DUNE_IMC_CONST_MAX_SIZE);
    }
  }

  {
    IMC::GpsFixRejection msg;
    msg.setTimeStamp(0.3177679600047044);
    msg.setSource(65421U);
    msg.setSourceEntity(180U);
    msg.setDestination(36051U);
    msg.setDestinationEntity(254U);
    msg.utc_time = 0.769418519741913;
    msg.reason = 232U;

    try
    {
      Utils::ByteBuffer bfr;
      IMC::Packet::serialize(&msg, bfr);
      IMC::Message* msg_d = IMC::Packet::deserialize(bfr.getBuffer(), bfr.getSize());
      test.boolean("GpsFixRejection #0", msg == *msg_d);
      delete msg_d;
    }
    catch (IMC::InvalidMessageSize& e)
    {
      (void)e;
      test.boolean("msg #0", msg.getSerializationSize() > DUNE_IMC_CONST_MAX_SIZE);
    }
  }

  {
    IMC::GpsFixRejection msg;
    msg.setTimeStamp(0.1921074911245637);
    msg.setSource(12536U);
    msg.setSourceEntity(204U);
    msg.setDestination(17517U);
    msg.setDestinationEntity(240U);
    msg.utc_time = 0.5333683094312672;
    msg.reason = 87U;

    try
    {
      Utils::ByteBuffer bfr;
      IMC::Packet::serialize(&msg, bfr);
      IMC::Message* msg_d = IMC::Packet::deserialize(bfr.getBuffer(), bfr.getSize());
      test.boolean("GpsFixRejection #1", msg == *msg_d);
      delete msg_d;
    }
    catch (IMC::InvalidMessageSize& e)
    {
      (void)e;
      test.boolean("msg #1", msg.getSerializationSize() > DUNE_IMC_CONST_MAX_SIZE);
    }
  }

  {
    IMC::GpsFixRejection msg;
    msg.setTimeStamp(0.5609908224322716);
    msg.setSource(974U);
    msg.setSourceEntity(91U);
    msg.setDestination(38320U);
    msg.setDestinationEntity(211U);
    msg.utc_time = 0.8967026766717737;
    msg.reason = 174U;

    try
    {
      Utils::ByteBuffer bfr;
      IMC::Packet::serialize(&msg, bfr);
      IMC::Message* msg_d = IMC::Packet::deserialize(bfr.getBuffer(), bfr.getSize());
      test.boolean("GpsFixRejection #2", msg == *msg_d);
      delete msg_d;
    }
    catch (IMC::InvalidMessageSize& e)
    {
      (void)e;
      test.boolean("msg #2", msg.getSerializationSize() > DUNE_IMC_CONST_MAX_SIZE);
    }
  }

  {
    IMC::LblRangeAcceptance msg;
    msg.setTimeStamp(0.23701420485016889);
    msg.setSource(24382U);
    msg.setSourceEntity(181U);
    msg.setDestination(30017U);
    msg.setDestinationEntity(73U);
    msg.id = 178U;
    msg.range = 0.80233157366543;
    msg.acceptance = 37U;

    try
    {
      Utils::ByteBuffer bfr;
      IMC::Packet::serialize(&msg, bfr);
      IMC::Message* msg_d = IMC::Packet::deserialize(bfr.getBuffer(), bfr.getSize());
      test.boolean("LblRangeAcceptance #0", msg == *msg_d);
      delete msg_d;
    }
    catch (IMC::InvalidMessageSize& e)
    {
      (void)e;
      test.boolean("msg #0", msg.getSerializationSize() > DUNE_IMC_CONST_MAX_SIZE);
    }
  }

  {
    IMC::LblRangeAcceptance msg;
    msg.setTimeStamp(0.7208409903501398);
    msg.setSource(30995U);
    msg.setSourceEntity(201U);
    msg.setDestination(5717U);
    msg.setDestinationEntity(51U);
    msg.id = 238U;
    msg.range = 0.3078681140120826;
    msg.acceptance = 20U;

    try
    {
      Utils::ByteBuffer bfr;
      IMC::Packet::serialize(&msg, bfr);
      IMC::Message* msg_d = IMC::Packet::deserialize(bfr.getBuffer(), bfr.getSize());
      test.boolean("LblRangeAcceptance #1", msg == *msg_d);
      delete msg_d;
    }
    catch (IMC::InvalidMessageSize& e)
    {
      (void)e;
      test.boolean("msg #1", msg.getSerializationSize() > DUNE_IMC_CONST_MAX_SIZE);
    }
  }

  {
    IMC::LblRangeAcceptance msg;
    msg.setTimeStamp(0.9081381980065255);
    msg.setSource(42768U);
    msg.setSourceEntity(148U);
    msg.setDestination(46684U);
    msg.setDestinationEntity(28U);
    msg.id = 39U;
    msg.range = 0.32668053208978276;
    msg.acceptance = 91U;

    try
    {
      Utils::ByteBuffer bfr;
      IMC::Packet::serialize(&msg, bfr);
      IMC::Message* msg_d = IMC::Packet::deserialize(bfr.getBuffer(), bfr.getSize());
      test.boolean("LblRangeAcceptance #2", msg == *msg_d);
      delete msg_d;
    }
    catch (IMC::InvalidMessageSize& e)
    {
      (void)e;
      test.boolean("msg #2", msg.getSerializationSize() > DUNE_IMC_CONST_MAX_SIZE);
    }
  }

  {
    IMC::DvlRejection msg;
    msg.setTimeStamp(0.4778142231976593);
    msg.setSource(45338U);
    msg.setSourceEntity(108U);
    msg.setDestination(12563U);
    msg.setDestinationEntity(233U);
    msg.type = 126U;
    msg.reason = 244U;
    msg.value = 0.986702292214265;
    msg.timestep = 0.8823206678945362;

    try
    {
      Utils::ByteBuffer bfr;
      IMC::Packet::serialize(&msg, bfr);
      IMC::Message* msg_d = IMC::Packet::deserialize(bfr.getBuffer(), bfr.getSize());
      test.boolean("DvlRejection #0", msg == *msg_d);
      delete msg_d;
    }
    catch (IMC::InvalidMessageSize& e)
    {
      (void)e;
      test.boolean("msg #0", msg.getSerializationSize() > DUNE_IMC_CONST_MAX_SIZE);
    }
  }

  {
    IMC::DvlRejection msg;
    msg.setTimeStamp(0.2933492995747202);
    msg.setSource(14102U);
    msg.setSourceEntity(99U);
    msg.setDestination(10562U);
    msg.setDestinationEntity(73U);
    msg.type = 72U;
    msg.reason = 185U;
    msg.value = 0.5257534466571491;
    msg.timestep = 0.9849963428900864;

    try
    {
      Utils::ByteBuffer bfr;
      IMC::Packet::serialize(&msg, bfr);
      IMC::Message* msg_d = IMC::Packet::deserialize(bfr.getBuffer(), bfr.getSize());
      test.boolean("DvlRejection #1", msg == *msg_d);
      delete msg_d;
    }
    catch (IMC::InvalidMessageSize& e)
    {
      (void)e;
      test.boolean("msg #1", msg.getSerializationSize() > DUNE_IMC_CONST_MAX_SIZE);
    }
  }

  {
    IMC::DvlRejection msg;
    msg.setTimeStamp(0.10932318926662943);
    msg.setSource(30722U);
    msg.setSourceEntity(45U);
    msg.setDestination(25311U);
    msg.setDestinationEntity(176U);
    msg.type = 103U;
    msg.reason = 124U;
    msg.value = 0.6575955761274669;
    msg.timestep = 0.8354013374578367;

    try
    {
      Utils::ByteBuffer bfr;
      IMC::Packet::serialize(&msg, bfr);
      IMC::Message* msg_d = IMC::Packet::deserialize(bfr.getBuffer(), bfr.getSize());
      test.boolean("DvlRejection #2", msg == *msg_d);
      delete msg_d;
    }
    catch (IMC::InvalidMessageSize& e)
    {
      (void)e;
      test.boolean("msg #2", msg.getSerializationSize() > DUNE_IMC_CONST_MAX_SIZE);
    }
  }

  {
    IMC::LblEstimate msg;
    msg.setTimeStamp(0.47793206010292366);
    msg.setSource(25043U);
    msg.setSourceEntity(150U);
    msg.setDestination(42129U);
    msg.setDestinationEntity(218U);
    IMC::LblBeacon tmp_msg_0;
    tmp_msg_0.beacon.assign("OMHPPFAWJFJYVKJWDZQFTANGVXSBZPSDOAPIMQXWGFMRUYBPIOIQCLWGAKUXHSKYXNTAIDVEUTODEWVFFNKBCKVMXGVNSEKVHCTUYHMQXNBJZRQNJPEJGOZBYYBGRPSLHLUQCKWUQXPMBOUIXBARNCQTSBLIYJQHRHEKHTWMZMFGLFOKAKVWMYZSDWLJILHFPTOZITEGVSLRCDTEGRJCPWNMIED");
    tmp_msg_0.lat = 0.1838492513490354;
    tmp_msg_0.lon = 0.9527718174730179;
    tmp_msg_0.depth = 0.9050070501585854;
    tmp_msg_0.query_channel = 244U;
    tmp_msg_0.reply_channel = 4U;
    tmp_msg_0.transponder_delay = 47U;
    msg.beacon.set(tmp_msg_0);
    msg.x = 0.14457703780541187;
    msg.y = 0.9195923436870248;
    msg.var_x = 0.7799961641738342;
    msg.var_y = 0.3526565766616794;
    msg.distance = 0.9967045076939206;

    try
    {
      Utils::ByteBuffer bfr;
      IMC::Packet::serialize(&msg, bfr);
      IMC::Message* msg_d = IMC::Packet::deserialize(bfr.getBuffer(), bfr.getSize());
      test.boolean("LblEstimate #0", msg == *msg_d);
      delete msg_d;
    }
    catch (IMC::InvalidMessageSize& e)
    {
      (void)e;
      test.boolean("msg #0", msg.getSerializationSize() > DUNE_IMC_CONST_MAX_SIZE);
    }
  }

  {
    IMC::LblEstimate msg;
    msg.setTimeStamp(0.8593758053447826);
    msg.setSource(49776U);
    msg.setSourceEntity(118U);
    msg.setDestination(38227U);
    msg.setDestinationEntity(218U);
    IMC::LblBeacon tmp_msg_0;
    tmp_msg_0.beacon.assign("CMRVZOPFWTSHCSUQWFLLEQWQGHPQONSOESZHRINMXJCKIGKPJBLOPOYZGUUAQMKADEBJBY");
    tmp_msg_0.lat = 0.3201819104002982;
    tmp_msg_0.lon = 0.9036904220355271;
    tmp_msg_0.depth = 0.5893003710221127;
    tmp_msg_0.query_channel = 95U;
    tmp_msg_0.reply_channel = 104U;
    tmp_msg_0.transponder_delay = 183U;
    msg.beacon.set(tmp_msg_0);
    msg.x = 0.5409691498521751;
    msg.y = 0.7221926324016025;
    msg.var_x = 0.6242508480038527;
    msg.var_y = 0.6827793460064426;
    msg.distance = 0.6495769041406182;

    try
    {
      Utils::ByteBuffer bfr;
      IMC::Packet::serialize(&msg, bfr);
      IMC::Message* msg_d = IMC::Packet::deserialize(bfr.getBuffer(), bfr.getSize());
      test.boolean("LblEstimate #1", msg == *msg_d);
      delete msg_d;
    }
    catch (IMC::InvalidMessageSize& e)
    {
      (void)e;
      test.boolean("msg #1", msg.getSerializationSize() > DUNE_IMC_CONST_MAX_SIZE);
    }
  }

  {
    IMC::LblEstimate msg;
    msg.setTimeStamp(0.5035918486667633);
    msg.setSource(22433U);
    msg.setSourceEntity(179U);
    msg.setDestination(16577U);
    msg.setDestinationEntity(65U);
    IMC::LblBeacon tmp_msg_0;
    tmp_msg_0.beacon.assign("ELXMCGUEMNKVGCLNUNHFTTTPDLIOBCVAOEQRJMYBMGUABVDMDPGAXHZFAZHLDKESAPSMONOYYSOEGZVRWMIGTBYPZPYY");
    tmp_msg_0.lat = 0.395622818244761;
    tmp_msg_0.lon = 0.20479059206364902;
    tmp_msg_0.depth = 0.9310707846077635;
    tmp_msg_0.query_channel = 118U;
    tmp_msg_0.reply_channel = 12U;
    tmp_msg_0.transponder_delay = 144U;
    msg.beacon.set(tmp_msg_0);
    msg.x = 0.4174422878267884;
    msg.y = 0.6307352836256612;
    msg.var_x = 0.4510233322517797;
    msg.var_y = 0.22921229697663514;
    msg.distance = 0.09270608146491166;

    try
    {
      Utils::ByteBuffer bfr;
      IMC::Packet::serialize(&msg, bfr);
      IMC::Message* msg_d = IMC::Packet::deserialize(bfr.getBuffer(), bfr.getSize());
      test.boolean("LblEstimate #2", msg == *msg_d);
      delete msg_d;
    }
    catch (IMC::InvalidMessageSize& e)
    {
      (void)e;
      test.boolean("msg #2", msg.getSerializationSize() > DUNE_IMC_CONST_MAX_SIZE);
    }
  }

  {
    IMC::AlignmentState msg;
    msg.setTimeStamp(0.7863445648871239);
    msg.setSource(64859U);
    msg.setSourceEntity(74U);
    msg.setDestination(7597U);
    msg.setDestinationEntity(139U);
    msg.state = 75U;

    try
    {
      Utils::ByteBuffer bfr;
      IMC::Packet::serialize(&msg, bfr);
      IMC::Message* msg_d = IMC::Packet::deserialize(bfr.getBuffer(), bfr.getSize());
      test.boolean("AlignmentState #0", msg == *msg_d);
      delete msg_d;
    }
    catch (IMC::InvalidMessageSize& e)
    {
      (void)e;
      test.boolean("msg #0", msg.getSerializationSize() > DUNE_IMC_CONST_MAX_SIZE);
    }
  }

  {
    IMC::AlignmentState msg;
    msg.setTimeStamp(0.8714927770194222);
    msg.setSource(12320U);
    msg.setSourceEntity(49U);
    msg.setDestination(58266U);
    msg.setDestinationEntity(56U);
    msg.state = 101U;

    try
    {
      Utils::ByteBuffer bfr;
      IMC::Packet::serialize(&msg, bfr);
      IMC::Message* msg_d = IMC::Packet::deserialize(bfr.getBuffer(), bfr.getSize());
      test.boolean("AlignmentState #1", msg == *msg_d);
      delete msg_d;
    }
    catch (IMC::InvalidMessageSize& e)
    {
      (void)e;
      test.boolean("msg #1", msg.getSerializationSize() > DUNE_IMC_CONST_MAX_SIZE);
    }
  }

  {
    IMC::AlignmentState msg;
    msg.setTimeStamp(0.9557952921511756);
    msg.setSource(65462U);
    msg.setSourceEntity(135U);
    msg.setDestination(4730U);
    msg.setDestinationEntity(158U);
    msg.state = 114U;

    try
    {
      Utils::ByteBuffer bfr;
      IMC::Packet::serialize(&msg, bfr);
      IMC::Message* msg_d = IMC::Packet::deserialize(bfr.getBuffer(), bfr.getSize());
      test.boolean("AlignmentState #2", msg == *msg_d);
      delete msg_d;
    }
    catch (IMC::InvalidMessageSize& e)
    {
      (void)e;
      test.boolean("msg #2", msg.getSerializationSize() > DUNE_IMC_CONST_MAX_SIZE);
    }
  }

  {
    IMC::GroupStreamVelocity msg;
    msg.setTimeStamp(0.32413046139724044);
    msg.setSource(61437U);
    msg.setSourceEntity(217U);
    msg.setDestination(29627U);
    msg.setDestinationEntity(154U);
    msg.x = 0.13664195473471386;
    msg.y = 0.9633388541147546;
    msg.z = 0.5604553665917282;

    try
    {
      Utils::ByteBuffer bfr;
      IMC::Packet::serialize(&msg, bfr);
      IMC::Message* msg_d = IMC::Packet::deserialize(bfr.getBuffer(), bfr.getSize());
      test.boolean("GroupStreamVelocity #0", msg == *msg_d);
      delete msg_d;
    }
    catch (IMC::InvalidMessageSize& e)
    {
      (void)e;
      test.boolean("msg #0", msg.getSerializationSize() > DUNE_IMC_CONST_MAX_SIZE);
    }
  }

  {
    IMC::GroupStreamVelocity msg;
    msg.setTimeStamp(0.029147560817404106);
    msg.setSource(56569U);
    msg.setSourceEntity(5U);
    msg.setDestination(31967U);
    msg.setDestinationEntity(242U);
    msg.x = 0.17382994610447533;
    msg.y = 0.985191048852654;
    msg.z = 0.6464873814793637;

    try
    {
      Utils::ByteBuffer bfr;
      IMC::Packet::serialize(&msg, bfr);
      IMC::Message* msg_d = IMC::Packet::deserialize(bfr.getBuffer(), bfr.getSize());
      test.boolean("GroupStreamVelocity #1", msg == *msg_d);
      delete msg_d;
    }
    catch (IMC::InvalidMessageSize& e)
    {
      (void)e;
      test.boolean("msg #1", msg.getSerializationSize() > DUNE_IMC_CONST_MAX_SIZE);
    }
  }

  {
    IMC::GroupStreamVelocity msg;
    msg.setTimeStamp(0.3131017355103507);
    msg.setSource(65049U);
    msg.setSourceEntity(207U);
    msg.setDestination(23695U);
    msg.setDestinationEntity(72U);
    msg.x = 0.4888237615821418;
    msg.y = 0.1745013157962816;
    msg.z = 0.9466565064704517;

    try
    {
      Utils::ByteBuffer bfr;
      IMC::Packet::serialize(&msg, bfr);
      IMC::Message* msg_d = IMC::Packet::deserialize(bfr.getBuffer(), bfr.getSize());
      test.boolean("GroupStreamVelocity #2", msg == *msg_d);
      delete msg_d;
    }
    catch (IMC::InvalidMessageSize& e)
    {
      (void)e;
      test.boolean("msg #2", msg.getSerializationSize() > DUNE_IMC_CONST_MAX_SIZE);
    }
  }

  {
    IMC::Airflow msg;
    msg.setTimeStamp(0.7276452946680289);
    msg.setSource(51611U);
    msg.setSourceEntity(94U);
    msg.setDestination(33974U);
    msg.setDestinationEntity(184U);
    msg.va = 0.28643904513028706;
    msg.aoa = 0.8619532958335557;
    msg.ssa = 0.5143251668442262;

    try
    {
      Utils::ByteBuffer bfr;
      IMC::Packet::serialize(&msg, bfr);
      IMC::Message* msg_d = IMC::Packet::deserialize(bfr.getBuffer(), bfr.getSize());
      test.boolean("Airflow #0", msg == *msg_d);
      delete msg_d;
    }
    catch (IMC::InvalidMessageSize& e)
    {
      (void)e;
      test.boolean("msg #0", msg.getSerializationSize() > DUNE_IMC_CONST_MAX_SIZE);
    }
  }

  {
    IMC::Airflow msg;
    msg.setTimeStamp(0.3591517494366021);
    msg.setSource(35579U);
    msg.setSourceEntity(160U);
    msg.setDestination(30650U);
    msg.setDestinationEntity(6U);
    msg.va = 0.5575426391388214;
    msg.aoa = 0.8420503752944966;
    msg.ssa = 0.7426920608606052;

    try
    {
      Utils::ByteBuffer bfr;
      IMC::Packet::serialize(&msg, bfr);
      IMC::Message* msg_d = IMC::Packet::deserialize(bfr.getBuffer(), bfr.getSize());
      test.boolean("Airflow #1", msg == *msg_d);
      delete msg_d;
    }
    catch (IMC::InvalidMessageSize& e)
    {
      (void)e;
      test.boolean("msg #1", msg.getSerializationSize() > DUNE_IMC_CONST_MAX_SIZE);
    }
  }

  {
    IMC::Airflow msg;
    msg.setTimeStamp(0.2906363138820157);
    msg.setSource(24769U);
    msg.setSourceEntity(153U);
    msg.setDestination(57690U);
    msg.setDestinationEntity(9U);
    msg.va = 0.2238692699562681;
    msg.aoa = 0.8444190551101536;
    msg.ssa = 0.09211686407491593;

    try
    {
      Utils::ByteBuffer bfr;
      IMC::Packet::serialize(&msg, bfr);
      IMC::Message* msg_d = IMC::Packet::deserialize(bfr.getBuffer(), bfr.getSize());
      test.boolean("Airflow #2", msg == *msg_d);
      delete msg_d;
    }
    catch (IMC::InvalidMessageSize& e)
    {
      (void)e;
      test.boolean("msg #2", msg.getSerializationSize() > DUNE_IMC_CONST_MAX_SIZE);
    }
  }

  {
    IMC::DesiredHeading msg;
    msg.setTimeStamp(0.04762059738550273);
    msg.setSource(12508U);
    msg.setSourceEntity(45U);
    msg.setDestination(39726U);
    msg.setDestinationEntity(126U);
    msg.value = 0.781722982774306;

    try
    {
      Utils::ByteBuffer bfr;
      IMC::Packet::serialize(&msg, bfr);
      IMC::Message* msg_d = IMC::Packet::deserialize(bfr.getBuffer(), bfr.getSize());
      test.boolean("DesiredHeading #0", msg == *msg_d);
      delete msg_d;
    }
    catch (IMC::InvalidMessageSize& e)
    {
      (void)e;
      test.boolean("msg #0", msg.getSerializationSize() > DUNE_IMC_CONST_MAX_SIZE);
    }
  }

  {
    IMC::DesiredHeading msg;
    msg.setTimeStamp(0.6232351445848343);
    msg.setSource(27859U);
    msg.setSourceEntity(126U);
    msg.setDestination(15594U);
    msg.setDestinationEntity(223U);
    msg.value = 0.8004796725512716;

    try
    {
      Utils::ByteBuffer bfr;
      IMC::Packet::serialize(&msg, bfr);
      IMC::Message* msg_d = IMC::Packet::deserialize(bfr.getBuffer(), bfr.getSize());
      test.boolean("DesiredHeading #1", msg == *msg_d);
      delete msg_d;
    }
    catch (IMC::InvalidMessageSize& e)
    {
      (void)e;
      test.boolean("msg #1", msg.getSerializationSize() > DUNE_IMC_CONST_MAX_SIZE);
    }
  }

  {
    IMC::DesiredHeading msg;
    msg.setTimeStamp(0.23947390458229922);
    msg.setSource(14840U);
    msg.setSourceEntity(94U);
    msg.setDestination(56155U);
    msg.setDestinationEntity(209U);
    msg.value = 0.8728299705432822;

    try
    {
      Utils::ByteBuffer bfr;
      IMC::Packet::serialize(&msg, bfr);
      IMC::Message* msg_d = IMC::Packet::deserialize(bfr.getBuffer(), bfr.getSize());
      test.boolean("DesiredHeading #2", msg == *msg_d);
      delete msg_d;
    }
    catch (IMC::InvalidMessageSize& e)
    {
      (void)e;
      test.boolean("msg #2", msg.getSerializationSize() > DUNE_IMC_CONST_MAX_SIZE);
    }
  }

  {
    IMC::DesiredZ msg;
    msg.setTimeStamp(0.7911220414609329);
    msg.setSource(50148U);
    msg.setSourceEntity(199U);
    msg.setDestination(28344U);
    msg.setDestinationEntity(202U);
    msg.value = 0.7305403360841126;
    msg.z_units = 150U;

    try
    {
      Utils::ByteBuffer bfr;
      IMC::Packet::serialize(&msg, bfr);
      IMC::Message* msg_d = IMC::Packet::deserialize(bfr.getBuffer(), bfr.getSize());
      test.boolean("DesiredZ #0", msg == *msg_d);
      delete msg_d;
    }
    catch (IMC::InvalidMessageSize& e)
    {
      (void)e;
      test.boolean("msg #0", msg.getSerializationSize() > DUNE_IMC_CONST_MAX_SIZE);
    }
  }

  {
    IMC::DesiredZ msg;
    msg.setTimeStamp(0.7768861484181293);
    msg.setSource(49560U);
    msg.setSourceEntity(235U);
    msg.setDestination(56449U);
    msg.setDestinationEntity(99U);
    msg.value = 0.3431012078197223;
    msg.z_units = 78U;

    try
    {
      Utils::ByteBuffer bfr;
      IMC::Packet::serialize(&msg, bfr);
      IMC::Message* msg_d = IMC::Packet::deserialize(bfr.getBuffer(), bfr.getSize());
      test.boolean("DesiredZ #1", msg == *msg_d);
      delete msg_d;
    }
    catch (IMC::InvalidMessageSize& e)
    {
      (void)e;
      test.boolean("msg #1", msg.getSerializationSize() > DUNE_IMC_CONST_MAX_SIZE);
    }
  }

  {
    IMC::DesiredZ msg;
    msg.setTimeStamp(0.17824467970757019);
    msg.setSource(3066U);
    msg.setSourceEntity(160U);
    msg.setDestination(47452U);
    msg.setDestinationEntity(233U);
    msg.value = 0.4625997694625379;
    msg.z_units = 10U;

    try
    {
      Utils::ByteBuffer bfr;
      IMC::Packet::serialize(&msg, bfr);
      IMC::Message* msg_d = IMC::Packet::deserialize(bfr.getBuffer(), bfr.getSize());
      test.boolean("DesiredZ #2", msg == *msg_d);
      delete msg_d;
    }
    catch (IMC::InvalidMessageSize& e)
    {
      (void)e;
      test.boolean("msg #2", msg.getSerializationSize() > DUNE_IMC_CONST_MAX_SIZE);
    }
  }

  {
    IMC::DesiredSpeed msg;
    msg.setTimeStamp(0.17960090458783595);
    msg.setSource(11610U);
    msg.setSourceEntity(120U);
    msg.setDestination(21106U);
    msg.setDestinationEntity(38U);
    msg.value = 0.3374586128168513;
    msg.speed_units = 168U;

    try
    {
      Utils::ByteBuffer bfr;
      IMC::Packet::serialize(&msg, bfr);
      IMC::Message* msg_d = IMC::Packet::deserialize(bfr.getBuffer(), bfr.getSize());
      test.boolean("DesiredSpeed #0", msg == *msg_d);
      delete msg_d;
    }
    catch (IMC::InvalidMessageSize& e)
    {
      (void)e;
      test.boolean("msg #0", msg.getSerializationSize() > DUNE_IMC_CONST_MAX_SIZE);
    }
  }

  {
    IMC::DesiredSpeed msg;
    msg.setTimeStamp(0.8266744599511171);
    msg.setSource(32935U);
    msg.setSourceEntity(152U);
    msg.setDestination(36939U);
    msg.setDestinationEntity(152U);
    msg.value = 0.756478122065297;
    msg.speed_units = 147U;

    try
    {
      Utils::ByteBuffer bfr;
      IMC::Packet::serialize(&msg, bfr);
      IMC::Message* msg_d = IMC::Packet::deserialize(bfr.getBuffer(), bfr.getSize());
      test.boolean("DesiredSpeed #1", msg == *msg_d);
      delete msg_d;
    }
    catch (IMC::InvalidMessageSize& e)
    {
      (void)e;
      test.boolean("msg #1", msg.getSerializationSize() > DUNE_IMC_CONST_MAX_SIZE);
    }
  }

  {
    IMC::DesiredSpeed msg;
    msg.setTimeStamp(0.23335471724122514);
    msg.setSource(62682U);
    msg.setSourceEntity(124U);
    msg.setDestination(23044U);
    msg.setDestinationEntity(123U);
    msg.value = 0.5628341730234355;
    msg.speed_units = 157U;

    try
    {
      Utils::ByteBuffer bfr;
      IMC::Packet::serialize(&msg, bfr);
      IMC::Message* msg_d = IMC::Packet::deserialize(bfr.getBuffer(), bfr.getSize());
      test.boolean("DesiredSpeed #2", msg == *msg_d);
      delete msg_d;
    }
    catch (IMC::InvalidMessageSize& e)
    {
      (void)e;
      test.boolean("msg #2", msg.getSerializationSize() > DUNE_IMC_CONST_MAX_SIZE);
    }
  }

  {
    IMC::DesiredRoll msg;
    msg.setTimeStamp(0.85872008753231);
    msg.setSource(2711U);
    msg.setSourceEntity(44U);
    msg.setDestination(3864U);
    msg.setDestinationEntity(239U);
    msg.value = 0.5934445913310404;

    try
    {
      Utils::ByteBuffer bfr;
      IMC::Packet::serialize(&msg, bfr);
      IMC::Message* msg_d = IMC::Packet::deserialize(bfr.getBuffer(), bfr.getSize());
      test.boolean("DesiredRoll #0", msg == *msg_d);
      delete msg_d;
    }
    catch (IMC::InvalidMessageSize& e)
    {
      (void)e;
      test.boolean("msg #0", msg.getSerializationSize() > DUNE_IMC_CONST_MAX_SIZE);
    }
  }

  {
    IMC::DesiredRoll msg;
    msg.setTimeStamp(0.20475669186334655);
    msg.setSource(46420U);
    msg.setSourceEntity(119U);
    msg.setDestination(57598U);
    msg.setDestinationEntity(68U);
    msg.value = 0.7751134637447232;

    try
    {
      Utils::ByteBuffer bfr;
      IMC::Packet::serialize(&msg, bfr);
      IMC::Message* msg_d = IMC::Packet::deserialize(bfr.getBuffer(), bfr.getSize());
      test.boolean("DesiredRoll #1", msg == *msg_d);
      delete msg_d;
    }
    catch (IMC::InvalidMessageSize& e)
    {
      (void)e;
      test.boolean("msg #1", msg.getSerializationSize() > DUNE_IMC_CONST_MAX_SIZE);
    }
  }

  {
    IMC::DesiredRoll msg;
    msg.setTimeStamp(0.923112627092277);
    msg.setSource(29106U);
    msg.setSourceEntity(35U);
    msg.setDestination(390U);
    msg.setDestinationEntity(43U);
    msg.value = 0.09200275861755669;

    try
    {
      Utils::ByteBuffer bfr;
      IMC::Packet::serialize(&msg, bfr);
      IMC::Message* msg_d = IMC::Packet::deserialize(bfr.getBuffer(), bfr.getSize());
      test.boolean("DesiredRoll #2", msg == *msg_d);
      delete msg_d;
    }
    catch (IMC::InvalidMessageSize& e)
    {
      (void)e;
      test.boolean("msg #2", msg.getSerializationSize() > DUNE_IMC_CONST_MAX_SIZE);
    }
  }

  {
    IMC::DesiredPitch msg;
    msg.setTimeStamp(0.8564015065743473);
    msg.setSource(12008U);
    msg.setSourceEntity(78U);
    msg.setDestination(11392U);
    msg.setDestinationEntity(226U);
    msg.value = 0.0009041299250317492;

    try
    {
      Utils::ByteBuffer bfr;
      IMC::Packet::serialize(&msg, bfr);
      IMC::Message* msg_d = IMC::Packet::deserialize(bfr.getBuffer(), bfr.getSize());
      test.boolean("DesiredPitch #0", msg == *msg_d);
      delete msg_d;
    }
    catch (IMC::InvalidMessageSize& e)
    {
      (void)e;
      test.boolean("msg #0", msg.getSerializationSize() > DUNE_IMC_CONST_MAX_SIZE);
    }
  }

  {
    IMC::DesiredPitch msg;
    msg.setTimeStamp(0.24528218803363033);
    msg.setSource(2427U);
    msg.setSourceEntity(205U);
    msg.setDestination(43375U);
    msg.setDestinationEntity(235U);
    msg.value = 0.6599216874928835;

    try
    {
      Utils::ByteBuffer bfr;
      IMC::Packet::serialize(&msg, bfr);
      IMC::Message* msg_d = IMC::Packet::deserialize(bfr.getBuffer(), bfr.getSize());
      test.boolean("DesiredPitch #1", msg == *msg_d);
      delete msg_d;
    }
    catch (IMC::InvalidMessageSize& e)
    {
      (void)e;
      test.boolean("msg #1", msg.getSerializationSize() > DUNE_IMC_CONST_MAX_SIZE);
    }
  }

  {
    IMC::DesiredPitch msg;
    msg.setTimeStamp(0.9834373244151564);
    msg.setSource(10574U);
    msg.setSourceEntity(125U);
    msg.setDestination(61250U);
    msg.setDestinationEntity(242U);
    msg.value = 0.3801327774470691;

    try
    {
      Utils::ByteBuffer bfr;
      IMC::Packet::serialize(&msg, bfr);
      IMC::Message* msg_d = IMC::Packet::deserialize(bfr.getBuffer(), bfr.getSize());
      test.boolean("DesiredPitch #2", msg == *msg_d);
      delete msg_d;
    }
    catch (IMC::InvalidMessageSize& e)
    {
      (void)e;
      test.boolean("msg #2", msg.getSerializationSize() > DUNE_IMC_CONST_MAX_SIZE);
    }
  }

  {
    IMC::DesiredVerticalRate msg;
    msg.setTimeStamp(0.033330652921733206);
    msg.setSource(54297U);
    msg.setSourceEntity(137U);
    msg.setDestination(15934U);
    msg.setDestinationEntity(66U);
    msg.value = 0.35087299288316054;

    try
    {
      Utils::ByteBuffer bfr;
      IMC::Packet::serialize(&msg, bfr);
      IMC::Message* msg_d = IMC::Packet::deserialize(bfr.getBuffer(), bfr.getSize());
      test.boolean("DesiredVerticalRate #0", msg == *msg_d);
      delete msg_d;
    }
    catch (IMC::InvalidMessageSize& e)
    {
      (void)e;
      test.boolean("msg #0", msg.getSerializationSize() > DUNE_IMC_CONST_MAX_SIZE);
    }
  }

  {
    IMC::DesiredVerticalRate msg;
    msg.setTimeStamp(0.2545499785002968);
    msg.setSource(47638U);
    msg.setSourceEntity(53U);
    msg.setDestination(6315U);
    msg.setDestinationEntity(95U);
    msg.value = 0.7398568355850849;

    try
    {
      Utils::ByteBuffer bfr;
      IMC::Packet::serialize(&msg, bfr);
      IMC::Message* msg_d = IMC::Packet::deserialize(bfr.getBuffer(), bfr.getSize());
      test.boolean("DesiredVerticalRate #1", msg == *msg_d);
      delete msg_d;
    }
    catch (IMC::InvalidMessageSize& e)
    {
      (void)e;
      test.boolean("msg #1", msg.getSerializationSize() > DUNE_IMC_CONST_MAX_SIZE);
    }
  }

  {
    IMC::DesiredVerticalRate msg;
    msg.setTimeStamp(0.5321883894035501);
    msg.setSource(5385U);
    msg.setSourceEntity(88U);
    msg.setDestination(3502U);
    msg.setDestinationEntity(120U);
    msg.value = 0.1942911785914181;

    try
    {
      Utils::ByteBuffer bfr;
      IMC::Packet::serialize(&msg, bfr);
      IMC::Message* msg_d = IMC::Packet::deserialize(bfr.getBuffer(), bfr.getSize());
      test.boolean("DesiredVerticalRate #2", msg == *msg_d);
      delete msg_d;
    }
    catch (IMC::InvalidMessageSize& e)
    {
      (void)e;
      test.boolean("msg #2", msg.getSerializationSize() > DUNE_IMC_CONST_MAX_SIZE);
    }
  }

  {
    IMC::DesiredPath msg;
    msg.setTimeStamp(0.0020580867995759755);
    msg.setSource(15051U);
    msg.setSourceEntity(164U);
    msg.setDestination(35188U);
    msg.setDestinationEntity(158U);
    msg.path_ref = 3496731341U;
    msg.start_lat = 0.6263159870819349;
    msg.start_lon = 0.146356381680242;
    msg.start_z = 0.0020278692287195588;
    msg.start_z_units = 251U;
    msg.end_lat = 0.9312043493138117;
    msg.end_lon = 0.8644224983741143;
    msg.end_z = 0.0292596728699549;
    msg.end_z_units = 13U;
    msg.speed = 0.3354794026386251;
    msg.speed_units = 235U;
    msg.lradius = 0.14605370912043292;
    msg.flags = 118U;

    try
    {
      Utils::ByteBuffer bfr;
      IMC::Packet::serialize(&msg, bfr);
      IMC::Message* msg_d = IMC::Packet::deserialize(bfr.getBuffer(), bfr.getSize());
      test.boolean("DesiredPath #0", msg == *msg_d);
      delete msg_d;
    }
    catch (IMC::InvalidMessageSize& e)
    {
      (void)e;
      test.boolean("msg #0", msg.getSerializationSize() > DUNE_IMC_CONST_MAX_SIZE);
    }
  }

  {
    IMC::DesiredPath msg;
    msg.setTimeStamp(0.09253032605914913);
    msg.setSource(34398U);
    msg.setSourceEntity(89U);
    msg.setDestination(50733U);
    msg.setDestinationEntity(211U);
    msg.path_ref = 1530078290U;
    msg.start_lat = 0.8013586165171612;
    msg.start_lon = 0.9372218510138817;
    msg.start_z = 0.48589722050313044;
    msg.start_z_units = 170U;
    msg.end_lat = 0.6222774829723685;
    msg.end_lon = 0.10809914308731716;
    msg.end_z = 0.44212799663863767;
    msg.end_z_units = 238U;
    msg.speed = 0.8359941655446333;
    msg.speed_units = 240U;
    msg.lradius = 0.03019430701408299;
    msg.flags = 87U;

    try
    {
      Utils::ByteBuffer bfr;
      IMC::Packet::serialize(&msg, bfr);
      IMC::Message* msg_d = IMC::Packet::deserialize(bfr.getBuffer(), bfr.getSize());
      test.boolean("DesiredPath #1", msg == *msg_d);
      delete msg_d;
    }
    catch (IMC::InvalidMessageSize& e)
    {
      (void)e;
      test.boolean("msg #1", msg.getSerializationSize() > DUNE_IMC_CONST_MAX_SIZE);
    }
  }

  {
    IMC::DesiredPath msg;
    msg.setTimeStamp(0.1852957759113365);
    msg.setSource(26729U);
    msg.setSourceEntity(207U);
    msg.setDestination(57962U);
    msg.setDestinationEntity(188U);
    msg.path_ref = 4287946037U;
    msg.start_lat = 0.7076827850788973;
    msg.start_lon = 0.8567715730314945;
    msg.start_z = 0.9605268947423098;
    msg.start_z_units = 64U;
    msg.end_lat = 0.19942944423197984;
    msg.end_lon = 0.6047349420610432;
    msg.end_z = 0.09574550775696755;
    msg.end_z_units = 167U;
    msg.speed = 0.9824197606013018;
    msg.speed_units = 90U;
    msg.lradius = 0.48284151241554163;
    msg.flags = 201U;

    try
    {
      Utils::ByteBuffer bfr;
      IMC::Packet::serialize(&msg, bfr);
      IMC::Message* msg_d = IMC::Packet::deserialize(bfr.getBuffer(), bfr.getSize());
      test.boolean("DesiredPath #2", msg == *msg_d);
      delete msg_d;
    }
    catch (IMC::InvalidMessageSize& e)
    {
      (void)e;
      test.boolean("msg #2", msg.getSerializationSize() > DUNE_IMC_CONST_MAX_SIZE);
    }
  }

  {
    IMC::DesiredControl msg;
    msg.setTimeStamp(0.7313325572987674);
    msg.setSource(11194U);
    msg.setSourceEntity(216U);
    msg.setDestination(58089U);
    msg.setDestinationEntity(157U);
    msg.x = 0.535897784665402;
    msg.y = 0.49888680966024657;
    msg.z = 0.27798654255015454;
    msg.k = 0.02369491835985138;
    msg.m = 0.2264826220429934;
    msg.n = 0.8459643386607283;
    msg.flags = 54U;

    try
    {
      Utils::ByteBuffer bfr;
      IMC::Packet::serialize(&msg, bfr);
      IMC::Message* msg_d = IMC::Packet::deserialize(bfr.getBuffer(), bfr.getSize());
      test.boolean("DesiredControl #0", msg == *msg_d);
      delete msg_d;
    }
    catch (IMC::InvalidMessageSize& e)
    {
      (void)e;
      test.boolean("msg #0", msg.getSerializationSize() > DUNE_IMC_CONST_MAX_SIZE);
    }
  }

  {
    IMC::DesiredControl msg;
    msg.setTimeStamp(0.9880152631673715);
    msg.setSource(23257U);
    msg.setSourceEntity(113U);
    msg.setDestination(22491U);
    msg.setDestinationEntity(13U);
    msg.x = 0.7355610835192123;
    msg.y = 0.7796269868888566;
    msg.z = 0.47825330088717954;
    msg.k = 0.7369435067894706;
    msg.m = 0.22453859855493452;
    msg.n = 0.545270061709044;
    msg.flags = 247U;

    try
    {
      Utils::ByteBuffer bfr;
      IMC::Packet::serialize(&msg, bfr);
      IMC::Message* msg_d = IMC::Packet::deserialize(bfr.getBuffer(), bfr.getSize());
      test.boolean("DesiredControl #1", msg == *msg_d);
      delete msg_d;
    }
    catch (IMC::InvalidMessageSize& e)
    {
      (void)e;
      test.boolean("msg #1", msg.getSerializationSize() > DUNE_IMC_CONST_MAX_SIZE);
    }
  }

  {
    IMC::DesiredControl msg;
    msg.setTimeStamp(0.7315790767391673);
    msg.setSource(29372U);
    msg.setSourceEntity(155U);
    msg.setDestination(38426U);
    msg.setDestinationEntity(178U);
    msg.x = 0.6432608678694308;
    msg.y = 0.9079112791090133;
    msg.z = 0.9267676212833514;
    msg.k = 0.9823093186203181;
    msg.m = 0.02928019007636018;
    msg.n = 0.3636001646286935;
    msg.flags = 94U;

    try
    {
      Utils::ByteBuffer bfr;
      IMC::Packet::serialize(&msg, bfr);
      IMC::Message* msg_d = IMC::Packet::deserialize(bfr.getBuffer(), bfr.getSize());
      test.boolean("DesiredControl #2", msg == *msg_d);
      delete msg_d;
    }
    catch (IMC::InvalidMessageSize& e)
    {
      (void)e;
      test.boolean("msg #2", msg.getSerializationSize() > DUNE_IMC_CONST_MAX_SIZE);
    }
  }

  {
    IMC::DesiredHeadingRate msg;
    msg.setTimeStamp(0.873873678992615);
    msg.setSource(11353U);
    msg.setSourceEntity(78U);
    msg.setDestination(43263U);
    msg.setDestinationEntity(236U);
    msg.value = 0.7773108550842796;

    try
    {
      Utils::ByteBuffer bfr;
      IMC::Packet::serialize(&msg, bfr);
      IMC::Message* msg_d = IMC::Packet::deserialize(bfr.getBuffer(), bfr.getSize());
      test.boolean("DesiredHeadingRate #0", msg == *msg_d);
      delete msg_d;
    }
    catch (IMC::InvalidMessageSize& e)
    {
      (void)e;
      test.boolean("msg #0", msg.getSerializationSize() > DUNE_IMC_CONST_MAX_SIZE);
    }
  }

  {
    IMC::DesiredHeadingRate msg;
    msg.setTimeStamp(0.9507761802341097);
    msg.setSource(23455U);
    msg.setSourceEntity(252U);
    msg.setDestination(34730U);
    msg.setDestinationEntity(29U);
    msg.value = 0.04774867105679703;

    try
    {
      Utils::ByteBuffer bfr;
      IMC::Packet::serialize(&msg, bfr);
      IMC::Message* msg_d = IMC::Packet::deserialize(bfr.getBuffer(), bfr.getSize());
      test.boolean("DesiredHeadingRate #1", msg == *msg_d);
      delete msg_d;
    }
    catch (IMC::InvalidMessageSize& e)
    {
      (void)e;
      test.boolean("msg #1", msg.getSerializationSize() > DUNE_IMC_CONST_MAX_SIZE);
    }
  }

  {
    IMC::DesiredHeadingRate msg;
    msg.setTimeStamp(0.5047312923140223);
    msg.setSource(32349U);
    msg.setSourceEntity(12U);
    msg.setDestination(39218U);
    msg.setDestinationEntity(6U);
    msg.value = 0.9323029279783667;

    try
    {
      Utils::ByteBuffer bfr;
      IMC::Packet::serialize(&msg, bfr);
      IMC::Message* msg_d = IMC::Packet::deserialize(bfr.getBuffer(), bfr.getSize());
      test.boolean("DesiredHeadingRate #2", msg == *msg_d);
      delete msg_d;
    }
    catch (IMC::InvalidMessageSize& e)
    {
      (void)e;
      test.boolean("msg #2", msg.getSerializationSize() > DUNE_IMC_CONST_MAX_SIZE);
    }
  }

  {
    IMC::DesiredVelocity msg;
    msg.setTimeStamp(0.5300130922132777);
    msg.setSource(65068U);
    msg.setSourceEntity(226U);
    msg.setDestination(64020U);
    msg.setDestinationEntity(107U);
    msg.u = 0.9894733059034844;
    msg.v = 0.5987988556537512;
    msg.w = 0.5663170946107059;
    msg.p = 0.20132498694524936;
    msg.q = 0.7210969906774153;
    msg.r = 0.3107101199517943;
    msg.flags = 224U;

    try
    {
      Utils::ByteBuffer bfr;
      IMC::Packet::serialize(&msg, bfr);
      IMC::Message* msg_d = IMC::Packet::deserialize(bfr.getBuffer(), bfr.getSize());
      test.boolean("DesiredVelocity #0", msg == *msg_d);
      delete msg_d;
    }
    catch (IMC::InvalidMessageSize& e)
    {
      (void)e;
      test.boolean("msg #0", msg.getSerializationSize() > DUNE_IMC_CONST_MAX_SIZE);
    }
  }

  {
    IMC::DesiredVelocity msg;
    msg.setTimeStamp(0.1586012646966216);
    msg.setSource(62086U);
    msg.setSourceEntity(240U);
    msg.setDestination(51549U);
    msg.setDestinationEntity(52U);
    msg.u = 0.7441637620188855;
    msg.v = 0.9969097916342496;
    msg.w = 0.491274629167335;
    msg.p = 0.8624924294187117;
    msg.q = 0.5638032981617112;
    msg.r = 0.20902801674327243;
    msg.flags = 93U;

    try
    {
      Utils::ByteBuffer bfr;
      IMC::Packet::serialize(&msg, bfr);
      IMC::Message* msg_d = IMC::Packet::deserialize(bfr.getBuffer(), bfr.getSize());
      test.boolean("DesiredVelocity #1", msg == *msg_d);
      delete msg_d;
    }
    catch (IMC::InvalidMessageSize& e)
    {
      (void)e;
      test.boolean("msg #1", msg.getSerializationSize() > DUNE_IMC_CONST_MAX_SIZE);
    }
  }

  {
    IMC::DesiredVelocity msg;
    msg.setTimeStamp(0.4982838064527849);
    msg.setSource(12564U);
    msg.setSourceEntity(231U);
    msg.setDestination(4374U);
    msg.setDestinationEntity(246U);
    msg.u = 0.9960554466452994;
    msg.v = 0.8269517393069871;
    msg.w = 0.051960323917373374;
    msg.p = 0.5342684202326977;
    msg.q = 0.9377994034885648;
    msg.r = 0.6113538473777618;
    msg.flags = 166U;

    try
    {
      Utils::ByteBuffer bfr;
      IMC::Packet::serialize(&msg, bfr);
      IMC::Message* msg_d = IMC::Packet::deserialize(bfr.getBuffer(), bfr.getSize());
      test.boolean("DesiredVelocity #2", msg == *msg_d);
      delete msg_d;
    }
    catch (IMC::InvalidMessageSize& e)
    {
      (void)e;
      test.boolean("msg #2", msg.getSerializationSize() > DUNE_IMC_CONST_MAX_SIZE);
    }
  }

  {
    IMC::PathControlState msg;
    msg.setTimeStamp(0.2549228436061386);
    msg.setSource(51323U);
    msg.setSourceEntity(174U);
    msg.setDestination(10083U);
    msg.setDestinationEntity(144U);
    msg.path_ref = 3375200516U;
    msg.start_lat = 0.99634167632419;
    msg.start_lon = 0.3469674896673959;
    msg.start_z = 0.156232045757849;
    msg.start_z_units = 226U;
    msg.end_lat = 0.0486830718705058;
    msg.end_lon = 0.3846724367199791;
    msg.end_z = 0.7094649204667453;
    msg.end_z_units = 52U;
    msg.lradius = 0.854642729670897;
    msg.flags = 207U;
    msg.x = 0.32785262574220175;
    msg.y = 0.8173692671970507;
    msg.z = 0.5278725749496718;
    msg.vx = 0.26859466861317927;
    msg.vy = 0.06671417735362095;
    msg.vz = 0.7276852579222517;
    msg.course_error = 0.9199657503093356;
    msg.eta = 64988U;

    try
    {
      Utils::ByteBuffer bfr;
      IMC::Packet::serialize(&msg, bfr);
      IMC::Message* msg_d = IMC::Packet::deserialize(bfr.getBuffer(), bfr.getSize());
      test.boolean("PathControlState #0", msg == *msg_d);
      delete msg_d;
    }
    catch (IMC::InvalidMessageSize& e)
    {
      (void)e;
      test.boolean("msg #0", msg.getSerializationSize() > DUNE_IMC_CONST_MAX_SIZE);
    }
  }

  {
    IMC::PathControlState msg;
    msg.setTimeStamp(0.9723072597489804);
    msg.setSource(64348U);
    msg.setSourceEntity(154U);
    msg.setDestination(22875U);
    msg.setDestinationEntity(228U);
    msg.path_ref = 96514116U;
    msg.start_lat = 0.8419650832153535;
    msg.start_lon = 0.0906193656725377;
    msg.start_z = 0.3455927961677474;
    msg.start_z_units = 253U;
    msg.end_lat = 0.001135053537395847;
    msg.end_lon = 0.3363565682093905;
    msg.end_z = 0.5951159950996915;
    msg.end_z_units = 206U;
    msg.lradius = 0.5099736333362369;
    msg.flags = 230U;
    msg.x = 0.05351842656292616;
    msg.y = 0.8749643605609901;
    msg.z = 0.9537960821488803;
    msg.vx = 0.49992900310599353;
    msg.vy = 0.6557694808402179;
    msg.vz = 0.8850293457214112;
    msg.course_error = 0.6279613307086392;
    msg.eta = 63596U;

    try
    {
      Utils::ByteBuffer bfr;
      IMC::Packet::serialize(&msg, bfr);
      IMC::Message* msg_d = IMC::Packet::deserialize(bfr.getBuffer(), bfr.getSize());
      test.boolean("PathControlState #1", msg == *msg_d);
      delete msg_d;
    }
    catch (IMC::InvalidMessageSize& e)
    {
      (void)e;
      test.boolean("msg #1", msg.getSerializationSize() > DUNE_IMC_CONST_MAX_SIZE);
    }
  }

  {
    IMC::PathControlState msg;
    msg.setTimeStamp(0.3305728051509714);
    msg.setSource(29767U);
    msg.setSourceEntity(202U);
    msg.setDestination(3718U);
    msg.setDestinationEntity(248U);
    msg.path_ref = 654000336U;
    msg.start_lat = 0.927476949380717;
    msg.start_lon = 0.7348903724351612;
    msg.start_z = 0.3077540350914638;
    msg.start_z_units = 180U;
    msg.end_lat = 0.6688467576096735;
    msg.end_lon = 0.2805391646767087;
    msg.end_z = 0.5087784496063328;
    msg.end_z_units = 151U;
    msg.lradius = 0.972035550511397;
    msg.flags = 194U;
    msg.x = 0.999994233552534;
    msg.y = 0.8800125621699;
    msg.z = 0.4485344947136406;
    msg.vx = 0.4707138108292912;
    msg.vy = 0.1418144232677112;
    msg.vz = 0.32213136911950346;
    msg.course_error = 0.1520007303881713;
    msg.eta = 43792U;

    try
    {
      Utils::ByteBuffer bfr;
      IMC::Packet::serialize(&msg, bfr);
      IMC::Message* msg_d = IMC::Packet::deserialize(bfr.getBuffer(), bfr.getSize());
      test.boolean("PathControlState #2", msg == *msg_d);
      delete msg_d;
    }
    catch (IMC::InvalidMessageSize& e)
    {
      (void)e;
      test.boolean("msg #2", msg.getSerializationSize() > DUNE_IMC_CONST_MAX_SIZE);
    }
  }

  {
    IMC::AllocatedControlTorques msg;
    msg.setTimeStamp(0.7539311002711593);
    msg.setSource(64004U);
    msg.setSourceEntity(71U);
    msg.setDestination(13232U);
    msg.setDestinationEntity(198U);
    msg.k = 0.06032026145079228;
    msg.m = 0.4184297232278511;
    msg.n = 0.6495595156442444;

    try
    {
      Utils::ByteBuffer bfr;
      IMC::Packet::serialize(&msg, bfr);
      IMC::Message* msg_d = IMC::Packet::deserialize(bfr.getBuffer(), bfr.getSize());
      test.boolean("AllocatedControlTorques #0", msg == *msg_d);
      delete msg_d;
    }
    catch (IMC::InvalidMessageSize& e)
    {
      (void)e;
      test.boolean("msg #0", msg.getSerializationSize() > DUNE_IMC_CONST_MAX_SIZE);
    }
  }

  {
    IMC::AllocatedControlTorques msg;
    msg.setTimeStamp(0.27529085430686473);
    msg.setSource(8497U);
    msg.setSourceEntity(122U);
    msg.setDestination(34072U);
    msg.setDestinationEntity(59U);
    msg.k = 0.9143231129905889;
    msg.m = 0.0416362397402642;
    msg.n = 0.030451165501335087;

    try
    {
      Utils::ByteBuffer bfr;
      IMC::Packet::serialize(&msg, bfr);
      IMC::Message* msg_d = IMC::Packet::deserialize(bfr.getBuffer(), bfr.getSize());
      test.boolean("AllocatedControlTorques #1", msg == *msg_d);
      delete msg_d;
    }
    catch (IMC::InvalidMessageSize& e)
    {
      (void)e;
      test.boolean("msg #1", msg.getSerializationSize() > DUNE_IMC_CONST_MAX_SIZE);
    }
  }

  {
    IMC::AllocatedControlTorques msg;
    msg.setTimeStamp(0.6159647971834139);
    msg.setSource(840U);
    msg.setSourceEntity(91U);
    msg.setDestination(17U);
    msg.setDestinationEntity(77U);
    msg.k = 0.06873586963644518;
    msg.m = 0.7582310619178325;
    msg.n = 0.8748634464185597;

    try
    {
      Utils::ByteBuffer bfr;
      IMC::Packet::serialize(&msg, bfr);
      IMC::Message* msg_d = IMC::Packet::deserialize(bfr.getBuffer(), bfr.getSize());
      test.boolean("AllocatedControlTorques #2", msg == *msg_d);
      delete msg_d;
    }
    catch (IMC::InvalidMessageSize& e)
    {
      (void)e;
      test.boolean("msg #2", msg.getSerializationSize() > DUNE_IMC_CONST_MAX_SIZE);
    }
  }

  {
    IMC::ControlParcel msg;
    msg.setTimeStamp(0.7945260715295355);
    msg.setSource(15258U);
    msg.setSourceEntity(35U);
    msg.setDestination(21149U);
    msg.setDestinationEntity(143U);
    msg.p = 0.30857498039635456;
    msg.i = 0.5323347488087948;
    msg.d = 0.9113296729541175;
    msg.a = 0.5625577042566721;

    try
    {
      Utils::ByteBuffer bfr;
      IMC::Packet::serialize(&msg, bfr);
      IMC::Message* msg_d = IMC::Packet::deserialize(bfr.getBuffer(), bfr.getSize());
      test.boolean("ControlParcel #0", msg == *msg_d);
      delete msg_d;
    }
    catch (IMC::InvalidMessageSize& e)
    {
      (void)e;
      test.boolean("msg #0", msg.getSerializationSize() > DUNE_IMC_CONST_MAX_SIZE);
    }
  }

  {
    IMC::ControlParcel msg;
    msg.setTimeStamp(0.766549086423343);
    msg.setSource(50769U);
    msg.setSourceEntity(183U);
    msg.setDestination(43824U);
    msg.setDestinationEntity(185U);
    msg.p = 0.0013770895052288568;
    msg.i = 0.6179369361069418;
    msg.d = 0.8315692070925614;
    msg.a = 0.7634808680719474;

    try
    {
      Utils::ByteBuffer bfr;
      IMC::Packet::serialize(&msg, bfr);
      IMC::Message* msg_d = IMC::Packet::deserialize(bfr.getBuffer(), bfr.getSize());
      test.boolean("ControlParcel #1", msg == *msg_d);
      delete msg_d;
    }
    catch (IMC::InvalidMessageSize& e)
    {
      (void)e;
      test.boolean("msg #1", msg.getSerializationSize() > DUNE_IMC_CONST_MAX_SIZE);
    }
  }

  {
    IMC::ControlParcel msg;
    msg.setTimeStamp(0.015636348835199487);
    msg.setSource(49098U);
    msg.setSourceEntity(208U);
    msg.setDestination(22542U);
    msg.setDestinationEntity(180U);
    msg.p = 0.8655471943805679;
    msg.i = 0.5330357760290264;
    msg.d = 0.002484614041844635;
    msg.a = 0.5495862375039503;

    try
    {
      Utils::ByteBuffer bfr;
      IMC::Packet::serialize(&msg, bfr);
      IMC::Message* msg_d = IMC::Packet::deserialize(bfr.getBuffer(), bfr.getSize());
      test.boolean("ControlParcel #2", msg == *msg_d);
      delete msg_d;
    }
    catch (IMC::InvalidMessageSize& e)
    {
      (void)e;
      test.boolean("msg #2", msg.getSerializationSize() > DUNE_IMC_CONST_MAX_SIZE);
    }
  }

  {
    IMC::Brake msg;
    msg.setTimeStamp(0.18497640596164222);
    msg.setSource(24350U);
    msg.setSourceEntity(111U);
    msg.setDestination(57634U);
    msg.setDestinationEntity(189U);
    msg.op = 73U;

    try
    {
      Utils::ByteBuffer bfr;
      IMC::Packet::serialize(&msg, bfr);
      IMC::Message* msg_d = IMC::Packet::deserialize(bfr.getBuffer(), bfr.getSize());
      test.boolean("Brake #0", msg == *msg_d);
      delete msg_d;
    }
    catch (IMC::InvalidMessageSize& e)
    {
      (void)e;
      test.boolean("msg #0", msg.getSerializationSize() > DUNE_IMC_CONST_MAX_SIZE);
    }
  }

  {
    IMC::Brake msg;
    msg.setTimeStamp(0.5911914491735868);
    msg.setSource(27938U);
    msg.setSourceEntity(211U);
    msg.setDestination(62161U);
    msg.setDestinationEntity(132U);
    msg.op = 59U;

    try
    {
      Utils::ByteBuffer bfr;
      IMC::Packet::serialize(&msg, bfr);
      IMC::Message* msg_d = IMC::Packet::deserialize(bfr.getBuffer(), bfr.getSize());
      test.boolean("Brake #1", msg == *msg_d);
      delete msg_d;
    }
    catch (IMC::InvalidMessageSize& e)
    {
      (void)e;
      test.boolean("msg #1", msg.getSerializationSize() > DUNE_IMC_CONST_MAX_SIZE);
    }
  }

  {
    IMC::Brake msg;
    msg.setTimeStamp(0.7868092430273843);
    msg.setSource(45750U);
    msg.setSourceEntity(254U);
    msg.setDestination(36202U);
    msg.setDestinationEntity(208U);
    msg.op = 156U;

    try
    {
      Utils::ByteBuffer bfr;
      IMC::Packet::serialize(&msg, bfr);
      IMC::Message* msg_d = IMC::Packet::deserialize(bfr.getBuffer(), bfr.getSize());
      test.boolean("Brake #2", msg == *msg_d);
      delete msg_d;
    }
    catch (IMC::InvalidMessageSize& e)
    {
      (void)e;
      test.boolean("msg #2", msg.getSerializationSize() > DUNE_IMC_CONST_MAX_SIZE);
    }
  }

  {
    IMC::DesiredLinearState msg;
    msg.setTimeStamp(0.9919337266897693);
    msg.setSource(53940U);
    msg.setSourceEntity(234U);
    msg.setDestination(26964U);
    msg.setDestinationEntity(169U);
    msg.x = 0.6540411993664501;
    msg.y = 0.44512476534757106;
    msg.z = 0.8720791858154634;
    msg.vx = 0.3861499675403489;
    msg.vy = 0.7848166773356028;
    msg.vz = 0.6720573685980036;
    msg.ax = 0.5030418593026349;
    msg.ay = 0.7169720482705888;
    msg.az = 0.15196463453371356;
    msg.flags = 3329U;

    try
    {
      Utils::ByteBuffer bfr;
      IMC::Packet::serialize(&msg, bfr);
      IMC::Message* msg_d = IMC::Packet::deserialize(bfr.getBuffer(), bfr.getSize());
      test.boolean("DesiredLinearState #0", msg == *msg_d);
      delete msg_d;
    }
    catch (IMC::InvalidMessageSize& e)
    {
      (void)e;
      test.boolean("msg #0", msg.getSerializationSize() > DUNE_IMC_CONST_MAX_SIZE);
    }
  }

  {
    IMC::DesiredLinearState msg;
    msg.setTimeStamp(0.878753068326456);
    msg.setSource(54210U);
    msg.setSourceEntity(81U);
    msg.setDestination(34346U);
    msg.setDestinationEntity(246U);
    msg.x = 0.7036397788175337;
    msg.y = 0.25892984117301776;
    msg.z = 0.17599862837005786;
    msg.vx = 0.26283955122752123;
    msg.vy = 0.011895751769323115;
    msg.vz = 0.06176240894977647;
    msg.ax = 0.5222319388016786;
    msg.ay = 0.036052530693398754;
    msg.az = 0.23797234160126624;
    msg.flags = 63747U;

    try
    {
      Utils::ByteBuffer bfr;
      IMC::Packet::serialize(&msg, bfr);
      IMC::Message* msg_d = IMC::Packet::deserialize(bfr.getBuffer(), bfr.getSize());
      test.boolean("DesiredLinearState #1", msg == *msg_d);
      delete msg_d;
    }
    catch (IMC::InvalidMessageSize& e)
    {
      (void)e;
      test.boolean("msg #1", msg.getSerializationSize() > DUNE_IMC_CONST_MAX_SIZE);
    }
  }

  {
    IMC::DesiredLinearState msg;
    msg.setTimeStamp(0.7855293417281896);
    msg.setSource(9312U);
    msg.setSourceEntity(22U);
    msg.setDestination(58851U);
    msg.setDestinationEntity(189U);
    msg.x = 0.26599110251571023;
    msg.y = 0.3745155479096517;
    msg.z = 0.8723534233918976;
    msg.vx = 0.14441435941973335;
    msg.vy = 0.731211679732175;
    msg.vz = 0.6312029542431362;
    msg.ax = 0.7246965469502711;
    msg.ay = 0.3028064620568689;
    msg.az = 0.029999106139215526;
    msg.flags = 11890U;

    try
    {
      Utils::ByteBuffer bfr;
      IMC::Packet::serialize(&msg, bfr);
      IMC::Message* msg_d = IMC::Packet::deserialize(bfr.getBuffer(), bfr.getSize());
      test.boolean("DesiredLinearState #2", msg == *msg_d);
      delete msg_d;
    }
    catch (IMC::InvalidMessageSize& e)
    {
      (void)e;
      test.boolean("msg #2", msg.getSerializationSize() > DUNE_IMC_CONST_MAX_SIZE);
    }
  }

  {
    IMC::DesiredThrottle msg;
    msg.setTimeStamp(0.29585788429108895);
    msg.setSource(45543U);
    msg.setSourceEntity(111U);
    msg.setDestination(30479U);
    msg.setDestinationEntity(202U);
    msg.value = 0.5491062526504418;

    try
    {
      Utils::ByteBuffer bfr;
      IMC::Packet::serialize(&msg, bfr);
      IMC::Message* msg_d = IMC::Packet::deserialize(bfr.getBuffer(), bfr.getSize());
      test.boolean("DesiredThrottle #0", msg == *msg_d);
      delete msg_d;
    }
    catch (IMC::InvalidMessageSize& e)
    {
      (void)e;
      test.boolean("msg #0", msg.getSerializationSize() > DUNE_IMC_CONST_MAX_SIZE);
    }
  }

  {
    IMC::DesiredThrottle msg;
    msg.setTimeStamp(0.7947705007609033);
    msg.setSource(61824U);
    msg.setSourceEntity(84U);
    msg.setDestination(38141U);
    msg.setDestinationEntity(91U);
    msg.value = 0.5567532458638405;

    try
    {
      Utils::ByteBuffer bfr;
      IMC::Packet::serialize(&msg, bfr);
      IMC::Message* msg_d = IMC::Packet::deserialize(bfr.getBuffer(), bfr.getSize());
      test.boolean("DesiredThrottle #1", msg == *msg_d);
      delete msg_d;
    }
    catch (IMC::InvalidMessageSize& e)
    {
      (void)e;
      test.boolean("msg #1", msg.getSerializationSize() > DUNE_IMC_CONST_MAX_SIZE);
    }
  }

  {
    IMC::DesiredThrottle msg;
    msg.setTimeStamp(0.0018922677403210297);
    msg.setSource(62710U);
    msg.setSourceEntity(197U);
    msg.setDestination(9751U);
    msg.setDestinationEntity(196U);
    msg.value = 0.32783952251658655;

    try
    {
      Utils::ByteBuffer bfr;
      IMC::Packet::serialize(&msg, bfr);
      IMC::Message* msg_d = IMC::Packet::deserialize(bfr.getBuffer(), bfr.getSize());
      test.boolean("DesiredThrottle #2", msg == *msg_d);
      delete msg_d;
    }
    catch (IMC::InvalidMessageSize& e)
    {
      (void)e;
      test.boolean("msg #2", msg.getSerializationSize() > DUNE_IMC_CONST_MAX_SIZE);
    }
  }

  {
    IMC::Goto msg;
    msg.setTimeStamp(0.5334365900819322);
    msg.setSource(10184U);
    msg.setSourceEntity(22U);
    msg.setDestination(36714U);
    msg.setDestinationEntity(42U);
    msg.timeout = 44258U;
    msg.lat = 0.0014615320128522624;
    msg.lon = 0.9365837747396286;
    msg.z = 0.9166762490812584;
    msg.z_units = 22U;
    msg.speed = 0.9170135977940835;
    msg.speed_units = 247U;
    msg.roll = 0.9099024479956115;
    msg.pitch = 0.9194807629467379;
    msg.yaw = 0.7242270939965919;
    msg.custom.assign("LWLBJXGQUSZGRJLEBRMBZPFWXIEQBQPRTHWHOELXBILYQSTOGRMTZTGZAJWBSOKCFHSSDGXCQVRWPTPYANYAZXHPWLBGROATDSHCZUMUGVNCNCNFVPSYTEXMZCCSCDONVMMHUYHCBKV");

    try
    {
      Utils::ByteBuffer bfr;
      IMC::Packet::serialize(&msg, bfr);
      IMC::Message* msg_d = IMC::Packet::deserialize(bfr.getBuffer(), bfr.getSize());
      test.boolean("Goto #0", msg == *msg_d);
      delete msg_d;
    }
    catch (IMC::InvalidMessageSize& e)
    {
      (void)e;
      test.boolean("msg #0", msg.getSerializationSize() > DUNE_IMC_CONST_MAX_SIZE);
    }
  }

  {
    IMC::Goto msg;
    msg.setTimeStamp(0.33562015990219074);
    msg.setSource(23539U);
    msg.setSourceEntity(55U);
    msg.setDestination(54008U);
    msg.setDestinationEntity(43U);
    msg.timeout = 14641U;
    msg.lat = 0.04955485011662453;
    msg.lon = 0.0745834331466052;
    msg.z = 0.6441918340602288;
    msg.z_units = 245U;
    msg.speed = 0.35529847681084403;
    msg.speed_units = 136U;
    msg.roll = 0.713570533531633;
    msg.pitch = 0.2604524039304913;
    msg.yaw = 0.7591517970963858;
    msg.custom.assign("DYQGOCMIZQYHDUAGKXKNFCR");

    try
    {
      Utils::ByteBuffer bfr;
      IMC::Packet::serialize(&msg, bfr);
      IMC::Message* msg_d = IMC::Packet::deserialize(bfr.getBuffer(), bfr.getSize());
      test.boolean("Goto #1", msg == *msg_d);
      delete msg_d;
    }
    catch (IMC::InvalidMessageSize& e)
    {
      (void)e;
      test.boolean("msg #1", msg.getSerializationSize() > DUNE_IMC_CONST_MAX_SIZE);
    }
  }

  {
    IMC::Goto msg;
    msg.setTimeStamp(0.9193258629909637);
    msg.setSource(13273U);
    msg.setSourceEntity(96U);
    msg.setDestination(22180U);
    msg.setDestinationEntity(33U);
    msg.timeout = 51764U;
    msg.lat = 0.6844471898933102;
    msg.lon = 0.6667222379616251;
    msg.z = 0.7875291801588872;
    msg.z_units = 104U;
    msg.speed = 0.6055540277227325;
    msg.speed_units = 122U;
    msg.roll = 0.47207848885000514;
    msg.pitch = 0.7712270652396515;
    msg.yaw = 0.02335160579339257;
    msg.custom.assign("JFWGMOQAFXUHMSZILMZSJVQSYFKQRFRRLOMWEDXCRANUZDUSNNZLLLLRYFBBOOYHHFSUCVDPEXNRTHAQCTKXTGMZYWIYKOHQGWGNCHUTUCCLPVHLIBMGYUB");

    try
    {
      Utils::ByteBuffer bfr;
      IMC::Packet::serialize(&msg, bfr);
      IMC::Message* msg_d = IMC::Packet::deserialize(bfr.getBuffer(), bfr.getSize());
      test.boolean("Goto #2", msg == *msg_d);
      delete msg_d;
    }
    catch (IMC::InvalidMessageSize& e)
    {
      (void)e;
      test.boolean("msg #2", msg.getSerializationSize() > DUNE_IMC_CONST_MAX_SIZE);
    }
  }

  {
    IMC::PopUp msg;
    msg.setTimeStamp(0.6508407763425508);
    msg.setSource(63503U);
    msg.setSourceEntity(101U);
    msg.setDestination(22194U);
    msg.setDestinationEntity(235U);
    msg.timeout = 2920U;
    msg.lat = 0.03654944481504563;
    msg.lon = 0.19164578816681788;
    msg.z = 0.7664594125474121;
    msg.z_units = 90U;
    msg.speed = 0.3588031747869176;
    msg.speed_units = 104U;
    msg.duration = 34537U;
    msg.radius = 0.790934765119347;
    msg.flags = 233U;
    msg.custom.assign("LVPUYNPVOTWYBFMSRQBRTDRFHRKGZGIXADJQXUKDSHHPITQRQAWXUGOFFEEEBUQNBIEMXOATZUEQZTSENPINKXWWMTDJTWYPJPDGLRPPSNXMXGVPJWDYNFZCRTYGAWQFORBDOFFRUFJJTZVOKKHUIZICCYSZNREDKUX");

    try
    {
      Utils::ByteBuffer bfr;
      IMC::Packet::serialize(&msg, bfr);
      IMC::Message* msg_d = IMC::Packet::deserialize(bfr.getBuffer(), bfr.getSize());
      test.boolean("PopUp #0", msg == *msg_d);
      delete msg_d;
    }
    catch (IMC::InvalidMessageSize& e)
    {
      (void)e;
      test.boolean("msg #0", msg.getSerializationSize() > DUNE_IMC_CONST_MAX_SIZE);
    }
  }

  {
    IMC::PopUp msg;
    msg.setTimeStamp(0.01921122367596184);
    msg.setSource(25205U);
    msg.setSourceEntity(144U);
    msg.setDestination(65268U);
    msg.setDestinationEntity(191U);
    msg.timeout = 65396U;
    msg.lat = 0.9611540489086678;
    msg.lon = 0.0520059633978891;
    msg.z = 0.49581160257203927;
    msg.z_units = 117U;
    msg.speed = 0.3151749070786778;
    msg.speed_units = 241U;
    msg.duration = 64786U;
    msg.radius = 0.7524698033155528;
    msg.flags = 42U;
    msg.custom.assign("CUMTTJXIKJR");

    try
    {
      Utils::ByteBuffer bfr;
      IMC::Packet::serialize(&msg, bfr);
      IMC::Message* msg_d = IMC::Packet::deserialize(bfr.getBuffer(), bfr.getSize());
      test.boolean("PopUp #1", msg == *msg_d);
      delete msg_d;
    }
    catch (IMC::InvalidMessageSize& e)
    {
      (void)e;
      test.boolean("msg #1", msg.getSerializationSize() > DUNE_IMC_CONST_MAX_SIZE);
    }
  }

  {
    IMC::PopUp msg;
    msg.setTimeStamp(0.5012046408026541);
    msg.setSource(645U);
    msg.setSourceEntity(3U);
    msg.setDestination(24266U);
    msg.setDestinationEntity(172U);
    msg.timeout = 61279U;
    msg.lat = 0.7569199592922763;
    msg.lon = 0.21197584983912277;
    msg.z = 0.12663612111109268;
    msg.z_units = 231U;
    msg.speed = 0.4431803044036492;
    msg.speed_units = 26U;
    msg.duration = 10278U;
    msg.radius = 0.9648582646760352;
    msg.flags = 147U;
    msg.custom.assign("FRUYWADEGDGWEUDRZKQVTXIZPRDLIDNZJVJHZUHDPMCQHCAJXHTZJXROOWUSGWLRJUJWVNJTEISQNJOSLGIAJQNYHBHOXPBAMAPMYKGDLUZCVXZNWEBWYEYGASKOCKHIQDTFXHBNBOOYPKKVAMBLRGIFYFIFLLVCAZFTCUFZSXQVVGSUBNMTMTBYK");

    try
    {
      Utils::ByteBuffer bfr;
      IMC::Packet::serialize(&msg, bfr);
      IMC::Message* msg_d = IMC::Packet::deserialize(bfr.getBuffer(), bfr.getSize());
      test.boolean("PopUp #2", msg == *msg_d);
      delete msg_d;
    }
    catch (IMC::InvalidMessageSize& e)
    {
      (void)e;
      test.boolean("msg #2", msg.getSerializationSize() > DUNE_IMC_CONST_MAX_SIZE);
    }
  }

  {
    IMC::Teleoperation msg;
    msg.setTimeStamp(0.4936261886336758);
    msg.setSource(8571U);
    msg.setSourceEntity(36U);
    msg.setDestination(63117U);
    msg.setDestinationEntity(32U);
    msg.custom.assign("BJKXGSVBEQXECMVIDTYTKIKQUHRLNAOJWXHOIZNXBRYBKSMLYYUKUEDDHUFLGLOTXGQBMDPSPWXNPGUFDWJCYSHIWCVSPLJPCRPZAJEKUAKROTHELMBONQRAAYKHKLGAWTCVSROYDZPOR");

    try
    {
      Utils::ByteBuffer bfr;
      IMC::Packet::serialize(&msg, bfr);
      IMC::Message* msg_d = IMC::Packet::deserialize(bfr.getBuffer(), bfr.getSize());
      test.boolean("Teleoperation #0", msg == *msg_d);
      delete msg_d;
    }
    catch (IMC::InvalidMessageSize& e)
    {
      (void)e;
      test.boolean("msg #0", msg.getSerializationSize() > DUNE_IMC_CONST_MAX_SIZE);
    }
  }

  {
    IMC::Teleoperation msg;
    msg.setTimeStamp(0.6848387069821578);
    msg.setSource(35416U);
    msg.setSourceEntity(230U);
    msg.setDestination(61363U);
    msg.setDestinationEntity(207U);
    msg.custom.assign("OQUIAMOCNATCDJFLLGQMYOYLGCUCZUOJPGHMRMFWCAHKIHHXCOGVJZXUPRIACQXDYGDNKEFZBBVYBIEJRGVIZKPLERSTJIVZNUMDOJDJHVAWLDDBZOMTNLCVFRGWBYAFEOUSNVHKFTPPQTPIUUULWQNPPKMWBFJEASCXOOBRBZTWNJBJYLSKQEVYEGFNWTCYWXZGPWXDNSRSR");

    try
    {
      Utils::ByteBuffer bfr;
      IMC::Packet::serialize(&msg, bfr);
      IMC::Message* msg_d = IMC::Packet::deserialize(bfr.getBuffer(), bfr.getSize());
      test.boolean("Teleoperation #1", msg == *msg_d);
      delete msg_d;
    }
    catch (IMC::InvalidMessageSize& e)
    {
      (void)e;
      test.boolean("msg #1", msg.getSerializationSize() > DUNE_IMC_CONST_MAX_SIZE);
    }
  }

  {
    IMC::Teleoperation msg;
    msg.setTimeStamp(0.5359625150811728);
    msg.setSource(480U);
    msg.setSourceEntity(20U);
    msg.setDestination(41029U);
    msg.setDestinationEntity(134U);
    msg.custom.assign("EMMZNFUGYLJMLCHIWIRDEYPAFUAKVTVGILQUQXBVCEGVRBGLDBXDIZPNZACEUEUHMBGJKTQRHYCIFTFRDSDOWYWGOOSRFKXTHWJPPYTQUYYPQRMUANITCUXULFZPANDORQOFSFCEOVXYSLZAWKXXWXQIBHTODHAJRHSIETMVFPOVLCHMVTAZJJSGSPQLENSHJGDPCQNGVVMKSCDBPZRCKFTNESJBYQOOKZNIJN");

    try
    {
      Utils::ByteBuffer bfr;
      IMC::Packet::serialize(&msg, bfr);
      IMC::Message* msg_d = IMC::Packet::deserialize(bfr.getBuffer(), bfr.getSize());
      test.boolean("Teleoperation #2", msg == *msg_d);
      delete msg_d;
    }
    catch (IMC::InvalidMessageSize& e)
    {
      (void)e;
      test.boolean("msg #2", msg.getSerializationSize() > DUNE_IMC_CONST_MAX_SIZE);
    }
  }

  {
    IMC::Loiter msg;
    msg.setTimeStamp(0.71911075508123);
    msg.setSource(31361U);
    msg.setSourceEntity(248U);
    msg.setDestination(5134U);
    msg.setDestinationEntity(77U);
    msg.timeout = 47631U;
    msg.lat = 0.4942442467259104;
    msg.lon = 0.4285547143994223;
    msg.z = 0.479254146638187;
    msg.z_units = 173U;
    msg.duration = 21695U;
    msg.speed = 0.04692320154175844;
    msg.speed_units = 117U;
    msg.type = 132U;
    msg.radius = 0.85445844811389;
    msg.length = 0.6124363802148416;
    msg.bearing = 0.10131453610273977;
    msg.direction = 98U;
    msg.custom.assign("ZDRXFRCEKPOUMSMQNSJBGZFDXPTOJXVZDHUFMZCQWVTWXSEELRJKDWGXZIDPHBRVLPEODJIYNWFJUNBCUHTOGYACUAMNLIMCJNWBLCNVDQLNOBEXUITGUROKDABJZYUFPBALQVTYQOFJRYXTCELKRCOKIHLTPEYZSSPLIFWGVWTXEDAKBZAYSUXKMGYQNBNMIZOPAGFJQFRTVBSAVRQIKYSSUQJIDHQPAIMH");

    try
    {
      Utils::ByteBuffer bfr;
      IMC::Packet::serialize(&msg, bfr);
      IMC::Message* msg_d = IMC::Packet::deserialize(bfr.getBuffer(), bfr.getSize());
      test.boolean("Loiter #0", msg == *msg_d);
      delete msg_d;
    }
    catch (IMC::InvalidMessageSize& e)
    {
      (void)e;
      test.boolean("msg #0", msg.getSerializationSize() > DUNE_IMC_CONST_MAX_SIZE);
    }
  }

  {
    IMC::Loiter msg;
    msg.setTimeStamp(0.6929106846385851);
    msg.setSource(14812U);
    msg.setSourceEntity(85U);
    msg.setDestination(25641U);
    msg.setDestinationEntity(46U);
    msg.timeout = 56927U;
    msg.lat = 0.2380903696454797;
    msg.lon = 0.371486371416594;
    msg.z = 0.13111518892823903;
    msg.z_units = 53U;
    msg.duration = 40318U;
    msg.speed = 0.9811681475563487;
    msg.speed_units = 136U;
    msg.type = 250U;
    msg.radius = 0.34984839053048433;
    msg.length = 0.317882355803201;
    msg.bearing = 0.3653125855180912;
    msg.direction = 174U;
    msg.custom.assign("PVQECYRFIQIVSENPRNDJSEUPQFZIOKFGDCQETSPIZRSGVXYARYMOHCOSGXDKTLLUJUHVKOQHNNNQFGRXTLHZOLVZKAAWLYGUIMFWAHKPIXQLKNCXCIPKAZZTCCDWGBVGLKMCNRWNYXBSYJOLHSRJVLZLUQEMJUABDIRXFZFOJCZBYTYEXSHBPDTSFJFNBVXUHRASTDBECQTBHMZOTDDPPQXATWONPJBUMKYIYJVAMMGOEBUGUKREMHWWW");

    try
    {
      Utils::ByteBuffer bfr;
      IMC::Packet::serialize(&msg, bfr);
      IMC::Message* msg_d = IMC::Packet::deserialize(bfr.getBuffer(), bfr.getSize());
      test.boolean("Loiter #1", msg == *msg_d);
      delete msg_d;
    }
    catch (IMC::InvalidMessageSize& e)
    {
      (void)e;
      test.boolean("msg #1", msg.getSerializationSize() > DUNE_IMC_CONST_MAX_SIZE);
    }
  }

  {
    IMC::Loiter msg;
    msg.setTimeStamp(0.8740074063749946);
    msg.setSource(16937U);
    msg.setSourceEntity(87U);
    msg.setDestination(3449U);
    msg.setDestinationEntity(42U);
    msg.timeout = 60362U;
    msg.lat = 0.9671389704415176;
    msg.lon = 0.6804229950270828;
    msg.z = 0.07361396675840381;
    msg.z_units = 190U;
    msg.duration = 41284U;
    msg.speed = 0.9095438762476528;
    msg.speed_units = 172U;
    msg.type = 143U;
    msg.radius = 0.7379806939483923;
    msg.length = 0.12247170723430512;
    msg.bearing = 0.10574363824734578;
    msg.direction = 162U;
    msg.custom.assign("BETDUGAQHSGDCYHCIUOXHXCLQDYTMCNVDQSKJTLUIBGZMAXWQLOFOTPCBOLWHRIZIXHYDKNGGOIPTSRUBSRZPDNMBZVYUEWSFZDFDHPMGRUNOWYVJFKAQWFIPGXPKLGCLFHYKVQJID");

    try
    {
      Utils::ByteBuffer bfr;
      IMC::Packet::serialize(&msg, bfr);
      IMC::Message* msg_d = IMC::Packet::deserialize(bfr.getBuffer(), bfr.getSize());
      test.boolean("Loiter #2", msg == *msg_d);
      delete msg_d;
    }
    catch (IMC::InvalidMessageSize& e)
    {
      (void)e;
      test.boolean("msg #2", msg.getSerializationSize() > DUNE_IMC_CONST_MAX_SIZE);
    }
  }

  {
    IMC::IdleManeuver msg;
    msg.setTimeStamp(0.2087118687648779);
    msg.setSource(42962U);
    msg.setSourceEntity(132U);
    msg.setDestination(13560U);
    msg.setDestinationEntity(239U);
    msg.duration = 46226U;
    msg.custom.assign("QGYVEAESCCZZLKTJLKKWVMWFPDFQJDCLFSEQNWXBJBXSJZOLMRIIURVJEZXLJSOYYDLYZTTIUPMGAWHPTZJPRKMBLOERAKICLYYMPEBNRBVHMHHCGGININHYUCXWCTBZPMISFSRJUURSMZKYOQNCDSFBOPWJOVYYFX");

    try
    {
      Utils::ByteBuffer bfr;
      IMC::Packet::serialize(&msg, bfr);
      IMC::Message* msg_d = IMC::Packet::deserialize(bfr.getBuffer(), bfr.getSize());
      test.boolean("IdleManeuver #0", msg == *msg_d);
      delete msg_d;
    }
    catch (IMC::InvalidMessageSize& e)
    {
      (void)e;
      test.boolean("msg #0", msg.getSerializationSize() > DUNE_IMC_CONST_MAX_SIZE);
    }
  }

  {
    IMC::IdleManeuver msg;
    msg.setTimeStamp(0.04090425732765657);
    msg.setSource(2299U);
    msg.setSourceEntity(7U);
    msg.setDestination(28790U);
    msg.setDestinationEntity(4U);
    msg.duration = 15010U;
    msg.custom.assign("CWBXGRYJZWCAUEPAQYELRLFCQXPSRSEKDALBHIQB");

    try
    {
      Utils::ByteBuffer bfr;
      IMC::Packet::serialize(&msg, bfr);
      IMC::Message* msg_d = IMC::Packet::deserialize(bfr.getBuffer(), bfr.getSize());
      test.boolean("IdleManeuver #1", msg == *msg_d);
      delete msg_d;
    }
    catch (IMC::InvalidMessageSize& e)
    {
      (void)e;
      test.boolean("msg #1", msg.getSerializationSize() > DUNE_IMC_CONST_MAX_SIZE);
    }
  }

  {
    IMC::IdleManeuver msg;
    msg.setTimeStamp(0.004096927681239926);
    msg.setSource(44862U);
    msg.setSourceEntity(155U);
    msg.setDestination(60150U);
    msg.setDestinationEntity(12U);
    msg.duration = 21609U;
    msg.custom.assign("BZXAZHQXRZDDVDLVJLTMTQBSMWOENJVMAEXEKCZLXOOUPWGRLFCLZHQCPPDXHKSRDIHMJQFWSPGVGSFPMJHEMNPRUKOGNVHERKZAUKPMINYCRTSYWZRFHLPYOGLIAVFQNQ");

    try
    {
      Utils::ByteBuffer bfr;
      IMC::Packet::serialize(&msg, bfr);
      IMC::Message* msg_d = IMC::Packet::deserialize(bfr.getBuffer(), bfr.getSize());
      test.boolean("IdleManeuver #2", msg == *msg_d);
      delete msg_d;
    }
    catch (IMC::InvalidMessageSize& e)
    {
      (void)e;
      test.boolean("msg #2", msg.getSerializationSize() > DUNE_IMC_CONST_MAX_SIZE);
    }
  }

  {
    IMC::LowLevelControl msg;
    msg.setTimeStamp(0.9360627941709753);
    msg.setSource(11703U);
    msg.setSourceEntity(32U);
    msg.setDestination(47552U);
    msg.setDestinationEntity(148U);
    IMC::DesiredHeading tmp_msg_0;
    tmp_msg_0.value = 0.4843393550320624;
    msg.control.set(tmp_msg_0);
    msg.duration = 52750U;
    msg.custom.assign("EMGWUVJEQSMFMGCEPILDBJWKKDPSVOYREGNOLOWXTCSFOHRQJZIZXAKELRZMMHLZHKMEFYXMIWMLMZEAQIGPSAUOVFQVQISPZYTWEXNUOIKWCCHRIJGJBCUGPWYBVFFCZQYQD");

    try
    {
      Utils::ByteBuffer bfr;
      IMC::Packet::serialize(&msg, bfr);
      IMC::Message* msg_d = IMC::Packet::deserialize(bfr.getBuffer(), bfr.getSize());
      test.boolean("LowLevelControl #0", msg == *msg_d);
      delete msg_d;
    }
    catch (IMC::InvalidMessageSize& e)
    {
      (void)e;
      test.boolean("msg #0", msg.getSerializationSize() > DUNE_IMC_CONST_MAX_SIZE);
    }
  }

  {
    IMC::LowLevelControl msg;
    msg.setTimeStamp(0.653093469300969);
    msg.setSource(37610U);
    msg.setSourceEntity(132U);
    msg.setDestination(30292U);
    msg.setDestinationEntity(25U);
    IMC::DesiredHeading tmp_msg_0;
    tmp_msg_0.value = 0.8747328395272901;
    msg.control.set(tmp_msg_0);
    msg.duration = 48447U;
    msg.custom.assign("LWMCNYXCWWSNFZRTVMUFQJLICSTPLBHNESBLRZPPAIDVELEZJNOVSCFYGVVOMBUYIBJWKKDADUDWMGOTKXYRTVVOUQPSJKZXCECYXFICTUQIAHNIEUDSPFIJVYTDNAULZEMSGQKGBXAPRTQRBECJPRSVXBQMMGMKUOIQOVWWRAZJEBRKOMHWSDPTLXPWECXTUHADTZGGYELZKDPGFIHRHJBJFCAGWYZFFAQHUJFQNOOH");

    try
    {
      Utils::ByteBuffer bfr;
      IMC::Packet::serialize(&msg, bfr);
      IMC::Message* msg_d = IMC::Packet::deserialize(bfr.getBuffer(), bfr.getSize());
      test.boolean("LowLevelControl #1", msg == *msg_d);
      delete msg_d;
    }
    catch (IMC::InvalidMessageSize& e)
    {
      (void)e;
      test.boolean("msg #1", msg.getSerializationSize() > DUNE_IMC_CONST_MAX_SIZE);
    }
  }

  {
    IMC::LowLevelControl msg;
    msg.setTimeStamp(0.9008022081868273);
    msg.setSource(52771U);
    msg.setSourceEntity(227U);
    msg.setDestination(7736U);
    msg.setDestinationEntity(41U);
    IMC::DesiredSpeed tmp_msg_0;
    tmp_msg_0.value = 0.9860463942377329;
    tmp_msg_0.speed_units = 111U;
    msg.control.set(tmp_msg_0);
    msg.duration = 47178U;
    msg.custom.assign("PYDQGNTBZTSZYCLVBKFOMDDZSGPSDTDLJIYKBFWWBRPENGXVLMMCWVPSTGTRVOXGBYHRWHDAYTBVSVCKZXONOIOFIFFMIOCUYQNCGKRCJUKZCQIMLJFNCGGLFWAXNINAVPCEYSNEWUIEMLYRKABAUIXRJEFI");

    try
    {
      Utils::ByteBuffer bfr;
      IMC::Packet::serialize(&msg, bfr);
      IMC::Message* msg_d = IMC::Packet::deserialize(bfr.getBuffer(), bfr.getSize());
      test.boolean("LowLevelControl #2", msg == *msg_d);
      delete msg_d;
    }
    catch (IMC::InvalidMessageSize& e)
    {
      (void)e;
      test.boolean("msg #2", msg.getSerializationSize() > DUNE_IMC_CONST_MAX_SIZE);
    }
  }

  {
    IMC::Rows msg;
    msg.setTimeStamp(0.4539632129600515);
    msg.setSource(45734U);
    msg.setSourceEntity(207U);
    msg.setDestination(44638U);
    msg.setDestinationEntity(114U);
    msg.timeout = 63447U;
    msg.lat = 0.01165781219554396;
    msg.lon = 0.3478477360112683;
    msg.z = 0.27332708540848405;
    msg.z_units = 178U;
    msg.speed = 0.1313331801024844;
    msg.speed_units = 33U;
    msg.bearing = 0.2269256886272112;
    msg.cross_angle = 0.1992313082670365;
    msg.width = 0.5855534213226906;
    msg.length = 0.6922715275479583;
    msg.hstep = 0.9608932718421621;
    msg.coff = 159U;
    msg.alternation = 165U;
    msg.flags = 218U;
    msg.custom.assign("ITTRYLXFWFNEMQGRHYRWACXWBUCCXDWNHFYDSJMLDZYEPLKLBQGNXKNUDUSHUQZLXTGNSFBJVXTDOKYOEARGYFTKHIZIWZATJNJJHZHSBKMGSEOGIPEDCUSBEVXODKPXZILIOGEPVSNTSHWAOQNPQKCMPBQRLRVVEANOMLQCZVIOUPAZWYVWIREFSWOPCBBDFGV");

    try
    {
      Utils::ByteBuffer bfr;
      IMC::Packet::serialize(&msg, bfr);
      IMC::Message* msg_d = IMC::Packet::deserialize(bfr.getBuffer(), bfr.getSize());
      test.boolean("Rows #0", msg == *msg_d);
      delete msg_d;
    }
    catch (IMC::InvalidMessageSize& e)
    {
      (void)e;
      test.boolean("msg #0", msg.getSerializationSize() > DUNE_IMC_CONST_MAX_SIZE);
    }
  }

  {
    IMC::Rows msg;
    msg.setTimeStamp(0.6580716179537842);
    msg.setSource(35276U);
    msg.setSourceEntity(11U);
    msg.setDestination(62875U);
    msg.setDestinationEntity(252U);
    msg.timeout = 46122U;
    msg.lat = 0.5429774260496069;
    msg.lon = 0.0036438804073567477;
    msg.z = 0.28305436942395;
    msg.z_units = 85U;
    msg.speed = 0.7099812862113747;
    msg.speed_units = 145U;
    msg.bearing = 0.35717790160158247;
    msg.cross_angle = 0.20158283761373808;
    msg.width = 0.5819538603642739;
    msg.length = 0.3757831147320855;
    msg.hstep = 0.5397724509155473;
    msg.coff = 185U;
    msg.alternation = 244U;
    msg.flags = 254U;
    msg.custom.assign("UWPBJBQZXNNHRFIEIGNURSYKQYQNFIOZOCLPBMLDFVXNSOCCWWIQDYMGCCMKSXWKUQVKTZZHATETPDTDAYFOCGKGHHIDKWOBEJMVJKRINAWPGYBNSQGZKJVIORGTEYCGBJPRLQTSYHNJLXSL");

    try
    {
      Utils::ByteBuffer bfr;
      IMC::Packet::serialize(&msg, bfr);
      IMC::Message* msg_d = IMC::Packet::deserialize(bfr.getBuffer(), bfr.getSize());
      test.boolean("Rows #1", msg == *msg_d);
      delete msg_d;
    }
    catch (IMC::InvalidMessageSize& e)
    {
      (void)e;
      test.boolean("msg #1", msg.getSerializationSize() > DUNE_IMC_CONST_MAX_SIZE);
    }
  }

  {
    IMC::Rows msg;
    msg.setTimeStamp(0.6806391138357757);
    msg.setSource(11812U);
    msg.setSourceEntity(209U);
    msg.setDestination(46249U);
    msg.setDestinationEntity(16U);
    msg.timeout = 10508U;
    msg.lat = 0.22190736843155656;
    msg.lon = 0.4901579362003151;
    msg.z = 0.15502195249500994;
    msg.z_units = 130U;
    msg.speed = 0.5614797124281702;
    msg.speed_units = 80U;
    msg.bearing = 0.10963728041329912;
    msg.cross_angle = 0.46781876613899;
    msg.width = 0.9488235494286622;
    msg.length = 0.276343145541983;
    msg.hstep = 0.6432387619714878;
    msg.coff = 75U;
    msg.alternation = 182U;
    msg.flags = 170U;
    msg.custom.assign("IKWRRDALUVUSZNSNFXMCIWTUMTDWB");

    try
    {
      Utils::ByteBuffer bfr;
      IMC::Packet::serialize(&msg, bfr);
      IMC::Message* msg_d = IMC::Packet::deserialize(bfr.getBuffer(), bfr.getSize());
      test.boolean("Rows #2", msg == *msg_d);
      delete msg_d;
    }
    catch (IMC::InvalidMessageSize& e)
    {
      (void)e;
      test.boolean("msg #2", msg.getSerializationSize() > DUNE_IMC_CONST_MAX_SIZE);
    }
  }

  {
    IMC::FollowPath msg;
    msg.setTimeStamp(0.5336692849332979);
    msg.setSource(36455U);
    msg.setSourceEntity(22U);
    msg.setDestination(64189U);
    msg.setDestinationEntity(115U);
    msg.timeout = 14307U;
    msg.lat = 0.9239829701262937;
    msg.lon = 0.24365928699295647;
    msg.z = 0.891108186554037;
    msg.z_units = 226U;
    msg.speed = 0.44563617963858737;
    msg.speed_units = 204U;
    IMC::PathPoint tmp_msg_0;
    tmp_msg_0.x = 0.47207652295945624;
    tmp_msg_0.y = 0.8745802585020844;
    tmp_msg_0.z = 0.8770677741794217;
    msg.points.push_back(tmp_msg_0);
    msg.custom.assign("XBMCYUSASQZTOPMHNQXUEWWYUOFPXIEDJWPXUKNMVDVFGMMAGSAZFLLKVVNBTCMSRHAVFWEAISUCSEQKAQWZQHHKSXVKRGBIGGFLGXIULTYLQUZGWIYAPYZCGCDQJNNHOTETXXYOWYXCJJKLRZUCTNKUQDEKHOEZEMHVQEJPTRVMJOETFBJROJLJTZWFPNCBUFNRKQNOLL");

    try
    {
      Utils::ByteBuffer bfr;
      IMC::Packet::serialize(&msg, bfr);
      IMC::Message* msg_d = IMC::Packet::deserialize(bfr.getBuffer(), bfr.getSize());
      test.boolean("FollowPath #0", msg == *msg_d);
      delete msg_d;
    }
    catch (IMC::InvalidMessageSize& e)
    {
      (void)e;
      test.boolean("msg #0", msg.getSerializationSize() > DUNE_IMC_CONST_MAX_SIZE);
    }
  }

  {
    IMC::FollowPath msg;
    msg.setTimeStamp(0.44727542275566423);
    msg.setSource(2512U);
    msg.setSourceEntity(225U);
    msg.setDestination(784U);
    msg.setDestinationEntity(154U);
    msg.timeout = 27822U;
    msg.lat = 0.7488949068900299;
    msg.lon = 0.2745759200846345;
    msg.z = 0.8326746793477228;
    msg.z_units = 96U;
    msg.speed = 0.9077659914779868;
    msg.speed_units = 113U;
    msg.custom.assign("JJQGYZRWGPZLBIFNDRNZPDVPZODNLYBWRTLWINLSCSMYXIECMRWXCKWUYHHKMWJAUKOVEFEQCUZ");

    try
    {
      Utils::ByteBuffer bfr;
      IMC::Packet::serialize(&msg, bfr);
      IMC::Message* msg_d = IMC::Packet::deserialize(bfr.getBuffer(), bfr.getSize());
      test.boolean("FollowPath #1", msg == *msg_d);
      delete msg_d;
    }
    catch (IMC::InvalidMessageSize& e)
    {
      (void)e;
      test.boolean("msg #1", msg.getSerializationSize() > DUNE_IMC_CONST_MAX_SIZE);
    }
  }

  {
    IMC::FollowPath msg;
    msg.setTimeStamp(0.37816940254551656);
    msg.setSource(1689U);
    msg.setSourceEntity(194U);
    msg.setDestination(20028U);
    msg.setDestinationEntity(6U);
    msg.timeout = 10457U;
    msg.lat = 0.5674547373217527;
    msg.lon = 0.9529089571809636;
    msg.z = 0.23704006569779335;
    msg.z_units = 226U;
    msg.speed = 0.6781125527986237;
    msg.speed_units = 89U;
    msg.custom.assign("SYQHWUMCDYDDAOXZCJDTOCWKNICFXXCBAYWOPLHR");

    try
    {
      Utils::ByteBuffer bfr;
      IMC::Packet::serialize(&msg, bfr);
      IMC::Message* msg_d = IMC::Packet::deserialize(bfr.getBuffer(), bfr.getSize());
      test.boolean("FollowPath #2", msg == *msg_d);
      delete msg_d;
    }
    catch (IMC::InvalidMessageSize& e)
    {
      (void)e;
      test.boolean("msg #2", msg.getSerializationSize() > DUNE_IMC_CONST_MAX_SIZE);
    }
  }

  {
    IMC::PathPoint msg;
    msg.setTimeStamp(0.9868912305913469);
    msg.setSource(23077U);
    msg.setSourceEntity(65U);
    msg.setDestination(17418U);
    msg.setDestinationEntity(81U);
    msg.x = 0.3304389826330193;
    msg.y = 0.7303282191431782;
    msg.z = 0.5080783456883685;

    try
    {
      Utils::ByteBuffer bfr;
      IMC::Packet::serialize(&msg, bfr);
      IMC::Message* msg_d = IMC::Packet::deserialize(bfr.getBuffer(), bfr.getSize());
      test.boolean("PathPoint #0", msg == *msg_d);
      delete msg_d;
    }
    catch (IMC::InvalidMessageSize& e)
    {
      (void)e;
      test.boolean("msg #0", msg.getSerializationSize() > DUNE_IMC_CONST_MAX_SIZE);
    }
  }

  {
    IMC::PathPoint msg;
    msg.setTimeStamp(0.39372362020255625);
    msg.setSource(52627U);
    msg.setSourceEntity(36U);
    msg.setDestination(42137U);
    msg.setDestinationEntity(91U);
    msg.x = 0.24306688362010997;
    msg.y = 0.6755779793244335;
    msg.z = 0.34120581879232725;

    try
    {
      Utils::ByteBuffer bfr;
      IMC::Packet::serialize(&msg, bfr);
      IMC::Message* msg_d = IMC::Packet::deserialize(bfr.getBuffer(), bfr.getSize());
      test.boolean("PathPoint #1", msg == *msg_d);
      delete msg_d;
    }
    catch (IMC::InvalidMessageSize& e)
    {
      (void)e;
      test.boolean("msg #1", msg.getSerializationSize() > DUNE_IMC_CONST_MAX_SIZE);
    }
  }

  {
    IMC::PathPoint msg;
    msg.setTimeStamp(0.6918082580198869);
    msg.setSource(58582U);
    msg.setSourceEntity(51U);
    msg.setDestination(36541U);
    msg.setDestinationEntity(221U);
    msg.x = 0.26822189903858495;
    msg.y = 0.012374958440143913;
    msg.z = 0.7213654993251135;

    try
    {
      Utils::ByteBuffer bfr;
      IMC::Packet::serialize(&msg, bfr);
      IMC::Message* msg_d = IMC::Packet::deserialize(bfr.getBuffer(), bfr.getSize());
      test.boolean("PathPoint #2", msg == *msg_d);
      delete msg_d;
    }
    catch (IMC::InvalidMessageSize& e)
    {
      (void)e;
      test.boolean("msg #2", msg.getSerializationSize() > DUNE_IMC_CONST_MAX_SIZE);
    }
  }

  {
    IMC::YoYo msg;
    msg.setTimeStamp(0.09065275932201589);
    msg.setSource(31509U);
    msg.setSourceEntity(160U);
    msg.setDestination(44156U);
    msg.setDestinationEntity(58U);
    msg.timeout = 37907U;
    msg.lat = 0.005154708250124984;
    msg.lon = 0.7260347951816618;
    msg.z = 0.019348420969670488;
    msg.z_units = 176U;
    msg.amplitude = 0.4484019438557194;
    msg.pitch = 0.6913369941620072;
    msg.speed = 0.22228709221982723;
    msg.speed_units = 109U;
    msg.custom.assign("AHACJNBPPJFZARWTNJKBBMYMEQLAXEYBQQNMXBFIPGIEFQLHTARALOHHSCDOVUUWGUXXROWVAIEBMNMTOVPQKICJITCXKGOJCTOPXJKUHJRAYQMDYRBYUCSKFRMZRHBEFLWLSXVGCDGVNLTZHWDRVJYXDNTESGZPIXKDHWKLUTFVZCTONXSDGBLWUCWEZNCJZSVHNSTPQLOIDZHVJRIOGYOSKZ");

    try
    {
      Utils::ByteBuffer bfr;
      IMC::Packet::serialize(&msg, bfr);
      IMC::Message* msg_d = IMC::Packet::deserialize(bfr.getBuffer(), bfr.getSize());
      test.boolean("YoYo #0", msg == *msg_d);
      delete msg_d;
    }
    catch (IMC::InvalidMessageSize& e)
    {
      (void)e;
      test.boolean("msg #0", msg.getSerializationSize() > DUNE_IMC_CONST_MAX_SIZE);
    }
  }

  {
    IMC::YoYo msg;
    msg.setTimeStamp(0.8613334963916001);
    msg.setSource(25993U);
    msg.setSourceEntity(9U);
    msg.setDestination(23687U);
    msg.setDestinationEntity(5U);
    msg.timeout = 13088U;
    msg.lat = 0.28439383906758586;
    msg.lon = 0.3394054057019159;
    msg.z = 0.8622582627611629;
    msg.z_units = 123U;
    msg.amplitude = 0.21762583403166869;
    msg.pitch = 0.9709500431578757;
    msg.speed = 0.30780632437943445;
    msg.speed_units = 165U;
    msg.custom.assign("GUAIUQBYWMJXPAACRNLXICEFHGKPGFNTIQBPTKKLJKIZSTDYYYWZQXLCIKGDEBXVMQYLNZZHIGFHVGXSRMDJRBCWAKNSTYTWOJCQSLPCNWJUOWETPAKWPNGSXEPYOILMWQONQXCYSRPNSLAPFHNBBZDPMH");

    try
    {
      Utils::ByteBuffer bfr;
      IMC::Packet::serialize(&msg, bfr);
      IMC::Message* msg_d = IMC::Packet::deserialize(bfr.getBuffer(), bfr.getSize());
      test.boolean("YoYo #1", msg == *msg_d);
      delete msg_d;
    }
    catch (IMC::InvalidMessageSize& e)
    {
      (void)e;
      test.boolean("msg #1", msg.getSerializationSize() > DUNE_IMC_CONST_MAX_SIZE);
    }
  }

  {
    IMC::YoYo msg;
    msg.setTimeStamp(0.8946121458040366);
    msg.setSource(58355U);
    msg.setSourceEntity(85U);
    msg.setDestination(10877U);
    msg.setDestinationEntity(68U);
    msg.timeout = 22803U;
    msg.lat = 0.9135296511576667;
    msg.lon = 0.9585745489800981;
    msg.z = 0.2780024506601567;
    msg.z_units = 250U;
    msg.amplitude = 0.9428999774361009;
    msg.pitch = 0.2482119924294507;
    msg.speed = 0.8150373345217298;
    msg.speed_units = 77U;
    msg.custom.assign("RPNIQCABNQWLUZSYKYWYFVRDZSTOWFCIDU");

    try
    {
      Utils::ByteBuffer bfr;
      IMC::Packet::serialize(&msg, bfr);
      IMC::Message* msg_d = IMC::Packet::deserialize(bfr.getBuffer(), bfr.getSize());
      test.boolean("YoYo #2", msg == *msg_d);
      delete msg_d;
    }
    catch (IMC::InvalidMessageSize& e)
    {
      (void)e;
      test.boolean("msg #2", msg.getSerializationSize() > DUNE_IMC_CONST_MAX_SIZE);
    }
  }

  {
    IMC::TeleoperationDone msg;
    msg.setTimeStamp(0.4992810292438936);
    msg.setSource(20495U);
    msg.setSourceEntity(67U);
    msg.setDestination(42531U);
    msg.setDestinationEntity(238U);

    try
    {
      Utils::ByteBuffer bfr;
      IMC::Packet::serialize(&msg, bfr);
      IMC::Message* msg_d = IMC::Packet::deserialize(bfr.getBuffer(), bfr.getSize());
      test.boolean("TeleoperationDone #0", msg == *msg_d);
      delete msg_d;
    }
    catch (IMC::InvalidMessageSize& e)
    {
      (void)e;
      test.boolean("msg #0", msg.getSerializationSize() > DUNE_IMC_CONST_MAX_SIZE);
    }
  }

  {
    IMC::TeleoperationDone msg;
    msg.setTimeStamp(0.09426266471772693);
    msg.setSource(7697U);
    msg.setSourceEntity(191U);
    msg.setDestination(25836U);
    msg.setDestinationEntity(232U);

    try
    {
      Utils::ByteBuffer bfr;
      IMC::Packet::serialize(&msg, bfr);
      IMC::Message* msg_d = IMC::Packet::deserialize(bfr.getBuffer(), bfr.getSize());
      test.boolean("TeleoperationDone #1", msg == *msg_d);
      delete msg_d;
    }
    catch (IMC::InvalidMessageSize& e)
    {
      (void)e;
      test.boolean("msg #1", msg.getSerializationSize() > DUNE_IMC_CONST_MAX_SIZE);
    }
  }

  {
    IMC::TeleoperationDone msg;
    msg.setTimeStamp(0.8842277186482269);
    msg.setSource(15066U);
    msg.setSourceEntity(202U);
    msg.setDestination(54572U);
    msg.setDestinationEntity(127U);

    try
    {
      Utils::ByteBuffer bfr;
      IMC::Packet::serialize(&msg, bfr);
      IMC::Message* msg_d = IMC::Packet::deserialize(bfr.getBuffer(), bfr.getSize());
      test.boolean("TeleoperationDone #2", msg == *msg_d);
      delete msg_d;
    }
    catch (IMC::InvalidMessageSize& e)
    {
      (void)e;
      test.boolean("msg #2", msg.getSerializationSize() > DUNE_IMC_CONST_MAX_SIZE);
    }
  }

  {
    IMC::StationKeeping msg;
    msg.setTimeStamp(0.8904902794095942);
    msg.setSource(24517U);
    msg.setSourceEntity(217U);
    msg.setDestination(13700U);
    msg.setDestinationEntity(40U);
    msg.lat = 0.10159352401685495;
    msg.lon = 0.9630703342238953;
    msg.z = 0.652389681781871;
    msg.z_units = 3U;
    msg.radius = 0.6185037176310575;
    msg.duration = 38162U;
    msg.speed = 0.03533885168617712;
    msg.speed_units = 155U;
    msg.custom.assign("XVRMZVSEBFSDRAROULQYUHHZHISBDWHMDULNGOVTKWTICCLOPWGABQOKTLCAGFTJMPRQAZDGINFDVMV");

    try
    {
      Utils::ByteBuffer bfr;
      IMC::Packet::serialize(&msg, bfr);
      IMC::Message* msg_d = IMC::Packet::deserialize(bfr.getBuffer(), bfr.getSize());
      test.boolean("StationKeeping #0", msg == *msg_d);
      delete msg_d;
    }
    catch (IMC::InvalidMessageSize& e)
    {
      (void)e;
      test.boolean("msg #0", msg.getSerializationSize() > DUNE_IMC_CONST_MAX_SIZE);
    }
  }

  {
    IMC::StationKeeping msg;
    msg.setTimeStamp(0.6112264732573568);
    msg.setSource(13726U);
    msg.setSourceEntity(149U);
    msg.setDestination(33229U);
    msg.setDestinationEntity(157U);
    msg.lat = 0.4981826687295752;
    msg.lon = 0.7386395769454253;
    msg.z = 0.012768611328844659;
    msg.z_units = 216U;
    msg.radius = 0.32892120677171444;
    msg.duration = 27258U;
    msg.speed = 0.7306299873186556;
    msg.speed_units = 243U;
    msg.custom.assign("HOIWVGLSHGKCHMUPHXEQGMSNAST");

    try
    {
      Utils::ByteBuffer bfr;
      IMC::Packet::serialize(&msg, bfr);
      IMC::Message* msg_d = IMC::Packet::deserialize(bfr.getBuffer(), bfr.getSize());
      test.boolean("StationKeeping #1", msg == *msg_d);
      delete msg_d;
    }
    catch (IMC::InvalidMessageSize& e)
    {
      (void)e;
      test.boolean("msg #1", msg.getSerializationSize() > DUNE_IMC_CONST_MAX_SIZE);
    }
  }

  {
    IMC::StationKeeping msg;
    msg.setTimeStamp(0.7631579466813416);
    msg.setSource(2416U);
    msg.setSourceEntity(128U);
    msg.setDestination(57295U);
    msg.setDestinationEntity(7U);
    msg.lat = 0.8027609396530851;
    msg.lon = 0.8243719773953623;
    msg.z = 0.23127086100571115;
    msg.z_units = 174U;
    msg.radius = 0.4418038338460851;
    msg.duration = 2908U;
    msg.speed = 0.7070668350275955;
    msg.speed_units = 36U;
    msg.custom.assign("CENELAAGNAYCLXIKIPFJCIRZTHEKXLOUSIXJNHUQXENDIVHCALWUVRVQASVPPHGHLFGBQWLWSKIALRUJITJVZBDGHWLMAGVHCXFZLZRZCHMPSAENZGMWFVTICURXMRUCYBSBTSFSKJUSPORSKDZYTKDTYWFCGOOZCOFAUBOGPPKPDKWPLQNGFVNTBQREDMYDNMBJBOYQFJBNKGUVRQDWJSQXENXEWUYBQOTMZI");

    try
    {
      Utils::ByteBuffer bfr;
      IMC::Packet::serialize(&msg, bfr);
      IMC::Message* msg_d = IMC::Packet::deserialize(bfr.getBuffer(), bfr.getSize());
      test.boolean("StationKeeping #2", msg == *msg_d);
      delete msg_d;
    }
    catch (IMC::InvalidMessageSize& e)
    {
      (void)e;
      test.boolean("msg #2", msg.getSerializationSize() > DUNE_IMC_CONST_MAX_SIZE);
    }
  }

  {
    IMC::Elevator msg;
    msg.setTimeStamp(0.6540781735369682);
    msg.setSource(50240U);
    msg.setSourceEntity(253U);
    msg.setDestination(21558U);
    msg.setDestinationEntity(51U);
    msg.timeout = 14293U;
    msg.flags = 40U;
    msg.lat = 0.9617305139512148;
    msg.lon = 0.1010369926540794;
    msg.start_z = 0.33062599709643825;
    msg.start_z_units = 214U;
    msg.end_z = 0.8963800370028122;
    msg.end_z_units = 59U;
    msg.radius = 0.975356888923884;
    msg.speed = 0.39193779589195143;
    msg.speed_units = 77U;
    msg.custom.assign("GBNDNTCFNZHODUSKROPVTQJJCSISENPRFSTIXCXOTTOFEYMQHYYSPESZLDIJRDXQIHAMLXRGSBFZJIQZUCVYBVAKFOFWQLXAZZRGDJWJAKZACVVHWHNUDEAAFLRKIFYGWGDCDLVCMNEMVLQOOVGMAPMYNAJQKXJWXRTKPLNESUZZNSIBILETZMKYHWFTCBPUUGPBYQIFULRPHPHUAOPMCWIQ");

    try
    {
      Utils::ByteBuffer bfr;
      IMC::Packet::serialize(&msg, bfr);
      IMC::Message* msg_d = IMC::Packet::deserialize(bfr.getBuffer(), bfr.getSize());
      test.boolean("Elevator #0", msg == *msg_d);
      delete msg_d;
    }
    catch (IMC::InvalidMessageSize& e)
    {
      (void)e;
      test.boolean("msg #0", msg.getSerializationSize() > DUNE_IMC_CONST_MAX_SIZE);
    }
  }

  {
    IMC::Elevator msg;
    msg.setTimeStamp(0.016642055074931772);
    msg.setSource(4511U);
    msg.setSourceEntity(96U);
    msg.setDestination(41945U);
    msg.setDestinationEntity(206U);
    msg.timeout = 17287U;
    msg.flags = 228U;
    msg.lat = 0.06881676995462627;
    msg.lon = 0.8678217119963992;
    msg.start_z = 0.8319214406161012;
    msg.start_z_units = 39U;
    msg.end_z = 0.439938762049081;
    msg.end_z_units = 119U;
    msg.radius = 0.949387336540025;
    msg.speed = 0.3208580008754096;
    msg.speed_units = 238U;
    msg.custom.assign("SGYUCKSMWZCPDQRZWTRNXXFKTXOEMPCWVJNFISLSSKXPYILQNUNTKSWRJAGZCWMJHSHUAXDKXYHTBUUQONJEQHYAIQXATRIRWPIRYKVZLWATMQCRDWFYESHQBVPZB");

    try
    {
      Utils::ByteBuffer bfr;
      IMC::Packet::serialize(&msg, bfr);
      IMC::Message* msg_d = IMC::Packet::deserialize(bfr.getBuffer(), bfr.getSize());
      test.boolean("Elevator #1", msg == *msg_d);
      delete msg_d;
    }
    catch (IMC::InvalidMessageSize& e)
    {
      (void)e;
      test.boolean("msg #1", msg.getSerializationSize() > DUNE_IMC_CONST_MAX_SIZE);
    }
  }

  {
    IMC::Elevator msg;
    msg.setTimeStamp(0.6987366174092631);
    msg.setSource(27159U);
    msg.setSourceEntity(161U);
    msg.setDestination(7088U);
    msg.setDestinationEntity(70U);
    msg.timeout = 60197U;
    msg.flags = 191U;
    msg.lat = 0.35925925116385793;
    msg.lon = 0.8530372757897107;
    msg.start_z = 0.33120220326043304;
    msg.start_z_units = 223U;
    msg.end_z = 0.05136507415332747;
    msg.end_z_units = 51U;
    msg.radius = 0.04987857371456528;
    msg.speed = 0.4517643527049332;
    msg.speed_units = 224U;
    msg.custom.assign("UJQQJHYFOSDSKUPQLZJWTIIZRQDRPOHLVRBGPHULKETLYOFSRGXNHYVTELPBLGONUDGCVSAYIYXIFMWWKWCPSTPMTCXNFQDYCNQSLIIRFNHUSEETSJQDHKUVDMZQVAVKSWBOUGJLYUDCHPZVOWCXVOEGZAKTFYEQOJARJBMXOMNZ");

    try
    {
      Utils::ByteBuffer bfr;
      IMC::Packet::serialize(&msg, bfr);
      IMC::Message* msg_d = IMC::Packet::deserialize(bfr.getBuffer(), bfr.getSize());
      test.boolean("Elevator #2", msg == *msg_d);
      delete msg_d;
    }
    catch (IMC::InvalidMessageSize& e)
    {
      (void)e;
      test.boolean("msg #2", msg.getSerializationSize() > DUNE_IMC_CONST_MAX_SIZE);
    }
  }

  {
    IMC::FollowTrajectory msg;
    msg.setTimeStamp(0.10850055628561173);
    msg.setSource(59297U);
    msg.setSourceEntity(77U);
    msg.setDestination(8529U);
    msg.setDestinationEntity(187U);
    msg.timeout = 14554U;
    msg.lat = 0.6846082088954564;
    msg.lon = 0.8379048807533237;
    msg.z = 0.4514639794159505;
    msg.z_units = 75U;
    msg.speed = 0.7152366808388431;
    msg.speed_units = 138U;
    IMC::TrajectoryPoint tmp_msg_0;
    tmp_msg_0.x = 0.8061687329828167;
    tmp_msg_0.y = 0.4783528711637095;
    tmp_msg_0.z = 0.2847786018356917;
    tmp_msg_0.t = 0.7692466193840458;
    msg.points.push_back(tmp_msg_0);
    msg.custom.assign("SMQHBZIKYSQQWKGUGPFXHXXLMGEZAUSHMUPKBJCKZLQEIMXJNNVFEOCMGBGLKRBDTCCRDCQJEFXRPVWJVJVQBPFEBPQLGFDMBHMDODFJUIYYCFWTNOOURWRUKNWHOYIOJLRZSUDKTJIELGVZZNZPMSWBSBYNDOKFAITWADXCKV");

    try
    {
      Utils::ByteBuffer bfr;
      IMC::Packet::serialize(&msg, bfr);
      IMC::Message* msg_d = IMC::Packet::deserialize(bfr.getBuffer(), bfr.getSize());
      test.boolean("FollowTrajectory #0", msg == *msg_d);
      delete msg_d;
    }
    catch (IMC::InvalidMessageSize& e)
    {
      (void)e;
      test.boolean("msg #0", msg.getSerializationSize() > DUNE_IMC_CONST_MAX_SIZE);
    }
  }

  {
    IMC::FollowTrajectory msg;
    msg.setTimeStamp(0.003814291227109634);
    msg.setSource(37804U);
    msg.setSourceEntity(156U);
    msg.setDestination(8310U);
    msg.setDestinationEntity(123U);
    msg.timeout = 54113U;
    msg.lat = 0.8209374760463107;
    msg.lon = 0.8269269756638915;
    msg.z = 0.5682768398090458;
    msg.z_units = 47U;
    msg.speed = 0.10378754803019641;
    msg.speed_units = 182U;
    IMC::TrajectoryPoint tmp_msg_0;
    tmp_msg_0.x = 0.3233568852350076;
    tmp_msg_0.y = 0.300254298832741;
    tmp_msg_0.z = 0.22527479132244033;
    tmp_msg_0.t = 0.8753092507733243;
    msg.points.push_back(tmp_msg_0);
    msg.custom.assign("HSIBEBMSUHFDUJYWZNNHCBWDTHMKXLGWNTQPCJQMCKFXKSPWUIETVASXUPLCLZNRSTOVUBUBUZINGRTQPPOBFJWTEVMXDUEP");

    try
    {
      Utils::ByteBuffer bfr;
      IMC::Packet::serialize(&msg, bfr);
      IMC::Message* msg_d = IMC::Packet::deserialize(bfr.getBuffer(), bfr.getSize());
      test.boolean("FollowTrajectory #1", msg == *msg_d);
      delete msg_d;
    }
    catch (IMC::InvalidMessageSize& e)
    {
      (void)e;
      test.boolean("msg #1", msg.getSerializationSize() > DUNE_IMC_CONST_MAX_SIZE);
    }
  }

  {
    IMC::FollowTrajectory msg;
    msg.setTimeStamp(0.0645738835249744);
    msg.setSource(39591U);
    msg.setSourceEntity(163U);
    msg.setDestination(37614U);
    msg.setDestinationEntity(128U);
    msg.timeout = 16252U;
    msg.lat = 0.28772700177713295;
    msg.lon = 0.022865628472892974;
    msg.z = 0.2735612333311608;
    msg.z_units = 67U;
    msg.speed = 0.4362628082447493;
    msg.speed_units = 25U;
    msg.custom.assign("VSTUCXIYTMSZPDKQMGSJPHYKUFNOIDBYZBUAQKVLVMWUXNXONHPYVZSVLMVPCKJWSFKZKBNTURLWJJRXLMUADDJQVZOFCKIAQTULQPMSGIEIASLLRFPLBRQZOXMERVBJHGIRXGINYYEAQD");

    try
    {
      Utils::ByteBuffer bfr;
      IMC::Packet::serialize(&msg, bfr);
      IMC::Message* msg_d = IMC::Packet::deserialize(bfr.getBuffer(), bfr.getSize());
      test.boolean("FollowTrajectory #2", msg == *msg_d);
      delete msg_d;
    }
    catch (IMC::InvalidMessageSize& e)
    {
      (void)e;
      test.boolean("msg #2", msg.getSerializationSize() > DUNE_IMC_CONST_MAX_SIZE);
    }
  }

  {
    IMC::TrajectoryPoint msg;
    msg.setTimeStamp(0.026816141716640263);
    msg.setSource(28463U);
    msg.setSourceEntity(1U);
    msg.setDestination(21122U);
    msg.setDestinationEntity(193U);
    msg.x = 0.06813784368814857;
    msg.y = 0.8471394811698537;
    msg.z = 0.3802909118491936;
    msg.t = 0.7913067390828802;

    try
    {
      Utils::ByteBuffer bfr;
      IMC::Packet::serialize(&msg, bfr);
      IMC::Message* msg_d = IMC::Packet::deserialize(bfr.getBuffer(), bfr.getSize());
      test.boolean("TrajectoryPoint #0", msg == *msg_d);
      delete msg_d;
    }
    catch (IMC::InvalidMessageSize& e)
    {
      (void)e;
      test.boolean("msg #0", msg.getSerializationSize() > DUNE_IMC_CONST_MAX_SIZE);
    }
  }

  {
    IMC::TrajectoryPoint msg;
    msg.setTimeStamp(0.4925410183449417);
    msg.setSource(53856U);
    msg.setSourceEntity(35U);
    msg.setDestination(6008U);
    msg.setDestinationEntity(188U);
    msg.x = 0.6187980108170466;
    msg.y = 0.6849716705511926;
    msg.z = 0.9051704635482276;
    msg.t = 0.8911043597892236;

    try
    {
      Utils::ByteBuffer bfr;
      IMC::Packet::serialize(&msg, bfr);
      IMC::Message* msg_d = IMC::Packet::deserialize(bfr.getBuffer(), bfr.getSize());
      test.boolean("TrajectoryPoint #1", msg == *msg_d);
      delete msg_d;
    }
    catch (IMC::InvalidMessageSize& e)
    {
      (void)e;
      test.boolean("msg #1", msg.getSerializationSize() > DUNE_IMC_CONST_MAX_SIZE);
    }
  }

  {
    IMC::TrajectoryPoint msg;
    msg.setTimeStamp(0.7515474021293235);
    msg.setSource(49262U);
    msg.setSourceEntity(112U);
    msg.setDestination(3346U);
    msg.setDestinationEntity(179U);
    msg.x = 0.6544286753090647;
    msg.y = 0.8759044702379919;
    msg.z = 0.3408805760198165;
    msg.t = 0.09005782458990186;

    try
    {
      Utils::ByteBuffer bfr;
      IMC::Packet::serialize(&msg, bfr);
      IMC::Message* msg_d = IMC::Packet::deserialize(bfr.getBuffer(), bfr.getSize());
      test.boolean("TrajectoryPoint #2", msg == *msg_d);
      delete msg_d;
    }
    catch (IMC::InvalidMessageSize& e)
    {
      (void)e;
      test.boolean("msg #2", msg.getSerializationSize() > DUNE_IMC_CONST_MAX_SIZE);
    }
  }

  {
    IMC::CustomManeuver msg;
    msg.setTimeStamp(0.9428769464132588);
    msg.setSource(35147U);
    msg.setSourceEntity(193U);
    msg.setDestination(27300U);
    msg.setDestinationEntity(146U);
    msg.timeout = 57880U;
    msg.name.assign("SLKQNSPWWNPJMQGMJHVYXAVRWXDHKNSCUTVIEVUMIDYQTOHCYWANTRCLIDIAZWHFYDKGYWCFBXYQLZEJBQTYOGNCCFGBRPTXJYATBRAJCMPEYSBSFVIRUKOXLELGKXIPFPNFNENASUCOUMOOBQOGNOJCRZHXUFPPLWNTSHKZZOLVQUJGZSCHMREJMXHLPHGQE");
    msg.custom.assign("BBQPSKVNZUHZCAGFFGFPFNJNDKQQFQRIVUPIBEHVUUIDMLOIOAMYTZMCLJCTPBEERVXHVESSOSRQMPUSBZVMEBWMDLQLRRWPVTSXJUM");

    try
    {
      Utils::ByteBuffer bfr;
      IMC::Packet::serialize(&msg, bfr);
      IMC::Message* msg_d = IMC::Packet::deserialize(bfr.getBuffer(), bfr.getSize());
      test.boolean("CustomManeuver #0", msg == *msg_d);
      delete msg_d;
    }
    catch (IMC::InvalidMessageSize& e)
    {
      (void)e;
      test.boolean("msg #0", msg.getSerializationSize() > DUNE_IMC_CONST_MAX_SIZE);
    }
  }

  {
    IMC::CustomManeuver msg;
    msg.setTimeStamp(0.10818568976633613);
    msg.setSource(3611U);
    msg.setSourceEntity(151U);
    msg.setDestination(14437U);
    msg.setDestinationEntity(130U);
    msg.timeout = 31197U;
    msg.name.assign("NPNBWVSUNIEIVZZSODIKTANTIOMWNYFFJZVFKLIPYALLIOEHSUQUZCQMDASACIYRCPYVOISCCFLKVJJYDABDEUCLKRDABWMAJQUFSCVQMXPRRXHTJEZEETZSZFKXMNOZBNWLWGPFFOTUQPGOHXXCWSQLQHGPRTUEHJXGMZGMYVRONYWBNPRTOVJXSVXVIMNGHPMXJRDWGRDPDBGUETDQZHAKYBJYQYECBALFLOWBCAUHRGKHFJQEBKTDTLK");
    msg.custom.assign("RKUTODJBPXRFIODLYHJDEJHCHTUJMHRVKJXADIVQYMKPJLTELBOZPFXMBYPKLPIGFFAINPLWTQBMTYERXMTXNMSUECQKIAGZSMUIOKUDEQZRKKOHVBRYZZSVOZOVAGHZGACIAFTFVBQYIHRAOLKVAVTWYCUQWPXGGGTFSQSGNZFCCTPCDWJWZSDRFIXLMWJPVRRESQMU");

    try
    {
      Utils::ByteBuffer bfr;
      IMC::Packet::serialize(&msg, bfr);
      IMC::Message* msg_d = IMC::Packet::deserialize(bfr.getBuffer(), bfr.getSize());
      test.boolean("CustomManeuver #1", msg == *msg_d);
      delete msg_d;
    }
    catch (IMC::InvalidMessageSize& e)
    {
      (void)e;
      test.boolean("msg #1", msg.getSerializationSize() > DUNE_IMC_CONST_MAX_SIZE);
    }
  }

  {
    IMC::CustomManeuver msg;
    msg.setTimeStamp(0.29026619771386886);
    msg.setSource(36961U);
    msg.setSourceEntity(119U);
    msg.setDestination(2774U);
    msg.setDestinationEntity(164U);
    msg.timeout = 40841U;
    msg.name.assign("LWFQSDFZQHPLSPSRFJBIEEWUOXFZCAMSBIHKPKBZCKXJMBDRS");
    msg.custom.assign("RUUZCTSWNSCRXXXAAODHSDBAJVGBWWGFLSWTWSHCSAIZAKDNYICYPYHXEGGFVJFVGUVXPOWFRYUVYLGGIFMOBFDITXEIPHHEKTKKORTZNZSPSRZJYQREDIJTBGXJESIPWXTYCVUJWGTPAHUNZLNNHHFDQWBOXCSMYTERPQVMQDQEKCLUQGKDXALNOQPHNHVKLLMLBUPREOOEMZTDVUYAJKMFQPJFOBJQZNLJLKKYVIBURCIZIMEDWMAMQBB");

    try
    {
      Utils::ByteBuffer bfr;
      IMC::Packet::serialize(&msg, bfr);
      IMC::Message* msg_d = IMC::Packet::deserialize(bfr.getBuffer(), bfr.getSize());
      test.boolean("CustomManeuver #2", msg == *msg_d);
      delete msg_d;
    }
    catch (IMC::InvalidMessageSize& e)
    {
      (void)e;
      test.boolean("msg #2", msg.getSerializationSize() > DUNE_IMC_CONST_MAX_SIZE);
    }
  }

  {
    IMC::VehicleFormation msg;
    msg.setTimeStamp(0.597614907497722);
    msg.setSource(52071U);
    msg.setSourceEntity(40U);
    msg.setDestination(25740U);
    msg.setDestinationEntity(14U);
    msg.lat = 0.9201400560140767;
    msg.lon = 0.25699383173946944;
    msg.z = 0.8573588251039458;
    msg.z_units = 205U;
    msg.speed = 0.23692404020761104;
    msg.speed_units = 154U;
    IMC::VehicleFormationParticipant tmp_msg_0;
    tmp_msg_0.vid = 45182U;
    tmp_msg_0.off_x = 0.8973017908044679;
    tmp_msg_0.off_y = 0.6779220937519471;
    tmp_msg_0.off_z = 0.24117024334574733;
    msg.participants.push_back(tmp_msg_0);
    msg.start_time = 0.2450412365486221;
    msg.custom.assign("HQADRIHEFWGROQAHLRBANSPOGADOKTPJQHBYXJKFOLJJZABKFFRVUBWEQLJTPLOMAZLDXXZROJFBXQVXAYBDFCOYXWBGINUWDNNMVGKZPHTVQQWVSCHRPCHDGNTBUMSWXXZCRMWPJYSKMYIJUSLGWMHIOCUITUNKIAZSSKVXFOIWNCDPCGRUVZEFTJESEUYYBZIDWUACGVH");

    try
    {
      Utils::ByteBuffer bfr;
      IMC::Packet::serialize(&msg, bfr);
      IMC::Message* msg_d = IMC::Packet::deserialize(bfr.getBuffer(), bfr.getSize());
      test.boolean("VehicleFormation #0", msg == *msg_d);
      delete msg_d;
    }
    catch (IMC::InvalidMessageSize& e)
    {
      (void)e;
      test.boolean("msg #0", msg.getSerializationSize() > DUNE_IMC_CONST_MAX_SIZE);
    }
  }

  {
    IMC::VehicleFormation msg;
    msg.setTimeStamp(0.08791186561450226);
    msg.setSource(7767U);
    msg.setSourceEntity(196U);
    msg.setDestination(34737U);
    msg.setDestinationEntity(131U);
    msg.lat = 0.4953407287450946;
    msg.lon = 0.33034698531747264;
    msg.z = 0.7546213703292435;
    msg.z_units = 70U;
    msg.speed = 0.33124005068739293;
    msg.speed_units = 104U;
    IMC::TrajectoryPoint tmp_msg_0;
    tmp_msg_0.x = 0.603111440670778;
    tmp_msg_0.y = 0.7167251202345873;
    tmp_msg_0.z = 0.808110422817836;
    tmp_msg_0.t = 0.29946024645476776;
    msg.points.push_back(tmp_msg_0);
    IMC::VehicleFormationParticipant tmp_msg_1;
    tmp_msg_1.vid = 10485U;
    tmp_msg_1.off_x = 0.6094002619284324;
    tmp_msg_1.off_y = 0.39392799061582495;
    tmp_msg_1.off_z = 0.5275378060547532;
    msg.participants.push_back(tmp_msg_1);
    msg.start_time = 0.06249170856803332;
    msg.custom.assign("VIFVLPDDNYGJPOMZTDVWIZUXPHGFVQWHPRVRCYXLYWKSUUNRYOQIWBQPXSCLMEXTMCPZZRGMABAYFTWAVQQCSZBTGHDFVJO");

    try
    {
      Utils::ByteBuffer bfr;
      IMC::Packet::serialize(&msg, bfr);
      IMC::Message* msg_d = IMC::Packet::deserialize(bfr.getBuffer(), bfr.getSize());
      test.boolean("VehicleFormation #1", msg == *msg_d);
      delete msg_d;
    }
    catch (IMC::InvalidMessageSize& e)
    {
      (void)e;
      test.boolean("msg #1", msg.getSerializationSize() > DUNE_IMC_CONST_MAX_SIZE);
    }
  }

  {
    IMC::VehicleFormation msg;
    msg.setTimeStamp(0.8280500155876215);
    msg.setSource(13208U);
    msg.setSourceEntity(148U);
    msg.setDestination(3696U);
    msg.setDestinationEntity(134U);
    msg.lat = 0.40703286729909294;
    msg.lon = 0.5223848317342635;
    msg.z = 0.9368640867892647;
    msg.z_units = 196U;
    msg.speed = 0.7209442874538805;
    msg.speed_units = 101U;
    IMC::VehicleFormationParticipant tmp_msg_0;
    tmp_msg_0.vid = 48700U;
    tmp_msg_0.off_x = 0.197792725195585;
    tmp_msg_0.off_y = 0.5280960645292239;
    tmp_msg_0.off_z = 0.9530308495882641;
    msg.participants.push_back(tmp_msg_0);
    msg.start_time = 0.9014226308713059;
    msg.custom.assign("HJADSXQQDYISZLEOFODBXESTGLZHSIETVGIFHXEQULKRURMLYJDDVKNFIYPLGPFSIQXEWOZDUYVKNPGHQZGRRAWFJSFNGJIVHSOBUYCRWFLJOXGOYRJMVBLEOXHUPLCQORWULEAKXNHCYZTTCPPXKYFHTQPVCZBKABGQDBMCCKUQWYJTZAKUAJSRXKXWABBCNZNGMYI");

    try
    {
      Utils::ByteBuffer bfr;
      IMC::Packet::serialize(&msg, bfr);
      IMC::Message* msg_d = IMC::Packet::deserialize(bfr.getBuffer(), bfr.getSize());
      test.boolean("VehicleFormation #2", msg == *msg_d);
      delete msg_d;
    }
    catch (IMC::InvalidMessageSize& e)
    {
      (void)e;
      test.boolean("msg #2", msg.getSerializationSize() > DUNE_IMC_CONST_MAX_SIZE);
    }
  }

  {
    IMC::VehicleFormationParticipant msg;
    msg.setTimeStamp(0.37659107113296475);
    msg.setSource(26166U);
    msg.setSourceEntity(31U);
    msg.setDestination(11865U);
    msg.setDestinationEntity(17U);
    msg.vid = 26986U;
    msg.off_x = 0.9376179146150058;
    msg.off_y = 0.7905818639497301;
    msg.off_z = 0.42508974677335576;

    try
    {
      Utils::ByteBuffer bfr;
      IMC::Packet::serialize(&msg, bfr);
      IMC::Message* msg_d = IMC::Packet::deserialize(bfr.getBuffer(), bfr.getSize());
      test.boolean("VehicleFormationParticipant #0", msg == *msg_d);
      delete msg_d;
    }
    catch (IMC::InvalidMessageSize& e)
    {
      (void)e;
      test.boolean("msg #0", msg.getSerializationSize() > DUNE_IMC_CONST_MAX_SIZE);
    }
  }

  {
    IMC::VehicleFormationParticipant msg;
    msg.setTimeStamp(0.38535490345373546);
    msg.setSource(27301U);
    msg.setSourceEntity(166U);
    msg.setDestination(6289U);
    msg.setDestinationEntity(120U);
    msg.vid = 27660U;
    msg.off_x = 0.9444622131095909;
    msg.off_y = 0.810586198394235;
    msg.off_z = 0.8255121486387119;

    try
    {
      Utils::ByteBuffer bfr;
      IMC::Packet::serialize(&msg, bfr);
      IMC::Message* msg_d = IMC::Packet::deserialize(bfr.getBuffer(), bfr.getSize());
      test.boolean("VehicleFormationParticipant #1", msg == *msg_d);
      delete msg_d;
    }
    catch (IMC::InvalidMessageSize& e)
    {
      (void)e;
      test.boolean("msg #1", msg.getSerializationSize() > DUNE_IMC_CONST_MAX_SIZE);
    }
  }

  {
    IMC::VehicleFormationParticipant msg;
    msg.setTimeStamp(0.02037279947237891);
    msg.setSource(51363U);
    msg.setSourceEntity(124U);
    msg.setDestination(24579U);
    msg.setDestinationEntity(223U);
    msg.vid = 50778U;
    msg.off_x = 0.21578676801629348;
    msg.off_y = 0.12232995641284716;
    msg.off_z = 0.9419361598173865;

    try
    {
      Utils::ByteBuffer bfr;
      IMC::Packet::serialize(&msg, bfr);
      IMC::Message* msg_d = IMC::Packet::deserialize(bfr.getBuffer(), bfr.getSize());
      test.boolean("VehicleFormationParticipant #2", msg == *msg_d);
      delete msg_d;
    }
    catch (IMC::InvalidMessageSize& e)
    {
      (void)e;
      test.boolean("msg #2", msg.getSerializationSize() > DUNE_IMC_CONST_MAX_SIZE);
    }
  }

  {
    IMC::StopManeuver msg;
    msg.setTimeStamp(0.1586507471228703);
    msg.setSource(9457U);
    msg.setSourceEntity(49U);
    msg.setDestination(51410U);
    msg.setDestinationEntity(254U);

    try
    {
      Utils::ByteBuffer bfr;
      IMC::Packet::serialize(&msg, bfr);
      IMC::Message* msg_d = IMC::Packet::deserialize(bfr.getBuffer(), bfr.getSize());
      test.boolean("StopManeuver #0", msg == *msg_d);
      delete msg_d;
    }
    catch (IMC::InvalidMessageSize& e)
    {
      (void)e;
      test.boolean("msg #0", msg.getSerializationSize() > DUNE_IMC_CONST_MAX_SIZE);
    }
  }

  {
    IMC::StopManeuver msg;
    msg.setTimeStamp(0.11203092995929032);
    msg.setSource(48764U);
    msg.setSourceEntity(38U);
    msg.setDestination(14323U);
    msg.setDestinationEntity(45U);

    try
    {
      Utils::ByteBuffer bfr;
      IMC::Packet::serialize(&msg, bfr);
      IMC::Message* msg_d = IMC::Packet::deserialize(bfr.getBuffer(), bfr.getSize());
      test.boolean("StopManeuver #1", msg == *msg_d);
      delete msg_d;
    }
    catch (IMC::InvalidMessageSize& e)
    {
      (void)e;
      test.boolean("msg #1", msg.getSerializationSize() > DUNE_IMC_CONST_MAX_SIZE);
    }
  }

  {
    IMC::StopManeuver msg;
    msg.setTimeStamp(0.4900508869021001);
    msg.setSource(19604U);
    msg.setSourceEntity(14U);
    msg.setDestination(7291U);
    msg.setDestinationEntity(205U);

    try
    {
      Utils::ByteBuffer bfr;
      IMC::Packet::serialize(&msg, bfr);
      IMC::Message* msg_d = IMC::Packet::deserialize(bfr.getBuffer(), bfr.getSize());
      test.boolean("StopManeuver #2", msg == *msg_d);
      delete msg_d;
    }
    catch (IMC::InvalidMessageSize& e)
    {
      (void)e;
      test.boolean("msg #2", msg.getSerializationSize() > DUNE_IMC_CONST_MAX_SIZE);
    }
  }

  {
    IMC::RegisterManeuver msg;
    msg.setTimeStamp(0.22647686477446494);
    msg.setSource(22243U);
    msg.setSourceEntity(155U);
    msg.setDestination(39008U);
    msg.setDestinationEntity(210U);
    msg.mid = 18457U;

    try
    {
      Utils::ByteBuffer bfr;
      IMC::Packet::serialize(&msg, bfr);
      IMC::Message* msg_d = IMC::Packet::deserialize(bfr.getBuffer(), bfr.getSize());
      test.boolean("RegisterManeuver #0", msg == *msg_d);
      delete msg_d;
    }
    catch (IMC::InvalidMessageSize& e)
    {
      (void)e;
      test.boolean("msg #0", msg.getSerializationSize() > DUNE_IMC_CONST_MAX_SIZE);
    }
  }

  {
    IMC::RegisterManeuver msg;
    msg.setTimeStamp(0.7393472201841756);
    msg.setSource(24881U);
    msg.setSourceEntity(228U);
    msg.setDestination(62626U);
    msg.setDestinationEntity(42U);
    msg.mid = 34383U;

    try
    {
      Utils::ByteBuffer bfr;
      IMC::Packet::serialize(&msg, bfr);
      IMC::Message* msg_d = IMC::Packet::deserialize(bfr.getBuffer(), bfr.getSize());
      test.boolean("RegisterManeuver #1", msg == *msg_d);
      delete msg_d;
    }
    catch (IMC::InvalidMessageSize& e)
    {
      (void)e;
      test.boolean("msg #1", msg.getSerializationSize() > DUNE_IMC_CONST_MAX_SIZE);
    }
  }

  {
    IMC::RegisterManeuver msg;
    msg.setTimeStamp(0.38286589095648904);
    msg.setSource(19104U);
    msg.setSourceEntity(154U);
    msg.setDestination(56906U);
    msg.setDestinationEntity(49U);
    msg.mid = 46481U;

    try
    {
      Utils::ByteBuffer bfr;
      IMC::Packet::serialize(&msg, bfr);
      IMC::Message* msg_d = IMC::Packet::deserialize(bfr.getBuffer(), bfr.getSize());
      test.boolean("RegisterManeuver #2", msg == *msg_d);
      delete msg_d;
    }
    catch (IMC::InvalidMessageSize& e)
    {
      (void)e;
      test.boolean("msg #2", msg.getSerializationSize() > DUNE_IMC_CONST_MAX_SIZE);
    }
  }

  {
    IMC::ManeuverControlState msg;
    msg.setTimeStamp(0.21775922014988214);
    msg.setSource(29497U);
    msg.setSourceEntity(215U);
    msg.setDestination(56143U);
    msg.setDestinationEntity(66U);
    msg.state = 182U;
    msg.eta = 56189U;
    msg.info.assign("MXDYQNOLJDUBDUFLXTDIWUPDRFZZBXKEQSIDXSOLRSKDLOUUELMPJLRMRDSYYZXGWZII");

    try
    {
      Utils::ByteBuffer bfr;
      IMC::Packet::serialize(&msg, bfr);
      IMC::Message* msg_d = IMC::Packet::deserialize(bfr.getBuffer(), bfr.getSize());
      test.boolean("ManeuverControlState #0", msg == *msg_d);
      delete msg_d;
    }
    catch (IMC::InvalidMessageSize& e)
    {
      (void)e;
      test.boolean("msg #0", msg.getSerializationSize() > DUNE_IMC_CONST_MAX_SIZE);
    }
  }

  {
    IMC::ManeuverControlState msg;
    msg.setTimeStamp(0.625501862663127);
    msg.setSource(55302U);
    msg.setSourceEntity(72U);
    msg.setDestination(13795U);
    msg.setDestinationEntity(165U);
    msg.state = 99U;
    msg.eta = 63716U;
    msg.info.assign("UNFHWACXPLPQFVBXPCETRABHQWEGNPYJGTBMWRPJDUHNSYEOMRICVPPLNOXKFLOLSUXCGMMOAPSFEJLHSJFAGQHBMADMBNNXPTCZKBJJVJVZICUQFDIDTYXWEEYGZDJZHZKFVOEFCIAVCFEOAKQQZXIAKMWEVMLRHXUMKZLZUNGWBGSQBLLGXTGGWMVRKOKTUTJEIYJY");

    try
    {
      Utils::ByteBuffer bfr;
      IMC::Packet::serialize(&msg, bfr);
      IMC::Message* msg_d = IMC::Packet::deserialize(bfr.getBuffer(), bfr.getSize());
      test.boolean("ManeuverControlState #1", msg == *msg_d);
      delete msg_d;
    }
    catch (IMC::InvalidMessageSize& e)
    {
      (void)e;
      test.boolean("msg #1", msg.getSerializationSize() > DUNE_IMC_CONST_MAX_SIZE);
    }
  }

  {
    IMC::ManeuverControlState msg;
    msg.setTimeStamp(0.8356783597718465);
    msg.setSource(51257U);
    msg.setSourceEntity(77U);
    msg.setDestination(11553U);
    msg.setDestinationEntity(30U);
    msg.state = 107U;
    msg.eta = 48850U;
    msg.info.assign("VDREDEMUEOMYHCOPTFXUBJDYNFZVUMQZNLSHXIGMPPSZPKYOILDAENQGLRWWOTBGHSPVYJVRQHRGXQSBFKRCIBRRDJUCFFVVHGZLSAPJSPUWTCSXIEWWIIJAZRNSATQWELCVLGJSAQCDGMTGLNOJAAGBJUUELXXFFXAWKYNNMMKEXOAGUSFHKVOCR");

    try
    {
      Utils::ByteBuffer bfr;
      IMC::Packet::serialize(&msg, bfr);
      IMC::Message* msg_d = IMC::Packet::deserialize(bfr.getBuffer(), bfr.getSize());
      test.boolean("ManeuverControlState #2", msg == *msg_d);
      delete msg_d;
    }
    catch (IMC::InvalidMessageSize& e)
    {
      (void)e;
      test.boolean("msg #2", msg.getSerializationSize() > DUNE_IMC_CONST_MAX_SIZE);
    }
  }

  {
    IMC::FollowSystem msg;
    msg.setTimeStamp(0.35025246681842237);
    msg.setSource(28247U);
    msg.setSourceEntity(142U);
    msg.setDestination(37573U);
    msg.setDestinationEntity(149U);
    msg.system = 27850U;
    msg.duration = 34883U;
    msg.speed = 0.6729036434763604;
    msg.speed_units = 198U;
    msg.x = 0.10395718934578668;
    msg.y = 0.28320386071891035;
    msg.z = 0.3033238535618018;
    msg.z_units = 47U;

    try
    {
      Utils::ByteBuffer bfr;
      IMC::Packet::serialize(&msg, bfr);
      IMC::Message* msg_d = IMC::Packet::deserialize(bfr.getBuffer(), bfr.getSize());
      test.boolean("FollowSystem #0", msg == *msg_d);
      delete msg_d;
    }
    catch (IMC::InvalidMessageSize& e)
    {
      (void)e;
      test.boolean("msg #0", msg.getSerializationSize() > DUNE_IMC_CONST_MAX_SIZE);
    }
  }

  {
    IMC::FollowSystem msg;
    msg.setTimeStamp(0.39543278072827104);
    msg.setSource(40875U);
    msg.setSourceEntity(254U);
    msg.setDestination(14566U);
    msg.setDestinationEntity(6U);
    msg.system = 43329U;
    msg.duration = 38692U;
    msg.speed = 0.020917752398641132;
    msg.speed_units = 108U;
    msg.x = 0.30684856601078514;
    msg.y = 0.8764377050606964;
    msg.z = 0.392109203719866;
    msg.z_units = 233U;

    try
    {
      Utils::ByteBuffer bfr;
      IMC::Packet::serialize(&msg, bfr);
      IMC::Message* msg_d = IMC::Packet::deserialize(bfr.getBuffer(), bfr.getSize());
      test.boolean("FollowSystem #1", msg == *msg_d);
      delete msg_d;
    }
    catch (IMC::InvalidMessageSize& e)
    {
      (void)e;
      test.boolean("msg #1", msg.getSerializationSize() > DUNE_IMC_CONST_MAX_SIZE);
    }
  }

  {
    IMC::FollowSystem msg;
    msg.setTimeStamp(0.1304157784294736);
    msg.setSource(7933U);
    msg.setSourceEntity(215U);
    msg.setDestination(55981U);
    msg.setDestinationEntity(225U);
    msg.system = 27724U;
    msg.duration = 7881U;
    msg.speed = 0.4070029326810942;
    msg.speed_units = 54U;
    msg.x = 0.02842861732345714;
    msg.y = 0.4922846258950324;
    msg.z = 0.34870906139753655;
    msg.z_units = 33U;

    try
    {
      Utils::ByteBuffer bfr;
      IMC::Packet::serialize(&msg, bfr);
      IMC::Message* msg_d = IMC::Packet::deserialize(bfr.getBuffer(), bfr.getSize());
      test.boolean("FollowSystem #2", msg == *msg_d);
      delete msg_d;
    }
    catch (IMC::InvalidMessageSize& e)
    {
      (void)e;
      test.boolean("msg #2", msg.getSerializationSize() > DUNE_IMC_CONST_MAX_SIZE);
    }
  }

  {
    IMC::CommsRelay msg;
    msg.setTimeStamp(0.8233201036535942);
    msg.setSource(20418U);
    msg.setSourceEntity(134U);
    msg.setDestination(60218U);
    msg.setDestinationEntity(207U);
    msg.lat = 0.9636485870929258;
    msg.lon = 0.7664222371676225;
    msg.speed = 0.9784536258607068;
    msg.speed_units = 92U;
    msg.duration = 14728U;
    msg.sys_a = 33863U;
    msg.sys_b = 24085U;
    msg.move_threshold = 0.22813548397402372;

    try
    {
      Utils::ByteBuffer bfr;
      IMC::Packet::serialize(&msg, bfr);
      IMC::Message* msg_d = IMC::Packet::deserialize(bfr.getBuffer(), bfr.getSize());
      test.boolean("CommsRelay #0", msg == *msg_d);
      delete msg_d;
    }
    catch (IMC::InvalidMessageSize& e)
    {
      (void)e;
      test.boolean("msg #0", msg.getSerializationSize() > DUNE_IMC_CONST_MAX_SIZE);
    }
  }

  {
    IMC::CommsRelay msg;
    msg.setTimeStamp(0.9982482949618341);
    msg.setSource(5256U);
    msg.setSourceEntity(96U);
    msg.setDestination(534U);
    msg.setDestinationEntity(11U);
    msg.lat = 0.3147263908603941;
    msg.lon = 0.5508551184338509;
    msg.speed = 0.3210755137203374;
    msg.speed_units = 128U;
    msg.duration = 13453U;
    msg.sys_a = 12467U;
    msg.sys_b = 52566U;
    msg.move_threshold = 0.20134467256164867;

    try
    {
      Utils::ByteBuffer bfr;
      IMC::Packet::serialize(&msg, bfr);
      IMC::Message* msg_d = IMC::Packet::deserialize(bfr.getBuffer(), bfr.getSize());
      test.boolean("CommsRelay #1", msg == *msg_d);
      delete msg_d;
    }
    catch (IMC::InvalidMessageSize& e)
    {
      (void)e;
      test.boolean("msg #1", msg.getSerializationSize() > DUNE_IMC_CONST_MAX_SIZE);
    }
  }

  {
    IMC::CommsRelay msg;
    msg.setTimeStamp(0.6810203720355377);
    msg.setSource(13684U);
    msg.setSourceEntity(238U);
    msg.setDestination(8066U);
    msg.setDestinationEntity(84U);
    msg.lat = 0.1326337046120193;
    msg.lon = 0.4164893817857057;
    msg.speed = 0.5031244117128809;
    msg.speed_units = 18U;
    msg.duration = 48253U;
    msg.sys_a = 6746U;
    msg.sys_b = 37472U;
    msg.move_threshold = 0.47362709309923046;

    try
    {
      Utils::ByteBuffer bfr;
      IMC::Packet::serialize(&msg, bfr);
      IMC::Message* msg_d = IMC::Packet::deserialize(bfr.getBuffer(), bfr.getSize());
      test.boolean("CommsRelay #2", msg == *msg_d);
      delete msg_d;
    }
    catch (IMC::InvalidMessageSize& e)
    {
      (void)e;
      test.boolean("msg #2", msg.getSerializationSize() > DUNE_IMC_CONST_MAX_SIZE);
    }
  }

  {
    IMC::CoverArea msg;
    msg.setTimeStamp(0.798150827777461);
    msg.setSource(50380U);
    msg.setSourceEntity(206U);
    msg.setDestination(11131U);
    msg.setDestinationEntity(141U);
    msg.lat = 0.9934457826282211;
    msg.lon = 0.298934708629914;
    msg.z = 0.21034817611034984;
    msg.z_units = 223U;
    msg.speed = 0.08576727953279817;
    msg.speed_units = 246U;
    msg.custom.assign("GHBCTDSILLCNXMEYDQFJYCEAPBZBMFITOAWPBIMRROZGDZYKUREIBHAJLINKPEQTXJDSUAYBYPVU");

    try
    {
      Utils::ByteBuffer bfr;
      IMC::Packet::serialize(&msg, bfr);
      IMC::Message* msg_d = IMC::Packet::deserialize(bfr.getBuffer(), bfr.getSize());
      test.boolean("CoverArea #0", msg == *msg_d);
      delete msg_d;
    }
    catch (IMC::InvalidMessageSize& e)
    {
      (void)e;
      test.boolean("msg #0", msg.getSerializationSize() > DUNE_IMC_CONST_MAX_SIZE);
    }
  }

  {
    IMC::CoverArea msg;
    msg.setTimeStamp(0.0883082353033462);
    msg.setSource(3231U);
    msg.setSourceEntity(223U);
    msg.setDestination(39825U);
    msg.setDestinationEntity(12U);
    msg.lat = 0.9993812136580873;
    msg.lon = 0.47005546661680553;
    msg.z = 0.3972814713046584;
    msg.z_units = 6U;
    msg.speed = 0.7385541707208232;
    msg.speed_units = 154U;
    IMC::PolygonVertex tmp_msg_0;
    tmp_msg_0.lat = 0.6342981503215858;
    tmp_msg_0.lon = 0.49123140221514006;
    msg.polygon.push_back(tmp_msg_0);
    msg.custom.assign("KMXUWERSGPXSBOHADDTGUCJDYCZQABQFSAYEMNBYMEYIRLIRXHNZHAXWFVGKJRWZAXNIHGTGABEGUFXVVCFFSH");

    try
    {
      Utils::ByteBuffer bfr;
      IMC::Packet::serialize(&msg, bfr);
      IMC::Message* msg_d = IMC::Packet::deserialize(bfr.getBuffer(), bfr.getSize());
      test.boolean("CoverArea #1", msg == *msg_d);
      delete msg_d;
    }
    catch (IMC::InvalidMessageSize& e)
    {
      (void)e;
      test.boolean("msg #1", msg.getSerializationSize() > DUNE_IMC_CONST_MAX_SIZE);
    }
  }

  {
    IMC::CoverArea msg;
    msg.setTimeStamp(0.3010251540071377);
    msg.setSource(3134U);
    msg.setSourceEntity(20U);
    msg.setDestination(9177U);
    msg.setDestinationEntity(250U);
    msg.lat = 0.5895884239614595;
    msg.lon = 0.9785839774099117;
    msg.z = 0.36392962818436636;
    msg.z_units = 188U;
    msg.speed = 0.6209704286624278;
    msg.speed_units = 187U;
    IMC::PolygonVertex tmp_msg_0;
    tmp_msg_0.lat = 0.6814643765474917;
    tmp_msg_0.lon = 0.8090659459280382;
    msg.polygon.push_back(tmp_msg_0);
    msg.custom.assign("INFAMVPIAJQFBCKBWURCJMQRXCUMHGCRIGMFBLAYWJFWXSDJKXMKRPRKKZYQYLHMZEGQHXYTVFTEJHSONGIJXYBRNM");

    try
    {
      Utils::ByteBuffer bfr;
      IMC::Packet::serialize(&msg, bfr);
      IMC::Message* msg_d = IMC::Packet::deserialize(bfr.getBuffer(), bfr.getSize());
      test.boolean("CoverArea #2", msg == *msg_d);
      delete msg_d;
    }
    catch (IMC::InvalidMessageSize& e)
    {
      (void)e;
      test.boolean("msg #2", msg.getSerializationSize() > DUNE_IMC_CONST_MAX_SIZE);
    }
  }

  {
    IMC::PolygonVertex msg;
    msg.setTimeStamp(0.6142813761927637);
    msg.setSource(25447U);
    msg.setSourceEntity(142U);
    msg.setDestination(63469U);
    msg.setDestinationEntity(130U);
    msg.lat = 0.022815534772622437;
    msg.lon = 0.9292062553276722;

    try
    {
      Utils::ByteBuffer bfr;
      IMC::Packet::serialize(&msg, bfr);
      IMC::Message* msg_d = IMC::Packet::deserialize(bfr.getBuffer(), bfr.getSize());
      test.boolean("PolygonVertex #0", msg == *msg_d);
      delete msg_d;
    }
    catch (IMC::InvalidMessageSize& e)
    {
      (void)e;
      test.boolean("msg #0", msg.getSerializationSize() > DUNE_IMC_CONST_MAX_SIZE);
    }
  }

  {
    IMC::PolygonVertex msg;
    msg.setTimeStamp(0.07224496410603032);
    msg.setSource(36180U);
    msg.setSourceEntity(236U);
    msg.setDestination(64115U);
    msg.setDestinationEntity(106U);
    msg.lat = 0.8222045639582853;
    msg.lon = 0.1402943279202541;

    try
    {
      Utils::ByteBuffer bfr;
      IMC::Packet::serialize(&msg, bfr);
      IMC::Message* msg_d = IMC::Packet::deserialize(bfr.getBuffer(), bfr.getSize());
      test.boolean("PolygonVertex #1", msg == *msg_d);
      delete msg_d;
    }
    catch (IMC::InvalidMessageSize& e)
    {
      (void)e;
      test.boolean("msg #1", msg.getSerializationSize() > DUNE_IMC_CONST_MAX_SIZE);
    }
  }

  {
    IMC::PolygonVertex msg;
    msg.setTimeStamp(0.25175439134065214);
    msg.setSource(201U);
    msg.setSourceEntity(76U);
    msg.setDestination(22249U);
    msg.setDestinationEntity(238U);
    msg.lat = 0.4644414237551028;
    msg.lon = 0.652686305538471;

    try
    {
      Utils::ByteBuffer bfr;
      IMC::Packet::serialize(&msg, bfr);
      IMC::Message* msg_d = IMC::Packet::deserialize(bfr.getBuffer(), bfr.getSize());
      test.boolean("PolygonVertex #2", msg == *msg_d);
      delete msg_d;
    }
    catch (IMC::InvalidMessageSize& e)
    {
      (void)e;
      test.boolean("msg #2", msg.getSerializationSize() > DUNE_IMC_CONST_MAX_SIZE);
    }
  }

  {
    IMC::CompassCalibration msg;
    msg.setTimeStamp(0.7843412830068502);
    msg.setSource(10743U);
    msg.setSourceEntity(84U);
    msg.setDestination(17963U);
    msg.setDestinationEntity(86U);
    msg.timeout = 39125U;
    msg.lat = 0.8391767718479551;
    msg.lon = 0.26289312299270373;
    msg.z = 0.09316673344679505;
    msg.z_units = 199U;
    msg.pitch = 0.9298769363180501;
    msg.amplitude = 0.15628364067858158;
    msg.duration = 25347U;
    msg.speed = 0.33967825415828656;
    msg.speed_units = 20U;
    msg.radius = 0.5262549195013713;
    msg.direction = 154U;
    msg.custom.assign("BUNPYBXTJHMXSCAHQJJQEZNAOBQCFNBESVJFIMZYVROIBIKDKXBKXPA");

    try
    {
      Utils::ByteBuffer bfr;
      IMC::Packet::serialize(&msg, bfr);
      IMC::Message* msg_d = IMC::Packet::deserialize(bfr.getBuffer(), bfr.getSize());
      test.boolean("CompassCalibration #0", msg == *msg_d);
      delete msg_d;
    }
    catch (IMC::InvalidMessageSize& e)
    {
      (void)e;
      test.boolean("msg #0", msg.getSerializationSize() > DUNE_IMC_CONST_MAX_SIZE);
    }
  }

  {
    IMC::CompassCalibration msg;
    msg.setTimeStamp(0.7562004374764864);
    msg.setSource(44966U);
    msg.setSourceEntity(219U);
    msg.setDestination(61102U);
    msg.setDestinationEntity(144U);
    msg.timeout = 54255U;
    msg.lat = 0.01116235078433614;
    msg.lon = 0.9146153603738123;
    msg.z = 0.4557250902768748;
    msg.z_units = 26U;
    msg.pitch = 0.9644173034023226;
    msg.amplitude = 0.5867337136348394;
    msg.duration = 49842U;
    msg.speed = 0.18717328114201204;
    msg.speed_units = 34U;
    msg.radius = 0.5666042759219582;
    msg.direction = 84U;
    msg.custom.assign("SCICOXEGMUDHDMUQKGUZIZCWWJTSVWDBESNCVPNOUAZIYLBGTF");

    try
    {
      Utils::ByteBuffer bfr;
      IMC::Packet::serialize(&msg, bfr);
      IMC::Message* msg_d = IMC::Packet::deserialize(bfr.getBuffer(), bfr.getSize());
      test.boolean("CompassCalibration #1", msg == *msg_d);
      delete msg_d;
    }
    catch (IMC::InvalidMessageSize& e)
    {
      (void)e;
      test.boolean("msg #1", msg.getSerializationSize() > DUNE_IMC_CONST_MAX_SIZE);
    }
  }

  {
    IMC::CompassCalibration msg;
    msg.setTimeStamp(0.8368685350043559);
    msg.setSource(45839U);
    msg.setSourceEntity(58U);
    msg.setDestination(45627U);
    msg.setDestinationEntity(104U);
    msg.timeout = 6626U;
    msg.lat = 0.5986827958073343;
    msg.lon = 0.5501340576912118;
    msg.z = 0.7642406696357102;
    msg.z_units = 167U;
    msg.pitch = 0.294034790016819;
    msg.amplitude = 0.8388235073561825;
    msg.duration = 17795U;
    msg.speed = 0.6420797392828188;
    msg.speed_units = 0U;
    msg.radius = 0.1951418733614294;
    msg.direction = 231U;
    msg.custom.assign("BFRBEOYDHJQLUOYRCXZAHLJEXEJACGHDKAZUHFCTXVVGXQCIASLSRNIMODPQSSGZXDXHDJAQGXFIYJYNCBRZXFATZKLTMDITT");

    try
    {
      Utils::ByteBuffer bfr;
      IMC::Packet::serialize(&msg, bfr);
      IMC::Message* msg_d = IMC::Packet::deserialize(bfr.getBuffer(), bfr.getSize());
      test.boolean("CompassCalibration #2", msg == *msg_d);
      delete msg_d;
    }
    catch (IMC::InvalidMessageSize& e)
    {
      (void)e;
      test.boolean("msg #2", msg.getSerializationSize() > DUNE_IMC_CONST_MAX_SIZE);
    }
  }

  {
    IMC::FormationParameters msg;
    msg.setTimeStamp(0.07993276253454107);
    msg.setSource(36126U);
    msg.setSourceEntity(208U);
    msg.setDestination(5105U);
    msg.setDestinationEntity(242U);
    msg.formation_name.assign("BQFPBGVEKAKGASZOCIWFUPRFTUYSUEOAOMGQHAIMTFJKZAPOVELMYRQWKQSHNOTNGWFZXFHOAWBCJZQKJUJZOLYQRVVPJFJRUHMMVUQTGSHXKTIDTMELMGNYATIIRRCIBUTEJBDLLCTFRKPXEWJGXETSCDNZHOERDYDBDBFVNLLMCKWWOYWWCPSNZUMBJINNNHPBRYLLSPGKUYQIUVACRHXLYHBQCGDXEPMIKPXEXVGVAAXHZ");
    msg.reference_frame = 79U;
    IMC::VehicleFormationParticipant tmp_msg_0;
    tmp_msg_0.vid = 2119U;
    tmp_msg_0.off_x = 0.6969182864775407;
    tmp_msg_0.off_y = 0.006288130712225337;
    tmp_msg_0.off_z = 0.24718445516287302;
    msg.participants.push_back(tmp_msg_0);
    msg.custom.assign("GIKNEOWIXRTSXIQGEUMWNNFJNUGXQEITQCNHCWKUFVPPLQSQCEDICRVDWPUZANTTJOTAOMZZLLTSHELRUORRRQSYYJFFGUSFOXPSRBFFDGOHFPHVGTYPWMYKYOVHBVJHSUNXKTUBGQMZOPUAKVCBPEDGZVXMHIMAOIHKLMEEIOXRBWAMYLSEHJHALMYPK");

    try
    {
      Utils::ByteBuffer bfr;
      IMC::Packet::serialize(&msg, bfr);
      IMC::Message* msg_d = IMC::Packet::deserialize(bfr.getBuffer(), bfr.getSize());
      test.boolean("FormationParameters #0", msg == *msg_d);
      delete msg_d;
    }
    catch (IMC::InvalidMessageSize& e)
    {
      (void)e;
      test.boolean("msg #0", msg.getSerializationSize() > DUNE_IMC_CONST_MAX_SIZE);
    }
  }

  {
    IMC::FormationParameters msg;
    msg.setTimeStamp(0.7304229000930546);
    msg.setSource(37946U);
    msg.setSourceEntity(90U);
    msg.setDestination(24929U);
    msg.setDestinationEntity(142U);
    msg.formation_name.assign("NSKUSFKPLTQXBWNBUFREZGSDFDVMMNRBKYLENUVCJUPOIPBPSNZPOGBXBNFJSVCYAPNTVJEEGRVXTJJIRBASFYEIHWFVZYHDGRHOTKUSNFXIWOMWMZHJYQYNRD");
    msg.reference_frame = 20U;
    msg.custom.assign("DTIAMEXFYINGETZTICTFMYQLUFDXSFDAYMWRKZNXFWBDEWMQEKYIDQNQJPNYHGUBAKWAEPOJJZZUFHLJWGZBACPRHVXHENSHDLYGPVTIHGSQLNYJZTZPKQSVUKJYBWOBCIAUOGVYXBXRWEQOWSLOXRFIWPTACRURGVAO");

    try
    {
      Utils::ByteBuffer bfr;
      IMC::Packet::serialize(&msg, bfr);
      IMC::Message* msg_d = IMC::Packet::deserialize(bfr.getBuffer(), bfr.getSize());
      test.boolean("FormationParameters #1", msg == *msg_d);
      delete msg_d;
    }
    catch (IMC::InvalidMessageSize& e)
    {
      (void)e;
      test.boolean("msg #1", msg.getSerializationSize() > DUNE_IMC_CONST_MAX_SIZE);
    }
  }

  {
    IMC::FormationParameters msg;
    msg.setTimeStamp(0.6763343788651331);
    msg.setSource(57808U);
    msg.setSourceEntity(149U);
    msg.setDestination(35464U);
    msg.setDestinationEntity(135U);
    msg.formation_name.assign("PYDCPVWYFOMYCHQENZPUHJLJXITQQINJNGHSNRLVHFYYYQEMGOUTWXCUMEBCHTELZNVSSQCYVBLFBOTBFDKHKVIACLRASJVAMOWKXAWPGSLZZSVGUDCUIGJWXZMOVCGRXETQWLPRTFXFDHKKKMZXPUVBONQBMNFZEXYUWSNYGKFDJ");
    msg.reference_frame = 10U;
    IMC::VehicleFormationParticipant tmp_msg_0;
    tmp_msg_0.vid = 16941U;
    tmp_msg_0.off_x = 0.06909161461393021;
    tmp_msg_0.off_y = 0.609057595202435;
    tmp_msg_0.off_z = 0.5935644611276066;
    msg.participants.push_back(tmp_msg_0);
    msg.custom.assign("EPWTNOQTEHHNTAACLGEPNYYTFQKHFBDKXICIIAJAXYGQBZYCMZOBAYZLLPJCXZTGFHYROOGERVMFZCLJPFNVUCQUHJHMKKZMEGQXWZQLMBRINYPDSOHEAMWQNGPWSMDEIGWPCCFBANFBXGHOTSKZKRTOQPMRWRJCIUKUDDYNVOISBSYRNSEBSIPZJACLJKUMVHXDVXJRGAQSHTBWGULUVYVZUMUUXBSODF");

    try
    {
      Utils::ByteBuffer bfr;
      IMC::Packet::serialize(&msg, bfr);
      IMC::Message* msg_d = IMC::Packet::deserialize(bfr.getBuffer(), bfr.getSize());
      test.boolean("FormationParameters #2", msg == *msg_d);
      delete msg_d;
    }
    catch (IMC::InvalidMessageSize& e)
    {
      (void)e;
      test.boolean("msg #2", msg.getSerializationSize() > DUNE_IMC_CONST_MAX_SIZE);
    }
  }

  {
    IMC::FormationPlanExecution msg;
    msg.setTimeStamp(0.48745330943290843);
    msg.setSource(28451U);
    msg.setSourceEntity(143U);
    msg.setDestination(11600U);
    msg.setDestinationEntity(244U);
    msg.group_name.assign("KCKIQGLNORVDZFVVOKAYFXGGYEQDUJEYAGNYSOZXCNIQTYEPXDUWWMEMMRKVWHLMJAGRJBBMMKRIWRVHCXAFEULDLWCQJYSWOWMASTOKTGCOMAOJIJHZKHTOMZPFEUTSBIUGYPNPXIKRZOHTQIINFTZNEGHPSUZULNFWRHEQCUFJJVJZZEALDXDLIDHCXRWHXBBBTSDCBBKMRPUJTKFVDVCVNGOTPXNZBQPQDIWYAYSPP");
    msg.formation_name.assign("VQXUAZSXOBIIZJTNGNZLGMDYDEZYIKBCJSPPVVFCCRQRFIHUWDKMUOFHLFOJQOIENZBAJKARAVXSWZUULPEQKYOEMBFMUFIFAKCSLLTIOYNDDOEUCNMXRUPLDSYBHTRDHRKEXQWKOMFLWTLNIEKSQVWCRECFBTT");
    msg.plan_id.assign("DVUSVXTEATCZESYSWESOALJNJJWJQDXJCGRJFDYLS");
    msg.description.assign("DTVVCATDBHEJGKZGCIOJBURPAUUFGRVRBQSQBHGPOTEOCIGMTUWBNLUE");
    msg.leader_speed = 0.670909931687056;
    msg.leader_bank_lim = 0.5632620998247229;
    msg.pos_sim_err_lim = 0.8023845389660752;
    msg.pos_sim_err_wrn = 0.6239652167496503;
    msg.pos_sim_err_timeout = 55209U;
    msg.converg_max = 0.24868522406700555;
    msg.converg_timeout = 53936U;
    msg.comms_timeout = 32966U;
    msg.turb_lim = 0.792512038468208;
    msg.custom.assign("GCKOUEAIBRFNUXJPGBQQQDNZNTRXLSONWVIHEKEGVKEAEYFMBFUHTCIEPPXPIROKOQPBBMXQEYOXZVUDLDLQBCOSTKAAUWIXFNCAZMVUJZQITTNZQBQVWGWFSNKSOJHMAPKIFCDSMIKXVUYTNLMRCAVIRETDMVZDRXAKWADPSTLBGS");

    try
    {
      Utils::ByteBuffer bfr;
      IMC::Packet::serialize(&msg, bfr);
      IMC::Message* msg_d = IMC::Packet::deserialize(bfr.getBuffer(), bfr.getSize());
      test.boolean("FormationPlanExecution #0", msg == *msg_d);
      delete msg_d;
    }
    catch (IMC::InvalidMessageSize& e)
    {
      (void)e;
      test.boolean("msg #0", msg.getSerializationSize() > DUNE_IMC_CONST_MAX_SIZE);
    }
  }

  {
    IMC::FormationPlanExecution msg;
    msg.setTimeStamp(0.29004761480275876);
    msg.setSource(3145U);
    msg.setSourceEntity(193U);
    msg.setDestination(33841U);
    msg.setDestinationEntity(215U);
    msg.group_name.assign("TARUBQDOSYFFETIZPMAGUZDBCJLZXJJPGTQERZOOCGIFTMZAPQSDNSNPERCQZFEXTPBXEIFVWBMFNPREOECJKUQSQTITQKYAWSUIZHXCLIYRPBNRVI");
    msg.formation_name.assign("ETXLRWYMNNQFBHVGRASBKPCVCYGHRBGFCFOUEOHAXRMORKXCUMEMHNDLMHWSIIKVRSTHFBQPTOYSXFXXLJILCDIKHSCYVJJWREVTXTLIFLDYCU");
    msg.plan_id.assign("SSVBAXFXZDKOEPCOENBQGQPYNKMAPFQUIPGOUXERJMTQAPCDMNLFVWWZDNCRLGGLANSKJISHTVCLHNSQLKZBWSYKWUMUTEAZYBLMBDSXMCXJGCNDMHKRBIFYJWUDPVVZXDTFLHSPUAIUBQQJOYMTZIJXTJDQTONHTACYVOTBMRZEJFOLJWRHFGXORFBSUPPFEHQDKYVHRIMAKNAIWJNKZIKIZEPWRCYXHEUVILWGGAHQLDVTROGYFERSBCUZW");
    msg.description.assign("XFMAHNKLGDJBDPSVOYEFOGWLISSZUGHSZTKXHQZHYKXIVEMUMJOIXKCMNNUUQRXEBULNWVHXJNEKZFITGYJWRZQZNLQHFGBPXMPDEYFEVZKCPQPRWWUDAPVZBNFBOZTMMJIANDIOWVQBKVVLMLTXYVNGBICSYCHSXEDKANOITFTWECTCRGEDLHGLCTALYSAAAMPUUQW");
    msg.leader_speed = 0.20819453554183276;
    msg.leader_bank_lim = 0.6714612000165437;
    msg.pos_sim_err_lim = 0.17406435897332773;
    msg.pos_sim_err_wrn = 0.906681652952214;
    msg.pos_sim_err_timeout = 57202U;
    msg.converg_max = 0.7211630994201482;
    msg.converg_timeout = 51915U;
    msg.comms_timeout = 2532U;
    msg.turb_lim = 0.5830526935398045;
    msg.custom.assign("HUPTWIGWVGEQKFGTKPGJTJWCFXDURDTUVVYVPBJFXTJNWXTIZQMXDTSPDNJZXCFLQXVABWROAATAMBUOLCIYEIKGDCCONOISONAQZFOKOQPVGUSEJUFWCJSLEVQMYISEGILUXQCRZIBIZXHKHWUCOSQRLHQFKPTOBSEYYYVEKPRTEYSGRDAKN");

    try
    {
      Utils::ByteBuffer bfr;
      IMC::Packet::serialize(&msg, bfr);
      IMC::Message* msg_d = IMC::Packet::deserialize(bfr.getBuffer(), bfr.getSize());
      test.boolean("FormationPlanExecution #1", msg == *msg_d);
      delete msg_d;
    }
    catch (IMC::InvalidMessageSize& e)
    {
      (void)e;
      test.boolean("msg #1", msg.getSerializationSize() > DUNE_IMC_CONST_MAX_SIZE);
    }
  }

  {
    IMC::FormationPlanExecution msg;
    msg.setTimeStamp(0.9413641642562596);
    msg.setSource(12951U);
    msg.setSourceEntity(249U);
    msg.setDestination(40143U);
    msg.setDestinationEntity(190U);
    msg.group_name.assign("TRJVJYNNLLKJDEPEJOXLMMWPRCJIPUQVFPWILDTBZ");
    msg.formation_name.assign("POXXAUTZCPHAHZIRIOIJLMVLBFYIGEEWOVZYAUOELFSEUQNRUNEWCYJGQJVEYVDWQMFPXWWBVSVTVAMVMOKZEYSAGBJDHTXDOBDBTPWYCSIZGYVINDDRYQNWOFKCHZZRQTUJMCXMIFCDLXCGKQSBUYONBJPNBAEHLNGIWMSQNKCPRHLGTKFJQUMQTADPKMPINU");
    msg.plan_id.assign("SSCDQNHCHJBBDCVUVZFAGEDKIOONVGPRGOJWIOWOWMRYGYXDXWUSCKEWXLRXLAODZDPRSRIEHFLCLNWYKM");
    msg.description.assign("RXKLVTXZFIKWBJZPR");
    msg.leader_speed = 0.9580296042317238;
    msg.leader_bank_lim = 0.08115828296172622;
    msg.pos_sim_err_lim = 0.1024995430461505;
    msg.pos_sim_err_wrn = 0.6645756717048437;
    msg.pos_sim_err_timeout = 44206U;
    msg.converg_max = 0.3347084640085093;
    msg.converg_timeout = 24581U;
    msg.comms_timeout = 28081U;
    msg.turb_lim = 0.9863852821789479;
    msg.custom.assign("PKOUKDTILZDNQHTUAAHBSYUYYFJCDURXVXG");

    try
    {
      Utils::ByteBuffer bfr;
      IMC::Packet::serialize(&msg, bfr);
      IMC::Message* msg_d = IMC::Packet::deserialize(bfr.getBuffer(), bfr.getSize());
      test.boolean("FormationPlanExecution #2", msg == *msg_d);
      delete msg_d;
    }
    catch (IMC::InvalidMessageSize& e)
    {
      (void)e;
      test.boolean("msg #2", msg.getSerializationSize() > DUNE_IMC_CONST_MAX_SIZE);
    }
  }

  {
    IMC::FollowReference msg;
    msg.setTimeStamp(0.7910479682948842);
    msg.setSource(643U);
    msg.setSourceEntity(91U);
    msg.setDestination(45558U);
    msg.setDestinationEntity(244U);
    msg.control_src = 29863U;
    msg.control_ent = 243U;
    msg.timeout = 0.13589952476889666;
    msg.loiter_radius = 0.03715393338093398;
    msg.altitude_interval = 0.1889033460774675;

    try
    {
      Utils::ByteBuffer bfr;
      IMC::Packet::serialize(&msg, bfr);
      IMC::Message* msg_d = IMC::Packet::deserialize(bfr.getBuffer(), bfr.getSize());
      test.boolean("FollowReference #0", msg == *msg_d);
      delete msg_d;
    }
    catch (IMC::InvalidMessageSize& e)
    {
      (void)e;
      test.boolean("msg #0", msg.getSerializationSize() > DUNE_IMC_CONST_MAX_SIZE);
    }
  }

  {
    IMC::FollowReference msg;
    msg.setTimeStamp(0.22924023248508052);
    msg.setSource(41764U);
    msg.setSourceEntity(248U);
    msg.setDestination(3422U);
    msg.setDestinationEntity(139U);
    msg.control_src = 29193U;
    msg.control_ent = 11U;
    msg.timeout = 0.6340760359964334;
    msg.loiter_radius = 0.47960705237927825;
    msg.altitude_interval = 0.7715459797981643;

    try
    {
      Utils::ByteBuffer bfr;
      IMC::Packet::serialize(&msg, bfr);
      IMC::Message* msg_d = IMC::Packet::deserialize(bfr.getBuffer(), bfr.getSize());
      test.boolean("FollowReference #1", msg == *msg_d);
      delete msg_d;
    }
    catch (IMC::InvalidMessageSize& e)
    {
      (void)e;
      test.boolean("msg #1", msg.getSerializationSize() > DUNE_IMC_CONST_MAX_SIZE);
    }
  }

  {
    IMC::FollowReference msg;
    msg.setTimeStamp(0.8294995886901947);
    msg.setSource(52218U);
    msg.setSourceEntity(9U);
    msg.setDestination(47248U);
    msg.setDestinationEntity(149U);
    msg.control_src = 62426U;
    msg.control_ent = 230U;
    msg.timeout = 0.9520933994681156;
    msg.loiter_radius = 0.8354368796340761;
    msg.altitude_interval = 0.2773244471657834;

    try
    {
      Utils::ByteBuffer bfr;
      IMC::Packet::serialize(&msg, bfr);
      IMC::Message* msg_d = IMC::Packet::deserialize(bfr.getBuffer(), bfr.getSize());
      test.boolean("FollowReference #2", msg == *msg_d);
      delete msg_d;
    }
    catch (IMC::InvalidMessageSize& e)
    {
      (void)e;
      test.boolean("msg #2", msg.getSerializationSize() > DUNE_IMC_CONST_MAX_SIZE);
    }
  }

  {
    IMC::Reference msg;
    msg.setTimeStamp(0.4038328685549688);
    msg.setSource(53379U);
    msg.setSourceEntity(102U);
    msg.setDestination(58794U);
    msg.setDestinationEntity(1U);
    msg.flags = 20U;
    IMC::DesiredSpeed tmp_msg_0;
    tmp_msg_0.value = 0.4357027096386745;
    tmp_msg_0.speed_units = 210U;
    msg.speed.set(tmp_msg_0);
    IMC::DesiredZ tmp_msg_1;
    tmp_msg_1.value = 0.983947044999883;
    tmp_msg_1.z_units = 172U;
    msg.z.set(tmp_msg_1);
    msg.lat = 0.4096731477086937;
    msg.lon = 0.5517023679595987;
    msg.radius = 0.1606584830029656;

    try
    {
      Utils::ByteBuffer bfr;
      IMC::Packet::serialize(&msg, bfr);
      IMC::Message* msg_d = IMC::Packet::deserialize(bfr.getBuffer(), bfr.getSize());
      test.boolean("Reference #0", msg == *msg_d);
      delete msg_d;
    }
    catch (IMC::InvalidMessageSize& e)
    {
      (void)e;
      test.boolean("msg #0", msg.getSerializationSize() > DUNE_IMC_CONST_MAX_SIZE);
    }
  }

  {
    IMC::Reference msg;
    msg.setTimeStamp(0.05982904299994796);
    msg.setSource(21408U);
    msg.setSourceEntity(127U);
    msg.setDestination(60309U);
    msg.setDestinationEntity(58U);
    msg.flags = 220U;
    IMC::DesiredSpeed tmp_msg_0;
    tmp_msg_0.value = 0.18733404537884069;
    tmp_msg_0.speed_units = 65U;
    msg.speed.set(tmp_msg_0);
    IMC::DesiredZ tmp_msg_1;
    tmp_msg_1.value = 0.02615576409138487;
    tmp_msg_1.z_units = 135U;
    msg.z.set(tmp_msg_1);
    msg.lat = 0.2587824899267812;
    msg.lon = 0.3277386029421083;
    msg.radius = 0.6508147034874958;

    try
    {
      Utils::ByteBuffer bfr;
      IMC::Packet::serialize(&msg, bfr);
      IMC::Message* msg_d = IMC::Packet::deserialize(bfr.getBuffer(), bfr.getSize());
      test.boolean("Reference #1", msg == *msg_d);
      delete msg_d;
    }
    catch (IMC::InvalidMessageSize& e)
    {
      (void)e;
      test.boolean("msg #1", msg.getSerializationSize() > DUNE_IMC_CONST_MAX_SIZE);
    }
  }

  {
    IMC::Reference msg;
    msg.setTimeStamp(0.6887147048747984);
    msg.setSource(8382U);
    msg.setSourceEntity(73U);
    msg.setDestination(49605U);
    msg.setDestinationEntity(182U);
    msg.flags = 72U;
    IMC::DesiredSpeed tmp_msg_0;
    tmp_msg_0.value = 0.36631454544894815;
    tmp_msg_0.speed_units = 186U;
    msg.speed.set(tmp_msg_0);
    IMC::DesiredZ tmp_msg_1;
    tmp_msg_1.value = 0.6748911158108589;
    tmp_msg_1.z_units = 47U;
    msg.z.set(tmp_msg_1);
    msg.lat = 0.6951681415773273;
    msg.lon = 0.08212496766881516;
    msg.radius = 0.20107684041169027;

    try
    {
      Utils::ByteBuffer bfr;
      IMC::Packet::serialize(&msg, bfr);
      IMC::Message* msg_d = IMC::Packet::deserialize(bfr.getBuffer(), bfr.getSize());
      test.boolean("Reference #2", msg == *msg_d);
      delete msg_d;
    }
    catch (IMC::InvalidMessageSize& e)
    {
      (void)e;
      test.boolean("msg #2", msg.getSerializationSize() > DUNE_IMC_CONST_MAX_SIZE);
    }
  }

  {
    IMC::FollowRefState msg;
    msg.setTimeStamp(0.21975278442730395);
    msg.setSource(19299U);
    msg.setSourceEntity(230U);
    msg.setDestination(32011U);
    msg.setDestinationEntity(124U);
    msg.control_src = 101U;
    msg.control_ent = 168U;
    IMC::Reference tmp_msg_0;
    tmp_msg_0.flags = 229U;
    IMC::DesiredSpeed tmp_tmp_msg_0_0;
    tmp_tmp_msg_0_0.value = 0.06657519597392925;
    tmp_tmp_msg_0_0.speed_units = 127U;
    tmp_msg_0.speed.set(tmp_tmp_msg_0_0);
    IMC::DesiredZ tmp_tmp_msg_0_1;
    tmp_tmp_msg_0_1.value = 0.08716298737796657;
    tmp_tmp_msg_0_1.z_units = 43U;
    tmp_msg_0.z.set(tmp_tmp_msg_0_1);
    tmp_msg_0.lat = 0.2296711996981583;
    tmp_msg_0.lon = 0.18650681201282449;
    tmp_msg_0.radius = 0.2124365575595739;
    msg.reference.set(tmp_msg_0);
    msg.state = 198U;
    msg.proximity = 8U;

    try
    {
      Utils::ByteBuffer bfr;
      IMC::Packet::serialize(&msg, bfr);
      IMC::Message* msg_d = IMC::Packet::deserialize(bfr.getBuffer(), bfr.getSize());
      test.boolean("FollowRefState #0", msg == *msg_d);
      delete msg_d;
    }
    catch (IMC::InvalidMessageSize& e)
    {
      (void)e;
      test.boolean("msg #0", msg.getSerializationSize() > DUNE_IMC_CONST_MAX_SIZE);
    }
  }

  {
    IMC::FollowRefState msg;
    msg.setTimeStamp(0.5898762827676172);
    msg.setSource(61053U);
    msg.setSourceEntity(236U);
    msg.setDestination(385U);
    msg.setDestinationEntity(229U);
    msg.control_src = 63686U;
    msg.control_ent = 199U;
    IMC::Reference tmp_msg_0;
    tmp_msg_0.flags = 102U;
    IMC::DesiredSpeed tmp_tmp_msg_0_0;
    tmp_tmp_msg_0_0.value = 0.8739808179992139;
    tmp_tmp_msg_0_0.speed_units = 16U;
    tmp_msg_0.speed.set(tmp_tmp_msg_0_0);
    IMC::DesiredZ tmp_tmp_msg_0_1;
    tmp_tmp_msg_0_1.value = 0.430348084401046;
    tmp_tmp_msg_0_1.z_units = 174U;
    tmp_msg_0.z.set(tmp_tmp_msg_0_1);
    tmp_msg_0.lat = 0.037765381711060586;
    tmp_msg_0.lon = 0.11541649356040373;
    tmp_msg_0.radius = 0.6580459711192637;
    msg.reference.set(tmp_msg_0);
    msg.state = 68U;
    msg.proximity = 53U;

    try
    {
      Utils::ByteBuffer bfr;
      IMC::Packet::serialize(&msg, bfr);
      IMC::Message* msg_d = IMC::Packet::deserialize(bfr.getBuffer(), bfr.getSize());
      test.boolean("FollowRefState #1", msg == *msg_d);
      delete msg_d;
    }
    catch (IMC::InvalidMessageSize& e)
    {
      (void)e;
      test.boolean("msg #1", msg.getSerializationSize() > DUNE_IMC_CONST_MAX_SIZE);
    }
  }

  {
    IMC::FollowRefState msg;
    msg.setTimeStamp(0.05513289594694015);
    msg.setSource(12539U);
    msg.setSourceEntity(223U);
    msg.setDestination(32080U);
    msg.setDestinationEntity(39U);
    msg.control_src = 31576U;
    msg.control_ent = 139U;
    IMC::Reference tmp_msg_0;
    tmp_msg_0.flags = 86U;
    IMC::DesiredSpeed tmp_tmp_msg_0_0;
    tmp_tmp_msg_0_0.value = 0.24028676494133627;
    tmp_tmp_msg_0_0.speed_units = 77U;
    tmp_msg_0.speed.set(tmp_tmp_msg_0_0);
    IMC::DesiredZ tmp_tmp_msg_0_1;
    tmp_tmp_msg_0_1.value = 0.28286767601870766;
    tmp_tmp_msg_0_1.z_units = 19U;
    tmp_msg_0.z.set(tmp_tmp_msg_0_1);
    tmp_msg_0.lat = 0.4048899433713862;
    tmp_msg_0.lon = 0.15517422967332428;
    tmp_msg_0.radius = 0.04565086127477247;
    msg.reference.set(tmp_msg_0);
    msg.state = 239U;
    msg.proximity = 72U;

    try
    {
      Utils::ByteBuffer bfr;
      IMC::Packet::serialize(&msg, bfr);
      IMC::Message* msg_d = IMC::Packet::deserialize(bfr.getBuffer(), bfr.getSize());
      test.boolean("FollowRefState #2", msg == *msg_d);
      delete msg_d;
    }
    catch (IMC::InvalidMessageSize& e)
    {
      (void)e;
      test.boolean("msg #2", msg.getSerializationSize() > DUNE_IMC_CONST_MAX_SIZE);
    }
  }

  {
    IMC::FormationMonitor msg;
    msg.setTimeStamp(0.7612470083361492);
    msg.setSource(43979U);
    msg.setSourceEntity(55U);
    msg.setDestination(53730U);
    msg.setDestinationEntity(10U);
    msg.ax_cmd = 0.5890327072402561;
    msg.ay_cmd = 0.8724526105516274;
    msg.az_cmd = 0.12781244460761632;
    msg.ax_des = 0.20612908858351242;
    msg.ay_des = 0.6296056708535568;
    msg.az_des = 0.7039571807768017;
    msg.virt_err_x = 0.49802242326061974;
    msg.virt_err_y = 0.7891570004452584;
    msg.virt_err_z = 0.4950985211281539;
    msg.surf_fdbk_x = 0.6407686530113361;
    msg.surf_fdbk_y = 0.44092722098556314;
    msg.surf_fdbk_z = 0.7474294262560561;
    msg.surf_unkn_x = 0.5536347534798659;
    msg.surf_unkn_y = 0.986753258138465;
    msg.surf_unkn_z = 0.41659096768641757;
    msg.ss_x = 0.30602637524260023;
    msg.ss_y = 0.5757796771960078;
    msg.ss_z = 0.14589914070485954;

    try
    {
      Utils::ByteBuffer bfr;
      IMC::Packet::serialize(&msg, bfr);
      IMC::Message* msg_d = IMC::Packet::deserialize(bfr.getBuffer(), bfr.getSize());
      test.boolean("FormationMonitor #0", msg == *msg_d);
      delete msg_d;
    }
    catch (IMC::InvalidMessageSize& e)
    {
      (void)e;
      test.boolean("msg #0", msg.getSerializationSize() > DUNE_IMC_CONST_MAX_SIZE);
    }
  }

  {
    IMC::FormationMonitor msg;
    msg.setTimeStamp(0.24429394954867578);
    msg.setSource(62362U);
    msg.setSourceEntity(239U);
    msg.setDestination(56175U);
    msg.setDestinationEntity(72U);
    msg.ax_cmd = 0.32162309523276456;
    msg.ay_cmd = 0.7686921894490408;
    msg.az_cmd = 0.7875537623674079;
    msg.ax_des = 0.47876713498696555;
    msg.ay_des = 0.9805131775505505;
    msg.az_des = 0.9917882848715612;
    msg.virt_err_x = 0.6439231334443071;
    msg.virt_err_y = 0.8966422804115932;
    msg.virt_err_z = 0.5427638757214224;
    msg.surf_fdbk_x = 0.49799373996003504;
    msg.surf_fdbk_y = 0.24436906410237424;
    msg.surf_fdbk_z = 0.9733337344700004;
    msg.surf_unkn_x = 0.7817302592861267;
    msg.surf_unkn_y = 0.5314077289833157;
    msg.surf_unkn_z = 0.5211200551502564;
    msg.ss_x = 0.5233105283727207;
    msg.ss_y = 0.8534631628848048;
    msg.ss_z = 0.9934242992394022;
    IMC::RelativeState tmp_msg_0;
    tmp_msg_0.s_id.assign("ZQYCCZRHRAILXPWRJOHJPRMAUUKOUEJTZXYOLNFHHPTSTIPBJXLZTZVVMKOPXXEDSKSMBAIMDDTHEVQATHNUMVFIGQKHGZLYRVXGWFCFMDLFRDCUJDLUWNNABDMEKQDNSERYEWKOGOBLTJREZGPDQLFVWSLGZBQATYQAIDTXHCAXSSGWPCTHUCOICNVBPCSYOMVJJFJWAGUYVFICORPQQNNFWIGEE");
    tmp_msg_0.dist = 0.8397669265892154;
    tmp_msg_0.err = 0.6669768824543765;
    tmp_msg_0.ctrl_imp = 0.2527006379970228;
    tmp_msg_0.rel_dir_x = 0.10102558831332942;
    tmp_msg_0.rel_dir_y = 0.9079285871252547;
    tmp_msg_0.rel_dir_z = 0.697622351694269;
    tmp_msg_0.err_x = 0.09992390466189083;
    tmp_msg_0.err_y = 0.8227874393545055;
    tmp_msg_0.err_z = 0.4381047633544195;
    tmp_msg_0.rf_err_x = 0.8282792219404923;
    tmp_msg_0.rf_err_y = 0.5897071068591303;
    tmp_msg_0.rf_err_z = 0.0020877212372861775;
    tmp_msg_0.rf_err_vx = 0.7577716401666063;
    tmp_msg_0.rf_err_vy = 0.10209912717235192;
    tmp_msg_0.rf_err_vz = 0.791514162567123;
    tmp_msg_0.ss_x = 0.5900578136878829;
    tmp_msg_0.ss_y = 0.05163313116926205;
    tmp_msg_0.ss_z = 0.16718984696003958;
    tmp_msg_0.virt_err_x = 0.7455539002385493;
    tmp_msg_0.virt_err_y = 0.7520152537933609;
    tmp_msg_0.virt_err_z = 0.8669943889839786;
    msg.rel_state.push_back(tmp_msg_0);

    try
    {
      Utils::ByteBuffer bfr;
      IMC::Packet::serialize(&msg, bfr);
      IMC::Message* msg_d = IMC::Packet::deserialize(bfr.getBuffer(), bfr.getSize());
      test.boolean("FormationMonitor #1", msg == *msg_d);
      delete msg_d;
    }
    catch (IMC::InvalidMessageSize& e)
    {
      (void)e;
      test.boolean("msg #1", msg.getSerializationSize() > DUNE_IMC_CONST_MAX_SIZE);
    }
  }

  {
    IMC::FormationMonitor msg;
    msg.setTimeStamp(0.9788235984292666);
    msg.setSource(10279U);
    msg.setSourceEntity(127U);
    msg.setDestination(58360U);
    msg.setDestinationEntity(254U);
    msg.ax_cmd = 0.9358567480012944;
    msg.ay_cmd = 0.9349532023722839;
    msg.az_cmd = 0.35840477945920823;
    msg.ax_des = 0.6478224856333498;
    msg.ay_des = 0.376072222360082;
    msg.az_des = 0.5340549959467803;
    msg.virt_err_x = 0.5276644745313537;
    msg.virt_err_y = 0.4902601222204711;
    msg.virt_err_z = 0.24411419512640886;
    msg.surf_fdbk_x = 0.2468095502733082;
    msg.surf_fdbk_y = 0.21556615522887967;
    msg.surf_fdbk_z = 0.39327830088761817;
    msg.surf_unkn_x = 0.6240364833961818;
    msg.surf_unkn_y = 0.40321972327803;
    msg.surf_unkn_z = 0.23469122526274488;
    msg.ss_x = 0.7764614246334056;
    msg.ss_y = 0.4217450462981073;
    msg.ss_z = 0.8938454744766066;
    IMC::RelativeState tmp_msg_0;
    tmp_msg_0.s_id.assign("EACTOUVCCZRDLXHDDOPNQHULPGLEWQEURBLWRGVWLYPMLPPTPGIXAWDHGSHYPKRQTINCDEXKKGIXADVDBSMCNPZVWARYZHAMEYBFXRSLBJHNWHUFSHKSRIFQMUYEFOGYWGCMTPNNTECSOTSUDIJZETXVZGKUYVRBVHZQNTQSQFCBJOKSIBMFCJCIDGHOXLGJFFWWMBUOJOFAZBXNVQOAJVZKOENKAUWKZYI");
    tmp_msg_0.dist = 0.1849608397207615;
    tmp_msg_0.err = 0.8774993876049075;
    tmp_msg_0.ctrl_imp = 0.801592254206083;
    tmp_msg_0.rel_dir_x = 0.045090224171451254;
    tmp_msg_0.rel_dir_y = 0.10051112047009525;
    tmp_msg_0.rel_dir_z = 0.21535441512956743;
    tmp_msg_0.err_x = 0.49060699252958806;
    tmp_msg_0.err_y = 0.7416492962861299;
    tmp_msg_0.err_z = 0.8284859973878039;
    tmp_msg_0.rf_err_x = 0.9476117108968497;
    tmp_msg_0.rf_err_y = 0.5908916822266893;
    tmp_msg_0.rf_err_z = 0.5019626383451378;
    tmp_msg_0.rf_err_vx = 0.8150619307488488;
    tmp_msg_0.rf_err_vy = 0.6911959307344324;
    tmp_msg_0.rf_err_vz = 0.20962232878604858;
    tmp_msg_0.ss_x = 0.6370176027072819;
    tmp_msg_0.ss_y = 0.4015400709918774;
    tmp_msg_0.ss_z = 0.8004188091746894;
    tmp_msg_0.virt_err_x = 0.141271300206669;
    tmp_msg_0.virt_err_y = 0.9447934828053397;
    tmp_msg_0.virt_err_z = 0.6891656296826303;
    msg.rel_state.push_back(tmp_msg_0);

    try
    {
      Utils::ByteBuffer bfr;
      IMC::Packet::serialize(&msg, bfr);
      IMC::Message* msg_d = IMC::Packet::deserialize(bfr.getBuffer(), bfr.getSize());
      test.boolean("FormationMonitor #2", msg == *msg_d);
      delete msg_d;
    }
    catch (IMC::InvalidMessageSize& e)
    {
      (void)e;
      test.boolean("msg #2", msg.getSerializationSize() > DUNE_IMC_CONST_MAX_SIZE);
    }
  }

  {
    IMC::RelativeState msg;
    msg.setTimeStamp(0.5291362192268616);
    msg.setSource(65161U);
    msg.setSourceEntity(126U);
    msg.setDestination(6401U);
    msg.setDestinationEntity(204U);
    msg.s_id.assign("ZWMAOHCGMBDYQYMWWQCHAZZUZPXBUFUXTNZOMPBFIIQCRDMUJMVPMGVGTDFRJOKBKWMAVWUWOXKAZXNNQPAHBHFKAXVSTYCDHUBAQNRSVZJVLWPKJSJDYPZYDRCKLHEQHYJBPGNCNOYTAIYEGDWALGEJFSLRESITMEETQIVPKFKVCWEJXSXEEWDILMPTUDISLYRYLOIUSZSTUFGQBRRKJCXZXA");
    msg.dist = 0.581135417428222;
    msg.err = 0.6423729932217567;
    msg.ctrl_imp = 0.8889270312718454;
    msg.rel_dir_x = 0.354166284026607;
    msg.rel_dir_y = 0.7107723105815426;
    msg.rel_dir_z = 0.900022970680219;
    msg.err_x = 0.9657738598763352;
    msg.err_y = 0.28425185313825985;
    msg.err_z = 0.5697653059758262;
    msg.rf_err_x = 0.5267647457779866;
    msg.rf_err_y = 0.05592193123472655;
    msg.rf_err_z = 0.5934514856600079;
    msg.rf_err_vx = 0.459942300646496;
    msg.rf_err_vy = 0.7492845379206847;
    msg.rf_err_vz = 0.7221377731728118;
    msg.ss_x = 0.3612592367488372;
    msg.ss_y = 0.5750428811869557;
    msg.ss_z = 0.6944100862058018;
    msg.virt_err_x = 0.7726856422560857;
    msg.virt_err_y = 0.6844568203296615;
    msg.virt_err_z = 0.6416849151106426;

    try
    {
      Utils::ByteBuffer bfr;
      IMC::Packet::serialize(&msg, bfr);
      IMC::Message* msg_d = IMC::Packet::deserialize(bfr.getBuffer(), bfr.getSize());
      test.boolean("RelativeState #0", msg == *msg_d);
      delete msg_d;
    }
    catch (IMC::InvalidMessageSize& e)
    {
      (void)e;
      test.boolean("msg #0", msg.getSerializationSize() > DUNE_IMC_CONST_MAX_SIZE);
    }
  }

  {
    IMC::RelativeState msg;
    msg.setTimeStamp(0.28557689030001254);
    msg.setSource(33078U);
    msg.setSourceEntity(9U);
    msg.setDestination(49186U);
    msg.setDestinationEntity(39U);
    msg.s_id.assign("SOKSVCTUYHSWYTMIQDMCZZFUXHWK");
    msg.dist = 0.17352593581747766;
    msg.err = 0.6795294580767247;
    msg.ctrl_imp = 0.04401830840858534;
    msg.rel_dir_x = 0.7202059131374905;
    msg.rel_dir_y = 0.1443344576693022;
    msg.rel_dir_z = 0.6189829348603999;
    msg.err_x = 0.11691431628967652;
    msg.err_y = 0.8859111790659367;
    msg.err_z = 0.28462798584158056;
    msg.rf_err_x = 0.8181960129575548;
    msg.rf_err_y = 0.22507768186281762;
    msg.rf_err_z = 0.9759994119825285;
    msg.rf_err_vx = 0.803382466437569;
    msg.rf_err_vy = 0.43516184850869943;
    msg.rf_err_vz = 0.6611070632080264;
    msg.ss_x = 0.31364443498935846;
    msg.ss_y = 0.2242717030963014;
    msg.ss_z = 0.25396545754052857;
    msg.virt_err_x = 0.6051892499560135;
    msg.virt_err_y = 0.7420643539349892;
    msg.virt_err_z = 0.027907606423556608;

    try
    {
      Utils::ByteBuffer bfr;
      IMC::Packet::serialize(&msg, bfr);
      IMC::Message* msg_d = IMC::Packet::deserialize(bfr.getBuffer(), bfr.getSize());
      test.boolean("RelativeState #1", msg == *msg_d);
      delete msg_d;
    }
    catch (IMC::InvalidMessageSize& e)
    {
      (void)e;
      test.boolean("msg #1", msg.getSerializationSize() > DUNE_IMC_CONST_MAX_SIZE);
    }
  }

  {
    IMC::RelativeState msg;
    msg.setTimeStamp(0.0573301450876289);
    msg.setSource(45373U);
    msg.setSourceEntity(241U);
    msg.setDestination(8039U);
    msg.setDestinationEntity(16U);
    msg.s_id.assign("MAHZHWFOBLKPDQKVLXW");
    msg.dist = 0.932766417948441;
    msg.err = 0.1705361478957329;
    msg.ctrl_imp = 0.23622194817976094;
    msg.rel_dir_x = 0.11674497726889566;
    msg.rel_dir_y = 0.7942926273041151;
    msg.rel_dir_z = 0.17471317129683728;
    msg.err_x = 0.06568861768185574;
    msg.err_y = 0.2734977099478718;
    msg.err_z = 0.8764102629255583;
    msg.rf_err_x = 0.2137504369913763;
    msg.rf_err_y = 0.6105204158990062;
    msg.rf_err_z = 0.8399010674728538;
    msg.rf_err_vx = 0.8545594468948582;
    msg.rf_err_vy = 0.45953328480563205;
    msg.rf_err_vz = 0.9344712763231496;
    msg.ss_x = 0.010474734935943752;
    msg.ss_y = 0.5229967653083901;
    msg.ss_z = 0.12900710989028397;
    msg.virt_err_x = 0.3774102093672147;
    msg.virt_err_y = 0.24815474065498422;
    msg.virt_err_z = 0.5840784041053609;

    try
    {
      Utils::ByteBuffer bfr;
      IMC::Packet::serialize(&msg, bfr);
      IMC::Message* msg_d = IMC::Packet::deserialize(bfr.getBuffer(), bfr.getSize());
      test.boolean("RelativeState #2", msg == *msg_d);
      delete msg_d;
    }
    catch (IMC::InvalidMessageSize& e)
    {
      (void)e;
      test.boolean("msg #2", msg.getSerializationSize() > DUNE_IMC_CONST_MAX_SIZE);
    }
  }

  {
    IMC::Dislodge msg;
    msg.setTimeStamp(0.2413941469025892);
    msg.setSource(1644U);
    msg.setSourceEntity(123U);
    msg.setDestination(45924U);
    msg.setDestinationEntity(36U);
    msg.timeout = 197U;
    msg.rpm = 0.5329705481951361;
    msg.direction = 140U;
    msg.custom.assign("YWAVUNPHQLKJNPXCZRQDPGBQPUQCJSRXDRMYNGBZGJEPWWIIEXGQAWETRKZGQMLAZZT");

    try
    {
      Utils::ByteBuffer bfr;
      IMC::Packet::serialize(&msg, bfr);
      IMC::Message* msg_d = IMC::Packet::deserialize(bfr.getBuffer(), bfr.getSize());
      test.boolean("Dislodge #0", msg == *msg_d);
      delete msg_d;
    }
    catch (IMC::InvalidMessageSize& e)
    {
      (void)e;
      test.boolean("msg #0", msg.getSerializationSize() > DUNE_IMC_CONST_MAX_SIZE);
    }
  }

  {
    IMC::Dislodge msg;
    msg.setTimeStamp(0.5488905625263883);
    msg.setSource(32768U);
    msg.setSourceEntity(66U);
    msg.setDestination(45807U);
    msg.setDestinationEntity(75U);
    msg.timeout = 38934U;
    msg.rpm = 0.8053936591541314;
    msg.direction = 241U;
    msg.custom.assign("EKEFKFIWBOWPZRAMMZQXLTRMGBDKOGTHMGWIJODJPHAWPAGSARSSKSRICWYEPVMUFHSCORHNYEKTMCDRPJKVOXAQXMOCCVTJBFBJFNIYNTVUGYIIHDCJVZUQWDSYTYDXLUEVRTLPBAXQNLBWUFXLVNDIKKXPZFRZSBXNFSQAUCKQUYGQDXENTZAWCZDQPAZHHPVEEJQONHHAYHRMNWLMSDJIBS");

    try
    {
      Utils::ByteBuffer bfr;
      IMC::Packet::serialize(&msg, bfr);
      IMC::Message* msg_d = IMC::Packet::deserialize(bfr.getBuffer(), bfr.getSize());
      test.boolean("Dislodge #1", msg == *msg_d);
      delete msg_d;
    }
    catch (IMC::InvalidMessageSize& e)
    {
      (void)e;
      test.boolean("msg #1", msg.getSerializationSize() > DUNE_IMC_CONST_MAX_SIZE);
    }
  }

  {
    IMC::Dislodge msg;
    msg.setTimeStamp(0.9635274500334027);
    msg.setSource(24686U);
    msg.setSourceEntity(202U);
    msg.setDestination(59641U);
    msg.setDestinationEntity(47U);
    msg.timeout = 35476U;
    msg.rpm = 0.7106804642568135;
    msg.direction = 93U;
    msg.custom.assign("KIKLLWOQRSSBYEHTIUBFTNSUWUKFKXYRXJMUZUUUHQCQXQNMZMCHWPMGNWOSOPDLDEDZRFKPAYTEXBWOAHEXVETJDYJZRGBVCLAKBEOMPHZAVVZQVPCUEQTGNMKXXQMHLMZFNTRNGNDTYI");

    try
    {
      Utils::ByteBuffer bfr;
      IMC::Packet::serialize(&msg, bfr);
      IMC::Message* msg_d = IMC::Packet::deserialize(bfr.getBuffer(), bfr.getSize());
      test.boolean("Dislodge #2", msg == *msg_d);
      delete msg_d;
    }
    catch (IMC::InvalidMessageSize& e)
    {
      (void)e;
      test.boolean("msg #2", msg.getSerializationSize() > DUNE_IMC_CONST_MAX_SIZE);
    }
  }

  {
    IMC::Formation msg;
    msg.setTimeStamp(0.9702609007689563);
    msg.setSource(14327U);
    msg.setSourceEntity(19U);
    msg.setDestination(26735U);
    msg.setDestinationEntity(138U);
    msg.formation_name.assign("PZPSBRYFVTYGIHLRHGSATQYMZFBTJWVDUQBLXLBOIOXCBMXBITNJCFAIPVEIHKJQGEUCJDFGGWKDSNNMYOQMUXKKOARJVHAXFPSWVQ");
    msg.type = 119U;
    msg.op = 112U;
    msg.group_name.assign("BZDYGDRCWROEOQRLTILGKIQFKUCDTLYSLTKKKGTTBBHBNKFOHNESPDXWIJCAABKSEVV");
    msg.plan_id.assign("DHBMLWJHUGMWNUAMATTSHMKQPERWVBFXLUGKPFPQHUCZBNIBGCIVKKXVQNPJYQNWENDZJYTSKPWOWYYRXZEFYNGOVEEONTDTRJLJNOR");
    msg.description.assign("ARXMICDQCJ");
    msg.reference_frame = 216U;
    msg.leader_bank_lim = 0.5309509631658916;
    msg.leader_speed_min = 0.15269409981099968;
    msg.leader_speed_max = 0.2615279881100716;
    msg.leader_alt_min = 0.3219302382613669;
    msg.leader_alt_max = 0.39248336758998437;
    msg.pos_sim_err_lim = 0.16353708919876353;
    msg.pos_sim_err_wrn = 0.4951410514601594;
    msg.pos_sim_err_timeout = 17676U;
    msg.converg_max = 0.6156973517671327;
    msg.converg_timeout = 22222U;
    msg.comms_timeout = 50295U;
    msg.turb_lim = 0.4177576541379153;
    msg.custom.assign("WXACDWKABYAYFRUIEFFSNZHNSNQTAFJWXKLEGWVOZQFOLPTOVZFTLIBBNOAYSBIIEWSSRISUHDDDMUVFRMHGLTKANRPTOOUTVNXPLEUY");

    try
    {
      Utils::ByteBuffer bfr;
      IMC::Packet::serialize(&msg, bfr);
      IMC::Message* msg_d = IMC::Packet::deserialize(bfr.getBuffer(), bfr.getSize());
      test.boolean("Formation #0", msg == *msg_d);
      delete msg_d;
    }
    catch (IMC::InvalidMessageSize& e)
    {
      (void)e;
      test.boolean("msg #0", msg.getSerializationSize() > DUNE_IMC_CONST_MAX_SIZE);
    }
  }

  {
    IMC::Formation msg;
    msg.setTimeStamp(0.20541007311784543);
    msg.setSource(53384U);
    msg.setSourceEntity(152U);
    msg.setDestination(39397U);
    msg.setDestinationEntity(186U);
    msg.formation_name.assign("UREEICGARVTZTNWUUZBHGPVJGBPTZVXFFXOQOCSBGCALPBTXSH");
    msg.type = 92U;
    msg.op = 2U;
    msg.group_name.assign("TKXYUOVVLMNFPEEFPKJLLXKMYFXPSVXGFWDXWGAEHUNTIXLTGCQSRZKTJPRJIICWFLRLCIQYTZUYRLGQANXHLFNIUIBDVVLANCBGDBBNFHBOOHPZAEKZFJAROESIOYMDQHWNMQADECJBUWXPIGGDJAOGJOOUKHD");
    msg.plan_id.assign("MLMEILRTWQYHCALLXYQODGVDNYBDWRPBKGWFWJZECPPWDVSHBSNTV");
    msg.description.assign("HRHKSWOIJDBMXKBONIUAFLEMKY");
    msg.reference_frame = 251U;
    IMC::VehicleFormationParticipant tmp_msg_0;
    tmp_msg_0.vid = 32173U;
    tmp_msg_0.off_x = 0.35922735061214917;
    tmp_msg_0.off_y = 0.3163802206098948;
    tmp_msg_0.off_z = 0.1606885521012077;
    msg.participants.push_back(tmp_msg_0);
    msg.leader_bank_lim = 0.8713188675522853;
    msg.leader_speed_min = 0.8330477339589505;
    msg.leader_speed_max = 0.016223333894348047;
    msg.leader_alt_min = 0.44654928073309597;
    msg.leader_alt_max = 0.2280893083744363;
    msg.pos_sim_err_lim = 0.7919811882980582;
    msg.pos_sim_err_wrn = 0.27220274096017927;
    msg.pos_sim_err_timeout = 33640U;
    msg.converg_max = 0.674951975465325;
    msg.converg_timeout = 17333U;
    msg.comms_timeout = 28017U;
    msg.turb_lim = 0.0026808681114761646;
    msg.custom.assign("ZZKIDCGTYOXLULMEGCAYLRDVXJMASUMFMAQLCDVTZGNZMDFNZHALJCMIUXKEOWRIFQAOHKDCGSFWKXIKJICTWJUWROVJSGQWIVYYXTHQPNWASOKOPFEQMVTUHSCYQEEGSQJMLVUVPSPRSDTEYHIIWAKHKVJSJE");

    try
    {
      Utils::ByteBuffer bfr;
      IMC::Packet::serialize(&msg, bfr);
      IMC::Message* msg_d = IMC::Packet::deserialize(bfr.getBuffer(), bfr.getSize());
      test.boolean("Formation #1", msg == *msg_d);
      delete msg_d;
    }
    catch (IMC::InvalidMessageSize& e)
    {
      (void)e;
      test.boolean("msg #1", msg.getSerializationSize() > DUNE_IMC_CONST_MAX_SIZE);
    }
  }

  {
    IMC::Formation msg;
    msg.setTimeStamp(0.22290955899315357);
    msg.setSource(53433U);
    msg.setSourceEntity(22U);
    msg.setDestination(33088U);
    msg.setDestinationEntity(119U);
    msg.formation_name.assign("DYZXQVTDXQBLGLIXOMORWVJVNBFPDZHXBLDUPQIFRBYBISHVTZAUCFGGAKSOCKCCDUELCYTHPWZCVDSNCYOHFMKODLAVQASMSKJNHFJPQNRBRXCJJATIKFDUREOURJYGLKBNTOIHCWXMGGPWEHPKTOBIZSGULIWHMJALJGBITHXROV");
    msg.type = 66U;
    msg.op = 186U;
    msg.group_name.assign("PIVSQVLKZTENVMQETZWFAZEGJHOASCIUCORRRZAGSJIGHDFHIKVZNNSZXTSDRUPYVQYQIWDDGGALVSTURKAEKGTNWHMANDLFMMEDPOFXUTSDXNFPZNXXBCWYSVUAQIFWOJHIBMSBRSWYXGLHAEEMFTBPTPJECXYLTHLNWKUBRODHZCXLKKJVRYBKUOKEBQWMYOFPYCJYLAPPQBWDNNQOKXIFWCTDIBJRJALUOCCJOFZUZLMHJQEIQ");
    msg.plan_id.assign("YVLYNTJHWBPBAUVCEFDRMEIJZYIGSDSPPJEYPAWDFSBTSZSBXROFZJENRNFDLKDIETKXWZIRHNOGUMUOX");
    msg.description.assign("GPVHDDDOAIQLEZ");
    msg.reference_frame = 9U;
    IMC::VehicleFormationParticipant tmp_msg_0;
    tmp_msg_0.vid = 58086U;
    tmp_msg_0.off_x = 0.32252247544148993;
    tmp_msg_0.off_y = 0.04617842904987968;
    tmp_msg_0.off_z = 0.3992316212654673;
    msg.participants.push_back(tmp_msg_0);
    msg.leader_bank_lim = 0.781795981561468;
    msg.leader_speed_min = 0.06910264875556027;
    msg.leader_speed_max = 0.44355785827913996;
    msg.leader_alt_min = 0.6910553016691658;
    msg.leader_alt_max = 0.7115423305717096;
    msg.pos_sim_err_lim = 0.9884999624949525;
    msg.pos_sim_err_wrn = 0.9686700253820903;
    msg.pos_sim_err_timeout = 11069U;
    msg.converg_max = 0.2880762859030387;
    msg.converg_timeout = 43228U;
    msg.comms_timeout = 55918U;
    msg.turb_lim = 0.871621574039833;
    msg.custom.assign("QMKHALBLASWZIDVBHNOAJHIMCTLYGFIBZSACUQQCYMTWXMBGYZDMEIZIFXKXTSBBOQTEGUVWROVUMGCHSLLPKQAYYPTMYOHXYQXPPDNFJRJTLRWJXCBDAFLRXDOXZWPYUGDGPEHKCBFEPWQVVOVAKBBDNJFTAUGHUJZDZCO");

    try
    {
      Utils::ByteBuffer bfr;
      IMC::Packet::serialize(&msg, bfr);
      IMC::Message* msg_d = IMC::Packet::deserialize(bfr.getBuffer(), bfr.getSize());
      test.boolean("Formation #2", msg == *msg_d);
      delete msg_d;
    }
    catch (IMC::InvalidMessageSize& e)
    {
      (void)e;
      test.boolean("msg #2", msg.getSerializationSize() > DUNE_IMC_CONST_MAX_SIZE);
    }
  }

  {
    IMC::Launch msg;
    msg.setTimeStamp(0.5444309500444824);
    msg.setSource(64630U);
    msg.setSourceEntity(203U);
    msg.setDestination(59817U);
    msg.setDestinationEntity(211U);
    msg.timeout = 62121U;
    msg.lat = 0.636518873299885;
    msg.lon = 0.943651671460034;
    msg.z = 0.9526201611876558;
    msg.z_units = 72U;
    msg.speed = 0.9754199343709373;
    msg.speed_units = 21U;
    msg.custom.assign("MTGKXIIZBZFNQVMUMKYRGZAWYZAOXDMSFHTEBJVQUBJXTRLKDLLPMBPEOODFIHAFISPJVUPMUHSCGVKLWYRFYVRXGQCMYZWKDCHJZHOYFAJDCOATECTENVWBNFOGQWQINSTCZVCRLEUHPGHLPJFAANTGMASUKSDEFEOSDEHLAZICRVNQ");

    try
    {
      Utils::ByteBuffer bfr;
      IMC::Packet::serialize(&msg, bfr);
      IMC::Message* msg_d = IMC::Packet::deserialize(bfr.getBuffer(), bfr.getSize());
      test.boolean("Launch #0", msg == *msg_d);
      delete msg_d;
    }
    catch (IMC::InvalidMessageSize& e)
    {
      (void)e;
      test.boolean("msg #0", msg.getSerializationSize() > DUNE_IMC_CONST_MAX_SIZE);
    }
  }

  {
    IMC::Launch msg;
    msg.setTimeStamp(0.6101743769000575);
    msg.setSource(60582U);
    msg.setSourceEntity(125U);
    msg.setDestination(53648U);
    msg.setDestinationEntity(208U);
    msg.timeout = 14417U;
    msg.lat = 0.8532488086179852;
    msg.lon = 0.19299613742965194;
    msg.z = 0.6375118801198979;
    msg.z_units = 102U;
    msg.speed = 0.09689090995410266;
    msg.speed_units = 186U;
    msg.custom.assign("OIRBPUFPGLBQVZIWROTIDNZHADWOUVMHNXNEOCGPPXLVUJXDFDUVPORDJHVWQGWRYSAKIRASQXYKCGANEZSKSREIQKMZFLKGAFEJFWTVIDFWLDXQYNFGOZWZCHQKEBEPXNEMRDBSAUAJOICUCEUSWBTLJRUCIHJBTJUKJBIHMQETN");

    try
    {
      Utils::ByteBuffer bfr;
      IMC::Packet::serialize(&msg, bfr);
      IMC::Message* msg_d = IMC::Packet::deserialize(bfr.getBuffer(), bfr.getSize());
      test.boolean("Launch #1", msg == *msg_d);
      delete msg_d;
    }
    catch (IMC::InvalidMessageSize& e)
    {
      (void)e;
      test.boolean("msg #1", msg.getSerializationSize() > DUNE_IMC_CONST_MAX_SIZE);
    }
  }

  {
    IMC::Launch msg;
    msg.setTimeStamp(0.6500772110445071);
    msg.setSource(21473U);
    msg.setSourceEntity(171U);
    msg.setDestination(47781U);
    msg.setDestinationEntity(121U);
    msg.timeout = 9093U;
    msg.lat = 0.4342297822579866;
    msg.lon = 0.6829843367583595;
    msg.z = 0.8012257626920559;
    msg.z_units = 129U;
    msg.speed = 0.7883042306378024;
    msg.speed_units = 134U;
    msg.custom.assign("DEMPRJWRLLQZQTBUBMVOINSWQBGHAFDXPIFLACDEEHZUGIAYDUWAVVKQBLTNJRFXRRKGJNOAPUTOWFBPHXQQMDUBZUNXGSHYDCRVYLDYTCBDLQAHNRPQFLRKMKVSYAAIEKJUEINPKKPCALWNPJEFSSXOVMXEZYGZTEZSZXITHOXMORGGYMWZCCJVZYIMWOEKTUFOTJGF");

    try
    {
      Utils::ByteBuffer bfr;
      IMC::Packet::serialize(&msg, bfr);
      IMC::Message* msg_d = IMC::Packet::deserialize(bfr.getBuffer(), bfr.getSize());
      test.boolean("Launch #2", msg == *msg_d);
      delete msg_d;
    }
    catch (IMC::InvalidMessageSize& e)
    {
      (void)e;
      test.boolean("msg #2", msg.getSerializationSize() > DUNE_IMC_CONST_MAX_SIZE);
    }
  }

  {
    IMC::Drop msg;
    msg.setTimeStamp(0.29071402616806163);
    msg.setSource(47788U);
    msg.setSourceEntity(179U);
    msg.setDestination(30237U);
    msg.setDestinationEntity(54U);
    msg.timeout = 29790U;
    msg.lat = 0.8159297852760841;
    msg.lon = 0.6884585852389796;
    msg.z = 0.22968481914083883;
    msg.z_units = 69U;
    msg.speed = 0.20802517042442792;
    msg.speed_units = 239U;
    msg.custom.assign("EZYFHONXDRASNSSUEFEAOLIVEEAOQAGUGECKRKTKMWRPHWCQWTXTFPLNLCWSGIUVFRCCPSNWGBNHXUODBKYWCEUSEDXSTWFVLMJGDXJGYDOVZVYEMRTIYTUBBZVCLBAJWYBYVZXDJHMYHQNJBMPKWOOPBFSNHRPTSQATOKUZDXUHDPEKTRQILSAQFXTMIBQRZRQYNPAQBZGFMPZGZJLLFILQUA");

    try
    {
      Utils::ByteBuffer bfr;
      IMC::Packet::serialize(&msg, bfr);
      IMC::Message* msg_d = IMC::Packet::deserialize(bfr.getBuffer(), bfr.getSize());
      test.boolean("Drop #0", msg == *msg_d);
      delete msg_d;
    }
    catch (IMC::InvalidMessageSize& e)
    {
      (void)e;
      test.boolean("msg #0", msg.getSerializationSize() > DUNE_IMC_CONST_MAX_SIZE);
    }
  }

  {
    IMC::Drop msg;
    msg.setTimeStamp(0.7348200711596273);
    msg.setSource(16130U);
    msg.setSourceEntity(231U);
    msg.setDestination(42858U);
    msg.setDestinationEntity(79U);
    msg.timeout = 48438U;
    msg.lat = 0.963304566351478;
    msg.lon = 0.5236503619850117;
    msg.z = 0.6494661582403315;
    msg.z_units = 22U;
    msg.speed = 0.43939002147762973;
    msg.speed_units = 249U;
    msg.custom.assign("TFOLDGPRYUFIHPPJMUBQLKKISQEYIINOMZSVFVZVXOIGADBDHEKWBVUWWTHYMHYSKLFYGNNIVKYDPLVSEEJDXTORDPCAGNHOUZLSNXAOITWDUECTWXPFUOJZXKWMGJBSQCRHRVUHNFCZEYAR");

    try
    {
      Utils::ByteBuffer bfr;
      IMC::Packet::serialize(&msg, bfr);
      IMC::Message* msg_d = IMC::Packet::deserialize(bfr.getBuffer(), bfr.getSize());
      test.boolean("Drop #1", msg == *msg_d);
      delete msg_d;
    }
    catch (IMC::InvalidMessageSize& e)
    {
      (void)e;
      test.boolean("msg #1", msg.getSerializationSize() > DUNE_IMC_CONST_MAX_SIZE);
    }
  }

  {
    IMC::Drop msg;
    msg.setTimeStamp(0.18310622372359142);
    msg.setSource(7459U);
    msg.setSourceEntity(170U);
    msg.setDestination(29962U);
    msg.setDestinationEntity(39U);
    msg.timeout = 4110U;
    msg.lat = 0.4806757208938508;
    msg.lon = 0.6502972164812107;
    msg.z = 0.9891210848192598;
    msg.z_units = 243U;
    msg.speed = 0.12213438628341822;
    msg.speed_units = 191U;
    msg.custom.assign("YAZVQCHFHMRZLXDIEURNNRPLOKYLXWBAKCRHBIRBFDSRQSMCLDBPWQGTBPQZRJMBMXKGLBBYKAEHUGASNRCQIVAATGDUENOJIJSFOWNNUUMVGEQFIVPFKTWNTFULEAMXYVMRZDFW");

    try
    {
      Utils::ByteBuffer bfr;
      IMC::Packet::serialize(&msg, bfr);
      IMC::Message* msg_d = IMC::Packet::deserialize(bfr.getBuffer(), bfr.getSize());
      test.boolean("Drop #2", msg == *msg_d);
      delete msg_d;
    }
    catch (IMC::InvalidMessageSize& e)
    {
      (void)e;
      test.boolean("msg #2", msg.getSerializationSize() > DUNE_IMC_CONST_MAX_SIZE);
    }
  }

  {
    IMC::ScheduledGoto msg;
    msg.setTimeStamp(0.32491532558310665);
    msg.setSource(60422U);
    msg.setSourceEntity(209U);
    msg.setDestination(26513U);
    msg.setDestinationEntity(75U);
    msg.arrival_time = 0.7948337859553309;
    msg.lat = 0.2397568684951762;
    msg.lon = 0.9723706030472579;
    msg.z = 0.6753886965643243;
    msg.z_units = 170U;
    msg.travel_z = 0.6169696670635766;
    msg.travel_z_units = 226U;
    msg.delayed = 163U;

    try
    {
      Utils::ByteBuffer bfr;
      IMC::Packet::serialize(&msg, bfr);
      IMC::Message* msg_d = IMC::Packet::deserialize(bfr.getBuffer(), bfr.getSize());
      test.boolean("ScheduledGoto #0", msg == *msg_d);
      delete msg_d;
    }
    catch (IMC::InvalidMessageSize& e)
    {
      (void)e;
      test.boolean("msg #0", msg.getSerializationSize() > DUNE_IMC_CONST_MAX_SIZE);
    }
  }

  {
    IMC::ScheduledGoto msg;
    msg.setTimeStamp(0.8759786926758698);
    msg.setSource(10515U);
    msg.setSourceEntity(63U);
    msg.setDestination(9761U);
    msg.setDestinationEntity(131U);
    msg.arrival_time = 0.8762025669207298;
    msg.lat = 0.9953152466764288;
    msg.lon = 0.4099920119592534;
    msg.z = 0.6217151374636254;
    msg.z_units = 22U;
    msg.travel_z = 0.7722434710291618;
    msg.travel_z_units = 105U;
    msg.delayed = 45U;

    try
    {
      Utils::ByteBuffer bfr;
      IMC::Packet::serialize(&msg, bfr);
      IMC::Message* msg_d = IMC::Packet::deserialize(bfr.getBuffer(), bfr.getSize());
      test.boolean("ScheduledGoto #1", msg == *msg_d);
      delete msg_d;
    }
    catch (IMC::InvalidMessageSize& e)
    {
      (void)e;
      test.boolean("msg #1", msg.getSerializationSize() > DUNE_IMC_CONST_MAX_SIZE);
    }
  }

  {
    IMC::ScheduledGoto msg;
    msg.setTimeStamp(0.15184068422549546);
    msg.setSource(51862U);
    msg.setSourceEntity(65U);
    msg.setDestination(1587U);
    msg.setDestinationEntity(68U);
    msg.arrival_time = 0.5769621138301697;
    msg.lat = 0.7072191479903246;
    msg.lon = 0.7137349855377227;
    msg.z = 0.9248998972934127;
    msg.z_units = 135U;
    msg.travel_z = 0.8691487244509873;
    msg.travel_z_units = 202U;
    msg.delayed = 253U;

    try
    {
      Utils::ByteBuffer bfr;
      IMC::Packet::serialize(&msg, bfr);
      IMC::Message* msg_d = IMC::Packet::deserialize(bfr.getBuffer(), bfr.getSize());
      test.boolean("ScheduledGoto #2", msg == *msg_d);
      delete msg_d;
    }
    catch (IMC::InvalidMessageSize& e)
    {
      (void)e;
      test.boolean("msg #2", msg.getSerializationSize() > DUNE_IMC_CONST_MAX_SIZE);
    }
  }

  {
    IMC::RowsCoverage msg;
    msg.setTimeStamp(0.2169538111455449);
    msg.setSource(23992U);
    msg.setSourceEntity(134U);
    msg.setDestination(10702U);
    msg.setDestinationEntity(205U);
    msg.lat = 0.5878269476483594;
    msg.lon = 0.6623462212564901;
    msg.z = 0.8397870694479956;
    msg.z_units = 139U;
    msg.speed = 0.05691726614092041;
    msg.speed_units = 149U;
    msg.bearing = 0.7087036259689588;
    msg.cross_angle = 0.4155493942181485;
    msg.width = 0.5734176874286971;
    msg.length = 0.7997095681186247;
    msg.coff = 155U;
    msg.angaperture = 0.005315944361434233;
    msg.range = 33198U;
    msg.overlap = 163U;
    msg.flags = 19U;
    msg.custom.assign("OWUGVRLQXNUMPRMCSZSMBIPTORJKQXOHJJTWNUXHJCIRGNIYXZVYUDUZLEAYBVUPPBFZXTRSZMSTXCLNDOKESJDZGRGVMZJAYKXYMAWANCT");

    try
    {
      Utils::ByteBuffer bfr;
      IMC::Packet::serialize(&msg, bfr);
      IMC::Message* msg_d = IMC::Packet::deserialize(bfr.getBuffer(), bfr.getSize());
      test.boolean("RowsCoverage #0", msg == *msg_d);
      delete msg_d;
    }
    catch (IMC::InvalidMessageSize& e)
    {
      (void)e;
      test.boolean("msg #0", msg.getSerializationSize() > DUNE_IMC_CONST_MAX_SIZE);
    }
  }

  {
    IMC::RowsCoverage msg;
    msg.setTimeStamp(0.05403749193253615);
    msg.setSource(37707U);
    msg.setSourceEntity(191U);
    msg.setDestination(24677U);
    msg.setDestinationEntity(235U);
    msg.lat = 0.6499280466602599;
    msg.lon = 0.4232151274334688;
    msg.z = 0.47946599912172094;
    msg.z_units = 127U;
    msg.speed = 0.5383069516737695;
    msg.speed_units = 141U;
    msg.bearing = 0.20124904014846545;
    msg.cross_angle = 0.7927373105982874;
    msg.width = 0.6754524188654649;
    msg.length = 0.6694112187950787;
    msg.coff = 36U;
    msg.angaperture = 0.2997038863843008;
    msg.range = 31778U;
    msg.overlap = 119U;
    msg.flags = 189U;
    msg.custom.assign("XZUMTFMRUKPJ");

    try
    {
      Utils::ByteBuffer bfr;
      IMC::Packet::serialize(&msg, bfr);
      IMC::Message* msg_d = IMC::Packet::deserialize(bfr.getBuffer(), bfr.getSize());
      test.boolean("RowsCoverage #1", msg == *msg_d);
      delete msg_d;
    }
    catch (IMC::InvalidMessageSize& e)
    {
      (void)e;
      test.boolean("msg #1", msg.getSerializationSize() > DUNE_IMC_CONST_MAX_SIZE);
    }
  }

  {
    IMC::RowsCoverage msg;
    msg.setTimeStamp(0.5026470001705345);
    msg.setSource(60009U);
    msg.setSourceEntity(214U);
    msg.setDestination(5733U);
    msg.setDestinationEntity(118U);
    msg.lat = 0.741532174348267;
    msg.lon = 0.8227211882255496;
    msg.z = 0.16255700310189025;
    msg.z_units = 27U;
    msg.speed = 0.03564381969714303;
    msg.speed_units = 46U;
    msg.bearing = 0.831955250896038;
    msg.cross_angle = 0.19711263224795983;
    msg.width = 0.7644481341490658;
    msg.length = 0.16389030623454925;
    msg.coff = 95U;
    msg.angaperture = 0.45310933286399524;
    msg.range = 24276U;
    msg.overlap = 164U;
    msg.flags = 167U;
    msg.custom.assign("ASLZAXAAFRDQRBBRACEGFGYAQOYJJDQQBLYSLPUUTAJXBOSHYPKQUFXDKELXSVIUORGQFYNWYYCMNVVMPRBVEFLCRJETFKWXCJZRBWHXSTPGJJIHAUQLTCDDYOYPXZEXPDRTQOZNRTNLMHWOMIACJMCMENTWGVNAOGWHKEPPGWVNIPZBICIKTCQIVOZOBIBHMVHIDFNXSUBWSUEFYMDUHZJRGMNUJFSEDSSGXFIKKULDO");

    try
    {
      Utils::ByteBuffer bfr;
      IMC::Packet::serialize(&msg, bfr);
      IMC::Message* msg_d = IMC::Packet::deserialize(bfr.getBuffer(), bfr.getSize());
      test.boolean("RowsCoverage #2", msg == *msg_d);
      delete msg_d;
    }
    catch (IMC::InvalidMessageSize& e)
    {
      (void)e;
      test.boolean("msg #2", msg.getSerializationSize() > DUNE_IMC_CONST_MAX_SIZE);
    }
  }

  {
    IMC::Sample msg;
    msg.setTimeStamp(0.4213287017437257);
    msg.setSource(10871U);
    msg.setSourceEntity(14U);
    msg.setDestination(37335U);
    msg.setDestinationEntity(116U);
    msg.timeout = 41160U;
    msg.lat = 0.7181722084207245;
    msg.lon = 0.915733783353105;
    msg.z = 0.5477273254080454;
    msg.z_units = 55U;
    msg.speed = 0.8772692013586568;
    msg.speed_units = 2U;
    msg.syringe0 = 103U;
    msg.syringe1 = 227U;
    msg.syringe2 = 234U;
    msg.custom.assign("SVOATYQGXGUHPMIMCCVABUYJIWGPMFJXVSYEUHHUKQJXQBXZRKNTEVTJFQEAFQPLPEGYJWYIVGHZFZCOXBZOCMDPWOQCJNKFXYKKWAWNDJVRXWMDLLAQEDTEJIEGFPGNC");

    try
    {
      Utils::ByteBuffer bfr;
      IMC::Packet::serialize(&msg, bfr);
      IMC::Message* msg_d = IMC::Packet::deserialize(bfr.getBuffer(), bfr.getSize());
      test.boolean("Sample #0", msg == *msg_d);
      delete msg_d;
    }
    catch (IMC::InvalidMessageSize& e)
    {
      (void)e;
      test.boolean("msg #0", msg.getSerializationSize() > DUNE_IMC_CONST_MAX_SIZE);
    }
  }

  {
    IMC::Sample msg;
    msg.setTimeStamp(0.045452808770601094);
    msg.setSource(41864U);
    msg.setSourceEntity(139U);
    msg.setDestination(50887U);
    msg.setDestinationEntity(119U);
    msg.timeout = 13583U;
    msg.lat = 0.7685905815321125;
    msg.lon = 0.300384279985365;
    msg.z = 0.501656789096464;
    msg.z_units = 192U;
    msg.speed = 0.09131960244009174;
    msg.speed_units = 143U;
    msg.syringe0 = 35U;
    msg.syringe1 = 211U;
    msg.syringe2 = 185U;
    msg.custom.assign("FAZPRYJHGVTWRKSSENFDFGSEZLKWRVAUDHRXRVJDNUTJHUZBHMYUDNZCPNKOMWWWCYVPKRKNDUXUPGQPIYKHVDKSSTLKUTYWLVBLOFAGACFIGWMUHFZWPHIXXVFPQCSLLJLJVMZYRWAGMPXGSORMBBQMYNMHZQSTEEXEZABOGRSYWEJXNQQICB");

    try
    {
      Utils::ByteBuffer bfr;
      IMC::Packet::serialize(&msg, bfr);
      IMC::Message* msg_d = IMC::Packet::deserialize(bfr.getBuffer(), bfr.getSize());
      test.boolean("Sample #1", msg == *msg_d);
      delete msg_d;
    }
    catch (IMC::InvalidMessageSize& e)
    {
      (void)e;
      test.boolean("msg #1", msg.getSerializationSize() > DUNE_IMC_CONST_MAX_SIZE);
    }
  }

  {
    IMC::Sample msg;
    msg.setTimeStamp(0.5450751119634554);
    msg.setSource(54474U);
    msg.setSourceEntity(200U);
    msg.setDestination(56101U);
    msg.setDestinationEntity(42U);
    msg.timeout = 28354U;
    msg.lat = 0.28434341397684026;
    msg.lon = 0.09800716083641381;
    msg.z = 0.382513408083875;
    msg.z_units = 78U;
    msg.speed = 0.27366716438207317;
    msg.speed_units = 208U;
    msg.syringe0 = 169U;
    msg.syringe1 = 74U;
    msg.syringe2 = 158U;
    msg.custom.assign("SOOXBKDXDMQNKSDOXDLJBGCYINKMHJ");

    try
    {
      Utils::ByteBuffer bfr;
      IMC::Packet::serialize(&msg, bfr);
      IMC::Message* msg_d = IMC::Packet::deserialize(bfr.getBuffer(), bfr.getSize());
      test.boolean("Sample #2", msg == *msg_d);
      delete msg_d;
    }
    catch (IMC::InvalidMessageSize& e)
    {
      (void)e;
      test.boolean("msg #2", msg.getSerializationSize() > DUNE_IMC_CONST_MAX_SIZE);
    }
  }

  {
    IMC::ImageTracking msg;
    msg.setTimeStamp(0.10045712794813078);
    msg.setSource(4512U);
    msg.setSourceEntity(138U);
    msg.setDestination(37788U);
    msg.setDestinationEntity(129U);

    try
    {
      Utils::ByteBuffer bfr;
      IMC::Packet::serialize(&msg, bfr);
      IMC::Message* msg_d = IMC::Packet::deserialize(bfr.getBuffer(), bfr.getSize());
      test.boolean("ImageTracking #0", msg == *msg_d);
      delete msg_d;
    }
    catch (IMC::InvalidMessageSize& e)
    {
      (void)e;
      test.boolean("msg #0", msg.getSerializationSize() > DUNE_IMC_CONST_MAX_SIZE);
    }
  }

  {
    IMC::ImageTracking msg;
    msg.setTimeStamp(0.7238664751963677);
    msg.setSource(58556U);
    msg.setSourceEntity(187U);
    msg.setDestination(13952U);
    msg.setDestinationEntity(58U);

    try
    {
      Utils::ByteBuffer bfr;
      IMC::Packet::serialize(&msg, bfr);
      IMC::Message* msg_d = IMC::Packet::deserialize(bfr.getBuffer(), bfr.getSize());
      test.boolean("ImageTracking #1", msg == *msg_d);
      delete msg_d;
    }
    catch (IMC::InvalidMessageSize& e)
    {
      (void)e;
      test.boolean("msg #1", msg.getSerializationSize() > DUNE_IMC_CONST_MAX_SIZE);
    }
  }

  {
    IMC::ImageTracking msg;
    msg.setTimeStamp(0.08288852725976048);
    msg.setSource(55780U);
    msg.setSourceEntity(147U);
    msg.setDestination(55581U);
    msg.setDestinationEntity(220U);

    try
    {
      Utils::ByteBuffer bfr;
      IMC::Packet::serialize(&msg, bfr);
      IMC::Message* msg_d = IMC::Packet::deserialize(bfr.getBuffer(), bfr.getSize());
      test.boolean("ImageTracking #2", msg == *msg_d);
      delete msg_d;
    }
    catch (IMC::InvalidMessageSize& e)
    {
      (void)e;
      test.boolean("msg #2", msg.getSerializationSize() > DUNE_IMC_CONST_MAX_SIZE);
    }
  }

  {
    IMC::Takeoff msg;
    msg.setTimeStamp(0.7178544790365389);
    msg.setSource(18302U);
    msg.setSourceEntity(123U);
    msg.setDestination(17848U);
    msg.setDestinationEntity(251U);
    msg.lat = 0.8244193376270075;
    msg.lon = 0.030642799642224272;
    msg.z = 0.9349379385132726;
    msg.z_units = 245U;
    msg.speed = 0.5734570627697138;
    msg.speed_units = 56U;
    msg.takeoff_pitch = 0.8073654519572966;
    msg.custom.assign("URGMSXCVXLMYGBURWAHXNLEIJFLDDSTIQNVQFOPLGONVDKQPMWAHZGAUMXKZCAEHEPFNBCCSTZSZWKFGBGSSQROQGUAKWZWFALXLZPHBVUOXWZDVDRKWAYDFQMPKLNZEXOGROQFBEIQJYEUZPHFMDFUTJXHRCVCCBCIIDCJBBVWEL");

    try
    {
      Utils::ByteBuffer bfr;
      IMC::Packet::serialize(&msg, bfr);
      IMC::Message* msg_d = IMC::Packet::deserialize(bfr.getBuffer(), bfr.getSize());
      test.boolean("Takeoff #0", msg == *msg_d);
      delete msg_d;
    }
    catch (IMC::InvalidMessageSize& e)
    {
      (void)e;
      test.boolean("msg #0", msg.getSerializationSize() > DUNE_IMC_CONST_MAX_SIZE);
    }
  }

  {
    IMC::Takeoff msg;
    msg.setTimeStamp(0.6091957353461118);
    msg.setSource(25651U);
    msg.setSourceEntity(52U);
    msg.setDestination(5295U);
    msg.setDestinationEntity(136U);
    msg.lat = 0.6832709851045604;
    msg.lon = 0.19597049089700436;
    msg.z = 0.24463569785641448;
    msg.z_units = 226U;
    msg.speed = 0.3279837012605704;
    msg.speed_units = 109U;
    msg.takeoff_pitch = 0.2897261087532339;
    msg.custom.assign("KKGZOHLLYGNIRPDQRUWYSZXOPBERGIPMJQFJHLEPDHOVHQKTICWABNQSDULFOXUOXFIWFDNJNYCTALZGBVYFMKUUEUQMJHRGLSAJFDWAIWSBALSGPEFVZIWVBCTXOUBYYMBDZDRZKKQZHKUHYRZVNMSVGGXPXTGKLMNARNCFPOQCJEMYDNDMUVCQLAGUMTYEZOSHICABDXQRBSEFECSIVPWRIHTNTJWCLVQYOFKXJJAEAZNRPTSXTVMKWXCWHI");

    try
    {
      Utils::ByteBuffer bfr;
      IMC::Packet::serialize(&msg, bfr);
      IMC::Message* msg_d = IMC::Packet::deserialize(bfr.getBuffer(), bfr.getSize());
      test.boolean("Takeoff #1", msg == *msg_d);
      delete msg_d;
    }
    catch (IMC::InvalidMessageSize& e)
    {
      (void)e;
      test.boolean("msg #1", msg.getSerializationSize() > DUNE_IMC_CONST_MAX_SIZE);
    }
  }

  {
    IMC::Takeoff msg;
    msg.setTimeStamp(0.410525622294751);
    msg.setSource(15683U);
    msg.setSourceEntity(239U);
    msg.setDestination(11749U);
    msg.setDestinationEntity(226U);
    msg.lat = 0.357622532766662;
    msg.lon = 0.15018002628191318;
    msg.z = 0.5540068592670733;
    msg.z_units = 171U;
    msg.speed = 0.15268404740216768;
    msg.speed_units = 37U;
    msg.takeoff_pitch = 0.5792367648755324;
    msg.custom.assign("VFRUJZYPCSXSEIAWABYPBHZTXMSMFPUOYTOVSVXJJGBXEFGQEIWNIPVYXKXGVKBBXLPPKTYBVAVYJEL");

    try
    {
      Utils::ByteBuffer bfr;
      IMC::Packet::serialize(&msg, bfr);
      IMC::Message* msg_d = IMC::Packet::deserialize(bfr.getBuffer(), bfr.getSize());
      test.boolean("Takeoff #2", msg == *msg_d);
      delete msg_d;
    }
    catch (IMC::InvalidMessageSize& e)
    {
      (void)e;
      test.boolean("msg #2", msg.getSerializationSize() > DUNE_IMC_CONST_MAX_SIZE);
    }
  }

  {
    IMC::Land msg;
    msg.setTimeStamp(0.6071366951390356);
    msg.setSource(63509U);
    msg.setSourceEntity(241U);
    msg.setDestination(17827U);
    msg.setDestinationEntity(189U);
    msg.lat = 0.4868246032293936;
    msg.lon = 0.9145798289525369;
    msg.z = 0.6889758767154157;
    msg.z_units = 222U;
    msg.speed = 0.7633045798511277;
    msg.speed_units = 56U;
    msg.abort_z = 0.5202663273218947;
    msg.bearing = 0.7473695813542695;
    msg.glide_slope = 214U;
    msg.glide_slope_alt = 0.43966237788943996;
    msg.custom.assign("NECJRBAFMTRSUJTGNNUVFVTARNQIQZVYTRRAUYDMFLQXUIMGPPFBQFWRTXPEKKAYLNCXWNCYSCOIDCZHLNZLCHPXPIZIWGBJKTARMFCDXRWVUFIYDYBYSNDZRMLESIXGGJJJELKVKTBMMPEUAVEQPOUDWMGXNGHJJCSKLBEGWJQMESEGHKUFZUQAKPTBOWVVHAQBOESYYOTISORGPOXHZOWQZDVNHXAFKBYHOLVHZCOBPKILHIXUZDDSQCDT");

    try
    {
      Utils::ByteBuffer bfr;
      IMC::Packet::serialize(&msg, bfr);
      IMC::Message* msg_d = IMC::Packet::deserialize(bfr.getBuffer(), bfr.getSize());
      test.boolean("Land #0", msg == *msg_d);
      delete msg_d;
    }
    catch (IMC::InvalidMessageSize& e)
    {
      (void)e;
      test.boolean("msg #0", msg.getSerializationSize() > DUNE_IMC_CONST_MAX_SIZE);
    }
  }

  {
    IMC::Land msg;
    msg.setTimeStamp(0.030541888333700307);
    msg.setSource(62042U);
    msg.setSourceEntity(97U);
    msg.setDestination(33732U);
    msg.setDestinationEntity(244U);
    msg.lat = 0.8637580327510762;
    msg.lon = 0.9806419449298761;
    msg.z = 0.7964134607881869;
    msg.z_units = 32U;
    msg.speed = 0.26082997290780263;
    msg.speed_units = 128U;
    msg.abort_z = 0.7255589703518844;
    msg.bearing = 0.9843393389849766;
    msg.glide_slope = 198U;
    msg.glide_slope_alt = 0.21341450089954528;
    msg.custom.assign("DYCARPCLBQGJSXQJYRZEXPSZTYWLHECUWSKLBRNQWAJKHQABPIVVAWINDRSZTUQFSC");

    try
    {
      Utils::ByteBuffer bfr;
      IMC::Packet::serialize(&msg, bfr);
      IMC::Message* msg_d = IMC::Packet::deserialize(bfr.getBuffer(), bfr.getSize());
      test.boolean("Land #1", msg == *msg_d);
      delete msg_d;
    }
    catch (IMC::InvalidMessageSize& e)
    {
      (void)e;
      test.boolean("msg #1", msg.getSerializationSize() > DUNE_IMC_CONST_MAX_SIZE);
    }
  }

  {
    IMC::Land msg;
    msg.setTimeStamp(0.35916268587713873);
    msg.setSource(25860U);
    msg.setSourceEntity(127U);
    msg.setDestination(30259U);
    msg.setDestinationEntity(68U);
    msg.lat = 0.2699512643721127;
    msg.lon = 0.8745951448171467;
    msg.z = 0.06908776138665906;
    msg.z_units = 149U;
    msg.speed = 0.03433068196192368;
    msg.speed_units = 215U;
    msg.abort_z = 0.5236614895490909;
    msg.bearing = 0.1840924298572273;
    msg.glide_slope = 140U;
    msg.glide_slope_alt = 0.04236604726141968;
    msg.custom.assign("OIDFOCJUQWBZCPPQYNAENKTLNTLHYORIWBGVPZWOHKJSSIWEZMLQWLACDJPEIFUJHQBDRMSKGGQYWXDCKEPUJEYNUDALCBERCKTUVF");

    try
    {
      Utils::ByteBuffer bfr;
      IMC::Packet::serialize(&msg, bfr);
      IMC::Message* msg_d = IMC::Packet::deserialize(bfr.getBuffer(), bfr.getSize());
      test.boolean("Land #2", msg == *msg_d);
      delete msg_d;
    }
    catch (IMC::InvalidMessageSize& e)
    {
      (void)e;
      test.boolean("msg #2", msg.getSerializationSize() > DUNE_IMC_CONST_MAX_SIZE);
    }
  }

  {
    IMC::AutonomousSection msg;
    msg.setTimeStamp(0.21130514278752777);
    msg.setSource(50960U);
    msg.setSourceEntity(55U);
    msg.setDestination(54706U);
    msg.setDestinationEntity(138U);
    msg.lat = 0.7179738027838193;
    msg.lon = 0.5454773914738005;
    msg.speed = 0.6120490453859383;
    msg.speed_units = 177U;
    msg.limits = 3U;
    msg.max_depth = 0.6461848015384744;
    msg.min_alt = 0.8341359558198852;
    msg.time_limit = 0.5556092319520094;
    msg.controller.assign("GRDMVAHVDWHJOCDJSAROCKWUAUKLXONHQWMRGRIWITMOZWNZIQMAATJCVLEZODLFBPTHSNITECYQNKRNMFKJXEDMJHIXBNGCDUQYEYLJKOSBUCLN");
    msg.custom.assign("IJHCPVUUNIWATBVCKKBBRZNSZCQNVKJORISSSQFPZBIFLECAGJCXOVABFSMGGTWJYOXMPFFNLMEDPPRUOAJXERUXLPVRRVYUNWHROLHKSUNTZXBXYHHQCDGEZEDSFOKGHIXPPGAREFLIMUYUYIVEOCQDFK");

    try
    {
      Utils::ByteBuffer bfr;
      IMC::Packet::serialize(&msg, bfr);
      IMC::Message* msg_d = IMC::Packet::deserialize(bfr.getBuffer(), bfr.getSize());
      test.boolean("AutonomousSection #0", msg == *msg_d);
      delete msg_d;
    }
    catch (IMC::InvalidMessageSize& e)
    {
      (void)e;
      test.boolean("msg #0", msg.getSerializationSize() > DUNE_IMC_CONST_MAX_SIZE);
    }
  }

  {
    IMC::AutonomousSection msg;
    msg.setTimeStamp(0.7693189073398206);
    msg.setSource(3918U);
    msg.setSourceEntity(150U);
    msg.setDestination(31274U);
    msg.setDestinationEntity(17U);
    msg.lat = 0.32613040053018727;
    msg.lon = 0.43177817596575596;
    msg.speed = 0.4945416469173032;
    msg.speed_units = 107U;
    msg.limits = 19U;
    msg.max_depth = 0.033433121154142764;
    msg.min_alt = 0.9734978152513687;
    msg.time_limit = 0.7818606040833411;
    msg.controller.assign("ILYRBRSUBGXOSCBMYFSSGDYGYQEQKLYFPLTFNBLDJNRMBAUTRUXZSRTOIQSZLBXHMAFFOWSNSXFYVIVNFGXGZGQUDGLHJDBBSCUOPHEIVE");
    msg.custom.assign("LDEFXAZODNAKUWPTQDOSRCAOVOCJMJBHYMQKJXYBTVFQDVRQMGWUIRZVQMGXUJMFZMRNNGWREZIXYALYHNYZOZFNNPIIKMTBQXWBJWPOJSNHICLSSELLYQYIDASHPUPKTLHMSODOHPRWBZLQHHRKEDMKQVBOG");

    try
    {
      Utils::ByteBuffer bfr;
      IMC::Packet::serialize(&msg, bfr);
      IMC::Message* msg_d = IMC::Packet::deserialize(bfr.getBuffer(), bfr.getSize());
      test.boolean("AutonomousSection #1", msg == *msg_d);
      delete msg_d;
    }
    catch (IMC::InvalidMessageSize& e)
    {
      (void)e;
      test.boolean("msg #1", msg.getSerializationSize() > DUNE_IMC_CONST_MAX_SIZE);
    }
  }

  {
    IMC::AutonomousSection msg;
    msg.setTimeStamp(0.7282163564175705);
    msg.setSource(49165U);
    msg.setSourceEntity(80U);
    msg.setDestination(4303U);
    msg.setDestinationEntity(131U);
    msg.lat = 0.05483815014750204;
    msg.lon = 0.9985370297671202;
    msg.speed = 0.17756931043210145;
    msg.speed_units = 11U;
    msg.limits = 41U;
    msg.max_depth = 0.4979951511015357;
    msg.min_alt = 0.01221636063561471;
    msg.time_limit = 0.5175697893738426;
    msg.controller.assign("PSSRJOTDMVGRIBNCSYIJZAIFYMDKQZHKYNSDCLCEODWLWR");
    msg.custom.assign("CSIOKPBYQDWLKRVDOGMCRMQVCXKTWYUPPKCUIYMAVGPKRGLBLPZKQHSAUYIEXHTGJONWQWWVSIZLEFHLAFYBFHIYFNHZGZUAALBTJPKCHNYXFRLFGAZJWPCAJVMNUBIATJREMYBBDQXSIXOZTTCRFMHBWNUSDYHISTEDRXCDMJFLVJFXEQOW");

    try
    {
      Utils::ByteBuffer bfr;
      IMC::Packet::serialize(&msg, bfr);
      IMC::Message* msg_d = IMC::Packet::deserialize(bfr.getBuffer(), bfr.getSize());
      test.boolean("AutonomousSection #2", msg == *msg_d);
      delete msg_d;
    }
    catch (IMC::InvalidMessageSize& e)
    {
      (void)e;
      test.boolean("msg #2", msg.getSerializationSize() > DUNE_IMC_CONST_MAX_SIZE);
    }
  }

  {
    IMC::FollowPoint msg;
    msg.setTimeStamp(0.7080967548414046);
    msg.setSource(41153U);
    msg.setSourceEntity(253U);
    msg.setDestination(44887U);
    msg.setDestinationEntity(235U);
    msg.target.assign("AIWQCEROQHMRPGZAISRKKDEKZQWNMURJBEIVVZQZLPRFIKFVCNPWLWGPHGYZQTBMDRITWWSNBYNOLGCLRAPUAPFUVNKHSMTEOYXUBPUJFTHINSVKFGDYG");
    msg.max_speed = 0.6397468623796205;
    msg.speed_units = 252U;
    msg.lat = 0.9179559944273211;
    msg.lon = 0.025322494023266584;
    msg.z = 0.9276211602805089;
    msg.z_units = 206U;
    msg.custom.assign("QWJMZREWDTJTCBVCQICDEMPBXDRSHEUFYIOXQVUEJZEXZSQCFLOARNMXCSWIKKTTDKQALJNNRSPBIYVXFWRFPLDUGGKSRLNTBJWKBTDLOLGWQXHUSMJBHFIMKGNGPMGLVZAENJFMVTMOCDLEXNZYSZTFVHRUSOEKUODBQUOHSG");

    try
    {
      Utils::ByteBuffer bfr;
      IMC::Packet::serialize(&msg, bfr);
      IMC::Message* msg_d = IMC::Packet::deserialize(bfr.getBuffer(), bfr.getSize());
      test.boolean("FollowPoint #0", msg == *msg_d);
      delete msg_d;
    }
    catch (IMC::InvalidMessageSize& e)
    {
      (void)e;
      test.boolean("msg #0", msg.getSerializationSize() > DUNE_IMC_CONST_MAX_SIZE);
    }
  }

  {
    IMC::FollowPoint msg;
    msg.setTimeStamp(0.7438862866643994);
    msg.setSource(60596U);
    msg.setSourceEntity(216U);
    msg.setDestination(42614U);
    msg.setDestinationEntity(201U);
    msg.target.assign("YZCKNVXAVCSEIDSARHQZNBSDOHWTMFMESVMGBPZWLCAUFUQHQTYPABEVNZDFWLQCZBGVWQREXJNQWMPZZDPYIDUFHTRIOYJHCTORDUTUQNNLFJNLRXSGLYIFZJMXXBMTGKMTGSGZXICFRMGEJADWVYOFWDUKKVHAJUWM");
    msg.max_speed = 0.007761491139142596;
    msg.speed_units = 245U;
    msg.lat = 0.49703680619486;
    msg.lon = 0.1430160194026019;
    msg.z = 0.9600280205387174;
    msg.z_units = 1U;
    msg.custom.assign("BYOLAPHUKVVRPWWOVLYJQGASIGYJFBVVBUDKNXLLMCQMARERQPMELDTUVTEVHDWJKNCOHAQTIJDQAZTKCPPGCDZAHGPRTCXRMNDRXFDWIFUYKBWEPECEFLXBYZLZGCQIIBIFOYNPXPMZTWOKZKTSJSXIMLZUISQGIUGGCJMDRMAQBXJCJMKYWKQGGYUZUMBXOSWFXOHJFHESFYUNRVBZRNHVSLFJKNBPZSWSNNSHETTEHUDALANEQH");

    try
    {
      Utils::ByteBuffer bfr;
      IMC::Packet::serialize(&msg, bfr);
      IMC::Message* msg_d = IMC::Packet::deserialize(bfr.getBuffer(), bfr.getSize());
      test.boolean("FollowPoint #1", msg == *msg_d);
      delete msg_d;
    }
    catch (IMC::InvalidMessageSize& e)
    {
      (void)e;
      test.boolean("msg #1", msg.getSerializationSize() > DUNE_IMC_CONST_MAX_SIZE);
    }
  }

  {
    IMC::FollowPoint msg;
    msg.setTimeStamp(0.8620622949358026);
    msg.setSource(16490U);
    msg.setSourceEntity(128U);
    msg.setDestination(32792U);
    msg.setDestinationEntity(63U);
    msg.target.assign("NLFVWZUDBZUYRVQWBILWNMBCRIDSIJITZXSXXGLRBL");
    msg.max_speed = 0.673507212862183;
    msg.speed_units = 143U;
    msg.lat = 0.18561307509800662;
    msg.lon = 0.5584183831179345;
    msg.z = 0.7990095501920029;
    msg.z_units = 20U;
    msg.custom.assign("PCUQDBKOXTLQSSHXACCLAJBMUNUEOQJRNWYQBPGSQWIVAEPGVETXIOBZDULZTWMXPFXVGUNCCIUBNSEQEPRPIGTFFKFNLJMLVMCJWTNDAEYRMEDFUZHBBOMDKQSKVYMXPDTFGSLGIQTUWXYAJCUQGFSKVXOHZAFKYNLARCZBENWVHJGROSOWLRVPAWHJIJVIZPY");

    try
    {
      Utils::ByteBuffer bfr;
      IMC::Packet::serialize(&msg, bfr);
      IMC::Message* msg_d = IMC::Packet::deserialize(bfr.getBuffer(), bfr.getSize());
      test.boolean("FollowPoint #2", msg == *msg_d);
      delete msg_d;
    }
    catch (IMC::InvalidMessageSize& e)
    {
      (void)e;
      test.boolean("msg #2", msg.getSerializationSize() > DUNE_IMC_CONST_MAX_SIZE);
    }
  }

  {
    IMC::Alignment msg;
    msg.setTimeStamp(0.5910289463782467);
    msg.setSource(63645U);
    msg.setSourceEntity(58U);
    msg.setDestination(58393U);
    msg.setDestinationEntity(28U);
    msg.timeout = 31906U;
    msg.lat = 0.9980575485990334;
    msg.lon = 0.9458059572192097;
    msg.speed = 0.08905572572472675;
    msg.speed_units = 58U;
    msg.custom.assign("YQDPEEIUPZUHMYGXMACNEIDRMBQMTAWOBIEAILCGUJDETCJJRHYWZB");

    try
    {
      Utils::ByteBuffer bfr;
      IMC::Packet::serialize(&msg, bfr);
      IMC::Message* msg_d = IMC::Packet::deserialize(bfr.getBuffer(), bfr.getSize());
      test.boolean("Alignment #0", msg == *msg_d);
      delete msg_d;
    }
    catch (IMC::InvalidMessageSize& e)
    {
      (void)e;
      test.boolean("msg #0", msg.getSerializationSize() > DUNE_IMC_CONST_MAX_SIZE);
    }
  }

  {
    IMC::Alignment msg;
    msg.setTimeStamp(0.4957528534679263);
    msg.setSource(56797U);
    msg.setSourceEntity(150U);
    msg.setDestination(6032U);
    msg.setDestinationEntity(52U);
    msg.timeout = 28830U;
    msg.lat = 0.2408033524316563;
    msg.lon = 0.24694230498323944;
    msg.speed = 0.1257456347870004;
    msg.speed_units = 170U;
    msg.custom.assign("UIPXOOVNRIJKAPYKSRMCAKXCWCCYMIXNEYOBUJIZGMKCAWEZUFNCURLXVDQWKERNMDFFJEEQI");

    try
    {
      Utils::ByteBuffer bfr;
      IMC::Packet::serialize(&msg, bfr);
      IMC::Message* msg_d = IMC::Packet::deserialize(bfr.getBuffer(), bfr.getSize());
      test.boolean("Alignment #1", msg == *msg_d);
      delete msg_d;
    }
    catch (IMC::InvalidMessageSize& e)
    {
      (void)e;
      test.boolean("msg #1", msg.getSerializationSize() > DUNE_IMC_CONST_MAX_SIZE);
    }
  }

  {
    IMC::Alignment msg;
    msg.setTimeStamp(0.35119171212875067);
    msg.setSource(58988U);
    msg.setSourceEntity(123U);
    msg.setDestination(40453U);
    msg.setDestinationEntity(192U);
    msg.timeout = 60161U;
    msg.lat = 0.16868918639802777;
    msg.lon = 0.22018625985189944;
    msg.speed = 0.3054035072717719;
    msg.speed_units = 16U;
    msg.custom.assign("JCGOQCUXYDVEJGGBFNZRADEYCVFTZBXQRLRZNTRULQZCWUSDA");

    try
    {
      Utils::ByteBuffer bfr;
      IMC::Packet::serialize(&msg, bfr);
      IMC::Message* msg_d = IMC::Packet::deserialize(bfr.getBuffer(), bfr.getSize());
      test.boolean("Alignment #2", msg == *msg_d);
      delete msg_d;
    }
    catch (IMC::InvalidMessageSize& e)
    {
      (void)e;
      test.boolean("msg #2", msg.getSerializationSize() > DUNE_IMC_CONST_MAX_SIZE);
    }
  }

  {
    IMC::StationKeepingExtended msg;
    msg.setTimeStamp(0.08661806997970145);
    msg.setSource(16348U);
    msg.setSourceEntity(74U);
    msg.setDestination(56476U);
    msg.setDestinationEntity(62U);
    msg.lat = 0.7856636859249612;
    msg.lon = 0.4931922640051787;
    msg.z = 0.5127021420690687;
    msg.z_units = 254U;
    msg.radius = 0.1681468347516495;
    msg.duration = 15280U;
    msg.speed = 0.11079073404235484;
    msg.speed_units = 124U;
    msg.popup_period = 59857U;
    msg.popup_duration = 48140U;
    msg.flags = 159U;
    msg.custom.assign("NMXDBQHKXDFBQNCQOMKHHNLEYUXTNHVRMSJUKXVJOEVJLNQGLZTBMBFIEBDRABPXSOLOYLDODSJLKRYFRUCLDZPQGRNSTLQXHNEMXVDVSKZGHSGPOCDARQYDMEZYZLGQAAG");

    try
    {
      Utils::ByteBuffer bfr;
      IMC::Packet::serialize(&msg, bfr);
      IMC::Message* msg_d = IMC::Packet::deserialize(bfr.getBuffer(), bfr.getSize());
      test.boolean("StationKeepingExtended #0", msg == *msg_d);
      delete msg_d;
    }
    catch (IMC::InvalidMessageSize& e)
    {
      (void)e;
      test.boolean("msg #0", msg.getSerializationSize() > DUNE_IMC_CONST_MAX_SIZE);
    }
  }

  {
    IMC::StationKeepingExtended msg;
    msg.setTimeStamp(0.2618800469601028);
    msg.setSource(32348U);
    msg.setSourceEntity(222U);
    msg.setDestination(52655U);
    msg.setDestinationEntity(54U);
    msg.lat = 0.10851987447177736;
    msg.lon = 0.4627915129903035;
    msg.z = 0.2338210935682663;
    msg.z_units = 231U;
    msg.radius = 0.9270724249324334;
    msg.duration = 20066U;
    msg.speed = 0.3472283524725476;
    msg.speed_units = 113U;
    msg.popup_period = 50722U;
    msg.popup_duration = 31000U;
    msg.flags = 193U;
    msg.custom.assign("MVBVHNOFHAPMVPDKMIUOSGUTLMUZZNYLCMBQKVSNXBDKGPCXJYQPXOCLBASXGHNTMMDETKPFTWVQDSYSWCITRPXDECRYIWSXICSKEJEVPHELRORHKXVHDAQPANWQHDLJ");

    try
    {
      Utils::ByteBuffer bfr;
      IMC::Packet::serialize(&msg, bfr);
      IMC::Message* msg_d = IMC::Packet::deserialize(bfr.getBuffer(), bfr.getSize());
      test.boolean("StationKeepingExtended #1", msg == *msg_d);
      delete msg_d;
    }
    catch (IMC::InvalidMessageSize& e)
    {
      (void)e;
      test.boolean("msg #1", msg.getSerializationSize() > DUNE_IMC_CONST_MAX_SIZE);
    }
  }

  {
    IMC::StationKeepingExtended msg;
    msg.setTimeStamp(0.9839538636579614);
    msg.setSource(41109U);
    msg.setSourceEntity(25U);
    msg.setDestination(23526U);
    msg.setDestinationEntity(205U);
    msg.lat = 0.6551668407521607;
    msg.lon = 0.8305017956156652;
    msg.z = 0.7451255601368515;
    msg.z_units = 82U;
    msg.radius = 0.27729675615965155;
    msg.duration = 49465U;
    msg.speed = 0.1318240670526255;
    msg.speed_units = 151U;
    msg.popup_period = 35894U;
    msg.popup_duration = 58590U;
    msg.flags = 57U;
    msg.custom.assign("HAWEFQGFGXUVTGLQTXMONDQYJTIILIMDZPFWRAEXNCUEKXKKVRIXPUZMVYNINGEMCDQYOMJNBPAEOLIWVTEDAWOEQDAOHZFSBEEPDSUBLOCKUGEJWNQK");

    try
    {
      Utils::ByteBuffer bfr;
      IMC::Packet::serialize(&msg, bfr);
      IMC::Message* msg_d = IMC::Packet::deserialize(bfr.getBuffer(), bfr.getSize());
      test.boolean("StationKeepingExtended #2", msg == *msg_d);
      delete msg_d;
    }
    catch (IMC::InvalidMessageSize& e)
    {
      (void)e;
      test.boolean("msg #2", msg.getSerializationSize() > DUNE_IMC_CONST_MAX_SIZE);
    }
  }

  {
    IMC::ManeuverDone msg;
    msg.setTimeStamp(0.348272804572066);
    msg.setSource(13322U);
    msg.setSourceEntity(15U);
    msg.setDestination(3598U);
    msg.setDestinationEntity(79U);

    try
    {
      Utils::ByteBuffer bfr;
      IMC::Packet::serialize(&msg, bfr);
      IMC::Message* msg_d = IMC::Packet::deserialize(bfr.getBuffer(), bfr.getSize());
      test.boolean("ManeuverDone #0", msg == *msg_d);
      delete msg_d;
    }
    catch (IMC::InvalidMessageSize& e)
    {
      (void)e;
      test.boolean("msg #0", msg.getSerializationSize() > DUNE_IMC_CONST_MAX_SIZE);
    }
  }

  {
    IMC::ManeuverDone msg;
    msg.setTimeStamp(0.7341932003467637);
    msg.setSource(48948U);
    msg.setSourceEntity(105U);
    msg.setDestination(62326U);
    msg.setDestinationEntity(251U);

    try
    {
      Utils::ByteBuffer bfr;
      IMC::Packet::serialize(&msg, bfr);
      IMC::Message* msg_d = IMC::Packet::deserialize(bfr.getBuffer(), bfr.getSize());
      test.boolean("ManeuverDone #1", msg == *msg_d);
      delete msg_d;
    }
    catch (IMC::InvalidMessageSize& e)
    {
      (void)e;
      test.boolean("msg #1", msg.getSerializationSize() > DUNE_IMC_CONST_MAX_SIZE);
    }
  }

  {
    IMC::ManeuverDone msg;
    msg.setTimeStamp(0.4589628658915518);
    msg.setSource(52210U);
    msg.setSourceEntity(178U);
    msg.setDestination(25350U);
    msg.setDestinationEntity(0U);

    try
    {
      Utils::ByteBuffer bfr;
      IMC::Packet::serialize(&msg, bfr);
      IMC::Message* msg_d = IMC::Packet::deserialize(bfr.getBuffer(), bfr.getSize());
      test.boolean("ManeuverDone #2", msg == *msg_d);
      delete msg_d;
    }
    catch (IMC::InvalidMessageSize& e)
    {
      (void)e;
      test.boolean("msg #2", msg.getSerializationSize() > DUNE_IMC_CONST_MAX_SIZE);
    }
  }

  {
    IMC::Magnetometer msg;
    msg.setTimeStamp(0.4911495754834786);
    msg.setSource(59831U);
    msg.setSourceEntity(136U);
    msg.setDestination(51128U);
    msg.setDestinationEntity(8U);
    msg.timeout = 26436U;
    msg.lat = 0.44438665407692446;
    msg.lon = 0.4316594748800573;
    msg.z = 0.858384853619868;
    msg.z_units = 252U;
    msg.speed = 0.9782153659224124;
    msg.speed_units = 33U;
    msg.bearing = 0.20830545115677368;
    msg.width = 0.09817329505939743;
    msg.direction = 26U;
    msg.custom.assign("LVVPYYEUAEZGSOXWBBVKPPBDGRGTGRSDIODCUIRWVJZTMXWTNSHJMBFQQRNLUTXVYAALDBXFQEZUJUIKQAEJRUMIQUMHOSARTJXICPRMNCLIECLRDGPXKFFCHJZLEZBSVMKZKMNVFWHWASZQOESPNKBKLLYZYWSQKXCXPBFJWRXGBSTMAULTWWOJWKCAOHTYKZHOJINGTQ");

    try
    {
      Utils::ByteBuffer bfr;
      IMC::Packet::serialize(&msg, bfr);
      IMC::Message* msg_d = IMC::Packet::deserialize(bfr.getBuffer(), bfr.getSize());
      test.boolean("Magnetometer #0", msg == *msg_d);
      delete msg_d;
    }
    catch (IMC::InvalidMessageSize& e)
    {
      (void)e;
      test.boolean("msg #0", msg.getSerializationSize() > DUNE_IMC_CONST_MAX_SIZE);
    }
  }

  {
    IMC::Magnetometer msg;
    msg.setTimeStamp(0.6358601316108843);
    msg.setSource(12108U);
    msg.setSourceEntity(194U);
    msg.setDestination(29951U);
    msg.setDestinationEntity(149U);
    msg.timeout = 29420U;
    msg.lat = 0.1252450488459329;
    msg.lon = 0.21146466598217595;
    msg.z = 0.8546385379593628;
    msg.z_units = 170U;
    msg.speed = 0.4265497240244074;
    msg.speed_units = 4U;
    msg.bearing = 0.513361985642041;
    msg.width = 0.3232501030611644;
    msg.direction = 242U;
    msg.custom.assign("MVOGUDQGZPPGMMGHTMDJZZTAZOBQRVPAITHOFFYRJPSTBYIRQHYQPPILFQJFUVHTZNDASPTOGAXGKVVITCAMQUOWTOXEHMTNUUKLDNCYMYIEBZWQJGVRNOQFXVICYGGBLVFKWBKSVALRBCDRTLFRJRHURXXAEXGBERDNJEHJKBYCFJCINLOSEASNDESU");

    try
    {
      Utils::ByteBuffer bfr;
      IMC::Packet::serialize(&msg, bfr);
      IMC::Message* msg_d = IMC::Packet::deserialize(bfr.getBuffer(), bfr.getSize());
      test.boolean("Magnetometer #1", msg == *msg_d);
      delete msg_d;
    }
    catch (IMC::InvalidMessageSize& e)
    {
      (void)e;
      test.boolean("msg #1", msg.getSerializationSize() > DUNE_IMC_CONST_MAX_SIZE);
    }
  }

  {
    IMC::Magnetometer msg;
    msg.setTimeStamp(0.1538189296678235);
    msg.setSource(11501U);
    msg.setSourceEntity(103U);
    msg.setDestination(5225U);
    msg.setDestinationEntity(179U);
    msg.timeout = 61945U;
    msg.lat = 0.831876079086323;
    msg.lon = 0.1634518150879195;
    msg.z = 0.1554117503476211;
    msg.z_units = 158U;
    msg.speed = 0.3763270656001543;
    msg.speed_units = 49U;
    msg.bearing = 0.6230200341827118;
    msg.width = 0.4583799722942731;
    msg.direction = 152U;
    msg.custom.assign("GMJNFVOZEZEOFJWZHONXPKGHIJRCTOYMINVNDLHOJQFVXFOMZGFCEJBLAWWTPMTZCGLCNYKYAQYXLBORUSSVVYJVWTEFIMYETYRXPEQOYITULALMMUQPAAQBWGCXNUGJHLYGDBSIUBDCMBPWVDMARKHPOBKAXFXRIQCZSECSSKWPPZXJFKCEIQWQFHKNHBKCRLISWZHTZUMRFIDDRSEDJVRU");

    try
    {
      Utils::ByteBuffer bfr;
      IMC::Packet::serialize(&msg, bfr);
      IMC::Message* msg_d = IMC::Packet::deserialize(bfr.getBuffer(), bfr.getSize());
      test.boolean("Magnetometer #2", msg == *msg_d);
      delete msg_d;
    }
    catch (IMC::InvalidMessageSize& e)
    {
      (void)e;
      test.boolean("msg #2", msg.getSerializationSize() > DUNE_IMC_CONST_MAX_SIZE);
    }
  }

  {
    IMC::VehicleState msg;
    msg.setTimeStamp(0.8744322854581863);
    msg.setSource(18484U);
    msg.setSourceEntity(225U);
    msg.setDestination(29151U);
    msg.setDestinationEntity(132U);
    msg.op_mode = 71U;
    msg.error_count = 136U;
    msg.error_ents.assign("XPGGDNJJXUUGLULYKSUYGMFSVHTMQOWBRHIMUXKNALTOUDKVCDBFQCZDPDADMOUJVHW");
    msg.maneuver_type = 47517U;
    msg.maneuver_stime = 0.06064844728746732;
    msg.maneuver_eta = 37045U;
    msg.control_loops = 3355094774U;
    msg.flags = 27U;
    msg.last_error.assign("EDNVAITBDPXYILWVXIQRZAOLAVKIBWUSLLEICMBHBR");
    msg.last_error_time = 0.5972719007460308;

    try
    {
      Utils::ByteBuffer bfr;
      IMC::Packet::serialize(&msg, bfr);
      IMC::Message* msg_d = IMC::Packet::deserialize(bfr.getBuffer(), bfr.getSize());
      test.boolean("VehicleState #0", msg == *msg_d);
      delete msg_d;
    }
    catch (IMC::InvalidMessageSize& e)
    {
      (void)e;
      test.boolean("msg #0", msg.getSerializationSize() > DUNE_IMC_CONST_MAX_SIZE);
    }
  }

  {
    IMC::VehicleState msg;
    msg.setTimeStamp(0.023640449592991275);
    msg.setSource(40328U);
    msg.setSourceEntity(12U);
    msg.setDestination(55641U);
    msg.setDestinationEntity(20U);
    msg.op_mode = 20U;
    msg.error_count = 20U;
    msg.error_ents.assign("KQTPOJQNSEXEIFP");
    msg.maneuver_type = 22137U;
    msg.maneuver_stime = 0.9901825624216916;
    msg.maneuver_eta = 37395U;
    msg.control_loops = 3614928431U;
    msg.flags = 211U;
    msg.last_error.assign("LXXSHNZLMIKCLVRNCIVDCZYXSYJXPDQEEEEFKHGTXKLYJBUYUTNJKOMOU");
    msg.last_error_time = 0.0893322117733013;

    try
    {
      Utils::ByteBuffer bfr;
      IMC::Packet::serialize(&msg, bfr);
      IMC::Message* msg_d = IMC::Packet::deserialize(bfr.getBuffer(), bfr.getSize());
      test.boolean("VehicleState #1", msg == *msg_d);
      delete msg_d;
    }
    catch (IMC::InvalidMessageSize& e)
    {
      (void)e;
      test.boolean("msg #1", msg.getSerializationSize() > DUNE_IMC_CONST_MAX_SIZE);
    }
  }

  {
    IMC::VehicleState msg;
    msg.setTimeStamp(0.9852276027960569);
    msg.setSource(27606U);
    msg.setSourceEntity(237U);
    msg.setDestination(47851U);
    msg.setDestinationEntity(148U);
    msg.op_mode = 38U;
    msg.error_count = 72U;
    msg.error_ents.assign("FWQAJYNWEAEMTKZGRMVIRLGJWLLPIEOMPXZDOFYCYWZVQVRWMULJPZPBDUGBNSCJOMUAHPTBIXEDYJZIWLCRWFPBDCSYHNATTSRKWGCNUTQMUWLLMOCSFEUSVXHVQHPCKLSGYXEKTAZGNLEFDBTGZOXQDJAEEZPCXAFDMROSUINHGKIFNXDUSWPRFAVLVDKMBFAKOQYT");
    msg.maneuver_type = 40032U;
    msg.maneuver_stime = 0.07860684912775129;
    msg.maneuver_eta = 26530U;
    msg.control_loops = 2481010046U;
    msg.flags = 142U;
    msg.last_error.assign("DIFDAJBXPYYIREWUDEZJERLQMIJLMKCYWDZVYWTKPFICVLXUQAIUFSYGZHRABTOHGASZXMIZVSIJQLYRHNOJGZJROJWUAGNEVNBMSKMOKMORTWVUCCGSEDDMWBLOSUKNEOEHSTFEDGCRKJPOCWEZNBNLPQKNCAXQPXKFCTODPTIZQTANSUTSAPJTM");
    msg.last_error_time = 0.3603273178823846;

    try
    {
      Utils::ByteBuffer bfr;
      IMC::Packet::serialize(&msg, bfr);
      IMC::Message* msg_d = IMC::Packet::deserialize(bfr.getBuffer(), bfr.getSize());
      test.boolean("VehicleState #2", msg == *msg_d);
      delete msg_d;
    }
    catch (IMC::InvalidMessageSize& e)
    {
      (void)e;
      test.boolean("msg #2", msg.getSerializationSize() > DUNE_IMC_CONST_MAX_SIZE);
    }
  }

  {
    IMC::VehicleCommand msg;
    msg.setTimeStamp(0.1007665357168348);
    msg.setSource(33967U);
    msg.setSourceEntity(73U);
    msg.setDestination(35792U);
    msg.setDestinationEntity(235U);
    msg.type = 124U;
    msg.request_id = 56271U;
    msg.command = 118U;
    IMC::CompassCalibration tmp_msg_0;
    tmp_msg_0.timeout = 57225U;
    tmp_msg_0.lat = 0.9362286243380825;
    tmp_msg_0.lon = 0.21858951194118037;
    tmp_msg_0.z = 0.11577256996658614;
    tmp_msg_0.z_units = 78U;
    tmp_msg_0.pitch = 0.25766130087311234;
    tmp_msg_0.amplitude = 0.6474987548156605;
    tmp_msg_0.duration = 41531U;
    tmp_msg_0.speed = 0.7427396701227786;
    tmp_msg_0.speed_units = 181U;
    tmp_msg_0.radius = 0.07552121973397641;
    tmp_msg_0.direction = 42U;
    tmp_msg_0.custom.assign("RMNAUZGNGYMQRYZVGARYIJLHLXQLHPPJIKAAZWPGOEVODIWYABWQVXGODHDNTWACSBGMDYVUWSJFBDGWAXMPDXMJFJPQEJSKSAMJCNOZOTSGBESPRVKULKMCXEHDKAENFTDIEORZTUKFSXIDVHZKCDVOC");
    msg.maneuver.set(tmp_msg_0);
    msg.calib_time = 54272U;
    msg.info.assign("RCJNRLVPILZCBGDJHEHLWVTBEBLPNFVHTMJTECRWSSXSDQZIHJZQR");

    try
    {
      Utils::ByteBuffer bfr;
      IMC::Packet::serialize(&msg, bfr);
      IMC::Message* msg_d = IMC::Packet::deserialize(bfr.getBuffer(), bfr.getSize());
      test.boolean("VehicleCommand #0", msg == *msg_d);
      delete msg_d;
    }
    catch (IMC::InvalidMessageSize& e)
    {
      (void)e;
      test.boolean("msg #0", msg.getSerializationSize() > DUNE_IMC_CONST_MAX_SIZE);
    }
  }

  {
    IMC::VehicleCommand msg;
    msg.setTimeStamp(0.23150955673373486);
    msg.setSource(11825U);
    msg.setSourceEntity(35U);
    msg.setDestination(39911U);
    msg.setDestinationEntity(44U);
    msg.type = 101U;
    msg.request_id = 11820U;
    msg.command = 12U;
    IMC::FollowReference tmp_msg_0;
    tmp_msg_0.control_src = 41048U;
    tmp_msg_0.control_ent = 235U;
    tmp_msg_0.timeout = 0.7300849315288999;
    tmp_msg_0.loiter_radius = 0.17151784027251138;
    tmp_msg_0.altitude_interval = 0.8513626610510425;
    msg.maneuver.set(tmp_msg_0);
    msg.calib_time = 44039U;
    msg.info.assign("HAZWJBQRWKPRCTYJIREAJFULEUQYANHECZVBTPETCTDKOUYSFWVSISUSVGDAMJNMWYLSOXEGJGTIOVEOKPGXZCNXMEQKUZUKMUHXRLJJGPHZOQDZDBSAHNNQLGTQKGWWKVHKFNAVMIOLGDYXFBQPYXWDMUCXPONAXVXBBBDHHNQFEGIBNEMAICLCKPRLIRDVHVYZOTGSQRLJBFXAACFOMETSYDIYPJPHLIKZDTZFWFFOSVPBZRUQ");

    try
    {
      Utils::ByteBuffer bfr;
      IMC::Packet::serialize(&msg, bfr);
      IMC::Message* msg_d = IMC::Packet::deserialize(bfr.getBuffer(), bfr.getSize());
      test.boolean("VehicleCommand #1", msg == *msg_d);
      delete msg_d;
    }
    catch (IMC::InvalidMessageSize& e)
    {
      (void)e;
      test.boolean("msg #1", msg.getSerializationSize() > DUNE_IMC_CONST_MAX_SIZE);
    }
  }

  {
    IMC::VehicleCommand msg;
    msg.setTimeStamp(0.6502823194461056);
    msg.setSource(35653U);
    msg.setSourceEntity(23U);
    msg.setDestination(27436U);
    msg.setDestinationEntity(185U);
    msg.type = 227U;
    msg.request_id = 48033U;
    msg.command = 123U;
    IMC::StationKeepingExtended tmp_msg_0;
    tmp_msg_0.lat = 0.16299452134018433;
    tmp_msg_0.lon = 0.4421761872022266;
    tmp_msg_0.z = 0.8568736365952655;
    tmp_msg_0.z_units = 185U;
    tmp_msg_0.radius = 0.83887939076644;
    tmp_msg_0.duration = 42405U;
    tmp_msg_0.speed = 0.8045784086142721;
    tmp_msg_0.speed_units = 83U;
    tmp_msg_0.popup_period = 21933U;
    tmp_msg_0.popup_duration = 16442U;
    tmp_msg_0.flags = 66U;
    tmp_msg_0.custom.assign("JRCXPZIZHZXFHFNRLASVETRUEXQKQGREGMMUZFIPHMBSVOPGAMFCZKDWAFLHXDMCZBDUILPDDNBTVYCFNNEANGOOTKNOGJGFYKHOOECRUWKBYYVTSFRBNCBTVZD");
    msg.maneuver.set(tmp_msg_0);
    msg.calib_time = 50476U;
    msg.info.assign("RSTQQHPAOAJIVKKQUYYGCGHULVKDWUQOTPJFJKDPZSEZHLVITFSXHCZWUIQRJTFGWLKVMNEETHPHHIDMSWSRAMECFMWGZIOARSWNEUBSTLVFBQKMNEEXDHGBANCEOGORCWIZVTXYNLPJMPHPIRJYLQUUGJRONGRYGKLBJCYUQXTFMCBBGOMJDXURHTVDNRWTIVOZECXSYIABAKFSIVNSZLKXZJXPNNBXZAWVUFPOYYZDQYC");

    try
    {
      Utils::ByteBuffer bfr;
      IMC::Packet::serialize(&msg, bfr);
      IMC::Message* msg_d = IMC::Packet::deserialize(bfr.getBuffer(), bfr.getSize());
      test.boolean("VehicleCommand #2", msg == *msg_d);
      delete msg_d;
    }
    catch (IMC::InvalidMessageSize& e)
    {
      (void)e;
      test.boolean("msg #2", msg.getSerializationSize() > DUNE_IMC_CONST_MAX_SIZE);
    }
  }

  {
    IMC::MonitorEntityState msg;
    msg.setTimeStamp(0.8791471527060439);
    msg.setSource(11449U);
    msg.setSourceEntity(92U);
    msg.setDestination(56520U);
    msg.setDestinationEntity(119U);
    msg.command = 107U;
    msg.entities.assign("JNMGSPNRDOBFTRCTYYTKURXEJUHOQQFLGPFSPOIZWYABLLVFBEVWNTFXSBIFYAMIFBPMIEKEARZMZDKWOHJHLNMCYTBTNVNHYPQFLZLRULHVMVZDDIUPEQKOUIYIORUJNQQJKGOCKOCOANAUXZHBUESZBYIHZXTDFTXDOMJGGCSGSQRJBVGZSPSJMDCWUDEKAWDPLCGKJPCXXFRRLQHKANSQAXRVEIWVCLVHWU");

    try
    {
      Utils::ByteBuffer bfr;
      IMC::Packet::serialize(&msg, bfr);
      IMC::Message* msg_d = IMC::Packet::deserialize(bfr.getBuffer(), bfr.getSize());
      test.boolean("MonitorEntityState #0", msg == *msg_d);
      delete msg_d;
    }
    catch (IMC::InvalidMessageSize& e)
    {
      (void)e;
      test.boolean("msg #0", msg.getSerializationSize() > DUNE_IMC_CONST_MAX_SIZE);
    }
  }

  {
    IMC::MonitorEntityState msg;
    msg.setTimeStamp(0.24709737848347002);
    msg.setSource(50583U);
    msg.setSourceEntity(254U);
    msg.setDestination(54004U);
    msg.setDestinationEntity(235U);
    msg.command = 185U;
    msg.entities.assign("ZEQXHLZXMTCTQSWHEHDHDJMETLMGAEJSCFUZRAENQRIGPZAQIVSIJGTQSXPPFKHLIOVUKCCXIZAHYQBKNVSCZQSECFGDWOOXULTODUWABYDYJOMFNSVIQCGBOLTORPUAWONMGFXWKRWYLDBJSRVBFKJYRJHYAFPSXGVUAMRPNWQHKXELUNZBVANMHUQFKGUPIDCMYTPYMPHDJBRVEPNTIUOWWABZOKTRYDNLIKZ");

    try
    {
      Utils::ByteBuffer bfr;
      IMC::Packet::serialize(&msg, bfr);
      IMC::Message* msg_d = IMC::Packet::deserialize(bfr.getBuffer(), bfr.getSize());
      test.boolean("MonitorEntityState #1", msg == *msg_d);
      delete msg_d;
    }
    catch (IMC::InvalidMessageSize& e)
    {
      (void)e;
      test.boolean("msg #1", msg.getSerializationSize() > DUNE_IMC_CONST_MAX_SIZE);
    }
  }

  {
    IMC::MonitorEntityState msg;
    msg.setTimeStamp(0.9572371315605996);
    msg.setSource(38329U);
    msg.setSourceEntity(222U);
    msg.setDestination(25852U);
    msg.setDestinationEntity(46U);
    msg.command = 179U;
    msg.entities.assign("OSUTBEYEVBXYDIJMKPKURYKIYTDO");

    try
    {
      Utils::ByteBuffer bfr;
      IMC::Packet::serialize(&msg, bfr);
      IMC::Message* msg_d = IMC::Packet::deserialize(bfr.getBuffer(), bfr.getSize());
      test.boolean("MonitorEntityState #2", msg == *msg_d);
      delete msg_d;
    }
    catch (IMC::InvalidMessageSize& e)
    {
      (void)e;
      test.boolean("msg #2", msg.getSerializationSize() > DUNE_IMC_CONST_MAX_SIZE);
    }
  }

  {
    IMC::EntityMonitoringState msg;
    msg.setTimeStamp(0.6046037991896859);
    msg.setSource(26075U);
    msg.setSourceEntity(8U);
    msg.setDestination(40828U);
    msg.setDestinationEntity(146U);
    msg.mcount = 174U;
    msg.mnames.assign("WESBXOZRLMSAUFGXCZGJHQYQZNESORFYPTYPXNTSEUIVZJIFMWLTNRVXTWILUAYYLFDEWARDJGOQPGPBPNBPBKCKODPRQLIQHSIGMCJMTLSBDYZXLKZWOTGMXVDDKSRMGJAKNWGSUKOCUINUDVDDUEJBBTVCHCHJZE");
    msg.ecount = 63U;
    msg.enames.assign("YVFVZHKQAKCSGLFNDY");
    msg.ccount = 218U;
    msg.cnames.assign("UQPIJPJPVVAZIFIEFHELWOESCRMYNIFNLPLCVLKMCDOSOFGNIYJHGUCDEDGABSMRWZUPTRKTQSTRNHHTLZMZVYAACCJQBTLEHGLKWWQUIVUYKVHAMYSWQABBPKEBUAVJWHGJBRSRGPDSCWREDXFBKVWHEZPNCYNYZIDSTKDFODPTNQXLMTLBIFDLFQXEZQRUKQHYOXCXORAXNHIONKIXJVZBFGJZAQZSMXXGPTWJW");
    msg.last_error.assign("FAJVYEFSEGCOWCUPOTVTSFHMXMUENVXMAEUZCAYCZNGFCKTCJLXISYTQPBBHWSOTDRVLQLUQWZQPYOHIMAEBPDRNYOYNHYDRBMXDMYDQAVAMIWJYCGRRCXWWHPWUUXLQZOEGJJGEBGRSHJKSFXNZXPLKQQFLVGZKHGWFNHJVHGNJERNUCSBIKVKPUJZILWARLQOYKANAOCJILHRNEAIFTSBTSKBBMEPVDGTDFDKZUZOFZOQISKDWXBMXITIDV");
    msg.last_error_time = 0.8381872918176537;

    try
    {
      Utils::ByteBuffer bfr;
      IMC::Packet::serialize(&msg, bfr);
      IMC::Message* msg_d = IMC::Packet::deserialize(bfr.getBuffer(), bfr.getSize());
      test.boolean("EntityMonitoringState #0", msg == *msg_d);
      delete msg_d;
    }
    catch (IMC::InvalidMessageSize& e)
    {
      (void)e;
      test.boolean("msg #0", msg.getSerializationSize() > DUNE_IMC_CONST_MAX_SIZE);
    }
  }

  {
    IMC::EntityMonitoringState msg;
    msg.setTimeStamp(0.0337559577221066);
    msg.setSource(20224U);
    msg.setSourceEntity(202U);
    msg.setDestination(20164U);
    msg.setDestinationEntity(14U);
    msg.mcount = 182U;
    msg.mnames.assign("HVKTIHNEYRCEXCLXKBRDQSUYUVNTBKGMPCWCOCVRLGZZWYQJEARMAZANPBUBDOLGYPZHFIKTSPAMDKPUMDECXWJJRDRSNJGBWJFFSTQCXBKSJWSPEAWINJTIWJCTFBIMDGYMVDZYZHGORMGVQCKWPIDAEBZGFENZXXUVAOIRNKPSLURSHFOUGSRV");
    msg.ecount = 98U;
    msg.enames.assign("MDQXZZKSEPIAIWFTNSDFQVSTXDWUTFLKDSFPAFWDTYZCGZNOQIGPVWHA");
    msg.ccount = 219U;
    msg.cnames.assign("YCYDDELFCKNGIFPILPABMUXUBZJUROKBVVANRLEZGWCIDKFWKYLQWQGUTMZXKIPSFPYWBSCPHLFXQWBBNJTWWVMSNPTNHVTSKUEPUONZMDLTZJJSCAPADDJ");
    msg.last_error.assign("ZWWPTQTVYZTFCZDYKNEUCROVAJZISXXOEFIYWTWMBTALPCEVMDVSLHDCFCAWLCFFRCKPBHQGPBZKCYADTAQYYRDILCJMGEKBGPYIZWRFGKRPOHOLPEMIHJAAQLRVMOURNXIVGONDSDKOLMJNVNTUJAUTUPIEMNBIHXPBJOUCEQBVZBJHGFZYWGWMTNZBUOAUKMHNVXZHAU");
    msg.last_error_time = 0.21258457690731658;

    try
    {
      Utils::ByteBuffer bfr;
      IMC::Packet::serialize(&msg, bfr);
      IMC::Message* msg_d = IMC::Packet::deserialize(bfr.getBuffer(), bfr.getSize());
      test.boolean("EntityMonitoringState #1", msg == *msg_d);
      delete msg_d;
    }
    catch (IMC::InvalidMessageSize& e)
    {
      (void)e;
      test.boolean("msg #1", msg.getSerializationSize() > DUNE_IMC_CONST_MAX_SIZE);
    }
  }

  {
    IMC::EntityMonitoringState msg;
    msg.setTimeStamp(0.8314899828083203);
    msg.setSource(47901U);
    msg.setSourceEntity(20U);
    msg.setDestination(65311U);
    msg.setDestinationEntity(206U);
    msg.mcount = 211U;
    msg.mnames.assign("VLQSUCNEWCCFNPPVWWSSYKGMHHNUQMEZBNNLZQBYGEOKMIQEBUCOJVRFZUVW");
    msg.ecount = 42U;
    msg.enames.assign("NYKYQFPLVSFQGBFGOWSAFOEBRTWAXEXERWJOHAUUWWKIGSLHRIDFS");
    msg.ccount = 216U;
    msg.cnames.assign("XXTXTUAQEKQ");
    msg.last_error.assign("VJPHSSUPVSEBZCLHTBMAAFRXWXBCNSKAJRIYECQIMNOTNIOJHELKYHIULPRHKOCVROCSZATVIOOMLXYQSSJSAZJGPLLPQQZSTEBEOJUYMWDXUGGICJLFYWNPRZIMRKJVNQYPWWABQTWBHRAUDMALFFF");
    msg.last_error_time = 0.351059441295149;

    try
    {
      Utils::ByteBuffer bfr;
      IMC::Packet::serialize(&msg, bfr);
      IMC::Message* msg_d = IMC::Packet::deserialize(bfr.getBuffer(), bfr.getSize());
      test.boolean("EntityMonitoringState #2", msg == *msg_d);
      delete msg_d;
    }
    catch (IMC::InvalidMessageSize& e)
    {
      (void)e;
      test.boolean("msg #2", msg.getSerializationSize() > DUNE_IMC_CONST_MAX_SIZE);
    }
  }

  {
    IMC::OperationalLimits msg;
    msg.setTimeStamp(0.09179537190655729);
    msg.setSource(2562U);
    msg.setSourceEntity(46U);
    msg.setDestination(16296U);
    msg.setDestinationEntity(199U);
    msg.mask = 125U;
    msg.max_depth = 0.33536554847483924;
    msg.min_altitude = 0.12569105593158614;
    msg.max_altitude = 0.37756860281839455;
    msg.min_speed = 0.332303189703128;
    msg.max_speed = 0.24055438167474652;
    msg.max_vrate = 0.007006848633751117;
    msg.lat = 0.24769089357275764;
    msg.lon = 0.5887715250285374;
    msg.orientation = 0.6948866881813722;
    msg.width = 0.495399679267418;
    msg.length = 0.11297197394110003;

    try
    {
      Utils::ByteBuffer bfr;
      IMC::Packet::serialize(&msg, bfr);
      IMC::Message* msg_d = IMC::Packet::deserialize(bfr.getBuffer(), bfr.getSize());
      test.boolean("OperationalLimits #0", msg == *msg_d);
      delete msg_d;
    }
    catch (IMC::InvalidMessageSize& e)
    {
      (void)e;
      test.boolean("msg #0", msg.getSerializationSize() > DUNE_IMC_CONST_MAX_SIZE);
    }
  }

  {
    IMC::OperationalLimits msg;
    msg.setTimeStamp(0.9156641094599619);
    msg.setSource(62275U);
    msg.setSourceEntity(35U);
    msg.setDestination(23956U);
    msg.setDestinationEntity(101U);
    msg.mask = 174U;
    msg.max_depth = 0.4793452549645406;
    msg.min_altitude = 0.9841799062763625;
    msg.max_altitude = 0.14095252760093469;
    msg.min_speed = 0.601515944368228;
    msg.max_speed = 0.40656123651276865;
    msg.max_vrate = 0.6639661856386474;
    msg.lat = 0.028713162666166303;
    msg.lon = 0.31269230588474406;
    msg.orientation = 0.915599062264928;
    msg.width = 0.8351465079961058;
    msg.length = 0.9090013616106225;

    try
    {
      Utils::ByteBuffer bfr;
      IMC::Packet::serialize(&msg, bfr);
      IMC::Message* msg_d = IMC::Packet::deserialize(bfr.getBuffer(), bfr.getSize());
      test.boolean("OperationalLimits #1", msg == *msg_d);
      delete msg_d;
    }
    catch (IMC::InvalidMessageSize& e)
    {
      (void)e;
      test.boolean("msg #1", msg.getSerializationSize() > DUNE_IMC_CONST_MAX_SIZE);
    }
  }

  {
    IMC::OperationalLimits msg;
    msg.setTimeStamp(0.15894556243074554);
    msg.setSource(6483U);
    msg.setSourceEntity(40U);
    msg.setDestination(9831U);
    msg.setDestinationEntity(182U);
    msg.mask = 155U;
    msg.max_depth = 0.3172330397428391;
    msg.min_altitude = 0.30941978369458356;
    msg.max_altitude = 0.6819208615473463;
    msg.min_speed = 0.09550140119628903;
    msg.max_speed = 0.19082367877794104;
    msg.max_vrate = 0.8095213909541024;
    msg.lat = 0.6593392426956936;
    msg.lon = 0.12322893914900734;
    msg.orientation = 0.8392955228813878;
    msg.width = 0.13641921785051814;
    msg.length = 0.33611598064036163;

    try
    {
      Utils::ByteBuffer bfr;
      IMC::Packet::serialize(&msg, bfr);
      IMC::Message* msg_d = IMC::Packet::deserialize(bfr.getBuffer(), bfr.getSize());
      test.boolean("OperationalLimits #2", msg == *msg_d);
      delete msg_d;
    }
    catch (IMC::InvalidMessageSize& e)
    {
      (void)e;
      test.boolean("msg #2", msg.getSerializationSize() > DUNE_IMC_CONST_MAX_SIZE);
    }
  }

  {
    IMC::GetOperationalLimits msg;
    msg.setTimeStamp(0.6431846441593744);
    msg.setSource(37626U);
    msg.setSourceEntity(139U);
    msg.setDestination(44265U);
    msg.setDestinationEntity(32U);

    try
    {
      Utils::ByteBuffer bfr;
      IMC::Packet::serialize(&msg, bfr);
      IMC::Message* msg_d = IMC::Packet::deserialize(bfr.getBuffer(), bfr.getSize());
      test.boolean("GetOperationalLimits #0", msg == *msg_d);
      delete msg_d;
    }
    catch (IMC::InvalidMessageSize& e)
    {
      (void)e;
      test.boolean("msg #0", msg.getSerializationSize() > DUNE_IMC_CONST_MAX_SIZE);
    }
  }

  {
    IMC::GetOperationalLimits msg;
    msg.setTimeStamp(0.8776585291338372);
    msg.setSource(64436U);
    msg.setSourceEntity(0U);
    msg.setDestination(19466U);
    msg.setDestinationEntity(89U);

    try
    {
      Utils::ByteBuffer bfr;
      IMC::Packet::serialize(&msg, bfr);
      IMC::Message* msg_d = IMC::Packet::deserialize(bfr.getBuffer(), bfr.getSize());
      test.boolean("GetOperationalLimits #1", msg == *msg_d);
      delete msg_d;
    }
    catch (IMC::InvalidMessageSize& e)
    {
      (void)e;
      test.boolean("msg #1", msg.getSerializationSize() > DUNE_IMC_CONST_MAX_SIZE);
    }
  }

  {
    IMC::GetOperationalLimits msg;
    msg.setTimeStamp(0.14363611970775303);
    msg.setSource(16989U);
    msg.setSourceEntity(26U);
    msg.setDestination(23522U);
    msg.setDestinationEntity(250U);

    try
    {
      Utils::ByteBuffer bfr;
      IMC::Packet::serialize(&msg, bfr);
      IMC::Message* msg_d = IMC::Packet::deserialize(bfr.getBuffer(), bfr.getSize());
      test.boolean("GetOperationalLimits #2", msg == *msg_d);
      delete msg_d;
    }
    catch (IMC::InvalidMessageSize& e)
    {
      (void)e;
      test.boolean("msg #2", msg.getSerializationSize() > DUNE_IMC_CONST_MAX_SIZE);
    }
  }

  {
    IMC::Calibration msg;
    msg.setTimeStamp(0.07486166276810913);
    msg.setSource(57082U);
    msg.setSourceEntity(86U);
    msg.setDestination(33167U);
    msg.setDestinationEntity(167U);
    msg.duration = 41644U;

    try
    {
      Utils::ByteBuffer bfr;
      IMC::Packet::serialize(&msg, bfr);
      IMC::Message* msg_d = IMC::Packet::deserialize(bfr.getBuffer(), bfr.getSize());
      test.boolean("Calibration #0", msg == *msg_d);
      delete msg_d;
    }
    catch (IMC::InvalidMessageSize& e)
    {
      (void)e;
      test.boolean("msg #0", msg.getSerializationSize() > DUNE_IMC_CONST_MAX_SIZE);
    }
  }

  {
    IMC::Calibration msg;
    msg.setTimeStamp(0.4641392726164584);
    msg.setSource(9506U);
    msg.setSourceEntity(195U);
    msg.setDestination(59449U);
    msg.setDestinationEntity(87U);
    msg.duration = 29861U;

    try
    {
      Utils::ByteBuffer bfr;
      IMC::Packet::serialize(&msg, bfr);
      IMC::Message* msg_d = IMC::Packet::deserialize(bfr.getBuffer(), bfr.getSize());
      test.boolean("Calibration #1", msg == *msg_d);
      delete msg_d;
    }
    catch (IMC::InvalidMessageSize& e)
    {
      (void)e;
      test.boolean("msg #1", msg.getSerializationSize() > DUNE_IMC_CONST_MAX_SIZE);
    }
  }

  {
    IMC::Calibration msg;
    msg.setTimeStamp(0.613229057046783);
    msg.setSource(63497U);
    msg.setSourceEntity(93U);
    msg.setDestination(26070U);
    msg.setDestinationEntity(103U);
    msg.duration = 41544U;

    try
    {
      Utils::ByteBuffer bfr;
      IMC::Packet::serialize(&msg, bfr);
      IMC::Message* msg_d = IMC::Packet::deserialize(bfr.getBuffer(), bfr.getSize());
      test.boolean("Calibration #2", msg == *msg_d);
      delete msg_d;
    }
    catch (IMC::InvalidMessageSize& e)
    {
      (void)e;
      test.boolean("msg #2", msg.getSerializationSize() > DUNE_IMC_CONST_MAX_SIZE);
    }
  }

  {
    IMC::ControlLoops msg;
    msg.setTimeStamp(0.20827496011773283);
    msg.setSource(41764U);
    msg.setSourceEntity(147U);
    msg.setDestination(42370U);
    msg.setDestinationEntity(223U);
    msg.enable = 97U;
    msg.mask = 4190747307U;
    msg.scope_ref = 604899367U;

    try
    {
      Utils::ByteBuffer bfr;
      IMC::Packet::serialize(&msg, bfr);
      IMC::Message* msg_d = IMC::Packet::deserialize(bfr.getBuffer(), bfr.getSize());
      test.boolean("ControlLoops #0", msg == *msg_d);
      delete msg_d;
    }
    catch (IMC::InvalidMessageSize& e)
    {
      (void)e;
      test.boolean("msg #0", msg.getSerializationSize() > DUNE_IMC_CONST_MAX_SIZE);
    }
  }

  {
    IMC::ControlLoops msg;
    msg.setTimeStamp(0.8646140901157928);
    msg.setSource(24645U);
    msg.setSourceEntity(14U);
    msg.setDestination(53208U);
    msg.setDestinationEntity(238U);
    msg.enable = 204U;
    msg.mask = 3490374036U;
    msg.scope_ref = 4041841381U;

    try
    {
      Utils::ByteBuffer bfr;
      IMC::Packet::serialize(&msg, bfr);
      IMC::Message* msg_d = IMC::Packet::deserialize(bfr.getBuffer(), bfr.getSize());
      test.boolean("ControlLoops #1", msg == *msg_d);
      delete msg_d;
    }
    catch (IMC::InvalidMessageSize& e)
    {
      (void)e;
      test.boolean("msg #1", msg.getSerializationSize() > DUNE_IMC_CONST_MAX_SIZE);
    }
  }

  {
    IMC::ControlLoops msg;
    msg.setTimeStamp(0.2896666187990887);
    msg.setSource(173U);
    msg.setSourceEntity(220U);
    msg.setDestination(22200U);
    msg.setDestinationEntity(236U);
    msg.enable = 113U;
    msg.mask = 3479460765U;
    msg.scope_ref = 2704788237U;

    try
    {
      Utils::ByteBuffer bfr;
      IMC::Packet::serialize(&msg, bfr);
      IMC::Message* msg_d = IMC::Packet::deserialize(bfr.getBuffer(), bfr.getSize());
      test.boolean("ControlLoops #2", msg == *msg_d);
      delete msg_d;
    }
    catch (IMC::InvalidMessageSize& e)
    {
      (void)e;
      test.boolean("msg #2", msg.getSerializationSize() > DUNE_IMC_CONST_MAX_SIZE);
    }
  }

  {
    IMC::VehicleMedium msg;
    msg.setTimeStamp(0.42652331719578684);
    msg.setSource(58720U);
    msg.setSourceEntity(20U);
    msg.setDestination(46500U);
    msg.setDestinationEntity(153U);
    msg.medium = 67U;

    try
    {
      Utils::ByteBuffer bfr;
      IMC::Packet::serialize(&msg, bfr);
      IMC::Message* msg_d = IMC::Packet::deserialize(bfr.getBuffer(), bfr.getSize());
      test.boolean("VehicleMedium #0", msg == *msg_d);
      delete msg_d;
    }
    catch (IMC::InvalidMessageSize& e)
    {
      (void)e;
      test.boolean("msg #0", msg.getSerializationSize() > DUNE_IMC_CONST_MAX_SIZE);
    }
  }

  {
    IMC::VehicleMedium msg;
    msg.setTimeStamp(0.05329681744849668);
    msg.setSource(3938U);
    msg.setSourceEntity(229U);
    msg.setDestination(8149U);
    msg.setDestinationEntity(17U);
    msg.medium = 181U;

    try
    {
      Utils::ByteBuffer bfr;
      IMC::Packet::serialize(&msg, bfr);
      IMC::Message* msg_d = IMC::Packet::deserialize(bfr.getBuffer(), bfr.getSize());
      test.boolean("VehicleMedium #1", msg == *msg_d);
      delete msg_d;
    }
    catch (IMC::InvalidMessageSize& e)
    {
      (void)e;
      test.boolean("msg #1", msg.getSerializationSize() > DUNE_IMC_CONST_MAX_SIZE);
    }
  }

  {
    IMC::VehicleMedium msg;
    msg.setTimeStamp(0.20398757875350815);
    msg.setSource(48166U);
    msg.setSourceEntity(78U);
    msg.setDestination(46713U);
    msg.setDestinationEntity(244U);
    msg.medium = 10U;

    try
    {
      Utils::ByteBuffer bfr;
      IMC::Packet::serialize(&msg, bfr);
      IMC::Message* msg_d = IMC::Packet::deserialize(bfr.getBuffer(), bfr.getSize());
      test.boolean("VehicleMedium #2", msg == *msg_d);
      delete msg_d;
    }
    catch (IMC::InvalidMessageSize& e)
    {
      (void)e;
      test.boolean("msg #2", msg.getSerializationSize() > DUNE_IMC_CONST_MAX_SIZE);
    }
  }

  {
    IMC::Collision msg;
    msg.setTimeStamp(0.3541691114646912);
    msg.setSource(5160U);
    msg.setSourceEntity(200U);
    msg.setDestination(61891U);
    msg.setDestinationEntity(60U);
    msg.value = 0.0944553784256077;
    msg.type = 175U;

    try
    {
      Utils::ByteBuffer bfr;
      IMC::Packet::serialize(&msg, bfr);
      IMC::Message* msg_d = IMC::Packet::deserialize(bfr.getBuffer(), bfr.getSize());
      test.boolean("Collision #0", msg == *msg_d);
      delete msg_d;
    }
    catch (IMC::InvalidMessageSize& e)
    {
      (void)e;
      test.boolean("msg #0", msg.getSerializationSize() > DUNE_IMC_CONST_MAX_SIZE);
    }
  }

  {
    IMC::Collision msg;
    msg.setTimeStamp(0.27913816668830027);
    msg.setSource(52616U);
    msg.setSourceEntity(43U);
    msg.setDestination(45656U);
    msg.setDestinationEntity(19U);
    msg.value = 0.610279277458507;
    msg.type = 15U;

    try
    {
      Utils::ByteBuffer bfr;
      IMC::Packet::serialize(&msg, bfr);
      IMC::Message* msg_d = IMC::Packet::deserialize(bfr.getBuffer(), bfr.getSize());
      test.boolean("Collision #1", msg == *msg_d);
      delete msg_d;
    }
    catch (IMC::InvalidMessageSize& e)
    {
      (void)e;
      test.boolean("msg #1", msg.getSerializationSize() > DUNE_IMC_CONST_MAX_SIZE);
    }
  }

  {
    IMC::Collision msg;
    msg.setTimeStamp(0.39083167672782515);
    msg.setSource(11344U);
    msg.setSourceEntity(199U);
    msg.setDestination(21179U);
    msg.setDestinationEntity(107U);
    msg.value = 0.10533938313388724;
    msg.type = 123U;

    try
    {
      Utils::ByteBuffer bfr;
      IMC::Packet::serialize(&msg, bfr);
      IMC::Message* msg_d = IMC::Packet::deserialize(bfr.getBuffer(), bfr.getSize());
      test.boolean("Collision #2", msg == *msg_d);
      delete msg_d;
    }
    catch (IMC::InvalidMessageSize& e)
    {
      (void)e;
      test.boolean("msg #2", msg.getSerializationSize() > DUNE_IMC_CONST_MAX_SIZE);
    }
  }

  {
    IMC::FormState msg;
    msg.setTimeStamp(0.5340125457473301);
    msg.setSource(38376U);
    msg.setSourceEntity(123U);
    msg.setDestination(54777U);
    msg.setDestinationEntity(42U);
    msg.possimerr = 0.44391501855504345;
    msg.converg = 0.9263481551107381;
    msg.turbulence = 0.14604272185085265;
    msg.possimmon = 14U;
    msg.commmon = 202U;
    msg.convergmon = 129U;

    try
    {
      Utils::ByteBuffer bfr;
      IMC::Packet::serialize(&msg, bfr);
      IMC::Message* msg_d = IMC::Packet::deserialize(bfr.getBuffer(), bfr.getSize());
      test.boolean("FormState #0", msg == *msg_d);
      delete msg_d;
    }
    catch (IMC::InvalidMessageSize& e)
    {
      (void)e;
      test.boolean("msg #0", msg.getSerializationSize() > DUNE_IMC_CONST_MAX_SIZE);
    }
  }

  {
    IMC::FormState msg;
    msg.setTimeStamp(0.7626597552324047);
    msg.setSource(48010U);
    msg.setSourceEntity(150U);
    msg.setDestination(38628U);
    msg.setDestinationEntity(247U);
    msg.possimerr = 0.4134343796566927;
    msg.converg = 0.30972961009482136;
    msg.turbulence = 0.8413037448849984;
    msg.possimmon = 238U;
    msg.commmon = 54U;
    msg.convergmon = 94U;

    try
    {
      Utils::ByteBuffer bfr;
      IMC::Packet::serialize(&msg, bfr);
      IMC::Message* msg_d = IMC::Packet::deserialize(bfr.getBuffer(), bfr.getSize());
      test.boolean("FormState #1", msg == *msg_d);
      delete msg_d;
    }
    catch (IMC::InvalidMessageSize& e)
    {
      (void)e;
      test.boolean("msg #1", msg.getSerializationSize() > DUNE_IMC_CONST_MAX_SIZE);
    }
  }

  {
    IMC::FormState msg;
    msg.setTimeStamp(0.24356756887911324);
    msg.setSource(27740U);
    msg.setSourceEntity(28U);
    msg.setDestination(64428U);
    msg.setDestinationEntity(234U);
    msg.possimerr = 0.7188688623351436;
    msg.converg = 0.2948495532119887;
    msg.turbulence = 0.8331599713112334;
    msg.possimmon = 41U;
    msg.commmon = 24U;
    msg.convergmon = 158U;

    try
    {
      Utils::ByteBuffer bfr;
      IMC::Packet::serialize(&msg, bfr);
      IMC::Message* msg_d = IMC::Packet::deserialize(bfr.getBuffer(), bfr.getSize());
      test.boolean("FormState #2", msg == *msg_d);
      delete msg_d;
    }
    catch (IMC::InvalidMessageSize& e)
    {
      (void)e;
      test.boolean("msg #2", msg.getSerializationSize() > DUNE_IMC_CONST_MAX_SIZE);
    }
  }

  {
    IMC::AutopilotMode msg;
    msg.setTimeStamp(0.060187271142112975);
    msg.setSource(25328U);
    msg.setSourceEntity(228U);
    msg.setDestination(56526U);
    msg.setDestinationEntity(228U);
    msg.autonomy = 94U;
    msg.mode.assign("UXFLQGZBBWBNIAIFKCBUMZSDUGONSZKYSTJOGBWTQDYYQMVZUTPMHEWOZYKXUUGWTOFMDWBZRLICLQJAQCGPXDSOLMMJDBMHCRSIHUCGCVRWDDKXRHWQHAHRNOELXJZSZFAPWLFUYIARY");

    try
    {
      Utils::ByteBuffer bfr;
      IMC::Packet::serialize(&msg, bfr);
      IMC::Message* msg_d = IMC::Packet::deserialize(bfr.getBuffer(), bfr.getSize());
      test.boolean("AutopilotMode #0", msg == *msg_d);
      delete msg_d;
    }
    catch (IMC::InvalidMessageSize& e)
    {
      (void)e;
      test.boolean("msg #0", msg.getSerializationSize() > DUNE_IMC_CONST_MAX_SIZE);
    }
  }

  {
    IMC::AutopilotMode msg;
    msg.setTimeStamp(0.2956015722801584);
    msg.setSource(30371U);
    msg.setSourceEntity(74U);
    msg.setDestination(39035U);
    msg.setDestinationEntity(249U);
    msg.autonomy = 230U;
    msg.mode.assign("KDVMXSBMIADFUMRSTIDAAHSOOPLONVZONRBCFVGIZBCQQIXCLZPCDFALVISDMQBPPNEDUYXTBELOEWJNGWRYFMTAYRYJGPHWKRMXUSPGJQHM");

    try
    {
      Utils::ByteBuffer bfr;
      IMC::Packet::serialize(&msg, bfr);
      IMC::Message* msg_d = IMC::Packet::deserialize(bfr.getBuffer(), bfr.getSize());
      test.boolean("AutopilotMode #1", msg == *msg_d);
      delete msg_d;
    }
    catch (IMC::InvalidMessageSize& e)
    {
      (void)e;
      test.boolean("msg #1", msg.getSerializationSize() > DUNE_IMC_CONST_MAX_SIZE);
    }
  }

  {
    IMC::AutopilotMode msg;
    msg.setTimeStamp(0.061942744063481214);
    msg.setSource(31946U);
    msg.setSourceEntity(37U);
    msg.setDestination(6999U);
    msg.setDestinationEntity(200U);
    msg.autonomy = 26U;
    msg.mode.assign("SUNJUUUXEZJIJZGDERTBKLOOTWUABIFLBTUEMSYGKGSJXIJVFKOQCJVLHAWNOWWPYUK");

    try
    {
      Utils::ByteBuffer bfr;
      IMC::Packet::serialize(&msg, bfr);
      IMC::Message* msg_d = IMC::Packet::deserialize(bfr.getBuffer(), bfr.getSize());
      test.boolean("AutopilotMode #2", msg == *msg_d);
      delete msg_d;
    }
    catch (IMC::InvalidMessageSize& e)
    {
      (void)e;
      test.boolean("msg #2", msg.getSerializationSize() > DUNE_IMC_CONST_MAX_SIZE);
    }
  }

  {
    IMC::FormationState msg;
    msg.setTimeStamp(0.33754273975885396);
    msg.setSource(38685U);
    msg.setSourceEntity(125U);
    msg.setDestination(38410U);
    msg.setDestinationEntity(111U);
    msg.type = 162U;
    msg.op = 232U;
    msg.possimerr = 0.21726104113160216;
    msg.converg = 0.5824745669580967;
    msg.turbulence = 0.6352823594162422;
    msg.possimmon = 152U;
    msg.commmon = 174U;
    msg.convergmon = 118U;

    try
    {
      Utils::ByteBuffer bfr;
      IMC::Packet::serialize(&msg, bfr);
      IMC::Message* msg_d = IMC::Packet::deserialize(bfr.getBuffer(), bfr.getSize());
      test.boolean("FormationState #0", msg == *msg_d);
      delete msg_d;
    }
    catch (IMC::InvalidMessageSize& e)
    {
      (void)e;
      test.boolean("msg #0", msg.getSerializationSize() > DUNE_IMC_CONST_MAX_SIZE);
    }
  }

  {
    IMC::FormationState msg;
    msg.setTimeStamp(0.340155179974893);
    msg.setSource(41472U);
    msg.setSourceEntity(71U);
    msg.setDestination(25256U);
    msg.setDestinationEntity(188U);
    msg.type = 145U;
    msg.op = 187U;
    msg.possimerr = 0.6637710358800085;
    msg.converg = 0.5761268835547609;
    msg.turbulence = 0.06681993929562113;
    msg.possimmon = 65U;
    msg.commmon = 11U;
    msg.convergmon = 31U;

    try
    {
      Utils::ByteBuffer bfr;
      IMC::Packet::serialize(&msg, bfr);
      IMC::Message* msg_d = IMC::Packet::deserialize(bfr.getBuffer(), bfr.getSize());
      test.boolean("FormationState #1", msg == *msg_d);
      delete msg_d;
    }
    catch (IMC::InvalidMessageSize& e)
    {
      (void)e;
      test.boolean("msg #1", msg.getSerializationSize() > DUNE_IMC_CONST_MAX_SIZE);
    }
  }

  {
    IMC::FormationState msg;
    msg.setTimeStamp(0.22546850447599842);
    msg.setSource(64401U);
    msg.setSourceEntity(55U);
    msg.setDestination(50466U);
    msg.setDestinationEntity(233U);
    msg.type = 173U;
    msg.op = 35U;
    msg.possimerr = 0.5772367659652667;
    msg.converg = 0.69076729080467;
    msg.turbulence = 0.5748447880868867;
    msg.possimmon = 108U;
    msg.commmon = 13U;
    msg.convergmon = 37U;

    try
    {
      Utils::ByteBuffer bfr;
      IMC::Packet::serialize(&msg, bfr);
      IMC::Message* msg_d = IMC::Packet::deserialize(bfr.getBuffer(), bfr.getSize());
      test.boolean("FormationState #2", msg == *msg_d);
      delete msg_d;
    }
    catch (IMC::InvalidMessageSize& e)
    {
      (void)e;
      test.boolean("msg #2", msg.getSerializationSize() > DUNE_IMC_CONST_MAX_SIZE);
    }
  }

  {
    IMC::ReportControl msg;
    msg.setTimeStamp(0.8643357282806035);
    msg.setSource(3486U);
    msg.setSourceEntity(31U);
    msg.setDestination(52535U);
    msg.setDestinationEntity(179U);
    msg.op = 248U;
    msg.comm_interface = 98U;
    msg.period = 51246U;
    msg.sys_dst.assign("WGOWPEWIWXEDGFPURHNBFYIRMNNFCEXCMUTHQDFHEUUVUNYBPPNOPXZEZCXQQAFRJLTWXDXARETOHVVTSSSBAKZWJEJBKDOPTN");

    try
    {
      Utils::ByteBuffer bfr;
      IMC::Packet::serialize(&msg, bfr);
      IMC::Message* msg_d = IMC::Packet::deserialize(bfr.getBuffer(), bfr.getSize());
      test.boolean("ReportControl #0", msg == *msg_d);
      delete msg_d;
    }
    catch (IMC::InvalidMessageSize& e)
    {
      (void)e;
      test.boolean("msg #0", msg.getSerializationSize() > DUNE_IMC_CONST_MAX_SIZE);
    }
  }

  {
    IMC::ReportControl msg;
    msg.setTimeStamp(0.45934054202004515);
    msg.setSource(40051U);
    msg.setSourceEntity(2U);
    msg.setDestination(57608U);
    msg.setDestinationEntity(5U);
    msg.op = 49U;
    msg.comm_interface = 100U;
    msg.period = 14716U;
    msg.sys_dst.assign("CWJKKXEUMEDEONTDRSIDUAAOFVOZFJGPBQVKILLRZVYRQEXUIIZDUYJCCC");

    try
    {
      Utils::ByteBuffer bfr;
      IMC::Packet::serialize(&msg, bfr);
      IMC::Message* msg_d = IMC::Packet::deserialize(bfr.getBuffer(), bfr.getSize());
      test.boolean("ReportControl #1", msg == *msg_d);
      delete msg_d;
    }
    catch (IMC::InvalidMessageSize& e)
    {
      (void)e;
      test.boolean("msg #1", msg.getSerializationSize() > DUNE_IMC_CONST_MAX_SIZE);
    }
  }

  {
    IMC::ReportControl msg;
    msg.setTimeStamp(0.48762330298898127);
    msg.setSource(39308U);
    msg.setSourceEntity(67U);
    msg.setDestination(23887U);
    msg.setDestinationEntity(210U);
    msg.op = 116U;
    msg.comm_interface = 210U;
    msg.period = 54799U;
    msg.sys_dst.assign("NUTASHPHQFUXJEBBSLXGAHXROZJHWXYBZPVWVZZJTCMNEBZQRIEDCNJMJFLARRLMDPJEIKWSXOIVCRBDQGMDSACSBYDJUYCOMUTPIPKEGHYMNXFHFDTQFKRILWKVTJVIKWCNPOZHAVGYPZDRTQPFJLNZAOSPVRLYPWXOOARQUKEKFSTBOHIUMTBQXIHMSLGMHSXZKLQYQEAQSDFNFVTCYOE");

    try
    {
      Utils::ByteBuffer bfr;
      IMC::Packet::serialize(&msg, bfr);
      IMC::Message* msg_d = IMC::Packet::deserialize(bfr.getBuffer(), bfr.getSize());
      test.boolean("ReportControl #2", msg == *msg_d);
      delete msg_d;
    }
    catch (IMC::InvalidMessageSize& e)
    {
      (void)e;
      test.boolean("msg #2", msg.getSerializationSize() > DUNE_IMC_CONST_MAX_SIZE);
    }
  }

  {
    IMC::StateReport msg;
    msg.setTimeStamp(0.6284995228018422);
    msg.setSource(32047U);
    msg.setSourceEntity(150U);
    msg.setDestination(16328U);
    msg.setDestinationEntity(88U);
    msg.stime = 1782597731U;
    msg.latitude = 0.040821160564164405;
    msg.longitude = 0.17691274868220974;
    msg.altitude = 10013U;
    msg.depth = 41256U;
    msg.heading = 2560U;
    msg.speed = -2723;
    msg.fuel = -18;
    msg.exec_state = -69;
    msg.plan_checksum = 10413U;

    try
    {
      Utils::ByteBuffer bfr;
      IMC::Packet::serialize(&msg, bfr);
      IMC::Message* msg_d = IMC::Packet::deserialize(bfr.getBuffer(), bfr.getSize());
      test.boolean("StateReport #0", msg == *msg_d);
      delete msg_d;
    }
    catch (IMC::InvalidMessageSize& e)
    {
      (void)e;
      test.boolean("msg #0", msg.getSerializationSize() > DUNE_IMC_CONST_MAX_SIZE);
    }
  }

  {
    IMC::StateReport msg;
    msg.setTimeStamp(0.6362431538565182);
    msg.setSource(56216U);
    msg.setSourceEntity(157U);
    msg.setDestination(15779U);
    msg.setDestinationEntity(37U);
    msg.stime = 1216433028U;
    msg.latitude = 0.08762153395113148;
    msg.longitude = 0.9472612878855947;
    msg.altitude = 16203U;
    msg.depth = 62408U;
    msg.heading = 61875U;
    msg.speed = -30050;
    msg.fuel = 95;
    msg.exec_state = 125;
    msg.plan_checksum = 26799U;

    try
    {
      Utils::ByteBuffer bfr;
      IMC::Packet::serialize(&msg, bfr);
      IMC::Message* msg_d = IMC::Packet::deserialize(bfr.getBuffer(), bfr.getSize());
      test.boolean("StateReport #1", msg == *msg_d);
      delete msg_d;
    }
    catch (IMC::InvalidMessageSize& e)
    {
      (void)e;
      test.boolean("msg #1", msg.getSerializationSize() > DUNE_IMC_CONST_MAX_SIZE);
    }
  }

  {
    IMC::StateReport msg;
    msg.setTimeStamp(0.7732603867512962);
    msg.setSource(2749U);
    msg.setSourceEntity(32U);
    msg.setDestination(29141U);
    msg.setDestinationEntity(153U);
    msg.stime = 4194735249U;
    msg.latitude = 0.13266165784848527;
    msg.longitude = 0.18699233812782923;
    msg.altitude = 56869U;
    msg.depth = 44710U;
    msg.heading = 23788U;
    msg.speed = 6100;
    msg.fuel = -63;
    msg.exec_state = 50;
    msg.plan_checksum = 63760U;

    try
    {
      Utils::ByteBuffer bfr;
      IMC::Packet::serialize(&msg, bfr);
      IMC::Message* msg_d = IMC::Packet::deserialize(bfr.getBuffer(), bfr.getSize());
      test.boolean("StateReport #2", msg == *msg_d);
      delete msg_d;
    }
    catch (IMC::InvalidMessageSize& e)
    {
      (void)e;
      test.boolean("msg #2", msg.getSerializationSize() > DUNE_IMC_CONST_MAX_SIZE);
    }
  }

  {
    IMC::TransmissionRequest msg;
    msg.setTimeStamp(0.01950725853373192);
    msg.setSource(61423U);
    msg.setSourceEntity(250U);
    msg.setDestination(5033U);
    msg.setDestinationEntity(174U);
    msg.req_id = 61704U;
    msg.comm_mean = 15U;
    msg.destination.assign("DGFNHTQYWPFMQZJAWRTXKBYCTYCGXFSABDBHREQCIJINYVFVXYXTBUZ");
    msg.deadline = 0.18542830924369447;
    msg.range = 0.48793552690519426;
    msg.data_mode = 123U;
    IMC::ColoredDissolvedOrganicMatter tmp_msg_0;
    tmp_msg_0.value = 0.5646545237803201;
    msg.msg_data.set(tmp_msg_0);
    msg.txt_data.assign("YALYVAXZUUANSTZNVCGZKRGMCGEIRMVCBDFOHXQOLOOJVWTOMHMLIFFHUGFUILYEKMYBKGYAVEJVJXRWBHFNXVLQSHEZTAIJNSIC");
    const signed char tmp_msg_1[] = {-14, 124, 95, 58, 25, 89, -106, 43, -125, 108, -106, 12, -32, 85, 47, 28, -90, -125, 115, -73, 82, 106, -121, 121, 14, -18, -14, -8, -58, 90, -63, -114, -62, 37, 10, -39, 79, 26, -63, 37, 53, -104, -85, 50, 112, -41, 14, 105, -65, 7, -71, 67, 88, -83, 39, -109, -48, 44, 58, -108, 12, 36, 90, -89, -71, -44, 24, -6, 83, 22, 8, 102, -46, -49, -6, 48, 46, 64, 119, -13, -122, -120, -109, -6, -10, 92, -25, 14, -103, -20, 100, -16, -128, -25, 103, -89, 126, -92, 104, -32, -4, -7, 111, -125, -18, -34, -76, 108, 19, 46, 1, 81, 28, -87, 84, -102, 68, 82, -1, 63, 3, 87, 107, -64, 47, 105, -32, -117, -115, -108, 20, 3, 32, -24, -52, 105, 85, -106, -121, -80, -68, 60, 109, 119, -34, -76, 100, 14, 13, 117, 101, 107, -4, 116, -62, -41, -120, 21, 12, 37, 119, 73};
    msg.raw_data.assign(tmp_msg_1, tmp_msg_1 + sizeof(tmp_msg_1));

    try
    {
      Utils::ByteBuffer bfr;
      IMC::Packet::serialize(&msg, bfr);
      IMC::Message* msg_d = IMC::Packet::deserialize(bfr.getBuffer(), bfr.getSize());
      test.boolean("TransmissionRequest #0", msg == *msg_d);
      delete msg_d;
    }
    catch (IMC::InvalidMessageSize& e)
    {
      (void)e;
      test.boolean("msg #0", msg.getSerializationSize() > DUNE_IMC_CONST_MAX_SIZE);
    }
  }

  {
    IMC::TransmissionRequest msg;
    msg.setTimeStamp(0.9860639774911573);
    msg.setSource(48258U);
    msg.setSourceEntity(186U);
    msg.setDestination(52071U);
    msg.setDestinationEntity(53U);
    msg.req_id = 55244U;
    msg.comm_mean = 89U;
    msg.destination.assign("NRQFIVBRLNGLDIGTNSACHNDDITBKBMHKDFXOAFLUQUHQCCCT");
    msg.deadline = 0.7534199087814991;
    msg.range = 0.6626918078107057;
    msg.data_mode = 194U;
    IMC::AnnounceService tmp_msg_0;
    tmp_msg_0.service.assign("VNZJYUTYHBRMHJXJAUNPCVJVQONNXNHJPWHFPIOVIZEZBWRMAQWASQPUQPBVEIGADEJKMMJSCZGTDALLKWZDTWNGWAYDIEKHIOZQ");
    tmp_msg_0.service_type = 54U;
    msg.msg_data.set(tmp_msg_0);
    msg.txt_data.assign("UBEWARFWBTGOEFAPOEKINNSNLXOPWXDQENMVJMZKAEOHGCHHPIAAHQYOBERMZVJRJZK");
    const signed char tmp_msg_1[] = {29, 42, -112, 62, -107, -75, 95, -20, 35, 97, -58, -104, 36, 10, 4, 106, -77, 25, -111, -67, 16, -19, 113, 69, 124, -125, -68, -108, -21, -5, 15, 115, 101, 72, 84, 110};
    msg.raw_data.assign(tmp_msg_1, tmp_msg_1 + sizeof(tmp_msg_1));

    try
    {
      Utils::ByteBuffer bfr;
      IMC::Packet::serialize(&msg, bfr);
      IMC::Message* msg_d = IMC::Packet::deserialize(bfr.getBuffer(), bfr.getSize());
      test.boolean("TransmissionRequest #1", msg == *msg_d);
      delete msg_d;
    }
    catch (IMC::InvalidMessageSize& e)
    {
      (void)e;
      test.boolean("msg #1", msg.getSerializationSize() > DUNE_IMC_CONST_MAX_SIZE);
    }
  }

  {
    IMC::TransmissionRequest msg;
    msg.setTimeStamp(0.4129983420547668);
    msg.setSource(59625U);
    msg.setSourceEntity(193U);
    msg.setDestination(33157U);
    msg.setDestinationEntity(76U);
    msg.req_id = 19213U;
    msg.comm_mean = 111U;
    msg.destination.assign("DCBQXBNDTRAOSXHZBWWILLVVTEGUUXMNEIBEMBFEMWOSLKDCYZJEMLOWCFELMKZGTASPEGLGDNAUTZLTMOQQCNJISHDJDZCBPFAHCQOTOIJUYBKRRPSRVVRQFCXNEMSPJOFKCIQLDXUWFKIYARDUPCIHXGRXKGYVANQPWYSQJSXPYIW");
    msg.deadline = 0.012605155565690307;
    msg.range = 0.6716727592778576;
    msg.data_mode = 196U;
    IMC::PopEntityParameters tmp_msg_0;
    tmp_msg_0.name.assign("KTMZVDXIGBTGDXGKOKFZVIQNLBUZHLRQBPTBJYIZYNEUAWECWQQQMFNTVLKWZIOBJCPPZVDYXMVDEJJLSUOVFEZRNIHAAMKBNIJYMWSYQGHUF");
    msg.msg_data.set(tmp_msg_0);
    msg.txt_data.assign("MNPJCICFOWSCNBQRFHZRQAP");
    const signed char tmp_msg_1[] = {95, 48, -73, -122, 95, -60, -105, -70, -55, 85, -56, 62, 3, -16, 63, -93, 117, 120, 41, 85, -108, -87, -37, -8, 1, 50, -92, 10, -120, -69, 109, 66, -86, 98, 7, -90, -124, 75, -29, -93, 49, 27, 45, 98, -97, -97, -27, -77, 90};
    msg.raw_data.assign(tmp_msg_1, tmp_msg_1 + sizeof(tmp_msg_1));

    try
    {
      Utils::ByteBuffer bfr;
      IMC::Packet::serialize(&msg, bfr);
      IMC::Message* msg_d = IMC::Packet::deserialize(bfr.getBuffer(), bfr.getSize());
      test.boolean("TransmissionRequest #2", msg == *msg_d);
      delete msg_d;
    }
    catch (IMC::InvalidMessageSize& e)
    {
      (void)e;
      test.boolean("msg #2", msg.getSerializationSize() > DUNE_IMC_CONST_MAX_SIZE);
    }
  }

  {
    IMC::TransmissionStatus msg;
    msg.setTimeStamp(0.49057501256308755);
    msg.setSource(4942U);
    msg.setSourceEntity(218U);
    msg.setDestination(21587U);
    msg.setDestinationEntity(20U);
    msg.req_id = 31680U;
    msg.status = 130U;
    msg.range = 0.8685302387521419;
    msg.info.assign("FNEUTUDDILONDVZUTAEDEVJXNSMYSCMYBHCKJGSMMYFOWNXHLTSUBBVPAOHFLZURLJKOPPHJAYGPJIKIHILWVLWDVXDVDQKQRFNEMOQWOYTQPZETQTQGYSYKFGPKMYUJSAZRLSRTAFCCNMFGARICOCXT");

    try
    {
      Utils::ByteBuffer bfr;
      IMC::Packet::serialize(&msg, bfr);
      IMC::Message* msg_d = IMC::Packet::deserialize(bfr.getBuffer(), bfr.getSize());
      test.boolean("TransmissionStatus #0", msg == *msg_d);
      delete msg_d;
    }
    catch (IMC::InvalidMessageSize& e)
    {
      (void)e;
      test.boolean("msg #0", msg.getSerializationSize() > DUNE_IMC_CONST_MAX_SIZE);
    }
  }

  {
    IMC::TransmissionStatus msg;
    msg.setTimeStamp(0.2542149715080211);
    msg.setSource(30815U);
    msg.setSourceEntity(164U);
    msg.setDestination(5531U);
    msg.setDestinationEntity(236U);
    msg.req_id = 10943U;
    msg.status = 25U;
    msg.range = 0.19333313882231462;
    msg.info.assign("WHBDGCQYIKBLZNJVAXSUSIWRCVOHHBNMAEYZDXJJAZYNDFFRWPDHGIKMKLOJTEGQJGDXNPWOSAQRGHD");

    try
    {
      Utils::ByteBuffer bfr;
      IMC::Packet::serialize(&msg, bfr);
      IMC::Message* msg_d = IMC::Packet::deserialize(bfr.getBuffer(), bfr.getSize());
      test.boolean("TransmissionStatus #1", msg == *msg_d);
      delete msg_d;
    }
    catch (IMC::InvalidMessageSize& e)
    {
      (void)e;
      test.boolean("msg #1", msg.getSerializationSize() > DUNE_IMC_CONST_MAX_SIZE);
    }
  }

  {
    IMC::TransmissionStatus msg;
    msg.setTimeStamp(0.5567312018951782);
    msg.setSource(24319U);
    msg.setSourceEntity(88U);
    msg.setDestination(26683U);
    msg.setDestinationEntity(239U);
    msg.req_id = 3690U;
    msg.status = 171U;
    msg.range = 0.49149525183145715;
    msg.info.assign("COFSOEMZYSJDXUSGXKYTEKVNMXYMMQHVZYTPFHBVJRBGSZSXNWVSIIOUNGBNYHNHOLFFICRPQCEJLTBPTUJKC");

    try
    {
      Utils::ByteBuffer bfr;
      IMC::Packet::serialize(&msg, bfr);
      IMC::Message* msg_d = IMC::Packet::deserialize(bfr.getBuffer(), bfr.getSize());
      test.boolean("TransmissionStatus #2", msg == *msg_d);
      delete msg_d;
    }
    catch (IMC::InvalidMessageSize& e)
    {
      (void)e;
      test.boolean("msg #2", msg.getSerializationSize() > DUNE_IMC_CONST_MAX_SIZE);
    }
  }

  {
    IMC::SmsRequest msg;
    msg.setTimeStamp(0.6246062493965158);
    msg.setSource(20918U);
    msg.setSourceEntity(221U);
    msg.setDestination(23491U);
    msg.setDestinationEntity(130U);
    msg.req_id = 34358U;
    msg.destination.assign("BJBJIQYFEYKELNWFVHZGJDMYMKOJFTINMOYMWLHVOAQUHXZJDRHCAEEOLCDKGUFTQNIDZDDCCEUSYXXOIBJXYBRAKGIDXROCMNQYTHSIREVRCUGKSABXUTTZUTEKPGIWPSAQLOJ");
    msg.timeout = 0.6587860904981663;
    msg.sms_text.assign("SLRPIVASTVRHCWNRHHGZISECDSMNINGEWQMTYTDHYXBFXJDDEBXNDBUFLZMYDAVWLEHGTPJIAQLKFZSIFOCPXUKMKCNQYAHBZLBXVUJWDYEQWKYOBEUNRRALE");

    try
    {
      Utils::ByteBuffer bfr;
      IMC::Packet::serialize(&msg, bfr);
      IMC::Message* msg_d = IMC::Packet::deserialize(bfr.getBuffer(), bfr.getSize());
      test.boolean("SmsRequest #0", msg == *msg_d);
      delete msg_d;
    }
    catch (IMC::InvalidMessageSize& e)
    {
      (void)e;
      test.boolean("msg #0", msg.getSerializationSize() > DUNE_IMC_CONST_MAX_SIZE);
    }
  }

  {
    IMC::SmsRequest msg;
    msg.setTimeStamp(0.23307376626547205);
    msg.setSource(49644U);
    msg.setSourceEntity(199U);
    msg.setDestination(54905U);
    msg.setDestinationEntity(43U);
    msg.req_id = 50289U;
    msg.destination.assign("GFCQIUVZFAEDHXXFYFYNDFUAOWHOECTMJDUNJPAASZKSGEYSQLSVSKBJWWKIXGLEXNTIEPIHGYMWAVARWFPWYTSPRYHVULUYZBXEMLEJCWKBPADLNZZNQOFCCUBPMXJRCTGGMCNTJZRBBVPIAXSUHRBJBKDMTGVRZJQSYJCLLRVFGZDOHHSKUVBOQXWXEYAVONQKLQDHMRHCJNMFIITAKLPZOXHQGPT");
    msg.timeout = 0.3659640199174794;
    msg.sms_text.assign("TXFMEBIUQCNQFZPMRJBNPURZFBYHTTXPAGPBVKYXTRLDQAKPOFJMWCEHCGJZSNIZSQSZHUZYPZVGLZWEFD");

    try
    {
      Utils::ByteBuffer bfr;
      IMC::Packet::serialize(&msg, bfr);
      IMC::Message* msg_d = IMC::Packet::deserialize(bfr.getBuffer(), bfr.getSize());
      test.boolean("SmsRequest #1", msg == *msg_d);
      delete msg_d;
    }
    catch (IMC::InvalidMessageSize& e)
    {
      (void)e;
      test.boolean("msg #1", msg.getSerializationSize() > DUNE_IMC_CONST_MAX_SIZE);
    }
  }

  {
    IMC::SmsRequest msg;
    msg.setTimeStamp(0.6139534203030358);
    msg.setSource(51946U);
    msg.setSourceEntity(207U);
    msg.setDestination(9225U);
    msg.setDestinationEntity(226U);
    msg.req_id = 13538U;
    msg.destination.assign("BPTCSAHYRLKLFBFZGAVJIBMEGRCHUYSTMOGKFYTOXUYOTUGAHCDIVGWLNFNRNROZMVTDEAGUMSLPMJSIUSZWHJFEAOPWENUXEMWIFBQPVYMSRXKHPKQAKVRBMJUGSCZDDJLJKIYPYQQYDDVWHNHIOCBUTNXWDLEWB");
    msg.timeout = 0.3594317285578107;
    msg.sms_text.assign("ROMHHZFTMJSACBFPTNEMACVNZGMKOSKJUHAEYOZDTHKNDEGAQSPVSKIGSVCQFQKRDBYZYRBMAFECOQUKMYIMFOYXWVQOXNDLPEHHUGWDTELSBRJHRLVCBDDNALPELVUXYXWISUPWWLWMJGZLETWKKYNYVJOP");

    try
    {
      Utils::ByteBuffer bfr;
      IMC::Packet::serialize(&msg, bfr);
      IMC::Message* msg_d = IMC::Packet::deserialize(bfr.getBuffer(), bfr.getSize());
      test.boolean("SmsRequest #2", msg == *msg_d);
      delete msg_d;
    }
    catch (IMC::InvalidMessageSize& e)
    {
      (void)e;
      test.boolean("msg #2", msg.getSerializationSize() > DUNE_IMC_CONST_MAX_SIZE);
    }
  }

  {
    IMC::SmsStatus msg;
    msg.setTimeStamp(0.49474525161658756);
    msg.setSource(34481U);
    msg.setSourceEntity(2U);
    msg.setDestination(14426U);
    msg.setDestinationEntity(147U);
    msg.req_id = 13214U;
    msg.status = 37U;
    msg.info.assign("SUITGFEROUAOLJGONPZNOSUYZHDLNNLOZQOFBUSBKXMFHBYVUGCZCJIYSWSXRSSFSHTJMVAXVNJWTCRPIKLRMACGJTMNERSEIPPBKTQIWIUUNP");

    try
    {
      Utils::ByteBuffer bfr;
      IMC::Packet::serialize(&msg, bfr);
      IMC::Message* msg_d = IMC::Packet::deserialize(bfr.getBuffer(), bfr.getSize());
      test.boolean("SmsStatus #0", msg == *msg_d);
      delete msg_d;
    }
    catch (IMC::InvalidMessageSize& e)
    {
      (void)e;
      test.boolean("msg #0", msg.getSerializationSize() > DUNE_IMC_CONST_MAX_SIZE);
    }
  }

  {
    IMC::SmsStatus msg;
    msg.setTimeStamp(0.46388043176235993);
    msg.setSource(51743U);
    msg.setSourceEntity(213U);
    msg.setDestination(60362U);
    msg.setDestinationEntity(3U);
    msg.req_id = 32387U;
    msg.status = 1U;
    msg.info.assign("XSMMWBOIBWQEDSCGOEOOKFLTVDWHSDIVCLKYRTMQYEARINOIAZUWDIIRCJZYLXQANBKZIZYRVVWCRJVASEQGVYJHGBHOESJFFQALTFDRAUNSOYPOGJEMPZLHNOVKKWPTZRJEKUBIEYXKDXSMGMJHPGWRXWZNHNWAFQUBFQNNVHZN");

    try
    {
      Utils::ByteBuffer bfr;
      IMC::Packet::serialize(&msg, bfr);
      IMC::Message* msg_d = IMC::Packet::deserialize(bfr.getBuffer(), bfr.getSize());
      test.boolean("SmsStatus #1", msg == *msg_d);
      delete msg_d;
    }
    catch (IMC::InvalidMessageSize& e)
    {
      (void)e;
      test.boolean("msg #1", msg.getSerializationSize() > DUNE_IMC_CONST_MAX_SIZE);
    }
  }

  {
    IMC::SmsStatus msg;
    msg.setTimeStamp(0.26164665385263297);
    msg.setSource(30681U);
    msg.setSourceEntity(148U);
    msg.setDestination(33973U);
    msg.setDestinationEntity(75U);
    msg.req_id = 46191U;
    msg.status = 47U;
    msg.info.assign("LOTJBGNCAEMHPIUEZIXMCTTXNAXPSCFPWZDYHHQKIXDWGWGHMWHFWRUFSTVKPHVYYYEHCNDXOZDDJNJUFISKDFBLAAQYUSSMNTOPAQRHPMIMCHTLCLMZVGORURHOJKUJJBCKELGSFRIBLAVVDSWGBWZQNQPFLNFZRLQYXGCIOPAZZNPVAKWIVMMKWRWNFQATYEJDTOXEUQVRS");

    try
    {
      Utils::ByteBuffer bfr;
      IMC::Packet::serialize(&msg, bfr);
      IMC::Message* msg_d = IMC::Packet::deserialize(bfr.getBuffer(), bfr.getSize());
      test.boolean("SmsStatus #2", msg == *msg_d);
      delete msg_d;
    }
    catch (IMC::InvalidMessageSize& e)
    {
      (void)e;
      test.boolean("msg #2", msg.getSerializationSize() > DUNE_IMC_CONST_MAX_SIZE);
    }
  }

  {
    IMC::VtolState msg;
    msg.setTimeStamp(0.09984684331423077);
    msg.setSource(37502U);
    msg.setSourceEntity(252U);
    msg.setDestination(50211U);
    msg.setDestinationEntity(143U);
    msg.state = 102U;

    try
    {
      Utils::ByteBuffer bfr;
      IMC::Packet::serialize(&msg, bfr);
      IMC::Message* msg_d = IMC::Packet::deserialize(bfr.getBuffer(), bfr.getSize());
      test.boolean("VtolState #0", msg == *msg_d);
      delete msg_d;
    }
    catch (IMC::InvalidMessageSize& e)
    {
      (void)e;
      test.boolean("msg #0", msg.getSerializationSize() > DUNE_IMC_CONST_MAX_SIZE);
    }
  }

  {
    IMC::VtolState msg;
    msg.setTimeStamp(0.07150343368287082);
    msg.setSource(45334U);
    msg.setSourceEntity(193U);
    msg.setDestination(7081U);
    msg.setDestinationEntity(174U);
    msg.state = 197U;

    try
    {
      Utils::ByteBuffer bfr;
      IMC::Packet::serialize(&msg, bfr);
      IMC::Message* msg_d = IMC::Packet::deserialize(bfr.getBuffer(), bfr.getSize());
      test.boolean("VtolState #1", msg == *msg_d);
      delete msg_d;
    }
    catch (IMC::InvalidMessageSize& e)
    {
      (void)e;
      test.boolean("msg #1", msg.getSerializationSize() > DUNE_IMC_CONST_MAX_SIZE);
    }
  }

  {
    IMC::VtolState msg;
    msg.setTimeStamp(0.12671738126819343);
    msg.setSource(47966U);
    msg.setSourceEntity(215U);
    msg.setDestination(61683U);
    msg.setDestinationEntity(43U);
    msg.state = 119U;

    try
    {
      Utils::ByteBuffer bfr;
      IMC::Packet::serialize(&msg, bfr);
      IMC::Message* msg_d = IMC::Packet::deserialize(bfr.getBuffer(), bfr.getSize());
      test.boolean("VtolState #2", msg == *msg_d);
      delete msg_d;
    }
    catch (IMC::InvalidMessageSize& e)
    {
      (void)e;
      test.boolean("msg #2", msg.getSerializationSize() > DUNE_IMC_CONST_MAX_SIZE);
    }
  }

  {
    IMC::ArmingState msg;
    msg.setTimeStamp(0.8110909622402525);
    msg.setSource(59568U);
    msg.setSourceEntity(7U);
    msg.setDestination(38898U);
    msg.setDestinationEntity(169U);
    msg.state = 39U;

    try
    {
      Utils::ByteBuffer bfr;
      IMC::Packet::serialize(&msg, bfr);
      IMC::Message* msg_d = IMC::Packet::deserialize(bfr.getBuffer(), bfr.getSize());
      test.boolean("ArmingState #0", msg == *msg_d);
      delete msg_d;
    }
    catch (IMC::InvalidMessageSize& e)
    {
      (void)e;
      test.boolean("msg #0", msg.getSerializationSize() > DUNE_IMC_CONST_MAX_SIZE);
    }
  }

  {
    IMC::ArmingState msg;
    msg.setTimeStamp(0.05305599628896307);
    msg.setSource(50570U);
    msg.setSourceEntity(28U);
    msg.setDestination(24030U);
    msg.setDestinationEntity(5U);
    msg.state = 192U;

    try
    {
      Utils::ByteBuffer bfr;
      IMC::Packet::serialize(&msg, bfr);
      IMC::Message* msg_d = IMC::Packet::deserialize(bfr.getBuffer(), bfr.getSize());
      test.boolean("ArmingState #1", msg == *msg_d);
      delete msg_d;
    }
    catch (IMC::InvalidMessageSize& e)
    {
      (void)e;
      test.boolean("msg #1", msg.getSerializationSize() > DUNE_IMC_CONST_MAX_SIZE);
    }
  }

  {
    IMC::ArmingState msg;
    msg.setTimeStamp(0.45451223013766284);
    msg.setSource(8463U);
    msg.setSourceEntity(80U);
    msg.setDestination(25251U);
    msg.setDestinationEntity(58U);
    msg.state = 236U;

    try
    {
      Utils::ByteBuffer bfr;
      IMC::Packet::serialize(&msg, bfr);
      IMC::Message* msg_d = IMC::Packet::deserialize(bfr.getBuffer(), bfr.getSize());
      test.boolean("ArmingState #2", msg == *msg_d);
      delete msg_d;
    }
    catch (IMC::InvalidMessageSize& e)
    {
      (void)e;
      test.boolean("msg #2", msg.getSerializationSize() > DUNE_IMC_CONST_MAX_SIZE);
    }
  }

  {
    IMC::TCPRequest msg;
    msg.setTimeStamp(0.6498502580805687);
    msg.setSource(27468U);
    msg.setSourceEntity(190U);
    msg.setDestination(63173U);
    msg.setDestinationEntity(82U);
    msg.req_id = 33054U;
    msg.destination.assign("EVKXORSAYYNFAYOWFBBTWDNCKVOOIYSRYOJXCFHCPNMWTUELUZYUJGWXQNSHVGSDOQBMCRKIMLZGECRNHAADECXKDWCHHLXCIEJJWQQFTZSINXWMXVSBFIPBPVAHVDTBQPARVZXNHJLGGEETPLLZDSTRFTTMGMKYLUISNAEHXMFPWVMRQUFZPJTUKDDHILSNDVPFHGZIGRBGWYVSMCXBLAUJPOEBCKUAZYZIKQPJWAJORIROBQFQJEKLUD");
    msg.timeout = 0.7958627399672941;
    IMC::AcousticSystems tmp_msg_0;
    tmp_msg_0.list.assign("AEUCORNFCBRW");
    msg.msg_data.set(tmp_msg_0);

    try
    {
      Utils::ByteBuffer bfr;
      IMC::Packet::serialize(&msg, bfr);
      IMC::Message* msg_d = IMC::Packet::deserialize(bfr.getBuffer(), bfr.getSize());
      test.boolean("TCPRequest #0", msg == *msg_d);
      delete msg_d;
    }
    catch (IMC::InvalidMessageSize& e)
    {
      (void)e;
      test.boolean("msg #0", msg.getSerializationSize() > DUNE_IMC_CONST_MAX_SIZE);
    }
  }

  {
    IMC::TCPRequest msg;
    msg.setTimeStamp(0.8086525115347666);
    msg.setSource(39001U);
    msg.setSourceEntity(104U);
    msg.setDestination(62859U);
    msg.setDestinationEntity(69U);
    msg.req_id = 23363U;
    msg.destination.assign("DVBPQIIYHZZBHEGTHXPYMURNAXVBKLROBBVTGYYFGXSUIWJBSQUWDOVCHPYDQQPUIOCGITUAWIUWHPOUSWRKXJJSYNGRPOHCEZEYGGSWBATSIZMJZLREVWUQDQDIOJHQ");
    msg.timeout = 0.7881890761275085;
    IMC::GpioStateGet tmp_msg_0;
    tmp_msg_0.name.assign("ZJKBWZVUSBHNLMVEKKNLANOXHLFBXMGAXBCCOFELTJRJSRIBGWCD");
    msg.msg_data.set(tmp_msg_0);

    try
    {
      Utils::ByteBuffer bfr;
      IMC::Packet::serialize(&msg, bfr);
      IMC::Message* msg_d = IMC::Packet::deserialize(bfr.getBuffer(), bfr.getSize());
      test.boolean("TCPRequest #1", msg == *msg_d);
      delete msg_d;
    }
    catch (IMC::InvalidMessageSize& e)
    {
      (void)e;
      test.boolean("msg #1", msg.getSerializationSize() > DUNE_IMC_CONST_MAX_SIZE);
    }
  }

  {
    IMC::TCPRequest msg;
    msg.setTimeStamp(0.8804888073894257);
    msg.setSource(61457U);
    msg.setSourceEntity(152U);
    msg.setDestination(46281U);
    msg.setDestinationEntity(203U);
    msg.req_id = 14035U;
    msg.destination.assign("YZVJGOBOQPAUZEIVDLTRWUIDGFEKBLBDNSZQTKWQNFXIARCROMIGIDVEGSPRNCQWUBLIYPWFKGOWZFPKUURNYREHMUTTMLBQPMKOAFAXTYYUADALZOTVHGLIHJHPQXEHODTYGBBKLOFOJXHMOHCCVBQJU");
    msg.timeout = 0.5223999267484932;
    IMC::TrajectoryPoint tmp_msg_0;
    tmp_msg_0.x = 0.37636244558176246;
    tmp_msg_0.y = 0.5053126482064486;
    tmp_msg_0.z = 0.1830887959549674;
    tmp_msg_0.t = 0.12365322163299652;
    msg.msg_data.set(tmp_msg_0);

    try
    {
      Utils::ByteBuffer bfr;
      IMC::Packet::serialize(&msg, bfr);
      IMC::Message* msg_d = IMC::Packet::deserialize(bfr.getBuffer(), bfr.getSize());
      test.boolean("TCPRequest #2", msg == *msg_d);
      delete msg_d;
    }
    catch (IMC::InvalidMessageSize& e)
    {
      (void)e;
      test.boolean("msg #2", msg.getSerializationSize() > DUNE_IMC_CONST_MAX_SIZE);
    }
  }

  {
    IMC::TCPStatus msg;
    msg.setTimeStamp(0.48167470322627903);
    msg.setSource(60188U);
    msg.setSourceEntity(124U);
    msg.setDestination(63351U);
    msg.setDestinationEntity(164U);
    msg.req_id = 64896U;
    msg.status = 104U;
    msg.info.assign("HMNBIPTASGVFZUHEXXCYNOKWWFKBLTWZSXDXOMYLSCMULLVEVCPJFJFHQKCNHRVKQWRCCHOXDQRDIMEPUQTJRZPXTIBDIVINMNNETQJYSHJIAWVBRCGNGLUTLUAPMSAESOIZTNAETOCKSUBKQMEIDMPFGVKSFJLUSHCANQKFMWRFWZYBPIJFKHZOBVVQZYORBUCTGHAONZGEJTMBPKPUIGXDELGYJWQDQJEZYY");

    try
    {
      Utils::ByteBuffer bfr;
      IMC::Packet::serialize(&msg, bfr);
      IMC::Message* msg_d = IMC::Packet::deserialize(bfr.getBuffer(), bfr.getSize());
      test.boolean("TCPStatus #0", msg == *msg_d);
      delete msg_d;
    }
    catch (IMC::InvalidMessageSize& e)
    {
      (void)e;
      test.boolean("msg #0", msg.getSerializationSize() > DUNE_IMC_CONST_MAX_SIZE);
    }
  }

  {
    IMC::TCPStatus msg;
    msg.setTimeStamp(0.9132729390037779);
    msg.setSource(16818U);
    msg.setSourceEntity(241U);
    msg.setDestination(7893U);
    msg.setDestinationEntity(180U);
    msg.req_id = 21968U;
    msg.status = 245U;
    msg.info.assign("ZRMHVFJLFWODPEYRSQNRYOMMXFBPJTIJJCCXW");

    try
    {
      Utils::ByteBuffer bfr;
      IMC::Packet::serialize(&msg, bfr);
      IMC::Message* msg_d = IMC::Packet::deserialize(bfr.getBuffer(), bfr.getSize());
      test.boolean("TCPStatus #1", msg == *msg_d);
      delete msg_d;
    }
    catch (IMC::InvalidMessageSize& e)
    {
      (void)e;
      test.boolean("msg #1", msg.getSerializationSize() > DUNE_IMC_CONST_MAX_SIZE);
    }
  }

  {
    IMC::TCPStatus msg;
    msg.setTimeStamp(0.9776642691640469);
    msg.setSource(26083U);
    msg.setSourceEntity(164U);
    msg.setDestination(56405U);
    msg.setDestinationEntity(113U);
    msg.req_id = 19570U;
    msg.status = 124U;
    msg.info.assign("OTHOYWJCYKTUEEGAEXUYKJSZXSKUQJFOPAFCWCELGKBKEMUPDQZTBBSYNDUCLNBGNUHSIVHMCAAPQUWDVLAQIXVXMDWCRJKZWYAKRRNZDFOSLSFBTUYGQZRPQ");

    try
    {
      Utils::ByteBuffer bfr;
      IMC::Packet::serialize(&msg, bfr);
      IMC::Message* msg_d = IMC::Packet::deserialize(bfr.getBuffer(), bfr.getSize());
      test.boolean("TCPStatus #2", msg == *msg_d);
      delete msg_d;
    }
    catch (IMC::InvalidMessageSize& e)
    {
      (void)e;
      test.boolean("msg #2", msg.getSerializationSize() > DUNE_IMC_CONST_MAX_SIZE);
    }
  }

  {
    IMC::AssetReport msg;
    msg.setTimeStamp(0.8128314565181955);
    msg.setSource(51186U);
    msg.setSourceEntity(199U);
    msg.setDestination(43880U);
    msg.setDestinationEntity(60U);
    msg.name.assign("FIPDHTJDWNBTDEIJIFCTGMDIRFTWWBDEKDRVWBJMTHGIEXOTZQOGYPPHIHQRYRXVBQXRFSUWONZMVKGGACWWBYNSEZXZCLYCPXJKTUTSZFNXGJKCYTYGTLVCUAUWJZFBDGPAAR");
    msg.report_time = 0.31167956151339216;
    msg.medium = 243U;
    msg.lat = 0.9805264727332711;
    msg.lon = 0.4229755735555062;
    msg.depth = 0.4287283103018068;
    msg.alt = 0.8942351503978438;
    msg.sog = 0.44576141641858724;
    msg.cog = 0.6718270397487448;
    IMC::Event tmp_msg_0;
    tmp_msg_0.topic.assign("UZOVAGFOMPBHDQQPXWNJFWETSBPSFCMEENCBGVGYBQPQVEOGZJLIX");
    tmp_msg_0.data.assign("ALJYIVWHOHIEZXNPYFHUAHOKMIPCXLBDFLFKLXQVGHHQLVRVVDWJKQYOEUASTBOJEEMNYEATDQODSIKSUYPYCQAFXUWZOARFCCZJOSAHRNNWGRQBFMEASWSEVEZGTPAIFGCRSKDWXRFMNCDWPZRWXQEJSMOPPPCLOGHQUGICOJLNWMRFKLVGYYCBXKTFTEDUIBVKNCIKJVDSTIGBLUZNTRDLZZZWYKUBQAZNYMUGTMTXPVJTHHGBRU");
    msg.msgs.push_back(tmp_msg_0);

    try
    {
      Utils::ByteBuffer bfr;
      IMC::Packet::serialize(&msg, bfr);
      IMC::Message* msg_d = IMC::Packet::deserialize(bfr.getBuffer(), bfr.getSize());
      test.boolean("AssetReport #0", msg == *msg_d);
      delete msg_d;
    }
    catch (IMC::InvalidMessageSize& e)
    {
      (void)e;
      test.boolean("msg #0", msg.getSerializationSize() > DUNE_IMC_CONST_MAX_SIZE);
    }
  }

  {
    IMC::AssetReport msg;
    msg.setTimeStamp(0.6018370716797432);
    msg.setSource(57647U);
    msg.setSourceEntity(60U);
    msg.setDestination(31749U);
    msg.setDestinationEntity(232U);
    msg.name.assign("NDAFSRJKOPNCREOBDTXKYDBFNFLZXQHAVSZVQPTFTNULMCM");
    msg.report_time = 0.5786799745036418;
    msg.medium = 34U;
    msg.lat = 0.5365069209251466;
    msg.lon = 0.18587586302593673;
    msg.depth = 0.7873131769136174;
    msg.alt = 0.587889530720493;
    msg.sog = 0.7043956374683166;
    msg.cog = 0.04002442510734938;
    IMC::TelemetryMsg tmp_msg_0;
    tmp_msg_0.type = 147U;
    tmp_msg_0.req_id = 3020268444U;
    tmp_msg_0.ttl = 54279U;
    tmp_msg_0.code = 218U;
    tmp_msg_0.destination.assign("LIWCVDUOZAEDFPKFHEAIRAOSOJSYBNSDLTDPVKONMOTNWXOHMMKGUEVGALLKDANLZCBRQQDZDWIHIWPCRRWJB");
    tmp_msg_0.source.assign("HIMKLYDBVYEYGYRVRFXNPOFGYIYHSWXFTOGZQRZKATFOIQKEFKNXDLHIWEPAQPVQHNVGOUNGWOCJZAZLBKWXEPCSMAYNDOXNMUEOPLEUUZKQTVVAPZLVWQIBULBUJABSKMENUQCZKLMBZKBLNFRBBWHMFMEYDA");
    tmp_msg_0.acknowledge = 38U;
    tmp_msg_0.status = 175U;
    const signed char tmp_tmp_msg_0_0[] = {-60, 33, 4, 3, 38, 59, 65, 81, -16, 18, -47, 40, 74, 61, 81, 87, -30, -64, 62, -110, -62, 2, 82, -25, -81, 11, -102, -16, -66, 104, -119, 64, 119, -65, -29, 9, -19, -86, -13, -119, -40, 29, 114, 33, 121, 6, 119, -74, 55, -93, 27, 101, 89, 56, -2, -28, 17, 55, -92, -88, 48, 82, -72, -100, 31, 82, -43, -91, 62, 28, 80, -110, 27, -121, -128, 102, -26, 80, 64, -127, -62, -77, -7, -23, 51, -48, 36, -89, -43, -110, 77, -59, 4, -23, 118, -93, -128, 85, 44, -46, -62, 100, -78, -68, 37, -95, 119, 89, -71, 42, -94, -52, -67, 115, 43, 69, 116, 50, 38, -86, 102, -48, 98, -29, -69, -60, -80, 94, -17, -124, -7, 77, 89, -124, 34, -103, 78, 28, 17, -59, -53, 27, 86, -123, 63, 67, 23, -104, -98, -39, -15, -40, -68, -18, 115, -40, -54, 45, -41, -117, -88, -8, -50, -40, -36, -116, 37, -62, -100, -2, -71, 122, -43, -115, 124, 96, 68, -7, 94, 92, 45, 44, -118, -50, 8, -6, 73, -16, 0, 13, 48, -93, -49, 43, -25, 49, 89, -2, 34, -115, 116, 3, 31, -51, -49, 21, 61, -57, 114, -101, -59, -71, -78, 31, 121, 43, 106, 106, -82, 75, -23, -26, 40, 13, 94, -88, -77, -11};
    tmp_msg_0.data.assign(tmp_tmp_msg_0_0, tmp_tmp_msg_0_0 + sizeof(tmp_tmp_msg_0_0));
    msg.msgs.push_back(tmp_msg_0);

    try
    {
      Utils::ByteBuffer bfr;
      IMC::Packet::serialize(&msg, bfr);
      IMC::Message* msg_d = IMC::Packet::deserialize(bfr.getBuffer(), bfr.getSize());
      test.boolean("AssetReport #1", msg == *msg_d);
      delete msg_d;
    }
    catch (IMC::InvalidMessageSize& e)
    {
      (void)e;
      test.boolean("msg #1", msg.getSerializationSize() > DUNE_IMC_CONST_MAX_SIZE);
    }
  }

  {
    IMC::AssetReport msg;
    msg.setTimeStamp(0.7418692975736292);
    msg.setSource(13372U);
    msg.setSourceEntity(83U);
    msg.setDestination(3295U);
    msg.setDestinationEntity(5U);
    msg.name.assign("FNKYNXQXUFTHUCWYHFFIOLDLEPPDAJRPAUVOLBEVHLWOQASIFGQUMTGMOVWGMCBUJXNMRSHRGTVWRYANRPQLVJKIBCUFKZWVLIIGIWQREPRSXCAJIBKQJHTPZYRHBKZXXJWPROBTVGFSDKEEYGKMPZCXTQNZNSTHYXSMWADOACZGNNRJBOPHPXMTYEBLUIZQISVQSFMWJBYEKLAADODNCBDETUMEUNAGLWZVTFCJZSIDXHUJKEOCLC");
    msg.report_time = 0.6558316431644684;
    msg.medium = 97U;
    msg.lat = 0.7208095360846927;
    msg.lon = 0.38878617063065846;
    msg.depth = 0.2776371440557406;
    msg.alt = 0.10942496013176917;
    msg.sog = 0.16968281909476446;
    msg.cog = 0.8736921160870339;
    IMC::DesiredThrottle tmp_msg_0;
    tmp_msg_0.value = 0.9407585228707562;
    msg.msgs.push_back(tmp_msg_0);

    try
    {
      Utils::ByteBuffer bfr;
      IMC::Packet::serialize(&msg, bfr);
      IMC::Message* msg_d = IMC::Packet::deserialize(bfr.getBuffer(), bfr.getSize());
      test.boolean("AssetReport #2", msg == *msg_d);
      delete msg_d;
    }
    catch (IMC::InvalidMessageSize& e)
    {
      (void)e;
      test.boolean("msg #2", msg.getSerializationSize() > DUNE_IMC_CONST_MAX_SIZE);
    }
  }

  {
    IMC::Abort msg;
    msg.setTimeStamp(0.2891471877644928);
    msg.setSource(56833U);
    msg.setSourceEntity(173U);
    msg.setDestination(14118U);
    msg.setDestinationEntity(206U);

    try
    {
      Utils::ByteBuffer bfr;
      IMC::Packet::serialize(&msg, bfr);
      IMC::Message* msg_d = IMC::Packet::deserialize(bfr.getBuffer(), bfr.getSize());
      test.boolean("Abort #0", msg == *msg_d);
      delete msg_d;
    }
    catch (IMC::InvalidMessageSize& e)
    {
      (void)e;
      test.boolean("msg #0", msg.getSerializationSize() > DUNE_IMC_CONST_MAX_SIZE);
    }
  }

  {
    IMC::Abort msg;
    msg.setTimeStamp(0.9271155528196797);
    msg.setSource(15991U);
    msg.setSourceEntity(206U);
    msg.setDestination(61700U);
    msg.setDestinationEntity(125U);

    try
    {
      Utils::ByteBuffer bfr;
      IMC::Packet::serialize(&msg, bfr);
      IMC::Message* msg_d = IMC::Packet::deserialize(bfr.getBuffer(), bfr.getSize());
      test.boolean("Abort #1", msg == *msg_d);
      delete msg_d;
    }
    catch (IMC::InvalidMessageSize& e)
    {
      (void)e;
      test.boolean("msg #1", msg.getSerializationSize() > DUNE_IMC_CONST_MAX_SIZE);
    }
  }

  {
    IMC::Abort msg;
    msg.setTimeStamp(0.7315224499212313);
    msg.setSource(45736U);
    msg.setSourceEntity(132U);
    msg.setDestination(57205U);
    msg.setDestinationEntity(131U);

    try
    {
      Utils::ByteBuffer bfr;
      IMC::Packet::serialize(&msg, bfr);
      IMC::Message* msg_d = IMC::Packet::deserialize(bfr.getBuffer(), bfr.getSize());
      test.boolean("Abort #2", msg == *msg_d);
      delete msg_d;
    }
    catch (IMC::InvalidMessageSize& e)
    {
      (void)e;
      test.boolean("msg #2", msg.getSerializationSize() > DUNE_IMC_CONST_MAX_SIZE);
    }
  }

  {
    IMC::PlanSpecification msg;
    msg.setTimeStamp(0.9637216393011904);
    msg.setSource(35162U);
    msg.setSourceEntity(112U);
    msg.setDestination(60171U);
    msg.setDestinationEntity(242U);
    msg.plan_id.assign("XKWQIINDUAWEFOYWGWWBYXJDBLUVLWGNPXHQKBFHVRVZBOEFQHEWDSMULTQAZIWBMTTPVQYSITPORLETMUXKRODVIPBGQGYMHQACAMJXXCLNZKOEHGYPMJAFJUDZCIRMABTTSNEDSISLCZVWTPFYCKKSIHHBZYGOUJHCXPJQALOULZGRRJECXVFNBIXHFBWRKCDJPUYZMNJRVMVSNNQUCAYHALNPDDGFTFIZRPSE");
    msg.description.assign("YOELJGASGNKLAVGWXBYGASQTPNXRLBCEUBVFDYXPKSMIFQUALPJKNPZKZGDRZOOYDAGSBBVIPTXXILMHEUNFRVMUNENBJTVUIHXNIZHHESFZHGPZDLFPCTQHWODCBLYSEESQPWIYRDHFBVANDTKWBONMKSSMOKQZREUWWLRXXHIQDPZGWONWQK");
    msg.vnamespace.assign("SXFGHXAXDTQCGBFFCQALQRPFCGMETPAQYLQBEQRRNMPMXLGCZMLHPJUESXDLWJGEBOPNVIMPDBVKPJHPNKNHMNJTRWVPIOTBDYYFLMUAHAUSUCDGDXZDCOSWCVJMRYUEEZCVJLTROYJRWYZXGMID");
    msg.start_man_id.assign("YNWUVGBRYSUGZPMHAWZVOHRMTKOVAHTOZYPALMJJMDUQXSQSIJOTNCHWTEDYPVRDLEOFHOLDCXXZGAWMYDUSIVXLSPZMVCAJL");
    IMC::PlanManeuver tmp_msg_0;
    tmp_msg_0.maneuver_id.assign("NUBGBSYSBPHYXIJQXGOQLPHOBZUJFHGKJLIYXSAMVSZQCWCKKAQJRRUMHNVMNAVIRVKSHTXFTMEBRPEXIJGCGCQQTIPMJBHDTIJFNPUSFWYYDNIARXPQZKPRYLDVIWAKBSHEWZW");
    IMC::Alignment tmp_tmp_msg_0_0;
    tmp_tmp_msg_0_0.timeout = 20917U;
    tmp_tmp_msg_0_0.lat = 0.1369081903333299;
    tmp_tmp_msg_0_0.lon = 0.5823622623521046;
    tmp_tmp_msg_0_0.speed = 0.7333110554228922;
    tmp_tmp_msg_0_0.speed_units = 30U;
    tmp_tmp_msg_0_0.custom.assign("YTACSNQEDXJRRXUNKNSUUXP");
    tmp_msg_0.data.set(tmp_tmp_msg_0_0);
    msg.maneuvers.push_back(tmp_msg_0);
    IMC::DynamicsSimParam tmp_msg_1;
    tmp_msg_1.op = 28U;
    tmp_msg_1.tas2acc_pgain = 0.608296877622948;
    tmp_msg_1.bank2p_pgain = 0.8059073443656086;
    msg.start_actions.push_back(tmp_msg_1);

    try
    {
      Utils::ByteBuffer bfr;
      IMC::Packet::serialize(&msg, bfr);
      IMC::Message* msg_d = IMC::Packet::deserialize(bfr.getBuffer(), bfr.getSize());
      test.boolean("PlanSpecification #0", msg == *msg_d);
      delete msg_d;
    }
    catch (IMC::InvalidMessageSize& e)
    {
      (void)e;
      test.boolean("msg #0", msg.getSerializationSize() > DUNE_IMC_CONST_MAX_SIZE);
    }
  }

  {
    IMC::PlanSpecification msg;
    msg.setTimeStamp(0.2806119970131816);
    msg.setSource(41221U);
    msg.setSourceEntity(36U);
    msg.setDestination(7339U);
    msg.setDestinationEntity(170U);
    msg.plan_id.assign("OXPLKYDRCOGQPUDPUMQLGFKMVZSPNRILBZYZDSYQZMSNXDXUQGTPEALTVJW");
    msg.description.assign("AQDIGIZEXKNISUGQWPFLPWFRUFVOSCUVDZYQMWPRPVSLULNBXJZFCDJXYHMRTLCXLAQOIWLGOEDBNDOBKHGTWREZTSSWCJOBAFODIZQSFMHBTODBGEIMWVGYFASKBLZVUKEKRQCLRNJYCGDLXZEUMYAPUCMARCITSJNVORMHCHHOZJJUTWSPEGAJKNVMDYXKYXFQUEWNTS");
    msg.vnamespace.assign("ACJTBJZDXRRWLOYLHGJJSLONMNJTZYHTNBVYEOWIAOPIFMUTGMEABVXYKQUFGENWDIUCVWFIJVTIOCSRHXABECESABNANCYPSQSXRTDHECWTHGLXKKWZNZZGV");
    IMC::PlanVariable tmp_msg_0;
    tmp_msg_0.name.assign("AQZXSHCVISMGNLVUUWQQZAYCDBRTRNARUWWMQDRTYHNDUTUJSSMVZYHDVNIJKGTFZKEIFYRZXCQGEQGCDAUQPPYDGPDALPVJSMOKCTAEOPRJJPBNEUJYVYCWHGLEXJAVEEHZLKJGFCTMIFBKWHOOFDLISBLWOUKXNVJSVQOPLMCZMXLZOKSNEZXQOTEADYWCBSKFWQKJTLONCIHPVKNFADFERFFYOZYNWPIIGTMUXXXMILRHRTSHAPGRHGXBM");
    tmp_msg_0.value.assign("DQMJCCAOQNYEBUKIDBGXKWUEGHEOWYCMAPVXKNWNRLZLIUOCPELJVRQPUKMPHGHHDICZWYFQLUJKFQVNFJATEMBZRMTNOHWBUFMHVQVPXACDRAOSYWDIYQYTRJYUFXXRYMHBJXOACILAYGNZGZDSFNFTUVMJHZPKLSTWFEICVPSRABKOZSKNFESNVXAEVDZOAWJHGQXKBPIKGTXYPQCJLMULTIOGLZDXNFQST");
    tmp_msg_0.type = 23U;
    tmp_msg_0.access = 56U;
    msg.variables.push_back(tmp_msg_0);
    msg.start_man_id.assign("QLFDKCQGCRMPLSHXOTWRJOQBENCTVUGBRUANGYNISHCWPSDEWWGTUGMQLZLUPEJLTFRVVDOEGFKRBYXB");
    IMC::PlanManeuver tmp_msg_1;
    tmp_msg_1.maneuver_id.assign("PBCSHBOYWQJAECUHHPJQAHIOTUTSENOHBCXAPDHNTPXLMPMWWVAVGLVLHVCXWWJBXJEKFNSBSEUDIRPGKRTTPWJHDNMNLMINGOMOXYFLJFVRDFLKLZVUCVAXOXRKXUDEUOZRFYDEUCWMWQOTIKDJUDROKAIUZJGQKKPINBYZEEPBWRTQPYYVIGZYOMDAIBFUSGFLAGZZZN");
    IMC::LowLevelControl tmp_tmp_msg_1_0;
    IMC::DesiredPitch tmp_tmp_tmp_msg_1_0_0;
    tmp_tmp_tmp_msg_1_0_0.value = 0.9471575536333434;
    tmp_tmp_msg_1_0.control.set(tmp_tmp_tmp_msg_1_0_0);
    tmp_tmp_msg_1_0.duration = 64989U;
    tmp_tmp_msg_1_0.custom.assign("LDBSDJWYAMLGMARRXGCIFSZTVIGTNMJAQQBHQKKJOVEQUPPRBGGXWERCQYZFRDKGCULEYLBIJHWRERZHXOPXH");
    tmp_msg_1.data.set(tmp_tmp_msg_1_0);
    IMC::Announce tmp_tmp_msg_1_1;
    tmp_tmp_msg_1_1.sys_name.assign("PCRMYGAMSFUVAUTQBCVXMJNYVCGSGJUBOAILQIUXCDANZEOVUTCIZXFFWARJOKTHPSAHWBRDKPTBDUTNWWERQJGOCIHKCBWIZEGXFKFXVMBDWZZIMJDRZKKWVOZYTSZHFNHLMRWLOKOKXHEQEYOVBNKFNAHRPDIDEZXOEOEAIYXCMTFCAQHTWLURVSSIMJPNHIPY");
    tmp_tmp_msg_1_1.sys_type = 61U;
    tmp_tmp_msg_1_1.owner = 37110U;
    tmp_tmp_msg_1_1.lat = 0.5984099507593605;
    tmp_tmp_msg_1_1.lon = 0.5240958877171019;
    tmp_tmp_msg_1_1.height = 0.38070792788413244;
    tmp_tmp_msg_1_1.services.assign("CRYKTYPMRXDAYDENLGSTVLFNMOHLMRZPYOMGNCZWNBITNAWMOLHDRPOSVVZDZZTTLEWLMKQJBEVRBQSYKCHVFEDMSVSQNINFEUAHIIIZDTYBCCQGNTTHHXCGEZLCSCTXKZAUJWCXYURBFXORHOKWKQRFFSZYLPPUAXWKEIRSYGWPVHJMUOAABPFPUDYAPMGUSOQUJQWMWIVGOIVUBBAJTXQJOAGB");
    tmp_msg_1.start_actions.push_back(tmp_tmp_msg_1_1);
    msg.maneuvers.push_back(tmp_msg_1);

    try
    {
      Utils::ByteBuffer bfr;
      IMC::Packet::serialize(&msg, bfr);
      IMC::Message* msg_d = IMC::Packet::deserialize(bfr.getBuffer(), bfr.getSize());
      test.boolean("PlanSpecification #1", msg == *msg_d);
      delete msg_d;
    }
    catch (IMC::InvalidMessageSize& e)
    {
      (void)e;
      test.boolean("msg #1", msg.getSerializationSize() > DUNE_IMC_CONST_MAX_SIZE);
    }
  }

  {
    IMC::PlanSpecification msg;
    msg.setTimeStamp(0.1762780585996776);
    msg.setSource(21171U);
    msg.setSourceEntity(188U);
    msg.setDestination(2520U);
    msg.setDestinationEntity(50U);
    msg.plan_id.assign("KQKMDXWBIBCBDFEBLJPUFQKALIYRVSICWFEZLULUMPEPYUJLRCZXTSSJRULXTNEAFBSNTCWQORHQNWECYLVFMQQIBTWBXUVNQHRVAADFDMDRXPAOHPSYYZMHCGIEZTRAYDHOBFXYFAIHJUVSHOKRNVLXDEQXHHHSPGIJKWAFTITCMXJPNNNJCKEJGN");
    msg.description.assign("BAPOKREWXWOMXIDQKAYTUBLGEQIGPUGBLCDUOTKNMMLMHBZLMJKODOVYJVCRDIGDOIWQNMQFJKBHFTVZAVJFYHXXKCXVEBHXERMUBHIRIKCPUSFEWZQEJSWURSSCKFHAJXZDSHJUFNVIPDOOQFLNYS");
    msg.vnamespace.assign("QINDFRRLMC");
    msg.start_man_id.assign("TEDKBBBCNOQPVTNOXOGOIJUCNYXLJXCDCJCPJKVSXHQGCZMYCZLPYNFKVVRURWEATGLJFMRCKDEHTTAKHOYMGSBYFQDEHIZXZFPSDNEOUQGTNLLWRGJIELYYHDLAUPHXHJLCSMWZDRILRIEHPLGWAO");
    IMC::PlanManeuver tmp_msg_0;
    tmp_msg_0.maneuver_id.assign("AZFQHHMZLRUYWOQJPTCIIZUNZFUNHQFQCTMTKBEQHWKPWUUKVLKCXSDOBATLTKDETESXIRWJHIUYXPKMVGNDTFDXSFTXXOYSAJNOPDUYIYWRKHVA");
    IMC::FollowPoint tmp_tmp_msg_0_0;
    tmp_tmp_msg_0_0.target.assign("YSQLZAGMXLVXTEJYIKVUMZUKDDUGYDSPBHTJSKIIFJRBBMIRECCQIYCXOUDKPVHRXSEBFWVULPEDEJOAPXAYQFFYMVLBIOSWMEFPGJWWOLAXNOEXMCXHNMCLNKRKEFIVYDJMDZASQTEAOZKRQNIRZZPTYJTZWJWJQHXRHGHCNRGSV");
    tmp_tmp_msg_0_0.max_speed = 0.39771545393424546;
    tmp_tmp_msg_0_0.speed_units = 223U;
    tmp_tmp_msg_0_0.lat = 0.34936122661671665;
    tmp_tmp_msg_0_0.lon = 0.9824182816682048;
    tmp_tmp_msg_0_0.z = 0.8718647760759866;
    tmp_tmp_msg_0_0.z_units = 160U;
    tmp_tmp_msg_0_0.custom.assign("OIXZDIXNBGBCUESDAUMUKQEPNMPIAEHYVXBNBOZYBERVZIRUZEXCHKPHGEWHQZPUCNZKKAKTEPLDFMMYUMXRXZLRIAKUYQOMDPSWVAHVDLYBJHYIJFEEFBYSWHJJIIFFWCSFKHWGNABAMXOGJRSQRTMFPYSRDUAGTDWFZBVJPMNQSOPZCDGRNWWWKAUGOVWCLOC");
    tmp_msg_0.data.set(tmp_tmp_msg_0_0);
    IMC::EulerAnglesDelta tmp_tmp_msg_0_1;
    tmp_tmp_msg_0_1.time = 0.1343772819744753;
    tmp_tmp_msg_0_1.x = 0.9713068277319905;
    tmp_tmp_msg_0_1.y = 0.7851691026539998;
    tmp_tmp_msg_0_1.z = 0.6068348293478012;
    tmp_tmp_msg_0_1.timestep = 0.011996083884958542;
    tmp_msg_0.start_actions.push_back(tmp_tmp_msg_0_1);
    msg.maneuvers.push_back(tmp_msg_0);
    IMC::PlanTransition tmp_msg_1;
    tmp_msg_1.source_man.assign("YWXXMLFSXXMQOZAFJDSTVZZBSISPPUIYVXJULWARFQIVHHZRKNVHQHDLZNMEEGFPWFRBZCZLTKCXTYFGTAUPCKQJEGLISTGGMFJNOTR");
    tmp_msg_1.dest_man.assign("TEDYHNIKZBXWMSVBFUDOPJGQBQYSFDAVEPUXFJQTDDBXPHHKJYLSEWLLKLQEMKODIFTROCDMWWTZVPQQEITGWGDIYOQESPAUCJYWXOACBJTPHVOUWVBSVCKYFGRDRUBSKGZEKNERHPIZWQAYUSRIYXXNGQETLIINXHBQVBLYXIFMFNCIBEWHLFPMALUJJPUNVSGMGRZUNGMTPRDNOJK");
    tmp_msg_1.conditions.assign("VLKRNRHBSZBKUJLXLENCUAAKDYMCHELAJQDISKWOETHVHVYRAHJIDIIFCPGZJMGTAMYCAGQDKXJRFAUYUVFPYEQHWNTWOZMQFSIKERZADBHNRDMLXIXEGSTNMOUGGCPQEWDKFKQINUAIDOVWBZUGJQXLXIPTM");
    msg.transitions.push_back(tmp_msg_1);
    IMC::FormState tmp_msg_2;
    tmp_msg_2.possimerr = 0.07506878366641911;
    tmp_msg_2.converg = 0.00691815047986466;
    tmp_msg_2.turbulence = 0.7217604892783972;
    tmp_msg_2.possimmon = 51U;
    tmp_msg_2.commmon = 106U;
    tmp_msg_2.convergmon = 204U;
    msg.start_actions.push_back(tmp_msg_2);
    IMC::DesiredControl tmp_msg_3;
    tmp_msg_3.x = 0.13364318187360968;
    tmp_msg_3.y = 0.48583812658680214;
    tmp_msg_3.z = 0.9034177177831972;
    tmp_msg_3.k = 0.6322074255151837;
    tmp_msg_3.m = 0.02379840859860527;
    tmp_msg_3.n = 0.24764353029620367;
    tmp_msg_3.flags = 179U;
    msg.end_actions.push_back(tmp_msg_3);

    try
    {
      Utils::ByteBuffer bfr;
      IMC::Packet::serialize(&msg, bfr);
      IMC::Message* msg_d = IMC::Packet::deserialize(bfr.getBuffer(), bfr.getSize());
      test.boolean("PlanSpecification #2", msg == *msg_d);
      delete msg_d;
    }
    catch (IMC::InvalidMessageSize& e)
    {
      (void)e;
      test.boolean("msg #2", msg.getSerializationSize() > DUNE_IMC_CONST_MAX_SIZE);
    }
  }

  {
    IMC::PlanManeuver msg;
    msg.setTimeStamp(0.3181499257988347);
    msg.setSource(15107U);
    msg.setSourceEntity(34U);
    msg.setDestination(42157U);
    msg.setDestinationEntity(14U);
    msg.maneuver_id.assign("OJRYXUDZKTYYOBYXNWSBUAWLHSXQHPIPBUERMYNXBTRWGVGDDEVIGKZHPGHUQOVMIHVJRISQNLLJOFIZCJRJNAPUKSJADWYZHRFNULZBDCZIPSVADKKATEFGLQECDIBJVQKPQCWPUOAEQZFTP");
    IMC::StationKeeping tmp_msg_0;
    tmp_msg_0.lat = 0.6772235430389923;
    tmp_msg_0.lon = 0.9356263807231555;
    tmp_msg_0.z = 0.19138413496877682;
    tmp_msg_0.z_units = 8U;
    tmp_msg_0.radius = 0.4997684397305324;
    tmp_msg_0.duration = 43750U;
    tmp_msg_0.speed = 0.3705735242605517;
    tmp_msg_0.speed_units = 236U;
    tmp_msg_0.custom.assign("SLEHXPJHOEJWYQLWWKYQGCBPENJFLLWNAFMJGYMNYNIEA");
    msg.data.set(tmp_msg_0);

    try
    {
      Utils::ByteBuffer bfr;
      IMC::Packet::serialize(&msg, bfr);
      IMC::Message* msg_d = IMC::Packet::deserialize(bfr.getBuffer(), bfr.getSize());
      test.boolean("PlanManeuver #0", msg == *msg_d);
      delete msg_d;
    }
    catch (IMC::InvalidMessageSize& e)
    {
      (void)e;
      test.boolean("msg #0", msg.getSerializationSize() > DUNE_IMC_CONST_MAX_SIZE);
    }
  }

  {
    IMC::PlanManeuver msg;
    msg.setTimeStamp(0.750858522069342);
    msg.setSource(34510U);
    msg.setSourceEntity(59U);
    msg.setDestination(58647U);
    msg.setDestinationEntity(138U);
    msg.maneuver_id.assign("USIZZFOYEZFXWLKDAHACNYDDBRUBOQDFOCULVLLBSWQYLYFCYXTEIHJCRFKRA");
    IMC::FormationPlanExecution tmp_msg_0;
    tmp_msg_0.group_name.assign("GYCAYAANFSUQODRQPILNXCVOMHARRHQKRLMMDYHMEUYGSKKCFAXBHVPKCHIXBDLHADCHJMOVPPKLMZTOGTWFOQHQTAOWZVINBTWLVOQNZLXMSAZCMKWKXNDXLSDJPTKMPBEGTQXYBFFWWVONQYEENUJGSGWZMVBBJYIBEUCDIRZUZYZQ");
    tmp_msg_0.formation_name.assign("HCITXXUDCNXDBGHRRSKRNDNGWOBEACQSUPJGBQEXKZQMNPGONVHCIRGTZLWWMBB");
    tmp_msg_0.plan_id.assign("IRUBPAGIOJSENDMVAOUXYMCPWBYKPSIZEKDFCRYROJGDUOQOHQ");
    tmp_msg_0.description.assign("DNBQJAMQJYLUUDPRARBYTAPPXXODLXJUERRBIXYNXRFMHCWAJYOMPICSJTUODMCQVLIAFXHPSAZQYYCRKLGFNLCFNSWUGWBHHUNGZCMYMEGDVVQEECIIETFCRJHKTWBKZLGFAYVLJZNEKBIILJOWCOSGHOUBITWVTOGIOKXYAGZTBDEUPPBWSSKQVQQSNZDSHBVVRFTRNEMVFMAAOYKRMHVILDJKMXHGUZEHZOS");
    tmp_msg_0.leader_speed = 0.6703353959226429;
    tmp_msg_0.leader_bank_lim = 0.6103872273013171;
    tmp_msg_0.pos_sim_err_lim = 0.8885052787240786;
    tmp_msg_0.pos_sim_err_wrn = 0.7443046735677847;
    tmp_msg_0.pos_sim_err_timeout = 16607U;
    tmp_msg_0.converg_max = 0.9002741380474717;
    tmp_msg_0.converg_timeout = 16847U;
    tmp_msg_0.comms_timeout = 43630U;
    tmp_msg_0.turb_lim = 0.9180318964609842;
    tmp_msg_0.custom.assign("GEPXATTNFGDXAFCCOIUMLNAUYNVGBRMLYGMYIQLRUYKSJPDKGZTQIZQSFVLPOOJHCHZFPJWHPCJPXTBZREKFDDTITPSBAZMCUIBJEXAPHKRIFNCSXKIYBADRXLFIXGVKWJQWEDUOOOT");
    msg.data.set(tmp_msg_0);
    IMC::Brake tmp_msg_1;
    tmp_msg_1.op = 83U;
    msg.end_actions.push_back(tmp_msg_1);

    try
    {
      Utils::ByteBuffer bfr;
      IMC::Packet::serialize(&msg, bfr);
      IMC::Message* msg_d = IMC::Packet::deserialize(bfr.getBuffer(), bfr.getSize());
      test.boolean("PlanManeuver #1", msg == *msg_d);
      delete msg_d;
    }
    catch (IMC::InvalidMessageSize& e)
    {
      (void)e;
      test.boolean("msg #1", msg.getSerializationSize() > DUNE_IMC_CONST_MAX_SIZE);
    }
  }

  {
    IMC::PlanManeuver msg;
    msg.setTimeStamp(0.64439402979651);
    msg.setSource(33475U);
    msg.setSourceEntity(78U);
    msg.setDestination(45594U);
    msg.setDestinationEntity(87U);
    msg.maneuver_id.assign("MICIREHVEGCCNNYXLQCAPJSATIOQTWHPOZAPWVOSSLDIHXHSGRGRGBMTBEFEFWGKANDGYULMTFASMUICINQDKKRNLTWQSJJRZVHVQIDZMGKXUYXKWLOUJYPMYHKT");
    IMC::Elevator tmp_msg_0;
    tmp_msg_0.timeout = 56706U;
    tmp_msg_0.flags = 189U;
    tmp_msg_0.lat = 0.6261358168440914;
    tmp_msg_0.lon = 0.6978274685234661;
    tmp_msg_0.start_z = 0.7465841255229306;
    tmp_msg_0.start_z_units = 59U;
    tmp_msg_0.end_z = 0.057357737545095655;
    tmp_msg_0.end_z_units = 50U;
    tmp_msg_0.radius = 0.05535757914712536;
    tmp_msg_0.speed = 0.20115719043082003;
    tmp_msg_0.speed_units = 249U;
    tmp_msg_0.custom.assign("DJUECTLXBJQUSRBNEZLXMVSZZFJZUWVIJPUOXGKQOLMLORTCXZLEUXIYIAQCKFLGINCIPUOGNVLASLWBDYYSCFBOANIZTSGVFJSMGHBAAVHFHKU");
    msg.data.set(tmp_msg_0);
    IMC::ProfileSample tmp_msg_1;
    tmp_msg_1.depth = 8236U;
    tmp_msg_1.avg = 0.1931333952565032;
    msg.start_actions.push_back(tmp_msg_1);
    IMC::HistoricTelemetry tmp_msg_2;
    tmp_msg_2.altitude = 0.3386027230828741;
    tmp_msg_2.roll = 13986U;
    tmp_msg_2.pitch = 18226U;
    tmp_msg_2.yaw = 56968U;
    tmp_msg_2.speed = 3094;
    msg.end_actions.push_back(tmp_msg_2);

    try
    {
      Utils::ByteBuffer bfr;
      IMC::Packet::serialize(&msg, bfr);
      IMC::Message* msg_d = IMC::Packet::deserialize(bfr.getBuffer(), bfr.getSize());
      test.boolean("PlanManeuver #2", msg == *msg_d);
      delete msg_d;
    }
    catch (IMC::InvalidMessageSize& e)
    {
      (void)e;
      test.boolean("msg #2", msg.getSerializationSize() > DUNE_IMC_CONST_MAX_SIZE);
    }
  }

  {
    IMC::PlanTransition msg;
    msg.setTimeStamp(0.385017850271952);
    msg.setSource(8216U);
    msg.setSourceEntity(152U);
    msg.setDestination(19933U);
    msg.setDestinationEntity(193U);
    msg.source_man.assign("KAWRFBANYBRPIFXFBZTRQRZWYVULCHBZTNOMFIFDOPCLSDOYHOPPEPAWGVAYAQCBPXDOZGJIURIMMVLBXJRGHLGSHXLVVFTOAZIXNYPEEXWETEXNMJMCSDWJMZRSVZUHGEOSIXBKICNOUTKQTCQKFQCWPUGNQYQDBHNEVRVZCSKGTDWDSLTQTDWJBIKXLKMZVIQMJFWKONSJETYHEWSDR");
    msg.dest_man.assign("LMDDYBNPCEKNEVQIQAXDBWUFXNXIIQWMMVAYOSPNJXUBXHNDDHWKP");
    msg.conditions.assign("RCAEIMYGPVCHDANFLMTSDGYXIORQDKZYKVRVOKNPWSJFAJXQYFRMCOTGLPJFTZOWQQVVFOWZXWEINNVPLKIDKAHYKM");
    IMC::EulerAnglesDelta tmp_msg_0;
    tmp_msg_0.time = 0.6216162077109961;
    tmp_msg_0.x = 0.5395407840115832;
    tmp_msg_0.y = 0.4002982338721941;
    tmp_msg_0.z = 0.1442387212112085;
    tmp_msg_0.timestep = 0.29595842069142453;
    msg.actions.push_back(tmp_msg_0);

    try
    {
      Utils::ByteBuffer bfr;
      IMC::Packet::serialize(&msg, bfr);
      IMC::Message* msg_d = IMC::Packet::deserialize(bfr.getBuffer(), bfr.getSize());
      test.boolean("PlanTransition #0", msg == *msg_d);
      delete msg_d;
    }
    catch (IMC::InvalidMessageSize& e)
    {
      (void)e;
      test.boolean("msg #0", msg.getSerializationSize() > DUNE_IMC_CONST_MAX_SIZE);
    }
  }

  {
    IMC::PlanTransition msg;
    msg.setTimeStamp(0.47447170366630453);
    msg.setSource(12420U);
    msg.setSourceEntity(219U);
    msg.setDestination(35181U);
    msg.setDestinationEntity(129U);
    msg.source_man.assign("JYTLBXVXEGQRXTKGGDMXVKBDWZJFUECSCFZBIOLMSQAMOFFTFIQU");
    msg.dest_man.assign("IHFNVXOOLJYVCVKHWZQLDXZCOASIYAJXGWNKEFITHTZBMIKARHWDBQJTSSIZQIYSNYFQTRUPGQNPJ");
    msg.conditions.assign("DQZYQYSURAGHTPJNZQAELYCXDNIMGJWHPKMTRQGUEIYNZGSCZNCVHRRYLLB");

    try
    {
      Utils::ByteBuffer bfr;
      IMC::Packet::serialize(&msg, bfr);
      IMC::Message* msg_d = IMC::Packet::deserialize(bfr.getBuffer(), bfr.getSize());
      test.boolean("PlanTransition #1", msg == *msg_d);
      delete msg_d;
    }
    catch (IMC::InvalidMessageSize& e)
    {
      (void)e;
      test.boolean("msg #1", msg.getSerializationSize() > DUNE_IMC_CONST_MAX_SIZE);
    }
  }

  {
    IMC::PlanTransition msg;
    msg.setTimeStamp(0.9387817588612556);
    msg.setSource(55015U);
    msg.setSourceEntity(154U);
    msg.setDestination(57043U);
    msg.setDestinationEntity(38U);
    msg.source_man.assign("SRXFMNNWMANKUVAXIPOCGPCBFRUCTNIEAYJBQHBQPEWBJRTOLEHRGMVJNAKVMPTGRCSYATZIYKMHDPUMNOUSYHLIFVGJLDPWIUBYKZTYQSQNAOQWGTJCDUFIRQIXFLYKDJAWSILERHHEZCUVSHCIDYUNSHFKYGBJXPGVJGFQEGGQBPXORKMXLHKVZTEAAWXMNLF");
    msg.dest_man.assign("ICJGGPGTJCQGZXULDHRKYQUPPABSSVZVQXDYIOZNKPXQLUFJLSAREOYTCOWSPGKXJVRAZDWULMKEERYNWJDXRBMQGHODIIFMCZHBDARDVNWSGSXCMMHIVSWTIMQVFNHKNRJ");
    msg.conditions.assign("ZTGWGVVBLPFKCOAYZFXQMDPZMNIRMAPQHCWPRSPTORFZCFSWOJGFVUXYMMJALXEHCEPFVNZNXIORQICBUZYYUBIPNJUSTSBFJXHYGTIEDVWSSDTHILRVWHTAVKVJHKTENLPUMUMIIGXLXXUW");

    try
    {
      Utils::ByteBuffer bfr;
      IMC::Packet::serialize(&msg, bfr);
      IMC::Message* msg_d = IMC::Packet::deserialize(bfr.getBuffer(), bfr.getSize());
      test.boolean("PlanTransition #2", msg == *msg_d);
      delete msg_d;
    }
    catch (IMC::InvalidMessageSize& e)
    {
      (void)e;
      test.boolean("msg #2", msg.getSerializationSize() > DUNE_IMC_CONST_MAX_SIZE);
    }
  }

  {
    IMC::EmergencyControl msg;
    msg.setTimeStamp(0.08185766802607175);
    msg.setSource(63353U);
    msg.setSourceEntity(173U);
    msg.setDestination(11136U);
    msg.setDestinationEntity(197U);
    msg.command = 143U;
    IMC::PlanSpecification tmp_msg_0;
    tmp_msg_0.plan_id.assign("TRPQWQIKQBYGSRSTHMZEKUXLVFMXXIRDZZPJSNBCTZNOGKDZTUUOXOAOEAXVLWJLQUFKIDNOUMFNLBGBFHWJMHSYGVLPXTPMGDZIKAXSKPDECIAIUVKZIGB");
    tmp_msg_0.description.assign("VZRAPEKXBEDUEJOBSQPIHJVB");
    tmp_msg_0.vnamespace.assign("WIPCAOPOWAZIZUAOYQNMOUTTIVSKZNWEDYSGBQOUMLBYBHNRARRGHPTULCGDHUMNCJSSJBHPVPJESDXTUEZDXYOADJJRLFVYQXFJICOOENPQOWYNMMCRDVLAIBDLTGVKAMEMHTEKEDHSNNZIXEIKJYPSPZMVXIMCJHLUESQFBNKGSUYPHFWKQQKOFWZRGGFMTBYFZWZQKYRWTSKQAAHNBFBPIXUDUTZLVHXJTJGGCECLIVCQRX");
    IMC::PlanVariable tmp_tmp_msg_0_0;
    tmp_tmp_msg_0_0.name.assign("TMYVGWEPSHBMHNQFTXZWXERJCDOYVFIVFQWKPCGVLPNXGSHQIBPTVKPJXYBYKDLDOSNUXUSYRXZVAAZAPJUZGIUNEALIEZLLUIRXMORUTROIIGBHBBKNNMCITCDRKKAHSXCQVGGZCCEHE");
    tmp_tmp_msg_0_0.value.assign("GTBQEZVZBNDNVXKEXDHABWYYDTVSWOCQPOGUFNPQWXVYJGXXTYRXXUMKFGGMKACKHKIOWANWIWCLFRFPGBHBNHXXDNZGROJ");
    tmp_tmp_msg_0_0.type = 95U;
    tmp_tmp_msg_0_0.access = 220U;
    tmp_msg_0.variables.push_back(tmp_tmp_msg_0_0);
    tmp_msg_0.start_man_id.assign("TCPPQADJFSV");
    IMC::GpsFix tmp_tmp_msg_0_1;
    tmp_tmp_msg_0_1.validity = 38290U;
    tmp_tmp_msg_0_1.type = 156U;
    tmp_tmp_msg_0_1.utc_year = 47874U;
    tmp_tmp_msg_0_1.utc_month = 213U;
    tmp_tmp_msg_0_1.utc_day = 118U;
    tmp_tmp_msg_0_1.utc_time = 0.7730706345802782;
    tmp_tmp_msg_0_1.lat = 0.3684652702470679;
    tmp_tmp_msg_0_1.lon = 0.4007482439025073;
    tmp_tmp_msg_0_1.height = 0.1536237983559786;
    tmp_tmp_msg_0_1.satellites = 244U;
    tmp_tmp_msg_0_1.cog = 0.04876867593338663;
    tmp_tmp_msg_0_1.sog = 0.044315244967730316;
    tmp_tmp_msg_0_1.hdop = 0.12500480175668183;
    tmp_tmp_msg_0_1.vdop = 0.17834335101448173;
    tmp_tmp_msg_0_1.hacc = 0.16599024416538388;
    tmp_tmp_msg_0_1.vacc = 0.10770909874845747;
    tmp_msg_0.start_actions.push_back(tmp_tmp_msg_0_1);
    IMC::SetControlSurfaceDeflection tmp_tmp_msg_0_2;
    tmp_tmp_msg_0_2.id = 20U;
    tmp_tmp_msg_0_2.angle = 0.6155201122852227;
    tmp_msg_0.end_actions.push_back(tmp_tmp_msg_0_2);
    msg.plan.set(tmp_msg_0);

    try
    {
      Utils::ByteBuffer bfr;
      IMC::Packet::serialize(&msg, bfr);
      IMC::Message* msg_d = IMC::Packet::deserialize(bfr.getBuffer(), bfr.getSize());
      test.boolean("EmergencyControl #0", msg == *msg_d);
      delete msg_d;
    }
    catch (IMC::InvalidMessageSize& e)
    {
      (void)e;
      test.boolean("msg #0", msg.getSerializationSize() > DUNE_IMC_CONST_MAX_SIZE);
    }
  }

  {
    IMC::EmergencyControl msg;
    msg.setTimeStamp(0.6388744406387526);
    msg.setSource(58635U);
    msg.setSourceEntity(140U);
    msg.setDestination(35432U);
    msg.setDestinationEntity(31U);
    msg.command = 201U;
    IMC::PlanSpecification tmp_msg_0;
    tmp_msg_0.plan_id.assign("TYVGHEEVVR");
    tmp_msg_0.description.assign("CWSKKBBXKWGRFPO");
    tmp_msg_0.vnamespace.assign("GAZDTUOYIMWZWHBCTACSLAPGUJKZEXXZHQUDIMTORYUPRNAEEGEBDMQQMWCPWEPSDLVSLNYADVXBCETUQJJUGJMARCUFXZRWSNDRGUKQLJQBBOFNYIIPWHONKBQEIFALIAVBFLHDCGXESHISHYYGZXVGKBOLJZK");
    tmp_msg_0.start_man_id.assign("URWSWZEUQWSNXSYXZTJEMOAHWPNGKYRLTIZTNSFJKIEKNQBAMMOKWDPPCDTGJOGDKUSTYZVGTBKJDUNQUXMSMIV");
    IMC::PlanTransition tmp_tmp_msg_0_0;
    tmp_tmp_msg_0_0.source_man.assign("ALFWKRKMNREIHXCEYNTGTZMMXTOSBQXUYCDJSOEAANTFYASRJWBFWWICZRHTKWRKDYVFTNFRBXKHVAPKYBGILGQUMUQESIFZIONPUTDKWXBMCVXEUJBFFPIPE");
    tmp_tmp_msg_0_0.dest_man.assign("PTRRGDVLIAGFEFFYMCGGYYSBJRGRKENQWPAGAQGQKOHVJWLDNUZJBNMVDUEOOTLLHNISXBCAAYIGADVIRMPHLMSTEWIONCKILZKSUJNLEDWZVKXLEUBHNWFUTBIEEXQQCSCZTZTUDHGUOAP");
    tmp_tmp_msg_0_0.conditions.assign("CIMQLAUNAXRXDYHVAYORXPORLKZLZAGVWKKYZVYTYBTESBTLUBGFPFKBBSFCEUXIHSFFYEOOQGMZKMPEKRGLGQYAHZXFJOBAMNCNLUHFLEQSSOHCRDQWLHSINRVTYOMDCIKPPZUECFDGJAOCFGVJMQFAHQIDJOZUNJQLSYPIBKRTPCVRVXMTLNZYHQNIWUIEAGTDJXDWCTSADMKVKBGBIJRJWHHIEPXJUWJVSZWWXBWUSMTDNONZPEUM");
    tmp_msg_0.transitions.push_back(tmp_tmp_msg_0_0);
    IMC::NavigationData tmp_tmp_msg_0_1;
    tmp_tmp_msg_0_1.bias_psi = 0.19125022319413976;
    tmp_tmp_msg_0_1.bias_r = 0.5860390083619418;
    tmp_tmp_msg_0_1.cog = 0.562625252184829;
    tmp_tmp_msg_0_1.cyaw = 0.7874804913061629;
    tmp_tmp_msg_0_1.lbl_rej_level = 0.4552091086437833;
    tmp_tmp_msg_0_1.gps_rej_level = 0.02919472957248459;
    tmp_tmp_msg_0_1.custom_x = 0.9871866356136065;
    tmp_tmp_msg_0_1.custom_y = 0.10853798180363328;
    tmp_tmp_msg_0_1.custom_z = 0.20171169613924667;
    tmp_msg_0.start_actions.push_back(tmp_tmp_msg_0_1);
    msg.plan.set(tmp_msg_0);

    try
    {
      Utils::ByteBuffer bfr;
      IMC::Packet::serialize(&msg, bfr);
      IMC::Message* msg_d = IMC::Packet::deserialize(bfr.getBuffer(), bfr.getSize());
      test.boolean("EmergencyControl #1", msg == *msg_d);
      delete msg_d;
    }
    catch (IMC::InvalidMessageSize& e)
    {
      (void)e;
      test.boolean("msg #1", msg.getSerializationSize() > DUNE_IMC_CONST_MAX_SIZE);
    }
  }

  {
    IMC::EmergencyControl msg;
    msg.setTimeStamp(0.23032934087737789);
    msg.setSource(50514U);
    msg.setSourceEntity(105U);
    msg.setDestination(60157U);
    msg.setDestinationEntity(253U);
    msg.command = 80U;
    IMC::PlanSpecification tmp_msg_0;
    tmp_msg_0.plan_id.assign("IWRNLMXKQBJQSGKQJUUBMDIUCMJPRCVTXKENNXWPGEFYTYSTXZNYQHLXCKGESDMYXUTMBJVHCUPYLTDCLOAPRAHRDSUAPWSPZZOKAZMHIRCMJLIFQPXIHOVEVOQFGNYWDBLFHVWAQEEUPSHZAQECXKNSADWBKAV");
    tmp_msg_0.description.assign("CHWULLLHGJMJXTRNTESHZXYUGVKAMBNIGHHBZEBKCFXQVGSXPGNHUCRVHQQEFJWSYTIFAXUZRAAASQYCFTULOOOIYOKGECFUIKYLTKNZZTCGMQFJLXYCBIGBOSWWPWHNDBVDFBKEMDDDEOTPQKISCDOREIFPMYVXYRVUHLNVTTBAZPNNEQIVKUGJSOLFDLNJPCDMUQLWUIMKJRPOWTFOZMYHDPAVPKGSIABDWXARJWMZXZ");
    tmp_msg_0.vnamespace.assign("JMDOFDZOIUPNSDLQLGENHEDJOJXTDIAAZLRRPWOISNLIXQNHKVBRAGAPBFSIFRCQCKXLZWXEGEBZSQCCGILJBDYBAOVKRYIUECTQSCRXFK");
    IMC::PlanVariable tmp_tmp_msg_0_0;
    tmp_tmp_msg_0_0.name.assign("BJKFVCLDHPAUBIFRSXFPZPOWKHSZJRCDOWMMWOPTTXCLTGZMWNOATRAHYXYKXQHBIGZTMEMFVERMVCOQQUQIEMNUJANFAGBGVBGIXYZFTMSYDQCKJRCQYZSLIWQFCKZXWCPNCYEWKEPLYWHUTNEDEMODZIZTOEOGGSUBNVEDVXJMGRXRUSITRHAZDJFBYSQONDURBDNFYQSKOL");
    tmp_tmp_msg_0_0.value.assign("FJBTKLZLWGVDSJKQNRURYEPZOZKNXFWXCEHDKDTPFGRNBULINQYNCIUMVFISIYFQVBHTYBOCEQBVHGDXOVKQASDKTKXCJGXNPNEYKAEZMRUGVNIMWYWDHRHLLOPLISG");
    tmp_tmp_msg_0_0.type = 111U;
    tmp_tmp_msg_0_0.access = 121U;
    tmp_msg_0.variables.push_back(tmp_tmp_msg_0_0);
    tmp_msg_0.start_man_id.assign("WXDWQKAZITCJGEUVCOIYWIGXPQDKFGCGTVGCGHOAQRSERESRHYLNXLHWFPQMNYRSHRQZLATVBZBOYDONEXVUHWXHXBQKOTZWCXHMYBSCCEKJRYILZMVXSWDTCPYZAWINJLKLIQRJZNCWTTZWRUPBUOOQZGAMTOIFJHMSFKVGODNPFBAUBIVBNAQJJLDJYEFVAHUEMFGIKXMDSLZPKDV");
    IMC::PlanManeuver tmp_tmp_msg_0_1;
    tmp_tmp_msg_0_1.maneuver_id.assign("ATIHVVWBFUZRGJAMCMAEVXWIXOVDOPRIBBENIEGHBKQGIRVZKAFCOTATRZPZZUPSQTZBFSXSEFDRGJJJYMONMILMVIVZSZZCQLTAAGLHCQKMKFFXSQPDLVELEMWROGHTGTNGSDAUUUZYNLFHPWNKHXPRFMGPXOQRHYOAHESJ");
    IMC::StationKeeping tmp_tmp_tmp_msg_0_1_0;
    tmp_tmp_tmp_msg_0_1_0.lat = 0.23751892836299116;
    tmp_tmp_tmp_msg_0_1_0.lon = 0.34696156381764054;
    tmp_tmp_tmp_msg_0_1_0.z = 0.03442195682376892;
    tmp_tmp_tmp_msg_0_1_0.z_units = 77U;
    tmp_tmp_tmp_msg_0_1_0.radius = 0.3748577227122486;
    tmp_tmp_tmp_msg_0_1_0.duration = 56269U;
    tmp_tmp_tmp_msg_0_1_0.speed = 0.593964225321955;
    tmp_tmp_tmp_msg_0_1_0.speed_units = 29U;
    tmp_tmp_tmp_msg_0_1_0.custom.assign("UYWIJILTQUFZKGGWCMJYEQILXABDHHCSCWSTDMRYVSGIDPTASTDKUPJUEUOLHHWANGG");
    tmp_tmp_msg_0_1.data.set(tmp_tmp_tmp_msg_0_1_0);
    IMC::UsblModem tmp_tmp_tmp_msg_0_1_1;
    tmp_tmp_tmp_msg_0_1_1.name.assign("RCHDRLKXIBSCUKIHOTILMFVAVOBFTZZMWKCZSQDJHJGYFSEXKLXUBNMLGHWEVVMQZBOKPFLXQQYJXKTWWDGYBRSHZBWUXAWTHALTIEMXOZTWRREOIUAPPR");
    tmp_tmp_tmp_msg_0_1_1.lat = 0.08690815951952258;
    tmp_tmp_tmp_msg_0_1_1.lon = 0.011094394230299898;
    tmp_tmp_tmp_msg_0_1_1.z = 0.7601391990313052;
    tmp_tmp_tmp_msg_0_1_1.z_units = 225U;
    tmp_tmp_msg_0_1.start_actions.push_back(tmp_tmp_tmp_msg_0_1_1);
    tmp_msg_0.maneuvers.push_back(tmp_tmp_msg_0_1);
    IMC::AlignmentState tmp_tmp_msg_0_2;
    tmp_tmp_msg_0_2.state = 90U;
    tmp_msg_0.end_actions.push_back(tmp_tmp_msg_0_2);
    msg.plan.set(tmp_msg_0);

    try
    {
      Utils::ByteBuffer bfr;
      IMC::Packet::serialize(&msg, bfr);
      IMC::Message* msg_d = IMC::Packet::deserialize(bfr.getBuffer(), bfr.getSize());
      test.boolean("EmergencyControl #2", msg == *msg_d);
      delete msg_d;
    }
    catch (IMC::InvalidMessageSize& e)
    {
      (void)e;
      test.boolean("msg #2", msg.getSerializationSize() > DUNE_IMC_CONST_MAX_SIZE);
    }
  }

  {
    IMC::EmergencyControlState msg;
    msg.setTimeStamp(0.41833851798157196);
    msg.setSource(24075U);
    msg.setSourceEntity(119U);
    msg.setDestination(26719U);
    msg.setDestinationEntity(161U);
    msg.state = 144U;
    msg.plan_id.assign("CJDPIRNPQTRKRCGXQHRZIYKNJLSPCUQUWIWGOSWBMUJBCEEVXWYLRINKGFMPYFAFSLYTYACWEXYCLBCQUVBFAOFSKDYOLWTQCJOPTXKVMQGZGMPHAVFKLXXOZLHHUHTPLQHCKYTZAVJKFMJXZBLIJHSMRHAIAPSSMYBGDVGHEORDEQAOISIXJUGONXZBJVEMYDNFMCDGWZUVDBQWNJKFUTNXVWZDQRDINUSITMLPTEEENTW");
    msg.comm_level = 124U;

    try
    {
      Utils::ByteBuffer bfr;
      IMC::Packet::serialize(&msg, bfr);
      IMC::Message* msg_d = IMC::Packet::deserialize(bfr.getBuffer(), bfr.getSize());
      test.boolean("EmergencyControlState #0", msg == *msg_d);
      delete msg_d;
    }
    catch (IMC::InvalidMessageSize& e)
    {
      (void)e;
      test.boolean("msg #0", msg.getSerializationSize() > DUNE_IMC_CONST_MAX_SIZE);
    }
  }

  {
    IMC::EmergencyControlState msg;
    msg.setTimeStamp(0.5683628347294486);
    msg.setSource(44576U);
    msg.setSourceEntity(217U);
    msg.setDestination(35938U);
    msg.setDestinationEntity(140U);
    msg.state = 104U;
    msg.plan_id.assign("MYKWVPPSEQRJKUOAKKGOUVVLRMWAAWPIDZQVQRYXBHIAHGIJRCBWRLFOLSORO");
    msg.comm_level = 90U;

    try
    {
      Utils::ByteBuffer bfr;
      IMC::Packet::serialize(&msg, bfr);
      IMC::Message* msg_d = IMC::Packet::deserialize(bfr.getBuffer(), bfr.getSize());
      test.boolean("EmergencyControlState #1", msg == *msg_d);
      delete msg_d;
    }
    catch (IMC::InvalidMessageSize& e)
    {
      (void)e;
      test.boolean("msg #1", msg.getSerializationSize() > DUNE_IMC_CONST_MAX_SIZE);
    }
  }

  {
    IMC::EmergencyControlState msg;
    msg.setTimeStamp(0.9416412265352573);
    msg.setSource(43423U);
    msg.setSourceEntity(123U);
    msg.setDestination(57235U);
    msg.setDestinationEntity(193U);
    msg.state = 75U;
    msg.plan_id.assign("ZPWTZUROCHZXRJLQZCONFYRZJAUELKAPHKAWMYGCHDTJSELBONGKUPRUFYLRY");
    msg.comm_level = 248U;

    try
    {
      Utils::ByteBuffer bfr;
      IMC::Packet::serialize(&msg, bfr);
      IMC::Message* msg_d = IMC::Packet::deserialize(bfr.getBuffer(), bfr.getSize());
      test.boolean("EmergencyControlState #2", msg == *msg_d);
      delete msg_d;
    }
    catch (IMC::InvalidMessageSize& e)
    {
      (void)e;
      test.boolean("msg #2", msg.getSerializationSize() > DUNE_IMC_CONST_MAX_SIZE);
    }
  }

  {
    IMC::PlanDB msg;
    msg.setTimeStamp(0.12557335463350794);
    msg.setSource(59398U);
    msg.setSourceEntity(98U);
    msg.setDestination(11089U);
    msg.setDestinationEntity(163U);
    msg.type = 207U;
    msg.op = 126U;
    msg.request_id = 39251U;
    msg.plan_id.assign("EWGOMYDGMXOBISQVQLFLPRIAFQZAPPMFNURKMYMSHISSUODLTQVREZRBTNAVTXRQYXMRUAZHXHWTAKLOOKTHCRZLVIXDKVFPLXKHZZCBGDHQENBULSVIJXCAQHBGCWZOYNBUCDYTIGTDKRPYMNSFDIAQFIPQWCMPVUN");
    IMC::IoEvent tmp_msg_0;
    tmp_msg_0.type = 65U;
    tmp_msg_0.error.assign("OSPDBYZPQOHRSQECTGQFOVNGLVDJEJTZCJPNBTLTRYYVAWKEKESZKUIKDGPJQXZFIYUQMYEKOBEULCGOXN");
    msg.arg.set(tmp_msg_0);
    msg.info.assign("MWBWEHKETDQJMYSZTOCYSWCSCMNKSIFQAWTQITNREDEJZPIDPAQQPBSOAOCDT");

    try
    {
      Utils::ByteBuffer bfr;
      IMC::Packet::serialize(&msg, bfr);
      IMC::Message* msg_d = IMC::Packet::deserialize(bfr.getBuffer(), bfr.getSize());
      test.boolean("PlanDB #0", msg == *msg_d);
      delete msg_d;
    }
    catch (IMC::InvalidMessageSize& e)
    {
      (void)e;
      test.boolean("msg #0", msg.getSerializationSize() > DUNE_IMC_CONST_MAX_SIZE);
    }
  }

  {
    IMC::PlanDB msg;
    msg.setTimeStamp(0.16491435659059417);
    msg.setSource(49684U);
    msg.setSourceEntity(66U);
    msg.setDestination(23978U);
    msg.setDestinationEntity(197U);
    msg.type = 87U;
    msg.op = 61U;
    msg.request_id = 17639U;
    msg.plan_id.assign("JXYLWXHCACZHERMNVQGBDQFYLPAJANSOMJDIPLOEASDUXYBUKQSXEPTAWODBHLZGNT");
    IMC::LblEstimate tmp_msg_0;
    IMC::LblBeacon tmp_tmp_msg_0_0;
    tmp_tmp_msg_0_0.beacon.assign("QJRHKZVNLLFUGJLRMRMRXSFYEOVXYWMQZCWN");
    tmp_tmp_msg_0_0.lat = 0.6702388603513654;
    tmp_tmp_msg_0_0.lon = 0.13149022616138173;
    tmp_tmp_msg_0_0.depth = 0.7722706740533365;
    tmp_tmp_msg_0_0.query_channel = 251U;
    tmp_tmp_msg_0_0.reply_channel = 187U;
    tmp_tmp_msg_0_0.transponder_delay = 227U;
    tmp_msg_0.beacon.set(tmp_tmp_msg_0_0);
    tmp_msg_0.x = 0.8371117430342615;
    tmp_msg_0.y = 0.34562547316709624;
    tmp_msg_0.var_x = 0.9514566255541811;
    tmp_msg_0.var_y = 0.43289451732423656;
    tmp_msg_0.distance = 0.9145097274749835;
    msg.arg.set(tmp_msg_0);
    msg.info.assign("HATJPNQOUYOJNKJSYBOYBLFTDXBSTWDJGKNUVGLKZNLDEBMTSRYVYHGDDS");

    try
    {
      Utils::ByteBuffer bfr;
      IMC::Packet::serialize(&msg, bfr);
      IMC::Message* msg_d = IMC::Packet::deserialize(bfr.getBuffer(), bfr.getSize());
      test.boolean("PlanDB #1", msg == *msg_d);
      delete msg_d;
    }
    catch (IMC::InvalidMessageSize& e)
    {
      (void)e;
      test.boolean("msg #1", msg.getSerializationSize() > DUNE_IMC_CONST_MAX_SIZE);
    }
  }

  {
    IMC::PlanDB msg;
    msg.setTimeStamp(0.9728859988563558);
    msg.setSource(26582U);
    msg.setSourceEntity(91U);
    msg.setDestination(15947U);
    msg.setDestinationEntity(205U);
    msg.type = 76U;
    msg.op = 35U;
    msg.request_id = 58094U;
    msg.plan_id.assign("IBNUSLISTROQNUZZZRRDBCTXKKAQEMNJBKPJMQJQDWWDPHUKDMZUPENXJQZTJAGCPDSAMGGYYBEMSCPKISOQFFCZRE");
    IMC::AutonomousSection tmp_msg_0;
    tmp_msg_0.lat = 0.31762666474514334;
    tmp_msg_0.lon = 0.1855193995446418;
    tmp_msg_0.speed = 0.9091150382054924;
    tmp_msg_0.speed_units = 133U;
    tmp_msg_0.limits = 103U;
    tmp_msg_0.max_depth = 0.6502220015182351;
    tmp_msg_0.min_alt = 0.2114491376041725;
    tmp_msg_0.time_limit = 0.2543418273909501;
    IMC::PolygonVertex tmp_tmp_msg_0_0;
    tmp_tmp_msg_0_0.lat = 0.4460167256248567;
    tmp_tmp_msg_0_0.lon = 0.0721337405642225;
    tmp_msg_0.area_limits.push_back(tmp_tmp_msg_0_0);
    tmp_msg_0.controller.assign("QLLCRBMUGQHQFZWSWLIKYPFYFIQBEXIQBDYIBTFVKSFXNPLVHXKUQORIVAUCJODKRKRMMAVXGBTPGMAFNDYEBNXRZOOGIGC");
    tmp_msg_0.custom.assign("TBYBMKKDWEIPIJGISORLKBHHWALBYVZQDLXWNPAOAUUBLEMXAZVGIVCPTRUGNLOMOHZTEZGUXSQWYDHRFOIAVSWBFUPMZJKNVQQEQPJOTC");
    msg.arg.set(tmp_msg_0);
    msg.info.assign("DZOTAXINPMHUBQUAOFEUUTVUCRJGNAIEIJADGDSFKSAJHAMGTCHZFBMWMJMVYQKMJXVLEHABRDFXTDXCOLNOVGWBMKGSGNRDLHSPCRPPOOILWGVLHRRERFHPYKNWPIQEQVAQJSBFBUKWEXZXWTJYZIDKYYJZKIXOSCILYMBZTVQSPUDMCAIPWCYWTTNRNSLXXFHFMWLCSRXQSVUZHBYIWGFBOTNOCUJKZELLOPKHYDGEPE");

    try
    {
      Utils::ByteBuffer bfr;
      IMC::Packet::serialize(&msg, bfr);
      IMC::Message* msg_d = IMC::Packet::deserialize(bfr.getBuffer(), bfr.getSize());
      test.boolean("PlanDB #2", msg == *msg_d);
      delete msg_d;
    }
    catch (IMC::InvalidMessageSize& e)
    {
      (void)e;
      test.boolean("msg #2", msg.getSerializationSize() > DUNE_IMC_CONST_MAX_SIZE);
    }
  }

  {
    IMC::PlanDBState msg;
    msg.setTimeStamp(0.9789924928915992);
    msg.setSource(32998U);
    msg.setSourceEntity(188U);
    msg.setDestination(57058U);
    msg.setDestinationEntity(83U);
    msg.plan_count = 63072U;
    msg.plan_size = 516422292U;
    msg.change_time = 0.09267301399478778;
    msg.change_sid = 36412U;
    msg.change_sname.assign("TASZGSGELYZGVXNFGMWLMDTXTVACKJQBAVCJCQRRSQITNZWFMKVKPRAFSJSBMDURLYTXKYCJGXIJWZUUPZMSPLSLRJTHTIBTNUHWVVCWPQPPQQNORLJNCSPXFAUKDRRBGFVSHILEIINDLYIRUYEBNBODGRKVXOPGJZOCUE");
    const signed char tmp_msg_0[] = {-34, 14, -111, -72, 103, 39, -20, 50, -81, 126, -114, 113, 82, -122, 77, 19, -49, -14, 51, 20, -40, -46, -5, -83, 83, -18, 60, 98, -17, -40, -108, -48, -121, -13, -14, -14, -82, 32, 95, -40, 72, -62, 74, -121, 30, -13, 84, 76, 41, -40, 13, 38, 74, 113, 106, -100, -56, 74, 64, -73, -70, 90, -69, 53, 85, -128, 116, -18, 57, 22, 69, -27, 107, 67, 119, -115, 71, -114, -84, 28, -45, -42, -49, -3, 10, -111, 89, -58, 92, 3, -21, -58, 117, -2, 61, 89, 51, -120, -105, 107, -106, 14, -30, -106, 71, -55, -38, -101, 87, 39, -75, 74, 81, -67, -6, -27, -116, -116, -85, 90};
    msg.md5.assign(tmp_msg_0, tmp_msg_0 + sizeof(tmp_msg_0));
    IMC::PlanDBInformation tmp_msg_1;
    tmp_msg_1.plan_id.assign("ALHGCJYLOKAXMTRHERCSUNKYLWTGRPMVTOZJYDQIETWCNTIRBELHBVUHYQDYVCOLGWZGFVGIPYQXSJSBAXJJVPAZZXPBAYEXPVVHQINCGNRGYDNMWTRNAWNMIUSSFCUPROKADDZHFTSLFQJBOAEWZJEIUXMEN");
    tmp_msg_1.plan_size = 53858U;
    tmp_msg_1.change_time = 0.5674351946252703;
    tmp_msg_1.change_sid = 35966U;
    tmp_msg_1.change_sname.assign("JZDWULSYZWVPKMYORAROSAZTQIOILDUPXYSMYJFGJQCJMJCRXUACPGXNODZZZDFAAVHHWWNUWGQOKIOACALPCKGCEQESPGIKRGYLNZWGMLXVOLUUBPJFVZJMJGNTOYRKEPCRPXDVIDQGZEAKBKHRKTNDECIFSEVYLMSQMBEFDRNVOBBPMUNEHHWJCVTEOTHFHMIHFWVDSYTXBUWXQFYBYIECIBULKABTNQGJRAZRLNXXBDUIHSWTHNTSXTFKL");
    const signed char tmp_tmp_msg_1_0[] = {123, 78, 118, -11, -101, -112, 39, -33, -25, -91, 26, 18, 116, 117, -90, -71, -108, -23, -80, -53, 72, -105, -43, 115, -100, -97, -36, 70, 5, -18, 11, -48, 40, -96, -38, 36, 101, -35, -48, -71, 4, -49, -69, -51, -110, -111, -78, 115, -91, -102, 56, -59, 17, 74, 45, 51, 50, -94, -40, 10, -32, 35};
    tmp_msg_1.md5.assign(tmp_tmp_msg_1_0, tmp_tmp_msg_1_0 + sizeof(tmp_tmp_msg_1_0));
    msg.plans_info.push_back(tmp_msg_1);

    try
    {
      Utils::ByteBuffer bfr;
      IMC::Packet::serialize(&msg, bfr);
      IMC::Message* msg_d = IMC::Packet::deserialize(bfr.getBuffer(), bfr.getSize());
      test.boolean("PlanDBState #0", msg == *msg_d);
      delete msg_d;
    }
    catch (IMC::InvalidMessageSize& e)
    {
      (void)e;
      test.boolean("msg #0", msg.getSerializationSize() > DUNE_IMC_CONST_MAX_SIZE);
    }
  }

  {
    IMC::PlanDBState msg;
    msg.setTimeStamp(0.8723666216140329);
    msg.setSource(9313U);
    msg.setSourceEntity(243U);
    msg.setDestination(52768U);
    msg.setDestinationEntity(9U);
    msg.plan_count = 37763U;
    msg.plan_size = 1119341767U;
    msg.change_time = 0.5192290986074667;
    msg.change_sid = 12641U;
    msg.change_sname.assign("KLDFJUKNRZGUNEGOSTRSVNXJYQJKMOFCTXMKUWAEFELQHFMPSJLUCKDXQBQCZTJHMUMTVPOWWTNSAKBFISJHFYJJVQIXYCZVHYRQYXOIOGYWHESUQADVLLMGJAWWHLOENTSEGZADHNBVGNIRWDGBGPHSDWBWYIBMRURMNPRZFEAXDNH");
    const signed char tmp_msg_0[] = {-12, 94, -42, -94, -39, 13, 0, 53, 104, -23, 88, -69, 110, 104, -112, -125, 120, 96, 89, -122, 32, 47, 15, 56, 112, -2, -2, -117, -25, 2, -48, 105, 75, 6, -35, 82, -4, 66, -122, 48, -69, 119, -79, -100, -33, -126, 113, -93, 70, -46, -6, -53, 90, 5, -97, 33, 71, -94, -118, 44, 50, 106, 68, -18, 121, -121, -55, -101, 50, -34, 37, 75, 57, -72, 41, -80, -47, 70, 38, 17, 54, 80, -48, -82, -39, 79, 103, 106, -38, -57, -27, -11, -124, 114, -125, 65, 111, -51, -48, -100, 81, 51, 5, 32, -53, 96, 82, -115, -63, 89, -72, -69, 2, -55, 49, 99, -123, 78, -107, -119, -81, -118, -76, -103, 116, -12, 103, -116, -101, 2, 48, -2, 61, -120, -42, -106, 63, -11, 36, -37, -5, -42, -80, -5, -104, -100, 115, -6, 41, 80, -68, -70, 104, 125, 23, 91, -73, 95, -85, -85, 100, 101, 13, 98, 121, -122, -55, 71, 10, -42, -115, 70, -101, 68, 80, -21, 42, -120, -4, 14, -86, 36, -21, -3, 82, 103, 78, -72, -6, -73, 7, 17, -26, -127, -5, 40, 68, -8, -104, 8, 42, 88, 45, 85, 22, -72, 56, 87, 71, 34, 8, -61, 1, -20, -38, 14, -63, 51, -69, -39, -113, -86, 40, 16, -78, 101, 105, -34, -51, -88, 79, -10, -83, -124, 48, 67};
    msg.md5.assign(tmp_msg_0, tmp_msg_0 + sizeof(tmp_msg_0));
    IMC::PlanDBInformation tmp_msg_1;
    tmp_msg_1.plan_id.assign("DBEVSWBDFBKIQJNMAJFWESGCYOKWZCHQLILRPCZRDNMWEXQWUSXVSPDJNEURJWOUTMDCIYRPXVBNCHIWI");
    tmp_msg_1.plan_size = 6769U;
    tmp_msg_1.change_time = 0.364153361072558;
    tmp_msg_1.change_sid = 64457U;
    tmp_msg_1.change_sname.assign("IIBAQHXKSJMQCWXWRJZOZMZQPJ");
    const signed char tmp_tmp_msg_1_0[] = {40, 60, -60, 20, -21, -38, 2, 18, -100, 20, 117, 3, -128, 31, 27, 69, -29, -6, -28, -113, -98, 95, -63, -55, 120, -30, 106, 45, -14, -40, -101, 94, 9, -49, -26, 99, 38, 6, -13, 72, -105, -122, -54, -60, -56, -117, -64, 119, 86, 72, 16, 46};
    tmp_msg_1.md5.assign(tmp_tmp_msg_1_0, tmp_tmp_msg_1_0 + sizeof(tmp_tmp_msg_1_0));
    msg.plans_info.push_back(tmp_msg_1);

    try
    {
      Utils::ByteBuffer bfr;
      IMC::Packet::serialize(&msg, bfr);
      IMC::Message* msg_d = IMC::Packet::deserialize(bfr.getBuffer(), bfr.getSize());
      test.boolean("PlanDBState #1", msg == *msg_d);
      delete msg_d;
    }
    catch (IMC::InvalidMessageSize& e)
    {
      (void)e;
      test.boolean("msg #1", msg.getSerializationSize() > DUNE_IMC_CONST_MAX_SIZE);
    }
  }

  {
    IMC::PlanDBState msg;
    msg.setTimeStamp(0.1219621062415367);
    msg.setSource(41005U);
    msg.setSourceEntity(194U);
    msg.setDestination(43490U);
    msg.setDestinationEntity(127U);
    msg.plan_count = 19474U;
    msg.plan_size = 2880523218U;
    msg.change_time = 0.8037142330543352;
    msg.change_sid = 63346U;
    msg.change_sname.assign("HSLWWMKNTLTBKRYWCECFSCUZGONTENFJNBGTIEXJJZOOBQIHSWYCHXVFZRIFUWLQYFIQNPE");
    const signed char tmp_msg_0[] = {61, -71, -79, -74, 100, -104, 78, 100, -31, 50, 51, -64, -64, -122, 117, -17, 77, 120, 26, 29, 87, 70, 74, -56, 35, 107, 49, 86, -69, -126, 87, 52, -111, -115, 116, -126, -44, -92, 66, -110, 101, -122, 86, -17, -42, -74, 28, -16, 57, 56, 92, -97, 124, -52, -113, 125, -96, 15, 105, 118, -120, 69, -32, 59, 32};
    msg.md5.assign(tmp_msg_0, tmp_msg_0 + sizeof(tmp_msg_0));
    IMC::PlanDBInformation tmp_msg_1;
    tmp_msg_1.plan_id.assign("CKYGAKBRINOQWHKW");
    tmp_msg_1.plan_size = 2807U;
    tmp_msg_1.change_time = 0.922212694601798;
    tmp_msg_1.change_sid = 46235U;
    tmp_msg_1.change_sname.assign("KZUGCCYQPBLVZQLKTSYHSLPJHHAJWNYYEJSSAIDEIAFXLMJLWGBRILQPAKWPNQRNUQKVKDKURNNZOXEUBYGOAFYCEYOFUABXBKVZNJBCBBXYGTLWRZHWVVGCEMDRNQXSQQOIUFRLDJSOCRTFQPQMPRJDHTAANVPITFWMFSWXGO");
    const signed char tmp_tmp_msg_1_0[] = {74, 43, -58, 29, 38, 89, 47, 67, 8, 117, 69, -104, 32, -27, -71, 52, 56, 47, -99, -52, 101, 49, -65, -28, -28, -24, -56, -60, -114, -75, 25, -70, 117, -23, -99, -117, 39, 30, -28, 92, -10, -63, -18, 92, -89, -7, 39, -46, -1, 72, -62, 30, -66, -56, 52, -32, -102, 79, 18, 119, -41, -46, -111, -99, -57, -44, -2, 110, 106, -1, -47, -36, 45, 0, 46, -74, 116, 77, 2, 63, -100, 33, 49, 100, 103, -127, 87, 39, 68, 97, 8, 34, -92, -73, 19, -57, -65, -5, 53, -63, -82, -66, -95, 39, 111, -28, -58, -11, 25, 47, 117, 28, 111, -40, -52, 64, 35, -26, 19, 48, -27, -54, -52, 34, -65, 109, 52, 76, 37, 41, -83, 0, 45, -64, 30, -73, -28, -45, -52, -16, 39, -89, 34, -16, -101, -18};
    tmp_msg_1.md5.assign(tmp_tmp_msg_1_0, tmp_tmp_msg_1_0 + sizeof(tmp_tmp_msg_1_0));
    msg.plans_info.push_back(tmp_msg_1);

    try
    {
      Utils::ByteBuffer bfr;
      IMC::Packet::serialize(&msg, bfr);
      IMC::Message* msg_d = IMC::Packet::deserialize(bfr.getBuffer(), bfr.getSize());
      test.boolean("PlanDBState #2", msg == *msg_d);
      delete msg_d;
    }
    catch (IMC::InvalidMessageSize& e)
    {
      (void)e;
      test.boolean("msg #2", msg.getSerializationSize() > DUNE_IMC_CONST_MAX_SIZE);
    }
  }

  {
    IMC::PlanDBInformation msg;
    msg.setTimeStamp(0.4320231562756124);
    msg.setSource(14906U);
    msg.setSourceEntity(168U);
    msg.setDestination(20913U);
    msg.setDestinationEntity(127U);
    msg.plan_id.assign("HWNFXBLXMDBVFSTREVFWBOOKQXZFFPEJKTADDFMXBNYRDGKJMSHAVDLNAPUESEPQBIJHKBCNQYORIPNUWQVMUWYZZXCBVTINHTCZJJYGMHAIEPPTXBXGRCZQKUOTHSOEWVACAHQWDYPVKWQYRZINQAKINGLCCY");
    msg.plan_size = 43399U;
    msg.change_time = 0.09079322342366303;
    msg.change_sid = 50224U;
    msg.change_sname.assign("FKTYOOBTBULSOSIMJTMAUEYNPLXAEENGLYPXFABHUWBZDWTHIJKCRGZXNGCYAAICAHPPOCTFDRWOQWKQJQSDSWKILHQYMQNOJQKOUJCNFXRZUFRGGXPMHRRDRGTIMKKEYTPFETJCXFXLNQCFVFVNEUJQ");
    const signed char tmp_msg_0[] = {-34, -116, -110, -90, 32, -108, -56, -40, 25, -16, 15, -61, -37, 17, -36, -4, -44, 103, -89, -56, -10, 94, 30, 65, -74, 76, 109, -82, 106, 28, 119, 4, -43, -3, -20, -91, -82, -55, 38, -21, 36, 80, -57, 99, 126, -98, 115, -63, 63, -45, 24, -109, -112, -106, -49, -5, -92, -3, 56, -23, -35, -125, 123, 74, 20, -50, 60, 88, -55, -70, 67, -8, -58};
    msg.md5.assign(tmp_msg_0, tmp_msg_0 + sizeof(tmp_msg_0));

    try
    {
      Utils::ByteBuffer bfr;
      IMC::Packet::serialize(&msg, bfr);
      IMC::Message* msg_d = IMC::Packet::deserialize(bfr.getBuffer(), bfr.getSize());
      test.boolean("PlanDBInformation #0", msg == *msg_d);
      delete msg_d;
    }
    catch (IMC::InvalidMessageSize& e)
    {
      (void)e;
      test.boolean("msg #0", msg.getSerializationSize() > DUNE_IMC_CONST_MAX_SIZE);
    }
  }

  {
    IMC::PlanDBInformation msg;
    msg.setTimeStamp(0.4578951897390964);
    msg.setSource(34742U);
    msg.setSourceEntity(113U);
    msg.setDestination(39988U);
    msg.setDestinationEntity(157U);
    msg.plan_id.assign("YUFMQAROEJBKHMALIWEISITTOUDAUQTOLRTIJJEBWQXEALBSPPTEYWMGHKPBFZSDMHYNXOIDMVNWTJMHSYDHCYGDXSLJLZGTCPRVKFAXNWORFUIFAGXPOSUEFULWWZUNRUHTUTQHLBZEDBQYSSPZACGNAAYLCG");
    msg.plan_size = 3341U;
    msg.change_time = 0.8431365209732885;
    msg.change_sid = 60896U;
    msg.change_sname.assign("IWWBYBSRNIMWFAGDCXOTOEMILKFCFRPANMYLXTANLGZLCOWOEPTYDRSNDQYJRROFKRPQSBUOVAQYEFAZVSCGFRXLKVQSWZRVVXTHLOQIHBDDAQGVNUYAUTKHJIZEMJWNLBJRYZBKIGJUQAUXCXDFKNAQJHNWOZZKPDGLECIZNEYBBSWQJKHISVKXTUTMCTOUIMLQTRD");
    const signed char tmp_msg_0[] = {88, 59, 118, -38, 91, -124, 53, 66, -47, 69, -37, -119, -11, 34, 83, -105, -36, -10, -90, 76, -51, -106, 4, 71, 66, -50, 119, 42, -81, -23, 52, 37, -24, 5, -50, 102, 32, 40, 67, 103, -16, 11, -18, -58, 105, 71, 14, 23, 58, 33, -70, -72, 4, 68, -128, -33, 114, -38, 45, -19, -107, -99, 51, -115, 2, -62, 6, -126, 126, 101, 24, -114, 88, -125, 16, 125, 43, -25, 68, -121, 53, 3, 60, -18, -2, 97, -103, 6, 66, -44, 74, -53, 49, -51, -34, -83, -89, -86, 10, 49, 83, -93, 66, 68, -7, 89, 3, 56, -94, 37, 4, 95, 17, 53, 75, 39, -33, -75, -117, 85, 66, 38, 3, 65, 52, -52, -61, -8, -46, -69, -12, -99, -69, -113, 76, -110, 90, -77, -63, 67, 91, 88, -39, 59, -18, 89, 111, -13, -75, -49, 109, 110, -3, 112, -15, -40};
    msg.md5.assign(tmp_msg_0, tmp_msg_0 + sizeof(tmp_msg_0));

    try
    {
      Utils::ByteBuffer bfr;
      IMC::Packet::serialize(&msg, bfr);
      IMC::Message* msg_d = IMC::Packet::deserialize(bfr.getBuffer(), bfr.getSize());
      test.boolean("PlanDBInformation #1", msg == *msg_d);
      delete msg_d;
    }
    catch (IMC::InvalidMessageSize& e)
    {
      (void)e;
      test.boolean("msg #1", msg.getSerializationSize() > DUNE_IMC_CONST_MAX_SIZE);
    }
  }

  {
    IMC::PlanDBInformation msg;
    msg.setTimeStamp(0.3607921921724657);
    msg.setSource(30766U);
    msg.setSourceEntity(230U);
    msg.setDestination(8719U);
    msg.setDestinationEntity(144U);
    msg.plan_id.assign("XZEFDADPLQUURICGSVTATKOKNCZLETRAYBDRDFBRABSKUVSTPCIPAKCIVINMKKLCJLQMCWXQWMPUUYJTBRGMAOFDYBDEKKHLYMKEXUSEHEBAVNUXQBUAEPHMQMGZTBNNWCAZFYVJGSSHGDHNYXXJWGIIZOGFIPHPDYXQFYJGUCLNSSVBJQJREHJ");
    msg.plan_size = 41153U;
    msg.change_time = 0.8781935153010351;
    msg.change_sid = 34823U;
    msg.change_sname.assign("AHKRZXBSXTGCQWFXKYBTUZFLGBZPYNKAGUOCYYTGIXEINHAPZEKERBHVMUDROKFPJQEABJMWBDCEGIJQAQUFFOCFDBLSJTJIEVWYALVGXNIVWVAQXOHZ");
    const signed char tmp_msg_0[] = {-96, 18, -20, -9, 47, -109, -25, -114, -51, 11, -119, 105, 102};
    msg.md5.assign(tmp_msg_0, tmp_msg_0 + sizeof(tmp_msg_0));

    try
    {
      Utils::ByteBuffer bfr;
      IMC::Packet::serialize(&msg, bfr);
      IMC::Message* msg_d = IMC::Packet::deserialize(bfr.getBuffer(), bfr.getSize());
      test.boolean("PlanDBInformation #2", msg == *msg_d);
      delete msg_d;
    }
    catch (IMC::InvalidMessageSize& e)
    {
      (void)e;
      test.boolean("msg #2", msg.getSerializationSize() > DUNE_IMC_CONST_MAX_SIZE);
    }
  }

  {
    IMC::PlanControl msg;
    msg.setTimeStamp(0.1374433473165224);
    msg.setSource(26365U);
    msg.setSourceEntity(150U);
    msg.setDestination(49166U);
    msg.setDestinationEntity(176U);
    msg.type = 139U;
    msg.op = 199U;
    msg.request_id = 10671U;
    msg.plan_id.assign("QLMSIOOYXVBALLNBPMBXOMGIRTSVBGKIUUDEZGYMDBJDFWFUAIKSCOVEHIZAWZRCBJHZKPNSPYIHERCESUAPIOBOWRDKSRYLAUWTXJZYAJDSCRGDJDXCQAZBQQJQNEYZTWUGDTNTELCHGKEFWXQPNPRLOJNHLPKTNBYHWPDKTRVVAWCKQGOVVOTIVOUZVJHLFFYXMAGEKLMHNYYNMWXRKCFTHZ");
    msg.flags = 44896U;
    IMC::SetControlSurfaceDeflection tmp_msg_0;
    tmp_msg_0.id = 171U;
    tmp_msg_0.angle = 0.5054020373116286;
    msg.arg.set(tmp_msg_0);
    msg.info.assign("IBUQVGPGASWPUDZQYXP");

    try
    {
      Utils::ByteBuffer bfr;
      IMC::Packet::serialize(&msg, bfr);
      IMC::Message* msg_d = IMC::Packet::deserialize(bfr.getBuffer(), bfr.getSize());
      test.boolean("PlanControl #0", msg == *msg_d);
      delete msg_d;
    }
    catch (IMC::InvalidMessageSize& e)
    {
      (void)e;
      test.boolean("msg #0", msg.getSerializationSize() > DUNE_IMC_CONST_MAX_SIZE);
    }
  }

  {
    IMC::PlanControl msg;
    msg.setTimeStamp(0.25587319133986797);
    msg.setSource(40297U);
    msg.setSourceEntity(214U);
    msg.setDestination(25871U);
    msg.setDestinationEntity(35U);
    msg.type = 133U;
    msg.op = 166U;
    msg.request_id = 58276U;
    msg.plan_id.assign("PEXYGPZVRQZQHVUFCNFGGDMYNVTHOJPQHGJSNQDSXYWFQBELLGEZ");
    msg.flags = 40922U;
    IMC::CameraZoom tmp_msg_0;
    tmp_msg_0.id = 3U;
    tmp_msg_0.zoom = 224U;
    tmp_msg_0.action = 71U;
    msg.arg.set(tmp_msg_0);
    msg.info.assign("PNRTPLEEXHIFQMZRLCJVNM");

    try
    {
      Utils::ByteBuffer bfr;
      IMC::Packet::serialize(&msg, bfr);
      IMC::Message* msg_d = IMC::Packet::deserialize(bfr.getBuffer(), bfr.getSize());
      test.boolean("PlanControl #1", msg == *msg_d);
      delete msg_d;
    }
    catch (IMC::InvalidMessageSize& e)
    {
      (void)e;
      test.boolean("msg #1", msg.getSerializationSize() > DUNE_IMC_CONST_MAX_SIZE);
    }
  }

  {
    IMC::PlanControl msg;
    msg.setTimeStamp(0.7788117643536797);
    msg.setSource(55365U);
    msg.setSourceEntity(98U);
    msg.setDestination(48813U);
    msg.setDestinationEntity(66U);
    msg.type = 96U;
    msg.op = 170U;
    msg.request_id = 15468U;
    msg.plan_id.assign("MYJDSJJPDCGHJNMCLFMCMOAXVIVIYUIZBISWKSZVOGTBLARRDRQBLPDWLBPGXXUDRHXIOOTEODCYKEUIVRHHAATFLTZLKXPMQZYGTNH");
    msg.flags = 29702U;
    IMC::PlanTransition tmp_msg_0;
    tmp_msg_0.source_man.assign("GGJPZEOSSUHCWMQQQLKFPKVAQIAJZINLVVYSBGTMDFXVUXOQRQAQDTKKAJCDVLQEZBJPKTHLPICGRORWIJNVFAIVWDWFMXXBQNMZJETGXMOBOPHNHDYORHACNWFJYFWHHRLUCSBHDSZJTBSUCOIGSPXMVPDCCLHVSFKYULRFQIWAABTBWNSLONEYDHKEM");
    tmp_msg_0.dest_man.assign("MFKJATMVTDAGTMXCRVJUSHNTHGABBEEYWIAFLYLENWTRDAIKMHHEYIWFFNKLMHIYDPTVDFSIPYPYDDCFBQCLXGGBNRQTZDJEGIWWHOZZXUZDRLAUVMBWBOOVKCWSPVARSZBQXOZSOLXBRSZHPQAIRXVRENQBRKOGYWXAGNOQP");
    tmp_msg_0.conditions.assign("VDLEDYTTONNDDSPUKSXIOUIAFGEQYEBAABHYLOSRZPQZYZVMEJGJMMUYESSEVUHZBKZVMFMQNMLJFHKOJYTELRWYBHFWOWPKNFYCJGVBBIGAPIKFXXJZXZTMNUZTDNMMPSSKGR");
    IMC::CacheControl tmp_tmp_msg_0_0;
    tmp_tmp_msg_0_0.op = 191U;
    tmp_tmp_msg_0_0.snapshot.assign("OQUEPLDWAMRYPJPSVTIGZPRZUOFKBZB");
    IMC::MagneticField tmp_tmp_tmp_msg_0_0_0;
    tmp_tmp_tmp_msg_0_0_0.time = 0.8190572783797684;
    tmp_tmp_tmp_msg_0_0_0.x = 0.09958551631103063;
    tmp_tmp_tmp_msg_0_0_0.y = 0.21093345471494462;
    tmp_tmp_tmp_msg_0_0_0.z = 0.8232393108056144;
    tmp_tmp_msg_0_0.message.set(tmp_tmp_tmp_msg_0_0_0);
    tmp_msg_0.actions.push_back(tmp_tmp_msg_0_0);
    msg.arg.set(tmp_msg_0);
    msg.info.assign("UMYHYXBYPCTQQASSFJNRKCQKUACCBOZVEDDZPRIUJEWAQCLKGTJGWPMHJATNMCHHZIPGXJGOVBVADHKFIPWERTVISLGWUBJKSEZKSDVUVPNRFWINCDRNAXXGMPCKRBZHKPRFIXPZQGZSOLYHAIQWGCANDSXEOWYVOWLWDIVLUHFMTQFGJUVTAMMXJITUBYOXDWRUHFR");

    try
    {
      Utils::ByteBuffer bfr;
      IMC::Packet::serialize(&msg, bfr);
      IMC::Message* msg_d = IMC::Packet::deserialize(bfr.getBuffer(), bfr.getSize());
      test.boolean("PlanControl #2", msg == *msg_d);
      delete msg_d;
    }
    catch (IMC::InvalidMessageSize& e)
    {
      (void)e;
      test.boolean("msg #2", msg.getSerializationSize() > DUNE_IMC_CONST_MAX_SIZE);
    }
  }

  {
    IMC::PlanControlState msg;
    msg.setTimeStamp(0.8791081856755603);
    msg.setSource(61713U);
    msg.setSourceEntity(151U);
    msg.setDestination(32206U);
    msg.setDestinationEntity(99U);
    msg.state = 181U;
    msg.plan_id.assign("HPSBJVYGLMWVDXRC");
    msg.plan_eta = -1304275361;
    msg.plan_progress = 0.9594182788216746;
    msg.man_id.assign("BIIXQNOISANOLVAUFJAYWMKXHONMPMEEUVDCVGPGHMBSRQFWRAJVALUAVQXEBWNRTJRZKYKKPTTDNTPRXOEAETZEGFOGOPHSEKLJJIVCZCUGRMSFWDZVSYBQDAZOWCOILFWLVCNVHRBEDZXCWQEPH");
    msg.man_type = 22091U;
    msg.man_eta = 1182562210;
    msg.last_outcome = 7U;

    try
    {
      Utils::ByteBuffer bfr;
      IMC::Packet::serialize(&msg, bfr);
      IMC::Message* msg_d = IMC::Packet::deserialize(bfr.getBuffer(), bfr.getSize());
      test.boolean("PlanControlState #0", msg == *msg_d);
      delete msg_d;
    }
    catch (IMC::InvalidMessageSize& e)
    {
      (void)e;
      test.boolean("msg #0", msg.getSerializationSize() > DUNE_IMC_CONST_MAX_SIZE);
    }
  }

  {
    IMC::PlanControlState msg;
    msg.setTimeStamp(0.7684050702687656);
    msg.setSource(45668U);
    msg.setSourceEntity(212U);
    msg.setDestination(30051U);
    msg.setDestinationEntity(148U);
    msg.state = 21U;
    msg.plan_id.assign("VHMDPNUIXUOBZAVGTPTWNOFDRINRZJTSHRLSQBVXAFEPIEVMGQLGEUQURCNJWYXNZFDLECKVRERFBPVMUXSSCIADZZUWSCKDSJOSJFADPQOYZHKGKOFXIBYHMXPLYPQCKDINPPXKZIRPJZSAAMDLYFLHBWQJLRYBAQUTEFEJUJBONYLGGSXXBSIYNRBGCAHMWOYDHENXK");
    msg.plan_eta = 332710183;
    msg.plan_progress = 0.8440138499349841;
    msg.man_id.assign("IQTWMPIKRWEJJCAUCGBVVYGHDXBSGXCCOFLRERJTPVSMLSBKXUWDMXXGNDRWDAKSTKARPZFAGGLKICBYNYBAQIITLNOSAEEEKUFFSHJIMKPRPXHRRE");
    msg.man_type = 46951U;
    msg.man_eta = -1182916725;
    msg.last_outcome = 47U;

    try
    {
      Utils::ByteBuffer bfr;
      IMC::Packet::serialize(&msg, bfr);
      IMC::Message* msg_d = IMC::Packet::deserialize(bfr.getBuffer(), bfr.getSize());
      test.boolean("PlanControlState #1", msg == *msg_d);
      delete msg_d;
    }
    catch (IMC::InvalidMessageSize& e)
    {
      (void)e;
      test.boolean("msg #1", msg.getSerializationSize() > DUNE_IMC_CONST_MAX_SIZE);
    }
  }

  {
    IMC::PlanControlState msg;
    msg.setTimeStamp(0.24604652559186446);
    msg.setSource(32646U);
    msg.setSourceEntity(35U);
    msg.setDestination(2147U);
    msg.setDestinationEntity(95U);
    msg.state = 204U;
    msg.plan_id.assign("HRDPQFNWBHEZRKIVNQJYZRSKHNXWCHDTBBLTTLIYBJZNCARFQVWPGDOKURMEXDC");
    msg.plan_eta = 1635733112;
    msg.plan_progress = 0.41030773304918144;
    msg.man_id.assign("FDFPRECZAOUSNBAZUVAPZPLBTNYPDETRYZFTUHTHWSCLOQBGVIKQSSLLICCGJWYNXZSLEAFYGNPKPNUQHXVTBAOKFMTVRDYDRVEDAMTSXWDIEJUA");
    msg.man_type = 3308U;
    msg.man_eta = -1251461241;
    msg.last_outcome = 25U;

    try
    {
      Utils::ByteBuffer bfr;
      IMC::Packet::serialize(&msg, bfr);
      IMC::Message* msg_d = IMC::Packet::deserialize(bfr.getBuffer(), bfr.getSize());
      test.boolean("PlanControlState #2", msg == *msg_d);
      delete msg_d;
    }
    catch (IMC::InvalidMessageSize& e)
    {
      (void)e;
      test.boolean("msg #2", msg.getSerializationSize() > DUNE_IMC_CONST_MAX_SIZE);
    }
  }

  {
    IMC::PlanVariable msg;
    msg.setTimeStamp(0.16346889674196563);
    msg.setSource(62579U);
    msg.setSourceEntity(213U);
    msg.setDestination(1955U);
    msg.setDestinationEntity(80U);
    msg.name.assign("VHYIHUVBAKDRXKVYWINPWBGEPITLBMHBWHELMBXUXLRHRBSSUSXCJTOZYZRZWMJKDZKYENAVDTIRFDEPQDDFTLCRFBSJTOLWTNVGCWFFDENVGOGOFKQNXIILKZJDQQCXBQMYPUCIOMQZSOETNAANPLBZRULVSFEWHMVAJCMXMZMJXFEGFPAKFZYWCINGHYKQGNGHRTCVROJSVAA");
    msg.value.assign("FHPHUONKKBZWNRITMTBKINBQHEXQ");
    msg.type = 36U;
    msg.access = 57U;

    try
    {
      Utils::ByteBuffer bfr;
      IMC::Packet::serialize(&msg, bfr);
      IMC::Message* msg_d = IMC::Packet::deserialize(bfr.getBuffer(), bfr.getSize());
      test.boolean("PlanVariable #0", msg == *msg_d);
      delete msg_d;
    }
    catch (IMC::InvalidMessageSize& e)
    {
      (void)e;
      test.boolean("msg #0", msg.getSerializationSize() > DUNE_IMC_CONST_MAX_SIZE);
    }
  }

  {
    IMC::PlanVariable msg;
    msg.setTimeStamp(0.529098143765798);
    msg.setSource(56133U);
    msg.setSourceEntity(68U);
    msg.setDestination(894U);
    msg.setDestinationEntity(75U);
    msg.name.assign("CCQTDCTQSPKWBXXWYZRDMRAWEFSIBOPLXRRTBVUNYJNLZXDAOXCFQZJNPLSGSWQFGTMZWLEDHAGHQKYICVELUQIHZIDPBMCAHBESOYANCKOESMIPVCGOEQQUN");
    msg.value.assign("EJQMXUXMTASCOMYVNPRPEKONTPYDWAQVFEVAUKMKQRYJAGPZJBHKVTNFJFBWJDLONDIBKCHPHTK");
    msg.type = 115U;
    msg.access = 87U;

    try
    {
      Utils::ByteBuffer bfr;
      IMC::Packet::serialize(&msg, bfr);
      IMC::Message* msg_d = IMC::Packet::deserialize(bfr.getBuffer(), bfr.getSize());
      test.boolean("PlanVariable #1", msg == *msg_d);
      delete msg_d;
    }
    catch (IMC::InvalidMessageSize& e)
    {
      (void)e;
      test.boolean("msg #1", msg.getSerializationSize() > DUNE_IMC_CONST_MAX_SIZE);
    }
  }

  {
    IMC::PlanVariable msg;
    msg.setTimeStamp(0.8670402259297729);
    msg.setSource(54485U);
    msg.setSourceEntity(25U);
    msg.setDestination(10040U);
    msg.setDestinationEntity(226U);
    msg.name.assign("MYHAODBTYWREGKLYUMQFNSQATPNJPEQZSJDIVMFWMHPFNEVFYQIUQCBQDRUUGYCJFBXTMKFIQPTYRGPEWRPXQCVETGXVJFNGCYXJDVVAAMLAYALZOSICRTNKVEBSPUMTOKHTLEUPGOMMFBUJCNZNUOQDDSTGIWKIAXRWQRBWEKSBCEVJZRYHLDLWIDFUAEWAZXZHOOHDJZJJCKHOXPXLCTBGGRCOBHZZONLKISAFHRWULDWK");
    msg.value.assign("OJIJEDNXZTZUCTYHLVROCMDVSWRZNPRQZVFOAEMHAUGIVWBUUAKBSKXYOYTYDVGPDYCHVPBKYACITYKINPWWSSDJKTMLDUFQGPQHGOOLXYJPWOJVPFUNARFHTEEKJMIZWOBCGOKCLIQAVRCCBKRNQNRPUSWISFCGUKQQDXPOGNNEHDFTLMBALIMMJJHTEUXVESFEWSJSKSHXZZ");
    msg.type = 32U;
    msg.access = 173U;

    try
    {
      Utils::ByteBuffer bfr;
      IMC::Packet::serialize(&msg, bfr);
      IMC::Message* msg_d = IMC::Packet::deserialize(bfr.getBuffer(), bfr.getSize());
      test.boolean("PlanVariable #2", msg == *msg_d);
      delete msg_d;
    }
    catch (IMC::InvalidMessageSize& e)
    {
      (void)e;
      test.boolean("msg #2", msg.getSerializationSize() > DUNE_IMC_CONST_MAX_SIZE);
    }
  }

  {
    IMC::PlanGeneration msg;
    msg.setTimeStamp(0.7122924082147327);
    msg.setSource(5287U);
    msg.setSourceEntity(116U);
    msg.setDestination(20340U);
    msg.setDestinationEntity(205U);
    msg.cmd = 181U;
    msg.op = 229U;
    msg.plan_id.assign("BQPUQJZPPLRWAWFNXEVCSNZCDHSGERKFWBCDBMOZHOYLYKZIZWGHXBUKT");
    msg.params.assign("VEMHURYJFBPLEIZGTELHMHSMCVDJ");

    try
    {
      Utils::ByteBuffer bfr;
      IMC::Packet::serialize(&msg, bfr);
      IMC::Message* msg_d = IMC::Packet::deserialize(bfr.getBuffer(), bfr.getSize());
      test.boolean("PlanGeneration #0", msg == *msg_d);
      delete msg_d;
    }
    catch (IMC::InvalidMessageSize& e)
    {
      (void)e;
      test.boolean("msg #0", msg.getSerializationSize() > DUNE_IMC_CONST_MAX_SIZE);
    }
  }

  {
    IMC::PlanGeneration msg;
    msg.setTimeStamp(0.45546219420887557);
    msg.setSource(63547U);
    msg.setSourceEntity(121U);
    msg.setDestination(54299U);
    msg.setDestinationEntity(87U);
    msg.cmd = 206U;
    msg.op = 183U;
    msg.plan_id.assign("YPXEULFHEKKCOESWPNBSGICRQTIFKCOPJIPVTHTFZSBBASWNUYXEGLQZMDFYYWXRBOEFPOGVTWADGQTTFPSLGNWSTEDLBAUXXUZPIQJEMERNPAIAVVNVSNBGRHKWGYSCYBDRHCEMFYHCJNOMSMDKYCHUWBIAZGZXGMZJOSDNDHERDM");
    msg.params.assign("YJRSJFLOUGILYDRPSSTCZYWTSQDUNNEBRCWNBOXZMFRHMIFOCUTEOYZCKVFAJMQDEUKOENNX");

    try
    {
      Utils::ByteBuffer bfr;
      IMC::Packet::serialize(&msg, bfr);
      IMC::Message* msg_d = IMC::Packet::deserialize(bfr.getBuffer(), bfr.getSize());
      test.boolean("PlanGeneration #1", msg == *msg_d);
      delete msg_d;
    }
    catch (IMC::InvalidMessageSize& e)
    {
      (void)e;
      test.boolean("msg #1", msg.getSerializationSize() > DUNE_IMC_CONST_MAX_SIZE);
    }
  }

  {
    IMC::PlanGeneration msg;
    msg.setTimeStamp(0.5002567888490995);
    msg.setSource(17576U);
    msg.setSourceEntity(175U);
    msg.setDestination(17251U);
    msg.setDestinationEntity(100U);
    msg.cmd = 112U;
    msg.op = 174U;
    msg.plan_id.assign("MVQEUOJOULFFRJKMSYOIDMZBAFDTSLHYELPAJQSMDHZIPQPWPWLPSBVWEXBVUAPUEXDXBDNGKQRNCHCMXCRPYGQTHKDFDWGKRZAGXUELEWEKZKOLXOMDCBLTCNKWKMYDSAATWJVSWITZBUNU");
    msg.params.assign("CTWDLFJOQWMBLLLNQCMBKUGQABRFDLLWITHZOAYBETFUAEODRTPXIZTFEFDTJZCTYNMGGOKBMQXKH");

    try
    {
      Utils::ByteBuffer bfr;
      IMC::Packet::serialize(&msg, bfr);
      IMC::Message* msg_d = IMC::Packet::deserialize(bfr.getBuffer(), bfr.getSize());
      test.boolean("PlanGeneration #2", msg == *msg_d);
      delete msg_d;
    }
    catch (IMC::InvalidMessageSize& e)
    {
      (void)e;
      test.boolean("msg #2", msg.getSerializationSize() > DUNE_IMC_CONST_MAX_SIZE);
    }
  }

  {
    IMC::LeaderState msg;
    msg.setTimeStamp(0.5982151764430427);
    msg.setSource(35392U);
    msg.setSourceEntity(234U);
    msg.setDestination(21027U);
    msg.setDestinationEntity(108U);
    msg.group_name.assign("LSAGVOITROJDUYBJUALVAOIUXUKWZRLMNZWDVFAEUWJNZNTPPDTXVIMFHSZDGBNFUHJSKWPPCUBLFVQYPQOJXSMOYPCYUTNKDLGEMUWHPZCQCAKFQTEBOMJWYSRRFYNJMCRTWGSAALEQBTGOLNVRFTYASGIZIOGHKGBTRDAPBDKBEQDXNHZOEDMHD");
    msg.op = 39U;
    msg.lat = 0.9641620086594503;
    msg.lon = 0.8954109356422258;
    msg.height = 0.48873104417038715;
    msg.x = 0.4746290321432397;
    msg.y = 0.6775907098913301;
    msg.z = 0.495156620611087;
    msg.phi = 0.8656115522745448;
    msg.theta = 0.2436831222742104;
    msg.psi = 0.402527229590548;
    msg.vx = 0.31193707032381934;
    msg.vy = 0.4518525507285409;
    msg.vz = 0.8931825215711121;
    msg.p = 0.030058546237307193;
    msg.q = 0.6039364783931587;
    msg.r = 0.22352654161400465;
    msg.svx = 0.21653372271320248;
    msg.svy = 0.3374176204547631;
    msg.svz = 0.5198530929844932;

    try
    {
      Utils::ByteBuffer bfr;
      IMC::Packet::serialize(&msg, bfr);
      IMC::Message* msg_d = IMC::Packet::deserialize(bfr.getBuffer(), bfr.getSize());
      test.boolean("LeaderState #0", msg == *msg_d);
      delete msg_d;
    }
    catch (IMC::InvalidMessageSize& e)
    {
      (void)e;
      test.boolean("msg #0", msg.getSerializationSize() > DUNE_IMC_CONST_MAX_SIZE);
    }
  }

  {
    IMC::LeaderState msg;
    msg.setTimeStamp(0.4987373479482269);
    msg.setSource(46233U);
    msg.setSourceEntity(2U);
    msg.setDestination(59771U);
    msg.setDestinationEntity(132U);
    msg.group_name.assign("ITGVXEKTUJLCJXZYHBQDDLPGEFPMAA");
    msg.op = 28U;
    msg.lat = 0.30355081060289;
    msg.lon = 0.14035280435329678;
    msg.height = 0.0800343868697595;
    msg.x = 0.5182610764636175;
    msg.y = 0.4620427279169228;
    msg.z = 0.5546200698799489;
    msg.phi = 0.41231201343671053;
    msg.theta = 0.4099445244231158;
    msg.psi = 0.6314051777627333;
    msg.vx = 0.9597696049173018;
    msg.vy = 0.994619089494872;
    msg.vz = 0.7011651186547007;
    msg.p = 0.8458442961770548;
    msg.q = 0.030606772740146004;
    msg.r = 0.6320866302260533;
    msg.svx = 0.7038563453375065;
    msg.svy = 0.4432207014325944;
    msg.svz = 0.7877466493040853;

    try
    {
      Utils::ByteBuffer bfr;
      IMC::Packet::serialize(&msg, bfr);
      IMC::Message* msg_d = IMC::Packet::deserialize(bfr.getBuffer(), bfr.getSize());
      test.boolean("LeaderState #1", msg == *msg_d);
      delete msg_d;
    }
    catch (IMC::InvalidMessageSize& e)
    {
      (void)e;
      test.boolean("msg #1", msg.getSerializationSize() > DUNE_IMC_CONST_MAX_SIZE);
    }
  }

  {
    IMC::LeaderState msg;
    msg.setTimeStamp(0.44195707966858433);
    msg.setSource(20074U);
    msg.setSourceEntity(218U);
    msg.setDestination(64748U);
    msg.setDestinationEntity(133U);
    msg.group_name.assign("BESWFVVDHLETJQOZHXGWWKRURTUFYHEJRWTIMSWRVCHNFHVTNKFUUSWUTXNIODGXVQKDRBISLOIQUPBBYOPIOXODBIGACWEXYQZVKUZLJPLRFLADCEFHEJMGQPIPMQNTZQWYMKUXASDKTRGABNXSRCDXYAJOPTITBWSPAGCCECEEAYVUCYGYNCSKHMOELTNPFNODZDLZMLKPFVAKJQBJYYZWHMAXKHZVNMGZJHULJPLJOFGM");
    msg.op = 145U;
    msg.lat = 0.2854621165004271;
    msg.lon = 0.37655388561009095;
    msg.height = 0.5845816258652454;
    msg.x = 0.01248809013163954;
    msg.y = 0.08529140256838497;
    msg.z = 0.2692031445182853;
    msg.phi = 0.8988303181763245;
    msg.theta = 0.13685733091275376;
    msg.psi = 0.002274812590563502;
    msg.vx = 0.43902458154465707;
    msg.vy = 0.942570436448138;
    msg.vz = 0.40616234876373525;
    msg.p = 0.1801922760629594;
    msg.q = 0.5814081059406946;
    msg.r = 0.6239141429234711;
    msg.svx = 0.8238508724206675;
    msg.svy = 0.18892923066457268;
    msg.svz = 0.23157571809995392;

    try
    {
      Utils::ByteBuffer bfr;
      IMC::Packet::serialize(&msg, bfr);
      IMC::Message* msg_d = IMC::Packet::deserialize(bfr.getBuffer(), bfr.getSize());
      test.boolean("LeaderState #2", msg == *msg_d);
      delete msg_d;
    }
    catch (IMC::InvalidMessageSize& e)
    {
      (void)e;
      test.boolean("msg #2", msg.getSerializationSize() > DUNE_IMC_CONST_MAX_SIZE);
    }
  }

  {
    IMC::PlanStatistics msg;
    msg.setTimeStamp(0.6138006964071973);
    msg.setSource(62926U);
    msg.setSourceEntity(123U);
    msg.setDestination(9312U);
    msg.setDestinationEntity(247U);
    msg.plan_id.assign("UXTUGLYCEJVLTILVZSEVYZJRATWIABSMKWMBVLJJOCNCHVHVKTVOCLEXLKIIXWCDXGXYSQANDUHSIYKBBPUFDIOXADPWBSREEODTRODPSMTFSNIAONXRJGHYHUDFQAWEGDBMIPHBIQFCUVQKJREFLGPTFJGDHMKRTCUFOQRNDYYRASKWJNWGXMVWFWUOG");
    msg.type = 93U;
    msg.properties = 252U;
    msg.durations.assign("XLTWSLAFALXERSHQLBKWGDMVQFXWZNQIRZVWBBQXOISZGXYIKAUQIESQAJPJEKPOIJXBSIOJUVYBJMWLPMICTZZHTSKWHLCYXGDKCEAAFJYAGDNGSTNDYNFKHOOHKVBIOUENHVGPUFYDRTPTMPMYVNHVMIFXTUGAREYRZEAGCCUWJFHEQZYCXRPFQCWWWOVOPKURBZXVIZBBMOSGKZOEYDDBJRMJNPQMCCNLRSL");
    msg.distances.assign("JKKNGETMRFLHVYCULIFOAPQUYTRKZPRLIBNMDUVMEVROWGZZROPQFOSSYMHDKJVWQTDJDCQTQOLBXHYRNIJSSPKSJKNIMXKAIMENAHLCIBFMHZHUKMZUCFLBMWUFYYGYDYDABVRDGCEJCBFESWTQSAIKYLSPRHOBAVGHPVXWLEFSHTOIUWZDYRXCNGPFRVHZNJJWAQFGEZ");
    msg.actions.assign("FUDYNZHPVIENNABWJAZEPYJVDRHWPLGFWNOYGKXQYIJTJROYGKWIBFOUMLSNMPPRXAEQEMM");
    msg.fuel.assign("RKPYXRCRHWIEECYNCSPJLWUVUIUZBVGRRHZLZHQNEOCDVTBAAYCXUPJWMJSXFCBNLTKMOQFIANBJOQCPDDLTYVNJHJQLYZBYPFDKLXFPXHADGVYETEWMTTGGNWTKUEBZRIVVDKXBS");

    try
    {
      Utils::ByteBuffer bfr;
      IMC::Packet::serialize(&msg, bfr);
      IMC::Message* msg_d = IMC::Packet::deserialize(bfr.getBuffer(), bfr.getSize());
      test.boolean("PlanStatistics #0", msg == *msg_d);
      delete msg_d;
    }
    catch (IMC::InvalidMessageSize& e)
    {
      (void)e;
      test.boolean("msg #0", msg.getSerializationSize() > DUNE_IMC_CONST_MAX_SIZE);
    }
  }

  {
    IMC::PlanStatistics msg;
    msg.setTimeStamp(0.18548560206435127);
    msg.setSource(56195U);
    msg.setSourceEntity(52U);
    msg.setDestination(19038U);
    msg.setDestinationEntity(177U);
    msg.plan_id.assign("JTGWWTQSWPPBOYEKFGPOMGQBINRACROZXAEAJIULVZZTOGIOTQWXDMFFIVTSEUYLPHDTRSTIARGLKGKEB");
    msg.type = 98U;
    msg.properties = 138U;
    msg.durations.assign("VBDGUQKNTRNIHSFEHHJVYXRHEBJSXWLBHRKHOYOFKCYLEKCPSNBDKFPLRWHMTVXJULNZAPPYNRAYJXWAVGWIIVDEVYDCNCZFTKLWFJYCJBXPQMHDGQKNZW");
    msg.distances.assign("XEVBQWNNFTLVIJZBERSWTUQXQYMSTVXSCCXGNKEYDMDNNAOAYYHKPYPUOONGHOIKDQLGZTVACSCABPIQSVTAQGUDFIKUZBFLJBN");
    msg.actions.assign("WYRUQUHIXKYEIZUATBVGJWRPKGZXCJSFKKQIDAMCMKCFQSYOGGSJTLJTPWKQOAUPFOWWTLVHRLQLPUOVYNZSVIRUBIGGNWJTFYTOKJPWTBNJCBMHFIDABIHWIERDNVLDXAERBCHNENCNKDGOMFDMPEJLZZIGULSXGUKCCJYFNDCPFPAVSLHDQZNZSQWBLZKXLEAXOYBXFRSM");
    msg.fuel.assign("XYRULHEXPXEHQIKKEBRJVBVZCNGCCUFOSTYBLNZLQGKGEKTFJNYFDPHWDUWGWQOQUAJYPAXPUOOIOWDFWIEPFZDSYJOKTZHGTDNKVDFM");

    try
    {
      Utils::ByteBuffer bfr;
      IMC::Packet::serialize(&msg, bfr);
      IMC::Message* msg_d = IMC::Packet::deserialize(bfr.getBuffer(), bfr.getSize());
      test.boolean("PlanStatistics #1", msg == *msg_d);
      delete msg_d;
    }
    catch (IMC::InvalidMessageSize& e)
    {
      (void)e;
      test.boolean("msg #1", msg.getSerializationSize() > DUNE_IMC_CONST_MAX_SIZE);
    }
  }

  {
    IMC::PlanStatistics msg;
    msg.setTimeStamp(0.1921258829097744);
    msg.setSource(17324U);
    msg.setSourceEntity(108U);
    msg.setDestination(19935U);
    msg.setDestinationEntity(41U);
    msg.plan_id.assign("DAYDXBZMDJXHUCSQYAWZNEGGZTHOTEZRVPKSWLCJNKGSMGFFUHEOAJULJSCKMUOCJQGGSIGFNOKIKUTDBABYOARXZSRGXFFLUXHXTCYSCPQPSPEDJMWAHARTQTYRFQNZVJJMZWYDGRASMKUHOQNBTVKAEFBXUUVASCWBMJVIVOBMIDLIILXLTHYQHPDNKBLZWLJGWTHPXFERPOQI");
    msg.type = 232U;
    msg.properties = 159U;
    msg.durations.assign("ZMLBKJKHTHFVQKLIYJQGFDQTTZBERXFBYMFBDDVUPIIHTWNNJZBFUPHGQFRANYZYKTWRLSBBESCGCOOIREWPDKDEXAMKYLUDJEMCMPIREFPAHSCLIVXJHDNOQPVYDGXTPOHAQKXAQEBSNSWBVGSGZYZNNAAOXKRWLONLRTUSJLSYOJONWVMCZXGCLVEXWCYSVHUFUQQBGDNQRVJGLCXZPCMM");
    msg.distances.assign("HCXLKDJKMBOTYJZSGNOQGBETVMLNCDKUNQVRTCKVBIUQUGWTVLPPCXISFQLXPNEJOHIYTLATLJFIAUMKVBWBJMCJGTPNDORARYSFVGCUDKBTGZNIZAQBSHZQGNZJDWPWEZESEEDVTVYRFSZSCJCXPYHVOFFSGXNCZINMMKEZUUBWPWVXRGIXEHKRHOYANLL");
    msg.actions.assign("OQLCHHQWNAVDPVGLIKLQMGMKISLZWWVNRROFQGEHVHUYEEZADCFIKUHCJAPYMNBXRIOOMVTXAPZFZEGBVDHIWZVNPNQBFEGSBARPCYAJPOZXXSSSNXNUIPMGDMFWMHJPYHNAXJOEBKLKCQWTKTRPOZKDGRESWDBDTCYSZDBOOBRIPCQDF");
    msg.fuel.assign("MWIPPBORMZDSDPRDBGUWUVVFAGVTNJVHNPJEZEQVQNAJKVCKAGHVWWDGPFLTMBYINAFJAFBKAKFQECYEMCSZZSVLNRFKUCGDSLISWPHCGUULZRATISMVQPOLCOTDQOIKSCYYUTBQHRAXTQCOCDUSEXZLEXZOVTZULDFOPRJXCEYYKEJWZDFXBSRKYLNXWAGPLBKFIMXGMQJRYNRJYAJQBQHHFOZISMTXMUIHOHUNKI");

    try
    {
      Utils::ByteBuffer bfr;
      IMC::Packet::serialize(&msg, bfr);
      IMC::Message* msg_d = IMC::Packet::deserialize(bfr.getBuffer(), bfr.getSize());
      test.boolean("PlanStatistics #2", msg == *msg_d);
      delete msg_d;
    }
    catch (IMC::InvalidMessageSize& e)
    {
      (void)e;
      test.boolean("msg #2", msg.getSerializationSize() > DUNE_IMC_CONST_MAX_SIZE);
    }
  }

  {
    IMC::ReportedState msg;
    msg.setTimeStamp(0.2736264992638392);
    msg.setSource(1454U);
    msg.setSourceEntity(6U);
    msg.setDestination(47841U);
    msg.setDestinationEntity(149U);
    msg.lat = 0.17236745765871342;
    msg.lon = 0.013150193566618062;
    msg.depth = 0.5591809835759517;
    msg.roll = 0.3124757207386487;
    msg.pitch = 0.37013075942204043;
    msg.yaw = 0.24679385826738942;
    msg.rcp_time = 0.4365472999394103;
    msg.sid.assign("XRZECLFGTCUJEOQWCOHBKLIHIXSBTPUAGQPNSCPEAXDYTPCOJAWTURUCLYXTQZMDKFPYSLNEKJCTFPWMNSHVHPPSOSSIGW");
    msg.s_type = 50U;

    try
    {
      Utils::ByteBuffer bfr;
      IMC::Packet::serialize(&msg, bfr);
      IMC::Message* msg_d = IMC::Packet::deserialize(bfr.getBuffer(), bfr.getSize());
      test.boolean("ReportedState #0", msg == *msg_d);
      delete msg_d;
    }
    catch (IMC::InvalidMessageSize& e)
    {
      (void)e;
      test.boolean("msg #0", msg.getSerializationSize() > DUNE_IMC_CONST_MAX_SIZE);
    }
  }

  {
    IMC::ReportedState msg;
    msg.setTimeStamp(0.4528341972751253);
    msg.setSource(39626U);
    msg.setSourceEntity(115U);
    msg.setDestination(10576U);
    msg.setDestinationEntity(7U);
    msg.lat = 0.03238700230241909;
    msg.lon = 0.17374590220829567;
    msg.depth = 0.07253952086643034;
    msg.roll = 0.3815928930628051;
    msg.pitch = 0.8402290279710123;
    msg.yaw = 0.5385555075982255;
    msg.rcp_time = 0.9613672019512252;
    msg.sid.assign("FDUPANHWLGIRQPFDOMHVUUFYUJWHBECJADBKPLFSIZXCVHNRJXXLBWGCSQAJIZDFLYDBSGZKMIPEIXENZGHJWPYDZBFSMWZEQOHQLGRNERCFTHMQRNLEYAMKXBXRHLBUTTWABQOKWTTMSYHAKEINTWEOJNHGOOAOYVXUPTVNPZLSOVIUDYWMTLZVBCNRJCUYTR");
    msg.s_type = 237U;

    try
    {
      Utils::ByteBuffer bfr;
      IMC::Packet::serialize(&msg, bfr);
      IMC::Message* msg_d = IMC::Packet::deserialize(bfr.getBuffer(), bfr.getSize());
      test.boolean("ReportedState #1", msg == *msg_d);
      delete msg_d;
    }
    catch (IMC::InvalidMessageSize& e)
    {
      (void)e;
      test.boolean("msg #1", msg.getSerializationSize() > DUNE_IMC_CONST_MAX_SIZE);
    }
  }

  {
    IMC::ReportedState msg;
    msg.setTimeStamp(0.9218870779795582);
    msg.setSource(8990U);
    msg.setSourceEntity(226U);
    msg.setDestination(46264U);
    msg.setDestinationEntity(17U);
    msg.lat = 0.9419787732543206;
    msg.lon = 0.644000742643931;
    msg.depth = 0.3203534473655295;
    msg.roll = 0.38322623891315744;
    msg.pitch = 0.09213675915785391;
    msg.yaw = 0.8122508062116248;
    msg.rcp_time = 0.45708417226905573;
    msg.sid.assign("JMEHJRYLZZGXPFACWVHKQSKSXZDIXLLRJHINECCONRDECASFTDBSHGCOPZHQCXUKYJEZLYTQTKGYVMYVXXSVAJREGGCUBVVJYAG");
    msg.s_type = 95U;

    try
    {
      Utils::ByteBuffer bfr;
      IMC::Packet::serialize(&msg, bfr);
      IMC::Message* msg_d = IMC::Packet::deserialize(bfr.getBuffer(), bfr.getSize());
      test.boolean("ReportedState #2", msg == *msg_d);
      delete msg_d;
    }
    catch (IMC::InvalidMessageSize& e)
    {
      (void)e;
      test.boolean("msg #2", msg.getSerializationSize() > DUNE_IMC_CONST_MAX_SIZE);
    }
  }

  {
    IMC::RemoteSensorInfo msg;
    msg.setTimeStamp(0.2492396114903106);
    msg.setSource(26137U);
    msg.setSourceEntity(70U);
    msg.setDestination(58687U);
    msg.setDestinationEntity(222U);
    msg.id.assign("XOHYICVTEYAJBXIGSBTHAJQDVDFEWRLVOWBANKROHKACCPMVFZJASKYFGVDBQJLZUFUOCJSUYCHZHLTDNASKMQGWTB");
    msg.sensor_class.assign("SQITVTJPDSLQIRLBFFRFSGGVEGEXLPTAMRYAQXPGVUOWHWKBNWCRLPIMAOYZNNJZKBVHMMWEHJIFSHONZMKRRCJNSUDGBHKLSYJIJQKGXXVWJNZLOWQBAF");
    msg.lat = 0.4787001215386981;
    msg.lon = 0.8592222767038534;
    msg.alt = 0.36140403956787404;
    msg.heading = 0.37417973087238043;
    msg.data.assign("NFEDKOJQTEPJBCKOITHBUNCXXKLMIGXJICVUXTFGSALVRQJBBPQHCKAAKIDDNGOLTRPTLIBNGPYEAVMAMLUYHHOWYOTDRIUVRPYXNEJMMCQIVWWGIHCWZUNWQZGPOFDSALCDZRMFSQKHUWPFVSQLLITSEFPJIPXRHEUPDJJTHYXCCJBBVACKWARBDZUXZRSZAQEGXROSYUM");

    try
    {
      Utils::ByteBuffer bfr;
      IMC::Packet::serialize(&msg, bfr);
      IMC::Message* msg_d = IMC::Packet::deserialize(bfr.getBuffer(), bfr.getSize());
      test.boolean("RemoteSensorInfo #0", msg == *msg_d);
      delete msg_d;
    }
    catch (IMC::InvalidMessageSize& e)
    {
      (void)e;
      test.boolean("msg #0", msg.getSerializationSize() > DUNE_IMC_CONST_MAX_SIZE);
    }
  }

  {
    IMC::RemoteSensorInfo msg;
    msg.setTimeStamp(0.9510163116036267);
    msg.setSource(48331U);
    msg.setSourceEntity(64U);
    msg.setDestination(4254U);
    msg.setDestinationEntity(77U);
    msg.id.assign("MDXTZVVOZWDBIDIUWMSTAEKJIFABGZBWMOWNCIIDMOXVMGOBXCHAZXKTVSUHCXIPAFHQPNBPFNKLMAR");
    msg.sensor_class.assign("DUBGIVKJWWSPCINCLJTXYFJEITLYRNBHAXGNNQATEQHSUADGZLYMCUEWVZAHMSDRWRCBKTOYLPZBDVDBEFIEKYLTYSRKAAMMMHJDWTPMLCXZYEDAOAVJHWBRUIQVZQGSUXCUKUGPRRMJO");
    msg.lat = 0.6347089292235164;
    msg.lon = 0.6171596367101577;
    msg.alt = 0.7642283239204194;
    msg.heading = 0.9786669279079763;
    msg.data.assign("YKPQEQFGJKGUFXQSOYPPBZPZNZXVDZIEXNPYYMWPDMDWRHRSQGTOBKUWEJZBMOMDBCIVHTYONENAEVIBACOLUOQVKGQUGGNLFDJJLRKNTHDHVBLXYHLIWIOBQNRTTYMAGEGGVMRFYKXCUKSACTKDAAWWARLPPCUIDADXCHUJMOQAY");

    try
    {
      Utils::ByteBuffer bfr;
      IMC::Packet::serialize(&msg, bfr);
      IMC::Message* msg_d = IMC::Packet::deserialize(bfr.getBuffer(), bfr.getSize());
      test.boolean("RemoteSensorInfo #1", msg == *msg_d);
      delete msg_d;
    }
    catch (IMC::InvalidMessageSize& e)
    {
      (void)e;
      test.boolean("msg #1", msg.getSerializationSize() > DUNE_IMC_CONST_MAX_SIZE);
    }
  }

  {
    IMC::RemoteSensorInfo msg;
    msg.setTimeStamp(0.5189798511240287);
    msg.setSource(61816U);
    msg.setSourceEntity(29U);
    msg.setDestination(40667U);
    msg.setDestinationEntity(212U);
    msg.id.assign("VVNWQSIAXRQXZUCBVOLUPKDCPGYGJNAMIBTVAMSCEDRGJLGVVPXQFJMVRFARANWEBKBSDRPMFZXHYPEYNCEKMKTBACLDHEOUWNZLLOQUMYWLHQXLSRTHGCOWWTIOZSFXBJRPCTBAIDFVHOFQULUIUDTMPXHT");
    msg.sensor_class.assign("XEWVQIKRBXSDULUMVDICOWKJDEQOIAUKOUDZTJLTMGVHUZXPRKLIOKZYBNISYPNETAASXTUCVXDHEAAGZNHHNVTCMESWJGYQWRJSFHQHDMFJAGXUDGRLJAJOEWPGEYCDCSONBFOQEFTYVVDPRACCWVZMXERQLLFBYCPOVZDSNKYPGNQWSMXYTRZAKTLPQMFKOJUJGZFTISPHCZOKYBNBRWBRSHGYNFFNBTVL");
    msg.lat = 0.5223732402873692;
    msg.lon = 0.8521487653283502;
    msg.alt = 0.6557570633249735;
    msg.heading = 0.6659266462673937;
    msg.data.assign("SBXVFRWIWFDDNPWFYQQWKCRVNAJCDTEZWQFUMNISICHYNVPIEDE");

    try
    {
      Utils::ByteBuffer bfr;
      IMC::Packet::serialize(&msg, bfr);
      IMC::Message* msg_d = IMC::Packet::deserialize(bfr.getBuffer(), bfr.getSize());
      test.boolean("RemoteSensorInfo #2", msg == *msg_d);
      delete msg_d;
    }
    catch (IMC::InvalidMessageSize& e)
    {
      (void)e;
      test.boolean("msg #2", msg.getSerializationSize() > DUNE_IMC_CONST_MAX_SIZE);
    }
  }

  {
    IMC::Map msg;
    msg.setTimeStamp(0.1743221773805137);
    msg.setSource(46955U);
    msg.setSourceEntity(114U);
    msg.setDestination(39223U);
    msg.setDestinationEntity(222U);
    msg.id.assign("CGZZUBRIPTLQRZGEWBEMKTSLHYMSIJANCBTOETNJQOHRTOZPQQMDDPWNQVXEB");
    IMC::MapFeature tmp_msg_0;
    tmp_msg_0.id.assign("LAJLKRTDOJFJKVBXHFPZGJA");
    tmp_msg_0.feature_type = 143U;
    tmp_msg_0.rgb_red = 236U;
    tmp_msg_0.rgb_green = 130U;
    tmp_msg_0.rgb_blue = 236U;
    msg.features.push_back(tmp_msg_0);

    try
    {
      Utils::ByteBuffer bfr;
      IMC::Packet::serialize(&msg, bfr);
      IMC::Message* msg_d = IMC::Packet::deserialize(bfr.getBuffer(), bfr.getSize());
      test.boolean("Map #0", msg == *msg_d);
      delete msg_d;
    }
    catch (IMC::InvalidMessageSize& e)
    {
      (void)e;
      test.boolean("msg #0", msg.getSerializationSize() > DUNE_IMC_CONST_MAX_SIZE);
    }
  }

  {
    IMC::Map msg;
    msg.setTimeStamp(0.7450195971124047);
    msg.setSource(53109U);
    msg.setSourceEntity(244U);
    msg.setDestination(46554U);
    msg.setDestinationEntity(83U);
    msg.id.assign("SMOSFGTSDMOIRWGDZFRCMWRWGQKXPBVBJHNHIEDNDHVFPXYZPXJRAKANKUVQMDRICOQHJZSRPWPIOTPLNOMUCTSJYSKIYPKYJGHVBFTGCDTAMAJXSZULWNXEZMDDZLKDPNVANKTILXXQHRGSIHUMNXLQWHYEQYCKEZHMOQLBZPUBJYRCFYUVXERUEPVATYYLJEFIGAKGOWBRBTMVIABOFJTNDVHSFCKSLULTXZFOEWALQ");
    IMC::MapFeature tmp_msg_0;
    tmp_msg_0.id.assign("EADCKXGVFJTCRWKAMSZHIONQEIYCGLAOTFGFZJJOBWJSZXIUXULQNSYQUIVOZMVWNFEKYDMWVUPFJOIHJZVVBSTVHWPTSZFPNDDMWRPJHJKENWNBSXRKOJSKLHRDPIBEKLPGSNPGTAGROIOBWLDEGLUQIKFVTXTYHSUHZBKUYQBYILUCNMYQAPBTBNAACHECMLDRQMLQSXHTZFWIDGDATKOPQFRGRWAOCLYFQUJZRC");
    tmp_msg_0.feature_type = 211U;
    tmp_msg_0.rgb_red = 117U;
    tmp_msg_0.rgb_green = 33U;
    tmp_msg_0.rgb_blue = 76U;
    msg.features.push_back(tmp_msg_0);

    try
    {
      Utils::ByteBuffer bfr;
      IMC::Packet::serialize(&msg, bfr);
      IMC::Message* msg_d = IMC::Packet::deserialize(bfr.getBuffer(), bfr.getSize());
      test.boolean("Map #1", msg == *msg_d);
      delete msg_d;
    }
    catch (IMC::InvalidMessageSize& e)
    {
      (void)e;
      test.boolean("msg #1", msg.getSerializationSize() > DUNE_IMC_CONST_MAX_SIZE);
    }
  }

  {
    IMC::Map msg;
    msg.setTimeStamp(0.21012396718135795);
    msg.setSource(59365U);
    msg.setSourceEntity(95U);
    msg.setDestination(38680U);
    msg.setDestinationEntity(167U);
    msg.id.assign("BEAUDCYWIKQQDNQPCRHGECHNTCUIFTJDEGXOKFMLOLAYESJKKQLLRDORYGXHIRRVOVYIFSVXKUHLKFAURCXTPTYGAWCVPMIWJCTSUYNZGLEZZSLJORBDJJUKQBUXXBDMXHGGFJEPWKSOBRVCSIJYOWUIIEHPMGQNDXMEABCIZHFQMDQWMTXTENZZANKSHGVAFHPHAMUOYFNAOBWZLDNBVJLZTMSRPJQFXCDNVOGSEYTRTKBUZALIVFSWPWPPQB");

    try
    {
      Utils::ByteBuffer bfr;
      IMC::Packet::serialize(&msg, bfr);
      IMC::Message* msg_d = IMC::Packet::deserialize(bfr.getBuffer(), bfr.getSize());
      test.boolean("Map #2", msg == *msg_d);
      delete msg_d;
    }
    catch (IMC::InvalidMessageSize& e)
    {
      (void)e;
      test.boolean("msg #2", msg.getSerializationSize() > DUNE_IMC_CONST_MAX_SIZE);
    }
  }

  {
    IMC::MapFeature msg;
    msg.setTimeStamp(0.5431382060160089);
    msg.setSource(28372U);
    msg.setSourceEntity(228U);
    msg.setDestination(31856U);
    msg.setDestinationEntity(166U);
    msg.id.assign("SQMSVWFJKLGRNFEBQYEMXFOZCPHRLDMNRLFAAEOIVYBDAUGOCNWNLNWKXRBR");
    msg.feature_type = 242U;
    msg.rgb_red = 31U;
    msg.rgb_green = 138U;
    msg.rgb_blue = 185U;

    try
    {
      Utils::ByteBuffer bfr;
      IMC::Packet::serialize(&msg, bfr);
      IMC::Message* msg_d = IMC::Packet::deserialize(bfr.getBuffer(), bfr.getSize());
      test.boolean("MapFeature #0", msg == *msg_d);
      delete msg_d;
    }
    catch (IMC::InvalidMessageSize& e)
    {
      (void)e;
      test.boolean("msg #0", msg.getSerializationSize() > DUNE_IMC_CONST_MAX_SIZE);
    }
  }

  {
    IMC::MapFeature msg;
    msg.setTimeStamp(0.3312447021467696);
    msg.setSource(44411U);
    msg.setSourceEntity(18U);
    msg.setDestination(64900U);
    msg.setDestinationEntity(176U);
    msg.id.assign("LVCFJLQUDDNQJXXGB");
    msg.feature_type = 203U;
    msg.rgb_red = 145U;
    msg.rgb_green = 234U;
    msg.rgb_blue = 62U;
    IMC::MapPoint tmp_msg_0;
    tmp_msg_0.lat = 0.22504804402487333;
    tmp_msg_0.lon = 0.6965942995434824;
    tmp_msg_0.alt = 0.27424646236215966;
    msg.feature.push_back(tmp_msg_0);

    try
    {
      Utils::ByteBuffer bfr;
      IMC::Packet::serialize(&msg, bfr);
      IMC::Message* msg_d = IMC::Packet::deserialize(bfr.getBuffer(), bfr.getSize());
      test.boolean("MapFeature #1", msg == *msg_d);
      delete msg_d;
    }
    catch (IMC::InvalidMessageSize& e)
    {
      (void)e;
      test.boolean("msg #1", msg.getSerializationSize() > DUNE_IMC_CONST_MAX_SIZE);
    }
  }

  {
    IMC::MapFeature msg;
    msg.setTimeStamp(0.17427039053364113);
    msg.setSource(5888U);
    msg.setSourceEntity(98U);
    msg.setDestination(26538U);
    msg.setDestinationEntity(69U);
    msg.id.assign("IAERCDZGTTOTMAVQFACMXJWGLHPFONONFYZNQRRNGXUIAKEFBHJOIQBGTXPUNHJEPVAJWB");
    msg.feature_type = 72U;
    msg.rgb_red = 57U;
    msg.rgb_green = 34U;
    msg.rgb_blue = 132U;
    IMC::MapPoint tmp_msg_0;
    tmp_msg_0.lat = 0.7342462373996204;
    tmp_msg_0.lon = 0.1818114561761618;
    tmp_msg_0.alt = 0.830850869168196;
    msg.feature.push_back(tmp_msg_0);

    try
    {
      Utils::ByteBuffer bfr;
      IMC::Packet::serialize(&msg, bfr);
      IMC::Message* msg_d = IMC::Packet::deserialize(bfr.getBuffer(), bfr.getSize());
      test.boolean("MapFeature #2", msg == *msg_d);
      delete msg_d;
    }
    catch (IMC::InvalidMessageSize& e)
    {
      (void)e;
      test.boolean("msg #2", msg.getSerializationSize() > DUNE_IMC_CONST_MAX_SIZE);
    }
  }

  {
    IMC::MapPoint msg;
    msg.setTimeStamp(0.19722516576903448);
    msg.setSource(22869U);
    msg.setSourceEntity(65U);
    msg.setDestination(6659U);
    msg.setDestinationEntity(172U);
    msg.lat = 0.4555194865687353;
    msg.lon = 0.3679364337345725;
    msg.alt = 0.20868527239946555;

    try
    {
      Utils::ByteBuffer bfr;
      IMC::Packet::serialize(&msg, bfr);
      IMC::Message* msg_d = IMC::Packet::deserialize(bfr.getBuffer(), bfr.getSize());
      test.boolean("MapPoint #0", msg == *msg_d);
      delete msg_d;
    }
    catch (IMC::InvalidMessageSize& e)
    {
      (void)e;
      test.boolean("msg #0", msg.getSerializationSize() > DUNE_IMC_CONST_MAX_SIZE);
    }
  }

  {
    IMC::MapPoint msg;
    msg.setTimeStamp(0.49118572700616814);
    msg.setSource(26197U);
    msg.setSourceEntity(76U);
    msg.setDestination(53008U);
    msg.setDestinationEntity(54U);
    msg.lat = 0.2101870268510343;
    msg.lon = 0.04433666521360036;
    msg.alt = 0.8650717183899932;

    try
    {
      Utils::ByteBuffer bfr;
      IMC::Packet::serialize(&msg, bfr);
      IMC::Message* msg_d = IMC::Packet::deserialize(bfr.getBuffer(), bfr.getSize());
      test.boolean("MapPoint #1", msg == *msg_d);
      delete msg_d;
    }
    catch (IMC::InvalidMessageSize& e)
    {
      (void)e;
      test.boolean("msg #1", msg.getSerializationSize() > DUNE_IMC_CONST_MAX_SIZE);
    }
  }

  {
    IMC::MapPoint msg;
    msg.setTimeStamp(0.7225820009804149);
    msg.setSource(41008U);
    msg.setSourceEntity(91U);
    msg.setDestination(9844U);
    msg.setDestinationEntity(99U);
    msg.lat = 0.5070883784919809;
    msg.lon = 0.8303754800442839;
    msg.alt = 0.3911875018665003;

    try
    {
      Utils::ByteBuffer bfr;
      IMC::Packet::serialize(&msg, bfr);
      IMC::Message* msg_d = IMC::Packet::deserialize(bfr.getBuffer(), bfr.getSize());
      test.boolean("MapPoint #2", msg == *msg_d);
      delete msg_d;
    }
    catch (IMC::InvalidMessageSize& e)
    {
      (void)e;
      test.boolean("msg #2", msg.getSerializationSize() > DUNE_IMC_CONST_MAX_SIZE);
    }
  }

  {
    IMC::CcuEvent msg;
    msg.setTimeStamp(0.8825699541548203);
    msg.setSource(62420U);
    msg.setSourceEntity(154U);
    msg.setDestination(9329U);
    msg.setDestinationEntity(111U);
    msg.type = 88U;
    msg.id.assign("EFTPVBLLGBVBNIVJRFMVSHEZWEZWRXHZRTNYLSCUDQEJYOPBUUIWNJAXSBSSUTDEIBDWWNKVTUZUZAWIFXGMIGLOGXTQIBUFDJPXLQYF");
    IMC::RSSI tmp_msg_0;
    tmp_msg_0.value = 0.4805902214251552;
    msg.arg.set(tmp_msg_0);

    try
    {
      Utils::ByteBuffer bfr;
      IMC::Packet::serialize(&msg, bfr);
      IMC::Message* msg_d = IMC::Packet::deserialize(bfr.getBuffer(), bfr.getSize());
      test.boolean("CcuEvent #0", msg == *msg_d);
      delete msg_d;
    }
    catch (IMC::InvalidMessageSize& e)
    {
      (void)e;
      test.boolean("msg #0", msg.getSerializationSize() > DUNE_IMC_CONST_MAX_SIZE);
    }
  }

  {
    IMC::CcuEvent msg;
    msg.setTimeStamp(0.26883359586485);
    msg.setSource(48459U);
    msg.setSourceEntity(236U);
    msg.setDestination(10084U);
    msg.setDestinationEntity(250U);
    msg.type = 19U;
    msg.id.assign("DNIHCQXTHGSGFHWYWNMBYWBASPXKRKILIMZAPRBKQORQJRYSPXABUZMMJAJTUAYZZAWKLDVVDPGRFCSBAWHCLONLTUTYMJBZEHTVGXDIIEOLRFVNDQBWZQNNTCPANSSKOHFZJRFLZVMPWTWBXFQDSTCHGYFBUOECNLICRL");
    IMC::SmsTx tmp_msg_0;
    tmp_msg_0.seq = 2572198694U;
    tmp_msg_0.destination.assign("SYAEVEFVWPHOBXXYTZTCVUFVSFPPQJVGRNLGHTYROTUTASZTGEZJTIRAAUFKCJNXBOMCBSRZFABWWSZLKQIOUCFHCXAQLVKHXIEBLGWCIXMKTSRQPHNRTQWELSCMFPIVJCDMPYYYNKPWOFUUKQVOPEMDSDZJOTRGYJOBMHUOMMJXNBEDDNYIEUILIQYYLNAXSEANZEHKBRJULNNHKWWGZIBOXQS");
    tmp_msg_0.timeout = 31931U;
    const signed char tmp_tmp_msg_0_0[] = {-58, -26, -110, 2, 95, -118, -85, 10, 126, -106, -34, 80, -106, 79, 64, 46, -99, 12, 46, -14, 69, 91, 107, -24, -61, 25, 101, -39, -54, 107, -62, -71, -47, -119, -113, 8, 125, 86, -82, -57, -98, 119, -107, -6, -52, -91, 56, -11, -57, -98, 78, 76, 18, -27, 114, -57, -100, 24, 113, 35, -114, 67, 2, 106, 29, 120, -101, 3, -117, -32, -44, 99, -29, -76, -67, -40, 88, 33, -20, 55, -61, -124, -20, 95, -56, -58, -8, -10, -99, 103, -55, -61, 74, 33, -33, -37, 99, -109, -21, -47, 9, 31, -17, -56, -45, -15, 29, -18, -67, -59, 28, -94, -45, 8, -108, -68, -51, 8, 32, 126, -57, 69, -106, 116, 98, -99, 104, 76, 42, 106, 22, -23, 50, -16, 7, -82, 126, 65, -45, -67, -42, 110, 84, 8, 86, -61, -29, 16, 125, -64, -90, -23, 115, 10, -29, -42, -110, -14, -59, 67, 57, -83, 60, -64, -82, -124, -36, -49, -54, -56, -70, -71, 81, 38, 71, 39, 118, -61, -56, 116, 112, -119, 24, 26, 100, -84, -18, 102, -119, 65, 8, -50, 92, 70, -23, 79, -64, 124, -117, 79, 64, -47, 126, -48, 103, -4, -67, -1};
    tmp_msg_0.data.assign(tmp_tmp_msg_0_0, tmp_tmp_msg_0_0 + sizeof(tmp_tmp_msg_0_0));
    msg.arg.set(tmp_msg_0);

    try
    {
      Utils::ByteBuffer bfr;
      IMC::Packet::serialize(&msg, bfr);
      IMC::Message* msg_d = IMC::Packet::deserialize(bfr.getBuffer(), bfr.getSize());
      test.boolean("CcuEvent #1", msg == *msg_d);
      delete msg_d;
    }
    catch (IMC::InvalidMessageSize& e)
    {
      (void)e;
      test.boolean("msg #1", msg.getSerializationSize() > DUNE_IMC_CONST_MAX_SIZE);
    }
  }

  {
    IMC::CcuEvent msg;
    msg.setTimeStamp(0.8976882260531058);
    msg.setSource(40690U);
    msg.setSourceEntity(72U);
    msg.setDestination(60930U);
    msg.setDestinationEntity(21U);
    msg.type = 92U;
    msg.id.assign("FBCZMWNPVCAJZUBFAROBTIDZGXKKLGKTHPWSRUEESKMEKGWTDAVNFCGMYNIKUJHLNPFDUKZJCITAMXNVFYJQDHICGHPGRSXCCBLZHMZWQCMHNPAIAITXOATZBDSUWGUFAQLYWVPZSOJTTVVAOXHRTUIMYLSMFBRVYYWJQHQOELTXOEUXDMRKSWDHEJQUYJQOZBIOPHMGSYQFKSGSYOVDFIDXORIZBRLVJPNRUWCQWN");
    IMC::DynamicsSimParam tmp_msg_0;
    tmp_msg_0.op = 135U;
    tmp_msg_0.tas2acc_pgain = 0.9251066434241806;
    tmp_msg_0.bank2p_pgain = 0.45672481953931665;
    msg.arg.set(tmp_msg_0);

    try
    {
      Utils::ByteBuffer bfr;
      IMC::Packet::serialize(&msg, bfr);
      IMC::Message* msg_d = IMC::Packet::deserialize(bfr.getBuffer(), bfr.getSize());
      test.boolean("CcuEvent #2", msg == *msg_d);
      delete msg_d;
    }
    catch (IMC::InvalidMessageSize& e)
    {
      (void)e;
      test.boolean("msg #2", msg.getSerializationSize() > DUNE_IMC_CONST_MAX_SIZE);
    }
  }

  {
    IMC::VehicleLinks msg;
    msg.setTimeStamp(0.4391211027862808);
    msg.setSource(58822U);
    msg.setSourceEntity(94U);
    msg.setDestination(28622U);
    msg.setDestinationEntity(88U);
    msg.localname.assign("DKZLSEOOSNERHOSHJZRMHNRZMGPKJRIJKFEUJPNWC");

    try
    {
      Utils::ByteBuffer bfr;
      IMC::Packet::serialize(&msg, bfr);
      IMC::Message* msg_d = IMC::Packet::deserialize(bfr.getBuffer(), bfr.getSize());
      test.boolean("VehicleLinks #0", msg == *msg_d);
      delete msg_d;
    }
    catch (IMC::InvalidMessageSize& e)
    {
      (void)e;
      test.boolean("msg #0", msg.getSerializationSize() > DUNE_IMC_CONST_MAX_SIZE);
    }
  }

  {
    IMC::VehicleLinks msg;
    msg.setTimeStamp(0.023484505806514955);
    msg.setSource(63832U);
    msg.setSourceEntity(226U);
    msg.setDestination(64213U);
    msg.setDestinationEntity(197U);
    msg.localname.assign("GZTOJIQCWTPOJPDOSWUKJEFIGTZFAFJMJZQGBBUSYIFRNCKXSJUBLLDWWIMGOKBBYFNUYEEPHPDSYNVALVSC");

    try
    {
      Utils::ByteBuffer bfr;
      IMC::Packet::serialize(&msg, bfr);
      IMC::Message* msg_d = IMC::Packet::deserialize(bfr.getBuffer(), bfr.getSize());
      test.boolean("VehicleLinks #1", msg == *msg_d);
      delete msg_d;
    }
    catch (IMC::InvalidMessageSize& e)
    {
      (void)e;
      test.boolean("msg #1", msg.getSerializationSize() > DUNE_IMC_CONST_MAX_SIZE);
    }
  }

  {
    IMC::VehicleLinks msg;
    msg.setTimeStamp(0.6669409104180152);
    msg.setSource(61976U);
    msg.setSourceEntity(19U);
    msg.setDestination(11911U);
    msg.setDestinationEntity(27U);
    msg.localname.assign("ZUFMBESJFLCTGLMKLFOGBRYICXMCXVVKNDAFXLJWYWLUYGBFSVYXZHJMZNTMUEEETVPOXDDKPLEQPQAMRFKHNZIJSVUQPNTIWMWOCHESKXBJZFRXCGWFAPXRVDBYRJBUBIYJOCGKKUTXHUMIHAQIPWPWMQJTRVXNIZNBDCAPDYSDURCEOJDTLHSQPIEOHYFUYDDLHCGQTNGNYWRHI");

    try
    {
      Utils::ByteBuffer bfr;
      IMC::Packet::serialize(&msg, bfr);
      IMC::Message* msg_d = IMC::Packet::deserialize(bfr.getBuffer(), bfr.getSize());
      test.boolean("VehicleLinks #2", msg == *msg_d);
      delete msg_d;
    }
    catch (IMC::InvalidMessageSize& e)
    {
      (void)e;
      test.boolean("msg #2", msg.getSerializationSize() > DUNE_IMC_CONST_MAX_SIZE);
    }
  }

  {
    IMC::TrexObservation msg;
    msg.setTimeStamp(0.0515721603804552);
    msg.setSource(59111U);
    msg.setSourceEntity(252U);
    msg.setDestination(23866U);
    msg.setDestinationEntity(235U);
    msg.timeline.assign("ULLQVMSXLKYTKELCOVTKFNUAFUWHJKHWYENPXQTSJGOVHBOHMTLBFCFGCRYEIUBGPYWWFSMXGDNJFEEZIETNKIOJVAWWWUEVILAHGGATKSBNH");
    msg.predicate.assign("DDPXFTSAHKZUTUSJGPXKCHFIPBOLVPMNJCYOBUYEOQDKTPRZZJWKFULVENOTXIRBBHNXXHASWVRLCVLDGWMFY");
    msg.attributes.assign("OPXZNHGZIAWRDRITSWHFLVVKDTBQBNRELHNXYRZH");

    try
    {
      Utils::ByteBuffer bfr;
      IMC::Packet::serialize(&msg, bfr);
      IMC::Message* msg_d = IMC::Packet::deserialize(bfr.getBuffer(), bfr.getSize());
      test.boolean("TrexObservation #0", msg == *msg_d);
      delete msg_d;
    }
    catch (IMC::InvalidMessageSize& e)
    {
      (void)e;
      test.boolean("msg #0", msg.getSerializationSize() > DUNE_IMC_CONST_MAX_SIZE);
    }
  }

  {
    IMC::TrexObservation msg;
    msg.setTimeStamp(0.7179299630268526);
    msg.setSource(47157U);
    msg.setSourceEntity(118U);
    msg.setDestination(37723U);
    msg.setDestinationEntity(46U);
    msg.timeline.assign("ICPOERFTLLPVKGAVEUVCHFOYOUZIHCPZLSUGTBNCLSATANJQGNWROHQIUWMXWLAYRKJPTXEYBMKDVNDXKGXFPJJBSIESLRRVVWAMFUUYFQFKBQBHJHRTYLSJCZTMRQSZSDPIWCZHKPNAAUWIIEFLWZTYXHDOGXXYOKQJXTUJSADBEDEVJMGV");
    msg.predicate.assign("OCXKQZPRJJJMQHAURVBSPLQBIZDARGPMEVENKBEUNSNWDYWXTQDROWL");
    msg.attributes.assign("KTSKEYGSTPXTWLKMFNDXNRJUJXCKVUHKKCMBFAOSGOQOMQIXHZTYLMBMOJYTCVVISVQJIUCAEWDKJCJWGRKEQHPZSHBQIURRXHJNZMPMCSFZAFYGATRLQUVZZOFEIESLYUZCDJYRTQLBNFBFGFNVAWXBAHHBWOVLUUGAJPJXNHLYLIEBRQOOPTKPAPVCGQAOD");

    try
    {
      Utils::ByteBuffer bfr;
      IMC::Packet::serialize(&msg, bfr);
      IMC::Message* msg_d = IMC::Packet::deserialize(bfr.getBuffer(), bfr.getSize());
      test.boolean("TrexObservation #1", msg == *msg_d);
      delete msg_d;
    }
    catch (IMC::InvalidMessageSize& e)
    {
      (void)e;
      test.boolean("msg #1", msg.getSerializationSize() > DUNE_IMC_CONST_MAX_SIZE);
    }
  }

  {
    IMC::TrexObservation msg;
    msg.setTimeStamp(0.9479584117565122);
    msg.setSource(680U);
    msg.setSourceEntity(247U);
    msg.setDestination(35243U);
    msg.setDestinationEntity(136U);
    msg.timeline.assign("AKZYLDQVIHLOIGITZFJCKZQDICBHOSERAHVTYUQEJNCOLXB");
    msg.predicate.assign("FTQMUNJSBZDQHHRJNYRODMLJACXCUCPNXMTLUATYUFLHUHXOSVBJJVSVRAAGVQQPUWKFOXEORDQVHFMJCIUIZHHZJRQYGYJIFOCZEBEDSDOBBYODSGMRXKNVYIMOBZSAZHGKBRCXVWBONMPAWGGWZFJSLPOKZUYCETMQWXALRWLLEQGTAKRANNXIFYSKEWLFBWYPKHNNUEGFPQDQTWGZEMRPMPTLEANUI");
    msg.attributes.assign("FQZYFNHNHBMIZGFFLGDXPYHUKBCXUFSNNUSLJMHTVOAXLDCFJJVQPIYOSIZXKDEBLNMUYWATVVPVOGJQBSYYCOVETESZYZQKSHXOHTSQAFXGZZFRDIVXRJPMQAHOGGUKVZTMJTRVJIRRKDRXZMQW");

    try
    {
      Utils::ByteBuffer bfr;
      IMC::Packet::serialize(&msg, bfr);
      IMC::Message* msg_d = IMC::Packet::deserialize(bfr.getBuffer(), bfr.getSize());
      test.boolean("TrexObservation #2", msg == *msg_d);
      delete msg_d;
    }
    catch (IMC::InvalidMessageSize& e)
    {
      (void)e;
      test.boolean("msg #2", msg.getSerializationSize() > DUNE_IMC_CONST_MAX_SIZE);
    }
  }

  {
    IMC::TrexCommand msg;
    msg.setTimeStamp(0.8186344724088714);
    msg.setSource(56512U);
    msg.setSourceEntity(251U);
    msg.setDestination(40716U);
    msg.setDestinationEntity(65U);
    msg.command = 225U;
    msg.goal_id.assign("CPFLJTHFOATPTPQDYCBOISPJIYUPPCLIQXGTKOFZZORTBXVNWMEGUGIYMEMZZDQLUPVWVSKDRHUTXOETFSJJWWTBNPDWEDCKHMGREYEVOMXCMMIYZNLKLUIINAIPVAEYUDHRRGRVFQXNJEVMABBWSRDGXBSXXHJCLQKCLRMZQUFOTCWXHQLKRGSSLBYUKHGBNZKWAJFAAKWUJHACNRSVQZ");
    msg.goal_xml.assign("JJEYRABOZZZGYYYXNCKDCFDJCNQQSTPLBJSUBXLWLHMIMEGNVKBKZXUUZRLMOFQBCPAIVDXHFZCAPOHHTXREPBCSHFGTRHKSBUVTQTIJHEENHDYLWGKNRHGUNNTPGVSTJMNWIVVQUTIXYYDMYPNDFBKHUAQQNWVWGXECGDPAUOEQMFJELROFKWOJZDSAOWBLQAIMXRFGKVEEJOMLMMGSZZOWCPLAVJLPFOUZAV");

    try
    {
      Utils::ByteBuffer bfr;
      IMC::Packet::serialize(&msg, bfr);
      IMC::Message* msg_d = IMC::Packet::deserialize(bfr.getBuffer(), bfr.getSize());
      test.boolean("TrexCommand #0", msg == *msg_d);
      delete msg_d;
    }
    catch (IMC::InvalidMessageSize& e)
    {
      (void)e;
      test.boolean("msg #0", msg.getSerializationSize() > DUNE_IMC_CONST_MAX_SIZE);
    }
  }

  {
    IMC::TrexCommand msg;
    msg.setTimeStamp(0.9988619588010779);
    msg.setSource(56970U);
    msg.setSourceEntity(129U);
    msg.setDestination(11685U);
    msg.setDestinationEntity(38U);
    msg.command = 65U;
    msg.goal_id.assign("PZLIAZCIJXEXASWHHFMXDWVZKZDXGYCFEOLBTKQRMOIIOCDTZUTRNSHLWPFNQBUNXUQOGLMCAGEPHQGNNGUACRQZAJOWWAVFTUYRNUKACRCOFAUNBGNMXZBQRRPDBIEYDMMMXEOPDTV");
    msg.goal_xml.assign("VEDHWTMWMVIXBBXHYQMIUMZOSJKLTMVIZCVCUJCNGURYNWPOAPDNIUQJDIGCRZWVUSLRDSUYFGCYQKWXNDTTTVQSLWIUECGDJTXSNNLLBMUGSKLOGMHEZKGYFOEACRQECXWPGJTFPIJZVBKWDKBVOBEVLYEAPZITKFKUMKOQLRCDFKPAXZAOHARTBP");

    try
    {
      Utils::ByteBuffer bfr;
      IMC::Packet::serialize(&msg, bfr);
      IMC::Message* msg_d = IMC::Packet::deserialize(bfr.getBuffer(), bfr.getSize());
      test.boolean("TrexCommand #1", msg == *msg_d);
      delete msg_d;
    }
    catch (IMC::InvalidMessageSize& e)
    {
      (void)e;
      test.boolean("msg #1", msg.getSerializationSize() > DUNE_IMC_CONST_MAX_SIZE);
    }
  }

  {
    IMC::TrexCommand msg;
    msg.setTimeStamp(0.785892006322282);
    msg.setSource(43191U);
    msg.setSourceEntity(65U);
    msg.setDestination(44223U);
    msg.setDestinationEntity(54U);
    msg.command = 217U;
    msg.goal_id.assign("RYLVJLZDWZOLNHXOMZRHZXZBQIGMFSWLHAKMLHKXQFNXROQQSTFITJTNPX");
    msg.goal_xml.assign("KMLJGPXUXMOULWEYPNQRJXBFZCGGFIDHHRXVFMIDSBIPSUBOJZWVKIUPNOEBUVRWWGGMDQTIPSGAKHPKRVZVOAXQMTAIWUSYXWOCFSPNFURRTODLZLQYNAIV");

    try
    {
      Utils::ByteBuffer bfr;
      IMC::Packet::serialize(&msg, bfr);
      IMC::Message* msg_d = IMC::Packet::deserialize(bfr.getBuffer(), bfr.getSize());
      test.boolean("TrexCommand #2", msg == *msg_d);
      delete msg_d;
    }
    catch (IMC::InvalidMessageSize& e)
    {
      (void)e;
      test.boolean("msg #2", msg.getSerializationSize() > DUNE_IMC_CONST_MAX_SIZE);
    }
  }

  {
    IMC::TrexOperation msg;
    msg.setTimeStamp(0.6800106320853192);
    msg.setSource(46949U);
    msg.setSourceEntity(120U);
    msg.setDestination(48318U);
    msg.setDestinationEntity(129U);
    msg.op = 67U;
    msg.goal_id.assign("ELLRDNFSLELMLPYCHBQJWC");
    IMC::TrexToken tmp_msg_0;
    tmp_msg_0.timeline.assign("WCEDSVBINWKGCPLSDUADYBWKWEGFCTQZALXNXTHIJNHIGKNPPEAGTYZQUWJJAMGJKUCKXGURMOYPBBTKNGFTRXOXDDEBMTBMMWLQHLVWYLFXJIVPZSOFZUKPZDXJAERCVBNUAZEOVOERNHSYRYKXRVDIYSONLUFBTZ");
    tmp_msg_0.predicate.assign("YTYEARTCULZSFBGHIYQDZUJKMKXXQIBKHFMCAEDFWTSKVGWPOAAARHARXLVSGEOPVFVYWDKSWATVURCDWLHKNXNIZOZBIDUZUESTGNUMGBHMPCQBQXGPJFZIFMNEPZOTKODCBYPXNSDNCRZCFEIWJIJSRTMBKQTWLFWCPUQLGEHLJVGNMSXNLXUAR");
    msg.token.set(tmp_msg_0);

    try
    {
      Utils::ByteBuffer bfr;
      IMC::Packet::serialize(&msg, bfr);
      IMC::Message* msg_d = IMC::Packet::deserialize(bfr.getBuffer(), bfr.getSize());
      test.boolean("TrexOperation #0", msg == *msg_d);
      delete msg_d;
    }
    catch (IMC::InvalidMessageSize& e)
    {
      (void)e;
      test.boolean("msg #0", msg.getSerializationSize() > DUNE_IMC_CONST_MAX_SIZE);
    }
  }

  {
    IMC::TrexOperation msg;
    msg.setTimeStamp(0.6696872158303485);
    msg.setSource(42256U);
    msg.setSourceEntity(214U);
    msg.setDestination(26956U);
    msg.setDestinationEntity(194U);
    msg.op = 134U;
    msg.goal_id.assign("BDCGTMEDCKRJHNERRQSDOJCDGYLXUCKNOHBEXLLJKELBUQIZYVIRTXOLDHNGEMEXBZHVTGMUYIXFVISVIMZBNURWBYHULHCFSOMOQKJDKAJ");
    IMC::TrexToken tmp_msg_0;
    tmp_msg_0.timeline.assign("HCKICXCCWRVAOJQDWMLOGVTXMCGTUCLTMRSCGXABRCEXBMDQLDNEHQEFNAWVUOKIZRJOPPXHZQMKFZNBHTLPTOQWBNWRSYPTIZRPEDRXKLHHJJ");
    tmp_msg_0.predicate.assign("JDUVZBGRGNTIWPZMKFSOWXDTEQREAYQL");
    msg.token.set(tmp_msg_0);

    try
    {
      Utils::ByteBuffer bfr;
      IMC::Packet::serialize(&msg, bfr);
      IMC::Message* msg_d = IMC::Packet::deserialize(bfr.getBuffer(), bfr.getSize());
      test.boolean("TrexOperation #1", msg == *msg_d);
      delete msg_d;
    }
    catch (IMC::InvalidMessageSize& e)
    {
      (void)e;
      test.boolean("msg #1", msg.getSerializationSize() > DUNE_IMC_CONST_MAX_SIZE);
    }
  }

  {
    IMC::TrexOperation msg;
    msg.setTimeStamp(0.7980220452279855);
    msg.setSource(16922U);
    msg.setSourceEntity(43U);
    msg.setDestination(52619U);
    msg.setDestinationEntity(221U);
    msg.op = 152U;
    msg.goal_id.assign("DNLTRVYFSLOKIRVBBUWWLIKIAWNNVBEAEPCLDTCPPNXGMGPBWHTHFRTOVLDUPAZQENCCQDTEJAJZPUUFSOUQOBHMXCKFOTJHTZASPEENYAXJGMEFDQZMUVFMQGRKVHVKJRDZPSXPRIOOJSNDKHCOGYXRUTQYZMQYHTKNMYBABIQCUUZWYCZXFWSMDEHFOVBI");
    IMC::TrexToken tmp_msg_0;
    tmp_msg_0.timeline.assign("MUFMLBCKQQJAAQBMRJRPARCZOXASXBVOOWDKAHJVFYOCYVCSEEIFZPVWVPGCQKBEEOW");
    tmp_msg_0.predicate.assign("LGCOMVQOGPIHZMACATBJBFLLUZUKCRVGONNOSGRSKIHPGJDOZFRYDHVODQWGSHEEUPUMWWROXCNKYBBJJTDTAAIRAQQNBJBB");
    msg.token.set(tmp_msg_0);

    try
    {
      Utils::ByteBuffer bfr;
      IMC::Packet::serialize(&msg, bfr);
      IMC::Message* msg_d = IMC::Packet::deserialize(bfr.getBuffer(), bfr.getSize());
      test.boolean("TrexOperation #2", msg == *msg_d);
      delete msg_d;
    }
    catch (IMC::InvalidMessageSize& e)
    {
      (void)e;
      test.boolean("msg #2", msg.getSerializationSize() > DUNE_IMC_CONST_MAX_SIZE);
    }
  }

  {
    IMC::TrexAttribute msg;
    msg.setTimeStamp(0.2407902545711903);
    msg.setSource(4904U);
    msg.setSourceEntity(51U);
    msg.setDestination(5665U);
    msg.setDestinationEntity(3U);
    msg.name.assign("PKEYHYJEXATQWDPAXHTDZPHIZFHMDNHUXJANULEFRGNXRRPJJGMOQHEDJGPQAHSBUMRZIMBFWFGBQBVMBRBOFKTKYJEZIGVL");
    msg.attr_type = 64U;
    msg.min.assign("QRNHESFBRXWNOUHTDSSABRVOUVSHZAMUBHHIGEPOKPTCJSLWWYINMFIHWOEFZJSFUMXTJVWJEEJPNCNIKSYIYIRRUFIRCWNCGJTMXVMUASSQADQPLSBWBIXVMZDLPVUDQCRKXMTPYHQFJAVQKTTNMZQTHWXUIBMXDLGLXCYFCHOEBGKJYFZZCMLCWNGVZDYCQRKATKEOREDEUQBJOYYL");
    msg.max.assign("SWOGBYRAJYRWRJAKHVRWTEHDINUMLIAVTCHKPKTGCZFPQEQZBDYMQPBQIGKHCCTUZVGVRHGAFMNXNCNTLXILZBVIKSGFOMRIGXHMHCELDIOUVBGOUMFYPTCEBKUYSMLKVWDPXDJEDKOABXZCSNVPLQJPYEQMOIGYFUWWZYTBCCNNUDFEFPNXQJPRESAJOPQFVXVLHLGNKIRSASHDQSRXJ");

    try
    {
      Utils::ByteBuffer bfr;
      IMC::Packet::serialize(&msg, bfr);
      IMC::Message* msg_d = IMC::Packet::deserialize(bfr.getBuffer(), bfr.getSize());
      test.boolean("TrexAttribute #0", msg == *msg_d);
      delete msg_d;
    }
    catch (IMC::InvalidMessageSize& e)
    {
      (void)e;
      test.boolean("msg #0", msg.getSerializationSize() > DUNE_IMC_CONST_MAX_SIZE);
    }
  }

  {
    IMC::TrexAttribute msg;
    msg.setTimeStamp(0.39015752936602466);
    msg.setSource(37346U);
    msg.setSourceEntity(76U);
    msg.setDestination(60283U);
    msg.setDestinationEntity(80U);
    msg.name.assign("RAOITDWFSTGSCYXVMQEVAVXMHVJLHDBQVQQKNCIWPREFCKYQSHXWZZHYFTPJWTLHLMFQYKLRNUBQFAPJHQKDEFMDOUIJKKIOTKERDAFGNIDLUXOZXDASUZVHLUJMWMXCPWHEEULSZCRTJWBMNMRO");
    msg.attr_type = 228U;
    msg.min.assign("CEMNPEGAQVSNTPVBGCRDZJWGKAJBIPSKIRJDDUAVSPKFVBFGXSURERQHWCFMTYNSXDIPSJDKKOZMNHAHBIHAXLFNHNEWGRUGLOZUFAQYYLAFAMOWBAGCILMQBOZRGDAYZETVWRVBLMFTLBYPPQCFWC");
    msg.max.assign("TAPHJBLLLHKQJZNVVNQYFDARHOYIZWUEXNNWCXETUEDSMSFLCUEROOMPDWORAOIXVMXKMEQAIWAYVRWVJUMJEVNQNUUVIHHCPPWU");

    try
    {
      Utils::ByteBuffer bfr;
      IMC::Packet::serialize(&msg, bfr);
      IMC::Message* msg_d = IMC::Packet::deserialize(bfr.getBuffer(), bfr.getSize());
      test.boolean("TrexAttribute #1", msg == *msg_d);
      delete msg_d;
    }
    catch (IMC::InvalidMessageSize& e)
    {
      (void)e;
      test.boolean("msg #1", msg.getSerializationSize() > DUNE_IMC_CONST_MAX_SIZE);
    }
  }

  {
    IMC::TrexAttribute msg;
    msg.setTimeStamp(0.20538504518793732);
    msg.setSource(53152U);
    msg.setSourceEntity(32U);
    msg.setDestination(63949U);
    msg.setDestinationEntity(214U);
    msg.name.assign("DGHOIJQJZFWOQWOBUPKZUXONLIYFMRXFNBOXQJPEYSUWMYXSEUSCJLQQPUZLZWLRYNHFHFVWRLPGVSPGHXUFOKFLARNGFNYBMSJBLPJODEVONIAWELTPFQDZKIZCDZEXEPCIHBRZTHGPTCVHYGWMTCYWYXDSEVDNASOBAATFIYTTVTSRVHCJMURGKOAKHIJUESGQNURIPACAMCAGSRBWKRCMKUBDQWBZNYCLILVETVKDAMVDXIBQGXMEJMTJ");
    msg.attr_type = 29U;
    msg.min.assign("RIGTXRCAMYBFADOUVRDDISUFPWKFRAXGJNUDZAFILTQJAFLYNWPGHQDFREBYRJLWOHWEWCTSYKDUTQVBCSX");
    msg.max.assign("JZVJRSYYAEXUYTFSLGOFAHXWXIBGTWWZCRYWYXFVAQLEVAWXEPRDNOKBJAQNPTUMFCTIHRFZDTPZENLUGQFDHFCGAMSPNXNNYYBQBRIXLOWWNPROCUCTKKMQAVHJLWMKIOHUCOZTPHUIFGGLPZBSVHLTKVOVCEDXOVCRSMBZIMUIEPTZGRSDHKYQMPKSOFLZSKBKRDJQJBKLFBIRNDJPQMVWMVHLGNQJADJEIGZIYESEQYDNCHGEAJXBUMDXA");

    try
    {
      Utils::ByteBuffer bfr;
      IMC::Packet::serialize(&msg, bfr);
      IMC::Message* msg_d = IMC::Packet::deserialize(bfr.getBuffer(), bfr.getSize());
      test.boolean("TrexAttribute #2", msg == *msg_d);
      delete msg_d;
    }
    catch (IMC::InvalidMessageSize& e)
    {
      (void)e;
      test.boolean("msg #2", msg.getSerializationSize() > DUNE_IMC_CONST_MAX_SIZE);
    }
  }

  {
    IMC::TrexToken msg;
    msg.setTimeStamp(0.3160776121259845);
    msg.setSource(43266U);
    msg.setSourceEntity(160U);
    msg.setDestination(60230U);
    msg.setDestinationEntity(28U);
    msg.timeline.assign("IRGBSEVVOPFLIKFSAKNVDRAMLWBCCNDYBWWYJMRYPQNOGLXZNSXIFVSXPWXZQGYTQAQNWWUCBOTKECARMHUFLDYOVFFKTXJQTPLGTBUONHBEDTIQDRZRSNMHRHXXGUEVUARUEEFWKKBUVHHVJXKMSIZYSZNAEEUXJOEK");
    msg.predicate.assign("SXTQPTWDSLHBDANHIUMQDVBXOXHIHYKVYMGLMONRYIJGEJLSZAHYXBGBVEFOBAPWUPRTFRDMQLITKAYTSXRQYSDUOIUHJAFFWNTOPVFPWZSDQGLQYCVOEBVIKOASPZFANGCQTWZKOAJPZBENLVVWMJQCICMMDCKRL");

    try
    {
      Utils::ByteBuffer bfr;
      IMC::Packet::serialize(&msg, bfr);
      IMC::Message* msg_d = IMC::Packet::deserialize(bfr.getBuffer(), bfr.getSize());
      test.boolean("TrexToken #0", msg == *msg_d);
      delete msg_d;
    }
    catch (IMC::InvalidMessageSize& e)
    {
      (void)e;
      test.boolean("msg #0", msg.getSerializationSize() > DUNE_IMC_CONST_MAX_SIZE);
    }
  }

  {
    IMC::TrexToken msg;
    msg.setTimeStamp(0.368147786266809);
    msg.setSource(22368U);
    msg.setSourceEntity(176U);
    msg.setDestination(6172U);
    msg.setDestinationEntity(98U);
    msg.timeline.assign("NDYQYAOWJPYYYTKNOVUIGGCEXLRRIPSRAJNTEBOCSQQDKTXNJOPUHCTFVEDEXLXUIWETSYZEKCBDSXYHTVJMNJSHTMIQOLMDFWPDUEHHPTZWRCZWFRDVVNNKOYSAHDGWZBMLSVROVACOFCDSHFAXQGMKUJFGPDKZRSLVPEGHBPIAHTVCFFWSCQBZZXLIJWXLQUGEIUUWGAQFMBMHGABCFIEKNRWZMXUAVL");
    msg.predicate.assign("KZGWAMWOAVJFXYAUECHUHLYDRVEQNXVGNBTOHNDQWT");

    try
    {
      Utils::ByteBuffer bfr;
      IMC::Packet::serialize(&msg, bfr);
      IMC::Message* msg_d = IMC::Packet::deserialize(bfr.getBuffer(), bfr.getSize());
      test.boolean("TrexToken #1", msg == *msg_d);
      delete msg_d;
    }
    catch (IMC::InvalidMessageSize& e)
    {
      (void)e;
      test.boolean("msg #1", msg.getSerializationSize() > DUNE_IMC_CONST_MAX_SIZE);
    }
  }

  {
    IMC::TrexToken msg;
    msg.setTimeStamp(0.14236265211505938);
    msg.setSource(18952U);
    msg.setSourceEntity(76U);
    msg.setDestination(8518U);
    msg.setDestinationEntity(125U);
    msg.timeline.assign("SMWDRUNGGASCCFKCUQEOBDEHQCKXJOHQBPAYYLIZFVBSZKELGITUNHSCRHNEWRVCQMMTCYHNZICIOLDDSPWBGRFEKWXNJTQVXMWZPHHJYMQMMMEKSERKJOIFUUOTNBYDOVAHWXDSZYF");
    msg.predicate.assign("JLJZQXCIKYDBJBXBVSKQLPLYLGYMWKQIUUBQAMVWPTPWGNZJSTGYMDCNQSSOESHEOHZJIDZRTWPOJSLRJDAYRZHKNSKEPRMEZXLWGPXCAYEUSAQIOOSCFG");
    IMC::TrexAttribute tmp_msg_0;
    tmp_msg_0.name.assign("FWOTFRIMHDZGSXDFHGOICDCNAELTCCPAFPGWZRZLVGHOLXXNUASKXVSPBTDNLHWFHJBZXKKRBMRDMTQYBCCMEKDVABOJTQXZJGVPGOKFKLBKWCTLHRWENZRJEEVPMDVPNNYPBNFFGILVXRSTPYIMEWYJJLIBQRUMAXILQOPBCSCQVIHWI");
    tmp_msg_0.attr_type = 152U;
    tmp_msg_0.min.assign("RNJKVMFSGITDKIUCVYRQTLIOXBQQOKPWZALAWBJDKJSXDXXSUSFMVOJCLYCYASDLAYAOCIXANMEFBOCPFZQUHVGFOHUWDMRNNCGWTCVTENRUEQYRGIYQSTDRWXPIFVH");
    tmp_msg_0.max.assign("LTJXFREOAYOWHEAYNGVZVNQTTVMHKXCOLAPPRLTBJYGJKNYMDHTEINSSJOKEDXSVHIRGQDDSKWBWUCTYVCCBIOEQKGUJOPCOZTWQIDNTRYHBEADMPGJACWQYDFBXTBHXBIDRJSXKZLHTYFGURQXPACZNWHVQMZPNJFKZWKSPMUBGRMMA");
    msg.attributes.push_back(tmp_msg_0);

    try
    {
      Utils::ByteBuffer bfr;
      IMC::Packet::serialize(&msg, bfr);
      IMC::Message* msg_d = IMC::Packet::deserialize(bfr.getBuffer(), bfr.getSize());
      test.boolean("TrexToken #2", msg == *msg_d);
      delete msg_d;
    }
    catch (IMC::InvalidMessageSize& e)
    {
      (void)e;
      test.boolean("msg #2", msg.getSerializationSize() > DUNE_IMC_CONST_MAX_SIZE);
    }
  }

  {
    IMC::TrexPlan msg;
    msg.setTimeStamp(0.8192843960063856);
    msg.setSource(36318U);
    msg.setSourceEntity(150U);
    msg.setDestination(53081U);
    msg.setDestinationEntity(62U);
    msg.reactor.assign("DOQTNFWZOWQBFBJXUVUFSKHVAGDGSELVFWFQEBAZKRUNNRERJKSYSEYHYIJCAXRQWDDMPDXRBNPUNWVTJRNLNCOPAKIUZIDGTQSQTCPTHZVVMVUSMXJHXFNCOMZXOALPEBXQTUZWFFYGMOKXILGZZRGPOPVEPLCOHZUEWLYEQBWKVAWDJAOCIKHTABGJIWIIVBRJGHILXS");

    try
    {
      Utils::ByteBuffer bfr;
      IMC::Packet::serialize(&msg, bfr);
      IMC::Message* msg_d = IMC::Packet::deserialize(bfr.getBuffer(), bfr.getSize());
      test.boolean("TrexPlan #0", msg == *msg_d);
      delete msg_d;
    }
    catch (IMC::InvalidMessageSize& e)
    {
      (void)e;
      test.boolean("msg #0", msg.getSerializationSize() > DUNE_IMC_CONST_MAX_SIZE);
    }
  }

  {
    IMC::TrexPlan msg;
    msg.setTimeStamp(0.5220209758024995);
    msg.setSource(35430U);
    msg.setSourceEntity(22U);
    msg.setDestination(47542U);
    msg.setDestinationEntity(119U);
    msg.reactor.assign("QLVQHJXTWNXIHRDBJLPXZMLFSGFRPKKFRKDGJVSVBXPZHOBPXRUTFMWXYBWOLLSRNZYGMGTEEVRZOXASKISJMBXOEUXRDPELFKCRYYNPOUQOPVDMCCIDGUWUHMBSUEEGPRACHDZFFQYYMLIKGCGADBTNTFQAQWUNZZCDCJQLY");
    IMC::TrexToken tmp_msg_0;
    tmp_msg_0.timeline.assign("XXMWJZGXVTYQBKMPPSUULCDLGYNORFOHQUHWKTAZNJTDKWEYLHDOEMFUZOPBCEMVOXSBYQOLVKNYEJDGXHYWKCNHRLFXDTAWTVASDNBPFAXYBDTHMFVERJDVI");
    tmp_msg_0.predicate.assign("SOMKTEAELSXVMSLGXNWJUJYSOMREEQELOHYNEUODQRRVYOYMMUQICLLFHQPGFWEOCZYSDGNYOMHIGETKJFWDGSPMTWSOFTVKXZMICRZQBNPJIJBUEDTZLXTFAABKSUTJJRIVTNMDLPUFQYCWZLSEHFVKCCRCXJGFBDZVHSXRYIKKNWQNCAHRTGWDBJLXDGAUQYAKVMOHHVPIODP");
    msg.tokens.push_back(tmp_msg_0);

    try
    {
      Utils::ByteBuffer bfr;
      IMC::Packet::serialize(&msg, bfr);
      IMC::Message* msg_d = IMC::Packet::deserialize(bfr.getBuffer(), bfr.getSize());
      test.boolean("TrexPlan #1", msg == *msg_d);
      delete msg_d;
    }
    catch (IMC::InvalidMessageSize& e)
    {
      (void)e;
      test.boolean("msg #1", msg.getSerializationSize() > DUNE_IMC_CONST_MAX_SIZE);
    }
  }

  {
    IMC::TrexPlan msg;
    msg.setTimeStamp(0.31722911147837607);
    msg.setSource(14007U);
    msg.setSourceEntity(152U);
    msg.setDestination(8504U);
    msg.setDestinationEntity(201U);
    msg.reactor.assign("WKIRFWSOODQALDJYVADQPIDKEXFZBWXEUCREONIZXBIXLBSUTVNSRUNJMAMZG");
    IMC::TrexToken tmp_msg_0;
    tmp_msg_0.timeline.assign("IZGQDOGEQRYFNYLUYVNQKTRKDSINYARFDYIMDGUKZPYGPEELJPSATQYLVJCRMRJLXBANNPUOATHWXMFBABHWCKIVQWHXCSAHNPYLOWGHFLVBBSZWJOSYFEPLZQNXAOUYMCBUSGXXNGVJKVEDMJFINRRSDETXDFKOZXKMPHMPZVWRQVDEVJZUGLMCOOAFIBINTHJUWKXUTCJULIGBCPFQRAUEDOKOIMCSRWTKVJCDSTA");
    tmp_msg_0.predicate.assign("NFQSWEMWTZIKVVAQICUCQXAIHDLHGRJPYCICFAJGDDWHDFIYSBJFLE");
    msg.tokens.push_back(tmp_msg_0);

    try
    {
      Utils::ByteBuffer bfr;
      IMC::Packet::serialize(&msg, bfr);
      IMC::Message* msg_d = IMC::Packet::deserialize(bfr.getBuffer(), bfr.getSize());
      test.boolean("TrexPlan #2", msg == *msg_d);
      delete msg_d;
    }
    catch (IMC::InvalidMessageSize& e)
    {
      (void)e;
      test.boolean("msg #2", msg.getSerializationSize() > DUNE_IMC_CONST_MAX_SIZE);
    }
  }

  {
    IMC::Event msg;
    msg.setTimeStamp(0.761446313249633);
    msg.setSource(35461U);
    msg.setSourceEntity(250U);
    msg.setDestination(46218U);
    msg.setDestinationEntity(175U);
    msg.topic.assign("CFPHSGAEZFMTWXBYLDCMINMRKCQHFDVARWFULJTUKAFUULUJXZXBCRLNASRSYHSEUOHNOJNITHIJQTYGQVXAPPHSYTALEIEEDTEWZIJIDLYRJEFLKPVTCNNNMWQJSUUPVVJQRTYPNBORWBZLMUEGSVBVOCMDPQOOYQBJCYHKX");
    msg.data.assign("OKKFTFKHJNCEZYDMZMOLPRBTRYRSEEAVEPYQCRAKUVWQZKGMGJIFZZNNEAUXNVJOFWMQNLEEDCYWSRMUJMBOHQMBQPCWKMQTDNCHDXFOXYCJGDIWBDUOKBGLXDGKHFFQBWNZVTVKLSPJDGCNZTABSEVAHITCCIUAJYAKVIIZYXPNUTBSCSMLHFWL");

    try
    {
      Utils::ByteBuffer bfr;
      IMC::Packet::serialize(&msg, bfr);
      IMC::Message* msg_d = IMC::Packet::deserialize(bfr.getBuffer(), bfr.getSize());
      test.boolean("Event #0", msg == *msg_d);
      delete msg_d;
    }
    catch (IMC::InvalidMessageSize& e)
    {
      (void)e;
      test.boolean("msg #0", msg.getSerializationSize() > DUNE_IMC_CONST_MAX_SIZE);
    }
  }

  {
    IMC::Event msg;
    msg.setTimeStamp(0.3056492192763227);
    msg.setSource(25111U);
    msg.setSourceEntity(200U);
    msg.setDestination(35588U);
    msg.setDestinationEntity(82U);
    msg.topic.assign("OWMLKBBMQTVWXGDLZIIDVXTQFTRMWYLPKDMMGEDTUDQLYWTWRXAEPUTJ");
    msg.data.assign("FMKSCSIDSICKYQXYVNHNFKQDRXUPUTVKWUMWCQHSXORGLJXBGGJBLUTOKTIHIJEYCUBICNVFLWOZLYIIEBRQZRACWXMVNRGGEZKUPMPABOMTODCRTVNLIKSVOWAWHKQLYHDPAIBHXAEOWKFMWNZKXHOINJHFDUMHFUBAOBJQLQLPRZDSAAEMEZUZGDFUSQETSZHEPBNVQXSPAJGMYJLYGBTTRECJGYJJDVNQF");

    try
    {
      Utils::ByteBuffer bfr;
      IMC::Packet::serialize(&msg, bfr);
      IMC::Message* msg_d = IMC::Packet::deserialize(bfr.getBuffer(), bfr.getSize());
      test.boolean("Event #1", msg == *msg_d);
      delete msg_d;
    }
    catch (IMC::InvalidMessageSize& e)
    {
      (void)e;
      test.boolean("msg #1", msg.getSerializationSize() > DUNE_IMC_CONST_MAX_SIZE);
    }
  }

  {
    IMC::Event msg;
    msg.setTimeStamp(0.48700942466261343);
    msg.setSource(6186U);
    msg.setSourceEntity(20U);
    msg.setDestination(36545U);
    msg.setDestinationEntity(155U);
    msg.topic.assign("TJGWSDHUFJRDKCKEWWNGPUIHEFLUAKYENXZLRQAWVLPRFYPAVYOMPQXELNHVOHILBMUCATFWXVDGOHIQDYXZSWRJLXEZENBBCIZRZRJQKOMHPSQXOAYDYXSYRISEPDUHGKQPYSUSIPNBLJRJDMJXJTFYVRHGLQNRYZHTIGPWXJ");
    msg.data.assign("ORYBLXBRJGNMVQXUKCRXIFEQPSXHAHHWDXHNKAZLLKCDWODJKZLBMUJZC");

    try
    {
      Utils::ByteBuffer bfr;
      IMC::Packet::serialize(&msg, bfr);
      IMC::Message* msg_d = IMC::Packet::deserialize(bfr.getBuffer(), bfr.getSize());
      test.boolean("Event #2", msg == *msg_d);
      delete msg_d;
    }
    catch (IMC::InvalidMessageSize& e)
    {
      (void)e;
      test.boolean("msg #2", msg.getSerializationSize() > DUNE_IMC_CONST_MAX_SIZE);
    }
  }

  {
    IMC::CompressedImage msg;
    msg.setTimeStamp(0.46222002361198766);
    msg.setSource(10841U);
    msg.setSourceEntity(223U);
    msg.setDestination(42238U);
    msg.setDestinationEntity(213U);
    msg.frameid = 9U;
    const signed char tmp_msg_0[] = {-80, -2, -34, 16, -40, 93, -114, 49, -75, 104, -124, -38, 117, -37, 84, 46, 5, 112, 44, -83, -13, -12, 94, 121, -93, -75, -47, 0, -98, 32, -123, 15, 99, -10, -90, -9, -23, -114, -107, 47, -85, -121, 14, -120, -125, 41, -91, -62, -82, -29, 98, -104, -121, -119, -103, -21, 102, -77, 122, 88, 49, 86, 100, -84, 98, -31, -108, 103, -40, 69, 122, 3, -93, -65, -87, -117, 125, 123, -63, -58, 100, 108, -103, 26, 125, 107, -102, 70, -31, -74, -70, 126, 17, 71, -21, -19, -30, 9, 102, -14, -72, -125, -70, -66, 47, 105, 99, -76, 57, -88, -56, 12, 31, -54, 121, -81, -85, -24};
    msg.data.assign(tmp_msg_0, tmp_msg_0 + sizeof(tmp_msg_0));

    try
    {
      Utils::ByteBuffer bfr;
      IMC::Packet::serialize(&msg, bfr);
      IMC::Message* msg_d = IMC::Packet::deserialize(bfr.getBuffer(), bfr.getSize());
      test.boolean("CompressedImage #0", msg == *msg_d);
      delete msg_d;
    }
    catch (IMC::InvalidMessageSize& e)
    {
      (void)e;
      test.boolean("msg #0", msg.getSerializationSize() > DUNE_IMC_CONST_MAX_SIZE);
    }
  }

  {
    IMC::CompressedImage msg;
    msg.setTimeStamp(0.4614791195114044);
    msg.setSource(22122U);
    msg.setSourceEntity(107U);
    msg.setDestination(36060U);
    msg.setDestinationEntity(102U);
    msg.frameid = 246U;
    const signed char tmp_msg_0[] = {-39, -62, 89, -26, -69, 47, 40, 75, -5, -49, 124, 89, 62, 4, 53, -71, 34, -20, -69, -54, 69, -34, 20, -69, -111, 43, -109, 49, 42, 66, -67, 40, 39, 95, 33, 105, -101, -58, 95, 113, 80, -112, -62, 112, -7, 5, -57, 57, -125, 71, 68, -35, 122, -54, 19, -36, -68, 49, 82, 112, -39, -77, 19, 107, -108, -92, -40, -116, -11, -91, -82, -35, 111, -92, 121, 109, 102, 68, 10, -123, 83, -12, -91, -84, 5, 87, 54, -95, -9, -22, 76, 8, 105, -25, -87, -3, -53, -27, -90, 28, -8, 18, 42, 70, 124, -112, 29, 34, 90, -77, 29, -59, -60, -127, 45, 45, 60, -77, 44, -58, -57, 7, -10, 4, 105, 61, 16, 59, -15, 94, -108, 37, -13, -17, -100, 40, 125, 59, -101, -16, -7, -25, 105, -125, 20, 11, 103, 10, 87, 98, 88, 72, -99, 52, -98, -27, -77, -56, -97, 106, -66, 90, 67, -81, -16, -104, 33};
    msg.data.assign(tmp_msg_0, tmp_msg_0 + sizeof(tmp_msg_0));

    try
    {
      Utils::ByteBuffer bfr;
      IMC::Packet::serialize(&msg, bfr);
      IMC::Message* msg_d = IMC::Packet::deserialize(bfr.getBuffer(), bfr.getSize());
      test.boolean("CompressedImage #1", msg == *msg_d);
      delete msg_d;
    }
    catch (IMC::InvalidMessageSize& e)
    {
      (void)e;
      test.boolean("msg #1", msg.getSerializationSize() > DUNE_IMC_CONST_MAX_SIZE);
    }
  }

  {
    IMC::CompressedImage msg;
    msg.setTimeStamp(0.0669739602580749);
    msg.setSource(65150U);
    msg.setSourceEntity(123U);
    msg.setDestination(16196U);
    msg.setDestinationEntity(155U);
    msg.frameid = 129U;
    const signed char tmp_msg_0[] = {104, 33, 108, 60, -76, -124, -105, -31, -66, -122, 104};
    msg.data.assign(tmp_msg_0, tmp_msg_0 + sizeof(tmp_msg_0));

    try
    {
      Utils::ByteBuffer bfr;
      IMC::Packet::serialize(&msg, bfr);
      IMC::Message* msg_d = IMC::Packet::deserialize(bfr.getBuffer(), bfr.getSize());
      test.boolean("CompressedImage #2", msg == *msg_d);
      delete msg_d;
    }
    catch (IMC::InvalidMessageSize& e)
    {
      (void)e;
      test.boolean("msg #2", msg.getSerializationSize() > DUNE_IMC_CONST_MAX_SIZE);
    }
  }

  {
    IMC::ImageTxSettings msg;
    msg.setTimeStamp(0.7868192171437876);
    msg.setSource(5483U);
    msg.setSourceEntity(218U);
    msg.setDestination(53343U);
    msg.setDestinationEntity(91U);
    msg.fps = 70U;
    msg.quality = 52U;
    msg.reps = 66U;
    msg.tsize = 217U;

    try
    {
      Utils::ByteBuffer bfr;
      IMC::Packet::serialize(&msg, bfr);
      IMC::Message* msg_d = IMC::Packet::deserialize(bfr.getBuffer(), bfr.getSize());
      test.boolean("ImageTxSettings #0", msg == *msg_d);
      delete msg_d;
    }
    catch (IMC::InvalidMessageSize& e)
    {
      (void)e;
      test.boolean("msg #0", msg.getSerializationSize() > DUNE_IMC_CONST_MAX_SIZE);
    }
  }

  {
    IMC::ImageTxSettings msg;
    msg.setTimeStamp(0.536480928585881);
    msg.setSource(45895U);
    msg.setSourceEntity(7U);
    msg.setDestination(59936U);
    msg.setDestinationEntity(25U);
    msg.fps = 222U;
    msg.quality = 229U;
    msg.reps = 160U;
    msg.tsize = 161U;

    try
    {
      Utils::ByteBuffer bfr;
      IMC::Packet::serialize(&msg, bfr);
      IMC::Message* msg_d = IMC::Packet::deserialize(bfr.getBuffer(), bfr.getSize());
      test.boolean("ImageTxSettings #1", msg == *msg_d);
      delete msg_d;
    }
    catch (IMC::InvalidMessageSize& e)
    {
      (void)e;
      test.boolean("msg #1", msg.getSerializationSize() > DUNE_IMC_CONST_MAX_SIZE);
    }
  }

  {
    IMC::ImageTxSettings msg;
    msg.setTimeStamp(0.23680662099699057);
    msg.setSource(57450U);
    msg.setSourceEntity(178U);
    msg.setDestination(50493U);
    msg.setDestinationEntity(212U);
    msg.fps = 6U;
    msg.quality = 158U;
    msg.reps = 72U;
    msg.tsize = 199U;

    try
    {
      Utils::ByteBuffer bfr;
      IMC::Packet::serialize(&msg, bfr);
      IMC::Message* msg_d = IMC::Packet::deserialize(bfr.getBuffer(), bfr.getSize());
      test.boolean("ImageTxSettings #2", msg == *msg_d);
      delete msg_d;
    }
    catch (IMC::InvalidMessageSize& e)
    {
      (void)e;
      test.boolean("msg #2", msg.getSerializationSize() > DUNE_IMC_CONST_MAX_SIZE);
    }
  }

  {
    IMC::RemoteState msg;
    msg.setTimeStamp(0.2790672434938153);
    msg.setSource(39399U);
    msg.setSourceEntity(153U);
    msg.setDestination(48629U);
    msg.setDestinationEntity(124U);
    msg.lat = 0.7972997287371679;
    msg.lon = 0.269051069657828;
    msg.depth = 227U;
    msg.speed = 0.18699712185493267;
    msg.psi = 0.746937314068316;

    try
    {
      Utils::ByteBuffer bfr;
      IMC::Packet::serialize(&msg, bfr);
      IMC::Message* msg_d = IMC::Packet::deserialize(bfr.getBuffer(), bfr.getSize());
      test.boolean("RemoteState #0", msg == *msg_d);
      delete msg_d;
    }
    catch (IMC::InvalidMessageSize& e)
    {
      (void)e;
      test.boolean("msg #0", msg.getSerializationSize() > DUNE_IMC_CONST_MAX_SIZE);
    }
  }

  {
    IMC::RemoteState msg;
    msg.setTimeStamp(0.8423563695666906);
    msg.setSource(9177U);
    msg.setSourceEntity(142U);
    msg.setDestination(43862U);
    msg.setDestinationEntity(254U);
    msg.lat = 0.6000527269572858;
    msg.lon = 0.6348826466190339;
    msg.depth = 242U;
    msg.speed = 0.22432563964719365;
    msg.psi = 0.15571356697170946;

    try
    {
      Utils::ByteBuffer bfr;
      IMC::Packet::serialize(&msg, bfr);
      IMC::Message* msg_d = IMC::Packet::deserialize(bfr.getBuffer(), bfr.getSize());
      test.boolean("RemoteState #1", msg == *msg_d);
      delete msg_d;
    }
    catch (IMC::InvalidMessageSize& e)
    {
      (void)e;
      test.boolean("msg #1", msg.getSerializationSize() > DUNE_IMC_CONST_MAX_SIZE);
    }
  }

  {
    IMC::RemoteState msg;
    msg.setTimeStamp(0.24861600889519953);
    msg.setSource(50374U);
    msg.setSourceEntity(27U);
    msg.setDestination(3576U);
    msg.setDestinationEntity(223U);
    msg.lat = 0.7249986201882573;
    msg.lon = 0.20106240681511833;
    msg.depth = 6U;
    msg.speed = 0.43221612794234987;
    msg.psi = 0.8103984045870389;

    try
    {
      Utils::ByteBuffer bfr;
      IMC::Packet::serialize(&msg, bfr);
      IMC::Message* msg_d = IMC::Packet::deserialize(bfr.getBuffer(), bfr.getSize());
      test.boolean("RemoteState #2", msg == *msg_d);
      delete msg_d;
    }
    catch (IMC::InvalidMessageSize& e)
    {
      (void)e;
      test.boolean("msg #2", msg.getSerializationSize() > DUNE_IMC_CONST_MAX_SIZE);
    }
  }

  {
    IMC::Target msg;
    msg.setTimeStamp(0.7020520642719434);
    msg.setSource(39295U);
    msg.setSourceEntity(51U);
    msg.setDestination(58436U);
    msg.setDestinationEntity(175U);
    msg.label.assign("APRGPOXIENKGPOSUNWJJZDNIWWHDUEZCYOFUUASJEKLCLSRVUVDSDKXJRJKJXILTKWYGTGRWRRVMLPFGAOYZGBNAMLDFBJUXITYLOHYTMCNQZHQQ");
    msg.lat = 0.17539879598473362;
    msg.lon = 0.34890982482124033;
    msg.z = 0.6538017482645737;
    msg.z_units = 196U;
    msg.cog = 0.7255179527303269;
    msg.sog = 0.7865623848972985;

    try
    {
      Utils::ByteBuffer bfr;
      IMC::Packet::serialize(&msg, bfr);
      IMC::Message* msg_d = IMC::Packet::deserialize(bfr.getBuffer(), bfr.getSize());
      test.boolean("Target #0", msg == *msg_d);
      delete msg_d;
    }
    catch (IMC::InvalidMessageSize& e)
    {
      (void)e;
      test.boolean("msg #0", msg.getSerializationSize() > DUNE_IMC_CONST_MAX_SIZE);
    }
  }

  {
    IMC::Target msg;
    msg.setTimeStamp(0.6128545760022545);
    msg.setSource(428U);
    msg.setSourceEntity(228U);
    msg.setDestination(47013U);
    msg.setDestinationEntity(241U);
    msg.label.assign("KNANONONOZTBVSGBBBCKRMDYCLBQQXRMFRJGBOIGUTDMBKFUPHTRXP");
    msg.lat = 0.24539904605575458;
    msg.lon = 0.14946873962792706;
    msg.z = 0.9689857848597426;
    msg.z_units = 179U;
    msg.cog = 0.46061928210754033;
    msg.sog = 0.3010545370805079;

    try
    {
      Utils::ByteBuffer bfr;
      IMC::Packet::serialize(&msg, bfr);
      IMC::Message* msg_d = IMC::Packet::deserialize(bfr.getBuffer(), bfr.getSize());
      test.boolean("Target #1", msg == *msg_d);
      delete msg_d;
    }
    catch (IMC::InvalidMessageSize& e)
    {
      (void)e;
      test.boolean("msg #1", msg.getSerializationSize() > DUNE_IMC_CONST_MAX_SIZE);
    }
  }

  {
    IMC::Target msg;
    msg.setTimeStamp(0.9862618056522829);
    msg.setSource(25154U);
    msg.setSourceEntity(27U);
    msg.setDestination(40507U);
    msg.setDestinationEntity(63U);
    msg.label.assign("YOAWHKADWMKCGVVDURJBTPHFWWEKGVVOYMYRUJQRXVJTLWPDJFKSDZKTRCWSYTPYUCNXUBMAVSJDRYEOIYMKDGBERLAPEFLSXVFQJAEOQXRBAHRZHTCKBCAWMPLRGZXNHVOQKPZPEQUNSXTHBLLKTUDVITIYUFQSNUIZJVTIRAMEJWG");
    msg.lat = 0.3075397299402113;
    msg.lon = 0.004134235643941886;
    msg.z = 0.9259212532310629;
    msg.z_units = 32U;
    msg.cog = 0.010875602872312373;
    msg.sog = 0.6373105913035428;

    try
    {
      Utils::ByteBuffer bfr;
      IMC::Packet::serialize(&msg, bfr);
      IMC::Message* msg_d = IMC::Packet::deserialize(bfr.getBuffer(), bfr.getSize());
      test.boolean("Target #2", msg == *msg_d);
      delete msg_d;
    }
    catch (IMC::InvalidMessageSize& e)
    {
      (void)e;
      test.boolean("msg #2", msg.getSerializationSize() > DUNE_IMC_CONST_MAX_SIZE);
    }
  }

  {
    IMC::EntityParameter msg;
    msg.setTimeStamp(0.5640513778847646);
    msg.setSource(33689U);
    msg.setSourceEntity(183U);
    msg.setDestination(62076U);
    msg.setDestinationEntity(128U);
    msg.name.assign("UIPXGYNTDLFJTXGXTZUDCGNKGYIEIGJQDTVNOCNNRJCXAKWUYXDAIBLCSOOAUSRSJVLGSHMEZXRMUBCWSNOQMQPTUQYHORMZUTLLIBNZCYRVGMZFVVEIIYTVCEGRHCNHECAOSLL");
    msg.value.assign("UMGHABGTPDUKCSQSGVLFJNUSMTRYMKDSACLMMKJPLDDBNTMVDJGECWQYCHFUPHZFZIJ");

    try
    {
      Utils::ByteBuffer bfr;
      IMC::Packet::serialize(&msg, bfr);
      IMC::Message* msg_d = IMC::Packet::deserialize(bfr.getBuffer(), bfr.getSize());
      test.boolean("EntityParameter #0", msg == *msg_d);
      delete msg_d;
    }
    catch (IMC::InvalidMessageSize& e)
    {
      (void)e;
      test.boolean("msg #0", msg.getSerializationSize() > DUNE_IMC_CONST_MAX_SIZE);
    }
  }

  {
    IMC::EntityParameter msg;
    msg.setTimeStamp(0.37239830784762873);
    msg.setSource(40821U);
    msg.setSourceEntity(154U);
    msg.setDestination(9945U);
    msg.setDestinationEntity(183U);
    msg.name.assign("HKJUKCZPMWMDSIGONQETDISWOBQFPWNOGEDSQRMWZSEEAYYJJTMVIQCEOUAYFTHWGECMGD");
    msg.value.assign("OAHJZFRWPPUQWDOXKXQ");

    try
    {
      Utils::ByteBuffer bfr;
      IMC::Packet::serialize(&msg, bfr);
      IMC::Message* msg_d = IMC::Packet::deserialize(bfr.getBuffer(), bfr.getSize());
      test.boolean("EntityParameter #1", msg == *msg_d);
      delete msg_d;
    }
    catch (IMC::InvalidMessageSize& e)
    {
      (void)e;
      test.boolean("msg #1", msg.getSerializationSize() > DUNE_IMC_CONST_MAX_SIZE);
    }
  }

  {
    IMC::EntityParameter msg;
    msg.setTimeStamp(0.03635632832517488);
    msg.setSource(78U);
    msg.setSourceEntity(147U);
    msg.setDestination(51538U);
    msg.setDestinationEntity(242U);
    msg.name.assign("SCZPERUQADVSXXLT");
    msg.value.assign("QWMFZUNPBVBULKTKIZPKOVCBVVECLCXJZRQADTWPUGTNABYZOMOCJONZFFXNBDADHYQKPLGYMXRJQZULWWW");

    try
    {
      Utils::ByteBuffer bfr;
      IMC::Packet::serialize(&msg, bfr);
      IMC::Message* msg_d = IMC::Packet::deserialize(bfr.getBuffer(), bfr.getSize());
      test.boolean("EntityParameter #2", msg == *msg_d);
      delete msg_d;
    }
    catch (IMC::InvalidMessageSize& e)
    {
      (void)e;
      test.boolean("msg #2", msg.getSerializationSize() > DUNE_IMC_CONST_MAX_SIZE);
    }
  }

  {
    IMC::EntityParameters msg;
    msg.setTimeStamp(0.4181332507498735);
    msg.setSource(62838U);
    msg.setSourceEntity(120U);
    msg.setDestination(29452U);
    msg.setDestinationEntity(106U);
    msg.name.assign("YRYTMKOACZYAMVBDJCWEMBELLRWAWRROQALEFQKWPBAROOQRPFATUFZWPZTVVDZEGIUYPVRJQDGKVGLSPLINP");
    IMC::EntityParameter tmp_msg_0;
    tmp_msg_0.name.assign("GFGFRHPAVLNMRUASPZPZDVWXLVLLJDVPOVJECJNEYPTMKJDFUOJUCHHSWKTDYZMYEPFLBMKLLVNSRKOYAAOIEUHQTOSRPHZXCCHMUXQOYN");
    tmp_msg_0.value.assign("BZGNRGKXIVAAJFN");
    msg.params.push_back(tmp_msg_0);

    try
    {
      Utils::ByteBuffer bfr;
      IMC::Packet::serialize(&msg, bfr);
      IMC::Message* msg_d = IMC::Packet::deserialize(bfr.getBuffer(), bfr.getSize());
      test.boolean("EntityParameters #0", msg == *msg_d);
      delete msg_d;
    }
    catch (IMC::InvalidMessageSize& e)
    {
      (void)e;
      test.boolean("msg #0", msg.getSerializationSize() > DUNE_IMC_CONST_MAX_SIZE);
    }
  }

  {
    IMC::EntityParameters msg;
    msg.setTimeStamp(0.2780789318161505);
    msg.setSource(61713U);
    msg.setSourceEntity(67U);
    msg.setDestination(18222U);
    msg.setDestinationEntity(76U);
    msg.name.assign("NNEPUHRAQUMUNZWLXHYQFEOIPTFRZGFWHTDXLUMBHWKCPTRSVMOXJEVAZAIBGYVMQZGVDULBHYJRJU");
    IMC::EntityParameter tmp_msg_0;
    tmp_msg_0.name.assign("GVVPTNJFZHHGMXXPTFLPZFAKOPJJQNRIVYZKHEUXSOMBWFMVGNZQHYFIQCZEMLQOVBPHRWKKOLOWUSLEKHQIVDQMJGHIRLESDZXCCWYOVQBBNANEXUTYNLTWQEOEAXOMOQSXTCIBPPGOCBWRFKYRSWSNYMUDLFIERMFAGVCZZAVREHCZLWCJLDRDYRTJGSKQGJSTUUJHXYWG");
    tmp_msg_0.value.assign("ZEYJANWFQYBQRBYNENNOKBVFLJWYQVSNDETHOGPFUUGISARMDXHJVFSUQUYXVIGXLTUKDOJUAFTNGDROWBRLBEFKWXOWHBAXFLSSCMKEOSIUVPPWBPFWOXIPGMOVKRMEJJPCTYJHCHIKMKKHDQXVCNALCPZDKIVZDCVCTUHAKNWLXPZMATQADFXSSXRAIQZGY");
    msg.params.push_back(tmp_msg_0);

    try
    {
      Utils::ByteBuffer bfr;
      IMC::Packet::serialize(&msg, bfr);
      IMC::Message* msg_d = IMC::Packet::deserialize(bfr.getBuffer(), bfr.getSize());
      test.boolean("EntityParameters #1", msg == *msg_d);
      delete msg_d;
    }
    catch (IMC::InvalidMessageSize& e)
    {
      (void)e;
      test.boolean("msg #1", msg.getSerializationSize() > DUNE_IMC_CONST_MAX_SIZE);
    }
  }

  {
    IMC::EntityParameters msg;
    msg.setTimeStamp(0.871954939310962);
    msg.setSource(37399U);
    msg.setSourceEntity(209U);
    msg.setDestination(40085U);
    msg.setDestinationEntity(115U);
    msg.name.assign("UPWLMCJRKLLAKXSJYAGFNEPGJZFSWKTFEGUXDMTTWNMWZMJHDLYHEYZQJNOQSWXIBSPOVBONGYBFPVHRACRVLOWZUSUBAIVHBXGOBLMNHMXENFCEVONYCFWEDIJZDQG");
    IMC::EntityParameter tmp_msg_0;
    tmp_msg_0.name.assign("RAMJZTEECUGVHBXUMPSAJXLFCLLTVFKATZNKSBUFECNEAPIDBJZQKOTZLJGECFMJDOSDVTRUYNRQRAAVSZTJWRMRWZKECOCZZGUSQQKRYBLYUFNHDTJHKYJGWIKUPYIEKBSAEYRSGADAWVYLMDPMNTYSQOEQNPMSHOQLROPFGIPITBJXUUGWBCGFVXIFPLXZOCAXIOPCWKRXWLTKHNHLNPBNZMQUVQB");
    tmp_msg_0.value.assign("ZDYIXGETQZVXWUJACOFUPTYRVUBXOUZIWYHDWBFJRAJPWNKBOEZDSLLTSTJUUMZYWWMWDLCDOAIFSHNWJWTNMQQOSKMIMEAIIRZLYAGZFKBHBSJJKGUMHVZSOKENJSVXIJXAILQCTTXYEYNMLHMVYJPCAGFEGHLLSAXAFQXLHRNDCSQHHVPUURFFRTKMDEDOBVMLNANNOKGHGGTXQBCVCBZWCIE");
    msg.params.push_back(tmp_msg_0);

    try
    {
      Utils::ByteBuffer bfr;
      IMC::Packet::serialize(&msg, bfr);
      IMC::Message* msg_d = IMC::Packet::deserialize(bfr.getBuffer(), bfr.getSize());
      test.boolean("EntityParameters #2", msg == *msg_d);
      delete msg_d;
    }
    catch (IMC::InvalidMessageSize& e)
    {
      (void)e;
      test.boolean("msg #2", msg.getSerializationSize() > DUNE_IMC_CONST_MAX_SIZE);
    }
  }

  {
    IMC::QueryEntityParameters msg;
    msg.setTimeStamp(0.6042497380591059);
    msg.setSource(6785U);
    msg.setSourceEntity(27U);
    msg.setDestination(30275U);
    msg.setDestinationEntity(230U);
    msg.name.assign("UVEGCTFMTHSWPSNMXEGHJLHOZITQSNDUBFZKFSFFSWUFOFHCMXSWNMZMHKGZWUUZCBFDBOVXZELPJHKDXWNVQCKRSVJYLAVTIBDZNOYMCYYIWAHPBUXXUQDEZGJCAKZPPSJNMTVTQJDCJYNDQRTQPILEAEIELRAIILUYSNGIXDG");
    msg.visibility.assign("IZIWSBFJOPTGYDOTSNLUHJVGOCERQRBKKXMDKVQTHXTEHVSMOZMMGDWGRXDKYTYIEUENFCZDYIULDFLAWEZGTDHYHAKILGFFPMBLQCGQPTTWOZBBTNZYMSYEBLKDJOVFJMGXIDVZPJWRHQEBIQWWJOXLIPJYQNJBAXLANSVJQWKCOSACVMFYEPKTMZCARJERSUXBGFUAHCRNLCXYAKUUIZWPHSDCPOSBERFKIPNANGM");
    msg.scope.assign("IUDMPPIHWTJALGTVQITPORUQZBHIXWZCZBNOCJQXLOFHNMVLSQREGEBWWVYYPYYUVWBCUHEULFNWAKCSGAIWFKDAORHSHLLALLWQGFAZBSZQTRICTXNFKMFAZPPFZUXRHXMOIADDO");

    try
    {
      Utils::ByteBuffer bfr;
      IMC::Packet::serialize(&msg, bfr);
      IMC::Message* msg_d = IMC::Packet::deserialize(bfr.getBuffer(), bfr.getSize());
      test.boolean("QueryEntityParameters #0", msg == *msg_d);
      delete msg_d;
    }
    catch (IMC::InvalidMessageSize& e)
    {
      (void)e;
      test.boolean("msg #0", msg.getSerializationSize() > DUNE_IMC_CONST_MAX_SIZE);
    }
  }

  {
    IMC::QueryEntityParameters msg;
    msg.setTimeStamp(0.4236863727124759);
    msg.setSource(55217U);
    msg.setSourceEntity(70U);
    msg.setDestination(20229U);
    msg.setDestinationEntity(230U);
    msg.name.assign("XNSKJSTZOXPXESABRCKXCTJZGBWBZIVYQDRFEZUBJQQIAVCKKGZWZXJHOUXFKGFRDJSCKYRVSEMQCISCAKOMUESLTLBONIHVFPYXKTPFGOFGQOGXHPCKGUAARXVJLWUEIMMELADINNXFEYLHDMLPSBJJHYIRGKYNCDZPLOIUBHWGTYLVFWFUA");
    msg.visibility.assign("CDJLZKBDUTJFFQIUTJYOGINMULGBEHXSVEEZ");
    msg.scope.assign("HFJMXROVUXHKYYPWBDFIMABHCXZEKVKARQJLXZAQJKZBRODOCHZXVGHPCMQEJKDTQCTJOWIDTZDUNTLVPDYNLQMCMIQRZVOCEGUPFLIHUFANZBFAKUPIBHGYBGMGEWARLLVUYZW");

    try
    {
      Utils::ByteBuffer bfr;
      IMC::Packet::serialize(&msg, bfr);
      IMC::Message* msg_d = IMC::Packet::deserialize(bfr.getBuffer(), bfr.getSize());
      test.boolean("QueryEntityParameters #1", msg == *msg_d);
      delete msg_d;
    }
    catch (IMC::InvalidMessageSize& e)
    {
      (void)e;
      test.boolean("msg #1", msg.getSerializationSize() > DUNE_IMC_CONST_MAX_SIZE);
    }
  }

  {
    IMC::QueryEntityParameters msg;
    msg.setTimeStamp(0.2790293624666529);
    msg.setSource(25887U);
    msg.setSourceEntity(101U);
    msg.setDestination(12364U);
    msg.setDestinationEntity(29U);
    msg.name.assign("TBOCZGRBAVSCIHXQWMRZYIFDBWUVJGLPOLYIDXHQUMMGDYNQNRNGUQQPWYIMZKAXYEWHFGNNBTKTCVLJQHKFPRPBJQEKSPSSWOUZPSVFYWHCAALINXPVDEOGMVOUNBOSUEKWKIVBAJXGMLHOUNFPJJYJATTFYG");
    msg.visibility.assign("UOCQJOUSBIUWSCNBRSOIQZYWJNKXEXIMKEWQTLEFAVVEDTMTLYYYNUIARPTMPZXFHISWXJNOHYWJKDBLGGEIVSCGAJVOGJPKPUVOTTMDZESHUKDZXZFCNTGHYSAPAZXVCFQQDBMPSGLDSBRBQIFNPKXRGZLJTIKWXDPLYQMQHHXGYHYQUADGDJLRBVMOFAFCCWKNEOKNMCPTRIUOUJTLWLBMN");
    msg.scope.assign("XUIWTQXFXPSEDNFCMMGGTITRTBIGWPVQFEHRMQUKPZWWWJYAGENZFEJCOAJVXCAYEOBLSPJKUCGRWIQQHUKQZSBUNKYTJFSSIGFDRFKBLXEDPYLPHHXIUDOMZVAIRLCAWXNWKXRXZUHAZCEYJGRIGHCYNSVAVCLEBPMKLZSUAZWSJMIVBTYGNOJATBPOVLJBTDCBLHZWQLVMHRSXFVBDDHMRCPKYRQNNDOUYOPSKTJLDEIOOVZFQONDNHYFEMG");

    try
    {
      Utils::ByteBuffer bfr;
      IMC::Packet::serialize(&msg, bfr);
      IMC::Message* msg_d = IMC::Packet::deserialize(bfr.getBuffer(), bfr.getSize());
      test.boolean("QueryEntityParameters #2", msg == *msg_d);
      delete msg_d;
    }
    catch (IMC::InvalidMessageSize& e)
    {
      (void)e;
      test.boolean("msg #2", msg.getSerializationSize() > DUNE_IMC_CONST_MAX_SIZE);
    }
  }

  {
    IMC::SetEntityParameters msg;
    msg.setTimeStamp(0.7143398863711873);
    msg.setSource(24070U);
    msg.setSourceEntity(50U);
    msg.setDestination(34124U);
    msg.setDestinationEntity(143U);
    msg.name.assign("JHOTKCNAVPVYKFQOXNDSKPBXGSIJWYSTSBZXQKHUMBGVOBOETOCVQJSRWCHDDZVZGVXUFMWTLCIQUTXSCERMEFCKHQIIWXBRLLDWZLAXFVJHMLPNDDNFWIGWWPNRLEASBKZHFEAVFEFMFMRSQASDPQQLYJRKJNCYAUILXHDRPITVCZTTURWPJJKPZNLEUQCOBNXGACZNEOAGMBLBVRYMERKJIDTDZAIUUU");

    try
    {
      Utils::ByteBuffer bfr;
      IMC::Packet::serialize(&msg, bfr);
      IMC::Message* msg_d = IMC::Packet::deserialize(bfr.getBuffer(), bfr.getSize());
      test.boolean("SetEntityParameters #0", msg == *msg_d);
      delete msg_d;
    }
    catch (IMC::InvalidMessageSize& e)
    {
      (void)e;
      test.boolean("msg #0", msg.getSerializationSize() > DUNE_IMC_CONST_MAX_SIZE);
    }
  }

  {
    IMC::SetEntityParameters msg;
    msg.setTimeStamp(0.7842910673098641);
    msg.setSource(26276U);
    msg.setSourceEntity(158U);
    msg.setDestination(20834U);
    msg.setDestinationEntity(159U);
    msg.name.assign("HTQVAEMDDURYZLTUKSSAOLJSDCD");
    IMC::EntityParameter tmp_msg_0;
    tmp_msg_0.name.assign("OGGYRGJCALRMJOGXWBNXMXJOLUQKSNQHSZOTHQXUTPVSHMCGNMMVTUQLWKTPSURFEVWFZXKTKJKNZADCQQUBGTICAXWUOLQUHSSAHFNKLAXDYBHLPVWDMEEMGNPOBZNJLTXDABIDPRUHBMAWJREFRSLZJLSPFVDGSFHDKWUVWKCWFRNTCEWUVQYIBTIPAIYFKJOZECKSQRYVYGHPOEZ");
    tmp_msg_0.value.assign("GBWBKOPZFFY");
    msg.params.push_back(tmp_msg_0);

    try
    {
      Utils::ByteBuffer bfr;
      IMC::Packet::serialize(&msg, bfr);
      IMC::Message* msg_d = IMC::Packet::deserialize(bfr.getBuffer(), bfr.getSize());
      test.boolean("SetEntityParameters #1", msg == *msg_d);
      delete msg_d;
    }
    catch (IMC::InvalidMessageSize& e)
    {
      (void)e;
      test.boolean("msg #1", msg.getSerializationSize() > DUNE_IMC_CONST_MAX_SIZE);
    }
  }

  {
    IMC::SetEntityParameters msg;
    msg.setTimeStamp(0.6779835013747009);
    msg.setSource(31086U);
    msg.setSourceEntity(156U);
    msg.setDestination(11438U);
    msg.setDestinationEntity(138U);
    msg.name.assign("QBZPIEICNBLMDPKSFJGGTCXFCDMTFKTYRUPWEVEWLFPMSTSJLNSFYYXABQKHNZTAQBGIWQBGCGAWWRFFHYGDXTCZRIAYHQBVXICRRMKBENSXBPAIKFLWVKUODVLZFMPNNWVPZTQXNNQOJUCZXFZYCXRDKIIMVJWTQTXEJLCHGYMBRJEPLLORNUEWVKVUBSAVTUDDMJLEXZHUKAZSHIOZOAOJUAHSSEUOPJPKOCLVDGJES");
    IMC::EntityParameter tmp_msg_0;
    tmp_msg_0.name.assign("LGHTYJLWBPRBKUTLRTFZUKYBOLSZHMSLSXUZLMVAJWYQMRDERXPYEEHNQRZVDBEEWJWMCNEHIONOQJJWBCPDEUBDKMEQIOMKFKR");
    tmp_msg_0.value.assign("GMYHFGEXUPLCQSSBIBXECNKCDMFZLRLMRDMGCJYCNNIAIKXZTDYNLPTUFLWTDQEDNTEWXKLURTRMBBVBSAAAMCCUPXVZJIQIINUNFBJVPYSOHKZAVQFXVGFGOHWAMYKONJEHVYPVSHIEOLSDRGUWZREOWUGGBZUJZDQKCALHMNYJLJLIWFSROOUVMTYKWXQYQVKWZHJIPXNOQBCWPDTOUSZTRWJIFQVTHAM");
    msg.params.push_back(tmp_msg_0);

    try
    {
      Utils::ByteBuffer bfr;
      IMC::Packet::serialize(&msg, bfr);
      IMC::Message* msg_d = IMC::Packet::deserialize(bfr.getBuffer(), bfr.getSize());
      test.boolean("SetEntityParameters #2", msg == *msg_d);
      delete msg_d;
    }
    catch (IMC::InvalidMessageSize& e)
    {
      (void)e;
      test.boolean("msg #2", msg.getSerializationSize() > DUNE_IMC_CONST_MAX_SIZE);
    }
  }

  {
    IMC::SaveEntityParameters msg;
    msg.setTimeStamp(0.7541568816827118);
    msg.setSource(49466U);
    msg.setSourceEntity(148U);
    msg.setDestination(26037U);
    msg.setDestinationEntity(88U);
    msg.name.assign("OTKOXUQOLZVACVCVROERBKFUJRXN");

    try
    {
      Utils::ByteBuffer bfr;
      IMC::Packet::serialize(&msg, bfr);
      IMC::Message* msg_d = IMC::Packet::deserialize(bfr.getBuffer(), bfr.getSize());
      test.boolean("SaveEntityParameters #0", msg == *msg_d);
      delete msg_d;
    }
    catch (IMC::InvalidMessageSize& e)
    {
      (void)e;
      test.boolean("msg #0", msg.getSerializationSize() > DUNE_IMC_CONST_MAX_SIZE);
    }
  }

  {
    IMC::SaveEntityParameters msg;
    msg.setTimeStamp(0.4114048218403116);
    msg.setSource(53430U);
    msg.setSourceEntity(97U);
    msg.setDestination(21604U);
    msg.setDestinationEntity(45U);
    msg.name.assign("WGUWUOZHSYQJHAWHXLFNCNEGEVMZETTBVPPOMLZYIKBKAVYLVVZMYBUNDREHOAHMRGJMGDRYSPFWKNFDRHZQLGCGOUAJYUJJGQRIIBWFOFXFUNMMBCJXYBIRJDIBUFCLZNGTFUTDEYBTJCDRGWXAEVMFOWKUDOXLFE");

    try
    {
      Utils::ByteBuffer bfr;
      IMC::Packet::serialize(&msg, bfr);
      IMC::Message* msg_d = IMC::Packet::deserialize(bfr.getBuffer(), bfr.getSize());
      test.boolean("SaveEntityParameters #1", msg == *msg_d);
      delete msg_d;
    }
    catch (IMC::InvalidMessageSize& e)
    {
      (void)e;
      test.boolean("msg #1", msg.getSerializationSize() > DUNE_IMC_CONST_MAX_SIZE);
    }
  }

  {
    IMC::SaveEntityParameters msg;
    msg.setTimeStamp(0.36525911168077774);
    msg.setSource(59218U);
    msg.setSourceEntity(253U);
    msg.setDestination(14848U);
    msg.setDestinationEntity(186U);
    msg.name.assign("SQKUSJCXESAVAEABINOVXXAZWKYZNEHNIWBRZDAJYVMUJ");

    try
    {
      Utils::ByteBuffer bfr;
      IMC::Packet::serialize(&msg, bfr);
      IMC::Message* msg_d = IMC::Packet::deserialize(bfr.getBuffer(), bfr.getSize());
      test.boolean("SaveEntityParameters #2", msg == *msg_d);
      delete msg_d;
    }
    catch (IMC::InvalidMessageSize& e)
    {
      (void)e;
      test.boolean("msg #2", msg.getSerializationSize() > DUNE_IMC_CONST_MAX_SIZE);
    }
  }

  {
    IMC::CreateSession msg;
    msg.setTimeStamp(0.8158589157646767);
    msg.setSource(38456U);
    msg.setSourceEntity(246U);
    msg.setDestination(26582U);
    msg.setDestinationEntity(51U);
    msg.timeout = 1252364710U;

    try
    {
      Utils::ByteBuffer bfr;
      IMC::Packet::serialize(&msg, bfr);
      IMC::Message* msg_d = IMC::Packet::deserialize(bfr.getBuffer(), bfr.getSize());
      test.boolean("CreateSession #0", msg == *msg_d);
      delete msg_d;
    }
    catch (IMC::InvalidMessageSize& e)
    {
      (void)e;
      test.boolean("msg #0", msg.getSerializationSize() > DUNE_IMC_CONST_MAX_SIZE);
    }
  }

  {
    IMC::CreateSession msg;
    msg.setTimeStamp(0.7425640526059166);
    msg.setSource(49539U);
    msg.setSourceEntity(22U);
    msg.setDestination(31043U);
    msg.setDestinationEntity(56U);
    msg.timeout = 2149993479U;

    try
    {
      Utils::ByteBuffer bfr;
      IMC::Packet::serialize(&msg, bfr);
      IMC::Message* msg_d = IMC::Packet::deserialize(bfr.getBuffer(), bfr.getSize());
      test.boolean("CreateSession #1", msg == *msg_d);
      delete msg_d;
    }
    catch (IMC::InvalidMessageSize& e)
    {
      (void)e;
      test.boolean("msg #1", msg.getSerializationSize() > DUNE_IMC_CONST_MAX_SIZE);
    }
  }

  {
    IMC::CreateSession msg;
    msg.setTimeStamp(0.7970455898677107);
    msg.setSource(63621U);
    msg.setSourceEntity(38U);
    msg.setDestination(706U);
    msg.setDestinationEntity(40U);
    msg.timeout = 1959309298U;

    try
    {
      Utils::ByteBuffer bfr;
      IMC::Packet::serialize(&msg, bfr);
      IMC::Message* msg_d = IMC::Packet::deserialize(bfr.getBuffer(), bfr.getSize());
      test.boolean("CreateSession #2", msg == *msg_d);
      delete msg_d;
    }
    catch (IMC::InvalidMessageSize& e)
    {
      (void)e;
      test.boolean("msg #2", msg.getSerializationSize() > DUNE_IMC_CONST_MAX_SIZE);
    }
  }

  {
    IMC::CloseSession msg;
    msg.setTimeStamp(0.5177129952208025);
    msg.setSource(59285U);
    msg.setSourceEntity(238U);
    msg.setDestination(19771U);
    msg.setDestinationEntity(99U);
    msg.sessid = 3623448577U;

    try
    {
      Utils::ByteBuffer bfr;
      IMC::Packet::serialize(&msg, bfr);
      IMC::Message* msg_d = IMC::Packet::deserialize(bfr.getBuffer(), bfr.getSize());
      test.boolean("CloseSession #0", msg == *msg_d);
      delete msg_d;
    }
    catch (IMC::InvalidMessageSize& e)
    {
      (void)e;
      test.boolean("msg #0", msg.getSerializationSize() > DUNE_IMC_CONST_MAX_SIZE);
    }
  }

  {
    IMC::CloseSession msg;
    msg.setTimeStamp(0.2786243897507038);
    msg.setSource(10172U);
    msg.setSourceEntity(135U);
    msg.setDestination(3045U);
    msg.setDestinationEntity(223U);
    msg.sessid = 3182636810U;

    try
    {
      Utils::ByteBuffer bfr;
      IMC::Packet::serialize(&msg, bfr);
      IMC::Message* msg_d = IMC::Packet::deserialize(bfr.getBuffer(), bfr.getSize());
      test.boolean("CloseSession #1", msg == *msg_d);
      delete msg_d;
    }
    catch (IMC::InvalidMessageSize& e)
    {
      (void)e;
      test.boolean("msg #1", msg.getSerializationSize() > DUNE_IMC_CONST_MAX_SIZE);
    }
  }

  {
    IMC::CloseSession msg;
    msg.setTimeStamp(0.35747088325079446);
    msg.setSource(47618U);
    msg.setSourceEntity(129U);
    msg.setDestination(62905U);
    msg.setDestinationEntity(84U);
    msg.sessid = 441638411U;

    try
    {
      Utils::ByteBuffer bfr;
      IMC::Packet::serialize(&msg, bfr);
      IMC::Message* msg_d = IMC::Packet::deserialize(bfr.getBuffer(), bfr.getSize());
      test.boolean("CloseSession #2", msg == *msg_d);
      delete msg_d;
    }
    catch (IMC::InvalidMessageSize& e)
    {
      (void)e;
      test.boolean("msg #2", msg.getSerializationSize() > DUNE_IMC_CONST_MAX_SIZE);
    }
  }

  {
    IMC::SessionSubscription msg;
    msg.setTimeStamp(0.7461197065892844);
    msg.setSource(5379U);
    msg.setSourceEntity(95U);
    msg.setDestination(35354U);
    msg.setDestinationEntity(67U);
    msg.sessid = 142618174U;
    msg.messages.assign("HMEOOKWYNLUWDACSXNTDPEHWIOKULBBXVZR");

    try
    {
      Utils::ByteBuffer bfr;
      IMC::Packet::serialize(&msg, bfr);
      IMC::Message* msg_d = IMC::Packet::deserialize(bfr.getBuffer(), bfr.getSize());
      test.boolean("SessionSubscription #0", msg == *msg_d);
      delete msg_d;
    }
    catch (IMC::InvalidMessageSize& e)
    {
      (void)e;
      test.boolean("msg #0", msg.getSerializationSize() > DUNE_IMC_CONST_MAX_SIZE);
    }
  }

  {
    IMC::SessionSubscription msg;
    msg.setTimeStamp(0.5230013577920766);
    msg.setSource(29823U);
    msg.setSourceEntity(11U);
    msg.setDestination(22971U);
    msg.setDestinationEntity(210U);
    msg.sessid = 3101821792U;
    msg.messages.assign("XILBQCZCYIHHCZIGUAPMBCAGXJUWPUSGDJTSLEQHLOSXHHXAWSJAWEVLSYJORFESMAPGRDYONNBSHMBQRCPMMURSGBAQIVTOZWLHZQFCDXWFXTXCJLGCKVQBPPPAGLOTIUWPEZAJJQVWZQKMUEUBFZDJUEKSYMEJRNTNDWIXIEWSVHCZYV");

    try
    {
      Utils::ByteBuffer bfr;
      IMC::Packet::serialize(&msg, bfr);
      IMC::Message* msg_d = IMC::Packet::deserialize(bfr.getBuffer(), bfr.getSize());
      test.boolean("SessionSubscription #1", msg == *msg_d);
      delete msg_d;
    }
    catch (IMC::InvalidMessageSize& e)
    {
      (void)e;
      test.boolean("msg #1", msg.getSerializationSize() > DUNE_IMC_CONST_MAX_SIZE);
    }
  }

  {
    IMC::SessionSubscription msg;
    msg.setTimeStamp(0.002779240134290095);
    msg.setSource(21523U);
    msg.setSourceEntity(106U);
    msg.setDestination(37969U);
    msg.setDestinationEntity(170U);
    msg.sessid = 1745768275U;
    msg.messages.assign("GATIPCDYKEDDSFFGZLDCIMTFRMZCYKWRQTPLJHJWLESUJVWHXKJOSZQNTZDDRENGBJOAVCAALLMBNWXCNMUZVFOMQYVAYMHPPLUWYZCOQWHQAPXYLPKUNVKMYEIFEVLSTQGZJQMZHONHRXLJGKIELRKZQVAOXRDG");

    try
    {
      Utils::ByteBuffer bfr;
      IMC::Packet::serialize(&msg, bfr);
      IMC::Message* msg_d = IMC::Packet::deserialize(bfr.getBuffer(), bfr.getSize());
      test.boolean("SessionSubscription #2", msg == *msg_d);
      delete msg_d;
    }
    catch (IMC::InvalidMessageSize& e)
    {
      (void)e;
      test.boolean("msg #2", msg.getSerializationSize() > DUNE_IMC_CONST_MAX_SIZE);
    }
  }

  {
    IMC::SessionKeepAlive msg;
    msg.setTimeStamp(0.5186447942102165);
    msg.setSource(2165U);
    msg.setSourceEntity(244U);
    msg.setDestination(8837U);
    msg.setDestinationEntity(74U);
    msg.sessid = 1388798569U;

    try
    {
      Utils::ByteBuffer bfr;
      IMC::Packet::serialize(&msg, bfr);
      IMC::Message* msg_d = IMC::Packet::deserialize(bfr.getBuffer(), bfr.getSize());
      test.boolean("SessionKeepAlive #0", msg == *msg_d);
      delete msg_d;
    }
    catch (IMC::InvalidMessageSize& e)
    {
      (void)e;
      test.boolean("msg #0", msg.getSerializationSize() > DUNE_IMC_CONST_MAX_SIZE);
    }
  }

  {
    IMC::SessionKeepAlive msg;
    msg.setTimeStamp(0.24154626001191726);
    msg.setSource(48910U);
    msg.setSourceEntity(85U);
    msg.setDestination(57518U);
    msg.setDestinationEntity(194U);
    msg.sessid = 3022140040U;

    try
    {
      Utils::ByteBuffer bfr;
      IMC::Packet::serialize(&msg, bfr);
      IMC::Message* msg_d = IMC::Packet::deserialize(bfr.getBuffer(), bfr.getSize());
      test.boolean("SessionKeepAlive #1", msg == *msg_d);
      delete msg_d;
    }
    catch (IMC::InvalidMessageSize& e)
    {
      (void)e;
      test.boolean("msg #1", msg.getSerializationSize() > DUNE_IMC_CONST_MAX_SIZE);
    }
  }

  {
    IMC::SessionKeepAlive msg;
    msg.setTimeStamp(0.11007851997839657);
    msg.setSource(51556U);
    msg.setSourceEntity(82U);
    msg.setDestination(45632U);
    msg.setDestinationEntity(194U);
    msg.sessid = 2578875759U;

    try
    {
      Utils::ByteBuffer bfr;
      IMC::Packet::serialize(&msg, bfr);
      IMC::Message* msg_d = IMC::Packet::deserialize(bfr.getBuffer(), bfr.getSize());
      test.boolean("SessionKeepAlive #2", msg == *msg_d);
      delete msg_d;
    }
    catch (IMC::InvalidMessageSize& e)
    {
      (void)e;
      test.boolean("msg #2", msg.getSerializationSize() > DUNE_IMC_CONST_MAX_SIZE);
    }
  }

  {
    IMC::SessionStatus msg;
    msg.setTimeStamp(0.5232380388791211);
    msg.setSource(46605U);
    msg.setSourceEntity(0U);
    msg.setDestination(35948U);
    msg.setDestinationEntity(220U);
    msg.sessid = 1052942675U;
    msg.status = 8U;

    try
    {
      Utils::ByteBuffer bfr;
      IMC::Packet::serialize(&msg, bfr);
      IMC::Message* msg_d = IMC::Packet::deserialize(bfr.getBuffer(), bfr.getSize());
      test.boolean("SessionStatus #0", msg == *msg_d);
      delete msg_d;
    }
    catch (IMC::InvalidMessageSize& e)
    {
      (void)e;
      test.boolean("msg #0", msg.getSerializationSize() > DUNE_IMC_CONST_MAX_SIZE);
    }
  }

  {
    IMC::SessionStatus msg;
    msg.setTimeStamp(0.31367082674134195);
    msg.setSource(41816U);
    msg.setSourceEntity(166U);
    msg.setDestination(5202U);
    msg.setDestinationEntity(192U);
    msg.sessid = 598172123U;
    msg.status = 28U;

    try
    {
      Utils::ByteBuffer bfr;
      IMC::Packet::serialize(&msg, bfr);
      IMC::Message* msg_d = IMC::Packet::deserialize(bfr.getBuffer(), bfr.getSize());
      test.boolean("SessionStatus #1", msg == *msg_d);
      delete msg_d;
    }
    catch (IMC::InvalidMessageSize& e)
    {
      (void)e;
      test.boolean("msg #1", msg.getSerializationSize() > DUNE_IMC_CONST_MAX_SIZE);
    }
  }

  {
    IMC::SessionStatus msg;
    msg.setTimeStamp(0.6330039637671862);
    msg.setSource(47112U);
    msg.setSourceEntity(190U);
    msg.setDestination(14973U);
    msg.setDestinationEntity(90U);
    msg.sessid = 2822971169U;
    msg.status = 34U;

    try
    {
      Utils::ByteBuffer bfr;
      IMC::Packet::serialize(&msg, bfr);
      IMC::Message* msg_d = IMC::Packet::deserialize(bfr.getBuffer(), bfr.getSize());
      test.boolean("SessionStatus #2", msg == *msg_d);
      delete msg_d;
    }
    catch (IMC::InvalidMessageSize& e)
    {
      (void)e;
      test.boolean("msg #2", msg.getSerializationSize() > DUNE_IMC_CONST_MAX_SIZE);
    }
  }

  {
    IMC::PushEntityParameters msg;
    msg.setTimeStamp(0.054624665521354476);
    msg.setSource(20282U);
    msg.setSourceEntity(62U);
    msg.setDestination(46253U);
    msg.setDestinationEntity(204U);
    msg.name.assign("JEGNEEKRAZNZTUQJBKLWWGDHAFXYWVKDOZWNWUBQXPIROBEQXOGHHRODEJQSPSNLKJRLIHTCIMGGNICWMXNVYLPAIRXSZGBUSNPRHRKJDBIYYGLPTMLAAUTOXAOIGUFTYIPCVVHGAUESLOCCHIICDYNKFZZGHBUYKQFRT");

    try
    {
      Utils::ByteBuffer bfr;
      IMC::Packet::serialize(&msg, bfr);
      IMC::Message* msg_d = IMC::Packet::deserialize(bfr.getBuffer(), bfr.getSize());
      test.boolean("PushEntityParameters #0", msg == *msg_d);
      delete msg_d;
    }
    catch (IMC::InvalidMessageSize& e)
    {
      (void)e;
      test.boolean("msg #0", msg.getSerializationSize() > DUNE_IMC_CONST_MAX_SIZE);
    }
  }

  {
    IMC::PushEntityParameters msg;
    msg.setTimeStamp(0.46224314036493386);
    msg.setSource(34637U);
    msg.setSourceEntity(177U);
    msg.setDestination(50574U);
    msg.setDestinationEntity(142U);
    msg.name.assign("ZRIAMOWROXLDDWMZEFPPYXHUUSSSYRNUVPQGKMGGNODEYLMSMWZLHDQJZZVXHDBGDWXJQFJPHLVZBAXQVCIBUKQHIOFZOUFUOBXOSPREWVIEPXAWJEYTUQJGUGSQFAAKGTFPCWIQCSPBQYCNDERNCCEMNITCTFAAPIHWSWDGWJSNZCOYVVERTNIJMALBKKHVTKXTDZQTEBZYVAFCDKMARNKO");

    try
    {
      Utils::ByteBuffer bfr;
      IMC::Packet::serialize(&msg, bfr);
      IMC::Message* msg_d = IMC::Packet::deserialize(bfr.getBuffer(), bfr.getSize());
      test.boolean("PushEntityParameters #1", msg == *msg_d);
      delete msg_d;
    }
    catch (IMC::InvalidMessageSize& e)
    {
      (void)e;
      test.boolean("msg #1", msg.getSerializationSize() > DUNE_IMC_CONST_MAX_SIZE);
    }
  }

  {
    IMC::PushEntityParameters msg;
    msg.setTimeStamp(0.41175728890354213);
    msg.setSource(16202U);
    msg.setSourceEntity(159U);
    msg.setDestination(4266U);
    msg.setDestinationEntity(69U);
    msg.name.assign("DIXHRESNAJILBXIEPNEKSYISQMYCJRTZOIBMZEIPJUVFHTLFSKSOFOBYYBOCGUAFVDPBWXMVTGXIULWTUSYCROPARIFWQKMGWNDFDEBDKWOVAJRQNCECFCGAFXQDMOMWTNWHKCVUEENDXNJWMXLJPZJZQVKHYGBHUHTAHMTLRQQCURPZZ");

    try
    {
      Utils::ByteBuffer bfr;
      IMC::Packet::serialize(&msg, bfr);
      IMC::Message* msg_d = IMC::Packet::deserialize(bfr.getBuffer(), bfr.getSize());
      test.boolean("PushEntityParameters #2", msg == *msg_d);
      delete msg_d;
    }
    catch (IMC::InvalidMessageSize& e)
    {
      (void)e;
      test.boolean("msg #2", msg.getSerializationSize() > DUNE_IMC_CONST_MAX_SIZE);
    }
  }

  {
    IMC::PopEntityParameters msg;
    msg.setTimeStamp(0.26954335554974496);
    msg.setSource(6513U);
    msg.setSourceEntity(64U);
    msg.setDestination(35099U);
    msg.setDestinationEntity(202U);
    msg.name.assign("JPHUQKQYJCTIJBNZBHVXEWIMBNTCYOHIPNOZQCSTCDXARRNGJRGRBJXVVFXXDACXKNSHLMMFHYFZUFLILYCNOSAPWGFJRHKUDXBDOIEEAVCRLKB");

    try
    {
      Utils::ByteBuffer bfr;
      IMC::Packet::serialize(&msg, bfr);
      IMC::Message* msg_d = IMC::Packet::deserialize(bfr.getBuffer(), bfr.getSize());
      test.boolean("PopEntityParameters #0", msg == *msg_d);
      delete msg_d;
    }
    catch (IMC::InvalidMessageSize& e)
    {
      (void)e;
      test.boolean("msg #0", msg.getSerializationSize() > DUNE_IMC_CONST_MAX_SIZE);
    }
  }

  {
    IMC::PopEntityParameters msg;
    msg.setTimeStamp(0.3287949800005905);
    msg.setSource(59650U);
    msg.setSourceEntity(18U);
    msg.setDestination(3730U);
    msg.setDestinationEntity(3U);
    msg.name.assign("NBVDORMVRXWWFKLFWDOOGELEZHWXLRGLTRJVPFABGKMDMJSXVKSZUPFRHIGZTGTBUPFIMEIUVHTFYRMKOOWSAALIOWJFLYQTUJEYMOQJYDRSAQYMCSEGNXCAYBVFZICWHVPCVVARHSYCEWHHGTMAKINAPNPJGCSZCTSLRESZXGPLXRBYQNQYAZOSIZXWH");

    try
    {
      Utils::ByteBuffer bfr;
      IMC::Packet::serialize(&msg, bfr);
      IMC::Message* msg_d = IMC::Packet::deserialize(bfr.getBuffer(), bfr.getSize());
      test.boolean("PopEntityParameters #1", msg == *msg_d);
      delete msg_d;
    }
    catch (IMC::InvalidMessageSize& e)
    {
      (void)e;
      test.boolean("msg #1", msg.getSerializationSize() > DUNE_IMC_CONST_MAX_SIZE);
    }
  }

  {
    IMC::PopEntityParameters msg;
    msg.setTimeStamp(0.4875711843620535);
    msg.setSource(17036U);
    msg.setSourceEntity(225U);
    msg.setDestination(48354U);
    msg.setDestinationEntity(183U);
    msg.name.assign("XJINYKZFLCERLWMJXOLQDKJEEKAEOZHTQGPYDNKANHLAMUGAHOASKCYLJEQADGHICYBTWZQRMKHPZETYTUNQRICCWUFUWPKIGGOMXSVSJFFXOPLBMIXRLQAMIIBNTEQXZNGHYBHBVFAQLX");

    try
    {
      Utils::ByteBuffer bfr;
      IMC::Packet::serialize(&msg, bfr);
      IMC::Message* msg_d = IMC::Packet::deserialize(bfr.getBuffer(), bfr.getSize());
      test.boolean("PopEntityParameters #2", msg == *msg_d);
      delete msg_d;
    }
    catch (IMC::InvalidMessageSize& e)
    {
      (void)e;
      test.boolean("msg #2", msg.getSerializationSize() > DUNE_IMC_CONST_MAX_SIZE);
    }
  }

  {
    IMC::IoEvent msg;
    msg.setTimeStamp(0.030908860475341582);
    msg.setSource(24644U);
    msg.setSourceEntity(232U);
    msg.setDestination(40784U);
    msg.setDestinationEntity(231U);
    msg.type = 254U;
    msg.error.assign("TOIKGMELIZRHPCVWVHWMAWJQRZBOQHYWZJRVAYHCSTSBDQXDLWXFFGPTIGBDVPDYEUORQWKZLTHGPNJXAEKSMNXEEYQOXUOWAFZLRFJJPWMZNBWNQANULJLUGKOCFDVLUKFBTNXNBMEQCPTPHKNSFKRBJKUIFCYICGSHSVOLXYRUHCWJKKPYGDRSVVOFCCQIIAROEULPSVYXCZDEGAZMIREXMSOLNQIXYMMDIDJAZBPVTESDJTMH");

    try
    {
      Utils::ByteBuffer bfr;
      IMC::Packet::serialize(&msg, bfr);
      IMC::Message* msg_d = IMC::Packet::deserialize(bfr.getBuffer(), bfr.getSize());
      test.boolean("IoEvent #0", msg == *msg_d);
      delete msg_d;
    }
    catch (IMC::InvalidMessageSize& e)
    {
      (void)e;
      test.boolean("msg #0", msg.getSerializationSize() > DUNE_IMC_CONST_MAX_SIZE);
    }
  }

  {
    IMC::IoEvent msg;
    msg.setTimeStamp(0.327716971825854);
    msg.setSource(58780U);
    msg.setSourceEntity(147U);
    msg.setDestination(56735U);
    msg.setDestinationEntity(228U);
    msg.type = 180U;
    msg.error.assign("SICQFCPGLTPWQOXSCEXATFIRZYSKEWQGJYJOWNEWZFBDREDFJKMBLHQHZXDOYCZLGMUHLAIMWUAVXVCCNKVVSMEHOJQXLRZZ");

    try
    {
      Utils::ByteBuffer bfr;
      IMC::Packet::serialize(&msg, bfr);
      IMC::Message* msg_d = IMC::Packet::deserialize(bfr.getBuffer(), bfr.getSize());
      test.boolean("IoEvent #1", msg == *msg_d);
      delete msg_d;
    }
    catch (IMC::InvalidMessageSize& e)
    {
      (void)e;
      test.boolean("msg #1", msg.getSerializationSize() > DUNE_IMC_CONST_MAX_SIZE);
    }
  }

  {
    IMC::IoEvent msg;
    msg.setTimeStamp(0.14391590570279533);
    msg.setSource(10155U);
    msg.setSourceEntity(114U);
    msg.setDestination(4010U);
    msg.setDestinationEntity(50U);
    msg.type = 125U;
    msg.error.assign("SVQVPICNIFXQWSLYXCAFIPRJPHRNRBHBEJWRLBKVOIKXKFLSWURYOXCQQGMBGYVZEMJWDTSVTDGSRTWXZMAJPZCZTXEFBCKPUKLZTUYEZMLUZEXVNSMHVLGBOOAJMPAWKMEIHTLUTQLUDCTBGACCOAHGQUAHROXIDJVVQTISTJNJSONEOSMCUDLWQHNVEZUGPQDWRFISYOHBRMYPXKWHDGYXPIFAYFNCNYMAZD");

    try
    {
      Utils::ByteBuffer bfr;
      IMC::Packet::serialize(&msg, bfr);
      IMC::Message* msg_d = IMC::Packet::deserialize(bfr.getBuffer(), bfr.getSize());
      test.boolean("IoEvent #2", msg == *msg_d);
      delete msg_d;
    }
    catch (IMC::InvalidMessageSize& e)
    {
      (void)e;
      test.boolean("msg #2", msg.getSerializationSize() > DUNE_IMC_CONST_MAX_SIZE);
    }
  }

  {
    IMC::UamTxFrame msg;
    msg.setTimeStamp(0.12004059332168404);
    msg.setSource(21296U);
    msg.setSourceEntity(253U);
    msg.setDestination(9887U);
    msg.setDestinationEntity(252U);
    msg.seq = 63101U;
    msg.sys_dst.assign("XMEHPEEUKPTUSFMEYNZMOMIHGIOTOPESNCKGVAEOYLSIRYIEXYAJSSGRLWAKQAFCOQXTJNNCRLLVRQPCWZZVMBBNXOXGXOKXHDJURTWCALYSWOQIQVFGWJWEQVDCQULHVMA");
    msg.flags = 140U;
    const signed char tmp_msg_0[] = {88, -59, 50, 55, 38, -44, -71, 13, 11, -1, -29, -18, 38, -58, -119, 14, 67, 33, -123, 71, 32, 97, 88, -68, -118, 17, 35, -100, -60, -88, 59, 70, 119, -103, 35, -89, 60, -23, 109, 77, 122, 39, -53, 91, -8, 4, -15, -63, 66, 46, 117, 64, 97, -119, -99, -87, -91, -85, -57, 40, -3, -88, -89, 65, 13, -57, 13, -116, -22, -71, -119, 69, -92, -117, 46, -118, -43, -15, 120, -50, -44, 1, 49, -90, -93, 70, -61, -46, -39, 57, -36, -118, -49, 39, -127, -37, 20, 24, -27, -26, 61, 111, -18, 24, 75, -46, 30, 9, -89, -126, 108, -65, -26, 112, -54, -13, 40, -115, 53, 23, -43, -70, 28, 41, -11, 51, 5, 117, -37, -1, 65, 81, 71, 103, 98, 35, 98, 97, -53, -108, 24, -108, 71, -40, -127, 100, -116, 10, -53, -82, 38, -55, -6, 8, -125, 103, 9, 87, 41, -56, 26, 66, -121, -102, -35, 85, 0, -96, 85, 99, -30, -83, -54, -28, -74, -49, -87, -55, 90, 108, 82, 21, 117};
    msg.data.assign(tmp_msg_0, tmp_msg_0 + sizeof(tmp_msg_0));

    try
    {
      Utils::ByteBuffer bfr;
      IMC::Packet::serialize(&msg, bfr);
      IMC::Message* msg_d = IMC::Packet::deserialize(bfr.getBuffer(), bfr.getSize());
      test.boolean("UamTxFrame #0", msg == *msg_d);
      delete msg_d;
    }
    catch (IMC::InvalidMessageSize& e)
    {
      (void)e;
      test.boolean("msg #0", msg.getSerializationSize() > DUNE_IMC_CONST_MAX_SIZE);
    }
  }

  {
    IMC::UamTxFrame msg;
    msg.setTimeStamp(0.8433006245467483);
    msg.setSource(34275U);
    msg.setSourceEntity(248U);
    msg.setDestination(41704U);
    msg.setDestinationEntity(118U);
    msg.seq = 6705U;
    msg.sys_dst.assign("QMPYKNRELLKCGGGOBYNAUXQXRRBRENAAUEWWJROLWOPYBMHHBKQTMOVFKWMLHCDNVZCEJBYYPSOLQBJEEDFAFOVKQSCZGTTYZVKNHSTQMLSFESMHZSUXVQIBUAZPMCGDTYIFKDVQFXTTNUATHKDKJGBDGOGMBIHFJTCTJVJYNPJQPZSNWVOZWJXWOCFDYALIFMAVUSZRUSEQJILHGLXIIXPICPMWNRRLOXUUFIHYRP");
    msg.flags = 108U;
    const signed char tmp_msg_0[] = {-76, 63, -19, 56, 109, -22, -78, -4, 83, -68, -33, 36, 84, -65, 74, -76, 54, 108, 49, -84, 42, 33, -125, -37, -34, -120, 0, 53, 33, 20, 21, 38, -31, -27};
    msg.data.assign(tmp_msg_0, tmp_msg_0 + sizeof(tmp_msg_0));

    try
    {
      Utils::ByteBuffer bfr;
      IMC::Packet::serialize(&msg, bfr);
      IMC::Message* msg_d = IMC::Packet::deserialize(bfr.getBuffer(), bfr.getSize());
      test.boolean("UamTxFrame #1", msg == *msg_d);
      delete msg_d;
    }
    catch (IMC::InvalidMessageSize& e)
    {
      (void)e;
      test.boolean("msg #1", msg.getSerializationSize() > DUNE_IMC_CONST_MAX_SIZE);
    }
  }

  {
    IMC::UamTxFrame msg;
    msg.setTimeStamp(0.4331132906026909);
    msg.setSource(41774U);
    msg.setSourceEntity(200U);
    msg.setDestination(18267U);
    msg.setDestinationEntity(234U);
    msg.seq = 14333U;
    msg.sys_dst.assign("CQDHESIPCZVFAKEKGPMUPLZJIQVSUOXMZMXYCKGLYVSBJBETBURDHDYTCUYROMTRVBRZCOIEBDMCWMFWBAIKXHYOSZUZPMIQISJPNTNCELDGTGRHJYSBLYL");
    msg.flags = 56U;
    const signed char tmp_msg_0[] = {-52, -12, -50, -37, 12, 80, -71, 59, -36, -51, -34, 66, 95, 70, 5, 0, 104, -92, -49, 28, 115, -59, 62, 48, -97, -95, -48, 67, 43, 45, -14, -38, 97, -90, 75, 67, -89, -32, -81, -20, -11, -1, -92, -86, -94, -23, 30, -11, 20, -118, -111, -65, -111, -104, -40, 84};
    msg.data.assign(tmp_msg_0, tmp_msg_0 + sizeof(tmp_msg_0));

    try
    {
      Utils::ByteBuffer bfr;
      IMC::Packet::serialize(&msg, bfr);
      IMC::Message* msg_d = IMC::Packet::deserialize(bfr.getBuffer(), bfr.getSize());
      test.boolean("UamTxFrame #2", msg == *msg_d);
      delete msg_d;
    }
    catch (IMC::InvalidMessageSize& e)
    {
      (void)e;
      test.boolean("msg #2", msg.getSerializationSize() > DUNE_IMC_CONST_MAX_SIZE);
    }
  }

  {
    IMC::UamRxFrame msg;
    msg.setTimeStamp(0.12826431332199872);
    msg.setSource(59573U);
    msg.setSourceEntity(152U);
    msg.setDestination(14176U);
    msg.setDestinationEntity(118U);
    msg.sys_src.assign("RDPWVJEHRKIHFOOZFGDMTBYVTLTAUOWWAPUBHPJKXPIDLNNKTUTZDWVOADVXGXFQLZLLKA");
    msg.sys_dst.assign("FBEQTVDEFXMWMYGUEZPGOYRKJKVLVJPQNTKUQRUWNVPUSAYN");
    msg.flags = 143U;
    const signed char tmp_msg_0[] = {50, -38, -52, 84, 119, -9, -4, -52, -73, 18, -49, 67, -74, -18, -34, -15, 49, -29, 92, -65, -88, -94, -77, -97, -55, 32, 117, 119, 44, 63, -75, -29, 118, 12, -95, -70, -40, -55, -74, 56, 126, -112, -127, -61, -56, -87, -113, 110, -118, 106, -102, -2, -72, 63, 94, 45, 114, -38, -39, 7, 17, 125, -57, -86, 46, -113, 20, -64, 73, 24, -39, 93, -28, 63, -28, 108, 43, -8, 77, -99, -24, 43, 64, -77, -45, 73, 69, -14, -57, -105, -83, -58, 110, 47, -41, -63, -40, 113, -118, 60, 49, 104, 121, -124, -84, 18, -54, 5, 5, 47, 22, -115, -48, 88, -57, 0, 22, -6, -26, -100, 28, -124, -46, -71, -56, 29, -77, -57, -90, 41, 34, 28, -85, -91, 89, 39, -45, -56, -69, -34, 110, 44, -97, 109, 111, 110, 77, 28, 54, -49, 45, -108, -17, -45, 116, -7, 69};
    msg.data.assign(tmp_msg_0, tmp_msg_0 + sizeof(tmp_msg_0));

    try
    {
      Utils::ByteBuffer bfr;
      IMC::Packet::serialize(&msg, bfr);
      IMC::Message* msg_d = IMC::Packet::deserialize(bfr.getBuffer(), bfr.getSize());
      test.boolean("UamRxFrame #0", msg == *msg_d);
      delete msg_d;
    }
    catch (IMC::InvalidMessageSize& e)
    {
      (void)e;
      test.boolean("msg #0", msg.getSerializationSize() > DUNE_IMC_CONST_MAX_SIZE);
    }
  }

  {
    IMC::UamRxFrame msg;
    msg.setTimeStamp(0.39558712256769557);
    msg.setSource(11559U);
    msg.setSourceEntity(243U);
    msg.setDestination(6089U);
    msg.setDestinationEntity(8U);
    msg.sys_src.assign("YAZTZXZNXTEQZCMGSBWMDTCPLKBZNZIPUYGAHOFXSFQCNBUYTROLHQVBVUUGBFGDMCITHUCLACXT");
    msg.sys_dst.assign("XTEAABBMSBQAAOVJXRVUFJZVBFCKJNFZOXAYLADRWABZHEFAMGRCFOYHUWWPTSJBNGKLUJULRSUXRYDHODMLPDUQLPFUGVIKYMWMOESZWQQDVFWWEPPYOWMYKOEONHLPFLGZYTEVZJLCDIBZPCLPSURAFCZGGMQSSMQQ");
    msg.flags = 228U;
    const signed char tmp_msg_0[] = {91, 43, 122, 37, -69, -2, 93, -124, 33, 80, 30, -127, 96, 99, 99, 70, -42, 65, 37, -106, -56, 82, -39, -55, -37, 80, -80, 58, -14, 93, 70};
    msg.data.assign(tmp_msg_0, tmp_msg_0 + sizeof(tmp_msg_0));

    try
    {
      Utils::ByteBuffer bfr;
      IMC::Packet::serialize(&msg, bfr);
      IMC::Message* msg_d = IMC::Packet::deserialize(bfr.getBuffer(), bfr.getSize());
      test.boolean("UamRxFrame #1", msg == *msg_d);
      delete msg_d;
    }
    catch (IMC::InvalidMessageSize& e)
    {
      (void)e;
      test.boolean("msg #1", msg.getSerializationSize() > DUNE_IMC_CONST_MAX_SIZE);
    }
  }

  {
    IMC::UamRxFrame msg;
    msg.setTimeStamp(0.34595785150700364);
    msg.setSource(12923U);
    msg.setSourceEntity(53U);
    msg.setDestination(46129U);
    msg.setDestinationEntity(145U);
    msg.sys_src.assign("BBSCEGAEBFTIECTGUKAZWCQOAIMNBPKFXFWWITESXIEUIDCYYHKPXKACDFMYPZRZJNZGZGCGDPXPGOSANXWOHTQZNNOXLOVUBZDACOJTNVLHHMOMQKSOVULFNSRDLQQVBAQPHBLBFFKQMPHVIKTDEAXDHUNMJPJZWUDRQPCEINSIXWJIMWZWRKUXTRY");
    msg.sys_dst.assign("EVNUHLJINULKGJZRDJXNNUPBQGKKJASFQZBMYUQZRBOMZHJDQFDROHYCQWMEHGLISMQSKHLATYJEOTSCJGMMZEXDFROGXYEJVICBGSBGFWICIKZXRTCYPPHFPREGFEPKFOUTXRDPUIWVXAITB");
    msg.flags = 1U;
    const signed char tmp_msg_0[] = {1, 58, 117, 22, -68, 120, 89, 57, 38, -6, -54, 114, 9, 51, -87, -39, -15, -14, -51, -60, 20, 57, -122, 111, -56, -109, -87, -54, -40, 72, -21, 73, 102, 57, 116, -44, 22, 53, 65, 79, 73, -25, 121, 106, -95, 125, 106, 113, 118, -95, 79, -93, 114, -38, 124, -120, 119, 9, -96, -55, 98, 62, 19, -37, -120, -42, 86, -47, 57, -118, -102, -17, 15, 60, 124, -11, 109, 49, 30, 69, -36, -101, -92, -45, -70, -56, 53, 77, -65, -89, -39, 54, 67, 5, 78, -74, 54, 1, 26, -21, 122, -45, 44, -106, 63, -31, 93, -46, 5, 23, -126, -14, 105, 89, -64, 54, 110, 7, 42, -98, -16, -85, -17, -90, 14, 5, -93, 6, 97, 117, 69, -71, -123, -75, 8, 117, -84, -104, -33, -7, 81, 92, 16, -54, 66, -63, -72, -9, -108, -113, 61, -31, -72, 23, -109, 63, -45, -128, -126, -33, 38, 115, -68, 27, -96, -78, -101, -57, -8, 4, -45, 80, -102, -83, -58, 10, -92, -8, -119, -5, 92, -86, -70, -117, -114, 29, -92, -67, 123, 126, -113, 118, 79, 10, -94, -60, -123, -87, 101, -22, -102, 84, 86, -105, 37, -85, 94, 121, 85, 71, -87, 83, -100, 28, 38, -9, -70, -106, 82, 21, -20, -63, 22, 42, -109};
    msg.data.assign(tmp_msg_0, tmp_msg_0 + sizeof(tmp_msg_0));

    try
    {
      Utils::ByteBuffer bfr;
      IMC::Packet::serialize(&msg, bfr);
      IMC::Message* msg_d = IMC::Packet::deserialize(bfr.getBuffer(), bfr.getSize());
      test.boolean("UamRxFrame #2", msg == *msg_d);
      delete msg_d;
    }
    catch (IMC::InvalidMessageSize& e)
    {
      (void)e;
      test.boolean("msg #2", msg.getSerializationSize() > DUNE_IMC_CONST_MAX_SIZE);
    }
  }

  {
    IMC::UamTxStatus msg;
    msg.setTimeStamp(0.27660996166969154);
    msg.setSource(30658U);
    msg.setSourceEntity(199U);
    msg.setDestination(34876U);
    msg.setDestinationEntity(180U);
    msg.seq = 52461U;
    msg.value = 28U;
    msg.error.assign("GBBCKOKOVLOTHNSCYMFITQLZJRRMNCAIHPJIDBOSDNJTYMGCGVXUBMZMEAJAPXHYPVHTSBCIJMGBECOLPQNPFHZLZEWHFQULTVKVEDDLSXCXVB");

    try
    {
      Utils::ByteBuffer bfr;
      IMC::Packet::serialize(&msg, bfr);
      IMC::Message* msg_d = IMC::Packet::deserialize(bfr.getBuffer(), bfr.getSize());
      test.boolean("UamTxStatus #0", msg == *msg_d);
      delete msg_d;
    }
    catch (IMC::InvalidMessageSize& e)
    {
      (void)e;
      test.boolean("msg #0", msg.getSerializationSize() > DUNE_IMC_CONST_MAX_SIZE);
    }
  }

  {
    IMC::UamTxStatus msg;
    msg.setTimeStamp(0.1684814093029645);
    msg.setSource(13412U);
    msg.setSourceEntity(22U);
    msg.setDestination(41155U);
    msg.setDestinationEntity(166U);
    msg.seq = 28201U;
    msg.value = 21U;
    msg.error.assign("ITLCBNASUFOPHHRKSAFDZQZKXBCCWLEHKT");

    try
    {
      Utils::ByteBuffer bfr;
      IMC::Packet::serialize(&msg, bfr);
      IMC::Message* msg_d = IMC::Packet::deserialize(bfr.getBuffer(), bfr.getSize());
      test.boolean("UamTxStatus #1", msg == *msg_d);
      delete msg_d;
    }
    catch (IMC::InvalidMessageSize& e)
    {
      (void)e;
      test.boolean("msg #1", msg.getSerializationSize() > DUNE_IMC_CONST_MAX_SIZE);
    }
  }

  {
    IMC::UamTxStatus msg;
    msg.setTimeStamp(0.5763390430326427);
    msg.setSource(13287U);
    msg.setSourceEntity(254U);
    msg.setDestination(52394U);
    msg.setDestinationEntity(221U);
    msg.seq = 38202U;
    msg.value = 93U;
    msg.error.assign("REHUTAQWJQNMJSDYMAXIHACFQLAKYTVSPOSDCMGBKEVWNZHBWCVSTHHZYBUVXAEWYYUXKSZLHEDEDFVNENCXTVGMAVJBQILPBCQZGIJSCPZIAG");

    try
    {
      Utils::ByteBuffer bfr;
      IMC::Packet::serialize(&msg, bfr);
      IMC::Message* msg_d = IMC::Packet::deserialize(bfr.getBuffer(), bfr.getSize());
      test.boolean("UamTxStatus #2", msg == *msg_d);
      delete msg_d;
    }
    catch (IMC::InvalidMessageSize& e)
    {
      (void)e;
      test.boolean("msg #2", msg.getSerializationSize() > DUNE_IMC_CONST_MAX_SIZE);
    }
  }

  {
    IMC::UamRxRange msg;
    msg.setTimeStamp(0.8000497642399833);
    msg.setSource(44869U);
    msg.setSourceEntity(42U);
    msg.setDestination(40849U);
    msg.setDestinationEntity(183U);
    msg.seq = 25720U;
    msg.sys.assign("WYSJFEONBMSHGFRMIYEEIGPUIMKGTCJRDUYWEGHTJYWIQPZVGTZWWULUUPRWJDANSVCJUTAKNGYQHVHSFOPGECBZBESHMKEWUZDJCZJMXLWTKKKUAHTYVDUWXRFVARJXWZDDKRJIBDZODXJBXVFRLOCCPNMZKYTZSPGHXVZHUILFSLBMSAQXAPTOBFAVXCLDINCIQLXMIFOQMYQRQNPNNRQGENBCOCFSH");
    msg.value = 0.29829481311655437;

    try
    {
      Utils::ByteBuffer bfr;
      IMC::Packet::serialize(&msg, bfr);
      IMC::Message* msg_d = IMC::Packet::deserialize(bfr.getBuffer(), bfr.getSize());
      test.boolean("UamRxRange #0", msg == *msg_d);
      delete msg_d;
    }
    catch (IMC::InvalidMessageSize& e)
    {
      (void)e;
      test.boolean("msg #0", msg.getSerializationSize() > DUNE_IMC_CONST_MAX_SIZE);
    }
  }

  {
    IMC::UamRxRange msg;
    msg.setTimeStamp(0.2517285784997283);
    msg.setSource(13897U);
    msg.setSourceEntity(56U);
    msg.setDestination(54277U);
    msg.setDestinationEntity(81U);
    msg.seq = 36867U;
    msg.sys.assign("RXBWUJLKZOZOCVYKSUXSYGGWEVZABBNFOTVWXEQBWFJKVVUKKJBTMEULMGFANODXATQTN");
    msg.value = 0.9936223227764525;

    try
    {
      Utils::ByteBuffer bfr;
      IMC::Packet::serialize(&msg, bfr);
      IMC::Message* msg_d = IMC::Packet::deserialize(bfr.getBuffer(), bfr.getSize());
      test.boolean("UamRxRange #1", msg == *msg_d);
      delete msg_d;
    }
    catch (IMC::InvalidMessageSize& e)
    {
      (void)e;
      test.boolean("msg #1", msg.getSerializationSize() > DUNE_IMC_CONST_MAX_SIZE);
    }
  }

  {
    IMC::UamRxRange msg;
    msg.setTimeStamp(0.860502285996682);
    msg.setSource(150U);
    msg.setSourceEntity(25U);
    msg.setDestination(15138U);
    msg.setDestinationEntity(162U);
    msg.seq = 64055U;
    msg.sys.assign("MJAUKRLWUHHUIBQVQSDNOXBUOPAQFBOHYQWRXFYJIIUUXNEIELFBRYVVDBZZNPANLNDQHSRMEWCHXFPFKXLKKEZVGMRLPRWHSTGCRES");
    msg.value = 0.24971372966031014;

    try
    {
      Utils::ByteBuffer bfr;
      IMC::Packet::serialize(&msg, bfr);
      IMC::Message* msg_d = IMC::Packet::deserialize(bfr.getBuffer(), bfr.getSize());
      test.boolean("UamRxRange #2", msg == *msg_d);
      delete msg_d;
    }
    catch (IMC::InvalidMessageSize& e)
    {
      (void)e;
      test.boolean("msg #2", msg.getSerializationSize() > DUNE_IMC_CONST_MAX_SIZE);
    }
  }

  {
    IMC::UamTxRange msg;
    msg.setTimeStamp(0.9536074348307403);
    msg.setSource(20852U);
    msg.setSourceEntity(205U);
    msg.setDestination(46349U);
    msg.setDestinationEntity(250U);
    msg.seq = 19923U;
    msg.sys_dst.assign("MLLCNERHKWGDVCZDPQHFOUYGQRIZEQWGAKYLGHYNYJYBNOMYBZUXTEJYJLECIEMOKTAJBJVAXVTNTXFPVBHTOXLNITTCRCILWSUEMWOMSXJDWZPORFJBPGTYHHFJDGMJELMKLJYBOLXUFUCWHSEYWNZKPDMVWNIUDHQAFNPIKKAAZSPAKROIURIFXHM");
    msg.timeout = 0.6572378060095555;

    try
    {
      Utils::ByteBuffer bfr;
      IMC::Packet::serialize(&msg, bfr);
      IMC::Message* msg_d = IMC::Packet::deserialize(bfr.getBuffer(), bfr.getSize());
      test.boolean("UamTxRange #0", msg == *msg_d);
      delete msg_d;
    }
    catch (IMC::InvalidMessageSize& e)
    {
      (void)e;
      test.boolean("msg #0", msg.getSerializationSize() > DUNE_IMC_CONST_MAX_SIZE);
    }
  }

  {
    IMC::UamTxRange msg;
    msg.setTimeStamp(0.709904478081555);
    msg.setSource(43793U);
    msg.setSourceEntity(235U);
    msg.setDestination(11639U);
    msg.setDestinationEntity(216U);
    msg.seq = 48733U;
    msg.sys_dst.assign("BXNRPEVSQBWYACERPA");
    msg.timeout = 0.910938701579613;

    try
    {
      Utils::ByteBuffer bfr;
      IMC::Packet::serialize(&msg, bfr);
      IMC::Message* msg_d = IMC::Packet::deserialize(bfr.getBuffer(), bfr.getSize());
      test.boolean("UamTxRange #1", msg == *msg_d);
      delete msg_d;
    }
    catch (IMC::InvalidMessageSize& e)
    {
      (void)e;
      test.boolean("msg #1", msg.getSerializationSize() > DUNE_IMC_CONST_MAX_SIZE);
    }
  }

  {
    IMC::UamTxRange msg;
    msg.setTimeStamp(0.7426746115550177);
    msg.setSource(113U);
    msg.setSourceEntity(30U);
    msg.setDestination(47713U);
    msg.setDestinationEntity(237U);
    msg.seq = 23116U;
    msg.sys_dst.assign("JZVDCNOSNXWYWZYMDCQBLEZRKADAAQBSOABHHHATKRDEAMIORBEOKJNVAEYEFSRNXZYDRFSWTXGIHJWGVITAEJUGDSCBPVKFEFATTIQQFLNJGGDRLVPCMVBMWCZYFCOKVLJPSFKNEJHKCRJIOGHLMJZPLUHUHZPKURNOJDXSXOXOYWOBZLGDFUZSVKYPMFNTWRGQWVVUZBBHFUYLXQGRSIUTLMNNILDGSHU");
    msg.timeout = 0.4193115284558092;

    try
    {
      Utils::ByteBuffer bfr;
      IMC::Packet::serialize(&msg, bfr);
      IMC::Message* msg_d = IMC::Packet::deserialize(bfr.getBuffer(), bfr.getSize());
      test.boolean("UamTxRange #2", msg == *msg_d);
      delete msg_d;
    }
    catch (IMC::InvalidMessageSize& e)
    {
      (void)e;
      test.boolean("msg #2", msg.getSerializationSize() > DUNE_IMC_CONST_MAX_SIZE);
    }
  }

  {
    IMC::FormCtrlParam msg;
    msg.setTimeStamp(0.6895750914032478);
    msg.setSource(39581U);
    msg.setSourceEntity(235U);
    msg.setDestination(28295U);
    msg.setDestinationEntity(129U);
    msg.action = 6U;
    msg.longain = 0.762781571185536;
    msg.latgain = 0.3076874822217247;
    msg.bondthick = 3170136664U;
    msg.leadgain = 0.8489210251683383;
    msg.deconflgain = 0.3030807150507131;

    try
    {
      Utils::ByteBuffer bfr;
      IMC::Packet::serialize(&msg, bfr);
      IMC::Message* msg_d = IMC::Packet::deserialize(bfr.getBuffer(), bfr.getSize());
      test.boolean("FormCtrlParam #0", msg == *msg_d);
      delete msg_d;
    }
    catch (IMC::InvalidMessageSize& e)
    {
      (void)e;
      test.boolean("msg #0", msg.getSerializationSize() > DUNE_IMC_CONST_MAX_SIZE);
    }
  }

  {
    IMC::FormCtrlParam msg;
    msg.setTimeStamp(0.8233544618060441);
    msg.setSource(751U);
    msg.setSourceEntity(228U);
    msg.setDestination(4636U);
    msg.setDestinationEntity(240U);
    msg.action = 209U;
    msg.longain = 0.9732377467273652;
    msg.latgain = 0.5943252015542871;
    msg.bondthick = 2642552612U;
    msg.leadgain = 0.8291185969792914;
    msg.deconflgain = 0.7563017789369664;

    try
    {
      Utils::ByteBuffer bfr;
      IMC::Packet::serialize(&msg, bfr);
      IMC::Message* msg_d = IMC::Packet::deserialize(bfr.getBuffer(), bfr.getSize());
      test.boolean("FormCtrlParam #1", msg == *msg_d);
      delete msg_d;
    }
    catch (IMC::InvalidMessageSize& e)
    {
      (void)e;
      test.boolean("msg #1", msg.getSerializationSize() > DUNE_IMC_CONST_MAX_SIZE);
    }
  }

  {
    IMC::FormCtrlParam msg;
    msg.setTimeStamp(0.013196097919111582);
    msg.setSource(20818U);
    msg.setSourceEntity(201U);
    msg.setDestination(20655U);
    msg.setDestinationEntity(118U);
    msg.action = 172U;
    msg.longain = 0.6413582251786462;
    msg.latgain = 0.47871032434326144;
    msg.bondthick = 240632462U;
    msg.leadgain = 0.8717216767852273;
    msg.deconflgain = 0.6324185562664258;

    try
    {
      Utils::ByteBuffer bfr;
      IMC::Packet::serialize(&msg, bfr);
      IMC::Message* msg_d = IMC::Packet::deserialize(bfr.getBuffer(), bfr.getSize());
      test.boolean("FormCtrlParam #2", msg == *msg_d);
      delete msg_d;
    }
    catch (IMC::InvalidMessageSize& e)
    {
      (void)e;
      test.boolean("msg #2", msg.getSerializationSize() > DUNE_IMC_CONST_MAX_SIZE);
    }
  }

  {
    IMC::FormationEval msg;
    msg.setTimeStamp(0.9713451823448002);
    msg.setSource(58852U);
    msg.setSourceEntity(158U);
    msg.setDestination(47871U);
    msg.setDestinationEntity(218U);
    msg.err_mean = 0.11790960103507142;
    msg.dist_min_abs = 0.48863559082341856;
    msg.dist_min_mean = 0.770412164720697;

    try
    {
      Utils::ByteBuffer bfr;
      IMC::Packet::serialize(&msg, bfr);
      IMC::Message* msg_d = IMC::Packet::deserialize(bfr.getBuffer(), bfr.getSize());
      test.boolean("FormationEval #0", msg == *msg_d);
      delete msg_d;
    }
    catch (IMC::InvalidMessageSize& e)
    {
      (void)e;
      test.boolean("msg #0", msg.getSerializationSize() > DUNE_IMC_CONST_MAX_SIZE);
    }
  }

  {
    IMC::FormationEval msg;
    msg.setTimeStamp(0.7876823037672235);
    msg.setSource(20365U);
    msg.setSourceEntity(250U);
    msg.setDestination(29032U);
    msg.setDestinationEntity(82U);
    msg.err_mean = 0.2562736436497415;
    msg.dist_min_abs = 0.8702469346591377;
    msg.dist_min_mean = 0.7077897969086473;

    try
    {
      Utils::ByteBuffer bfr;
      IMC::Packet::serialize(&msg, bfr);
      IMC::Message* msg_d = IMC::Packet::deserialize(bfr.getBuffer(), bfr.getSize());
      test.boolean("FormationEval #1", msg == *msg_d);
      delete msg_d;
    }
    catch (IMC::InvalidMessageSize& e)
    {
      (void)e;
      test.boolean("msg #1", msg.getSerializationSize() > DUNE_IMC_CONST_MAX_SIZE);
    }
  }

  {
    IMC::FormationEval msg;
    msg.setTimeStamp(0.7964191288977676);
    msg.setSource(4894U);
    msg.setSourceEntity(198U);
    msg.setDestination(63942U);
    msg.setDestinationEntity(172U);
    msg.err_mean = 0.1615362024499466;
    msg.dist_min_abs = 0.11730140652024224;
    msg.dist_min_mean = 0.12009156396626752;

    try
    {
      Utils::ByteBuffer bfr;
      IMC::Packet::serialize(&msg, bfr);
      IMC::Message* msg_d = IMC::Packet::deserialize(bfr.getBuffer(), bfr.getSize());
      test.boolean("FormationEval #2", msg == *msg_d);
      delete msg_d;
    }
    catch (IMC::InvalidMessageSize& e)
    {
      (void)e;
      test.boolean("msg #2", msg.getSerializationSize() > DUNE_IMC_CONST_MAX_SIZE);
    }
  }

  {
    IMC::FormationControlParams msg;
    msg.setTimeStamp(0.08835033609559773);
    msg.setSource(54413U);
    msg.setSourceEntity(169U);
    msg.setDestination(3420U);
    msg.setDestinationEntity(63U);
    msg.action = 59U;
    msg.lon_gain = 0.1394774439619243;
    msg.lat_gain = 0.37777788201505547;
    msg.bond_thick = 0.7225847947973557;
    msg.lead_gain = 0.3021166014110648;
    msg.deconfl_gain = 0.810417615869889;
    msg.accel_switch_gain = 0.03157846762758698;
    msg.safe_dist = 0.9813439342073673;
    msg.deconflict_offset = 0.6827086101725999;
    msg.accel_safe_margin = 0.9695999662530159;
    msg.accel_lim_x = 0.06449375467427743;

    try
    {
      Utils::ByteBuffer bfr;
      IMC::Packet::serialize(&msg, bfr);
      IMC::Message* msg_d = IMC::Packet::deserialize(bfr.getBuffer(), bfr.getSize());
      test.boolean("FormationControlParams #0", msg == *msg_d);
      delete msg_d;
    }
    catch (IMC::InvalidMessageSize& e)
    {
      (void)e;
      test.boolean("msg #0", msg.getSerializationSize() > DUNE_IMC_CONST_MAX_SIZE);
    }
  }

  {
    IMC::FormationControlParams msg;
    msg.setTimeStamp(0.9652143430521426);
    msg.setSource(41566U);
    msg.setSourceEntity(119U);
    msg.setDestination(24080U);
    msg.setDestinationEntity(12U);
    msg.action = 248U;
    msg.lon_gain = 0.06537686866206327;
    msg.lat_gain = 0.07024375847029651;
    msg.bond_thick = 0.5393995119701199;
    msg.lead_gain = 0.4860456438968418;
    msg.deconfl_gain = 0.7311226196631719;
    msg.accel_switch_gain = 0.780678865292539;
    msg.safe_dist = 0.32542006825443903;
    msg.deconflict_offset = 0.3247286488715959;
    msg.accel_safe_margin = 0.7348154592495201;
    msg.accel_lim_x = 0.6776943671886136;

    try
    {
      Utils::ByteBuffer bfr;
      IMC::Packet::serialize(&msg, bfr);
      IMC::Message* msg_d = IMC::Packet::deserialize(bfr.getBuffer(), bfr.getSize());
      test.boolean("FormationControlParams #1", msg == *msg_d);
      delete msg_d;
    }
    catch (IMC::InvalidMessageSize& e)
    {
      (void)e;
      test.boolean("msg #1", msg.getSerializationSize() > DUNE_IMC_CONST_MAX_SIZE);
    }
  }

  {
    IMC::FormationControlParams msg;
    msg.setTimeStamp(0.4785678702446946);
    msg.setSource(50189U);
    msg.setSourceEntity(20U);
    msg.setDestination(6851U);
    msg.setDestinationEntity(186U);
    msg.action = 79U;
    msg.lon_gain = 0.5114558895808458;
    msg.lat_gain = 0.5014891616218004;
    msg.bond_thick = 0.9747229404403672;
    msg.lead_gain = 0.15074971611576193;
    msg.deconfl_gain = 0.7802808420479528;
    msg.accel_switch_gain = 0.3995686990378662;
    msg.safe_dist = 0.8129479176513164;
    msg.deconflict_offset = 0.32393714590847056;
    msg.accel_safe_margin = 0.4920501735379128;
    msg.accel_lim_x = 0.9483551431284323;

    try
    {
      Utils::ByteBuffer bfr;
      IMC::Packet::serialize(&msg, bfr);
      IMC::Message* msg_d = IMC::Packet::deserialize(bfr.getBuffer(), bfr.getSize());
      test.boolean("FormationControlParams #2", msg == *msg_d);
      delete msg_d;
    }
    catch (IMC::InvalidMessageSize& e)
    {
      (void)e;
      test.boolean("msg #2", msg.getSerializationSize() > DUNE_IMC_CONST_MAX_SIZE);
    }
  }

  {
    IMC::FormationEvaluation msg;
    msg.setTimeStamp(0.07070354106509613);
    msg.setSource(15094U);
    msg.setSourceEntity(68U);
    msg.setDestination(27728U);
    msg.setDestinationEntity(10U);
    msg.type = 44U;
    msg.op = 244U;
    msg.err_mean = 0.636587349606044;
    msg.dist_min_abs = 0.3705776892375896;
    msg.dist_min_mean = 0.8817964668573312;
    msg.roll_rate_mean = 0.7164597262255412;
    msg.time = 0.3050515485602068;
    IMC::FormationControlParams tmp_msg_0;
    tmp_msg_0.action = 193U;
    tmp_msg_0.lon_gain = 0.7512980735846376;
    tmp_msg_0.lat_gain = 0.16021938948802616;
    tmp_msg_0.bond_thick = 0.8917754494700203;
    tmp_msg_0.lead_gain = 0.6940121961118146;
    tmp_msg_0.deconfl_gain = 0.12181032806520287;
    tmp_msg_0.accel_switch_gain = 0.4556822325494845;
    tmp_msg_0.safe_dist = 0.9539714874538396;
    tmp_msg_0.deconflict_offset = 0.6939437569936524;
    tmp_msg_0.accel_safe_margin = 0.08810273610650965;
    tmp_msg_0.accel_lim_x = 0.3333749486673968;
    msg.controlparams.set(tmp_msg_0);

    try
    {
      Utils::ByteBuffer bfr;
      IMC::Packet::serialize(&msg, bfr);
      IMC::Message* msg_d = IMC::Packet::deserialize(bfr.getBuffer(), bfr.getSize());
      test.boolean("FormationEvaluation #0", msg == *msg_d);
      delete msg_d;
    }
    catch (IMC::InvalidMessageSize& e)
    {
      (void)e;
      test.boolean("msg #0", msg.getSerializationSize() > DUNE_IMC_CONST_MAX_SIZE);
    }
  }

  {
    IMC::FormationEvaluation msg;
    msg.setTimeStamp(0.7922481316520795);
    msg.setSource(907U);
    msg.setSourceEntity(202U);
    msg.setDestination(1902U);
    msg.setDestinationEntity(23U);
    msg.type = 188U;
    msg.op = 52U;
    msg.err_mean = 0.3087291197581218;
    msg.dist_min_abs = 0.17407617997561065;
    msg.dist_min_mean = 0.36119355305475953;
    msg.roll_rate_mean = 0.9295510361642688;
    msg.time = 0.6959581677300147;
    IMC::FormationControlParams tmp_msg_0;
    tmp_msg_0.action = 235U;
    tmp_msg_0.lon_gain = 0.5793009854887196;
    tmp_msg_0.lat_gain = 0.26572810591913776;
    tmp_msg_0.bond_thick = 0.47427312832143187;
    tmp_msg_0.lead_gain = 0.03803625163545621;
    tmp_msg_0.deconfl_gain = 0.22991077594359977;
    tmp_msg_0.accel_switch_gain = 0.13834749619784603;
    tmp_msg_0.safe_dist = 0.34004563932046583;
    tmp_msg_0.deconflict_offset = 0.33723038046465015;
    tmp_msg_0.accel_safe_margin = 0.9625876603788527;
    tmp_msg_0.accel_lim_x = 0.23784523571726035;
    msg.controlparams.set(tmp_msg_0);

    try
    {
      Utils::ByteBuffer bfr;
      IMC::Packet::serialize(&msg, bfr);
      IMC::Message* msg_d = IMC::Packet::deserialize(bfr.getBuffer(), bfr.getSize());
      test.boolean("FormationEvaluation #1", msg == *msg_d);
      delete msg_d;
    }
    catch (IMC::InvalidMessageSize& e)
    {
      (void)e;
      test.boolean("msg #1", msg.getSerializationSize() > DUNE_IMC_CONST_MAX_SIZE);
    }
  }

  {
    IMC::FormationEvaluation msg;
    msg.setTimeStamp(0.534922987996144);
    msg.setSource(40103U);
    msg.setSourceEntity(70U);
    msg.setDestination(65256U);
    msg.setDestinationEntity(124U);
    msg.type = 46U;
    msg.op = 51U;
    msg.err_mean = 0.3098246953289727;
    msg.dist_min_abs = 0.05511207746203817;
    msg.dist_min_mean = 0.5122307378376477;
    msg.roll_rate_mean = 0.16258702978009854;
    msg.time = 0.11514795239057307;
    IMC::FormationControlParams tmp_msg_0;
    tmp_msg_0.action = 215U;
    tmp_msg_0.lon_gain = 0.6099560281625008;
    tmp_msg_0.lat_gain = 0.7579499885482184;
    tmp_msg_0.bond_thick = 0.2816546556543057;
    tmp_msg_0.lead_gain = 0.30682808474794043;
    tmp_msg_0.deconfl_gain = 0.5219480483427935;
    tmp_msg_0.accel_switch_gain = 0.8530999517676267;
    tmp_msg_0.safe_dist = 0.47621735190324843;
    tmp_msg_0.deconflict_offset = 0.5463806629338006;
    tmp_msg_0.accel_safe_margin = 0.40809670733908276;
    tmp_msg_0.accel_lim_x = 0.16204342356609613;
    msg.controlparams.set(tmp_msg_0);

    try
    {
      Utils::ByteBuffer bfr;
      IMC::Packet::serialize(&msg, bfr);
      IMC::Message* msg_d = IMC::Packet::deserialize(bfr.getBuffer(), bfr.getSize());
      test.boolean("FormationEvaluation #2", msg == *msg_d);
      delete msg_d;
    }
    catch (IMC::InvalidMessageSize& e)
    {
      (void)e;
      test.boolean("msg #2", msg.getSerializationSize() > DUNE_IMC_CONST_MAX_SIZE);
    }
  }

  {
    IMC::SoiWaypoint msg;
    msg.setTimeStamp(0.8423847646748517);
    msg.setSource(62864U);
    msg.setSourceEntity(2U);
    msg.setDestination(20052U);
    msg.setDestinationEntity(108U);
    msg.lat = 0.6015291434779177;
    msg.lon = 0.580212907715622;
    msg.eta = 857033795U;
    msg.duration = 61321U;

    try
    {
      Utils::ByteBuffer bfr;
      IMC::Packet::serialize(&msg, bfr);
      IMC::Message* msg_d = IMC::Packet::deserialize(bfr.getBuffer(), bfr.getSize());
      test.boolean("SoiWaypoint #0", msg == *msg_d);
      delete msg_d;
    }
    catch (IMC::InvalidMessageSize& e)
    {
      (void)e;
      test.boolean("msg #0", msg.getSerializationSize() > DUNE_IMC_CONST_MAX_SIZE);
    }
  }

  {
    IMC::SoiWaypoint msg;
    msg.setTimeStamp(0.623718719378251);
    msg.setSource(46927U);
    msg.setSourceEntity(201U);
    msg.setDestination(62650U);
    msg.setDestinationEntity(10U);
    msg.lat = 0.28940973386214275;
    msg.lon = 0.6534121598307132;
    msg.eta = 897608370U;
    msg.duration = 20237U;

    try
    {
      Utils::ByteBuffer bfr;
      IMC::Packet::serialize(&msg, bfr);
      IMC::Message* msg_d = IMC::Packet::deserialize(bfr.getBuffer(), bfr.getSize());
      test.boolean("SoiWaypoint #1", msg == *msg_d);
      delete msg_d;
    }
    catch (IMC::InvalidMessageSize& e)
    {
      (void)e;
      test.boolean("msg #1", msg.getSerializationSize() > DUNE_IMC_CONST_MAX_SIZE);
    }
  }

  {
    IMC::SoiWaypoint msg;
    msg.setTimeStamp(0.00918765010074074);
    msg.setSource(51661U);
    msg.setSourceEntity(118U);
    msg.setDestination(35859U);
    msg.setDestinationEntity(94U);
    msg.lat = 0.5163975840558537;
    msg.lon = 0.9587382974494614;
    msg.eta = 1060256963U;
    msg.duration = 58700U;

    try
    {
      Utils::ByteBuffer bfr;
      IMC::Packet::serialize(&msg, bfr);
      IMC::Message* msg_d = IMC::Packet::deserialize(bfr.getBuffer(), bfr.getSize());
      test.boolean("SoiWaypoint #2", msg == *msg_d);
      delete msg_d;
    }
    catch (IMC::InvalidMessageSize& e)
    {
      (void)e;
      test.boolean("msg #2", msg.getSerializationSize() > DUNE_IMC_CONST_MAX_SIZE);
    }
  }

  {
    IMC::SoiPlan msg;
    msg.setTimeStamp(0.8778410116732107);
    msg.setSource(30166U);
    msg.setSourceEntity(4U);
    msg.setDestination(52890U);
    msg.setDestinationEntity(205U);
    msg.plan_id = 63251U;
    IMC::SoiWaypoint tmp_msg_0;
    tmp_msg_0.lat = 0.9866600596616428;
    tmp_msg_0.lon = 0.6031769197333587;
    tmp_msg_0.eta = 2429704222U;
    tmp_msg_0.duration = 59783U;
    msg.waypoints.push_back(tmp_msg_0);

    try
    {
      Utils::ByteBuffer bfr;
      IMC::Packet::serialize(&msg, bfr);
      IMC::Message* msg_d = IMC::Packet::deserialize(bfr.getBuffer(), bfr.getSize());
      test.boolean("SoiPlan #0", msg == *msg_d);
      delete msg_d;
    }
    catch (IMC::InvalidMessageSize& e)
    {
      (void)e;
      test.boolean("msg #0", msg.getSerializationSize() > DUNE_IMC_CONST_MAX_SIZE);
    }
  }

  {
    IMC::SoiPlan msg;
    msg.setTimeStamp(0.6671202726515525);
    msg.setSource(13350U);
    msg.setSourceEntity(137U);
    msg.setDestination(41105U);
    msg.setDestinationEntity(51U);
    msg.plan_id = 56259U;

    try
    {
      Utils::ByteBuffer bfr;
      IMC::Packet::serialize(&msg, bfr);
      IMC::Message* msg_d = IMC::Packet::deserialize(bfr.getBuffer(), bfr.getSize());
      test.boolean("SoiPlan #1", msg == *msg_d);
      delete msg_d;
    }
    catch (IMC::InvalidMessageSize& e)
    {
      (void)e;
      test.boolean("msg #1", msg.getSerializationSize() > DUNE_IMC_CONST_MAX_SIZE);
    }
  }

  {
    IMC::SoiPlan msg;
    msg.setTimeStamp(0.5977846121817643);
    msg.setSource(23354U);
    msg.setSourceEntity(241U);
    msg.setDestination(11371U);
    msg.setDestinationEntity(82U);
    msg.plan_id = 36496U;

    try
    {
      Utils::ByteBuffer bfr;
      IMC::Packet::serialize(&msg, bfr);
      IMC::Message* msg_d = IMC::Packet::deserialize(bfr.getBuffer(), bfr.getSize());
      test.boolean("SoiPlan #2", msg == *msg_d);
      delete msg_d;
    }
    catch (IMC::InvalidMessageSize& e)
    {
      (void)e;
      test.boolean("msg #2", msg.getSerializationSize() > DUNE_IMC_CONST_MAX_SIZE);
    }
  }

  {
    IMC::SoiCommand msg;
    msg.setTimeStamp(0.0697559266838278);
    msg.setSource(56025U);
    msg.setSourceEntity(97U);
    msg.setDestination(43957U);
    msg.setDestinationEntity(70U);
    msg.type = 186U;
    msg.command = 118U;
    msg.settings.assign("AGBZLSSFSOBVREBIIHWOZYDUMGSTJJJSODEAVHAQYMKBVCJXTBEICLEQEBKHJWAPLPKADBMHMLQGUONIQPCVPJHUHIGDGENYHWXKTYXGFJCROMAYKZWUZTJRMXTPODCCNEXOAQXZNXAMPUTCOVMTVYHXWWQXZCJIVUFSADKIFMSNGWZFRGHKVIZFIVSGRKRNZKBFERWNDRRTVF");
    IMC::SoiPlan tmp_msg_0;
    tmp_msg_0.plan_id = 25210U;
    IMC::SoiWaypoint tmp_tmp_msg_0_0;
    tmp_tmp_msg_0_0.lat = 0.9447800383332368;
    tmp_tmp_msg_0_0.lon = 0.2556863585287835;
    tmp_tmp_msg_0_0.eta = 2128036857U;
    tmp_tmp_msg_0_0.duration = 34155U;
    tmp_msg_0.waypoints.push_back(tmp_tmp_msg_0_0);
    msg.plan.set(tmp_msg_0);
    msg.info.assign("HAPLMQENPYUSAXDFHMBRBKOINDRTPTGZIDMOVGJEAXOQLIHSLQGCKXDORFQABHGFPFTAVOUXCRYXIBFQWSUJKKZCRCNGZCFATRPKEZNUKCTJDHZVIYWMRHEJLPYDRREBWCVMJZVKLHUYNSSJATIWPNJKOTMJANQFKSOLHWMOWBYPWZJZBSXABTDLBVDXEBXUGYFOXMDUEVQELEYQHQGCTXZMWVIPDAOVWUCPCFLZYNU");

    try
    {
      Utils::ByteBuffer bfr;
      IMC::Packet::serialize(&msg, bfr);
      IMC::Message* msg_d = IMC::Packet::deserialize(bfr.getBuffer(), bfr.getSize());
      test.boolean("SoiCommand #0", msg == *msg_d);
      delete msg_d;
    }
    catch (IMC::InvalidMessageSize& e)
    {
      (void)e;
      test.boolean("msg #0", msg.getSerializationSize() > DUNE_IMC_CONST_MAX_SIZE);
    }
  }

  {
    IMC::SoiCommand msg;
    msg.setTimeStamp(0.795236332167783);
    msg.setSource(35972U);
    msg.setSourceEntity(122U);
    msg.setDestination(39850U);
    msg.setDestinationEntity(22U);
    msg.type = 7U;
    msg.command = 115U;
    msg.settings.assign("BYFJFBZMIKLSWYUKVSMJHAOTFRGOIKZQUJRJXFZHVUTKENPPFYQVJOOUGGQSTADDMCYMXAOFZDBYEGHIHQVQZXNMKBLKTVBWUOXPYNXBFRMESICWYMQVSIAZGDMZWULTFCTWILJAGRBEZWEAEIRXCSIU");
    IMC::SoiPlan tmp_msg_0;
    tmp_msg_0.plan_id = 42109U;
    msg.plan.set(tmp_msg_0);
    msg.info.assign("NOQMUWQVYUSERQVAICGFYTTVUGMIGPQIRIMBXCODKMLQDUCRHUJTYGC");

    try
    {
      Utils::ByteBuffer bfr;
      IMC::Packet::serialize(&msg, bfr);
      IMC::Message* msg_d = IMC::Packet::deserialize(bfr.getBuffer(), bfr.getSize());
      test.boolean("SoiCommand #1", msg == *msg_d);
      delete msg_d;
    }
    catch (IMC::InvalidMessageSize& e)
    {
      (void)e;
      test.boolean("msg #1", msg.getSerializationSize() > DUNE_IMC_CONST_MAX_SIZE);
    }
  }

  {
    IMC::SoiCommand msg;
    msg.setTimeStamp(0.9397392119102393);
    msg.setSource(13337U);
    msg.setSourceEntity(119U);
    msg.setDestination(45938U);
    msg.setDestinationEntity(238U);
    msg.type = 66U;
    msg.command = 220U;
    msg.settings.assign("OUJAWXVQOFUDWWDRZHEQXVSMLSCASEPWROGOECQDPAGIUTFQMIHSRELSLBDUOBMYNECAEJZNWQYKGQKHRFHYHINMLEQPHVWALNKOK");
    IMC::SoiPlan tmp_msg_0;
    tmp_msg_0.plan_id = 14880U;
    IMC::SoiWaypoint tmp_tmp_msg_0_0;
    tmp_tmp_msg_0_0.lat = 0.09525542038179557;
    tmp_tmp_msg_0_0.lon = 0.9372430777950516;
    tmp_tmp_msg_0_0.eta = 3762581327U;
    tmp_tmp_msg_0_0.duration = 5579U;
    tmp_msg_0.waypoints.push_back(tmp_tmp_msg_0_0);
    msg.plan.set(tmp_msg_0);
    msg.info.assign("VTYAZSXWQJOBPQVFAGXINXZVQUDJISTIMHFKDWYHZQQZDGDILLRHDGNDZXNDGNURZQHUNZDPPQCYVRVRIFSCSXOAMXORFJJBMGGMWBENMTMBJPMZBAESMLFEOETHGUKTZPHIPWWRLDPVLSSRKCEOYVBAOFYOCWIJICKAVTMUPYPUEFTAFOXWEBFNPKXGCCRBUIKWSXLNAKN");

    try
    {
      Utils::ByteBuffer bfr;
      IMC::Packet::serialize(&msg, bfr);
      IMC::Message* msg_d = IMC::Packet::deserialize(bfr.getBuffer(), bfr.getSize());
      test.boolean("SoiCommand #2", msg == *msg_d);
      delete msg_d;
    }
    catch (IMC::InvalidMessageSize& e)
    {
      (void)e;
      test.boolean("msg #2", msg.getSerializationSize() > DUNE_IMC_CONST_MAX_SIZE);
    }
  }

  {
    IMC::SoiState msg;
    msg.setTimeStamp(0.761540459873461);
    msg.setSource(54496U);
    msg.setSourceEntity(90U);
    msg.setDestination(62276U);
    msg.setDestinationEntity(166U);
    msg.state = 177U;
    msg.plan_id = 33946U;
    msg.wpt_id = 50U;
    msg.settings_chk = 63361U;

    try
    {
      Utils::ByteBuffer bfr;
      IMC::Packet::serialize(&msg, bfr);
      IMC::Message* msg_d = IMC::Packet::deserialize(bfr.getBuffer(), bfr.getSize());
      test.boolean("SoiState #0", msg == *msg_d);
      delete msg_d;
    }
    catch (IMC::InvalidMessageSize& e)
    {
      (void)e;
      test.boolean("msg #0", msg.getSerializationSize() > DUNE_IMC_CONST_MAX_SIZE);
    }
  }

  {
    IMC::SoiState msg;
    msg.setTimeStamp(0.5009430534313085);
    msg.setSource(56823U);
    msg.setSourceEntity(81U);
    msg.setDestination(60584U);
    msg.setDestinationEntity(145U);
    msg.state = 30U;
    msg.plan_id = 52327U;
    msg.wpt_id = 124U;
    msg.settings_chk = 12642U;

    try
    {
      Utils::ByteBuffer bfr;
      IMC::Packet::serialize(&msg, bfr);
      IMC::Message* msg_d = IMC::Packet::deserialize(bfr.getBuffer(), bfr.getSize());
      test.boolean("SoiState #1", msg == *msg_d);
      delete msg_d;
    }
    catch (IMC::InvalidMessageSize& e)
    {
      (void)e;
      test.boolean("msg #1", msg.getSerializationSize() > DUNE_IMC_CONST_MAX_SIZE);
    }
  }

  {
    IMC::SoiState msg;
    msg.setTimeStamp(0.889180659430687);
    msg.setSource(55070U);
    msg.setSourceEntity(216U);
    msg.setDestination(7788U);
    msg.setDestinationEntity(71U);
    msg.state = 97U;
    msg.plan_id = 23146U;
    msg.wpt_id = 119U;
    msg.settings_chk = 40544U;

    try
    {
      Utils::ByteBuffer bfr;
      IMC::Packet::serialize(&msg, bfr);
      IMC::Message* msg_d = IMC::Packet::deserialize(bfr.getBuffer(), bfr.getSize());
      test.boolean("SoiState #2", msg == *msg_d);
      delete msg_d;
    }
    catch (IMC::InvalidMessageSize& e)
    {
      (void)e;
      test.boolean("msg #2", msg.getSerializationSize() > DUNE_IMC_CONST_MAX_SIZE);
    }
  }

  {
    IMC::MessagePart msg;
    msg.setTimeStamp(0.9383984063341811);
    msg.setSource(37338U);
    msg.setSourceEntity(110U);
    msg.setDestination(30539U);
    msg.setDestinationEntity(87U);
    msg.uid = 198U;
    msg.frag_number = 196U;
    msg.num_frags = 129U;
    const signed char tmp_msg_0[] = {-48, -28, -37, -66, -103, 27, -112, 19, -61, -12, 19, 26, -17, 65, -42, 3, 105, 100, 113, -53, -26, -11, 62, -45, -7, 36, -109, -2, 31, -86, -44, 23, -86, -32, 93, 109, -30, 20, 46, -66, 116, 12, -82, 51, -87, -74, -12, 73, -95, 86, -11, -112, 125, -63, 31, -1, -6, -17, -65, 68, -39, -46, 41, 16, 26, -72, -108, -82, 71, -110, -44, -119, 2, 50, -76, 35, -75, -22, -81, -101, -112, 118, -121, 82, 98, -50, -58, 13};
    msg.data.assign(tmp_msg_0, tmp_msg_0 + sizeof(tmp_msg_0));

    try
    {
      Utils::ByteBuffer bfr;
      IMC::Packet::serialize(&msg, bfr);
      IMC::Message* msg_d = IMC::Packet::deserialize(bfr.getBuffer(), bfr.getSize());
      test.boolean("MessagePart #0", msg == *msg_d);
      delete msg_d;
    }
    catch (IMC::InvalidMessageSize& e)
    {
      (void)e;
      test.boolean("msg #0", msg.getSerializationSize() > DUNE_IMC_CONST_MAX_SIZE);
    }
  }

  {
    IMC::MessagePart msg;
    msg.setTimeStamp(0.55695855060406);
    msg.setSource(53331U);
    msg.setSourceEntity(64U);
    msg.setDestination(14292U);
    msg.setDestinationEntity(123U);
    msg.uid = 216U;
    msg.frag_number = 229U;
    msg.num_frags = 194U;
    const signed char tmp_msg_0[] = {82, 125, -128, 121, 46, 46, -115, 117, 37, -99, 99, -110, 56, 4, -83, 122, 30, 45, 36, 62, 118, 92, -85, 118, -57, -10, 105, 109, 61, 124, -17, -61, -128, 64, 16, -58, -36, 51, -4, -61, -77, 75, -11, 107, 26, 115, 105, 122, -48, -7, 57, 117, 91, 21, 6, -30, -57, -85, -71, -17, 10, 76, 27, 105, 102, 4, -28, 45, 109, 90, -11, -100, 51, -127, 55, -117, 73, -8, -29, -1, 70, 15, -29, 39, -35, -91, -56, 15, 104, 81, -34, 121, -61, 25, -59, 60, 28, 9};
    msg.data.assign(tmp_msg_0, tmp_msg_0 + sizeof(tmp_msg_0));

    try
    {
      Utils::ByteBuffer bfr;
      IMC::Packet::serialize(&msg, bfr);
      IMC::Message* msg_d = IMC::Packet::deserialize(bfr.getBuffer(), bfr.getSize());
      test.boolean("MessagePart #1", msg == *msg_d);
      delete msg_d;
    }
    catch (IMC::InvalidMessageSize& e)
    {
      (void)e;
      test.boolean("msg #1", msg.getSerializationSize() > DUNE_IMC_CONST_MAX_SIZE);
    }
  }

  {
    IMC::MessagePart msg;
    msg.setTimeStamp(0.9470455349708914);
    msg.setSource(21388U);
    msg.setSourceEntity(13U);
    msg.setDestination(48824U);
    msg.setDestinationEntity(246U);
    msg.uid = 91U;
    msg.frag_number = 169U;
    msg.num_frags = 142U;
    const signed char tmp_msg_0[] = {-21, 33, 95, 76, -79, 87, 117, -112, -106, 76, -127, 100, 75, -127, 62, -40, -105, -90, -114};
    msg.data.assign(tmp_msg_0, tmp_msg_0 + sizeof(tmp_msg_0));

    try
    {
      Utils::ByteBuffer bfr;
      IMC::Packet::serialize(&msg, bfr);
      IMC::Message* msg_d = IMC::Packet::deserialize(bfr.getBuffer(), bfr.getSize());
      test.boolean("MessagePart #2", msg == *msg_d);
      delete msg_d;
    }
    catch (IMC::InvalidMessageSize& e)
    {
      (void)e;
      test.boolean("msg #2", msg.getSerializationSize() > DUNE_IMC_CONST_MAX_SIZE);
    }
  }

  {
    IMC::NeptusBlob msg;
    msg.setTimeStamp(0.5040912011721039);
    msg.setSource(35846U);
    msg.setSourceEntity(183U);
    msg.setDestination(17535U);
    msg.setDestinationEntity(20U);
    msg.content_type.assign("VFICPULKHAPXOHZHKGBRXHMILRSKSWDKQBRTIBQKKRBVAFRWWLEBIXEZMCWINCRHDTPZSAUFBVRQCGDCNLZEVUSWSNHMXIAQKZFYAQTZDMYUOVWIPCOLSXOTRNTENBGFOYFNGJYGTZMOAFWBGODQYPZKYPMDOUCPVJUFMOHIVELYVMDSSLTQTDZ");
    const signed char tmp_msg_0[] = {-42, -22, -23, -1, -41, -78, -35, -89, -86, -56, -17, -78, -109, -98, 11, 59, 112, 23, 22, -1, -104, 43, 50, -12, 49, -99, 125, 6, 105, -79, 109, -67, 75, 21, 119, 76, 108, -91, 23, -64, 93, 66, 116, -58, -14, 105, 74, -60, 52, -60, 48, 43, 115, 21, 92, 85, 64, -82, 114, 81, 4, -20, 3, 66, -52, -75, -18, 76, 126, -86, -80, 71, -16, -105, -105, -64, -105, 110, -43, 89, 71, 80, -9, -122, -19, 120, 25, -2, -31, -121, -39, -107, -111, 85, -44, 56, 66, -53, 5, 44, 121, 51, -101, 85, -105, -108, 31, -14, 5, -54, -54, 84, -5, -49, -63, -45, -53, 84, 71, 121, 44, 87, -55, 29, 98, 43, -86, -99, -50, 36, -119, 91, 40, 102, 98, -80, -49, 75, -11, -88, -101, -95, 111, -51, 50, 80, -96, -50, -113, -91, -89, -105, -87, 32, -97, 110, 99, 78, 102, 98, 90, 59, 82, -76, -52, -12, -96, 18, -92, -4, 67, 107, -64, -8, -30, 84, -105, 49, 83, -73, 63, -96, -61, 118, 7, 118, 93, -79, 58, -105, -103, -70, -29, 45, -43, -83, 31, -78, 17, -52, 20, 32, 53, -40, -52, -39, 49, -66, 33, -84, 99, -110, -35, 77, 91, -127, -61, 82, -104, 109, 53, -119, -119, -11, -38, -56, 70, 85, -46, 47, -77, 78, -102};
    msg.content.assign(tmp_msg_0, tmp_msg_0 + sizeof(tmp_msg_0));

    try
    {
      Utils::ByteBuffer bfr;
      IMC::Packet::serialize(&msg, bfr);
      IMC::Message* msg_d = IMC::Packet::deserialize(bfr.getBuffer(), bfr.getSize());
      test.boolean("NeptusBlob #0", msg == *msg_d);
      delete msg_d;
    }
    catch (IMC::InvalidMessageSize& e)
    {
      (void)e;
      test.boolean("msg #0", msg.getSerializationSize() > DUNE_IMC_CONST_MAX_SIZE);
    }
  }

  {
    IMC::NeptusBlob msg;
    msg.setTimeStamp(0.721523133200889);
    msg.setSource(10588U);
    msg.setSourceEntity(180U);
    msg.setDestination(14200U);
    msg.setDestinationEntity(137U);
    msg.content_type.assign("EOHBNCQKWHVDNYYQDRMZUCSLRZYDEDOHQQWXHFMRGWEGTEAJVIHTZQGYVNGYNTCTXUEJNVDZEDHRRMJCPIZIKOTICTURDUVOFFSATFYULLVRORSJPZJPWBCPFPGBJFEQXBPXWFMKXQSSMJRMUIAABKAWKPZYNTLIFWHYBKY");
    const signed char tmp_msg_0[] = {-81, 108, -12, -43, -48, 35, 26, -33, -21, -102, 82, 41, -5, 57, 68, -59, 40, -70, -89, 33, -75, 31, -36, -67, 10, 83, 43, 0, -88, -65, 20, -89, 47, -51, 122, 62, -70, 52, 48, 23, -85, 18, -39, 96, 64, -119, 80, -44, 114, 28, -50, -63, -105, -86, 50, -19, 74, 124, -16, -21, 28, 80, -113, -14, -24, 80, 53, -29, 122, -60, 8, 103, 42, -10, 70, -59, 76, 82, -89, -86, -11, -111, 3, 26, 46, -128, 81, -21, 37, -104, -36, 115, 3, 124, 106, -18, 55, 38, -19, -7, -37, -120, -31, -109, -12, 103, -51, 20, -65, -123, 89, 13, 13, -70, -76, 99, -65, -55, -16, 78, -15, 47, -24, 73, -115, 36, 1, -127, -123, -51, -26, 12, -17, -22, 38, -76, -25, -7, -114, 29, -83, 41, -30, 1, -120, -20, -73, 116, -71, -47, 12, 83, 32, -73, 26, 58, 114, 74, 74, 117, 117, 115, 1, 46, -2, -41};
    msg.content.assign(tmp_msg_0, tmp_msg_0 + sizeof(tmp_msg_0));

    try
    {
      Utils::ByteBuffer bfr;
      IMC::Packet::serialize(&msg, bfr);
      IMC::Message* msg_d = IMC::Packet::deserialize(bfr.getBuffer(), bfr.getSize());
      test.boolean("NeptusBlob #1", msg == *msg_d);
      delete msg_d;
    }
    catch (IMC::InvalidMessageSize& e)
    {
      (void)e;
      test.boolean("msg #1", msg.getSerializationSize() > DUNE_IMC_CONST_MAX_SIZE);
    }
  }

  {
    IMC::NeptusBlob msg;
    msg.setTimeStamp(0.14646947934088028);
    msg.setSource(26674U);
    msg.setSourceEntity(85U);
    msg.setDestination(27218U);
    msg.setDestinationEntity(47U);
    msg.content_type.assign("IAGEWECUYHYHJAQYUHJSSGCJOTLVVIBQWABMWTSJLMDESNDSNMJIFNUVYKFHFOXBUKGOZTTVMUXQSYBTDMPAUEKLXRZKVCCUYSEPXNFJGXKPQPHGLLCCNIDHQBMHHLQVELHOBIMWKZDYNAGXUIPZOXMJTFWBFRJKCYTGXWXJAORIFFDNKCZAKNBVCLOGFWWMZEVRBOPSBSXRVRZDTUAIQLWERFEUARYZGNCKPL");
    const signed char tmp_msg_0[] = {-19, -107, 42, -67, -91, 91, -90, 48, 69, -70, -59, -67, 117, 69, 44, -81, 91, -13, -83, -95, 56, 62, 124, 100, -53, -28, 95, -11, 96, -68, -77, -51, 59, 45, 57, 93, -79, 19, 64, 92, 111, 38, 45, 68, 33, 25, 125, -47, 32, 111, 33, -37, 14, 120, 38, -104, -124, -14, -124, 76, 122, 24, -10, 6, -74, -73, -127, -22, 39, -5, 16, 125, 98, -37, 65, -28, 27, 89, -124, -116, -114, -47, -38, 38, 8, -26, -15, 102, -51, 97, -93, 36, 74, -61, -107, -95, 100, -104, -3, 64, -30, 1, 9, -46, 89, 8, 90, 94, 59, -33, 94, -3, -109, -95, 14, 19, 3, -41, -47, 52, 59, -77, 36, 126, 70, -20, 104, 75, 111, 100, -60, 50, -81, 79, 70, -8, -21, 117, -80, -33, 72, 37, -77, -25, -56, -100, -49, 55, 62, 56, -111, -26, 105, -89, 36, -105, 67, 104, 66, 24, 52, 86, 101, -51, 81, -28, 117, 53, -72, 23, -57, 22, 23, 47, 69, -41, -83, -65, 33, -22, 80, 104, 62, 30, 57};
    msg.content.assign(tmp_msg_0, tmp_msg_0 + sizeof(tmp_msg_0));

    try
    {
      Utils::ByteBuffer bfr;
      IMC::Packet::serialize(&msg, bfr);
      IMC::Message* msg_d = IMC::Packet::deserialize(bfr.getBuffer(), bfr.getSize());
      test.boolean("NeptusBlob #2", msg == *msg_d);
      delete msg_d;
    }
    catch (IMC::InvalidMessageSize& e)
    {
      (void)e;
      test.boolean("msg #2", msg.getSerializationSize() > DUNE_IMC_CONST_MAX_SIZE);
    }
  }

  {
    IMC::Aborted msg;
    msg.setTimeStamp(0.29541118397067645);
    msg.setSource(14915U);
    msg.setSourceEntity(129U);
    msg.setDestination(8125U);
    msg.setDestinationEntity(172U);

    try
    {
      Utils::ByteBuffer bfr;
      IMC::Packet::serialize(&msg, bfr);
      IMC::Message* msg_d = IMC::Packet::deserialize(bfr.getBuffer(), bfr.getSize());
      test.boolean("Aborted #0", msg == *msg_d);
      delete msg_d;
    }
    catch (IMC::InvalidMessageSize& e)
    {
      (void)e;
      test.boolean("msg #0", msg.getSerializationSize() > DUNE_IMC_CONST_MAX_SIZE);
    }
  }

  {
    IMC::Aborted msg;
    msg.setTimeStamp(0.9207264622793918);
    msg.setSource(12288U);
    msg.setSourceEntity(104U);
    msg.setDestination(38086U);
    msg.setDestinationEntity(0U);

    try
    {
      Utils::ByteBuffer bfr;
      IMC::Packet::serialize(&msg, bfr);
      IMC::Message* msg_d = IMC::Packet::deserialize(bfr.getBuffer(), bfr.getSize());
      test.boolean("Aborted #1", msg == *msg_d);
      delete msg_d;
    }
    catch (IMC::InvalidMessageSize& e)
    {
      (void)e;
      test.boolean("msg #1", msg.getSerializationSize() > DUNE_IMC_CONST_MAX_SIZE);
    }
  }

  {
    IMC::Aborted msg;
    msg.setTimeStamp(0.32559266271091014);
    msg.setSource(43478U);
    msg.setSourceEntity(246U);
    msg.setDestination(2713U);
    msg.setDestinationEntity(47U);

    try
    {
      Utils::ByteBuffer bfr;
      IMC::Packet::serialize(&msg, bfr);
      IMC::Message* msg_d = IMC::Packet::deserialize(bfr.getBuffer(), bfr.getSize());
      test.boolean("Aborted #2", msg == *msg_d);
      delete msg_d;
    }
    catch (IMC::InvalidMessageSize& e)
    {
      (void)e;
      test.boolean("msg #2", msg.getSerializationSize() > DUNE_IMC_CONST_MAX_SIZE);
    }
  }

  {
    IMC::UsblAngles msg;
    msg.setTimeStamp(0.89480915685855);
    msg.setSource(44385U);
    msg.setSourceEntity(124U);
    msg.setDestination(53891U);
    msg.setDestinationEntity(254U);
    msg.target = 19528U;
    msg.bearing = 0.9451509758952179;
    msg.elevation = 0.04389955675002877;

    try
    {
      Utils::ByteBuffer bfr;
      IMC::Packet::serialize(&msg, bfr);
      IMC::Message* msg_d = IMC::Packet::deserialize(bfr.getBuffer(), bfr.getSize());
      test.boolean("UsblAngles #0", msg == *msg_d);
      delete msg_d;
    }
    catch (IMC::InvalidMessageSize& e)
    {
      (void)e;
      test.boolean("msg #0", msg.getSerializationSize() > DUNE_IMC_CONST_MAX_SIZE);
    }
  }

  {
    IMC::UsblAngles msg;
    msg.setTimeStamp(0.24059982143348602);
    msg.setSource(33778U);
    msg.setSourceEntity(119U);
    msg.setDestination(3661U);
    msg.setDestinationEntity(234U);
    msg.target = 28423U;
    msg.bearing = 0.887699285199055;
    msg.elevation = 0.09362686312586332;

    try
    {
      Utils::ByteBuffer bfr;
      IMC::Packet::serialize(&msg, bfr);
      IMC::Message* msg_d = IMC::Packet::deserialize(bfr.getBuffer(), bfr.getSize());
      test.boolean("UsblAngles #1", msg == *msg_d);
      delete msg_d;
    }
    catch (IMC::InvalidMessageSize& e)
    {
      (void)e;
      test.boolean("msg #1", msg.getSerializationSize() > DUNE_IMC_CONST_MAX_SIZE);
    }
  }

  {
    IMC::UsblAngles msg;
    msg.setTimeStamp(0.967088135573481);
    msg.setSource(64288U);
    msg.setSourceEntity(68U);
    msg.setDestination(13776U);
    msg.setDestinationEntity(148U);
    msg.target = 36948U;
    msg.bearing = 0.5459230938223537;
    msg.elevation = 0.43239942413907884;

    try
    {
      Utils::ByteBuffer bfr;
      IMC::Packet::serialize(&msg, bfr);
      IMC::Message* msg_d = IMC::Packet::deserialize(bfr.getBuffer(), bfr.getSize());
      test.boolean("UsblAngles #2", msg == *msg_d);
      delete msg_d;
    }
    catch (IMC::InvalidMessageSize& e)
    {
      (void)e;
      test.boolean("msg #2", msg.getSerializationSize() > DUNE_IMC_CONST_MAX_SIZE);
    }
  }

  {
    IMC::UsblPosition msg;
    msg.setTimeStamp(0.14468298782535716);
    msg.setSource(803U);
    msg.setSourceEntity(28U);
    msg.setDestination(2812U);
    msg.setDestinationEntity(154U);
    msg.target = 43813U;
    msg.x = 0.4019036326347746;
    msg.y = 0.5074911751391684;
    msg.z = 0.3353830023478841;

    try
    {
      Utils::ByteBuffer bfr;
      IMC::Packet::serialize(&msg, bfr);
      IMC::Message* msg_d = IMC::Packet::deserialize(bfr.getBuffer(), bfr.getSize());
      test.boolean("UsblPosition #0", msg == *msg_d);
      delete msg_d;
    }
    catch (IMC::InvalidMessageSize& e)
    {
      (void)e;
      test.boolean("msg #0", msg.getSerializationSize() > DUNE_IMC_CONST_MAX_SIZE);
    }
  }

  {
    IMC::UsblPosition msg;
    msg.setTimeStamp(0.07003493935399363);
    msg.setSource(12417U);
    msg.setSourceEntity(166U);
    msg.setDestination(53506U);
    msg.setDestinationEntity(238U);
    msg.target = 25425U;
    msg.x = 0.09433770599078684;
    msg.y = 0.37680988050266895;
    msg.z = 0.36635437942943827;

    try
    {
      Utils::ByteBuffer bfr;
      IMC::Packet::serialize(&msg, bfr);
      IMC::Message* msg_d = IMC::Packet::deserialize(bfr.getBuffer(), bfr.getSize());
      test.boolean("UsblPosition #1", msg == *msg_d);
      delete msg_d;
    }
    catch (IMC::InvalidMessageSize& e)
    {
      (void)e;
      test.boolean("msg #1", msg.getSerializationSize() > DUNE_IMC_CONST_MAX_SIZE);
    }
  }

  {
    IMC::UsblPosition msg;
    msg.setTimeStamp(0.4444217085117761);
    msg.setSource(44996U);
    msg.setSourceEntity(69U);
    msg.setDestination(9361U);
    msg.setDestinationEntity(181U);
    msg.target = 53411U;
    msg.x = 0.8325502034044215;
    msg.y = 0.8831225872084293;
    msg.z = 0.7048213907932175;

    try
    {
      Utils::ByteBuffer bfr;
      IMC::Packet::serialize(&msg, bfr);
      IMC::Message* msg_d = IMC::Packet::deserialize(bfr.getBuffer(), bfr.getSize());
      test.boolean("UsblPosition #2", msg == *msg_d);
      delete msg_d;
    }
    catch (IMC::InvalidMessageSize& e)
    {
      (void)e;
      test.boolean("msg #2", msg.getSerializationSize() > DUNE_IMC_CONST_MAX_SIZE);
    }
  }

  {
    IMC::UsblFix msg;
    msg.setTimeStamp(0.30693441845782665);
    msg.setSource(51354U);
    msg.setSourceEntity(167U);
    msg.setDestination(53436U);
    msg.setDestinationEntity(115U);
    msg.target = 25813U;
    msg.lat = 0.9172290134985391;
    msg.lon = 0.8471333562064856;
    msg.z_units = 61U;
    msg.z = 0.1915714550568427;

    try
    {
      Utils::ByteBuffer bfr;
      IMC::Packet::serialize(&msg, bfr);
      IMC::Message* msg_d = IMC::Packet::deserialize(bfr.getBuffer(), bfr.getSize());
      test.boolean("UsblFix #0", msg == *msg_d);
      delete msg_d;
    }
    catch (IMC::InvalidMessageSize& e)
    {
      (void)e;
      test.boolean("msg #0", msg.getSerializationSize() > DUNE_IMC_CONST_MAX_SIZE);
    }
  }

  {
    IMC::UsblFix msg;
    msg.setTimeStamp(0.2660462962251282);
    msg.setSource(42085U);
    msg.setSourceEntity(83U);
    msg.setDestination(35076U);
    msg.setDestinationEntity(28U);
    msg.target = 40131U;
    msg.lat = 0.9850367330454717;
    msg.lon = 0.3911311236155076;
    msg.z_units = 233U;
    msg.z = 0.8242861923425872;

    try
    {
      Utils::ByteBuffer bfr;
      IMC::Packet::serialize(&msg, bfr);
      IMC::Message* msg_d = IMC::Packet::deserialize(bfr.getBuffer(), bfr.getSize());
      test.boolean("UsblFix #1", msg == *msg_d);
      delete msg_d;
    }
    catch (IMC::InvalidMessageSize& e)
    {
      (void)e;
      test.boolean("msg #1", msg.getSerializationSize() > DUNE_IMC_CONST_MAX_SIZE);
    }
  }

  {
    IMC::UsblFix msg;
    msg.setTimeStamp(0.07269048102243003);
    msg.setSource(37723U);
    msg.setSourceEntity(138U);
    msg.setDestination(31371U);
    msg.setDestinationEntity(171U);
    msg.target = 43259U;
    msg.lat = 0.5497431140145773;
    msg.lon = 0.13100534376220718;
    msg.z_units = 147U;
    msg.z = 0.6753486818894515;

    try
    {
      Utils::ByteBuffer bfr;
      IMC::Packet::serialize(&msg, bfr);
      IMC::Message* msg_d = IMC::Packet::deserialize(bfr.getBuffer(), bfr.getSize());
      test.boolean("UsblFix #2", msg == *msg_d);
      delete msg_d;
    }
    catch (IMC::InvalidMessageSize& e)
    {
      (void)e;
      test.boolean("msg #2", msg.getSerializationSize() > DUNE_IMC_CONST_MAX_SIZE);
    }
  }

  {
    IMC::ParametersXml msg;
    msg.setTimeStamp(0.5053446504290282);
    msg.setSource(3847U);
    msg.setSourceEntity(104U);
    msg.setDestination(27596U);
    msg.setDestinationEntity(98U);
    msg.locale.assign("TPRIZDNSTCCCEHKMGOGAKFGVKNWDZYPTFAHUEZ");
    const signed char tmp_msg_0[] = {-73, -50, -62, 37, 91, 78, -52, -66, -58, -25, -81, -108, 23, 92, -54, 102, -24, -85, -44, 33, -89, 85, 84, -67, -80, 4, 80, 64, 78, 97, 17, -53, -127, 32, 59, 36, 80, 7, 71, -36, -76, 19, 42, -49, 99, 71, 24, -116, 12, 86, 47, 121, 24, -43, -86, -94, -74, -125, -36, -77, -116, -111, 80, -79, -112, -15, -24, 4, 104, 107, 36, -101, -74, 34, -107, -32, -66, 126, -126, 105, -35, 89, 118, -86, 26, 33, 116, 3, 106, -100, -54, 80, 48, 13, -78, -23, -11, 11, 95, 44, -2, -44, -85, -106, -51, 79, 124, -81, -53, -107, -70, 97, 101, 25, 25, 29, 53, -45, 77, 27, -121, 76, 14, -54, -34, -112, -34, -102, 110, -26, -43, 2, -15, -53, 36, -64, -18, 72, -79, 33, 69, -95, 106, 32, 91, -37, -71, -30, 32, -57, 83, 107, -57, -85, -71, -57, 53, -4, -114, 68, -99, -122, -110, -100, -82, 16, -8, -58, -109, -107, -27, 121, 47, -31, -82, -19, -44, -33, 10, 85, 109, -78, -91, 6, 14, -75, 19, 2, -84, 33, 29, -50, 53, -49, 108, -29, -58, -120, 29, 113, -42, 20, -95, -109, 30, 82, -13, -50, -107, -99, 25, -73, 26, 122, -12, 30, -82, -98, 91, 52, -61, 10, -110, 107, 3, -19, 82, -15, 70, -57};
    msg.config.assign(tmp_msg_0, tmp_msg_0 + sizeof(tmp_msg_0));

    try
    {
      Utils::ByteBuffer bfr;
      IMC::Packet::serialize(&msg, bfr);
      IMC::Message* msg_d = IMC::Packet::deserialize(bfr.getBuffer(), bfr.getSize());
      test.boolean("ParametersXml #0", msg == *msg_d);
      delete msg_d;
    }
    catch (IMC::InvalidMessageSize& e)
    {
      (void)e;
      test.boolean("msg #0", msg.getSerializationSize() > DUNE_IMC_CONST_MAX_SIZE);
    }
  }

  {
    IMC::ParametersXml msg;
    msg.setTimeStamp(0.0668759647912388);
    msg.setSource(48431U);
    msg.setSourceEntity(119U);
    msg.setDestination(25270U);
    msg.setDestinationEntity(69U);
    msg.locale.assign("TVCSMJQHEUEAHWSFCRBNDYLBPOPMVUWEMNRVLJBLBDTOIKC");
    const signed char tmp_msg_0[] = {-4, 117, -32, 94, -68, 1, 43, -88, 114, 83, -99, -10, 63, -102, 126, 4, -52, 92, 73, -59, 17, -39, -82, 45, -20, 106, 6, -6, -82, 9, 31, 79, -26, -43, 50, -117, 48, 16, -86, -42, 66, 110, -18, -34, -71, -61, -55, -29, 84, 71, 107, 90, -113, -96, 4, 8, -119, 77, -45, 49, -76, -37, 45, -52, 25, -107, -74, -3, -21, -1, 19, -107, 97, -52, 121, 124, 62, 22, -24, -2, -13, 125, 109, 118, -50, -117, -58, -37, 56, 86, 59, -110, 54, 78, 14, 94, -117, -59, 87, -111, 32, -111, 58, 125, -45, -22, -32, 71, 119, 30, 53, -16, 50, -97, -122, -29, -76, 48, -98, -101, 13, -101, -74, 6, -33, 11, -25, 78, 78, -117, -83, -64, -79, 123, 96, 57, -87, -11, 75, -74, -61, 61, 56, -97, -125, -26, 1, 62, 9, 99, -126, -116, 96, 39, -65, 13, 31, 43, -108, -89, 71, -106, 50, -91, -92, 36, -1, 110, -58, 92, 90, 122, -59, -32, 68, 6, -49, -68, 112, 101, -89, 95, 85, -3, -84, 15, -57, 100, -60, 11, -123, 125, 100, -81, -49, -17, 71, 34, 7, -105, 34, -99, -55, 57, 112, 124, 85, 77, -115, 84, 62, -75, 97, 75, -54, -21, 123, 100, -63, 102, -1, 105, -127, 71, 22, -92, 0, -52, -60, -120, -97, -36, 91, 39, 87, -72, -84, -13};
    msg.config.assign(tmp_msg_0, tmp_msg_0 + sizeof(tmp_msg_0));

    try
    {
      Utils::ByteBuffer bfr;
      IMC::Packet::serialize(&msg, bfr);
      IMC::Message* msg_d = IMC::Packet::deserialize(bfr.getBuffer(), bfr.getSize());
      test.boolean("ParametersXml #1", msg == *msg_d);
      delete msg_d;
    }
    catch (IMC::InvalidMessageSize& e)
    {
      (void)e;
      test.boolean("msg #1", msg.getSerializationSize() > DUNE_IMC_CONST_MAX_SIZE);
    }
  }

  {
    IMC::ParametersXml msg;
    msg.setTimeStamp(0.07509896467455213);
    msg.setSource(44126U);
    msg.setSourceEntity(163U);
    msg.setDestination(11753U);
    msg.setDestinationEntity(93U);
    msg.locale.assign("TYGHAPHUKJXXJXCHOEEZPLRTPBGWBXESSPPINMWEVLQGAZEUFWHYFGIYCKMQMKFSUXCJONVHMEDTVWRYXRHMN");
    const signed char tmp_msg_0[] = {-97, -120, -67, 21, -78, 99, 70, 112, 115, 85, -103, 40, -126, 15, 35, -14, 12, 78, -5, 54, -111, -27, 0, -29, -42, 51, -111, 116, -29, 122, -7, 59, -71, 83, 113, 105, 9, 76, 67, 44, -58, -40, -110, 88, 83, 89, 110, -1, 114, -91, -102, -49, -68, -78, 114, -88, 93, 107, 98, 49, -13, -98};
    msg.config.assign(tmp_msg_0, tmp_msg_0 + sizeof(tmp_msg_0));

    try
    {
      Utils::ByteBuffer bfr;
      IMC::Packet::serialize(&msg, bfr);
      IMC::Message* msg_d = IMC::Packet::deserialize(bfr.getBuffer(), bfr.getSize());
      test.boolean("ParametersXml #2", msg == *msg_d);
      delete msg_d;
    }
    catch (IMC::InvalidMessageSize& e)
    {
      (void)e;
      test.boolean("msg #2", msg.getSerializationSize() > DUNE_IMC_CONST_MAX_SIZE);
    }
  }

  {
    IMC::GetParametersXml msg;
    msg.setTimeStamp(0.5012801144012613);
    msg.setSource(23872U);
    msg.setSourceEntity(108U);
    msg.setDestination(62568U);
    msg.setDestinationEntity(230U);

    try
    {
      Utils::ByteBuffer bfr;
      IMC::Packet::serialize(&msg, bfr);
      IMC::Message* msg_d = IMC::Packet::deserialize(bfr.getBuffer(), bfr.getSize());
      test.boolean("GetParametersXml #0", msg == *msg_d);
      delete msg_d;
    }
    catch (IMC::InvalidMessageSize& e)
    {
      (void)e;
      test.boolean("msg #0", msg.getSerializationSize() > DUNE_IMC_CONST_MAX_SIZE);
    }
  }

  {
    IMC::GetParametersXml msg;
    msg.setTimeStamp(0.2022487073928093);
    msg.setSource(19125U);
    msg.setSourceEntity(121U);
    msg.setDestination(45832U);
    msg.setDestinationEntity(163U);

    try
    {
      Utils::ByteBuffer bfr;
      IMC::Packet::serialize(&msg, bfr);
      IMC::Message* msg_d = IMC::Packet::deserialize(bfr.getBuffer(), bfr.getSize());
      test.boolean("GetParametersXml #1", msg == *msg_d);
      delete msg_d;
    }
    catch (IMC::InvalidMessageSize& e)
    {
      (void)e;
      test.boolean("msg #1", msg.getSerializationSize() > DUNE_IMC_CONST_MAX_SIZE);
    }
  }

  {
    IMC::GetParametersXml msg;
    msg.setTimeStamp(0.412332862468605);
    msg.setSource(30636U);
    msg.setSourceEntity(137U);
    msg.setDestination(37670U);
    msg.setDestinationEntity(252U);

    try
    {
      Utils::ByteBuffer bfr;
      IMC::Packet::serialize(&msg, bfr);
      IMC::Message* msg_d = IMC::Packet::deserialize(bfr.getBuffer(), bfr.getSize());
      test.boolean("GetParametersXml #2", msg == *msg_d);
      delete msg_d;
    }
    catch (IMC::InvalidMessageSize& e)
    {
      (void)e;
      test.boolean("msg #2", msg.getSerializationSize() > DUNE_IMC_CONST_MAX_SIZE);
    }
  }

  {
    IMC::SetImageCoords msg;
    msg.setTimeStamp(0.6986879012231952);
    msg.setSource(12695U);
    msg.setSourceEntity(181U);
    msg.setDestination(28364U);
    msg.setDestinationEntity(199U);
    msg.camid = 229U;
    msg.x = 32010U;
    msg.y = 47033U;

    try
    {
      Utils::ByteBuffer bfr;
      IMC::Packet::serialize(&msg, bfr);
      IMC::Message* msg_d = IMC::Packet::deserialize(bfr.getBuffer(), bfr.getSize());
      test.boolean("SetImageCoords #0", msg == *msg_d);
      delete msg_d;
    }
    catch (IMC::InvalidMessageSize& e)
    {
      (void)e;
      test.boolean("msg #0", msg.getSerializationSize() > DUNE_IMC_CONST_MAX_SIZE);
    }
  }

  {
    IMC::SetImageCoords msg;
    msg.setTimeStamp(0.44375093262584386);
    msg.setSource(61496U);
    msg.setSourceEntity(39U);
    msg.setDestination(39075U);
    msg.setDestinationEntity(74U);
    msg.camid = 124U;
    msg.x = 40318U;
    msg.y = 47775U;

    try
    {
      Utils::ByteBuffer bfr;
      IMC::Packet::serialize(&msg, bfr);
      IMC::Message* msg_d = IMC::Packet::deserialize(bfr.getBuffer(), bfr.getSize());
      test.boolean("SetImageCoords #1", msg == *msg_d);
      delete msg_d;
    }
    catch (IMC::InvalidMessageSize& e)
    {
      (void)e;
      test.boolean("msg #1", msg.getSerializationSize() > DUNE_IMC_CONST_MAX_SIZE);
    }
  }

  {
    IMC::SetImageCoords msg;
    msg.setTimeStamp(0.18578431973859444);
    msg.setSource(63258U);
    msg.setSourceEntity(183U);
    msg.setDestination(40448U);
    msg.setDestinationEntity(157U);
    msg.camid = 83U;
    msg.x = 2129U;
    msg.y = 41352U;

    try
    {
      Utils::ByteBuffer bfr;
      IMC::Packet::serialize(&msg, bfr);
      IMC::Message* msg_d = IMC::Packet::deserialize(bfr.getBuffer(), bfr.getSize());
      test.boolean("SetImageCoords #2", msg == *msg_d);
      delete msg_d;
    }
    catch (IMC::InvalidMessageSize& e)
    {
      (void)e;
      test.boolean("msg #2", msg.getSerializationSize() > DUNE_IMC_CONST_MAX_SIZE);
    }
  }

  {
    IMC::GetImageCoords msg;
    msg.setTimeStamp(0.14980809003185014);
    msg.setSource(47231U);
    msg.setSourceEntity(115U);
    msg.setDestination(4093U);
    msg.setDestinationEntity(57U);
    msg.camid = 190U;
    msg.x = 3496U;
    msg.y = 51717U;

    try
    {
      Utils::ByteBuffer bfr;
      IMC::Packet::serialize(&msg, bfr);
      IMC::Message* msg_d = IMC::Packet::deserialize(bfr.getBuffer(), bfr.getSize());
      test.boolean("GetImageCoords #0", msg == *msg_d);
      delete msg_d;
    }
    catch (IMC::InvalidMessageSize& e)
    {
      (void)e;
      test.boolean("msg #0", msg.getSerializationSize() > DUNE_IMC_CONST_MAX_SIZE);
    }
  }

  {
    IMC::GetImageCoords msg;
    msg.setTimeStamp(0.28297928898787084);
    msg.setSource(52009U);
    msg.setSourceEntity(21U);
    msg.setDestination(17654U);
    msg.setDestinationEntity(179U);
    msg.camid = 204U;
    msg.x = 11658U;
    msg.y = 44048U;

    try
    {
      Utils::ByteBuffer bfr;
      IMC::Packet::serialize(&msg, bfr);
      IMC::Message* msg_d = IMC::Packet::deserialize(bfr.getBuffer(), bfr.getSize());
      test.boolean("GetImageCoords #1", msg == *msg_d);
      delete msg_d;
    }
    catch (IMC::InvalidMessageSize& e)
    {
      (void)e;
      test.boolean("msg #1", msg.getSerializationSize() > DUNE_IMC_CONST_MAX_SIZE);
    }
  }

  {
    IMC::GetImageCoords msg;
    msg.setTimeStamp(0.3166802902651382);
    msg.setSource(5821U);
    msg.setSourceEntity(222U);
    msg.setDestination(59076U);
    msg.setDestinationEntity(125U);
    msg.camid = 28U;
    msg.x = 20730U;
    msg.y = 49330U;

    try
    {
      Utils::ByteBuffer bfr;
      IMC::Packet::serialize(&msg, bfr);
      IMC::Message* msg_d = IMC::Packet::deserialize(bfr.getBuffer(), bfr.getSize());
      test.boolean("GetImageCoords #2", msg == *msg_d);
      delete msg_d;
    }
    catch (IMC::InvalidMessageSize& e)
    {
      (void)e;
      test.boolean("msg #2", msg.getSerializationSize() > DUNE_IMC_CONST_MAX_SIZE);
    }
  }

  {
    IMC::GetWorldCoordinates msg;
    msg.setTimeStamp(0.24720846523061235);
    msg.setSource(53744U);
    msg.setSourceEntity(120U);
    msg.setDestination(57780U);
    msg.setDestinationEntity(67U);
    msg.tracking = 119U;
    msg.lat = 0.16756637842544475;
    msg.lon = 0.186784825699306;
    msg.x = 0.5365802996455875;
    msg.y = 0.7013477474551542;
    msg.z = 0.020202347380050334;

    try
    {
      Utils::ByteBuffer bfr;
      IMC::Packet::serialize(&msg, bfr);
      IMC::Message* msg_d = IMC::Packet::deserialize(bfr.getBuffer(), bfr.getSize());
      test.boolean("GetWorldCoordinates #0", msg == *msg_d);
      delete msg_d;
    }
    catch (IMC::InvalidMessageSize& e)
    {
      (void)e;
      test.boolean("msg #0", msg.getSerializationSize() > DUNE_IMC_CONST_MAX_SIZE);
    }
  }

  {
    IMC::GetWorldCoordinates msg;
    msg.setTimeStamp(0.7603395527397465);
    msg.setSource(54944U);
    msg.setSourceEntity(194U);
    msg.setDestination(58726U);
    msg.setDestinationEntity(2U);
    msg.tracking = 76U;
    msg.lat = 0.9432369103317199;
    msg.lon = 0.7633609460906987;
    msg.x = 0.35516429598027355;
    msg.y = 0.5438171137409971;
    msg.z = 0.6422552732792901;

    try
    {
      Utils::ByteBuffer bfr;
      IMC::Packet::serialize(&msg, bfr);
      IMC::Message* msg_d = IMC::Packet::deserialize(bfr.getBuffer(), bfr.getSize());
      test.boolean("GetWorldCoordinates #1", msg == *msg_d);
      delete msg_d;
    }
    catch (IMC::InvalidMessageSize& e)
    {
      (void)e;
      test.boolean("msg #1", msg.getSerializationSize() > DUNE_IMC_CONST_MAX_SIZE);
    }
  }

  {
    IMC::GetWorldCoordinates msg;
    msg.setTimeStamp(0.4853876783250265);
    msg.setSource(58378U);
    msg.setSourceEntity(240U);
    msg.setDestination(16520U);
    msg.setDestinationEntity(175U);
    msg.tracking = 231U;
    msg.lat = 0.02592274140810713;
    msg.lon = 0.9711755395970808;
    msg.x = 0.3842505796385679;
    msg.y = 0.696758518794065;
    msg.z = 0.7920478055167413;

    try
    {
      Utils::ByteBuffer bfr;
      IMC::Packet::serialize(&msg, bfr);
      IMC::Message* msg_d = IMC::Packet::deserialize(bfr.getBuffer(), bfr.getSize());
      test.boolean("GetWorldCoordinates #2", msg == *msg_d);
      delete msg_d;
    }
    catch (IMC::InvalidMessageSize& e)
    {
      (void)e;
      test.boolean("msg #2", msg.getSerializationSize() > DUNE_IMC_CONST_MAX_SIZE);
    }
  }

  {
    IMC::UsblAnglesExtended msg;
    msg.setTimeStamp(0.3746411344074815);
    msg.setSource(1449U);
    msg.setSourceEntity(139U);
    msg.setDestination(61800U);
    msg.setDestinationEntity(146U);
    msg.target.assign("TVIOIAMUAGBQNXXPJMESTDYAIZGPFMXLQSHZYAQLDKBTGFZTLUKPROFFQSGZCYXXIPDJDXQNKEUWVJMKVRRPWFDBCSOOXNTUXQJBGIWMWBMLMFHLAQOIYHWDFQNVNTRNEGMVZNSSLGOCEOJICPEG");
    msg.lbearing = 0.8693277636077955;
    msg.lelevation = 0.9368310199247158;
    msg.bearing = 0.04815415099486642;
    msg.elevation = 0.3575814041372136;
    msg.phi = 0.1748607983907946;
    msg.theta = 0.9225005623915399;
    msg.psi = 0.04775616178720421;
    msg.accuracy = 0.723998421973279;

    try
    {
      Utils::ByteBuffer bfr;
      IMC::Packet::serialize(&msg, bfr);
      IMC::Message* msg_d = IMC::Packet::deserialize(bfr.getBuffer(), bfr.getSize());
      test.boolean("UsblAnglesExtended #0", msg == *msg_d);
      delete msg_d;
    }
    catch (IMC::InvalidMessageSize& e)
    {
      (void)e;
      test.boolean("msg #0", msg.getSerializationSize() > DUNE_IMC_CONST_MAX_SIZE);
    }
  }

  {
    IMC::UsblAnglesExtended msg;
    msg.setTimeStamp(0.3078168272741284);
    msg.setSource(29212U);
    msg.setSourceEntity(2U);
    msg.setDestination(33044U);
    msg.setDestinationEntity(191U);
    msg.target.assign("GPXSPJIYTFVYQFELBQICAUMWRCOLZKDUBNJZCPYGOOGKKNNRHJBFHCPCRRLPAQTVTLHREJNDMKEOKPMNSUCQOHJPHERXUACSMXVIAVZACLUWIFEMOYNOGVONIQYFDQQEVFQGFMSUNBYFXSFZPJXWHQDCRWJKDJCRLZIRYDKWSTELMEXO");
    msg.lbearing = 0.5758950404846274;
    msg.lelevation = 0.3560011097854714;
    msg.bearing = 0.3126243418325736;
    msg.elevation = 0.553219476341692;
    msg.phi = 0.8450977086426229;
    msg.theta = 0.19256234944125217;
    msg.psi = 0.0890499359020237;
    msg.accuracy = 0.01224456863021095;

    try
    {
      Utils::ByteBuffer bfr;
      IMC::Packet::serialize(&msg, bfr);
      IMC::Message* msg_d = IMC::Packet::deserialize(bfr.getBuffer(), bfr.getSize());
      test.boolean("UsblAnglesExtended #1", msg == *msg_d);
      delete msg_d;
    }
    catch (IMC::InvalidMessageSize& e)
    {
      (void)e;
      test.boolean("msg #1", msg.getSerializationSize() > DUNE_IMC_CONST_MAX_SIZE);
    }
  }

  {
    IMC::UsblAnglesExtended msg;
    msg.setTimeStamp(0.44581980155485823);
    msg.setSource(28053U);
    msg.setSourceEntity(154U);
    msg.setDestination(13948U);
    msg.setDestinationEntity(193U);
    msg.target.assign("QHTCYWPFFVTCVBZUXEISMCDNCEYOGVURKFBJCLTJPBNGAQGGLIUMXDUFWSYSJXRNEIQRVRGIWEZAMFGDUQKRAXIEZNGSVCKPLEQVNJNASHVKDBDWRUZQLFMBVCSGNKOYLQZZXPWLDPOROWYRUIFUWAJLMBBIOMHENMTZWLPBUVTHXGWIBCJJXPHJASATCUKYSLKJKYOTSHBNECGFPEHOWKYNYMPSAHTPDRDVMQOYMAHFEHOIRKT");
    msg.lbearing = 0.41505482414436035;
    msg.lelevation = 0.7283468318810039;
    msg.bearing = 0.19570152958375442;
    msg.elevation = 0.752597059715015;
    msg.phi = 0.6585700035684723;
    msg.theta = 0.3497108237996944;
    msg.psi = 0.3549341606667695;
    msg.accuracy = 0.34652662506284115;

    try
    {
      Utils::ByteBuffer bfr;
      IMC::Packet::serialize(&msg, bfr);
      IMC::Message* msg_d = IMC::Packet::deserialize(bfr.getBuffer(), bfr.getSize());
      test.boolean("UsblAnglesExtended #2", msg == *msg_d);
      delete msg_d;
    }
    catch (IMC::InvalidMessageSize& e)
    {
      (void)e;
      test.boolean("msg #2", msg.getSerializationSize() > DUNE_IMC_CONST_MAX_SIZE);
    }
  }

  {
    IMC::UsblPositionExtended msg;
    msg.setTimeStamp(0.5503169080970286);
    msg.setSource(40053U);
    msg.setSourceEntity(113U);
    msg.setDestination(21195U);
    msg.setDestinationEntity(81U);
    msg.target.assign("MAKMVEYTLZRBVVWXGPZTAWXKCELKAJUFXUBEQGLUXDUEYGPMHSKWNHUJRGYNJTYZUTAGQASJZOLQSDUEDCVONYUTHVVPPOFQCCGDKRSYPYHXKWWYIE");
    msg.x = 0.4624919766260198;
    msg.y = 0.3351894214164979;
    msg.z = 0.17399270198671157;
    msg.n = 0.33657739906504447;
    msg.e = 0.7810267718694887;
    msg.d = 0.9854862518007746;
    msg.phi = 0.8711520198105858;
    msg.theta = 0.16441502947494224;
    msg.psi = 0.6069428646800643;
    msg.accuracy = 0.21674338480782795;

    try
    {
      Utils::ByteBuffer bfr;
      IMC::Packet::serialize(&msg, bfr);
      IMC::Message* msg_d = IMC::Packet::deserialize(bfr.getBuffer(), bfr.getSize());
      test.boolean("UsblPositionExtended #0", msg == *msg_d);
      delete msg_d;
    }
    catch (IMC::InvalidMessageSize& e)
    {
      (void)e;
      test.boolean("msg #0", msg.getSerializationSize() > DUNE_IMC_CONST_MAX_SIZE);
    }
  }

  {
    IMC::UsblPositionExtended msg;
    msg.setTimeStamp(0.47558468571917545);
    msg.setSource(20110U);
    msg.setSourceEntity(39U);
    msg.setDestination(35147U);
    msg.setDestinationEntity(54U);
    msg.target.assign("RLRGSKSUGYBHNNJVWVNTOZHTZLX");
    msg.x = 0.21035871654629934;
    msg.y = 0.6365885486215126;
    msg.z = 0.3074360316316841;
    msg.n = 0.8313358816771235;
    msg.e = 0.628902645825523;
    msg.d = 0.20944717806503732;
    msg.phi = 0.734969354125897;
    msg.theta = 0.534184576669366;
    msg.psi = 0.7448174029556587;
    msg.accuracy = 0.7273529158209648;

    try
    {
      Utils::ByteBuffer bfr;
      IMC::Packet::serialize(&msg, bfr);
      IMC::Message* msg_d = IMC::Packet::deserialize(bfr.getBuffer(), bfr.getSize());
      test.boolean("UsblPositionExtended #1", msg == *msg_d);
      delete msg_d;
    }
    catch (IMC::InvalidMessageSize& e)
    {
      (void)e;
      test.boolean("msg #1", msg.getSerializationSize() > DUNE_IMC_CONST_MAX_SIZE);
    }
  }

  {
    IMC::UsblPositionExtended msg;
    msg.setTimeStamp(0.42294433142811005);
    msg.setSource(1953U);
    msg.setSourceEntity(24U);
    msg.setDestination(1033U);
    msg.setDestinationEntity(226U);
    msg.target.assign("XFFBJQUHMIVXLEKHAALOIHMYRJTZSBADEXEWGPERJMIXBPQILUVMMZGTKYGYIOEVPLXPSAWOTLXZVSNNIPGQPCWZSLVNJPJWZDSTMFWKHEGVKJWVFBRKTYOTBWOCHFCZFDYIUUCTNLTVNECNSBZDQRKBWNYURQOJUCFXCUSFWUJCCGKNQAISLYHTRDWGEDXDIAFRQODZDPGQYZQKPPXYOCGMBHLSHD");
    msg.x = 0.5297486487265011;
    msg.y = 0.8549989116215994;
    msg.z = 0.0407616886861788;
    msg.n = 0.12466854674931982;
    msg.e = 0.1726969757369906;
    msg.d = 0.7590128886822352;
    msg.phi = 0.5783895840115593;
    msg.theta = 0.4037690488169995;
    msg.psi = 0.1249805456650449;
    msg.accuracy = 0.42202540849146253;

    try
    {
      Utils::ByteBuffer bfr;
      IMC::Packet::serialize(&msg, bfr);
      IMC::Message* msg_d = IMC::Packet::deserialize(bfr.getBuffer(), bfr.getSize());
      test.boolean("UsblPositionExtended #2", msg == *msg_d);
      delete msg_d;
    }
    catch (IMC::InvalidMessageSize& e)
    {
      (void)e;
      test.boolean("msg #2", msg.getSerializationSize() > DUNE_IMC_CONST_MAX_SIZE);
    }
  }

  {
    IMC::UsblFixExtended msg;
    msg.setTimeStamp(0.1365247525560972);
    msg.setSource(8608U);
    msg.setSourceEntity(198U);
    msg.setDestination(9198U);
    msg.setDestinationEntity(141U);
    msg.target.assign("LGAPNIKYGAKVQMWWOMYTHDOTLHGCOLDIAUFZRWNHXZOABNEOMEWUHEMDYBAOCUQTNZNCBCJRSJVPHSUCFWPXEENNVQVGPVNEJSVTENHJHJXIPGRCRKGGPIJUDUFAQQSDHFQWBRAMMYMQFYWYRAZFLXDDJFVEDHUTBXYVQXSSTIVOMKZIOIOCYKRWCBSKCRTEPXGKOPIFZIBSPGLTWXIMZRKT");
    msg.lat = 0.3000305965511322;
    msg.lon = 0.7559583958576007;
    msg.z_units = 110U;
    msg.z = 0.596363665081823;
    msg.accuracy = 0.8483692507072882;

    try
    {
      Utils::ByteBuffer bfr;
      IMC::Packet::serialize(&msg, bfr);
      IMC::Message* msg_d = IMC::Packet::deserialize(bfr.getBuffer(), bfr.getSize());
      test.boolean("UsblFixExtended #0", msg == *msg_d);
      delete msg_d;
    }
    catch (IMC::InvalidMessageSize& e)
    {
      (void)e;
      test.boolean("msg #0", msg.getSerializationSize() > DUNE_IMC_CONST_MAX_SIZE);
    }
  }

  {
    IMC::UsblFixExtended msg;
    msg.setTimeStamp(0.9925519438175454);
    msg.setSource(31670U);
    msg.setSourceEntity(74U);
    msg.setDestination(38697U);
    msg.setDestinationEntity(238U);
    msg.target.assign("QEANUHILHISYOHNTVXMAGBZLKQUCDEFLTNNOUJYSDXOWFIIPEZNRKAFQYLPFRCSBYOYEMQGQZAVGRQUIJCYSBGLBMKRBZFPGAKTTUAIZMTCUXGGUOTLBCFOKJXMQHAPOXCUHEJDEXXNDQIWJVRTTFVHVVBM");
    msg.lat = 0.9849228237716614;
    msg.lon = 0.8770166124728859;
    msg.z_units = 39U;
    msg.z = 0.5441040788457553;
    msg.accuracy = 0.5254663803552682;

    try
    {
      Utils::ByteBuffer bfr;
      IMC::Packet::serialize(&msg, bfr);
      IMC::Message* msg_d = IMC::Packet::deserialize(bfr.getBuffer(), bfr.getSize());
      test.boolean("UsblFixExtended #1", msg == *msg_d);
      delete msg_d;
    }
    catch (IMC::InvalidMessageSize& e)
    {
      (void)e;
      test.boolean("msg #1", msg.getSerializationSize() > DUNE_IMC_CONST_MAX_SIZE);
    }
  }

  {
    IMC::UsblFixExtended msg;
    msg.setTimeStamp(0.9619528455669685);
    msg.setSource(13975U);
    msg.setSourceEntity(211U);
    msg.setDestination(11018U);
    msg.setDestinationEntity(167U);
    msg.target.assign("QUPOBBNFAIXFTICLNNLPSBFHUXNXBCOHDKBPKDEDJMQYVWMKDGGZACOOLLOFIUJSLWXJGPQRYIJZZUSRVDHVACVVLQAUEMTBQLKUYOCGVOMGVYNNTGGFICHGAWPECGUTTEBDEJSZYESYOWXAEZNVRKTPJXSYINOZXFP");
    msg.lat = 0.1431224614121117;
    msg.lon = 0.5528786028096395;
    msg.z_units = 223U;
    msg.z = 0.020934068422659546;
    msg.accuracy = 0.20879128333612407;

    try
    {
      Utils::ByteBuffer bfr;
      IMC::Packet::serialize(&msg, bfr);
      IMC::Message* msg_d = IMC::Packet::deserialize(bfr.getBuffer(), bfr.getSize());
      test.boolean("UsblFixExtended #2", msg == *msg_d);
      delete msg_d;
    }
    catch (IMC::InvalidMessageSize& e)
    {
      (void)e;
      test.boolean("msg #2", msg.getSerializationSize() > DUNE_IMC_CONST_MAX_SIZE);
    }
  }

  {
    IMC::UsblModem msg;
    msg.setTimeStamp(0.5650294395413791);
    msg.setSource(12247U);
    msg.setSourceEntity(210U);
    msg.setDestination(36246U);
    msg.setDestinationEntity(98U);
    msg.name.assign("OEOCSVHYPKJYAJPBHUEBFTZBLBWFJKXQMILADAHLPQJEFGGANVZYWKIWCRDTPJQZTVMNSNOWITFIVSKGSSKOTAICLTMQZIHKZUDZLRFXQOFJJCLBMECMSDVTGEBCKTNXRSXLCSCLTMEQNEHUATQRHDXIAOSXPDNYDNYFFVQGCYYLZQBWYBRIXYPZGOHNXGXPPDHUFDWVFEHEMGWVERMBWSG");
    msg.lat = 0.813213553296704;
    msg.lon = 0.4892117885330677;
    msg.z = 0.49584997986428625;
    msg.z_units = 104U;

    try
    {
      Utils::ByteBuffer bfr;
      IMC::Packet::serialize(&msg, bfr);
      IMC::Message* msg_d = IMC::Packet::deserialize(bfr.getBuffer(), bfr.getSize());
      test.boolean("UsblModem #0", msg == *msg_d);
      delete msg_d;
    }
    catch (IMC::InvalidMessageSize& e)
    {
      (void)e;
      test.boolean("msg #0", msg.getSerializationSize() > DUNE_IMC_CONST_MAX_SIZE);
    }
  }

  {
    IMC::UsblModem msg;
    msg.setTimeStamp(0.5940358913479618);
    msg.setSource(18870U);
    msg.setSourceEntity(75U);
    msg.setDestination(12598U);
    msg.setDestinationEntity(144U);
    msg.name.assign("URPPXBZSTOXDJQRUVISNQUEHYCYHTLLLYOCSWJPPFWXUIZZWMPLJGMCRKUDZZDBAFAVAFCNBRWGBGELZNLIGMVFMCVFFKECKWISRHHDXMQOQUVRVJHKECSUWNEAAAUYKIPZXRQWZANMYKBAVJTMNGJHDKXILGTTJKYNSOHYGBYBGMJOTLODVTRWOCTQZMO");
    msg.lat = 0.1394453324321714;
    msg.lon = 0.014488637334523324;
    msg.z = 0.538598461950811;
    msg.z_units = 167U;

    try
    {
      Utils::ByteBuffer bfr;
      IMC::Packet::serialize(&msg, bfr);
      IMC::Message* msg_d = IMC::Packet::deserialize(bfr.getBuffer(), bfr.getSize());
      test.boolean("UsblModem #1", msg == *msg_d);
      delete msg_d;
    }
    catch (IMC::InvalidMessageSize& e)
    {
      (void)e;
      test.boolean("msg #1", msg.getSerializationSize() > DUNE_IMC_CONST_MAX_SIZE);
    }
  }

  {
    IMC::UsblModem msg;
    msg.setTimeStamp(0.22070415667768728);
    msg.setSource(65083U);
    msg.setSourceEntity(214U);
    msg.setDestination(59164U);
    msg.setDestinationEntity(186U);
    msg.name.assign("RUEHSZWZDJRASGIBASWUUUVGIEYWDVUIFPUHCYGYGXUDIOEJYAJGZCQUWHNVDWCMWCJKVZGOIUZZKIHOYRZXHC");
    msg.lat = 0.9635820069544164;
    msg.lon = 0.07032281997683743;
    msg.z = 0.42411315869375354;
    msg.z_units = 150U;

    try
    {
      Utils::ByteBuffer bfr;
      IMC::Packet::serialize(&msg, bfr);
      IMC::Message* msg_d = IMC::Packet::deserialize(bfr.getBuffer(), bfr.getSize());
      test.boolean("UsblModem #2", msg == *msg_d);
      delete msg_d;
    }
    catch (IMC::InvalidMessageSize& e)
    {
      (void)e;
      test.boolean("msg #2", msg.getSerializationSize() > DUNE_IMC_CONST_MAX_SIZE);
    }
  }

  {
    IMC::UsblConfig msg;
    msg.setTimeStamp(0.5277773125430146);
    msg.setSource(63102U);
    msg.setSourceEntity(194U);
    msg.setDestination(40064U);
    msg.setDestinationEntity(190U);
    msg.op = 189U;

    try
    {
      Utils::ByteBuffer bfr;
      IMC::Packet::serialize(&msg, bfr);
      IMC::Message* msg_d = IMC::Packet::deserialize(bfr.getBuffer(), bfr.getSize());
      test.boolean("UsblConfig #0", msg == *msg_d);
      delete msg_d;
    }
    catch (IMC::InvalidMessageSize& e)
    {
      (void)e;
      test.boolean("msg #0", msg.getSerializationSize() > DUNE_IMC_CONST_MAX_SIZE);
    }
  }

  {
    IMC::UsblConfig msg;
    msg.setTimeStamp(0.08803069900852822);
    msg.setSource(39142U);
    msg.setSourceEntity(141U);
    msg.setDestination(42134U);
    msg.setDestinationEntity(180U);
    msg.op = 65U;

    try
    {
      Utils::ByteBuffer bfr;
      IMC::Packet::serialize(&msg, bfr);
      IMC::Message* msg_d = IMC::Packet::deserialize(bfr.getBuffer(), bfr.getSize());
      test.boolean("UsblConfig #1", msg == *msg_d);
      delete msg_d;
    }
    catch (IMC::InvalidMessageSize& e)
    {
      (void)e;
      test.boolean("msg #1", msg.getSerializationSize() > DUNE_IMC_CONST_MAX_SIZE);
    }
  }

  {
    IMC::UsblConfig msg;
    msg.setTimeStamp(0.8618238617529849);
    msg.setSource(6257U);
    msg.setSourceEntity(185U);
    msg.setDestination(25802U);
    msg.setDestinationEntity(208U);
    msg.op = 115U;

    try
    {
      Utils::ByteBuffer bfr;
      IMC::Packet::serialize(&msg, bfr);
      IMC::Message* msg_d = IMC::Packet::deserialize(bfr.getBuffer(), bfr.getSize());
      test.boolean("UsblConfig #2", msg == *msg_d);
      delete msg_d;
    }
    catch (IMC::InvalidMessageSize& e)
    {
      (void)e;
      test.boolean("msg #2", msg.getSerializationSize() > DUNE_IMC_CONST_MAX_SIZE);
    }
  }

  {
    IMC::DissolvedOrganicMatter msg;
    msg.setTimeStamp(0.7233277348039611);
    msg.setSource(23993U);
    msg.setSourceEntity(45U);
    msg.setDestination(7590U);
    msg.setDestinationEntity(68U);
    msg.value = 0.41676237182373765;
    msg.type = 48U;

    try
    {
      Utils::ByteBuffer bfr;
      IMC::Packet::serialize(&msg, bfr);
      IMC::Message* msg_d = IMC::Packet::deserialize(bfr.getBuffer(), bfr.getSize());
      test.boolean("DissolvedOrganicMatter #0", msg == *msg_d);
      delete msg_d;
    }
    catch (IMC::InvalidMessageSize& e)
    {
      (void)e;
      test.boolean("msg #0", msg.getSerializationSize() > DUNE_IMC_CONST_MAX_SIZE);
    }
  }

  {
    IMC::DissolvedOrganicMatter msg;
    msg.setTimeStamp(0.04864090775080243);
    msg.setSource(34520U);
    msg.setSourceEntity(162U);
    msg.setDestination(43798U);
    msg.setDestinationEntity(13U);
    msg.value = 0.4509968710195452;
    msg.type = 75U;

    try
    {
      Utils::ByteBuffer bfr;
      IMC::Packet::serialize(&msg, bfr);
      IMC::Message* msg_d = IMC::Packet::deserialize(bfr.getBuffer(), bfr.getSize());
      test.boolean("DissolvedOrganicMatter #1", msg == *msg_d);
      delete msg_d;
    }
    catch (IMC::InvalidMessageSize& e)
    {
      (void)e;
      test.boolean("msg #1", msg.getSerializationSize() > DUNE_IMC_CONST_MAX_SIZE);
    }
  }

  {
    IMC::DissolvedOrganicMatter msg;
    msg.setTimeStamp(0.3813985053374763);
    msg.setSource(64753U);
    msg.setSourceEntity(33U);
    msg.setDestination(55400U);
    msg.setDestinationEntity(207U);
    msg.value = 0.15390351669793334;
    msg.type = 253U;

    try
    {
      Utils::ByteBuffer bfr;
      IMC::Packet::serialize(&msg, bfr);
      IMC::Message* msg_d = IMC::Packet::deserialize(bfr.getBuffer(), bfr.getSize());
      test.boolean("DissolvedOrganicMatter #2", msg == *msg_d);
      delete msg_d;
    }
    catch (IMC::InvalidMessageSize& e)
    {
      (void)e;
      test.boolean("msg #2", msg.getSerializationSize() > DUNE_IMC_CONST_MAX_SIZE);
    }
  }

  {
    IMC::OpticalBackscatter msg;
    msg.setTimeStamp(0.3464531514663959);
    msg.setSource(26993U);
    msg.setSourceEntity(207U);
    msg.setDestination(40577U);
    msg.setDestinationEntity(87U);
    msg.value = 0.14479803466637853;

    try
    {
      Utils::ByteBuffer bfr;
      IMC::Packet::serialize(&msg, bfr);
      IMC::Message* msg_d = IMC::Packet::deserialize(bfr.getBuffer(), bfr.getSize());
      test.boolean("OpticalBackscatter #0", msg == *msg_d);
      delete msg_d;
    }
    catch (IMC::InvalidMessageSize& e)
    {
      (void)e;
      test.boolean("msg #0", msg.getSerializationSize() > DUNE_IMC_CONST_MAX_SIZE);
    }
  }

  {
    IMC::OpticalBackscatter msg;
    msg.setTimeStamp(0.5110838423660464);
    msg.setSource(31082U);
    msg.setSourceEntity(112U);
    msg.setDestination(29522U);
    msg.setDestinationEntity(34U);
    msg.value = 0.25771962511398505;

    try
    {
      Utils::ByteBuffer bfr;
      IMC::Packet::serialize(&msg, bfr);
      IMC::Message* msg_d = IMC::Packet::deserialize(bfr.getBuffer(), bfr.getSize());
      test.boolean("OpticalBackscatter #1", msg == *msg_d);
      delete msg_d;
    }
    catch (IMC::InvalidMessageSize& e)
    {
      (void)e;
      test.boolean("msg #1", msg.getSerializationSize() > DUNE_IMC_CONST_MAX_SIZE);
    }
  }

  {
    IMC::OpticalBackscatter msg;
    msg.setTimeStamp(0.538141123718359);
    msg.setSource(44324U);
    msg.setSourceEntity(225U);
    msg.setDestination(31350U);
    msg.setDestinationEntity(62U);
    msg.value = 0.7195683289408848;

    try
    {
      Utils::ByteBuffer bfr;
      IMC::Packet::serialize(&msg, bfr);
      IMC::Message* msg_d = IMC::Packet::deserialize(bfr.getBuffer(), bfr.getSize());
      test.boolean("OpticalBackscatter #2", msg == *msg_d);
      delete msg_d;
    }
    catch (IMC::InvalidMessageSize& e)
    {
      (void)e;
      test.boolean("msg #2", msg.getSerializationSize() > DUNE_IMC_CONST_MAX_SIZE);
    }
  }

  {
    IMC::Tachograph msg;
    msg.setTimeStamp(0.9381257296693324);
    msg.setSource(15985U);
    msg.setSourceEntity(165U);
    msg.setDestination(30635U);
    msg.setDestinationEntity(147U);
    msg.timestamp_last_service = 0.30191658076713435;
    msg.time_next_service = 0.12775382669428903;
    msg.time_motor_next_service = 0.998109556357606;
    msg.time_idle_ground = 0.7553239503686902;
    msg.time_idle_air = 0.7976937223916346;
    msg.time_idle_water = 0.5379632573642196;
    msg.time_idle_underwater = 0.10944030021585871;
    msg.time_idle_unknown = 0.17837150308277028;
    msg.time_motor_ground = 0.027291498823939775;
    msg.time_motor_air = 0.31666270612803915;
    msg.time_motor_water = 0.7824631583724166;
    msg.time_motor_underwater = 0.3759136767993526;
    msg.time_motor_unknown = 0.3148840263119508;
    msg.rpm_min = 28101;
    msg.rpm_max = 9663;
    msg.depth_max = 0.2457862072853676;

    try
    {
      Utils::ByteBuffer bfr;
      IMC::Packet::serialize(&msg, bfr);
      IMC::Message* msg_d = IMC::Packet::deserialize(bfr.getBuffer(), bfr.getSize());
      test.boolean("Tachograph #0", msg == *msg_d);
      delete msg_d;
    }
    catch (IMC::InvalidMessageSize& e)
    {
      (void)e;
      test.boolean("msg #0", msg.getSerializationSize() > DUNE_IMC_CONST_MAX_SIZE);
    }
  }

  {
    IMC::Tachograph msg;
    msg.setTimeStamp(0.2746362837824998);
    msg.setSource(30473U);
    msg.setSourceEntity(212U);
    msg.setDestination(13847U);
    msg.setDestinationEntity(73U);
    msg.timestamp_last_service = 0.26222963217416617;
    msg.time_next_service = 0.08148661767517218;
    msg.time_motor_next_service = 0.034218735074864726;
    msg.time_idle_ground = 0.5900171237270173;
    msg.time_idle_air = 0.8224176687741034;
    msg.time_idle_water = 0.8915736849652977;
    msg.time_idle_underwater = 0.8150736411298161;
    msg.time_idle_unknown = 0.5986673387309587;
    msg.time_motor_ground = 0.6266989302276543;
    msg.time_motor_air = 0.5637558895493924;
    msg.time_motor_water = 0.6949647839520923;
    msg.time_motor_underwater = 0.9840009791127003;
    msg.time_motor_unknown = 0.7294951900449649;
    msg.rpm_min = -23214;
    msg.rpm_max = -25465;
    msg.depth_max = 0.9267197404127234;

    try
    {
      Utils::ByteBuffer bfr;
      IMC::Packet::serialize(&msg, bfr);
      IMC::Message* msg_d = IMC::Packet::deserialize(bfr.getBuffer(), bfr.getSize());
      test.boolean("Tachograph #1", msg == *msg_d);
      delete msg_d;
    }
    catch (IMC::InvalidMessageSize& e)
    {
      (void)e;
      test.boolean("msg #1", msg.getSerializationSize() > DUNE_IMC_CONST_MAX_SIZE);
    }
  }

  {
    IMC::Tachograph msg;
    msg.setTimeStamp(0.6642555823955562);
    msg.setSource(60574U);
    msg.setSourceEntity(132U);
    msg.setDestination(45564U);
    msg.setDestinationEntity(130U);
    msg.timestamp_last_service = 0.5320441250783216;
    msg.time_next_service = 0.6183109980169821;
    msg.time_motor_next_service = 0.8603745625409652;
    msg.time_idle_ground = 0.1955854931796408;
    msg.time_idle_air = 0.16147152511646057;
    msg.time_idle_water = 0.8889861720426996;
    msg.time_idle_underwater = 0.5907369886038316;
    msg.time_idle_unknown = 0.5458924578213182;
    msg.time_motor_ground = 0.3826740171976557;
    msg.time_motor_air = 0.2953497766032006;
    msg.time_motor_water = 0.5974347782058962;
    msg.time_motor_underwater = 0.8963074956279493;
    msg.time_motor_unknown = 0.4501170058031476;
    msg.rpm_min = -15755;
    msg.rpm_max = 17266;
    msg.depth_max = 0.8397845549808007;

    try
    {
      Utils::ByteBuffer bfr;
      IMC::Packet::serialize(&msg, bfr);
      IMC::Message* msg_d = IMC::Packet::deserialize(bfr.getBuffer(), bfr.getSize());
      test.boolean("Tachograph #2", msg == *msg_d);
      delete msg_d;
    }
    catch (IMC::InvalidMessageSize& e)
    {
      (void)e;
      test.boolean("msg #2", msg.getSerializationSize() > DUNE_IMC_CONST_MAX_SIZE);
    }
  }

  {
    IMC::ApmStatus msg;
    msg.setTimeStamp(0.8683855813531889);
    msg.setSource(60045U);
    msg.setSourceEntity(67U);
    msg.setDestination(16070U);
    msg.setDestinationEntity(90U);
    msg.severity = 0U;
    msg.text.assign("TIINEQAFAEVGCKJMSXFNEKGKQRHMMBDQJQRCQIVULWHMZFPIFDOJCTHLDWWXBSLLHVQGCPBPTXTXRNUAFLNXQOOBEXRFNSZJTKYMWLEGOIGCYCLQOFARKDWSMVMMVHINOQHBRSTSRUHMNJZPZKBQTKWNZLGFUOGJYABWBAAXGCDKUAIWKHYFUVYJYCTXBTIDVEZYSVJERAEYXDWDXCGOTIOBHESPJUPPRSDYZAP");

    try
    {
      Utils::ByteBuffer bfr;
      IMC::Packet::serialize(&msg, bfr);
      IMC::Message* msg_d = IMC::Packet::deserialize(bfr.getBuffer(), bfr.getSize());
      test.boolean("ApmStatus #0", msg == *msg_d);
      delete msg_d;
    }
    catch (IMC::InvalidMessageSize& e)
    {
      (void)e;
      test.boolean("msg #0", msg.getSerializationSize() > DUNE_IMC_CONST_MAX_SIZE);
    }
  }

  {
    IMC::ApmStatus msg;
    msg.setTimeStamp(0.6438055205530981);
    msg.setSource(26577U);
    msg.setSourceEntity(145U);
    msg.setDestination(60072U);
    msg.setDestinationEntity(126U);
    msg.severity = 67U;
    msg.text.assign("SKWVHEBPOTDOUWYRKIDVDLFTEUZFMMMSVGLXWMJDBESNJGFBNPXKNKVBGTQNCOTCPPVZUQBYLNYTSWUPOBCIAGAHAXVLBEERGFMTHGZZPLSMHGAWIKWPQDMIRQLOSDETWCXUSHUFZIIOLGHPMKUYNROFVCFOBZMCRVSRW");

    try
    {
      Utils::ByteBuffer bfr;
      IMC::Packet::serialize(&msg, bfr);
      IMC::Message* msg_d = IMC::Packet::deserialize(bfr.getBuffer(), bfr.getSize());
      test.boolean("ApmStatus #1", msg == *msg_d);
      delete msg_d;
    }
    catch (IMC::InvalidMessageSize& e)
    {
      (void)e;
      test.boolean("msg #1", msg.getSerializationSize() > DUNE_IMC_CONST_MAX_SIZE);
    }
  }

  {
    IMC::ApmStatus msg;
    msg.setTimeStamp(0.5656236479710354);
    msg.setSource(53503U);
    msg.setSourceEntity(161U);
    msg.setDestination(60484U);
    msg.setDestinationEntity(19U);
    msg.severity = 14U;
    msg.text.assign("ZSGMJDGEWMYGNZFWKORVQSIDJHHWDTXR");

    try
    {
      Utils::ByteBuffer bfr;
      IMC::Packet::serialize(&msg, bfr);
      IMC::Message* msg_d = IMC::Packet::deserialize(bfr.getBuffer(), bfr.getSize());
      test.boolean("ApmStatus #2", msg == *msg_d);
      delete msg_d;
    }
    catch (IMC::InvalidMessageSize& e)
    {
      (void)e;
      test.boolean("msg #2", msg.getSerializationSize() > DUNE_IMC_CONST_MAX_SIZE);
    }
  }

  {
    IMC::SadcReadings msg;
    msg.setTimeStamp(0.7569761766282922);
    msg.setSource(57839U);
    msg.setSourceEntity(169U);
    msg.setDestination(45901U);
    msg.setDestinationEntity(223U);
    msg.channel = 125;
    msg.value = 43307545;
    msg.gain = 149U;

    try
    {
      Utils::ByteBuffer bfr;
      IMC::Packet::serialize(&msg, bfr);
      IMC::Message* msg_d = IMC::Packet::deserialize(bfr.getBuffer(), bfr.getSize());
      test.boolean("SadcReadings #0", msg == *msg_d);
      delete msg_d;
    }
    catch (IMC::InvalidMessageSize& e)
    {
      (void)e;
      test.boolean("msg #0", msg.getSerializationSize() > DUNE_IMC_CONST_MAX_SIZE);
    }
  }

  {
    IMC::SadcReadings msg;
    msg.setTimeStamp(0.5779771236951228);
    msg.setSource(51897U);
    msg.setSourceEntity(173U);
    msg.setDestination(32569U);
    msg.setDestinationEntity(156U);
    msg.channel = -63;
    msg.value = 581669788;
    msg.gain = 113U;

    try
    {
      Utils::ByteBuffer bfr;
      IMC::Packet::serialize(&msg, bfr);
      IMC::Message* msg_d = IMC::Packet::deserialize(bfr.getBuffer(), bfr.getSize());
      test.boolean("SadcReadings #1", msg == *msg_d);
      delete msg_d;
    }
    catch (IMC::InvalidMessageSize& e)
    {
      (void)e;
      test.boolean("msg #1", msg.getSerializationSize() > DUNE_IMC_CONST_MAX_SIZE);
    }
  }

  {
    IMC::SadcReadings msg;
    msg.setTimeStamp(0.15348945814005688);
    msg.setSource(53724U);
    msg.setSourceEntity(216U);
    msg.setDestination(62880U);
    msg.setDestinationEntity(82U);
    msg.channel = 98;
    msg.value = 829954979;
    msg.gain = 150U;

    try
    {
      Utils::ByteBuffer bfr;
      IMC::Packet::serialize(&msg, bfr);
      IMC::Message* msg_d = IMC::Packet::deserialize(bfr.getBuffer(), bfr.getSize());
      test.boolean("SadcReadings #2", msg == *msg_d);
      delete msg_d;
    }
    catch (IMC::InvalidMessageSize& e)
    {
      (void)e;
      test.boolean("msg #2", msg.getSerializationSize() > DUNE_IMC_CONST_MAX_SIZE);
    }
  }

  {
    IMC::DmsDetection msg;
    msg.setTimeStamp(0.05167497101588148);
    msg.setSource(22183U);
    msg.setSourceEntity(136U);
    msg.setDestination(10221U);
    msg.setDestinationEntity(0U);
    msg.ch01 = 0.338829308724826;
    msg.ch02 = 0.6117368375686624;
    msg.ch03 = 0.7666256546744357;
    msg.ch04 = 0.16607380445668907;
    msg.ch05 = 0.14405095233236453;
    msg.ch06 = 0.8513392165495812;
    msg.ch07 = 0.4760939122793919;
    msg.ch08 = 0.6126150815971133;
    msg.ch09 = 0.1833761401096643;
    msg.ch10 = 0.39301647873569756;
    msg.ch11 = 0.41342908823361035;
    msg.ch12 = 0.9615433089428905;
    msg.ch13 = 0.028752437217570703;
    msg.ch14 = 0.3637207389416345;
    msg.ch15 = 0.5058456396544444;
    msg.ch16 = 0.41711200631850776;

    try
    {
      Utils::ByteBuffer bfr;
      IMC::Packet::serialize(&msg, bfr);
      IMC::Message* msg_d = IMC::Packet::deserialize(bfr.getBuffer(), bfr.getSize());
      test.boolean("DmsDetection #0", msg == *msg_d);
      delete msg_d;
    }
    catch (IMC::InvalidMessageSize& e)
    {
      (void)e;
      test.boolean("msg #0", msg.getSerializationSize() > DUNE_IMC_CONST_MAX_SIZE);
    }
  }

  {
    IMC::DmsDetection msg;
    msg.setTimeStamp(0.5151877196184722);
    msg.setSource(31980U);
    msg.setSourceEntity(1U);
    msg.setDestination(43682U);
    msg.setDestinationEntity(200U);
    msg.ch01 = 0.5808253474320896;
    msg.ch02 = 0.078282633828064;
    msg.ch03 = 0.633091001342329;
    msg.ch04 = 0.5406730788821638;
    msg.ch05 = 0.6068813025260863;
    msg.ch06 = 0.1602968095734808;
    msg.ch07 = 0.5502779724310406;
    msg.ch08 = 0.8124312971857569;
    msg.ch09 = 0.8879540126611972;
    msg.ch10 = 0.08554596375030044;
    msg.ch11 = 0.5619383504114823;
    msg.ch12 = 0.6640878423388707;
    msg.ch13 = 0.042636111864178705;
    msg.ch14 = 0.26576515851532756;
    msg.ch15 = 0.9452100504782172;
    msg.ch16 = 0.44328185224176797;

    try
    {
      Utils::ByteBuffer bfr;
      IMC::Packet::serialize(&msg, bfr);
      IMC::Message* msg_d = IMC::Packet::deserialize(bfr.getBuffer(), bfr.getSize());
      test.boolean("DmsDetection #1", msg == *msg_d);
      delete msg_d;
    }
    catch (IMC::InvalidMessageSize& e)
    {
      (void)e;
      test.boolean("msg #1", msg.getSerializationSize() > DUNE_IMC_CONST_MAX_SIZE);
    }
  }

  {
    IMC::DmsDetection msg;
    msg.setTimeStamp(0.9876965765628989);
    msg.setSource(5977U);
    msg.setSourceEntity(106U);
    msg.setDestination(2868U);
    msg.setDestinationEntity(109U);
    msg.ch01 = 0.8445093296540449;
    msg.ch02 = 0.16575076560005797;
    msg.ch03 = 0.494215430827435;
    msg.ch04 = 0.0349828661485766;
    msg.ch05 = 0.8181639809736948;
    msg.ch06 = 0.13167089642491014;
    msg.ch07 = 0.23341975427177597;
    msg.ch08 = 0.4886643366633343;
    msg.ch09 = 0.2946625952848474;
    msg.ch10 = 0.02422664734141866;
    msg.ch11 = 0.07755900616039946;
    msg.ch12 = 0.8830535354290023;
    msg.ch13 = 0.1633036746804193;
    msg.ch14 = 0.7438952272117554;
    msg.ch15 = 0.706377197794467;
    msg.ch16 = 0.6949475622662151;

    try
    {
      Utils::ByteBuffer bfr;
      IMC::Packet::serialize(&msg, bfr);
      IMC::Message* msg_d = IMC::Packet::deserialize(bfr.getBuffer(), bfr.getSize());
      test.boolean("DmsDetection #2", msg == *msg_d);
      delete msg_d;
    }
    catch (IMC::InvalidMessageSize& e)
    {
      (void)e;
      test.boolean("msg #2", msg.getSerializationSize() > DUNE_IMC_CONST_MAX_SIZE);
    }
  }

  {
    IMC::HomePosition msg;
    msg.setTimeStamp(0.9975626210606277);
    msg.setSource(15018U);
    msg.setSourceEntity(178U);
    msg.setDestination(30028U);
    msg.setDestinationEntity(61U);
    msg.op = 206U;
    msg.lat = 0.8329092544511285;
    msg.lon = 0.6228135181255009;
    msg.height = 0.24067144812368246;
    msg.depth = 0.10468127232031843;
    msg.alt = 0.25877182210347704;

    try
    {
      Utils::ByteBuffer bfr;
      IMC::Packet::serialize(&msg, bfr);
      IMC::Message* msg_d = IMC::Packet::deserialize(bfr.getBuffer(), bfr.getSize());
      test.boolean("HomePosition #0", msg == *msg_d);
      delete msg_d;
    }
    catch (IMC::InvalidMessageSize& e)
    {
      (void)e;
      test.boolean("msg #0", msg.getSerializationSize() > DUNE_IMC_CONST_MAX_SIZE);
    }
  }

  {
    IMC::HomePosition msg;
    msg.setTimeStamp(0.1313678937308549);
    msg.setSource(60134U);
    msg.setSourceEntity(242U);
    msg.setDestination(29487U);
    msg.setDestinationEntity(102U);
    msg.op = 7U;
    msg.lat = 0.6146096293939054;
    msg.lon = 0.006766398837639631;
    msg.height = 0.6564852847730173;
    msg.depth = 0.4167141295131911;
    msg.alt = 0.685221795909374;

    try
    {
      Utils::ByteBuffer bfr;
      IMC::Packet::serialize(&msg, bfr);
      IMC::Message* msg_d = IMC::Packet::deserialize(bfr.getBuffer(), bfr.getSize());
      test.boolean("HomePosition #1", msg == *msg_d);
      delete msg_d;
    }
    catch (IMC::InvalidMessageSize& e)
    {
      (void)e;
      test.boolean("msg #1", msg.getSerializationSize() > DUNE_IMC_CONST_MAX_SIZE);
    }
  }

  {
    IMC::HomePosition msg;
    msg.setTimeStamp(0.8998434017341838);
    msg.setSource(63010U);
    msg.setSourceEntity(61U);
    msg.setDestination(19183U);
    msg.setDestinationEntity(134U);
    msg.op = 77U;
    msg.lat = 0.18587124093944896;
    msg.lon = 0.44810671298813465;
    msg.height = 0.39708951780212176;
    msg.depth = 0.831662013760327;
    msg.alt = 0.7759862120625529;

    try
    {
      Utils::ByteBuffer bfr;
      IMC::Packet::serialize(&msg, bfr);
      IMC::Message* msg_d = IMC::Packet::deserialize(bfr.getBuffer(), bfr.getSize());
      test.boolean("HomePosition #2", msg == *msg_d);
      delete msg_d;
    }
    catch (IMC::InvalidMessageSize& e)
    {
      (void)e;
      test.boolean("msg #2", msg.getSerializationSize() > DUNE_IMC_CONST_MAX_SIZE);
    }
  }

  {
    IMC::CurrentProfile msg;
    msg.setTimeStamp(0.7595888489800579);
    msg.setSource(8285U);
    msg.setSourceEntity(35U);
    msg.setDestination(52763U);
    msg.setDestinationEntity(47U);
    msg.nbeams = 207U;
    msg.ncells = 178U;
    msg.coord_sys = 157U;

    try
    {
      Utils::ByteBuffer bfr;
      IMC::Packet::serialize(&msg, bfr);
      IMC::Message* msg_d = IMC::Packet::deserialize(bfr.getBuffer(), bfr.getSize());
      test.boolean("CurrentProfile #0", msg == *msg_d);
      delete msg_d;
    }
    catch (IMC::InvalidMessageSize& e)
    {
      (void)e;
      test.boolean("msg #0", msg.getSerializationSize() > DUNE_IMC_CONST_MAX_SIZE);
    }
  }

  {
    IMC::CurrentProfile msg;
    msg.setTimeStamp(0.04565762656931349);
    msg.setSource(32755U);
    msg.setSourceEntity(133U);
    msg.setDestination(48527U);
    msg.setDestinationEntity(52U);
    msg.nbeams = 116U;
    msg.ncells = 184U;
    msg.coord_sys = 31U;

    try
    {
      Utils::ByteBuffer bfr;
      IMC::Packet::serialize(&msg, bfr);
      IMC::Message* msg_d = IMC::Packet::deserialize(bfr.getBuffer(), bfr.getSize());
      test.boolean("CurrentProfile #1", msg == *msg_d);
      delete msg_d;
    }
    catch (IMC::InvalidMessageSize& e)
    {
      (void)e;
      test.boolean("msg #1", msg.getSerializationSize() > DUNE_IMC_CONST_MAX_SIZE);
    }
  }

  {
    IMC::CurrentProfile msg;
    msg.setTimeStamp(0.059692781275435425);
    msg.setSource(27866U);
    msg.setSourceEntity(155U);
    msg.setDestination(33444U);
    msg.setDestinationEntity(213U);
    msg.nbeams = 48U;
    msg.ncells = 37U;
    msg.coord_sys = 74U;

    try
    {
      Utils::ByteBuffer bfr;
      IMC::Packet::serialize(&msg, bfr);
      IMC::Message* msg_d = IMC::Packet::deserialize(bfr.getBuffer(), bfr.getSize());
      test.boolean("CurrentProfile #2", msg == *msg_d);
      delete msg_d;
    }
    catch (IMC::InvalidMessageSize& e)
    {
      (void)e;
      test.boolean("msg #2", msg.getSerializationSize() > DUNE_IMC_CONST_MAX_SIZE);
    }
  }

  {
    IMC::CurrentProfileCell msg;
    msg.setTimeStamp(0.9156359380111584);
    msg.setSource(24574U);
    msg.setSourceEntity(230U);
    msg.setDestination(62677U);
    msg.setDestinationEntity(230U);
    msg.cell_position = 0.19570808803693063;
    IMC::ADCPBeam tmp_msg_0;
    tmp_msg_0.vel = 0.07684462539221215;
    tmp_msg_0.amp = 0.7611479527526576;
    tmp_msg_0.cor = 149U;
    msg.beams.push_back(tmp_msg_0);

    try
    {
      Utils::ByteBuffer bfr;
      IMC::Packet::serialize(&msg, bfr);
      IMC::Message* msg_d = IMC::Packet::deserialize(bfr.getBuffer(), bfr.getSize());
      test.boolean("CurrentProfileCell #0", msg == *msg_d);
      delete msg_d;
    }
    catch (IMC::InvalidMessageSize& e)
    {
      (void)e;
      test.boolean("msg #0", msg.getSerializationSize() > DUNE_IMC_CONST_MAX_SIZE);
    }
  }

  {
    IMC::CurrentProfileCell msg;
    msg.setTimeStamp(0.2276536151124008);
    msg.setSource(39346U);
    msg.setSourceEntity(57U);
    msg.setDestination(213U);
    msg.setDestinationEntity(18U);
    msg.cell_position = 0.49036195137247907;
    IMC::ADCPBeam tmp_msg_0;
    tmp_msg_0.vel = 0.381012435535966;
    tmp_msg_0.amp = 0.19554984742118864;
    tmp_msg_0.cor = 43U;
    msg.beams.push_back(tmp_msg_0);

    try
    {
      Utils::ByteBuffer bfr;
      IMC::Packet::serialize(&msg, bfr);
      IMC::Message* msg_d = IMC::Packet::deserialize(bfr.getBuffer(), bfr.getSize());
      test.boolean("CurrentProfileCell #1", msg == *msg_d);
      delete msg_d;
    }
    catch (IMC::InvalidMessageSize& e)
    {
      (void)e;
      test.boolean("msg #1", msg.getSerializationSize() > DUNE_IMC_CONST_MAX_SIZE);
    }
  }

  {
    IMC::CurrentProfileCell msg;
    msg.setTimeStamp(0.10577286995228974);
    msg.setSource(27508U);
    msg.setSourceEntity(25U);
    msg.setDestination(51686U);
    msg.setDestinationEntity(242U);
    msg.cell_position = 0.3903382930521898;

    try
    {
      Utils::ByteBuffer bfr;
      IMC::Packet::serialize(&msg, bfr);
      IMC::Message* msg_d = IMC::Packet::deserialize(bfr.getBuffer(), bfr.getSize());
      test.boolean("CurrentProfileCell #2", msg == *msg_d);
      delete msg_d;
    }
    catch (IMC::InvalidMessageSize& e)
    {
      (void)e;
      test.boolean("msg #2", msg.getSerializationSize() > DUNE_IMC_CONST_MAX_SIZE);
    }
  }

  {
    IMC::ADCPBeam msg;
    msg.setTimeStamp(0.26398842833299174);
    msg.setSource(9341U);
    msg.setSourceEntity(209U);
    msg.setDestination(61450U);
    msg.setDestinationEntity(117U);
    msg.vel = 0.7986064344696521;
    msg.amp = 0.2452248848828511;
    msg.cor = 93U;

    try
    {
      Utils::ByteBuffer bfr;
      IMC::Packet::serialize(&msg, bfr);
      IMC::Message* msg_d = IMC::Packet::deserialize(bfr.getBuffer(), bfr.getSize());
      test.boolean("ADCPBeam #0", msg == *msg_d);
      delete msg_d;
    }
    catch (IMC::InvalidMessageSize& e)
    {
      (void)e;
      test.boolean("msg #0", msg.getSerializationSize() > DUNE_IMC_CONST_MAX_SIZE);
    }
  }

  {
    IMC::ADCPBeam msg;
    msg.setTimeStamp(0.9977988740613477);
    msg.setSource(64095U);
    msg.setSourceEntity(18U);
    msg.setDestination(60934U);
    msg.setDestinationEntity(95U);
    msg.vel = 0.23642460619711825;
    msg.amp = 0.9768800962757961;
    msg.cor = 3U;

    try
    {
      Utils::ByteBuffer bfr;
      IMC::Packet::serialize(&msg, bfr);
      IMC::Message* msg_d = IMC::Packet::deserialize(bfr.getBuffer(), bfr.getSize());
      test.boolean("ADCPBeam #1", msg == *msg_d);
      delete msg_d;
    }
    catch (IMC::InvalidMessageSize& e)
    {
      (void)e;
      test.boolean("msg #1", msg.getSerializationSize() > DUNE_IMC_CONST_MAX_SIZE);
    }
  }

  {
    IMC::ADCPBeam msg;
    msg.setTimeStamp(0.8286342117104085);
    msg.setSource(63625U);
    msg.setSourceEntity(130U);
    msg.setDestination(4540U);
    msg.setDestinationEntity(139U);
    msg.vel = 0.38188943486615556;
    msg.amp = 0.45982740307399284;
    msg.cor = 191U;

    try
    {
      Utils::ByteBuffer bfr;
      IMC::Packet::serialize(&msg, bfr);
      IMC::Message* msg_d = IMC::Packet::deserialize(bfr.getBuffer(), bfr.getSize());
      test.boolean("ADCPBeam #2", msg == *msg_d);
      delete msg_d;
    }
    catch (IMC::InvalidMessageSize& e)
    {
      (void)e;
      test.boolean("msg #2", msg.getSerializationSize() > DUNE_IMC_CONST_MAX_SIZE);
    }
  }

  {
    IMC::GpioState msg;
    msg.setTimeStamp(0.5305284702149449);
    msg.setSource(2434U);
    msg.setSourceEntity(148U);
    msg.setDestination(37507U);
    msg.setDestinationEntity(209U);
    msg.name.assign("NJTGGJDVGQFCNWICWGYLOFULQSVWSPBTXRWISIHPQCXJIBRKOZSWOAKNROQOUEGAXXFAADDSBKJDKGPZWGXRCBDOHSROJTEIGSFFUHIXMPRLMIQQFUPVICVLGYBOKKMNKYPECJNWZJDEMZBFGNUPABRFWUNQDDLUEXLNXDYJOZXLZHDPEYQEMEFMITFWRZ");
    msg.value = 210U;

    try
    {
      Utils::ByteBuffer bfr;
      IMC::Packet::serialize(&msg, bfr);
      IMC::Message* msg_d = IMC::Packet::deserialize(bfr.getBuffer(), bfr.getSize());
      test.boolean("GpioState #0", msg == *msg_d);
      delete msg_d;
    }
    catch (IMC::InvalidMessageSize& e)
    {
      (void)e;
      test.boolean("msg #0", msg.getSerializationSize() > DUNE_IMC_CONST_MAX_SIZE);
    }
  }

  {
    IMC::GpioState msg;
    msg.setTimeStamp(0.23782774879456592);
    msg.setSource(60777U);
    msg.setSourceEntity(177U);
    msg.setDestination(24726U);
    msg.setDestinationEntity(14U);
    msg.name.assign("LXPQEZHQFAABUORKNQKMHGISITTHFZEWAKOKBYETGRFFCVDZHSJGHECDVFQLQOMXVNESJDSBQEYUAYOPMDEVDVSRNNFMPDRVIVXGCKRDKXMXJCAULUGLRYJRNGRZXKWIQOJAACMUBFJXZMVJZJONOTWKAZQIATLUDLVISNPELHUPBGXWMBRVW");
    msg.value = 4U;

    try
    {
      Utils::ByteBuffer bfr;
      IMC::Packet::serialize(&msg, bfr);
      IMC::Message* msg_d = IMC::Packet::deserialize(bfr.getBuffer(), bfr.getSize());
      test.boolean("GpioState #1", msg == *msg_d);
      delete msg_d;
    }
    catch (IMC::InvalidMessageSize& e)
    {
      (void)e;
      test.boolean("msg #1", msg.getSerializationSize() > DUNE_IMC_CONST_MAX_SIZE);
    }
  }

  {
    IMC::GpioState msg;
    msg.setTimeStamp(0.8439622034890926);
    msg.setSource(62361U);
    msg.setSourceEntity(119U);
    msg.setDestination(60805U);
    msg.setDestinationEntity(128U);
    msg.name.assign("CVEDZATZJXAOUEACDYVUCFMJYSHDXWGOWIHGYNOZJNEGKZJRTIQTPIUQDGGPNHJELFVSCEUDVMFBCSPTOLLF");
    msg.value = 93U;

    try
    {
      Utils::ByteBuffer bfr;
      IMC::Packet::serialize(&msg, bfr);
      IMC::Message* msg_d = IMC::Packet::deserialize(bfr.getBuffer(), bfr.getSize());
      test.boolean("GpioState #2", msg == *msg_d);
      delete msg_d;
    }
    catch (IMC::InvalidMessageSize& e)
    {
      (void)e;
      test.boolean("msg #2", msg.getSerializationSize() > DUNE_IMC_CONST_MAX_SIZE);
    }
  }

  {
    IMC::GpioStateGet msg;
    msg.setTimeStamp(0.882994984161118);
    msg.setSource(55626U);
    msg.setSourceEntity(1U);
    msg.setDestination(26625U);
    msg.setDestinationEntity(220U);
    msg.name.assign("LUSUOQWEVITCEMUXVZKTPKXARBDEHWWPRYAQNFJCESVMIDERVILTNLWZQXMUVPUHRCTIFKXLVYJCCJBXDSWGXLRLJHDKFHXFAFFPEAZGDYOQGDBVYJBWHEOKFPPRMTYA");

    try
    {
      Utils::ByteBuffer bfr;
      IMC::Packet::serialize(&msg, bfr);
      IMC::Message* msg_d = IMC::Packet::deserialize(bfr.getBuffer(), bfr.getSize());
      test.boolean("GpioStateGet #0", msg == *msg_d);
      delete msg_d;
    }
    catch (IMC::InvalidMessageSize& e)
    {
      (void)e;
      test.boolean("msg #0", msg.getSerializationSize() > DUNE_IMC_CONST_MAX_SIZE);
    }
  }

  {
    IMC::GpioStateGet msg;
    msg.setTimeStamp(0.710645111618507);
    msg.setSource(60808U);
    msg.setSourceEntity(202U);
    msg.setDestination(22694U);
    msg.setDestinationEntity(50U);
    msg.name.assign("WYGSRWQVVPTFKUBATBSMDYZFPTXFILRQRMNDUEAQJMTEXMGOJORPMAGYHUKLHONZSESOLNVQSWNPKNQYPLKKPGUXAXUCLESHFATYTXUHHKCNDIOAVSOHZCPVUMYJWIVIFRZTRMPHUKTLBREQOHBLEDKZMMBBAVZJTKWAKYHLRLTJQIYNOSJEXFYISXCZNAGJCDDZJDBIC");

    try
    {
      Utils::ByteBuffer bfr;
      IMC::Packet::serialize(&msg, bfr);
      IMC::Message* msg_d = IMC::Packet::deserialize(bfr.getBuffer(), bfr.getSize());
      test.boolean("GpioStateGet #1", msg == *msg_d);
      delete msg_d;
    }
    catch (IMC::InvalidMessageSize& e)
    {
      (void)e;
      test.boolean("msg #1", msg.getSerializationSize() > DUNE_IMC_CONST_MAX_SIZE);
    }
  }

  {
    IMC::GpioStateGet msg;
    msg.setTimeStamp(0.9360135112284231);
    msg.setSource(63880U);
    msg.setSourceEntity(66U);
    msg.setDestination(64569U);
    msg.setDestinationEntity(110U);
    msg.name.assign("OXIBYSTBXNAFRTQUBBIYRHZAUBPLJIDMIAJDPKRSPAOXXWJLGJNKDQFYVFESNHLYPFVVTHYYEWTZKJJCHMNRHZKVSDMDWEDKTSPDJOZVUXHSLDHGPMQCFQUQITWYXNIQWUMCVXTCXLQSVZCYQOUWFWKGRECZVNRNGKYERYZGSKXTIOEMLOSJLEULIRCZHHTZFOAIQU");

    try
    {
      Utils::ByteBuffer bfr;
      IMC::Packet::serialize(&msg, bfr);
      IMC::Message* msg_d = IMC::Packet::deserialize(bfr.getBuffer(), bfr.getSize());
      test.boolean("GpioStateGet #2", msg == *msg_d);
      delete msg_d;
    }
    catch (IMC::InvalidMessageSize& e)
    {
      (void)e;
      test.boolean("msg #2", msg.getSerializationSize() > DUNE_IMC_CONST_MAX_SIZE);
    }
  }

  {
    IMC::GpioStateSet msg;
    msg.setTimeStamp(0.016497838312518165);
    msg.setSource(61317U);
    msg.setSourceEntity(174U);
    msg.setDestination(32159U);
    msg.setDestinationEntity(154U);
    msg.name.assign("GDJXFTIWGXPLXWHTTBCNOHYOUQGZNTMYRQTGSCCYUFUHBTEIDIWOVOZEHDVFSZSZDHYNKAVMZBGRYKBAYZBLYNLBAPCJYVMODBNIFBMOICSFMDVSKXEKRMQQYKCFHCUKWMCXRSRFJWZRJPPAMXPWBFHAJTGOCNEGDPOXGEIIXJQXQWSPFSNJVLEPXAVTPUSDJZHQBUCVQTFIMRLDWUPKHKRNRLUVNLSZQULUIONOEMWAAJYELGQJIHAKDAWG");
    msg.value = 148U;

    try
    {
      Utils::ByteBuffer bfr;
      IMC::Packet::serialize(&msg, bfr);
      IMC::Message* msg_d = IMC::Packet::deserialize(bfr.getBuffer(), bfr.getSize());
      test.boolean("GpioStateSet #0", msg == *msg_d);
      delete msg_d;
    }
    catch (IMC::InvalidMessageSize& e)
    {
      (void)e;
      test.boolean("msg #0", msg.getSerializationSize() > DUNE_IMC_CONST_MAX_SIZE);
    }
  }

  {
    IMC::GpioStateSet msg;
    msg.setTimeStamp(0.3590238832595588);
    msg.setSource(23943U);
    msg.setSourceEntity(7U);
    msg.setDestination(16459U);
    msg.setDestinationEntity(223U);
    msg.name.assign("ZBYGHMFSVZHDXLENOPJKSPLLJOGRDQVXXSDMGWTIEXIPYMWHMGLGGQWWFIQUNSUHGYPCLEOTIVNOFFOMFSIMBSBCXZIPKBSLNCVRKSNFWAZHOQBZ");
    msg.value = 229U;

    try
    {
      Utils::ByteBuffer bfr;
      IMC::Packet::serialize(&msg, bfr);
      IMC::Message* msg_d = IMC::Packet::deserialize(bfr.getBuffer(), bfr.getSize());
      test.boolean("GpioStateSet #1", msg == *msg_d);
      delete msg_d;
    }
    catch (IMC::InvalidMessageSize& e)
    {
      (void)e;
      test.boolean("msg #1", msg.getSerializationSize() > DUNE_IMC_CONST_MAX_SIZE);
    }
  }

  {
    IMC::GpioStateSet msg;
    msg.setTimeStamp(0.08270752071243892);
    msg.setSource(5921U);
    msg.setSourceEntity(80U);
    msg.setDestination(32559U);
    msg.setDestinationEntity(27U);
    msg.name.assign("OOCXVVPQXDQYDTRHNWCAABEAZVYDMGFUGTLHKIHUBZEWHNDDEYQXOQPMLHMSYFVDTXISKBOTRMWUORTPFCWZFSKCEQSGZH");
    msg.value = 253U;

    try
    {
      Utils::ByteBuffer bfr;
      IMC::Packet::serialize(&msg, bfr);
      IMC::Message* msg_d = IMC::Packet::deserialize(bfr.getBuffer(), bfr.getSize());
      test.boolean("GpioStateSet #2", msg == *msg_d);
      delete msg_d;
    }
    catch (IMC::InvalidMessageSize& e)
    {
      (void)e;
      test.boolean("msg #2", msg.getSerializationSize() > DUNE_IMC_CONST_MAX_SIZE);
    }
  }

  {
    IMC::ColoredDissolvedOrganicMatter msg;
    msg.setTimeStamp(0.9288464337311952);
    msg.setSource(60770U);
    msg.setSourceEntity(130U);
    msg.setDestination(52984U);
    msg.setDestinationEntity(250U);
    msg.value = 0.9091897598826784;

    try
    {
      Utils::ByteBuffer bfr;
      IMC::Packet::serialize(&msg, bfr);
      IMC::Message* msg_d = IMC::Packet::deserialize(bfr.getBuffer(), bfr.getSize());
      test.boolean("ColoredDissolvedOrganicMatter #0", msg == *msg_d);
      delete msg_d;
    }
    catch (IMC::InvalidMessageSize& e)
    {
      (void)e;
      test.boolean("msg #0", msg.getSerializationSize() > DUNE_IMC_CONST_MAX_SIZE);
    }
  }

  {
    IMC::ColoredDissolvedOrganicMatter msg;
    msg.setTimeStamp(0.9982554205089181);
    msg.setSource(12361U);
    msg.setSourceEntity(14U);
    msg.setDestination(25796U);
    msg.setDestinationEntity(210U);
    msg.value = 0.48548923146732126;

    try
    {
      Utils::ByteBuffer bfr;
      IMC::Packet::serialize(&msg, bfr);
      IMC::Message* msg_d = IMC::Packet::deserialize(bfr.getBuffer(), bfr.getSize());
      test.boolean("ColoredDissolvedOrganicMatter #1", msg == *msg_d);
      delete msg_d;
    }
    catch (IMC::InvalidMessageSize& e)
    {
      (void)e;
      test.boolean("msg #1", msg.getSerializationSize() > DUNE_IMC_CONST_MAX_SIZE);
    }
  }

  {
    IMC::ColoredDissolvedOrganicMatter msg;
    msg.setTimeStamp(0.32809595819336757);
    msg.setSource(56356U);
    msg.setSourceEntity(108U);
    msg.setDestination(23785U);
    msg.setDestinationEntity(36U);
    msg.value = 0.5998901256320002;

    try
    {
      Utils::ByteBuffer bfr;
      IMC::Packet::serialize(&msg, bfr);
      IMC::Message* msg_d = IMC::Packet::deserialize(bfr.getBuffer(), bfr.getSize());
      test.boolean("ColoredDissolvedOrganicMatter #2", msg == *msg_d);
      delete msg_d;
    }
    catch (IMC::InvalidMessageSize& e)
    {
      (void)e;
      test.boolean("msg #2", msg.getSerializationSize() > DUNE_IMC_CONST_MAX_SIZE);
    }
  }

  {
    IMC::FluorescentDissolvedOrganicMatter msg;
    msg.setTimeStamp(0.8384205388108392);
    msg.setSource(51469U);
    msg.setSourceEntity(94U);
    msg.setDestination(9598U);
    msg.setDestinationEntity(48U);
    msg.value = 0.14099257997522907;

    try
    {
      Utils::ByteBuffer bfr;
      IMC::Packet::serialize(&msg, bfr);
      IMC::Message* msg_d = IMC::Packet::deserialize(bfr.getBuffer(), bfr.getSize());
      test.boolean("FluorescentDissolvedOrganicMatter #0", msg == *msg_d);
      delete msg_d;
    }
    catch (IMC::InvalidMessageSize& e)
    {
      (void)e;
      test.boolean("msg #0", msg.getSerializationSize() > DUNE_IMC_CONST_MAX_SIZE);
    }
  }

  {
    IMC::FluorescentDissolvedOrganicMatter msg;
    msg.setTimeStamp(0.38345589665324553);
    msg.setSource(45755U);
    msg.setSourceEntity(47U);
    msg.setDestination(40934U);
    msg.setDestinationEntity(146U);
    msg.value = 0.9676372123169568;

    try
    {
      Utils::ByteBuffer bfr;
      IMC::Packet::serialize(&msg, bfr);
      IMC::Message* msg_d = IMC::Packet::deserialize(bfr.getBuffer(), bfr.getSize());
      test.boolean("FluorescentDissolvedOrganicMatter #1", msg == *msg_d);
      delete msg_d;
    }
    catch (IMC::InvalidMessageSize& e)
    {
      (void)e;
      test.boolean("msg #1", msg.getSerializationSize() > DUNE_IMC_CONST_MAX_SIZE);
    }
  }

  {
    IMC::FluorescentDissolvedOrganicMatter msg;
    msg.setTimeStamp(0.03649911931953942);
    msg.setSource(31122U);
    msg.setSourceEntity(144U);
    msg.setDestination(42403U);
    msg.setDestinationEntity(4U);
    msg.value = 0.01398430217518054;

    try
    {
      Utils::ByteBuffer bfr;
      IMC::Packet::serialize(&msg, bfr);
      IMC::Message* msg_d = IMC::Packet::deserialize(bfr.getBuffer(), bfr.getSize());
      test.boolean("FluorescentDissolvedOrganicMatter #2", msg == *msg_d);
      delete msg_d;
    }
    catch (IMC::InvalidMessageSize& e)
    {
      (void)e;
      test.boolean("msg #2", msg.getSerializationSize() > DUNE_IMC_CONST_MAX_SIZE);
    }
  }

  {
    IMC::TotalMagIntensity msg;
    msg.setTimeStamp(0.9826375660047431);
    msg.setSource(54142U);
    msg.setSourceEntity(141U);
    msg.setDestination(63956U);
    msg.setDestinationEntity(9U);
    msg.value = 0.7689931520770084;

    try
    {
      Utils::ByteBuffer bfr;
      IMC::Packet::serialize(&msg, bfr);
      IMC::Message* msg_d = IMC::Packet::deserialize(bfr.getBuffer(), bfr.getSize());
      test.boolean("TotalMagIntensity #0", msg == *msg_d);
      delete msg_d;
    }
    catch (IMC::InvalidMessageSize& e)
    {
      (void)e;
      test.boolean("msg #0", msg.getSerializationSize() > DUNE_IMC_CONST_MAX_SIZE);
    }
  }

  {
    IMC::TotalMagIntensity msg;
    msg.setTimeStamp(0.3562474885413205);
    msg.setSource(42580U);
    msg.setSourceEntity(195U);
    msg.setDestination(1671U);
    msg.setDestinationEntity(79U);
    msg.value = 0.7890767898593805;

    try
    {
      Utils::ByteBuffer bfr;
      IMC::Packet::serialize(&msg, bfr);
      IMC::Message* msg_d = IMC::Packet::deserialize(bfr.getBuffer(), bfr.getSize());
      test.boolean("TotalMagIntensity #1", msg == *msg_d);
      delete msg_d;
    }
    catch (IMC::InvalidMessageSize& e)
    {
      (void)e;
      test.boolean("msg #1", msg.getSerializationSize() > DUNE_IMC_CONST_MAX_SIZE);
    }
  }

  {
    IMC::TotalMagIntensity msg;
    msg.setTimeStamp(0.4855543594403795);
    msg.setSource(9733U);
    msg.setSourceEntity(247U);
    msg.setDestination(53433U);
    msg.setDestinationEntity(63U);
    msg.value = 0.5395467379314135;

    try
    {
      Utils::ByteBuffer bfr;
      IMC::Packet::serialize(&msg, bfr);
      IMC::Message* msg_d = IMC::Packet::deserialize(bfr.getBuffer(), bfr.getSize());
      test.boolean("TotalMagIntensity #2", msg == *msg_d);
      delete msg_d;
    }
    catch (IMC::InvalidMessageSize& e)
    {
      (void)e;
      test.boolean("msg #2", msg.getSerializationSize() > DUNE_IMC_CONST_MAX_SIZE);
    }
  }

  {
    IMC::CommRestriction msg;
    msg.setTimeStamp(0.6341837285437473);
    msg.setSource(34483U);
    msg.setSourceEntity(241U);
    msg.setDestination(12298U);
    msg.setDestinationEntity(0U);
    msg.restriction = 42U;
    msg.reason.assign("LTNNXGZGAFWYAILCMGFILERZFCOXKYQGNKRNUVXPYEHUEJAAIYUTSPQOCONUJDWTMHRXUZAMPHDALUQMVZJYTPEHBNDBFNMWPUIUTICMEROJZID");

    try
    {
      Utils::ByteBuffer bfr;
      IMC::Packet::serialize(&msg, bfr);
      IMC::Message* msg_d = IMC::Packet::deserialize(bfr.getBuffer(), bfr.getSize());
      test.boolean("CommRestriction #0", msg == *msg_d);
      delete msg_d;
    }
    catch (IMC::InvalidMessageSize& e)
    {
      (void)e;
      test.boolean("msg #0", msg.getSerializationSize() > DUNE_IMC_CONST_MAX_SIZE);
    }
  }

  {
    IMC::CommRestriction msg;
    msg.setTimeStamp(0.7710762278856079);
    msg.setSource(4742U);
    msg.setSourceEntity(196U);
    msg.setDestination(35459U);
    msg.setDestinationEntity(163U);
    msg.restriction = 48U;
    msg.reason.assign("ZCPFLHTDOEBDRRUMNFTQ");

    try
    {
      Utils::ByteBuffer bfr;
      IMC::Packet::serialize(&msg, bfr);
      IMC::Message* msg_d = IMC::Packet::deserialize(bfr.getBuffer(), bfr.getSize());
      test.boolean("CommRestriction #1", msg == *msg_d);
      delete msg_d;
    }
    catch (IMC::InvalidMessageSize& e)
    {
      (void)e;
      test.boolean("msg #1", msg.getSerializationSize() > DUNE_IMC_CONST_MAX_SIZE);
    }
  }

  {
    IMC::CommRestriction msg;
    msg.setTimeStamp(0.9386625021381158);
    msg.setSource(32820U);
    msg.setSourceEntity(131U);
    msg.setDestination(55894U);
    msg.setDestinationEntity(33U);
    msg.restriction = 204U;
    msg.reason.assign("XQBUFOUHPNMXETQYQWMAZBTNI");

    try
    {
      Utils::ByteBuffer bfr;
      IMC::Packet::serialize(&msg, bfr);
      IMC::Message* msg_d = IMC::Packet::deserialize(bfr.getBuffer(), bfr.getSize());
      test.boolean("CommRestriction #2", msg == *msg_d);
      delete msg_d;
    }
    catch (IMC::InvalidMessageSize& e)
    {
      (void)e;
      test.boolean("msg #2", msg.getSerializationSize() > DUNE_IMC_CONST_MAX_SIZE);
    }
  }

  {
    IMC::PlantState msg;
    msg.setTimeStamp(0.13903350018186367);
    msg.setSource(3835U);
    msg.setSourceEntity(75U);
    msg.setDestination(50179U);
    msg.setDestinationEntity(16U);
    msg.stage = 221U;
    msg.days_elapsed = 0.13551651099482354;

    try
    {
      Utils::ByteBuffer bfr;
      IMC::Packet::serialize(&msg, bfr);
      IMC::Message* msg_d = IMC::Packet::deserialize(bfr.getBuffer(), bfr.getSize());
      test.boolean("PlantState #0", msg == *msg_d);
      delete msg_d;
    }
    catch (IMC::InvalidMessageSize& e)
    {
      (void)e;
      test.boolean("msg #0", msg.getSerializationSize() > DUNE_IMC_CONST_MAX_SIZE);
    }
  }

  {
    IMC::PlantState msg;
    msg.setTimeStamp(0.7858600250322635);
    msg.setSource(65333U);
    msg.setSourceEntity(107U);
    msg.setDestination(51431U);
    msg.setDestinationEntity(209U);
    msg.stage = 24U;
    msg.days_elapsed = 0.7157475381316857;

    try
    {
      Utils::ByteBuffer bfr;
      IMC::Packet::serialize(&msg, bfr);
      IMC::Message* msg_d = IMC::Packet::deserialize(bfr.getBuffer(), bfr.getSize());
      test.boolean("PlantState #1", msg == *msg_d);
      delete msg_d;
    }
    catch (IMC::InvalidMessageSize& e)
    {
      (void)e;
      test.boolean("msg #1", msg.getSerializationSize() > DUNE_IMC_CONST_MAX_SIZE);
    }
  }

  {
    IMC::PlantState msg;
    msg.setTimeStamp(0.3772638019200837);
    msg.setSource(52024U);
    msg.setSourceEntity(203U);
    msg.setDestination(18825U);
    msg.setDestinationEntity(252U);
    msg.stage = 240U;
    msg.days_elapsed = 0.21541187485929392;

    try
    {
      Utils::ByteBuffer bfr;
      IMC::Packet::serialize(&msg, bfr);
      IMC::Message* msg_d = IMC::Packet::deserialize(bfr.getBuffer(), bfr.getSize());
      test.boolean("PlantState #2", msg == *msg_d);
      delete msg_d;
    }
    catch (IMC::InvalidMessageSize& e)
    {
      (void)e;
      test.boolean("msg #2", msg.getSerializationSize() > DUNE_IMC_CONST_MAX_SIZE);
    }
  }

  {
    IMC::DesiredLight msg;
    msg.setTimeStamp(0.1330323832494289);
    msg.setSource(12635U);
    msg.setSourceEntity(158U);
    msg.setDestination(39457U);
    msg.setDestinationEntity(123U);
    msg.value = 0.3864979535790557;

    try
    {
      Utils::ByteBuffer bfr;
      IMC::Packet::serialize(&msg, bfr);
      IMC::Message* msg_d = IMC::Packet::deserialize(bfr.getBuffer(), bfr.getSize());
      test.boolean("DesiredLight #0", msg == *msg_d);
      delete msg_d;
    }
    catch (IMC::InvalidMessageSize& e)
    {
      (void)e;
      test.boolean("msg #0", msg.getSerializationSize() > DUNE_IMC_CONST_MAX_SIZE);
    }
  }

  {
    IMC::DesiredLight msg;
    msg.setTimeStamp(0.8112962722869304);
    msg.setSource(17359U);
    msg.setSourceEntity(211U);
    msg.setDestination(63193U);
    msg.setDestinationEntity(139U);
    msg.value = 0.7004157068831369;

    try
    {
      Utils::ByteBuffer bfr;
      IMC::Packet::serialize(&msg, bfr);
      IMC::Message* msg_d = IMC::Packet::deserialize(bfr.getBuffer(), bfr.getSize());
      test.boolean("DesiredLight #1", msg == *msg_d);
      delete msg_d;
    }
    catch (IMC::InvalidMessageSize& e)
    {
      (void)e;
      test.boolean("msg #1", msg.getSerializationSize() > DUNE_IMC_CONST_MAX_SIZE);
    }
  }

  {
    IMC::DesiredLight msg;
    msg.setTimeStamp(0.8519616948016517);
    msg.setSource(31038U);
    msg.setSourceEntity(183U);
    msg.setDestination(44415U);
    msg.setDestinationEntity(169U);
    msg.value = 0.6947017508521112;

    try
    {
      Utils::ByteBuffer bfr;
      IMC::Packet::serialize(&msg, bfr);
      IMC::Message* msg_d = IMC::Packet::deserialize(bfr.getBuffer(), bfr.getSize());
      test.boolean("DesiredLight #2", msg == *msg_d);
      delete msg_d;
    }
    catch (IMC::InvalidMessageSize& e)
    {
      (void)e;
      test.boolean("msg #2", msg.getSerializationSize() > DUNE_IMC_CONST_MAX_SIZE);
    }
  }

  {
    IMC::DesiredAirFlow msg;
    msg.setTimeStamp(0.7591248619599541);
    msg.setSource(57719U);
    msg.setSourceEntity(151U);
    msg.setDestination(31535U);
    msg.setDestinationEntity(227U);
    msg.value = 0.9490272918294385;

    try
    {
      Utils::ByteBuffer bfr;
      IMC::Packet::serialize(&msg, bfr);
      IMC::Message* msg_d = IMC::Packet::deserialize(bfr.getBuffer(), bfr.getSize());
      test.boolean("DesiredAirFlow #0", msg == *msg_d);
      delete msg_d;
    }
    catch (IMC::InvalidMessageSize& e)
    {
      (void)e;
      test.boolean("msg #0", msg.getSerializationSize() > DUNE_IMC_CONST_MAX_SIZE);
    }
  }

  {
    IMC::DesiredAirFlow msg;
    msg.setTimeStamp(0.15349205528939724);
    msg.setSource(26295U);
    msg.setSourceEntity(92U);
    msg.setDestination(40912U);
    msg.setDestinationEntity(70U);
    msg.value = 0.7823254032006841;

    try
    {
      Utils::ByteBuffer bfr;
      IMC::Packet::serialize(&msg, bfr);
      IMC::Message* msg_d = IMC::Packet::deserialize(bfr.getBuffer(), bfr.getSize());
      test.boolean("DesiredAirFlow #1", msg == *msg_d);
      delete msg_d;
    }
    catch (IMC::InvalidMessageSize& e)
    {
      (void)e;
      test.boolean("msg #1", msg.getSerializationSize() > DUNE_IMC_CONST_MAX_SIZE);
    }
  }

  {
    IMC::DesiredAirFlow msg;
    msg.setTimeStamp(0.9532171865651384);
    msg.setSource(63423U);
    msg.setSourceEntity(124U);
    msg.setDestination(49158U);
    msg.setDestinationEntity(175U);
    msg.value = 0.7252729422753562;

    try
    {
      Utils::ByteBuffer bfr;
      IMC::Packet::serialize(&msg, bfr);
      IMC::Message* msg_d = IMC::Packet::deserialize(bfr.getBuffer(), bfr.getSize());
      test.boolean("DesiredAirFlow #2", msg == *msg_d);
      delete msg_d;
    }
    catch (IMC::InvalidMessageSize& e)
    {
      (void)e;
      test.boolean("msg #2", msg.getSerializationSize() > DUNE_IMC_CONST_MAX_SIZE);
    }
  }

  {
    IMC::DesiredIrrigation msg;
    msg.setTimeStamp(0.16507041013350676);
    msg.setSource(63182U);
    msg.setSourceEntity(236U);
    msg.setDestination(32834U);
    msg.setDestinationEntity(243U);
    msg.value = 0.6037391687680532;

    try
    {
      Utils::ByteBuffer bfr;
      IMC::Packet::serialize(&msg, bfr);
      IMC::Message* msg_d = IMC::Packet::deserialize(bfr.getBuffer(), bfr.getSize());
      test.boolean("DesiredIrrigation #0", msg == *msg_d);
      delete msg_d;
    }
    catch (IMC::InvalidMessageSize& e)
    {
      (void)e;
      test.boolean("msg #0", msg.getSerializationSize() > DUNE_IMC_CONST_MAX_SIZE);
    }
  }

  {
    IMC::DesiredIrrigation msg;
    msg.setTimeStamp(0.8414901391627992);
    msg.setSource(21326U);
    msg.setSourceEntity(219U);
    msg.setDestination(32867U);
    msg.setDestinationEntity(244U);
    msg.value = 0.15689533736145855;

    try
    {
      Utils::ByteBuffer bfr;
      IMC::Packet::serialize(&msg, bfr);
      IMC::Message* msg_d = IMC::Packet::deserialize(bfr.getBuffer(), bfr.getSize());
      test.boolean("DesiredIrrigation #1", msg == *msg_d);
      delete msg_d;
    }
    catch (IMC::InvalidMessageSize& e)
    {
      (void)e;
      test.boolean("msg #1", msg.getSerializationSize() > DUNE_IMC_CONST_MAX_SIZE);
    }
  }

  {
    IMC::DesiredIrrigation msg;
    msg.setTimeStamp(0.6386029751407422);
    msg.setSource(1242U);
    msg.setSourceEntity(221U);
    msg.setDestination(19812U);
    msg.setDestinationEntity(42U);
    msg.value = 0.9320913719093413;

    try
    {
      Utils::ByteBuffer bfr;
      IMC::Packet::serialize(&msg, bfr);
      IMC::Message* msg_d = IMC::Packet::deserialize(bfr.getBuffer(), bfr.getSize());
      test.boolean("DesiredIrrigation #2", msg == *msg_d);
      delete msg_d;
    }
    catch (IMC::InvalidMessageSize& e)
    {
      (void)e;
      test.boolean("msg #2", msg.getSerializationSize() > DUNE_IMC_CONST_MAX_SIZE);
    }
  }

  {
    IMC::DesiredTemperature msg;
    msg.setTimeStamp(0.456768563476341);
    msg.setSource(27374U);
    msg.setSourceEntity(75U);
    msg.setDestination(62768U);
    msg.setDestinationEntity(195U);
    msg.value = 0.44823043699664944;

    try
    {
      Utils::ByteBuffer bfr;
      IMC::Packet::serialize(&msg, bfr);
      IMC::Message* msg_d = IMC::Packet::deserialize(bfr.getBuffer(), bfr.getSize());
      test.boolean("DesiredTemperature #0", msg == *msg_d);
      delete msg_d;
    }
    catch (IMC::InvalidMessageSize& e)
    {
      (void)e;
      test.boolean("msg #0", msg.getSerializationSize() > DUNE_IMC_CONST_MAX_SIZE);
    }
  }

  {
    IMC::DesiredTemperature msg;
    msg.setTimeStamp(0.2712366669504659);
    msg.setSource(20632U);
    msg.setSourceEntity(209U);
    msg.setDestination(13400U);
    msg.setDestinationEntity(186U);
    msg.value = 0.7750970813349688;

    try
    {
      Utils::ByteBuffer bfr;
      IMC::Packet::serialize(&msg, bfr);
      IMC::Message* msg_d = IMC::Packet::deserialize(bfr.getBuffer(), bfr.getSize());
      test.boolean("DesiredTemperature #1", msg == *msg_d);
      delete msg_d;
    }
    catch (IMC::InvalidMessageSize& e)
    {
      (void)e;
      test.boolean("msg #1", msg.getSerializationSize() > DUNE_IMC_CONST_MAX_SIZE);
    }
  }

  {
    IMC::DesiredTemperature msg;
    msg.setTimeStamp(0.5482159047755284);
    msg.setSource(29305U);
    msg.setSourceEntity(192U);
    msg.setDestination(48789U);
    msg.setDestinationEntity(153U);
    msg.value = 0.5741945924000493;

    try
    {
      Utils::ByteBuffer bfr;
      IMC::Packet::serialize(&msg, bfr);
      IMC::Message* msg_d = IMC::Packet::deserialize(bfr.getBuffer(), bfr.getSize());
      test.boolean("DesiredTemperature #2", msg == *msg_d);
      delete msg_d;
    }
    catch (IMC::InvalidMessageSize& e)
    {
      (void)e;
      test.boolean("msg #2", msg.getSerializationSize() > DUNE_IMC_CONST_MAX_SIZE);
    }
  }

  return test.getReturnValue();
}

/*
 * =====================================================================================
 *
 *       Filename:  Kafka.cpp
 *
 *    Description:  Kafka
 *
 *        Version:  1.0
 *        Created:  2024年03月01日 15时08分51秒
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  vyouzhi (vz), vyouzhi@gmail.com
 *   Organization:  Etomc2.com
 *        LICENSE:  BSD-3-Clause license
 *
 *  Copyright (c) 2019-2022, vyouzhi
 *  All rights reserved.
 *
 *  Redistribution and use in source and binary forms, with or without
 *  modification, are permitted provided that the following conditions are met:
 *  * Redistributions of source code must retain the above copyright
 *  notice, this list of conditions and the following disclaimer.
 *  * Redistributions in binary form must reproduce the above copyright
 *  notice, this list of conditions and the following disclaimer in the
 *  documentation and/or other materials provided with the distribution.
 *  * Neither the name of vyouzhi and/or the DataFrame nor the
 *  names of its contributors may be used to endorse or promote products
 *  derived from this software without specific prior written permission.
 *
 *  THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS "AS IS"
 * AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE
 * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE
 * ARE DISCLAIMED. IN NO EVENT SHALL vyouzhi BE LIABLE FOR ANY DIRECT, INDIRECT,
 * INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT
 * LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, DATA,
 * OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF
 * LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT (INCLUDING
 * NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF THIS SOFTWARE,
 * EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
 * =====================================================================================
 */

#include "kafka/Consumer.hpp"

#include <signal.h>

#include <cstdint>
#include <cstdlib>
#include <string>
namespace e2q {
/*
 * ===  FUNCTION  =============================
 *
 *         Name:  KfConsumeCb::SymbolInit
 *  ->  void *
 *  Parameters:
 *  - size_t  arg
 *  Description:
 *  #%.3f;%s:%d,%s:%d...
 *  #tick_time;index_name:index_cficode,symbol_name:symbol_cficode
 * ============================================
 */
void KfConsumeCb::SymbolInit(const char *p, int sz)
{
    // std::string seg;
    // std::string sym;
    // std::string id;
    // std::string::size_type n;
    // std::string sleep_time;

} /* -----  end of function KfConsumeCb::SymbolInit  ----- */

/*
 * ===  FUNCTION  dfsdf
 *
 *         Name:  KfConsumeCb::SymbolExrd
 *  ->  void *
 *  Parameters:
 *  - size_t  arg
 *  Description:
 *  @%d,%d%02d%02d,%d,%.02f,%.02f
 *  sym_code,year,month,day,category,fenhong,songzhuangu
 * ============================================
 */
void KfConsumeCb::SymbolExrd(const char *p, int sz) {

} /* -----  end of function KfConsumeCb::SymbolExrd  ----- */

/*
 * ===  FUNCTION  =============================
 *
 *         Name:  KfConsumeCb::StopOrder
 *  ->  void *
 *  Parameters:
 *  - size_t  arg
 *  Description:
 *  ','  size==1
 * ============================================
 */
void KfConsumeCb::StopOrder() {
} /* -----  end of function KfConsumeCb::StopOrder  ----- */

/*
 * ===  FUNCTION  =============================
 *
 *         Name:  KfConsumeCb::ExitOrder
 *  ->  void *
 *  Parameters:
 *  - size_t  arg
 *  Description:
 *
 * ============================================
 */
void KfConsumeCb::ExitOrder()
{
    _kafka_run = 0;
} /* -----  end of function KfConsumeCb::ExitOrder  ----- */

/*
 * ===  FUNCTION  =============================
 *
 *         Name:  KfConsumeCb::callback
 *  ->  void *
 *  Parameters:
 *  - size_t  arg
 *  Description:
 *  T%d:%d@%d,%d,%d,%.2f,%d,%d#%d,%d,%d,%.2f,%d,%d....
 *  Tticker_number:unix_time@frame,side,qty,price,message
 * type,cficode#frame,side,qty,price,message type,cficode ...
 * eg:
 * T2:1735544400@5,0,658905,93589.64,119,179591#5,0,658905,93589.64,119,0
 * ============================================
 */
void KfConsumeCb::callback(const char *ptr, int sz, int64_t moffset)
{
    if (ptr == nullptr) {
        log::echo("payload ie empty");
        return;
    }
    // T = ptr + 1
    //  const char *tick_data = ptr + 1;

} /* -----  end of function KfConsumeCb::callback  ----- */

/*
 * ===  FUNCTION  =============================
 *
 *         Name:  KfConsumeCb::logs
 *  ->  void *
 *  Parameters:
 *  - size_t  arg
 *  Description:
 *
 * ============================================
 */
void KfConsumeCb::logs(std::array<SeqType, trading_protocols> trad_data,
                       int64_t moffset)
{
} /* -----  end of function KfConsumeCb::logs  ----- */
/*
 * ===  FUNCTION  =============================
 *
 *         Name:  KafkaFeed::handle
 *  ->  void *
 *  Parameters:
 *  - size_t  arg
 *  Description:
 *
 * ============================================
 */
void KafkaFeed::handle(TradType tradcall)
{
    if (tradcall == nullptr) {
        log::bug("TradType is nullptr");
        return;
    }
    if (_bokers.length() == 0 || _topic.length() == 0) {
        log::bug("bokers or topic is empty");
        return;
    }

    std::string errstr;
    int32_t partition = RdKafka::Topic::PARTITION_UA;
    /**
     * kafka-topics.sh --describe	Partition: 0
     *
     */
    partition = 0;
    // --from-beginning
    int64_t start_offset = RdKafka::Topic::OFFSET_END;

    int use_ccb = 1;

    /*
     * Create configuration objects
     */
    RdKafka::Conf *conf = RdKafka::Conf::create(RdKafka::Conf::CONF_GLOBAL);
    if (!conf) {
        log::bug("conf is null");
        return;
    }
    RdKafka::Conf *tconf = RdKafka::Conf::create(RdKafka::Conf::CONF_TOPIC);
    if (!tconf) {
        delete conf;
        log::bug("tconf");
        return;
    }
    /*
     * Set configuration properties
     */
    conf->set("metadata.broker.list", _bokers, errstr);

    KfEventCb ex_event_cb;
    conf->set("event_cb", &ex_event_cb, errstr);

    signal(SIGINT, sigterm);
    signal(SIGTERM, sigterm);

    /*
     * Consumer mode
     */

    conf->set("enable.partition.eof", "true", errstr);

    /*
     * Create consumer using accumulated global configuration.
     */
    RdKafka::Consumer *consumer = RdKafka::Consumer::create(conf, errstr);
    if (!consumer) {
        log::bug("Failed to create consumer: ", errstr);
        delete conf;
        delete tconf;
        exit(1);
    }

    log::echo(consumer->name(), " Created consumer ");

    /*
     * Create topic handle.
     */
    RdKafka::Topic *topic =
        RdKafka::Topic::create(consumer, _topic, tconf, errstr);
    if (!topic) {
        log::bug("Failed to create topic: ", errstr);

        delete consumer;
        delete tconf;
        delete conf;

        exit(1);
    }

    /*
     * Start consumer for topic+partition at start offset
     */
    RdKafka::ErrorCode resp = consumer->start(topic, partition, start_offset);
    if (resp != RdKafka::ERR_NO_ERROR) {
        log::bug("Failed to start consumer: ", RdKafka::err2str(resp));
        delete topic;
        delete consumer;
        delete tconf;
        delete conf;

        exit(1);
    }
    //    std::size_t kcount = 1;

    KfConsumeCb ex_consume_cb;
    ex_consume_cb.handle(tradcall);

    /*
     * Consume messages
     */
    int timeout_ms = 1000;
    while (_kafka_run) {
        consumer->consume_callback(topic, partition, timeout_ms, &ex_consume_cb,
                                   &use_ccb);
        consumer->poll(0);
        // RdKafka::Message *msg = consumer->consume(topic, partition,
        // timeout_ms); ex_consume_cb.msg_consume(msg, nullptr); delete msg;
        // consumer->poll(FinFabr->_offer_time);
    }

    /*
     * Stop consumer
     */

    consumer->stop(topic, partition);

    //  consumer->poll(FinFabr->_offer_time);

    delete topic;
    delete consumer;

    delete conf;
    delete tconf;

    /*
     * Wait for RdKafka to decommission.
     * This is not strictly needed (when check outq_len() above), but
     * allows RdKafka to clean up all its resources before the application
     * exits so that memory profilers such as valgrind wont complain about
     * memory leaks.
     */
    RdKafka::wait_destroyed(5000);

} /* -----  end of function KafkaFeed::handle  ----- */
}  // namespace e2q

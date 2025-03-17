/*
 * =====================================================================================
 *
 *       Filename:  Kafka.hpp
 *
 *    Description:  Kafak.hpp
 *
 *        Version:  1.0
 *        Created:  2024年02月04日 10时59分58秒
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
 *
 * =====================================================================================
 */

#ifndef KAFKA_INC
#define KAFKA_INC

#include <atomic>
#include <cstddef>
#include <cstdint>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <string>
#include <vector>

#include "Log.hpp"
#include "librdkafka/rdkafkacpp.h"
#include "util_zts.hpp"
namespace e2q {

/**
 * https://github.com/confluentinc/librdkafka/blob/master/examples/rdkafka_example.cpp
 */
inline volatile std::atomic<std::uint32_t> _kafka_run = 1;
inline bool exit_eof = false;

inline void sigterm(int sig) { _kafka_run = 0; }

class KfEventCb : public RdKafka::EventCb {
public:
    void event_cb(RdKafka::Event &event)
    {
        switch (event.type()) {
            case RdKafka::Event::EVENT_ERROR:
                if (event.fatal()) {
                    _kafka_run = 0;
                }
                log::bug("FATAL ERROR (", RdKafka::err2str(event.err()),
                         "): ", event.str());
                break;

            case RdKafka::Event::EVENT_STATS:
                log::bug("\"STATS\": ", event.str());
                break;

            case RdKafka::Event::EVENT_LOG:
                log::bug("LOG-", event.severity(), "-", event.fac().c_str(),
                         "-", event.str().c_str());
                break;

            default:
                log::bug("EVENT ", event.type(), " (",
                         RdKafka::err2str(event.err()), "): ", event.str());
                break;
        }
    }
};

/*
 * ================================
 *        Class:  KfConsumeCb
 *  Description:
 * ================================
 */
class KfConsumeCb : public RdKafka::ConsumeCb {
public:
    /* =============  LIFECYCLE     =================== */
    KfConsumeCb() {}; /* constructor */

    /* =============  ACCESSORS     =================== */
    void consume_cb(RdKafka::Message &msg, void *opaque)
    {
        msg_consume(&msg, opaque);
    }
    void msg_consume(RdKafka::Message *message, void *opaque)
    {
        const RdKafka::Headers *headers;
        int64_t now_offset = 0;
        // log::info("Read msg at offset ", message->offset());

        switch (message->err()) {
            case RdKafka::ERR__TIMED_OUT:
                break;

            case RdKafka::ERR_NO_ERROR: {
                /* Real message */

                if (message->key()) {
                    log::info("Key: ", *message->key());
                }
                headers = message->headers();
                if (headers) {
                    std::vector<RdKafka::Headers::Header> hdrs =
                        headers->get_all();
                    for (size_t i = 0; i < hdrs.size(); i++) {
                        const RdKafka::Headers::Header hdr = hdrs[i];

                        if (hdr.value() != NULL) {
                            log::bug(" Header: %s ", hdr.key().c_str(), "=",
                                     (int)hdr.value_size(), ".",
                                     (const char *)hdr.value());
                        }
                        else {
                            log::bug(" Header:  ", hdr.key().c_str(), "= NULL");
                        }
                    }
                }

                now_offset = message->offset();
                if (_lastoffset >= now_offset) {
                    log::bug("repeat offset:", now_offset);
                }
                _lastoffset = now_offset;

                int sz = static_cast<int>(message->len());
                const char *p = static_cast<const char *>(message->payload());

                if (*p == '#') {
                    SymbolInit(p, sz);
                }
                else if (*p == '@') {
                    SymbolExrd(p, sz);
                }
                else if (*p == ',' && sz == 1) {
                    StopOrder();
                }
                else if (p == nullptr || *p == '.') {
                    ExitOrder();
                }
                else if (*p == 'T') {
                    callback(p, sz, _lastoffset);
                }
                else {
                    log::bug("bad data!");
                }

                break;
            }

            case RdKafka::ERR__PARTITION_EOF:
                /* Last message */
                if (exit_eof) {
                    ExitOrder();
                }
                break;

            case RdKafka::ERR__UNKNOWN_TOPIC:
            case RdKafka::ERR__UNKNOWN_PARTITION:
                log::bug("Consume failed: ", message->errstr());
                ExitOrder();
                break;

            default:
                /* Errors */
                log::bug("Consume failed: ", message->errstr());
                ExitOrder();
        }
    }
    /* =============  MUTATORS      =================== */
    void handle(TradType t) { _TunCall = std::move(t); }
    /* =============  OPERATORS     =================== */

protected:
    /* =============  METHODS       =================== */

    /* =============  DATA MEMBERS  =================== */

private:
    /* =============  METHODS       =================== */

    void SymbolInit(const char *p, int sz);
    void SymbolExrd(const char *p, int sz);
    void StopOrder();
    void ExitOrder();
    void logs(std::array<SeqType, trading_protocols>, int64_t);

    /*
     * ===  FUNCTION  =============================
     *
     *         Name:  callback
     *  ->  void *
     *  Parameters:
     *  - size_t  arg
     *  Description:
     *
     * ============================================
     */

    void callback(const char *ptr, int sz, int64_t);

    /* -----  end of function callback  ----- */

    /* =============  DATA MEMBERS  =================== */
    TradType _TunCall = nullptr;
    long _lastTime = 0;

    int64_t _lastoffset;

}; /* -----  end of class KfConsumeCb  ----- */

/*
 * ================================
 *        Class:  KafkaFeed
 *  Description:
 * ================================
 */
class KafkaFeed {
public:
    /* =============  LIFECYCLE     =================== */
    KafkaFeed(std::string &bokers, std::string &topic)
        : _bokers(bokers), _topic(topic) {

          }; /* constructor */

    /* =============  ACCESSORS     =================== */
    void handle(TradType tt);

    /* =============  MUTATORS      =================== */

    /* =============  OPERATORS     =================== */

protected:
    /* =============  METHODS       =================== */

    /* =============  DATA MEMBERS  =================== */

private:
    /* =============  METHODS       =================== */

    /* =============  DATA MEMBERS  =================== */
    std::string _bokers;
    std::string _topic;
    //    std::vector<std::string> _symobls;
}; /* -----  end of class KafkaFeed  ----- */

}  // namespace e2q
#endif /* ----- #ifndef KAFKA_INC  ----- */

/*
 * =====================================================================================
 *
 *       Filename:  itch50.cpp
 *
 *    Description:  itch50
 *
 *        Version:  1.0
 *        Created:  2024年03月16日 11时51分05秒
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
#include "itch50.hpp"

#include <cstddef>
#include <cstdint>
#include <cstdio>

namespace e2q {
inline bool IsBigEndian() { return false; }

inline bool IsLittleEndian() { return true; }

inline size_t ReadBigEndian(const void* buffer, int16_t& value)
{
    if (IsBigEndian()) {
        ((uint8_t*)&value)[0] = ((const uint8_t*)buffer)[0];
        ((uint8_t*)&value)[1] = ((const uint8_t*)buffer)[1];
    }
    else {
        ((uint8_t*)&value)[0] = ((const uint8_t*)buffer)[1];
        ((uint8_t*)&value)[1] = ((const uint8_t*)buffer)[0];
    }

    return 2;
}

inline size_t ReadBigEndian(const void* buffer, uint16_t& value)
{
    if (IsBigEndian()) {
        ((uint8_t*)&value)[0] = ((const uint8_t*)buffer)[0];
        ((uint8_t*)&value)[1] = ((const uint8_t*)buffer)[1];
    }
    else {
        ((uint8_t*)&value)[0] = ((const uint8_t*)buffer)[1];
        ((uint8_t*)&value)[1] = ((const uint8_t*)buffer)[0];
    }

    return 2;
}

inline size_t ReadBigEndian(const void* buffer, int32_t& value)
{
    if (IsBigEndian()) {
        ((uint8_t*)&value)[0] = ((const uint8_t*)buffer)[0];
        ((uint8_t*)&value)[1] = ((const uint8_t*)buffer)[1];
        ((uint8_t*)&value)[2] = ((const uint8_t*)buffer)[2];
        ((uint8_t*)&value)[3] = ((const uint8_t*)buffer)[3];
    }
    else {
        ((uint8_t*)&value)[0] = ((const uint8_t*)buffer)[3];
        ((uint8_t*)&value)[1] = ((const uint8_t*)buffer)[2];
        ((uint8_t*)&value)[2] = ((const uint8_t*)buffer)[1];
        ((uint8_t*)&value)[3] = ((const uint8_t*)buffer)[0];
    }

    return 4;
}

inline size_t ReadBigEndian(const void* buffer, uint32_t& value)
{
    if (IsBigEndian()) {
        ((uint8_t*)&value)[0] = ((const uint8_t*)buffer)[0];
        ((uint8_t*)&value)[1] = ((const uint8_t*)buffer)[1];
        ((uint8_t*)&value)[2] = ((const uint8_t*)buffer)[2];
        ((uint8_t*)&value)[3] = ((const uint8_t*)buffer)[3];
    }
    else {
        ((uint8_t*)&value)[0] = ((const uint8_t*)buffer)[3];
        ((uint8_t*)&value)[1] = ((const uint8_t*)buffer)[2];
        ((uint8_t*)&value)[2] = ((const uint8_t*)buffer)[1];
        ((uint8_t*)&value)[3] = ((const uint8_t*)buffer)[0];
    }

    return 4;
}

inline size_t ReadBigEndian(const void* buffer, int64_t& value)
{
    if (IsBigEndian()) {
        ((uint8_t*)&value)[0] = ((const uint8_t*)buffer)[0];
        ((uint8_t*)&value)[1] = ((const uint8_t*)buffer)[1];
        ((uint8_t*)&value)[2] = ((const uint8_t*)buffer)[2];
        ((uint8_t*)&value)[3] = ((const uint8_t*)buffer)[3];
        ((uint8_t*)&value)[4] = ((const uint8_t*)buffer)[4];
        ((uint8_t*)&value)[5] = ((const uint8_t*)buffer)[5];
        ((uint8_t*)&value)[6] = ((const uint8_t*)buffer)[6];
        ((uint8_t*)&value)[7] = ((const uint8_t*)buffer)[7];
    }
    else {
        ((uint8_t*)&value)[0] = ((const uint8_t*)buffer)[7];
        ((uint8_t*)&value)[1] = ((const uint8_t*)buffer)[6];
        ((uint8_t*)&value)[2] = ((const uint8_t*)buffer)[5];
        ((uint8_t*)&value)[3] = ((const uint8_t*)buffer)[4];
        ((uint8_t*)&value)[4] = ((const uint8_t*)buffer)[3];
        ((uint8_t*)&value)[5] = ((const uint8_t*)buffer)[2];
        ((uint8_t*)&value)[6] = ((const uint8_t*)buffer)[1];
        ((uint8_t*)&value)[7] = ((const uint8_t*)buffer)[0];
    }

    return 8;
}

inline size_t ReadBigEndian(const void* buffer, uint64_t& value)
{
    if (IsBigEndian()) {
        ((uint8_t*)&value)[0] = ((const uint8_t*)buffer)[0];
        ((uint8_t*)&value)[1] = ((const uint8_t*)buffer)[1];
        ((uint8_t*)&value)[2] = ((const uint8_t*)buffer)[2];
        ((uint8_t*)&value)[3] = ((const uint8_t*)buffer)[3];
        ((uint8_t*)&value)[4] = ((const uint8_t*)buffer)[4];
        ((uint8_t*)&value)[5] = ((const uint8_t*)buffer)[5];
        ((uint8_t*)&value)[6] = ((const uint8_t*)buffer)[6];
        ((uint8_t*)&value)[7] = ((const uint8_t*)buffer)[7];
    }
    else {
        ((uint8_t*)&value)[0] = ((const uint8_t*)buffer)[7];
        ((uint8_t*)&value)[1] = ((const uint8_t*)buffer)[6];
        ((uint8_t*)&value)[2] = ((const uint8_t*)buffer)[5];
        ((uint8_t*)&value)[3] = ((const uint8_t*)buffer)[4];
        ((uint8_t*)&value)[4] = ((const uint8_t*)buffer)[3];
        ((uint8_t*)&value)[5] = ((const uint8_t*)buffer)[2];
        ((uint8_t*)&value)[6] = ((const uint8_t*)buffer)[1];
        ((uint8_t*)&value)[7] = ((const uint8_t*)buffer)[0];
    }

    return 8;
}

/*
 * ===  FUNCTION  =============================
 *
 *         Name:  ItchMsg::read
 *  ->  void *
 *  Parameters:
 *  - size_t  arg
 *  Description:
 *
 * ============================================
 */
/* std::size_t s; */
/* int16_t val_16 = 0; */
/* uint16_t uval_16 = 0; */
/* int32_t val_32 = 0; */
/* uint32_t uval_32 = 0; */
/* int64_t val_64 = 0; */
/* uint64_t uval_64 = 0; */
/* // s = ctou(nullptr, val_16); */
/* s = ctou(nullptr, uval_16); */
/* // s = ctou(nullptr, val_32); */
/* s = ctou(nullptr, uval_32); */
/* // s = ctou(nullptr, val_64); */
/* s = ctou(nullptr, uval_64); */
void ItchMsg::read()
{
    log::echo("path:", _path);
    _fp = fopen(_path.c_str(), "r");
    if (_fp == NULL) {
        log::echo("error path:");

        return;
    }

    _base_size = fldsiz(BaseMessage, StockLocate) +
                 fldsiz(BaseMessage, TrackingNumber) +
                 (fldsiz(BaseMessage, Timestamp) - 2);
    log::echo("_base_size:", _base_size,
              " stock:", fldsiz(BaseMessage, StockLocate),
              " track:", fldsiz(BaseMessage, TrackingNumber),
              " time:", fldsiz(BaseMessage, Timestamp));

    std::size_t next = 0;
    std::size_t key_size = sizeof(char);
    log::echo("key_size:", key_size);
    fseek(_fp, 2, SEEK_SET);
    memset(_buffer, 0, BUFF_SIZE);
    while ((_msize = fread(_key, key_size, 1, _fp)) >

           0) {
        log::echo("a,seek:", ftell(_fp));

        log::echo("key:", *_key);
        message();
        log::echo("next:", next);
        if (test == 1 || next > 20000) {
            break;
        }

        next++;
    }

    fclose(_fp);
} /* -----  end of function ItchMsg::read  ----- */

/*
 * ===  FUNCTION  =============================
 *
 *         Name:  ItchMsg::message
 *  ->  void *
 *  Parameters:
 *  - size_t  arg
 *  Description:
 *
 * ============================================
 */
void ItchMsg::message()
{
    auto fun_time = [](double tm) {
        double seconds = tm * 0.000000001;
        int nn = 3600;
        int mm = 60;
        int hour = (int)seconds / nn;
        int minute = ((int)seconds % nn) / mm;
        int second = (int)seconds % mm;

        printf("%.4f  %02d : %02d :%02d \n", seconds, hour, minute, second);
    };  // -----  end lambda  -----

    _pos = 1;
    test = 0;
    std::size_t nmemb = 1;
    uint64_t tm = 0;
    switch (*_key) {
        case 'S': {
            // SystemEventMessage

            _pos = _base_size + fldsiz(SystemEventMessage, EventCode);
            log::echo("S size:", _pos);

            _msize = fread(_buffer, _pos, 1, _fp);

            log::echo("time. seek:", ftell(_fp), " msize:", _msize);

            tm = parse_ts(_buffer + 4);

            log::echo("tm:", tm, " time: ");
            fun_time(tm);

            // test = 1;
            break;
        }
        case 'R': {
            // StockDirectoryMessage
            _pos = _base_size + fldsiz(StockDirectoryMessage, Stock) +
                   fldsiz(StockDirectoryMessage, MarketCategory) +
                   fldsiz(StockDirectoryMessage, FinancialStatusIndicator) +
                   fldsiz(StockDirectoryMessage, RoundLotSize) +
                   fldsiz(StockDirectoryMessage, RoundLotsOnly) +
                   fldsiz(StockDirectoryMessage, IssueClassification) +
                   fldsiz(StockDirectoryMessage, IssueSubType) +
                   fldsiz(StockDirectoryMessage, Authenticity) +
                   fldsiz(StockDirectoryMessage, ShortSaleThresholdIndicator) +
                   fldsiz(StockDirectoryMessage, IPOFlag) +
                   fldsiz(StockDirectoryMessage, LULDReferencePriceTier) +
                   fldsiz(StockDirectoryMessage, ETPFlag) +
                   fldsiz(StockDirectoryMessage, ETPLeverageFactor) +
                   fldsiz(StockDirectoryMessage, InverseIndicator);

            _msize = fread(_buffer, _pos, 1, _fp);
            log::echo("time. seek:", ftell(_fp), " msize:", _msize);

            tm = parse_ts(_buffer + 4);
            log::echo("tm:", tm, " time: ");
            fun_time(tm);

            log::echo("R size:", _pos);

            break;
            // test = 1;
        }
        case 'H':
        case 'T': {
            _pos = _base_size + fldsiz(StockTradingActionMessage, Stock) +
                   fldsiz(StockTradingActionMessage, TradingState) +
                   fldsiz(StockTradingActionMessage, Reserved) +
                   fldsiz(StockTradingActionMessage, Reason) * 4;
            log::echo("H or T size:", _pos);
            _msize = fread(_buffer, _pos, 1, _fp);
            log::echo("time. seek:", ftell(_fp), " msize:", _msize);

            tm = parse_ts(_buffer + 4);
            log::echo("tm:", tm, " time: ");
            fun_time(tm);

            // test = 1;
            break;
        }
        case 'Y': {
            _pos = _base_size + fldsiz(RegSHOMessage, Stock) +
                   fldsiz(RegSHOMessage, RegSHOAction);

            log::echo("Y size:", _pos);
            nmemb = 1;

            _msize = fread(_buffer, _pos, nmemb, _fp);
            log::echo("time. seek:", ftell(_fp), " msize:", _msize);

            tm = parse_ts(_buffer + 4);
            log::echo("tm:", tm, " time: ");
            fun_time(tm);

            //  test = 1;
            break;
        }
        case 'L': {
            _pos =
                _base_size + fldsiz(MarketParticipantPositionMessage, Stock) +
                fldsiz(MarketParticipantPositionMessage, MPID) +
                fldsiz(MarketParticipantPositionMessage, PrimaryMarketMaker) +
                fldsiz(MarketParticipantPositionMessage, MarketMakerMode) +
                fldsiz(MarketParticipantPositionMessage,
                       MarketParticipantState);

            nmemb = 1;

            _msize = fread(_buffer, _pos, nmemb, _fp);
            log::echo("time. seek:", ftell(_fp), " msize:", _msize);

            tm = parse_ts(_buffer + 4);
            log::echo("tm:", tm, " time: ");
            fun_time(tm);

            break;
        }
        case 'V': {
            _pos = _base_size + fldsiz(MWCBDeclineMessage, Level1) +
                   fldsiz(MWCBDeclineMessage, Level2) +
                   fldsiz(MWCBDeclineMessage, Level3);

            _msize = fread(_buffer, _pos, 1, _fp);
            if (_msize == -1) {
                log::bug("error");
                break;
            }
            log::echo("V size:", _pos);
            tm = parse_ts(_buffer + 4);
            log::echo("tm:", tm, " time: ");
            fun_time(tm);

            break;
        }
        case 'W': {
            _pos = _base_size + fldsiz(MWCBStatusMessage, BreachedLevel);
            _msize = fread(_buffer, _pos, 1, _fp);
            if (_msize == -1) {
                log::bug("error");
                break;
            }
            log::echo("V size:", _pos);
            tm = parse_ts(_buffer + 4);
            log::echo("tm:", tm, " time: ");

            fun_time(tm);

            break;
        }
        case 'K': {
            _pos = _base_size + fldsiz(IPOQuotingMessage, Stock) +
                   fldsiz(IPOQuotingMessage, IPOReleaseTime) +
                   fldsiz(IPOQuotingMessage, IPOReleaseQualifier) +
                   fldsiz(IPOQuotingMessage, IPOPrice);
            _msize = fread(_buffer, _pos, 1, _fp);
            if (_msize == -1) {
                log::bug("error");
                break;
            }
            log::echo("K size:", _pos);
            tm = parse_ts(_buffer + 4);
            log::echo("tm:", tm, " time: ");
            fun_time(tm);

            break;
        }
        case 'A': {
            //            AddOrderMessage

            _pos = _base_size + fldsiz(AddOrderMessage, OrderReferenceNumber) +
                   fldsiz(AddOrderMessage, BuySellIndicator) +
                   fldsiz(AddOrderMessage, Shares) +
                   fldsiz(AddOrderMessage, Stock) +
                   fldsiz(AddOrderMessage, Price);

            _msize = fread(_buffer, _pos, 1, _fp);
            if (_msize == -1) {
                log::bug("error");
                break;
            }
            log::echo("A size:", _pos);
            tm = parse_ts(_buffer + 4);
            log::echo("tm:", tm, " time: ");
            fun_time(tm);

            break;
        }
        case 'F': {
            _pos = _base_size +
                   fldsiz(AddOrderMPIDMessage, OrderReferenceNumber) +
                   fldsiz(AddOrderMPIDMessage, BuySellIndicator) +
                   fldsiz(AddOrderMPIDMessage, Shares) +
                   fldsiz(AddOrderMPIDMessage, Stock) +
                   fldsiz(AddOrderMPIDMessage, Price) +
                   fldsiz(AddOrderMPIDMessage, Attribution);

            _msize = fread(_buffer, _pos, 1, _fp);
            if (_msize == -1) {
                log::bug("error");
                break;
            }
            log::echo("F size:", _pos);
            tm = parse_ts(_buffer + 4);
            log::echo("tm:", tm, " time: ");
            fun_time(tm);

            break;
        }
        case 'E': {
            _pos = _base_size +
                   fldsiz(OrderExecutedMessage, OrderReferenceNumber) +
                   fldsiz(OrderExecutedMessage, ExecutedShares) +
                   fldsiz(OrderExecutedMessage, MatchNumber);
            _msize = fread(_buffer, _pos, 1, _fp);
            if (_msize == -1) {
                log::bug("error");
                break;
            }
            log::echo("E size:", _pos);
            tm = parse_ts(_buffer + 4);
            log::echo("tm:", tm, " time: ");
            fun_time(tm);

            break;
        }
        case 'C': {
            _pos = _base_size +
                   fldsiz(OrderExecutedWithPriceMessage, OrderReferenceNumber) +
                   fldsiz(OrderExecutedWithPriceMessage, ExecutedShares) +
                   fldsiz(OrderExecutedWithPriceMessage, MatchNumber) +
                   fldsiz(OrderExecutedWithPriceMessage, Printable) +
                   fldsiz(OrderExecutedWithPriceMessage, ExecutionPrice);
            ;
            _msize = fread(_buffer, _pos, 1, _fp);
            if (_msize == -1) {
                log::bug("error");
                break;
            }
            log::echo("C size:", _pos);
            tm = parse_ts(_buffer + 4);
            log::echo("tm:", tm, " time: ");
            fun_time(tm);

            break;
        }
        case 'X': {
            _pos = _base_size +
                   fldsiz(OrderCancelMessage, OrderReferenceNumber) +
                   fldsiz(OrderCancelMessage, CanceledShares)

                ;
            _msize = fread(_buffer, _pos, 1, _fp);
            if (_msize == -1) {
                log::bug("error");
                break;
            }
            log::echo("X size:", _pos);

            tm = parse_ts(_buffer + 4);
            log::echo("tm:", tm, " time: ");
            fun_time(tm);

            break;
        }
        case 'D': {
            _pos = _base_size + fldsiz(OrderDeleteMessage, OrderReferenceNumber)

                ;
            _msize = fread(_buffer, _pos, 1, _fp);
            if (_msize == -1) {
                log::bug("error");
                break;
            }
            log::echo("D size:", _pos);
            tm = parse_ts(_buffer + 4);
            log::echo("tm:", tm, " time: ");
            fun_time(tm);

            break;
        }
        case 'U': {
            _pos = _base_size +
                   fldsiz(OrderReplaceMessage, OriginalOrderReferenceNumber) +
                   fldsiz(OrderReplaceMessage, NewOrderReferenceNumber) +
                   fldsiz(OrderReplaceMessage, Shares) +
                   fldsiz(OrderReplaceMessage, Price);

            _msize = fread(_buffer, _pos, 1, _fp);

            if (_msize == -1) {
                log::bug("error");
                break;
            }
            log::echo("U size:", _pos);
            tm = parse_ts(_buffer + 4);
            log::echo("tm:", tm, " time: ");
            fun_time(tm);

            break;
        }
        case 'P': {
            _pos = _base_size + fldsiz(TradeMessage, OrderReferenceNumber) +
                   fldsiz(TradeMessage, BuySellIndicator) +
                   fldsiz(TradeMessage, Shares) + fldsiz(TradeMessage, Stock) +
                   fldsiz(TradeMessage, Price) +
                   fldsiz(TradeMessage, MatchNumber)

                ;
            _msize = fread(_buffer, _pos, 1, _fp);
            if (_msize == -1) {
                log::bug("error");
                break;
            }
            log::echo("P size:", _pos);
            tm = parse_ts(_buffer + 4);
            log::echo("tm:", tm, " time: ");
            fun_time(tm);

            break;
        }
        case 'Q': {
            // CrossTradeMessage
            _pos = _base_size + fldsiz(CrossTradeMessage, Shares) +
                   fldsiz(CrossTradeMessage, Stock) +
                   fldsiz(CrossTradeMessage, CrossPrice) +
                   fldsiz(CrossTradeMessage, MatchNumber) +
                   fldsiz(CrossTradeMessage, CrossType);
            _msize = fread(_buffer, _pos, 1, _fp);

            if (_msize == -1) {
                log::bug("error");
                break;
            }
            log::echo("Q size:", _pos);
            tm = parse_ts(_buffer + 4);
            log::echo("tm:", tm, " time: ");
            fun_time(tm);

            break;
        }
        case 'B': {
            _pos = _base_size + fldsiz(BrokenTradeMessage, MatchNumber);
            _msize = fread(_buffer, _pos, 1, _fp);
            if (_msize == -1) {
                log::bug("error");
                break;
            }
            log::echo("B size:", _pos);
            tm = parse_ts(_buffer + 4);
            log::echo("tm:", tm, " time: ");
            fun_time(tm);

            break;
        }
        case 'I': {
            _pos = _base_size + fldsiz(NOIIMessage, PairedShares) +
                   fldsiz(NOIIMessage, ImbalanceShares) +
                   fldsiz(NOIIMessage, ImbalanceDirection) +
                   fldsiz(NOIIMessage, Stock) + fldsiz(NOIIMessage, FarPrice) +
                   fldsiz(NOIIMessage, NearPrice) +
                   fldsiz(NOIIMessage, CurrentReferencePrice) +
                   fldsiz(NOIIMessage, CrossType) +
                   fldsiz(NOIIMessage, PriceVariationIndicator)

                ;
            _msize = fread(_buffer, _pos, 1, _fp);
            if (_msize == -1) {
                log::bug("error");
                break;
            }
            log::echo("I size:", _pos);
            tm = parse_ts(_buffer + 4);
            log::echo("tm:", tm, " time: ");
            fun_time(tm);

            break;
        }
        case 'N': {
            // RPIIMessage
            _pos = _base_size + fldsiz(RPIIMessage, Stock) +
                   fldsiz(RPIIMessage, InterestFlag);
            _msize = fread(_buffer, _pos, 1, _fp);

            if (_msize == -1) {
                log::bug("error");
                break;
            }
            log::echo("N size:", _pos);
            tm = parse_ts(_buffer + 4);
            log::echo("tm:", tm, " time: ");
            fun_time(tm);

            break;
        }
        case 'J': {
            _pos =
                _base_size + fldsiz(LULDAuctionCollarMessage, Stock) +
                fldsiz(LULDAuctionCollarMessage, AuctionCollarReferencePrice) +
                fldsiz(LULDAuctionCollarMessage, UpperAuctionCollarPrice) +
                fldsiz(LULDAuctionCollarMessage, LowerAuctionCollarPrice) +
                fldsiz(LULDAuctionCollarMessage, AuctionCollarExtension)

                ;
            _msize = fread(_buffer, _pos, 1, _fp);

            if (_msize == -1) {
                log::bug("error");
                break;
            }
            log::echo("J size:", _pos);
            tm = parse_ts(_buffer + 4);
            log::echo("tm:", tm, " time: ");
            fun_time(tm);

            break;
        }
        default: {
            log::bug("default..");
            test = 1;
            break;
        }
    }

    fseek(_fp, 2, SEEK_CUR);

} /* -----  end of function ItchMsg::message  ----- */

/*
 * ===  FUNCTION  =============================
 *
 *         Name:  ItchMsg::Process
 *  ->  void *
 *  Parameters:
 *  - size_t  arg
 *  Description:
 *
 * ============================================
 */
bool ItchMsg::Process(void* buffer, size_t size)
{
    size_t index = 0;
    uint8_t* data = (uint8_t*)buffer;

    while (index < size) {
        if (_msize == 0) {
            size_t remaining = size - index;

            // Collect message size into the cache
            if (((_cache.size() == 0) && (remaining < 3)) ||
                (_cache.size() == 1)) {
                _cache.push_back(data[index++]);
                continue;
            }

            // Read a new message size
            uint16_t message_msize;
            if (_cache.empty()) {
                // Read the message size directly from the input buffer
                index += ReadBigEndian(&data[index], message_msize);
            }
            else {
                // Read the message size from the cache
                ReadBigEndian(_cache.data(), message_msize);

                // Clear the cache
                _cache.clear();
            }
            _msize = message_msize;
        }

        // Read a new message
        if (_msize > 0) {
            size_t remaining = size - index;

            // Complete or place the message into the cache
            if (!_cache.empty()) {
                size_t tail = _msize - _cache.size();
                if (tail > remaining) tail = remaining;
                _cache.insert(_cache.end(), &data[index], &data[index + tail]);
                index += tail;
                if (_cache.size() < _msize) continue;
            }
            else if (_msize > remaining) {
                _cache.reserve(_msize);
                _cache.insert(_cache.end(), &data[index],
                              &data[index + remaining]);
                index += remaining;
                continue;
            }

            // Process the current message
            if (_cache.empty()) {
                // Process the current message size directly from the input
                // buffer
                if (!ProcessMessage(&data[index], _msize)) return false;
                index += _msize;
            }
            else {
                // Process the current message size directly from the cache
                if (!ProcessMessage(_cache.data(), _msize)) return false;

                // Clear the cache
                _cache.clear();
            }

            // Process the next message
            _msize = 0;
        }
    }

    return true;

} /* -----  end of function ItchMsg::Process  ----- */

/*
 * ===  FUNCTION  =============================
 *
 *         Name:  ItchMsg::ProcessMessage
 *  ->  void *
 *  Parameters:
 *  - size_t  arg
 *  Description:
 *
 * ============================================
 */
bool ItchMsg::ProcessMessage(void* buffer, size_t size)
{
    if (size == 0) return false;

    uint8_t* data = (uint8_t*)buffer;
    log::echo("data:", *data);
    switch (*data) {
        case 'S':
            return ProcessSystemEventMessage(data, size);
        case 'R':
            return ProcessStockDirectoryMessage(data, size);
        case 'H':
            return ProcessStockTradingActionMessage(data, size);
        case 'Y':
            return ProcessRegSHOMessage(data, size);
        case 'L':
            return ProcessMarketParticipantPositionMessage(data, size);
        case 'V':
            return ProcessMWCBDeclineMessage(data, size);
        case 'W':
            return ProcessMWCBStatusMessage(data, size);
        case 'K':
            return ProcessIPOQuotingMessage(data, size);
        case 'A':
            return ProcessAddOrderMessage(data, size);
        case 'F':
            return ProcessAddOrderMPIDMessage(data, size);
        case 'E':
            return ProcessOrderExecutedMessage(data, size);
        case 'C':
            return ProcessOrderExecutedWithPriceMessage(data, size);
        case 'X':
            return ProcessOrderCancelMessage(data, size);
        case 'D':
            return ProcessOrderDeleteMessage(data, size);
        case 'U':
            return ProcessOrderReplaceMessage(data, size);
        case 'P':
            return ProcessTradeMessage(data, size);
        case 'Q':
            return ProcessCrossTradeMessage(data, size);
        case 'B':
            return ProcessBrokenTradeMessage(data, size);
        case 'I':
            return ProcessNOIIMessage(data, size);
        case 'N':
            return ProcessRPIIMessage(data, size);
        case 'J':
            return ProcessLULDAuctionCollarMessage(data, size);
        default:
            return ProcessUnknownMessage(data, size);
    }

} /* -----  end of function ItchMsg::ProcessMessage  ----- */
bool ItchMsg::ProcessSystemEventMessage(void* buffer, size_t size)
{
    assert((size == 12) && "Invalid size of the ITCH message type 'S'");
    if (size != 12) return false;

    uint8_t* data = (uint8_t*)buffer;

    SystemEventMessage message;
    message.Type = *data++;
    data += ReadBigEndian(data, message.StockLocate);
    data += ReadBigEndian(data, message.TrackingNumber);
    data += ReadTimestamp(data, message.Timestamp);
    message.EventCode = *data++;

    return onMessage(message);
}

bool ItchMsg::ProcessStockDirectoryMessage(void* buffer, size_t size)
{
    assert((size == 39) && "Invalid size of the ITCH message type 'R'");
    if (size != 39) return false;

    uint8_t* data = (uint8_t*)buffer;

    StockDirectoryMessage message;
    message.Type = *data++;
    data += ReadBigEndian(data, message.StockLocate);
    data += ReadBigEndian(data, message.TrackingNumber);
    data += ReadTimestamp(data, message.Timestamp);
    data += ReadString(data, message.Stock);
    message.MarketCategory = *data++;
    message.FinancialStatusIndicator = *data++;
    data += ReadBigEndian(data, message.RoundLotSize);
    message.RoundLotsOnly = *data++;
    message.IssueClassification = *data++;
    data += ReadString(data, message.IssueSubType);
    message.Authenticity = *data++;
    message.ShortSaleThresholdIndicator = *data++;
    message.IPOFlag = *data++;
    message.LULDReferencePriceTier = *data++;
    message.ETPFlag = *data++;
    data += ReadBigEndian(data, message.ETPLeverageFactor);
    message.InverseIndicator = *data++;

    return onMessage(message);
}

bool ItchMsg::ProcessStockTradingActionMessage(void* buffer, size_t size)
{
    assert((size == 25) && "Invalid size of the ITCH message type 'H'");
    if (size != 25) return false;

    uint8_t* data = (uint8_t*)buffer;

    StockTradingActionMessage message;
    message.Type = *data++;
    data += ReadBigEndian(data, message.StockLocate);
    data += ReadBigEndian(data, message.TrackingNumber);
    data += ReadTimestamp(data, message.Timestamp);
    data += ReadString(data, message.Stock);
    message.TradingState = *data++;
    message.Reserved = *data++;
    message.Reason = *data++;

    return onMessage(message);
}

bool ItchMsg::ProcessRegSHOMessage(void* buffer, size_t size)
{
    assert((size == 20) && "Invalid size of the ITCH message type 'Y'");
    if (size != 20) return false;

    uint8_t* data = (uint8_t*)buffer;

    RegSHOMessage message;
    message.Type = *data++;
    data += ReadBigEndian(data, message.StockLocate);
    data += ReadBigEndian(data, message.TrackingNumber);
    data += ReadTimestamp(data, message.Timestamp);
    data += ReadString(data, message.Stock);
    message.RegSHOAction = *data++;

    return onMessage(message);
}

bool ItchMsg::ProcessMarketParticipantPositionMessage(void* buffer, size_t size)
{
    assert((size == 26) && "Invalid size of the ITCH message type 'L'");
    if (size != 26) return false;

    uint8_t* data = (uint8_t*)buffer;

    MarketParticipantPositionMessage message;
    message.Type = *data++;
    data += ReadBigEndian(data, message.StockLocate);
    data += ReadBigEndian(data, message.TrackingNumber);
    data += ReadTimestamp(data, message.Timestamp);
    data += ReadString(data, message.MPID);
    data += ReadString(data, message.Stock);
    message.PrimaryMarketMaker = *data++;
    message.MarketMakerMode = *data++;
    message.MarketParticipantState = *data++;

    return onMessage(message);
}

bool ItchMsg::ProcessMWCBDeclineMessage(void* buffer, size_t size)
{
    assert((size == 35) && "Invalid size of the ITCH message type 'V'");
    if (size != 35) return false;

    uint8_t* data = (uint8_t*)buffer;

    MWCBDeclineMessage message;
    message.Type = *data++;
    data += ReadBigEndian(data, message.StockLocate);
    data += ReadBigEndian(data, message.TrackingNumber);
    data += ReadTimestamp(data, message.Timestamp);
    data += ReadBigEndian(data, message.Level1);
    data += ReadBigEndian(data, message.Level2);
    data += ReadBigEndian(data, message.Level3);

    return onMessage(message);
}

bool ItchMsg::ProcessMWCBStatusMessage(void* buffer, size_t size)
{
    assert((size == 12) && "Invalid size of the ITCH message type 'W'");
    if (size != 12) return false;

    uint8_t* data = (uint8_t*)buffer;

    MWCBStatusMessage message;
    message.Type = *data++;
    data += ReadBigEndian(data, message.StockLocate);
    data += ReadBigEndian(data, message.TrackingNumber);
    data += ReadTimestamp(data, message.Timestamp);
    message.BreachedLevel = *data++;

    return onMessage(message);
}

bool ItchMsg::ProcessIPOQuotingMessage(void* buffer, size_t size)
{
    assert((size == 28) && "Invalid size of the ITCH message type 'W'");
    if (size != 28) return false;

    uint8_t* data = (uint8_t*)buffer;

    IPOQuotingMessage message;
    message.Type = *data++;
    data += ReadBigEndian(data, message.StockLocate);
    data += ReadBigEndian(data, message.TrackingNumber);
    data += ReadTimestamp(data, message.Timestamp);
    data += ReadString(data, message.Stock);
    data += ReadBigEndian(data, message.IPOReleaseTime);
    message.IPOReleaseQualifier = *data++;
    data += ReadBigEndian(data, message.IPOPrice);

    return onMessage(message);
}

bool ItchMsg::ProcessAddOrderMessage(void* buffer, size_t size)
{
    assert((size == 36) && "Invalid size of the ITCH message type 'A'");
    if (size != 36) return false;

    uint8_t* data = (uint8_t*)buffer;

    AddOrderMessage message;
    message.Type = *data++;
    data += ReadBigEndian(data, message.StockLocate);
    data += ReadBigEndian(data, message.TrackingNumber);
    data += ReadTimestamp(data, message.Timestamp);
    data += ReadBigEndian(data, message.OrderReferenceNumber);
    message.BuySellIndicator = *data++;
    data += ReadBigEndian(data, message.Shares);
    data += ReadString(data, message.Stock);
    data += ReadBigEndian(data, message.Price);

    return onMessage(message);
}

bool ItchMsg::ProcessAddOrderMPIDMessage(void* buffer, size_t size)
{
    assert((size == 40) && "Invalid size of the ITCH message type 'F'");
    if (size != 40) return false;

    uint8_t* data = (uint8_t*)buffer;

    AddOrderMPIDMessage message;
    message.Type = *data++;
    data += ReadBigEndian(data, message.StockLocate);
    data += ReadBigEndian(data, message.TrackingNumber);
    data += ReadTimestamp(data, message.Timestamp);
    data += ReadBigEndian(data, message.OrderReferenceNumber);
    message.BuySellIndicator = *data++;
    data += ReadBigEndian(data, message.Shares);
    data += ReadString(data, message.Stock);
    data += ReadBigEndian(data, message.Price);
    message.Attribution = *data++;

    return onMessage(message);
}

bool ItchMsg::ProcessOrderExecutedMessage(void* buffer, size_t size)
{
    assert((size == 31) && "Invalid size of the ITCH message type 'E'");
    if (size != 31) return false;

    uint8_t* data = (uint8_t*)buffer;

    OrderExecutedMessage message;
    message.Type = *data++;
    data += ReadBigEndian(data, message.StockLocate);
    data += ReadBigEndian(data, message.TrackingNumber);
    data += ReadTimestamp(data, message.Timestamp);
    data += ReadBigEndian(data, message.OrderReferenceNumber);
    data += ReadBigEndian(data, message.ExecutedShares);
    data += ReadBigEndian(data, message.MatchNumber);

    return onMessage(message);
}

bool ItchMsg::ProcessOrderExecutedWithPriceMessage(void* buffer, size_t size)
{
    assert((size == 36) && "Invalid size of the ITCH message type 'C'");
    if (size != 36) return false;

    uint8_t* data = (uint8_t*)buffer;

    OrderExecutedWithPriceMessage message;
    message.Type = *data++;
    data += ReadBigEndian(data, message.StockLocate);
    data += ReadBigEndian(data, message.TrackingNumber);
    data += ReadTimestamp(data, message.Timestamp);
    data += ReadBigEndian(data, message.OrderReferenceNumber);
    data += ReadBigEndian(data, message.ExecutedShares);
    data += ReadBigEndian(data, message.MatchNumber);
    message.Printable = *data++;
    data += ReadBigEndian(data, message.ExecutionPrice);

    return onMessage(message);
}

bool ItchMsg::ProcessOrderCancelMessage(void* buffer, size_t size)
{
    assert((size == 23) && "Invalid size of the ITCH message type 'X'");
    if (size != 23) return false;

    uint8_t* data = (uint8_t*)buffer;

    OrderCancelMessage message;
    message.Type = *data++;
    data += ReadBigEndian(data, message.StockLocate);
    data += ReadBigEndian(data, message.TrackingNumber);
    data += ReadTimestamp(data, message.Timestamp);
    data += ReadBigEndian(data, message.OrderReferenceNumber);
    data += ReadBigEndian(data, message.CanceledShares);

    return onMessage(message);
}

bool ItchMsg::ProcessOrderDeleteMessage(void* buffer, size_t size)
{
    assert((size == 19) && "Invalid size of the ITCH message type 'D'");
    if (size != 19) return false;

    uint8_t* data = (uint8_t*)buffer;

    OrderDeleteMessage message;
    message.Type = *data++;
    data += ReadBigEndian(data, message.StockLocate);
    data += ReadBigEndian(data, message.TrackingNumber);
    data += ReadTimestamp(data, message.Timestamp);
    data += ReadBigEndian(data, message.OrderReferenceNumber);

    return onMessage(message);
}

bool ItchMsg::ProcessOrderReplaceMessage(void* buffer, size_t size)
{
    assert((size == 35) && "Invalid size of the ITCH message type 'U'");
    if (size != 35) return false;

    uint8_t* data = (uint8_t*)buffer;

    OrderReplaceMessage message;
    message.Type = *data++;
    data += ReadBigEndian(data, message.StockLocate);
    data += ReadBigEndian(data, message.TrackingNumber);
    data += ReadTimestamp(data, message.Timestamp);
    data += ReadBigEndian(data, message.OriginalOrderReferenceNumber);
    data += ReadBigEndian(data, message.NewOrderReferenceNumber);
    data += ReadBigEndian(data, message.Shares);
    data += ReadBigEndian(data, message.Price);

    return onMessage(message);
}

bool ItchMsg::ProcessTradeMessage(void* buffer, size_t size)
{
    assert((size == 44) && "Invalid size of the ITCH message type 'P'");
    if (size != 44) return false;

    uint8_t* data = (uint8_t*)buffer;

    TradeMessage message;
    message.Type = *data++;
    data += ReadBigEndian(data, message.StockLocate);
    data += ReadBigEndian(data, message.TrackingNumber);
    data += ReadTimestamp(data, message.Timestamp);
    data += ReadBigEndian(data, message.OrderReferenceNumber);
    message.BuySellIndicator = *data++;
    data += ReadBigEndian(data, message.Shares);
    data += ReadString(data, message.Stock);
    data += ReadBigEndian(data, message.Price);
    data += ReadBigEndian(data, message.MatchNumber);

    return onMessage(message);
}

bool ItchMsg::ProcessCrossTradeMessage(void* buffer, size_t size)
{
    assert((size == 40) && "Invalid size of the ITCH message type 'Q'");
    if (size != 40) return false;

    uint8_t* data = (uint8_t*)buffer;

    CrossTradeMessage message;
    message.Type = *data++;
    data += ReadBigEndian(data, message.StockLocate);
    data += ReadBigEndian(data, message.TrackingNumber);
    data += ReadTimestamp(data, message.Timestamp);
    data += ReadBigEndian(data, message.Shares);
    data += ReadString(data, message.Stock);
    data += ReadBigEndian(data, message.CrossPrice);
    data += ReadBigEndian(data, message.MatchNumber);
    message.CrossType = *data++;

    return onMessage(message);
}

bool ItchMsg::ProcessBrokenTradeMessage(void* buffer, size_t size)
{
    assert((size == 19) && "Invalid size of the ITCH message type 'B'");
    if (size != 19) return false;

    uint8_t* data = (uint8_t*)buffer;

    BrokenTradeMessage message;
    message.Type = *data++;
    data += ReadBigEndian(data, message.StockLocate);
    data += ReadBigEndian(data, message.TrackingNumber);
    data += ReadTimestamp(data, message.Timestamp);
    data += ReadBigEndian(data, message.MatchNumber);

    return onMessage(message);
}

bool ItchMsg::ProcessNOIIMessage(void* buffer, size_t size)
{
    assert((size == 50) && "Invalid size of the ITCH message type 'I'");
    if (size != 50) return false;

    uint8_t* data = (uint8_t*)buffer;

    NOIIMessage message;
    message.Type = *data++;
    data += ReadBigEndian(data, message.StockLocate);
    data += ReadBigEndian(data, message.TrackingNumber);
    data += ReadTimestamp(data, message.Timestamp);
    data += ReadBigEndian(data, message.PairedShares);
    data += ReadBigEndian(data, message.ImbalanceShares);
    message.ImbalanceDirection = *data++;
    data += ReadString(data, message.Stock);
    data += ReadBigEndian(data, message.FarPrice);
    data += ReadBigEndian(data, message.NearPrice);
    data += ReadBigEndian(data, message.CurrentReferencePrice);
    message.CrossType = *data++;
    message.PriceVariationIndicator = *data++;

    return onMessage(message);
}

bool ItchMsg::ProcessRPIIMessage(void* buffer, size_t size)
{
    assert((size == 20) && "Invalid size of the ITCH message type 'N'");
    if (size != 20) return false;

    uint8_t* data = (uint8_t*)buffer;

    RPIIMessage message;
    message.Type = *data++;
    data += ReadBigEndian(data, message.StockLocate);
    data += ReadBigEndian(data, message.TrackingNumber);
    data += ReadTimestamp(data, message.Timestamp);
    data += ReadString(data, message.Stock);
    message.InterestFlag = *data++;

    return onMessage(message);
}

bool ItchMsg::ProcessLULDAuctionCollarMessage(void* buffer, size_t size)
{
    assert((size == 35) && "Invalid size of the ITCH message type 'J'");
    if (size != 35) return false;

    uint8_t* data = (uint8_t*)buffer;

    LULDAuctionCollarMessage message;
    message.Type = *data++;
    data += ReadBigEndian(data, message.StockLocate);
    data += ReadBigEndian(data, message.TrackingNumber);
    data += ReadTimestamp(data, message.Timestamp);
    data += ReadString(data, message.Stock);
    data += ReadBigEndian(data, message.AuctionCollarReferencePrice);
    data += ReadBigEndian(data, message.UpperAuctionCollarPrice);
    data += ReadBigEndian(data, message.LowerAuctionCollarPrice);
    data += ReadBigEndian(data, message.AuctionCollarExtension);

    return onMessage(message);
}

bool ItchMsg::ProcessUnknownMessage(void* buffer, size_t size)
{
    assert((size > 0) && "Invalid size of the unknown ITCH message!");
    if (size == 0) return false;

    uint8_t* data = (uint8_t*)buffer;

    UnknownMessage message;
    message.Type = *data;

    return onMessage(message);
}

template <size_t N>
inline size_t ItchMsg::ReadString(const void* buffer, char (&str)[N])
{
    std::memcpy(str, buffer, N);

    return N;
}

inline size_t ItchMsg::ReadTimestamp(const void* buffer, uint64_t& value)
{
    if (IsBigEndian()) {
        ((uint8_t*)&value)[0] = 0;
        ((uint8_t*)&value)[1] = 0;
        ((uint8_t*)&value)[2] = 0;
        ((uint8_t*)&value)[3] = 0;
        ((uint8_t*)&value)[4] = 0;
        ((uint8_t*)&value)[5] = ((const uint8_t*)buffer)[0];
        ((uint8_t*)&value)[6] = ((const uint8_t*)buffer)[1];
        ((uint8_t*)&value)[7] = ((const uint8_t*)buffer)[2];
    }
    else {
        ((uint8_t*)&value)[0] = ((const uint8_t*)buffer)[2];
        ((uint8_t*)&value)[1] = ((const uint8_t*)buffer)[1];
        ((uint8_t*)&value)[2] = ((const uint8_t*)buffer)[0];
        ((uint8_t*)&value)[3] = 0;
        ((uint8_t*)&value)[4] = 0;
        ((uint8_t*)&value)[5] = 0;
        ((uint8_t*)&value)[6] = 0;
        ((uint8_t*)&value)[7] = 0;
    }

    return 6;
}

}  // namespace e2q

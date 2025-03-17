/*
 * =====================================================================================
 *
 *       Filename:  itch50.hpp
 *
 *    Description:  itch50
 *
 *        Version:  1.0
 *        Created:  2024年03月16日 11时44分35秒
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

#ifndef ITCH50_INC
#define ITCH50_INC
#include <cmath>
#include <cstddef>
#include <cstdint>
#include <cstdio>
#include <string>
#include <vector>

// #include "OMSPack/foreign.hpp"
namespace e2q {
#define BUFF_SIZE 8192

template <unsigned nbits>
struct uint {};

template <>
struct uint<2> {
    using type = uint16_t;
};
template <>
struct uint<4> {
    using type = uint16_t;
};
template <>
struct uint<8> {
    using type = uint32_t;
};

#define fldsiz(name, field) (sizeof(((struct name*)0)->field))

#define MoveTo()

/* #define MoveTo()                 \ */
/*     do {                         \ */
/*         fseek(_fp, 2, SEEK_CUR); \ */
/*     } while (0) */

struct BaseMessage {
    char Type;
    uint16_t StockLocate;
    uint16_t TrackingNumber;
    uint64_t Timestamp;
}; /* ----------  end of struct BaseMessage  ---------- */

typedef struct BaseMessage BaseMessage;

//! System Event Message
struct SystemEventMessage : public BaseMessage {
    char EventCode;
};

inline void network_to_host(uint32_t& x)
{
    x = (x & 0x000000FF) << 24 | (x & 0x0000FF00) << 8 | (x & 0x00FF0000) >> 8 |
        (x & 0xFF000000) >> 24;
}

//! Stock Directory Message
struct StockDirectoryMessage : public BaseMessage {
    char Stock[8];
    char MarketCategory;
    char FinancialStatusIndicator;
    uint32_t RoundLotSize;
    char RoundLotsOnly;
    char IssueClassification;
    char IssueSubType[2];
    char Authenticity;
    char ShortSaleThresholdIndicator;
    char IPOFlag;
    char LULDReferencePriceTier;
    char ETPFlag;
    uint32_t ETPLeverageFactor;
    char InverseIndicator;

    template <class TOutputStream>
    friend TOutputStream& operator<<(TOutputStream& stream,
                                     const StockDirectoryMessage& message);
};

//! Stock Trading Action Message
struct StockTradingActionMessage : public BaseMessage {
    char Stock[8];
    char TradingState;
    char Reserved;
    char Reason;

    template <class TOutputStream>
    friend TOutputStream& operator<<(TOutputStream& stream,
                                     const StockTradingActionMessage& message);
};

//! Reg SHO Short Sale Price Test Restricted Indicator Message
struct RegSHOMessage : public BaseMessage {
    char Stock[8];
    char RegSHOAction;

    template <class TOutputStream>
    friend TOutputStream& operator<<(TOutputStream& stream,
                                     const RegSHOMessage& message);
};

//! Market Participant Position Message
struct MarketParticipantPositionMessage : public BaseMessage {
    char MPID[4];
    char Stock[8];
    char PrimaryMarketMaker;
    char MarketMakerMode;
    char MarketParticipantState;

    template <class TOutputStream>
    friend TOutputStream& operator<<(
        TOutputStream& stream, const MarketParticipantPositionMessage& message);
};

//! MWCB Decline Level Message
struct MWCBDeclineMessage : public BaseMessage {
    uint64_t Level1;
    uint64_t Level2;
    uint64_t Level3;

    template <class TOutputStream>
    friend TOutputStream& operator<<(TOutputStream& stream,
                                     const MWCBDeclineMessage& message);
};

//! MWCB Status Message
struct MWCBStatusMessage : public BaseMessage {
    char BreachedLevel;

    template <class TOutputStream>
    friend TOutputStream& operator<<(TOutputStream& stream,
                                     const MWCBStatusMessage& message);
};

//! IPO Quoting Period Update Message
struct IPOQuotingMessage : public BaseMessage {
    char Stock[8];
    uint32_t IPOReleaseTime;
    char IPOReleaseQualifier;
    uint32_t IPOPrice;

    template <class TOutputStream>
    friend TOutputStream& operator<<(TOutputStream& stream,
                                     const IPOQuotingMessage& message);
};

//! Add Order Message
struct AddOrderMessage : public BaseMessage {
    uint64_t OrderReferenceNumber;
    char BuySellIndicator;
    uint32_t Shares;
    char Stock[8];
    uint32_t Price;

    template <class TOutputStream>
    friend TOutputStream& operator<<(TOutputStream& stream,
                                     const AddOrderMessage& message);
};

//! Add Order with MPID Attribution Message
struct AddOrderMPIDMessage : public BaseMessage {
    uint64_t OrderReferenceNumber;
    char BuySellIndicator;
    uint32_t Shares;
    char Stock[8];
    uint32_t Price;
    char Attribution;

    template <class TOutputStream>
    friend TOutputStream& operator<<(TOutputStream& stream,
                                     const AddOrderMPIDMessage& message);
};

//! Order Executed Message
struct OrderExecutedMessage : public BaseMessage {
    uint64_t OrderReferenceNumber;
    uint32_t ExecutedShares;
    uint64_t MatchNumber;

    template <class TOutputStream>
    friend TOutputStream& operator<<(TOutputStream& stream,
                                     const OrderExecutedMessage& message);
};

//! Order Executed With Price Message
struct OrderExecutedWithPriceMessage : public BaseMessage {
    uint64_t OrderReferenceNumber;
    uint32_t ExecutedShares;
    uint64_t MatchNumber;
    char Printable;
    uint32_t ExecutionPrice;

    template <class TOutputStream>
    friend TOutputStream& operator<<(
        TOutputStream& stream, const OrderExecutedWithPriceMessage& message);
};

//! Order Cancel Message
struct OrderCancelMessage : public BaseMessage {
    uint64_t OrderReferenceNumber;
    uint32_t CanceledShares;

    template <class TOutputStream>
    friend TOutputStream& operator<<(TOutputStream& stream,
                                     const OrderCancelMessage& message);
};

//! Order Delete Message
struct OrderDeleteMessage : public BaseMessage {
    uint64_t OrderReferenceNumber;

    template <class TOutputStream>
    friend TOutputStream& operator<<(TOutputStream& stream,
                                     const OrderDeleteMessage& message);
};

//! Order Replace Message
struct OrderReplaceMessage : public BaseMessage {
    uint64_t OriginalOrderReferenceNumber;
    uint64_t NewOrderReferenceNumber;
    uint32_t Shares;
    uint32_t Price;

    template <class TOutputStream>
    friend TOutputStream& operator<<(TOutputStream& stream,
                                     const OrderReplaceMessage& message);
};

//! Trade Message
struct TradeMessage : public BaseMessage {
    uint64_t OrderReferenceNumber;
    char BuySellIndicator;
    uint32_t Shares;
    char Stock[8];
    uint32_t Price;
    uint64_t MatchNumber;

    template <class TOutputStream>
    friend TOutputStream& operator<<(TOutputStream& stream,
                                     const TradeMessage& message);
};

//! Cross Trade Message
struct CrossTradeMessage : public BaseMessage {
    uint64_t Shares;
    char Stock[8];
    uint32_t CrossPrice;
    uint64_t MatchNumber;
    char CrossType;

    template <class TOutputStream>
    friend TOutputStream& operator<<(TOutputStream& stream,
                                     const CrossTradeMessage& message);
};

//! Broken Trade Message
struct BrokenTradeMessage : public BaseMessage {
    uint64_t MatchNumber;

    template <class TOutputStream>
    friend TOutputStream& operator<<(TOutputStream& stream,
                                     const BrokenTradeMessage& message);
};

//! Net Order Imbalance Indicator (NOII) Message
struct NOIIMessage : public BaseMessage {
    uint64_t PairedShares;
    uint64_t ImbalanceShares;
    char ImbalanceDirection;
    char Stock[8];
    uint32_t FarPrice;
    uint32_t NearPrice;
    uint32_t CurrentReferencePrice;
    char CrossType;
    char PriceVariationIndicator;

    template <class TOutputStream>
    friend TOutputStream& operator<<(TOutputStream& stream,
                                     const NOIIMessage& message);
};

//! Retail Price Improvement Indicator (RPII) Message
struct RPIIMessage : public BaseMessage {
    char Stock[8];
    char InterestFlag;

    template <class TOutputStream>
    friend TOutputStream& operator<<(TOutputStream& stream,
                                     const RPIIMessage& message);
};

//! Limit Up – Limit Down (LULD) Auction Collar Message
struct LULDAuctionCollarMessage : public BaseMessage {
    char Stock[8];
    uint32_t AuctionCollarReferencePrice;
    uint32_t UpperAuctionCollarPrice;
    uint32_t LowerAuctionCollarPrice;
    uint32_t AuctionCollarExtension;

    template <class TOutputStream>
    friend TOutputStream& operator<<(TOutputStream& stream,
                                     const LULDAuctionCollarMessage& message);
};

//! Unknown message
struct UnknownMessage {
    char Type;

    template <class TOutputStream>
    friend TOutputStream& operator<<(TOutputStream& stream,
                                     const UnknownMessage& message);
};

/*
 * ================================
 *        Class:  ItchMsg
 *  Description:
 *  NASDAQ according to the ITCH 50 data protocol specified at
 * https://www.nasdaqtrader.com/content/technicalsupport/specifications/dataproducts/NQTVITCHSpecification.pdf.
 * ================================
 */
class ItchMsg {
public:
    /* =============  LIFECYCLE     =================== */
    ItchMsg(std::string& path) : _path(path) {}; /* constructor */

    /* =============  ACCESSORS     =================== */

    template <class T, std::enable_if_t<std::is_integral_v<T>, int> = 0>
    size_t ctou(void* buf, T& dst)
    {
        unsigned tsize = sizeof(T);
        //        using int_type = typename uint<sizeof(T)>::type;
        std::size_t mov = tsize << 2;

        T offset = std ::pow(2, mov) - 1;
        /* log::echo("-----"); */

        /* log::echo("type tsize:", tsize, " mov:", mov, " nT:",
         * sizeof(int_type), */
        /*           " offset:", offset); */
        if (buf == nullptr) {
            return 0;
        }
        T* tbuf = reinterpret_cast<T*>(buf);

        /* if (sizeof(int_type) < tsize) { */
        /*     int_type idst = static_cast<int_type>(tbuf & offset); */

        /*     dst = static_cast<T>((idst) << mov) | static_cast<T>((idst) >>
         * mov); */
        /* } */
        /* else { */
        T ndst = static_cast<T>((*tbuf) & offset);

        dst = static_cast<T>((ndst << mov) | (ndst >> mov));
        /* } */

        return tsize;
    }

    /* =============  MUTATORS      =================== */
    void read();

    void message();

    bool Process(void* buffer, size_t size);
    bool ProcessMessage(void* buffer, size_t size);
    /* =============  OPERATORS     =================== */

protected:
    /* =============  METHODS       =================== */
    virtual bool onMessage(const SystemEventMessage& message) { return true; }
    virtual bool onMessage(const StockDirectoryMessage& message)
    {
        return true;
    }
    virtual bool onMessage(const StockTradingActionMessage& message)
    {
        return true;
    }
    virtual bool onMessage(const RegSHOMessage& message) { return true; }
    virtual bool onMessage(const MarketParticipantPositionMessage& message)
    {
        return true;
    }
    virtual bool onMessage(const MWCBDeclineMessage& message) { return true; }
    virtual bool onMessage(const MWCBStatusMessage& message) { return true; }
    virtual bool onMessage(const IPOQuotingMessage& message) { return true; }
    virtual bool onMessage(const AddOrderMessage& message) { return true; }
    virtual bool onMessage(const AddOrderMPIDMessage& message) { return true; }
    virtual bool onMessage(const OrderExecutedMessage& message) { return true; }
    virtual bool onMessage(const OrderExecutedWithPriceMessage& message)
    {
        return true;
    }
    virtual bool onMessage(const OrderCancelMessage& message) { return true; }
    virtual bool onMessage(const OrderDeleteMessage& message) { return true; }
    virtual bool onMessage(const OrderReplaceMessage& message) { return true; }
    virtual bool onMessage(const TradeMessage& message) { return true; }
    virtual bool onMessage(const CrossTradeMessage& message) { return true; }
    virtual bool onMessage(const BrokenTradeMessage& message) { return true; }
    virtual bool onMessage(const NOIIMessage& message) { return true; }
    virtual bool onMessage(const RPIIMessage& message) { return true; }
    virtual bool onMessage(const LULDAuctionCollarMessage& message)
    {
        return true;
    }
    virtual bool onMessage(const UnknownMessage& message) { return true; }

    /* =============  DATA MEMBERS  =================== */

private:
    /* =============  METHODS       =================== */

    bool ProcessSystemEventMessage(void* buffer, size_t size);
    bool ProcessStockDirectoryMessage(void* buffer, size_t size);
    bool ProcessStockTradingActionMessage(void* buffer, size_t size);
    bool ProcessRegSHOMessage(void* buffer, size_t size);
    bool ProcessMarketParticipantPositionMessage(void* buffer, size_t size);
    bool ProcessMWCBDeclineMessage(void* buffer, size_t size);
    bool ProcessMWCBStatusMessage(void* buffer, size_t size);
    bool ProcessIPOQuotingMessage(void* buffer, size_t size);
    bool ProcessAddOrderMessage(void* buffer, size_t size);
    bool ProcessAddOrderMPIDMessage(void* buffer, size_t size);
    bool ProcessOrderExecutedMessage(void* buffer, size_t size);
    bool ProcessOrderExecutedWithPriceMessage(void* buffer, size_t size);
    bool ProcessOrderCancelMessage(void* buffer, size_t size);
    bool ProcessOrderDeleteMessage(void* buffer, size_t size);
    bool ProcessOrderReplaceMessage(void* buffer, size_t size);
    bool ProcessTradeMessage(void* buffer, size_t size);
    bool ProcessCrossTradeMessage(void* buffer, size_t size);
    bool ProcessBrokenTradeMessage(void* buffer, size_t size);
    bool ProcessNOIIMessage(void* buffer, size_t size);
    bool ProcessRPIIMessage(void* buffer, size_t size);
    bool ProcessLULDAuctionCollarMessage(void* buffer, size_t size);
    bool ProcessUnknownMessage(void* buffer, size_t size);

    /* =============  DATA MEMBERS  =================== */
    std::size_t _msize;
    char _buffer[BUFF_SIZE];
    std::string _path;
    std::uint8_t _key[1];
    std::FILE* _fp;
    std::size_t _pos = 0;  // init
    std::size_t _base_size = 0;

    std::size_t test = 0;

    std::vector<uint8_t> _cache;
    template <size_t N>
    size_t ReadString(const void* buffer, char (&str)[N]);
    size_t ReadTimestamp(const void* buffer, uint64_t& value);
}; /* -----  end of class ItchMsg  ----- */

}  // namespace e2q
#endif /* ----- #ifndef ITCH50_INC  ----- */

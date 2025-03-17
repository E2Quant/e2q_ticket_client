#include "quote_spi.h"

#include <cstdint>
#include <iostream>
using namespace std;

MyQuoteSpi::MyQuoteSpi() {}

MyQuoteSpi::~MyQuoteSpi() {}

void MyQuoteSpi::OnDisconnected(int reason)
{
    cout << "--->>> " << "OnDisconnected quote" << endl;
    cout << "--->>> Reason = " << reason << endl;
    // ���ߺ󣬿�����������
    // �������ӳɹ�����Ҫ���������������������
}

void MyQuoteSpi::OnSubMarketData(XTPST *ticker, XTPRI *error_info, bool is_last)
{
    cout << "OnRspSubMarketData ticker:" << std::string(ticker->ticker) << endl;
}

void MyQuoteSpi::OnUnSubMarketData(XTPST *ticker, XTPRI *error_info,
                                   bool is_last)
{
    cout << "OnRspUnSubMarketData -----------" << endl;
}

void MyQuoteSpi::OnDepthMarketData(XTPMD *market_data, int64_t bid1_qty[],
                                   int32_t bid1_count, int32_t max_bid1_count,
                                   int64_t ask1_qty[], int32_t ask1_count,
                                   int32_t max_ask1_count)
{
    std::cout << " depth " << std::endl;
    if (bid1_count > 0) {
        for (int32_t m = 0; m < bid1_count; m++) {
            std::cout << bid1_qty[m] << " .";
        }
        std::cout << " \n";
    }

    if (market_data != nullptr) {
        std::cout << "open price:" << market_data->open_price
                  << " last_price:" << market_data->last_price
                  << " close price:" << market_data->close_price
                  << " date_time:" << market_data->data_time << std::endl;
    }
}

void MyQuoteSpi::OnSubOrderBook(XTPST *ticker, XTPRI *error_info, bool is_last)
{
    std::cout << "suborder book" << std::endl;
}

void MyQuoteSpi::OnUnSubOrderBook(XTPST *ticker, XTPRI *error_info,
                                  bool is_last)
{
    std::cout << "unsuborder book" << std::endl;
}

void MyQuoteSpi::OnSubTickByTick(XTPST *ticker, XTPRI *error_info, bool is_last)
{
    std::cout << "sub tick by tick" << std::endl;
}

void MyQuoteSpi::OnUnSubTickByTick(XTPST *ticker, XTPRI *error_info,
                                   bool is_last)
{
    std::cout << "un sub tick by tick" << std::endl;
}

void MyQuoteSpi::OnOrderBook(XTPOB *order_book)
{
    std::cout << "on order book" << std::endl;
}

void MyQuoteSpi::OnTickByTick(XTPTBT *tbt_data)
{
    std::cout << "on tick by tick" << std::endl;
}

void MyQuoteSpi::OnQueryAllTickers(XTPQSI *ticker_info, XTPRI *error_info,
                                   bool is_last)
{
    cout << "OnQueryAllTickers -----------" << endl;
    if (IsErrorRspInfo(error_info)) {
        // �д�����
        return;
    }
}

void MyQuoteSpi::OnQueryTickersPriceInfo(XTPTPI *ticker_info, XTPRI *error_info,
                                         bool is_last)
{
    std::cout << "query ticker price" << std::endl;
}

void MyQuoteSpi::OnSubscribeAllMarketData(XTP_EXCHANGE_TYPE exchange_id,
                                          XTPRI *error_info)
{
    std::cout << "sub sub all market data" << std::endl;
}

void MyQuoteSpi::OnUnSubscribeAllMarketData(XTP_EXCHANGE_TYPE exchange_id,
                                            XTPRI *error_info)
{
    std::cout << "un sub sub all market data" << std::endl;
}

void MyQuoteSpi::OnSubscribeAllOrderBook(XTP_EXCHANGE_TYPE exchange_id,
                                         XTPRI *error_info)
{
    std::cout << "sub all order book" << std::endl;
}

void MyQuoteSpi::OnUnSubscribeAllOrderBook(XTP_EXCHANGE_TYPE exchange_id,
                                           XTPRI *error_info)
{
    std::cout << "un sub all order book" << std::endl;
}

void MyQuoteSpi::OnSubscribeAllTickByTick(XTP_EXCHANGE_TYPE exchange_id,
                                          XTPRI *error_info)
{
    std::cout << "sub all tick by tick" << std::endl;
}

void MyQuoteSpi::OnUnSubscribeAllTickByTick(XTP_EXCHANGE_TYPE exchange_id,
                                            XTPRI *error_info)
{
    std::cout << "un sub all tick by tick" << std::endl;
}

void MyQuoteSpi::OnSubscribeAllOptionMarketData(XTP_EXCHANGE_TYPE exchange_id,
                                                XTPRI *error_info)
{
    std::cout << "sub all option market data" << std::endl;
}

void MyQuoteSpi::OnUnSubscribeAllOptionMarketData(XTP_EXCHANGE_TYPE exchange_id,
                                                  XTPRI *error_info)
{
    std::cout << "un sub all option market data" << std::endl;
}

void MyQuoteSpi::OnSubscribeAllOptionOrderBook(XTP_EXCHANGE_TYPE exchange_id,
                                               XTPRI *error_info)
{
    std::cout << "sub all option order book" << std::endl;
}

void MyQuoteSpi::OnUnSubscribeAllOptionOrderBook(XTP_EXCHANGE_TYPE exchange_id,
                                                 XTPRI *error_info)
{
    std::cout << "un sub all option order book" << std::endl;
}

void MyQuoteSpi::OnSubscribeAllOptionTickByTick(XTP_EXCHANGE_TYPE exchange_id,
                                                XTPRI *error_info)
{
    std::cout << "sub all option tick by tick" << std::endl;
}

void MyQuoteSpi::OnUnSubscribeAllOptionTickByTick(XTP_EXCHANGE_TYPE exchange_id,
                                                  XTPRI *error_info)
{
    std::cout << "un sub all option tick by tick" << std::endl;
}

void MyQuoteSpi::OnQueryAllTickersFullInfo(XTPQFI *ticker_info,
                                           XTPRI *error_info, bool is_last)
{
    if (IsErrorRspInfo(error_info)) {
        // �д�����
        return;
    }
}

void MyQuoteSpi::OnRebuildQuoteServerDisconnected(int reason)
{
    std::cout << "OnRebuildQuoteServerDisconnected reason:" << reason
              << std::endl;
    // �벻Ҫ��ʱ�䱣����ز������������ӣ�������Ҫʱ���ӣ�������������߼�������¼����
}

void MyQuoteSpi::OnRequestRebuildQuote(XTPQuoteRebuildResultRsp *rebuild_result)
{
    // ����Ļز������Ƿ��Ѿ���ȫ�ز��꣬���û����ȫ�Ļ��������ٴη�������
    switch (rebuild_result->result_code) {
        case XTP_REBUILD_RET_COMPLETE: {
            // ��ʱ�ز�������ȫ
            std::cout << "ret complete" << std::endl;
            break;
        }
        case XTP_REBUILD_RET_PARTLY: {
            // ��ʱ�ز����ݲ���������Ҫ�ٴη�������
            std::cout << "ret partly" << std::endl;
            break;
        }
        case XTP_REBUILD_RET_NO_DATA: {
            // ��ʱ������Ҳû�лز����ݣ���ʱ���ܷ�����Ҳȱ�����ݣ���Ҫ�ȴ�һ��������󿴿�
            std::cout << "ret partly" << std::endl;
            break;
        }
        case XTP_REBUILD_RET_PARAM_ERR: {
            // ��ʱ����Ļز����ݲ�ѯ����������Ҫ����ѯ�����Ƿ���ȷ
            std::cout << "ret param err" << std::endl;
            break;
        }
        case XTP_REBUILD_RET_FREQUENTLY: {
            // ��ʱ�ز�����������Ϊ����̫Ƶ����������������Ƶ���뽵������Ƶ�ʻ��ߵȴ�һ���������
            std::cout << "ret frequently" << std::endl;
            break;
        }
        default:
            break;
    }
}

void MyQuoteSpi::OnRebuildTickByTick(XTPTBT *tbt_data)
{
    std::cout << "rebuild tick by tick" << std::endl;
}

void MyQuoteSpi::OnRebuildMarketData(XTPMD *md_data)
{
    std::cout << "rebuild market data" << std::endl;
}

bool MyQuoteSpi::IsErrorRspInfo(XTPRI *pRspInfo)
{
    // ���ErrorID != 0, ˵���յ��˴������Ӧ
    bool bResult = ((pRspInfo) && (pRspInfo->error_id != 0));
    if (bResult)
        cout << "--->>> ErrorID=" << pRspInfo->error_id
             << ", ErrorMsg=" << pRspInfo->error_msg << endl;
    return bResult;
}


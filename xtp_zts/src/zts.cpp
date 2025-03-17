/*
 * =====================================================================================
 *
 *       Filename:  zts.cpp
 *
 *    Description:  zts
 *
 *        Version:  1.0
 *        Created:  2025/01/23 17时31分47秒
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

#include <stdlib.h>
#include <sys/wait.h>

#include <cstdint>
#include <cstdio>
#include <cstdlib>
#include <iostream>
#include <string>

#ifdef _WIN32
#include <windows.h>
#else
#include <unistd.h>
#endif  // _WIN32

#include "FeedPack/QuoteEvent.hpp"
#include "FileUtils.h"
#include "kafka/protocol/nbo.hpp"
#include "kafka/protocol/proto.hpp"
/*
 * ===  FUNCTION  =============================
 *
 *         Name:  zts_server
 *  ->  void *
 *  Parameters:
 *  - size_t  arg
 *  Description:
 *
 * ============================================
 */
void zts_server(int argc, char* argv[])
{
    int h;
    char* c = nullptr;
    char* s = nullptr;

    FileUtils* fileUtils = NULL;

    std::string help =
        "%s -c config.json \n \
                Usage: \n \
                -c which loading config.json \n \
                -p which loading db properties \n \
                -D debug zts \n \
                -d daemon run \n";

    if (argc < 2) {
        std::cout << help << std::endl;
        exit(-1);
    }

    while ((h = getopt(argc, argv, "dDc:p:")) != -1) {
        switch (h) {
            case 'd':
                // deamon
                break;
            case 'D':
                // Debug
                break;
            case 'c':
                c = optarg;
                if (c != nullptr) {
                    printf("config: %s\n", c);

                    fileUtils = new FileUtils();
                    if (!fileUtils->init(c)) {
                        std::cout << "The config.json file parse error."
                                  << std::endl;
#ifdef _WIN32
                        system("pause");
#endif

                        exit(-1);
                    }
                }
                break;
            case 'p':
                s = optarg;
                if (s != nullptr) {
                    printf("db properties: %s\n", s);
                }
                break;
            default:
                printf("%s --help\n", argv[0]);
                exit(-1);

        } /* -----  end switch  ----- */
    }

    e2q::QuoteEvent qe(fileUtils);
    qe.run();
    if (fileUtils == nullptr) {
        exit(-1);
    }

    if (fileUtils != nullptr) {
        delete fileUtils;
        fileUtils = NULL;
    }
} /* -----  end of function zts_server  ----- */

/*
 * ===  FUNCTION  =============================
 *
 *         Name:  zts_proc
 *  ->  void *
 *  Parameters:
 *  - size_t  arg
 *  Description:
 *
 * ============================================
 */
void zts_proc()
{
    using namespace e2q;
    e2q::SystemInitMessage sim;
    std::size_t mlen = 1;
    std::size_t stock_len = fldsiz(SystemInitMessage, Stock);
    mlen += stock_len;
    mlen += fldsiz(SystemInitMessage, CfiCode);
    mlen += fldsiz(SystemInitMessage, Itype);
    mlen += fldsiz(SystemInitMessage, OfferTime);

    sim.MsgType = e2l_pro_t::INIT;
    stock_len--;
    memcpy(&sim.Stock, "sh000002", stock_len);

    sim.CfiCode = 179593;
    sim.Itype = 't';
    sim.OfferTime = std::uint32_t(0.5 * 10000.0);
    sim.Aligned = aligned_t::UNDER;

    char* ptr = (char*)calloc(mlen, sizeof(char*));
    std::size_t idx = 0;
    idx += serialize_uint_t(ptr + idx, sim.MsgType);

    memcpy((ptr + idx), sim.Stock, stock_len);

    idx += stock_len;

    idx += serialize_uint_t((ptr + idx), sim.CfiCode);

    *(ptr + idx) = sim.Itype;
    idx++;
    idx += serialize_uint_t((ptr + idx), sim.CfiCode);
    *(ptr + idx) = sim.Aligned;

    printf("%s\n", ptr);

} /* -----  end of function zts_proc  ----- */

/*
 * ===  FUNCTION  =============================
 *         Name:  main
 *  Description:
 * ============================================
 */
int main(int argc, char* argv[])
{
    // zts_proc();
    zts_server(argc, argv);
    return EXIT_SUCCESS;
} /* ----------  end of function main  ---------- */

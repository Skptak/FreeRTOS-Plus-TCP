/*
 * FreeRTOS+TCP <DEVELOPMENT BRANCH>
 * Copyright (C) 2022 Amazon.com, Inc. or its affiliates.  All Rights Reserved.
 *
 * SPDX-License-Identifier: MIT
 *
 * Permission is hereby granted, free of charge, to any person obtaining a copy
 * of this software and associated documentation files (the "Software"), to deal
 * in the Software without restriction, including without limitation the rights
 * to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
 * copies of the Software, and to permit persons to whom the Software is
 * furnished to do so, subject to the following conditions:
 *
 * The above copyright notice and this permission notice shall be included in
 * all copies or substantial portions of the Software.
 *
 * THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
 * IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
 * FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
 * AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
 * LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
 * OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE
 * SOFTWARE.
 *
 * http://aws.amazon.com/freertos
 * http://www.FreeRTOS.org
 */

/* Include Unity header */
#include "unity.h"

/* Include standard libraries */
#include <stdlib.h>
#include <string.h>
#include <stdint.h>

#include "mock_task.h"
#include "mock_list.h"

#include "FreeRTOSIPConfig.h"

#include "FreeRTOS_Sockets.h"
#include "FreeRTOS_IP_Private.h"

#include "catch_assert.h"

/* ============================== Test Cases ============================== */

/*
 * @brief Binding successful.
 */
void test_vSocketBind_TCP( void )
{
    BaseType_t xReturn;
    FreeRTOS_Socket_t xSocket;
    struct freertos_sockaddr xBindAddress;
    size_t uxAddressLength;
    BaseType_t xInternal = pdFALSE;
    NetworkEndPoint_t xEndPoint = { 0 };

    memset( &xBindAddress, 0xFC, sizeof( xBindAddress ) );
    memset( &xSocket, 0, sizeof( xSocket ) );

    xSocket.ucProtocol = ( uint8_t ) FREERTOS_IPPROTO_TCP;

    catch_assert( vSocketBind( &xSocket, NULL, uxAddressLength, xInternal ) );
}

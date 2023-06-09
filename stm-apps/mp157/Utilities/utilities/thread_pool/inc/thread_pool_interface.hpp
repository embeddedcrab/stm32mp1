/*********************************************************************************************************************
 * @file     
 * @brief    
 * @version  1.0.0
 * @date	 03/08/2023
 *
 * @cond
 *********************************************************************************************************************
 * Copyright (c) 2023, EmbeddedCrab (Hemant Sharma) - All Rights Reserved
 * All rights reserved.
 *
 * Redistribution and use in source and binary forms, with or without modification,are permitted provided that the
 * following conditions are met:
 *
 * Redistributions of source code must retain the above copyright notice, this list of conditions and the following
 * disclaimer.
 *
 * Redistributions in binary form must reproduce the above copyright notice, this list of conditions and the following
 * disclaimer in the documentation and/or other materials provided with the distribution.
 *
 * Neither the name of the copyright holders nor the names of its contributors may be used to endorse or promote
 * products derived from this software without specific prior written permission.
 *
 * THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS "AS IS" AND ANY EXPRESS OR IMPLIED WARRANTIES,
 * INCLUDING, BUT NOT LIMITED TO, THE IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE
 * DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT HOLDER OR CONTRIBUTORS BE LIABLE  FOR ANY DIRECT, INDIRECT, INCIDENTAL,
 * SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR
 * SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY,
 * WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE
 * OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
 *********************************************************************************************************************
 *
 * *************************** Change history ********************************
 *
 * @endcond
 */
/******************************************************************************
* Notes:
*
* Change History
* --------------
*
*******************************************************************************/

/** @file:	
 *  @brief:	This file contains.
 */
#ifndef _THREAD_POOL_INTERFACE_HPP_
#define _THREAD_POOL_INTERFACE_HPP_


/******************************************************************************
* Includes
******************************************************************************/
#include <cstdint>

#include <thread>
#include <vector>
#include <deque>
#include <functional>
#include <atomic>
#include <mutex>
#include <condition_variable>

#include "pmr_headers.hpp"



/******************************************************************************
* Configuration Constants
******************************************************************************/


/******************************************************************************
* Class Declarations
******************************************************************************/

namespace utils{


/**
 * Implementation of Thread Pool Interface
 */
class ThreadPoolI
{
    public:
        /**
         * Destructor of ThreadPoolI
         *
        */
        virtual ~ThreadPoolI() = default;

        virtual void init() noexcept = 0;
        virtual void destroy() noexcept = 0;

    private:
        virtual void execute() noexcept = 0;

    protected:
};


}   // namespace utils

#endif  // thread_pool_interface.hpp

/********************************** End of File *******************************/
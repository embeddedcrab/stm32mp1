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


/******************************************************************************
* Includes
******************************************************************************/
#include "semaphore.hpp"


/******************************************************************************
* Constant Declarations
******************************************************************************/


/******************************************************************************
* Class Function Definitions
******************************************************************************/

namespace utils
{


Semaphore::~Semaphore()
{
  std::cout << __FUNCTION__ << std::endl;
  // Close Semaphore
  if( !semName_.empty() )
  {
    std::cout << "Named Semaphore closed" << std::endl;
    // Named Semaphore
    static_cast<void>(sem_close( sem_ ));

    // Check flags, if creator of semaphore then destroy it also
    if( static_cast<int32_t>(flags_) & 0x40 ){
      static_cast<void>(sem_destroy( sem_ ));
      std::cout << "Named Semaphore Creator destructed" << std::endl;
    } else{
      // Nothing to be done
    }
  } else{
    std::cout << "UnNamed Semaphore destructed" << std::endl;
    // UnNamed Semaphore
    static_cast<void>(sem_destroy( sem_ ));
  }

  std::cout << "Semaphore destructed Finished" << std::endl;
}


} // namespace utils

/********************************** End of File *******************************/
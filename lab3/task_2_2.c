/*
 * Copyright (c) 2018, Swiss Federal Institute of Technology (ETH Zurich).
 * All rights reserved.
 *
 * Redistribution and use in source and binary forms, with or without
 * modification, are permitted provided that the following conditions
 * are met:
 * 1. Redistributions of source code must retain the above copyright
 *    notice, this list of conditions and the following disclaimer.
 * 2. Redistributions in binary form must reproduce the above copyright
 *    notice, this list of conditions and the following disclaimer in the
 *    documentation and/or other materials provided with the distribution.
 * 3. Neither the name of the copyright holder nor the names of its
 *    contributors may be used to endorse or promote products derived
 *    from this software without specific prior written permission.
 *
 * THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS
 * ``AS IS'' AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT
 * LIMITED TO, THE IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS
 * FOR A PARTICULAR PURPOSE ARE DISCLAIMED.  IN NO EVENT SHALL THE
 * COPYRIGHT HOLDER OR CONTRIBUTORS BE LIABLE FOR ANY DIRECT, INDIRECT,
 * INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES
 * (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR
 * SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)
 * HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT,
 * STRICT LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE)
 * ARISING IN ANY WAY OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED
 * OF THE POSSIBILITY OF SUCH DAMAGE.
 *
 * Author:  Philipp Miedl
 */

#include <msp.h>                              // Platform specific header (HW definitions)
#include <stdint.h>                           // Standard Integer - data type definitions
#include <stdio.h>                            // Standard In-/Output definitions/functions

#include "ESLab3driverLib/driverlib.h"
#include "lab3.h"                             // Lab specific defines/declarations

void task_2_2(void)
{
  WDT_A->CTL = WDT_A_CTL_PW | WDT_A_CTL_HOLD;       // Stopping the Watchdog Timer

  uint32_t count = 0;                               // Simple counter variable
  GPIO_setAsOutputPin(GPIO_PORT_P1, GPIO_PIN0);     // LED1
  GPIO_setAsOutputPin(GPIO_PORT_P2, GPIO_PIN0 | GPIO_PIN1 | GPIO_PIN2);  // LED2

  // set them to high and low for alternating toggle in pull up pull down fashion
  GPIO_setOutputHighOnPin(GPIO_PORT_P2, GPIO_PIN0 | GPIO_PIN1 | GPIO_PIN2); //LED1
  GPIO_setOutputLowOnPin(GPIO_PORT_P1, GPIO_PIN0);  //LED2

  // set the switches as input
  GPIO_setAsInputPinWithPullUpResistor(GPIO_PORT_P1, GPIO_PIN1 | GPIO_PIN4);

  while(1)
  {
      // toggle the LEDS
    GPIO_toggleOutputOnPin(GPIO_PORT_P1, GPIO_PIN0);
    GPIO_toggleOutputOnPin(GPIO_PORT_P2, GPIO_PIN0);
    // ---------------------------------------------------------------------------------- //
    //                                    Placeholder 1                                   //
    if(GPIO_getInputPinValue(GPIO_PORT_P1, GPIO_PIN1) == ((uint8_t)0x00)){
        GPIO_setOutputHighOnPin(GPIO_PORT_P2, GPIO_PIN1);
    }
    else{
        GPIO_setOutputLowOnPin(GPIO_PORT_P2, GPIO_PIN1);
    }
    if(GPIO_getInputPinValue(GPIO_PORT_P1, GPIO_PIN4) == ((uint8_t)0x00)){
            GPIO_setOutputHighOnPin(GPIO_PORT_P2, GPIO_PIN2);
        }
        else{
            GPIO_setOutputLowOnPin(GPIO_PORT_P2, GPIO_PIN2);
        }
    // ---------------------------------------------------------------------------------- //
    for(count = 0; count < g_waitcycles; count++)   // Busy Loop for Delay
    {
      // ---------------------------------------------------------------------------------//
      //                                  Placeholder 2                                   //
      // ---------------------------------------------------------------------------------//
    }
  }
}

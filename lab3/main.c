/*
 *
 */

#include <ESLab3driverLib/driverlib.h>     // TI Platform library (subset)
#include <msp.h>                           // Platform specific header (HW definitions)
#include <stdint.h>                        // Standard Integer Library - datatype definitions
#include <stdio.h>                         // Standard In-/Output definitions/functions

#include "lab3.h"                          // Lab Header file for lab specific defines/declarations

// Global variable defining the number of cycles of the busy loop
uint32_t g_waitcycles = WAIT_CYCLES * WAIT_INIT_MULTI;

/**
 * @brief Embedded Systems (ES) Lab1
 *
 * Base scaffold for the Lab1 in Embedded Systems (ES). The goal of this
 * Lab is that the students get to know the platform MSP432P401R LaunchPad
 * Development Kit. This lab splits into following parts
 * Task 1.1: Flashing an existing application.
 * Task 1.2: Using library functions instead of hard-coded register access
 * Task 1.3: Adding a blinking LED
 * Task 1.4: GPIO Input Polling
 * Task 1.5: Simple UART output
 */
void main(void)
{
  //task_1_1();
  //task_1_2();
  //task_1_3();
  //task_2_2();
    task_2_3();
}

/*
 *
 */

#include "lab2.h"                               // Lab specific defines/declarations

#define LED_RED         (0x01)
#define RGB_RED         (0x02)
#define RGB_GREEN       (0x04)
#define RGB_BLUE        (0x08)

void task_5(void)
{
  // Declare a delay counter
  volatile uint32_t i;

  // Define a toggling counter
  uint32_t counter = 0;

  /*
   * Definition of activeLED
   *
   * activeLED : (MSB)  _____  _____  _____  _____    ________  _________  _______  _______  (LSB)
   *                    **     unused bits      **    RGB_BLUE  RGB_GREEN  RGB_RED  LED_RED
   *
   * Set the bits in activeLED to toggle the corresponding LEDs
   */

//
// TODO: Change the definition of activeLED
//
  uint8_t activeLED = 0b0010;

  while(1)
  {
    //
    // TODO: For Task 5.2 (set value for activeLED)
    //
    activeLED = 0b0010; // RGB_LED
    activeLED = (activeLED<<(counter%3)) + 1; // shift activeLED by mod value, add 1

    // Toggle an LED
    toggle(activeLED);

    // Delay of ~333ms
    for (i = 0; i < 100000; i++);

    // Toggle an LED
    toggle(activeLED);

    // Delay of ~333ms
    for (i = 0; i < 100000; i++);

    // Print counter value and increment it
    uart_println("counter = %u",counter);
    counter += 1;
  }
}

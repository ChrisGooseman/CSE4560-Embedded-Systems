/*
 *
 */

#include <lab4.h>                       // Lab specific defines/declarations

/* Application defines  */
#define PWM_UPDATE_MAX            499
#define PWM_MAX                   127
#define COMPARE_VAL_INC_STEP        1

/* Port mapper configuration register */
const uint8_t port_mapping[] =
{
  PMAP_TA1CCR1A, PMAP_NONE, PMAP_NONE, PMAP_NONE, PMAP_NONE, PMAP_NONE, PMAP_NONE, PMAP_NONE
};

void task2(void)
{
  /* Timer_A0 up mode configuration parameters */
  const Timer_A_UpModeConfig upConfigA0 =
  {
    TIMER_A_CLOCKSOURCE_SMCLK,     // SMCLK clock source (3MHz)
    TIMER_A_CLOCKSOURCE_DIVIDER_64,     // SMCLK/??
    TIMER_A0,   // Value in CCR0; NOTE: limited to 16 bit!
    TIMER_A_TAIE_INTERRUPT_DISABLE,     // Disable timer roll-over interrupt
    TIMER_A_CCIE_CCR0_INTERRUPT_ENABLE,     // Enable CCR0 interrupt
    TIMER_A_DO_CLEAR      // Clear value in the timer counter register
  };

  //// Placeholder 1 /////////////////////////////////////////////////////////
  /* Configuring P1.0 (LED1) as output */
  GPIO_setAsOutputPin ( GPIO_PORT_P1 , GPIO_PIN0 );
  GPIO_setOutputLowOnPin ( GPIO_PORT_P1 , GPIO_PIN0 ) ;
  ////////////////////////////////////////////////////////////////////////////

  //// Placeholder 2 /////////////////////////////////////////////////////////
  /* Configuring Timer_A0 for Up mode */
  // Timer_A_configureUpMode(_TODO_, _TODO_);
  Timer_A_configureUpMode ( TIMER_A0_BASE , &upConfigA0);
  ////////////////////////////////////////////////////////////////////////////

  //// Placeholder 3 /////////////////////////////////////////////////////////
  /* Timer_A CCR0 interrupt is enabled by the upConfigA0 struct,
     Timer_A_enableCaptureCompareInterrupt() is not necessary! */
  /* Enable interrupt source */

  /* Clear interrupt */
 // Timer_A_clearCaptureCompareInterrupt ( TIMER_A0_BASE, TIMER_A_CAPTURECOMPARE_REGISTER_0 );
  //Interrupt_enableInterrupt ( INT_TA0_0 );
  // Timer_A_clearCaptureCompareInterrupt(_TODO_,
  //                                      _TODO_);
  /* Enable interrupts globally */
  Interrupt_enableMaster () ;
  /* Start the Timer_A0 */
  // Timer_A_startCounter(_TODO_, _TODO_);
  Timer_A_startCounter ( TIMER_A0_BASE , TIMER_A_UP_MODE );
  ////////////////////////////////////////////////////////////////////////////

  /* Remapping TA1CCR1 output pin to P2.0 (red LED of LED2) */
  PMAP_configurePorts((const uint8_t *) port_mapping,
                      PMAP_P2MAP,
                      1,
                      PMAP_DISABLE_RECONFIGURATION);

  /* Set pin P2.0 as output pin */
  GPIO_setAsPeripheralModuleFunctionOutputPin(GPIO_PORT_P2,
                                              GPIO_PIN0,
                                              GPIO_PRIMARY_MODULE_FUNCTION);

  /* Timer_A1 up mode configuration parameters */
  const Timer_A_UpModeConfig upConfigA1 =
  {
    // _TODO_,     // SMCLK clock source
    // _TODO_,     // SMCLK/1 = 3MHz
    // _TODO_,     // Value in CCR0; NOTE: limited to 16 bit!
    // _TODO_,     // Disable Timer interrupt
    // _TODO_,     // Disable CCR0 interrupt
    // _TODO_      // Clear value
  };

  /* Timer_A1 compare configuration parameters */
  Timer_A_CompareModeConfig compareConfigA1 =
  {
//    TIMER_A_CAPTURECOMPARE_REGISTER_1,     // Use CCR1 as compare register
//    TIMER_A_CAPTURECOMPARE_INTERRUPT_DISABLE,     // Disable CCR interrupt
//    TIMER_A_OUTPUTMODE_TOGGLE_RESET,     // Toggle-reset output mode
//    125      // Compare value (CCR1)Timer_A_clearInterruptFlag
  };

  //// Placeholder 4 /////////////////////////////////////////////////////////
  /* Configure the compare functionality of Timer_A1 */
  // Timer_A_initCompare(_TODO_, _TODO_);
  /* Configure Timer_A1 for Up Mode */
  // Timer_A_configureUpMode(_TODO_, _TODO_);
  /* Start counter of Timer_A1 */
  // Timer_A_startCounter(_TODO_, _TODO_);
  ////////////////////////////////////////////////////////////////////////////

  /* Sleeping when not in use */
  while (1)
  {
    PCM_gotoLPM3();
  }
}

void TA0_0_IRQHandler(void)
{
  //// Placeholder 5 /////////////////////////////////////////////////////////
  /* Toggle LED1 */
    GPIO_toggleOutputOnPin(GPIO_PORT_P1, GPIO_PIN0);
  ////////////////////////////////////////////////////////////////////////////

  /* Definitions for Task 2.3 */
  static int16_t pwmCompareVal = PWM_MAX;     // Current duty cycle value
  static bool goUp = false;                   // Flag to indicate whether compare
                                              // value is currently increased or decreased

  //// Placeholder 6 /////////////////////////////////////////////////////////
  /* Update compare value variable */
  ////////////////////////////////////////////////////////////////////////////

  //// Placeholder 7 /////////////////////////////////////////////////////////
  /* Invert the direction of increase/decrease of the duty cycle */
  ////////////////////////////////////////////////////////////////////////////

  //// Placeholder 8 /////////////////////////////////////////////////////////
  /* Update the compare value of Timer A1 (linear increase/decrease) */
  uint16_t pwmCompareValCurr = pwmCompareVal;
  // Timer_A_setCompareValue(_TODO_,
                          // _TODO_,
                          // _TODO_);
  ////////////////////////////////////////////////////////////////////////////

  //// Placeholder 9 ////////////////////////////////////////////////////////
  /* Clear interrupt of timer A0 */
  // Timer_A_clearCaptureCompareInterrupt(_TODO_,
  //                                      _TODO_);
  Timer_A_clearCaptureCompareInterrupt(TIMER_A0_BASE, TIMER_A_CAPTURECOMPARE_REGISTER_0);
  ////////////////////////////////////////////////////////////////////////////
}

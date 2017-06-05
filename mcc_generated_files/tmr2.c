/**
  Section: Included Files
*/

#include <xc.h>
#include "tmr2.h"
//#include "MotorDriver.h"

/////////////////  Section: Global Variables Definitions
volatile unsigned char Timer2Ticked;
/////////////////////////////////////////////////////////
void (*TMR2_InterruptHandler)(void);

/**
  Section: TMR2 APIs
*/

void TMR2_Initialize(void)
{
    // Set TMR2 to the options selected in the User Interface

    // T2CKPS 1:16; T2OUTPS 1:1; TMR2ON off; 
    T2CON = 0x02;

    // PR2 18; 
    PR2 = 0x12;

    // TMR2 0; 
    TMR2 = 0x00;

    // Clearing IF flag before enabling the interrupt.
    PIR1bits.TMR2IF = 0;

    // Enabling TMR2 interrupt.
    PIE1bits.TMR2IE = 1;

    // Set Default Interrupt Handler
    TMR2_SetInterruptHandler(TMR2_DefaultInterruptHandler);

    // Start TMR2
    TMR2_StartTimer();
}

void TMR2_StartTimer(void)
{
    // Start the Timer by writing to TMRxON bit
    T2CONbits.TMR2ON = 1;
}

void TMR2_StopTimer(void)
{
    // Stop the Timer by writing to TMRxON bit
    T2CONbits.TMR2ON = 0;
}

uint8_t TMR2_ReadTimer(void)
{
    uint8_t readVal;

    readVal = TMR2;

    return readVal;
}

void TMR2_WriteTimer(uint8_t timerVal)
{
    // Write to the Timer2 register
    TMR2 = timerVal;
}

void TMR2_LoadPeriodRegister(uint8_t periodVal)
{
   PR2 = periodVal;
}

void TMR2_ISR(void)
{
    static volatile unsigned int CountCallBack = 0;

    // clear the TMR2 interrupt flag
    PIR1bits.TMR2IF = 0;

    // callback function - called every 16th pass (75 useg aproximadamente))
    if (++CountCallBack >= TMR2_INTERRUPT_TICKER_FACTOR)
    {
        // ticker function call
        TMR2_CallBack();

        // reset ticker counter
        CountCallBack = 0;
    }
}

void TMR2_CallBack(void)
{
    // Add your custom callback code here
    // this code executes every TMR2_INTERRUPT_TICKER_FACTOR periods of TMR2
    Timer2Ticked = 1;
    if(TMR2_InterruptHandler)
    {
        TMR2_InterruptHandler();
    }
}

void TMR2_SetInterruptHandler(void* InterruptHandler){
    TMR2_InterruptHandler = InterruptHandler;
}

void TMR2_DefaultInterruptHandler(void){
    // add your TMR2 interrupt custom code
    // or set custom function using TMR2_SetInterruptHandler()
}

/**
  End of File
*/
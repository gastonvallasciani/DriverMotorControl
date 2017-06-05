/*
  Description:
    Generation Information :
        Product Revision  :  MPLAB(c) Code Configurator - 4.15
        Device            :  PIC18F46K22
        Driver Version    :  2.00
    The generated drivers are tested against the following:
        Compiler          :  XC8 1.35
        MPLAB             :  MPLAB X 3.40
 * 
 * bug: Arranque muy brusco. Falta realimentación de corriente y control de dirección.  
 * 
*/
#include "mcc_generated_files/mcc.h"
#include "MotorDriver.h"


extern unsigned char Timer2Ticked;
int Timer2Tick_count;
int StepCount;
/*
                         Main application
 */
void main(void)
{
    // Initialize the device
    SYSTEM_Initialize();
    StateMEF_ini();
    LTest_SetHigh();
    Timer2Tick_count=0;
    StepCount=0;
    // Enable the Global Interrupts
    INTERRUPT_GlobalInterruptEnable();

    // Enable the Peripheral Interrupts
    INTERRUPT_PeripheralInterruptEnable();
    while (1)
    {   
        if (StepCount<500)
        {
            if (Timer2Ticked){ 
                Timer2Tick_count++;
                if (Timer2Tick_count==5){
                StateMEF_act();
                StepCount++;
                Timer2Tick_count=0;
                }
                Timer2Ticked = 0;
            }
        }
    }
}
/**
 End of File
*/
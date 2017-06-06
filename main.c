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
 * bug: Falta realimentación de corriente, control de dirección y de velocidad.  
 * 
*/
#include "mcc_generated_files/mcc.h"
#include "MotorDriver.h"

void main(void)
{
    // Initialize the device
    SYSTEM_Initialize();
    StateMEF_ini();
    LTest_SetHigh();

    // Enable the Global Interrupts
    INTERRUPT_GlobalInterruptEnable();

    // Enable the Peripheral Interrupts
    INTERRUPT_PeripheralInterruptEnable();
    while (1)
    {      
      StepMove(1400,1);
    }
}
/**
 End of File
*/
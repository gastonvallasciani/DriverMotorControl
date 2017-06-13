/*
  Description:
    Generation Information :
        Product Revision  :  MPLAB(c) Code  - 4.15
        Device            :  PIC18F46K22
        Driver Version    :  2.00
    The generated drivers are tested against the following:
        Compiler          :  XC8 1.35
        MPLAB             :  MPLAB X 3.40
 * 
 * bug:  
 * 
*/
#include "mcc_generated_files/mcc.h"
#include "MotorDriver.h"

extern unsigned char Timer2Ticked; 

void main(void)
{
    // Initialize the device
    SYSTEM_Initialize();
    StateMEF_ini();
    Timer2Ticked=0;
    LTest_SetHigh();

    // Enable the Global Interrupts
    INTERRUPT_GlobalInterruptEnable();

    // Enable the Peripheral Interrupts
    INTERRUPT_PeripheralInterruptEnable();
    while (1)
    {      
 
            StepMove(3000,1,16,BACKWARD);    // numero de pasos, velocidad, numero de micropasos,direccion  tao=L/Rl = 1.6mHy/0.77ohm = 2.07ms --> 5*tao = 10.38ms (Tiempo que tarda en 
                                            // cargar una bobina del devanado))
   
      
    }
}
/**
 End of File
*/
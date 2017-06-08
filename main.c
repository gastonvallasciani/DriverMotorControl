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

//uint16_t ANALOG_0;
//uint8_t ADRESLH[2];
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
      StepMove(3000,1,16);    // numero de pasos, velocidad, numero de micropasos  tao=L/Rl = 1.6mHy/0.77ohm = 2.7ms --> 5*tao = 10.38ms (Tiempo que tarda en 
                              // cargar una bobina del devanado))
      /*if (Timer2Ticked){
          
        ANALOG_0 = ADC_Conversion(0);

        ADRESLH[0]=ADRESL;
        ADRESLH[1]=ADRESH;
        EUSART1_Write(ADRESLH[0]);
        EUSART1_Write(ADRESLH[1]);
      }*/
      
    }
}
/**
 End of File
*/
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

uint8_t StepsComplete;

extern unsigned char Timer2Ticked; 
extern unsigned char DelayTimerTicked; 

void main(void)
{
    // Initialize the device
    SYSTEM_Initialize();
    StateMEF_ini();
    Timer2Ticked=0;
    DelayTimerTicked=0;
    LTest_SetHigh();
    

    StepperMotor.Velocidad = 10;
    StepperMotor.StepsNumber = 2000;
    StepperMotor.MicroStepNumber = MICROSTEP16;

    // Enable the Global Interrupts
    INTERRUPT_GlobalInterruptEnable();

    // Enable the Peripheral Interrupts
    INTERRUPT_PeripheralInterruptEnable();
    while (1)
    {      
          // numero de pasos, velocidad, numero de micropasos,direccion  tao=L/Rl = 1.6mHy/0.77ohm = 2.07ms --> 5*tao = 10.38ms (Tiempo que tarda en 
         // cargar una bobina del devanado)) VELOCIDAD a partir de 3
        
        StepperMotor.Direccion = FORWARD;
      
        RectaAceleracion( StepperMotor.Velocidad , StepperMotor.MicroStepNumber , StepperMotor.Direccion );
        while(StepMove(StepperMotor.StepsNumber, StepperMotor.Velocidad , StepperMotor.MicroStepNumber ,StepperMotor.Direccion)==NO);
        RectaFrenado( StepperMotor.Velocidad , StepperMotor.MicroStepNumber , StepperMotor.Direccion);
        Motor_Stop();
        
        StateMEF_ini();
        
        DelayTmr2(s1_t);
        
        StepperMotor.Direccion = BACKWARD;
        
        RectaAceleracion( StepperMotor.Velocidad , StepperMotor.MicroStepNumber , StepperMotor.Direccion);
        while(StepMove(StepperMotor.StepsNumber , StepperMotor.Velocidad , StepperMotor.MicroStepNumber ,StepperMotor.Direccion)==NO);
        RectaFrenado( StepperMotor.Velocidad , StepperMotor.MicroStepNumber , StepperMotor.Direccion);
        Motor_Stop();
        
        DelayTmr2(s1_t);
        
        StateMEF_ini();
        
       
    }
}
/**
 End of File
*/
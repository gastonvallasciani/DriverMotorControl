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
 * 
*/
#include "mcc_generated_files/mcc.h"
#include "MotorDriver.h"

uint8_t StepsComplete;

extern unsigned char Timer2Ticked; 
extern unsigned char DelayTimerTicked; 

uint8_t parar=0;

void main(void)
{
    // Initialize the device
    SYSTEM_Initialize();
    StateMEF_ini();
    Timer2Ticked=0;
    DelayTimerTicked=0;
    LTest_SetHigh();
    

    StepperMotor.Velocidad = SLOWESTSPEED_16uSTEPS;
    StepperMotor.StepsNumber = 2*(REVOLUTION_16uSTEPS);
    StepperMotor.MicroStepNumber = MICROSTEP16;
    StepperMotor.Direccion = FORWARD;
    
    // Enable the Global Interrupts
    INTERRUPT_GlobalInterruptEnable();

    // Enable the Peripheral Interrupts
    INTERRUPT_PeripheralInterruptEnable();
    while (1)
    {      
        
        /*RectaAceleracion( StepperMotor.Velocidad , StepperMotor.MicroStepNumber , StepperMotor.Direccion );
        while(StepMove(StepperMotor.StepsNumber, StepperMotor.Velocidad , StepperMotor.MicroStepNumber ,StepperMotor.Direccion)==NO);
        RectaFrenado( StepperMotor.Velocidad , StepperMotor.MicroStepNumber , StepperMotor.Direccion);
        Motor_Stop();
        
        StateMEF_ini();
        
        StepperMotor.Direccion = SwitchDirection( StepperMotor.Direccion );
        
        DelayTmr2(s1_t);*/
        
      
        if (parar==0){
            parar=1;
            RectaAceleracion( StepperMotor.Velocidad , StepperMotor.MicroStepNumber , StepperMotor.Direccion );
            while(StepMove(StepperMotor.StepsNumber, StepperMotor.Velocidad , StepperMotor.MicroStepNumber ,StepperMotor.Direccion)==NO);
            Motor_Stop();
        }
        
       
    }
}
/**
 End of File
*/
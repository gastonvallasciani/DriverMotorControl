#include "MotorDriver.h"
#include "mcc_generated_files/mcc.h"


static uint8_t LookUP_TABLE_COS[32]={250,237,216,188,153,113,69,24,24,69,113,153,188,216,237,250,250,237,216,188,153,113,69,24,24,69,113,153,188,216,237,250};
static uint8_t LookUP_TABLE_SEN[32]={24,69,113,153,188,216,237,250,250,237,216,188,153,113,69,24,24,69,113,153,188,216,237,250,250,237,216,188,153,113,69,24};

static uint8_t LookUP_TABLE_COS_16[64]={254,250,244,236,226,214,200,184,166,147,127,106,83,60,36,12,12,36,60,83,106,127,147,166,184,200,214,226,236,244,250,254,254,250,244,236,226,214,200,184,166,147,127,106,83,60,36,12,12,36,60,83,106,127,147,166,184,200,214,226,236,244,250,254};
static uint8_t LookUP_TABLE_SEN_16[64]={12,36,60,83,106,127,147,166,184,200,214,226,236,244,250,254,254,250,244,236,226,214,200,184,166,147,127,106,83,60,36,12,12,36,60,83,106,127,147,166,184,200,214,226,236,244,250,254,254,250,244,236,226,214,200,184,166,147,127,106,83,60,36,12};
static int8_t Microstep;

static int8_t Direccion;

static uint16_t StepCount=0;

static uint16_t Timer2Tick_count;

extern unsigned char Timer2Ticked;





typedef enum{
    STATE0,
    STATE1,
    STATE2,
    STATE3,    
    STATE4   
}t_STATEMEF;

t_STATEMEF EstadoActual;



void StateMEF_ini( void ){
      EstadoActual = STATE1;
      Microstep=0;
}

void State8MEF_act( void ){
     switch(EstadoActual) {
         case STATE0:
             PSTR1CON = 0x00; PSTR2CON = 0x00;
             INA_OFF(); INB_OFF();INC_OFF(); IND_OFF();
             EstadoActual = STATE1;
             break;
         case STATE1:
                 PSTR1CON = 0x01; PSTR2CON = 0x01;
                 INB_OFF(); IND_OFF();                  
                 if (Microstep<8){
                     EUSART1_Write(Microstep);
                     EPWM1_LoadDutyValue(LookUP_TABLE_COS[Microstep]);
                     EPWM2_LoadDutyValue(LookUP_TABLE_SEN[Microstep]);                     
                     if (Microstep==7){
                         EstadoActual = STATE2;                  
                     }
                        Microstep++;                    
                 }
             break;
         case STATE2:
                 PSTR1CON = 0x02; PSTR2CON = 0x01;
                 INA_OFF(); IND_OFF();
                 if ((Microstep<16)&&(Microstep>7)){
                     EUSART1_Write(Microstep);
                     EPWM1_LoadDutyValue(LookUP_TABLE_COS[Microstep]);
                     EPWM2_LoadDutyValue(LookUP_TABLE_SEN[Microstep]);
                     if (Microstep==15){
                         EstadoActual = STATE3;      
                     }
                        Microstep++;                    
                 }
             break;
         case STATE3:                 
                 PSTR1CON = 0x02; PSTR2CON = 0x02;
                 INA_OFF(); INC_OFF();
                   if ((Microstep<24)&&(Microstep>15)){
                     EUSART1_Write(Microstep);
                     EPWM1_LoadDutyValue(LookUP_TABLE_COS[Microstep]);
                     EPWM2_LoadDutyValue(LookUP_TABLE_SEN[Microstep]);
                     if (Microstep==23){
                         EstadoActual = STATE4;
                     }
                        Microstep++;
                 }
             break;
         case STATE4:
                 PSTR1CON = 0x01; PSTR2CON = 0x02;
                 INB_OFF(); INC_OFF();
                  if ((Microstep<32)&&(Microstep>23)){
                     EUSART1_Write(Microstep);
                     EPWM1_LoadDutyValue(LookUP_TABLE_COS[Microstep]);
                     EPWM2_LoadDutyValue(LookUP_TABLE_SEN[Microstep]);
                     if (Microstep==31){
                         EstadoActual = STATE0;
                         Microstep=-1;
                     }
                        Microstep++; 
                 }
             break;
         default:
             StateMEF_ini;
             break; 
     }    
}

void State16MEF_act( void ){
     switch(EstadoActual) {
         case STATE0:
             PSTR1CON = 0x00; PSTR2CON = 0x00;
             INA_OFF(); INB_OFF();INC_OFF(); IND_OFF();
             EstadoActual = STATE1;
             break;
         case STATE1:
                 PSTR1CON = 0x01; PSTR2CON = 0x01;
                 INB_OFF(); IND_OFF();                  
                 if (Microstep<16){
                     EUSART1_Write(Microstep);
                     EPWM1_LoadDutyValue(LookUP_TABLE_COS_16[Microstep]);
                     EPWM2_LoadDutyValue(LookUP_TABLE_SEN_16[Microstep]);                     
                 if (Microstep==15){
                         EstadoActual = STATE2;                  
                     }
                        Microstep++;                    
                 }
             break;
         case STATE2:
                 PSTR1CON = 0x02; PSTR2CON = 0x01;
                 INA_OFF(); IND_OFF();
                 if ((Microstep<32)&&(Microstep>15)){
                     EUSART1_Write(Microstep);
                     EPWM1_LoadDutyValue(LookUP_TABLE_COS_16[Microstep]);
                     EPWM2_LoadDutyValue(LookUP_TABLE_SEN_16[Microstep]);
                     if (Microstep==31){
                         EstadoActual = STATE3;      
                     }
                        Microstep++;                    
                 }
             break;
         case STATE3:                 
                 PSTR1CON = 0x02; PSTR2CON = 0x02;
                 INA_OFF(); INC_OFF();
                 if ((Microstep<48)&&(Microstep>31)){
                     EUSART1_Write(Microstep);
                     EPWM1_LoadDutyValue(LookUP_TABLE_COS_16[Microstep]);
                     EPWM2_LoadDutyValue(LookUP_TABLE_SEN_16[Microstep]);
                     if (Microstep==47){
                         EstadoActual = STATE4;
                     }
                        Microstep++;
                 }
             break;
         case STATE4:
                 PSTR1CON = 0x01; PSTR2CON = 0x02;
                 INB_OFF(); INC_OFF();
                 if ((Microstep<64)&&(Microstep>47)){              
                     EUSART1_Write(Microstep);
                     EPWM1_LoadDutyValue(LookUP_TABLE_COS_16[Microstep]);
                     EPWM2_LoadDutyValue(LookUP_TABLE_SEN_16[Microstep]);
                     if (Microstep==63){
                         EstadoActual = STATE0;
                         Microstep=-1;
                     }
                        Microstep++; 
                 }
             break;
         default:
             StateMEF_ini;
             break; 
     }    
}

void StepMove( uint16_t StepNumber, uint8_t Velocidad,uint8_t microstep_number ){
   
    if (StepCount<StepNumber)
        {
            if (StepCount < StepNumber)
            {
                if (Timer2Ticked){ 
                    Timer2Tick_count++;
                    if (Timer2Tick_count == Velocidad){
                        if (microstep_number==16){
                            State16MEF_act();
                        }
                        else{State8MEF_act();}
                    StepCount++;
                    Timer2Tick_count=0;
                    }
                    Timer2Ticked = 0;
                }
            }  
        }
}

uint16_t ADC_Conversion( uint8_t channel ){
    uint16_t VALUE;
    
    ADC_SelectChannel(channel);
    ADC_StartConversion();
    if (ADC_IsConversionDone()){
        VALUE = ADC_GetConversionResult();
    }
    return(VALUE);
}

/*uint8_t control (uint8_t LookUp){
   
    int8_t error;
    float Vref;

    Vref = ADC_Conversion(0);
    Vref = Vref/257;
    
    error = (uint8_t)Vref - LookUp;
    if error<0{
        LookUp_Table=LookUp+2;
    }
    else if(error>0){
        LookUp_Table=LookUp-2;
    }
   return(0);
}*/





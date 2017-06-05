#include "MotorDriver.h"
#include "mcc_generated_files/mcc.h"

static uint8_t LookUP_TABLE_COS[32]={250,237,216,188,153,113,69,24,24,69,113,153,188,216,237,250,250,237,216,188,153,113,69,24,24,69,113,153,188,216,237,250};
static uint8_t LookUP_TABLE_SEN[32]={24,69,113,153,188,216,237,250,250,237,216,188,153,113,69,24,24,69,113,153,188,216,237,250,250,237,216,188,153,113,69,24};

static int8_t Microstep;

typedef enum{
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

void StateMEF_act( void ){
     switch(EstadoActual) {
         case STATE1:
                 PSTR1CON = 0x01; PSTR2CON = 0x01;
                 INB_OFF(); IND_OFF(); 
                 EUSART1_Write(Microstep);
                 if (Microstep<8){
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
                 EUSART1_Write(Microstep);
                 if ((Microstep<16)&&(Microstep>7)){
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
                 EUSART1_Write(Microstep);
                 if ((Microstep<24)&&(Microstep>15)){
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
                 EUSART1_Write(Microstep);
                 if ((Microstep<32)&&(Microstep>23)){
                     EPWM1_LoadDutyValue(LookUP_TABLE_COS[Microstep]);
                     EPWM2_LoadDutyValue(LookUP_TABLE_SEN[Microstep]);
                     if (Microstep==31){
                         EstadoActual = STATE1;
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





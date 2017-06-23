#include "MotorDriver.h"
#include "mcc_generated_files/mcc.h"


static uint8_t LookUP_TABLE_COS[32]={125,118,108,94,77,57,34,12,12,34,57,77,94,108,118,125,125,118,108,94,77,57,34,12,12,34,57,77,94,108,118,125};
static uint8_t LookUP_TABLE_SEN[32]={12,34,57,77,94,108,118,125,125,118,108,94,77,57,34,12,12,34,57,77,94,108,118,125,125,118,108,94,77,57,34,12};

static uint8_t LookUP_TABLE_COS_16[64]={126,124,121,117,112,106,99,91,83,73,63,53,42,29,18,6,6,18,29,42,53,63,73,83,91,99,106,112,117,121,124,126,126,124,121,117,112,106,99,91,83,73,63,53,42,29,18,6,6,18,29,42,53,63,73,83,91,99,106,112,117,121,124,126};
static uint8_t LookUP_TABLE_SEN_16[64]={6,18,29,42,53,63,73,83,91,99,106,112,117,121,124,126,126,124,121,117,112,106,99,91,83,73,63,53,42,29,18,6,6,18,29,42,53,63,73,83,91,99,106,112,117,121,124,126,126,124,121,117,112,106,99,91,83,73,63,53,42,29,18,6};

static int16_t Microstep;

uint16_t StepCount=0;

static uint16_t Timer2Tick_count;

static uint8_t MoveDone;

extern uint8_t Timer2Ticked;
extern uint8_t DelayTimerTicked;

uint8_t StepsComplete=NO;

static void limitar_corriente( void );

typedef enum{
    STATE0,
    STATE1,
    STATE2,
    STATE3,    
    STATE4   
}t_STATEMEF;

t_STATEMEF EstadoActual;

void StateMEF_ini( void ){
      //EstadoActual = STATE0;
    EstadoActual = STATE1;  
    Microstep=0;
}

uint8_t StepMove( uint16_t StepNumber, uint8_t Velocidad,uint8_t microstep_number, uint8_t direccion ){
    
    if ((StepCount<StepNumber)){
            if (Timer2Ticked){ 
                Timer2Tick_count++;
                if (Timer2Tick_count == Velocidad){
                     if (microstep_number==16){
                     State16MEF_act( direccion );
                     }
                     else{
                        State8MEF_act( direccion );
                     }
                    StepCount++;
                    Timer2Tick_count=0;
                    }
                    Timer2Ticked = 0;
                }       
            StepsComplete=NO;  
    }
    else{
        StepsComplete=YES;
        StepCount=0;
      
    }
    return(StepsComplete);
}



static void limitar_corriente( void ){
    if ((LookUP_TABLE_COS[Microstep])>115){
        LookUP_TABLE_COS[Microstep]=115;
    }
    if ((LookUP_TABLE_SEN[Microstep])>115){
        LookUP_TABLE_SEN[Microstep]=115;
    }
    
}

void Motor_Stop( void ){
    PSTR1CON = 0x00; PSTR2CON = 0x00;
    INA_OFF(); INB_OFF();INC_OFF(); IND_OFF();
}

void DelayTmr2(unsigned uint16_t Timeout){
    
	// Solo puede haber un Delay en ejecución
	// No se puede llamar a Delay desde interrupciones
	DelayTimerTicked = 0; // Timer2Tick cambia a YES
	while (Timeout > 0)
	{
		if (DelayTimerTicked)
		{
			Timeout--;
			DelayTimerTicked = 0;
		}
	}
}

void State8MEF_act( uint8_t direccion ){

     switch(EstadoActual) {
         case STATE1:
                 PSTR1CON = 0x01; PSTR2CON = 0x01;
                 INB_OFF(); IND_OFF();                  
                 if (Microstep<8){     
                     //EUSART1_Write(Microstep);
                     //limitar_corriente();
                     
                     EPWM1_LoadDutyValue(LookUP_TABLE_COS[Microstep]);
                     EPWM2_LoadDutyValue(LookUP_TABLE_SEN[Microstep]);
                     
                     if (direccion == FORWARD){
                        if (Microstep==7){
                        EstadoActual = STATE2;                  
                        }
                        Microstep++;  
                     }
                     else{
                        if (Microstep==0){
                        EstadoActual = STATE4;
                        Microstep=31;
                        }
                        Microstep--; 
                     }   
                }
             break;
         case STATE2:
                 PSTR1CON = 0x02; PSTR2CON = 0x01;
                 INA_OFF(); IND_OFF();
                 if ((Microstep<16)&&(Microstep>7)){
                     
                     //EUSART1_Write(Microstep);                
                     //limitar_corriente();
                     
                     EPWM1_LoadDutyValue(LookUP_TABLE_COS[Microstep]);
                     EPWM2_LoadDutyValue(LookUP_TABLE_SEN[Microstep]);
                     
                     if (direccion == FORWARD){
                        if (Microstep==15){
                        EstadoActual = STATE3;      
                        }
                        Microstep++;
                     }
                     else{
                        if (Microstep==8){
                        EstadoActual = STATE1;      
                        }
                        Microstep--;         
                        }                    
                 }
             break;
         case STATE3:                 
                 PSTR1CON = 0x02; PSTR2CON = 0x02;
                 INA_OFF(); INC_OFF();
                 if ((Microstep<24)&&(Microstep>15)){
                     
                     //EUSART1_Write(Microstep);
                     //limitar_corriente();
                     
                     EPWM1_LoadDutyValue(LookUP_TABLE_COS[Microstep]);
                     EPWM2_LoadDutyValue(LookUP_TABLE_SEN[Microstep]); 
                     
                     if (direccion == FORWARD){
                        if (Microstep==23){
                        EstadoActual = STATE4;
                        }
                        Microstep++;
                     }
                     else{
                        if (Microstep==16){
                        EstadoActual = STATE2;
                        }
                        Microstep--; 
                     }
                 }
             break;
         case STATE4:
                 PSTR1CON = 0x01; PSTR2CON = 0x02;
                 INB_OFF(); INC_OFF();
                 if ((Microstep<32)&&(Microstep>23)){
                     
                     //EUSART1_Write(Microstep);               
                     //limitar_corriente();
                     
                     EPWM1_LoadDutyValue(LookUP_TABLE_COS[Microstep]);
                     EPWM2_LoadDutyValue(LookUP_TABLE_SEN[Microstep]); 
                     
                     if (direccion == FORWARD){
                        if (Microstep==31){
                        EstadoActual = STATE1;
                        Microstep=-1;
                        }
                        Microstep++;  
                     }
                     else{
                        if (Microstep==24){
                        EstadoActual = STATE3;
                        }
                        Microstep--; 
                     } 
                 }
             break;
         default:
             StateMEF_ini;
             break; 
     }    
}

void State16MEF_act( uint8_t direccion ){

     switch(EstadoActual) {
         case STATE1:
                 PSTR1CON = 0x01; PSTR2CON = 0x01;
                 INB_OFF(); IND_OFF();                  
                 if (Microstep<16){     
                     //EUSART1_Write(Microstep);
                     //limitar_corriente();
                     
                     EPWM1_LoadDutyValue(LookUP_TABLE_COS_16[Microstep]);
                     EPWM2_LoadDutyValue(LookUP_TABLE_SEN_16[Microstep]);
                     
                     if (direccion == FORWARD){
                        if (Microstep==15){
                        EstadoActual = STATE2;                  
                        }
                        Microstep++;  
                     }
                     else{
                        if (Microstep==0){
                        EstadoActual = STATE4;
                        Microstep=63;
                        }
                        Microstep--; 
                     }   
                }
             break;
         case STATE2:
                 PSTR1CON = 0x02; PSTR2CON = 0x01;
                 INA_OFF(); IND_OFF();
                 if ((Microstep<32)&&(Microstep>15)){
                     
                     //EUSART1_Write(Microstep);                
                     //limitar_corriente();
                     
                     EPWM1_LoadDutyValue(LookUP_TABLE_COS_16[Microstep]);
                     EPWM2_LoadDutyValue(LookUP_TABLE_SEN_16[Microstep]);
                     
                     if (direccion == FORWARD){
                        if (Microstep==31){
                        EstadoActual = STATE3;      
                        }
                        Microstep++;
                     }
                     else{
                        if (Microstep==16){
                        EstadoActual = STATE1;      
                        }
                        Microstep--;         
                        }                    
                 }
             break;
         case STATE3:                 
                 PSTR1CON = 0x02; PSTR2CON = 0x02;
                 INA_OFF(); INC_OFF();
                 if ((Microstep<48)&&(Microstep>31)){
                     
                     //EUSART1_Write(Microstep);
                     //limitar_corriente();
                     
                     EPWM1_LoadDutyValue(LookUP_TABLE_COS_16[Microstep]);
                     EPWM2_LoadDutyValue(LookUP_TABLE_SEN_16[Microstep]); 
                     
                     if (direccion == FORWARD){
                        if (Microstep==47){
                        EstadoActual = STATE4;
                        }
                        Microstep++;
                     }
                     else{
                        if (Microstep==32){
                        EstadoActual = STATE2;
                        }
                        Microstep--; 
                     }
                 }
             break;
         case STATE4:
                 PSTR1CON = 0x01; PSTR2CON = 0x02;
                 INB_OFF(); INC_OFF();
                 if ((Microstep<64)&&(Microstep>47)){
                     
                     //EUSART1_Write(Microstep);               
                     //limitar_corriente();
                     
                     EPWM1_LoadDutyValue(LookUP_TABLE_COS_16[Microstep]);
                     EPWM2_LoadDutyValue(LookUP_TABLE_SEN_16[Microstep]); 
                     
                     if (direccion == FORWARD){
                        if (Microstep==63){
                        EstadoActual = STATE1;
                        Microstep=-1;
                        }
                        Microstep++;  
                     }
                     else{
                        if (Microstep==48){
                        EstadoActual = STATE3;
                        }
                        Microstep--; 
                     } 
                 }
             break;
         default:
             StateMEF_ini;
             break; 
     }    
}

void RectaAceleracion( uint8_t velocidad , uint8_t microstep_number, uint8_t direccion){
    uint8_t i;
    if (microstep_number == 8){
       for (i=30;i>velocidad;i--){
       while(StepMove(10,i,8,direccion)==NO);    
       }     
    }
    else if (microstep_number == 16){
       for (i=30;i>velocidad;i--){
       while(StepMove(10,i,16,direccion)==NO);    
       }
    }
    
}

/*void RectaFrenado( uint8_t velocidad , uint8_t microstep_number, uint8_t direccion){
    uint8_t i;
    if (microstep_number == 8){
       for (i=velocidad;i<30;i++){
       while(StepMove(10,i,8,direccion)==NO);    
       }     
    }
    else if (microstep_number == 16){
       for (i=velocidad;i<30;i++){
       while(StepMove(10,i,16,direccion)==NO);    
       }
    }
}*/






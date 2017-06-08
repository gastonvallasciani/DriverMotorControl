/* 
 * File:   MotorDriver.h
 * Author: Gastón Vallasciani
 *
 * Created on May 26, 2017, 10:57 AM
 */

#ifndef MOTORDRIVER_H
#define	MOTORDRIVER_H

#include "mcc_generated_files/mcc.h"

void StateMEF_ini( void );
void State8MEF_act( void );
void State16MEF_act( void );
void StepMove( uint16_t StepNumber, uint8_t Velocidad, uint8_t microstep_number );
uint8_t controlador1(uint8_t LookUp,uint16_t An_Acquisition);
uint8_t controlador2(uint8_t LookUp,uint16_t An_Acquisition);

// INA(P1A) --> RC2 --> PSTR2CON STRA
// INB(P1B) --> RD5 --> PSTR1CON STRB
// INC(P2A) --> RC1 --> PSTR1CON STRA
// IND(P2B) --> RC0 --> PSTR2CON STRB


//          PSTRxCON = - | - | - | STRxSYNC | STRxD | STRxC | STRxB | STRxA
//                     b7  b6  b5   b4         b3      b2      b1      b0
//
//                                  STRxSYNC = 1 --> output steering update occurs on the next PWM period.
//                                  STRxSYNC = 0 --> output steering update occurs at the beginning of the instruction cycle boundary. 
//
//                                  STRxA,B,C,D = 1 --> PxA,B,C,D pins have the PWM waveform with polarity control from CCPxM<1:0>
//                                  STRxA,B,C,D = 0 --> PxA,B,C,D are assign to port pin.

#define FORWARD 1
#define BACKWARD 0

// IN A
#define INA_SET(x)        LATCbits.LATC2 = x
#define INA_OFF()         RC2_SetLow()     // IO_RC2_MOTOR2_PAP1_SetLow()
#define INA_ON()          RC2_SetHigh()    // IO_RC2_MOTOR2_PAP1_SetHigh()
// IN B
#define INB_SET(x)        LATDbits.LATD2 = x
#define INB_OFF()         RD5_SetLow()     // IO_RD5_MOTOR2_PDIR1_SetLow()
#define INB_ON()          RD5_SetHigh()    // IO_RD5_MOTOR2_PDIR1_SetHigh()
// IN C
#define INC_SET(x)        LATCbits.LATC1 = x
#define INC_OFF()         RC1_SetLow()     // IO_RC1_MOTOR2_PAP2_SetLow()
#define INC_ON()          RC1_SetHigh()    // IO_RC1_MOTOR2_PAP2_SetHigh()
// IN D
#define IND_SET(x)        LATCbits.LATC0 = x
#define IND_OFF()         RC0_SetLow()     // IO_RC0_MOTOR2_PDIR2_SetLow()
#define IND_ON()          RC0_SetHigh()    // IO_RC0_MOTOR2_PDIR2_SetHigh()


#ifdef	__cplusplus
extern "C" {
#endif




#ifdef	__cplusplus
}
#endif

#endif	/* MOTORDRIVER_H */


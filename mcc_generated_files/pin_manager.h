/**
  @Generated Pin Manager Header File

  @Company:
    Microchip Technology Inc.

  @File Name:
    pin_manager.h

  @Summary:
    This is the Pin Manager file generated using MPLAB(c) Code Configurator

  @Description:
    This header file provides implementations for pin APIs for all pins selected in the GUI.
    Generation Information :
        Product Revision  :  MPLAB(c) Code Configurator - 4.15
        Device            :  PIC18F46K22
        Version           :  1.01
    The generated drivers are tested against the following:
        Compiler          :  XC8 1.35
        MPLAB             :  MPLAB X 3.40

    Copyright (c) 2013 - 2015 released Microchip Technology Inc.  All rights reserved.

    Microchip licenses to you the right to use, modify, copy and distribute
    Software only when embedded on a Microchip microcontroller or digital signal
    controller that is integrated into your product or third party product
    (pursuant to the sublicense terms in the accompanying license agreement).

    You should refer to the license agreement accompanying this Software for
    additional information regarding your rights and obligations.

    SOFTWARE AND DOCUMENTATION ARE PROVIDED "AS IS" WITHOUT WARRANTY OF ANY KIND,
    EITHER EXPRESS OR IMPLIED, INCLUDING WITHOUT LIMITATION, ANY WARRANTY OF
    MERCHANTABILITY, TITLE, NON-INFRINGEMENT AND FITNESS FOR A PARTICULAR PURPOSE.
    IN NO EVENT SHALL MICROCHIP OR ITS LICENSORS BE LIABLE OR OBLIGATED UNDER
    CONTRACT, NEGLIGENCE, STRICT LIABILITY, CONTRIBUTION, BREACH OF WARRANTY, OR
    OTHER LEGAL EQUITABLE THEORY ANY DIRECT OR INDIRECT DAMAGES OR EXPENSES
    INCLUDING BUT NOT LIMITED TO ANY INCIDENTAL, SPECIAL, INDIRECT, PUNITIVE OR
    CONSEQUENTIAL DAMAGES, LOST PROFITS OR LOST DATA, COST OF PROCUREMENT OF
    SUBSTITUTE GOODS, TECHNOLOGY, SERVICES, OR ANY CLAIMS BY THIRD PARTIES
    (INCLUDING BUT NOT LIMITED TO ANY DEFENSE THEREOF), OR OTHER SIMILAR COSTS.

*/


#ifndef PIN_MANAGER_H
#define PIN_MANAGER_H

#define INPUT   1
#define OUTPUT  0

#define HIGH    1
#define LOW     0

#define ANALOG      1
#define DIGITAL     0

#define PULL_UP_ENABLED      1
#define PULL_UP_DISABLED     0

// get/set AN_A aliases
#define AN_A_TRIS               TRISAbits.TRISA0
#define AN_A_LAT                LATAbits.LATA0
#define AN_A_PORT               PORTAbits.RA0
#define AN_A_ANS                ANSELAbits.ANSA0
#define AN_A_SetHigh()            do { LATAbits.LATA0 = 1; } while(0)
#define AN_A_SetLow()             do { LATAbits.LATA0 = 0; } while(0)
#define AN_A_Toggle()             do { LATAbits.LATA0 = ~LATAbits.LATA0; } while(0)
#define AN_A_GetValue()           PORTAbits.RA0
#define AN_A_SetDigitalInput()    do { TRISAbits.TRISA0 = 1; } while(0)
#define AN_A_SetDigitalOutput()   do { TRISAbits.TRISA0 = 0; } while(0)
#define AN_A_SetAnalogMode()  do { ANSELAbits.ANSA0 = 1; } while(0)
#define AN_A_SetDigitalMode() do { ANSELAbits.ANSA0 = 0; } while(0)

// get/set AN_B aliases
#define AN_B_TRIS               TRISAbits.TRISA1
#define AN_B_LAT                LATAbits.LATA1
#define AN_B_PORT               PORTAbits.RA1
#define AN_B_ANS                ANSELAbits.ANSA1
#define AN_B_SetHigh()            do { LATAbits.LATA1 = 1; } while(0)
#define AN_B_SetLow()             do { LATAbits.LATA1 = 0; } while(0)
#define AN_B_Toggle()             do { LATAbits.LATA1 = ~LATAbits.LATA1; } while(0)
#define AN_B_GetValue()           PORTAbits.RA1
#define AN_B_SetDigitalInput()    do { TRISAbits.TRISA1 = 1; } while(0)
#define AN_B_SetDigitalOutput()   do { TRISAbits.TRISA1 = 0; } while(0)
#define AN_B_SetAnalogMode()  do { ANSELAbits.ANSA1 = 1; } while(0)
#define AN_B_SetDigitalMode() do { ANSELAbits.ANSA1 = 0; } while(0)

// get/set ILAMP aliases
#define ILAMP_TRIS               TRISAbits.TRISA2
#define ILAMP_LAT                LATAbits.LATA2
#define ILAMP_PORT               PORTAbits.RA2
#define ILAMP_ANS                ANSELAbits.ANSA2
#define ILAMP_SetHigh()            do { LATAbits.LATA2 = 1; } while(0)
#define ILAMP_SetLow()             do { LATAbits.LATA2 = 0; } while(0)
#define ILAMP_Toggle()             do { LATAbits.LATA2 = ~LATAbits.LATA2; } while(0)
#define ILAMP_GetValue()           PORTAbits.RA2
#define ILAMP_SetDigitalInput()    do { TRISAbits.TRISA2 = 1; } while(0)
#define ILAMP_SetDigitalOutput()   do { TRISAbits.TRISA2 = 0; } while(0)
#define ILAMP_SetAnalogMode()  do { ANSELAbits.ANSA2 = 1; } while(0)
#define ILAMP_SetDigitalMode() do { ANSELAbits.ANSA2 = 0; } while(0)

// get/set LED_MEDIR aliases
#define LED_MEDIR_TRIS               TRISAbits.TRISA4
#define LED_MEDIR_LAT                LATAbits.LATA4
#define LED_MEDIR_PORT               PORTAbits.RA4
#define LED_MEDIR_SetHigh()            do { LATAbits.LATA4 = 1; } while(0)
#define LED_MEDIR_SetLow()             do { LATAbits.LATA4 = 0; } while(0)
#define LED_MEDIR_Toggle()             do { LATAbits.LATA4 = ~LATAbits.LATA4; } while(0)
#define LED_MEDIR_GetValue()           PORTAbits.RA4
#define LED_MEDIR_SetDigitalInput()    do { TRISAbits.TRISA4 = 1; } while(0)
#define LED_MEDIR_SetDigitalOutput()   do { TRISAbits.TRISA4 = 0; } while(0)

// get/set CAJON aliases
#define CAJON_TRIS               TRISBbits.TRISB0
#define CAJON_LAT                LATBbits.LATB0
#define CAJON_PORT               PORTBbits.RB0
#define CAJON_WPU                WPUBbits.WPUB0
#define CAJON_ANS                ANSELBbits.ANSB0
#define CAJON_SetHigh()            do { LATBbits.LATB0 = 1; } while(0)
#define CAJON_SetLow()             do { LATBbits.LATB0 = 0; } while(0)
#define CAJON_Toggle()             do { LATBbits.LATB0 = ~LATBbits.LATB0; } while(0)
#define CAJON_GetValue()           PORTBbits.RB0
#define CAJON_SetDigitalInput()    do { TRISBbits.TRISB0 = 1; } while(0)
#define CAJON_SetDigitalOutput()   do { TRISBbits.TRISB0 = 0; } while(0)
#define CAJON_SetPullup()      do { WPUBbits.WPUB0 = 1; } while(0)
#define CAJON_ResetPullup()    do { WPUBbits.WPUB0 = 0; } while(0)
#define CAJON_SetAnalogMode()  do { ANSELBbits.ANSB0 = 1; } while(0)
#define CAJON_SetDigitalMode() do { ANSELBbits.ANSB0 = 0; } while(0)

// get/set LTest aliases
#define LTest_TRIS               TRISBbits.TRISB6
#define LTest_LAT                LATBbits.LATB6
#define LTest_PORT               PORTBbits.RB6
#define LTest_WPU                WPUBbits.WPUB6
#define LTest_SetHigh()            do { LATBbits.LATB6 = 1; } while(0)
#define LTest_SetLow()             do { LATBbits.LATB6 = 0; } while(0)
#define LTest_Toggle()             do { LATBbits.LATB6 = ~LATBbits.LATB6; } while(0)
#define LTest_GetValue()           PORTBbits.RB6
#define LTest_SetDigitalInput()    do { TRISBbits.TRISB6 = 1; } while(0)
#define LTest_SetDigitalOutput()   do { TRISBbits.TRISB6 = 0; } while(0)
#define LTest_SetPullup()      do { WPUBbits.WPUB6 = 1; } while(0)
#define LTest_ResetPullup()    do { WPUBbits.WPUB6 = 0; } while(0)

// get/set RC0 procedures
#define RC0_SetHigh()    do { LATCbits.LATC0 = 1; } while(0)
#define RC0_SetLow()   do { LATCbits.LATC0 = 0; } while(0)
#define RC0_Toggle()   do { LATCbits.LATC0 = ~LATCbits.LATC0; } while(0)
#define RC0_GetValue()         PORTCbits.RC0
#define RC0_SetDigitalInput()   do { TRISCbits.TRISC0 = 1; } while(0)
#define RC0_SetDigitalOutput()  do { TRISCbits.TRISC0 = 0; } while(0)

// get/set RC1 procedures
#define RC1_SetHigh()    do { LATCbits.LATC1 = 1; } while(0)
#define RC1_SetLow()   do { LATCbits.LATC1 = 0; } while(0)
#define RC1_Toggle()   do { LATCbits.LATC1 = ~LATCbits.LATC1; } while(0)
#define RC1_GetValue()         PORTCbits.RC1
#define RC1_SetDigitalInput()   do { TRISCbits.TRISC1 = 1; } while(0)
#define RC1_SetDigitalOutput()  do { TRISCbits.TRISC1 = 0; } while(0)

// get/set RC2 procedures
#define RC2_SetHigh()    do { LATCbits.LATC2 = 1; } while(0)
#define RC2_SetLow()   do { LATCbits.LATC2 = 0; } while(0)
#define RC2_Toggle()   do { LATCbits.LATC2 = ~LATCbits.LATC2; } while(0)
#define RC2_GetValue()         PORTCbits.RC2
#define RC2_SetDigitalInput()   do { TRISCbits.TRISC2 = 1; } while(0)
#define RC2_SetDigitalOutput()  do { TRISCbits.TRISC2 = 0; } while(0)
#define RC2_SetAnalogMode() do { ANSELCbits.ANSC2 = 1; } while(0)
#define RC2_SetDigitalMode()do { ANSELCbits.ANSC2 = 0; } while(0)

// get/set RC6 procedures
#define RC6_SetHigh()    do { LATCbits.LATC6 = 1; } while(0)
#define RC6_SetLow()   do { LATCbits.LATC6 = 0; } while(0)
#define RC6_Toggle()   do { LATCbits.LATC6 = ~LATCbits.LATC6; } while(0)
#define RC6_GetValue()         PORTCbits.RC6
#define RC6_SetDigitalInput()   do { TRISCbits.TRISC6 = 1; } while(0)
#define RC6_SetDigitalOutput()  do { TRISCbits.TRISC6 = 0; } while(0)
#define RC6_SetAnalogMode() do { ANSELCbits.ANSC6 = 1; } while(0)
#define RC6_SetDigitalMode()do { ANSELCbits.ANSC6 = 0; } while(0)

// get/set RC7 procedures
#define RC7_SetHigh()    do { LATCbits.LATC7 = 1; } while(0)
#define RC7_SetLow()   do { LATCbits.LATC7 = 0; } while(0)
#define RC7_Toggle()   do { LATCbits.LATC7 = ~LATCbits.LATC7; } while(0)
#define RC7_GetValue()         PORTCbits.RC7
#define RC7_SetDigitalInput()   do { TRISCbits.TRISC7 = 1; } while(0)
#define RC7_SetDigitalOutput()  do { TRISCbits.TRISC7 = 0; } while(0)
#define RC7_SetAnalogMode() do { ANSELCbits.ANSC7 = 1; } while(0)
#define RC7_SetDigitalMode()do { ANSELCbits.ANSC7 = 0; } while(0)

// get/set RD5 procedures
#define RD5_SetHigh()    do { LATDbits.LATD5 = 1; } while(0)
#define RD5_SetLow()   do { LATDbits.LATD5 = 0; } while(0)
#define RD5_Toggle()   do { LATDbits.LATD5 = ~LATDbits.LATD5; } while(0)
#define RD5_GetValue()         PORTDbits.RD5
#define RD5_SetDigitalInput()   do { TRISDbits.TRISD5 = 1; } while(0)
#define RD5_SetDigitalOutput()  do { TRISDbits.TRISD5 = 0; } while(0)
#define RD5_SetAnalogMode() do { ANSELDbits.ANSD5 = 1; } while(0)
#define RD5_SetDigitalMode()do { ANSELDbits.ANSD5 = 0; } while(0)

// get/set FCMOTREF aliases
#define FCMOTREF_TRIS               TRISEbits.TRISE2
#define FCMOTREF_LAT                LATEbits.LATE2
#define FCMOTREF_PORT               PORTEbits.RE2
#define FCMOTREF_ANS                ANSELEbits.ANSE2
#define FCMOTREF_SetHigh()            do { LATEbits.LATE2 = 1; } while(0)
#define FCMOTREF_SetLow()             do { LATEbits.LATE2 = 0; } while(0)
#define FCMOTREF_Toggle()             do { LATEbits.LATE2 = ~LATEbits.LATE2; } while(0)
#define FCMOTREF_GetValue()           PORTEbits.RE2
#define FCMOTREF_SetDigitalInput()    do { TRISEbits.TRISE2 = 1; } while(0)
#define FCMOTREF_SetDigitalOutput()   do { TRISEbits.TRISE2 = 0; } while(0)
#define FCMOTREF_SetAnalogMode()  do { ANSELEbits.ANSE2 = 1; } while(0)
#define FCMOTREF_SetDigitalMode() do { ANSELEbits.ANSE2 = 0; } while(0)

/**
   @Param
    none
   @Returns
    none
   @Description
    GPIO and peripheral I/O initialization
   @Example
    PIN_MANAGER_Initialize();
 */
void PIN_MANAGER_Initialize (void);

/**
 * @Param
    none
 * @Returns
    none
 * @Description
    Interrupt on Change Handling routine
 * @Example
    PIN_MANAGER_IOC();
 */
void PIN_MANAGER_IOC(void);



#endif // PIN_MANAGER_H
/**
 End of File
*/
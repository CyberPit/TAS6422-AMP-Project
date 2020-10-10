/**
  @Generated Pin Manager Header File

  @Company:
    Microchip Technology Inc.

  @File Name:
    pin_manager.h

  @Summary:
    This is the Pin Manager file generated using PIC10 / PIC12 / PIC16 / PIC18 MCUs

  @Description
    This header file provides APIs for driver for .
    Generation Information :
        Product Revision  :  PIC10 / PIC12 / PIC16 / PIC18 MCUs - 1.81.3
        Device            :  PIC16F18346
        Driver Version    :  2.11
    The generated drivers are tested against the following:
        Compiler          :  XC8 2.20 and above
        MPLAB 	          :  MPLAB X 5.40	
*/

/*
    (c) 2018 Microchip Technology Inc. and its subsidiaries. 
    
    Subject to your compliance with these terms, you may use Microchip software and any 
    derivatives exclusively with Microchip products. It is your responsibility to comply with third party 
    license terms applicable to your use of third party software (including open source software) that 
    may accompany Microchip software.
    
    THIS SOFTWARE IS SUPPLIED BY MICROCHIP "AS IS". NO WARRANTIES, WHETHER 
    EXPRESS, IMPLIED OR STATUTORY, APPLY TO THIS SOFTWARE, INCLUDING ANY 
    IMPLIED WARRANTIES OF NON-INFRINGEMENT, MERCHANTABILITY, AND FITNESS 
    FOR A PARTICULAR PURPOSE.
    
    IN NO EVENT WILL MICROCHIP BE LIABLE FOR ANY INDIRECT, SPECIAL, PUNITIVE, 
    INCIDENTAL OR CONSEQUENTIAL LOSS, DAMAGE, COST OR EXPENSE OF ANY KIND 
    WHATSOEVER RELATED TO THE SOFTWARE, HOWEVER CAUSED, EVEN IF MICROCHIP 
    HAS BEEN ADVISED OF THE POSSIBILITY OR THE DAMAGES ARE FORESEEABLE. TO 
    THE FULLEST EXTENT ALLOWED BY LAW, MICROCHIP'S TOTAL LIABILITY ON ALL 
    CLAIMS IN ANY WAY RELATED TO THIS SOFTWARE WILL NOT EXCEED THE AMOUNT 
    OF FEES, IF ANY, THAT YOU HAVE PAID DIRECTLY TO MICROCHIP FOR THIS 
    SOFTWARE.
*/

#ifndef PIN_MANAGER_H
#define PIN_MANAGER_H

/**
  Section: Included Files
*/

#include <xc.h>

#define INPUT   1
#define OUTPUT  0

#define HIGH    1
#define LOW     0

#define ANALOG      1
#define DIGITAL     0

#define PULL_UP_ENABLED      1
#define PULL_UP_DISABLED     0

// get/set DIG_1 aliases
#define DIG_1_TRIS                 TRISAbits.TRISA0
#define DIG_1_LAT                  LATAbits.LATA0
#define DIG_1_PORT                 PORTAbits.RA0
#define DIG_1_WPU                  WPUAbits.WPUA0
#define DIG_1_OD                   ODCONAbits.ODCA0
#define DIG_1_ANS                  ANSELAbits.ANSA0
#define DIG_1_SetHigh()            do { LATAbits.LATA0 = 1; } while(0)
#define DIG_1_SetLow()             do { LATAbits.LATA0 = 0; } while(0)
#define DIG_1_Toggle()             do { LATAbits.LATA0 = ~LATAbits.LATA0; } while(0)
#define DIG_1_GetValue()           PORTAbits.RA0
#define DIG_1_SetDigitalInput()    do { TRISAbits.TRISA0 = 1; } while(0)
#define DIG_1_SetDigitalOutput()   do { TRISAbits.TRISA0 = 0; } while(0)
#define DIG_1_SetPullup()          do { WPUAbits.WPUA0 = 1; } while(0)
#define DIG_1_ResetPullup()        do { WPUAbits.WPUA0 = 0; } while(0)
#define DIG_1_SetPushPull()        do { ODCONAbits.ODCA0 = 0; } while(0)
#define DIG_1_SetOpenDrain()       do { ODCONAbits.ODCA0 = 1; } while(0)
#define DIG_1_SetAnalogMode()      do { ANSELAbits.ANSA0 = 1; } while(0)
#define DIG_1_SetDigitalMode()     do { ANSELAbits.ANSA0 = 0; } while(0)

// get/set DIG_2 aliases
#define DIG_2_TRIS                 TRISAbits.TRISA1
#define DIG_2_LAT                  LATAbits.LATA1
#define DIG_2_PORT                 PORTAbits.RA1
#define DIG_2_WPU                  WPUAbits.WPUA1
#define DIG_2_OD                   ODCONAbits.ODCA1
#define DIG_2_ANS                  ANSELAbits.ANSA1
#define DIG_2_SetHigh()            do { LATAbits.LATA1 = 1; } while(0)
#define DIG_2_SetLow()             do { LATAbits.LATA1 = 0; } while(0)
#define DIG_2_Toggle()             do { LATAbits.LATA1 = ~LATAbits.LATA1; } while(0)
#define DIG_2_GetValue()           PORTAbits.RA1
#define DIG_2_SetDigitalInput()    do { TRISAbits.TRISA1 = 1; } while(0)
#define DIG_2_SetDigitalOutput()   do { TRISAbits.TRISA1 = 0; } while(0)
#define DIG_2_SetPullup()          do { WPUAbits.WPUA1 = 1; } while(0)
#define DIG_2_ResetPullup()        do { WPUAbits.WPUA1 = 0; } while(0)
#define DIG_2_SetPushPull()        do { ODCONAbits.ODCA1 = 0; } while(0)
#define DIG_2_SetOpenDrain()       do { ODCONAbits.ODCA1 = 1; } while(0)
#define DIG_2_SetAnalogMode()      do { ANSELAbits.ANSA1 = 1; } while(0)
#define DIG_2_SetDigitalMode()     do { ANSELAbits.ANSA1 = 0; } while(0)

// get/set DIG_3 aliases
#define DIG_3_TRIS                 TRISAbits.TRISA2
#define DIG_3_LAT                  LATAbits.LATA2
#define DIG_3_PORT                 PORTAbits.RA2
#define DIG_3_WPU                  WPUAbits.WPUA2
#define DIG_3_OD                   ODCONAbits.ODCA2
#define DIG_3_ANS                  ANSELAbits.ANSA2
#define DIG_3_SetHigh()            do { LATAbits.LATA2 = 1; } while(0)
#define DIG_3_SetLow()             do { LATAbits.LATA2 = 0; } while(0)
#define DIG_3_Toggle()             do { LATAbits.LATA2 = ~LATAbits.LATA2; } while(0)
#define DIG_3_GetValue()           PORTAbits.RA2
#define DIG_3_SetDigitalInput()    do { TRISAbits.TRISA2 = 1; } while(0)
#define DIG_3_SetDigitalOutput()   do { TRISAbits.TRISA2 = 0; } while(0)
#define DIG_3_SetPullup()          do { WPUAbits.WPUA2 = 1; } while(0)
#define DIG_3_ResetPullup()        do { WPUAbits.WPUA2 = 0; } while(0)
#define DIG_3_SetPushPull()        do { ODCONAbits.ODCA2 = 0; } while(0)
#define DIG_3_SetOpenDrain()       do { ODCONAbits.ODCA2 = 1; } while(0)
#define DIG_3_SetAnalogMode()      do { ANSELAbits.ANSA2 = 1; } while(0)
#define DIG_3_SetDigitalMode()     do { ANSELAbits.ANSA2 = 0; } while(0)


// get/set MODEn aliases
#define MODEn_TRIS                 TRISAbits.TRISA3
#define MODEn_PORT                 PORTAbits.RA3
#define MODEn_WPU                  WPUAbits.WPUA3
#define MODEn_GetValue()           PORTAbits.RA3
#define MODEn_SetDigitalInput()    do { TRISAbits.TRISA3 = 1; } while(0)
#define MODEn_SetDigitalOutput()   do { TRISAbits.TRISA3 = 0; } while(0)
#define MODEn_SetPullup()          do { WPUAbits.WPUA3 = 1; } while(0)
#define MODEn_ResetPullup()        do { WPUAbits.WPUA3 = 0; } while(0)


// get/set RE_A aliases
#define RE_A_TRIS                 TRISAbits.TRISA4
#define RE_A_LAT                  LATAbits.LATA4
#define RE_A_PORT                 PORTAbits.RA4
#define RE_A_WPU                  WPUAbits.WPUA4
#define RE_A_OD                   ODCONAbits.ODCA4
#define RE_A_ANS                  ANSELAbits.ANSA4
#define RE_A_SetHigh()            do { LATAbits.LATA4 = 1; } while(0)
#define RE_A_SetLow()             do { LATAbits.LATA4 = 0; } while(0)
#define RE_A_Toggle()             do { LATAbits.LATA4 = ~LATAbits.LATA4; } while(0)
#define RE_A_GetValue()           PORTAbits.RA4
#define RE_A_SetDigitalInput()    do { TRISAbits.TRISA4 = 1; } while(0)
#define RE_A_SetDigitalOutput()   do { TRISAbits.TRISA4 = 0; } while(0)
#define RE_A_SetPullup()          do { WPUAbits.WPUA4 = 1; } while(0)
#define RE_A_ResetPullup()        do { WPUAbits.WPUA4 = 0; } while(0)
#define RE_A_SetPushPull()        do { ODCONAbits.ODCA4 = 0; } while(0)
#define RE_A_SetOpenDrain()       do { ODCONAbits.ODCA4 = 1; } while(0)
#define RE_A_SetAnalogMode()      do { ANSELAbits.ANSA4 = 1; } while(0)
#define RE_A_SetDigitalMode()     do { ANSELAbits.ANSA4 = 0; } while(0)

// get/set RE_B aliases
#define RE_B_TRIS                 TRISAbits.TRISA5
#define RE_B_LAT                  LATAbits.LATA5
#define RE_B_PORT                 PORTAbits.RA5
#define RE_B_WPU                  WPUAbits.WPUA5
#define RE_B_OD                   ODCONAbits.ODCA5
#define RE_B_ANS                  ANSELAbits.ANSA5
#define RE_B_SetHigh()            do { LATAbits.LATA5 = 1; } while(0)
#define RE_B_SetLow()             do { LATAbits.LATA5 = 0; } while(0)
#define RE_B_Toggle()             do { LATAbits.LATA5 = ~LATAbits.LATA5; } while(0)
#define RE_B_GetValue()           PORTAbits.RA5
#define RE_B_SetDigitalInput()    do { TRISAbits.TRISA5 = 1; } while(0)
#define RE_B_SetDigitalOutput()   do { TRISAbits.TRISA5 = 0; } while(0)
#define RE_B_SetPullup()          do { WPUAbits.WPUA5 = 1; } while(0)
#define RE_B_ResetPullup()        do { WPUAbits.WPUA5 = 0; } while(0)
#define RE_B_SetPushPull()        do { ODCONAbits.ODCA5 = 0; } while(0)
#define RE_B_SetOpenDrain()       do { ODCONAbits.ODCA5 = 1; } while(0)
#define RE_B_SetAnalogMode()      do { ANSELAbits.ANSA5 = 1; } while(0)
#define RE_B_SetDigitalMode()     do { ANSELAbits.ANSA5 = 0; } while(0)

// get/set RB4 procedures
#define RB4_SetHigh()            do { LATBbits.LATB4 = 1; } while(0)
#define RB4_SetLow()             do { LATBbits.LATB4 = 0; } while(0)
#define RB4_Toggle()             do { LATBbits.LATB4 = ~LATBbits.LATB4; } while(0)
#define RB4_GetValue()              PORTBbits.RB4
#define RB4_SetDigitalInput()    do { TRISBbits.TRISB4 = 1; } while(0)
#define RB4_SetDigitalOutput()   do { TRISBbits.TRISB4 = 0; } while(0)
#define RB4_SetPullup()             do { WPUBbits.WPUB4 = 1; } while(0)
#define RB4_ResetPullup()           do { WPUBbits.WPUB4 = 0; } while(0)
#define RB4_SetAnalogMode()         do { ANSELBbits.ANSB4 = 1; } while(0)
#define RB4_SetDigitalMode()        do { ANSELBbits.ANSB4 = 0; } while(0)

// get/set IRQ aliases
#define IRQ_TRIS                 TRISBbits.TRISB5
#define IRQ_LAT                  LATBbits.LATB5
#define IRQ_PORT                 PORTBbits.RB5
#define IRQ_WPU                  WPUBbits.WPUB5
#define IRQ_OD                   ODCONBbits.ODCB5
#define IRQ_ANS                  ANSELBbits.ANSB5
#define IRQ_SetHigh()            do { LATBbits.LATB5 = 1; } while(0)
#define IRQ_SetLow()             do { LATBbits.LATB5 = 0; } while(0)
#define IRQ_Toggle()             do { LATBbits.LATB5 = ~LATBbits.LATB5; } while(0)
#define IRQ_GetValue()           PORTBbits.RB5
#define IRQ_SetDigitalInput()    do { TRISBbits.TRISB5 = 1; } while(0)
#define IRQ_SetDigitalOutput()   do { TRISBbits.TRISB5 = 0; } while(0)
#define IRQ_SetPullup()          do { WPUBbits.WPUB5 = 1; } while(0)
#define IRQ_ResetPullup()        do { WPUBbits.WPUB5 = 0; } while(0)
#define IRQ_SetPushPull()        do { ODCONBbits.ODCB5 = 0; } while(0)
#define IRQ_SetOpenDrain()       do { ODCONBbits.ODCB5 = 1; } while(0)
#define IRQ_SetAnalogMode()      do { ANSELBbits.ANSB5 = 1; } while(0)
#define IRQ_SetDigitalMode()     do { ANSELBbits.ANSB5 = 0; } while(0)

// get/set RB6 procedures
#define RB6_SetHigh()            do { LATBbits.LATB6 = 1; } while(0)
#define RB6_SetLow()             do { LATBbits.LATB6 = 0; } while(0)
#define RB6_Toggle()             do { LATBbits.LATB6 = ~LATBbits.LATB6; } while(0)
#define RB6_GetValue()              PORTBbits.RB6
#define RB6_SetDigitalInput()    do { TRISBbits.TRISB6 = 1; } while(0)
#define RB6_SetDigitalOutput()   do { TRISBbits.TRISB6 = 0; } while(0)
#define RB6_SetPullup()             do { WPUBbits.WPUB6 = 1; } while(0)
#define RB6_ResetPullup()           do { WPUBbits.WPUB6 = 0; } while(0)
#define RB6_SetAnalogMode()         do { ANSELBbits.ANSB6 = 1; } while(0)
#define RB6_SetDigitalMode()        do { ANSELBbits.ANSB6 = 0; } while(0)

// get/set MUTEn aliases
#define MUTEn_TRIS                 TRISBbits.TRISB7
#define MUTEn_LAT                  LATBbits.LATB7
#define MUTEn_PORT                 PORTBbits.RB7
#define MUTEn_WPU                  WPUBbits.WPUB7
#define MUTEn_OD                   ODCONBbits.ODCB7
#define MUTEn_ANS                  ANSELBbits.ANSB7
#define MUTEn_SetHigh()            do { LATBbits.LATB7 = 1; } while(0)
#define MUTEn_SetLow()             do { LATBbits.LATB7 = 0; } while(0)
#define MUTEn_Toggle()             do { LATBbits.LATB7 = ~LATBbits.LATB7; } while(0)
#define MUTEn_GetValue()           PORTBbits.RB7
#define MUTEn_SetDigitalInput()    do { TRISBbits.TRISB7 = 1; } while(0)
#define MUTEn_SetDigitalOutput()   do { TRISBbits.TRISB7 = 0; } while(0)
#define MUTEn_SetPullup()          do { WPUBbits.WPUB7 = 1; } while(0)
#define MUTEn_ResetPullup()        do { WPUBbits.WPUB7 = 0; } while(0)
#define MUTEn_SetPushPull()        do { ODCONBbits.ODCB7 = 0; } while(0)
#define MUTEn_SetOpenDrain()       do { ODCONBbits.ODCB7 = 1; } while(0)
#define MUTEn_SetAnalogMode()      do { ANSELBbits.ANSB7 = 1; } while(0)
#define MUTEn_SetDigitalMode()     do { ANSELBbits.ANSB7 = 0; } while(0)

// get/set SEG_A aliases
#define SEG_A_TRIS                 TRISCbits.TRISC0
#define SEG_A_LAT                  LATCbits.LATC0
#define SEG_A_PORT                 PORTCbits.RC0
#define SEG_A_WPU                  WPUCbits.WPUC0
#define SEG_A_OD                   ODCONCbits.ODCC0
#define SEG_A_ANS                  ANSELCbits.ANSC0
#define SEG_A_SetHigh()            do { LATCbits.LATC0 = 1; } while(0)
#define SEG_A_SetLow()             do { LATCbits.LATC0 = 0; } while(0)
#define SEG_A_Toggle()             do { LATCbits.LATC0 = ~LATCbits.LATC0; } while(0)
#define SEG_A_GetValue()           PORTCbits.RC0
#define SEG_A_SetDigitalInput()    do { TRISCbits.TRISC0 = 1; } while(0)
#define SEG_A_SetDigitalOutput()   do { TRISCbits.TRISC0 = 0; } while(0)
#define SEG_A_SetPullup()          do { WPUCbits.WPUC0 = 1; } while(0)
#define SEG_A_ResetPullup()        do { WPUCbits.WPUC0 = 0; } while(0)
#define SEG_A_SetPushPull()        do { ODCONCbits.ODCC0 = 0; } while(0)
#define SEG_A_SetOpenDrain()       do { ODCONCbits.ODCC0 = 1; } while(0)
#define SEG_A_SetAnalogMode()      do { ANSELCbits.ANSC0 = 1; } while(0)
#define SEG_A_SetDigitalMode()     do { ANSELCbits.ANSC0 = 0; } while(0)

// get/set SEG_B aliases
#define SEG_B_TRIS                 TRISCbits.TRISC1
#define SEG_B_LAT                  LATCbits.LATC1
#define SEG_B_PORT                 PORTCbits.RC1
#define SEG_B_WPU                  WPUCbits.WPUC1
#define SEG_B_OD                   ODCONCbits.ODCC1
#define SEG_B_ANS                  ANSELCbits.ANSC1
#define SEG_B_SetHigh()            do { LATCbits.LATC1 = 1; } while(0)
#define SEG_B_SetLow()             do { LATCbits.LATC1 = 0; } while(0)
#define SEG_B_Toggle()             do { LATCbits.LATC1 = ~LATCbits.LATC1; } while(0)
#define SEG_B_GetValue()           PORTCbits.RC1
#define SEG_B_SetDigitalInput()    do { TRISCbits.TRISC1 = 1; } while(0)
#define SEG_B_SetDigitalOutput()   do { TRISCbits.TRISC1 = 0; } while(0)
#define SEG_B_SetPullup()          do { WPUCbits.WPUC1 = 1; } while(0)
#define SEG_B_ResetPullup()        do { WPUCbits.WPUC1 = 0; } while(0)
#define SEG_B_SetPushPull()        do { ODCONCbits.ODCC1 = 0; } while(0)
#define SEG_B_SetOpenDrain()       do { ODCONCbits.ODCC1 = 1; } while(0)
#define SEG_B_SetAnalogMode()      do { ANSELCbits.ANSC1 = 1; } while(0)
#define SEG_B_SetDigitalMode()     do { ANSELCbits.ANSC1 = 0; } while(0)

// get/set SEG_C aliases
#define SEG_C_TRIS                 TRISCbits.TRISC2
#define SEG_C_LAT                  LATCbits.LATC2
#define SEG_C_PORT                 PORTCbits.RC2
#define SEG_C_WPU                  WPUCbits.WPUC2
#define SEG_C_OD                   ODCONCbits.ODCC2
#define SEG_C_ANS                  ANSELCbits.ANSC2
#define SEG_C_SetHigh()            do { LATCbits.LATC2 = 1; } while(0)
#define SEG_C_SetLow()             do { LATCbits.LATC2 = 0; } while(0)
#define SEG_C_Toggle()             do { LATCbits.LATC2 = ~LATCbits.LATC2; } while(0)
#define SEG_C_GetValue()           PORTCbits.RC2
#define SEG_C_SetDigitalInput()    do { TRISCbits.TRISC2 = 1; } while(0)
#define SEG_C_SetDigitalOutput()   do { TRISCbits.TRISC2 = 0; } while(0)
#define SEG_C_SetPullup()          do { WPUCbits.WPUC2 = 1; } while(0)
#define SEG_C_ResetPullup()        do { WPUCbits.WPUC2 = 0; } while(0)
#define SEG_C_SetPushPull()        do { ODCONCbits.ODCC2 = 0; } while(0)
#define SEG_C_SetOpenDrain()       do { ODCONCbits.ODCC2 = 1; } while(0)
#define SEG_C_SetAnalogMode()      do { ANSELCbits.ANSC2 = 1; } while(0)
#define SEG_C_SetDigitalMode()     do { ANSELCbits.ANSC2 = 0; } while(0)

// get/set SEG_D aliases
#define SEG_D_TRIS                 TRISCbits.TRISC3
#define SEG_D_LAT                  LATCbits.LATC3
#define SEG_D_PORT                 PORTCbits.RC3
#define SEG_D_WPU                  WPUCbits.WPUC3
#define SEG_D_OD                   ODCONCbits.ODCC3
#define SEG_D_ANS                  ANSELCbits.ANSC3
#define SEG_D_SetHigh()            do { LATCbits.LATC3 = 1; } while(0)
#define SEG_D_SetLow()             do { LATCbits.LATC3 = 0; } while(0)
#define SEG_D_Toggle()             do { LATCbits.LATC3 = ~LATCbits.LATC3; } while(0)
#define SEG_D_GetValue()           PORTCbits.RC3
#define SEG_D_SetDigitalInput()    do { TRISCbits.TRISC3 = 1; } while(0)
#define SEG_D_SetDigitalOutput()   do { TRISCbits.TRISC3 = 0; } while(0)
#define SEG_D_SetPullup()          do { WPUCbits.WPUC3 = 1; } while(0)
#define SEG_D_ResetPullup()        do { WPUCbits.WPUC3 = 0; } while(0)
#define SEG_D_SetPushPull()        do { ODCONCbits.ODCC3 = 0; } while(0)
#define SEG_D_SetOpenDrain()       do { ODCONCbits.ODCC3 = 1; } while(0)
#define SEG_D_SetAnalogMode()      do { ANSELCbits.ANSC3 = 1; } while(0)
#define SEG_D_SetDigitalMode()     do { ANSELCbits.ANSC3 = 0; } while(0)

// get/set SEG_E aliases
#define SEG_E_TRIS                 TRISCbits.TRISC4
#define SEG_E_LAT                  LATCbits.LATC4
#define SEG_E_PORT                 PORTCbits.RC4
#define SEG_E_WPU                  WPUCbits.WPUC4
#define SEG_E_OD                   ODCONCbits.ODCC4
#define SEG_E_ANS                  ANSELCbits.ANSC4
#define SEG_E_SetHigh()            do { LATCbits.LATC4 = 1; } while(0)
#define SEG_E_SetLow()             do { LATCbits.LATC4 = 0; } while(0)
#define SEG_E_Toggle()             do { LATCbits.LATC4 = ~LATCbits.LATC4; } while(0)
#define SEG_E_GetValue()           PORTCbits.RC4
#define SEG_E_SetDigitalInput()    do { TRISCbits.TRISC4 = 1; } while(0)
#define SEG_E_SetDigitalOutput()   do { TRISCbits.TRISC4 = 0; } while(0)
#define SEG_E_SetPullup()          do { WPUCbits.WPUC4 = 1; } while(0)
#define SEG_E_ResetPullup()        do { WPUCbits.WPUC4 = 0; } while(0)
#define SEG_E_SetPushPull()        do { ODCONCbits.ODCC4 = 0; } while(0)
#define SEG_E_SetOpenDrain()       do { ODCONCbits.ODCC4 = 1; } while(0)
#define SEG_E_SetAnalogMode()      do { ANSELCbits.ANSC4 = 1; } while(0)
#define SEG_E_SetDigitalMode()     do { ANSELCbits.ANSC4 = 0; } while(0)

// get/set SEG_F aliases
#define SEG_F_TRIS                 TRISCbits.TRISC5
#define SEG_F_LAT                  LATCbits.LATC5
#define SEG_F_PORT                 PORTCbits.RC5
#define SEG_F_WPU                  WPUCbits.WPUC5
#define SEG_F_OD                   ODCONCbits.ODCC5
#define SEG_F_ANS                  ANSELCbits.ANSC5
#define SEG_F_SetHigh()            do { LATCbits.LATC5 = 1; } while(0)
#define SEG_F_SetLow()             do { LATCbits.LATC5 = 0; } while(0)
#define SEG_F_Toggle()             do { LATCbits.LATC5 = ~LATCbits.LATC5; } while(0)
#define SEG_F_GetValue()           PORTCbits.RC5
#define SEG_F_SetDigitalInput()    do { TRISCbits.TRISC5 = 1; } while(0)
#define SEG_F_SetDigitalOutput()   do { TRISCbits.TRISC5 = 0; } while(0)
#define SEG_F_SetPullup()          do { WPUCbits.WPUC5 = 1; } while(0)
#define SEG_F_ResetPullup()        do { WPUCbits.WPUC5 = 0; } while(0)
#define SEG_F_SetPushPull()        do { ODCONCbits.ODCC5 = 0; } while(0)
#define SEG_F_SetOpenDrain()       do { ODCONCbits.ODCC5 = 1; } while(0)
#define SEG_F_SetAnalogMode()      do { ANSELCbits.ANSC5 = 1; } while(0)
#define SEG_F_SetDigitalMode()     do { ANSELCbits.ANSC5 = 0; } while(0)

// get/set SEG_G aliases
#define SEG_G_TRIS                 TRISCbits.TRISC6
#define SEG_G_LAT                  LATCbits.LATC6
#define SEG_G_PORT                 PORTCbits.RC6
#define SEG_G_WPU                  WPUCbits.WPUC6
#define SEG_G_OD                   ODCONCbits.ODCC6
#define SEG_G_ANS                  ANSELCbits.ANSC6
#define SEG_G_SetHigh()            do { LATCbits.LATC6 = 1; } while(0)
#define SEG_G_SetLow()             do { LATCbits.LATC6 = 0; } while(0)
#define SEG_G_Toggle()             do { LATCbits.LATC6 = ~LATCbits.LATC6; } while(0)
#define SEG_G_GetValue()           PORTCbits.RC6
#define SEG_G_SetDigitalInput()    do { TRISCbits.TRISC6 = 1; } while(0)
#define SEG_G_SetDigitalOutput()   do { TRISCbits.TRISC6 = 0; } while(0)
#define SEG_G_SetPullup()          do { WPUCbits.WPUC6 = 1; } while(0)
#define SEG_G_ResetPullup()        do { WPUCbits.WPUC6 = 0; } while(0)
#define SEG_G_SetPushPull()        do { ODCONCbits.ODCC6 = 0; } while(0)
#define SEG_G_SetOpenDrain()       do { ODCONCbits.ODCC6 = 1; } while(0)
#define SEG_G_SetAnalogMode()      do { ANSELCbits.ANSC6 = 1; } while(0)
#define SEG_G_SetDigitalMode()     do { ANSELCbits.ANSC6 = 0; } while(0)

// get/set SEG_DP aliases
#define SEG_DP_TRIS                 TRISCbits.TRISC7
#define SEG_DP_LAT                  LATCbits.LATC7
#define SEG_DP_PORT                 PORTCbits.RC7
#define SEG_DP_WPU                  WPUCbits.WPUC7
#define SEG_DP_OD                   ODCONCbits.ODCC7
#define SEG_DP_ANS                  ANSELCbits.ANSC7
#define SEG_DP_SetHigh()            do { LATCbits.LATC7 = 1; } while(0)
#define SEG_DP_SetLow()             do { LATCbits.LATC7 = 0; } while(0)
#define SEG_DP_Toggle()             do { LATCbits.LATC7 = ~LATCbits.LATC7; } while(0)
#define SEG_DP_GetValue()           PORTCbits.RC7
#define SEG_DP_SetDigitalInput()    do { TRISCbits.TRISC7 = 1; } while(0)
#define SEG_DP_SetDigitalOutput()   do { TRISCbits.TRISC7 = 0; } while(0)
#define SEG_DP_SetPullup()          do { WPUCbits.WPUC7 = 1; } while(0)
#define SEG_DP_ResetPullup()        do { WPUCbits.WPUC7 = 0; } while(0)
#define SEG_DP_SetPushPull()        do { ODCONCbits.ODCC7 = 0; } while(0)
#define SEG_DP_SetOpenDrain()       do { ODCONCbits.ODCC7 = 1; } while(0)
#define SEG_DP_SetAnalogMode()      do { ANSELCbits.ANSC7 = 1; } while(0)
#define SEG_DP_SetDigitalMode()     do { ANSELCbits.ANSC7 = 0; } while(0)

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
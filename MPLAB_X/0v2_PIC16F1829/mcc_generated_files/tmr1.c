/* 
 * (c) CyberPit HILO 2020
 * This software was written for the  PIC16F1829 
 * TAS6422 Amplifier board MCU
 * 
 * Home Page: https://cyberpithilo.web.fc2.com/
 * Project Web Page https://cyberpithilo.web.fc2.com/audio/tas6422amp/index.html
 * GitHub: https://github.com/CyberPit/TAS6422-AMP-Project
 *
 * Included my orignal part of  software are  licensed under a Creative Commons Attribution Share-Alike 4.0 license.
 * This allows for both personal and commercial derivative works, as long as they credit "Designd by CyberPit HILO" 
 * and release their designs under the same license.
 */

/**
  TMR1 Generated Driver File

  @Company
    Microchip Technology Inc.

  @File Name
    tmr1.c

  @Summary
    This is the generated driver implementation file for the TMR1 driver using PIC10 / PIC12 / PIC16 / PIC18 MCUs

  @Description
    This source file provides APIs for TMR1.
    Generation Information :
        Product Revision  :  PIC10 / PIC12 / PIC16 / PIC18 MCUs - 1.81.3
        Device            :  PIC16F1829
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

/**
  Section: Included Files
*/

#include <xc.h>
#include "tmr1.h"
#include "pin_manager.h"


// LED DP Attribute for each digit's dot
static unsigned char led_dot[3] = {DOT_OFF, DOT_OFF, DOT_OFF};
// LED DP blink attribute, if NOT zero each digit  blinks (slowest ==1)
static unsigned char blink_rate[]={0, 0, 0 }; 
// Greeting LED message
static  char ledstr[9]="___\0\0\0\0\0";
static  char ledbuff[4]="___\0";
// Current Roltaty Encoder Position Indicator
static unsigned char     RE_pos;
// Button pushed status flag, if Zero -- NotPushed, None-Zero==HoldDuration
static char button1 = NOT_PUSHED;
// Button push-hold duration counter



const unsigned char font7seg[]=
{
    0xff    //0x20: ' ' as space
,   0xf9   //0x21: '!'
,   0xff    //0x22: '"'
,   0xff    //0x23: '#'
,   0xff    //0x24: '$'
,   0x9c    //0x25: '%'
,   0xff    //0x26: '&'
,   0xff    //0x27: ''
,   0xff    //0x28: '('
,   0xff    //0x29: ')'
,   0xff    //0x2A: '*'
,   0xff    //0x2B: '+'
,   0xff    //0x2C: ','
,   0xbf    //0x2D: '-'
,   0x7f    //0x2E: '.'
,   0xcf    //0x2F: '/'
   
,   0xc0    //0x30: '0'
,   0xf9    //0x31: '1'
,   0xa4    //0x32: '2'
,   0xb0    //0x33: '3'
,   0x99    //0x34: '4'
,   0x92    //0x35: '5'
,   0x82   //0x36: '6'
,   0xf8    //0x37: '7'
,   0x80    //0x38: '8'
,   0x90    //0x39: '9'
,   0xf6    //0x3A: ':'
,   0xb6    //0x3B: ';'
,   0xff    //0x3C: '<'
,   0xb7    //0x3D: '='
,   0xff    //0x3E: '>'
,   0xff    //0x3F: '?'
            
,   0xa0    //0x40: '@'
,   0x88    //0x41: 'A'
,   0x83    //0x42: 'B'
,   0xc6    //0x43: 'C'
,   0xa1    //0x44: 'D'
,   0x86    //0x45: 'E'
,   0x8e    //0x46 'F'
,   0xc2    //0x47 'G'
,   0x89    //0x48 'H'
,   0xcf    //0x49: 'I'
,   0xe1   //0x4A: 'J'
,   0x87    //0x4B: 'K'
,   0xc7    //0x4C: 'L'
,   0xc8    //0x4D: 'M'
,   0xab    //0x4E: 'N'
,   0xc0    //0x4F: 'O'
            
,   0x8c    //0x50: 'P'
,   0x98    //0x51: 'Q'
,   0x88    //0x52: 'R'
,   0x92    //0x53: 'S'
,   0xce    //0x54: 'T'
,   0xc1    //0x55: 'U'
,   0xc1    //0x56: 'V'
,   0x81   //0x57: 'W'
,   0x89    //0x58: 'X'
,   0x91    //0x59: 'Y'
,   0xe4    //0x5A: 'Z'
,   0xc6    //0x5B: '['
,   0xff    //0x5C: '\'
,   0xf0    //0x5D: ']'
,   0xbc    //0x5E: '^'
,   0xf7    //0x5F: '_'
            
,   0xde    //0x60: '''
,   0xa0    //0x61: 'a'
,   0x83    //0x62: 'b'
,   0xa7    //0x63: 'c'
,   0xa1    //0x64: 'd'
,   0x86    //0x65: 'e'
,   0x8e    //0x66: 'f'
,   0x90    //0x67: 'g'
,   0x8b    //0x68: 'h'
,   0xfb    //0x69: 'i'
,   0xf1   //0x6A: 'j'
,   0x87    //0x6B: 'k'
,   0xc7    //0x6C: 'l'
,   0xc8    //0x6D: 'm'
,   0xab    //0x6E: 'n'
,   0xa3    //0x6F: 'o'
            
,   0x8c    //0x70: 'p'
,   0x98    //0x71: 'q'
,   0xaf    //0x72: 'r'
,   0x92    //0x73: 's'
,   0x87    //0x74: 't'
,   0xe3    //0x75: 'u'
,   0xe3    //0x76: 'v'
,   0x81    //0x77: 'w'
,   0x89    //0x78: 'x'
,   0x91    //0x79: 'y'
,   0xe4   //0x7A: 'z'
,   0xff    //0x7B: '{'
,   0xff    //0x7C: '|'
,   0xff    //0x7D: '}'
,   0xfe    //0x7E: '~'          
};

/**
  Section: Global Variables Definitions
*/
volatile uint16_t timer1ReloadVal;
void (*TMR1_InterruptHandler)(void);

/**
  Section: TMR1 APIs
*/

void TMR1_Initialize(void)
{
    //Set the Timer to the options selected in the GUI

    //T1GSS T1G_pin; TMR1GE disabled; T1GTM disabled; T1GPOL low; T1GGO done; T1GSPM disabled; 
    T1GCON = 0x00;

    //TMR1H 11; 
    TMR1H = 0xE0;

    //TMR1L 220; 
    TMR1L = 0xDC;

    // Clearing IF flag before enabling the interrupt.
    PIR1bits.TMR1IF = 0;

    // Load the TMR value to reload variable
    timer1ReloadVal=(uint16_t)((TMR1H << 8) | TMR1L);

    // Enabling TMR1 interrupt.
    PIE1bits.TMR1IE = 1;

    // Set Default Interrupt Handler
    TMR1_SetInterruptHandler(TMR1_DefaultInterruptHandler);

    // T1CKPS 1:1; T1OSCEN disabled; nT1SYNC synchronize; TMR1CS FOSC/4; TMR1ON enabled; 
    T1CON = 0x01;
}

void TMR1_StartTimer(void)
{
    // Start the Timer by writing to TMRxON bit
    T1CONbits.TMR1ON = 1;
}

void TMR1_StopTimer(void)
{
    // Stop the Timer by writing to TMRxON bit
    T1CONbits.TMR1ON = 0;
}



uint16_t TMR1_ReadTimer(void)
{
    uint16_t readVal;
    uint8_t readValHigh;
    uint8_t readValLow;
    
	
    readValLow = TMR1L;
    readValHigh = TMR1H;
    
    readVal = ((uint16_t)readValHigh << 8) | readValLow;

    return readVal;
}

void TMR1_WriteTimer(uint16_t timerVal)
{
    if (T1CONbits.nT1SYNC == 1)
    {
        // Stop the Timer by writing to TMRxON bit
        T1CONbits.TMR1ON = 0;

        // Write to the Timer1 register
        TMR1H = (timerVal >> 8);
        TMR1L = timerVal;

        // Start the Timer after writing to the register
        T1CONbits.TMR1ON =1;
    }
    else
    {
        // Write to the Timer1 register
        TMR1H = (timerVal >> 8);
        TMR1L = timerVal;
    }
}

void TMR1_Reload(void)
{
    TMR1_WriteTimer(timer1ReloadVal);
}

void TMR1_StartSinglePulseAcquisition(void)
{
    T1GCONbits.T1GGO = 1;
}

uint8_t TMR1_CheckGateValueStatus(void)
{
    return (T1GCONbits.T1GVAL);
}

//
// -----Get 7seg LED display data from table array----
// 文字コードに対応した表示データを所得する（ドットは別）
//
unsigned char get7seg_font(char cdata)
{
unsigned char    fontdata;
    
    if (cdata >= 0x20)
        {
        cdata -= 0x20;
        fontdata = font7seg[cdata];
         }
    else         
        fontdata = 0xff;    
return(fontdata);
}



//-----------NonClick Rotary Encoder Rread --------------
// 直前の状況と今回の状況を合わせた16通りの組合せから
// 左右どちらに回転をしたのか判定することができる
// 加速なしの高分解能で戻り値は (-1,0,1) の３通り
//--------------------------------------------------------

signed char readRE(void){
 //const char RE_states[] ={0, 1,-1, 2,-1, 0, 2, 1,-1, 2,-1,1, 2,-1, 1, 0};
 //const char RE_states[] ={0,-1, 1, 0, 1, 0, 0,-1,-1, 0, 0, 1, 0, 1,-1, 0};
// const char RE_states[] ={0,-1, 0, 3, 1, 0, 3, 0, 0, 3, 0, 0, 3, 0, 0, 0};
const signed char RE_states[] =    {0,-1, 0, 5, 1, 0, 5, 0, 0, 5, 5, 0, 5, 0, 0, 0};
 static signed char direction;
  static unsigned char RE_old = 0;               // 共通変数（値は保存）
  unsigned char RE_now;
  signed char  offset;
  RE_now =  RE_B_GetValue() * 2 +  RE_A_GetValue();           // 今回情報の読取
  RE_old <<= 2;                         // 前回の読取値と
  RE_old |= ( RE_now & 0x03 );          // 今回の読取値を組合わせる
  if ((offset = RE_states[( (RE_old & 0x0F))]) == 5)
    return (1 * direction * offset);  // 変化分を戻り値をする
  direction = offset;
  return(offset);
}

//-----------Clicking Rotary Encoder Rread --------------
// A相のクリック安定点ではB相を読まない
// A相がONになるタイミングで左右どちらに
// 回転をしたのか判定。　戻り値は (-1,0,1) の３通り
//--------------------------------------------------------
signed char read_clickRE(void){
  static unsigned char index, interval;
     signed char current;
   
     current = RE_B_GetValue();
   if((current != index) && (current== 0))
        {  // RE_Aが1から0に変化しているとき
        index =current; // Save this time level of RE_A=0
        current = RE_A_GetValue() ? 1 : -1;     // RE_Bの値で時計回り、反時計回りが判定で角速度対応する
        if (interval <5)
           current *=2; // Accelrarate Value Change
        if (interval <12)
           current *=2; // Accelrarate Value Change
        if (interval <20)
           current *=2; // Accelrarate Value Change
        interval =0;
        }
   else
        {                            // RE_Aが0から1に変化しているとき、RE_Bのみ変化する場合は無視
        index = current;
        current = 0;
        if (interval <127)
            ++interval;
        }
 return(current);   // Return changed offset value
}


void TMR1_ISR(void)
{
    // Clear the TMR1 interrupt flag
    PIR1bits.TMR1IF = 0;
    TMR1_WriteTimer(timer1ReloadVal);    // timer周期再設定

    if(TMR1_InterruptHandler)       // Timer1割り込みであれば
        {
        TMR1_InterruptHandler();   // Timer1割り込み処理
        }
    
}



void TMR1_SetInterruptHandler(void (* InterruptHandler)(void)){
    TMR1_InterruptHandler = InterruptHandler;
}


void TMR1_DefaultInterruptHandler(void)
{
    // add your TMR1 interrupt custom code
    // or set custom function using TMR1_SetInterruptHandler()
static unsigned char led_blink[]={0, 0, 0};
static unsigned char  intcnt;    
static unsigned int pushcnt = 0;
static unsigned char pushstat = 0;
static signed char    RE_offset;

switch ( intcnt++)
        {
        case 0:
            {
             DIG_3_SetLow();
             if(led_blink[0] < 0xc0)
                    DIG_1_SetHigh();
             else DIG_1_SetLow();
            PORTC =  led_dot[0] & get7seg_font(ledbuff[0]);
            break;
            }
        case 1:
           {
           DIG_1_SetLow();
           if(led_blink[1] < 0xc0)
                      DIG_2_SetHigh();
            else    DIG_2_SetLow();
            PORTC = led_dot[1] & get7seg_font(ledbuff[1]);
            break;
            }
        case 2:
           {
           DIG_2_SetLow();
           if(led_blink[0] < 0xc0)
                      DIG_3_SetHigh();
           else     DIG_3_SetLow();
            PORTC = led_dot[2] & get7seg_font(ledbuff[2]);
            }
        default:
          intcnt = 0; 
        }
RE_offset =read_clickRE();
if (RE_offset > 0)  // if offset is positive
         {
         if (RE_pos > 247)
                {
                if (238> (unsigned char)(RE_pos + RE_offset))
                    RE_pos =255;
                }
         else     RE_pos   += RE_offset;// Update Rotary Ecncoder position
         }
else    // if offset is negative
       {        
         if (RE_pos < 8)
                {
                if (17 < (unsigned char)(RE_pos + RE_offset))
                    RE_pos =0;
                }
         else
                 RE_pos   += RE_offset;// Update Rotary Ecncoder position
        }

 
 // if blink rate defined then proceed that digit blink counter
 if(blink_rate[0]) 
         led_blink[0] += blink_rate[0]; 
else   led_blink[0] = 0;
if(blink_rate[1])
        led_blink[1] += blink_rate[1];
else   led_blink[1] = 0;
if(blink_rate[2])
        led_blink[2] += blink_rate[2];
 else   led_blink[2] = 0;
// if Button is down countup holding duration
if (MODEn_GetValue() == HIGH)
    {
    if (pushstat !=0)
        {
        button1 = pushstat; // Update Button Status
        pushstat = NOT_PUSHED;  // Clear for next push
        }
    else
        {
         pushcnt =0; // Skip because of chattaing
        }
    }
else // if PUSHED
    {
    ++pushcnt;
    if (pushcnt > CHATT_FILT)
        {
        pushstat = 1;// Short pushing
        if (pushcnt > LONG_HOLD_THR)
             pushstat = 2;
        }
    }
}


/**
  End of File
*/

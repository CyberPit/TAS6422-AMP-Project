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


/*  MCC Generated Main Source File, 
  Company:
    Microchip Technology Inc.
  File Name:
    main.c
  Summary:
    This is the main file generated using PIC10 / PIC12 / PIC16 / PIC18 MCUs
  Description:
    This header file provides implementations for driver APIs for all modules selected in the GUI.
    Generation Information :
        Product Revision  :  PIC10 / PIC12 / PIC16 / PIC18 MCUs - 1.81.3
        Device            :  PIC16F18346
        Driver Version    :  2.00
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
#include "mcc_generated_files/mcc.h"
#include "mcc_generated_files/memory.h"
#include "mcc_generated_files/tmr1.h"
#include <xc.h>
#include "./lcd_driver_files/i2c-lcdlib-ceg003400.h"
#include "disp_param.h"
//#include <stdint.h>
#include <stdio.h>
#include <string.h>
// EEPROM Address Labels
#define     EE_FACTORY              0xF010  // Ideity to know  initalize EEPROM
#define     EE_VOLUME               0xF011  // TAS6422 Volume Setting
#define     EE_BALANCE              0xF012  // TAS6422 Input offset Setting
#define     EE_SOURCE                0xF013  // PCM9211 Input
#define     EE_AUXDIRECTION      0xF014  //  PCM9211 Group-B Setting
#define     EE_HPF                       0xF015  //-6dB per octave High Pass Filter Setting
#define     EE_UOL                      0xF016  // User Oriented Volume Setting
#define     I2S_INPMODE     0
#define     I2S_OUTMODE   1
// Values for EE
#define     YES_FACTORY  0xC5     // Defult EEPROM Value Loaded Flag
#define     NON_FACTORY 0x5C    // Idetifier Not to initialize EEPROM


extern char ledstr[], ledbuff[], blink_rate[]; // for 3digits LED
extern unsigned char led_dot[];
extern char RE_pos;
extern char button1;
static  char lcdbuff[41];
static  unsigned char tasbuff[2];   // offset_adrr, reg_value
static char gain;
static unsigned char   current_source;
static unsigned char   current_volume;
static unsigned char   stored_volume;
static unsigned char   current_aux;
static unsigned char   current_fs;
static signed char       current_balance;
static signed char      current_direction;  // Port B  as AUX I2S direction
static signed char      current_hpf;          // HPF Setting 0-7, 8 is OFF
static signed char      current_uol;          // Startup volume setting (0=Last Saved)

// Fixed Message String
//Opening Message
//const char CyberPitStr[]="   TAS6422 44.1kHz AMP by CyberPit HILO 2020";
// SAMPLING RATE VALUES
const char led_fs_name[6][7] = { "44.1", " 48", " 88.2"," 96", "176", "192"};
 // I2S Header I/O Mode Selection Items
const char led_i2s_dir[2][7] = { "1np", "Out" };
  // MUSIC SOURCE SELECT ITEMS
const char led_src_name[5][7] = { "COA", "OPT", "AdC", "HDM",  "12S"};
 //HPF Selection Items
const char led_hpf_fc[9][7] = { "  4", "  8", " 15"," 30", " 59", "118", "235","463", "oFF"};

void puts_led(char *str)
{
    unsigned char *cpoint;
   
cpoint =(unsigned char *)(str);  // Pint Strings top
         {
            ledbuff[0] = *(cpoint++);
            if (*cpoint == '.')
                {
                led_dot[0]= DOT_ON;
                ++cpoint;
                }
            else     
                led_dot[0]= DOT_OFF;
             ledbuff[1] = *(cpoint++);
            if (*cpoint == '.')
                {
                led_dot[1]= DOT_ON;
                ++cpoint;
                }
            else     
                led_dot[1]= DOT_OFF;            
             ledbuff[2] = *(cpoint++);
            if (*cpoint == '.')
                {
                led_dot[2]= DOT_ON;
   //             ++cpoint;
                }
            else     
                led_dot[2]= DOT_OFF;            
        }

}

// Set Gain on LED
void    set_gainstr(unsigned char gval)
{
if (gval <9)
         strcpy( ledstr, "OFF");
else   
         {
         if (gval > 0xba)  // Wehn above -10dB
                  {                              
                   gain = (signed char) (((signed int)gval - (signed int)0x00cf)/2);
                   sprintf(ledstr, "%2d", (signed char)gain);
                   if (gval == 0xce)
                           ledstr[0] = 0x2d;  // Display '-'
                   if(gval & 0x01)
                           strcat(ledstr, ".0 ");
                   else  strcat(ledstr, ".5 ");
                  }
         else
                  {
                  gain =(signed char)((((int)gval - (int)0xcf))/2);
                  sprintf(ledstr, "%3d",(signed char)gain);
                  if((gval & 0x01) != 0x01)
                           strcat (ledstr, ".");
                  }
         }
 puts_led(ledstr);
}


// Show  UOL Setting on LED
void    show_uolstr(unsigned char gval)
{
if (gval <9)
         strcpy( ledstr, "LAS");
else   
         {
         if (gval > 0xba)  // Wehn above -10dB
                  {                              
                   gain = (signed char) (((signed int)gval - (signed int)0x00cf)/2);
                   sprintf(ledstr, "%2d", (signed char)gain);
                   if (gval == 0xce)
                           ledstr[0] = 0x2d;  // Display '-'
                   if(gval & 0x01)
                           strcat(ledstr, ".0 ");
                   else  strcat(ledstr, ".5 ");
                  }
         else
                  {
                  gain =(signed char)((((int)gval - (int)0xcf))/2);
                  sprintf(ledstr, "%3d",(signed char)gain);
                  if((gval & 0x01) != 0x01)
                           strcat (ledstr, ".");
                  }
         }
 puts_led(ledstr);
}

// PCM9211 Setting Data Table
typedef struct  
    {
    const unsigned char    addr;
    const unsigned char   data;
    }   Command9211;
 // Offset Address, Value
Command9211     I2S_OUT   = {0x6f, 0x08};
Command9211     I2S_IN      = {0x6f, 0x00};
// SOURCE SELECTIONS
Command9211     SRC_DIR    = {0x6b, 0x11};
Command9211     SRC_ADC   = {0x6b, 0x22};
Command9211     SRC_LVDS = {0x6b, 0x33};
Command9211     SRC_I2S    = {0x6b, 0x55};
// AUX(I2S-OUT) SOURCE SELECTIONS
Command9211     AUXSRC_AUTO = {0x6c, 0x00};
Command9211     AUXSRC_DIR    = {0x6c, 0x11};
Command9211     AUXSRC_ADC   = {0x6c, 0x22};
Command9211     AUXSRC_LVDS = {0x6c, 0x33};
Command9211     AUXSRC_I2S    = {0x6c, 0x55};
//DIR SOURCE SLECTIONS
Command9211     DIR_OPT     = {0x34, 0x00};
Command9211     DIR_COAX   ={0x34, 0x01};
// Fs calc signal selection
Command9211     CALC_DIR      ={0x37, 0x00}; 
Command9211     CALC_ADC    ={0x37, 0x01}; 
Command9211     CALC_MPIB  ={0x37, 0x03}; 
Command9211     CALC_MOUT  ={0x37, 0x05}; 
Command9211     CALC_MPOB  ={0x37, 0x06}; 
Command9211     CALC_DIT      ={0x37, 0x07}; 
// ADC ReGain
Command9211     ADC_ATTL_0dB = { 0x46, 215 };// Default Sens
Command9211     ADC_ATTR_0dB = { 0x47, 215 };// Default Sens
Command9211     ADC_ATTL_3dB = { 0x46, 209 }; // -3dB for adjusting input sensitivity
Command9211     ADC_ATTR_3dB = { 0x47, 209 };// -3dB for adjusting input sensitivity
Command9211     ADC_ATTL_6dB = { 0x46, 203 };// -6dB for adjusting input sensitivity
Command9211     ADC_ATTR_6dB = { 0x47, 203 };// -6dB for adjusting input sensitivity
// DIT SOURCE SELECTIONS
Command9211     DIT_DIR     = {0x60, 0x11};
Command9211     DIT_ADC    ={0x60, 0x22};
Command9211     DIT_LVDS  ={0x60, 0x44};
Command9211     DIT_I2S     ={0x60, 0x55};

//ADC COMMANDS
Command9211     ADC_I2S_MASTER_256  = {0x48, 0x40};
Command9211     ADC_DC  = {0x49, 0x08};
Command9211    ADC_AC  = {0x49, 0x00};
Command9211    ADC_96K={0x31, 0x05};
Command9211    ADC_48K={0x31, 0x1a};
// INITIAL DEFAULT SETUP
Command9211     INIT9211_20 = {0x20, 0x01};
Command9211     INIT9211_2E = {0x2e, 0x08};
Command9211     INIT9211_2B = {0x2b, 0xfe};
Command9211     INIT9211_26 = {0x26, 0x60};
Command9211     INIT9211_27 = {0x27, 0xdb};
Command9211     INIT9211_31 = {0x31, 0x05};

  // MUSIC SOURCE SELECT ITEMS
Command9211   *srcset9211[5] = { &DIR_COAX, &DIR_OPT, &SRC_ADC, &SRC_LVDS, &SRC_I2S }; 

// TAS6422 Setting Data Table
typedef struct  
    {
    const unsigned char    addr;
    const unsigned char   data;
    }   Command6422;
 // Offset Address, Value
Command6422 TAS_RESET  = {0x00, 0x80};
Command6422 TAS_RUN     = {0x00, 0x00};
Command6422 TAS_DCDIAG_ABORT     = {0x09, 0x80};
Command6422 TAS_DCDIAG_CLEAR     = {0x09, 0x01};
// HPF Switch
Command6422 TAS_DC       = {0x01, 0xF2}; // HPF==OFF, 110degrees
Command6422 TAS_AC       = {0x01, 0x72}; // HPF==ON, 110degrees
Command6422 TAS_FC4     = {0x26, 0x40}; // fc==3.7Hz
Command6422 TAS_FC7     = {0x26, 0x41}; // fc==7.4Hz
Command6422 TAS_FC15   = {0x26, 0x42}; // fc==15Hz
Command6422 TAS_FC30   = {0x26, 0x43}; // fc==30Hz
Command6422 TAS_FC59   = {0x26, 0x44}; // fc==59Hz
Command6422 TAS_FC118 ={0x26, 0x45}; // fc==118Hz
Command6422 TAS_FC235 ={0x26, 0x46}; // fc==235Hz
Command6422 TAS_FC463 ={0x26, 0x47}; // fc==467Hz
// Oversampling Rate Select
Command6422 TAS_OSR64 = {0x02, 0x62}; // For Higher S/N
Command6422 TAS_OSR128= {0x02, 0x66};// For WIde-bandwith
// Sampling Rate Select
Command6422 TAS_FS44K   = {0x03, 0x04};
Command6422 TAS_FS48K   = {0x03, 0x44};
Command6422 TAS_FS96K   = {0x03, 0x84};
// Output Control
Command6422 TAS_HiZ         = {0x04, 0x55};
Command6422 TAS_MUTE     = {0x04, 0xA5};
Command6422 TAS_PLAY     = {0x04, 0x05};
// Warning setup
Command6422 TAS_CHK_RAILS     = {0x11, 0x1F}; // Ignore Clock Error
// Swap Channel  Control
Command6422 TAS_CLEAR_FALT   = {0x21, 0x88};
Command6422 TAS_NORMAL   = {0x21, 0x08};

void init_pcm9211(void)
{
i2c_writeNBytes(ADR_PCM9211,&INIT9211_20, 2 ); 
i2c_writeNBytes(ADR_PCM9211,&INIT9211_26, 2 ); 
i2c_writeNBytes(ADR_PCM9211,&INIT9211_27, 2 ); 
i2c_writeNBytes(ADR_PCM9211,&INIT9211_2E, 2 );
i2c_writeNBytes(ADR_PCM9211,&INIT9211_2B, 2 );
i2c_writeNBytes(ADR_PCM9211,&INIT9211_31, 2 ); 
 if( current_direction == I2S_OUTMODE)
           i2c_writeNBytes(ADR_PCM9211,&I2S_OUT, 2 );  
 else    i2c_writeNBytes(ADR_PCM9211,&I2S_IN, 2 ); 
 i2c_writeNBytes(ADR_PCM9211,&ADC_96K, 2 ); 
 i2c_writeNBytes(ADR_PCM9211,&ADC_DC, 2 );
i2c_writeNBytes(ADR_PCM9211,&ADC_ATTL_3dB, 2 );
i2c_writeNBytes(ADR_PCM9211,&ADC_ATTR_3dB, 2 );
 i2c_writeNBytes(ADR_PCM9211,&SRC_ADC, 2 );
 i2c_writeNBytes(ADR_PCM9211,&DIR_OPT, 2 );
 i2c_writeNBytes(ADR_PCM9211,&DIT_ADC, 2 );
 i2c_writeNBytes(ADR_PCM9211,&CALC_MOUT, 2); // Check the Main Out fs
}

void write_tas6422(unsigned char adr, unsigned char val)
{
static char  buffer[2];
 buffer[0] = adr;
 buffer[1] = val;
i2c_writeNBytes(ADR_TAS6422,&buffer, 2); // Write val to offser=adr
}
void init_tas6422(void)
{
i2c_writeNBytes(ADR_TAS6422,&TAS_RESET, 2 );
  DELAY_milliseconds(5); 
i2c_writeNBytes(ADR_TAS6422,&TAS_RUN, 2 );
 //i2c_writeNBytes(ADR_TAS6422,&TAS_DCDIAG_ABORT, 2 );
i2c_writeNBytes(ADR_TAS6422,&TAS_DCDIAG_CLEAR, 2 );
i2c_writeNBytes(ADR_TAS6422,&TAS_FS96K, 2 );
i2c_writeNBytes(ADR_TAS6422,&TAS_AC, 2 );
i2c_writeNBytes(ADR_TAS6422,&TAS_CHK_RAILS, 2 );
i2c_writeNBytes(ADR_TAS6422,&TAS_CLEAR_FALT, 2 );
i2c_writeNBytes(ADR_TAS6422,&TAS_NORMAL, 2 );
MUTEn_SetHigh();
}

char    chk6422warning(void)
{
static uint8_t   lasttime, ocdc, otshut, otwarn,clip,ilim,prail;
    ocdc    = i2c_read1ByteRegister(ADR_TAS6422, 0x10);  
    otwarn = i2c_read1ByteRegister(ADR_TAS6422, 0x13);
    clip       = i2c_read1ByteRegister(ADR_TAS6422, 0x24);
    ilim       = i2c_read1ByteRegister(ADR_TAS6422, 0x25);
    otshut = i2c_read1ByteRegister(ADR_TAS6422, 0x12); 
    prail = i2c_read1ByteRegister(ADR_TAS6422, 0x11); 
    if(lasttime == (ocdc + otshut + otwarn + clip +ilim + prail ))
             return(0);
     else
     {
      lasttime = ocdc + otshut + otwarn + clip +ilim + prail ;
      return(1);
     }
}
void    set_gains(unsigned char vol, signed char  bal)
{
 if (bal < 0)
    {
     tasbuff[0] = TAS_VOL1;
     tasbuff[1] =vol;
    i2c_writeNBytes(ADR_TAS6422, &tasbuff, 2 );
    tasbuff[0] = TAS_VOL2;
    tasbuff[1] = vol - abs(bal);
    i2c_writeNBytes(ADR_TAS6422, &tasbuff, 2 );
    }
 else
    {
     tasbuff[0] = TAS_VOL1;
     tasbuff[1] =vol - bal;
    i2c_writeNBytes(ADR_TAS6422, &tasbuff, 2 );
    tasbuff[0] = TAS_VOL2;
    tasbuff[1] = vol ;
    i2c_writeNBytes(ADR_TAS6422, &tasbuff, 2 );
     }
 }

void set_source(unsigned char sourcenumber)
{                   switch(sourcenumber % 5)
                        {
                         case    0:
                                i2c_writeNBytes(ADR_PCM9211,&SRC_DIR, 2 );
                                i2c_writeNBytes(ADR_PCM9211,&DIR_COAX, 2 );
                                i2c_writeNBytes(ADR_PCM9211,&DIT_DIR, 2 );
                                i2c_writeNBytes(ADR_PCM9211,&AUXSRC_DIR, 2 );
                                 break;
                         case   1:
                                i2c_writeNBytes(ADR_PCM9211,&SRC_DIR, 2 );
                                i2c_writeNBytes(ADR_PCM9211,&DIR_OPT, 2 );
                                i2c_writeNBytes(ADR_PCM9211,&DIT_DIR, 2 );
                                i2c_writeNBytes(ADR_PCM9211,&AUXSRC_DIR, 2 );
                                break;
                         case   2:
                                 i2c_writeNBytes(ADR_PCM9211,&SRC_ADC, 2 );
                                 i2c_writeNBytes(ADR_PCM9211,&DIT_ADC, 2 );
                                i2c_writeNBytes(ADR_PCM9211,&AUXSRC_ADC, 2 );
                                 break;
                           case   3:
                                 i2c_writeNBytes(ADR_PCM9211,&SRC_LVDS, 2 );
                                 i2c_writeNBytes(ADR_PCM9211,&DIT_LVDS, 2 );
                                 i2c_writeNBytes(ADR_PCM9211,&AUXSRC_LVDS, 2 );
                                break;
                           case   4:
                                 i2c_writeNBytes(ADR_PCM9211,&SRC_I2S, 2 );
                                 i2c_writeNBytes(ADR_PCM9211,&DIT_I2S, 2 );
                                i2c_writeNBytes(ADR_PCM9211,&AUXSRC_AUTO, 2 );
                                 break;
                        }
DELAY_milliseconds(5);
 i2c_writeNBytes(ADR_TAS6422, &TAS_CLEAR_FALT, 2 );   // Run TAS6422
i2c_writeNBytes(ADR_TAS6422, &TAS_NORMAL, 2 );   // Run TAS6422
}


/*
 --------------------   Main application -------------------- 
 */
void main(void)
{
    static unsigned char count;
    char level;
    unsigned char textlen;
    unsigned int    vol_move_cnt=0;
    
   // signed char gain;
    
    // initialize the device
    SYSTEM_Initialize();
    DELAY_milliseconds(500);
    // Enable the Global Interrupts
    TMR1_Initialize();    // add
    TMR1_StartTimer();
     // add
     PIE1bits.TMR1IE = 1;	// TMR1 Overflow Interrupt Enable bit
     INTCONbits.PEIE = 1;	// Peripheral Interrupt Enable bit
     INTCONbits.GIE = 1;		// Global Interrupt Enable bit
     // Start inturrupt
     INTERRUPT_GlobalInterruptEnable();
    // Enable the Peripheral Interrupts
    INTERRUPT_PeripheralInterruptEnable();
    //Restore Saved Settings for EE DATAEE_WriteByte(0x10,0x45);
    
    DELAY_milliseconds(100);  // Wiat for a Hardware stable
    
    // Restore Saved Values or Factory preset
 if(DATAEE_ReadByte(EE_FACTORY) == NON_FACTORY)
          {
        // Only NON_FACTORY restore from EEPROM
         current_balance   = DATAEE_ReadByte(EE_BALANCE);
        current_source    = DATAEE_ReadByte(EE_SOURCE);
        current_direction = DATAEE_ReadByte(EE_AUXDIRECTION);
        current_hpf          = DATAEE_ReadByte(EE_HPF);
        current_uol          = DATAEE_ReadByte(EE_UOL);
        stored_volume  = DATAEE_ReadByte(EE_VOLUME);
        if( current_uol == 0)
                current_volume  = stored_volume;
        else    current_volume  = stored_volume = current_uol;
       }
 else
        {
        //Otherwise  Load Factory defaults
         DATAEE_WriteByte(EE_VOLUME, current_volume=stored_volume =146);
         DATAEE_WriteByte(EE_BALANCE, current_balance=0);
         DATAEE_WriteByte(EE_SOURCE, current_source=2);
         DATAEE_WriteByte(EE_AUXDIRECTION, current_direction = I2S_INPMODE);
         DATAEE_WriteByte(EE_HPF, current_hpf = 0);
         DATAEE_WriteByte(EE_UOL, current_uol = 0);
         DATAEE_WriteByte(EE_FACTORY, YES_FACTORY);
         }


  // Power-On Initialize
     init_pcm9211();
     init_tas6422(); 
  // LCD Setup  
   // LCD Setup
    i2c_lcd_init();                                                                   
    i2c_lcd_ulcursor_off();     
    i2c_lcd_home(); //         i2c_lcd_set_cursor_pos(0, 0);
    sprintf(lcdbuff,"Firmware: 2020OCT11"); 
    i2c_lcd_puts(lcdbuff);  
    DELAY_milliseconds(800); 
    i2c_lcd_clear();

     
 RE_pos = current_volume;    //  Set TAS6422 Default Volume Level
 set_gains(current_volume, current_balance); // Set each channel's gain
  i2c_writeNBytes(ADR_TAS6422, &TAS_PLAY, 2 );   // Run TAS6422

  
i2c_writeNBytes(ADR_TAS6422, &TAS_CLEAR_FALT, 2 );   // Run TAS6422
i2c_writeNBytes(ADR_TAS6422, &TAS_NORMAL, 2 );   // Run TAS6422

set_source(current_source);
vol_move_cnt = 0;
// LED Setup
blink_rate[2]= blink_rate[1]=blink_rate[0]=0; // No blink
puts_led("HL0"); // Firmware Version String Notice
DELAY_milliseconds(1000);


lcd_disp_param();
//current_volume = RE_pos;
set_gainstr(current_volume);
    while (1)
        {
        if (button1 == SHORT_PUSHED)
                    {
                    RE_pos = current_source;  
                    puts_led("SOC");
                    button1 = NOT_PUSHED;   // Clear for nettime
                    DELAY_milliseconds(800);
                    puts_led("   ");
                    DELAY_milliseconds(200);
                    button1 = NOT_PUSHED;   // Clear for nettime
                  
                    blink_rate[2]= blink_rate[1]=blink_rate[0]=1; // blink LED
                    while (button1 == NOT_PUSHED)
                        {
                         puts_led(led_src_name[current_source % 5]);
                         lcd_disp_param();
                         current_source = RE_pos;
                        }
                    button1 = NOT_PUSHED;   // Clear for nexttime
//                    MUTEn_SetLow(); // Muting start
                    i2c_writeNBytes(ADR_TAS6422,&TAS_MUTE, 2 );
                    DATAEE_WriteByte(EE_FACTORY, NON_FACTORY); // Erace Factory Mode flag
                    DATAEE_WriteByte(EE_SOURCE, (current_source % 5));
                    set_source(current_source); // Switch Source
                     RE_pos = current_volume;    // Restore Volume Setting
                    set_gainstr(current_volume);
                    blink_rate[2]= blink_rate[1]=blink_rate[0]=0; // Non blink LED
                    puts_led(ledstr);
 //                    MUTEn_SetHigh(); // Muting release
                    i2c_writeNBytes(ADR_TAS6422,&TAS_PLAY, 2 );
                 }
        if (button1 == LONG_PUSHED)
                    {
                    // Balance Settup
                     DATAEE_WriteByte(EE_FACTORY, NON_FACTORY); // Erace Factory Mode flag
                    RE_pos = 64 + current_balance ;  
                    puts_led("BAL");
                    DELAY_milliseconds(900);
                    puts_led("   ");
                    DELAY_milliseconds(200);
                    blink_rate[2]= blink_rate[1]=blink_rate[0]=1; // blink LED
                    button1 = NOT_PUSHED;   // Clear for nexttime
                    while (button1 == NOT_PUSHED)
                        {
                        sprintf(ledbuff, "%03d",(current_balance=(signed char)(RE_pos-64)));
                        puts_led(ledbuff);
                        lcd_disp_param();
                        }
                    button1 = NOT_PUSHED;   // Clear for nettime
                    DATAEE_WriteByte(EE_BALANCE, current_balance);
                    blink_rate[2]= blink_rate[1]=blink_rate[0]=0; // No  blink
                    sprintf(ledbuff, "%03d",current_balance);
                    set_gains(current_volume, current_balance);
                    puts_led(ledbuff);
                    DELAY_milliseconds(1400);
                    puts_led("   ");
                    DELAY_milliseconds(800);
 
                    // HPF Setup
                    RE_pos = current_hpf;  
                    puts_led("HPF");
                    DELAY_milliseconds(900);
                    puts_led("   ");
                    DELAY_milliseconds(200);
                    blink_rate[2]= blink_rate[1]=blink_rate[0]=1; // blink LED
                    button1 = NOT_PUSHED;   // Clear for nexttime
                    while (button1 == NOT_PUSHED)
                        {
                        current_hpf = RE_pos%9;
                        strcpy(ledbuff,  led_hpf_fc[current_hpf]);
                        puts_led(ledbuff);
                        lcd_disp_param();
                        }
                    button1 = NOT_PUSHED;   // Clear for nettime
                    DATAEE_WriteByte(EE_HPF, current_hpf);
                    blink_rate[2]= blink_rate[1]=blink_rate[0]=0; // No  blink
                    if( current_hpf == 8)
                              i2c_writeNBytes(ADR_TAS6422,&TAS_DC, 2 );  
                    else  {  
                            i2c_writeNBytes(ADR_TAS6422,&TAS_AC, 2 ); 
                            write_tas6422( 0x26, current_hpf);
                            }
                    strcpy(ledbuff,  led_hpf_fc[current_hpf]);
                    puts_led(ledbuff);
                    DELAY_milliseconds(1500);
                    puts_led("   ");
                    DELAY_milliseconds(800);
                    
                    // Startup Volume Setup
                    RE_pos = current_uol;  
                    puts_led("UOL");
                    DELAY_milliseconds(900);
                    puts_led("   ");
                    DELAY_milliseconds(200);
                    blink_rate[2]= blink_rate[1]=blink_rate[0]=1; // blink LED
                    button1 = NOT_PUSHED;   // Clear for nexttime
                    while (button1 == NOT_PUSHED)
                        {
                        current_uol = RE_pos;
                        show_uolstr(current_uol);
                        }
                    button1 = NOT_PUSHED;   // Clear for nettime
                    DATAEE_WriteByte(EE_UOL, current_uol);
                    blink_rate[2]= blink_rate[1]=blink_rate[0]=0; // No  blink
                    if( current_uol != 0)
                       strcpy(ledbuff,  "SET");
                    puts_led(ledbuff);
                    DELAY_milliseconds(800);
                    puts_led("   ");
                    DELAY_milliseconds(800);

                    
                    // AUX (I2S) Direction Setup
                    RE_pos = current_direction;  
                    puts_led("12S");
                    DELAY_milliseconds(900);
                    puts_led("   ");
                    DELAY_milliseconds(200);
                    blink_rate[2]= blink_rate[1]=blink_rate[0]=1; // blink LED
                    button1 = NOT_PUSHED;   // Clear for nexttime
                    while (button1 == NOT_PUSHED)
                        {
                        current_direction = RE_pos%2;
                        strcpy(ledbuff,  led_i2s_dir[current_direction]);
                        puts_led(ledbuff);
                        lcd_disp_param();
                        }
                    button1 = NOT_PUSHED;   // Clear for nettime
                    DATAEE_WriteByte(EE_AUXDIRECTION, current_direction);
                    blink_rate[2]= blink_rate[1]=blink_rate[0]=0; // No  blink
                    if( current_direction == I2S_OUTMODE)
                              i2c_writeNBytes(ADR_PCM9211,&I2S_OUT, 2 );  
                    else    i2c_writeNBytes(ADR_PCM9211,&I2S_IN, 2 ); 
                    strcpy(ledbuff,  led_i2s_dir[current_direction]);
                    puts_led(ledbuff);
                    DELAY_milliseconds(1500);

                    // Inidicate as Seeting mode Finished
                    puts_led("   ");
                    DELAY_milliseconds(800);
                    puts_led("FAd");
                    DELAY_milliseconds(500);
                   
                    // Restore Setting for Volume Loop Mode
                    RE_pos = current_volume;
                    set_gainstr(current_volume);
                    lcd_disp_param();
                    button1 = NOT_PUSHED;   // Clear for nexttime
                    }     

         if (current_volume != RE_pos) // When moved
                    {
                    current_volume =  RE_pos;    // update psition
                    set_gainstr(current_volume);
                    set_gains(current_volume, current_balance); //  Default Volume Level
                    lcd_disp_param();
                   puts_led(ledstr);
                   }
         switch(0x0f & i2c_read1ByteRegister(ADR_PCM9211, 0x38))
                {
             case 0x08: // 44.1kHz
                    i2c_writeNBytes(ADR_TAS6422,&TAS_FS44K, 2 );
                   write_tas6422( 0x26, (current_hpf));
                   break;
             case 0x09:
                    i2c_writeNBytes(ADR_TAS6422,&TAS_FS48K, 2 );
                   write_tas6422( 0x26, (current_hpf));
                   break;
            case 0x0b:
            case 0x0c:
                    i2c_writeNBytes(ADR_TAS6422,&TAS_FS96K, 2 );
                    if (current_hpf)
                   write_tas6422( 0x26, (current_hpf - 1)); // Compnsate cutoff frequency
                    break;
                 }
         i2c_read1ByteRegister(ADR_PCM9211, 0x2d); // Dummy read for clear the Analog signal LED
         if (chk6422warning())
                {
                lcd_disp_param();
                i2c_writeNBytes(ADR_TAS6422, &TAS_CLEAR_FALT, 2 );   // Run TAS6422
                i2c_writeNBytes(ADR_TAS6422, &TAS_NORMAL, 2 );   // Run TAS6422
                }
         if (current_volume != stored_volume)
             if ( vol_move_cnt++ > 900)
                {
 //                   puts_led("VOL");  // To check the EEPROM overwrite timing
                 stored_volume = current_volume;
                 DATAEE_WriteByte(EE_VOLUME,   stored_volume);
                vol_move_cnt = 0;
                 }
         }
 // Disable the Global Interrupts
 //INTERRUPT_GlobalInterruptDisable();
 // Disable the Peripheral Interrupts
}
/**
 End of File
*/

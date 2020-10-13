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

#include <stdio.h>
#include <string.h>
#include "./lcd_driver_files/i2c-lcdlib-ceg003400.h"
#include "./mcc_generated_files/drivers/i2c_simple_master.h"

//#include "./lcd_driver_files/disp_param.h"
extern char lcdbuff[],ledbuff[], led_dot[];
extern unsigned char RE_pos;
extern char button1;
extern char gain;
extern unsigned char   current_source;
extern unsigned char   current_volume;
extern unsigned char   current_aux;
extern unsigned char   current_fs;
extern signed char     current_balance;
extern signed char     current_direction;
extern signed char     current_hpf;

const char lcd_hpf_fc[9][7] = { "4Hz  ", "8Hz  ", "15Hz  ","30Hz  ", "59Hz  ", "118Hz ", "235Hz ","463Hz ", "BYP  "};

// MUSIC SOURCE SELECT ITEMS
const char lcd_src_name[5][8] = {"COAXIAL","OPTICAL", "ADC    ",  "HDMI   ", "I2S    "};
// AUX ROUTING ITEMS
const char lcd_aux_name[2][7] = { "INPUT ", "OUTPUT"};
// SAMPLING RATE VALUES
const char lcd_fs_name[16][7] = {"UNLK", "  8k", " 11k", " 12k", " 16k", " 22k", " 24k", " 32k",  "44.1k", " 48k", " 64k", "88.2k", " 96k", "128k",  "176k", "192k"};

void lcd_disp_param(void)
{      
uint8_t   pfspo,ocdc, otshut, otwarn,clip,ilim,prail;
    
    i2c_lcd_set_cursor_pos(0, 0);
    sprintf(lcdbuff,"SOURCE:%s", lcd_src_name[current_source % 5]);
    i2c_lcd_puts(lcdbuff);     

   i2c_lcd_set_cursor_pos(0, 1);
    sprintf(lcdbuff,"AUX:%s HPF:%s", lcd_aux_name[current_direction %2], lcd_hpf_fc[current_hpf]);
    i2c_lcd_puts(lcdbuff);     
  
    pfspo = i2c_read1ByteRegister(ADR_PCM9211, 0x38);
    i2c_lcd_set_cursor_pos(0, 2);
    sprintf(lcdbuff,"VOL:%3d BAL:%2d %s",current_volume, (signed char)current_balance,   lcd_fs_name[(0x0F &pfspo)]);
    i2c_lcd_puts(lcdbuff);     
 
    ocdc    = i2c_read1ByteRegister(ADR_TAS6422, 0x10);  
    otwarn = i2c_read1ByteRegister(ADR_TAS6422, 0x13);
    clip       = i2c_read1ByteRegister(ADR_TAS6422, 0x24);
    ilim       = i2c_read1ByteRegister(ADR_TAS6422, 0x25);
    otshut = i2c_read1ByteRegister(ADR_TAS6422, 0x12);
    prail = i2c_read1ByteRegister(ADR_TAS6422, 0x11);
 i2c_lcd_set_cursor_pos(0, 3);
    sprintf(lcdbuff,"WAR:%02X %02X %02X %02X %02X%02X",ocdc, otshut, otwarn,clip,ilim,prail);
    i2c_lcd_puts(lcdbuff);     
 }

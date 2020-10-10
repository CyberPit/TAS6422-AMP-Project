/*
  * License Notice 
  * This file was inherit from "LCDモジュール用ライブラリ" Written by INOUE Hirokazu 2016
 　* Original file located at http://oasis.halfmoon.jp/mw/index.php?title=Elec-pic-i2c-common-library
  * License infromation:  http://oasis.halfmoon.jp/about/index.html#Section_Copyright
  */

/*
 * File:   i2c-lcdlib-ceg003400.c   for Microchip PIC XC8 (12F1822, 16F1823, 16F1827)
 *
 * 2C LCD 変換アダプタ mjkdz I2C lcd1602用
 */

#include <stdio.h>
#include <stdlib.h>

#include <xc.h>
//#include "i2c-lib.h"
#include "i2c-lcdlib-ceg003400.h"
#include "../mcc_generated_files/examples/i2c1_master_example.h"
#include "../mcc_generated_files/i2c1_master.h"

#ifndef _XTAL_FREQ
     /* 例：4MHzの場合、4000000 をセットする */
    #define _XTAL_FREQ 4000000
#endif

// I2C Bus Control Definition
#define I2C_WRITE_CMD 0
#define I2C_READ_CMD 1


// BL は指定するとONになる
#define LCD_BL_ON 0b00001000
#define LCD_BL_OFF 0b00000000
#define LCD_EN 0b00000100
#define LCD_RW 0b00000010
#define LCD_RS 0b00000001

// LCD Commands
#define LCD_CLEAR 0x01
#define LCD_HOME 0x02
#define LCD_UL_CURSOR_ON 0x0e
#define LCD_UL_CURSOR_OFF 0x0c
#define LCD_1CYCLE 0
#define LCD_2CYCLE 1

// send raw 8bit Command to I2C LCD (I2C LCDにコマンドを送信する関数)
void i2c_lcd_send_command(unsigned char data)
    {
    unsigned char upperdata, upperdata_en, lowerdata, lowerdata_en;
     // Put the Upper 4 bits data
     // Write Enable Pulse E: Hi
    upperdata = (data & 0xf0) | LCD_BL_ON;
    upperdata_en = upperdata | LCD_EN;
    lowerdata = ((data << 4) & 0xf0) | LCD_BL_ON ;
    lowerdata_en =  lowerdata | LCD_EN;
      I2C1_WriteNBytes(LCD_ADR, &upperdata_en,1);
     __delay_us(1);      // PWeh=0.23 us (HD44780U), Tpw=0.14 us (SD1602V)
     // Write Enable Pulse E: Hi -> Lo
     I2C1_WriteNBytes(LCD_ADR,  &upperdata, 1);
     __delay_us(1);      // Tcyce-PWeh=0.5-0.23=0.27 us (HD44780U), Tc-Tpw=1.2-0.14=1.06 us (SD1602V)

     // Put the Lower 4 bits data
     // Write Enable Pulse E: Hi
    I2C1_WriteNBytes(LCD_ADR, &lowerdata_en, 1);
     __delay_us(1);      // PWeh=0.23 us (HD44780U), Tpw=0.14 us (SD1602V)
     // Write Enable Pulse E: Hi -> Lo
    I2C1_WriteNBytes(LCD_ADR, &lowerdata, 1);
     __delay_us(1);      // Tcyce-PWeh=0.5-0.23=0.27 us (HD44780U), Tc-Tpw=1.2-0.14=1.06 us (SD1602V)

}

// send upper 4bit Command only to the I2C LCD(I2C LCDに4bitコマンドを送信する関数)
void i2c_lcd_send_upper4bit(unsigned char data)
    {
    unsigned char upperdata, upperdata_en;
     // Put the Upper 4 bits data
     // Write Enable Pulse E: Hi
    upperdata = (data & 0xf0) | LCD_BL_ON;
    upperdata_en = upperdata | LCD_EN;
      I2C1_WriteNBytes(LCD_ADR, &upperdata_en  ,1);
     __delay_us(1);      // PWeh=0.23 us (HD44780U), Tpw=0.14 us (SD1602V)
     // Write Enable Pulse E: Hi -> Lo
     I2C1_WriteNBytes(LCD_ADR, &upperdata, 1);
     __delay_us(1);      // Tcyce-PWeh=0.5-0.23=0.27 us (HD44780U), Tc-Tpw=1.2-0.14=1.06 us (SD1602V)
 }



// send data to I2C LCD(I2C液晶にデータを送信する) 
void i2c_lcd_send_data(unsigned char data)
{
   unsigned char upperdata, upperdata_en, lowerdata, lowerdata_en;
     // Put the Upper 4 bits data
     // Write Enable Pulse E: Hi
    upperdata = (data & 0xf0) | LCD_BL_ON | LCD_RS;
    upperdata_en = upperdata | LCD_EN;
    lowerdata = ((data << 4) & 0xf0) | LCD_BL_ON | LCD_RS ;
    lowerdata_en =  lowerdata | LCD_EN;
      I2C1_WriteNBytes(LCD_ADR, &upperdata_en,1);
     __delay_us(1);      // PWeh=0.23 us (HD44780U), Tpw=0.14 us (SD1602V)
     // Write Enable Pulse E: Hi -> Lo
     I2C1_WriteNBytes(LCD_ADR,  &upperdata, 1);
     __delay_us(1);      // Tcyce-PWeh=0.5-0.23=0.27 us (HD44780U), Tc-Tpw=1.2-0.14=1.06 us (SD1602V)

     // Put the Lower 4 bits data
     // Write Enable Pulse E: Hi
    I2C1_WriteNBytes(LCD_ADR, &lowerdata_en, 1);
     __delay_us(1);      // PWeh=0.23 us (HD44780U), Tpw=0.14 us (SD1602V)
     // Write Enable Pulse E: Hi -> Lo
    I2C1_WriteNBytes(LCD_ADR, &lowerdata, 1);
     __delay_us(1);      // Tcyce-PWeh=0.5-0.23=0.27 us (HD44780U), Tc-Tpw=1.2-0.14=1.06 us (SD1602V)
}

// I2C LCD initialize (I2C??????)
void i2c_lcd_init(void){
    // Wait after Power ON : 15ms (HD44780U), 40ms (SD1602V)
    __delay_ms(100);
    // Send Command 0x30
    i2c_lcd_send_upper4bit(0x30);
    // Wait 4.1ms (HD44780U), 0.037ms (SD1602V)
    __delay_ms(5);
    // Send Command 0x30
    i2c_lcd_send_upper4bit(0x30);
    // Wait 0.1ms (HD44780U), 0.037ms (SD1602V)
    __delay_us(200);
    // Send Command 0x30
    i2c_lcd_send_upper4bit(0x30);
    // Wait 0.037ms (HD44780U, SD1602V)
    __delay_us(100);
    // Function set: Set interface to be 4 bits long (only 1 cycle write).
    i2c_lcd_send_upper4bit(0x20);
    __delay_us(100);    // Wait 0.037ms (HD44780U, SD1602V)
    // Function set: DL=0;Interface is 4 bits, N=1; 2 Lines, F=0; 5x8 dots font)
    i2c_lcd_send_command(0x28);
    __delay_us(100);    // Wait 0.037ms (HD44780U, SD1602V)
    // Display Off: D=0; Display on, C=0; UnderCursor Off, B=0; Blinking Off
    i2c_lcd_send_command(0x0C);
    __delay_us(100);    // Wait 0.037ms (HD44780U, SD1602V)
    // Display Clear
    i2c_lcd_send_command(LCD_CLEAR);
    __delay_ms(5);    // Wait 1.52ms (SD1602V)
    // Entry Mode Set: I/D=1; Increament, S=0; No shift
    i2c_lcd_send_command(0x06);
    __delay_ms(5);    // Wait 0.037ms (HD44780U, SD1602V)
  }

// put one character on LCD (I2C液晶の初期化)
void i2c_lcd_putch(unsigned char c){
    if (c >=0x30)
        i2c_lcd_send_data(c);                   //？¶？？？\？？
}

// put string on LCD (LCD?????????)
void i2c_lcd_puts(unsigned char *s){
    while(*s)               //？¶？？？？？？？o？？
        i2c_lcd_send_data(*s++);            //？¶？？？\？？
}

// send command to I2C LCD (I2C????????????)
void i2c_lcd_cmd(unsigned char cmd){
    i2c_lcd_send_command(cmd);
    __delay_us(100);    // Wait 0.037ms (HD44780U, SD1602V)
}

// clear screen of I2C LCD
void i2c_lcd_clear(void){
    i2c_lcd_send_command(LCD_CLEAR);
    __delay_ms(5);    // Wait 1.52ms (SD1602V)
}

// Baclk to cursot Home Positopn
void i2c_lcd_home(void){
    i2c_lcd_send_command(LCD_HOME);
    __delay_ms(5);    // Wait 1.52ms (SD1602V)
}

// Display Underline Cursor
void i2c_lcd_ulcursor_on(void){
    i2c_lcd_send_command(LCD_UL_CURSOR_ON);
    __delay_ms(2);
}

void i2c_lcd_ulcursor_off(void){
   i2c_lcd_send_command(LCD_UL_CURSOR_OFF);
    __delay_ms(2);
}
// set cursor position of I2C LCD (I2C?? ?????????)
void i2c_lcd_set_cursor_pos(unsigned char col, unsigned char line){
    // line one:     DDRAM start from 0x00 - 0x13
    // line two :    DDRAM start from 0x40 - 0x53
     // line three : DDRAM start from 0x14 - 0x27
    // line four :    DDRAM start from 0x54 - 0x67
   unsigned char pos;
   
    switch( line )
    {
        case 0: pos = col;
                    break;
        case 1: pos = col + 0x40; //ok
                    break;
        case 2: pos = col + 0x14;
                    break;
        case 3: pos = col + 0x54;
    }
    pos += 0x80;
  i2c_lcd_send_command(pos);
  __delay_us(10);    // Wait 0.037ms (HD44780U, SD1602V)
}

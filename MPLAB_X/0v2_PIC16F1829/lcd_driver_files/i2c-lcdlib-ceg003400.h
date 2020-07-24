/*
  * License Notice 
  * This file was inherit from "LCDモジュール用ライブラリ" Written by INOUE Hirokazu 2016
 　* Original file located at http://oasis.halfmoon.jp/mw/index.php?title=Elec-pic-i2c-common-library
  * License infromation:  http://oasis.halfmoon.jp/about/index.html#Section_Copyright
  */


/* 
 * File:   i2c-lcdlib-ceg003400.h
 */

#ifndef I2C_LCDLIB_CEG003400_H
#define	I2C_LCDLIB_CEG003400_H

#ifdef	__cplusplus
extern "C" {
#endif

// LCD device I2C Address
#define LCD_ADR	0x25

// LCD Backlight
#define LCD_BACKLIGHT 0b00001000    // Backlight ON
// #define LCD_BACKLIGHT 0b00000000    // Backlight OFF

//void i2c_lcd_send_common(const unsigned char data);
void i2c_lcd_send_command(unsigned char data);
void i2c_lcd_send_upper4bit(unsigned char data);
void i2c_lcd_send_data(unsigned char data);
void i2c_lcd_init(void);
void i2c_lcd_putch(unsigned char c);
void i2c_lcd_puts(unsigned char *s);
void i2c_lcd_cmd(unsigned char cmd);
void i2c_lcd_clear(void);
void i2c_lcd_home(void);
void i2c_lcd_ulcursor_on(void);
void i2c_lcd_ulcursor_off(void);
void i2c_lcd_set_cursor_pos(unsigned char col, unsigned char line);


#ifdef	__cplusplus
}
#endif

#endif	/* I2C_LCDLIB_CEG003400_H */


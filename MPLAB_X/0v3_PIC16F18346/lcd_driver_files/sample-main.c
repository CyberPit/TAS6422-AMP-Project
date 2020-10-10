/*
  * License Notice 
  * This file was inherit from "LCDモジュール用ライブラリ" Written by INOUE Hirokazu 2016
 　* Original file located at http://oasis.halfmoon.jp/mw/index.php?title=Elec-pic-i2c-common-library
  * License infromation:  http://oasis.halfmoon.jp/about/index.html#Section_Copyright
  */


/* 
 * File:   main.c
 *
 * Sample main file for LCD Lib
 */

#include <stdio.h>
#include <stdlib.h>

#include <xc.h>
#include "i2c-lib.h"
#include "i2c-lcdlib-mjkdz.h"


/* PIC Configuration 1 */
__CONFIG(FOSC_INTOSC &	// INTOSC oscillator: I/O function on CLKIN pin
		WDTE_OFF &		// WDT(Watchdog Timer) disabled
		PWRTE_ON &		// PWRT(Power-up Timer) disabled
		MCLRE_OFF &		// MCLR pin function is digital input
		CP_OFF &		// Program memory code protection is disabled
		CPD_OFF &		// Data memory code protection is disabled
		BOREN_OFF &		// BOR(Brown-out Reset) disabled
		CLKOUTEN_OFF &	// CLKOUT function is disabled. I/O or oscillator function on the CLKOUT pin
		IESO_OFF &		// Internal/External Switchover mode is disabled
		FCMEN_OFF);		// Fail-Safe Clock Monitor is disabled

/* PIC Configuration 2 */
__CONFIG(WRT_OFF &		// Flash Memory Self-Write Protection : OFF
		VCAPEN_OFF &	// VDDCORE pin functionality is disabled
		PLLEN_OFF &		// 4x PLL disabled
		STVREN_ON &		// Stack Overflow or Underflow will not cause a Reset
		BORV_HI &		// Brown-out Reset Voltage Selection : High Voltage
		DEBUG_OFF &		// In-Circuit Debugger disabled, ICSPCLK and ICSPDAT are general purpose I/O pins
		LVP_OFF);		// Low-voltage programming : disable


#ifndef _XTAL_FREQ
	/* ？？？？？？4MHz？？？？？？？？？？？？4000000 ？？？？？？？？？？？？？？？？？？ */
	#define _XTAL_FREQ 4000000
#endif


/*
 * 
 */

/* printf？？？？？？？？？？？？？？？？？？？？？？？？？？？？？？？？？？？？？？？？？？？？？？？？？？？ */
void putch(unsigned char ch){
	i2c_lcd_putch(ch);
//	if(flag_serial_enable) rs232c_putch(ch);
	return;
}


int main(int argc, char** argv) {
    // ？？？？？？？？？？？？？？？？？？？？？
    OSCCON = 0b01101010;        // ？？？？？？？？？？？？？？？？？？？？？？？？ 4MHz
    TRISA = 0b00101111;         // IO？？？？？？？？？RA0(AN0),RA1(SCL),RA2(SDA),RA5(RX)？？？？？？？？？？？？？？？？？？？？？RA3？？？？？？？？？？？？？？？？？？？？？RA4(TX)？？？？？？？？？？？？？？？？？？
    ANSELA = 0;                 // A/D？？？？？？？？？？？？？？？
    ADCON0 = 0;                 // AN0？？？？？？, A/D？？？？？？？？？？？？
    PORTA = 0;

    INTCONbits.PEIE = 0;        // ？？？？？？？？？？？？？？？？？？？？？OFF ？？？RX？？？？？？？？？？？？？？？？？？？？？？？？？？？？？？？？？？？？
    INTCONbits.GIE = 0;         // ？？？？？？？？？？？？？？？？？？？？？OFF ？？？RX？？？？？？？？？？？？？？？？？？？？？？？？？？？？？？？？？？？？

    i2c_enable();
    OPTION_REGbits.nWPUEN = 0;  // I2C ？？？？？？？？？？？？？？？？？？？？？ ？？？？？？
    WPUA = 0b00000110;          // pull-up (RA1=SCL, RA2=SDA pull-up enable)

    // 0.5？？？？？？？？？
    __delay_ms(500);


    i2c_lcd_init();

    i2c_lcd_set_cursor_pos(0);
    printf("LCD Test");
        
    for(unsigned int i=0; i<0xfff0; i++){

        i2c_lcd_set_cursor_pos(0x40);
        printf("count %04X", i);

    }

    return (EXIT_SUCCESS);
}


/*
 * File:   lcd.c
 * Author: Admin
 *
 * Created on 21 May, 2025, 7:22 PM
 */


#include <xc.h>

// CONFIG
#pragma config FOSC = EXTRC     // Oscillator Selection bits (RC oscillator)
#pragma config WDTE = OFF        // Watchdog Timer Enable bit (WDT enabled)
#pragma config PWRTE = OFF      // Power-up Timer Enable bit (PWRT disabled)
#pragma config BOREN = OFF       // Brown-out Reset Enable bit (BOR enabled)
#pragma config LVP = OFF         // Low-Voltage (Single-Supply) In-Circuit Serial Programming Enable bit (RB3/PGM pin has PGM function; low-voltage programming enabled)
#pragma config CPD = OFF        // Data EEPROM Memory Code Protection bit (Data EEPROM code protection off)
#pragma config WRT = OFF        // Flash Program Memory Write Enable bits (Write protection off; all program memory may be written to by EECON control)
#pragma config CP = OFF         // Flash Program Memory Code Protection bit (Code protection off)

#define _XTAL_FREQ 4000000

#define rs RB0
#define rw RB1
#define en RB2

void lcd_enable() {
    en = 1;
    __delay_ms(30);
    en = 0;
}

void lcd_cmd(char cmd) {

    PORTC = cmd;
    rs = 0;
    rw = 0;
    lcd_enable();
}

void lcd_init() {

    lcd_cmd(0x38);
    lcd_cmd(0x06);
    lcd_cmd(0x0c);
    lcd_cmd(0x80);
    //lcd_cmd(0x18);



}

void print(char *data) {

    for (int i = 0; data[i] != '\0'; i++) {
        PORTC = data[i];
        rs = 1;
        rw = 0;
        lcd_enable();

    }
}

void main(void) {

    TRISB = 0x00;
    TRISC = 0x00;

    PORTB = 0x00;
    PORTC = 0x00;

    lcd_init();
    int count = 0;
    while (1){
        print("Hello world \r");
        print(count);
        count++;
        __delay_ms(10);
    }
    return;
}

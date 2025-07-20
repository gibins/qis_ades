/*
 * File:   led1.c
 * Author: Admin
 *
 * Created on 12 May, 2025, 7:23 PM
 */
// CONFIG
#pragma config FOSC = XT        // Oscillator Selection bits (XT oscillator)
#pragma config WDTE = OFF       // Watchdog Timer Enable bit (WDT disabled)
#pragma config PWRTE = OFF      // Power-up Timer Enable bit (PWRT disabled)
#pragma config BOREN = OFF      // Brown-out Reset Enable bit (BOR disabled)
#pragma config LVP = OFF        // Low-Voltage (Single-Supply) In-Circuit Serial Programming Enable bit (RB3 is digital I/O, HV on MCLR must be used for programming)
#pragma config CPD = OFF        // Data EEPROM Memory Code Protection bit (Data EEPROM code protection off)
#pragma config WRT = OFF        // Flash Program Memory Write Enable bits (Write protection off; all program memory may be written to by EECON control)
#pragma config CP = OFF         // Flash Program Memory Code Protection bit (Code protection off)
#define _XTAL_FREQ 4000000 
#include <xc.h>

void main(void) {
    /*
     * TRSIB=0x00;
     * PORTB=0x00;
     * \TRSIB=0b00000000;
     * PORTB=0b000000001;
     * 
     */
    TRISB = 0x00;
    PORTB = 0x01;

    TRISA = 0x00;
    PORTA = 0x01;

    TRISC = 0x00;
    PORTC = 0x01;
    
    ADCON1 = 0x07;

    while (1) {
        PORTB = 0x00;
        PORTC = 0x01;
        PORTA = 0x00;
        
      /*  for (int i = 0; i < 7; i++) {
            PORTA = 0x00;
            PORTB = 0x00;
            PORTC = PORTC << 1;
            __delay_ms(100);
        }
        
          PORTB = 0x01;
        for (int i = 0; i < 7; i++) {
            PORTA = 0x00;
            PORTC = 0x00;
            PORTB = PORTB << 1;
            __delay_ms(100);
        }

          PORTA = 0x01;
        for (int i = 0; i < 7; i++) {
            PORTB = 0x00;
            PORTC = 0x00;
            PORTA = PORTA << 1;
            __delay_ms(100);
        }
        */
        
              
        PORTB = 0x01;
      /*  for (int i = 0; i < 7; i++) {
            PORTA = 0x00;
            PORTC = 0x00;
            PORTB = PORTB << 1;
            __delay_ms(100);
        }*/
        
        PORTC = 0x01;
        for (int i = 0; i < 7; i++) {
            PORTA = 0x00;
            PORTB = 0x00;
            PORTC = PORTC << 1;
            __delay_ms(100);
        }
        PORTC = 0b10000000;
       /* for (int i = 0; i < 7; i++) {
            PORTA = 0x00;
            PORTB = 0x00;
            PORTC = PORTC >> 1;
            __delay_ms(100);
        }
        PORTB = 0b10000000;
        for (int i = 0; i < 7; i++) {
            PORTA = 0x00;
            PORTC = 0x00;
            PORTB = PORTB >> 1;
            __delay_ms(100);
        }
       */
      

        
        
    }

}

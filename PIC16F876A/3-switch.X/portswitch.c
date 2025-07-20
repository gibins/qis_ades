/*
 * File:   portswitch.c
 * Author: Admin
 *
 * Created on 15 May, 2025, 6:13 PM
 */

// CONFIG
#pragma config FOSC = EXTRC     // Oscillator Selection bits (RC oscillator)
#pragma config WDTE = ON        // Watchdog Timer Enable bit (WDT enabled)
#pragma config PWRTE = OFF      // Power-up Timer Enable bit (PWRT disabled)
#pragma config BOREN = ON       // Brown-out Reset Enable bit (BOR enabled)
#pragma config LVP = ON         // Low-Voltage (Single-Supply) In-Circuit Serial Programming Enable bit (RB3/PGM pin has PGM function; low-voltage programming enabled)
#pragma config CPD = OFF        // Data EEPROM Memory Code Protection bit (Data EEPROM code protection off)
#pragma config WRT = OFF        // Flash Program Memory Write Enable bits (Write protection off; all program memory may be written to by EECON control)
#pragma config CP = OFF         // Flash Program Memory Code Protection bit (Code protection off)

#define _XTAL_FREQ 4000000


#include <xc.h>

void main(void) {

    TRISA = 0xFF;
    ADCON1 = 0x07;

    TRISB = 0x00;
    PORTB = 0x00;

    TRISC = 0x00;
    PORTC = 0x00;

    int pushButtonFlag = 0;
    int counter = 0;

    while (1) {

        if (RA0 == 0 && RA1 == 0 && RA2 == 0 && RA3 == 0) {
            RB0 = 0;
            RB1 = 0;

        }

        if (RA0 == 0 && RA1 == 0 && RA2 == 0 && RA3 == 1) {
            RB0 = 1;
            RB1 = 0;

        }

        if (RA0 == 0 && RA1 == 0 && RA2 == 1 && RA3 == 0) {
            RB0 = 0;
            RB1 = 1;

        }
        if (RA0 == 0 && RA1 == 0 && RA2 == 1 && RA3 == 1) {
            RB0 = 1;
            RB1 = 1;

        }
        /*    
          if (RA0 == 1) {
              counter = counter + 1;
              while(RA0 == 1);
              if (counter == 3) {
                 //PORTB = 0xFF;
                  PORTB ^= 0xFF;
                 // __delay_ms(100);
                  counter = 0 ;
              }
              /*while (RA0 == 1) {
                  RC0 = 1;
              }*/



    //}

    // __delay_ms(100);*/



}

}

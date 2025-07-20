/*
 * File:   serial.c
 * Author: Admin
 *
 * Created on 25 May, 2025, 11:26 AM
 */

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

//char *message = " string message \r";

void print(char *message);
void read(char *message);
char receive();

void main(void) {

    TXSTA = 0x24;
    RCSTA = 0x90;
    SPBRG = 25;
    
    //TRISC6=0;
    //TRISC7=1;

    /*  
     *  // single character
      while(1) {
    
          TXREG='V';
          while(TRMT == 0);
          __delay_ms(100);
       
      }*/

    // string transmitt


    /*  
      for(int i=0;message[i];i++) {
        
          TXREG=message[i];
          while(TRMT == 0);
          __delay_ms(100);
      }
     */

    //receiving
    /* char input;
     while(1) {
         while(RCIF==0);
         input=RCREG;
         TXREG=input;
         while(TRMT ==0);
     }*/


    char input[40];
    print("\r Enter a string \0");
    ///__delay_ms(100);
    //read(input);
   // print("\r Entered string ");
   // print(input);
    

    //return;
}

void print(char *message) {
    for (int i = 0;message[i]!='/0'; i++) {

        TXREG = message[i];
        while (TRMT == 0);
        __delay_ms(100);
    }
}

void read(char *message) {
    
    for (int i = 0;; i++) {
        message[i] = receive();
        if (message[i] == '\r') {
            message[i] = '\0';
            break;
        }
    }
}

char receive() {

    char ch;
    while (RCIF == 0);
    ch = RCREG;
    return ch;
}



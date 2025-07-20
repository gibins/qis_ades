/*
 * File:   serial.c
 * Author: Admin
 *
 * Created on 25 May, 2025, 11:26 AM
 */

#pragma config FOSC = EXTRC     // Oscillator Selection bits (RC oscillator)
#pragma config WDTE = OFF        // Watchdog Timer Enable bit (WDT enabled)
#pragma config PWRTE = OFF      // Power-up Timer Enable bit (PWRT disabled)
#pragma config BOREN = ON       // Brown-out Reset Enable bit (BOR enabled)
#pragma config LVP = ON         // Low-Voltage (Single-Supply) In-Circuit Serial Programming Enable bit (RB3/PGM pin has PGM function; low-voltage programming enabled)
#pragma config CPD = OFF        // Data EEPROM Memory Code Protection bit (Data EEPROM code protection off)
#pragma config WRT = OFF        // Flash Program Memory Write Enable bits (Write protection off; all program memory may be written to by EECON control)
#pragma config CP = OFF         // Flash Program Memory Code Protection bit (Code protection off)

#define _XTAL_FREQ 400000

#include <xc.h>
#include<string.h>

void read(char *message);
char receive();
void printMessage(char *message);

int flag = 0;

void main(void) {

    TXSTA = 0x25;
    RCSTA = 0x90;
    SPBRG = 24;

    char input[40];

    //called only one time
    printMessage("\r Enter your six character password...\r");
    read(input);
    // printMessage("\r Entered string\r");
    // printMessage(input);
    // __delay_ms(100);

}

void printMessage(char *textMessage) {
    if (flag == 0) {
        for (int i = 0; textMessage[i]; i++) {

            TXREG = textMessage[i];
            while (TRMT == 0);
            //__delay_ms(50);

            //To check whether end of loop reached 
            if (i == strlen(textMessage)) {
                flag = 1;
                while (TRMT == 0);
                break;
            }
        }
    }
}

void read(char *message) {

    for (int i = 0;; i++) {

        message[i] = receive();

        if (message[i] == '\r') {
            message[i] = '\0';
            break;
        }

        printMessage("*");
    }

    printMessage(message);
    if (strcmp("123456", message) != 0) {
        printMessage("\rAuthentication Successful\r");
    } else {
        printMessage("\r Authentication Failure!!! \r");
    }

}

char receive() {

    char ch;
    while (RCIF == 0);
    ch = RCREG;
    return ch;
}




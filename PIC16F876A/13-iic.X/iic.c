
// PIC16F876A Configuration Bit Settings

// 'C' source line config statements

// CONFIG
#pragma config FOSC = EXTRC     // Oscillator Selection bits (RC oscillator)
#pragma config WDTE = OFF        // Watchdog Timer Enable bit (WDT enabled)
#pragma config PWRTE = OFF      // Power-up Timer Enable bit (PWRT disabled)
#pragma config BOREN = ON       // Brown-out Reset Enable bit (BOR enabled)
#pragma config LVP = ON         // Low-Voltage (Single-Supply) In-Circuit Serial Programming Enable bit (RB3/PGM pin has PGM function; low-voltage programming enabled)
#pragma config CPD = OFF        // Data EEPROM Memory Code Protection bit (Data EEPROM code protection off)
#pragma config WRT = OFF        // Flash Program Memory Write Enable bits (Write protection off; all program memory may be written to by EECON control)
#pragma config CP = OFF         // Flash Program Memory Code Protection bit (Code protection off)

// #pragma config statements should precede project file includes.
// Use project enums instead of #define for ON and OFF.
#define _XTAL_FREQ 4000000

#include <xc.h>
#include <stdio.h>

char time[40];
char second, minitue, hour;

void start() {
    SEN = 1;
    while (SSPIF == 0);
    SSPIF = 0;
}

int send(char ch) {
    SSPBUF = ch;
    while (SSPIF == 0);
    SSPIF = 0;
    return (ACKSTAT);

}

void stop() {
    PEN = 1;
    while (SSPIF == 0);
    SSPIF = 0;
}

void restart() {

    RSEN = 1;
    while (SSPIF == 0);
    SSPIF = 0;
}

char read() {

    RCEN = 1;
    while (SSPIF == 0);
    SSPIF = 0;
    return SSPBUF;

}

void ack() {
    ACKDT = 0;
    ACKEN = 1;
    while (SSPIF == 0);
    SSPIF = 0;


}

void nack() {
    ACKDT = 1;
    ACKEN = 1;
    while (SSPIF == 0);
    SSPIF = 0;
}

void printToSerail(char *message) {
    for (int i = 0;message[i]!='\0'; i++) {

        TXREG = message[i];
        while (TRMT == 0);
        __delay_ms(100);
    }
}

void main(void) {
    
    //uart
    
   TXSTA = 0x24;
    RCSTA = 0x90;
    SPBRG = 25;
    
    //i2c config
    
    TRISC3 = 1;
    TRISC4 = 1;
    
    SSPSTAT = 0x80;
    SSPCON = 0x28;
    SSPADD = 9;
    
   // printToSerail("Test print");

    start();
    while (send(0xD0) == 1) {
        start();
    }
    send(0x00); //address of second registre

    send(0x58);

    send(0x59);
    send(0x06);

    stop();
    //reading
   while (1) {
        start();
        while (send(0xD0) == 1) {
            start();
        }
        send(0x00);
        restart();
        send(0xD1);
        second = read();
        ack();
        minitue = read();
        ack();
        hour = read();
        nack();
        stop();
        sprintf(time, "%x:%x:%x\r\n", hour, minitue, second);
        printToSerail(time);
    }





    return;
}

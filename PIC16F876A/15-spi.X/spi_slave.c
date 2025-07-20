
// PIC16F876A Configuration Bit Settings

// 'C' source line config statements

// CONFIG
#pragma config FOSC = EXTRC     // Oscillator Selection bits (RC oscillator)
#pragma config WDTE = OFF       // Watchdog Timer Enable bit (WDT disabled)
#pragma config PWRTE = OFF      // Power-up Timer Enable bit (PWRT disabled)
#pragma config BOREN = OFF      // Brown-out Reset Enable bit (BOR disabled)
#pragma config LVP = OFF        // Low-Voltage (Single-Supply) In-Circuit Serial Programming Enable bit (RB3 is digital I/O, HV on MCLR must be used for programming)
#pragma config CPD = OFF        // Data EEPROM Memory Code Protection bit (Data EEPROM code protection off)
#pragma config WRT = OFF        // Flash Program Memory Write Enable bits (Write protection off; all program memory may be written to by EECON control)
#pragma config CP = OFF         // Flash Program Memory Code Protection bit (Code protection off)

// #pragma config statements should precede project file includes.
// Use project enums instead of #define for ON and OFF.

#define _XTAL_FREQ 4000000
#include <xc.h>
#include <stdio.h>

void uart_init() {
    TXSTA = 0x24;
    RCSTA = 0x90;
    SPBRG = 25;
}

void print_to_serial(char message) {
    //for (int i = 0;message[i]!='\0'; i++) {

        TXREG = message;
        while (TRMT == 0);
        //__delay_ms(40);
    //}
}

void  spi_slave_init() {
    SSPSTAT = 0x00;
    SSPCON = 0x25;
   // TRISC |=(0<<3)|(1<<4)|(0<<5);
    TRISC = (1<<3)|(1<<4);
    
}
char spi_receive_char() 
{
    char receivedChar;
    while(SSPIF == 0);
    receivedChar = SSPBUF;
    SSPIF=0;
    return receivedChar;
}

void main(void) {
    
    spi_slave_init();
    uart_init(); 
    
    // print_to_serial("R\r");
    while(1) {
         //print_to_serial("\r Reading...\r");
       char receivedChar =  spi_receive_char();
       print_to_serial(receivedChar);
       __delay_ms(45);
        
    }
    return;
}

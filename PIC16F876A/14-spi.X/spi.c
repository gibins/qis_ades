
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
#include <string.h>

void uart_init() 
{
    TXSTA = 0x24;
    RCSTA = 0x90;
    SPBRG = 25;
}

char uart_receive() {

    char ch;
    while (RCIF == 0);
    ch = RCREG;
    TXREG = ch;
    while(TRMT == 0);
    
    return ch;
}

void  spi_master_init() {
    SSPSTAT = 0x00;
    SSPCON = 0x20;
    //TRISC |=(0<<3)|(1<<4)|(0<<5);
    TRISC = (1<<4);
    
}

void send_to_spi(char ch) {
    SSPBUF=ch;
    while(SSPIF == 0);
    SSPIF=0;
   __delay_ms(45);
}


void main(void) {
    
    PORTC = 0x00;
    uart_init();
    spi_master_init();
    
    /**while(1) {
        send_to_spi('A');
    }**/
   /* char message[] = "\r Test Message \r";
    for(int i=0;message[i];i++) {
        send_to_spi(message[i]);
    }*/
    //send_to_spi('T');
    while(1) {
    char uartBuffer = uart_receive();
    send_to_spi(uartBuffer);
    }
    
    return;
}

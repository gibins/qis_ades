
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

/*
 
 Method to configure registers for UART and ADC 
 */
void configRegiters() {
    //For Serial port
    TXSTA = 0x24;
    RCSTA = 0x90;
    SPBRG = 25;

    //For ADC
   // TRISB = TRISC = 0;
    TRISA0 = 1;
    TRISA1 = 1;
    
    ADCON1 = 0x80;
    ADCON0 = 0x41;

}

/*
 Method to send data to serial
 */
void printMessage(char *message) {

    for (int i = 0; message[i] != '\0'; i++) {
        TXREG = message[i];
        while (TRMT == 0);
    }

}

void main(void) {
    
    int adc_result; 
    char encoded_result[40];
    
    configRegiters();


    while (1) {
        ADCON0 = 0x41;
        GO = 1;
        while (GO == 1);
        // PORTB=ADRESL;
        // PORTC=ADRESH;
        adc_result = (ADRESH << 8) | ADRESL;
        sprintf(encoded_result, "ADC 0 Value %d",adc_result);
        printMessage("\r");
        printMessage(&encoded_result);
        __delay_ms(30);
        //second channel
        ADCON0 = 0x51;
         GO = 1;
        while (GO == 1);
        adc_result = (ADRESH << 8) | ADRESL;
        sprintf(encoded_result, "ADC 2 Value %d",adc_result);
        printMessage("\r");
        printMessage(&encoded_result);
         
         
        
    }

}

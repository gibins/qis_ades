
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

void configRegisters() {
    //For Serial port
    TXSTA = 0x24;
    RCSTA = 0x90;
    SPBRG = 25;

    //For ADC

    TRISA = 0xFF;
    ADCON1 = 0x80;
    //ADCON0 = 0x41;
    
    //For Switch
    
    TRISB = 0xFF;

}
/*
 * Method to get adcon0 address;
 */
int getAdconReg(int pos) {
    
    int adcon0[]={ 0x41,0x49,0x51,0x59,0x61};
    return adcon0[pos];
    
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
    int adc_channel_number=0;
    
    configRegisters(); 
    
    while(1)
    {
        if(RB0 == 1) {
           // while(RB0==1);
            __delay_ms(200);
           adc_channel_number++; 
           
        }
        if(RB0 == 1 && adc_channel_number > 4)
        {
            adc_channel_number = 0;
        }
        
        ADCON0 = getAdconReg(adc_channel_number);
        GO = 1;
        while (GO == 1);
        // PORTB=ADRESL;
        // PORTC=ADRESH;
        adc_result = (ADRESH << 8) | ADRESL;
        sprintf(encoded_result, "\rADC Channel %d Value %d", adc_channel_number, adc_result);
        printMessage(&encoded_result);
    }
    
    return;
}

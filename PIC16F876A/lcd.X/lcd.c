/*
 * File:   lcd.c
 * Author: Admin
 *
 * Created on 21 May, 2025, 7:22 PM
 */


#include <xc.h>

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

#define rs RB0
#define rw RB1
#define en RB2


void lcd_enable();
void lcd_init();
void print(char *data);
void lcd_cmd(char cmd);

//4bit functions
void Forbitdata(unsigned char b);
void Fourbitcmd(unsigned char a);

void lcd_cmd(char cmd){

    PORTC = cmd;
    rs = 0;
    rw = 0;
    lcd_enable();
}


void lcd_init() {
   /*
    lcd_cmd(0x38);
    lcd_cmd(0x06);
    lcd_cmd(0x0c);
    lcd_cmd(0x01);
    */
   
    
}

void Forbit_init() {

  Fourbitcmd(0x02);
    Fourbitcmd(0x28);
    Fourbitcmd(0x0c);
    Fourbitcmd(0x06);
    //Fourbitcmd(0x80);    
}

void lcd_enable() {
    en = 1;
    __delay_ms(30);
    en = 0;
}


void print(char *data) {

    for(int i=0;data[i]!='\0';i++){
    /*PORTC = data[i];
    rs = 1;
    rw = 0;
    lcd_enable();*/
    
        Forbitdata(data[i]);
    
    }
}

void main(void) {
    TRISB = 0x00;
    TRISC = 0x00;

    PORTB = 0x00;
    PORTC = 0x00;
   /* lcd_init();
    lcd_cmd(0x80);
    print("Hello");*/
    
    Forbit_init();
    Fourbitcmd(0x80);
    print("Hello ");
    //Forbitdata('G');
    
    
    while(1);
    //return;
}


void Fourbitcmd(unsigned char a)
{
    rs=0; 
    PORTC&=0x0F;
    PORTC|=(a&0xf0);
 
    lcd_enable();
    
    PORTC&=0x0f;
    PORTC|=(a<<4&0xf0);

    lcd_enable();
}

void Forbitdata(unsigned char b)
{
    rs=1; 
   
    PORTC&=0x0F;
    PORTC|=(b&0xf0);
    
   lcd_enable();
   
    PORTC&=0x0f;
    PORTC|=(b<<4&0xf0);
    
    lcd_enable();
    
}



#include <xc.h>
#include <string.h>
#define _XTAL_FREQ 4000000

#define RS RC0
#define EN RC1
#define D4 RC2
#define D5 RC3
#define D6 RC4
#define D7 RC5

void Lcd_Command(unsigned char cmd, int par1, int par2);
void Lcd_Char(unsigned char data);
void Lcd_Init();
void Lcd_String(const char *str);
void Lcd_Clear();
void Lcd_Set_Cursor(unsigned char row, unsigned char col);

void Lcd_Command(unsigned char cmd, int par1, int par2) {
    RS = 0;
    D4 = (cmd >> 4) & 1;
    D5 = (cmd >> 5) & 1;
    D6 = (cmd >> 6) & 1;
    D7 = (cmd >> 7) & 1;
    EN = 1; __delay_ms(2); EN = 0;

    D4 = cmd & 1;
    D5 = (cmd >> 1) & 1;
    D6 = (cmd >> 2) & 1;
    D7 = (cmd >> 3) & 1;
    EN = 1; __delay_ms(2); EN = 0;
}

void Lcd_Char(unsigned char data) {
    RS = 1;
    D4 = (data >> 4) & 1;
    D5 = (data >> 5) & 1;
    D6 = (data >> 6) & 1;
    D7 = (data >> 7) & 1;
    EN = 1; __delay_ms(2); EN = 0;

    D4 = data & 1;
    D5 = (data >> 1) & 1;
    D6 = (data >> 2) & 1;
    D7 = (data >> 3) & 1;
    EN = 1; __delay_ms(2); EN = 0;
}

void Lcd_Init() {
    //TRISD = 0x00;
    RS = EN = 0;
    Lcd_Command(0x02, 0, 0);
    Lcd_Command(0x28, 0, 0);
    Lcd_Command(0x0C, 0, 0);
    Lcd_Command(0x06, 0, 0);
    Lcd_Command(0x01, 0, 0);
}

void Lcd_String(const char *str) {
    while (*str)
        Lcd_Char(*str++);
}

void Lcd_Clear() {
    Lcd_Command(0x01, 0, 0);
}

void Lcd_Set_Cursor(unsigned char row, unsigned char col) {
    char pos = (row == 1) ? (0x80 + col - 1) : (0xC0 + col - 1);
    Lcd_Command(pos, 0, 0);
}



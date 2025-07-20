#include <xc.h>
#include <stdlib.h>
#include "lcd.h"
#include "keypad.h"
// CONFIG
#pragma config FOSC = XT     // Oscillator Selection bits (RC oscillator)
#pragma config WDTE = OFF        // Watchdog Timer Enable bit (WDT enabled)
#pragma config PWRTE = OFF      // Power-up Timer Enable bit (PWRT disabled)
#pragma config BOREN = OFF       // Brown-out Reset Enable bit (BOR enabled)
#pragma config LVP = OFF         // Low-Voltage (Single-Supply) In-Circuit Serial Programming Enable bit (RB3/PGM pin has PGM function; low-voltage programming enabled)
#pragma config CPD = OFF        // Data EEPROM Memory Code Protection bit (Data EEPROM code protection off)
#pragma config WRT = OFF        // Flash Program Memory Write Enable bits (Write protection off; all program memory may be written to by EECON control)
#pragma config CP = OFF         // Flash Program Memory Code Protection bit (Code protection off)

#define _XTAL_FREQ 4000000

char num1_str[10] = "";
char num2_str[10] = "";
char op = 0;
char key;
unsigned int i = 0, j = 0;
float result = 0;
__bit second_operand = 0;

void main() {
    Lcd_Init();
    Keypad_Init();
    Lcd_Clear();
    Lcd_Set_Cursor(1, 1);
    Lcd_String("Calculator");

    while (1) {
        key = Keypad_Scan();
        if (key) {
            if (key >= '0' && key <= '9') {
                if (!second_operand) {
                    num1_str[i++] = key;
                    num1_str[i] = '\0';
                    Lcd_Set_Cursor(2, i);
                    Lcd_Char(key);
                } else {
                    num2_str[j++] = key;
                    num2_str[j] = '\0';
                    Lcd_Set_Cursor(2, i + j + 1);
                    Lcd_Char(key);
                }
            } else if (key == '+' || key == '-' || key == '*' || key == '/') {
                if (!second_operand) {
                    op = key;
                    second_operand = 1;
                    Lcd_Set_Cursor(2, i + 1);
                    Lcd_Char(op);
                }
            } else if (key == '=') {
                float n1 = atof(num1_str);
                float n2 = atof(num2_str);
                switch (op) {
                    case '+': result = n1 + n2; break;
                    case '-': result = n1 - n2; break;
                    case '*': result = n1 * n2; break;
                    case '/': result = (n2 != 0) ? (n1 / n2) : 0; break;
                }
                char res_str[16];
                //sprintf(res_str, "%.2f", result);
                Lcd_Clear();
                Lcd_Set_Cursor(1, 1);
                Lcd_String("Result:");
                Lcd_Set_Cursor(2, 1);
                Lcd_String(res_str);
                __delay_ms(3000);
                i = j = 0;
                num1_str[0] = num2_str[0] = '\0';
                second_operand = 0;
                Lcd_Clear();
                Lcd_Set_Cursor(1, 1);
                Lcd_String("Calculator");
            } else if (key == 'C') {
                i = j = 0;
                num1_str[0] = num2_str[0] = '\0';
                second_operand = 0;
                Lcd_Clear();
                Lcd_Set_Cursor(1, 1);
                Lcd_String("Calculator");
            }
        }
    }
}

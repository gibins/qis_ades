
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

#include <xc.h>
#include <string.h>

#define _XTAL_FREQ 4000000

void config();

void createPassword();
void printMessage();
char receiveCharacter();
void readMessage();
void validatePassword(char *password);

char *userPassword[40];
int resetMode = 0;

void configRegistres() {

    TXSTA = 0x24;
    RCSTA = 0x90;
    SPBRG = 25;

}

void printMessage(char *message) {

    for (int i = 0; message[i] != '\0'; i++) {
        TXREG = message[i];
        while (TRMT == 0);
    }

}

char receiveCharacter() {

    while (RCIF == 0);
    return RCREG;

}

void readMessage(char *message) {

    for (int i = 0;; i++) {
        message[i] = receiveCharacter();
        if (message[i] == '\r') {
            message[i] = '\0';
            break;
        }
        printMessage("*");
    }

}

void createPassword() {

    if (strlen(userPassword) == 0 ) {
        printMessage("\r Enter New Password \r");
        readMessage(userPassword);

        if (strcmp(userPassword, NULL)) {
           resetMode = 1;
            printMessage("\r User password updated successfully \r");
        } else {
            printMessage("\r Unable to update user password Contact support \r");
        }
    }
    printMessage("\r Reset Mode ");
    printMessage(resetMode);
    printMessage("\r Password Hint ");
    printMessage(strlen(userPassword));
}

void validatePassword(char *password) {
    char *stockPassword = "123456";
    /*
     * if userpassword is  not null then validate userpassword
     * if userpassword is null then validate with stockpassword
     */
    if (!strcmp(userPassword, "")) {

        if (!strcmp(password, stockPassword)) {
            printMessage("\r Authentication Successful!!!\r");
        } else {
            printMessage("\r Authentication Failed!!!\r");
        }
    } else {
        if (!strcmp(password, userPassword)) {
            printMessage("\r Authentication Successful!!!\r");
        } else {
            printMessage("\r Authentication Failed!!!\r");
        }
    }

}

void main(void) {

    char *serialBuffer[40];

    configRegistres();
    if(resetMode == 0) {
    createPassword();}

    printMessage("\r Enter Password \r");
    readMessage(serialBuffer);

    validatePassword(serialBuffer);

    return;
}

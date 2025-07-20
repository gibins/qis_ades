#include <xc.h>


const char keypad_map[4][4] = {
    {'1','2','3','A'},
    {'4','5','6','B'},
    {'7','8','9','C'},
    {'*','0','#','D'}
};

char Keypad_Scan() {
    for (int row = 0; row < 4; row++) {
        PORTB = ~(1 << row);  // pull current row low
        for (int col = 0; col < 4; col++) {
            if (!(PORTB & (1 << (col + 4)))) {
                __delay_ms(20); // debounce
                while (!(PORTB & (1 << (col + 4))));
                return keypad_map[row][col];
            }
        }
    }
    return 0;
}

void Keypad_Init() {
    TRISB = 0xF0; // RB0?RB3 output (rows), RB4?RB7 input (columns)
    PORTB = 0xFF;
}


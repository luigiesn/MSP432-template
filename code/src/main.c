#include "msp.h"
#include <stdint.h>

/* Change the color of the RGB led */ 

int main(void) {
    volatile uint32_t i;

    P2->DIR |= 0x7;

    for (;;) {
        P2->OUT = (P2->OUT & 0b111) >> 1;
        if ((P2->OUT & 0b111) == 0) {
            P2->OUT = 0b100;
        }

        for (i = 100000; i > 0; i--);
    }
}


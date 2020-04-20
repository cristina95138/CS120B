/*	Author: cristinalawson
 *  Partner(s) Name: 
 *	Lab Section:
 *	Assignment: Lab #4  Exercise #1
 *	Exercise Description: [optional - include for your own benefit]
 *
 *	I acknowledge all content contained herein, excluding template or example
 *	code, is my own original work.
 */
#include <avr/io.h>
#ifdef _SIMULATE_
#include "simAVRHeader.h"
#endif

enum States {Start, Init, BP0 , BR0, BP1, BR1} state;

int TickFct() {
    
	switch (state) {
		case Start:
			state = Init;
			break;
		case Init:
			if (PINA) {
				state = BP0;
			} else {
				state = Init;
			}
			break;
		case BP0:		
			if (!PINA) {
				state = BR0;
			} else {
				state = BP0;
			}
			break;
		case BR0:
                        if (PINA) {
                                state = BP1;
                        } else {
                                state = BR0;
                        }
                        break;
		case BP1:
			if (!PINA) {
				state = BR1;
			} else {
				state = BP1;
			}
			break;
		case BR1:
			if (PINA) {
				state = BP0;
			} else {
				state = BR1;
			}
			break;
		default:
			state = Start;
			break;

	}
	
	switch (state) {
		case Init:
			PORTB = ((PORTB & 0xFC) | 0x01);
			break;
		case BP0:
			PORTB = ((PORTB & 0xFC) | 0x02);
			break;
		case BR0:
			PORTB = ((PORTB & 0xFC) | 0x02);
                        break;
		case BP1: 
			PORTB = ((PORTB & 0xFC) | 0x01);
                        break;
		case BR1:
		default: break;
	}
}

int main(void) {
   state = Start;
   DDRA = 0x00; PORTA = 0xFF;
   DDRB = 0xFF; PORTB = 0x00;

    while (1) {
	TickFct();
    }
    return 1;
}

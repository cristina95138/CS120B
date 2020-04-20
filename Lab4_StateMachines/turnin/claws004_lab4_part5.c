/*	Author: cristinalawson
 *  Partner(s) Name: 
 *	Lab Section:
 *	Assignment: Lab #4  Exercise #5
 *	Exercise Description: [optional - include for your own benefit]
 *
 *	I acknowledge all content contained herein, excluding template or example
 *	code, is my own original work.
 */
#include <avr/io.h>
#ifdef _SIMULATE_
#include "simAVRHeader.h"
#endif

enum States {Start, S1, S2} state;
unsigned char nums[8] = {0x04, 0x00, 0x01, 0x00, 0x02, 0x00, 0x02, 0x00};
unsigned char num;

int TickFct() {
    
	switch (state) {
		case Start: state = S1; break;
		case S1:		
			if ((PINA & 0x80) == 0x80) {
				state = Start;
			}
			if (num == 7) {
				state = S2;
			}
			break;
		case S2: state = Start; break;
		default:
			state = Start;
			break;
	}
	
	switch (state) {
		case Start: break;
		case S1:
			if ((PINA & 0x80) == 0x80) {
				PORTB = 0x00;
				num = 0;
			}
			if ((PINA & 0x07) == nums[num]) {
				num = num + 1;
			} else {
				num = 0;
			}
			break;
		case S2:
			if ((PORTB & 0x00) == 0x00) {
				PORTB = 0x01;
			} else {
				PORTB = 0x00;
			}
 			num = 0;
			break;
		default: PORTB = 0x00; break;
	}
}

int main(void) {
   state = Start;
   num = 0;
	
   DDRA = 0x00; PORTA = 0xFF;
   DDRB = 0xFF; PORTB = 0x00;

    while (1) {
	TickFct();
    }
    return 1;
}

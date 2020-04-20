/*	Author: cristinalawson
 *  Partner(s) Name: 
 *	Lab Section:
 *	Assignment: Lab #4  Exercise #4
 *	Exercise Description: [optional - include for your own benefit]
 *
 *	I acknowledge all content contained herein, excluding template or example
 *	code, is my own original work.
 */
#include <avr/io.h>
#ifdef _SIMULATE_
#include "simAVRHeader.h"
#endif

enum States {Start, S1, S2, S3} state;

int TickFct() {
    
	switch (state) {
		case Start:
			if ((PINA & 0x07) == 0x04) {
				state = S1;
			} else {
				state = Start;
			}
			break;
		case S1:		
			if ((PINA & 0x07) == 0x04) {
				state = S1;
			} else if ((PINA & 0x07) == 0x00) {
				state = S2;
			} else {
				state = Start;
			}
			break;
		case S2:
                        if ((PINA & 0x07) == 0x00)  {
				state = S2;
			} else if ((PINA & 0x07) == 0x02) {
				state = S3;
			} else {
				state = Start;
			}
                        break;
		case S3:
			if ((PINA & 0x80) == 0x80) {
				state = Start;
			}
			state = Start;
			break;
		default: state = Start; break;

	}
	
	switch (state) {
		case Start:
		case S1:
		case S2:
			if ((PINA & 0x80) == 0x80) {
				PORTB = 0x00;
			}
			break;
		case S3: 
			if ((PINA & 0x80) == 0x80) {
				PORTB = 0x00;
			} else if (PORTB == 0x01) {
				PORTB = 0x00;
			} else if (PORTB == 0x00) {
				PORTB = 0x01;
			}
			break;
		default: PORTB = 0x00; break;
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

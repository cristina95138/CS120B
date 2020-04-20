/*	Author: cristinalawson
 *  Partner(s) Name: 
 *	Lab Section: 021
 *	Assignment: Lab #3  Exercise #3
 *	Exercise Description: [optional - include for your own benefit]
 *
 *	I acknowledge all content contained herein, excluding template or example
 *	code, is my own original work.
 */
#include <avr/io.h>
#ifdef _SIMULATE_
#include "simAVRHeader.h"
#endif

int main(void) {
	DDRA = 0x00;  PORTA = 0xFF;
	DDRB = 0x00;  PORTB = 0xFF;
	DDRC = 0xFF;  PORTC = 0x00;
	
	unsigned char count = 0x00;
	unsigned char A = 0x00;
	unsigned char B = 0x00;

    while (1) {
	A = PINA & 0x0F;

	if (A == 0) {
		count = 0x40;
	}
	else if ((A == 1) || (A == 2)) {
		count = 0x60;
	}
	else if ((A == 3) || (A == 4)) {
                count = 0x70;
	}
	else if ((A == 5) || (A == 6)) {
                count = 0x38;
	}
	else if ((A == 7) || (A == 8) || (A == 9)) {
                count = 0x3C;
	}
	else if ((A == 10) || (A == 11) || (A == 12)) {
		count = 0x3E;
	}
	else if ((A == 13) || (A == 14) || (A == 15)) {
                count = 0x3F;
	}

	A = PINA & 0x70;

	if (A == 0x30) {
		count = count + 0x80;
	}	
		
	PORTC = count;	
    }
    return 1;
}

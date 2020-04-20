/*	Author: cristinalawson
 *  Partner(s) Name: 
 *	Lab Section: 021
 *	Assignment: Lab #3  Exercise #5
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
	DDRB = 0xFE;  PORTB = 0x01;
	DDRD = 0x00;  PORTD = 0xFF;
	
	unsigned char count = 0x00;
	unsigned char B = 0x00;
	unsigned char temp = 0x00;

    while (1) {
	B = PINB & 0x01;
	count  = PIND << 1;

	count = count | B;

	if (count >= 0x46) {
		temp = 0x02;
	}
	else if ((count > 0x05) && (count < 0x46)) {
		temp = 0x04;
	}
	else if (count <= 0x05) {
		temp = 0x00;
	}
	else if (count == 0) {
		temp = 0x00;
	}

	PORTB = temp;
	temp = 0x01;
	count = 0x00;
    }
    return 1;
}

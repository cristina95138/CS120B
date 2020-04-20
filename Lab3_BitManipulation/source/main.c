/*	Author: cristinalawson
 *  Partner(s) Name: 
 *	Lab Section: 021
 *	Assignment: Lab #3  Exercise #1
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
	A = PINA;
	B = PINB;

	while (A > 0) {
		count = count + (A & 0x01);
		A = A >> 1
	}

	while (B > 0) {
		count = count + (B & 0x01);
		B = B >> 1;
	}

	PORTC = count;
    }
    return 1;
}

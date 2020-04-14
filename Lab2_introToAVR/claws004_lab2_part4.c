/*	Author: cristinalawson
 *  Partner(s) Name: 
 *	Lab Section: 021
 *	Assignment: Lab #2  Exercise #4
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
	DDRA = 0x00; PORTA = 0xFF; // Configure port A's 8 pins as inputs
	DDRB = 0xFF; PORTB = 0xFF; // Configure port B's 8 pins as outputs
							// Initialize output on PORTB to 0x00
	DDRC = 0x00; PORTC = 0xFF;
	DDRD = 0xFF; PORTD = 0x00;

	unsigned char A = 0x00;
	unsigned char B = 0x00;
	unsigned char C = 0x00;
	unsigned short weight = 0x0000;
	unsigned char diff = 0x00;
	unsigned char temp = 0x00;
	
	while(1) {

		weight = A + B + C;
		
		if ((abs(A - C)) >= 0x50) {
			diff = 0x02;
		}
		
		if (weight >= 0x008C) {
			temp = 0x01;
		}

		PORTD = temp | diff;
		temp = 0x00;
		diff = 0x00;
		weight = 0x0000;
	}
	return 0;
}

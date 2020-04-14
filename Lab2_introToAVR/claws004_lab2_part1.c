/*	Author: cristinalawson
 *  Partner(s) Name: 
 *	Lab Section: 021
 *	Assignment: Lab #2  Exercise #1
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
	DDRB = 0xFF; PORTB = 0x00; // Configure port B's 8 pins as outputs
							// Initialize output on PORTB to 0x00
	unsigned char PAZERO = 0x00;
	unsigned char PAONE = 0x00;
	
	while(1) {
		PAZERO = PINA & 0x01;
		PAONE = PINA & 0x02;

		if((PAZERO == 0x01) && (PAONE == 0x00)) {
			PORTB = 0x01;
		}
		else {
			PORTB = 0x00;
		}
	}
	return 0;
}

/*	Author: cristinalawson
 *  Partner(s) Name: 
 *	Lab Section: 021
 *	Assignment: Lab #2  Exercise #2
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
	unsigned char available = 0x00;
	unsigned char one = 0x00;
	unsigned char two = 0x00;
	unsigned char three = 0x00;
	unsigned char four = 0x00;
	
	while(1) {
		one = PINA & 0x01;
		two = PINA & 0x02;
		three = PINA & 0x04;
		four = PINA & 0x08;

		two = two >> 1;
		three = three >> 2;
		four = four >> 3;

		available = one + two + three + four;
		available = 0x04 - available;
		PORTC = available;
	}
	return 0;
}

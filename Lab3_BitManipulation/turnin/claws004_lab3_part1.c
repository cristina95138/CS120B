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

unsigned char GetBit(unsigned char temp_one, unsigned temp_two){//helper function from zybook
	return ((temp_one & (0x01 << temp_two)) != 0);
}

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

	for (unsigned char i = 0x00; i < 0x08; i = i + 0x01) {
		count = count + GetBit(A, i);
		count = count + GetBit(B, i);
	}

	PORTC = count;
	count = 0x00;
    }
    return 1;
}

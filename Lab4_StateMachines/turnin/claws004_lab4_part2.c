/*	Author: cristinalawson
 *  Partner(s) Name: 
 *	Lab Section:
 *	Assignment: Lab #4  Exercise #2
 *	Exercise Description: [optional - include for your own benefit]
 *
 *	I acknowledge all content contained herein, excluding template or example
 *	code, is my own original work.
 */
#include <avr/io.h>
#ifdef _SIMULATE_
#include "simAVRHeader.h"
#endif

enum States {Start, Init, B0P, B1P, B01P, M0, M1} state;

int TickFct() {
    
	switch (state) {
		case Start:
			state = Init;
			break;
		case Init:
			if ((PINA & 0x03) == 0x01) {
				state = B0P;
			} else if ((PINA & 0x03) == 0x02) {
				state = B1P;
			} else if ((PINA & 0x03) == 0x03) {
				state = B01P;
			}
			break;
		case B0P:		
			if ((PINA & 0x03) == 0x01) {
                                state = M0;
                        } else if ((PINA & 0x03) == 0x02) {
                                state = B1P;
                        } else if ((PINA & 0x03) == 0x03) {
                                state = B01P;
                        }
			break;
		case B1P:
                        if ((PINA & 0x03) == 0x01) {
                                state = B0P;
                        } else if ((PINA & 0x03) == 0x02) {
                                state = M1;
                        } else if ((PINA & 0x03) == 0x03) {
                                state = B01P;
                        }
                        break;
		case B01P:
			if ((PINA & 0x03) == 0x01) {
                                state = B0P;
                        } else if ((PINA & 0x03) == 0x02) {
                                state = B1P;
                        } else if ((PINA & 0x03) == 0x03) {
                                state = B01P;
                        }
			break;
		case M0:
			if ((PINA & 0x03) == 0x00) {
				state = Init;
			} else if ((PINA & 0x03) == 0x01) {
                                state = M0;
                        } else if ((PINA & 0x03) == 0x02) {
                                state = B1P;
                        } else if ((PINA & 0x03) == 0x03) {
                                state = B01P;
     			}
                        break;
		case M1:
			if ((PINA & 0x03) == 0x00) {
                                state = Init;
                        } else if ((PINA & 0x03) == 0x01) {
                                state = B0P;
                        } else if ((PINA & 0x03) == 0x02) {
                                state = M1;
                        } else if ((PINA & 0x03) == 0x03) {
                                state = B01P;
                        }
                        break;
		default:
			state = Start;
			break;

	}
	
	switch (state) {
		case Init: break;
		case B0P:
			if (PORTC < 0x09) {
				PORTC = PORTC + 1;
			}
			break;
		case B1P:
			if (PORTC > 0x00) {
				PORTC = PORTC - 1;
			}
			break;
		case B01P: PORTC = 0x00; break;
		case M0: PORTC = PORTC; break;
		case M1: PORTC = PORTC; break;
		default: PORTC = 0x07; break;
	}
}

int main(void) {
   state = Start;
   DDRA = 0x00; PORTA = 0xFF;
   DDRB = 0xFF; PORTB = 0x00;
   
   PORTC = 0x07;
    
    while (1) {
	TickFct();
    }
    return 1;
}

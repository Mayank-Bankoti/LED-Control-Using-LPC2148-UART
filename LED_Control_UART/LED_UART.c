#include "LPC214X.h"
#define LED_PIN (1 << 11)

unsigned char receive()
{
	while(!(U0LSR & 0x01));
	return (U0RBR);
}

void transmit(unsigned char ch)
{
 while (!(U0LSR & 0x20));
 
 U0THR =ch;
}


int main()
 {
	 unsigned char  temp[30] = "Welcome to FC" ;
	 IO0DIR |= LED_PIN;
 	 PINSEL0 = 5;
	 U0LCR = 0x83;
	 U0DLM =0x00;
	 U0DLL =97;
	 U0LCR =0x03;
	 while(1)
	 {
 char command = receive();  // Receive a character from UART

        // If the received command is '1', turn ON the LED; if '0', turn OFF the LED
        if (command == '1') {
            IO0SET = LED_PIN;  // Turn ON the LED
        } else if (command == '0') {
            IO0CLR = LED_PIN;  // Turn OFF the LED
        }
	 }
	 return 0;
}
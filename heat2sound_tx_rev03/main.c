#include <atmel_start.h>
#include <avr/io.h>
#include <avr/interrupt.h>

#define LED PB0


//ISR (TIMER1_COMPA_vect) //Timer1 ISR

//ISR (TIMER1_OVF_vect) //Timer1 ISR
ISR (TIMER0_OVF_vect) //Timer0 ISR
{
	//clock is 16Mhz/256=250,000hz
	//for 440hz 250,000/440=568.18
	PORTB ^= (1 << LED);
	//TCNT1 = 568; //for 440hz
	TCNT0 = 1;//18; //8 bit only for 880hz (440hz full cycle)
	
}

int main(void)
{
	/* Initializes MCU, drivers and middleware */
	atmel_start_init();
	
	TCNT0 = 1;//18; //8 bit only for 440hz
	//TCNT1 = 568; //for 440hz

	//TCCR1A = 0x00;
	//TCCR1B = (1 << CS10) | (1 << CS12);  //Timer mode with 1024 prescaler 
	//TCCR1B |= (0 << CS12) | (0 << CS11) | (1 << CS10); /* no prescaling */
	//TIMSK1 = (1 << TOIE1); //enable timer1 overflow interrupt (TOIE1)
	//TIMSK1 = (1 << OCIE1A); //enable timer1 output compare interrupt
	//OCR1A = 1;//

	//sei(); //Enable global interrupts by setting global interrupt enable

	/* Replace with your application code */
	while (1) {
	}
}

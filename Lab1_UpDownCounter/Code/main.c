#include<avr/io.h>
#include<util/delay.h>
/* values of A B C D E F G for pins from PA1 : PA7*/
	unsigned char digits[10]={0b0111111,
							  0b0000110,
							  0b1011011,
							  0b1001111,
							  0b1100110,
							  0b1101101,
							  0b1111101,
							  0b0000111,
							  0b1111111,
							  0b1100111};
/* Setting direction for Count up Button */
void SW1_Init(void)
{
	DDRD &= ~(1<<2);
}
/* Setting direction for Count Down Button */
void SW2_Init(void)
{
	DDRD &= ~(1<<3);
}
/* Setting direction for Reset Button */
void SW3_init(void)
{
	DDRD &= ~(1<<4);
}
/* Setting Direction for the Multiplixed 7-semgents*/
void Multiplixed_7Seg_Init(void)
{
	DDRA |= (1<<1) | (1<<2) | (1<<3) | (1<<4) | (1<<4) | (1<<5) | (1<<6) | (1<<7);
	/* Direction of Control pins for 1st and 2nd 7-semgnet on the same PORT */
	DDRC |= (1<<6) | (1<<7);
}
/* Activate the 1st segmgent only on PORTA and Disable 2nd 7-sement */
void Enable_first_only(void)
{
	PORTC = (PORTC&0) | (1<<6);
}
/* Activate the 2nd segmgent only on PORTA and Disable 1st 7-sement */
void Enable_second_only(void)
{
	PORTC = (PORTC&0) | (1<<7);
}
int main(void)
{
	signed char first_seg_value=0, second_seg_value=0;
	Multiplixed_7Seg_Init();
	SW1_Init();
	SW2_Init();
	SW3_init();
	while(1)
	{
		Enable_first_only();
		PORTA = (PORTA&0)|(digits[first_seg_value]<<1);
		_delay_ms(5);
		Enable_second_only();
		PORTA = (PORTA&0)|(digits[second_seg_value]<<1);
		_delay_ms(5);
		/* Checking if the Count Up Button is pressed */
		if(!(PIND & (1<<2)))
		{
			_delay_ms(30); /* small delay for debouncing */
			if(!(PIND & (1<<2)))
			{
				first_seg_value++;
				if(first_seg_value == 10)
				{
					first_seg_value = 0;
					second_seg_value++;
					if(second_seg_value == 10)
					{
						second_seg_value = 0;
					}
				}
			}
			while(!(PIND & (1<<2))){};
		}
		/* Checking if the Count Down Button is pressed */
		else if(!(PIND & (1<<3)))
		{
			_delay_ms(30); /* small delay for debouncing */
			if(!(PIND & (1<<3)))
			{
				first_seg_value--;
				if(first_seg_value == -1 && second_seg_value == 0)
				{
					first_seg_value = 0;
				}
				else if(second_seg_value >0 && first_seg_value == -1)
				{
					first_seg_value = 9;
					second_seg_value--;
				}
				else if(second_seg_value == -1)
				{
					second_seg_value = 0;
				}
			}
			while(!(PIND & (1<<3))){};
		}
		/* Checking if the Reset Button is pressed */
		else if(!(PIND & (1<<4)))
		{
			_delay_ms(30); /* small delay for debouncing */
			if(!(PIND & (1<<4)))
			{
				first_seg_value = 0;
				second_seg_value = 0;
			}
			while(!(PIND & (1<<4))){};
		}
	}
}

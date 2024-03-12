#include "STD_TYPES.h"
#include <avr/delay.h>
#include "DIO_interface.h"
#include "CLCD_interface.h"

void main(void)
{
	uint8 Local_u8Counter;
	DIO_u8SetPortDirection(DIO_u8PORTA,DIO_u8PORT_OUTPUT);

	CLCD_voidInit();

	while(1)
	{
		for (Local_u8Counter = 0; Local_u8Counter < 5; Local_u8Counter++)
		{
			CLCD_voidGoToXY(Local_u8Counter,0);
			CLCD_u8SendString("Hello");
			_delay_ms(1000);
			CLCD_voidSendCmd(1);

		}

		for (Local_u8Counter = 5; Local_u8Counter > 0; Local_u8Counter--)
		{
			CLCD_voidGoToXY(Local_u8Counter,0);
			CLCD_u8SendString("Hello");
			_delay_ms(1000);
			CLCD_voidSendCmd(1);
		}
	}
}

/*
 * LED.c
 *
 *  Created on: Aug 12, 2026
 *      Author: youssef sayed
 */
#include "../../LIB/BitMath.h"
#include "../../LIB/STd_Types.h"

#include "../../MCAL/DIO/DIO.h"

#include "LED.h"

void HLED_voidInit      (u8 A_u8LedPort , u8 A_u8LedPin)
{
	MDIO_voidInitPin(A_u8LedPort, A_u8LedPin, DIO_OUTPUT) ;
}
void HLED_voidTurnOn    (u8 A_u8LedPort , u8 A_u8LedPin)
{
	MDIO_voidSetPinValue(A_u8LedPort, A_u8LedPin, DIO_HIGH) ;
}
void HLED_voidTurnOff   (u8 A_u8LedPort , u8 A_u8LedPin)
{
	MDIO_voidSetPinValue(A_u8LedPort, A_u8LedPin, DIO_LOW) ;
}
void HLED_voidTogStatus (u8 A_u8LedPort , u8 A_u8LedPin)
{
	MDIO_voidTogPinValue (A_u8LedPort , A_u8LedPin) ;
}

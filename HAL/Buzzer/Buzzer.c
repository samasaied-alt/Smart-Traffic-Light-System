/*
 * Buzzer.c
 *
 *  Created on: Aug 12, 2026
 *      Author: youssef sayed
 */
#include "../../LIB/STd_Types.h"

#include "../../LIB/BitMath.h"
#include "../../MCAL/DIO/DIO.h"
#include "Buzzer.h"



void HBUZZER_voidInit(u8 A_u8BuzzerPort , u8 A_u8BuzzerPin)
{
	MDIO_voidInitPin(A_u8BuzzerPort, A_u8BuzzerPin, DIO_OUTPUT) ;
}
void HBUZZER_voidTurnOn(u8 A_u8BuzzerPort , u8 A_u8BuzzerPin)
{
	MDIO_voidSetPinValue(A_u8BuzzerPort, A_u8BuzzerPin, DIO_HIGH) ;
}
void HBUZZER_voidTurnOff(u8 A_u8BuzzerPort , u8 A_u8BuzzerPin)
{
	MDIO_voidSetPinValue(A_u8BuzzerPort, A_u8BuzzerPin, DIO_LOW) ;
}
void HBUZZER_voidTogStatus(u8 A_u8BuzzerPort , u8 A_u8BuzzerPin)
{
	MDIO_voidTogPinValue (A_u8BuzzerPort , A_u8BuzzerPin) ;
}

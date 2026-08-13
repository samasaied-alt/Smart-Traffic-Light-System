/*
 * Motor.c
 *
 *  Created on: Aug 12, 2026
 *      Author: youssef sayed
 */
#include "../../LIB/STd_Types.h"
#include "../../MCAL/DIO/DIO.h"

#include "Motor.h"


void HDCM_voidInit (u8 A_u8DCMPort , u8 A_u8Pin1 , u8 A_u8Pin2)
{
	MDIO_voidInitPin(A_u8DCMPort, A_u8Pin1, DIO_OUTPUT) ;
	MDIO_voidInitPin(A_u8DCMPort, A_u8Pin2, DIO_OUTPUT) ;

	MDIO_voidSetPinValue(A_u8DCMPort, A_u8Pin1, DIO_LOW) ;
	MDIO_voidSetPinValue(A_u8DCMPort, A_u8Pin2, DIO_LOW) ;
}

void HDCM_voidTurnOn (u8 A_u8DCMPort , u8 A_u8Pin1 , u8 A_u8Pin2)
{
	MDIO_voidSetPinValue(A_u8DCMPort, A_u8Pin1, DIO_HIGH) ;
	MDIO_voidSetPinValue(A_u8DCMPort, A_u8Pin2, DIO_LOW) ;
}

void HDCM_voidTurnOff (u8 A_u8DCMPort , u8 A_u8Pin1 , u8 A_u8Pin2)
{
	MDIO_voidSetPinValue(A_u8DCMPort, A_u8Pin1, DIO_LOW) ;
	MDIO_voidSetPinValue(A_u8DCMPort, A_u8Pin2, DIO_LOW) ;
}

void HDCM_voidStop (u8 A_u8DCMPort , u8 A_u8Pin1 , u8 A_u8Pin2)
{
	HDCM_voidTurnOff(A_u8DCMPort, A_u8Pin1, A_u8Pin2) ;
}

void HDCM_voidCW (u8 A_u8DCMPort , u8 A_u8Pin1 , u8 A_u8Pin2)
{
	MDIO_voidSetPinValue(A_u8DCMPort, A_u8Pin1, DIO_HIGH) ;
	MDIO_voidSetPinValue(A_u8DCMPort, A_u8Pin2, DIO_LOW) ;
}

void HDCM_voidCCW (u8 A_u8DCMPort , u8 A_u8Pin1 , u8 A_u8Pin2)
{
	MDIO_voidSetPinValue(A_u8DCMPort, A_u8Pin1, DIO_LOW) ;
	MDIO_voidSetPinValue(A_u8DCMPort, A_u8Pin2, DIO_HIGH) ;
}

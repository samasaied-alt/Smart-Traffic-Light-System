/*
 * Button.c
 *
 *  Created on: Aug 12, 2026
 *      Author: youssef sayed
 */
#include "../../LIB/BitMath.h"
#include "../../LIB/STd_Types.h"

#include "../../MCAL/DIO/DIO.h"

#include "Button.h"


void HPB_voidInit (u8 A_u8PbPort ,u8 A_u8PbPin)
{
	MDIO_voidInitPin(A_u8PbPort, A_u8PbPin, DIO_INPUT) ;
	MDIO_voidSetPinValue(A_u8PbPort, A_u8PbPin, DIO_HIGH) ;
}

u8   HPB_u8GetStatues (u8 A_u8PbPort , u8 A_u8PbPin)
{
	return  MDIO_u8ReadPinValue(A_u8PbPort , A_u8PbPin);
}

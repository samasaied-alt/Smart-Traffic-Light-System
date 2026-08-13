/*
 * LED.h
 *
 *  Created on: Aug 12, 2026
 *      Author: youssef sayed
 */
#ifndef HAL_LED_LED_H_
#define HAL_LED_LED_H_

#include "../../LIB/STd_Types.h"

void HLED_voidInit      (u8 A_u8LedPort , u8 A_u8LedPin) ;
void HLED_voidTurnOn    (u8 A_u8LedPort , u8 A_u8LedPin) ;
void HLED_voidTurnOff   (u8 A_u8LedPort , u8 A_u8LedPin) ;
void HLED_voidTogStatus (u8 A_u8LedPort , u8 A_u8LedPin) ;

#endif /* HAL_LED_LED_H_ */

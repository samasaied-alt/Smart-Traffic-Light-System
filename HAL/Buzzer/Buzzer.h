/*
 * Buzzer.h
 *
 *  Created on: Aug 12, 2026
 *      Author: youssef sayed
 */
#ifndef HAL_BUZZER_BUZZER_H_
#define HAL_BUZZER_BUZZER_H_

#include "../../LIB/STd_Types.h"


void HBUZZER_voidInit      (u8 A_u8BuzerPort , u8 A_u8BuzzerPin) ;
void HBUZZER_voidTurnOn    (u8 A_u8BuzerPort , u8 A_u8BuzzerPin) ;
void HBUZZER_voidTurnOff   (u8 A_u8BuzerPort , u8 A_u8BuzzerPin) ;
void HBUZZER_voidTogStatus (u8 A_u8BuzerPort , u8 A_u8BuzzerPin) ;


#endif /* HAL_BUZZER_BUZZER_H_ */

/*
 * Motor.h
 *
 *  Created on: Aug 12, 2026
 *      Author: youssef sayed
 */
#ifndef HAL_MOTOR_MOTOR_H_
#define HAL_MOTOR_MOTOR_H_

#include "../../LIB/STd_Types.h"

void HDCM_voidInit    (u8 A_u8DCMPort , u8 A_u8Pin1 , u8 A_u8Pin2) ;
void HDCM_voidTurnOn  (u8 A_u8DCMPort , u8 A_u8Pin1 , u8 A_u8Pin2) ;
void HDCM_voidTurnOff (u8 A_u8DCMPort , u8 A_u8Pin1 , u8 A_u8Pin2) ;
void HDCM_voidStop    (u8 A_u8DCMPort , u8 A_u8Pin1 , u8 A_u8Pin2) ;
void HDCM_voidCW      (u8 A_u8DCMPort , u8 A_u8Pin1 , u8 A_u8Pin2) ;
void HDCM_voidCCW     (u8 A_u8DCMPort , u8 A_u8Pin1 , u8 A_u8Pin2) ;

#endif /* HAL_MOTOR_MOTOR_H_ */

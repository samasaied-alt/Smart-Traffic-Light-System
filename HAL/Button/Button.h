/*
 * Button.h
 *
 *  Created on: Aug 12, 2026
 *      Author: youssef sayed
 */
#ifndef HAL_BUTTON_BUTTON_H_
#define HAL_BUTTON_BUTTON_H_

#include "../../LIB/STd_Types.h"

#define PB_PRESSED      0
#define PB_NOT_PRESSED  1
#define PB_RELEASED     1

void HPB_voidInit (u8 A_u8PbPort , u8 A_u8PbPin) ;
u8   HPB_u8GetStatues (u8 A_u8PbPort , u8 A_u8PbPin) ;

#endif /* HAL_BUTTON_BUTTON_H_ */

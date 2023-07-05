/*
 * BUTTON_int.h
 *
 *  Created on: Feb 8, 2023
 *      Author: fathy
 */

#ifndef HAL_BUTTON_BUTTON_INT_H_
#define HAL_BUTTON_BUTTON_INT_H_

void BUTTON_voidInit(void);
void BUTTON_ON_voidGetValue(u8 * copy_u8Value);
void BUTTON_OFF_voidGetValue(u8 * copy_u8Value);

#define PRESSED  1
#endif /* HAL_BUTTON_BUTTON_INT_H_ */

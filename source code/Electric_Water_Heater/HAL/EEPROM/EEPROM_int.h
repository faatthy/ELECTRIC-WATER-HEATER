/*
 * EEPROM_int.h
 *
 *  Created on: Feb 7, 2023
 *      Author: fathy
 */

#ifndef HAL_EEPROM_EEPROM_INT_H_
#define HAL_EEPROM_EEPROM_INT_H_

void EEPROM_voidInit(void);
void EEPROM_voidWrite(u8 Copy_u8Data,u8 Copy_u8PageAddress,u8 Copy_u8ByteAddress);
void EEPROM_voidRead(u8* Copy_u8Data,u8 Copy_u8PageAddress,u8 Copy_u8ByteAddress);
#endif /* HAL_EEPROM_EEPROM_INT_H_ */

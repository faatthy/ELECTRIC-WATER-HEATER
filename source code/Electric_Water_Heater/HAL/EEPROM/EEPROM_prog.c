/*
 * EEPROM_prog.c
 *
 *  Created on: Feb 7, 2023
 *      Author: fathy
 */
#include "../../LIBRARY/errorState.h"
#include "../../LIBRARY/stdTypes.h"
#include"../../MCAL/IIC/IIC_int.h"
#include"EEPROM_priv.h"
#include "EEPROM_conf.h"

void EEPROM_voidInit(void)
{

	IIC_voidInit();
	return;
}
void EEPROM_voidWrite(u8 Copy_u8Data,u8 Copy_u8PageAddress,u8 Copy_u8ByteAddress)
{

	if(Copy_u8PageAddress < 8)
	{
		IIC_voidStartCondition();
		IIC_voidSendSlaveAddressWrite((0x50 | Copy_u8PageAddress));
		IIC_voidSendData(Copy_u8ByteAddress);
		IIC_voidSendData(Copy_u8Data);
		IIC_voidStopCondition();
	}

}
void EEPROM_voidRead(u8* Copy_u8Data,u8 Copy_u8PageAddress,u8 Copy_u8ByteAddress)
{
		if(Copy_u8PageAddress < 8)
		{
	u8 Local_u8Data = 0;
	IIC_voidStartCondition();
	IIC_voidSendSlaveAddressWrite((0x50 | Copy_u8PageAddress));
	IIC_voidSendData(Copy_u8ByteAddress);
	IIC_voidRepeatedStart();
	IIC_voidSendSlaveAddressRead((0x50 | Copy_u8PageAddress));
	IIC_voidReadDataNoAck(&Local_u8Data);
	*Copy_u8Data=Local_u8Data;
	IIC_voidStopCondition();
		}
}

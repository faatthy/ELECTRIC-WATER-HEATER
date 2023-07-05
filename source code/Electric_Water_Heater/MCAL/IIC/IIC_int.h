/*
 * IIC_int.h
 *
 *  Created on: Feb 7, 2023
 *      Author: fathy
 */

#ifndef MCAL_IIC_IIC_INT_H_
#define MCAL_IIC_IIC_INT_H_

/********************************_PROTOTYPES_***************************************/
void IIC_voidInit(void);
void IIC_voidStartCondition(void);
void IIC_voidSendSlaveAddressWrite(u8 Copy_u8Address);
void IIC_voidSendSlaveAddressRead(u8 Copy_u8Address);
void IIC_voidSendData(u8 Copy_u8Data);
void IIC_voidReadData(u8* Copy_u8Data);
void IIC_voidRepeatedStart(void);
void IIC_voidStopCondition(void);
void IIC_voidReadDataNoAck(u8* Copy_u8Data);


#endif /* MCAL_IIC_IIC_INT_H_ */

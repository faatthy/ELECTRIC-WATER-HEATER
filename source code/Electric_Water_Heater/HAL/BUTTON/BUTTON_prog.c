/*
 * BUTTON_prog.c
 *
 *  Created on: Feb 8, 2023
 *      Author: fathy
 */
#include "../../LIBRARY/errorState.h"
#include "../../LIBRARY/stdTypes.h"
#include"../../MCAL/DIO/DIO_int.h"
#include "BUTTON_priv.h"
#include "BUTTON_conf.h"
#include <util/delay.h>

void BUTTON_voidInit(void){

	DIO_voidSetPinDirection(BUTTON_ON_GROUP,BUTTON__ON_PIN,DIO_u8INPUT);
	DIO_voidSetPinValue(BUTTON_ON_GROUP,BUTTON__ON_PIN,DIO_u8FLOAT);

	DIO_voidSetPinDirection(BUTTON_OFF_GROUP,BUTTON__OFF_PIN,DIO_u8INPUT);
	DIO_voidSetPinValue(BUTTON_OFF_GROUP,BUTTON__OFF_PIN,DIO_u8FLOAT);

	DIO_voidSetPinDirection(BUTTON_UP_GROUP,BUTTON__UP_PIN,DIO_u8INPUT);
	DIO_voidSetPinValue(BUTTON_UP_GROUP,BUTTON__UP_PIN,DIO_u8FLOAT);

	DIO_voidSetPinDirection(BUTTON_DOWN_GROUP,BUTTON__DOWN_PIN,DIO_u8INPUT);
	DIO_voidSetPinValue(BUTTON_DOWN_GROUP,BUTTON__DOWN_PIN,DIO_u8FLOAT);

	return;
}
void BUTTON_ON_voidGetValue(u8 * copy_u8Value){
	u8 Local_u8Value=0;
	DIO_voidGetPinValue(BUTTON_ON_GROUP,BUTTON__ON_PIN,&Local_u8Value);
	*copy_u8Value=Local_u8Value;
}
void BUTTON_OFF_voidGetValue(u8 * copy_u8Value){
	    u8 Local_u8Value=0;
		DIO_voidGetPinValue(BUTTON_OFF_GROUP,BUTTON__OFF_PIN,&Local_u8Value);
		*copy_u8Value=Local_u8Value;
}

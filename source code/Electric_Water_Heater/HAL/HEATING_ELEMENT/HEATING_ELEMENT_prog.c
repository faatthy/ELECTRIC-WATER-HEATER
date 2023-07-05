/*
 * HEATING_ELEMENT_prog.c
 *
 *  Created on: Jul 5, 2023
 *      Author: fathy
 */
#include"../../LIBRARY/stdTypes.h"
#include"../../MCAL/DIO/DIO_int.h"
#include "HEATING_ELEMENT_priv.h"
#include "HEATING_ELEMENT_conf.h"
void HEATING_ELEMENT_voidInit(void){
	DIO_voidSetPinDirection(HEATING_ELEMENT_GROUP,HEATING_ELEMENT_PIN,DIO_u8OUTPUT);
}
void HEATING_ELEMENT_voidEnable(void){
	DIO_voidSetPinValue(HEATING_ELEMENT_GROUP,HEATING_ELEMENT_PIN,DIO_u8HIGH);
}
void HEATING_ELEMENT_voidDisable(void){
	DIO_voidSetPinValue(HEATING_ELEMENT_GROUP,HEATING_ELEMENT_PIN,DIO_u8LOW);
}

/*

 * COOLING_ELEMENT_prog.c
 *
 *  Created on: Jul 5, 2023
 *      Author: fathy
 */


#include"../../LIBRARY/stdTypes.h"
#include"../../MCAL/DIO/DIO_int.h"
#include "COOLING_ELEMENT_priv.h"
#include "COOLING_ELEMENT_conf.h"
void COOLING_ELEMENT_voidInit(void){
	DIO_voidSetPinDirection(COOLING_ELEMENT_GROUP,COOLING_ELEMENT_PIN,DIO_u8OUTPUT);
}
void COOLING_ELEMENT_voidEnable(void){
	DIO_voidSetPinValue(COOLING_ELEMENT_GROUP,COOLING_ELEMENT_PIN,DIO_u8HIGH);
}
void COOLING_ELEMENT_voidDisable(void){
	DIO_voidSetPinValue(COOLING_ELEMENT_GROUP,COOLING_ELEMENT_PIN,DIO_u8LOW);
}

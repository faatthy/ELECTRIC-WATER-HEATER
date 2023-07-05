/*
 * TEMP_SENSOR_prog.c
 *
 *  Created on: Feb 5, 2023
 *      Author: fathy
 */
#include"../../LIBRARY/errorState.h"
#include"../../LIBRARY/stdTypes.h"
#include"../../MCAL/DIO/DIO_int.h"
#include"TEMP_SENSOR_priv.h"
#include"TEMP_SENSOR_conf.h"
#include"../../MCAL/ADC/ADC_int.h"
u16 read;

void TEMP_SENSOR_voidInit(void){

	ADC_voidInit();
	ADC_voidStartConversion();
	ADC_voidPollingRead(&read);
	return ;
}
u16 TEMP_SENSOR_u16Read(void){


	ADC_voidStartConversion();
	ADC_voidPollingRead(&read);

	read=(read*500ul)/1024;

return read;

}

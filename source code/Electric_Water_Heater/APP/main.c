/*
 * main.c
 *
 *  Created on: Jun 25, 2023
 *      Author: fathy
 */
#include "../LIBRARY/errorState.h"
#include"../LIBRARY/stdTypes.h"
#include"../MCAL/DIO/DIO_int.h"
#include "../HAL/BUTTON/BUTTON_int.h"

#include"../HAL/LCD/LCD_int.h"

#include "../MCAL/GIE/GIE_int.h"
#include "../MCAL/EXTI/EXTI_int.h"
#include "../MCAL/ADC/ADC_int.h"
#include "../HAL/TEMP_SENSOR/TEMP_SENSOR_int.h"

#include "../HAL/EEPROM/EEPROM_int.h"
#include "../HAL/COOLING_ELEMENT/COOLING_ELEMENT_int.h"
#include "../HAL/HEATING_ELEMENT/HEATING_ELEMENT_int.h"
void Initalization(void);
void LCD_Display(u8 Copy_u8Number);
void Sensor_Display(void);
void TURN_OFF(void);
void System_Managment(void);
void Temperature_Setting_Mode(void);
void Increase_TEMP(void);
void Decrease_TEMP(void);
void Save_Data(void);

u8 Initial_Temp=60;
u8 ON_Flag=0;
u8 First_Press=0; // for up and down buttons
u16 TEMPERATURE;
#include<util/delay.h>
int main(){
	Initalization();
	EXTI_voidCallBack(Increase_TEMP,INT0);
	EXTI_voidCallBack(Decrease_TEMP,INT1);
	EXTI_voidCallBack(Save_Data,INT2);
	u8 value;
	/*
	EEPROM_voidRead(&value,0,0);
	if(value!=0xFF){
		Initial_Temp=value;
	}
	*/
	while(1){
		BUTTON_ON_voidGetValue(&value);
		if (value==PRESSED){
			ON_Flag=1;
		}
		if(ON_Flag){
		Sensor_Display();
		System_Managment();
		}
		else{
			TURN_OFF();
		}
	}
}
void Initalization(void){
	GIE_voidEnable();
	EXTI_voidInit();
	LCD_voidInit();
	TEMP_SENSOR_voidInit();
	BUTTON_voidInit();

	EEPROM_voidInit();
	HEATING_ELEMENT_voidInit();
	COOLING_ELEMENT_voidInit();
}
void LCD_Display(u8 Copy_u8Number){
	LCD_voidClearScreen();
	LCD_voidWritInteger(Copy_u8Number);
}
void Sensor_Display(void){
	TEMPERATURE=TEMP_SENSOR_u16Read();
	LCD_Display(TEMPERATURE);
	_delay_ms(2000);
}
void TURN_OFF(void){
	HEATING_ELEMENT_voidDisable();
	COOLING_ELEMENT_voidDisable();
	LCD_voidClearScreen();

}
void System_Managment(void){
	if(TEMPERATURE<Initial_Temp-5){
		HEATING_ELEMENT_voidEnable();
		COOLING_ELEMENT_voidDisable();
	}
	else if(TEMPERATURE>Initial_Temp+5){
		COOLING_ELEMENT_voidEnable();
		HEATING_ELEMENT_voidDisable();
	}
}
void Temperature_Setting_Mode(void){
	if(First_Press==1){
		LCD_Display(Initial_Temp);
	}
}
void Increase_TEMP(void){
	if(First_Press==1){
		if(Initial_Temp<=70){
			Initial_Temp+=5;
		}
		LCD_Display(Initial_Temp);
		_delay_ms(1000);
		First_Press=0;
	}
	else{
		First_Press=1;
	}

}
void Decrease_TEMP(void){
	if(First_Press==1){
			if(Initial_Temp>=40){
				Initial_Temp-=5;
			}
			LCD_Display(Initial_Temp);
			_delay_ms(1000);
			First_Press=0;
		}
		else{
			First_Press=1;
		}
}
void Save_Data(void){
	EEPROM_voidWrite(Initial_Temp,0,0);
	ON_Flag=0;
}

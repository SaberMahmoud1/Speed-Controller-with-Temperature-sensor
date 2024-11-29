/******************************************************************************
 *
 * Module: main function
 *
 * File Name: adc.c
 *
 * Description: Source file for the ATmega16 ADC driver
 *
 * Author: Saber Mahmoud
 *
 *******************************************************************************/
#include"adc.h"
#include"dc_motor.h"
#include"lcd.h"
#include"lm35_sensor.h"
#include"std_types.h"
#include"timer_pwm.h"
#include<util/delay.h>
void main(void)
{
	ADC_config ADC_CONTROLLER={internal2_56,preclck_8};
	uint8 motor_state=CW;
	uint8 temp;
	Timer0_PWM_Init(0);
	ADC_init(&ADC_CONTROLLER);
	DcMotor_Init();
	LCD_init();
	while(1)
	{
		temp=LM35_getTemperature();
		if(temp<30)
		{
			LCD_displayStringRowColumn(0, 4, "FAN is OFF");
			LCD_displayStringRowColumn(1, 4, "Temp =    c");
			DcMotor_Rotate(motor_state,ZeroSpeed);
			LCD_moveCursor(1, 11);
			LCD_intgerToString(temp);
		}
		else if(temp<60)
		{
			LCD_displayStringRowColumn(0, 4, "FAN is ON ");
			LCD_displayStringRowColumn(1, 4, "Temp =    c");
			DcMotor_Rotate(motor_state,QuarterSpeed);
			LCD_moveCursor(1, 11);
			LCD_intgerToString(temp);
		}
		else if(temp<90)
		{
			LCD_displayStringRowColumn(0, 4, "FAN is ON");
			LCD_displayStringRowColumn(1, 4, "Temp =    c");

			DcMotor_Rotate(motor_state,HalfSpeed);
			LCD_moveCursor(1, 11);
			LCD_intgerToString(temp);
		}
		else if(temp<120)
		{
			LCD_displayStringRowColumn(0, 4, "FAN is ON");
			LCD_displayStringRowColumn(1, 4, "Temp =    c");

			DcMotor_Rotate(motor_state,ThreeQuartersSpeed);
			LCD_moveCursor(1, 11);
			LCD_intgerToString(temp);
		}
		else if(temp>=120)
		{
			LCD_displayStringRowColumn(0, 4, "FAN is ON");
			LCD_displayStringRowColumn(1, 4, "Temp =    c");

			DcMotor_Rotate(motor_state,FullSpeed);
			LCD_moveCursor(1, 11);
			LCD_intgerToString(temp);
		}
		while(temp==LM35_getTemperature());
	}
}

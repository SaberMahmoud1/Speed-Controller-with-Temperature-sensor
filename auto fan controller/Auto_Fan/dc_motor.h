 /******************************************************************************
 *
 * Module: timer0
 *
 * File Name: timer_pwm.c
 *
 * Description: Source file for the TIMER0 driver
 *
 * Author: Saber Mahmoud
 *
 ********************************************************************************/
#include"std_types.h"
#ifndef DC_MOTOR_H_
#define DC_MOTOR_H_
/***********************************************************************
 * definitions
 ***********************************************************************/
#define MAX_SPEED 100
#define MAX_COUNTS_OF_TIMER 255
/***********************************************************************
 * type definitions
 ***********************************************************************/
enum{STOP_MOTOR,CW,A_CW};
enum{ZeroSpeed=0,QuarterSpeed=25,HalfSpeed=50,ThreeQuartersSpeed=75,FullSpeed=100};
/***********************************************************************
 * functions prototype
 ***********************************************************************/
/*
 *Description
➢ The Function responsible for setup the direction for the two
motor pins through the GPIO driver.
➢ Stop at the DC-Motor at the beginning through the GPIO driver.
 *
 */
void DcMotor_Init(void);
/*
 * • Description:
➢ The function responsible for rotate the DC Motor CW/ or A-CW or
stop the motor based on the state input state value.
➢ Send the required duty cycle to the PWM driver based on the
required speed value.
*/
void DcMotor_Rotate(uint8 state,uint8 speed);
#endif /* DC_MOTOR_H_ */

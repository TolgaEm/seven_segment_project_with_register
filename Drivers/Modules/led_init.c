/*
 * led_driver.c
 *
 *  Created on: Jun 23, 2022
 *      Author: tolga_em
 */

#include "stm32f4xx_hal.h"

void led_init (void){

	RCC->AHB1ENR   = 0X00000001; // port A clock enable

	GPIOA->MODER   = 0X00001555; // A0,A1,A2,A3,A4,A5,A6 set output
	GPIOA->OTYPER  = 0X00000000;
	GPIOA->OSPEEDR = 0X00003FFF; // clock speed set as very high
	GPIOA->PUPDR   = 0X00000000; // set no pull up-down
}

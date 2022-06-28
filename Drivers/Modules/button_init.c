/*
 * button_init.c
 *
 *  Created on: Jun 23, 2022
 *      Author: tem-1
 */

#include  "stm32f4xx_hal.h"

void button_init (void){

	RCC->AHB1ENR   |= 0X00000002; // ENABLE PORTB0 PIN CLOCK

	GPIOB->MODER   |= 0X00000000; // SET OUTPUT MODE
	GPIOB->OTYPER  |= 0X00000000;
	GPIOB->OSPEEDR |= 0X00000003; // CLOCK SPEED SET AS VERY HİGH SPEED
	GPIOB->PUPDR   |= 0X00000002; // SET PULL DOWN
}

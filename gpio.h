/*
 * gpio.h
 *
 *  Created on: Nov 11, 2017
 *      Author: kevin
 */


#include "msp.h"
#include "i2C.h"

#ifndef GPIO_H_
#define GPIO_H_

//
/*
 * pins:
 *          //
 *          //
 * */
void i2c_B1__MASTER_PIN_CONFIGURE();


void red_LED_Configure();

void red_LED_Blink();


#endif /* GPIO_H_ */

/*
 * ssd1306.h
 *
 *  Created on: Nov 11, 2017
 *      Author: kevin
 */

#include "msp.h"

#ifndef SSD1306_H_
#define SSD1306_H_



/* @name: Initialize_Display
 * @brief: Intialize the oled display 128x64, calls i2c config.
 * @param: currently no input or output, use defaults for i2c connection
 * */
uint8_t initialize_Display();

#endif /* SSD1306_H_ */

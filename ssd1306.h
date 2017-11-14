/*
 * ssd1306.h
 *
 *  Created on: Nov 14, 2017
 *      Author: kevin
 */

#ifndef SSD1306_H_
#define SSD1306_H_

/* @name:   ssd1306_Commmand
 *  @brief: Writes one of the SSD1306 commands. Uses I2c start_Transmission() and stop_Transmission()
 *  @input: Address of slave and the command desired to send.
 * */
void ssd1306_Command(uint8_t _address, uint8_t _command);

#endif /* SSD1306_H_ */

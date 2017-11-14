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


/*
 *  @name: clear_Screen
 *  @brief: each byte is a 0x00 then we do that 128 times because we have 128 columns, and do it 8 times because we have 64 rows.
 * */

void clear_Screen(uint8_t _address);


/*
 *  @name: darw_Square
 *  @brief: draws a small square hopefully?
 *  0x7F is required * 6 times
 * */
void draw_Square(uint8_t _address);

#endif /* SSD1306_H_ */

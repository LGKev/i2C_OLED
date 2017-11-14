/*
 * ssd1306.h
 *
 *  Created on: Nov 14, 2017
 *      Author: kevin
 */

#ifndef SSD1306_H_
#define SSD1306_H_


/*
 *  Looking at Adafuirts init for the screen there are quite a bit that needs to be done prior to displaying info! So here is my attempt.
 *  starting at line 230 of adafruit_ssd1306.cpp file
 * */
void init_OLED_SSD1306();


/* very basic draw a single pixel...*/
void draw_Pixel(uint16_t _x, uint16_t _y,uint16_t color);

/*
 *  @name: Print_Display
 *  @brief: takes in the address of the display and comences the sequence to display info on the scrren
 * */
void print_Display(uint8_t _address);






/* @name:   ssd1306_Commmand
 *  @brief: Writes one of the SSD1306 commands. Uses I2c start_Transmission() and stop_Transmission()
 *  @input: Address of slave and the command desired to send.
 * */
void ssd1306_Command(uint8_t _address, uint8_t _command);

/*
 *  @name: ss1306_DATA
 *  @brief very similar to ssd1306_Command, but instead of writing 0x00 after slave address we write 0x40 to signify data to be placed into Graphical ram.
 * */
void ssd1306_DATA(uint8_t _address, uint8_t _data);



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

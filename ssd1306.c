/*
 * ssd1306.c
 *
 *  Created on: Nov 14, 2017
 *      Author: kevin
 */

#include "msp.h"
#include "i2C.h"
#include "ssd1306.h"

#define DEFAULT_SLAVE_ADDRESS                     (0x3C)
#define DEFAULT_DISP_HEIGHT                            (128)
#define DEFAULT_DISP_WIDTH                              (64)

#define ORIGIN_TOP_LEFT                                       (0x40)
#define PIXEL_OFF                                                     (0x00)
#define CONTROL                                                      (0x00)
#define DISPLAY_ON                                                 (0xAF)
#define DISPLAY_OFF                                                (0xAE)

#define SET_DISPLAY_CLOCK_DIV                          (0xD5)
#define SET_MULTIPLEX                                           (0xA8)

#define SET_DISP_OFFSET                                       (0xD3)
#define DEFAULT_OFFSET                                        (0x00)

#define SET_START_LINE                                         (0x40)

#define SSD1306_CHARGEPUMP                              (0x8D)
#define SET_CHARGEPUMP_EXTERN                      (0x10)
#define SET_CHARGEPUMP_MEMORY                     (0x14)

#define MEMORYMODE                                               (0x20)

#define SEG_REMAP                                                    (0xA0)
#define COM_SCAN_DIREC                                         (0xC8)

#define SET_COM_PINS                                               (0xDA)

#define SET_CONTRAST                                              (0x81)
#define DEFAULT_CONTRAST_EXTERN                    (0X9F) //:TODO DEFINE WHAT THIS DOES

#define SET_PRE_CHARGE                                         (0xD9)
#define DEFAULT_PRE_CHARGE_EXTERN               (0x22)

#define SET_V_COM_DETECT                                    (0xDB)
#define DEFAULT_V_COM_DETECT                           (0X40)

#define DISPLAY_ALL_ON_RESUME                          (0xA4)
#define NORMAL_DISPLAY                                          (0xA6)

#define DEACTIVATE_SCROLL                                    (0X2E)


void init_OLED_SSD1306(){
    // turn display off
    ssd1306_Command(DEFAULT_SLAVE_ADDRESS, DISPLAY_OFF);           //0XAE
    ssd1306_Command(DEFAULT_SLAVE_ADDRESS, SET_DISPLAY_CLOCK_DIV);        //0XD5
    ssd1306_Command(DEFAULT_SLAVE_ADDRESS, 0XB0); //SET THE PAGE START ADDDRESS OF THE TARGET DISPLAY LOCATION : b0 to b7

    ssd1306_Command(DEFAULT_SLAVE_ADDRESS, SET_DISPLAY_CLOCK_DIV );           //0XD5

    ssd1306_Command(DEFAULT_SLAVE_ADDRESS, SET_MULTIPLEX); //0xA8     allows for any multiplex ratio
    ssd1306_Command(DEFAULT_SLAVE_ADDRESS, DEFAULT_DISP_HEIGHT - 1); //128 sets the display, index at 0

    ssd1306_Command(DEFAULT_SLAVE_ADDRESS, SET_DISP_OFFSET); //0XD3     allows for any multiplex ratio
    ssd1306_Command(DEFAULT_SLAVE_ADDRESS, DEFAULT_OFFSET);  // SET AT NO OFFSET

    ssd1306_Command(DEFAULT_SLAVE_ADDRESS, SET_START_LINE | 0X0);         //0X40
    ssd1306_Command(DEFAULT_SLAVE_ADDRESS, DEFAULT_OFFSET); //0X40, WITHOUT ANY OFFSET

    ssd1306_Command(DEFAULT_SLAVE_ADDRESS, SSD1306_CHARGEPUMP); //0x8D turn on Charge pump, not sure if external or memory setting as if external power.. table 2.1 of the ssd1306 data sheet
    ssd1306_Command(DEFAULT_SLAVE_ADDRESS, SET_CHARGEPUMP_EXTERN); //0x8D turn on Charge pump, not sure if external or memory setting as if external power.. table 2.1 of the ssd1306 data sheet

    ssd1306_Command(DEFAULT_SLAVE_ADDRESS, MEMORYMODE); //0X20 MEMORY MODE
    ssd1306_Command(DEFAULT_SLAVE_ADDRESS, 0x00);//0x8D turn on Charge pump, not sure if external or memory setting as if external power.. table 2.1 of the ssd1306 data sheet

    ssd1306_Command(DEFAULT_SLAVE_ADDRESS, COM_SCAN_DIREC); //0xC8 determines screen orientation

    ssd1306_Command(DEFAULT_SLAVE_ADDRESS, SET_COM_PINS); //0xDA
    ssd1306_Command(DEFAULT_SLAVE_ADDRESS, 0x12);


    ssd1306_Command(DEFAULT_SLAVE_ADDRESS, SET_CONTRAST); //0x81
    ssd1306_Command(DEFAULT_SLAVE_ADDRESS, DEFAULT_CONTRAST_EXTERN); //0X9F


    ssd1306_Command(DEFAULT_SLAVE_ADDRESS, SET_PRE_CHARGE); //0XD9 //NOT IN FLOW CHART?
    ssd1306_Command(DEFAULT_SLAVE_ADDRESS, DEFAULT_PRE_CHARGE_EXTERN); //0x22

    ssd1306_Command(DEFAULT_SLAVE_ADDRESS, SET_V_COM_DETECT); //0xDB
    ssd1306_Command(DEFAULT_SLAVE_ADDRESS, DEFAULT_V_COM_DETECT); //0x40

    ssd1306_Command(DEFAULT_SLAVE_ADDRESS, DISPLAY_ALL_ON_RESUME); //0xA4
    ssd1306_Command(DEFAULT_SLAVE_ADDRESS, NORMAL_DISPLAY); //0xA6


    ssd1306_Command(DEFAULT_SLAVE_ADDRESS, DEACTIVATE_SCROLL); //0x2E

    /* DISPLAY ON*/
    ssd1306_Command(DEFAULT_SLAVE_ADDRESS, DISPLAY_ON); //0XAF

}

void ssd1306_Command(uint8_t _address, uint8_t _command)
{
    start_Transmission(_address);
    EUSCI_B1->TXBUF = CONTROL;
    EUSCI_B1->TXBUF = _command;
    stop_Transmission(_address);
}

void clear_Screen(uint8_t _address)
{
    start_Transmission(_address);
    EUSCI_B1->TXBUF = CONTROL; // set the start location0x40;
    EUSCI_B1->TXBUF = ORIGIN_TOP_LEFT; // set the start location0x40;
    uint16_t position = 0;
    for (position = 0; position < 128; position++)
    {
        EUSCI_B1->TXBUF = PIXEL_OFF; // set the start location0x40;
    }
    stop_Transmission(_address);
}

void draw_Square(uint8_t _address)
{
    start_Transmission(_address);
    EUSCI_B1->TXBUF = CONTROL; // set the start location0x40;

    uint8_t count = 0;
    for (count = 0; count < 6; count++)
    {
        EUSCI_B1->TXBUF = 0X7F; // set the start location0x40;
    }

    stop_Transmission(_address);
}

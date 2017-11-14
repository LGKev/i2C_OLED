/*
 * ssd1306.c
 *
 *  Created on: Nov 14, 2017
 *      Author: kevin
 */


#include "msp.h"
#include "i2C.h"
#include "ssd1306.h"


#define ORIGIN_TOP_LEFT                     (0x40)
#define PIXEL_OFF                                   (0X00)
#define CONTROL                                    (0X00)



void ssd1306_Command(uint8_t _address, uint8_t _command){
        start_Transmission(_address);
        //TODO: write how to write the control bit

        EUSCI_B1->TXBUF = CONTROL;

        i2cDelay();

        //TODO: how to write the command bit'
        EUSCI_B1->TXBUF = _command;
        i2cDelay();

        stop_Transmission(_address);
}

void clear_Screen(uint8_t _address){
    start_Transmission(_address);
    EUSCI_B1->TXBUF = CONTROL; // set the start location0x40;
    EUSCI_B1->TXBUF = ORIGIN_TOP_LEFT; // set the start location0x40;
    uint16_t position =0;
    for(position = 0; position < 128; position++){
        EUSCI_B1->TXBUF = PIXEL_OFF; // set the start location0x40;
    }
stop_Transmission(_address);
}

void draw_Square(uint8_t _address){
    start_Transmission(_address);
    EUSCI_B1->TXBUF = CONTROL; // set the start location0x40;

    uint8_t count = 0;
    for(count = 0; count < 6; count++){
        EUSCI_B1->TXBUF = 0X7F; // set the start location0x40;
    }

    stop_Transmission(_address);
}

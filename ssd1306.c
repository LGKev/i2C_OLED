/*
 * ssd1306.c
 *
 *  Created on: Nov 14, 2017
 *      Author: kevin
 */


#include "msp.h"
#include "i2C.h"
#include "ssd1306.h"


void ssd1306_Command(uint8_t _address, uint8_t _command){
        uint8_t CONTROL = 0X00; //data sheet
        start_Transmission(_address);
        //TODO: write how to write the control bit

        EUSCI_B1->TXBUF = CONTROL;

        i2cDelay();

        //TODO: how to write the command bit'
        EUSCI_B1->TXBUF = _command;
        i2cDelay();

        stop_Transmission(_address);
}

/*
 * i2C.h
 *
 *  Created on: Nov 11, 2017
 *      Author: kevin
 */

#include "msp.h"

#ifndef I2C_H_
#define I2C_H_


void  i2c_MASTER_Configure();


/*
 *      The EUSCI Handles the SDA START transition
 *      we just need to send the address
 * */
void start_Transmission(uint8_t _address);


void stop_Transmission(uint8_t _address);

void send_Data_TX(uint8_t _slave_Address, uint8_t * data,  uint8_t length);


//1 is transmit 0 is rx
void set_Mode(uint8_t _mode);

/*
 * Really simple delay, does nothing in function but provides enough delay for i2c SDA transitions
 **/
void i2cDelay();


#endif /* I2C_H_ */

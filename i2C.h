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
    @name: start_Transmission
    @brief: Writes _address to UCBIi2cA field. Sets master into TX mode and sets UCTXSTT start BIT
    @input: The address of the slave device
 */
void start_Transmission(uint8_t _address);


/* @name: stop_Transmission
 * @brief: Sets the UCTXSTP bit to trigger stop
   @input: Address of the slave in Hex
 */
void stop_Transmission(uint8_t _address);


/*  @name: write_Command
 *  @brief: Sequence of events required to write to the i2c BUS: Is this just as simple as looping over TX BUFFer?
 *  @inputs, command [hex]
 *      */
void wirte_Command(uint8_t );


void send_Data_TX(uint8_t _slave_Address, uint8_t * _data, uint8_t length);


//1 is transmit 0 is rx
void set_Mode(uint8_t _mode);

/*
 * Really simple delay, does nothing in function but provides enough delay for i2c SDA transitions
 **/
void i2cDelay();


#endif /* I2C_H_ */

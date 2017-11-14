#include "msp.h"
#include "ssd1306.h"
#include "i2C.h"
#include "gpio.h"

/**
 * main.c
 *
 *  ============ Notes and ToDOs ================
 *          * Need to figure out driver for i2c
 *          * Need to find out how to initialize LCD
 *          * Need to figure out the drawBitmap function.
 *
 */


/*
 *  ===========================================================================
 *  ===========================================================================
 *  ===========================================================================
                                Globals for I2C
 *  ===========================================================================
 *          Require an Array/ Buffer for the RX and TX
 *          Most likely an ARRAY as thats how the bits for each pixel is stored
 */

volatile uint8_t i2c_RX_array[10==6]; //10 bytes of data
volatile uint8_t RX_index = 0;
volatile uint8_t i2c_TX_array[16]; //probabily much biggeris required.
volatile uint8_t TX_index = 0;


//void main(void)
//{
//	WDT_A->CTL = WDT_A_CTL_PW | WDT_A_CTL_HOLD;		// stop watchdog timer
//
//	red_LED_Configure();
//
//	i2c_MASTER_Configure();
//
//	__enable_irq();
//
//	uint32_t time =0;
//
//
//
//		while(1){
//
//            start_Transmission(0x003C); //I want to see the UCSSTT flag cleared after transmission of addres!
//            // I want to see UCTX



//
//		   // send_Data_TX(0x003C, "123", 3);
//
//		}
//
//}


void main(void){
      WDT_A->CTL = WDT_A_CTL_PW | WDT_A_CTL_HOLD;     // stop watchdog timer

      red_LED_Configure();
      red_LED_Blink();
      red_LED_Blink();


      i2c_MASTER_Configure();

          __enable_irq();


      while(1){

          start_Transmission(0x003C);
         red_LED_Blink();
        // start_Transmission(0x007D);


//          UCB1I2CSA = 6;
//          while(UCB1CTLW0 & UCTXSTP);
//          UCB1CTLW0 |= UCTR | UCTXSTT;
      }
}

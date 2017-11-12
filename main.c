#include "msp.h"
#include "ssd1306.h"
#include "i2C.h"

/**
 * main.c
 *
 *  ============ Notes and ToDOs ================
 *          * Need to figure out driver for i2c
 *          * Need to find out how to initialize LCD
 *          * Need to figure out the drawBitmap function.
 *
 */
void main(void)
{
	WDT_A->CTL = WDT_A_CTL_PW | WDT_A_CTL_HOLD;		// stop watchdog timer

	i2c_configure();

	uint32_t time =0;
	while(1){
	        for(time =0; time < 32000; time++);
            start_Transmission(0x3C); //I want to see the UCSSTT flag cleared after transmission of addres!
            // I want to see UCTX
	}

}


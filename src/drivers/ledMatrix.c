#include <stdlib.h>
#include "ledMatrix.h"
#include "hardwareConfig.h"
#include <stdio.h>
#include "stm32f0xx.h"


void bufferInit() {
	for (int i = 0; i < BUFFERSIZE; i++) {
		screenBuffer[i] = 0;
	}
	return;
}

void matrixDisplay() {
    for (int currRow = 0; currRow < SCANRATE; currRow++) {

        // 1. Begin with OE, CLK, LAT set to low
        OE_PORT->BRR  |= OE_PIN;
        CLK_PORT->BRR |= CLK_PIN;
        LAT_PORT->BRR |= LAT_PIN;
        
        // 2. Initialize row counter N -> 0
        // 6. Repeat steps 3-5 WIDTH times for the remaining columns.
        for (int currColumn = 0; currColumn < SCREENWIDTH; currColumn++) {
            
            // 3. Set R1,G1,B1 to the desired color for row N, column 0.
            // 4. Set R2,G2,B2 to the desired color for row HEIGHT/2+N, column 0.
            R1_PORT->BRR |= (0b111111 << COLOR_OFFSET);
            R1_PORT->BSRR |= screenBuffer[(currRow * SCREENWIDTH) + currColumn] << COLOR_OFFSET;
        
            // 5. Set CLK high, then low, to shift in the color bit.
            CLK_PORT->BSRR |= CLK_PIN;
            while (!(CLK_PORT->ODR & CLK_PIN)) { }
            CLK_PORT->BRR |= CLK_PIN;

        }

        // 7. Set OE high to disable the LEDs.
        OE_PORT->BSRR |= OE_PIN;

        // 8. Set LAT high, then low, to load the shift register contents into the LED outputs.
        LAT_PORT->BSRR |= LAT_PIN;    
        while (!(LAT_PORT->ODR & LAT_PIN)) { }
        LAT_PORT->BRR |= LAT_PIN;    
        
        // 9. Set ABC (or ABCD) to the current row number N.
        ROW_A_PORT->BRR |= (0b11111 << ROW_OFFSET);
        ROW_A_PORT->BSRR |= (currRow << ROW_OFFSET);

        // 10. Set OE low to re-enable the LEDs.
        OE_PORT->BRR |= OE_PIN;
    }
}

void setPixel(uint8_t x, uint8_t y, uint8_t color){
	if (x > SCREENWIDTH || y > SCREENHEIGHT)
		return;

	// color 0 = black, 1 = blue, 2 = green, 3 = cyan, 4 = red, 5 = magenta, 6 = yellow, 7 = white
	if (y < SCREENHEIGHT/2)
	{
		// top half of matrix, color value is in bits 0-2
		uint16_t addr = y*SCREENWIDTH + x;
		screenBuffer[addr] &= ~0x7;
		screenBuffer[addr] |= (color & 0x7);
	}
	else
	{
		// bottom half of matrix, color value is in bits 3-5
		uint16_t addr = (y-SCREENHEIGHT/2)*SCREENWIDTH + x;
		screenBuffer[addr] &= ~0x38;
		screenBuffer[addr] |= ((color & 0x7) << 3);
	}
}
#pragma once

#include "stm32f0xx_hal.h"

// LED Matrix Clock, Latch, and Output Enable pins
#define CLK_PORT GPIOC
#define CLK_PIN  GPIO_PIN_12

#define LAT_PORT GPIOC
#define LAT_PIN  GPIO_PIN_11

#define OE_PORT  GPIOD
#define OE_PIN   GPIO_PIN_2

// LED Matrix Row Select pins (A-E)
#define ROW_A_PORT GPIOC
#define ROW_A_PIN  GPIO_PIN_6

#define ROW_B_PORT GPIOC
#define ROW_B_PIN  GPIO_PIN_7

#define ROW_C_PORT GPIOC
#define ROW_C_PIN  GPIO_PIN_8

#define ROW_D_PORT GPIOC
#define ROW_D_PIN  GPIO_PIN_9

#define ROW_E_PORT GPIOC
#define ROW_E_PIN  GPIO_PIN_10

// LED Matrix RGB pins
// Note: Must be consecutive
#define R1_PORT GPIOC
#define R1_PIN  GPIO_PIN_0

#define G1_PORT GPIOC
#define G1_PIN  GPIO_PIN_1

#define B1_PORT GPIOC
#define B1_PIN  GPIO_PIN_2

#define R2_PORT GPIOC
#define R2_PIN  GPIO_PIN_3

#define G2_PORT GPIOC
#define G2_PIN  GPIO_PIN_4

#define B2_PORT GPIOC
#define B2_PIN  GPIO_PIN_5

#define LED_MATRIX_ROW_PINS (ROW_A_PIN | ROW_B_PIN | ROW_C_PIN | ROW_D_PIN | ROW_E_PIN)
#define LED_MATRIX_RGB_PINS (R1_PIN | G1_PIN | B1_PIN | R2_PIN | G2_PIN | B2_PIN)

#define TRIG1_PORT GPIOB
#define TRIG1_PIN GPIO_PIN_2

#define ECHO1_PORT GPIOB
#define ECHO1_PIN GPIO_PIN_3
 
#define TRIG2_PORT
#define TRIG2_PIN
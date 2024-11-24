#pragma once

#include "stm32f0xx_hal.h"

/**
  * @brief  Set the selected data port bit.
  * @note   This function uses GPIOx_BSRR and GPIOx_BRR registers to allow atomic read/modify
  *         accesses. In this way, there is no risk of an IRQ occurring between
  *         the read and the modify access.
  *
  * @param  GPIOx where x can be (A..H) to select the GPIO peripheral for STM32F0 family
  * @param  GPIO_Pin specifies the port bit to be written.
  *          This parameter can be one of GPIO_PIN_x where x can be (0..15).
  * @retval None
  */
#define GPIO_ON(port, pin)  HAL_GPIO_WritePin(port, pin, GPIO_PIN_SET)

/**
  * @brief  Reset the selected data port bit.
  * @note   This function uses GPIOx_BSRR and GPIOx_BRR registers to allow atomic read/modify
  *         accesses. In this way, there is no risk of an IRQ occurring between
  *         the read and the modify access.
  *
  * @param  GPIOx where x can be (A..H) to select the GPIO peripheral for STM32F0 family
  * @param  GPIO_Pin specifies the port bit to be written.
  *          This parameter can be one of GPIO_PIN_x where x can be (0..15).
  * @retval None
  */
#define GPIO_OFF(port, pin)  HAL_GPIO_WritePin(port, pin, GPIO_PIN_RESET)

/**
  * @brief  Toggle the specified GPIO pin.
  * @param  GPIOx where x can be (A..F) to select the GPIO peripheral for STM32F0 family
  * @param  GPIO_Pin specifies the pin to be toggled.
  * @retval None
  */
#define GPIO_TOGGLE(port, pin) HAL_GPIO_TogglePin(port, pin)

/**
  * @brief  Provides a tick value in millisecond.
  * @note   This function is declared as __weak  to be overwritten  in case of other 
  *       implementations in user file.
  * @retval tick value
  */
#define GET_TICK()  HAL_GetTick()
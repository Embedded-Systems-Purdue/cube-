#include "main.h"
#include "ultrasonic.h"
#include "tim.h"

void UltrasonicSensor::update() {

    uint32_t Value1 = 0;
    uint32_t Value2 = 0;
    uint32_t pMillis;

    HAL_GPIO_WritePin(trigPort, trigPin, GPIO_PIN_SET);  // pull the TRIG pin HIGH
    __HAL_TIM_SET_COUNTER(&htim1, 0);
    HAL_Delay(1);
    // while (__HAL_TIM_GET_COUNTER (&htim1) < 10);  // wait for 10 us
    HAL_GPIO_WritePin(trigPort, trigPin, GPIO_PIN_RESET);  // pull the TRIG pin low

    pMillis = HAL_GetTick(); // used this to avoid infinite while loop  (for timeout)
    // wait for the echo pin to go high
    while (!(HAL_GPIO_ReadPin (echoPort, echoPin)) && pMillis + 10 >  HAL_GetTick());
    Value1 = __HAL_TIM_GET_COUNTER (&htim1);

    pMillis = HAL_GetTick(); // used this to avoid infinite while loop (for timeout)
    // wait for the echo pin to go low
    while ((HAL_GPIO_ReadPin (echoPort, echoPin)) && pMillis + 50 > HAL_GetTick());
    Value2 = __HAL_TIM_GET_COUNTER(&htim1);

    distance = (Value2-Value1)* 0.034/2;

    return;
}
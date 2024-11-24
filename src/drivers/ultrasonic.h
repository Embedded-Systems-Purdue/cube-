#pragma once
#include <main.h>

#ifdef __cplusplus

class UltrasonicSensor {
private:
    GPIO_TypeDef *trigPort;    // 1st
    GPIO_TypeDef *echoPort;    // 2nd
    uint16_t trigPin;          // 3rd
    uint16_t echoPin;          // 4th
    TIM_HandleTypeDef *htim;   // 5th
    float distance;            // 6th

public:
    inline UltrasonicSensor(
        GPIO_TypeDef *trigPort, 
        GPIO_TypeDef *echoPort, 
        uint16_t trigPin, 
        uint16_t echoPin, 
        TIM_HandleTypeDef *htim
    ) : 
        // Order must match the order of declaration above
        trigPort(trigPort),    // 1st
        echoPort(echoPort),    // 2nd
        trigPin(trigPin),      // 3rd
        echoPin(echoPin),      // 4th
        htim(htim),            // 5th
        distance(0)            // 6th
    {}

    void update();
    uint16_t getDistance() { return distance; }
};

#endif // __cplusplus

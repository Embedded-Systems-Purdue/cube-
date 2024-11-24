#pragma once

#include <stdint.h>
#include "led.h"
#include "ledMatrix.h"
#include "ultrasonic.h"

#ifdef __cplusplus
class App {
public:
    static void init();
    static void loop();

private:
    static Led led1;

};

extern "C" {
#endif

void app_init(void);
void app_loop(void);

#ifdef __cplusplus
}
#endif // __cplusplus
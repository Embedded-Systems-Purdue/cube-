#include "app.h"
#include "hardwareConfig.h"
#include "tim.h"


UltrasonicSensor leftPaddle(TRIG1_PORT, ECHO1_PORT, TRIG1_PIN, ECHO1_PIN, &htim1);

void App::init() {
    // led1.startBlink(1000);
    bufferInit();
    setPixel(0,0,WHITE);
}

void App::loop() {
    matrixDisplay();
    leftPaddle.update();
    int x = leftPaddle.getDistance();
    // led1.update();
    HAL_Delay(100);
}

// C interface implementations
extern "C" {
    void app_init(void) { App::init(); }
    void app_loop(void) { App::loop(); }
}
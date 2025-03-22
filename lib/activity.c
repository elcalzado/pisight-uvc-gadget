#include <signal.h>
#include <stdio.h>
#include <pigpio.h>

#include "activity.h"

const int activity_led = BCM_PIN_NUM;
static int gpio_initialized = 0;

int gpio_init() {
    if (gpio_initialized) return 0;

    if (gpioInitialise() == PI_INIT_FAILED) {
        printf("error: Failed to initialize the GPIO interface.\n");
        return 1;
    }

    gpio_initialized = 1;

    return 0;
}

int activity_led_on() {
    if (!gpio_initialized) return 1;

    if (gpioGetMode(activity_led) != PI_OUTPUT)
        gpioSetMode(activity_led, PI_OUTPUT);
    gpioWrite(activity_led, PI_HIGH);

    printf("Activity led on\n");

    return 0;
}

void activity_led_off() {
    if (gpio_initialized) {
        if (gpioGetMode(activity_led) != PI_OUTPUT)
            gpioSetMode(activity_led, PI_OUTPUT);
        gpioWrite(activity_led, PI_LOW);

        printf("Activity led off\n");
    }
}

int activity_led_error() {
    if (!gpio_initialized) return 1;

    printf("Activity led indicating error\n");

    if (gpioGetMode(activity_led) != PI_OUTPUT)
        gpioSetMode(activity_led, PI_OUTPUT);
    for (int i = 0; i < 5; i++) {
        gpioWrite(activity_led, PI_HIGH);
        time_sleep(1);
        gpioWrite(activity_led, PI_LOW);
        time_sleep(1);
    }

    return 0;
}

void gpio_cleanup() {
    if (gpio_initialized) {
        if (gpioGetMode(activity_led) != PI_OUTPUT)
            gpioSetMode(activity_led, PI_OUTPUT);
        gpioWrite(activity_led, PI_LOW);
        gpioSetMode(activity_led, PI_INPUT);

        gpioTerminate();
        gpio_initialized = 0;
    }
}
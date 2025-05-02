#include <signal.h>
#include <stdio.h>
#include "gpio.h"

static int gpio_initialized = 0;

int gpio_init() {
    if (gpio_initialized) return 0;

    if (gpioInitialise() == PI_INIT_FAILED) {
        fprintf(stderr, "error: Failed to initialize the GPIO interface.\n");
        return 1;
    }

    gpio_initialized = 1;

    return 0;
}

void gpio_cleanup() {
    if (gpio_initialized) {
        if (gpioGetMode(activity_led) != PI_OUTPUT) {
            if (gpioSetMode(activity_led, PI_OUTPUT) != 0) {
                fprintf(stderr, "error: Failed to set GPIO mode to OUTPUT during cleanup.\n");
            }
        }
        if (gpioWrite(activity_led, PI_LOW) != 0) {
            fprintf(stderr, "error: Failed to set GPIO to LOW during cleanup.\n");
        }
        gpioSetMode(activity_led, PI_INPUT);

        gpioTerminate();
        gpio_initialized = 0;
    }
}
#include <stdio.h>
#include "led.h"

int led_on(int led_pin) {
    if (!gpio_initialized) return 1;

    if (gpioWrite(led_pin, PI_HIGH) != 0) {
        fprintf(stderr, "error: Failed to set LED to HIGH.\n");
        return 1;
    }

    return 0;
}

int led_off(int led_pin) {
    if (!gpio_initialized) return 1;
    
    if (gpioWrite(led_pin, PI_LOW) != 0) {
        fprintf(stderr, "error: Failed to set LED to LOW.\n");
        return 1;
    }

    return 0;
}

int activity_led_error() {
    if (!gpio_initialized) return 1;

    for (int i = 0; i < 5; i++) {
        if (gpioWrite(activity_led, PI_HIGH) != 0) {
            fprintf(stderr, "error: Failed to set activity LED to HIGH.\n");
            return 1;
        }
        time_sleep(1);
        if (gpioWrite(activity_led, PI_LOW) != 0) {
            fprintf(stderr, "error: Failed to set activity LED to LOW.\n");
            return 1;
        }
        time_sleep(1);
    }

    return 0;
}
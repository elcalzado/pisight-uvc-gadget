#include <pigpio.h>
#include <stdio.h>

#include "gpio.h"
#include "led.h"
#include "shutter.h"

static int gpio_initialized = 0;

const int logo_led = LOGO_BCM_PIN_NUM;
const int activity_led = ACTIVITY_BCM_PIN_NUM;

const int num_output_pins = 2;
const int output_pins[] = {logo_led, activity_led};

const int shutter_output = SHUTTER_OUTPUT_BCM_PIN_NUM;

const int num_input_pins = 1;
const int input_pins[] = {shutter_output};

int gpio_init()
{
    if (gpioInitialise() == PI_INIT_FAILED) {
        fprintf(stderr, "Failed to initialize the GPIO interface.\n");
        return 1;
    }

    for (int i = 0; i < num_output_pins; i++) {
        if (gpioSetMode(output_pins[i], PI_OUTPUT) != 0) {
            fprintf(stderr, "Failed to set GPIO mode to OUTPUT.\n");
            return 1;
        }
    }

    for (int i = 0; i < num_input_pins; i++) {
        if (gpioSetMode(input_pins[i], PI_INPUT) != 0) {
            fprintf(stderr, "Failed to set GPIO mode to INPUT.\n");
            return 1;
        }
    }

    gpio_initialized = 1;

    return 0;
}

void gpio_cleanup()
{
    if (gpio_initialized) {
        for (int i = 0; i < num_output_pins; i++) {
            if (gpioWrite(output_pins[i], PI_LOW) != 0) {
                fprintf(stderr, "Failed to set GPIO to LOW during cleanup.\n");
            }

            if (gpioSetMode(output_pins[i], PI_INPUT) != 0) {
                fprintf(stderr, "Failed to set GPIO mode to INPUT during cleanup.\n");
            }
        }

        gpioTerminate();
        gpio_initialized = 0;
    }
}

int is_gpio_init()
{
    return gpio_initialized;
}
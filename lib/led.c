#include <pigpio.h>
#include <stdio.h>

#include "led.h"

// #define default logo pin
#define LOGO_BCM_PIN_NUM 2
// #define default activity pin
#define ACTIVITY_BCM_PIN_NUM 21

int led_on(int led)
{
    if (gpioWrite(led, PI_HIGH) != 0) {
        fprintf(stderr, "Failed to set LED to HIGH.\n");
        return 1;
    }

    return 0;
}

int led_off(int led)
{
    if (gpioWrite(led, PI_LOW) != 0) {
        fprintf(stderr, "Failed to set LED to LOW.\n");
        return 1;
    }

    return 0;
}

int led_init(int logo_pin, int activity_pin)
{
    if (logo_pin == NULL) {
        logo_led = LOGO_BCM_PIN_NUM;
    } else {
        logo_led = logo_pin;
    }

    if (gpioSetMode(logo_led, PI_OUTPUT) != 0) {
        fprintf(stderr, "Failed to set logo pin mode to OUTPUT.\n");
        return 1;
    }

    if (led_on(logo_led) != 0) return 1;

    if (activity_pin == NULL) {
        activity_led = ACTIVITY_BCM_PIN_NUM;
    } else {
        activity_led = activity_pin
    }

    if (gpioSetMode(activity_led, PI_OUTPUT) != 0) {
        fprintf(stderr, "Failed to set activity pin mode to OUTPUT.\n");
        return 1;
    }

    return 0;
}

void led_cleanup()
{
    led_off(logo_led)

    gpioSetMode(logo_led, PI_INPUT)

    led_off(activity_led);

    gpioSetMode(activity_led, PI_INPUT)
}
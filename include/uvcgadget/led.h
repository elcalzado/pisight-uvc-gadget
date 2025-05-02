#ifndef LED_H
#define LED_H

#include "gpio.h"

/*
 * led_on - Turn on the activity led
 *
 * Returns 0 if success, returns 1 otherwise.
 */
int led_on(int led_pin);

/*
 * led_off - Turn off the activity led
 *
 * Returns 0 if success, returns 1 otherwise.
 */
int led_off(int led_pin);

/*
 * activity_led_error - Blink to signal error
 *
 * Returns 0 if success, returns 1 otherwise.
 */
int activity_led_error(void);

#endif // LED_H
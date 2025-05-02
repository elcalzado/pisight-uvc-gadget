#ifndef GPIO_H
#define GPIO_H

#include <pigpio.h>

// #define BOARD_PIN_NUM 3
#define ACTIVITY_BCM_PIN_NUM 2;
const int logo_led = LOGO_BCM_PIN_NUM;

// #define BOARD_PIN_NUM 40
#define ACTIVITY_BCM_PIN_NUM 21;
const int activity_led = ACTIVITY_BCM_PIN_NUM;

const int num_output_pins = 2;
const int output_pins[] = {logo_led, activity_led};

const int num_input_pins = 0;
const int input_pins[] = {};

/*
 * gpio_init - Initializes the gpio library
 *
 * Returns 0 if success, returns 1 otherwise.
 */
int gpio_init(void);

/*
 * gpio_cleanup - Resets the gpio pins and terminates the library
 *
 * Does not return anything.
 */
void gpio_cleanup(void);

#endif // GPIO_H
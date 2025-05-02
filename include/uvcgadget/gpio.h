#ifndef GPIO_H
#define GPIO_H

#include <pigpio.h>

// #define BOARD_PIN_NUM 40
#define ACTIVITY_BCM_PIN_NUM 21;
const int activity_led = ACTIVITY_BCM_PIN_NUM;

/*
 * gpio_init - If needed, initializes the gpio library
 *
 * Returns 0 if success, returns 1 otherwise.
 */
int gpio_init(void);

/*
 * gpio_cleanup - If needed, resets the gpio pin and terminates the library
 *
 * Does not return anything.
 */
void gpio_cleanup(void);

#endif // GPIO_H
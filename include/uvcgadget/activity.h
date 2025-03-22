#ifndef ACTIVITY_H
#define ACTIVITY_H

#define BCM_PIN_NUM 21
// #define BOARD_PIN_NUM 40

/*
 * gpio_init - If needed, initializes the gpio library
 *
 * Returns 0 if success, returns 1 otherwise.
 */
int gpio_init(void);

/*
 * activity_led_on - Turn on the activity led
 *
 * Returns 0 if success, returns 1 otherwise.
 */
int activity_led_on(void);

/*
 * activity_led_off - Turn off the activity led
 *
 * Does not return anything.
 */
void activity_led_off(void);

/*
 * activity_led_error - Blink to signal error
 *
 * Returns 0 if success, returns 1 otherwise.
 */
int activity_led_error(void);

/*
 * gpio_reset - If needed, resets the gpio pin and terminates the library
 *
 * Does not return anything.
 */
void gpio_cleanup(void);

#endif // ACTIVITY_H
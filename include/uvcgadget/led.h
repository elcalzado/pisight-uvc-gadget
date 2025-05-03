#ifndef LED_H
#define LED_H

// #define BOARD_PIN_NUM 3
#define LOGO_BCM_PIN_NUM 2;
const int logo_led = LOGO_BCM_PIN_NUM;

// #define BOARD_PIN_NUM 40
#define ACTIVITY_BCM_PIN_NUM 21;
const int activity_led = ACTIVITY_BCM_PIN_NUM;

/*
 * led_on - Turn on the activity led
 *
 * Returns 0 if success, returns 1 otherwise.
 */
int led_on(int led);

/*
 * led_off - Turn off the activity led
 *
 * Returns 0 if success, returns 1 otherwise.
 */
int led_off(int led);

/*
 * activity_led_error - Blink to signal error
 *
 * Returns 0 if success, returns 1 otherwise.
 */
int activity_led_error(void);

#endif // LED_H
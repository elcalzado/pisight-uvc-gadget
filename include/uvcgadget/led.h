#ifndef LED_H
#define LED_H

extern int logo_led;
extern int activity_led;

/*
 * led_on - Turn on an LED specified by pin num
 *
 * Returns 0 if success, returns 1 otherwise.
 */
int led_on(int led);

/*
 * led_off - Turn off an LED specified by pin num
 *
 * Returns 0 if success, returns 1 otherwise.
 */
int led_off(int led);

/*
 * led_init - Set logo and activity pins to output
 *
 * Returns 0 if success, returns 1 otherwise.
 */
int led_init(int logo_pin, int activity_pin);

/*
 * led_cleanup - Turns off LEDs and sets GPIO to input
 *
 * Doesn't return anything.
 */
void led_cleanup();

#endif // LED_H
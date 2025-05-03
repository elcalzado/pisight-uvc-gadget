#ifndef GPIO_H
#define GPIO_H

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

/*
 * is_gpio_init() - Checks if GPIO has been initialized
 *
 * Returns 1 if initialized, zero otherwise.
 */
int is_gpio_init(void);

#endif // GPIO_H
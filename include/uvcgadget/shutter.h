#ifndef SHUTTER_H
#define SHUTTER_H

// #define default shutter related pins
#define SHUTTER_POWER_BCM_PIN_NUM 13
#define SHUTTER_OUTPUT_BCM_PIN_NUM 19
#define SHUTTER_ANODE_BCM_PIN_NUM 26

struct uvc_stream;
struct events;

/*
 * shutter_init - Sets default state for shutter related pins
 *
 * Returns 0 if success, returns 1 otherwise.
 */
int shutter_init(int *shutter_pins, struct uvc_stream *stream_ptr, struct events *events_ptr);

/*
 * shutter_cleanup - Turns off shutter power and sets GPIO to input
 *
 * Doesn't return anything.
 */
void shutter_cleanup();

// Returns shutter status
int get_shutter_status();

#endif // SHUTTER_H
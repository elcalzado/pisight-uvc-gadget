#ifndef SHUTTER_H
#define SHUTTER_H

struct uvc_stream;
struct events;

/*
 * shutter_init - Sets default state for shutter related pins
 *
 * Returns 0 if success, returns 1 otherwise.
 */
int shutter_init(int *shutter_power_pin, int *shutter_output_pin, int *shutter_anode_pin, struct uvc_stream *stream_ptr, struct events *events_ptr);

/*
 * shutter_cleanup - Turns off shutter power and sets GPIO to input
 *
 * Doesn't return anything.
 */
void shutter_cleanup();

#endif // SHUTTER_H
#ifndef SHUTTER_H
#define SHUTTER_H

/*
 * shutter_init - Sets default state for shutter related pins
 *
 * Returns 0 if success, returns 1 otherwise.
 */
int shutter_init(struct uvc_stream *stream_ptr, struct events *events_ptr);

/*
 * shutter_cleanup - Turns off shutter power and sets GPIO to input
 *
 * Doesn't return anything.
 */
void shutter_cleanup();

#endif // SHUTTER_H
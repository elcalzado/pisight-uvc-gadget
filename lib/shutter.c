#include <fcntl.h>
#include <pigpio.h>
#include <stdio.h>
#include <unistd.h>

#include "events.h"
#include "shutter.h"
#include "stream.h"

static struct uvc_stream *stream;
static struct events *events;

static int shutter_power = SHUTTER_POWER_BCM_PIN_NUM;
static int shutter_status = 0;

static int shutter_pipe_fds[2];

static void shutter_event(void *priv __attribute__((unused)))
{
    uint8_t level;
    if (read(shutter_pipe_fds[0], &level, 1) != 1) return;

    // Open (0) or closed (1)
    shutter_status = (level == PI_HIGH) ? 1 : 0;

    uvc_stream_pause(stream, shutter_status);

    printf("Shutter %s - Stream %s\n",
            !shutter_status ? "OPEN" : "CLOSED",
            !shutter_status ? "ACTIVE" : "PAUSED");
}

static void shutter_callback(int pin __attribute__((unused)), int level, uint32_t tick __attribute__((unused)))
{
    uint8_t l = (uint8_t)level;
    write(shutter_pipe_fds[1], &l, 1);
}

int shutter_init(int *shutter_pins, struct uvc_stream *stream_ptr, struct events *events_ptr)
{
    stream = stream_ptr;
    events = events_ptr;

    if (pipe(shutter_pipe_fds) < 0) {
        perror("pipe");
        return 1;
    }

    fcntl(shutter_pipe_fds[0], F_SETFL, O_NONBLOCK);
    fcntl(shutter_pipe_fds[1], F_SETFL, O_NONBLOCK);

    events_watch_fd(events, shutter_pipe_fds[0], EVENT_READ, shutter_event, NULL);

    if (shutter_pins[0] != -1) {
        shutter_power = shutter_pins[0];
    }

    if (gpioSetMode(shutter_power, PI_OUTPUT) != 0) {
        fprintf(stderr, "Failed to set shutter power to OUTPUT.\n");
        return 1;
    }

    if (gpioWrite(shutter_power, PI_HIGH) != 0) {
        fprintf(stderr, "Failed to shutter power to HIGH.\n");
        return 1;
    }

    int shutter_output = SHUTTER_OUTPUT_BCM_PIN_NUM;
    if (shutter_pins[1] != -1) {
        shutter_output = shutter_pins[1];
    }

    if (gpioSetMode(shutter_output, PI_INPUT) != 0) {
        fprintf(stderr, "Failed to set shutter output to INPUT.\n");
        return 1;
    }

    int shutter_anode = SHUTTER_ANODE_BCM_PIN_NUM;
    if (shutter_pins[2] != -1) {
        shutter_anode = shutter_pins[2];
    }

    if (gpioSetMode(shutter_anode, PI_INPUT) != 0) {
        fprintf(stderr, "Failed to set shutter anode to INPUT.\n");
        return 1;
    }

    if (gpioSetAlertFunc(shutter_output, shutter_callback) != 0) {
        fprintf(stderr, "Failed to set shutter alert function.\n");
        return 1;
    }

    shutter_status = gpioRead(shutter_output) == PI_HIGH ? 1 : 0;
    if (uvc_stream_pause(stream, shutter_status) != 0) {
        fprintf(stderr, "Failed to set initial state to pause.\n");
        return 1;
    }

    return 0;
}

void shutter_cleanup()
{
    if (gpioWrite(shutter_power, PI_LOW) != 0) {
        fprintf(stderr, "Failed to shutter power to LOW.\n");
    }

    if (gpioSetMode(shutter_power, PI_INPUT) != 0) {
        fprintf(stderr, "Failed to set shutter power to INPUT.\n");
    }
}

int get_shutter_status() {
    return shutter_status;
}
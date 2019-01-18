#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include "system.h"
#include "pio.h"
#include "navswitch.h"
#include "tinygl.h"
#include "remote.h"
#include "pacer.h"
#include "font5x7_1.h"

#define RATE 150

void initialise(void)
{
    system_init ();
    navswitch_init ();
    pacer_init(RATE);
    remote_init();
    tinygl_init (RATE);
    tinygl_text_mode_set(TINYGL_TEXT_MODE_STEP);
    tinygl_text_dir_set(TINYGL_TEXT_DIR_NORMAL);
    tinygl_font_set (&font5x7_1);
}

int main(void)
{
    // Initialise system
    initialise();
    char c;


    while (1) {
        c = remote_read();
        if (c != -1) {
            tinygl_text(&c);
        }

        // if (navswitch_push_event_p(NAVSWITCH_DOWN)) {
        //     on != on;
        //
        //     if (on) {
        //         motor_on();
        //     } else {
        //         motor_off();
        //     }
        // }

        tinygl_update();
        pacer_wait();
    }
}

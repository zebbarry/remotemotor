#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include "system.h"
#include "pio.h"
#include "navswitch.h"
#include "motor.h"

int main(void)
{
    // Initialise system
    system_init ();
    navswitch_init ();
    ledmat_init ();

    bool on = false;

    while (1) {
        if (navswitch_push_event_p(NAVSWITCH_DOWN)) {
            on != on;

            if (on) {
                motor_on();
            } else {
                motor_off();
            }
        }
    }
}

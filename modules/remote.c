/** @file remote.c
 *  @author Zeb Barry
 *  @date 18 January 2019
 *  @brief Remote class
 *  @note Defines remote control and use
 */

#include "system.h"
#include "ir_uart.h"


void remote_init(void)
{
    ir_uart_init();
}

// Reads from ir transmitter, returning -1 if nothing to read.
int remote_read(void)
{
    int c;

    if (ir_uart_read_ready_p()) {
        c = ir_uart_getc();
    } else {
        c = -1;
    }

    return c;
}

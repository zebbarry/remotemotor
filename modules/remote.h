/** @file remote.h
 *  @author Zeb Barry
 *  @date 18 January 2019
 *  @brief Remote class header
 */

#ifndef REMOTE_H
#define REMOTE_H

#include "system.h"

void remote_init(void);

// Reads from ir transmitter, returning -1 if nothing to read.
int remote_read(void);

#endif

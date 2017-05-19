//
// Created by pi on 5/3/17.
//

#ifndef UTIL_H
#define UTIL_H

#include <stdio.h>
#include <stdint.h>
#include <stdarg.h>

// Constant/ boundary definitions
#define BUFFER_LENGTH 256

// Global variable definitions
// Debug (verbose) mode [1 or 0]
extern uint8_t DEBUG_VERBOSE;

// Function descriptions
void debug_output(const char *, ...);

#endif // UTIL_H

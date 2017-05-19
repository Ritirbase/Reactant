//
// Created by pi on 5/3/17.
//

#include "util.h"

// Global variable instantiations
uint8_t DEBUG_VERBOSE = 0;

void debug_output(const char * format, ...)
{
    char buffer[BUFFER_LENGTH];
    va_list args;

    if (DEBUG_VERBOSE == 1)
    {
        // Initialize variable argument list
        va_start(args, format);

        // Write formatted string into buffer
        vsnprintf(buffer, sizeof(buffer), format, args);

        // Print formatted string
        printf(buffer);

        // Clean up memory allocated to variable argument list
        va_end(args);
    }
}
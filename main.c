#include <unistd.h>
#include <signal.h>
#include <stdlib.h>

#include "util.h"
#include "socket.h"

void graceful_terminate(int);

int main(int argc, char * argv[])
{
    server_error_t r;
    int c;

    // Install signal interceptor(s)
    signal(SIGINT, graceful_terminate);
    signal(SIGTERM, graceful_terminate);

    // Parse command line options
    while ((c = getopt(argc, argv, "v")) != -1)
    {
        switch (c)
        {
            // Verbose operation; 'debug_output' will output to console.
            case 'v':
                DEBUG_VERBOSE = 1;

                break;
            default: ;
        }
    }

    // Main program loop to support state machine server.
    // This is done to allow other operations time to function as well.
    while(1)
    {
        // Start or resume server operations.
        // Server is implemented via non-blocking state machine.
        r = start_server();
        if (r != E_SUCCESS)
        {
            // Output error that caused server to fail
            debug_output("\n%s%s%c\n", "Server operation discontinued. Reason: '", SERVER_ERROR_REASON[r], '\'');

            return 1;
        }
        // Other operations go here:

    }

    return 0;
}

void graceful_terminate(int signal)
{
    switch(signal)
    {
        case SIGINT:
        case SIGTERM:
            // Program cleanup


            break;
        default: ;
    }

    debug_output("%s", "Program terminated gracefully.\n");
    exit(0);
}
//
// Created by pi on 5/3/17.
//

#include "socket.h"

char * SERVER_ERROR_REASON[4] = {
        "Success",
        "General failure",
        "Failed to create server socket",
        "Failed to bind to port",
};

server_error_t start_server()
{
    static socket_t server_socket;
    static socket_t client_sockets[MAX_CLIENTS];
    char buffer[BUFFER_LENGTH];
    struct sockaddr_in server_address, client_address;

    static enum
    {
        S_INITIAL = 0,
        S_CREATE_SOCKET,
        S_BIND,
        S_LISTEN,
        S_OPERATE,
        S_COMPLETE,

    } server_state = S_INITIAL;

    // State machine
    switch(server_state)
    {
        // Initialize server
        case S_INITIAL:
            debug_output("%-26s", "Initializing server... ");

            // Clear all client sockets
            for (int i = 0; i < MAX_CLIENTS; ++i)
            {
                client_sockets[i] = INVALID_SOCKET;
            }

            debug_output("%s\n", "Done.");
            ++server_state;
            break;

        // Create server socket
        case S_CREATE_SOCKET:
            debug_output("%-26s", "Creating socket... ");

            // Create server socket
            server_socket = socket(AF_INET, SOCK_STREAM, 0);
            if(server_socket < 0)
            {
                return E_SERVER_SOCKET;
            }

            server_address.sin_family = AF_INET;
            server_address.sin_addr.s_addr = INADDR_ANY;
            server_address.sin_port = htons(SERVER_PORT);

            debug_output("%s\n", "Done.");
            ++server_state;
            break;

        // Bind server socket to defined port
        case S_BIND:
            debug_output("%-26s","Binding to port... ");

            if(bind(server_socket, (struct sockaddr *) &server_address, sizeof(server_address)) < 0)
            {
                return E_BIND;
            }

            debug_output("%s\n", "Done.");
            ++server_state;
            break;

        // Listen for new connections and accept them
        case S_LISTEN:
            debug_output("%-26s", "Listening for client... ");



            debug_output("%s\n", "Done.");
            ++server_state;
            break;

        // Do something with the connection
        case S_OPERATE:
            debug_output("%-26s", "Handling client... ");



            debug_output("%s\n", "Done.");
            ++server_state;
            break;

        // Complete the connection
        case S_COMPLETE:
            debug_output("%-26s", "Terminating connection... ");

            close(server_socket);

            debug_output("%s\n", "Done.");
            server_state = S_INITIAL;
            getchar();
            break;

        // Server should never enter this state. Something weird happened.
        default:
            return E_GENERAL;
    }

    return E_SUCCESS;
}
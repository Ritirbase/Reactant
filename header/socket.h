//
// Created by pi on 5/3/17.
//

#ifndef SOCKET_H
#define SOCKET_H

#include <sys/socket.h>
#include <sys/types.h>
#include <netinet/in.h>
#include <netinet/ip.h>
#include <unistd.h>
#include "util.h"

// Constant/ boundary definitions
#define INVALID_SOCKET (-1)

// Configuration definitions
#define SERVER_PORT 15243
#define MAX_CLIENTS 32

// Type definitions
typedef int16_t socket_t; // uint16_t?

typedef enum _server_error_t // Server return codes
{
    E_SUCCESS = 0,
    E_GENERAL,
    E_SERVER_SOCKET,
    E_BIND,

} server_error_t;

typedef struct _channel_t // Channel definition
{
    char * name;

} channel_t;

// Define global variables
extern char * SERVER_ERROR_REASON[];

// Define functions
server_error_t start_server();

#endif // SOCKET_H

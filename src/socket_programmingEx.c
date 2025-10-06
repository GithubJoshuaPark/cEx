#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>     // For read(), close()
#include <sys/socket.h> // For socket(), connect()
#include <netdb.h>      // For getaddrinfo()

#include "socket_programmingEx.h"
#include "hello.h" // For printLine

void socket_programmingEx(void) {
    printLine("Demonstrating Socket Programming: Simple Time Client");

    const char *hostname = "example.com"; // A more reliable host
    const char *port = "80"; // HTTP port

    struct addrinfo hints, *servinfo, *p;
    int sockfd, rv;
    int bytes_read;
    char buffer[256];

    // 1. Set up hints and get address info for the server
    memset(&hints, 0, sizeof hints);
    hints.ai_family = AF_UNSPEC;     // Allow IPv4 or IPv6
    hints.ai_socktype = SOCK_STREAM; // TCP stream socket

    printf("Looking up host: %s on port %s\n", hostname, port);
    if ((rv = getaddrinfo(hostname, port, &hints, &servinfo)) != 0) {
        fprintf(stderr, "getaddrinfo: %s\n", gai_strerror(rv));
        return;
    }

    // 2. Loop through results and connect to the first one we can
    for(p = servinfo; p != NULL; p = p->ai_next) {
        // Create a socket
        if ((sockfd = socket(p->ai_family, p->ai_socktype, p->ai_protocol)) == -1) {
            perror("client: socket");
            continue;
        }

        // Connect to the server
        printf("Connecting to server...\n");
        if (connect(sockfd, p->ai_addr, p->ai_addrlen) == -1) {
            close(sockfd);
            perror("client: connect");
            continue;
        }

        break; // If we get here, we have connected successfully
    }

    if (p == NULL) {
        fprintf(stderr, "Failed to connect to any address for %s\n", hostname);
        freeaddrinfo(servinfo);
        return;
    }

    freeaddrinfo(servinfo); // All done with this structure

    printf("Connection successful! Sending HTTP GET request...\n\n");

    // 3. Send a simple HTTP GET request to the server.
    //    Web servers won't send anything until they receive a request.
    const char *http_request = "GET / HTTP/1.0\r\n\r\n";
    if (send(sockfd, http_request, strlen(http_request), 0) == -1) {
        perror("send");
        close(sockfd);
        return;
    }

    // 4. Read the response from the server
    printf("Server response (HTTP Headers):\n");
    bytes_read = read(sockfd, buffer, sizeof(buffer) - 1);
    if (bytes_read > 0) {
        buffer[bytes_read] = '\0'; // Null-terminate the string
        printf("  > %s", buffer);
    } else {
        perror("read");
    }

    // 5. Close the socket
    close(sockfd);
    printf("\nSocket closed.\n");
}
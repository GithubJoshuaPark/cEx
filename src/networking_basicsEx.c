#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <netdb.h>      // For getaddrinfo, gai_strerror
#include <sys/socket.h> // For AF_INET, AF_INET6
#include <arpa/inet.h>  // For inet_ntop

#include "networking_basicsEx.h"
#include "hello.h" // For printLine

void networking_basicsEx(void) {
    printLine("Demonstrating Networking Basics: Hostname to IP");

    const char *hostname = "www.google.com";
    struct addrinfo hints, *res, *p;
    int status;
    char ipstr[INET6_ADDRSTRLEN];

    // 1. Set up the hints structure.
    // This tells getaddrinfo what kind of addresses we're interested in.
    memset(&hints, 0, sizeof hints);
    hints.ai_family = AF_UNSPEC;     // AF_UNSPEC means we don't care if it's IPv4 or IPv6
    hints.ai_socktype = SOCK_STREAM; // We're interested in TCP stream sockets

    printf("Resolving hostname: %s\n\n", hostname);

    // 2. Call getaddrinfo to perform the DNS lookup.
    // It fills a linked list of addrinfo structures pointed to by 'res'.
    if ((status = getaddrinfo(hostname, "http", &hints, &res)) != 0) {
        fprintf(stderr, "getaddrinfo error: %s\n", gai_strerror(status));
        return;
    }

    printf("IP addresses for %s:\n\n", hostname);

    // 3. Loop through all the results and print them.
    for(p = res; p != NULL; p = p->ai_next) {
        void *addr;
        const char *ipver;

        // Get the pointer to the address itself,
        // which is stored in different fields for IPv4 and IPv6:
        if (p->ai_family == AF_INET) { // IPv4
            struct sockaddr_in *ipv4 = (struct sockaddr_in *)p->ai_addr;
            addr = &(ipv4->sin_addr);
            ipver = "IPv4";
        } else { // IPv6
            struct sockaddr_in6 *ipv6 = (struct sockaddr_in6 *)p->ai_addr;
            addr = &(ipv6->sin6_addr);
            ipver = "IPv6";
        }

        // Convert the IP to a string and print it
        inet_ntop(p->ai_family, addr, ipstr, sizeof ipstr);
        printf("  %s: %s\n", ipver, ipstr);
    }

    // 4. Free the linked list memory allocated by getaddrinfo.
    freeaddrinfo(res);
}
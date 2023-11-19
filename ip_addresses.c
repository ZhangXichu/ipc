#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <netinet/in.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netdb.h>
#include <arpa/inet.h>


int main() {
    struct sockaddr_in sa;    // IPv4
    struct sockaddr_in6 sa6;  // IPv6

    // Convert IP addresses from text to binary form
    inet_pton(AF_INET, "10.12.110.57", &(sa.sin_addr));    // IPv4
    inet_pton(AF_INET6, "2001:db8:63b3:1::3490", &(sa6.sin6_addr)); // IPv6

    // IPv4:

    char ip4[INET_ADDRSTRLEN];  // space to hold the IPv4 string
    
    // Convert IPv4 address from binary to text form
    inet_ntop(AF_INET, &(sa.sin_addr), ip4, INET_ADDRSTRLEN);

    printf("The IPv4 address is: %s\n", ip4);


    // IPv6:
    char ip6[INET6_ADDRSTRLEN]; // space to hold the IPv6 string

    // Convert IPv6 address from binary to text form
    inet_ntop(AF_INET6, &(sa6.sin6_addr), ip6, INET6_ADDRSTRLEN);

    printf("The address is: %s\n", ip6);

    return 0;
}
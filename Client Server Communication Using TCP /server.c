#include <stdio.h>
#include <stdlib.h>
#include <arpa/inet.h>
#include <sys/socket.h>
#include <string.h>
#include <netinet/in.h>
#include <unistd.h>

int main()
{
    int socdef, newsock, readval;
    struct sockaddr_in addr;

    char str[100], temp;

    int addrlen = sizeof(addr);

    // Create socket
    socdef = socket(AF_INET, SOCK_STREAM, 0);

    // Check socket creation
    if (socdef == 0)
    {
        printf("Socket creation failed");
        return -1;
    }

    // Define address family
    addr.sin_family = AF_INET;

    // Define port number
    addr.sin_port = htons(8086);

    // Accept connections from any IP
    addr.sin_addr.s_addr = INADDR_ANY;

    // Bind socket with IP and port
    if (bind(socdef, (struct sockaddr *)&addr, sizeof(addr)) < 0)
    {
        printf("Binding failed");
        return -1;
    }

    printf("Bind created\n");

    // Listen for client connections
    if (listen(socdef, 3) < 0)
    {
        printf("Listening failed");
        return -1;
    }

    printf("Listening....\n");

    // Accept client connection
    if ((newsock = accept(socdef,
        (struct sockaddr *)&addr,
        (socklen_t *)&addrlen)) < 0)
    {
        printf("Error in new socket creation");
        return -1;
    }

    printf("New socket created\n");

    // Receive string from client
    readval = read(newsock, str, sizeof(str));

    int i, j, k;

    // Find length of string
    k = strlen(str);

    // Reverse the string
    for (i = 0, j = k - 1; i < j; i++, j--)
    {
        temp = str[i];
        str[i] = str[j];
        str[j] = temp;
    }

    // Send reversed string to client
    send(newsock, str, strlen(str), 0);

    // Close sockets
    close(newsock);
    close(socdef);

    return 0;
}

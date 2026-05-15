#include <stdio.h>
#include <stdlib.h>
#include <arpa/inet.h>
#include <sys/socket.h>
#include <string.h>
#include <unistd.h>

int main()
{
    int socdef, readval;
    struct sockaddr_in addr;
    char str[100];

    // Create socket
    socdef = socket(AF_INET, SOCK_STREAM, 0);

    // Check socket creation
    if (socdef == 0)
    {
        printf("Socket creation failed");
        return -1;
    }

    // Initialize address structure to zero
    memset(&addr, 0, sizeof(addr));

    // Define address family
    addr.sin_family = AF_INET;

    // Define port number
    addr.sin_port = htons(8086);

    // Convert IP address into binary form
    if (inet_pton(AF_INET, "127.0.0.1", &addr.sin_addr) < 0)
    {
        printf("Error");
        return -1;
    }

    // Connect client to server
    if (connect(socdef, (struct sockaddr *)&addr, sizeof(addr)) < 0)
    {
        printf("Error in connection");
        return -1;
    }

    // Read string from user
    printf("Enter the string: ");
    scanf("%s", str);

    // Send string to server
    send(socdef, str, strlen(str), 0);

    // Receive reversed string from server
    readval = read(socdef, str, sizeof(str));

    // Display reversed string
    printf("Reversed string from server: %s\n", str);

    // Close socket
    close(socdef);

    return 0;
}

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <arpa/inet.h>
#include <sys/socket.h>
#include <netinet/in.h>

int main()
{
    int sockfd;
    int readval;

    struct sockaddr_in server;

    char str[100];

    // Create TCP socket
    sockfd = socket(AF_INET, SOCK_STREAM, 0);

    if (sockfd < 0)
    {
        printf("Socket creation failed\n");
        return 0;
    }

    // Server details
    server.sin_family = AF_INET;
    server.sin_port = htons(8086);

    inet_pton(AF_INET, "127.0.0.1",
              &server.sin_addr);

    // Connect to server
    if (connect(sockfd,
                (struct sockaddr *)&server,
                sizeof(server)) < 0)
    {
        printf("Error in connection\n");
        return 0;
    }

    // Input string
    printf("Enter the string: ");
    scanf("%s", str);

    // Send string to server
    send(sockfd, str, sizeof(str), 0);

    // Receive reversed string
    readval = read(sockfd, str, sizeof(str));

    // Display output
    printf("Reversed string from server: %s\n", str);

    // Close socket
    close(sockfd);

    return 0;
}

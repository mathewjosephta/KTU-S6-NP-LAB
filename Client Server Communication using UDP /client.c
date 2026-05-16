#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <arpa/inet.h>

int main()
{
    int sockfd;

    struct sockaddr_in server;

    int len = sizeof(server);

    char str[100];
    char result[100];

    // Create UDP socket
    sockfd = socket(AF_INET, SOCK_DGRAM, 0);

    if (sockfd < 0)
    {
        printf("Socket creation failed\n");
        return 0;
    }

    // Server details
    server.sin_family = AF_INET;
    server.sin_port = htons(8090);

    inet_pton(AF_INET,
              "127.0.0.1",
              &server.sin_addr);

    // Input string
    printf("Enter string: ");
    scanf("%s", str);

    // Send string to server
    sendto(sockfd,
           str,
           sizeof(str),
           0,
           (struct sockaddr *)&server,
           len);

    // Receive result from server
    recvfrom(sockfd,
             result,
             sizeof(result),
             0,
             (struct sockaddr *)&server,
             &len);

    // Display result
    printf("Server says: %s\n", result);

    // Close socket
    close(sockfd);

    return 0;
}

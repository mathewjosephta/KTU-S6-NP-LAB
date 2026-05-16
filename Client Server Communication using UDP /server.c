#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <arpa/inet.h>

int main()
{
    int sockfd;

    struct sockaddr_in server, client;

    int len = sizeof(client);

    char str[100];
    char result[100];

    int i, j, flag = 1;

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
    server.sin_addr.s_addr = INADDR_ANY;

    // Bind socket
    bind(sockfd,
         (struct sockaddr *)&server,
         sizeof(server));

    printf("Server waiting...\n");

    // Receive string from client
    recvfrom(sockfd,
             str,
             sizeof(str),
             0,
             (struct sockaddr *)&client,
             &len);

    printf("Received string: %s\n", str);

    // Check palindrome
    j = strlen(str) - 1;

    for (i = 0; i < j; i++, j--)
    {
        if (str[i] != str[j])
        {
            flag = 0;
            break;
        }
    }

    if (flag)
    {
        strcpy(result, "Palindrome");
    }
    else
    {
        strcpy(result, "Not Palindrome");
    }

    // Send result to client
    sendto(sockfd,
           result,
           sizeof(result),
           0,
           (struct sockaddr *)&client,
           len);

    // Close socket
    close(sockfd);

    return 0;
}

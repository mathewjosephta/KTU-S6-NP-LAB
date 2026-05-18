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
    struct sockaddr_in server, client;
    socklen_t clientlen = sizeof(client);
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

    // Initialize server structure
    memset(&server, 0, sizeof(server));

    // Server details
    server.sin_family = AF_INET;
    server.sin_port = htons(8090);
    server.sin_addr.s_addr = INADDR_ANY;

    // Bind socket
    if (bind(sockfd,(struct sockaddr *)&server,sizeof(server)) < 0)
    {
        printf("Binding failed\n");
        return 0;
    }

    printf("Server waiting...\n");

    // Receive string from client
    recvfrom(sockfd,str,sizeof(str),0,(struct sockaddr *)&client,&clientlen);

    printf("Received string: %s\n", str);

    // Find string length
    j = strlen(str) - 1;

    // Check palindrome
    for (i = 0; i < j; i++, j--)
    {
        if (str[i] != str[j])
        {
            flag = 0;
            break;
        }
    }

    // Store result
    if (flag)
    {
        strcpy(result, "Palindrome");
    }
    else
    {
        strcpy(result, "Not Palindrome");
    }

    // Send result
    sendto(sockfd,result,strlen(result) + 1,0,(struct sockaddr *)&client,clientlen);

    // Close socket
    close(sockfd);

    return 0;
}

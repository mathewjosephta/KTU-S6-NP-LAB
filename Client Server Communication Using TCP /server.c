#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <arpa/inet.h>
#include <sys/socket.h>
#include <netinet/in.h>

int main()
{
    int sockfd, newsockfd, readval;
    struct sockaddr_in server, client;
    int clientlen = sizeof(client);
    int i, j, k;
    char str[100], temp;

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
    server.sin_addr.s_addr = INADDR_ANY;

    // Bind socket
    if (bind(sockfd,(struct sockaddr *)&server,sizeof(server)) < 0)
    {
        printf("Binding failed\n");
        return 0;
    }
    printf("Bind created\n");

    // Listen for client
    if (listen(sockfd, 3) < 0)
    {
        printf("Listening failed\n");
        return 0;
    }
    printf("Listening....\n");

    // Accept client connection
    newsockfd = accept(sockfd,(struct sockaddr *)&client,(socklen_t *)&clientlen);

    if (newsockfd < 0)
    {
        printf("Accept failed\n");
        return 0;
    }
    printf("New socket created\n");

    // Receive string
    readval = read(newsockfd,str,sizeof(str));

    // Find string length
    k = strlen(str);

    // Reverse string
    for (i = 0, j = k - 1; i < j; i++, j--)
    {
        temp = str[i];
        str[i] = str[j];
        str[j] = temp;
    }

    // Send reversed string
    send(newsockfd,
         str,
         sizeof(str),
         0);

    // Close sockets
    close(newsockfd);
    close(sockfd);

    return 0;
}

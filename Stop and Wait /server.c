// STOP AND WAIT - SERVER SIDE

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <arpa/inet.h>
#include <sys/socket.h>
#include <netinet/in.h>

int main()
{
    int sockfd, newsockfd;

    struct sockaddr_in server, client;

    int clientlen = sizeof(client);

    char buffer[100];

    int frame;
    int readval;

    // Create TCP socket
    sockfd = socket(AF_INET,
                    SOCK_STREAM,
                    0);

    if (sockfd < 0)
    {
        printf("Socket creation failed\n");
        return 0;
    }

    // Server details
    server.sin_family = AF_INET;
    server.sin_port = htons(8080);
    server.sin_addr.s_addr = INADDR_ANY;

    // Bind socket
    if (bind(sockfd,
             (struct sockaddr *)&server,
             sizeof(server)) < 0)
    {
        printf("Binding failed\n");
        return 0;
    }

    // Listen for client
    if (listen(sockfd, 3) < 0)
    {
        printf("Listening failed\n");
        return 0;
    }

    printf("Server is listening on port 8080\n");

    // Accept client connection
    newsockfd = accept(sockfd,
                       (struct sockaddr *)&client,
                       (socklen_t *)&clientlen);

    if (newsockfd < 0)
    {
        printf("Accept failed\n");
        return 0;
    }

    printf("Connection established with client\n");

    // Receive frames continuously
    while (1)
    {
        // Clear buffer
        memset(buffer, 0, sizeof(buffer));

        // Read frame
        readval = read(newsockfd,
                       buffer,
                       sizeof(buffer));

        // Client disconnected
        if (readval <= 0)
        {
            printf("Connection closed by client\n");
            break;
        }

        // Convert string to integer
        sscanf(buffer, "%d", &frame);

        printf("Server: Received frame %d\n",
               frame);

        // Send acknowledgment
        sprintf(buffer, "%d", frame);

        send(newsockfd,
             buffer,
             sizeof(buffer),
             0);

        printf("Server: Sent acknowledgment for frame %d\n",
               frame);
    }

    // Close sockets
    close(newsockfd);
    close(sockfd);

    return 0;
}

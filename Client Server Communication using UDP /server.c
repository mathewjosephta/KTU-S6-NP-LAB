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

    char buffer[1024];

    int frame;

    int readval;

    // Create TCP socket
    sockfd = socket(AF_INET, SOCK_STREAM, 0);

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
    bind(sockfd,
         (struct sockaddr *)&server,
         sizeof(server));

    // Listen for client
    listen(sockfd, 3);

    printf("Server is listening on port 8080\n");

    // Accept client connection
    newsockfd = accept(sockfd,
                       (struct sockaddr *)&client,
                       (socklen_t *)&clientlen);

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

        if (readval <= 0)
        {
            printf("Connection closed by client\n");
            break;
        }

        // Convert string to integer
        sscanf(buffer, "%d", &frame);

        printf("Server: Received frame %d\n", frame);

        // Create acknowledgment
        sprintf(buffer,
                "ACK for frame %d",
                frame);

        // Send acknowledgment
        send(newsockfd,
             buffer,
             strlen(buffer),
             0);

        printf("Server: Sent acknowledgment for frame %d\n",
               frame);
    }

    // Close sockets
    close(newsockfd);
    close(sockfd);

    return 0;
}

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
    int frame, readval;

    struct sockaddr_in server, client;

    socklen_t clientlen = sizeof(client);

    char buffer[100];

    // Create TCP socket
    sockfd = socket(AF_INET,
                    SOCK_STREAM,
                    0);

    if (sockfd < 0)
    {
        printf("Socket creation failed\n");
        return 0;
    }

    // Initialize structure
    memset(&server, 0, sizeof(server));

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

    printf("Server listening on port 8080\n");

    // Accept connection
    newsockfd = accept(sockfd,
                       (struct sockaddr *)&client,
                       &clientlen);

    if (newsockfd < 0)
    {
        printf("Accept failed\n");
        return 0;
    }

    printf("Connection established\n");

    // Receive frames
    while (1)
    {
        memset(buffer, 0, sizeof(buffer));

        readval = read(newsockfd,
                       buffer,
                       sizeof(buffer));

        if (readval <= 0)
        {
            printf("Connection closed\n");
            break;
        }

        buffer[readval] = '\0';

        sscanf(buffer, "%d", &frame);

        printf("Received frame %d\n",
               frame);

        // Send acknowledgment
        sprintf(buffer, "%d", frame);

        send(newsockfd,
             buffer,
             strlen(buffer) + 1,
             0);

        printf("Acknowledgment sent for frame %d\n",
               frame);
    }

    close(newsockfd);
    close(sockfd);

    return 0;
}

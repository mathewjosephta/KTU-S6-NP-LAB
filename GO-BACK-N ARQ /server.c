#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <arpa/inet.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <time.h>

int main()
{
    int sockfd, newsockfd, readval;
    struct sockaddr_in server, client;
    socklen_t clientlen = sizeof(client);
    char str[100];
    int frame, randomvalue, ack = -1, expectedframe = 0;

    // Create TCP socket
    sockfd = socket(AF_INET, SOCK_STREAM, 0);
    if (sockfd < 0)
    {
        printf("Socket creation failed\n");
        return 0;
    }

    // Initialize server structure
    memset(&server, 0, sizeof(server));

    // Server details
    server.sin_family = AF_INET;
    server.sin_port = htons(8080);
    server.sin_addr.s_addr = INADDR_ANY;

    // Bind socket
    if (bind(sockfd,(struct sockaddr *)&server,sizeof(server)) < 0)
    {
        printf("Binding failed\n");
        return 0;
    }

    printf("Binding successful\n");

    // Listen for client
    if (listen(sockfd, 3) < 0)
    {
        printf("Listening failed\n");
        return 0;
    }

    printf("Waiting for connection...\n");

    // Accept client
    newsockfd = accept(sockfd,(struct sockaddr *)&client,&clientlen);
    if (newsockfd < 0)
    {
        printf("Accept failed\n");
        return 0;
    }

    printf("Connection established\n");

    srand(time(0));

    // Receive frames
    while (1)
    {
        memset(str, 0, sizeof(str));

        // Receive frame
        readval = read(newsockfd,str,izeof(str));
        if (readval <= 0)
        {
            printf("Connection closed\n");
            break;
        }
        str[readval] = '\0';

        // Exit condition
        if (strcmp(str, "Exit") == 0)
        {
            printf("Exit\n");
            break;
        }

        // Convert string to integer
        frame = atoi(str);

        // Simulate frame loss
        randomvalue = rand() % 3;

        if (randomvalue == 0)
        {
            printf("Frame %d lost\n", frame);
            continue;
        }

        // Check expected frame
        if (frame == expectedframe)
        {
            printf("Frame %d received\n", frame);
            ack = frame;
            expectedframe++;
        }
        else
        {
            printf("Frame %d discarded\n", frame);
        }

        // Convert acknowledgment to string
        sprintf(str, "%d", ack);

        // Send acknowledgment
        send(newsockfd,str,strlen(str) + 1,0);

        printf("Acknowledgment sent: %d\n", ack);
    }

    // Close sockets
    close(newsockfd);
    close(sockfd);

    return 0;
}

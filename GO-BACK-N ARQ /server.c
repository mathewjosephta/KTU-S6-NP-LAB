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
    int ack;
    int nextframe = 0;

    int randomvalue;

    // Create TCP socket
    sockfd = socket(AF_INET,
                    SOCK_STREAM,
                    0);

    if (sockfd < 0)
    {
        printf("Socket creation failed\n");
        return 0;
    }

    printf("Socket successfully created\n");

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

    printf("Socket successfully binded\n");

    // Listen for client
    listen(sockfd, 5);

    printf("Server listening\n");

    // Accept client
    newsockfd = accept(sockfd,
                       (struct sockaddr *)&client,
                       (socklen_t *)&clientlen);

    if (newsockfd < 0)
    {
        printf("Accept failed\n");
        return 0;
    }

    printf("Server accepted the client\n");

    // Receive frames continuously
    while (1)
    {
        sleep(1);

        memset(buffer, 0, sizeof(buffer));

        recv(newsockfd,
             buffer,
             sizeof(buffer),
             0);

        // Exit condition
        if (strcmp(buffer, "Exit") == 0)
        {
            printf("Exit\n");
            break;
        }

        frame = atoi(buffer);

        // Discard out-of-order frames
        if (frame != nextframe)
        {
            printf("Frame %d discarded\n",
                   frame);

            printf("Acknowledgement sent: %d\n",
                   ack);

            sprintf(buffer, "%d", ack);

            send(newsockfd,
                 buffer,
                 sizeof(buffer),
                 0);

            continue;
        }

        // Random frame loss simulation
        randomvalue = rand() % 3;

        switch (randomvalue)
        {
            case 0:

                // Frame lost
                break;

            case 1:

            case 2:

                ack = frame;

                printf("Frame %d received\n",
                       frame);

                printf("Acknowledgement sent: %d\n",
                       ack);

                sprintf(buffer, "%d", ack);

                send(newsockfd,
                     buffer,
                     sizeof(buffer),
                     0);

                nextframe = ack + 1;

                break;
        }
    }

    // Close sockets
    close(newsockfd);
    close(sockfd);

    return 0;
}

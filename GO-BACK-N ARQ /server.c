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
    int sockfd;

    struct sockaddr_in server, client;

    socklen_t clientlen = sizeof(client);

    char buffer[100];

    int frame;
    int ack = -1;
    int expectedframe = 0;

    int randomvalue;
    int readval;

    // Create UDP socket
    sockfd = socket(AF_INET,
                    SOCK_DGRAM,
                    0);

    if (sockfd < 0)
    {
        printf("Socket creation failed\n");
        return 0;
    }

    printf("Socket successfully created\n");

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

    printf("Binding successful\n");

    printf("Waiting for frames...\n");

    srand(time(0));

    while (1)
    {
        memset(buffer, 0, sizeof(buffer));

        // Receive frame
        readval = recvfrom(sockfd,
                           buffer,
                           sizeof(buffer),
                           0,
                           (struct sockaddr *)&client,
                           &clientlen);

        buffer[readval] = '\0';

        // Exit condition
        if (strcmp(buffer, "Exit") == 0)
        {
            printf("Exit\n");
            break;
        }

        frame = atoi(buffer);

        // Simulate frame loss
        randomvalue = rand() % 3;

        if (randomvalue == 0)
        {
            printf("Frame %d lost\n",
                   frame);

            continue;
        }

        // Correct frame
        if (frame == expectedframe)
        {
            printf("Frame %d received\n",
                   frame);

            ack = frame;

            expectedframe++;
        }
        else
        {
            printf("Frame %d discarded\n",
                   frame);
        }

        // Send cumulative ACK
        sprintf(buffer,
                "%d",
                ack);

        sendto(sockfd,
               buffer,
               strlen(buffer) + 1,
               0,
               (struct sockaddr *)&client,
               clientlen);

        printf("Acknowledgment sent: %d\n",
               ack);
    }

    close(sockfd);

    return 0;
}

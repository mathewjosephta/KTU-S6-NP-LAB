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
    int lostframe;

    int windowsize = 5;

    int i;
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

    // Random lost frame
    lostframe = rand() % windowsize;

    for (i = 0; i < windowsize; i++)
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

        frame = atoi(buffer);

        // Simulate frame loss
        if (frame == lostframe)
        {
            printf("Frame %d lost\n",
                   frame);

            continue;
        }

        printf("Received frame %d\n",
               frame);

        // Send ACK
        sprintf(buffer,
                "%d",
                frame);

        sendto(sockfd,
               buffer,
               strlen(buffer) + 1,
               0,
               (struct sockaddr *)&client,
               clientlen);

        printf("Acknowledgment sent for frame %d\n",
               frame);
    }

    printf("\nWaiting for retransmitted frames...\n");

    // Receive retransmitted frames
    for (i = lostframe; i < windowsize; i++)
    {
        memset(buffer, 0, sizeof(buffer));

        readval = recvfrom(sockfd,
                           buffer,
                           sizeof(buffer),
                           0,
                           (struct sockaddr *)&client,
                           &clientlen);

        buffer[readval] = '\0';

        frame = atoi(buffer);

        printf("Received retransmitted frame %d\n",
               frame);

        // Send ACK
        sprintf(buffer,
                "%d",
                frame);

        sendto(sockfd,
               buffer,
               strlen(buffer) + 1,
               0,
               (struct sockaddr *)&client,
               clientlen);
    }

    close(sockfd);

    return 0;
}

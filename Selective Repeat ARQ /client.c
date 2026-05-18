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

    struct sockaddr_in server;

    socklen_t serverlen = sizeof(server);

    char buffer[100];

    int windowsize = 5;

    int i;
    int ack;
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

    inet_pton(AF_INET,
              "127.0.0.1",
              &server.sin_addr);

    // Send frames
    printf("Sending frames...\n");

    for (i = 0; i < windowsize; i++)
    {
        sprintf(buffer,
                "%d",
                i);

        sendto(sockfd,
               buffer,
               strlen(buffer) + 1,
               0,
               (struct sockaddr *)&server,
               serverlen);

        printf("Sent frame %d\n",
               i);

        // Receive ACK
        readval = recvfrom(sockfd,
                           buffer,
                           sizeof(buffer),
                           0,
                           NULL,
                           NULL);

        if (readval > 0)
        {
            buffer[readval] = '\0';

            ack = atoi(buffer);

            printf("Received ACK for frame %d\n",
                   ack);
        }
        else
        {
            printf("ACK not received\n");
            break;
        }
    }

    printf("\nResending frames from lost frame...\n");

    // Retransmit remaining frames
    for (; i < windowsize; i++)
    {
        sprintf(buffer,
                "%d",
                i);

        sendto(sockfd,
               buffer,
               strlen(buffer) + 1,
               0,
               (struct sockaddr *)&server,
               serverlen);

        printf("Resent frame %d\n",
               i);

        readval = recvfrom(sockfd,
                           buffer,
                           sizeof(buffer),
                           0,
                           NULL,
                           NULL);

        buffer[readval] = '\0';

        ack = atoi(buffer);

        printf("Received ACK for frame %d\n",
               ack);
    }

    printf("\nAll frames sent successfully\n");

    close(sockfd);

    return 0;
}

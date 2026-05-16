#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <arpa/inet.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <sys/time.h>

int main()
{
    int sockfd;

    struct sockaddr_in server;

    struct timeval timeout;

    char buffer[100];

    int totalframes;
    int windowsize;

    int start = 0;
    int end;
    int frame = 0;

    int ack;
    int readval;

    int i;
    int resendflag = 0;

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

    inet_pton(AF_INET,
              "127.0.0.1",
              &server.sin_addr);

    // Timeout setting
    timeout.tv_sec = 3;
    timeout.tv_usec = 0;

    setsockopt(sockfd,
               SOL_SOCKET,
               SO_RCVTIMEO,
               (const char *)&timeout,
               sizeof(timeout));

    // Connect to server
    if (connect(sockfd,
                (struct sockaddr *)&server,
                sizeof(server)) < 0)
    {
        printf("Connection failed\n");
        return 0;
    }

    printf("Connected to server\n");

    // Input details
    printf("Enter total number of frames: ");
    scanf("%d", &totalframes);

    printf("Enter window size: ");
    scanf("%d", &windowsize);

    end = windowsize - 1;

    // Send initial frames
    for (frame = 0;
         frame < totalframes && frame <= end;
         frame++)
    {
        sprintf(buffer, "%d", frame);

        send(sockfd,
             buffer,
             sizeof(buffer),
             0);

        printf("Frame %d sent\n", frame);
    }

    // Continue communication
    while (1)
    {
        // Send next frame
        if (end - start != windowsize - 1 &&
            resendflag == 0 &&
            frame != totalframes)
        {
            sprintf(buffer, "%d", frame);

            send(sockfd,
                 buffer,
                 sizeof(buffer),
                 0);

            printf("Frame %d sent\n", frame);

            end++;
            frame++;
        }

        resendflag = 0;

        memset(buffer, 0, sizeof(buffer));

        // Receive ACK
        readval = recv(sockfd,
                       buffer,
                       sizeof(buffer),
                       0);

        ack = atoi(buffer);

        // ACK received
        if (readval > 0)
        {
            printf("Acknowledgement received: %d\n",
                   ack);

            if (ack + 1 == totalframes)
            {
                strcpy(buffer, "Exit");

                send(sockfd,
                     buffer,
                     sizeof(buffer),
                     0);

                printf("Exit\n");

                break;
            }

            if (ack == start)
            {
                start++;
            }
        }
        else
        {
            // Timeout occurred
            printf("Acknowledgement not received for %d\n",
                   start);

            printf("Resending frames\n");

            // Resend window frames
            for (i = start;
                 i < totalframes &&
                 i < start + windowsize;
                 i++)
            {
                sprintf(buffer, "%d", i);

                send(sockfd,
                     buffer,
                     sizeof(buffer),
                     0);

                printf("Frame %d sent\n", i);
            }

            resendflag = 1;
        }
    }

    // Close socket
    close(sockfd);

    return 0;
}

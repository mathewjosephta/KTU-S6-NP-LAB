// STOP AND WAIT - CLIENT SIDE

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

    char buffer[100];

    int frame = 0;
    int totalframes;

    int ack;
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

    printf("Socket successfully created\n");

    // Server details
    server.sin_family = AF_INET;
    server.sin_port = htons(8080);

    inet_pton(AF_INET,
              "127.0.0.1",
              &server.sin_addr);

    // Connect to server
    if (connect(sockfd,
                (struct sockaddr *)&server,
                sizeof(server)) < 0)
    {
        printf("Connection failed\n");
        return 0;
    }

    printf("Connected to server\n");

    // Input total frames
    printf("Enter total number of frames: ");
    scanf("%d", &totalframes);

    // Send frames one by one
    while (frame < totalframes)
    {
        // Convert frame number to string
        sprintf(buffer, "%d", frame);

        // Send frame
        send(sockfd,
             buffer,
             sizeof(buffer),
             0);

        printf("Client: Sent frame %d\n",
               frame);

        // Clear buffer
        memset(buffer, 0, sizeof(buffer));

        // Receive acknowledgment
        readval = read(sockfd,
                       buffer,
                       sizeof(buffer));

        if (readval > 0)
        {
            ack = atoi(buffer);

            printf("Client: Received acknowledgment for frame %d\n",
                   ack);

            frame++;
        }
        else
        {
            printf("Acknowledgment not received\n");
        }
    }

    printf("All frames sent successfully\n");

    // Close socket
    close(sockfd);

    return 0;
}

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

    char buffer[1024];

    int frame = 0;
    int totalframes;

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

    inet_pton(AF_INET,
              "127.0.0.1",
              &server.sin_addr);

    // Connect to server
    connect(sockfd,
            (struct sockaddr *)&server,
            sizeof(server));

    // Input total frames
    printf("Enter the total number of frames to send: ");
    scanf("%d", &totalframes);

    // Send frames one by one
    while (frame < totalframes)
    {
        // Convert frame number to string
        sprintf(buffer, "%d", frame);

        // Send frame
        send(sockfd,
             buffer,
             strlen(buffer),
             0);

        printf("Client: Sent frame %d\n", frame);

        // Clear buffer
        memset(buffer, 0, sizeof(buffer));

        // Receive acknowledgment
        readval = read(sockfd,
                       buffer,
                       sizeof(buffer));

        if (readval > 0)
        {
            printf("Client: Received acknowledgment: %s\n",
                   buffer);

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

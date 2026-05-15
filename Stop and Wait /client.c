#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <arpa/inet.h>

#define PORT 8080
#define SIZE 1024

int main()
{
    int sock;

    struct sockaddr_in server;

    char buffer[SIZE];

    int frame = 0;
    int total_frames;

    // Create socket
    sock = socket(AF_INET, SOCK_STREAM, 0);

    if (sock < 0)
    {
        printf("Socket creation failed\n");
        return 0;
    }

    // Server details
    server.sin_family = AF_INET;
    server.sin_port = htons(PORT);

    inet_pton(AF_INET, "127.0.0.1", &server.sin_addr);

    // Connect to server
    connect(sock, (struct sockaddr *)&server, sizeof(server));

    // Input number of frames
    printf("Enter the total number of frames to send: ");
    scanf("%d", &total_frames);

    // Send frames one by one
    while (frame < total_frames)
    {
        // Send frame
        sprintf(buffer, "%d", frame);

        send(sock, buffer, strlen(buffer), 0);

        printf("Client: Sent frame %d\n", frame);

        // Receive acknowledgment
        memset(buffer, 0, SIZE);

        int valread = read(sock, buffer, SIZE);

        if (valread > 0)
        {
            printf("Client: Received acknowledgment: %s\n", buffer);

            frame++;
        }
        else
        {
            printf("Acknowledgment not received\n");
        }
    }

    printf("All frames sent successfully\n");

    close(sock);

    return 0;
}

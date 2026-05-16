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

    int ack;
    int i;

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

    printf("Connected to receiver\n");

    // Send total frames
    sprintf(buffer, "%d", 8);

    write(sockfd,
          buffer,
          sizeof(buffer));

    printf("Frames Sending : ");

    for (i = 0; i < 8; i++)
    {
        printf("%d ", i);
    }

    printf("\n");

    // Receive lost frame ACK
    read(sockfd,
         buffer,
         sizeof(buffer));

    ack = atoi(buffer);

    printf("Frame %d not sent properly\n",
           ack);

    printf("Resending Frame : %d\n",
           ack);

    // Resend lost frame
    sprintf(buffer,
            "%d",
            ack + 1);

    write(sockfd,
          buffer,
          sizeof(buffer));

    // Receive completion message
    read(sockfd,
         buffer,
         sizeof(buffer));

    if (strcmp(buffer, "end") == 0)
    {
        printf("All frames sent successfully\n");
    }

    // Close socket
    close(sockfd);

    return 0;
}

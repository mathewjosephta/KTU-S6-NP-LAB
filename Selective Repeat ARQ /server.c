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
    int lostframe;
    int windowsize = 8;

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

    // Receive total frames
    read(newsockfd,
         buffer,
         sizeof(buffer));

    frame = atoi(buffer);

    // Display frames
    printf("Receiving Frames : ");

    for (i = 0; i < frame; i++)
    {
        printf("%d ", i);
    }

    printf("\n");

    // Random frame loss
    lostframe = rand() % (windowsize - 1);

    // Receive frames except lost frame
    for (i = 0; i < windowsize; i++)
    {
        if (i != lostframe)
        {
            sleep(1);

            printf("Received Frame : %d\n",
                   i);
        }
    }

    printf("Frame %d not received\n",
           lostframe);

    printf("Waiting for Frame %d\n",
           lostframe);

    // Send ACK for missing frame
    sprintf(buffer,
            "%d",
            lostframe);

    write(newsockfd,
          buffer,
          sizeof(buffer));

    // Receive retransmitted frame
    read(newsockfd,
         buffer,
         sizeof(buffer));

    frame = atoi(buffer);

    printf("Received Frame : %d\n",
           frame - 1);

    // Send completion message
    strcpy(buffer, "end");

    write(newsockfd,
          buffer,
          sizeof(buffer));

    // Close sockets
    close(newsockfd);
    close(sockfd);

    return 0;
}

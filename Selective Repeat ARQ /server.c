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
    int sockfd, newsockfd, readval;
    struct sockaddr_in server, client;
    socklen_t clientlen = sizeof(client);
    char str[100];
    int i,frame,lostframe,windowsize = 5,ack[5] = {0};

    // Create TCP socket
    sockfd = socket(AF_INET, SOCK_STREAM, 0);
    if (sockfd < 0)
    {
        printf("Socket creation failed\n");
        return 0;
    }

    // Initialize server structure
    memset(&server, 0, sizeof(server));

    // Server details
    server.sin_family = AF_INET;
    server.sin_port = htons(8080);
    server.sin_addr.s_addr = INADDR_ANY;

    // Bind socket
    if (bind(sockfd,(struct sockaddr *)&server,sizeof(server)) < 0)
    {
        printf("Binding failed\n");
        return 0;
    }

    printf("Binding successful\n");

    // Listen for client
    if (listen(sockfd, 3) < 0)
    {
        printf("Listening failed\n");
        return 0;
    }

    printf("Waiting for connection...\n");

    // Accept client
    newsockfd = accept(sockfd,(struct sockaddr *)&client,&clientlen);

    if (newsockfd < 0)
    {
        printf("Accept failed\n");
        return 0;
    }

    printf("Connection established\n");

    srand(time(0));

    // Random lost frame
    lostframe = rand() % windowsize;

    printf("Frame %d will be lost\n",
           lostframe);

    // Receive frames
    for (i = 0; i < windowsize; i++)
    {
        memset(str, 0, sizeof(str));

        // Receive frame
        readval = read(newsockfd, str,sizeof(str));

        if (readval <= 0)
        {
            printf("Connection closed\n");
            break;
        }

        str[readval] = '\0';

        frame = atoi(str);

        // Simulate frame loss
        if (frame == lostframe &&
            ack[frame] == 0)
        {
            printf("Frame %d lost\n",
                   frame);

            ack[frame] = -1;

            continue;
        }

        printf("Frame %d received\n", frame);

        // Send ACK
        sprintf(str,"%d",frame);

        send(newsockfd,str,strlen(str) + 1,0);

        printf("Acknowledgment sent for frame %d\n",
               frame);

        ack[frame] = 1;
    }

    printf("\nWaiting for retransmitted frame...\n");

    // Receive retransmitted frame
    memset(str, 0, sizeof(str));

    readval = read(newsockfd,str,sizeof(str));

    if (readval > 0)
    {
        str[readval] = '\0';

        frame = atoi(str);

        printf("Retransmitted frame %d received\n",
               frame);

        // Send ACK
        sprintf(str,"%d",frame);

        send(newsockfd,str,strlen(str) + 1,0);
        printf("Acknowledgment sent for frame %d\n",frame);
    }

    // Close sockets
    close(newsockfd);
    close(sockfd);
    return 0;
}

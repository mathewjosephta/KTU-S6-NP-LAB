#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <arpa/inet.h>
#include <sys/socket.h>
#include <netinet/in.h>

int main()
{
    int sockfd, readval;
    struct sockaddr_in server;
    char str[100];
    int i, ack,windowsize = 5;
    int ;
    int ack;

    // Create TCP socket
    sockfd = socket(AF_INET,SOCK_STREAM,0);
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
    inet_pton(AF_INET,"127.0.0.1",&server.sin_addr);

    // Connect to server
    if (connect(sockfd,(struct sockaddr *)&server,sizeof(server)) < 0)
    {
        printf("Connection failed\n");
        return 0;
    }

    printf("Connected to server\n");

    // Send frames
    printf("Sending frames...\n");

    for (i = 0; i < windowsize; i++)
    {
        sprintf(str,"%d",i);
        seid(sockfd,str,strlen(str) + 1,0);
        printf("Sent frame %d\n",i);

        // Receive ACK
        readval = read(sockfd,str,sizeof(str));

        if (readval > 0)
        {
            str[readval] = '\0';
            ack = atoi(str);
            printf("Received ACK for frame %d\n",ack);
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
        sprintf(str,"%d",i);

        send(sockfd,str,strlen(str) + 1,0);

        printf("Resent frame %d\n",i);

        readval = read(sockfd, str, sizeof(str));

        if (readval > 0)
        {
            str[readval] = '\0';

            ack = atoi(str);

            printf("Received ACK for frame %d\n",ack);
        }
    }

    printf("\nAll frames sent successfully\n");

    close(sockfd);

    return 0;
}

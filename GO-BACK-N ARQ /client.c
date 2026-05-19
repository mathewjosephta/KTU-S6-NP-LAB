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
    int sockfd, readval;
    struct sockaddr_in server;
    struct timeval timeout;
    char str[100];
    int totalframes;
    int windowsize,ack,end, start = 0,frame = 0;

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

    // Timeout settings
    timeout.tv_sec = 3;
    timeout.tv_usec = 0;

    setsockopt(sockfd,SOL_SOCKET,SO_RCVTIMEO,(const char *)&timeout,sizeof(timeout));

    // Input details
    printf("Enter total number of frames: ");
    scanf("%d", &totalframes);

    printf("Enter window size: ");
    scanf("%d", &windowsize);

    end = windowsize - 1;

    // Send frames
    while (start < totalframes)
    {
        // Send window frames
        while (frame <= end &&
               frame < totalframes)
        {
            sprintf(str,"%d",frame);

            send(sockfd,str,strlen(str) + 1,0);

            printf("Frame %d sent\n",frame);

            frame++;
        }

        memset(str, 0, sizeof(str));

        // Receive ACK
        readval = read(sockfd,str,sizeof(str));

        // ACK received
        if (readval > 0)
        {
            str[readval] = '\0';
            ack = atoi(str);

            printf("Acknowledgment received: %d\n",
                   ack);

            start = ack + 1;

            end = start + windowsize - 1;
        }
        else
        {
            // Timeout occurred
            printf("Timeout occurred\n");

            printf("Resending frames from %d\n",start);

            frame = start;
        }
    }

    // Exit message
    strcpy(str, "Exit");

    send(sockfd,str,strlen(str) + 1,0);

    printf("All frames sent successfully\n");

    close(sockfd);

    return 0;
}

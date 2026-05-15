#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <arpa/inet.h>
#include <sys/time.h>

#define MAX 80
#define PORT 8080

struct timeval timeout;

void func(int sockfd, int nf, int ws)
{
    char buff[MAX];

    int ack;
    int i = 0;
    int n, k;
    int w1 = 0;
    int w2 = ws - 1;
    int j;
    int flag = 0;

    // Set timeout
    setsockopt(sockfd,
               SOL_SOCKET,
               SO_RCVTIMEO,
               (const char *)&timeout,
               sizeof(timeout));

    // Send initial frames
    for(i = 0; i < nf && i <= w2; i++)
    {
        bzero(buff, sizeof(buff));

        snprintf(buff, sizeof(buff), "%d", i);

        send(sockfd, buff, sizeof(buff), 0);

        printf("Frame %d sent\n", i);
    }

    while(1)
    {
        // Send next frame
        if(w2 - w1 != ws - 1 &&
           flag == 0 &&
           i != nf)
        {
            bzero(buff, sizeof(buff));

            snprintf(buff, sizeof(buff), "%d", i);

            send(sockfd, buff, sizeof(buff), 0);

            printf("Frame %d sent\n", i);

            w2++;

            i++;
        }

        flag = 0;

        bzero(buff, sizeof(buff));

        n = recv(sockfd, buff, MAX, 0);

        ack = atoi(buff);

        // ACK received
        if(n > 0)
        {
            if(ack + 1 == nf)
            {
                printf("Acknowledgement received: %d\n",
                       ack);

                printf("Exit\n");

                bzero(buff, sizeof(buff));

                strcpy(buff, "Exit");

                send(sockfd, buff, sizeof(buff), 0);

                break;
            }

            if(ack == w1)
            {
                w1++;

                printf("Acknowledgement received: %d\n",
                       ack);
            }
        }
        else
        {
            // Timeout occurred
            printf("Acknowledgement not received for %d\n",
                   w1);

            printf("Resending frames\n");

            for(j = w1;
                j < nf && j < w1 + ws;
                j++)
            {
                bzero(buff, sizeof(buff));

                snprintf(buff,
                         sizeof(buff),
                         "%d",
                         j);

                send(sockfd,
                     buff,
                     sizeof(buff),
                     0);

                printf("Frame %d sent\n", j);
            }

            flag = 1;
        }
    }
}

int main()
{
    int sockfd;
    int f, w;

    struct sockaddr_in servaddr;

    // Create socket
    sockfd = socket(AF_INET, SOCK_STREAM, 0);

    if(sockfd == -1)
    {
        printf("Socket creation failed\n");
        return 0;
    }

    printf("Socket successfully created\n");

    // Server details
    bzero(&servaddr, sizeof(servaddr));

    servaddr.sin_family = AF_INET;
    servaddr.sin_addr.s_addr =
        inet_addr("127.0.0.1");

    servaddr.sin_port = htons(PORT);

    // Timeout setting
    timeout.tv_sec = 3;
    timeout.tv_usec = 0;

    // Connect to server
    if(connect(sockfd,
       (struct sockaddr *)&servaddr,
       sizeof(servaddr)) != 0)
    {
        printf("Connection failed\n");
        return 0;
    }

    printf("Connected to the server\n");

    // Input details
    printf("Enter the number of frames: ");
    scanf("%d", &f);

    printf("Enter the window size: ");
    scanf("%d", &w);

    func(sockfd, f, w);

    close(sockfd);

    return 0;
}

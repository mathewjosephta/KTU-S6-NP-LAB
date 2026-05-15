#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <arpa/inet.h>

#define MAX 80
#define PORT 8080

void func(int connfd)
{
    char buff[MAX];

    int f, c, ack, next = 0;

    while(1)
    {
        sleep(1);

        bzero(buff, MAX);

        recv(connfd, buff, MAX, 0);

        // Exit condition
        if(strcmp("Exit", buff) == 0)
        {
            printf("Exit\n");
            break;
        }

        f = atoi(buff);

        // Discard out of order frames
        if(f != next)
        {
            printf("Frame %d discarded\n", f);

            printf("Acknowledgement sent: %d\n", ack);

            bzero(buff, MAX);

            snprintf(buff, sizeof(buff), "%d", ack);

            send(connfd, buff, sizeof(buff), 0);

            continue;
        }

        // Random condition
        c = rand() % 3;

        switch(c)
        {
            case 0:

                // Frame lost
                break;

            case 1:

                ack = f;

                sleep(2);

                printf("Frame %d received\n", f);

                printf("Acknowledgement sent: %d\n", ack);

                bzero(buff, MAX);

                snprintf(buff, sizeof(buff), "%d", ack);

                send(connfd, buff, sizeof(buff), 0);

                next = ack + 1;

                break;

            case 2:

                ack = f;

                printf("Frame %d received\n", f);

                printf("Acknowledgement sent: %d\n", ack);

                bzero(buff, MAX);

                snprintf(buff, sizeof(buff), "%d", ack);

                send(connfd, buff, sizeof(buff), 0);

                next = ack + 1;

                break;
        }
    }
}

int main()
{
    int sockfd, connfd, len;

    struct sockaddr_in servaddr, cli;

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
    servaddr.sin_addr.s_addr = htonl(INADDR_ANY);
    servaddr.sin_port = htons(PORT);

    // Bind socket
    if(bind(sockfd,
       (struct sockaddr *)&servaddr,
       sizeof(servaddr)) != 0)
    {
        printf("Socket bind failed\n");
        return 0;
    }

    printf("Socket successfully binded\n");

    // Listen for client
    if(listen(sockfd, 5) != 0)
    {
        printf("Listen failed\n");
        return 0;
    }

    printf("Server listening\n");

    len = sizeof(cli);

    // Accept connection
    connfd = accept(sockfd,
             (struct sockaddr *)&cli,
             &len);

    if(connfd < 0)
    {
        printf("Server accept failed\n");
        return 0;
    }

    printf("Server accepted the client\n");

    func(connfd);

    close(sockfd);

    return 0;
}

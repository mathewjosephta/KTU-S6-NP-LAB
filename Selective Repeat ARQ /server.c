#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <arpa/inet.h>

void func(int connfd)
{
    char buff[80];

    int f, c, win, ack, k;

    win = 8;

    // Receive initial message
    read(connfd, buff, sizeof(buff));

    if(strcmp("end", buff) == 0)
    {
        printf("Exit\n");
    }

    f = atoi(buff);

    // Display frames
    for(k = 0; k < f; k++)
    {
        printf("%d ", k);
    }

    // Random frame loss
    c = rand() % (win - 1);

    // Receive frames except one lost frame
    for(k = 0; k < win; k++)
    {
        if(k != c)
        {
            sleep(1);

            printf("\nReceived Frame: %d\n", k);
        }
    }

    sleep(c);

    printf("\nFrame %d not received\n", c);

    printf("Waiting for Frame %d\n", c);

    // Send ACK for missing frame
    ack = c;

    snprintf(buff, sizeof(buff), "%d", ack);

    write(connfd, buff, sizeof(buff));

    // Receive retransmitted frame
    read(connfd, buff, sizeof(buff));

    if(strcmp("end", buff) == 0)
    {
        printf("Exit\n");
    }

    f = atoi(buff);

    sleep(1);

    printf("\nReceived Frame %d\n", (f - 1));

    printf("\n");

    strcpy(buff, "end");

    write(connfd, buff, sizeof(buff));
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
    servaddr.sin_family = AF_INET;
    servaddr.sin_addr.s_addr = inet_addr("127.0.0.1");
    servaddr.sin_port = htons(8080);

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

    // Accept client
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

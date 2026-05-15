#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <arpa/inet.h>

void func(int sockfd)
{
    char buff[80];

    int ack, k;

    // Send initial frame number
    snprintf(buff, sizeof(buff), "%d", 8);

    write(sockfd, buff, sizeof(buff));

    // Receive ACK for missing frame
    read(sockfd, buff, sizeof(buff));

    ack = atoi(buff);

    printf("Frames Sending : ");

    for(k = 0; k < 8; k++)
    {
        printf("%d ", k);
    }

    printf("\n");

    printf("Frame %d not sent properly.\n", ack);

    printf("Resending Frame : %d\n", ack);

    // Resend lost frame
    snprintf(buff, sizeof(buff), "%d", ack + 1);

    write(sockfd, buff, sizeof(buff));

    // Receive completion message
    read(sockfd, buff, sizeof(buff));

    if(strcmp("end", buff) == 0)
    {
        printf("All frames sent successfully\n");

        printf("Exit\n");
    }
}

int main()
{
    int sockfd;

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
    servaddr.sin_family = AF_INET;
    servaddr.sin_addr.s_addr = inet_addr("127.0.0.1");
    servaddr.sin_port = htons(8080);

    // Connect to server
    if(connect(sockfd,
       (struct sockaddr *)&servaddr,
       sizeof(servaddr)) != 0)
    {
        printf("Connection with receiver failed\n");
        return 0;
    }

    printf("Connected to the receiver\n");

    func(sockfd);

    close(sockfd);

    return 0;
}

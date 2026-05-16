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

    int serverlen = sizeof(server);

    int a[2][2], b[2][2];
    int flat[100];

    int i, j, k;

    // Create UDP socket
    sockfd = socket(AF_INET, SOCK_DGRAM, 0);

    if (sockfd < 0)
    {
        printf("Socket creation failed\n");
        return 0;
    }

    // Server details
    server.sin_family = AF_INET;
    server.sin_port = htons(8090);

    inet_pton(AF_INET, "127.0.0.1",
              &server.sin_addr);

    // Input first matrix
    printf("Enter elements for 1st matrix:\n");

    for (i = 0; i < 2; i++)
    {
        for (j = 0; j < 2; j++)
        {
            printf("[%d][%d]: ",
                   i + 1, j + 1);

            scanf("%d", &a[i][j]);
        }
    }

    // Convert first matrix to array
    k = 0;

    for (i = 0; i < 2; i++)
    {
        for (j = 0; j < 2; j++)
        {
            flat[k++] = a[i][j];
        }
    }

    // Send first matrix
    sendto(sockfd,
           flat,
           sizeof(flat),
           0,
           (struct sockaddr *)&server,
           serverlen);

    // Input second matrix
    printf("\nEnter elements for 2nd matrix:\n");

    for (i = 0; i < 2; i++)
    {
        for (j = 0; j < 2; j++)
        {
            printf("[%d][%d]: ",
                   i + 1, j + 1);

            scanf("%d", &b[i][j]);
        }
    }

    // Convert second matrix to array
    k = 0;

    for (i = 0; i < 2; i++)
    {
        for (j = 0; j < 2; j++)
        {
            flat[k++] = b[i][j];
        }
    }

    // Send second matrix
    sendto(sockfd,
           flat,
           sizeof(flat),
           0,
           (struct sockaddr *)&server,
           serverlen);

    // Receive result matrix
    recvfrom(sockfd,
             flat,
             sizeof(flat),
             0,
             (struct sockaddr *)&server,
             &serverlen);

    // Display result
    printf("\nResult matrix received from server:\n");

    k = 0;

    for (i = 0; i < 2; i++)
    {
        for (j = 0; j < 2; j++)
        {
            printf("%d\t", flat[k++]);
        }

        printf("\n");
    }

    // Close socket
    close(sockfd);

    return 0;
}

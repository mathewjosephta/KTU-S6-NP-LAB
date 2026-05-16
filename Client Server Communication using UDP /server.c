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

    struct sockaddr_in server, client;

    int clientlen = sizeof(client);

    int a[2][2], b[2][2], result[2][2];
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
    server.sin_addr.s_addr = INADDR_ANY;

    // Bind socket
    if (bind(sockfd,
             (struct sockaddr *)&server,
             sizeof(server)) < 0)
    {
        printf("Binding failed\n");
        return 0;
    }

    printf("Server is waiting...\n");

    // Receive first matrix
    recvfrom(sockfd,
             flat,
             sizeof(flat),
             0,
             (struct sockaddr *)&client,
             &clientlen);

    // Convert array to matrix
    k = 0;

    for (i = 0; i < 2; i++)
    {
        for (j = 0; j < 2; j++)
        {
            a[i][j] = flat[k++];
        }
    }

    // Receive second matrix
    recvfrom(sockfd,
             flat,
             sizeof(flat),
             0,
             (struct sockaddr *)&client,
             &clientlen);

    // Convert array to matrix
    k = 0;

    for (i = 0; i < 2; i++)
    {
        for (j = 0; j < 2; j++)
        {
            b[i][j] = flat[k++];
        }
    }

    // Matrix addition
    printf("\nMatrix Addition Result:\n");

    k = 0;

    for (i = 0; i < 2; i++)
    {
        for (j = 0; j < 2; j++)
        {
            result[i][j] =
                a[i][j] + b[i][j];

            printf("%d\t",
                   result[i][j]);

            flat[k++] =
                result[i][j];
        }

        printf("\n");
    }

    // Send result matrix
    sendto(sockfd,
           flat,
           sizeof(flat),
           0,
           (struct sockaddr *)&client,
           clientlen);

    printf("\nResult sent successfully\n");

    // Close socket
    close(sockfd);

    return 0;
}

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <arpa/inet.h>
#include <sys/socket.h>
#include <netinet/in.h>

int main()
{
    int sockfd, newsockfd, readval, frame;

    struct sockaddr_in server, client;

    socklen_t clientlen = sizeof(client);

    char str[100];

    sockfd = socket(AF_INET, SOCK_STREAM, 0);

    if (sockfd < 0)
    {
        printf("Socket creation failed\n");
        return 0;
    }

    memset(&server, 0, sizeof(server));

    server.sin_family = AF_INET;
    server.sin_port = htons(8080);
    server.sin_addr.s_addr = INADDR_ANY;

    if (bind(sockfd,
             (struct sockaddr *)&server,
             sizeof(server)) < 0)
    {
        printf("Binding failed\n");
        return 0;
    }

    if (listen(sockfd, 3) < 0)
    {
        printf("Listening failed\n");
        return 0;
    }

    printf("Server listening on port 8080\n");

    newsockfd = accept(sockfd,
                       (struct sockaddr *)&client,
                       &clientlen);

    if (newsockfd < 0)
    {
        printf("Accept failed\n");
        return 0;
    }

    printf("Connection established\n");

    while (1)
    {
        memset(str, 0, sizeof(str));

        readval = read(newsockfd,
                       str,
                       sizeof(str));

        if (readval <= 0)
        {
            printf("Connection closed\n");
            break;
        }

        str[readval] = '\0';

        sscanf(str, "%d", &frame);

        printf("Received frame %d\n",
               frame);

        sprintf(str, "%d", frame);

        send(newsockfd,
             str,
             strlen(str) + 1,
             0);

        printf("Acknowledgment sent for frame %d\n",
               frame);
    }

    close(newsockfd);
    close(sockfd);

    return 0;
}

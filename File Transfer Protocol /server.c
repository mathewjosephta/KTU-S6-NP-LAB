#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <arpa/inet.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <fcntl.h>

int main()
{
    int sockfd, newsockfd,readval;
    struct sockaddr_in server, client;
    socklen_t clientlen = sizeof(client);
    char filename[100];
    char filedata[300];
    int f;

    // Create TCP socket
    sockfd = socket(AF_INET, SOCK_STREAM, 0);
    if (sockfd < 0)
    {
        printf("Socket creation failed\n");
        return 0;
    }
    printf("Server socket created\n");

    // Initialize structure
    memset(&server, 0, sizeof(server));

    // Server details
    server.sin_family = AF_INET;
    server.sin_port = htons(8086);
    server.sin_addr.s_addr = INADDR_ANY;

    // Bind socket
    if (bind(sockfd,(struct sockaddr *)&server,sizeof(server)) < 0)
    {
        printf("Bind failed\n");
        return 0;
    }

    printf("Binding successful\n");

    // Listen for client
    if (listen(sockfd, 5) < 0)
    {
        printf("Listen failed\n");
        return 0;
    }

    printf("Listening...\n");

    // Accept client connection
    newsockfd = accept(sockfd,(struct sockaddr *)&client,&clientlen);

    if (newsockfd < 0)
    {
        printf("Accept failed\n");
        return 0;
    }

    printf("Connection successful\n");

    // Receive filename
    readval = read(newsockfd,filename,sizeof(filename));

    if (readval > 0 && readval < sizeof(filename))
    {
        filename[readval] = '\0';
    }

    printf("\nRequested file: %s\n",filename);

    // Open file
    f = open(filename, O_RDONLY);

    if (f < 0)
    {
        strcpy(filedata,"File not found on server");
        send(newsockfd,filedata,strlen(filedata) + 1,0);
    }
    else
    {
        // Read file contents
        readval = read(f,filedata,sizeof(filedata));

        if (readval >= 0 &&readval < sizeof(filedata))
        {
            filedata[readval] = '\0';
        }

        printf("\nFile contents:\n");

        printf("%s\n", filedata);

        // Send file contents
        send(newsockfd,filedata,readval, 0);

        close(f);
    }

    // Close sockets
    close(newsockfd);
    close(sockfd);

    return 0;
}

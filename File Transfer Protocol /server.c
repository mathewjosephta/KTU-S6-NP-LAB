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
    int serversock, newsock;
    int n, f;

    struct sockaddr_in serveraddr, clientaddr;

    socklen_t clientsize = sizeof(clientaddr);

    char filename[100];
    char filedata[300];

    // Create TCP socket
    serversock = socket(AF_INET, SOCK_STREAM, 0);

    if (serversock < 0)
    {
        printf("Socket creation failed\n");
        return 0;
    }

    printf("Server socket created\n");

    // Initialize structure
    memset(&serveraddr, 0, sizeof(serveraddr));

    // Server details
    serveraddr.sin_family = AF_INET;
    serveraddr.sin_port = htons(8086);
    serveraddr.sin_addr.s_addr = INADDR_ANY;

    // Bind socket
    if (bind(serversock,
             (struct sockaddr *)&serveraddr,
             sizeof(serveraddr)) < 0)
    {
        printf("Bind failed\n");
        return 0;
    }

    printf("Binding successful\n");

    // Listen for client
    if (listen(serversock, 5) < 0)
    {
        printf("Listen failed\n");
        return 0;
    }

    printf("Listening...\n");

    // Accept client connection
    newsock = accept(serversock,
                     (struct sockaddr *)&clientaddr,
                     &clientsize);

    if (newsock < 0)
    {
        printf("Accept failed\n");
        return 0;
    }

    printf("Connection successful\n");

    // Receive filename
    n = read(newsock,
             filename,
             sizeof(filename));

    filename[n] = '\0';

    printf("\nRequested file: %s\n", filename);

    // Open file
    f = open(filename, O_RDONLY);

    if (f < 0)
    {
        strcpy(filedata,
               "File not found on server");

        write(newsock,
              filedata,
              strlen(filedata) + 1);
    }
    else
    {
        // Read file contents
        n = read(f,
                 filedata,
                 sizeof(filedata));

        if (n >= 0 && n < sizeof(filedata))
        {
            filedata[n] = '\0';
        }

        printf("\nFile contents:\n");

        printf("%s\n", filedata);

        // Send file contents
        write(newsock,
              filedata,
              strlen(filedata) + 1);

        close(f);
    }

    // Close sockets
    close(newsock);
    close(serversock);

    return 0;
}

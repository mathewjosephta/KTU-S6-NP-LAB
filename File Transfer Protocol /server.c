#include <stdio.h>
#include <unistd.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <fcntl.h>
#include <string.h>
#include <stdlib.h>

int main()
{
    struct sockaddr_in clientaddr, serveraddr;

    int serversock, newserversock;
    int clientsize;
    int n, f;

    char filename[100];
    char filedata[300];

    // Create socket
    serversock = socket(AF_INET, SOCK_STREAM, 0);

    if (serversock < 0)
    {
        printf("Socket creation failed\n");
        return 0;
    }

    printf("Server socket created\n");

    // Clear structure
    bzero((char *)&serveraddr, sizeof(serveraddr));

    // Server details
    serveraddr.sin_family = AF_INET;
    serveraddr.sin_port = htons(8086);
    serveraddr.sin_addr.s_addr = inet_addr("127.0.0.1");

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

    printf("Listen successful\n");

    // Accept connection
    clientsize = sizeof(clientaddr);

    newserversock = accept(serversock,
        (struct sockaddr *)&clientaddr,
        &clientsize);

    if (newserversock < 0)
    {
        printf("Connection failed\n");
        return 0;
    }

    printf("Connection successful\n");

    // Receive filename
    n = read(newserversock,
        filename,
        sizeof(filename));

    filename[n] = '\0';

    printf("\nThe requested file from client is %s\n",
           filename);

    // Open file
    f = open(filename, O_RDWR);

    if (f < 0)
    {
        strcpy(filedata, "File not found on server");

        write(newserversock,
              filedata,
              strlen(filedata));
    }
    else
    {
        // Read file contents
        n = read(f, filedata, sizeof(filedata));

        filedata[n] = '\0';

        printf("\nThe contents of the file:\n");

        printf("%s\n", filedata);

        // Send file contents
        write(newserversock,
              filedata,
              strlen(filedata));

        close(f);
    }

    close(newserversock);
    close(serversock);

    return 0;
}

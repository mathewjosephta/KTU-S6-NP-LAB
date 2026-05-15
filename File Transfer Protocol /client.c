#include <stdio.h>
#include <unistd.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <string.h>
#include <stdlib.h>

int main()
{
    struct sockaddr_in serveraddr;

    int clientsock;
    int n, length;

    char filename[20];
    char filedata[300];

    // Clear structure
    bzero((char *)&serveraddr, sizeof(serveraddr));

    // Server details
    serveraddr.sin_family = AF_INET;
    serveraddr.sin_port = htons(8086);
    serveraddr.sin_addr.s_addr = inet_addr("127.0.0.1");

    // Create socket
    clientsock = socket(AF_INET, SOCK_STREAM, 0);

    if (clientsock < 0)
    {
        printf("Socket creation failed\n");
        return 0;
    }

    // Connect to server
    if (connect(clientsock,
        (struct sockaddr *)&serveraddr,
        sizeof(serveraddr)) < 0)
    {
        printf("Connection failed\n");
        return 0;
    }

    printf("Socket created successfully\n");

    // Enter filename
    printf("Enter the name of the file : ");
    scanf("%s", filename);

    // Send filename
    length = strlen(filename);

    write(clientsock, filename, length);

    // Receive file contents
    n = read(clientsock, filedata, sizeof(filedata));

    filedata[n] = '\0';

    // Display file contents
    printf("\nThe contents of the file:\n");

    printf("%s\n", filedata);

    close(clientsock);

    return 0;
}

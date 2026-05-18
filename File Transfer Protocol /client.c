#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <arpa/inet.h>
#include <sys/socket.h>
#include <netinet/in.h>

int main()
{
    int clientsock;
    int n;

    struct sockaddr_in serveraddr;

    char filename[100];
    char filedata[300];

    // Create TCP socket
    clientsock = socket(AF_INET, SOCK_STREAM, 0);

    if (clientsock < 0)
    {
        printf("Socket creation failed\n");
        return 0;
    }

    // Initialize structure
    memset(&serveraddr, 0, sizeof(serveraddr));

    // Server details
    serveraddr.sin_family = AF_INET;
    serveraddr.sin_port = htons(8086);

    inet_pton(AF_INET,
              "127.0.0.1",
              &serveraddr.sin_addr);

    // Connect to server
    if (connect(clientsock,
                (struct sockaddr *)&serveraddr,
                sizeof(serveraddr)) < 0)
    {
        printf("Connection failed\n");
        return 0;
    }

    printf("Socket connected successfully\n");

    // Enter filename
    printf("Enter filename: ");
    scanf("%s", filename);

    // Send filename
    write(clientsock,
          filename,
          strlen(filename) + 1);

    // Receive file contents
    n = read(clientsock,
             filedata,
             sizeof(filedata));

    if (n >= 0 && n < sizeof(filedata))
    {
        filedata[n] = '\0';
    }

    // Display file contents
    printf("\nFile contents:\n");

    printf("%s\n", filedata);

    // Close socket
    close(clientsock);

    return 0;
}

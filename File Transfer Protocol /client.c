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
    int n;
    struct sockaddr_in server;
    char filename[100];
    char filedata[300];

    // Create TCP socket
    sockfd = socket(AF_INET, SOCK_STREAM, 0);
    if (sockfd < 0)
    {
        printf("Socket creation failed\n");
        return 0;
    }

    // Initialize structure
    memset(&server, 0, sizeof(server));

    // Server details
    server.sin_family = AF_INET;
    server.sin_port = htons(8086);
    inet_pton(AF_INET,"127.0.0.1",&server.sin_addr);

    // Connect to server
    if (connect(sockfd,(struct sockaddr *)&server,sizeof(server)) < 0)
    {
        printf("Connection failed\n");
        return 0;
    }

    printf("Socket connected successfully\n");

    // Enter filename
    printf("Enter filename: ");
    scanf("%s", filename);

    // Send filename
    write(sockfd,filename,strlen(filename) + 1);

    // Receive file contents
    n = read(sockfd,filedata,sizeof(filedata));

    if (n >= 0 && n < sizeof(filedata))
    {
        filedata[n] = '\0';
    }

    // Display file contents
    printf("\nFile contents:\n");
    printf("%s\n", filedata);

    // Close socket
    close(sockfd);

    return 0;
}

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <arpa/inet.h>
#include <sys/socket.h>
#include <netinet/in.h>

int main()
{
    int sockfd,readval;
    struct sockaddr_in server;
    char str[100];

    // Create TCP socket
    sockfd = socket(AF_INET, SOCK_STREAM, 0);
    if (sockfd < 0)
    {
        printf("Socket creation failed\n");
        return 0;
    }

    // Initialize server structure
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

    // Input string
    printf("Enter string: ");
    scanf("%s", str);

    // Send string to server
    send(sockfd,str,strlen(str) + 1,0);

    // Receive reversed string
    readval = read(sockfd,str,sizeof(str));

    str[readval] = '\0';

    // Display result
    printf("Server says: %s\n", str);

    // Close socket
    close(sockfd);

    return 0;
}

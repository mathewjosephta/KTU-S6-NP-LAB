#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <arpa/inet.h>

#define PORT 8080
#define SIZE 1024

int main()
{
    int server_fd, new_socket;
    struct sockaddr_in address;

    int addrlen = sizeof(address);

    char buffer[SIZE];

    int frame;

    // Create socket
    server_fd = socket(AF_INET, SOCK_STREAM, 0);

    if (server_fd < 0)
    {
        printf("Socket creation failed\n");
        return 0;
    }

    // Server details
    address.sin_family = AF_INET;
    address.sin_port = htons(PORT);
    address.sin_addr.s_addr = INADDR_ANY;

    // Bind socket
    bind(server_fd, (struct sockaddr *)&address, sizeof(address));

    // Listen for connection
    listen(server_fd, 3);

    printf("Server is listening on port %d\n", PORT);

    // Accept client
    new_socket = accept(server_fd,
                        (struct sockaddr *)&address,
                        (socklen_t *)&addrlen);

    printf("Connection established with client\n");

    // Receive frames
    while (1)
    {
        memset(buffer, 0, SIZE);

        int valread = read(new_socket, buffer, SIZE);

        if (valread <= 0)
        {
            printf("Connection closed by client\n");
            break;
        }

        sscanf(buffer, "%d", &frame);

        printf("Server: Received frame %d\n", frame);

        // Send acknowledgment
        sprintf(buffer, "ACK for frame %d", frame);

        send(new_socket, buffer, strlen(buffer), 0);

        printf("Server: Sent acknowledgment for frame %d\n", frame);
    }

    close(new_socket);
    close(server_fd);

    return 0;
}

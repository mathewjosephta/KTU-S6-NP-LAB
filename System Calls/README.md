SYSTEM CALLS USED FOR OPERATING SYSTEM AND NETWORK PROGRAMMING IN LINUX

--------------------------------------------------

AIM

To familiarize and understand the use and functioning
of system calls used for operating system and network
programming in Linux.

--------------------------------------------------

1. socket()

Easy Idea:

socket() creates a communication endpoint between
client and server.

Without socket, communication cannot happen.

Syntax:

socket(AF_INET, SOCK_STREAM, 0);

Meaning:
- AF_INET  -> IPv4
- SOCK_STREAM -> TCP
- 0 -> Default protocol

Example:

sockfd = socket(AF_INET, SOCK_STREAM, 0);

Like creating a phone before making a call.

--------------------------------------------------

2. bind()

Easy Idea:

bind() connects the socket with:
- IP address
- Port number

Syntax:

bind(sockfd, (struct sockaddr *)&server, sizeof(server));

Example:

bind(sockfd, (struct sockaddr *)&server, sizeof(server));

Like assigning a phone number to your phone.

--------------------------------------------------

3. connect()

Easy Idea:

connect() is used by client to connect to server.

Syntax:

connect(sockfd, (struct sockaddr *)&server, sizeof(server));

Example:

connect(sockfd, (struct sockaddr *)&server, sizeof(server));

Like calling another person using their phone number.

--------------------------------------------------

4. listen()

Easy Idea:

listen() makes server wait for client connections.

Syntax:

listen(sockfd, 5);

Example:

listen(sockfd, 5);

Like waiting for incoming phone calls.

--------------------------------------------------

5. accept()

Easy Idea:

accept() accepts the connection request from client.

Syntax:

accept(sockfd, (struct sockaddr *)&client, &len);

Example:

newsock = accept(sockfd,
                 (struct sockaddr *)&client,
                 &len);

Like answering an incoming phone call.

--------------------------------------------------

6. read() and write()

Easy Idea:

read() receives data.

write() sends data.

Syntax:

read(fd, buffer, sizeof(buffer));

write(fd, buffer, sizeof(buffer));

Example:

read(sockfd, buffer, sizeof(buffer));

write(sockfd, buffer, sizeof(buffer));

Like reading and sending messages.

--------------------------------------------------

7. sendto() and recvfrom()

Easy Idea:

Used mainly in UDP communication.

sendto() sends data.

recvfrom() receives data.

Syntax:

sendto(sockfd, buffer, sizeof(buffer), 0,
       (struct sockaddr *)&server, len);

recvfrom(sockfd, buffer, sizeof(buffer), 0,
         (struct sockaddr *)&server, &len);

Example:

sendto(sockfd, msg, sizeof(msg), 0,
       (struct sockaddr *)&server, len);

Like sending letters without establishing a call.

--------------------------------------------------

8. close()

Easy Idea:

close() closes the socket or file.

Syntax:

close(sockfd);

Example:

close(sockfd);

Like hanging up the phone after conversation.

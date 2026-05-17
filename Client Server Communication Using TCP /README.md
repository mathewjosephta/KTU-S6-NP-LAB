# TCP Client Server Communication Using Socket Programming in C

## Aim

To implement client server communication using socket programming and TCP as transport layer protocol in C.

---

# Main Definitions

## Socket Programming

Socket programming is a method used for communication between two systems over a network.

A socket acts as an endpoint for communication.

Uses:
- Client server communication
- Data transfer over network
- Inter process communication

---

## TCP

TCP stands for Transmission Control Protocol.

TCP is:
- Reliable
- Connection oriented
- Error checking supported
- Ordered data delivery

TCP ensures data reaches correctly without loss.

---

## Client

A client is the program that:
- Requests connection
- Sends data to server
- Receives response from server

In this program:
The client sends a string.

---

## Server

A server is the program that:
- Waits for client connections
- Receives data
- Processes data
- Sends response back

In this program:
The server reverses the string.

---

## Port Number

A port number identifies a specific application running on a system.

This program uses:

```text
8086
```

---

## Localhost

127.0.0.1 is called:
- Localhost
- Loopback Address

It means the client and server are running on the same computer.

---

# How the Program Works

1. Server creates socket
2. Server binds socket with port
3. Server listens for client
4. Client connects to server
5. Client sends string
6. Server reverses string
7. Server sends reversed string back
8. Client displays output

---

# Algorithm

# CLIENT ALGORITHM

START

## Step 1
Create socket

```c
socket(AF_INET, SOCK_STREAM, 0);
```

## Step 2
Specify server IP address and port

```c
server.sin_family = AF_INET;
server.sin_port = htons(8086);
```

## Step 3
Convert IP address

```c
inet_pton(AF_INET, "127.0.0.1", &server.sin_addr);
```

## Step 4
Connect to server

```c
connect(sockfd, (struct sockaddr *)&server, sizeof(server));
```

## Step 5
Read string from user

```c
scanf("%s", str);
```

## Step 6
Send string to server

```c
send(sockfd, str, sizeof(str), 0);
```

## Step 7
Receive reversed string

```c
read(sockfd, str, sizeof(str));
```

## Step 8
Display reversed string

```c
printf("%s", str);
```

## Step 9
Close socket

```c
close(sockfd);
```

STOP

---

# SERVER ALGORITHM

START

## Step 1
Create socket

```c
socket(AF_INET, SOCK_STREAM, 0);
```

## Step 2
Specify server IP address and port

```c
server.sin_family = AF_INET;
server.sin_port = htons(8086);
server.sin_addr.s_addr = INADDR_ANY;
```

## Step 3
Bind socket with IP and port

```c
bind(sockfd, (struct sockaddr *)&server, sizeof(server));
```

## Step 4
Listen for client connection

```c
listen(sockfd, 3);
```

## Step 5
Accept client connection

```c
accept(sockfd, (struct sockaddr *)&client, &clientlen);
```

## Step 6
Receive string from client

```c
read(newsockfd, str, sizeof(str));
```

## Step 7
Find string length

```c
strlen(str);
```

## Step 8
Reverse the string

```c
str[i] = str[j];
```

## Step 9
Send reversed string

```c
send(newsockfd, str, sizeof(str), 0);
```

## Step 10
Close sockets

```c
close(newsockfd);
close(sockfd);
```

STOP
---

# Important Socket Functions

| Function | Purpose |
|---|---|
| socket() | Creates socket |
| bind() | Binds socket with IP and port |
| listen() | Waits for client connection |
| accept() | Accepts client request |
| connect() | Connects client to server |
| send() | Sends data |
| recv() | Receives data |
| close() | Closes socket |

---

# Sample Output

## Server Side

```text
Bind created
Listening....
New socket created
```

---

## Client Side

```text
Enter the string: hello

Reversed string from server: olleh
```

---

# Advantages

- Reliable communication
- Error checking supported
- Ordered data transfer
- Easy implementation

---

# Disadvantages

- Slower than UDP
- More overhead due to reliability checks

---

# Applications

- Chat applications
- File transfer
- Client server communication
- Web applications

---

# Viva Questions and Answers

## 1. What is Socket Programming?

Socket programming is a method used for communication between client and server over a network using sockets.

---

## 2. Why is TCP used in this program?

TCP is used because it provides reliable and connection oriented communication.

---

## 3. Difference between TCP and UDP?

### TCP
- Reliable
- Connection oriented
- Slower

### UDP
- Faster
- Connectionless
- No guarantee of delivery

---

## 4. What is a socket?

A socket is an endpoint used for sending and receiving data between systems.

---

## 5. What does bind() do?

bind() connects the socket with an IP address and port number.

---

## 6. Why is listen() used?

listen() waits for incoming client connections.

---

## 7. What does accept() do?

accept() accepts the connection request from the client.

---

## 8. What is localhost?

localhost means the same computer.

IP Address:

```text
127.0.0.1
```

---

## 9. What is the role of server in this program?

The server receives the string, reverses it, and sends it back to the client.

---

## 10. What is the role of client?

The client sends the string to the server and displays the reversed string received from the server.

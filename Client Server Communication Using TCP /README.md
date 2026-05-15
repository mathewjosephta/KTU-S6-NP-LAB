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

### START

### Step 1
Create socket

```c
socket(AF_INET, SOCK_STREAM, 0);
```

### Step 2
Bind socket with IP and port

```c
bind(socdef, (struct sockaddr *)&addr, sizeof(addr));
```

### Step 3
Listen for client connection

```c
listen(socdef, 3);
```

### Step 4
Accept client connection

```c
accept(socdef, (struct sockaddr *)&addr, &addrlen);
```

### Step 5
Client sends string

```c
send(socdef, str, sizeof(str), 0);
```

### Step 6
Server receives string

```c
read(newsock, str, sizeof(str));
```

### Step 7
Reverse the string

```c
str[i] = str[j];
```

### Step 8
Server sends reversed string

```c
send(newsock, str, sizeof(str), 0);
```

### Step 9
Client receives reversed string

```c
read(socdef, str, sizeof(str));
```

### STOP

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

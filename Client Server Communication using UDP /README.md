# IMPLEMENTATION OF CLIENT SERVER COMMUNICATION USING SOCKET PROGRAMMING AND UDP AS TRANSPORT LAYER PROTOCOL

## Aim

To implement client server communication using socket programming and UDP as transport layer protocol in C.

---

# Main Definitions

## Socket Programming

Socket programming is a method used for communication between two systems over a network.

A socket acts as an endpoint for communication.

Uses:
- Client server communication
- Data transfer over network
- Process communication

---

## UDP

UDP stands for User Datagram Protocol.

UDP is:
- Connectionless
- Faster communication protocol
- Less overhead
- No guarantee of delivery
- No error recovery

UDP is faster than TCP because it does not check whether packets are delivered correctly.

---

## Client

A client is the program that:
- Sends requests to server
- Sends data
- Receives result from server

In this program:
The client sends two matrices.

---

## Server

A server is the program that:
- Waits for data from client
- Processes data
- Sends response back

In this program:
The server performs matrix addition.

---

## Port Number

A port number identifies a specific application running on a system.

This program uses:

```text
8090
```

---

## Localhost

127.0.0.1 is called:
- Localhost
- Loopback Address

It means client and server are running on the same computer.

---

# How the Program Works

1. Server creates UDP socket
2. Server binds socket with port
3. Client creates UDP socket
4. Client enters first matrix
5. Client sends first matrix
6. Client enters second matrix
7. Client sends second matrix
8. Server receives matrices
9. Server performs matrix addition
10. Server sends result matrix
11. Client displays result

---

# Algorithm

### START

### Step 1
Create UDP socket

```c
socket(AF_INET, SOCK_DGRAM, IPPROTO_UDP);
```

### Step 2
Bind socket with IP and port

```c
bind(sockdef, (struct sockaddr *)&server, sizeof(server));
```

### Step 3
Client enters first matrix

```c
scanf("%d", &a[i][j]);
```

### Step 4
Send first matrix to server

```c
sendto(sockdef, flat, sizeof(flat), 0,
(struct sockaddr *)&server, clientlen);
```

### Step 5
Client enters second matrix

```c
scanf("%d", &b[i][j]);
```

### Step 6
Send second matrix to server

```c
sendto(sockdef, flat, sizeof(flat), 0,
(struct sockaddr *)&server, clientlen);
```

### Step 7
Server receives matrices

```c
recvfrom(sockdef, flat, sizeof(flat), 0,
(struct sockaddr *)&client, &clientlen);
```

### Step 8
Perform matrix addition

```c
result[i][j] = a[i][j] + b[i][j];
```

### Step 9
Send result matrix to client

```c
sendto(sockdef, flat, sizeof(flat), 0,
(struct sockaddr *)&client, clientlen);
```

### Step 10
Client receives result matrix

```c
recvfrom(sockdef, flat, sizeof(flat), 0,
(struct sockaddr *)&server, &clientlen);
```

### STOP

---

# Important Socket Functions

| Function | Purpose |
|---|---|
| socket() | Creates socket |
| bind() | Binds socket with IP and port |
| sendto() | Sends data using UDP |
| recvfrom() | Receives data using UDP |
| close() | Closes socket |

---

# Difference Between TCP and UDP

| TCP | UDP |
|---|---|
| Reliable | Unreliable |
| Connection oriented | Connectionless |
| Slower | Faster |
| Error checking available | No error recovery |
| Ordered delivery | No order guarantee |

---

# Matrix Addition Example

## First Matrix

```text
1   2
3   4
```

## Second Matrix

```text
5   6
7   8
```

## Result Matrix

```text
6   8
10  12
```

---

# Sample Output

## Server Side

```text
Matrix Addition Result (Server Side):

6   8
10  12

Result sent to client successfully.
```

---

## Client Side

```text
Enter elements for 1st matrix:

[1][1]: 1
[1][2]: 2
[2][1]: 3
[2][2]: 4

Enter elements for 2nd matrix:

[1][1]: 5
[1][2]: 6
[2][1]: 7
[2][2]: 8

Result matrix received from server:

6   8
10  12
```

---

# Advantages

- Faster communication
- Simple implementation
- Less overhead

---

# Disadvantages

- No guarantee of delivery
- No error checking
- Unreliable communication

---

# Applications

- Live streaming
- Online games
- Video conferencing
- DNS services

---

# Viva Questions and Answers

## 1. What is UDP?

UDP stands for User Datagram Protocol.

It is a connectionless and faster communication protocol.

---

## 2. Why is UDP used in this program?

UDP is used because it provides faster communication with less overhead.

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

## 4. What is socket programming?

Socket programming is a method used for communication between systems over a network.

---

## 5. What is the use of sendto()?

sendto() is used to send data using UDP protocol.

---

## 6. What is the use of recvfrom()?

recvfrom() is used to receive data using UDP protocol.

---

## 7. Why is bind() used?

bind() connects the socket with an IP address and port number.

---

## 8. What is localhost?

localhost means the same computer.

Its IP address is:

```text
127.0.0.1
```

---

## 9. What operation is performed in this program?

Matrix addition is performed on the server side.

---

## 10. What is the role of server in this program?

The server receives matrices, performs addition, and sends the result back to the client.

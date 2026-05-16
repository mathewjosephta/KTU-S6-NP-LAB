# IMPLEMENTATION OF CLIENT SERVER COMMUNICATION USING SOCKET PROGRAMMING AND UDP AS TRANSPORT LAYER PROTOCOL

## Aim

To implement client server communication using socket programming and UDP as transport layer protocol in C for checking whether a string is palindrome or not.

---

# Main Definitions

## Socket Programming

Socket programming is a method used for communication between two systems over a network.

A socket acts as an endpoint for communication.

Uses:

* Client server communication
* Data transfer over network
* Process communication

---

## UDP

UDP stands for User Datagram Protocol.

UDP is:

* Connectionless
* Faster communication protocol
* Less overhead
* No guarantee of delivery
* No error recovery

UDP is faster than TCP because it does not check whether packets are delivered correctly.

---

## Client

A client is the program that:

* Sends requests to server
* Sends data
* Receives result from server

In this program:
The client sends a string to the server.

---

## Server

A server is the program that:

* Waits for data from client
* Processes data
* Sends response back

In this program:
The server checks whether the string is palindrome or not.

---

## Palindrome

A palindrome is a word or string that reads the same forward and backward.

Examples:

```text
madam
malayalam
level
```

Non palindrome examples:

```text
hello
apple
```

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

* Localhost
* Loopback Address

It means client and server are running on the same computer.

---

# How the Program Works

1. Server creates UDP socket
2. Server binds socket with port
3. Client creates UDP socket
4. Client enters string
5. Client sends string to server
6. Server receives string
7. Server checks whether string is palindrome
8. Server sends result back to client
9. Client displays result

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
bind(sockfd, (struct sockaddr *)&server, sizeof(server));
```

### Step 3

Client enters string

```c
scanf("%s", str);
```

### Step 4

Send string to server

```c
sendto(sockfd, str, sizeof(str), 0,
(struct sockaddr *)&server, len);
```

### Step 5

Server receives string

```c
recvfrom(sockfd, str, sizeof(str), 0,
(struct sockaddr *)&client, &len);
```

### Step 6

Check palindrome

```c
if(str[i] != str[j])
```

### Step 7

Send result to client

```c
sendto(sockfd, result, sizeof(result), 0,
(struct sockaddr *)&client, len);
```

### Step 8

Client receives result

```c
recvfrom(sockfd, result, sizeof(result), 0,
(struct sockaddr *)&server, &len);
```

### STOP

---

# Important Socket Functions

| Function   | Purpose                       |
| ---------- | ----------------------------- |
| socket()   | Creates socket                |
| bind()     | Binds socket with IP and port |
| sendto()   | Sends data using UDP          |
| recvfrom() | Receives data using UDP       |
| close()    | Closes socket                 |

---

# Difference Between TCP and UDP

| TCP                      | UDP                |
| ------------------------ | ------------------ |
| Reliable                 | Unreliable         |
| Connection oriented      | Connectionless     |
| Slower                   | Faster             |
| Error checking available | No error recovery  |
| Ordered delivery         | No order guarantee |

---

# Palindrome Example

## Input

```text
madam
```

## Reverse

```text
madam
```

## Result

```text
Palindrome
```

---

# Non Palindrome Example

## Input

```text
hello
```

## Reverse

```text
olleh
```

## Result

```text
Not Palindrome
```

---

# Sample Output

## Server Side

```text
Server waiting...

Received string: madam
```

---

## Client Side

```text
Enter string: madam

Server says: Palindrome
```

---

# Advantages

* Faster communication
* Simple implementation
* Less overhead

---

# Disadvantages

* No guarantee of delivery
* No error checking
* Unreliable communication

---

# Applications

* Chat applications
* Online games
* DNS services
* Simple client server communication

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

* Reliable
* Connection oriented
* Slower

### UDP

* Faster
* Connectionless
* No guarantee of delivery

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

Palindrome checking is performed on the server side.

---

## 10. What is the role of server in this program?

The server receives the string, checks whether it is palindrome or not, and sends the result back to the client.

---

# Result

Thus the client server communication using socket programming and UDP as transport layer protocol was implemented successfully and the palindrome of a string was checked.

# TCP Client Server Communication Using Socket Programming in C

## What is this Program?

This program demonstrates communication between a client and a server using TCP socket programming.

- The client sends a string to the server.
- The server reverses the string.
- The reversed string is sent back to the client.

### Example

Input:
hello

Output:
olleh

---

# What is Socket Programming?

Socket programming is a way for two systems or processes to communicate over a network.

A socket acts as an endpoint for communication.

It is mainly used for:
- Client server communication
- Data transfer over network
- Inter process communication

---

# What is TCP?

TCP stands for Transmission Control Protocol.

It is a reliable communication protocol.

## Features of TCP

- Connection oriented
- Reliable communication
- Ordered data transfer
- Error checking

TCP ensures that data reaches correctly without loss.

---

# What is a Client?

A client is the program that:
- Requests connection
- Sends data to server
- Receives response from server

In this program:
The client sends a string.

---

# What is a Server?

A server is the program that:
- Waits for client connections
- Receives data
- Processes data
- Sends response back

In this program:
The server reverses the string.

---

# What is a Port Number?

A port number identifies a specific application running on a system.

This program uses:

8086

---

# What is 127.0.0.1 ?

127.0.0.1 is called:
- Localhost
- Loopback Address

It means the client and server are running on the same computer.

---

# Important Socket Functions

| Function | Purpose |
|----------|----------|
| socket() | Creates socket |
| bind() | Binds socket with IP and port |
| listen() | Waits for client connection |
| accept() | Accepts client request |
| connect() | Connects client to server |
| send() | Sends data |
| recv() | Receives data |
| close() | Closes socket |

---

# Program Flow

1. Server creates socket
2. Server binds socket with port
3. Server listens for client
4. Client connects to server
5. Client sends string
6. Server reverses string
7. Server sends reversed string back
8. Client displays output

---

# Sample Output

## Server Side

Bind created  
Listening....  
New socket created  

---

## Client Side

Enter the string: hello  
Reversed string from server: olleh  

---

# Important Viva Questions and Answers

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
127.0.0.1

---

## 9. What is the role of server in this program?

The server receives the string, reverses it, and sends it back to the client.

---

## 10. What is the role of client?

The client sends the string to the server and displays the reversed string received from the server.

# IMPLEMENTATION OF FILE TRANSFER PROTOCOL

## Aim

To implement File Transfer Protocol using socket programming and TCP in C.

---

# Main Definitions

## File Transfer Protocol

File Transfer Protocol (FTP) is used to transfer files between client and server through a network.

In this program:
- Client requests a file
- Server reads the file
- Server sends file contents to client

---

## Socket Programming

Socket programming is a method used for communication between two systems over a network.

A socket acts as an endpoint for communication.

Uses:
- Client server communication
- File transfer
- Data communication

---

## TCP

TCP stands for Transmission Control Protocol.

TCP is:
- Reliable
- Connection oriented
- Ordered data delivery
- Error checking supported

TCP ensures correct file transfer without data loss.

---

## Client

A client is the program that:
- Requests connection
- Sends file name to server
- Receives file contents

---

## Server

A server is the program that:
- Waits for client connection
- Receives requested filename
- Opens the file
- Sends file contents back

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

It means client and server are running on the same computer.

---

# How the Program Works

1. Server creates socket
2. Server binds socket with port
3. Server waits for client connection
4. Client creates socket
5. Client connects to server
6. Client sends filename
7. Server receives filename
8. Server opens file
9. Server reads file contents
10. Server sends file contents
11. Client receives and displays file contents

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
bind(serversock,
(struct sockaddr *)&serveraddr,
sizeof(serveraddr));
```

### Step 3
Listen for client connection

```c
listen(serversock, 5);
```

### Step 4
Accept client connection

```c
accept(serversock,
(struct sockaddr *)&clientaddr,
&clientsize);
```

### Step 5
Client sends filename

```c
write(clientsock, filename, length);
```

### Step 6
Server receives filename

```c
read(newserversock,
filename,
sizeof(filename));
```

### Step 7
Open requested file

```c
open(filename, O_RDWR);
```

### Step 8
Read file contents

```c
read(f, filedata, sizeof(filedata));
```

### Step 9
Send file contents to client

```c
write(newserversock,
filedata,
strlen(filedata));
```

### Step 10
Client receives file contents

```c
read(clientsock,
filedata,
300);
```

### STOP

---

# Important Functions Used

| Function | Purpose |
|---|---|
| socket() | Creates socket |
| bind() | Binds socket with IP and port |
| listen() | Waits for client connection |
| accept() | Accepts client request |
| connect() | Connects client to server |
| write() | Sends data |
| read() | Receives data |
| open() | Opens file |
| close() | Closes socket |

---

# Sample File

## sample.txt

```text
Welcome to the File Transfer Protocol Experiment!
This is a test file.
```

---

# Sample Output

## Server Side

```text
Server socket created.
Binding successful.
Listen successful.
Connection successful.

The requested file from the client is sample.txt.

The contents of the file:

Welcome to the File Transfer Protocol Experiment!
This is a test file.
```

---

## Client Side

```text
Socket created successfully.

Enter the name of the file : sample.txt

The contents of the file:

Welcome to the File Transfer Protocol Experiment!
This is a test file.
```

---

# Advantages

- Reliable file transfer
- Simple implementation
- Ordered data transmission
- Error checking supported

---

# Disadvantages

- Slower compared to UDP
- More overhead
- Suitable mainly for small file transfer systems

---

# Applications

- File sharing systems
- Client server applications
- Remote file access
- Network file transfer

---

# Viva Questions and Answers

## 1. What is File Transfer Protocol?

File Transfer Protocol is used to transfer files between client and server through a network.

---

## 2. Which protocol is used in this program?

TCP protocol is used.

---

## 3. Why is TCP used?

TCP provides reliable and ordered file transfer.

---

## 4. What is socket programming?

Socket programming is a method used for communication between systems over a network.

---

## 5. What is the use of open()?

open() is used to open the requested file.

---

## 6. What is the use of read()?

read() is used to receive data or read file contents.

---

## 7. What is the use of write()?

write() is used to send data.

---

## 8. What happens if file is not found?

Server sends the message:

```text
File not found on server.
```

---

## 9. What is localhost?

localhost means the same computer.

IP Address:

```text
127.0.0.1
```

---

## 10. What is the role of server in this program?

The server receives filename, reads file contents, and sends them back to the client.

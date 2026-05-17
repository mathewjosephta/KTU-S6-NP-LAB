# SIMULATION OF SLIDING WINDOW PROTOCOLS  
# STOP AND WAIT PROTOCOL

---

# Aim

To simulate Stop and Wait Protocol using socket programming in C.

---

# Main Definitions

## Stop and Wait Protocol

Stop and Wait Protocol is a flow control protocol used in computer networks.

In this protocol:

- Sender sends one frame
- Sender waits for acknowledgment
- Receiver sends acknowledgment
- Sender sends next frame only after receiving ACK

---

## Flow Control

Flow control controls the speed of data transmission between sender and receiver.

It prevents sender from sending data faster than receiver can process.

---

## Frame

A frame is a unit of data transmitted through network.

In this program:
Frame numbers are sent from client to server.

## Example

```text
0 1 2 3
```

---

# Acknowledgment (ACK)

ACK is a message sent by receiver to sender.

It confirms successful reception of frame.

In this program:  
Server sends frame number as acknowledgment.

## Example

```text
0
1
2
```

---

# Socket Programming

Socket programming is a method used for communication between two systems over a network.

Socket acts as endpoint for communication.

---

# TCP

TCP stands for:

Transmission Control Protocol

TCP is:
- Reliable
- Connection oriented
- Ordered
- Error checked

TCP ensures data reaches correctly.

---

# How the Program Works

1. Server creates TCP socket
2. Server binds socket with port number
3. Server waits for client connection
4. Client connects to server
5. Client sends one frame
6. Server receives frame
7. Server sends acknowledgment
8. Client waits for ACK
9. Next frame is sent
10. Process repeats until all frames are sent

---

# SERVER SIDE ALGORITHM

START

1. Create socket

```c
sockfd = socket(AF_INET, SOCK_STREAM, 0);
```

2. Bind socket with IP address and port number

```c
bind(sockfd,
     (struct sockaddr *)&server,
     sizeof(server));
```

3. Listen for client connection

```c
listen(sockfd, 3);
```

4. Accept client connection

```c
newsockfd = accept(sockfd,
                   (struct sockaddr *)&client,
                   &clientlen);
```

5. Repeat continuously

```c
while(1)
```

6. Server receives frame

```c
read(newsockfd,
     buffer,
     sizeof(buffer));
```

7. Check whether client disconnected

```c
if(readval <= 0)
```

8. Convert received string into integer frame number

```c
sscanf(buffer, "%d", &frame);
```

9. Display received frame

```c
printf("Received Frame %d", frame);
```

10. Server sends acknowledgment

```c
send(newsockfd,
     buffer,
     sizeof(buffer),
     0);
```

11. Repeat until client disconnects

```c
while(1)
```

12. Close sockets

```c
close(newsockfd);
close(sockfd);
```

STOP

# CLIENT SIDE ALGORITHM

START

1. Create socket

```c
sockfd = socket(AF_INET, SOCK_STREAM, 0);
```

2. Connect client to server

```c
connect(sockfd,
        (struct sockaddr *)&server,
        sizeof(server));
```

3. Read total number of frames

```c
scanf("%d", &totalframes);
```

4. Initialize frame number

```c
frame = 0;
```

5. Repeat until all frames are sent

```c
while(frame < totalframes)
```

6. Convert frame number into string

```c
sprintf(buffer, "%d", frame);
```

7. Client sends frame

```c
send(sockfd,
     buffer,
     sizeof(buffer),
     0);
```

8. Display sent frame

```c
printf("Sent Frame %d", frame);
```

9. Client waits for acknowledgment

```c
read(sockfd,
     buffer,
     sizeof(buffer));
```

10. Convert acknowledgment into integer

```c
ack = atoi(buffer);
```

11. Display acknowledgment

```c
printf("ACK Received %d", ack);
```

12. Increment frame number

```c
frame++;
```

13. Repeat until all frames are transmitted successfully

```c
while(frame < totalframes)
```

14. Close socket

```c
close(sockfd);
```

STOP

---

# Important Functions Used

| Function | Purpose |
|---|---|
| socket() | Creates socket |
| bind() | Binds socket with IP and port |
| listen() | Waits for client |
| accept() | Accepts client connection |
| connect() | Connects client to server |
| send() | Sends data |
| read() | Receives data |
| close() | Closes socket |

# Viva Questions and Answers

## 1. What is Stop and Wait Protocol?

Stop and Wait Protocol is a flow control protocol where sender sends one frame and waits for acknowledgment before sending next frame.

---

## 2. What is acknowledgment (ACK)?

ACK is a message sent by receiver to confirm successful reception of frame.

---

## 3. Why is ACK important?

ACK helps sender know whether frame reached receiver correctly.

---

## 4. What happens if ACK is not received?

Sender retransmits the frame.

---

## 5. What is flow control?

Flow control controls the speed of data transmission between sender and receiver.

---

## 6. What is a frame?

A frame is a unit of data transmitted through network.

---

## 7. Which protocol is used in this program?

TCP protocol is used.

---

## 8. Why is TCP used?

TCP provides:
- Reliable communication
- Ordered delivery
- Error checking

---

## 9. What is socket programming?

Socket programming is communication between systems using sockets.

---

## 10. What is a socket?

A socket is an endpoint used for sending and receiving data.

---

## 11. What is the role of sender?

Sender sends frames and waits for acknowledgment.

---

## 12. What is the role of receiver?

Receiver receives frames and sends acknowledgment.

---

## 13. What is the disadvantage of Stop and Wait Protocol?

It is slow because sender waits after every frame.

---

## 14. What is the advantage of Stop and Wait Protocol?

It is simple and reliable.

---

## 15. What is TCP?

TCP stands for Transmission Control Protocol.

It is a reliable and connection oriented protocol.

---

## 16. What is the use of socket()?

socket() creates a socket for communication.

---

## 17. What is the use of bind()?

bind() connects socket with IP address and port number.

---

## 18. What is the use of listen()?

listen() waits for client connection requests.

---

## 19. What is the use of accept()?

accept() accepts client connection.

---

## 20. What is the use of connect()?

connect() connects client to server.

---

## 21. What is the use of send()?

send() sends data through socket.

---

## 22. What is the use of read()?

read() receives data from socket.

---

## 23. What is the use of close()?

close() closes socket connection.

---

## 24. What is localhost?

localhost means same computer.

IP address:
127.0.0.1

---

## 25. What is a port number?

Port number identifies a specific application or process in network communication.

Example:
8080

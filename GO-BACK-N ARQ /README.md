# GO-BACK-N PROTOCOL

## Aim

To simulate Go-Back-N ARQ Protocol using socket programming in C.

---

# Main Definitions

## Go-Back-N ARQ

Go-Back-N ARQ is an error control protocol used in computer networks.

In this protocol:
- Multiple frames are sent continuously
- Receiver accepts frames in order
- If one frame is lost, all frames after it are discarded
- Sender retransmits the lost frame and all following frames

---

## ARQ

ARQ stands for:

Automatic Repeat reQuest

It is used for reliable data transmission.

---

## Sliding Window

Sliding Window is a flow control method where multiple frames are sent before receiving acknowledgment.

---

## Frame

A frame is a unit of data transmitted over a network.

Example:

```text
0 1 2 3 4 5
```

---

## Acknowledgment (ACK)

ACK is a message sent by receiver to confirm successful frame reception.

---

## Retransmission

Retransmission means resending frames when acknowledgment is not received.

In Go-Back-N:
- Lost frame and all following frames are retransmitted.

---

## Window Size

Window size represents the maximum number of frames that can be sent without waiting for acknowledgment.

---

## TCP

TCP stands for Transmission Control Protocol.

TCP provides:
- Reliable communication
- Ordered delivery
- Error checking

---

# How the Program Works

1. Server creates socket
2. Server waits for client connection
3. Client connects to server
4. Client sends frames within window size
5. Server receives frames
6. One frame may be lost or discarded
7. Receiver sends acknowledgment
8. If ACK not received, sender retransmits frames
9. Process continues until all frames are received

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
bind(sockfd,
(struct sockaddr *)&servaddr,
sizeof(servaddr));
```

### Step 3
Listen for client connection

```c
listen(sockfd, 5);
```

### Step 4
Accept client connection

```c
accept(sockfd,
(struct sockaddr *)&cli,
&len);
```

### Step 5
Client sends frames

```c
send(sockfd, buff, sizeof(buff), 0);
```

### Step 6
Server receives frames

```c
recv(connfd, buff, MAX, 0);
```

### Step 7
Server sends acknowledgment

```c
send(connfd, buff, sizeof(buff), 0);
```

### Step 8
Check acknowledgment timeout

```c
recv(sockfd, buff, MAX, 0);
```

### Step 9
Resend frames if acknowledgment not received

```c
printf("Resending frames");
```

### STOP

---

# Important Functions Used

| Function | Purpose |
|---|---|
| socket() | Creates socket |
| bind() | Binds socket with IP and port |
| listen() | Waits for client |
| accept() | Accepts connection |
| connect() | Connects to server |
| send() | Sends data |
| recv() | Receives data |
| setsockopt() | Sets timeout option |
| close() | Closes socket |

---

# Sample Output

## Server Side

```text
Socket successfully created
Socket successfully binded
Server listening
Server accept the client

Frame 0 received
Acknowledement sent: 0

Frame 1 received
Acknowledement sent: 1

Frame 3 discarded
Acknowledgement sent: 1

Frame 4 discarded
Acknowledgement sent: 1

Frame 5 discarded
Acknowledgement sent: 1

Frame 2 received
Acknowledement sent: 2

Frame 3 received
Acknowledement sent: 3

Frame 4 received
Acknowledement sent: 4

Frame 5 received
Acknowledement sent: 5

Exit
```

---

## Client Side

```text
Socket successfully created
Connected to the server

Enter the number of frames: 6
Enter the window size: 4

Frame 0 sent
Frame 1 sent
Frame 2 sent
Frame 3 sent

Acknowlegement received: 0

Frame 4 sent

Acknowlegement received: 1

Frame 5 sent

Acknowledgement not received for 2
Resending frames

Frame 2 sent
Frame 3 sent
Frame 4 sent
Frame 5 sent

Acknowlegement received: 2
Acknowlegement received: 3
Acknowlegement received: 4
Acknowlegement received: 5

Exit
```

---

# Advantages

- Better efficiency than Stop and Wait
- Multiple frames transmitted together
- Simple error recovery mechanism

---

# Disadvantages

- Retransmits multiple frames unnecessarily
- Bandwidth wastage may occur
- Receiver discards out of order frames

---

# Applications

- Data communication
- Error control systems
- Reliable transmission systems
- Computer networks

---

# Viva Questions and Answers

## 1. What is Go-Back-N Protocol?

Go-Back-N is an ARQ protocol where sender retransmits lost frame and all following frames.

---

## 2. What does ARQ stand for?

Automatic Repeat reQuest.

---

## 3. What is sliding window?

Sliding window allows multiple frames to be sent before receiving acknowledgment.

---

## 4. What happens if a frame is lost?

Receiver discards all following frames and sender retransmits them.

---

## 5. What is retransmission?

Retransmission means resending frames whose acknowledgment was not received.

---

## 6. What is ACK?

ACK is an acknowledgment message sent by receiver.

---

## 7. What is window size?

Window size is the number of frames that can be sent without waiting for ACK.

---

## 8. Which protocol is used here?

TCP protocol is used.

---

## 9. Why is TCP used?

TCP provides reliable and ordered communication.

---

## 10. What is the disadvantage of Go-Back-N?

Multiple frames may be retransmitted even if only one frame is lost.

# SELECTIVE REPEAT ARQ PROTOCOL

## Aim

To simulate Selective Repeat ARQ Protocol using socket programming in C.

---

# Main Definitions

## Selective Repeat ARQ

Selective Repeat ARQ is an error control protocol used in computer networks.

In this protocol:
- Multiple frames are sent continuously
- Only lost or damaged frames are retransmitted
- Correctly received frames are accepted and stored

---

## ARQ

ARQ stands for:

Automatic Repeat reQuest

It is used for reliable data transmission.

---

## Frame

A frame is a unit of data transmitted over a network.

Example:

```text
0 1 2 3 4 5 6 7
```

---

## Acknowledgment (ACK)

ACK is a message sent by receiver to sender to confirm successful frame reception.

---

## Sliding Window

Sliding Window is a flow control technique where multiple frames can be transmitted before receiving acknowledgment.

---

## Retransmission

Retransmission means resending lost or damaged frames.

In Selective Repeat:
Only the lost frame is retransmitted.

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
4. Client sends frames
5. Server randomly drops one frame
6. Server sends ACK for missing frame
7. Client retransmits only missing frame
8. Server receives retransmitted frame
9. Communication ends successfully

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
write(sockfd, buff, sizeof(buff));
```

### Step 6
Server simulates frame loss

```c
c = rand() % (win - 1);
```

### Step 7
Server sends ACK for missing frame

```c
write(connfd, buff, sizeof(buff));
```

### Step 8
Client retransmits missing frame

```c
write(sockfd, buff, sizeof(buff));
```

### Step 9
Server receives retransmitted frame

```c
read(connfd, buff, sizeof(buff));
```

### STOP

---

# Important Functions Used

| Function | Purpose |
|---|---|
| socket() | Creates socket |
| bind() | Binds socket with IP and port |
| listen() | Waits for client |
| accept() | Accepts client connection |
| connect() | Connects to server |
| read() | Receives data |
| write() | Sends data |
| close() | Closes socket |

---

# Sample Output

## Server Side

```text
Socket successfully created
Socket successfully binded
Server listening
Server accepted the client

Received Frame: 0
Received Frame: 1
Received Frame: 2
Received Frame: 3
Received Frame: 5
Received Frame: 6
Received Frame: 7

Frame 4 not received
Waiting for Frame 4

Received Frame 4
```

---

## Client Side

```text
Socket successfully created
Connected to the receiver

Frames Sending : 0 1 2 3 4 5 6 7

Frame 4 not sent properly.

Resending Frame : 4

All frames sent successfully

Exit
```

---

# Advantages

- Efficient retransmission
- Better bandwidth utilization
- Faster than Stop and Wait
- Only lost frames are resent

---

# Disadvantages

- More complex implementation
- Requires more memory
- Frame ordering management required

---

# Applications

- Data communication
- Wireless networks
- Reliable transmission systems
- Error control systems

---

# Viva Questions and Answers

## 1. What is Selective Repeat ARQ?

Selective Repeat ARQ is an error control protocol where only lost frames are retransmitted.

---

## 2. What does ARQ stand for?

Automatic Repeat reQuest.

---

## 3. What is the advantage of Selective Repeat over Stop and Wait?

Multiple frames can be sent continuously and only lost frames are retransmitted.

---

## 4. What is retransmission?

Retransmission means resending lost or damaged frames.

---

## 5. What is ACK?

ACK is an acknowledgment message sent by receiver.

---

## 6. What is sliding window?

Sliding window is a technique that allows multiple frames to be sent before receiving acknowledgment.

---

## 7. Which protocol is used here?

TCP protocol is used.

---

## 8. Why is TCP used?

TCP provides reliable and ordered communication.

---

## 9. What happens when a frame is lost?

Receiver requests retransmission of only that frame.

---

## 10. What is the main advantage of Selective Repeat ARQ?

Only lost frames are retransmitted, improving efficiency.

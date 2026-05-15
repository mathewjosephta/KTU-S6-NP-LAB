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
- Sender waits for acknowledgment (ACK)
- Receiver sends acknowledgment
- Sender sends next frame only after receiving ACK

---

## Flow Control

Flow control controls the speed of data transmission between sender and receiver.

It prevents data loss when sender sends data faster than receiver can process.

---

## Frame

A frame is a unit of data transmitted over a network.

In this program:
Frame numbers are sent from client to server.

Example:

```text
0, 1, 2, 3 ...
```

---

## Acknowledgment (ACK)

ACK is a message sent by receiver to sender.

It confirms that the frame was received successfully.

Example:

```text
ACK for frame 0
```

---

## Socket Programming

Socket programming is a method used for communication between two systems over a network.

Socket acts as an endpoint for communication.

---

## TCP

TCP stands for:

Transmission Control Protocol

TCP is:
- Reliable
- Connection oriented
- Error checking supported
- Ordered data delivery

TCP ensures data reaches correctly.

---

# How the Program Works

1. Server creates socket
2. Server waits for connection
3. Client connects to server
4. Client sends frame
5. Server receives frame
6. Server sends ACK
7. Client receives ACK
8. Next frame is sent
9. Process repeats until all frames are sent

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
bind(server_fd, (struct sockaddr *)&address, sizeof(address));
```

### Step 3
Listen for client connection

```c
listen(server_fd, 3);
```

### Step 4
Accept client connection

```c
accept(server_fd, (struct sockaddr *)&address, &addrlen);
```

### Step 5
Client sends frame

```c
send(sock, buffer, strlen(buffer), 0);
```

### Step 6
Server receives frame

```c
read(new_socket, buffer, sizeof(buffer));
```

### Step 7
Server sends acknowledgment

```c
send(new_socket, ack, strlen(ack), 0);
```

### Step 8
Client receives acknowledgment

```c
read(sock, buffer, sizeof(buffer));
```

### Step 9
Repeat until all frames are sent

```c
while(frame < total_frames)
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
| read() | Receives data |
| close() | Closes socket |

---

# Sample Output

## Server Side

```text
Server is listening on port 8080
Connection established with client

Server: Received frame 0
Server: Sent acknowledgment for frame 0

Server: Received frame 1
Server: Sent acknowledgment for frame 1

Server: Received frame 2
Server: Sent acknowledgment for frame 2

Connection closed by client
```

---

## Client Side

```text
Enter the total number of frames to send: 3

Client: Sent frame 0
Client: Received acknowledgment: ACK for frame 0

Client: Sent frame 1
Client: Received acknowledgment: ACK for frame 1

Client: Sent frame 2
Client: Received acknowledgment: ACK for frame 2

All frames sent successfully
```

---

# Advantages of Stop and Wait Protocol

- Simple implementation
- Reliable communication
- Easy error handling

---

# Disadvantages of Stop and Wait Protocol

- Slow transmission
- Low efficiency
- Sender waits after every frame

---

# Viva Questions and Answers

## 1. What is Stop and Wait Protocol?

It is a protocol where sender sends one frame and waits for acknowledgment before sending the next frame.

---

## 2. Why is acknowledgment important?

Acknowledgment confirms successful reception of frame.

---

## 3. What happens if ACK is not received?

Sender retransmits the frame.

---

## 4. What is flow control?

Flow control controls the rate of data transmission between sender and receiver.

---

## 5. Which protocol is used here?

TCP protocol is used.

---

## 6. Why is TCP used?

TCP provides reliable and connection oriented communication.

---

## 7. What is the disadvantage of Stop and Wait Protocol?

It is slow because sender waits after every frame.

---

## 8. What is a frame?

A frame is a unit of data transmitted through network.

---

## 9. What is the role of sender?

Sender sends frames and waits for acknowledgment.

---

## 10. What is the role of receiver?

Receiver receives frames and sends acknowledgment.

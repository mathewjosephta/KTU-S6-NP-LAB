# SIMULATION OF SLIDING WINDOW PROTOCOLS  
# STOP AND WAIT PROTOCOL

---

# Aim

To simulate Stop and Wait Protocol using socket programming in C.

---

# What is Stop and Wait Protocol?

Stop and Wait Protocol is a flow control protocol used in computer networks.

In this protocol:

- Sender sends one frame
- Sender waits for acknowledgment (ACK)
- Receiver sends acknowledgment
- Sender sends next frame only after receiving ACK

---

# Why is it called Stop and Wait?

After sending every frame:
- Sender stops
- Waits for acknowledgment from receiver

Then only next frame is sent.

---

# What is Flow Control?

Flow control controls the speed of data transmission between sender and receiver.

It prevents data loss when sender sends data faster than receiver can process.

---

# What is a Frame?

A frame is a unit of data transmitted over a network.

In this program:
Frame numbers are sent from client to server.

Example:
0, 1, 2, 3 ...

---

# What is Acknowledgment (ACK)?

ACK is a message sent by receiver to sender.

It confirms that the frame was received successfully.

Example:

ACK for frame 0

---

# What is Socket Programming?

Socket programming is a method used for communication between two systems over a network.

Socket acts as an endpoint for communication.

---

# What is TCP?

TCP stands for:

Transmission Control Protocol

TCP is:
- Reliable
- Connection oriented
- Error checking supported
- Ordered data delivery

TCP ensures data reaches correctly.

---

# Program Flow

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

# Important Functions Used

| Function | Purpose |
|----------|----------|
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

Server is listening on port 8080  
Connection established with client  

Server: Received frame 0  
Server: Sent acknowledgment for frame 0  

Server: Received frame 1  
Server: Sent acknowledgment for frame 1  

Server: Received frame 2  
Server: Sent acknowledgment for frame 2  

Connection closed by client  

---

## Client Side

Enter the total number of frames to send: 3  

Client: Sent frame 0  
Client: Received acknowledgment: ACK for frame 0  

Client: Sent frame 1  
Client: Received acknowledgment: ACK for frame 1  

Client: Sent frame 2  
Client: Received acknowledgment: ACK for frame 2  

All frames sent successfully  

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

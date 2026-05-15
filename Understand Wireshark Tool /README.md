# UNDERSTANDING THE WIRESHARK TOOL

## Aim

To study and understand the working of Wireshark, a network protocol analyzer tool used to capture and analyze network traffic.

---

# Main Definitions

## Wireshark

Wireshark is an open source network protocol analyzer used to capture and analyze packets traveling through a network in real time.

It is widely used for:
- Network troubleshooting
- Protocol analysis
- Security analysis
- Network monitoring
- Learning computer networks

---

## Packet

A packet is a small unit of data transmitted over a network.

Each packet contains:
- Source address
- Destination address
- Protocol information
- Payload data

---

## Protocol

A protocol is a set of rules used for communication between devices.

Examples:
- TCP
- UDP
- HTTP
- DNS
- ICMP

---

## IP Address

IP address identifies a device connected to a network.

Example:

```text
192.168.1.1
```

---

## MAC Address

MAC address is a physical hardware address of a network device.

---

## Port Number

Port number identifies a specific application or service running on a system.

Examples:
- HTTP → Port 80
- HTTPS → Port 443
- DNS → Port 53

---

## Packet Capture

Packet capture means collecting network packets for analysis.

---

# Features of Wireshark

1. Real time packet capture
2. Offline packet analysis
3. Supports hundreds of protocols
4. Color coded packet display
5. Powerful display filters
6. TCP session reconstruction
7. Export capture files in multiple formats

---

# How Wireshark Works

1. Wireshark captures packets from a selected network interface
2. Captured packets are displayed in real time
3. User applies filters to analyze specific packets
4. Packet details can be viewed layer by layer
5. Captured packets can be saved for future analysis

---

# Procedure

## Step 1 : Launch Wireshark

- Open Wireshark application
- Available network interfaces are displayed

---

## Step 2 : Start Packet Capture

- Select active network interface
- Click blue shark fin icon
- Packet capturing begins

---

## Step 3 : Observe Captured Packets

Each packet shows:
- Packet number
- Time
- Source address
- Destination address
- Protocol
- Packet information

---

## Step 4 : Apply Filters

Filters help display only required packets.

Example filters:

| Filter | Description |
|---|---|
| ip | Displays all IP packets |
| http | Displays only HTTP packets |
| dns | Displays DNS packets |
| icmp | Displays ping packets |
| tcp.port == 80 | Displays TCP packets on port 80 |

---

## Step 5 : Analyze Packets

Click a packet to view:
- Ethernet details
- IP details
- TCP/UDP details
- Application layer details

---

## Step 6 : Stop Capture

- Click red square icon
- Save capture using:

```text
File → Save As
```

---

# Algorithm

### START

### Step 1
Launch Wireshark

---

### Step 2
Select active network interface

---

### Step 3
Start packet capture

---

### Step 4
Observe captured packets

---

### Step 5
Apply filters if required

Example:

```text
http
dns
icmp
```

---

### Step 6
Analyze packet details

---

### Step 7
Stop packet capture

---

### Step 8
Save capture file

---

### STOP

---

# Common Filters Used

| Filter | Purpose |
|---|---|
| ip | Show all IP packets |
| tcp | Show TCP packets |
| udp | Show UDP packets |
| dns | Show DNS packets |
| icmp | Show ping packets |
| http | Show HTTP packets |
| arp | Show ARP packets |

---

# Sample Output

## Wireshark Main Interface

- Displays available network interfaces
- Allows packet capture selection

---

## Wireshark Working Screen

Displays:
- Packet list pane
- Packet details pane
- Packet bytes pane

---

# Advantages

- Real time packet analysis
- Easy troubleshooting
- Supports many protocols
- User friendly interface
- Powerful filtering system

---

# Disadvantages

- Requires network knowledge
- Large captures consume memory
- Encrypted traffic cannot be fully analyzed

---

# Applications

- Network troubleshooting
- Cybersecurity analysis
- Protocol development
- Traffic monitoring
- Educational purposes

---

# Viva Questions and Answers

## 1. What is Wireshark?

Wireshark is a network protocol analyzer used to capture and analyze network packets.

---

## 2. What is packet capture?

Packet capture is the process of collecting network packets for analysis.

---

## 3. What is a protocol?

A protocol is a set of communication rules between devices.

---

## 4. What is the use of filters in Wireshark?

Filters are used to display only required packets.

---

## 5. What does HTTP filter do?

It displays only HTTP packets.

---

## 6. What is the use of ICMP filter?

It displays ping packets.

---

## 7. What is packet analysis?

Packet analysis means examining packet contents and network communication.

---

## 8. What is a network interface?

A network interface is a connection point used for network communication.

Examples:
- Wi-Fi
- Ethernet

---

## 9. Can Wireshark capture live traffic?

Yes. Wireshark captures packets in real time.

---

## 10. What is the purpose of Wireshark?

Wireshark is used to monitor, troubleshoot, and analyze network traffic.

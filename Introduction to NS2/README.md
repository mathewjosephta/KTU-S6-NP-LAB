# NS2 SIMULATOR

## Aim

To study and understand the working of the Network Simulator 2 (NS2) tool used for simulating and analyzing network protocols and communication behavior.

---

# Main Definitions

## NS2

NS2 (Network Simulator 2) is an open source discrete event simulator used for networking research and education.

It is mainly used to simulate:
- Wired networks
- Wireless networks
- TCP/UDP protocols
- Routing protocols
- Network traffic behavior

---

## Simulation

Simulation is the process of creating a virtual model of a real network system to study its behavior.

---

## Tcl Script

Tcl (Tool Command Language) is used in NS2 to write simulation programs.

The script defines:
- Nodes
- Links
- Protocols
- Traffic flow
- Events

---

## C++ Backend

Core functionalities of NS2 are implemented in C++ for better performance.

---

## NAM

NAM stands for:

Network Animator

It is a graphical visualization tool used to view packet movement and network communication.

---

## Trace File

Trace files store detailed simulation information such as:
- Packet transmission
- Packet reception
- Packet drops
- Delay information

---

## TCP

TCP stands for Transmission Control Protocol.

TCP provides:
- Reliable communication
- Error checking
- Ordered delivery

---

## UDP

UDP stands for User Datagram Protocol.

UDP provides:
- Faster communication
- Connectionless transfer
- Less overhead

---

## FTP

FTP stands for File Transfer Protocol.

It is used to transfer files between systems.

---

## CBR

CBR stands for Constant Bit Rate.

CBR traffic sends packets at a constant speed.

---

# Main Components of NS2

| Component | Purpose |
|---|---|
| Tcl | Writing simulation scripts |
| C++ | Backend implementation |
| NAM | Network animation |
| Trace Files | Event recording |

---

# How NS2 Works

1. User writes simulation script using Tcl
2. NS2 executes the script
3. Network events are simulated
4. Trace file is generated
5. NAM visualizes network communication
6. Results are analyzed

---

# Procedure

## Step 1 : Launch NS2

Open terminal and start NS2 environment.

---

## Step 2 : Create Simulation Script

Create a Tcl script file.

Example:

```text
simple.tcl
```

---

## Step 3 : Run Simulation

Execute the script using:

```bash
ns simple.tcl
```

This generates:

```text
out.nam
```

---

## Step 4 : Open NAM

Visualize simulation using:

```bash
nam out.nam
```

The NAM window shows:
- Nodes
- Links
- Packet movement

---

# Algorithm

### START

### Step 1
Create simulator object

```tcl
set ns [new Simulator]
```

### Step 2
Open NAM trace file

```tcl
set nf [open out.nam w]
```

### Step 3
Create nodes

```tcl
set n0 [$ns node]
```

### Step 4
Create links between nodes

```tcl
$ns duplex-link $n0 $n2 2Mb 10ms DropTail
```

### Step 5
Setup TCP and UDP agents

```tcl
set tcp [new Agent/TCP]
set udp [new Agent/UDP]
```

### Step 6
Attach applications

```tcl
set ftp [new Application/FTP]
set cbr [new Application/Traffic/CBR]
```

### Step 7
Schedule events

```tcl
$ns at 0.1 "$cbr start"
```

### Step 8
Run simulation

```tcl
$ns run
```

### STOP

---

# Important NS2 Commands

| Command | Purpose |
|---|---|
| ns simple.tcl | Run simulation |
| nam out.nam | Open network animator |
| set ns [new Simulator] | Create simulator |
| $ns node | Create node |
| duplex-link | Create bidirectional link |
| attach-agent | Attach protocol agent |
| connect | Connect agents |
| at | Schedule events |

---

# Sample Script

```tcl
set ns [new Simulator]

set n0 [$ns node]
set n1 [$ns node]

$ns duplex-link $n0 $n1 2Mb 10ms DropTail

$ns run
```

---

# Sample Output

## Terminal Output

```text
CBR packet size = 1000
CBR interval = 0.008
```

---

## NAM Output

Displays:
- Network nodes
- Communication links
- Packet movement
- Traffic flow

---

# Advantages

- Open source
- Supports wired and wireless simulation
- Useful for protocol analysis
- Graphical visualization through NAM
- Educational and research support

---

# Disadvantages

- Old simulator
- Complex Tcl scripting
- Limited modern protocol support
- Slower for very large simulations

---

# Applications

- Network research
- Protocol testing
- Traffic analysis
- Academic projects
- Wireless network simulation

---

# Viva Questions and Answers

## 1. What is NS2?

NS2 is an open source network simulator used for simulating network protocols and communication.

---

## 2. What is NAM?

NAM is a graphical network animator used to visualize NS2 simulations.

---

## 3. What is Tcl?

Tcl is a scripting language used to write NS2 simulation programs.

---

## 4. What is the purpose of trace files?

Trace files store simulation events like packet send, receive, and drop.

---

## 5. What is a network simulator?

A network simulator is software used to model and analyze network behavior.

---

## 6. What is the use of duplex-link?

duplex-link creates a bidirectional communication link between nodes.

---

## 7. What is CBR traffic?

CBR sends packets at constant data rate.

---

## 8. What is the difference between TCP and UDP in NS2?

TCP is reliable while UDP is faster and connectionless.

---

## 9. How to run an NS2 simulation?

Use command:

```bash
ns filename.tcl
```

---

## 10. How to visualize NS2 output?

Use NAM command:

```bash
nam out.nam
```

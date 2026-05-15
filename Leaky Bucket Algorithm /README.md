# CONGESTION CONTROL USING LEAKY BUCKET ALGORITHM

## Aim

To simulate congestion control using Leaky Bucket Algorithm in C.

---

# Main Definitions

## Congestion

Congestion occurs when the network receives more packets than it can handle.

This causes:
- Packet loss
- Delay
- Reduced network performance

---

## Congestion Control

Congestion control is the process of controlling packet flow in a network to avoid congestion.

---

## Leaky Bucket Algorithm

Leaky Bucket Algorithm is a congestion control algorithm used to control the rate of packet transmission.

It works like a bucket with a small hole:
- Packets enter the bucket
- Packets leave at a fixed rate
- Extra packets are dropped if bucket becomes full

---

## Bucket Size

Bucket size represents the maximum number of packets that can be stored.

---

## Incoming Packets

Incoming packets are packets entering the bucket.

---

## Outgoing Rate

Outgoing rate represents the number of packets leaving the bucket at a fixed rate.

---

## Packet Drop

If incoming packets exceed bucket capacity, extra packets are dropped.

---

# How the Program Works

1. User enters bucket size
2. User enters number of inputs
3. User enters outgoing rate
4. Incoming packets enter the bucket
5. If bucket overflows, packets are dropped
6. Packets leave bucket at fixed outgoing rate
7. Remaining packets are displayed
8. Process repeats for all inputs

---

# Algorithm

### START

### Step 1
Read bucket size

```c
scanf("%d", &size);
```

### Step 2
Read number of inputs

```c
scanf("%d", &n);
```

### Step 3
Read outgoing rate

```c
scanf("%d", &out);
```

### Step 4
Read incoming packet size

```c
scanf("%d", &in);
```

### Step 5
Check bucket capacity

```c
if(in <= (size - store))
```

### Step 6
Store packets in bucket

```c
store += in;
```

### Step 7
Drop extra packets if bucket is full

```c
printf("Dropped packets");
```

### Step 8
Remove packets using outgoing rate

```c
store -= out;
```

### Step 9
Display remaining packets

```c
printf("Packets left in buffer");
```

### STOP

---

# Program Code

```c
#include <stdio.h>

int main()
{
    int in, out, size, n;
    int store = 0;

    printf("Enter bucket size: ");
    scanf("%d", &size);

    printf("Enter number of inputs: ");
    scanf("%d", &n);

    printf("Enter outgoing rate: ");
    scanf("%d", &out);

    while(n != 0)
    {
        printf("Incoming packet size: ");
        scanf("%d", &in);

        if(in <= (size - store))
        {
            store += in;

            printf("Bucket buffer size %d out of %d\n",
                   store, size);
        }
        else
        {
            printf("Dropped %d number of packets\n",
                   in - (size - store));

            store = size;

            printf("Bucket buffer size %d out of %d\n",
                   store, size);
        }

        store -= out;

        if(store < 0)
        {
            store = 0;
        }

        printf("After outgoing %d packets left out of %d in buffer\n",
               store, size);

        n--;
    }

    return 0;
}
```

---

# Sample Output

```text
Enter bucket size: 10
Enter number of inputs: 4
Enter outgoing rate: 3

Incoming packet size: 4
Bucket buffer size 4 out of 10
After outgoing 1 packets left out of 10 in buffer

Incoming packet size: 6
Bucket buffer size 7 out of 10
After outgoing 4 packets left out of 10 in buffer

Incoming packet size: 8
Dropped 2 number of packets
Bucket buffer size 10 out of 10
After outgoing 7 packets left out of 10 in buffer

Incoming packet size: 5
Bucket buffer size 10 out of 10
After outgoing 7 packets left out of 10 in buffer
```

---

# Advantages

- Controls congestion efficiently
- Smooth packet transmission
- Prevents sudden traffic bursts
- Simple implementation

---

# Disadvantages

- Packet loss may occur
- Fixed outgoing rate
- Not suitable for bursty traffic

---

# Applications

- Network traffic control
- Data communication
- Congestion management
- Packet scheduling

---

# Viva Questions and Answers

## 1. What is congestion?

Congestion occurs when network traffic exceeds network capacity.

---

## 2. What is congestion control?

Congestion control controls packet transmission to avoid congestion.

---

## 3. What is Leaky Bucket Algorithm?

Leaky Bucket Algorithm controls packet flow using a fixed outgoing rate.

---

## 4. Why is it called Leaky Bucket?

It behaves like a bucket with a hole where packets leak out at a constant rate.

---

## 5. What happens when bucket becomes full?

Extra packets are dropped.

---

## 6. What is bucket size?

Bucket size is the maximum packet storage capacity.

---

## 7. What is outgoing rate?

Outgoing rate is the number of packets leaving the bucket at fixed rate.

---

## 8. What is packet drop?

Packet drop occurs when incoming packets exceed bucket capacity.

---

## 9. What is the advantage of Leaky Bucket Algorithm?

It controls congestion and smoothens traffic flow.

---

## 10. What is the disadvantage of Leaky Bucket Algorithm?

Packet loss may occur during heavy traffic.

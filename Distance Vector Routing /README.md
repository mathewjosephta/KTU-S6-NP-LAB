# DISTANCE VECTOR ROUTING PROTOCOL

## Aim

To implement Distance Vector Routing Algorithm and generate routing tables using C programming.

---

# Main Definitions

## Distance Vector Routing
Distance Vector Routing is a routing algorithm used to find the shortest path between routers in a network.

Each router:
- Maintains a routing table
- Shares routing information with neighboring routers
- Updates shortest paths dynamically

---

## Routing Table
A routing table stores:
- Destination router
- Next hop
- Distance to destination

---

## Distance
Distance means the cost required to reach a destination node.

---

## Next Hop
Next hop is the next router through which data is forwarded to reach destination.

---

## Infinity (999)
999 represents:
- No direct connection
- Infinite distance

---

## Bellman Ford Algorithm
Bellman Ford Algorithm is used to calculate shortest paths between routers.

---

# How the Program Works

1. User enters number of routers
2. User enters cost matrix
3. Routing tables are initialized
4. Routers exchange routing information
5. Shortest paths are calculated
6. Routing tables are updated
7. Final routing tables are displayed

---

# Algorithm

### START

### Step 1
Read the number of nodes

```c
scanf("%d", &n);
```

### Step 2
Read the cost matrix

```c
scanf("%d", &cost[i][j]);
```

### Step 3
Initialize routing table with given costs

```c
rt[i].dist[j] = cost[i][j];
```

### Step 4
Set next hop for each destination

```c
rt[i].from[j] = j;
```

### Step 5
Repeat until no changes occur

```c
do
{
    count = 0;
```

### Step 6
Compare current distance with new calculated distance

```c
if(rt[i].dist[j] >
   cost[i][k] + rt[k].dist[j])
```

### Step 7
Update shortest distance and next hop

```c
rt[i].dist[j] =
cost[i][k] + rt[k].dist[j];

rt[i].from[j] = k;

count++;
```

### Step 8
Continue until routing table becomes stable

```c
} while(count != 0);
```

### Step 9
Display routing tables

```c
printf("Destination\tNext Hop\tDistance");
```

### STOP

---

# Data Structure Used

```c
struct node
{
    unsigned dist[20];
    unsigned from[20];
};
```

---

# Meaning of Structure Members

| Variable | Meaning |
|---|---|
| dist[] | Stores distance to destination |
| from[] | Stores next hop router |

---

# Sample Input

```text
Enter number of nodes (max 20): 3

Use 999 to represent infinity

Cost from node 1 to node 1: 0
Cost from node 1 to node 2: 2
Cost from node 1 to node 3: 7

Cost from node 2 to node 1: 2
Cost from node 2 to node 2: 0
Cost from node 2 to node 3: 1

Cost from node 3 to node 1: 7
Cost from node 3 to node 2: 1
Cost from node 3 to node 3: 0
```

---

# Sample Output

```text
--- Routing Tables ---

Routing table for router 1:

Destination    Next Hop    Distance

1              1           0
2              2           2
3              2           3

Routing table for router 2:

Destination    Next Hop    Distance

1              1           2
2              2           0
3              3           1

Routing table for router 3:

Destination    Next Hop    Distance

1              2           3
2              2           1
3              3           0
```

---

# Advantages

- Simple implementation
- Easy to understand
- Suitable for small networks

---

# Disadvantages

- Slow convergence
- Count to infinity problem
- Not suitable for large networks

---

# Applications

- Network routing
- Router path selection
- RIP (Routing Information Protocol)

---

# Viva Questions and Answers

## 1. What is Distance Vector Routing?

Distance Vector Routing is a routing algorithm used to find shortest paths between routers.

---

## 2. Which algorithm is used here?

Bellman Ford Algorithm.

---

## 3. What is stored in a routing table?

- Destination
- Next hop
- Distance

---

## 4. What is meant by next hop?

Next hop is the next router used to reach the destination.

---

## 5. What does 999 represent?

999 represents infinity or no direct connection.

---

## 6. What is convergence?

Convergence is the process where all routers update their routing tables correctly.

---

## 7. What is routing?

Routing is the process of selecting path for data transmission.

---

## 8. What is the disadvantage of Distance Vector Routing?

- Slow convergence
- Count to infinity problem

---

## 9. What is Bellman Ford Algorithm?

It is an algorithm used to find shortest paths from source to destination.

---

## 10. What is the purpose of this program?

To calculate shortest paths and generate routing tables for routers.

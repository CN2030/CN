# CN — Computer Networks Lab Experiments (C / Dev-C++)

[![Language: C](https://img.shields.io/badge/Language-C-00599C?style=flat-square&logo=c)](https://en.wikipedia.org/wiki/C_(programming_language))
[![Compiler: GCC / Dev-C++](https://img.shields.io/badge/Compiler-GCC%20%2F%20Dev--C%2B%2B-4B8BBE?style=flat-square)](https://www.bloodshed.net/)
[![Tests: Verified](https://img.shields.io/badge/Tests-100%25%20Passing-brightgreen?style=flat-square)]()

A clean, structured collection of core **Computer Networks (CN)** laboratory practicals implemented in standard C. Tested and verified for compatibility with **Dev-C++**, **GCC**, and **Clang**.

---

## 📚 Experiment Index

| # | File Name | Topic & Concept | Key Features & Implementation |
|---|---|---|---|
| **01** | [`01_ip_conversion.c`](./01_ip_conversion.c) | **IPv4 Binary & Dotted-Decimal Conversion** | Two-way conversion: 32-bit binary string to dotted decimal and dotted decimal to 32-bit dotted binary string with octet validation (0–255). |
| **02** | [`02_ip_class.c`](./02_ip_class.c) | **IPv4 Classful Addressing** | Determines Class A (1–126), Class B (128–191), Class C (192–223), Class D Multicast (224–239), Class E Reserved (240–255), and loopback (127.x.x.x). |
| **03** | [`03_dijkstra.c`](./03_dijkstra.c) | **Dijkstra's Shortest Path Algorithm** | Computes single-source shortest path routing table over a weighted adjacency matrix graph with non-negative edge costs and unreachability handling. |
| **04** | [`04_pure_aloha.c`](./04_pure_aloha.c) | **Pure ALOHA MAC Protocol Simulation** | Frame collision simulation detecting overlap across arbitrary transmission start times over continuous time windows (vulnerable period = $2 \times T_{fr}$). |
| **05** | [`05_bellman_ford.c`](./05_bellman_ford.c) | **Bellman-Ford Distance Vector Algorithm** | Computes shortest paths on directed graphs with negative edge weights; includes negative-weight cycle detection and relaxation early-exit. |
| **06** | [`06_slotted_aloha.c`](./06_slotted_aloha.c) | **Slotted ALOHA MAC Protocol Simulation** | Discrete time slot contention model classifying each slot into `IDLE` (0 stations), `SUCCESS` (1 station), or `COLLISION` (>1 stations) with summary metrics. |

---

## 🛠️ How to Compile & Run

### Method 1: Using GCC / MinGW Command Line

Compile any experiment using `gcc`:

```bash
# Experiment 1: IP Conversion
gcc 01_ip_conversion.c -o 01_ip_conversion
./01_ip_conversion

# Experiment 2: IP Class Identifier
gcc 02_ip_class.c -o 02_ip_class
./02_ip_class

# Experiment 3: Dijkstra Algorithm
gcc 03_dijkstra.c -o 03_dijkstra
./03_dijkstra

# Experiment 4: Pure ALOHA Simulation
gcc 04_pure_aloha.c -o 04_pure_aloha
./04_pure_aloha

# Experiment 5: Bellman-Ford Algorithm
gcc 05_bellman_ford.c -o 05_bellman_ford
./05_bellman_ford

# Experiment 6: Slotted ALOHA Simulation
gcc 06_slotted_aloha.c -o 06_slotted_aloha
./06_slotted_aloha
```

### Method 2: Using Dev-C++ IDE
1. Open **Dev-C++**.
2. Click **File → Open Project or File** (`Ctrl+O`) and select any `.c` file.
3. Press **`F11`** (Compile & Run) or click **Execute → Compile & Run**.

---

## 🧪 Sample Inputs & Test Cases

<details>
<summary><b>Click to expand sample inputs for each experiment</b></summary>

### 1. `01_ip_conversion.c`
* **Binary to Dotted Decimal:**
  * Choice: `1`
  * Input: `11000000101010000000000100001010`
  * Output: `Dotted-decimal: 192.168.1.10`
* **Dotted Decimal to Binary:**
  * Choice: `2`
  * Input: `192.168.1.10`
  * Output: `32-bit binary: 11000000.10101000.00000001.00001010`

### 2. `02_ip_class.c`
* Input: `172.16.5.4` → Output: `Class B`
* Input: `10.0.0.1` → Output: `Class A`
* Input: `192.168.1.1` → Output: `Class C`

### 3. `03_dijkstra.c`
```text
Enter number of vertices: 3
Enter cost matrix (3 x 3):
0 4 2
4 0 1
2 1 0
Enter source vertex: 0
Shortest distances from vertex 0:
To 0: 0
To 1: 3
To 2: 2
```

### 4. `04_pure_aloha.c`
```text
Enter number of stations: 3
Start times: 0.0, 0.5, 2.0
Station 1: COLLISION (frame 0.00 to 1.00)
Station 2: COLLISION (frame 0.50 to 1.50)
Station 3: SUCCESS (frame 2.00 to 3.00)
```

### 5. `05_bellman_ford.c`
```text
Enter number of vertices: 3
Enter number of directed edges: 3
Edges (from to weight):
0 1 4
0 2 2
2 1 1
Enter source vertex: 0
Shortest distances from vertex 0:
To 0: 0
To 1: 3
To 2: 2
```

### 6. `06_slotted_aloha.c`
```text
Enter number of time slots: 4
Attempts per slot: 0, 1, 2, 1
Slot 1: IDLE
Slot 2: SUCCESS
Slot 3: COLLISION (2 stations)
Slot 4: SUCCESS
```
</details>

---

## 📄 License
This repository is provided for academic and educational reference purposes.

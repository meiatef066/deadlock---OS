# Deadlock Avoidance, Detection, and Safe State (C++)

## Overview

This project demonstrates the concepts of **Deadlock Avoidance**, **Deadlock Detection**, and **Safe State** in the context of operating systems and resource allocation using **C++**.

- **Deadlock Avoidance** ensures that a system never enters a deadlock state.
- **Deadlock Detection** periodically checks if a system is in a deadlock state and takes appropriate action.
- **Safe State** refers to a state in which the system can allocate resources to processes in such a way that deadlock is avoided.

## Key Concepts

### 1. **Deadlock Avoidance**
Deadlock avoidance algorithms ensure that a system does not enter a deadlock situation. A common method used is the **Banker's Algorithm**, which checks whether allocating resources to a process will keep the system in a safe state.

#### What you will do:
- Implement the Banker's Algorithm to determine whether a requested resource allocation is safe.
- Check whether the system will remain in a safe state after each allocation request.

### 2. **Deadlock Detection**
Deadlock detection algorithms check if a system is in a deadlock state and if it is, recover from the deadlock.

#### What you will do:
- Implement an algorithm to detect deadlock in a system by examining the resource allocation graph or using the **Wait-for Graph**.
- Once a deadlock is detected, use a recovery method to break the deadlock, such as process termination or resource preemption.

### 3. **Safe State**
A safe state is one where resources can be allocated to processes in a way that ensures all processes will eventually complete. The system is said to be in a safe state if there exists a sequence of processes that can all be completed without causing deadlock.

#### What you will do:
- Implement the logic to check if the system is in a safe state before granting resource requests.
- Use **Safety Algorithm** (like the Banker's Algorithm) to determine if the system remains in a safe state after a resource allocation.

## Approach

1. **Simulate Processes and Resources**: 
   - Define a set of processes and the resources they request.
   - Keep track of the maximum resources each process might need, as well as the allocated resources.

2. **Implement Banker's Algorithm**:
   - Write functions in C++ to simulate the Banker's algorithm for both deadlock avoidance and safety checking.
   - Ensure that resources are allocated only if the system remains in a safe state.

3. **Deadlock Detection**:
   - Create a function that checks if there is a cycle in the wait-for graph, indicating a deadlock.
   - Implement recovery mechanisms to resolve deadlock, such as terminating or preempting processes.

4. **Testing**:
   - Test the system with different scenarios to verify that deadlock avoidance works and the system can detect and recover from deadlock situations.
   - Experiment with different resource allocation patterns and process behaviors to observe how the system handles them.

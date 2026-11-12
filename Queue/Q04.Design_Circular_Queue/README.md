# Q06. Design Circular Queue

## Problem Statement
Design a Circular Queue using an array.

A Circular Queue is a linear data structure in which the last position connects back to the first position, forming a circle.

It follows the FIFO (First In, First Out) principle.

Implement the following operations:

1. `enQueue(value)` – Insert an element into the queue. Return `true` if successful.
2. `deQueue()` – Delete an element from the front. Return `true` if successful.
3. `Front()` – Return the front element. Return `-1` if empty.
4. `Rear()` – Return the last element. Return `-1` if empty.
5. `isEmpty()` – Check whether the queue is empty.
6. `isFull()` – Check whether the queue is full.

## LeetCode Details

- **Problem Number:** 622
- **Problem Name:** Design Circular Queue
- **Difficulty:** Medium
- **Topic:** Queue, Array, Design
- **Platform:** LeetCode
- **Link:** https://leetcode.com/problems/design-circular-queue/

## Example

**Input:**
```text
MyCircularQueue q(3);
q.enQueue(10);
q.enQueue(20);
q.enQueue(30);
q.isFull();
q.deQueue();
q.enQueue(40);
q.Front();
q.Rear();
```

**Output:**
```text
true
true
true
true
true
true
20
40
```

## Approach: Circular Array

We use an array (implemented using `vector`) to store elements and four variables:

- `front` – Stores the index of the first element.
- `rear` – Stores the index of the last element.
- `capacity` – Maximum size of the queue.
- `count` – Current number of elements.

Initially:
```cpp
front = -1;
rear = -1;
count = 0;
```

### Important Formula

To move the rear or front circularly:

```cpp
(rear + 1) % capacity
(front + 1) % capacity
```

The modulo operator (`%`) helps us return to index `0` after reaching the last index.

## Algorithm

### 1. Enqueue
1. Check whether the queue is full.
2. If empty, set `front` and `rear` to `0`.
3. Otherwise, move rear using `(rear + 1) % capacity`.
4. Insert the new element.
5. Increase `count`.

### 2. Dequeue
1. Check whether the queue is empty.
2. If only one element exists, reset `front` and `rear` to `-1`.
3. Otherwise, move front using `(front + 1) % capacity`.
4. Decrease `count`.

### 3. Front
- If the queue is empty, return `-1`.
- Otherwise, return `arr[front]`.

### 4. Rear
- If the queue is empty, return `-1`.
- Otherwise, return `arr[rear]`.

### 5. isEmpty
- Return `true` if `count == 0`.

### 6. isFull
- Return `true` if `count == capacity`.

## Dry Run

Consider capacity = 3.

| Operation | Queue (Array) | Front | Rear | Count |
|---|---|---:|---:|---:|
| Initial | [_, _, _] | -1 | -1 | 0 |
| Enqueue(10) | [10, _, _] | 0 | 0 | 1 |
| Enqueue(20) | [10, 20, _] | 0 | 1 | 2 |
| Enqueue(30) | [10, 20, 30] | 0 | 2 | 3 |
| Dequeue() | [10, 20, 30] | 1 | 2 | 2 |
| Enqueue(40) | [40, 20, 30] | 1 | 0 | 3 |

Notice that after inserting 40, rear moves from index `2` to index `0`.

This is called **Circular Wrapping**.

## Time and Space Complexity

| Operation | Time Complexity |
|---|---|
| enQueue() | O(1) |
| deQueue() | O(1) |
| Front() | O(1) |
| Rear() | O(1) |
| isEmpty() | O(1) |
| isFull() | O(1) |

**Space Complexity:** O(k), where k is the capacity of the queue.

## Key Concepts Learned

- Circular Queue
- FIFO Principle
- Array Implementation
- Front and Rear Pointers
- Modulo Operator (`%`)
- Circular Wrapping
- Queue Overflow and Underflow
- Class and Constructor in C++
- Time and Space Complexity

## Language
C++

## LeetCode Status
- [ ] Solved on LeetCode
- [x] Practiced using C++ with `main()` function

## Progress
**Q06 – Design Circular Queue: Practiced**


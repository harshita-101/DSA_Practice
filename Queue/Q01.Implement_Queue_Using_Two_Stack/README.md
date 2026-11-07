# Q01. Implement Queue Using Two Stacks

## Problem Statement

**Problem:** Implement a First In First Out (FIFO) Queue using two stacks.

The implemented queue should support the following operations:

- `push(x)` – Insert an element into the queue.
- `pop()` – Remove the element from the front of the queue.
- `peek()` – Return the front element.
- `empty()` – Check whether the queue is empty.

## Example

**Input:**
```text
push(10)
push(20)
push(30)
peek()
pop()
peek()
empty()
```

**Output:**
```text
10
10
20
false
```

**Explanation:**

1. Insert 10, 20 and 30 into the queue.
2. `peek()` returns 10.
3. `pop()` removes 10.
4. `peek()` now returns 20.
5. The queue is not empty.

---

## Approach: Using Two Stacks (Push Costly)

We use two stacks, `s1` and `s2`, to implement a queue.

- **Push(x):**
  - Move all elements from `s1` to `s2`.
  - Push the new element into `s1`.
  - Move all elements back from `s2` to `s1`.

- **Pop():**
  - Remove the top element from `s1`.

- **Peek():**
  - Return the top element of `s1`.

- **Empty():**
  - Check whether `s1` is empty.

**Important:** We reverse the elements during insertion so that the oldest element always stays at the top of `s1`.

---

## Algorithm

1. Create two empty stacks, `s1` and `s2`.
2. For the push operation:
   - Transfer all elements from `s1` to `s2`.
   - Insert the new element into `s1`.
   - Transfer all elements back to `s1`.
3. For the pop operation:
   - Return and remove the top element of `s1`.
4. For the peek operation:
   - Return the top element of `s1`.
5. For the empty operation:
   - Return whether `s1` is empty.

---

## Dry Run

Consider the operations:

```text
push(10)
push(20)
push(30)
pop()
```

| Operation | Stack s1 (Bottom → Top) |
|---|---|
| push(10) | [10] |
| push(20) | [20, 10] |
| push(30) | [30, 20, 10] |
| pop() | [30, 20] |

**Final Answer:** 10 is removed from the queue.

---

## Code (C++)

```cpp
#include<iostream>
#include<stack>
using namespace std;

class MyQueue {
public:
    stack<int> s1;
    stack<int> s2;

    MyQueue() {
        
    }
    
    void push(int x) {
        while(!s1.empty()){
            s2.push(s1.top());
            s1.pop();
        }

        s1.push(x);

        while(!s2.empty()){
            s1.push(s2.top());
            s2.pop();
        }
    }
    
    int pop() {
        int ans = s1.top();
        s1.pop();
        return ans;
    }
    
    int peek() {
        return s1.top();
    }
    
    bool empty() {
        return s1.empty();
    }
};
```

---

## Complexity Analysis

Let `n` be the number of elements in the queue.

- **Push:** O(n) – Elements are transferred between two stacks.
- **Pop:** O(1) – Removes the top element from `s1`.
- **Peek:** O(1) – Returns the top element of `s1`.
- **Empty:** O(1) – Checks whether `s1` is empty.
- **Space Complexity:** O(n) – Two stacks store the queue elements.

---

## Key Concepts

- Queue (FIFO)
- Stack (LIFO)
- C++ STL Stack
- Implementing Queue using Two Stacks
- Push Costly Approach
- Time and Space Complexity

---

## Language

C++

## LeetCode

[Implement Queue using Stacks – LeetCode 232](https://leetcode.com/problems/implement-queue-using-stacks/)

## Status

✅ Solved
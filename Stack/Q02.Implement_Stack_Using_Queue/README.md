# Implement Stack Using Queues

## Problem Statement

Implement a **Last In, First Out (LIFO)** stack using only a single queue. The implemented stack should support all the functions of a normal stack.

Implement the `MyStack` class:

- `push(x)`: Pushes element `x` onto the stack.
- `pop()`: Removes and returns the top element of the stack.
- `top()`: Returns the top element without removing it.
- `empty()`: Returns `true` if the stack is empty, otherwise `false`.

**LeetCode:** 225  
**Difficulty:** Easy

---

## Example

### Example 1

**Input:**
```text
push(1)
push(2)
push(3)
top()
pop()
top()
empty()
```

**Output:**
```text
3
3
2
false
```

**Explanation:**

- `push(1)`, `push(2)`, and `push(3)` insert the elements into the stack.
- `top()` returns `3`, the most recently inserted element.
- `pop()` removes and returns `3`.
- `top()` now returns `2`.
- `empty()` returns `false` because the stack still contains elements.

---

## Approach

This problem can be solved using a **single queue**.

A queue follows the FIFO (First In, First Out) principle, whereas a stack follows the LIFO (Last In, First Out) principle.

To implement stack behavior, rearrange the queue after every insertion so that the newest element always stays at the front.

- Insert the new element into the queue using `push()`.
- Store the queue's current size.
- Move all previously inserted elements from the front to the rear of the queue.
- The newest element will now be at the front.
- Use `front()` to access the stack's top element.
- Use `pop()` to remove the front element.

This approach makes `pop()`, `top()`, and `empty()` efficient.

---

## Algorithm

1. Initialize an empty queue.
2. For `push(x)`:
   - Insert `x` into the queue.
   - Store the current queue size in a variable.
   - Rotate the previous elements by moving them from the front to the rear.
3. For `pop()`:
   - Store the front element.
   - Remove it from the queue.
   - Return the stored element.
4. For `top()`:
   - Return the front element.
5. For `empty()`:
   - Return whether the queue is empty.

---

## Dry Run

Consider the following operations:

```text
push(1)
push(2)
push(3)
```

### Step 1: Push 1

Insert `1` into the queue.

```text
Front → [1] ← Rear
```

### Step 2: Push 2

Insert `2`.

```text
Front → [1, 2] ← Rear
```

Rotate the previous element `1` to the rear.

```text
Front → [2, 1] ← Rear
```

### Step 3: Push 3

Insert `3`.

```text
Front → [2, 1, 3] ← Rear
```

Rotate the previous elements to the rear.

```text
Front → [3, 2, 1] ← Rear
```

Now the newest element is always at the front.

### Step 4: Pop

Remove the front element.

```text
Popped: 3

Front → [2, 1] ← Rear
```

**Final top element:** `2`

---

## Code

```cpp
#include <iostream>
#include <queue>
using namespace std;

class MyStack {
public:
    queue<int> q;

    MyStack() {
    }

    void push(int x) {
        q.push(x);

        int n = q.size();

        for (int i = 0; i < n - 1; i++) {
            q.push(q.front());
            q.pop();
        }
    }

    int pop() {
        int temp = q.front();
        q.pop();
        return temp;
    }

    int top() {
        return q.front();
    }

    bool empty() {
        return q.empty();
    }
};

int main() {
    MyStack st;

    st.push(1);
    st.push(2);
    st.push(3);

    cout << "Top element: " << st.top() << endl;
    cout << "Popped element: " << st.pop() << endl;
    cout << "Top element after pop: " << st.top() << endl;
    cout << "Is stack empty? "
         << (st.empty() ? "Yes" : "No") << endl;

    return 0;
}
```

---

## Complexity

- **Time Complexity of `push()`:** O(n), because existing elements are rotated.
- **Time Complexity of `pop()`:** O(1).
- **Time Complexity of `top()`:** O(1).
- **Time Complexity of `empty()`:** O(1).
- **Space Complexity:** O(n), for storing `n` elements in the queue.

Where `n` represents the number of elements in the stack.

---

## Key Concepts

- Stack and Queue
- LIFO and FIFO Principles
- Queue Rotation
- Class and Object Implementation
- Data Structure Design
- Time and Space Complexity Analysis

---

## Language

C++

## LeetCode

[225. Implement Stack using Queues](https://leetcode.com/problems/implement-stack-using-queues/)

## Status

✅ Solved

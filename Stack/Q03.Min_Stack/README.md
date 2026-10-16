# Q03. Min Stack

## Problem Statement

**LeetCode Problem:** [Min Stack](https://leetcode.com/problems/min-stack/)  
**Difficulty:** Medium

Design a stack that supports the following operations in **O(1) time complexity**:

- `push(val)`: Push an element onto the stack.
- `pop()`: Remove the top element from the stack.
- `top()`: Get the top element.
- `getMin()`: Retrieve the minimum element in the stack.

---

## Example

**Input:**
```text
push(-2)
push(0)
push(-3)
getMin()
pop()
top()
getMin()
```

**Output:**
```text
-3
0
-2
```

**Explanation:**
1. Push `-2`, `0`, and `-3` onto the stack.
2. `getMin()` returns `-3`, the minimum element.
3. `pop()` removes `-3`.
4. `top()` returns `0`.
5. `getMin()` returns `-2`.

---

## Approach: Using Two Stacks

We use two stacks:

1. **Main Stack (`st`)**: Stores all the elements.
2. **Minimum Stack (`minSt`)**: Stores the minimum elements.

Whenever we push an element:
- Push it into the main stack.
- If the minimum stack is empty or the new element is less than or equal to its top, push it into the minimum stack as well.

Whenever we pop an element:
- If the top element of the main stack equals the top element of the minimum stack, pop from the minimum stack too.
- Then pop from the main stack.

The minimum element is always available at the top of `minSt`.

---

## Algorithm

### Push Operation
1. Push the value into `st`.
2. If `minSt` is empty or the value is less than or equal to `minSt.top()`, push the value into `minSt`.

### Pop Operation
1. Check whether the top elements of `st` and `minSt` are equal.
2. If they are equal, pop from `minSt`.
3. Pop from `st`.

### Top Operation
Return `st.top()`.

### Get Minimum Operation
Return `minSt.top()`.

---

## Dry Run

Consider the following operations:

| Operation | Main Stack (`st`) | Minimum Stack (`minSt`) | Minimum |
|---|---|---|---|
| `push(-2)` | `[-2]` | `[-2]` | -2 |
| `push(0)` | `[-2, 0]` | `[-2]` | -2 |
| `push(-3)` | `[-2, 0, -3]` | `[-2, -3]` | -3 |
| `getMin()` | `[-2, 0, -3]` | `[-2, -3]` | -3 |
| `pop()` | `[-2, 0]` | `[-2]` | -2 |
| `top()` | `[-2, 0]` | `[-2]` | -2 |
| `getMin()` | `[-2, 0]` | `[-2]` | -2 |

**Note:** The bottom of each stack is shown on the left, and the top is shown on the right.

---

## Code (C++)

```cpp
#include <iostream>
#include <stack>
using namespace std;

class MinStack {
public:
    stack<int> st;
    stack<int> minSt;

    MinStack() {
    }

    void push(int value) {
        st.push(value);

        if (minSt.empty() || value <= minSt.top()) {
            minSt.push(value);
        }
    }

    void pop() {
        if (st.top() == minSt.top()) {
            minSt.pop();
        }

        st.pop();
    }

    int top() {
        return st.top();
    }

    int getMin() {
        return minSt.top();
    }
};

```

---

## Complexity Analysis

| Operation | Time Complexity |
|---|---|
| `push()` | O(1) |
| `pop()` | O(1) |
| `top()` | O(1) |
| `getMin()` | O(1) |

**Space Complexity:** O(n), where `n` is the number of elements stored in the stacks.

---

## Key Concepts

- Stack
- STL Stack in C++
- Auxiliary Stack
- Constant-Time Minimum Retrieval
- Time and Space Complexity

---

## Language

C++

## LeetCode

[Min Stack – LeetCode 155](https://leetcode.com/problems/min-stack/)

## Status

✅ Solved
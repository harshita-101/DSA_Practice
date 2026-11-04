# Q13. Validate Stack Sequences

**LeetCode Problem:** [946. Validate Stack Sequences](https://leetcode.com/problems/validate-stack-sequences/)  
**Difficulty:** Medium  
**Topics:** Array, Stack, Simulation

---

## Problem Statement

Given two integer arrays `pushed` and `popped`, each with distinct values, return `true` if this could have been the result of a sequence of push and pop operations on an initially empty stack, or `false` otherwise.

We are given:
- `pushed`: The order in which elements are pushed into the stack.
- `popped`: The required order in which elements should be popped from the stack.

We need to check whether the given `popped` sequence is possible using a stack.

## Examples

**Example 1:**

Input:
```text
pushed = [1,2,3,4,5]
popped = [4,5,3,2,1]
```

Output:
```text
true
```

Explanation:

- Push 1, 2, 3, 4.
- Pop 4.
- Push 5.
- Pop 5, 3, 2, 1.

The popped sequence matches the required order, so the answer is `true`.

**Example 2:**

Input:
```text
pushed = [1,2,3,4,5]
popped = [4,3,5,1,2]
```

Output:
```text
false
```

Explanation:

After popping 4, 3 and 5, the stack contains `[1,2]` with 2 at the top.

But the next required element is 1. We cannot pop 1 before 2.

Therefore, the sequence is invalid.

---

## Approach: Stack Simulation

We use a stack to simulate the push and pop operations.

### What We Store in the Stack

The stack stores elements from the `pushed` array.

We also maintain a variable `j` to track the current position in the `popped` array.

### Algorithm

1. Create an empty stack.
2. Initialize `j = 0`.
3. Traverse the `pushed` array.
4. Push the current element into the stack.
5. Check whether the stack is empty or its top element matches `popped[j]`.
6. If both conditions allow a pop:
   - Pop the top element.
   - Increment `j`.
7. Continue until all elements from `pushed` are processed.
8. Finally, check:
   - The stack should be empty.
   - All elements of `popped` should be processed (`j == popped.size()`).
9. If both conditions are true, return `true`; otherwise, return `false`.

### Why Do We Use a While Loop?

We use a `while` loop instead of an `if` statement because multiple consecutive elements may need to be popped after a single push.

For example:

```text
pushed = [1,2,3,4,5]
popped = [4,5,3,2,1]
```

After pushing 5, we can pop:

```text
5 → 3 → 2 → 1
```

So, we must keep checking the stack's top until it no longer matches the next required popped element.

---

## C++ Solution

```cpp
#include<iostream>
#include<vector>
#include<stack>
using namespace std;

bool validateStackSequences(vector<int>& pushed, vector<int>& popped) {
    stack<int> st;
    int j = 0;

    for(int i=0; i<pushed.size(); i++){
        st.push(pushed[i]);

        while(!st.empty() && st.top() == popped[j]){
            st.pop();
            j++;
        }
    }

    if(st.empty() && j == popped.size()){
        return true;
    }

    return false;
}

```

**Note:** For LeetCode submission, use the `Solution` class and omit the `main()` function.

---

## Complexity Analysis

Let `n` be the number of elements in the `pushed` array.

| Complexity | Value | Explanation |
|---|---|---|
| Time Complexity | O(n) | Each element is pushed once and popped at most once. |
| Space Complexity | O(n) | In the worst case, the stack can store all n elements. |

---

## Key Concepts Learned

- Stack operations: `push()`, `pop()`, `top()`, `empty()`.
- Simulating push and pop sequences.
- Using a separate pointer to track another array.
- Using a `while` loop for consecutive pop operations.
- Understanding LIFO (Last In, First Out).
- Validating a sequence using stack conditions.

---


**Language:** C++  
**Status:** Solved ✅
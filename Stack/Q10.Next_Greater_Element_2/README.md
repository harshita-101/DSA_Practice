# Q20 — Next Greater Element II

**LeetCode:** [503. Next Greater Element II](https://leetcode.com/problems/next-greater-element-ii/)  
**Difficulty:** Medium  
**Topic:** Stack, Monotonic Stack, Circular Array

---

## 📌 Problem Statement

Given a **circular integer array** `nums`, return an array `ans` such that `ans[i]` is the next greater number for `nums[i]`.

The next greater number of an element is the first number greater than it when traversing the array in the forward direction.

Since the array is circular, after reaching the last element, we continue searching from the beginning.

If no greater element exists, return `-1` for that position.

### Example 1

**Input:**
```text
nums = [1, 2, 1]
```

**Output:**
```text
[2, -1, 2]
```

**Explanation:**
- For `nums[0] = 1`, the next greater element is `2`.
- For `nums[1] = 2`, no greater element exists, so the answer is `-1`.
- For `nums[2] = 1`, we wrap around to the beginning and find `2`.

### Example 2

**Input:**
```text
nums = [1, 2, 3, 4, 3]
```

**Output:**
```text
[2, 3, 4, -1, 4]
```

---

## 💡 Approach: Monotonic Stack

A simple approach would be to check every element against the elements that follow it, including the circular portion. However, this would take **O(n²)** time.

We can solve the problem more efficiently using a **monotonic stack**.

### Step 1: Initialize the answer array

Create an answer array of size `n` and initialize every element to `-1`.

This handles elements that have no next greater element.

### Step 2: Traverse the array twice

Since the array is circular, we simulate two traversals using:

```cpp
for (int i = 2*n - 1; i >= 0; i--)
```

We use `i % n` to access the actual array index.

This lets us consider elements from the beginning of the array when searching for the next greater element of an element near the end.

### Step 3: Remove smaller or equal elements

Before finding the next greater element, remove indices from the stack while the corresponding values are smaller than or equal to the current value.

```cpp
while (!s.empty() && nums[s.top()] <= nums[i % n]) {
    s.pop();
}
```

Why?

A smaller or equal value cannot be the next greater element for the current element.

### Step 4: Find the answer

- If the stack is empty, no greater element is available, so the answer is `-1`.
- Otherwise, the value at the index on top of the stack is the next greater element.

### Step 5: Push the current index

Push the current index onto the stack so it can help determine the next greater element for earlier positions.

**Important:** The stack stores indices, not values.

---

## 💻 C++ Solution

```cpp
#include <iostream>
#include <vector>
#include <stack>
using namespace std;

vector<int> nextGreaterElements(vector<int>& nums) {
    int n = nums.size();

    vector<int> ans(n, -1);
    stack<int> s;

    for (int i = 2 * n - 1; i >= 0; i--) {
        while (!s.empty() && nums[s.top()] <= nums[i % n]) {
            s.pop();
        }

        ans[i % n] = s.empty() ? -1 : nums[s.top()];

        s.push(i % n);
    }

    return ans;
}

```

---

## 🔍 Dry Run

**Input:**

```text
nums = [1, 2, 1]
```

Initially:

```text
ans = [-1, -1, -1]
stack = empty
```

The loop begins at `i = 5` and ends at `i = 0`.

| `i` | `i % n` | Current Value | Action |
|---:|---:|---:|---|
| 5 | 2 | 1 | Push index 2 |
| 4 | 1 | 2 | Pop index 2; no greater element remains. Set `ans[1] = -1`, then push index 1 |
| 3 | 0 | 1 | Stack top is value 2. Set `ans[0] = 2`, then push index 0 |
| 2 | 2 | 1 | Pop index 0 because its value is 1; set `ans[2] = 2`, then push index 2 |
| 1 | 1 | 2 | Pop smaller or equal values; set `ans[1] = -1`, then push index 1 |
| 0 | 0 | 1 | Stack top is value 2. Set `ans[0] = 2`, then push index 0 |

Final result:

```text
[2, -1, 2]
```

The same answer positions may be assigned more than once during the two traversals, but the final result remains correct.

---

## 🧠 Why Do We Traverse Twice?

Consider:

```text
nums = [1, 2, 1]
```

The last `1` has no greater element to its right in a normal, non-circular traversal. However, because the array is circular, we can continue from the beginning and find `2`.

Traversing twice allows us to consider these wraparound elements without physically modifying the array.

The modulo operator:

```cpp
i % n
```

maps the loop index back to a valid array index.

---

## 📚 Important Concepts

### 1. Circular Array

A circular array allows traversal to continue from the beginning after reaching the end.

### 2. Monotonic Stack

A monotonic stack maintains a useful order of elements. Here, we remove smaller or equal values so that the top can provide the next greater element.

### 3. Store Indices Instead of Values

Storing indices lets us access the corresponding array values and place answers in the correct positions.

### 4. Initialize Answers with `-1`

If an element has no greater element, its answer remains `-1`.

---

## ⏱️ Complexity Analysis

**Time Complexity: O(n)**

Although the loop runs `2n` times, each iteration performs constant work apart from stack operations. Each index can be pushed and popped only a constant number of times across the traversal, so the overall time complexity is linear.

**Space Complexity: O(n)**

The answer vector and stack can each hold up to `n` elements.

---

## ⚖️ Brute Force vs. Optimized Approach

| Approach | Time Complexity | Space Complexity |
|---|---|---|
| Brute Force | O(n²) | O(n) for the answer |
| Monotonic Stack | O(n) | O(n) |

The monotonic stack avoids repeatedly scanning the array for each element.

---

## Language

C++

## Status

✅ Solved



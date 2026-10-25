# Q21 — Trapping Rain Water

**LeetCode:** [42. Trapping Rain Water](https://leetcode.com/problems/trapping-rain-water/)  
**Difficulty:** Hard  
**Topics:** Arrays, Prefix Maximum, Suffix Maximum

---

## 📌 Problem Statement

Given an array `height` where each element represents the height of a vertical bar, calculate how much rainwater can be trapped between the bars after it rains.

Each bar has a width of `1`.

### Example 1

**Input:**
```text
height = [0,1,0,2,1,0,1,3,2,1,2,1]
```

**Output:**
```text
6
```

**Explanation:**

The bars form several containers that trap a total of 6 units of rainwater.

### Example 2

**Input:**
```text
height = [4,2,0,3,2,5]
```

**Output:**
```text
9
```

---

## 💡 Approach: Left Maximum and Right Maximum

The main idea is that the amount of water trapped above a bar depends on the tallest bars to its left and right.

For each index `i`:

```text
Water trapped = min(leftMax[i], rightMax[i]) - height[i]
```

Where:
- `leftMax[i]` is the maximum height from index `0` to index `i`.
- `rightMax[i]` is the maximum height from index `i` to the last index.
- `height[i]` is the height of the current bar.

We use the smaller of the two maximum heights because water spills over the shorter boundary.

### Step 1: Handle an Empty Array

If the array has no elements, return `0`.

### Step 2: Create Two Arrays

Create:
- `leftMax` to store the tallest bar encountered from the left.
- `rightMax` to store the tallest bar encountered from the right.

### Step 3: Calculate Left Maximums

Initialize the first element:

```cpp
leftMax[0] = height[0];
```

Traverse from left to right. At each position, store the greater of the previous maximum and the current height.

```cpp
leftMax[i] = max(leftMax[i - 1], height[i]);
```

### Step 4: Calculate Right Maximums

Initialize the last element:

```cpp
rightMax[n - 1] = height[n - 1];
```

Traverse from right to left and store the maximum height seen so far.

```cpp
rightMax[i] = max(rightMax[i + 1], height[i]);
```

### Step 5: Calculate Trapped Water

For each index, calculate the water above the bar:

```cpp
min(leftMax[i], rightMax[i]) - height[i]
```

Add these values to `ans` to get the total amount of trapped rainwater.

---

## 💻 C++ Solution

```cpp
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int trap(vector<int>& height) {
    int n = height.size();

    if (n == 0) return 0;

    vector<int> leftMax(n), rightMax(n);

    leftMax[0] = height[0];
    rightMax[n - 1] = height[n - 1];

    for (int i = 1; i < n; i++) {
        leftMax[i] = max(leftMax[i - 1], height[i]);
    }

    for (int i = n - 2; i >= 0; i--) {
        rightMax[i] = max(rightMax[i + 1], height[i]);
    }

    int ans = 0;

    for (int i = 0; i < n; i++) {
        ans += min(leftMax[i], rightMax[i]) - height[i];
    }

    return ans;
}
---

## 🔍 Dry Run

Consider the input:

```text
height = [4, 2, 0, 3, 2, 5]
```

### Step 1: Calculate `leftMax`

```text
height = [4, 2, 0, 3, 2, 5]
leftMax = [4, 4, 4, 4, 4, 5]
```

At each index, `leftMax` stores the tallest bar encountered from the beginning.

### Step 2: Calculate `rightMax`

```text
height  = [4, 2, 0, 3, 2, 5]
rightMax = [5, 5, 5, 5, 5, 5]
```

At each index, `rightMax` stores the tallest bar from that position to the end.

### Step 3: Calculate Water at Each Index

| Index | Height | Left Max | Right Max | Water Trapped |
|---:|---:|---:|---:|---:|
| 0 | 4 | 4 | 5 | `min(4,5) - 4 = 0` |
| 1 | 2 | 4 | 5 | `min(4,5) - 2 = 2` |
| 2 | 0 | 4 | 5 | `min(4,5) - 0 = 4` |
| 3 | 3 | 4 | 5 | `min(4,5) - 3 = 1` |
| 4 | 2 | 4 | 5 | `min(4,5) - 2 = 2` |
| 5 | 5 | 5 | 5 | `min(5,5) - 5 = 0` |

### Final Answer

```text
Total water = 0 + 2 + 4 + 1 + 2 + 0
            = 9 units
```

---

## 🧠 Important Concepts

### 1. Prefix Maximum

`leftMax[i]` stores the maximum height from the beginning of the array up to index `i`.

### 2. Suffix Maximum

`rightMax[i]` stores the maximum height from index `i` to the end of the array.

### 3. Why Do We Use `min(leftMax[i], rightMax[i])`?

Water can only rise as high as the shorter boundary. If the left boundary is `4` and the right boundary is `5`, the water level cannot exceed `4`.

### 4. Why Subtract `height[i]`?

The bar itself already occupies some height. We subtract that height to calculate only the empty space that can hold water.

---

## ⏱️ Complexity Analysis

Let `n` be the number of bars.

**Time Complexity: O(n)**

We traverse the array three times:
1. Calculate `leftMax`.
2. Calculate `rightMax`.
3. Calculate the total trapped water.

Each traversal takes `O(n)` time, so the overall time complexity is `O(n)`.

**Space Complexity: O(n)**

The `leftMax` and `rightMax` arrays each store `n` elements.

---

## ⚖️ Approach Comparison

| Approach | Time Complexity | Auxiliary Space |
|---|---|---|
| Brute Force | O(n²) | O(1) |
| Prefix/Suffix Maximum Arrays | O(n) | O(n) |
| Two Pointers | O(n) | O(1) |

The current solution is easy to understand because it calculates the maximum boundaries explicitly. A two-pointer approach can solve the problem in linear time with constant auxiliary space.

---

## 🔗 Connection to Previous Questions

This problem reinforces array traversal and maximum-value tracking.

Unlike **Next Greater Element II**, which uses a monotonic stack, this solution uses two auxiliary arrays to store maximum heights.

The key lesson is that different problems may require different techniques even when both involve finding boundaries around an element.

---


## Language

C++

## Status

✅ Solved

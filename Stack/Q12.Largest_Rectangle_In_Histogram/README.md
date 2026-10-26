# Q22 — Largest Rectangle in Histogram

**LeetCode:** [84. Largest Rectangle in Histogram](https://leetcode.com/problems/largest-rectangle-in-histogram/)  
**Difficulty:** Hard  
**Topics:** Array, Stack, Monotonic Stack

---

## 📌 Problem Statement

Given an array of integers `heights`, where each element represents the height of a histogram bar and each bar has a width of `1`, find the **area of the largest rectangle** that can be formed within the histogram.

A rectangle can cover one or more consecutive bars. Its height cannot exceed the height of the shortest bar it covers.

### Example 1

**Input:**
```text
heights = [2,1,5,6,2,3]
```

**Output:**
```text
10
```

**Explanation:**

The bars with heights `5` and `6` can form a rectangle with:
- Height = `5`
- Width = `2`
- Area = `5 × 2 = 10`

### Example 2

**Input:**
```text
heights = [2,4]
```

**Output:**
```text
4
```

**Explanation:**

The largest rectangle has height `2` and width `2`, giving an area of `4`.

---

## 💡 Approach: Monotonic Stack

The main idea is to calculate the largest rectangle for every bar, treating that bar's height as the rectangle's height.

For each bar, we need to find:

- **Left boundary:** The index of the nearest bar to the left that is strictly shorter.
- **Right boundary:** The index of the nearest bar to the right that is strictly shorter.

Once these boundaries are known, we can calculate the maximum width and area for that bar.

### Formula

```text
Width = right[i] - left[i] - 1

Area = heights[i] × Width
```

We subtract `1` from the width because the boundary bars themselves are shorter and cannot be included in the rectangle.

### Step 1: Initialize the Arrays

Create two arrays:

- `left` stores the index of the nearest smaller bar on the left.
- `right` stores the index of the nearest smaller bar on the right.

Initialize `ans = 0` to track the maximum area.

### Step 2: Find the Right Boundaries

Traverse the histogram from right to left.

For each bar:
1. Remove indices from the stack while their heights are greater than or equal to the current height.
2. If the stack is empty, set `right[i] = n`.
3. Otherwise, the top index gives the nearest smaller bar on the right.
4. Push the current index.

The condition used is:

```cpp
heights[s.top()] >= heights[i]
```

We remove equal-height bars too, ensuring that the remaining top represents a strictly smaller bar.

### Step 3: Find the Left Boundaries

Traverse from left to right using the same stack approach.

For each bar:
1. Remove indices whose heights are greater than or equal to the current height.
2. If the stack is empty, set `left[i] = -1`.
3. Otherwise, the top index gives the nearest smaller bar on the left.
4. Push the current index.

**Important:** Clear the stack before this traversal. Otherwise, indices from the right-boundary traversal may affect the left-boundary results.

Your current code already does this correctly because the stack becomes empty after the first traversal finishes processing every index and pushing it.

### Step 4: Calculate the Maximum Area

For every bar, calculate its width and area:

```cpp
int width = right[i] - left[i] - 1;
int currArea = heights[i] * width;
ans = max(ans, currArea);
```

Return `ans` after processing all bars.

---

## 💻 C++ Solution

```cpp
#include <iostream>
#include <vector>
#include <stack>
#include <algorithm>
using namespace std;

int largestRectangleArea(vector<int>& heights) {
    int n = heights.size();

    stack<int> s;
    vector<int> left(n, 0);
    vector<int> right(n, 0);

    int ans = 0;

    // Find the nearest smaller element on the right
    for (int i = n - 1; i >= 0; i--) {
        while (!s.empty() && heights[s.top()] >= heights[i]) {
            s.pop();
        }

        right[i] = s.empty() ? n : s.top();
        s.push(i);
    }

    // Clear the stack before finding left boundaries
    while (!s.empty()) {
        s.pop();
    }

    // Find the nearest smaller element on the left
    for (int i = 0; i < n; i++) {
        while (!s.empty() && heights[s.top()] >= heights[i]) {
            s.pop();
        }

        left[i] = s.empty() ? -1 : s.top();
        s.push(i);
    }

    // Calculate the maximum rectangle area
    for (int i = 0; i < n; i++) {
        int width = right[i] - left[i] - 1;
        int currArea = heights[i] * width;

        ans = max(ans, currArea);
    }

    return ans;
}

```

---

## 🔍 Dry Run

Consider the input:

```text
heights = [2,1,5,6,2,3]
```

### Step 1: Find the Left and Right Boundaries

| Index | Height | Left Boundary | Right Boundary |
|---:|---:|---:|---:|
| 0 | 2 | -1 | 1 |
| 1 | 1 | -1 | 6 |
| 2 | 5 | 1 | 4 |
| 3 | 6 | 2 | 4 |
| 4 | 2 | 1 | 6 |
| 5 | 3 | 4 | 6 |

Here:
- `-1` means no smaller bar exists on the left.
- `6` means no smaller bar exists on the right, since the array length is `6`.

### Step 2: Calculate the Area for Each Bar

| Index | Height | Left | Right | Width | Area |
|---:|---:|---:|---:|---:|---:|
| 0 | 2 | -1 | 1 | 1 | 2 |
| 1 | 1 | -1 | 6 | 6 | 6 |
| 2 | 5 | 1 | 4 | 2 | 10 |
| 3 | 6 | 2 | 4 | 1 | 6 |
| 4 | 2 | 1 | 6 | 4 | 8 |
| 5 | 3 | 4 | 6 | 1 | 3 |

### Final Answer

```text
Maximum Area = 10
```

The largest rectangle is formed by the bars with heights `5` and `6`.

Its height is `5`, its width is `2`, and its area is `10`.

---

## 🧠 Important Concepts

### 1. Monotonic Stack

A monotonic stack maintains an order among the elements represented by its indices.

Here, we remove elements with heights greater than or equal to the current height so that the top identifies the nearest strictly smaller bar.

### 2. Nearest Smaller Element

The largest rectangle for a bar extends until a shorter bar is encountered on either side.

Finding the nearest smaller bars tells us how far the rectangle can extend.

### 3. Why Store Indices?

We need the positions of the boundaries to calculate the rectangle's width.

Storing only the heights would not provide enough information to determine that width.

### 4. Why Use `n` and `-1`?

If no smaller bar exists on the right, we use `n`.

If no smaller bar exists on the left, we use `-1`.

These sentinel values make the width formula work even when a rectangle extends to either end of the histogram.

### 5. Why Pop Equal Heights?

The condition:

```cpp
heights[s.top()] >= heights[i]
```

removes bars that are taller than or equal to the current bar.

This allows the current bar to extend across equal-height bars and helps determine the maximum possible width.

---

## ⏱️ Complexity Analysis

Let `n` be the number of bars.

**Time Complexity: O(n)**

We traverse the array twice to find the boundaries and once to calculate the areas.

Although the loops contain `while` loops, each index is pushed onto and popped from the stack at most once per boundary calculation. Therefore, the overall time complexity is linear.

**Space Complexity: O(n)**

The `left` and `right` arrays each require `O(n)` space, and the stack can also hold up to `n` indices.

---

## ⚖️ Approach Comparison

| Approach | Time Complexity | Auxiliary Space |
|---|---|---|
| Brute Force | O(n²) | O(1) |
| Precompute Left and Right Boundaries | O(n) | O(n) |
| Single-Pass Monotonic Stack | O(n) | O(n) |

The current approach is easier to understand because it separates boundary calculation from area calculation.



---

## Language

C++

## Status

✅ Solved

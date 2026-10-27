## 📌 Problem Statement

Given an array of integers `arr`, find the sum of the minimum element of every contiguous subarray.

Since the answer can be very large, return it modulo `10^9 + 7`.

### Example 1

**Input:**
```text
arr = [3,1,2,4]
```

**Output:**
```text
17
```

**Explanation:**

All contiguous subarrays and their minimums are:

| Subarray | Minimum |
|---|---:|
| `[3]` | 3 |
| `[1]` | 1 |
| `[2]` | 2 |
| `[4]` | 4 |
| `[3,1]` | 1 |
| `[1,2]` | 1 |
| `[2,4]` | 2 |
| `[3,1,2]` | 1 |
| `[1,2,4]` | 1 |
| `[3,1,2,4]` | 1 |

The sum of all minimums is:

`3 + 1 + 2 + 4 + 1 + 1 + 2 + 1 + 1 + 1 = 17`

### Example 2

**Input:**
```text
arr = [11,81,94,43,3]
```

**Output:**
```text
444
```

---

## 💡 Approach: Monotonic Stack + Contribution Technique

The main idea is to calculate how much each element contributes to the final answer.

Instead of generating every possible subarray and finding its minimum, we determine the number of subarrays in which each element acts as the minimum.

For every element, we find:

- **Previous Smaller Element:** The nearest strictly smaller element on the left.
- **Next Smaller-or-Equal Element:** The nearest smaller-than-or-equal element on the right.

These boundaries help us calculate the number of subarrays in which the current element is the selected minimum.

### Formula

For each index `i`:

```text
left  = i - prev[i]
right = next[i] - i

Contribution = arr[i] × left × right
```

The final answer is the sum of all contributions modulo `10^9 + 7`.

---

## Step 1: Find the Previous Smaller Element

Create a `prev` array to store the index of the nearest strictly smaller element on the left.

If no such element exists, store `-1`.

Traverse the array from left to right using a monotonic stack.

For every index `i`:

1. While the stack is not empty and `arr[s.top()] >= arr[i]`, pop the stack.
2. If the stack is empty, set `prev[i] = -1`.
3. Otherwise, set `prev[i] = s.top()`.
4. Push the current index onto the stack.

The condition used is:

```cpp
arr[s.top()] >= arr[i]
```

We remove greater-than-or-equal elements because we need the previous **strictly smaller** element.

---

## Step 2: Find the Next Smaller-or-Equal Element

Create a `next` array to store the index of the nearest smaller-than-or-equal element on the right.

If no such element exists, store `n`.

Before starting this traversal, clear the stack.

Traverse the array from right to left.

For every index `i`:

1. While the stack is not empty and `arr[s.top()] > arr[i]`, pop the stack.
2. If the stack is empty, set `next[i] = n`.
3. Otherwise, set `next[i] = s.top()`.
4. Push the current index onto the stack.

The condition used is:

```cpp
arr[s.top()] > arr[i]
```

We use `>` instead of `>=` so that duplicate elements are handled correctly.

**Important:** Using different comparison conditions on the two sides ensures that a subarray containing duplicate minimum values is counted exactly once.

---

## Step 3: Calculate the Number of Subarrays

For every index `i`, calculate the possible starting and ending positions.

### Left Choices

```cpp
left = i - prev[i];
```

This gives the number of possible starting positions for subarrays in which `arr[i]` is the selected minimum.

### Right Choices

```cpp
right = next[i] - i;
```

This gives the number of possible ending positions.

Therefore, the number of subarrays contributed by the current element is:

```text
left × right
```

---

## Step 4: Calculate Each Element's Contribution

If `arr[i]` is the selected minimum in `left × right` subarrays, its total contribution is:

```text
Contribution = arr[i] × left × right
```

Add each contribution to the final sum.

Since the multiplication can exceed the range of a normal integer, use `1LL` to ensure that multiplication is performed using `long long`.

Apply modulo `10^9 + 7` while updating the sum.

---

## 💻 C++ Solution

```cpp
#include <iostream>
#include <vector>
#include <stack>
using namespace std;

int sumSubarrayMins(vector<int> &arr)
{
    int n = arr.size();

    stack<int> s;
    vector<int> prev(n);
    vector<int> next(n);

    // Find Previous Strictly Smaller Element
    for (int i = 0; i < n; i++)
    {
        while (!s.empty() && arr[s.top()] >= arr[i])
        {
            s.pop();
        }

        prev[i] = s.empty() ? -1 : s.top();
        s.push(i);
    }

    // Clear the stack before the next traversal
    while (!s.empty())
    {
        s.pop();
    }

    // Find Next Smaller-or-Equal Element
    for (int i = n - 1; i >= 0; i--)
    {
        while (!s.empty() && arr[s.top()] > arr[i])
        {
            s.pop();
        }

        next[i] = s.empty() ? n : s.top();
        s.push(i);
    }

    long long sum = 0;
    const int mod = 1e9 + 7;

    // Calculate each element's contribution
    for (int i = 0; i < n; i++)
    {
        int left = i - prev[i];
        int right = next[i] - i;

        sum = (sum + (1LL * arr[i] * left * right) % mod) % mod;
    }

    return sum;
}
```

**Note:** The `main()` function is included for local testing. When submitting to LeetCode, use the required `Solution` class and omit `main()`.

---

## 🔍 Dry Run

Consider the input:

```text
arr = [3,1,2]
```

### Step 1: Find Previous and Next Boundaries

| Index | Element | Previous Smaller (`prev`) | Next Smaller-or-Equal (`next`) |
|---:|---:|---:|---:|
| 0 | 3 | -1 | 1 |
| 1 | 1 | -1 | 3 |
| 2 | 2 | 1 | 3 |

Here:
- `-1` means there is no smaller element on the left.
- `n = 3` means there is no smaller-or-equal element on the right.

### Step 2: Calculate the Contribution

| Index | Element | Left Choices | Right Choices | Contribution |
|---:|---:|---:|---:|---:|
| 0 | 3 | `0 - (-1) = 1` | `1 - 0 = 1` | `3 × 1 × 1 = 3` |
| 1 | 1 | `1 - (-1) = 2` | `3 - 1 = 2` | `1 × 2 × 2 = 4` |
| 2 | 2 | `2 - 1 = 1` | `3 - 2 = 1` | `2 × 1 × 1 = 2` |

### Final Answer

```text
Sum = 3 + 4 + 2 = 9
```

Therefore, the output is:

```text
9
```

---

## 🧠 Important Concepts

### 1. Monotonic Stack

A monotonic stack maintains an ordering of elements using their indices.

It helps us find the nearest smaller elements efficiently without repeatedly scanning the array.

### 2. Previous and Next Boundaries

The previous and next boundaries determine how far a subarray can extend while the current element remains its selected minimum.

### 3. Contribution Technique

Instead of calculating the minimum of every subarray, we calculate the total contribution of each element.

This reduces the time complexity from quadratic to linear.

### 4. Why Store Indices?

We need the positions of the boundaries to calculate the number of possible starting and ending positions.

Storing only element values would not be sufficient.

### 5. Why Use `-1` and `n`?

These are sentinel values:

- `-1` indicates that no previous smaller element exists.
- `n` indicates that no next smaller-or-equal element exists.

They allow us to calculate the number of choices using simple subtraction.

### 6. Why Are the Comparisons Different?

For the previous boundary, we pop while:

```cpp
arr[s.top()] >= arr[i]
```

For the next boundary, we pop while:

```cpp
arr[s.top()] > arr[i]
```

This asymmetric treatment of equal elements prevents duplicate counting.

### 7. Why Use `1LL`?

The expression:

```cpp
1LL * arr[i] * left * right
```

converts the multiplication to `long long` arithmetic, helping prevent integer overflow.

### 8. Why Apply Modulo?

The answer may exceed the range of a standard integer.

Taking modulo `10^9 + 7` keeps the result within the required range.

---

## ⏱️ Complexity Analysis

Let `n` be the size of the array.

### Time Complexity: O(n)

- Finding previous smaller elements takes `O(n)`.
- Finding next smaller-or-equal elements takes `O(n)`.
- Calculating contributions takes `O(n)`.

Each index is pushed onto and popped from the stack at most once per traversal.

Therefore, the overall time complexity is **O(n)**.

### Space Complexity: O(n)

The solution uses:
- A stack of indices.
- A `prev` array.
- A `next` array.

Therefore, the auxiliary space complexity is **O(n)**.

---

## ⚖️ Approach Comparison

| Approach | Time Complexity | Auxiliary Space |
|---|---|---|
| Brute Force | O(n²) or more, depending on minimum calculation | O(1) or O(n), depending on implementation |
| Monotonic Stack + Contribution Technique | O(n) | O(n) |

The monotonic stack approach is efficient because it calculates each element's contribution without explicitly generating all subarrays.

---

## 🧪 Important Edge Cases

| Input | Expected Output |
|---|---:|
| `[5]` | 5 |
| `[1,2,3]` | 10 |
| `[3,2,1]` | 10 |
| `[2,2]` | 6 |
| `[3,1,2,4]` | 17 |

These cases test single-element arrays, increasing and decreasing sequences, duplicate values, and a standard example.

---

## Language

C++

## Status

✅ Solved
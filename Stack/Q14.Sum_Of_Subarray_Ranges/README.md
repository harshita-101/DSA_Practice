# Q24 — Sum of Subarray Ranges

**LeetCode:** [2104. Sum of Subarray Ranges](https://leetcode.com/problems/sum-of-subarray-ranges/)  
**Difficulty:** Medium  
**Topics:** Array, Stack, Monotonic Stack, Contribution Technique

---

## 📌 Problem Statement

Given an integer array `nums`, the range of a subarray is the difference between its maximum and minimum elements.

Return the sum of the ranges of all possible non-empty contiguous subarrays of `nums`.

### Example 1

**Input:**
```text
nums = [1,2,3]
```

**Output:**
```text
4
```

**Explanation:**

All possible subarrays and their ranges are:

| Subarray | Maximum | Minimum | Range |
|---|---:|---:|---:|
| `[1]` | 1 | 1 | 0 |
| `[2]` | 2 | 2 | 0 |
| `[3]` | 3 | 3 | 0 |
| `[1,2]` | 2 | 1 | 1 |
| `[2,3]` | 3 | 2 | 1 |
| `[1,2,3]` | 3 | 1 | 2 |

Therefore:

`0 + 0 + 0 + 1 + 1 + 2 = 4`

### Example 2

**Input:**
```text
nums = [1,3,3]
```

**Output:**
```text
4
```

**Example 3**

**Input:**
```text
nums = [4,-2,-3,4,1]
```

**Output:**
```text
59
```

---

## 💡 Approach: Monotonic Stack + Contribution Technique

The range of a subarray is:

`Range = Maximum - Minimum`

Therefore, the sum of all subarray ranges can be calculated as:

\[
\boxed{\text{Answer}=\text{Sum of Maximums}-\text{Sum of Minimums}}
\]

Instead of generating every subarray, we calculate how much each element contributes as a maximum and as a minimum.

We use a monotonic stack to calculate both sums efficiently.

### Step 1: Calculate the Sum of Subarray Maximums

For each element, determine how many subarrays consider it the maximum.

We use a monotonic stack and traverse the array from left to right.

The loop runs from `i = 0` to `i <= n`. When `i == n`, we use a virtual boundary to process any indices remaining in the stack.

For each index:

1. While the stack is not empty and either `i == n` or `nums[i] >= nums[s.top()]`, pop the stack.
2. Store the popped index in `index`.
3. After popping, find the previous greater boundary:
   - If the stack is empty, use `-1`.
   - Otherwise, use `s.top()`.
4. Calculate the number of left and right choices.
5. Add the element's contribution to `maxSum`.
6. Push the current index if `i < n`.

### Maximum Contribution Formula

For a popped index `index`:

```text
left  = index - prevGreater
right = i - index

Contribution = nums[index] × left × right
```

We use `1LL` during multiplication to prevent integer overflow.

### Step 2: Calculate the Sum of Subarray Minimums

The process is similar to calculating maximums, but we reverse the comparison.

We first clear the stack and then traverse the array again.

For each index:

1. While the stack is not empty and either `i == n` or `nums[i] <= nums[s.top()]`, pop the stack.
2. Store the popped index in `index`.
3. Find the previous smaller boundary:
   - If the stack is empty, use `-1`.
   - Otherwise, use `s.top()`.
4. Calculate the left and right choices.
5. Add the element's contribution to `minSum`.
6. Push the current index if `i < n`.

### Minimum Contribution Formula

```text
left  = index - prevSmaller
right = i - index

Contribution = nums[index] × left × right
```

The implementation uses the same boundary variable structure as the maximum loop, but the comparison condition is reversed.

### Step 3: Calculate the Final Answer

Once both sums are calculated:

```text
Answer = maxSum - minSum
```

This gives the sum of the ranges of all non-empty contiguous subarrays.

---

## 💻 C++ Solution

```cpp
#include <iostream>
#include <vector>
#include <stack>
using namespace std;

long long subArrayRanges(vector<int> &nums)
{
    int n = nums.size();
    stack<int> s;

    long long maxSum = 0;
    long long minSum = 0;

    // Calculate the sum of subarray maximums
    for (int i = 0; i <= n; i++)
    {
        while (!s.empty() &&
               (i == n || nums[i] >= nums[s.top()]))
        {
            int index = s.top();
            s.pop();

            int prevGreater = s.empty() ? -1 : s.top();

            int left = index - prevGreater;
            int right = i - index;

            maxSum += 1LL * nums[index] * left * right;
        }

        if (i < n)
        {
            s.push(i);
        }
    }

    // Clear the stack before calculating minimums
    while (!s.empty())
    {
        s.pop();
    }

    // Calculate the sum of subarray minimums
    for (int i = 0; i <= n; i++)
    {
        while (!s.empty() &&
               (i == n || nums[i] <= nums[s.top()]))
        {
            int index = s.top();
            s.pop();

            int prevSmaller = s.empty() ? -1 : s.top();

            int left = index - prevSmaller;
            int right = i - index;

            minSum += 1LL * nums[index] * left * right;
        }

        if (i < n)
        {
            s.push(i);
        }
    }

    return maxSum - minSum;
}

int main()
{
    int n;

    cout << "Enter the size of the array: ";
    cin >> n;

    vector<int> nums(n);

    cout << "Enter the elements of the array: ";
    for (int i = 0; i < n; i++)
    {
        cin >> nums[i];
    }

    cout << "The sum of subarray ranges is: "
         << subArrayRanges(nums) << endl;

    return 0;
}
```

**Note:** The `main()` function is included for local testing. For LeetCode submission, use the required `Solution` class and omit `main()`.

---

## 🔍 Dry Run

Consider the input:

```text
nums = [1,2,3]
```

### Step 1: Sum of Subarray Maximums

| Subarray | Maximum |
|---|---:|
| `[1]` | 1 |
| `[2]` | 2 |
| `[3]` | 3 |
| `[1,2]` | 2 |
| `[2,3]` | 3 |
| `[1,2,3]` | 3 |

Therefore:

`maxSum = 1 + 2 + 3 + 2 + 3 + 3 = 14`

### Step 2: Sum of Subarray Minimums

| Subarray | Minimum |
|---|---:|
| `[1]` | 1 |
| `[2]` | 2 |
| `[3]` | 3 |
| `[1,2]` | 1 |
| `[2,3]` | 2 |
| `[1,2,3]` | 1 |

Therefore:

`minSum = 1 + 2 + 3 + 1 + 2 + 1 = 10`

### Step 3: Calculate the Final Answer

```text
Answer = maxSum - minSum
       = 14 - 10
       = 4
```

**Final Output:**
```text
4
```

---

## 🧠 Important Concepts

### 1. Monotonic Stack

A monotonic stack maintains a particular order of elements using their indices.

It helps us calculate each element's contribution without examining every possible subarray.

### 2. Contribution Technique

Instead of calculating the range of every subarray individually, we calculate each element's total contribution as a maximum and as a minimum.

### 3. Why Store Indices?

We need the positions of the boundaries to calculate the number of possible starting and ending positions.

Storing only values would not provide enough information to calculate the width or number of choices.

### 4. Why Use a Virtual Boundary?

The loop runs until `i == n`, even though `n` is not a valid array index.

This acts as a virtual boundary that allows us to process all indices remaining in the stack.

The short-circuit condition checks `i == n` first, so `nums[i]` is not accessed when `i == n`.

### 5. Why Clear the Stack?

The first traversal calculates maximum contributions. Before calculating minimum contributions, we clear the stack so that no leftover indices affect the second calculation.

### 6. Why Use `1LL`?

The expression:

```cpp
1LL * nums[index] * left * right
```

ensures multiplication is performed using `long long`, reducing the risk of integer overflow.

### 7. Handling Duplicate Elements

The comparison conditions determine when indices are popped.

For maximums, the condition uses `nums[i] >= nums[s.top()]`.

For minimums, the condition uses `nums[i] <= nums[s.top()]`.

This approach correctly handles equal values because the contributions are calculated using consistent boundary rules on both traversals.

---

## ⏱️ Complexity Analysis

Let `n` be the number of elements in `nums`.

### Time Complexity: O(n)

- Calculating the sum of maximums takes `O(n)`.
- Calculating the sum of minimums takes `O(n)`.

Although the loops contain `while` loops, each index is pushed onto and popped from the stack at most once per traversal.

Therefore, the overall time complexity is **O(n)**.

### Space Complexity: O(n)

The stack stores indices of the array.

In the worst case, it can hold up to `n` indices.

Therefore, the auxiliary space complexity is **O(n)**.

---

## ⚖️ Approach Comparison

| Approach | Time Complexity | Auxiliary Space |
|---|---|---|
| Brute Force | O(n²) or more, depending on minimum/maximum calculation | O(1) or O(n), depending on implementation |
| Monotonic Stack + Contribution Technique | O(n) | O(n) |

The monotonic stack approach is more efficient because it calculates the total contribution of each element without explicitly generating every subarray.

---

## 🧪 Important Edge Cases

| Input | Expected Output |
|---|---:|
| `[5]` | 0 |
| `[1,2,3]` | 4 |
| `[3,2,1]` | 4 |
| `[2,2]` | 0 |
| `[1,3,3]` | 4 |
| `[-1,2]` | 3 |

These cases test single-element arrays, increasing and decreasing sequences, duplicate elements, and negative values.

---

## Language

C++

## Status

✅ Solved
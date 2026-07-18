# Longest Subarray With Given Sum K

## Problem Statement

Given an array of **positive integers** and an integer `K`, return the length of the longest subarray whose sum is equal to `K`.

---

## Example 1

**Input**

```text
Array = [1,2,3,1,1,1,1,4,2,3]
K = 3
```

**Output**

```text
3
```

**Explanation**

Possible subarrays having sum = 3:

```text
[1,2]   -> Length = 2
[3]     -> Length = 1
[1,1,1] -> Length = 3
```

Hence, the answer is **3**.

---

## Approach (Optimal - Sliding Window)

### Idea

Maintain a window using two pointers (`left` and `right`).

- Expand the window by moving the right pointer.
- Add the current element to the running sum.
- If the sum becomes greater than `K`, shrink the window by moving the left pointer until the sum becomes less than or equal to `K`.
- Whenever the sum becomes equal to `K`, update the maximum length.

This approach works because **all array elements are positive**.

---

## Algorithm

1. Initialize:
   - `left = 0`
   - `sum = 0`
   - `maxLength = 0`
2. Traverse the array using the right pointer.
3. Add the current element to the sum.
4. While `sum > K`, remove elements from the left side.
5. If `sum == K`, update the maximum length.
6. Return `maxLength`.

---

## Time Complexity

```text
O(n)
```

Each pointer (`left` and `right`) moves at most `n` times.

---

## Space Complexity

```text
O(1)
```

No extra data structure is used.

---

## Why Sliding Window Works?

Sliding Window works only when **all elements are positive**.

- Expanding the window always increases the sum.
- Shrinking the window always decreases the sum.

Therefore, once the sum exceeds `K`, removing elements from the left will eventually reduce the sum.

---

## Limitation

This approach **does not work** if the array contains negative numbers.

For arrays with positive and negative numbers, the optimal solution is **Prefix Sum + HashMap**.

---

## Edge Cases

- Empty array
- Single element array
- No valid subarray
- Entire array is the answer
- Multiple valid subarrays
- `K` equals the first element
- `K` equals the last element

---

## Concepts Covered

- Arrays
- Sliding Window
- Two Pointers
- Time Complexity Analysis
- Space Complexity Analysis

---

## File

```text
longest_subarray_with_given_sum_k.cpp
```

---

## Status

- ✅ Problem Solved
- ✅ Optimal Approach Implemented
- ✅ Dry Run Completed
- ✅ Time & Space Complexity Analyzed
- ✅ Uploaded to GitHub
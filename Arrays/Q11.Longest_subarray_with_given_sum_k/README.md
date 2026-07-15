# Longest Subarray With Given Sum K

## Problem Statement

Given an array of positive integers and an integer `K`, find the length of the longest subarray whose sum is equal to `K`.

---

## Example 1

**Input:**

```text
Array = [1, 2, 3, 1, 1, 1, 1, 4, 2, 3]
K = 3
```

**Output:**

```text
3
```

**Explanation:**

Possible subarrays with sum `3` are:

```text
[1,2]   -> Length = 2
[3]     -> Length = 1
[1,1,1] -> Length = 3
```

The longest subarray length is **3**.

---

## Example 2

**Input:**

```text
Array = [1, 2, 1, 1, 1]
K = 3
```

**Output:**

```text
3
```

---

# Approach 1 (Brute Force)

## Idea

Generate every possible subarray and calculate its sum.

Whenever the sum becomes equal to `K`, update the maximum length.

### Time Complexity

```text
O(n²)
```

### Space Complexity

```text
O(1)
```

---

# Approach 2 (Better Approach - Prefix Sum + HashMap)

## Idea

Store the prefix sum in a hash map.

Whenever `(currentSum - K)` exists in the map, a valid subarray is found.

This approach works for:

- Positive numbers
- Negative numbers
- Mixed arrays

### Time Complexity

```text
O(n)
```

### Space Complexity

```text
O(n)
```

---

# Approach 3 (Optimal Approach - Sliding Window)

> Applicable only when all array elements are positive.

## Idea

Maintain a sliding window using two pointers.

- Expand the window by moving the right pointer.
- If the sum becomes greater than `K`, shrink the window by moving the left pointer.
- Whenever the sum becomes equal to `K`, update the maximum length.

### Time Complexity

```text
O(n)
```

### Space Complexity

```text
O(1)
```

---

# Why Sliding Window Works?

Since all elements are positive:

- Expanding the window always increases the sum.
- Shrinking the window always decreases the sum.

Therefore, once the sum exceeds `K`, removing elements from the left is guaranteed to move the sum closer to `K`.

---

# Why Doesn't Sliding Window Work for Negative Numbers?

If negative numbers are present, removing an element may increase or decrease the sum unpredictably.

Hence, the sliding window technique cannot guarantee the correct answer.

For arrays containing negative numbers, Prefix Sum + HashMap is the preferred approach.

---

# Edge Cases Covered

- Empty array
- Single element array
- No valid subarray
- Entire array forms the answer
- Multiple valid subarrays
- K equals first element
- K equals last element

---

# Concepts Covered

- Arrays
- Sliding Window
- Two Pointers
- Prefix Sum
- HashMap
- Time Complexity Analysis
- Space Complexity Analysis

---

# File

```text
longest_subarray_with_given_sum_k.cpp
```

---

# Status

- [x] Problem Understood
- [ ] Brute Force Implemented
- [ ] Better Approach Understood
- [ ] Optimal Sliding Window Implemented
- [ ] Dry Run Completed
- [ ] Time & Space Complexity Understood
- [ ] Edge Cases Tested
- [ ] Uploaded to GitHub
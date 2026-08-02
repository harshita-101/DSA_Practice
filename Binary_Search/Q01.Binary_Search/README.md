# Q1. Binary Search

## Problem Statement

Given a sorted array of integers `nums` and an integer `target`, return the index of `target` if it exists. Otherwise, return `-1`.

You must write an algorithm with **O(log n)** runtime complexity.

---

## Example 1

### Input

```text
nums = [-1,0,3,5,9,12]
target = 9
```

### Output

```text
4
```

### Explanation

```text
9 is present at index 4.
```

---

## Example 2

### Input

```text
nums = [-1,0,3,5,9,12]
target = 2
```

### Output

```text
-1
```

### Explanation

```text
2 is not present in the array.
```

---

# Approach

## Idea

Since the array is sorted, compare the target with the middle element.

- If the middle element is equal to the target, return its index.
- If the target is greater, search the right half.
- If the target is smaller, search the left half.
- Repeat until the element is found or the search space becomes empty.

---

## Algorithm

1. Initialize two pointers:
   - `low = 0`
   - `high = n - 1`
2. While `low <= high`:
   - Calculate `mid = low + (high - low) / 2`
   - If `nums[mid] == target`, return `mid`
   - If `nums[mid] < target`, move to the right half
   - Otherwise, move to the left half
3. If the target is not found, return `-1`.

---

## Time Complexity

```text
O(log n)
```

---

## Space Complexity

```text
O(1)
```

---

# Why Binary Search?

Binary Search reduces the search space by half after every comparison.

Instead of checking every element, it only searches in the half where the target can possibly exist.

This makes Binary Search much faster than Linear Search for sorted arrays.

---

# Important Points

- The array **must be sorted**.
- Use

```cpp
mid = low + (high - low) / 2;
```

to avoid integer overflow.

- Always use

```cpp
while(low <= high)
```

so that the last remaining element is also checked.

---

# Concepts Used

- Binary Search
- Divide and Conquer
- Searching
- Array

---

# Interview Tips

- Binary Search works only on **sorted data**.
- If the array is unsorted, Binary Search cannot be applied directly.
- Always explain why you use

```cpp
low + (high - low) / 2
```

instead of

```cpp
(low + high) / 2
```

during interviews.

---

# Status

- ✅ Binary Search Implemented
- ✅ Optimal Solution

---

## LeetCode

**Problem:** 704. Binary Search

**Difficulty:** Easy
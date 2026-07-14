# Check if Array is Sorted

## Problem Statement

Given an integer array, check whether the array is sorted in **non-decreasing order**.

Return:
- `true` if the array is sorted.
- `false` otherwise.

---

## Example 1

**Input:**
```text
[1, 2, 3, 4, 5]
```

**Output:**
```text
true
```

---

## Example 2

**Input:**
```text
[1, 3, 2, 4, 5]
```

**Output:**
```text
false
```

---

## Example 3

**Input:**
```text
[1, 1, 2, 2, 3]
```

**Output:**
```text
true
```

---

## Approach

### Optimal Approach

- Traverse the array from left to right.
- Compare every element with its next element.
- If `arr[i] > arr[i + 1]`, the array is not sorted.
- Return `false` immediately (Early Return).
- If the loop completes successfully, return `true`.

---

## Time Complexity

```text
O(n)
```

---

## Space Complexity

```text
O(1)
```

---

## Edge Cases Covered

- Single element array
- Already sorted array
- Unsorted array
- Array with duplicate elements
- Array with negative numbers

---

## Concepts Covered

- Array Traversal
- Adjacent Element Comparison
- Early Return
- Time Complexity Analysis
- Space Complexity Analysis

---

## File

```text
check_if_array_is_sorted.cpp
```

---

## Status

- [x] Problem Understood
- [x] Optimal Approach Implemented
- [x] Dry Run Completed
- [x] Time & Space Complexity Understood
- [x] Edge Cases Tested
- [ ] Uploaded to GitHub
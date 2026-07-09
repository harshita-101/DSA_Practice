# Left Rotate Array by One Place

## Problem Statement

Given an integer array, rotate the array to the left by **one position**.

The rotation should be performed **in-place**.

---

## Example 1

**Input:**
```text
[1, 2, 3, 4, 5]
```

**Output:**
```text
[2, 3, 4, 5, 1]
```

---

## Example 2

**Input:**
```text
[10, 20, 30]
```

**Output:**
```text
[20, 30, 10]
```

---

## Approach

### Optimal Approach

- Store the first element in a temporary variable.
- Shift every element one position to the left.
- Place the stored element at the last index.

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

- Empty array
- Single element array
- Array with duplicate elements
- Array containing negative numbers

---

## Concepts Covered

- Array Traversal
- Array Shifting
- In-place Modification
- Temporary Variable
- Time Complexity Analysis
- Space Complexity Analysis

---

## File

```text
left_rotate_array_by_one.cpp
```

---

## Status

- [x] Problem Understood
- [x] Optimal Approach Implemented
- [x] Dry Run Completed
- [x] Time & Space Complexity Understood
- [x] Edge Cases Tested
- [ ] Uploaded to GitHub
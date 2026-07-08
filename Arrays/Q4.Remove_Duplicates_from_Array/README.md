# Remove Duplicates from Sorted Array

## Problem Statement

Given a sorted integer array, remove the duplicate elements in-place such that each unique element appears only once.

Return the number of unique elements present in the array.

---

## Example 1

**Input:**
```text
[1, 1, 2]
```

**Output:**
```text
2
```

Modified Array:
```text
[1, 2]
```

---

## Example 2

**Input:**
```text
[1, 1, 2, 2, 3]
```

**Output:**
```text
3
```

Modified Array:
```text
[1, 2, 3]
```

---

## Approach

### Optimal Approach (Two Pointers)

- Use two pointers:
  - **Write Pointer (`i`)** → Stores unique elements.
  - **Read Pointer (`j`)** → Traverses the array.
- If the current element is different from the previous unique element:
  - Move the write pointer.
  - Copy the current element.
- Return the count of unique elements (`i + 1`).

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
- Array with all duplicate elements
- Array with all unique elements
- Negative numbers
- Already sorted array

---

## Concepts Covered

- Two Pointer Technique
- In-place Modification
- Array Traversal
- Time Complexity Analysis
- Space Complexity Analysis

---

## File

```text
remove_duplicates_from_sorted_array.cpp
```

---

## Status

- [x] Problem Understood
- [x] Optimal Approach Implemented
- [x] Dry Run Completed
- [x] Time & Space Complexity Understood
- [x] Edge Cases Tested
- [ ] Uploaded to GitHub
# Linear Search

## Problem Statement

Given an integer array and a target element, find the index of the target element.

If the target element exists, return its index. Otherwise, return `-1`.

---

## Example 1

**Input:**

```text
Array = [2, 4, 6, 8, 10]
Target = 8
```

**Output:**

```text
3
```

---

## Example 2

**Input:**

```text
Array = [5, 7, 9]
Target = 4
```

**Output:**

```text
-1
```

---

## Approach

1. Traverse the array from left to right.
2. Compare each element with the target.
3. If the target is found, immediately return its index.
4. If the loop completes without finding the target, return `-1`.

---

## Algorithm

1. Start from index `0`.
2. Compare `arr[i]` with the target.
3. If they are equal, return `i`.
4. Otherwise, continue searching.
5. If no match is found after traversing the entire array, return `-1`.

---

## Time Complexity

### Best Case

```text
O(1)
```

Target is found at the first index.

### Average Case

```text
O(n)
```

Target may be found somewhere in the middle.

### Worst Case

```text
O(n)
```

Target is at the last index or not present in the array.

---

## Space Complexity

```text
O(1)
```

Only a few extra variables are used.

---

## Edge Cases Covered

- Empty array
- Single element array
- Target at first index
- Target at last index
- Target not present
- Negative numbers
- Duplicate elements (returns the first occurrence)

---

## Concepts Covered

- Arrays
- Linear Search
- Array Traversal
- Early Return
- Time Complexity Analysis
- Space Complexity Analysis

---

## File

```text
linear_search.cpp
```

---

## Status

- [x] Problem Understood
- [x] Optimal Approach Implemented
- [x] Dry Run Completed
- [x] Time & Space Complexity Understood
- [x] Edge Cases Tested
- [ ] Uploaded to GitHub
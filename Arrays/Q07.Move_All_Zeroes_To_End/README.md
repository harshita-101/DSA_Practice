# Move All Zeroes to End

## Problem Statement

Given an integer array, move all the zeroes to the end while maintaining the relative order of the non-zero elements.

The operation should be performed in-place.

---

## Example 1

**Input:**

```text
[1, 0, 2, 3, 0, 4, 0, 1]
```

**Output:**

```text
[1, 2, 3, 4, 1, 0, 0, 0]
```

---

## Example 2

**Input:**

```text
[0, 0, 1]
```

**Output:**

```text
[1, 0, 0]
```

---

## Example 3

**Input:**

```text
[0, 0, 0]
```

**Output:**

```text
[0, 0, 0]
```

---

## Approach (Optimal Approach)

1. Initialize a write pointer `j = 0`.
2. Traverse the array.
3. Whenever a non-zero element is found:
   - Place it at index `j`.
   - Increment `j`.
4. After traversing the array, fill the remaining positions with zeroes.

---

## Algorithm

1. Traverse the array.
2. Copy every non-zero element to the front.
3. Keep track of the next position using pointer `j`.
4. Fill the remaining positions with `0`.

---

## Time Complexity

```text
O(n)
```

Explanation:

- First loop traverses the array once.
- Second loop fills the remaining positions with zeroes.
- Total operations = O(n) + O(n) = O(2n)
- Ignoring constants:

```text
O(n)
```

---

## Space Complexity

```text
O(1)
```

Only a few extra variables are used.

---

## Edge Cases Covered

- Empty array
- Array with all zeroes
- Array with no zeroes
- Single element array
- Duplicate non-zero elements

---

## Concepts Covered

- Arrays
- Two Pointers
- In-place Modification
- Array Traversal
- Time Complexity Analysis
- Space Complexity Analysis

---

## File

```text
move_all_zeroes_to_end.cpp
```

---

## Status

- [x] Problem Understood
- [x] Optimal Approach Implemented
- [x] Dry Run Completed
- [x] Time & Space Complexity Understood
- [x] Edge Cases Tested
- [ ] Uploaded to GitHub
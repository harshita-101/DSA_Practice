# Left Rotate Array by D Places

## Problem Statement

Given an integer array and an integer `d`, rotate the array to the left by `d` places.

The rotation should be performed efficiently.

---

## Example 1

**Input:**
```text
Array = [1, 2, 3, 4, 5, 6, 7]
d = 2
```

**Output:**
```text
[3, 4, 5, 6, 7, 1, 2]
```

---

## Example 2

**Input:**
```text
Array = [1, 2, 3, 4, 5]
d = 7
```

**Output:**
```text
[3, 4, 5, 1, 2]
```

Explanation:

```text
d = d % n
7 % 5 = 2
```

So, rotating by 7 places is the same as rotating by 2 places.

---

## Approach (Better Approach)

1. Find the size of the array.
2. Update `d` using `d = d % n`.
3. Store the first `d` elements in a temporary vector.
4. Shift the remaining elements to the left.
5. Copy the temporary elements to the end of the array.

---

## Algorithm

1. Store the first `d` elements in a temporary vector.
2. Shift all remaining elements `d` positions to the left.
3. Copy the elements from the temporary vector to the last `d` positions.
4. Print the rotated array.

---

## Time Complexity

```text
O(n)
```

---

## Space Complexity

```text
O(d)
```

---

## Edge Cases Covered

- Empty array
- Single element array
- `d = 0`
- `d > n`
- Duplicate elements
- Negative numbers

---

## Concepts Covered

- Array Rotation
- Better Approach
- Temporary Vector
- Array Traversal
- Modulo Operation (`d % n`)
- Time Complexity Analysis
- Space Complexity Analysis

---

## File

```text
left_rotate_array_by_d_places.cpp
```

---

## Status

- [x] Problem Understood
- [x] Better Approach Implemented
- [x] Dry Run Completed
- [x] Time & Space Complexity Understood
- [x] Edge Cases Tested
- [ ] Uploaded to GitHub
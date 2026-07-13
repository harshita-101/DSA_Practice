# Maximum Consecutive Ones

## Problem Statement

Given a binary array, return the maximum number of consecutive `1`s present in the array.

---

## Example 1

**Input:**

```text
[1, 1, 0, 1, 1, 1]
```

**Output:**

```text
3
```

---

## Example 2

**Input:**

```text
[1, 0, 1, 1, 0, 1]
```

**Output:**

```text
2
```

---

## Example 3

**Input:**

```text
[0, 0, 0, 0]
```

**Output:**

```text
0
```

---

## Approach (Optimal Approach)

1. Initialize two variables:
   - `count` to store the current consecutive ones.
   - `maxCount` to store the maximum consecutive ones found so far.
2. Traverse the array.
3. If the current element is `1`:
   - Increment `count`.
   - Update `maxCount` using `max(maxCount, count)`.
4. If the current element is `0`:
   - Reset `count` to `0`.
5. Return `maxCount`.

---

## Algorithm

1. Traverse the array from left to right.
2. Increase the count whenever `1` is found.
3. Reset the count when `0` is encountered.
4. Continuously update the maximum count.
5. Return the maximum consecutive ones.

---

## Time Complexity

### Best Case

```text
O(n)
```

### Worst Case

```text
O(n)
```

The array is traversed only once.

---

## Space Complexity

```text
O(1)
```

Only constant extra space is used.

---

## Edge Cases Covered

- Empty array
- Array containing all `0`s
- Array containing all `1`s
- Single element array
- Alternating `0`s and `1`s

---

## Concepts Covered

- Arrays
- Linear Traversal
- Running Count
- Maximum Tracking
- Time Complexity Analysis
- Space Complexity Analysis

---

## File

```text
maximum_consecutive_ones.cpp
```

---

## Status

- [x] Problem Understood
- [x] Optimal Approach Implemented
- [x] Dry Run Completed
- [x] Time & Space Complexity Understood
- [x] Edge Cases Tested
- [ ] Uploaded to GitHub
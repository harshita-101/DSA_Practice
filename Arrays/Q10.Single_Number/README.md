# Single Number

## Problem Statement

Given a non-empty array of integers, every element appears exactly twice except for one element. Find the element that appears only once.

You must solve the problem in linear time and with constant extra space.

---

## Example 1

**Input:**

```text
[2, 2, 1]
```

**Output:**

```text
1
```

---

## Example 2

**Input:**

```text
[4, 1, 2, 1, 2]
```

**Output:**

```text
4
```

---

## Brute Force Approach

1. Traverse each element.
2. Count its frequency by traversing the entire array.
3. Return the element whose frequency is `1`.

### Time Complexity

```text
O(n²)
```

### Space Complexity

```text
O(1)
```

---

## Better Approach (Hash Map)

1. Store the frequency of every element using an `unordered_map`.
2. Traverse the map.
3. Return the element whose frequency is `1`.

### Time Complexity

```text
O(n)
```

### Space Complexity

```text
O(n)
```

---

## Optimal Approach (Bit Manipulation - XOR)

### XOR Properties

```text
a ^ a = 0
a ^ 0 = a
```

All duplicate elements cancel each other after XOR.

The remaining value is the required answer.

---

## Algorithm

1. Initialize `ans = 0`.
2. Traverse the array.
3. Perform:

```cpp
ans = ans ^ arr[i];
```

4. Return `ans`.

---

## Time Complexity

```text
O(n)
```

Only one traversal of the array.

---

## Space Complexity

```text
O(1)
```

Only one extra variable is used.

---

## Edge Cases Covered

- Single element array
- Negative numbers
- Zero as the unique element
- Large input size

---

## Concepts Covered

- Arrays
- Bit Manipulation
- XOR Operator
- Time Complexity Analysis
- Space Complexity Analysis

---

## File

```text
single_number.cpp
```

---

## Status

- [x] Problem Understood
- [x] Brute Force Approach Understood
- [x] Better Approach Understood
- [x] Optimal XOR Approach Implemented
- [x] Dry Run Completed
- [x] Time & Space Complexity Understood
- [x] Edge Cases Tested
- [ ] Uploaded to GitHub
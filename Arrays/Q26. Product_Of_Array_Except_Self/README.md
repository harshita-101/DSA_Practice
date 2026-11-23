
# Product of Array Except Self

## Problem Statement

Given an integer array nums, return an array answer such that answer[i] is equal to the product of all the elements of nums except nums[i].

You must solve the problem without using the division operation.

### Example 1

**Input:**
```text
[1, 2, 3, 4]
```

**Output:**
```text
[24, 12, 8, 6]
```

### Example 2

**Input:**
```text
[-1, 1, 0, -3, 3]
```

**Output:**
```text
[0, 0, 9, 0, 0]
```

---

## Approaches

### 1. Brute Force

* For each index, multiply all elements except the current element.
* Time Complexity: **O(n²)**
* Space Complexity: **O(1)** (excluding output array)

### 2. Optimal Approach

* Use Prefix Product to calculate the product of all elements on the left.
* Use Suffix Product to calculate the product of all elements on the right.
* Multiply both products to get the final answer.
* Time Complexity: **O(n)**
* Space Complexity: **O(1)** auxiliary space (excluding output array)

---

## Concepts Covered

* Array Traversal
* Prefix Product
* Suffix Product
* Prefix and Suffix Technique
* Without Division
* Time Complexity Analysis
* Space Complexity Analysis

---

## File

```text
product_of_array_except_self.cpp
```

---

## Status

✅ Solved


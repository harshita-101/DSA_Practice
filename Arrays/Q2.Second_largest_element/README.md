# Second Largest Element in an Array

## Problem Statement

Given an integer array, find and return the **second largest distinct element** present in the array.

If the second largest element does not exist, return **-1**.

### Example 1

**Input:**

```text
[2, 5, 1, 8, 6]
```

**Output:**

```text
6
```

### Example 2

**Input:**

```text
[5, 5, 5]
```

**Output:**

```text
-1
```

### Example 3

**Input:**

```text
[-5, -2, -10]
```

**Output:**

```text
-5
```

---

## Approaches

### 1. Brute Force

* Sort the array in descending order.
* Traverse the sorted array to find the first element different from the largest.
* Return that element.

**Time Complexity:** `O(n log n)`

**Space Complexity:** `O(1)` (if sorting in-place)

---

### 2. Optimal Approach

* Traverse the array only once.
* Maintain two variables:

  * `largest`
  * `second_largest`
* Update them whenever a larger element is found.
* Handle duplicate values by considering only distinct elements.

**Time Complexity:** `O(n)`

**Space Complexity:** `O(1)`

---

## Edge Cases Covered

* Array with only one element
* Array with all duplicate elements
* Array containing negative numbers
* Array already sorted
* Array in descending order

---

## Concepts Covered

* Array Traversal
* Two Variable Technique
* Distinct Elements
* Edge Case Handling
* Time Complexity Analysis
* Space Complexity Analysis

---

## File

```text
second_largest_element.cpp
```

---

## Status

* [x] Problem Understood
* [x] Brute Force Implemented
* [x] Optimal Approach Implemented
* [x] Dry Run Completed
* [x] Time & Space Complexity Understood
* [x] Edge Cases Tested
* [ ] Uploaded to GitHub

# Q10. Search a 2D Matrix

## Problem Statement

You are given an `m × n` integer matrix with the following properties:

- Each row is sorted in ascending order.
- The first integer of each row is greater than the last integer of the previous row.

Given an integer `target`, return **true** if the target exists in the matrix, otherwise return **false**.

The solution must run in **O(log(m × n))** time.

**Difficulty:** Medium

**LeetCode:** 74

---

## Examples

### Example 1

```text
Input:

matrix =
[
 [1,3,5,7],
 [10,11,16,20],
 [23,30,34,60]
]

target = 3

Output:
true
```

---

### Example 2

```text
Input:

matrix =
[
 [1,3,5,7],
 [10,11,16,20],
 [23,30,34,60]
]

target = 13

Output:
false
```

---

## Approach

The matrix satisfies the following property:

- Every row is sorted.
- The first element of the next row is greater than the last element of the previous row.

Therefore, the complete matrix can be treated as a **single sorted 1D array**.

Example:

```text
Matrix

1   3   5   7
10 11  16  20
23 30  34  60
```

Equivalent 1D Array

```text
1 3 5 7 10 11 16 20 23 30 34 60
```

Apply Binary Search on indices from `0` to `rows × cols - 1`.

Convert the 1D index into 2D coordinates using:

```cpp
row = mid / cols;
col = mid % cols;
```

---

## Algorithm

1. Find the number of rows and columns.
2. Initialize:
   - `low = 0`
   - `high = rows × cols - 1`
3. Perform Binary Search.
4. Convert `mid` into matrix coordinates:
   - `row = mid / cols`
   - `col = mid % cols`
5. Compare `matrix[row][col]` with the target.
6. Return true if found.
7. Otherwise continue Binary Search.
8. If the loop ends, return false.

---

## Important Formula

### Convert 1D Index to 2D

```cpp
row = mid / cols;
col = mid % cols;
```

---

### Target Found

```cpp
if(matrix[row][col] == target)
    return true;
```

---

### Search Right

```cpp
else if(matrix[row][col] < target)
    low = mid + 1;
```

---

### Search Left

```cpp
else
    high = mid - 1;
```

---

## Dry Run

Input

```text
matrix =
[
 [1,3,5,7],
 [10,11,16,20],
 [23,30,34,60]
]

target = 16
```

### Iteration 1

```text
low = 0
high = 11

mid = 5

row = 5 / 4 = 1
col = 5 % 4 = 1

matrix[1][1] = 11
```

```
11 < 16
```

Move Right

```text
low = 6
```

---

### Iteration 2

```text
low = 6
high = 11

mid = 8

row = 2
col = 0

matrix[2][0] = 23
```

```
23 > 16
```

Move Left

```text
high = 7
```

---

### Iteration 3

```text
low = 6
high = 7

mid = 6

row = 1
col = 2

matrix[1][2] = 16
```

Target Found

Return

```text
true
```

---

## Complexity Analysis

**Time Complexity:** `O(log(m × n))`

**Space Complexity:** `O(1)`

---

## Key Concepts

- Binary Search
- 2D to 1D Mapping
- Matrix Search
- Row & Column Calculation
- Search Space Reduction

---

## Interview Tips

- Do **not** search row by row.
- Treat the matrix as a single sorted array.
- Convert the 1D index into 2D coordinates using:

```cpp
row = mid / cols;
col = mid % cols;
```

- Always calculate the middle index safely.

```cpp
mid = low + (high - low) / 2;
```

---

## Folder Structure

```
Q10.Search_a_2D_Matrix/
├── README.md
└── search_a_2D_matrix.cpp
```

---

## Learning Outcomes

After solving this problem, you will understand:

- Applying Binary Search on a 2D matrix.
- Mapping between 1D and 2D indices.
- Efficient matrix searching in logarithmic time.
- Solving interview-level matrix search problems.

---

## Status

✅ Solved
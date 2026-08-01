# Q11. Search a 2D Matrix II

## Problem Statement

You are given an `m × n` integer matrix with the following properties:

- Integers in each row are sorted in ascending order.
- Integers in each column are sorted in ascending order.

Given an integer `target`, return **true** if the target exists in the matrix; otherwise, return **false**.

**Difficulty:** Medium

**LeetCode:** 240

---

## Examples

### Example 1

```text
Input:

matrix =
[
 [1,4,7,11,15],
 [2,5,8,12,19],
 [3,6,9,16,22],
 [10,13,14,17,24],
 [18,21,23,26,30]
]

target = 5

Output:
true
```

---

### Example 2

```text
Input:

matrix =
[
 [1,4,7,11,15],
 [2,5,8,12,19],
 [3,6,9,16,22],
 [10,13,14,17,24],
 [18,21,23,26,30]
]

target = 20

Output:
false
```

---

## Approach

Unlike **LeetCode 74**, this matrix **cannot** be treated as a single sorted array.

Observation:

- Every row is sorted.
- Every column is sorted.

Start searching from the **Top Right Corner**.

At any position:

- If current element equals target → return true.
- If current element is greater than target → move left.
- If current element is smaller than target → move down.

This eliminates one complete row or one complete column in every step.

---

## Algorithm

1. Start from the top-right element.
2. While the current position is inside the matrix:
   - If current element equals target, return true.
   - If current element is greater than target, move left.
   - Otherwise move down.
3. If traversal finishes, return false.

---

## Important Conditions

### Starting Position

```cpp
int row = 0;
int col = cols - 1;
```

---

### Target Found

```cpp
if(matrix[row][col] == target)
    return true;
```

---

### Current Element > Target

```cpp
col--;
```

Move left because all elements below are larger.

---

### Current Element < Target

```cpp
row++;
```

Move down because all elements on the left are smaller.

---

## Dry Run

Input

```text
Target = 14
```

Matrix

```text
1   4   7   11   15
2   5   8   12   19
3   6   9   16   22
10 13 14   17   24
18 21 23   26   30
```

Steps

```text
15 > 14
Move Left

11 < 14
Move Down

12 < 14
Move Down

16 > 14
Move Left

14 == Target
```

Return

```text
true
```

---

## Complexity Analysis

**Time Complexity:** `O(rows + cols)`

**Space Complexity:** `O(1)`

---

## Key Concepts

- Matrix Traversal
- Row-wise Sorting
- Column-wise Sorting
- Search Space Reduction
- Top Right Traversal

---

## Interview Tips

- This problem is different from **LeetCode 74**.
- Do **not** flatten the matrix into a 1D array.
- Starting from **Top Right** or **Bottom Left** gives a unique direction to move.
- Every move removes either one row or one column from consideration.

---

## Comparison with Q10

| Q10 (LeetCode 74) | Q11 (LeetCode 240) |
|-------------------|--------------------|
| Matrix behaves like one sorted array | Matrix is only row-wise and column-wise sorted |
| Binary Search | Matrix Traversal |
| Time: `O(log(m × n))` | Time: `O(rows + cols)` |

---

## Folder Structure

```
Q11.Search_a_2D_Matrix_II/
├── README.md
└── search_a_2D_matrix_II.cpp
```

---

## Learning Outcomes

After solving this problem, you will understand:

- Searching efficiently in a sorted 2D matrix.
- Why Top Right (or Bottom Left) is the optimal starting point.
- How to eliminate one row or one column in each step.
- The difference between LeetCode 74 and LeetCode 240.

---

## Status

✅ Solved
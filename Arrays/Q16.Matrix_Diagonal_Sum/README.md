# Diagonal Sum

## Problem Statement

Given a square matrix `mat`, calculate the sum of the elements present on its two diagonals:

1. **Primary Diagonal**
2. **Secondary Diagonal**

If the matrix has odd dimensions, the center element belongs to both diagonals. It should be counted **only once**.

**Difficulty:** Easy

**LeetCode:** 1572

---

## Examples

### Example 1

```text
Input:

[
    [1,2,3],
    [4,5,6],
    [7,8,9]
]

Output:
25
```

Explanation:

Primary diagonal:

```text
1 + 5 + 9 = 15
```

Secondary diagonal:

```text
3 + 5 + 7 = 15
```

The center element `5` is common to both diagonals, so it should be counted only once:

```text
15 + 15 - 5 = 25
```

---

### Example 2

```text
Input:

[
    [1,1,1,1],
    [1,1,1,1],
    [1,1,1,1],
    [1,1,1,1]
]

Output:
8
```

For an even-sized matrix, there is no common center element.

---

## Approach

Use a **single loop** to traverse the rows of the matrix.

For every row `i`:

### Primary Diagonal

The primary diagonal element is:

```text
mat[i][i]
```

Example:

```text
mat[0][0]
mat[1][1]
mat[2][2]
```

---

### Secondary Diagonal

The secondary diagonal element is:

```text
mat[i][n - i - 1]
```

Example for a `3 × 3` matrix:

```text
mat[0][2]
mat[1][1]
mat[2][0]
```

---

## Handling the Center Element

For an odd-sized matrix, the middle element belongs to both diagonals.

For example:

```text
3 × 3 matrix
```

The center is:

```text
mat[1][1]
```

If we simply add both diagonals, the center would be counted twice.

Therefore, check:

```text
i == n - i - 1
```

If this condition is true, add the center element only once.

Otherwise, add both diagonal elements.

---

## Algorithm

1. Find the size of the matrix:
   ```text
   n = mat.size()
   ```

2. Initialize:
   ```text
   sum = 0
   ```

3. Traverse every row using `i`.

4. Check whether:
   ```text
   i == n - i - 1
   ```

5. If true:
   - Add `mat[i][i]` only once.

6. Otherwise:
   - Add primary diagonal:
     ```text
     mat[i][i]
     ```
   - Add secondary diagonal:
     ```text
     mat[i][n-i-1]
     ```

7. Return `sum`.

---

## Dry Run

### Input

```text
[
    [1,2,3],
    [4,5,6],
    [7,8,9]
]
```

Here:

```text
n = 3
```

### i = 0

Primary:

```text
mat[0][0] = 1
```

Secondary:

```text
mat[0][2] = 3
```

Sum:

```text
1 + 3 = 4
```

---

### i = 1

Primary:

```text
mat[1][1] = 5
```

Secondary:

```text
mat[1][1] = 5
```

They are the same element.

So add only:

```text
5
```

Sum:

```text
4 + 5 = 9
```

---

### i = 2

Primary:

```text
mat[2][2] = 9
```

Secondary:

```text
mat[2][0] = 7
```

Add:

```text
9 + 7 = 16
```

Final:

```text
9 + 16 = 25
```

Therefore:

```text
Output = 25
```

---

## Diagonal Visualization

For:

```text
[
    [1,2,3],
    [4,5,6],
    [7,8,9]
]
```

Primary diagonal:

```text
1
   5
      9
```

Secondary diagonal:

```text
      3
   5
7
```

Center:

```text
5
```

is common to both diagonals and must be counted once.

---

## Complexity Analysis

### Time Complexity

```text
O(n)
```

We traverse the matrix only once using the row index.

For every row, only a constant number of operations are performed.

---

### Space Complexity

```text
O(1)
```

Only variables such as:

```text
n
sum
i
```

are used.

No additional matrix or data structure is created.

---

## Why This Approach?

Instead of using two separate loops for the two diagonals, both diagonal elements can be accessed during the same traversal.

For each row:

```text
Primary   → mat[i][i]
Secondary → mat[i][n-i-1]
```

This makes the solution simple and efficient.

---

## Important Formula

### Primary Diagonal

```text
mat[i][i]
```

### Secondary Diagonal

```text
mat[i][n-i-1]
```

### Center Condition

```text
i == n-i-1
```

---

## Key Concepts

- 2D Arrays
- Matrices
- Matrix Traversal
- Primary Diagonal
- Secondary Diagonal
- Row and Column Indexing
- Conditional Checking
- Avoiding Duplicate Counting

---

## Interview Tips

- Remember the primary diagonal formula:
  ```text
  mat[i][i]
  ```
- Remember the secondary diagonal formula:
  ```text
  mat[i][n-i-1]
  ```
- For odd-sized matrices, the center element occurs in both diagonals.
- Count the center only once.
- A single loop is enough.
- The optimal complexity is:
  ```text
  Time  → O(n)
  Space → O(1)
  ```

---

## Folder Structure

```text
Q14.Diagonal_Sum/
├── README.md
└── diagonal_sum.cpp
```

---

## Learning Outcomes

After solving this problem, you will understand:

- How to traverse a square matrix efficiently.
- How to identify primary and secondary diagonals.
- How to calculate diagonal indexes.
- How to avoid counting the center element twice.
- How to solve matrix traversal problems using constant extra space.

---

## Status

✅ Solved
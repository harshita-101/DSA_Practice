# Spiral Matrix

## Problem Statement

Given an `m x n` matrix, return all elements of the matrix in **spiral order**.

The elements should be traversed in the following order:

```text
Top → Right → Bottom → Left
```

Then move toward the inner layer and repeat the same process.

**Difficulty:** Medium

**LeetCode:** 54

---

## Example

### Input

```text
[
    [1,  2,  3],
    [4,  5,  6],
    [7,  8,  9]
]
```

### Output

```text
[1,2,3,6,9,8,7,4,5]
```

---

## Spiral Order

The traversal happens layer by layer:

```text
1 → 2 → 3
        ↓
4   5   6
↑       ↓
7 ← 8 ← 9
```

Result:

```text
1 2 3 6 9 8 7 4 5
```

---

## Approach

Use **Boundary Traversal** with four boundaries:

```text
srow → Starting Row
erow → Ending Row
scol → Starting Column
ecol → Ending Column
```

Initially:

```text
srow = 0
erow = m - 1
scol = 0
ecol = n - 1
```

For every layer, traverse four sides:

1. Top
2. Right
3. Bottom
4. Left

After completing one layer, move the boundaries inward.

```text
srow++
scol++
erow--
ecol--
```

---

## Four Steps of Traversal

### 1. Top Row

Traverse from left to right:

```cpp
for(int j = scol; j <= ecol; j++)
```

Add:

```text
matrix[srow][j]
```

---

### 2. Right Column

Traverse from top to bottom:

```cpp
for(int i = srow + 1; i <= erow; i++)
```

Add:

```text
matrix[i][ecol]
```

---

### 3. Bottom Row

Traverse from right to left:

```cpp
for(int j = ecol - 1; j >= scol; j--)
```

Add:

```text
matrix[erow][j]
```

But if there is only one row remaining, we must avoid traversing the same row again.

Therefore:

```cpp
if(srow == erow)
    break;
```

---

### 4. Left Column

Traverse from bottom to top:

```cpp
for(int i = erow - 1; i >= srow + 1; i--)
```

Add:

```text
matrix[i][scol]
```

If there is only one column remaining, we must avoid traversing the same column again.

Therefore:

```cpp
if(scol == ecol)
    break;
```

---

## Algorithm

1. Find the number of rows `m`.
2. Find the number of columns `n`.
3. Initialize four boundaries:
   ```text
   srow = 0
   erow = m - 1
   scol = 0
   ecol = n - 1
   ```
4. While:
   ```text
   srow <= erow && scol <= ecol
   ```
5. Traverse the top row from left to right.
6. Traverse the right column from top to bottom.
7. Traverse the bottom row from right to left.
8. Traverse the left column from bottom to top.
9. Move all boundaries inward:
   ```text
   srow++
   scol++
   erow--
   ecol--
   ```
10. Continue until all elements are visited.
11. Return the answer vector.

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

Initial boundaries:

```text
srow = 0
erow = 2
scol = 0
ecol = 2
```

### Step 1: Top

```text
1 2 3
```

Result:

```text
[1,2,3]
```

---

### Step 2: Right

```text
6
9
```

Result:

```text
[1,2,3,6,9]
```

---

### Step 3: Bottom

Traverse from right to left:

```text
8 7
```

Result:

```text
[1,2,3,6,9,8,7]
```

---

### Step 4: Left

Traverse from bottom to top:

```text
4
```

Result:

```text
[1,2,3,6,9,8,7,4]
```

---

### Move Boundaries

```text
srow = 1
erow = 1
scol = 1
ecol = 1
```

Remaining matrix:

```text
[5]
```

Add:

```text
5
```

Final result:

```text
[1,2,3,6,9,8,7,4,5]
```

---

## Why Boundary Conditions Are Important?

Consider a single row:

```text
[1,2,3,4]
```

After traversing the top row, the bottom traversal could try to add the same elements again.

Therefore:

```cpp
if(srow == erow)
    break;
```

prevents duplicate traversal.

Similarly, for a single column:

```text
[
    [1],
    [2],
    [3],
    [4]
]
```

the left traversal could repeat the same column.

Therefore:

```cpp
if(scol == ecol)
    break;
```

prevents duplicate elements.

---

## Complexity Analysis

### Time Complexity

```text
O(m × n)
```

Every matrix element is visited exactly once.

If the matrix contains `m × n` elements, all of them need to be processed.

Therefore:

```text
O(m × n)
```

---

### Space Complexity

Ignoring the output vector:

```text
O(1)
```

Only four boundary variables are used.

However, the returned `ans` vector contains all matrix elements:

```text
O(m × n)
```

So:

```text
Auxiliary Space = O(1)
Output Space     = O(m × n)
```

---

## Is This Approach Optimal?

Yes. ✅

Every element of the matrix must be visited at least once to produce the spiral order.

Therefore, the minimum possible time complexity is:

```text
O(m × n)
```

Your approach achieves:

```text
Time = O(m × n)
```

So it is **optimal in time complexity**.

---

## Key Concepts

- 2D Arrays
- Matrix Traversal
- Boundary Traversal
- Spiral Traversal
- Layer-by-Layer Processing
- Four Boundary Technique
- Two Pointers / Boundary Pointers
- Nested Loops
- Edge Case Handling
- In-place Boundary Management

---

## Important Variables

```text
srow → Starting row
erow → Ending row
scol → Starting column
ecol → Ending column
```

After completing one layer:

```text
srow++
scol++
erow--
ecol--
```

This moves the traversal toward the center.

---

## Interview Tips

- Remember the four traversal directions:
  ```text
  → Right
  ↓ Down
  ← Left
  ↑ Up
  ```
- Use four boundaries to represent the current layer.
- After every complete layer, shrink all boundaries.
- Always handle:
  ```text
  Single Row
  Single Column
  ```
- Without the boundary checks, duplicate elements may be added.
- The optimal time complexity is:
  ```text
  O(m × n)
  ```
- Output space is:
  ```text
  O(m × n)
  ```
  because the answer contains all matrix elements.

---

## Folder Structure

```text
Q15.Spiral_Matrix/
├── README.md
└── spiral_matrix.cpp
```

---

## Learning Outcomes

After solving this problem, you will understand:

- How to traverse a matrix in spiral order.
- How to divide a matrix into layers.
- How to maintain four boundaries.
- How to move boundaries toward the center.
- How to handle single-row and single-column cases.
- How to achieve `O(m × n)` time complexity.
- How boundary traversal works in matrix problems.

---

## Status

✅ Solved
# Find Missing and Repeated Values

## Problem Statement

You are given an `n x n` grid containing numbers from `1` to `n²`.

Exactly one number appears **twice**, and exactly one number is **missing**.

Find the repeated number and the missing number.

Return the result in the following order:

```text
[repeated, missing]
```

**Difficulty:** Easy

**LeetCode:** 2965

---

## Example

### Input

```text
grid = [
    [1,2,3],
    [4,5,6],
    [7,7,9]
]
```

The numbers should be:

```text
1 2 3 4 5 6 7 8 9
```

But:

```text
7 → repeated
8 → missing
```

### Output

```text
[7,8]
```

---

## Approach

Use two things:

1. **`unordered_set`** to find the repeated value.
2. **Sum formula** to find the missing value.

The grid contains numbers from:

```text
1 to n²
```

So the expected sum is:

```text
n² × (n² + 1) / 2
```

We also calculate the actual sum of all elements in the grid.

---

## Finding the Repeated Value

While traversing the grid, insert every value into an `unordered_set`.

Before inserting, check:

```cpp
if(s.find(grid[i][j]) != s.end())
```

If the value already exists, it is the repeated value.

For example:

```text
grid = [1,2,3,4,4,6]
```

When we encounter the second `4`:

```text
4 already exists in set
```

Therefore:

```text
repeated = 4
```

---

## Finding the Missing Value

Let:

```text
Expected Sum = sum of numbers from 1 to n²
```

and:

```text
Actual Sum = sum of all values present in grid
```

Because one value is repeated and one value is missing:

```text
Actual Sum = Expected Sum + Repeated - Missing
```

Therefore:

```text
Missing = Expected Sum + Repeated - Actual Sum
```

So:

```cpp
b = expSum + a - actSum;
```

---

## Formula

For numbers from `1` to `N`:

```text
Sum = N × (N + 1) / 2
```

Here:

```text
N = n²
```

Therefore:

```text
Expected Sum = (n² × (n² + 1)) / 2
```

---

## Algorithm

1. Create an empty `unordered_set`.
2. Initialize:
   ```text
   actSum = 0
   ```
3. Traverse every element of the grid.
4. Add every element to `actSum`.
5. Before inserting an element into the set:
   - Check whether it already exists.
   - If yes, store it as the repeated value `a`.
6. Calculate:
   ```text
   N = n²
   ```
7. Calculate expected sum:
   ```text
   expSum = N × (N + 1) / 2
   ```
8. Calculate missing value:
   ```text
   missing = expSum + repeated - actSum
   ```
9. Return:
   ```text
   [repeated, missing]
   ```

---

## Dry Run

### Input

```text
grid = [
    [1,2],
    [2,4]
]
```

Here:

```text
n = 2
n² = 4
```

Numbers should be:

```text
1,2,3,4
```

But:

```text
2 is repeated
3 is missing
```

---

### Step 1: Traverse Grid

Elements:

```text
1 → insert
2 → insert
2 → already exists
4 → insert
```

Therefore:

```text
repeated = 2
```

Set:

```text
{1,2,4}
```

---

### Step 2: Actual Sum

```text
actual sum = 1 + 2 + 2 + 4
           = 9
```

---

### Step 3: Expected Sum

Numbers from `1` to `4`:

```text
1 + 2 + 3 + 4 = 10
```

Using formula:

```text
4 × 5 / 2 = 10
```

---

### Step 4: Find Missing Value

```text
missing = expected + repeated - actual
```

```text
missing = 10 + 2 - 9
```

```text
missing = 3
```

Therefore:

```text
Output = [2,3]
```

---

## Why Does the Formula Work?

Suppose:

```text
Expected = 1 + 2 + 3 + 4
         = 10
```

But the actual grid is:

```text
1 + 2 + 2 + 4
= 9
```

The actual sum is smaller by:

```text
3
```

because `3` is missing.

But `2` is repeated, which adds an extra:

```text
+2
```

Therefore:

```text
Actual = Expected - Missing + Repeated
```

Rearranging:

```text
Missing = Expected + Repeated - Actual
```

---

## Complexity Analysis

Let:

```text
N = n²
```

where `N` is the total number of elements in the grid.

### Time Complexity

```text
O(n²)
```

We traverse every element of the `n × n` grid once.

`unordered_set` operations take **O(1) average time**.

Therefore:

```text
O(n²)
```

---

### Space Complexity

```text
O(n²)
```

In the worst case, the `unordered_set` stores almost all unique elements.

Therefore:

```text
Space = O(n²)
```

---

## Is This Approach Optimal?

### Time

Yes. ✅

Every element of the grid needs to be checked at least once.

Therefore:

```text
O(n²)
```

is optimal in time.

### Space

The current approach uses:

```text
O(n²)
```

extra space because of `unordered_set`.

It is **not optimal in auxiliary space**.

A mathematical approach using sum and square-sum equations can reduce extra space to:

```text
O(1)
```

while still maintaining:

```text
O(n²)
```

time.

---

## Alternative Approach

We can solve the problem using mathematical equations without a set.

Let:

```text
x = repeated
y = missing
```

Using the sum:

```text
Actual Sum - Expected Sum = x - y
```

We can also use the sum of squares:

```text
Actual Square Sum - Expected Square Sum = x² - y²
```

Since:

```text
x² - y² = (x-y)(x+y)
```

we can calculate both `x` and `y`.

This approach uses:

```text
Time  = O(n²)
Space = O(1)
```

However, the current `unordered_set` approach is easier to understand and implement.

---

## Important Concepts

- 2D Arrays
- Matrix Traversal
- Hashing
- `unordered_set`
- Duplicate Detection
- Missing Number
- Mathematical Formula
- Arithmetic Sum
- Expected Sum
- Actual Sum
- Set Lookup

---

## Interview Tips

- First identify the range of numbers:
  ```text
  1 to n²
  ```
- Use:
  ```text
  N = n²
  ```
  for the sum formula.
- Remember:
  ```text
  Sum = N × (N + 1) / 2
  ```
- Use a set to detect the repeated value.
- Once the repeated value is known, the missing value can be calculated using the sum difference.
- `unordered_set` gives average `O(1)` lookup.
- If the interviewer asks for **O(1) extra space**, use the sum + square-sum mathematical approach.

---

## Key Formula

```text
Expected Sum = N × (N + 1) / 2
```

where:

```text
N = n²
```

Then:

```text
Missing = Expected Sum + Repeated - Actual Sum
```

---

## Folder Structure

```text
Q16.Find_Missing_and_Repeated_Values/
├── README.md
└── find_missing_and_repeated_values.cpp
```

---

## Learning Outcomes

After solving this problem, you will understand:

- How to detect duplicates using hashing.
- How to calculate expected sums mathematically.
- How to find a missing value using sum differences.
- How to traverse a 2D grid.
- How to combine hashing with mathematical observations.
- The difference between time optimization and space optimization.
- How to identify an `O(1)` space mathematical alternative.

---

## Status

✅ Solved
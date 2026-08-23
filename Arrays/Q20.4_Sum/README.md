# 4Sum

## Problem Statement

Given an integer array `nums` and an integer `target`, find all unique quadruplets:

```text
[nums[i], nums[j], nums[p], nums[q]]
```

such that:

```text
nums[i] + nums[j] + nums[p] + nums[q] = target
```

The solution must not contain duplicate quadruplets.

**Difficulty:** Medium

**LeetCode:** 18

---

## Example

### Input

```text
nums = [1,0,-1,0,-2,2]
target = 0
```

### Output

```text
[
    [-2,-1,1,2],
    [-2,0,0,2],
    [-1,0,0,1]
]
```

Each quadruplet has a sum equal to `0`.

---

## Approach

Use:

```text
Sorting + Two Pointers
```

First, sort the array.

Example:

```text
[1,0,-1,0,-2,2]
```

After sorting:

```text
[-2,-1,0,0,1,2]
```

Then use two fixed elements and two pointers:

```text
i → first element
j → second element
p → left pointer
q → right pointer
```

For every pair `i` and `j`, use `p` and `q` to find the remaining two elements.

---

## Pointer Structure

```text
i
 ↓
[-2, -1, 0, 0, 1, 2]
      ↑           ↑
      p           q
```

For every `i`:

```text
j = i + 1
p = j + 1
q = n - 1
```

Then calculate:

```text
sum = nums[i] + nums[j] + nums[p] + nums[q]
```

---

## Two Pointer Logic

### Case 1: `sum < target`

The current sum is too small.

Since the array is sorted, increase `p`:

```cpp
p++;
```

This increases the sum.

---

### Case 2: `sum > target`

The current sum is too large.

Decrease `q`:

```cpp
q--;
```

This decreases the sum.

---

### Case 3: `sum == target`

A valid quadruplet is found:

```cpp
ans.push_back({
    nums[i],
    nums[j],
    nums[p],
    nums[q]
});
```

Then move both pointers:

```cpp
p++;
q--;
```

---

## Handling Duplicates

The problem asks for **unique quadruplets**.

### Duplicate `i`

Skip duplicate values of `nums[i]`:

```cpp
if(i > 0 && nums[i] == nums[i-1])
    continue;
```

---

### Duplicate `j`

Skip duplicate values of `nums[j]`:

```cpp
if(j > i+1 && nums[j] == nums[j-1])
    continue;
```

This prevents generating the same quadruplet multiple times.

---

### Duplicate `p`

After finding a valid quadruplet:

```cpp
while(p < q && nums[p] == nums[p-1])
    p++;
```

This skips duplicate third elements.

---

## Why Do We Sort First?

Sorting is important because it allows us to decide which pointer to move.

For example:

```text
[-2,-1,0,0,1,2]
```

If:

```text
sum < target
```

we know moving `p` forward will increase the value.

If:

```text
sum > target
```

we know moving `q` backward will decrease the value.

Without sorting, this Two Pointer logic would not work.

---

## Why Use `long long`?

The code uses:

```cpp
long long sum =
    (long long)nums[i]
    + (long long)nums[j]
    + (long long)nums[p]
    + (long long)nums[q];
```

This is important because the sum of four integers can exceed the range of `int`.

For example, large values can cause **integer overflow**.

Using `long long` makes the calculation safer.

---

## Dry Run

### Input

```text
nums = [1,0,-1,0,-2,2]
target = 0
```

After sorting:

```text
[-2,-1,0,0,1,2]
```

### `i = 0`

```text
nums[i] = -2
```

### `j = 1`

```text
nums[j] = -1
p = 2
q = 5
```

Calculate:

```text
-2 + (-1) + 0 + 2 = -1
```

Since:

```text
sum < target
```

move:

```text
p++
```

Now:

```text
p = 3
```

Calculate:

```text
-2 + (-1) + 0 + 2 = -1
```

Continue moving `p`.

Eventually:

```text
-2 + (-1) + 1 + 2 = 0
```

Valid quadruplet:

```text
[-2,-1,1,2]
```

---

### Continue

For:

```text
-2 + 0 + 0 + 2
```

we get:

```text
0
```

So:

```text
[-2,0,0,2]
```

is also valid.

For:

```text
-1 + 0 + 0 + 1
```

we get:

```text
0
```

So:

```text
[-1,0,0,1]
```

is valid.

Final answer:

```text
[
    [-2,-1,1,2],
    [-2,0,0,2],
    [-1,0,0,1]
]
```

---

## Algorithm

1. Sort the array.
2. Initialize an empty answer vector.
3. Run the first loop for `i`.
4. Skip duplicate values of `i`.
5. Run the second loop for `j`.
6. Skip duplicate values of `j`.
7. Initialize:
   ```text
   p = j + 1
   q = n - 1
   ```
8. While `p < q`:
   - Calculate the four-element sum.
   - If sum is smaller than target:
     ```text
     p++
     ```
   - If sum is greater than target:
     ```text
     q--
     ```
   - If sum equals target:
     - Store the quadruplet.
     - Move both pointers.
     - Skip duplicate `p` values.
9. Return the answer.

---

## Complexity Analysis

### Time Complexity

Sorting:

```text
O(n log n)
```

The nested loops with Two Pointers take:

```text
O(n³)
```

Therefore:

```text
Overall Time = O(n³)
```

---

### Space Complexity

Ignoring the output vector:

```text
O(1)
```

Only a constant number of variables are used.

The answer itself requires additional space depending on the number of quadruplets.

So:

```text
Auxiliary Space = O(1)
Output Space    = O(k)
```

where `k` is the number of unique quadruplets.

---

## Is This Approach Optimal?

Yes. ✅

The standard optimal approach for 4Sum is:

```text
Sorting + Two Pointers
```

with:

```text
Time = O(n³)
```

This is significantly better than the brute-force approach.

---

## Brute Force vs Optimal

### Brute Force

Use four nested loops:

```text
i
 └── j
      └── p
           └── q
```

Complexity:

```text
O(n⁴)
```

---

### Optimized

Fix two elements and use Two Pointers:

```text
i
 └── j
      └── p → ← q
```

Complexity:

```text
O(n³)
```

Therefore:

```text
O(n⁴) → O(n³)
```

---

## Key Concepts

- Arrays
- Sorting
- Two Pointers
- 4Sum
- Four Elements
- Duplicate Handling
- Target Sum
- Fixed Pointers
- Left Pointer
- Right Pointer
- Integer Overflow
- `long long`
- Nested Loops
- Optimization

---

## Interview Tips

- 4Sum is an extension of the **3Sum pattern**.
- First sort the array.
- Fix the first two elements using `i` and `j`.
- Use `p` and `q` as Two Pointers.
- If `sum < target`, move `p`.
- If `sum > target`, move `q`.
- If `sum == target`, store the quadruplet.
- Always handle duplicates.
- Use `long long` for the sum to avoid integer overflow.
- The standard optimal complexity is:
  ```text
  O(n³)
  ```

---

## 3Sum vs 4Sum

| Problem | Technique | Time Complexity |
|---|---|---|
| 3Sum | Sorting + Two Pointers | O(n²) |
| 4Sum | Sorting + Two Pointers | O(n³) |

The general pattern is:

```text
2Sum → O(n)
3Sum → O(n²)
4Sum → O(n³)
```

when using the sorted Two Pointer approach.

---

## Folder Structure

```text
Q18.4Sum/
├── README.md
└── four_sum.cpp
```

---

## Learning Outcomes

After solving this problem, you will understand:

- How to extend the 3Sum technique to 4Sum.
- How to use multiple fixed pointers.
- How Two Pointers work on a sorted array.
- How to handle duplicate combinations.
- How to avoid integer overflow.
- How to reduce a brute-force `O(n⁴)` solution to `O(n³)`.
- How to recognize multi-pointer patterns in interview problems.

---

## Status

✅ Solved
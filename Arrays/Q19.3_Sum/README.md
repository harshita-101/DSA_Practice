# 3Sum

## Problem Statement

Given an integer array `nums`, find all unique triplets:

```text
[nums[i], nums[j], nums[k]]
```

such that:

```text
nums[i] + nums[j] + nums[k] = 0
```

The solution must not contain duplicate triplets.

**Difficulty:** Medium

**LeetCode:** 15

---

## Examples

### Example 1

```text
Input:
nums = [-1,0,1,2,-1,-4]

Output:
[
    [-1,-1,2],
    [-1,0,1]
]
```

Explanation:

The valid triplets are:

```text
-1 + -1 + 2 = 0
-1 + 0 + 1 = 0
```

---

### Example 2

```text
Input:
nums = [0,1,1]

Output:
[]
```

No three elements have sum `0`.

---

### Example 3

```text
Input:
nums = [0,0,0]

Output:
[
    [0,0,0]
]
```

Even though there are multiple ways to select the three zeros, only one unique triplet is returned.

---

## Approach

Use:

```text
Sorting + Two Pointers
```

First, sort the array.

Example:

```text
[-1,0,1,2,-1,-4]
```

After sorting:

```text
[-4,-1,-1,0,1,2]
```

Then fix one element using `i` and use two pointers:

```text
j = i + 1
k = n - 1
```

The three elements are:

```text
nums[i] + nums[j] + nums[k]
```

---

## Why Sort the Array?

Sorting makes the Two Pointer technique possible.

After sorting:

```text
[-4,-1,-1,0,1,2]
```

If:

```text
sum > 0
```

we need a smaller value.

So:

```text
k--
```

If:

```text
sum < 0
```

we need a larger value.

So:

```text
j++
```

If:

```text
sum == 0
```

we found a valid triplet.

---

## Two Pointer Logic

For a fixed `i`:

```text
j = i + 1
k = n - 1
```

Calculate:

```text
sum = nums[i] + nums[j] + nums[k]
```

### Case 1: `sum < 0`

The sum is too small.

Because the array is sorted, increase `j`:

```text
j++
```

This gives us a larger value.

---

### Case 2: `sum > 0`

The sum is too large.

Decrease `k`:

```text
k--
```

This gives us a smaller value.

---

### Case 3: `sum == 0`

A valid triplet is found:

```cpp
ans.push_back({nums[i], nums[j], nums[k]});
```

Then move both pointers:

```text
j++
k--
```

---

## Handling Duplicate Triplets

The problem requires **unique triplets**.

Suppose:

```text
[-1,-1,-1,0,1]
```

After finding a triplet, duplicate values of `nums[j]` should be skipped.

The code uses:

```cpp
while(j < k && nums[j] == nums[j-1])
    j++;
```

This prevents duplicate triplets.

---

## Dry Run

### Input

```text
nums = [-1,0,1,2,-1,-4]
```

After sorting:

```text
[-4,-1,-1,0,1,2]
```

---

### `i = 0`

```text
nums[i] = -4
j = 1
k = 5
```

Sum:

```text
-4 + (-1) + 2 = -3
```

Since:

```text
sum < 0
```

move:

```text
j++
```

Continue searching.

No valid triplet is found for `-4`.

---

### `i = 1`

```text
nums[i] = -1
j = 2
k = 5
```

Sum:

```text
-1 + (-1) + 2 = 0
```

Valid triplet:

```text
[-1,-1,2]
```

Add it to answer.

Move:

```text
j++
k--
```

Now:

```text
j = 3
k = 4
```

---

### Continue

Now:

```text
-1 + 0 + 1 = 0
```

Another valid triplet:

```text
[-1,0,1]
```

Add it.

Final answer:

```text
[
    [-1,-1,2],
    [-1,0,1]
]
```

---

## Important Observation

The outer loop can technically run while:

```cpp
i < n
```

but a more optimized implementation can stop at:

```cpp
i < n - 2
```

because at least three elements are required to form a triplet.

Also, duplicate values of `nums[i]` should ideally be skipped:

```cpp
if(i > 0 && nums[i] == nums[i-1])
    continue;
```

This prevents duplicate triplets more efficiently.

---

## Complexity Analysis

### Time Complexity

Sorting:

```text
O(n log n)
```

For every `i`, the two pointers traverse the remaining array:

```text
O(n)
```

for each iteration.

Therefore:

```text
O(n²)
```

dominates sorting.

Final:

```text
O(n²)
```

---

### Space Complexity

Ignoring the output:

```text
O(1)
```

The Two Pointer technique uses only a few variables.

However, the sorting implementation may use some internal stack space.

The returned answer itself requires:

```text
O(k)
```

where `k` is the number of triplets.

---

## Is This Approach Optimal?

Yes. ✅

The optimal known approach for the standard 3Sum problem is:

```text
Sorting + Two Pointers
```

with:

```text
Time  = O(n²)
```

This is much better than the brute-force approach:

```text
O(n³)
```

---

## Brute Force vs Optimal

### Brute Force

Use three nested loops:

```text
i
 └── j
      └── k
```

Complexity:

```text
O(n³)
```

---

### Optimized

Sort the array and use Two Pointers:

```text
i
 └── j → ← k
```

Complexity:

```text
O(n²)
```

Therefore, Two Pointers is preferred.

---

## Key Concepts

- Arrays
- Sorting
- Two Pointers
- Three Sum
- Duplicate Handling
- Fixed Pointer
- Left Pointer
- Right Pointer
- Target Sum
- Sorted Array
- Optimization
- Nested Loop + Two Pointer Combination

---

## Interview Tips

- First think about the brute-force `O(n³)` solution.
- Sorting allows the use of Two Pointers.
- Fix one element and solve the remaining **2Sum** problem.
- If `sum < 0`, increase `j`.
- If `sum > 0`, decrease `k`.
- If `sum == 0`, store the triplet.
- Always handle duplicates.
- Skip duplicate `i` values in the optimized implementation.
- Use:
  ```text
  i < n - 2
  ```
  because at least three elements are required.
- The optimal complexity is:
  ```text
  O(n²)
  ```

---

## Folder Structure

```text
Q17.3Sum/
├── README.md
└── three_sum.cpp
```

---

## Learning Outcomes

After solving this problem, you will understand:

- How sorting can enable the Two Pointer technique.
- How to reduce a 3Sum problem to repeated 2Sum searches.
- How to move pointers based on the current sum.
- How to handle duplicate triplets.
- How to improve an `O(n³)` solution to `O(n²)`.
- How to recognize Two Pointer patterns in interview problems.

---

## Status

✅ Solved
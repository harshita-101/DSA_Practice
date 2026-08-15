# Q11. Merge Sorted Array

## Problem Statement

You are given two integer arrays `nums1` and `nums2`, sorted in non-decreasing order.

The first array `nums1` has enough extra space at the end to hold all elements of `nums2`.

Merge `nums2` into `nums1` so that `nums1` becomes one sorted array.

The merge must be done **in-place**.

**Difficulty:** Easy

**LeetCode:** 88

---

## Examples

### Example 1

```text
Input:
nums1 = [1,2,3,0,0,0]
m = 3

nums2 = [2,5,6]
n = 3

Output:
[1,2,2,3,5,6]
```

Explanation:

The first `m` elements of `nums1` are valid:

```text
[1,2,3]
```

The last `n` positions are empty and are used to store elements from `nums2`.

After merging:

```text
[1,2,2,3,5,6]
```

---

### Example 2

```text
Input:
nums1 = [1]
m = 1

nums2 = []
n = 0

Output:
[1]
```

---

### Example 3

```text
Input:
nums1 = [0]
m = 0

nums2 = [1]
n = 1

Output:
[1]
```

---

## Approach

Use the **Two Pointer technique from the end**.

Instead of starting from the beginning, we start from the last valid elements of both arrays.

Three pointers are used:

```text
i = m - 1
j = n - 1
k = m + n - 1
```

Where:

- `i` → last valid element of `nums1`
- `j` → last element of `nums2`
- `k` → last available position of `nums1`

---

## Why Start From the End?

If we start merging from the beginning, elements already present in `nums1` may get overwritten.

For example:

```text
nums1 = [1,2,3,0,0,0]
nums2 = [2,5,6]
```

The empty positions are at the end.

Therefore, we place the **largest elements first** from right to left.

This prevents overwriting the existing elements of `nums1`.

---

## Algorithm

1. Initialize:
   ```text
   i = m - 1
   j = n - 1
   k = m + n - 1
   ```

2. Continue while `j >= 0`.

3. Compare:
   ```text
   nums1[i] and nums2[j]
   ```

4. If `nums1[i]` is greater:
   - Put `nums1[i]` at `nums1[k]`.
   - Decrease `i`.
   - Decrease `k`.

5. Otherwise:
   - Put `nums2[j]` at `nums1[k]`.
   - Decrease `j`.
   - Decrease `k`.

6. Continue until all elements of `nums2` are placed.

---

## Dry Run

### Input

```text
nums1 = [1,2,3,0,0,0]
m = 3

nums2 = [2,5,6]
n = 3
```

Initial pointers:

```text
i = 2
j = 2
k = 5
```

Array:

```text
nums1 = [1,2,3,0,0,0]
             ↑     ↑
             i     k

nums2 = [2,5,6]
             ↑
             j
```

---

### Step 1

Compare:

```text
nums1[i] = 3
nums2[j] = 6
```

`6` is larger.

Place `6` at `nums1[k]`:

```text
nums1 = [1,2,3,0,0,6]
```

Update:

```text
j--
k--
```

Now:

```text
i = 2
j = 1
k = 4
```

---

### Step 2

Compare:

```text
3 and 5
```

`5` is larger.

Place `5`:

```text
nums1 = [1,2,3,0,5,6]
```

Update:

```text
j--
k--
```

Now:

```text
i = 2
j = 0
k = 3
```

---

### Step 3

Compare:

```text
3 and 2
```

`3` is larger.

Place `3`:

```text
nums1 = [1,2,3,3,5,6]
```

Update:

```text
i--
k--
```

Now:

```text
i = 1
j = 0
k = 2
```

---

### Step 4

Compare:

```text
2 and 2
```

They are equal.

The `else` condition places `nums2[j]`:

```text
nums1 = [1,2,2,3,5,6]
```

Update:

```text
j--
k--
```

Now:

```text
i = 1
j = -1
k = 1
```

Since:

```text
j < 0
```

the loop stops.

Final array:

```text
[1,2,2,3,5,6]
```

---

## Why `while(j >= 0)`?

We only need to ensure that all elements of `nums2` are placed.

If:

```text
j < 0
```

then every element of `nums2` has already been placed.

The remaining elements of `nums1` are already in their correct positions.

Therefore, the loop only needs:

```text
j >= 0
```

---

## Important Condition

The comparison is:

```text
nums1[i] > nums2[j]
```

But we also need to make sure `i` is valid:

```text
i >= 0
```

Therefore:

```text
i >= 0 && nums1[i] > nums2[j]
```

If `i < 0`, we directly take the remaining elements from `nums2`.

---

## Complexity Analysis

### Time Complexity

```text
O(m + n)
```

Every element from both arrays is processed at most once.

Therefore, the total time complexity is:

```text
O(m + n)
```

---

### Space Complexity

```text
O(1)
```

No additional array or data structure is used for merging.

The elements are placed directly inside `nums1`.

---

## Why This Approach Is Optimal

A brute-force approach could create another array and merge the elements.

That would require:

```text
O(m + n)
```

extra space.

The two-pointer approach works directly inside `nums1`.

Therefore:

```text
Time  = O(m + n)
Space = O(1)
```

This is the optimal approach for the problem.

---

## Key Concepts

- Arrays
- Sorted Arrays
- Two Pointers
- In-Place Modification
- Reverse Traversal
- Merging
- Pointer Manipulation
- Non-Decreasing Order

---

## Interview Tips

- When merging into an array that has empty space at the end, consider working **from the back**.
- Use three pointers:
  ```text
  i = m - 1
  j = n - 1
  k = m + n - 1
  ```
- Always protect `i` from going negative.
- Continue until all elements of `nums2` are processed.
- The largest element should be placed first.
- This approach gives `O(m+n)` time and `O(1)` extra space.

---

## Folder Structure

```text
Q11.Merge_Sorted_Array/
├── README.md
└── merge_sorted_array.cpp
```

---

## Learning Outcomes

After solving this problem, you will understand:

- How to merge two sorted arrays efficiently.
- How to use multiple pointers.
- Why merging from the end avoids overwriting elements.
- How to perform in-place modifications.
- How to achieve `O(m+n)` time complexity.
- How to solve array merging problems using constant extra space.

---

## Status

✅ Solved
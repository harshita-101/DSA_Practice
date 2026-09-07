# Remove Duplicates from Sorted Array II

## Problem Statement

Given a sorted integer array `nums`, remove duplicates in-place such that each unique element appears at most **twice**.

The relative order of the elements should remain the same.

Return the number of elements remaining after removing the extra duplicates.

**Difficulty:** Medium  
**LeetCode:** 80

---

## Example

```text
Input:
nums = [1,1,1,2,2,3]

Output:
k = 5

Modified Array:
[1,1,2,2,3]
```

### Explanation

The number `1` appears three times in the original array.

Since each element can appear at most twice, one occurrence of `1` is removed.

The final array becomes:

```text
[1,1,2,2,3]
```

Therefore:

```text
k = 5
```

---

## Approach

Use the **Two Pointer Technique**.

Since the array is sorted, duplicate elements appear next to each other.

We use:

```text
i → Traverses the original array

k → Represents the position where the next valid element will be placed
```

Initially:

```text
k = 0
```

For every element, check the following condition:

```cpp
k < 2 || nums[i] != nums[k - 2]
```

### Why `k < 2`?

The first two elements can always be added because every element is allowed to appear at most twice.

### Why compare with `nums[k - 2]`?

Before adding a new element, we compare it with the element two positions behind the current valid position.

If both elements are equal, adding the current element would create a third duplicate.

Therefore, the element is skipped.

Otherwise:

```cpp
nums[k] = nums[i];
k++;
```

This places the valid element in the correct position.

---

## Algorithm

1. Initialize `k = 0`.
2. Traverse the array using index `i`.
3. If `k < 2`, add the current element.
4. Otherwise, compare `nums[i]` with `nums[k - 2]`.
5. If they are different, add the current element.
6. Increment `k` after adding a valid element.
7. Return `k`.

---

## Dry Run

Consider:

```text
nums = [1,1,1,2,2,3]
```

Initially:

```text
k = 0
```

### First Element: `1`

Since:

```text
k < 2
```

Add the element:

```text
nums = [1]
k = 1
```

### Second Element: `1`

Again:

```text
k < 2
```

Add the element:

```text
nums = [1,1]
k = 2
```

### Third Element: `1`

Compare:

```text
nums[i] = 1

nums[k - 2] = nums[0] = 1
```

Both are equal, so adding this element would create a third occurrence.

Skip it.

```text
k = 2
```

### Fourth Element: `2`

Compare:

```text
nums[i] = 2

nums[k - 2] = 1
```

They are different, so add `2`.

```text
nums = [1,1,2]
k = 3
```

Continue the same process for the remaining elements.

### Final Array

```text
[1,1,2,2,3]
```

### Output

```text
k = 5
```

---

## Complexity

Let `n` be the number of elements in the array.

| Time Complexity | Space Complexity |
|-----------------|------------------|
| O(n)            | O(1)             |

---

## Key Concepts

- Two Pointers
- Sorted Array
- In-Place Modification
- Duplicate Handling
- Array Traversal

---

## Status

✅ Solved
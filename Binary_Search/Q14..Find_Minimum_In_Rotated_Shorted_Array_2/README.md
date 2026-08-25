# Find Minimum in Rotated Sorted Array II

## Problem Statement

Given a rotated sorted array that may contain **duplicates**, find the minimum element.

**Difficulty:** Hard  
**LeetCode:** 154

---

## Example

```text
Input:
nums = [2,2,2,0,1]

Output:
0
```

---

## Approach

Use **Modified Binary Search**.

At every step compare:

```cpp
nums[mid]
```

with:

```cpp
nums[high]
```

### Cases

**1. `nums[mid] < nums[high]`**

The minimum is on the left side or at `mid`.

```cpp
high = mid;
```

**2. `nums[mid] > nums[high]`**

The minimum is on the right side.

```cpp
low = mid + 1;
```

**3. `nums[mid] == nums[high]`**

Duplicates make it impossible to determine the correct side.

```cpp
high--;
```

Continue until:

```text
low == high
```

Then:

```cpp
return nums[low];
```

---

## Algorithm

1. Initialize `low = 0` and `high = n - 1`.
2. Calculate `mid`.
3. Compare `nums[mid]` with `nums[high]`.
4. Move `low` or `high` accordingly.
5. If both values are equal, decrement `high`.
6. Return `nums[low]`.

---

## Complexity

| Case | Time | Space |
|------|------|-------|
| Average | O(log n) | O(1) |
| Worst | O(n) | O(1) |

> Worst-case `O(n)` occurs because of duplicates.

---

## Key Concepts

- Modified Binary Search
- Rotated Sorted Array
- Duplicate Handling
- Search Space Reduction
- Two Pointers

---

## Status

✅ Solved
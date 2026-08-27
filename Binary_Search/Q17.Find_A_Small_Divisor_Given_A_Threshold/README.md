# Find the Smallest Divisor Given a Threshold

## Problem Statement

Given an integer array `nums` and an integer `threshold`, find the **smallest positive integer divisor** such that the sum of:

```text
ceil(nums[i] / divisor)
```

for every element is less than or equal to `threshold`.

**Difficulty:** Medium  
**LeetCode:** 1283

---

## Example

```text
Input:
nums = [1,2,5,9]
threshold = 6

Output:
5
```

Explanation:

```text
ceil(1/5) + ceil(2/5) + ceil(5/5) + ceil(9/5)
= 1 + 1 + 1 + 2
= 5
```

Since `5 <= 6`, divisor `5` is valid.

---

## Approach

Use **Binary Search on Answer**.

The possible divisor lies between:

```text
1 to max(nums)
```

For each `mid`, calculate:

```cpp
(nums[i] + mid - 1) / mid
```

which gives:

```text
ceil(nums[i] / mid)
```

### Cases

**1. `sum <= threshold`**

The divisor is valid. Try a smaller divisor:

```cpp
high = mid - 1;
```

**2. `sum > threshold`**

The divisor is too small. Try a larger divisor:

```cpp
low = mid + 1;
```

Finally, `low` is the smallest valid divisor.

---

## Algorithm

1. Set `low = 1`.
2. Set `high = max(nums)`.
3. Calculate `mid`.
4. Calculate the required sum using `mid` as divisor.
5. If the sum is within the threshold, search left.
6. Otherwise, search right.
7. Return `low`.

---

## Complexity

Let `n` be the number of elements and `M = max(nums)`.

| Time Complexity | Space Complexity |
|-----------------|------------------|
| O(n log M)      | O(1)             |

---

## Key Concepts

- Binary Search on Answer
- Ceiling Division
- Search Space Reduction
- Monotonic Function
- Array Traversal

---

## Status

✅ Solved
# Split Array Largest Sum

## Problem Statement

Given an integer array `nums` and an integer `k`, split the array into `k` non-empty continuous subarrays such that the **largest sum among these subarrays is minimized**.

Return the minimized largest sum.

**Difficulty:** Hard  
**LeetCode:** 410

---

## Example

```text
Input:
nums = [7,2,5,10,8]
k = 2

Output:
18
```

Possible split:

```text
[7,2,5] [10,8]
```

Sums:

```text
14 and 18
```

The largest sum is:

```text
18
```

---

## Approach

Use **Binary Search on Answer**.

The possible answer lies between:

```text
max(nums) → sum(nums)
```

### Why?

- Minimum possible largest sum is at least the largest element.
- Maximum possible largest sum is the sum of all elements.

For every `mid`, check how many subarrays are required if the maximum allowed sum is `mid`.

### Cases

**1. `subarrays <= k`**

The current maximum sum is possible. Try a smaller value:

```cpp
high = mid - 1;
```

**2. `subarrays > k`**

The current maximum sum is too small. Increase it:

```cpp
low = mid + 1;
```

Finally, `low` is the minimum possible largest sum.

---

## Algorithm

1. Set `low = max(nums)`.
2. Set `high = sum(nums)`.
3. Calculate `mid`.
4. Greedily create subarrays while keeping their sum `<= mid`.
5. Count the required subarrays.
6. If `subarrays <= k`, search left.
7. Otherwise, search right.
8. Return `low`.

---

## Complexity

Let `n` be the number of elements and `S` be the sum of all elements.

| Time Complexity | Space Complexity |
|-----------------|------------------|
| O(n log S)      | O(1)             |

---

## Key Concepts

- Binary Search on Answer
- Greedy Approach
- Subarray Partitioning
- Feasibility Check
- Search Space Reduction
- Continuous Subarrays

---

## Status

✅ Solved
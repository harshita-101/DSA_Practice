# Capacity To Ship Packages Within D Days

## Problem Statement

Given an array `weights` where `weights[i]` represents the weight of the `i-th` package, find the **minimum ship capacity** required to ship all packages within `days` days.

Packages must be shipped in the given order.

**Difficulty:** Medium  
**LeetCode:** 1011

---

## Example

```text
Input:
weights = [1,2,3,4,5,6,7,8,9,10]
days = 5

Output:
15
```

With a ship capacity of `15`, all packages can be shipped within `5` days.

---

## Approach

Use **Binary Search on Answer**.

The possible capacity lies between:

```text
max(weights) → sum(weights)
```

### Why?

- Minimum capacity must be at least the **maximum package weight**.
- Maximum capacity can be the **sum of all weights**, allowing all packages to be shipped in one day.

For every `mid` capacity, calculate how many days are required.

### Cases

**1. `requiredDays <= days`**

The capacity is sufficient. Try a smaller capacity:

```cpp
high = mid - 1;
```

**2. `requiredDays > days`**

The capacity is too small. Increase it:

```cpp
low = mid + 1;
```

Finally, `low` gives the minimum required capacity.

---

## Algorithm

1. Set `low = max(weights)`.
2. Set `high = sum(weights)`.
3. Calculate `mid` as the possible capacity.
4. Simulate shipping packages using this capacity.
5. Count the required number of days.
6. If possible within `days`, search for a smaller capacity.
7. Otherwise, increase the capacity.
8. Return `low`.

---

## Complexity

Let `n` be the number of packages and `S` be the sum of all weights.

| Time Complexity | Space Complexity |
|-----------------|------------------|
| O(n log S)      | O(1)             |

---

## Key Concepts

- Binary Search on Answer
- Greedy Approach
- Search Space Reduction
- Capacity Feasibility
- Array Traversal

---

## Status

✅ Solved
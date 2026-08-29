# Minimum Number of Days to Make M Bouquets

## Problem Statement

Given an integer array `bloomDay`, where `bloomDay[i]` represents the day on which the `i-th` flower blooms, find the **minimum number of days** needed to make exactly `m` bouquets.

Each bouquet requires `k` **adjacent flowers**, and a flower can be used in only one bouquet.

If it is impossible to make the required bouquets, return `-1`.

**Difficulty:** Medium  
**LeetCode:** 1482

---

## Example

```text
Input:
bloomDay = [1,10,3,10,2]
m = 3
k = 1

Output:
3
```

By day `3`, flowers at positions:

```text
[1, 3, 2]
```

have bloomed, so 3 bouquets can be made.

---

## Approach

Use **Binary Search on Answer**.

The possible number of days lies between:

```text
min(bloomDay) → max(bloomDay)
```

For each `mid`, check how many bouquets can be made by that day.

### Cases

**1. `bloomDay[i] <= mid`**

The flower has bloomed:

```cpp
consecutive++;
```

When:

```cpp
consecutive == k
```

one bouquet is formed:

```cpp
bouquets++;
consecutive = 0;
```

**2. `bloomDay[i] > mid`**

The flower has not bloomed, so consecutive flowers are broken:

```cpp
consecutive = 0;
```

### Binary Search

If:

```cpp
bouquets >= m
```

the required bouquets can be made, so try fewer days:

```cpp
high = mid - 1;
```

Otherwise:

```cpp
low = mid + 1;
```

Finally, `low` is the minimum required number of days.

---

## Impossible Case

Each bouquet needs `k` flowers.

Therefore, total flowers required are:

```text
m × k
```

If:

```cpp
m * k > n
```

it is impossible to make the bouquets.

So return:

```cpp
-1;
```

`long long` is used to safely handle the multiplication.

---

## Algorithm

1. Check whether `m * k > n`.
2. Set `low = min(bloomDay)`.
3. Set `high = max(bloomDay)`.
4. Calculate `mid`.
5. Count possible bouquets by day `mid`.
6. If at least `m` bouquets are possible, search left.
7. Otherwise, search right.
8. Return `low`.

---

## Complexity

Let `n` be the number of flowers and `D` be the range of blooming days.

| Time Complexity | Space Complexity |
|-----------------|------------------|
| O(n log D)      | O(1)             |

---

## Key Concepts

- Binary Search on Answer
- Greedy Approach
- Consecutive Elements
- Feasibility Check
- Search Space Reduction
- Array Traversal

---

## Status

✅ Solved
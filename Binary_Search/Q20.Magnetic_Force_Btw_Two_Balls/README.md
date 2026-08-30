# Magnetic Force Between Two Balls

## Problem Statement

Given an array `position` representing the positions of baskets and an integer `m`, place `m` balls in different baskets such that the **minimum distance between any two balls is maximized**.

**Difficulty:** Medium  
**LeetCode:** 1552

---

## Example

```text
Input:
position = [1,2,3,4,7]
m = 3

Output:
3
```

One possible placement:

```text
1, 4, 7
```

The minimum distance is:

```text
min(4-1, 7-4) = 3
```

---

## Approach

Use **Binary Search on Answer**.

First sort the positions:

```cpp
sort(position.begin(), position.end());
```

The possible minimum distance lies between:

```text
1 → maxPosition - minPosition
```

For every `mid`, check whether it is possible to place `m` balls with at least `mid` distance between them.

### Feasibility Check

Start by placing the first ball at:

```cpp
position[0]
```

Then greedily place the next ball at the earliest position satisfying:

```cpp
position[i] - lastposition >= mid
```

If we can place at least `m` balls:

```cpp
count >= m
```

then `mid` is possible, so try a larger distance:

```cpp
low = mid + 1;
```

Otherwise, try a smaller distance:

```cpp
high = mid - 1;
```

Finally, `high` gives the maximum possible minimum distance.

---

## Algorithm

1. Sort the positions.
2. Set `low = 1`.
3. Set `high = maxPosition - minPosition`.
4. Calculate `mid`.
5. Greedily count how many balls can be placed with distance `mid`.
6. If `count >= m`, search for a larger distance.
7. Otherwise, search for a smaller distance.
8. Return `high`.

---

## Complexity

| Time Complexity | Space Complexity |
|-----------------|------------------|
| O(n log n + n log D) | O(1) |

Where `D` is the range between the minimum and maximum position.

---

## Key Concepts

- Binary Search on Answer
- Greedy Approach
- Sorting
- Feasibility Check
- Maximum Minimum Distance
- Search Space Reduction

---

## Status

✅ Solved
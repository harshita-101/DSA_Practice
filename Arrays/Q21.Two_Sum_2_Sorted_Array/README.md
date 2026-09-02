# Two Sum II - Input Array Is Sorted

## Problem Statement

Given a **1-indexed sorted array** of integers `numbers` and an integer `target`, find two numbers such that their sum is equal to `target`.

Return the indices of the two numbers as:

```text
[index1, index2]
```

The returned indices should be **1-indexed**.

**Difficulty:** Medium  
**LeetCode:** 167

---

## Example

```text
Input:
numbers = [2,7,11,15]
target = 9

Output:
[1,2]
```

### Explanation

The elements at index `1` and index `2` are:

```text
2 + 7 = 9
```

Therefore, the answer is:

```text
[1,2]
```

---

## Approach

Use the **Two Pointer Technique**.

Since the array is already sorted, we can use two pointers:

```text
low  → Starting from the beginning
high → Starting from the end
```

Calculate the sum of the elements at both pointers.

### Cases

**1. Sum is equal to target**

```text
numbers[low] + numbers[high] == target
```

The required pair is found.

---

**2. Sum is greater than target**

Move the `high` pointer to the left:

```cpp
high--;
```

This decreases the sum because the array is sorted.

---

**3. Sum is smaller than target**

Move the `low` pointer to the right:

```cpp
low++;
```

This increases the sum because the array is sorted.

---

Finally, return the indices after converting them to **1-indexing**:

```cpp
{low + 1, high + 1}
```

---

## Algorithm

1. Initialize `low = 0`.
2. Initialize `high = n - 1`.
3. Calculate the sum of `numbers[low]` and `numbers[high]`.
4. If the sum equals `target`, stop.
5. If the sum is greater than `target`, decrement `high`.
6. If the sum is smaller than `target`, increment `low`.
7. Return `{low + 1, high + 1}`.

---

## Dry Run

Consider:

```text
numbers = [2,7,11,15]
target = 9
```

Initially:

```text
low = 0
high = 3
```

Calculate:

```text
numbers[0] + numbers[3]

2 + 15 = 17
```

Since:

```text
17 > 9
```

Move `high` to the left.

```text
low = 0
high = 2
```

Calculate:

```text
2 + 11 = 13
```

Again:

```text
13 > 9
```

Move `high` to the left.

```text
low = 0
high = 1
```

Calculate:

```text
2 + 7 = 9
```

The target is found.

Since the answer requires 1-indexing:

```text
low + 1 = 1
high + 1 = 2
```

### Output

```text
[1,2]
```

---

## Complexity

Let `n` be the number of elements in the array.

| Time Complexity | Space Complexity |
|-----------------|------------------|
| O(n)            | O(1)             |

---

## Key Concepts

- Two Pointer Technique
- Sorted Array
- Search Space Reduction
- Array Traversal
- 1-Based Indexing

---

## Status

✅ Solved
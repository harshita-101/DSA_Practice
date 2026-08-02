# Q2. Search Insert Position

## Problem Statement

Given a sorted array of distinct integers and a target value, return the index if the target is found. If not, return the index where it would be inserted while maintaining the sorted order.

**LeetCode:** 35 - Search Insert Position

**Difficulty:** Easy

---

## Examples

### Example 1

```text
Input:
nums = [1,3,5,6]
target = 5

Output:
2
```

### Example 2

```text
Input:
nums = [1,3,5,6]
target = 2

Output:
1
```

### Example 3

```text
Input:
nums = [1,3,5,6]
target = 7

Output:
4
```

### Example 4

```text
Input:
nums = [1,3,5,6]
target = 0

Output:
0
```

---

## Approach

- Since the array is sorted, Binary Search can be used.
- If the target is found, return its index.
- If the target is not found, continue the search until the loop ends.
- After the loop, `low` points to the correct position where the target should be inserted.
- Return `low`.

---

## Algorithm

1. Initialize `low = 0` and `high = n - 1`.
2. Find the middle element.
3. If `nums[mid] == target`, return `mid`.
4. If `nums[mid] < target`, search in the right half.
5. Otherwise, search in the left half.
6. If the target is not found, return `low`.

---

## Complexity Analysis

**Time Complexity:** `O(log n)`

**Space Complexity:** `O(1)`

---

## Key Concepts

- Binary Search
- Sorted Array
- Search Space Reduction
- Insert Position
- Overflow-safe Mid Calculation

---

## Interview Tips

- Binary Search works only on sorted data.
- Always calculate mid as:

```cpp
mid = low + (high - low) / 2;
```

- If the target is not present, `low` gives the correct insertion index.
- Returning `high` would be incorrect because it points to the last element smaller than the target.

---

## Folder Structure

```
Q2.Search_Insert_Position/
├── README.md
└── search_insert_position.cpp
```

---

## Status

✅ Solved
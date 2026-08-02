# Q4. Search in Rotated Sorted Array

## Problem Statement

There is an integer array `nums` sorted in ascending order. Before being passed to your function, the array is rotated at an unknown pivot.

Given the rotated array and a target value, return its index. If the target is not found, return `-1`.

**LeetCode:** 33 - Search in Rotated Sorted Array

**Difficulty:** Medium

---

## Examples

### Example 1

```text
Input:
nums = [4,5,6,7,0,1,2]
target = 0

Output:
4
```

### Example 2

```text
Input:
nums = [4,5,6,7,0,1,2]
target = 3

Output:
-1
```

### Example 3

```text
Input:
nums = [1]
target = 0

Output:
-1
```

---

## Approach

A normal Binary Search cannot be used because the array is rotated.

At every iteration:

- Check if the left half is sorted.
- If the left half is sorted, determine whether the target lies in that range.
- Otherwise, search in the right half.
- If the left half is not sorted, then the right half must be sorted.
- Check whether the target belongs to the right sorted half.
- Discard the half that cannot contain the target.

This way, half of the search space is eliminated in every iteration.

---

## Algorithm

1. Initialize `low` and `high`.
2. Find the middle element.
3. If `nums[mid] == target`, return `mid`.
4. Check whether the left half is sorted.
5. If the left half is sorted:
   - If the target lies within the left half, move left.
   - Otherwise, move right.
6. Otherwise, the right half is sorted:
   - If the target lies within the right half, move right.
   - Otherwise, move left.
7. If the target is not found, return `-1`.

---

## Complexity Analysis

**Time Complexity:** `O(log n)`

**Space Complexity:** `O(1)`

---

## Key Concepts

- Binary Search
- Rotated Sorted Array
- Sorted Half Identification
- Search Space Reduction
- Decision Making using Binary Search

---

## Important Conditions

### Left Half is Sorted

```cpp
arr[low] <= arr[mid]
```

Target lies in the left half if:

```cpp
arr[low] <= target && target < arr[mid]
```

---

### Right Half is Sorted

Target lies in the right half if:

```cpp
arr[mid] < target && target <= arr[high]
```

---

## Interview Tips

- A rotated sorted array always has one sorted half.
- First identify the sorted half, then decide whether the target belongs to it.
- Never perform a linear search.
- Use the overflow-safe formula for calculating the middle index:

```cpp
mid = low + (high - low) / 2;
```

---

## Folder Structure

```
Q4.Search_In_Rotated_Sorted_Array/
├── README.md
└── search_in_rotated_sorted_array.cpp
```

---

## Learning Outcomes

After solving this problem, you will understand:

- How Binary Search works on rotated arrays
- How to identify the sorted half
- How to eliminate half of the search space efficiently
- How to solve interview-level Binary Search problems

---

## Status

✅ Solved
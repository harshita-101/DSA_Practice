# Q5. Find Minimum in Rotated Sorted Array

## Problem Statement

Suppose an array of unique integers sorted in ascending order is rotated between `1` and `n` times.

Find the minimum element in the array.

You must write an algorithm that runs in **O(log n)** time.

**LeetCode:** 153 - Find Minimum in Rotated Sorted Array

**Difficulty:** Medium

---

## Examples

### Example 1

```text
Input:
nums = [3,4,5,1,2]

Output:
1
```

### Example 2

```text
Input:
nums = [4,5,6,7,0,1,2]

Output:
0
```

### Example 3

```text
Input:
nums = [11,13,15,17]

Output:
11
```

---

## Approach

The array is rotated but one half of the array is always sorted.

At every iteration:

- If the current search space is already sorted, the first element is the minimum.
- Otherwise, determine which half is sorted.
- If the left half is sorted:
  - Store its minimum (`arr[low]`).
  - Search in the right half.
- Otherwise:
  - The minimum may be at `mid` or in the left half.
  - Store `arr[mid]`.
  - Search in the left half.

Repeat until the minimum element is found.

---

## Algorithm

1. Initialize `low`, `high`, and `ans`.
2. While `low <= high`:
   - If the current range is sorted:
     - Update the answer with `arr[low]`.
     - Break.
   - Find the middle element.
   - If the left half is sorted:
     - Update the answer using `arr[low]`.
     - Move to the right half.
   - Otherwise:
     - Update the answer using `arr[mid]`.
     - Move to the left half.
3. Return `ans`.

---

## Complexity Analysis

**Time Complexity:** `O(log n)`

**Space Complexity:** `O(1)`

---

## Key Concepts

- Binary Search
- Rotated Sorted Array
- Sorted Half Identification
- Minimum Element Search
- Search Space Reduction

---

## Important Conditions

### Current Search Space is Sorted

```cpp
if(arr[low] <= arr[high])
```

Action:

```cpp
ans = min(ans, arr[low]);
break;
```

---

### Left Half is Sorted

```cpp
if(arr[low] <= arr[mid])
```

Action:

```cpp
ans = min(ans, arr[low]);
low = mid + 1;
```

---

### Right Half is Sorted

```cpp
else
```

Action:

```cpp
ans = min(ans, arr[mid]);
high = mid - 1;
```

---

## Interview Tips

- Always check whether the current search space is already sorted.
- In a sorted half, the first element is always the minimum of that half.
- Never use Linear Search because the required complexity is `O(log n)`.
- Use the overflow-safe middle calculation:

```cpp
mid = low + (high - low) / 2;
```

---

## Folder Structure

```
Q5.Find_Minimum_in_Rotated_Sorted_Array/
├── README.md
└── find_minimum_in_rotated_sorted_array.cpp
```

---

## Learning Outcomes

After solving this problem, you will understand:

- How to identify a sorted half in a rotated array
- How to find the minimum element using Binary Search
- How to eliminate half of the search space in every iteration
- How to solve interview-level Binary Search problems efficiently

---

## Status

✅ Solved
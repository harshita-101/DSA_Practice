# Q6. Find Rotation Count in Rotated Sorted Array

## Problem Statement

Given a sorted array that has been rotated an unknown number of times, find how many times the array has been rotated.

The rotation count is equal to the index of the minimum element.

You must solve the problem in **O(log n)** time.

**Difficulty:** Medium

---

## Examples

### Example 1

```text
Input:
arr = [4,5,6,7,0,1,2]

Output:
4
```

Explanation:

Original Array:

```text
0 1 2 4 5 6 7
```

After rotating 4 times:

```text
4 5 6 7 0 1 2
```

Hence, the answer is **4**.

---

### Example 2

```text
Input:
arr = [3,4,5,1,2]

Output:
3
```

---

### Example 3

```text
Input:
arr = [1,2,3,4,5]

Output:
0
```

The array is already sorted, so it has been rotated **0** times.

---

## Approach

The index of the minimum element is equal to the number of rotations.

Using Binary Search:

- If the current search space is already sorted, its first element is the minimum.
- Otherwise, determine which half is sorted.
- Keep track of the index having the smallest value encountered.
- Continue searching only in the unsorted half.

---

## Algorithm

1. Initialize `low`, `high`, and `ans`.
2. While `low <= high`:
   - Find the middle index.
   - If the current range is already sorted:
     - Update the answer if needed.
     - Break.
   - If the left half is sorted:
     - Update the answer using `low`.
     - Search the right half.
   - Otherwise:
     - Update the answer using `mid`.
     - Search the left half.
3. Return `ans`.

---

## Complexity Analysis

**Time Complexity:** `O(log n)`

**Space Complexity:** `O(1)`

---

## Key Concepts

- Binary Search
- Rotated Sorted Array
- Minimum Element Index
- Rotation Count
- Search Space Reduction

---

## Important Conditions

### Current Search Space is Sorted

```cpp
if(arr[low] <= arr[high])
```

Action:

```cpp
if(arr[low] < arr[ans])
    ans = low;
break;
```

---

### Left Half is Sorted

```cpp
if(arr[low] <= arr[mid])
```

Action:

```cpp
if(arr[low] < arr[ans])
    ans = low;

low = mid + 1;
```

---

### Right Half is Sorted

```cpp
else
```

Action:

```cpp
if(arr[mid] < arr[ans])
    ans = mid;

high = mid - 1;
```

---

## Interview Tips

- Rotation Count = Index of Minimum Element.
- One half of the array is always sorted.
- Always use Binary Search instead of Linear Search.
- Use overflow-safe middle calculation.

```cpp
mid = low + (high - low) / 2;
```

---

## Folder Structure

```
Q6.Find_Rotation_Count/
├── README.md
└── rotation_count.cpp
```

---

## Learning Outcomes

After solving this problem, you will understand:

- How to find the rotation count using Binary Search.
- How to identify the sorted half of a rotated array.
- How to maintain the index of the minimum element.
- How to reduce the search space efficiently.

---

## Status

✅ Solved
# Q3. Find First and Last Position of Element in Sorted Array

## Problem Statement

Given a sorted array of integers `nums` (sorted in non-decreasing order) and a target value, return the starting and ending position of the target.

If the target is not found in the array, return:

```cpp
{-1, -1}
```

**LeetCode:** 34 - Find First and Last Position of Element in Sorted Array

**Difficulty:** Medium

---

## Examples

### Example 1

```text
Input:
nums = [5,7,7,8,8,10]
target = 8

Output:
[3,4]
```

### Example 2

```text
Input:
nums = [5,7,7,8,8,10]
target = 6

Output:
[-1,-1]
```

### Example 3

```text
Input:
nums = []
target = 0

Output:
[-1,-1]
```

---

## Approach

This problem cannot be solved using a normal Binary Search because the target may appear multiple times.

We perform **two modified Binary Searches**:

1. Find the **First Occurrence**
2. Find the **Last Occurrence**

### First Occurrence

- If `nums[mid] == target`
  - Store `mid` as the current answer.
  - Continue searching on the left side.

### Last Occurrence

- If `nums[mid] == target`
  - Store `mid` as the current answer.
  - Continue searching on the right side.

Finally, return both indices.

---

## Algorithm

### First Occurrence

1. Initialize `low`, `high`, and `ans = -1`.
2. Apply Binary Search.
3. If target is found:
   - Store `mid` in `ans`.
   - Move left (`high = mid - 1`).
4. Return `ans`.

### Last Occurrence

1. Initialize `low`, `high`, and `ans = -1`.
2. Apply Binary Search.
3. If target is found:
   - Store `mid` in `ans`.
   - Move right (`low = mid + 1`).
4. Return `ans`.

---

## Complexity Analysis

### Time Complexity

```
O(log n) + O(log n) = O(log n)
```

### Space Complexity

```
O(1)
```

---

## Key Concepts

- Binary Search
- Modified Binary Search
- First Occurrence
- Last Occurrence
- Duplicate Elements
- Sorted Array

---

## Interview Tips

- Do not return immediately when the target is found.
- Store the answer and continue searching.
- For First Occurrence:
  - Move to the left.
- For Last Occurrence:
  - Move to the right.
- Two Binary Searches still give an overall complexity of **O(log n)**.

---

## Folder Structure

```
Q3.Find_First_And_Last_Position/
├── README.md
└── first_last_position.cpp
```

---

## Learning Outcomes

After solving this problem, you will understand:

- Modified Binary Search
- Searching in arrays with duplicate elements
- Finding boundary positions
- How to customize Binary Search for interview questions

---

## Status

✅ Solved
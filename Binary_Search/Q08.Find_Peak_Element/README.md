# Q8. Find Peak Element

## Problem Statement

Given an integer array `nums`, find a **peak element** and return its index.

A peak element is an element that is **strictly greater** than its adjacent elements.

You may assume that:

```
nums[-1] = -∞
nums[n] = -∞
```

The array may contain multiple peak elements. Return the index of **any one** of them.

The solution must run in **O(log n)** time.

**Difficulty:** Medium

**LeetCode:** 162

---

## Examples

### Example 1

```text
Input:
nums = [1,2,3,1]

Output:
2
```

Explanation

```
1 2 3 1
    ↑
Peak Element = 3
```

---

### Example 2

```text
Input:
nums = [1,2,1,3,5,6,4]

Output:
5
```

Explanation

```
1 2 1 3 5 6 4
          ↑
Peak Element = 6
```

Another valid answer is index **1** because **2** is also a peak.

---

## Approach

A peak element always exists.

Using Binary Search:

- If the middle element is greater than both neighbours, it is the answer.
- If the sequence is increasing (`nums[mid-1] < nums[mid]`), a peak must exist on the right side.
- Otherwise, a peak lies on the left side.

---

## Algorithm

1. If the array contains only one element, return index `0`.
2. Check whether the first element is a peak.
3. Check whether the last element is a peak.
4. Perform Binary Search on indices `1` to `n-2`.
5. If middle element is greater than both neighbours, return its index.
6. If the left neighbour is smaller, search the right half.
7. Otherwise search the left half.

---

## Important Conditions

### Only One Element

```cpp
if(n == 1)
    return 0;
```

---

### First Element is Peak

```cpp
if(nums[0] > nums[1])
    return 0;
```

---

### Last Element is Peak

```cpp
if(nums[n-1] > nums[n-2])
    return n-1;
```

---

### Peak Found

```cpp
if(nums[mid-1] < nums[mid] &&
   nums[mid] > nums[mid+1])
{
    return mid;
}
```

---

### Increasing Slope

```cpp
if(nums[mid-1] < nums[mid])
{
    start = mid + 1;
}
```

Move towards the right half because a peak must exist there.

---

### Decreasing Slope

```cpp
else
{
    end = mid - 1;
}
```

Move towards the left half.

---

## Dry Run

Input

```text
[1,2,3,1]
```

```
start = 1
end = 2

mid = 1

2 < 3

Search Right

mid = 2

Peak Found

Return 2
```

---

## Complexity Analysis

**Time Complexity:** `O(log n)`

**Space Complexity:** `O(1)`

---

## Key Concepts

- Binary Search
- Peak Element
- Increasing Slope
- Decreasing Slope
- Search Space Reduction

---

## Interview Tips

- A peak element always exists.
- Multiple peaks may exist.
- Returning the index of any one peak is accepted.
- Binary Search is the expected interview solution.
- Always calculate the middle index safely.

```cpp
mid = start + (end - start) / 2;
```

---

## Folder Structure

```
Q8.Find_Peak_Element/
├── README.md
└── find_peak_element.cpp
```

---

## Learning Outcomes

After solving this problem, you will understand:

- Binary Search on mountain-like patterns.
- Identifying increasing and decreasing slopes.
- Finding a peak in logarithmic time.
- Search Space Reduction techniques.

---

## Status

✅ Solved
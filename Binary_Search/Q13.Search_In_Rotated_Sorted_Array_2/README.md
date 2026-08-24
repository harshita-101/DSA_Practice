# Search in Rotated Sorted Array II

## Problem Statement

You are given an integer array `nums` that was originally sorted in ascending order and then rotated at an unknown position.

The array may contain **duplicate values**.

Given a target value, return:

```text
true
```

if the target exists in the array, otherwise return:

```text
false
```

**Difficulty:** Medium

**LeetCode:** 81

---

## Example

### Example 1

```text
Input:
nums = [2,5,6,0,0,1,2]
target = 0

Output:
true
```

---

### Example 2

```text
Input:
nums = [2,5,6,0,0,1,2]
target = 3

Output:
false
```

---

## What is a Rotated Sorted Array?

Suppose the original sorted array is:

```text
[0,1,2,4,5,6,7]
```

After rotation:

```text
[4,5,6,7,0,1,2]
```

The array is still made of two sorted parts:

```text
[4,5,6,7] [0,1,2]
```

The challenge is to search in this rotated array using Binary Search.

---

## Approach

Use:

```text
Modified Binary Search
```

At every step:

1. Calculate `mid`.
2. Check whether `nums[mid]` is the target.
3. Handle the special case where:
   ```text
   nums[left] == nums[mid] == nums[right]
   ```
4. Determine which half is sorted.
5. Check whether the target lies inside the sorted half.
6. Eliminate the unnecessary half.
7. Repeat until the target is found or the search space becomes empty.

---

## Why Do We Need Special Handling for Duplicates?

Consider:

```text
[1,0,1,1,1]
```

Suppose:

```text
nums[left] == nums[mid] == nums[right]
```

Then we cannot determine which half is sorted.

For example:

```text
left = 0
mid  = 2
right = 4
```

Values:

```text
1 0 1 1 1
```

Both sides may appear valid because of duplicate values.

Therefore, shrink the search space:

```cpp
left++;
right--;
```

This is the key difference between **Search in Rotated Sorted Array** and **Search in Rotated Sorted Array II**.

---

## Special Duplicate Case

The code uses:

```cpp
else if(nums[left] == nums[mid] && nums[mid] == nums[right])
{
    left++;
    right--;
}
```

This removes duplicate boundary elements when we cannot determine the sorted half.

---

## Finding the Sorted Half

After handling duplicates, one of the two halves must be sorted.

### Case 1: Left Half is Sorted

Check:

```cpp
nums[left] <= nums[mid]
```

If true:

```text
left half is sorted
```

For example:

```text
[4,5,6,7,0,1,2]
 ↑     ↑
left  mid
```

The left portion:

```text
[4,5,6,7]
```

is sorted.

---

## Check Whether Target Lies in Left Half

If:

```cpp
target >= nums[left] && target <= nums[mid]
```

then the target lies inside the sorted left half.

So:

```cpp
right = mid - 1;
```

Otherwise:

```cpp
left = mid + 1;
```

---

## Case 2: Right Half is Sorted

If the left half is not sorted, the right half must be sorted.

For example:

```text
[6,7,0,1,2,4,5]
     ↑   ↑
    mid right
```

The right portion:

```text
[1,2,4,5]
```

is sorted.

Check:

```cpp
target >= nums[mid] && target <= nums[right]
```

If true:

```cpp
left = mid + 1;
```

Otherwise:

```cpp
right = mid - 1;
```

---

## Algorithm

1. Initialize:
   ```text
   left = 0
   right = n - 1
   ```
2. While:
   ```text
   left <= right
   ```
3. Calculate:
   ```cpp
   mid = left + (right - left) / 2;
   ```
4. If:
   ```cpp
   nums[mid] == target
   ```
   return `true`.
5. If:
   ```text
   nums[left] == nums[mid] == nums[right]
   ```
   shrink:
   ```text
   left++
   right--
   ```
6. Otherwise, check whether the left half is sorted.
7. If the target lies in the sorted half, search there.
8. Otherwise search the other half.
9. If the loop ends, return `false`.

---

## Dry Run

### Input

```text
nums = [2,5,6,0,0,1,2]
target = 0
```

Initial:

```text
left = 0
right = 6
```

Array:

```text
[2,5,6,0,0,1,2]
 ↑     ↑       ↑
 L     M       R
```

### Step 1

```text
mid = 3
nums[mid] = 0
```

Target:

```text
0
```

Since:

```text
nums[mid] == target
```

return:

```text
true
```

---

## Dry Run with Duplicate Case

Consider:

```text
nums = [1,1,1,1,2,1,1]
target = 2
```

Initially:

```text
left = 0
mid = 3
right = 6
```

Values:

```text
nums[left] = 1
nums[mid]  = 1
nums[right] = 1
```

Therefore:

```text
nums[left] == nums[mid] == nums[right]
```

We cannot identify the sorted half.

So:

```text
left++
right--
```

Now the search space becomes smaller.

Eventually the algorithm reaches:

```text
2
```

and returns:

```text
true
```

---

## Why Binary Search Works Here?

Even though the complete array is rotated, at least one half of the current search range is sorted whenever:

```text
nums[left], nums[mid], nums[right]
```

are not all equal.

We use this sorted half to decide where the target can exist.

This allows us to eliminate half of the search space in the normal case.

---

## Complexity Analysis

### Average Time Complexity

```text
O(log n)
```

In the normal case, the search space is reduced approximately by half.

---

### Worst-Case Time Complexity

```text
O(n)
```

Because duplicates can prevent us from determining which half is sorted.

For example:

```text
[1,1,1,1,1,1,1]
```

We may repeatedly perform:

```cpp
left++;
right--;
```

Therefore, the worst case becomes:

```text
O(n)
```

---

### Space Complexity

Only a few variables are used:

```text
left
right
mid
```

Therefore:

```text
O(1)
```

auxiliary space.

---

## Complexity Summary

| Case | Time Complexity | Space Complexity |
|------|-----------------|------------------|
| Average Case | O(log n) | O(1) |
| Worst Case | O(n) | O(1) |

---

## Is This Approach Optimal?

Yes. ✅

The standard approach for this problem is:

```text
Modified Binary Search
```

It provides:

```text
Average Time = O(log n)
Worst Time   = O(n)
Space        = O(1)
```

The `O(n)` worst case is caused by duplicates and is unavoidable for this comparison-based approach in the general problem.

---

## Difference from Search in Rotated Sorted Array

### Search in Rotated Sorted Array

Duplicates are not present.

```text
Time = O(log n)
```

### Search in Rotated Sorted Array II

Duplicates are allowed.

```text
Average = O(log n)
Worst   = O(n)
```

The important additional condition is:

```cpp
if(nums[left] == nums[mid] && nums[mid] == nums[right])
```

---

## Important Code Pattern

### Safe Mid Calculation

```cpp
int mid = left + (right - left) / 2;
```

Instead of:

```cpp
int mid = (left + right) / 2;
```

The first version avoids potential integer overflow.

---

## Key Concepts

- Binary Search
- Modified Binary Search
- Rotated Sorted Array
- Duplicate Handling
- Two Sorted Halves
- Search Space Reduction
- Left Pointer
- Right Pointer
- Middle Pointer
- Edge Case Handling

---

## Interview Tips

- First check:
  ```cpp
  nums[mid] == target
  ```
- Remember the duplicate case:
  ```text
  left == mid == right
  ```
- If duplicates make the sorted half unclear:
  ```text
  left++
  right--
  ```
- Otherwise identify the sorted half.
- Check whether the target lies inside that sorted range.
- Use `O(1)` extra space.
- Remember that unlike normal Binary Search, the worst case can become:
  ```text
  O(n)
  ```
  because of duplicates.
- This problem is a common interview variation of **Rotated Binary Search**.

---

## Folder Structure

```text
Q19.Search_in_Rotated_Sorted_Array_II/
├── README.md
└── search_in_rotated_sorted_array_II.cpp
```

---

## Learning Outcomes

After solving this problem, you will understand:

- How Binary Search works on rotated arrays.
- How to identify a sorted half.
- How duplicates affect Binary Search.
- How to handle ambiguous sorted halves.
- How to modify Binary Search for special cases.
- Why the worst-case complexity becomes `O(n)` with duplicates.
- How to maintain `O(1)` auxiliary space.

---

## Status

✅ Solved
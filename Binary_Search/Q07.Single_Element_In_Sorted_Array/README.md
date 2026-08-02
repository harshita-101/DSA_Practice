# Q7. Single Element in a Sorted Array

## Problem Statement

Given a sorted array where every element appears exactly twice except for one element that appears only once, find that single element.

You must solve the problem in **O(log n)** time and **O(1)** extra space.

**Difficulty:** Medium

**LeetCode:** 540

---

## Examples

### Example 1

```text
Input:
nums = [1,1,2,3,3,4,4,8,8]

Output:
2
```

---

### Example 2

```text
Input:
nums = [3,3,7,7,10,11,11]

Output:
10
```

---

### Example 3

```text
Input:
nums = [1]

Output:
1
```

---

## Approach

Since the array is sorted:

- Every element appears twice except one.
- Before the single element, pairs start at **even indices**.
- After the single element, pairs start at **odd indices**.

Using Binary Search:

- If the middle element is the unique element, return it.
- Otherwise, use the parity (even/odd index) to determine which half contains the answer.
- Reduce the search space until the unique element is found.

---

## Algorithm

1. Handle the case when the array contains only one element.
2. Perform Binary Search.
3. Check if the current element is unique.
4. If `mid` is even:
   - If `nums[mid-1] == nums[mid]`, search the left half.
   - Otherwise, search the right half.
5. If `mid` is odd:
   - If `nums[mid-1] == nums[mid]`, search the right half.
   - Otherwise, search the left half.
6. Return the single element.

---

## Important Conditions

### Single Element Found

```cpp
if(nums[mid-1] != nums[mid] && nums[mid] != nums[mid+1])
    return nums[mid];
```

---

### Even Index

```cpp
if(mid % 2 == 0)
```

If

```cpp
nums[mid-1] == nums[mid]
```

Search Left

```cpp
end = mid - 1;
```

Else

```cpp
st = mid + 1;
```

---

### Odd Index

```cpp
if(mid % 2 != 0)
```

If

```cpp
nums[mid-1] == nums[mid]
```

Search Right

```cpp
st = mid + 1;
```

Else

```cpp
end = mid - 1;
```

---

## Edge Cases

### Single Element Array

```text
[5]
```

Output

```text
5
```

---

### Single Element at Beginning

```text
[2,3,3,4,4]
```

Output

```text
2
```

---

### Single Element at End

```text
[1,1,2,2,5]
```

Output

```text
5
```

---

## Complexity Analysis

**Time Complexity:** `O(log n)`

**Space Complexity:** `O(1)`

---

## Key Concepts

- Binary Search
- Sorted Array
- Even-Odd Index Property
- Search Space Reduction
- Unique Element

---

## Interview Tips

- Brute Force takes **O(n)**.
- XOR also works in **O(n)** but does **not** satisfy the required **O(log n)** complexity.
- Binary Search is the expected interview solution.
- Always calculate mid safely:

```cpp
mid = st + (end - st) / 2;
```

---

## Folder Structure

```
Q7.Single_Element_in_Sorted_Array/
├── README.md
└── single_non_duplicate.cpp
```

---

## Learning Outcomes

After solving this problem, you will understand:

- Binary Search on answer pattern.
- Using index parity (even/odd) in Binary Search.
- Finding a unique element in a sorted array.
- Solving interview-level Binary Search problems efficiently.

---

## Status

✅ Solved
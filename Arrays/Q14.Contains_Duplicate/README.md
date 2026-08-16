# Q12. Contains Duplicate

## Problem Statement

Given an integer array `nums`, return `true` if any value appears at least twice in the array.

Return `false` if every element appears only once.

**Difficulty:** Easy

**LeetCode:** 217

---

## Examples

### Example 1

```text
Input:
nums = [1,2,3,1]

Output:
true
```

Explanation:

The value `1` appears more than once.

---

### Example 2

```text
Input:
nums = [1,2,3,4]

Output:
false
```

Explanation:

Every element appears exactly once.

---

### Example 3

```text
Input:
nums = [1,1,1,3,3,4,3,2,4,2]

Output:
true
```

Explanation:

Multiple elements appear more than once.

---

## Approach

Use an **`unordered_set`** to keep track of the elements that have already been seen.

While traversing the array:

1. Check whether the current element already exists in the set.
2. If it exists, a duplicate has been found, so return `true`.
3. Otherwise, insert the current element into the set.
4. If the complete array is traversed without finding a duplicate, return `false`.

---

## Algorithm

1. Create an empty `unordered_set<int>`.
2. Traverse the array from left to right.
3. For every element:
   - Search for the element in the set.
   - If found, return `true`.
   - Otherwise, insert it into the set.
4. If the loop finishes, return `false`.

---

## Dry Run

### Input

```text
nums = [1,2,3,1]
```

Initially:

```text
set = {}
```

### Step 1

Current element:

```text
1
```

`1` is not present.

Insert:

```text
set = {1}
```

---

### Step 2

Current element:

```text
2
```

`2` is not present.

Insert:

```text
set = {1,2}
```

---

### Step 3

Current element:

```text
3
```

`3` is not present.

Insert:

```text
set = {1,2,3}
```

---

### Step 4

Current element:

```text
1
```

`1` is already present in the set.

Therefore:

```text
Duplicate found
```

Return:

```text
true
```

---

## Why `unordered_set`?

An `unordered_set` stores only unique elements.

It also provides average `O(1)` time for:

- Searching
- Inserting

Therefore, it is efficient for checking whether an element has already appeared.

---

## Complexity Analysis

### Time Complexity

```text
O(n)
```

We traverse the array once.

Each `find()` and `insert()` operation takes **O(1) average time**.

Therefore:

```text
O(n)
```

on average.

---

### Space Complexity

```text
O(n)
```

In the worst case, if all elements are unique, the set stores all `n` elements.

---

## Why This Approach Is Optimal?

The hash set approach gives:

```text
Time  = O(n) average
Space = O(n)
```

This is optimal in time complexity for a general unsorted array when we want to detect duplicates without modifying the input.

Another approach is sorting the array first:

```text
Sorting → O(n log n)
```

followed by checking adjacent elements.

The `unordered_set` approach is faster on average.

---

## Alternative Approach

### Sorting

We can sort the array and then compare adjacent elements.

Example:

```text
[4,1,3,2,1]
```

After sorting:

```text
[1,1,2,3,4]
```

Adjacent `1`s indicate a duplicate.

Complexity:

```text
Time  = O(n log n)
Space = depends on sorting implementation
```

The `unordered_set` approach is preferred when we want average `O(n)` time.

---

## Key Concepts

- Arrays
- Hashing
- `unordered_set`
- Duplicate Detection
- Searching
- Insertion
- Early Termination
- Hash Table

---

## Interview Tips

- Use a hash set when you need to quickly check whether an element has already appeared.
- Always check before inserting the current element.
- Return immediately when a duplicate is found.
- If the array is sorted, adjacent elements can be compared instead.
- Remember that `unordered_set` provides **average `O(1)`** lookup and insertion, not guaranteed worst-case `O(1)`.

---

## Folder Structure

```text
Q12.Contains_Duplicate/
├── README.md
└── contains_duplicate.cpp
```

---

## Learning Outcomes

After solving this problem, you will understand:

- How to detect duplicates using hashing.
- How `unordered_set` works.
- How to perform fast lookup using a hash table.
- How early termination can improve practical performance.
- The difference between hashing and sorting approaches.
- How to achieve average `O(n)` time complexity.

---

## Status

✅ Solved
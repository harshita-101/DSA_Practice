# Q13. Intersection of Two Arrays

## Problem Statement

Given two integer arrays `nums1` and `nums2`, return an array containing their intersection.

Each element in the result must be **unique**.

The order of the result does not matter.

**Difficulty:** Easy

**LeetCode:** 349

---

## Examples

### Example 1

```text
Input:
nums1 = [1,2,2,1]
nums2 = [2,2]

Output:
[2]
```

Explanation:

The common element is `2`.

Since the result should contain only unique elements:

```text
[2]
```

---

### Example 2

```text
Input:
nums1 = [4,9,5]
nums2 = [9,4,9,8,4]

Output:
[4,9]
```

Explanation:

The common elements are:

```text
4 and 9
```

Duplicates are removed from the result.

So the output can be:

```text
[4,9]
```

or:

```text
[9,4]
```

Both are valid.

---

## Approach

Use **Hashing with `unordered_set`**.

We use two sets:

### Set 1: `s`

Store all unique elements of `nums1`.

### Set 2: `ans`

While traversing `nums2`, check whether the current element exists in `s`.

If it exists:

```text
nums2[i] is present in nums1
```

so it belongs to the intersection.

Insert it into `ans`.

Because `ans` is also an `unordered_set`, duplicate elements are automatically ignored.

Finally, copy all elements from `ans` into the result vector.

---

## Algorithm

1. Create an empty `unordered_set<int> s`.
2. Insert every element of `nums1` into `s`.
3. Create another `unordered_set<int> ans`.
4. Traverse `nums2`.
5. For every element:
   - Check whether it exists in `s`.
   - If it exists, insert it into `ans`.
6. Create a result vector.
7. Copy all elements from `ans` into the result vector.
8. Return the result.

---

## Dry Run

### Input

```text
nums1 = [1,2,2,1]
nums2 = [2,2]
```

### Step 1: Store `nums1`

After inserting all elements:

```text
s = {1,2}
```

Duplicates are automatically removed.

---

### Step 2: Traverse `nums2`

First element:

```text
2
```

Check:

```text
2 exists in s
```

Yes.

Insert into `ans`:

```text
ans = {2}
```

---

Second element:

```text
2
```

Again:

```text
2 exists in s
```

But `ans` already contains `2`.

Since `ans` is an `unordered_set`, it remains:

```text
ans = {2}
```

---

### Step 3: Create Result

Copy elements from `ans`:

```text
result = [2]
```

Final output:

```text
[2]
```

---

## Why Use Two Sets?

The first set:

```text
s
```

is used to quickly check whether an element of `nums2` exists in `nums1`.

The second set:

```text
ans
```

ensures that the result contains only unique elements.

For example:

```text
nums1 = [1,2,2,3]
nums2 = [2,2,2,3]
```

Without `ans`:

```text
[2,2,2,3]
```

With `unordered_set`:

```text
[2,3]
```

---

## Complexity Analysis

Let:

- `n` = size of `nums1`
- `m` = size of `nums2`

### Time Complexity

```text
O(n + m)
```

We:

- Traverse `nums1` once → `O(n)`
- Traverse `nums2` once → `O(m)`
- Copy the result → at most `O(min(n,m))`

Therefore, overall average complexity is:

```text
O(n + m)
```

---

### Space Complexity

```text
O(n + m)
```

In the worst case, the sets can store elements from both arrays.

The result vector also requires additional space for the intersection.

---

## Why This Approach?

Using `unordered_set` provides average:

```text
O(1)
```

time for:

- `insert()`
- `find()`

Therefore, we can efficiently determine whether an element is present in both arrays.

---

## Alternative Approach

### Sorting + Two Pointers

Another approach is:

1. Sort both arrays.
2. Use two pointers to find common elements.
3. Avoid duplicates while adding to the result.

Complexity:

```text
Time: O(n log n + m log m)
```

The hashing approach is faster on average:

```text
O(n + m)
```

but uses extra memory.

---

## Important Difference

This problem asks for **unique intersection**.

For:

```text
nums1 = [1,2,2,1]
nums2 = [2,2]
```

the answer is:

```text
[2]
```

not:

```text
[2,2]
```

This is different from problems where duplicate occurrences matter.

---

## Key Concepts

- Arrays
- Hashing
- `unordered_set`
- Set Intersection
- Duplicate Removal
- `find()`
- `insert()`
- Unique Elements
- Two Pointer Alternative

---

## Interview Tips

- Use a hash set when you need fast membership checking.
- Store the first array in a set.
- Traverse the second array and check membership.
- Use another set when the result must contain unique values.
- Remember that `unordered_set` does not maintain sorted order.
- The order of elements in the returned result does not matter for this problem.
- `unordered_set` operations are **average O(1)**.

---

## Folder Structure

```text
Q13.Intersection_of_Two_Arrays/
├── README.md
└── intersection_of_two_arrays.cpp
```

---

## Learning Outcomes

After solving this problem, you will understand:

- How to find common elements between two arrays.
- How to use `unordered_set` for membership checking.
- How sets automatically eliminate duplicates.
- How hashing can reduce the time complexity of array problems.
- How to compare hashing and sorting approaches.
- How to solve set-intersection problems efficiently.

---

## Status

✅ Solved
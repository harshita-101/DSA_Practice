# Q05. Next Greater Element I

## Problem Statement

**LeetCode Problem:** [Next Greater Element I](https://leetcode.com/problems/next-greater-element-i/)  
**Problem Number:** 496  
**Difficulty:** Easy

You are given two integer arrays, `nums1` and `nums2`, where `nums1` is a subset of `nums2`.

For each element in `nums1`, find the **next greater element** in `nums2`.

The next greater element of an element `x` is the first element to its right in `nums2` that is greater than `x`.

If no such element exists, return `-1`.

Return an array `ans` such that `ans[i]` is the next greater element of `nums1[i]`.

---

## Example 1

**Input:**
```text
nums1 = [4, 1, 2]
nums2 = [1, 3, 4, 2]
```

**Output:**
```text
[-1, 3, -1]
```

**Explanation:**

- For `4`, no greater element exists to its right, so the answer is `-1`.
- For `1`, the next greater element is `3`.
- For `2`, no greater element exists to its right, so the answer is `-1`.

## Example 2

**Input:**
```text
nums1 = [2, 4]
nums2 = [1, 2, 3, 4]
```

**Output:**
```text
[3, -1]
```

**Explanation:**

- For `2`, the next greater element is `3`.
- For `4`, no greater element exists to its right, so the answer is `-1`.

---

## Approach: Monotonic Stack + Hash Map

We solve the problem using a **stack** and an **unordered map**.

### 1. Traverse `nums2` from Right to Left

We process `nums2` backward because the next greater element must be on the right.

### 2. Maintain a Stack

For each element:
- Remove elements from the stack while they are less than or equal to the current element.
- If the stack becomes empty, the next greater element is `-1`.
- Otherwise, the top of the stack is the next greater element.
- Store the result in the hash map.
- Push the current element onto the stack.

### 3. Build the Answer

Traverse `nums1` and use the hash map to find the next greater element for each value.

---

## Algorithm

1. Create an empty `unordered_map<int, int>` and an empty stack.
2. Traverse `nums2` from right to left.
3. While the stack is not empty and its top element is less than or equal to the current element, pop the stack.
4. If the stack is empty, map the current element to `-1`; otherwise, map it to the stack's top element.
5. Push the current element onto the stack.
6. Traverse `nums1` and append the mapped next greater element to the answer vector.
7. Return the answer vector.

---

## Dry Run

Consider:

```text
nums1 = [4, 1, 2]
nums2 = [1, 3, 4, 2]
```

Process `nums2` from right to left.

| Current Element | Stack After Processing | Next Greater Element |
|---|---|---|
| `2` | `[2]` | `-1` |
| `4` | `[4]` | `-1` |
| `3` | `[4, 3]` | `4` |
| `1` | `[4, 3, 1]` | `3` |

The resulting map is:

| Element | Next Greater Element |
|---|---|
| `1` | `3` |
| `3` | `4` |
| `4` | `-1` |
| `2` | `-1` |

Now look up the elements of `nums1 = [4, 1, 2]`:

- `4` → `-1`
- `1` → `3`
- `2` → `-1`

**Final Answer:**
```text
[-1, 3, -1]
```

---

## Code (C++)

```cpp
#include <iostream>
#include <stack>
#include <vector>
#include <unordered_map>
using namespace std;

vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2)
{
    unordered_map<int, int> m;
    stack<int> s;

    for (int i = nums2.size() - 1; i >= 0; i--)
    {
        while (!s.empty() && s.top() <= nums2[i])
        {
            s.pop();
        }

        if (s.empty())
        {
            m[nums2[i]] = -1;
        }
        else
        {
            m[nums2[i]] = s.top();
        }

        s.push(nums2[i]);
    }

    vector<int> ans;

    for (int i = 0; i < nums1.size(); i++)
    {
        ans.push_back(m[nums1[i]]);
    }

    return ans;
}

```

---

## Complexity Analysis

Let:
- `n` = size of `nums1`
- `m` = size of `nums2`

**Time Complexity:** `O(n + m)` on average.

- Processing `nums2` takes `O(m)` because each element is pushed onto and popped from the stack at most once.
- Building the answer takes `O(n)` on average because hash map lookups are average `O(1)`.

**Space Complexity:** `O(m)`.

The stack and hash map can each store up to `m` elements, and the answer vector stores `n` elements. Since `nums1` is a subset of `nums2`, the overall auxiliary space is `O(m)`.

---

## Key Concepts

- Stack
- Monotonic Stack
- Hash Map (`unordered_map`)
- Next Greater Element
- Array Traversal
- Time and Space Complexity

---

## Language

C++

## LeetCode

[Next Greater Element I – LeetCode 496](https://leetcode.com/problems/next-greater-element-i/)

## Status

✅ Solved
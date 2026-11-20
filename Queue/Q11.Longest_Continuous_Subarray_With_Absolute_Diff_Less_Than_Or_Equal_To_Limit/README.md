## Problem Statement

Given an integer array `nums` and an integer `limit`, find the longest continuous subarray such that the absolute difference between any two elements is less than or equal to `limit`.

Return the length of the longest valid continuous subarray.

### Example

**Input:**

```text
nums = [8, 2, 4, 7]
limit = 4
```

**Output:**

```text
2
```

**Explanation:**

- `[8, 2]` → Invalid because difference = 6.
- `[2, 4]` → Valid because difference = 2.
- `[4, 7]` → Valid because difference = 3.
- `[2, 4, 7]` → Invalid because difference = 5.

The longest valid subarray has length 2.

## Approach: Sliding Window + Two Monotonic Deques

We use two pointers and two deques to maintain the maximum and minimum elements of the current window efficiently.

### Data Structures Used

| Data Structure | Purpose |
|---|---|
| `maxDeque` | Maintains indices in decreasing order of values |
| `minDeque` | Maintains indices in increasing order of values |
| `left` | Starting index of the window |
| `right` | Ending index of the window |
| `ans` | Stores the maximum valid window length |

**Important:** Both deques store array indices, not actual values.

## Algorithm

### Step 1: Initialize Variables

```cpp
int left = 0;
int ans = 0;

deque<int> maxDeque;
deque<int> minDeque;
```

### Step 2: Traverse the Array

Use a `for` loop with the `right` pointer to expand the window.

### Step 3: Maintain Maximum Deque

Remove indices from the back whose values are smaller than or equal to the current element.

```cpp
while (!maxDeque.empty() &&
       nums[maxDeque.back()] <= nums[right]) {
    maxDeque.pop_back();
}

maxDeque.push_back(right);
```

This maintains decreasing order of values.

The front of `maxDeque` gives the maximum element's index.

### Step 4: Maintain Minimum Deque

Remove indices from the back whose values are greater than or equal to the current element.

```cpp
while (!minDeque.empty() &&
       nums[minDeque.back()] >= nums[right]) {
    minDeque.pop_back();
}

minDeque.push_back(right);
```

This maintains increasing order of values.

The front of `minDeque` gives the minimum element's index.

### Step 5: Check Window Validity

The current window is valid when:

```cpp
maximum - minimum <= limit
```

If the difference is greater than `limit`, move the `left` pointer forward until the window becomes valid.

```cpp
while (!maxDeque.empty() && !minDeque.empty() &&
       nums[maxDeque.front()] - nums[minDeque.front()] > limit) {

    if (maxDeque.front() == left) {
        maxDeque.pop_front();
    }

    if (minDeque.front() == left) {
        minDeque.pop_front();
    }

    left++;
}
```

### Step 6: Update Maximum Length

After the window becomes valid:

```cpp
ans = max(ans, right - left + 1);
```

Finally, return `ans`.

## Dry Run

**Input:**

```text
nums = [8, 2, 4, 7]
limit = 4
```

| Current Window | Maximum | Minimum | Difference | Valid |
|---|---:|---:|---:|---|
| [8] | 8 | 8 | 0 | Yes |
| [8, 2] | 8 | 2 | 6 | No |
| [2, 4] | 4 | 2 | 2 | Yes |
| [2, 4, 7] | 7 | 2 | 5 | No |
| [4, 7] | 7 | 4 | 3 | Yes |

**Final Answer:**

```text
2
```

## C++ Implementation

```cpp

class Solution {
public:
    int longestSubarray(vector<int>& nums, int limit) {
        int left = 0;
        int ans = 0;

        deque<int> maxDeque;
        deque<int> minDeque;

        for (int right = 0; right < nums.size(); right++) {

            while (!maxDeque.empty() &&
                   nums[maxDeque.back()] <= nums[right]) {
                maxDeque.pop_back();
            }

            maxDeque.push_back(right);

            while (!minDeque.empty() &&
                   nums[minDeque.back()] >= nums[right]) {
                minDeque.pop_back();
            }

            minDeque.push_back(right);

            while (!maxDeque.empty() && !minDeque.empty() &&
                   nums[maxDeque.front()] -
                   nums[minDeque.front()] > limit) {

                if (maxDeque.front() == left) {
                    maxDeque.pop_front();
                }

                if (minDeque.front() == left) {
                    minDeque.pop_front();
                }

                left++;
            }

            ans = max(ans, right - left + 1);
        }

        return ans;
    }
};

```

## Complexity Analysis

| Complexity | Value | Explanation |
|---|---|---|
| Time | O(n) | Every index enters and leaves each deque at most once |
| Space | O(n) | Two deques can store up to n indices |

## Key Concepts Learned

- Sliding Window Technique
- Two Pointers
- STL Deque
- Monotonic Deque
- Maintaining maximum and minimum efficiently
- Window expansion and contraction
- Amortized O(n) time complexity

## Important Interview Notes

1. A normal queue cannot efficiently maintain both minimum and maximum values.
2. Monotonic Deques help retrieve minimum and maximum in O(1) time.
3. Store indices instead of values so outdated elements can be removed when the left pointer moves.
4. Each element is inserted and removed at most once, giving O(n) total time complexity.


**Status:** Completed ✅
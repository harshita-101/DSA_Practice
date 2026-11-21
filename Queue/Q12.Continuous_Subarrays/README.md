## Problem Statement

Given an integer array `nums`, count the total number of continuous subarrays in which the absolute difference between every pair of elements is at most 2.

A subarray is valid if:

```cpp
max(subarray) - min(subarray) <= 2
```

## Approach: Sliding Window + Two Monotonic Deques

We use two deques to maintain the maximum and minimum elements of the current window efficiently.

- `maxDeque`: Maintains elements in decreasing order.
- `minDeque`: Maintains elements in increasing order.
- `left`: Starting index of the current window.
- `right`: Ending index of the current window.
- `ans`: Stores the total number of valid subarrays.

Both deques store indices instead of actual values.

## Algorithm

1. Initialize `left = 0` and `ans = 0`.
2. Traverse the array using the `right` pointer.
3. Update `maxDeque` by removing smaller or equal elements from the back.
4. Update `minDeque` by removing greater or equal elements from the back.
5. If maximum minus minimum is greater than 2, shrink the window by moving `left` forward.
6. Remove outdated indices from the front of both deques.
7. Add `right - left + 1` to `ans` because all subarrays ending at `right` and starting from `left` to `right` are valid.
8. Return `ans`.

## Dry Run

**Input:**

```text
nums = [5, 4, 2, 4]
```

| Right | Valid Window | Subarrays Added | Total |
|---|---|---:|---:|
| 0 | [5] | 1 | 1 |
| 1 | [5, 4] | 2 | 3 |
| 2 | [4, 2] | 2 | 5 |
| 3 | [4, 2, 4] | 3 | 8 |

**Output:**

```text
8
```

## C++ Implementation

```cpp
long long continuousSubarrays(vector<int>& nums) {
    int left = 0;
    long long ans = 0;

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
               nums[minDeque.front()] > 2) {

            if (maxDeque.front() == left) {
                maxDeque.pop_front();
            }

            if (minDeque.front() == left) {
                minDeque.pop_front();
            }

            left++;
        }

        ans += right - left + 1;
    }

    return ans;
}

```

## Complexity Analysis

| Complexity | Value |
|---|---|
| Time Complexity | O(n) |
| Space Complexity | O(n) |

Each index enters and leaves each deque at most once.

## Key Concepts Learned

- STL Deque
- Monotonic Deque
- Sliding Window
- Two Pointers
- Maintaining maximum and minimum
- Counting valid subarrays
- Amortized O(n) complexity



**Status:** Completed ✅
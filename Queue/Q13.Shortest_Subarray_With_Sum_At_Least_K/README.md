## Problem Statement

Given an integer array `nums` and an integer `k`, find the length of the shortest non-empty continuous subarray whose sum is greater than or equal to `k`.

If no such subarray exists, return `-1`.

**Example:**

```text
Input:
nums = [2, -1, 2]
k = 3

Output:
3
```

**Explanation:**

The sum of the entire array is:

`2 + (-1) + 2 = 3`

Its length is 3, so the answer is 3.

## Approach: Prefix Sum + Monotonic Deque

We use Prefix Sum to calculate subarray sums efficiently and a Monotonic Deque to find the shortest valid subarray.

### 1. Prefix Sum

Create a prefix sum array of size `n + 1`.

Formula:

`prefix[i + 1] = prefix[i] + nums[i]`

The first element is initialized to 0.

Subarray sum from index `i` to `j - 1`:

`prefix[j] - prefix[i]`

### 2. Monotonic Deque

The deque stores indices of the prefix sum array in increasing order of their prefix values.

We use two conditions:

**Condition 1: Find a valid subarray**

If:

`prefix[i] - prefix[dq.front()] >= k`

Then:
- A valid subarray is found.
- Calculate its length using `i - dq.front()`.
- Update the minimum answer.
- Remove the front index using `pop_front()`.

**Condition 2: Maintain increasing prefix sums**

If:

`prefix[dq.back()] >= prefix[i]`

Remove the back index using `pop_back()`.

The current prefix sum is smaller or equal, so it is more useful for future subarrays.

Finally, insert the current index using `push_back(i)`.

## Algorithm / Steps

1. Create a prefix sum array of size `n + 1`.
2. Calculate cumulative sums.
3. Initialize an empty deque and `ans = INT_MAX`.
4. Traverse the prefix sum array.
5. Remove indices from the front while the subarray sum is at least `k`.
6. Update the minimum subarray length.
7. Remove indices from the back while their prefix sums are greater than or equal to the current prefix sum.
8. Insert the current index into the deque.
9. Return `-1` if no valid subarray exists; otherwise return `ans`.

## Dry Run

**Input:**

```text
nums = [2, -1, 2]
k = 3
```

Prefix Sum:

```text
prefix = [0, 2, 1, 3]
```

| Index | Prefix Value | Deque Operation | Answer |
|---|---:|---|---:|
| 0 | 0 | Push index 0 | INF |
| 1 | 2 | Push index 1 | INF |
| 2 | 1 | Remove index 1, push index 2 | INF |
| 3 | 3 | Valid sum found: 3 - 0 = 3; remove index 0 | 3 |

**Final Output:**

```text
3
```

## C++ Implementation

```cpp
int shortestSubarray(vector<int>& nums, int k) {
    vector<long long> prefix(nums.size() + 1);
    deque<int> dq;
    int ans = INT_MAX;

    // Build Prefix Sum
    for (int i = 0; i < nums.size(); i++) {
        prefix[i + 1] = prefix[i] + nums[i];
    }

    // Find Shortest Subarray
    for (int i = 0; i < prefix.size(); i++) {

        // Check valid subarray
        while (!dq.empty() &&
               prefix[i] - prefix[dq.front()] >= k) {

            ans = min(ans, i - dq.front());
            dq.pop_front();
        }

        // Maintain increasing prefix sums
        while (!dq.empty() &&
               prefix[dq.back()] >= prefix[i]) {

            dq.pop_back();
        }

        dq.push_back(i);
    }

    return ans == INT_MAX ? -1 : ans;
}

```

## Time and Space Complexity

| Complexity | Value | Explanation |
|---|---|---|
| Time | O(n) | Every index enters and leaves the deque at most once |
| Space | O(n) | Prefix sum array and deque |

## Key Concepts Learned

- STL Deque
- Prefix Sum
- Monotonic Deque
- Sliding Window
- Handling negative numbers
- Finding minimum subarray length
- Optimizing brute-force solutions


**Status:** Completed ✅
## 1. Problem Statement

Given an integer array `nums` and an integer `k`, find the maximum element in every contiguous subarray (window) of size `k`.

Return an array containing the maximum element of each window.

### Example

**Input:**
```text
nums = [1, 3, -1, -3, 5, 3, 6, 7]
k = 3
```

**Output:**
```text
[3, 3, 5, 5, 6, 7]
```

**Explanation:**

| Window | Maximum |
|---|---:|
| [1, 3, -1] | 3 |
| [3, -1, -3] | 3 |
| [-1, -3, 5] | 5 |
| [-3, 5, 3] | 5 |
| [5, 3, 6] | 6 |
| [3, 6, 7] | 7 |

## 2. Approach – Monotonic Deque

Use a **Deque (Double-Ended Queue)** to efficiently maintain maximum elements for each window.

The deque stores indices of array elements, not their values.

Maintain the deque in decreasing order of values:

1. Remove outdated indices from the front that are outside the current window.
2. Remove smaller or equal elements from the back because the current element is greater and dominates them.
3. Insert the current index at the back.
4. Once the window is complete, the front index represents the maximum element.
5. Add that maximum value to the answer.

## 3. Algorithm

1. Initialize an empty answer vector and deque.
2. Traverse the array using a loop.
3. Remove indices that are outside the current window.
4. Maintain decreasing order by removing smaller or equal elements.
5. Push the current index into the deque.
6. If `i >= k-1`, add `nums[dq.front()]` to the answer.
7. Return the answer vector.

## 4. Dry Run

**Input:**
```text
nums = [2, 1, 5, 3, 4]
k = 3
```

| Index | Current Element | Deque Values | Maximum |
|---:|---:|---|---:|
| 0 | 2 | [2] | - |
| 1 | 1 | [2, 1] | - |
| 2 | 5 | [5] | 5 |
| 3 | 3 | [5, 3] | 5 |
| 4 | 4 | [5, 4] | 5 |

**Output:**
```text
[5, 5, 5]
```

## 5. C++ Code

```cpp
vector<int> maxSlidingWindow(vector<int>& nums, int k) {
    int n = nums.size();
    vector<int> ans;
    deque<int> dq;

    for(int i = 0; i < n; i++) {

        if(!dq.empty() && dq.front() <= i-k) {
            dq.pop_front();
        }

        while(!dq.empty() && nums[dq.back()] <= nums[i]) {
            dq.pop_back();
        }

        dq.push_back(i);

        if(i >= k-1) {
            ans.push_back(nums[dq.front()]);
        }
    }

    return ans;
}
```

## 6. Time and Space Complexity

| Complexity | Value | Explanation |
|---|---|---|
| Time | O(n) | Every index is inserted and removed at most once. |
| Auxiliary Space | O(k) | Deque stores at most k indices. |

## 7. Key Concepts Learned

- Deque (Double-Ended Queue)
- Monotonic Deque
- Sliding Window Technique
- Index-based element tracking
- Maintaining decreasing order
- Optimizing window maximum calculation


**Key Learning:** A Monotonic Deque helps find the maximum element in every sliding window efficiently in O(n) time instead of checking every window separately in O(n × k) time.

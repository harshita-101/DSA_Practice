# Q02. Number of Recent Calls

## Problem Statement

**LeetCode Problem:** [Number of Recent Calls](https://leetcode.com/problems/number-of-recent-calls/)  
**Problem Number:** 933  
**Difficulty:** Easy

You are given a class `RecentCounter` that counts the number of recent requests.

Implement the `ping(int t)` function, which adds a new request at time `t` and returns the number of requests that have happened in the past 3000 milliseconds, including the current request.

A request is considered valid if its timestamp lies within the range:

`[t - 3000, t]`

**Note:**
- Every new timestamp is strictly greater than the previous timestamp.
- Remove all requests that fall outside the valid time range.

---

## Example 1

**Input:**
```text
ping(1)
ping(100)
ping(3001)
ping(3002)
```

**Output:**
```text
1
2
3
3
```

**Explanation:**

1. `ping(1)` → Queue: `[1]` → Count: 1
2. `ping(100)` → Queue: `[1, 100]` → Count: 2
3. `ping(3001)` → Queue: `[1, 100, 3001]` → Count: 3
4. `ping(3002)` → Remove timestamp 1 → Queue: `[100, 3001, 3002]` → Count: 3

Therefore, the output is `[1, 2, 3, 3]`.

---

## Approach: Using Queue

We use a Queue to store the timestamps of incoming requests.

- Insert the current timestamp into the queue using `push()`.
- Check whether the front timestamp is smaller than `t - 3000`.
- If it is smaller, remove it using `pop()`.
- Repeat until all timestamps are within the valid range.
- Return the current queue size using `size()`.

**Important:** Queue follows FIFO (First In, First Out), so the oldest timestamp is always present at the front.

---

## Algorithm

1. Create an empty queue of integers.
2. Insert the current timestamp `t` into the queue.
3. Check whether the queue is empty or the front timestamp is outside the valid range.
4. If `q.front() < t - 3000`, remove the front element.
5. Repeat the process until all timestamps are valid.
6. Return the size of the queue.

---

## Dry Run

Consider the input:

```text
timestamps = [1, 100, 3001, 3002]
```

| Timestamp | Valid Range | Operation | Queue |
|---|---|---|---|
| 1 | [-2999, 1] | Push 1 | [1] |
| 100 | [-2900, 100] | Push 100 | [1, 100] |
| 3001 | [1, 3001] | Push 3001 | [1, 100, 3001] |
| 3002 | [2, 3002] | Remove 1, push 3002 | [100, 3001, 3002] |

**Final Output:**
```text
1
2
3
3
```

---

## Code (C++)

```cpp
#include<iostream>
#include<queue>
using namespace std;

queue<int> q;

int ping(int t) {
    q.push(t);

    while(!q.empty() && q.front() < t - 3000) {
        q.pop();
    }

    return q.size();
}

```

---

## Complexity Analysis

Let `n` be the number of requests.

- **Time Complexity:** O(1) amortized per `ping()` operation. Each timestamp is inserted once and removed at most once.
- **Space Complexity:** O(n) in the worst case, as the queue stores recent timestamps.

---

## Key Concepts

- Queue
- FIFO (First In, First Out)
- C++ STL Queue
- Queue Operations (`push`, `pop`, `front`, `size`, `empty`)
- Sliding Time Window
- Amortized Time Complexity

---

## Language

C++

## LeetCode

[Number of Recent Calls – LeetCode 933](https://leetcode.com/problems/number-of-recent-calls/)

## Status

✅ Solved
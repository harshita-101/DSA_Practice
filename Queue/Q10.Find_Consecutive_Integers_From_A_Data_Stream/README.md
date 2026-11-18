## Problem Statement

You are given two integers:

- `value`: The target number.
- `k`: The required number of consecutive occurrences.

Design a class `DataStream` that checks whether the last `k` numbers in a stream are equal to the given `value`.

Implement two functions:

1. `DataStream(int value, int k)` – Initialize the data stream.
2. `bool consec(int num)` – Process a new number and return `true` if the last `k` numbers are all equal to `value`; otherwise, return `false`.

## Approach: Counter

We use a counter variable to track consecutive occurrences of the target value.

### Variables Used

| Variable | Purpose |
|---|---|
| `value` | Target number to check |
| `k` | Required consecutive occurrences |
| `count` | Tracks consecutive matching numbers |

## Algorithm

1. Initialize `value` and `k` using the constructor.
2. Set `count = 0`.
3. Whenever `consec(num)` is called:
   - If `num == value`, increment `count`.
   - Otherwise, reset `count = 0`.
4. Return `true` if `count >= k`.
5. Otherwise, return `false`.

## C++ Implementation

```cpp
#include<iostream>
using namespace std;

class DataStream {
    int value;
    int k;
    int count;

public:
    DataStream(int value, int k) {
        this->value = value;
        this->k = k;
        count = 0;
    }

    bool consec(int num) {
        if (num == value) {
            count++;
        }
        else {
            count = 0;
        }

        return count >= k;
    }
};

```

## Example Dry Run

**Input:**

```text
value = 5
k = 3
numbers = [5, 5, 2, 5, 5, 5]
```

**Dry Run:**

| Number | Count | Return |
|---|---:|---|
| 5 | 1 | false |
| 5 | 2 | false |
| 2 | 0 | false |
| 5 | 1 | false |
| 5 | 2 | false |
| 5 | 3 | true |

**Output:**

```text
false
false
false
false
false
true
```

## Complexity Analysis

| Complexity | Value | Explanation |
|---|---|---|
| Time | O(1) | Each `consec()` call performs constant-time operations |
| Space | O(1) | Only three variables are maintained |

## Key Concepts Learned

- Data Stream processing
- Consecutive counting
- Counter reset logic
- Conditional statements
- Class and constructor implementation
- Using `this` pointer
- Maintaining state between function calls

## Important Observation

We do not need to store all incoming numbers in an array or queue.

Only the consecutive count is required, which makes the solution efficient.


**Status:** Completed ✅
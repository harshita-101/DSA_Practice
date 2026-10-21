# Q07. Daily Temperatures

**LeetCode Problem:** [739. Daily Temperatures](https://leetcode.com/problems/daily-temperatures/)  
**Difficulty:** Medium  
**Topic:** Stack, Monotonic Stack, Array

---

## 📌 Problem Statement

You are given an array of integers `temperatures` representing the daily temperatures.

For each day, find how many days you have to wait until a warmer temperature. If there is no future day with a warmer temperature, store `0` for that day.

Return an array `answer` such that:

- `answer[i]` is the number of days after day `i` when a warmer temperature occurs.
- If no warmer temperature exists in the future, `answer[i] = 0`.

### Example 1

**Input:**
```text
temperatures = [73,74,75,71,69,72,76,73]
```

**Output:**
```text
[1,1,4,2,1,1,0,0]
```

**Explanation:**

- Day 0: Temperature is 73. The next warmer temperature is 74 on day 1. Wait = 1 day.
- Day 1: Temperature is 74. The next warmer temperature is 75 on day 2. Wait = 1 day.
- Day 2: Temperature is 75. The next warmer temperature is 76 on day 6. Wait = 4 days.
- Day 3: Temperature is 71. The next warmer temperature is 72 on day 5. Wait = 2 days.
- Day 4: Temperature is 69. The next warmer temperature is 72 on day 5. Wait = 1 day.
- Day 5: Temperature is 72. The next warmer temperature is 76 on day 6. Wait = 1 day.
- Day 6: Temperature is 76. No warmer temperature occurs afterward. Answer = 0.
- Day 7: Temperature is 73. No future day exists with a warmer temperature. Answer = 0.

### Example 2

**Input:**
```text
temperatures = [30,40,50,60]
```

**Output:**
```text
[1,1,1,0]
```

### Example 3

**Input:**
```text
temperatures = [30,60,90]
```

**Output:**
```text
[1,1,0]
```

---

## 💡 Approach: Monotonic Stack

We use a **monotonic decreasing stack** to efficiently find the next warmer day for each temperature.

Instead of storing temperatures in the stack, we store their **indices**.

### Why store indices?

We need to calculate how many days we must wait until a warmer temperature occurs.

If the current day is `i` and the previous day is `prev`, the waiting time is:

```cpp
ans[prev] = i - prev;
```

We need the indices to calculate this difference and update the correct answer.

### Algorithm

1. Find the size of the input array and store it in `n`.
2. Create an answer vector of size `n`, initialized with zeros:
   ```cpp
   vector<int> ans(n, 0);
   ```
3. Create an empty stack to store indices.
4. Traverse the temperatures from left to right.
5. For each index `i`, compare the current temperature with the temperature at the index on top of the stack.
6. While the stack is not empty and the current temperature is warmer:
   - Store the top index in `prev`.
   - Pop that index from the stack.
   - Calculate the waiting time using `i - prev`.
   - Update `ans[prev]`.
7. Push the current index `i` onto the stack.
8. Return the answer vector.

Any index left in the stack at the end has no warmer temperature in the future. Its answer remains `0`.

---

## 💻 C++ Solution

```cpp
#include<iostream>
#include<stack>
#include<vector>
using namespace std;

vector<int> dailyTemperatures(vector<int>& temperatures) {

    int n = temperatures.size();
    vector<int> ans(n, 0);
    stack<int> st;

    for (int i = 0; i < n; i++) {

        while (!st.empty() &&
               temperatures[st.top()] < temperatures[i]) {

            int prev = st.top();
            st.pop();

            ans[prev] = i - prev;
        }

        st.push(i);
    }

    return ans;
}

```

---

## 🔍 Dry Run

**Input:**
```text
temperatures = [73,74,75,71,69,72,76,73]
```

Initially:

```text
Stack = []
Answer = [0,0,0,0,0,0,0,0]
```

| Index `i` | Temperature | Operation | Updated Answer |
|---:|---:|---|---|
| 0 | 73 | Push index 0 | `[0,0,0,0,0,0,0,0]` |
| 1 | 74 | Pop index 0; `1 - 0 = 1`. Push index 1 | `[1,0,0,0,0,0,0,0]` |
| 2 | 75 | Pop index 1; `2 - 1 = 1`. Push index 2 | `[1,1,0,0,0,0,0,0]` |
| 3 | 71 | Push index 3 | `[1,1,0,0,0,0,0,0]` |
| 4 | 69 | Push index 4 | `[1,1,0,0,0,0,0,0]` |
| 5 | 72 | Pop index 4; `5 - 4 = 1`. Pop index 3; `5 - 3 = 2`. Push index 5 | `[1,1,0,2,1,0,0,0]` |
| 6 | 76 | Pop index 5; `6 - 5 = 1`. Pop index 2; `6 - 2 = 4`. Push index 6 | `[1,1,4,2,1,1,0,0]` |
| 7 | 73 | Push index 7 | `[1,1,4,2,1,1,0,0]` |

The indices remaining in the stack do not have a warmer temperature later, so their answers remain `0`.

**Final Output:**
```text
[1,1,4,2,1,1,0,0]
```

---

## ⏱️ Complexity Analysis

### Time Complexity: `O(n)`

Although there is a `while` loop inside the `for` loop, each index is pushed onto the stack once and popped at most once.

Therefore, the total number of stack operations is proportional to `n`.

**Time Complexity = O(n)**

### Space Complexity: `O(n)`

- The answer vector requires `O(n)` space.
- The stack can hold up to `n` indices in the worst case.

**Auxiliary Space Complexity = O(n)**

---

## 🧠 Key Concepts Learned

### 1. Monotonic Stack

A monotonic stack maintains elements in a particular order. Here, the temperatures corresponding to the stored indices are in non-increasing order from the bottom to the top.

When a warmer temperature appears, we pop the indices whose next warmer day has been found.

### 2. Store Indices Instead of Values

We store indices because we need to calculate the number of days between two temperatures and update the answer at the correct position.

### 3. Initialize the Answer Vector with Zeros

```cpp
vector<int> ans(n, 0);
```

This creates a vector of size `n`, with every element initialized to `0`.

If no warmer day is found for an index, its answer remains `0`.

### 4. Calculate the Waiting Period

```cpp
ans[prev] = i - prev;
```

The difference between the current index and the previous index gives the number of days to wait.

### 5. Each Index Is Processed Efficiently

Every index enters the stack once and leaves it at most once. This makes the solution more efficient than checking every future day separately.

---

## 📊 Brute Force vs. Optimized Approach

| Feature | Brute Force | Monotonic Stack |
|---|---|---|
| Approach | Check every future day | Maintain a stack of unresolved indices |
| Time Complexity | `O(n²)` | `O(n)` |
| Extra Space | `O(n)` for the answer | `O(n)` for the answer and stack |
| Efficiency | Slower for large arrays | More efficient |
| Main Concept | Nested loops | Monotonic Stack |

---

## Language

C++

## Status

✅ Solved
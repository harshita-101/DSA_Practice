# Q06. Baseball Game

## Problem Statement

**LeetCode Problem:** [Baseball Game](https://leetcode.com/problems/baseball-game/)  
**Problem Number:** 682  
**Difficulty:** Easy

You are given a list of strings called `operations`, where each string represents an operation in a baseball game.

You need to calculate the total score after performing all the operations.

Each operation can be one of the following:

| Operation | Meaning |
|---|---|
| Integer (`x`) | Record a new score of `x`. |
| `+` | Record a score equal to the sum of the previous two scores. |
| `D` | Record a score equal to double the previous score. |
| `C` | Invalidate and remove the previous score. |

**Note:** All operations are valid, and there will always be enough previous scores for `+`, `D`, and `C`.

---

## Example 1

**Input:**
```text
operations = ["5", "2", "C", "D", "+"]
```

**Output:**
```text
30
```

**Explanation:**

1. `"5"` → Record `5`. Scores: `[5]`
2. `"2"` → Record `2`. Scores: `[5, 2]`
3. `"C"` → Remove the previous score `2`. Scores: `[5]`
4. `"D"` → Double the previous score: `5 × 2 = 10`. Scores: `[5, 10]`
5. `"+"` → Add the previous two scores: `5 + 10 = 15`. Scores: `[5, 10, 15]`

Total score = `5 + 10 + 15 = 30`.

---

## Approach: Using Stack

We use a stack to store the valid scores.

Traverse the `operations` vector and handle each operation:

- **Integer:** Convert the string into an integer using `stoi()` and push it onto the stack.
- **`C`:** Remove the previous score using `pop()`.
- **`D`:** Double the top score and push the result.
- **`+`:** Add the previous two scores and push their sum while keeping both previous scores in the stack.

After processing all operations, calculate the sum of all the remaining scores and return it.

---

## Algorithm

1. Create an empty stack of integers.
2. Traverse every operation in the `operations` vector.
3. If the operation is an integer, convert it using `stoi()` and push it onto the stack.
4. If the operation is `C`, pop the top element.
5. If the operation is `D`, multiply the top element by `2` and push the result.
6. If the operation is `+`:
   - Store the top score in a variable.
   - Temporarily remove it.
   - Add it to the new top score.
   - Push the saved score back.
   - Push the calculated sum.
7. Initialize `total = 0`.
8. Pop each remaining score and add it to `total`.
9. Return `total`.

---

## Dry Run

Consider the input:

```text
operations = ["5", "2", "C", "D", "+"]
```

| Operation | Action | Stack | Total |
|---|---|---|---|
| `"5"` | Push 5 | `[5]` | — |
| `"2"` | Push 2 | `[5, 2]` | — |
| `"C"` | Remove 2 | `[5]` | — |
| `"D"` | Push 5 × 2 = 10 | `[5, 10]` | — |
| `"+"` | Push 10 + 5 = 15 | `[5, 10, 15]` | — |
| Sum | Add all scores | `[]` | `30` |

**Final Answer:** `30`

---

## Code (C++)

```cpp
#include <iostream>
#include <stack>
#include <string>
#include <vector>
using namespace std;

int calPoints(vector<string>& operations)
{
    stack<int> st;

    for (string c : operations)
    {
        if (c == "C")
        {
            st.pop();
        }
        else if (c == "D")
        {
            st.push(2 * st.top());
        }
        else if (c == "+")
        {
            int n = st.top();
            st.pop();

            int sum = n + st.top();

            st.push(n);
            st.push(sum);
        }
        else
        {
            st.push(stoi(c));
        }
    }

    int total = 0;

    while (!st.empty())
    {
        total += st.top();
        st.pop();
    }

    return total;
}

```

---

## Complexity Analysis

Let `n` be the number of operations.

- **Time Complexity:** `O(n)` — each operation is processed once, and each score is added to the total once.
- **Space Complexity:** `O(n)` — the stack can store up to `n` scores.

---

## Key Concepts

- Stack
- C++ STL Stack
- String-to-Integer Conversion using `stoi()`
- Conditional Statements
- Stack Operations: `push()`, `pop()`, and `top()`
- Time and Space Complexity

---

## Language

C++

## LeetCode

[Baseball Game – LeetCode 682](https://leetcode.com/problems/baseball-game/)

## Status

✅ Solved
# Q04. Evaluate Reverse Polish Notation

## Problem Statement

**LeetCode Problem:** [Evaluate Reverse Polish Notation](https://leetcode.com/problems/evaluate-reverse-polish-notation/)  
**Problem Number:** 150  
**Difficulty:** Medium

You are given an array of strings `tokens` representing an arithmetic expression in Reverse Polish Notation (RPN).

Evaluate the expression and return the integer result.

Valid operators are:
- Addition (`+`)
- Subtraction (`-`)
- Multiplication (`*`)
- Division (`/`)

**Note:** Integer division truncates toward zero. The given expression is valid, and division by zero will not occur.

---

## Example 1

**Input:**
```text
tokens = ["2", "1", "+", "3", "*"]
```

**Output:**
```text
9
```

**Explanation:**

1. `2 + 1 = 3`
2. `3 * 3 = 9`

Therefore, the result is `9`.

## Example 2

**Input:**
```text
tokens = ["4", "13", "5", "/", "+"]
```

**Output:**
```text
6
```

**Explanation:**

1. `13 / 5 = 2`
2. `4 + 2 = 6`

Therefore, the result is `6`.

## Example 3

**Input:**
```text
tokens = ["10", "6", "9", "3", "+", "-11", "*", "/", "*", "17", "+", "5", "+"]
```

**Output:**
```text
22
```

---

## Approach: Using Stack

We use a stack to evaluate the expression.

- If the current token is a number, convert it into an integer using `stoi()` and push it onto the stack.
- If the current token is an operator, pop the top two elements from the stack.
- Perform the operation and push the result back onto the stack.
- After processing all tokens, the top element of the stack contains the final answer.

**Important:** The order of operands matters for subtraction and division.

If the first popped value is `b` and the second popped value is `a`, perform:

- Addition: `a + b`
- Subtraction: `a - b`
- Multiplication: `a * b`
- Division: `a / b`

---

## Algorithm

1. Create an empty stack of integers.
2. Traverse each token in the input vector.
3. If the token is an operator:
   - Pop the top element and store it in `b`.
   - Pop the next element and store it in `a`.
   - Perform the corresponding operation.
   - Push the result onto the stack.
4. Otherwise, convert the token to an integer using `stoi()` and push it onto the stack.
5. Return the element at the top of the stack.

---

## Dry Run

Consider the input:

```text
tokens = ["2", "1", "+", "3", "*"]
```

| Token | Operation | Stack |
|---|---|---|
| `2` | Push 2 | `[2]` |
| `1` | Push 1 | `[2, 1]` |
| `+` | Pop 1 and 2; push 2 + 1 = 3 | `[3]` |
| `3` | Push 3 | `[3, 3]` |
| `*` | Pop 3 and 3; push 3 × 3 = 9 | `[9]` |

**Final Answer:** `9`

---

## Code (C++)

```cpp
#include <iostream>
#include <vector>
#include <stack>
#include <string>
using namespace std;

int evalRPN(vector<string>& tokens)
{
    stack<int> st;

    for (const string& c : tokens)
    {
        if (c == "+" || c == "-" || c == "*" || c == "/")
        {
            int b = st.top();
            st.pop();

            int a = st.top();
            st.pop();

            if (c == "+")
                st.push(a + b);
            else if (c == "-")
                st.push(a - b);
            else if (c == "*")
                st.push(a * b);
            else
                st.push(a / b);
        }
        else
        {
            st.push(stoi(c));
        }
    }

    return st.top();
}

```

---

## Complexity Analysis

Let `n` be the number of tokens.

- **Time Complexity:** `O(n)` — each token is processed once.
- **Space Complexity:** `O(n)` — in the worst case, the stack stores up to `n` operands.

---

## Key Concepts

- Stack
- Reverse Polish Notation (Postfix Expression)
- C++ STL Stack
- String-to-Integer Conversion using `stoi()`
- Arithmetic Operations
- Time and Space Complexity

---

## Language

C++

## LeetCode

[Evaluate Reverse Polish Notation – LeetCode 150](https://leetcode.com/problems/evaluate-reverse-polish-notation/)

## Status

✅ Solved
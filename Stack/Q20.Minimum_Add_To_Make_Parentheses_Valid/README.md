# Q15. Minimum Add to Make Parentheses Valid

**LeetCode Problem:** [921. Minimum Add to Make Parentheses Valid](https://leetcode.com/problems/minimum-add-to-make-parentheses-valid/)  
**Difficulty:** Medium  
**Topics:** String, Stack, Greedy

---

## Problem Statement

Given a string `s` consisting only of opening parentheses `'('` and closing parentheses `')'`, return the minimum number of parentheses that must be added to make the string valid.

A parentheses string is valid if:

- Every opening parenthesis `'('` has a matching closing parenthesis `')'`.
- Every closing parenthesis `')'` has a matching opening parenthesis `'('` before it.
- Parentheses are correctly balanced.

We need to find the minimum number of additions required to make the given string valid.

## Examples

**Example 1:**

Input:
```text
s = "())"
```

Output:
```text
1
```

Explanation:

Add one opening parenthesis `'('` at the beginning to make the string valid.

```text
Original: ())
Valid:    (())
```

**Example 2:**

Input:
```text
s = "((("
```

Output:
```text
3
```

Explanation:

Three closing parentheses `')'` are required.

```text
Original: (((
Valid:    ((()))
```

**Example 3:**

Input:
```text
s = "()))(("
```

Output:
```text
4
```

Explanation:

Two opening parentheses are unmatched by closing parentheses, and two closing parentheses are unmatched by opening parentheses.

Therefore, we need to add 4 parentheses.

---
### Algorithm

1. Create an empty stack of characters.
2. Traverse the string from left to right.
3. For every character:
   - If the stack is not empty, its top is `'('`, and the current character is `')'`, pop the top element.
   - Otherwise, push the current character into the stack.
4. After processing the complete string, the remaining stack elements represent unmatched parentheses.
5. Return the size of the stack.

### Why Do We Check `st.empty()`?

Before accessing `st.top()`, we must ensure that the stack is not empty.

Calling `top()` on an empty stack causes undefined behavior.

### Why Do We Use `if-else` Instead of `while`?

One closing parenthesis can match only one opening parenthesis.

Therefore, for each character, we need at most one pop operation. An `if-else` condition is sufficient.

---

## C++ Solution

```cpp
#include <iostream>
#include <stack>
using namespace std;

int minAddToMakeValid(string s)
{
    stack<char> st;

    for (int i = 0; i < s.length(); i++)
    {
        if (!st.empty() && (st.top() == '(' && s[i] == ')'))
        {
            st.pop();
        }
        else
        {
            st.push(s[i]);
        }
    }

    return st.size();
}
```

**Note:** For LeetCode submission, use the `Solution` class and omit the `main()` function.

---

## Dry Run

Input:

```text
s = "()))(("
```

Initially:

```text
Stack = []
```

| Step | Character | Operation | Stack |
|---|---|---|---|
| 1 | `(` | Push | `(` |
| 2 | `)` | Pop | Empty |
| 3 | `)` | Push | `)` |
| 4 | `)` | Push | `))` |
| 5 | `(` | Push | `))( (` |
| 6 | `(` | Push | `))((` |

After processing all characters:

```text
Stack = [), ), (, (]
```

Stack size:

```text
4
```

Output:

```text
4
```

---

## Complexity Analysis

Let `n` be the length of the string.

| Complexity | Value | Explanation |
|---|---|---|
| Time Complexity | O(n) | We traverse the string once, and each character is pushed and popped at most once. |
| Space Complexity | O(n) | In the worst case, all characters may remain in the stack. |

---

## Key Concepts Learned

- Stack operations: `push()`, `pop()`, `top()`, `empty()`.
- Matching opening and closing parentheses.
- Handling unmatched parentheses.
- Checking stack emptiness before accessing the top element.
- Using stack size to calculate the minimum additions.
- Understanding balanced parentheses.

---

**Language:** C++  
**Status:** Solved ✅
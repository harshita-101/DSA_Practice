# Q12. Backspace String Compare

**LeetCode Problem:** [844. Backspace String Compare](https://leetcode.com/problems/backspace-string-compare/)  
**Difficulty:** Easy  
**Topics:** Stack, String, Two Pointers

---

## 📌 Problem Statement

Given two strings `s` and `t`, return `true` if they are equal when both are typed into empty text editors. Otherwise, return `false`.

The character `#` represents a backspace.

A backspace removes the previous character if one exists. If there is no previous character, the backspace is ignored.

### Example 1

**Input:**
```text
s = "ab#c"
t = "ad#c"
```

**Output:**
```text
true
```

**Explanation:**

- `s = "ab#c"` → `"ac"`
- `t = "ad#c"` → `"ac"`

Both strings become `"ac"`, so return `true`.

### Example 2

**Input:**
```text
s = "ab##"
t = "c#d#"
```

**Output:**
```text
true
```

**Explanation:**

- `s = "ab##"` → `"a"` → `""`
- `t = "c#d#"` → `""`

Both strings become empty, so return `true`.

### Example 3

**Input:**
```text
s = "a#c"
t = "b"
```

**Output:**
```text
false
```

**Explanation:**

- `s = "a#c"` → `"c"`
- `t = "b"` → `"b"`

The resulting strings are different, so return `false`.

---

## 💡 Approach: Stack

We use a **Stack** to process both strings and handle backspace operations.

Instead of directly modifying the original strings, we store valid characters in a stack.

### What Do We Store in the Stack?

```cpp
stack<char> st;
```

We store characters in the stack.

The stack follows the **Last In, First Out (LIFO)** principle.

This is useful because a backspace always removes the most recently added character.

### How Does Backspace Work?

There are two possible cases:

**Case 1: Stack is not empty**

If the current character is `#`, remove the top character using `pop()`.

Example:

```text
Input: "ab#"
```

- Push `a`.
- Push `b`.
- `#` appears, so pop `b`.

Final stack contains:

```text
a
```

**Case 2: Stack is empty**

If the current character is `#` and the stack is empty, ignore it.

Example:

```text
Input: "##a"
```

- First `#` → Ignore.
- Second `#` → Ignore.
- `a` → Push.

Final stack contains:

```text
a
```

### Algorithm

1. Create an empty stack and two empty strings, `s1` and `t1`.
2. Traverse the first string `s`.
3. For every character:
   - If the character is `#` and the stack is not empty, pop the top character.
   - If the character is `#` and the stack is empty, ignore it.
   - Otherwise, push the current character.
4. Pop all remaining characters from the stack and append them to `s1`.
5. Traverse the second string `t` using the same stack.
6. Apply the same backspace rules.
7. Pop all remaining characters and append them to `t1`.
8. Reverse both strings because stack elements are retrieved in reverse order.
9. Compare `s1` and `t1`.
10. If both strings are equal, return `true`; otherwise, return `false`.

### Why Do We Reuse the Same Stack?

After processing the first string, we pop all its remaining characters into `s1`.

This makes the stack empty.

Therefore, we can reuse the same stack to process the second string without creating another stack.

---

## 💻 C++ Solution

```cpp
#include <iostream>
#include <string>
#include <stack>
#include <algorithm>
using namespace std;

bool backspaceCompare(string s, string t)
{
    stack<char> st;
    string s1 = "";
    string t1 = "";

    // Process the first string
    for (int i = 0; i < s.length(); i++)
    {
        if (!st.empty() && s[i] == '#')
        {
            st.pop();
        }
        else if (st.empty() && s[i] == '#')
        {
            continue;
        }
        else
        {
            st.push(s[i]);
        }
    }

    // Build the first processed string
    while (!st.empty())
    {
        s1 += st.top();
        st.pop();
    }

    // Process the second string
    for (int i = 0; i < t.length(); i++)
    {
        if (!st.empty() && t[i] == '#')
        {
            st.pop();
        }
        else if (st.empty() && t[i] == '#')
        {
            continue;
        }
        else
        {
            st.push(t[i]);
        }
    }

    // Build the second processed string
    while (!st.empty())
    {
        t1 += st.top();
        st.pop();
    }

    // Reverse both strings
    reverse(s1.begin(), s1.end());
    reverse(t1.begin(), t1.end());

    // Compare the processed strings
    if (s1 == t1)
    {
        return true;
    }

    return false;
}

```

**Note:** The `main()` function is included for local practice. For LeetCode submission, submit only the `Solution` class with the required `backspaceCompare()` method.

---

## 🔍 Dry Run

**Input:**

```text
s = "ab#c"
t = "ad#c"
```

Initially, the stack is empty.

### Processing First String: `"ab#c"`

| Character | Operation | Stack |
|---|---|---|
| `a` | Push `a` | `a` |
| `b` | Push `b` | `a, b` |
| `#` | Pop `b` | `a` |
| `c` | Push `c` | `a, c` |

Now pop all characters from the stack:

```text
Stack output = "ca"
```

Reverse the string:

```text
s1 = "ac"
```

### Processing Second String: `"ad#c"`

The stack is empty again.

| Character | Operation | Stack |
|---|---|---|
| `a` | Push `a` | `a` |
| `d` | Push `d` | `a, d` |
| `#` | Pop `d` | `a` |
| `c` | Push `c` | `a, c` |

Now pop all characters:

```text
Stack output = "ca"
```

Reverse the string:

```text
t1 = "ac"
```

### Final Comparison

```text
s1 = "ac"
t1 = "ac"
```

Since both strings are equal:

**Output:**
```text
true
```

### Understanding Empty Stack and Backspace

Consider:

```text
s = "a##c"
```

| Character | Operation | Stack |
|---|---|---|
| `a` | Push `a` | `a` |
| First `#` | Pop `a` | Empty |
| Second `#` | Ignore because stack is empty | Empty |
| `c` | Push `c` | `c` |

Final processed string:

```text
"c"
```

This shows why we must check whether the stack is empty before calling `pop()`.

---

## ⏱️ Complexity Analysis

Let `n` be the length of string `s` and `m` be the length of string `t`.

### Time Complexity: `O(n + m)`

- Processing the first string takes `O(n)`.
- Processing the second string takes `O(m)`.
- Building the result strings takes linear time.
- Reversing both strings takes linear time.
- Comparing the final strings takes linear time.

Therefore, the overall time complexity is **`O(n + m)`**.

### Space Complexity: `O(n + m)`

- The stack can store up to `n` characters.
- The processed strings `s1` and `t1` can store up to `n` and `m` characters respectively.

Therefore, the auxiliary space complexity is **`O(n + m)`**.

---

## 🧠 Key Concepts Learned

### 1. Stack

A stack follows the Last In, First Out (LIFO) principle.

We use it to remove the most recently added character when a backspace appears.

### 2. Backspace Handling

The `#` character represents backspace.

- If the stack is not empty, pop the top character.
- If the stack is empty, ignore the backspace.

### 3. Stack Reusability

After processing the first string and popping all its characters, the stack becomes empty.

The same stack can then process the second string.

### 4. String Reversal

Stack elements are retrieved in reverse order, so we use:

```cpp
reverse(s1.begin(), s1.end());
reverse(t1.begin(), t1.end());
```

to restore the original order.

### 5. String Comparison

After processing both strings, compare them using:

```cpp
s1 == t1
```

If both strings are equal, return `true`; otherwise, return `false`.

---

## 📊 Brute Force vs. Optimized Approach

| Feature | Brute Force | Stack Approach |
|---|---|---|
| Approach | Repeatedly modify strings to handle backspaces | Process characters using a stack |
| Backspace Handling | String deletion operations | Pop the stack's top character |
| Time Complexity | Can be `O(n² + m²)` with repeated deletions | `O(n + m)` |
| Extra Space | Depends on implementation | `O(n + m)` |
| Efficiency | Repeated string shifting can be costly | Each character is pushed and popped at most once |

---

## Language

C++

## Status

✅ Solved
# Q11. Make The String Great

**LeetCode Problem:** [1544. Make The String Great](https://leetcode.com/problems/make-the-string-great/)  
**Difficulty:** Easy  
**Topics:** Stack, String, ASCII

---

## 📌 Problem Statement

Given a string `s` of lowercase and uppercase English letters.

A string is considered good if there are no two adjacent characters where:

- Both characters represent the same letter.
- One character is lowercase and the other is uppercase.

To make the string good, repeatedly remove two adjacent characters that have the same letter but different cases.

Return the final good string.

**Note:** The order of the remaining characters must stay the same.

### Example 1

**Input:**
```text
s = "leEeetcode"
```

**Output:**
```text
"leetcode"
```

**Explanation:**

- `E` and `e` are adjacent and represent the same letter with different cases.
- Remove both characters.
- Continue until no such adjacent pair remains.

Final string: `"leetcode"`.

### Example 2

**Input:**
```text
s = "abBAcC"
```

**Output:**
```text
""
```

**Explanation:**

- Remove `bB`.
- The string becomes `"aAcC"`.
- Remove `aA`.
- The string becomes `"cC"`.
- Remove `cC`.

The final string is empty.

### Example 3

**Input:**
```text
s = "s"
```

**Output:**
```text
"s"
```

**Explanation:**

There is only one character, so no removal is possible.

---

## 💡 Approach: Stack

We use a **Stack** to remove adjacent characters that represent the same letter but have different cases.

Instead of repeatedly checking and modifying the original string, we process each character once and compare it with the top character of the stack.

### What Do We Store in the Stack?

```cpp
stack<char> st;
```

We store individual characters in the stack.

For example, for the string `"abBA"`:

- Push `a`.
- Push `b`.
- When `B` appears, compare it with `b`.
- Since they represent the same letter with different cases, pop `b`.
- When `A` appears, compare it with `a`.
- Pop `a`.

The final stack becomes empty.

### How Do We Compare Uppercase and Lowercase Characters?

Every character has an ASCII value.

| Character | ASCII Value |
|---|---:|
| A | 65 |
| B | 66 |
| C | 67 |
| a | 97 |
| b | 98 |
| c | 99 |

The difference between an uppercase and its corresponding lowercase character is always `32`.

For example:

```text
'a' = 97
'A' = 65

Difference = |97 - 65| = 32
```

We use the `abs()` function to calculate the absolute difference.

```cpp
abs(s[i] - st.top()) == 32
```

If the difference is `32`, the two characters represent the same letter but have different cases.

### Algorithm

1. Create an empty stack to store characters.
2. Traverse the input string using a `for` loop.
3. For every character, check whether:
   - The stack is not empty.
   - The absolute difference between the current character and the stack's top character is `32`.
4. If both conditions are true:
   - Remove the top character using `pop()`.
   - Do not push the current character because both characters must be removed.
5. Otherwise, push the current character onto the stack.
6. After processing the entire string, create an empty answer string.
7. Pop all characters from the stack and append them to the answer string.
8. Reverse the answer string because stack elements are retrieved in reverse order.
9. Return the final answer.

### Why Do We Use a Stack?

A stack allows us to compare the current character with the most recently processed character.

When two characters form a bad pair, removing the stack's top character can create a new adjacent pair with the next incoming character.

This is why a stack is useful for handling consecutive removals efficiently.

---

## 💻 C++ Solution

```cpp
#include <iostream>
#include <string>
#include <stack>
#include <algorithm>
using namespace std;

string makeGood(string s)
{
    stack<char> st;
    string ans = "";

    // Traverse the input string
    for (int i = 0; i < s.length(); i++)
    {
        // Check whether current and top characters
        // represent the same letter in different cases
        if (!st.empty() && abs(s[i] - st.top()) == 32)
        {
            // Remove the previous character
            st.pop();
        }
        else
        {
            // Push current character if no bad pair exists
            st.push(s[i]);
        }
    }

    // Build the answer from the stack
    while (!st.empty())
    {
        ans += st.top();
        st.pop();
    }

    // Reverse because stack follows LIFO
    reverse(ans.begin(), ans.end());

    return ans;
}
```

**Note:** The `main()` function is included for local practice. For LeetCode submission, submit only the `Solution` class with the required `makeGood()` method.

---

## 🔍 Dry Run

**Input:**

```text
s = "abBAcC"
```

Initially, the stack is empty.

| Current Character | Operation | Stack (bottom → top) |
|---|---|---|
| `a` | Push `a` | `a` |
| `b` | Push `b` | `a, b` |
| `B` | Difference with `b` is 32; pop `b` | `a` |
| `A` | Difference with `a` is 32; pop `a` | Empty |
| `c` | Push `c` | `c` |
| `C` | Difference with `c` is 32; pop `c` | Empty |

After processing all characters, the stack is empty.

**Output:**

```text
""
```

### Understanding the ASCII Comparison

Consider:

```text
s = "aA"
```

Initially:

```text
Stack = Empty
```

**Step 1:** Current character = `a`

- Stack is empty.
- Push `a`.

```text
Stack = [a]
```

**Step 2:** Current character = `A`

- Stack top = `a`.
- Current character = `A`.
- ASCII difference = `|97 - 65| = 32`.
- Pop `a`.
- Do not push `A`.

```text
Stack = Empty
```

Final answer:

```text
""
```

### Understanding Consecutive Removals

Consider:

```text
s = "leEeetcode"
```

When processing the characters:

- `l` is pushed.
- `e` is pushed.
- `E` matches `e`, so `e` is popped.
- The next `e` matches the previous lowercase `e`, so that character is also removed.
- Processing continues until all characters are handled.

Final output:

```text
"leetcode"
```

---

## ⏱️ Complexity Analysis

### Time Complexity: `O(n)`

Each character is processed once.

- Each character is pushed onto the stack at most once.
- Each character is popped from the stack at most once.
- Reversing the final answer takes `O(n)` time.

Therefore, the overall time complexity is **`O(n)`**, where `n` is the length of the input string.

### Space Complexity: `O(n)`

In the worst case, no characters are removed, and the stack stores all `n` characters.

The answer string can also contain up to `n` characters.

Therefore, the auxiliary space complexity is **`O(n)`**.

---

## 🧠 Key Concepts Learned

### 1. Stack

A stack follows the Last In, First Out (LIFO) principle.

We use it to compare the current character with the previously processed character.

### 2. ASCII Values

Every character has a numerical ASCII value.

The difference between an uppercase English letter and its corresponding lowercase letter is `32`.

### 3. Absolute Difference

```cpp
abs(s[i] - st.top()) == 32
```

This condition identifies two adjacent characters that represent the same letter but have different cases.

### 4. If-Else Logic

- If a bad pair is found, pop the previous character.
- Otherwise, push the current character.

Both characters must be removed when a bad pair is found.

### 5. String Reversal

Since stack elements are retrieved in reverse order, we use:

```cpp
reverse(ans.begin(), ans.end());
```

to restore the original order of the remaining characters.

### 6. Cascading Removals

Removing one pair can create another bad adjacent pair. The stack automatically handles this when the next character is processed.

---

## 📊 Brute Force vs. Optimized Approach

| Feature | Brute Force | Stack Approach |
|---|---|---|
| Approach | Repeatedly search and remove bad adjacent pairs | Process characters using a stack |
| Character Comparison | Repeated scans | Compare with stack top |
| Time Complexity | Can be `O(n²)` | `O(n)` |
| Extra Space | Depends on string modification | `O(n)` |
| Efficiency | Repeated string operations | Each character is pushed and popped at most once |

---

## Language

C++

## Status

✅ Solved
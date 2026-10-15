# Valid Parentheses

## Problem Statement

You are given a string `s` containing only the characters `'('`, `')'`, `'{'`, `'}'`, `'['`, and `']'`.

Determine if the input string is valid.

A string is valid if:
- Every opening bracket is closed by the same type of bracket.
- Brackets are closed in the correct order.
- Every closing bracket has a corresponding opening bracket.

**LeetCode:** 20  
**Difficulty:** Easy

---

## Example

### Example 1

**Input:**
```text
s = "()"
```

**Output:**
```text
true
```

### Example 2

**Input:**
```text
s = "()[]{}"
```

**Output:**
```text
true
```

### Example 3

**Input:**
```text
s = "(]"
```

**Output:**
```text
false
```

### Example 4

**Input:**
```text
s = "([{}])"
```

**Output:**
```text
true
```

---

## Approach

This problem can be solved using a **Stack**.

A stack follows the **LIFO (Last In, First Out)** principle. The last opening bracket inserted must be the first one to be matched with a closing bracket.

Traverse the string character by character.

- If the current character is an opening bracket `(`, `{`, or `[`, push it onto the stack.
- If it is a closing bracket, check whether the stack is empty. If it is empty, return `false`.
- Otherwise, compare the top element of the stack with the current closing bracket.
- If they match, pop the opening bracket from the stack.
- If they do not match, return `false`.

After processing all characters, the string is valid only if the stack is empty.

---

## Algorithm

1. Create an empty stack of characters.
2. Traverse the string from left to right.
3. If the current character is an opening bracket, push it onto the stack.
4. Otherwise:
   - If the stack is empty, return `false`.
   - Check whether the top element matches the current closing bracket.
   - If they match, pop the top element.
   - Otherwise, return `false`.
5. After the loop, check whether the stack is empty.
6. Return `true` if the stack is empty; otherwise, return `false`.

---

## Dry Run

Consider:

```text
s = "([{}])"
```

### Step 1

Character: `(`

Opening bracket, so push it.

```text
Stack: (
```

### Step 2

Character: `[`

Opening bracket, so push it.

```text
Stack: ( [
```

### Step 3

Character: `{`

Opening bracket, so push it.

```text
Stack: ( [ {
```

### Step 4

Character: `}`

The top element is `{`, which matches `}`. Pop it.

```text
Stack: ( [
```

### Step 5

Character: `]`

The top element is `[`, which matches `]`. Pop it.

```text
Stack: (
```

### Step 6

Character: `)`

The top element is `(`, which matches `)`. Pop it.

```text
Stack: Empty
```

The stack is empty after processing all characters.

**Output:**
```text
true
```

---

## Code

```cpp
bool isValid(string s) {
    stack<char> st;

    for (int i = 0; i < s.size(); i++) {
        if (s[i] == '(' || s[i] == '{' || s[i] == '[') {
            st.push(s[i]);
        }
        else {
            if (st.empty()) {
                return false;
            }

            if ((st.top() == '(' && s[i] == ')') ||
                (st.top() == '{' && s[i] == '}') ||
                (st.top() == '[' && s[i] == ']')) {
                st.pop();
            }
            else {
                return false;
            }
        }
    }

    return st.empty();
}
```

---

## Complexity

- **Time Complexity:** O(n)
- **Space Complexity:** O(n)

Where:

- `n` = length of the input string.
- Each character is processed at most once.
- In the worst case, the stack stores all opening brackets.

---

## Key Concepts

- Stack
- LIFO (Last In, First Out)
- String Traversal
- Matching Parentheses
- Conditional Statements
- Stack Operations (`push`, `pop`, `top`, `empty`)

---

## Status

✅ Solved
# Basic Calculator II with Parentheses

## Problem Statement

Given a string `s` representing a mathematical expression, evaluate and return its result.

The expression can contain:

- Positive integers
- `+` operator
- `-` operator
- Parentheses `(` and `)`
- Spaces

The expression should be evaluated while correctly handling nested parentheses and the sign before each expression.

**Difficulty:** Hard  
**LeetCode:** 224 — Basic Calculator

---

## Example

### Example 1

**Input:**
`s = "1 + 1"`

**Output:**
`2`

### Example 2

**Input:**
`s = "2-1 + 2"`

**Output:**
`3`

### Example 3

**Input:**
`s = "(1+(4+5+2)-3)+(6+8)"`

**Output:**
`23`

---

## Approach

The expression is evaluated using a **Stack** along with variables to keep track of the current result, number, and sign.

We maintain:

- `num` → stores the current number being formed.
- `result` → stores the result of the current expression.
- `sign` → stores whether the current number should be added or subtracted.
- `stack` → stores the result and sign before entering a parenthesis.

### Handling Digits

If the current character is a digit, construct the complete number:

`num = num * 10 + digit`

This allows numbers with multiple digits to be handled correctly.

### Handling `+` and `-`

Before changing the sign, add the current number to the result:

`result += num * sign`

Then reset `num` and update the sign.

### Handling `(`

When an opening parenthesis is encountered:

1. Store the current `result` in the stack.
2. Store the current `sign` in the stack.
3. Reset `result` to `0`.
4. Reset `sign` to `1`.

This allows the expression inside the parentheses to be calculated independently.

### Handling `)`

When a closing parenthesis is encountered:

1. Add the current number to the result.
2. Retrieve the sign before the parenthesis.
3. Retrieve the result before the parenthesis.
4. Combine both results:

`result = prevResult + prevSign * result`

This correctly connects the parenthesized expression with the expression outside it.

---

## Algorithm

1. Initialize `result = 0`, `num = 0`, and `sign = 1`.
2. Create an empty stack.
3. Traverse the expression from left to right.
4. If the character is a digit, construct the number.
5. If the character is `+`:
   - Add `num * sign` to `result`.
   - Reset `num`.
   - Set `sign = 1`.
6. If the character is `-`:
   - Add `num * sign` to `result`.
   - Reset `num`.
   - Set `sign = -1`.
7. If the character is `(`:
   - Push the current `result`.
   - Push the current `sign`.
   - Reset `result` and `sign`.
8. If the character is `)`:
   - Add the current number to `result`.
   - Pop the previous sign and result.
   - Combine them with the current result.
9. After the loop, add the remaining number to `result`.
10. Return the final result.

---

## Dry Run

Consider:

`s = "1+(2-3)"`

Initial:

`result = 0`  
`num = 0`  
`sign = 1`

### Read `1`

`num = 1`

### Read `+`

`result += 1 * 1`

`result = 1`

Reset:

`num = 0`  
`sign = 1`

### Read `(`

Push:

`result = 1`  
`sign = 1`

Stack:

`[1, 1]`

Reset:

`result = 0`  
`sign = 1`

### Read `2`

`num = 2`

### Read `-`

`result += 2 * 1`

`result = 2`

Set:

`sign = -1`

### Read `3`

`num = 3`

### Read `)`

First:

`result += 3 * (-1)`

`result = -1`

Pop from stack:

`prevSign = 1`  
`prevResult = 1`

Combine:

`result = 1 + 1 * (-1)`

`result = 0`

Therefore:

`Output = 0`

---

## Code

    #include <iostream>
    #include <stack>
    #include <string>
    #include <cctype>
    using namespace std;

    int calculate(string s)
    {
        long long result = 0;
        long long num = 0;
        int sign = 1;

        stack<long long> st;

        for (int i = 0; i < s.size(); i++)
        {
            if (isdigit(s[i]))
            {
                num = num * 10 + (s[i] - '0');
            }
            else if (s[i] == '+')
            {
                result += num * sign;
                num = 0;
                sign = 1;
            }
            else if (s[i] == '-')
            {
                result += num * sign;
                num = 0;
                sign = -1;
            }
            else if (s[i] == '(')
            {
                st.push(result);
                st.push(sign);

                result = 0;
                sign = 1;
            }
            else if (s[i] == ')')
            {
                result += num * sign;
                num = 0;

                long long prevSign = st.top();
                st.pop();

                long long prevResult = st.top();
                st.pop();

                result = prevResult + prevSign * result;
            }
        }

        result += num * sign;

        return (int)result;
    }

    int main()
    {
        string s;

        cout << "Enter the expression: ";
        getline(cin, s);

        cout << "Result: " << calculate(s) << endl;

        return 0;
    }

---

## Complexity

Let `n` be the length of the expression.

- **Time Complexity:** O(n)
- **Space Complexity:** O(n)

The stack can store information for nested parentheses.

---

## Key Concepts

- Stack
- String Traversal
- Expression Evaluation
- Parentheses Handling
- Sign Management
- Number Construction
- Nested Expressions

---

## Status

✅ Solved
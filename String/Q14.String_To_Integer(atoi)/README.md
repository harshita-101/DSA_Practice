# String to Integer (atoi)

## Problem Statement

Given a string `s`, convert it into a 32-bit signed integer.

The conversion follows the rules of the `atoi()` function.

The string may contain:

- Leading spaces
- A positive (`+`) or negative (`-`) sign
- Numeric characters
- Other characters after the number

The conversion stops when a non-digit character is encountered.

If the converted number exceeds the range of a 32-bit signed integer, return the appropriate boundary value.

**Difficulty:** Medium  
**LeetCode:** 8

---

## Example

```text
Input:
s = "   -42"

Output:
-42
```

### Explanation

First, the leading spaces are ignored.

Then the `-` sign is detected, so the number is negative.

The digits are converted one by one:

```text
4 → 4
2 → 42
```

Finally:

```text
-1 × 42 = -42
```

---

## Another Example

```text
Input:
s = "4193 with words"

Output:
4193
```

The conversion stops when a non-digit character is encountered.

---

## Approach

Use **String Traversal and Parsing**.

First, skip all leading spaces.

Then check whether the number contains a positive (`+`) or negative (`-`) sign.

Store the sign separately:

```text
'+' → sign = 1
'-' → sign = -1
```

If no sign is present, the number is considered positive.

Next, traverse the string while the characters are digits.

A digit is identified using:

```cpp
'0' <= s[i] && s[i] <= '9'
```

Each character is converted into an integer using:

```cpp
digit = s[i] - '0'
```

The number is built digit by digit:

```cpp
num = num * 10 + digit
```

For example, for `"123"`:

```text
num = 0 × 10 + 1 = 1
num = 1 × 10 + 2 = 12
num = 12 × 10 + 3 = 123
```

A `long long` variable is used while building the number to handle larger values.

Finally, check whether the number exceeds the range of a 32-bit signed integer.

```text
INT_MIN = -2147483648
INT_MAX = 2147483647
```

### Cases

**1. Positive Overflow**

If the number exceeds the maximum integer value:

```text
Return INT_MAX
```

**2. Negative Overflow**

If the negative number exceeds the minimum integer value:

```text
Return INT_MIN
```

Finally, apply the sign to the number.

```cpp
num = sign * num
```

---

## Algorithm

1. Initialize `i = 0`, `num = 0`, and `sign = 1`.
2. Skip all leading spaces.
3. If the entire string contains only spaces, return `0`.
4. Check for a `+` or `-` sign.
5. Store the appropriate sign.
6. Traverse the string while the characters are digits.
7. Convert each character using `s[i] - '0'`.
8. Build the number using `num = num * 10 + digit`.
9. Check for integer overflow.
10. Return `INT_MAX` for positive overflow.
11. Return `INT_MIN` for negative overflow.
12. Apply the sign and return the final number.

---

## Dry Run

Consider the input:

```text
s = "   -123abc"
```

### Step 1: Skip Spaces

```text
"   -123abc"
   ↓
"-123abc"
```

### Step 2: Check Sign

```text
s[i] = '-'

sign = -1
```

### Step 3: Process Digits

```text
Digit: 1
num = 1

Digit: 2
num = 12

Digit: 3
num = 123
```

The next character is `'a'`, which is not a digit, so the conversion stops.

### Step 4: Apply Sign

```text
sign × num

-1 × 123 = -123
```

### Output

```text
-123
```

---

## Complexity

Let `n` be the length of the input string.

| Time Complexity | Space Complexity |
|-----------------|------------------|
| O(n) | O(1) |

---

## Key Concepts

- String Traversal
- String Parsing
- Character to Integer Conversion
- Sign Handling
- Leading Space Removal
- Overflow Handling
- `long long`
- Integer Range

---

## Status

✅ Solved
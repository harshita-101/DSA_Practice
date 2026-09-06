# Roman to Integer

## Problem Statement

Given a Roman numeral represented as a string `s`, convert it into its corresponding integer value.

Roman numerals are represented using the following symbols:

| Symbol | Value |
|--------|-------|
| I | 1 |
| V | 5 |
| X | 10 |
| L | 50 |
| C | 100 |
| D | 500 |
| M | 1000 |

Usually, Roman numerals are written from largest to smallest values from left to right.

However, when a smaller value appears before a larger value, the smaller value is subtracted.

**Difficulty:** Easy  
**LeetCode:** 13

---

## Example

```text
Input:
s = "LVIII"

Output:
58
```

### Explanation

The values are:

```text
L = 50
V = 5
I = 1
I = 1
I = 1
```

Therefore:

```text
50 + 5 + 1 + 1 + 1 = 58
```

---

## Another Example

```text
Input:
s = "MCMXCIV"

Output:
1994
```

### Explanation

The Roman numeral can be interpreted as:

```text
M  = 1000
CM = 900
XC = 90
IV = 4
```

Therefore:

```text
1000 + 900 + 90 + 4 = 1994
```

---

## Approach

Use **String Traversal**.

First, convert every Roman character into its corresponding integer value.

A helper function is used for this conversion.

```text
I → 1
V → 5
X → 10
L → 50
C → 100
D → 500
M → 1000
```

Traverse the string from left to right.

For every character, compare its value with the value of the next character.

### Cases

**1. Current Value is Greater Than or Equal to Next Value**

Add the current value to the answer.

For example:

```text
VI

V = 5
I = 1

5 > 1
```

Therefore:

```text
5 + 1 = 6
```

---

**2. Current Value is Smaller Than Next Value**

Subtract the current value from the answer.

For example:

```text
IV

I = 1
V = 5
```

Since:

```text
1 < 5
```

Subtract `1` and then add `5`:

```text
-1 + 5 = 4
```

This handles subtractive combinations such as:

```text
IV → 4
IX → 9
XL → 40
XC → 90
CD → 400
CM → 900
```

---

## Algorithm

1. Initialize `ans = 0`.
2. Traverse the Roman numeral string.
3. Convert the current character into its integer value.
4. If a next character exists, convert it into its integer value.
5. Compare the current value with the next value.
6. If the current value is smaller, subtract it from `ans`.
7. Otherwise, add it to `ans`.
8. Add the value of the last character.
9. Return the final integer value.

---

## Dry Run

Consider:

```text
s = "MCMXCIV"
```

### Step 1

```text
M = 1000
C = 100
```

Since:

```text
1000 > 100
```

Add `1000`.

```text
ans = 1000
```

---

### Step 2

```text
C = 100
M = 1000
```

Since:

```text
100 < 1000
```

Subtract `100`.

```text
ans = 1000 - 100
ans = 900
```

---

### Step 3

```text
M = 1000
X = 10
```

Since:

```text
1000 > 10
```

Add `1000`.

```text
ans = 1900
```

---

### Step 4

```text
X = 10
C = 100
```

Since:

```text
10 < 100
```

Subtract `10`.

```text
ans = 1890
```

---

### Step 5

```text
C = 100
I = 1
```

Since:

```text
100 > 1
```

Add `100`.

```text
ans = 1990
```

---

### Step 6

```text
I = 1
V = 5
```

Since:

```text
1 < 5
```

Subtract `1`.

```text
ans = 1989
```

---

### Step 7

The last character is:

```text
V = 5
```

Add `5`.

```text
ans = 1994
```

### Output

```text
1994
```

---

## Complexity

Let `n` be the length of the Roman numeral string.

| Time Complexity | Space Complexity |
|-----------------|------------------|
| O(n)            | O(1)             |

---

## Key Concepts

- String Traversal
- Character Mapping
- Switch Statement
- Roman Numerals
- Subtractive Notation
- Look Ahead Technique
- Conditional Logic

---

## Status

✅ Solved
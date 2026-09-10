# Excel Sheet Column Number

## Problem Statement

Given a string `columnTitle` representing an Excel column title, return its corresponding column number.

Excel columns follow this pattern:

- `A → 1`
- `B → 2`
- `C → 3`
- ...
- `Z → 26`
- `AA → 27`
- `AB → 28`

**LeetCode:** 171  
**Difficulty:** Easy

---

## Example

### Example 1

**Input:**
`columnTitle = "A"`

**Output:**
`1`

### Example 2

**Input:**
`columnTitle = "AB"`

**Output:**
`28`

### Example 3

**Input:**
`columnTitle = "ZY"`

**Output:**
`701`

---

## Approach

This problem can be solved by treating the Excel column title as a **Base-26 number system**.

Each character has a value from `1` to `26`:

- `A = 1`
- `B = 2`
- ...
- `Z = 26`

For every character, calculate its value using:

`columnTitle[i] - 'A' + 1`

Then update the answer as:

`ans = ans * 26 + value`

This is similar to converting a number from a positional number system.

---

## Algorithm

1. Initialize `ans = 0`.
2. Traverse the string from left to right.
3. Convert the current character into its numerical value.
4. Multiply the current answer by `26`.
5. Add the current character's value.
6. Continue until all characters are processed.
7. Return `ans`.

---

## Dry Run

Consider:

`columnTitle = "AB"`

### Step 1

Current character = `A`

`A - 'A' + 1 = 1`

`ans = 0 * 26 + 1`

`ans = 1`

### Step 2

Current character = `B`

`B - 'A' + 1 = 2`

`ans = 1 * 26 + 2`

`ans = 28`

Therefore:

`AB = 28`

---

## Code

    #include <iostream>
    #include <string>
    using namespace std;

    int titleToNumber(string columnTitle)
    {
        int ans = 0;

        for (int i = 0; i < columnTitle.size(); i++)
        {
            int value = columnTitle[i] - 'A' + 1;
            ans = ans * 26 + value;
        }

        return ans;
    }

---

## Complexity

- **Time Complexity:** O(n)
- **Space Complexity:** O(1)

Where `n` is the length of `columnTitle`.

---

## Key Concepts

- String Traversal
- Character Arithmetic
- Base-26 Conversion
- Positional Number System
- Mathematical Approach

---

## Status

✅ Solved
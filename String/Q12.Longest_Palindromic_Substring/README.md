# Q12. Longest Palindromic Substring

## Problem Statement

Given a string `s`, return the longest palindromic substring in `s`.

A palindrome is a string that reads the same forward and backward.

**Difficulty:** Medium

**LeetCode:** 5

---

## Examples

### Example 1

```text
Input:
s = "babad"

Output:
"bab"
```

Explanation:

`"aba"` is also a valid answer because both `"bab"` and `"aba"` are palindromes of maximum length `3`.

---

### Example 2

```text
Input:
s = "cbbd"

Output:
"bb"
```

Explanation:

`"bb"` is the longest palindromic substring.

---

### Example 3

```text
Input:
s = "a"

Output:
"a"
```

---

## Approach

Use the **Expand Around Center** technique.

Every palindrome has a center.

There are two types of palindromes:

### 1. Odd Length Palindrome

Example:

```text
"aba"
```

The center is one character:

```text
a b a
  ↑
center
```

For every index `i`, consider:

```text
left = i
right = i
```

Then expand outward while the characters are equal.

---

### 2. Even Length Palindrome

Example:

```text
"abba"
```

The center lies between two characters:

```text
a b | b a
    ↑
  center
```

For every index `i`, consider:

```text
left = i
right = i + 1
```

Then expand outward while the characters are equal.

---

## Algorithm

1. Initialize:
   ```text
   maxlength = 1
   start = 0
   ```

2. Traverse every character using index `i`.

3. Check for an **odd-length palindrome**:
   ```text
   left = i
   right = i
   ```

4. Expand while:
   - `left >= 0`
   - `right < s.length()`
   - `s[left] == s[right]`

5. Calculate the current palindrome length:
   ```text
   right - left + 1
   ```

6. If the current palindrome is longer than the previous maximum:
   - Update `maxlength`
   - Update `start`

7. Check for an **even-length palindrome**:
   ```text
   left = i
   right = i + 1
   ```

8. Again expand while the characters are equal.

9. Update the maximum palindrome if required.

10. Finally, return:
   ```text
   s.substr(start, maxlength)
   ```

---

## Dry Run

### Input

```text
s = "babad"
```

Initial:

```text
maxlength = 1
start = 0
```

### Center = index 0

Character:

```text
b
```

Odd palindrome:

```text
b
```

Length:

```text
1
```

---

### Center = index 1

Character:

```text
a
```

Expand:

```text
a
```

Then:

```text
b a b
↑   ↑
```

Characters match:

```text
b == b
```

Palindrome:

```text
"bab"
```

Length:

```text
3
```

Update:

```text
maxlength = 3
start = 0
```

---

### Center = index 2

Character:

```text
b
```

Expand:

```text
b a b
```

and further:

```text
a b a
```

Palindrome:

```text
"aba"
```

Length:

```text
3
```

It is not greater than the current maximum, so no update is required.

---

### Final Result

```text
Longest Palindromic Substring = "bab"
```

---

## Why Two Cases?

We need to check both odd and even length palindromes.

### Odd Length

```text
"racecar"
```

One center character:

```text
race c ecar
     ↑
```

### Even Length

```text
"abba"
```

Two center characters:

```text
ab ba
  ↑
```

If we check only one case, we can miss valid palindromes such as `"bb"` or `"abba"`.

---

## Complexity Analysis

### Time Complexity

```text
O(n²)
```

There are `n` possible centers.

For every center, we may expand up to `O(n)` characters.

Therefore:

```text
O(n × n) = O(n²)
```

---

### Space Complexity

```text
O(1)
```

Only a few variables such as:

```text
left
right
start
maxlength
currentlength
```

are used.

The algorithm does not use any additional data structure proportional to the input size.

---

## Why This Approach?

A brute-force approach would generate all possible substrings and check each one for being a palindrome.

That requires more unnecessary work.

Expand Around Center directly searches for palindromes by treating every possible center as a starting point.

Therefore, it is much more efficient and uses constant extra space.

---

## Comparison of Approaches

| Approach | Time Complexity | Space Complexity |
| --- | --- | --- |
| Brute Force | O(n³) | O(1) |
| Dynamic Programming | O(n²) | O(n²) |
| Expand Around Center | O(n²) | O(1) |
| Manacher's Algorithm | O(n) | O(n) |

For interviews, **Expand Around Center** is usually a very good balance between simplicity, efficiency, and constant extra space.

---

## Key Concepts

- Palindrome
- Substring
- Two Pointers
- Expand Around Center
- Odd Length Palindrome
- Even Length Palindrome
- String Traversal
- `substr()`
- In-place comparison

---

## Interview Tips

- Always consider both odd and even length palindromes.
- For odd palindrome:
  ```text
  left = i
  right = i
  ```
- For even palindrome:
  ```text
  left = i
  right = i + 1
  ```
- Expand while characters are equal.
- Current palindrome length:
  ```text
  right - left + 1
  ```
- Store the starting index and maximum length instead of creating every substring.
- `O(n²)` time and `O(1)` extra space is a strong interview solution.

---

## Folder Structure

```text
Q12.Longest_Palindromic_Substring/
├── README.md
└── longest_palindromic_substring.cpp
```

---

## Learning Outcomes

After solving this problem, you will understand:

- How to identify palindrome centers.
- How to handle odd and even length palindromes.
- How the Expand Around Center technique works.
- How Two Pointers can be used for palindrome problems.
- How to find the longest palindrome using `O(n²)` time and `O(1)` extra space.
- Why storing only the starting index and length is better than storing all substrings.

---

## Status

✅ Solved
# Q2. Valid Palindrome

## Problem Statement

Given a string `s`, determine whether it is a palindrome after:

- Converting all uppercase letters to lowercase.
- Removing all non-alphanumeric characters.

Return **true** if the string is a palindrome; otherwise, return **false**.

**Difficulty:** Easy

**LeetCode:** 125

---

## Examples

### Example 1

```text
Input:
"A man, a plan, a canal: Panama"

Output:
true
```

Explanation

After removing special characters and converting to lowercase:

```text
amanaplanacanalpanama
```

It is a palindrome.

---

### Example 2

```text
Input:
"race a car"

Output:
false
```

---

### Example 3

```text
Input:
" "

Output:
true
```

---

## Approach

Use the **Two Pointer** technique.

- Initialize one pointer at the beginning.
- Initialize another pointer at the end.
- Ignore all non-alphanumeric characters.
- Compare characters after converting them to lowercase.
- If both characters are equal, move both pointers.
- Otherwise, return false.

If the entire string is traversed successfully, return true.

---

## Algorithm

1. Initialize `left = 0` and `right = n - 1`.
2. While `left < right`:
   - Skip non-alphanumeric characters from the left.
   - Skip non-alphanumeric characters from the right.
   - Compare both characters after converting them to lowercase.
   - If they are different, return false.
   - Otherwise, move both pointers.
3. Return true.

---

## Helper Function

```cpp
bool isAlphaNum(char ch)
```

Checks whether the given character is:

- Alphabet (`A-Z` or `a-z`)
- Digit (`0-9`)

---

## Dry Run

Input

```text
A man, a plan, a canal: Panama
```

After ignoring special characters

```text
amanaplanacanalpanama
```

Comparisons

```text
a == a
m == m
a == a
n == n
...
```

All characters match.

Return

```text
true
```

---

## Complexity Analysis

### Time Complexity

```
O(n)
```

### Space Complexity

```
O(1)
```

---

## Key Concepts

- Two Pointers
- String Traversal
- Character Comparison
- Case Conversion
- Alphanumeric Checking

---

## Interview Tips

- Ignore spaces and special characters.
- Perform case-insensitive comparison.
- Use Two Pointers to achieve O(1) extra space.
- Do not create a new string unnecessarily.

---

## Folder Structure

```
Q2.Valid_Palindrome/
├── README.md
└── valid_palindrome.cpp
```

---

## Learning Outcomes

After solving this problem, you will understand:

- Two Pointer technique.
- Case-insensitive string comparison.
- Skipping unwanted characters efficiently.
- In-place palindrome checking.

---

## Status

✅ Solved
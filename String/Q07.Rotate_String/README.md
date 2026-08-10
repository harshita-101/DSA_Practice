# Q7. Rotate String

## Problem Statement

Given two strings `s` and `goal`, return `true` if and only if `s` can become `goal` after some number of left rotations.

A rotation moves the first character of the string to the end.

**Difficulty:** Easy

**LeetCode:** 796

---

## Examples

### Example 1

```text
Input:
s = "abcde"
goal = "cdeab"

Output:
true
```

Explanation:

```text
abcde
 ↓
bcdea
 ↓
cdeab
```

So `goal` is a rotation of `s`.

---

### Example 2

```text
Input:
s = "abcde"
goal = "abced"

Output:
false
```

`goal` cannot be obtained by rotating `s`.

---

## Approach

The key observation is that if `goal` is a rotation of `s`, then `goal` must be present as a substring of:

```text
s + s
```

For example:

```text
s = "abcde"

s + s = "abcdeabcde"
```

All possible rotations of `s` can be found inside `s + s`.

```text
abcde
bcdea
cdeab
deabc
eabcd
```

Therefore, we check whether `goal` exists inside `s + s`.

---

## Algorithm

1. Check whether the lengths of `s` and `goal` are equal.
2. If the lengths are different, return `false`.
3. Create a new string:
   ```cpp
   string combined = s + s;
   ```
4. Search for `goal` inside `combined` using `find()`.
5. If `goal` is found, return `true`.
6. Otherwise, return `false`.

---

## Why `s + s` Works?

Consider:

```text
s = "abcde"
```

After concatenation:

```text
s + s = "abcdeabcde"
```

Every possible rotation appears as a substring:

```text
abcde
bcdea
cdeab
deabc
eabcd
```

Therefore:

```cpp
combined.find(goal) != string::npos
```

checks whether `goal` is one of these rotations.

---

## Understanding `string::npos`

`string::npos` represents **no position found**.

If:

```cpp
combined.find(goal) == string::npos
```

then `goal` was not found.

If:

```cpp
combined.find(goal) != string::npos
```

then `goal` was found.

---

## Dry Run

### Input

```text
s = "abcde"
goal = "cdeab"
```

### Step 1: Length Check

```text
Length of s = 5
Length of goal = 5
```

Lengths are equal.

---

### Step 2: Concatenate

```text
combined = s + s

combined = "abcdeabcde"
```

---

### Step 3: Search

```text
goal = "cdeab"
```

`"cdeab"` is present in:

```text
"abcdeabcde"
   ↑
 "cdeab"
```

Therefore:

```text
Output: true
```

---

## Complexity Analysis

### Time Complexity

```text
O(n²)
```

In the worst case, standard substring search can take `O(n²)` depending on the implementation.

### Space Complexity

```text
O(n)
```

Because `s + s` creates a new string of size approximately `2n`.

---

## Key Concepts

- String Manipulation
- String Concatenation
- Substring Search
- `find()`
- `string::npos`
- Rotations

---

## Interview Tips

- First check whether both strings have the same length.
- Remember the important observation:
  ```text
  goal must be a substring of s + s
  ```
- `string::npos` means the substring was not found.
- This approach is much simpler than manually generating every rotation.

---

## Folder Structure

```text
Q7.Rotate_String/
├── README.md
└── rotate_string.cpp
```

---

## Learning Outcomes

After solving this problem, you will understand:

- How string rotations work.
- The `s + s` rotation trick.
- How `find()` performs substring searching.
- The meaning of `string::npos`.
- Efficient string manipulation techniques.

---

## Status

✅ Solved
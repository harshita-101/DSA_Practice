# Find All Anagrams in a String

## Problem Statement

Given two strings `s` and `p`, find all starting indices of substrings in `s` that are anagrams of `p`.

An anagram contains the same characters with the same frequencies but possibly in a different order.

Return all the starting indices of the anagrams.

**Difficulty:** Medium  
**LeetCode:** 438

---

## Example

```text
Input:
s = "cbaebabacd"
p = "abc"

Output:
[0,6]
```

### Explanation

The substrings starting at index `0` and `6` are:

```text
Index 0 → "cba"
Index 6 → "bac"
```

Both `"cba"` and `"bac"` are anagrams of `"abc"`.

Therefore:

```text
[0,6]
```

---

## Approach

Use the **Sliding Window Technique** along with **Hash Maps**.

First, store the frequency of every character in string `p`.

```text
p = "abc"

a → 1
b → 1
c → 1
```

Then, create a sliding window in string `s` with the same size as `p`.

For every window, store the frequency of its characters.

If the frequency map of the current window is equal to the frequency map of `p`, then the current substring is an anagram.

---

## How the Sliding Window Works

Two pointers are used:

```text
left  → Starting index of the window
right → Ending index of the window
```

The `right` pointer expands the window by adding new characters.

If the window size becomes greater than the length of `p`, remove the character at the `left` pointer and move `left` forward.

```text
Window Size > p.size()
```

After maintaining the required window size, compare the two frequency maps.

```cpp
freq1 == freq2
```

If both maps are equal, store the `left` index in the answer.

---

## Algorithm

1. Create a frequency map for string `p`.
2. Initialize `left = 0`.
3. Traverse string `s` using the `right` pointer.
4. Add `s[right]` to the current window frequency map.
5. Check if the window size exceeds the size of `p`.
6. If yes, remove `s[left]` from the window.
7. Move the `left` pointer forward.
8. When the window size equals `p.size()`, compare both frequency maps.
9. If both maps are equal, store the `left` index.
10. Return all stored indices.

---

## Dry Run

Consider:

```text
s = "cbaebabacd"
p = "abc"
```

The required window size is:

```text
p.size() = 3
```

### Window 1

```text
"cba"
```

Frequency:

```text
a → 1
b → 1
c → 1
```

This matches the frequency of `"abc"`.

Store:

```text
Index = 0
```

---

### Window 2

```text
"bae"
```

Frequency does not match `"abc"`.

Do not store the index.

---

### Continuing the Process

The window keeps moving one character at a time.

Eventually:

```text
"bac"
```

is found at index:

```text
6
```

Its frequency matches `"abc"`.

Store:

```text
Index = 6
```

### Output

```text
[0,6]
```

---

## Complexity

Let:

- `n` be the length of string `s`
- `m` be the length of string `p`

| Time Complexity | Space Complexity |
|-----------------|------------------|
| O(n)            | O(m)             |

---

## Key Concepts

- Sliding Window
- Two Pointers
- Hashing
- Frequency Counting
- `unordered_map`
- String Traversal
- Anagram Detection

---

## Status

✅ Solved
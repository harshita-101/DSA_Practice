# Q10. Longest Substring Without Repeating Characters

## Problem Statement

Given a string `s`, find the length of the longest substring without repeating characters.

A substring is a contiguous sequence of characters in the string.

**Difficulty:** Medium

**LeetCode:** 3

---

## Examples

### Example 1

```text
Input:
s = "abcabcbb"

Output:
3
```

Explanation:

The longest substring without repeating characters is:

```text
"abc"
```

Length = `3`

---

### Example 2

```text
Input:
s = "bbbbb"

Output:
1
```

Explanation:

The longest substring is:

```text
"b"
```

Length = `1`

---

### Example 3

```text
Input:
s = "pwwkew"

Output:
3
```

Explanation:

The longest substring without repeating characters is:

```text
"wke"
```

Length = `3`

---

## Approach

Use the **Sliding Window** technique with two pointers and an `unordered_set`.

We maintain a window containing only **unique characters**.

Two pointers are used:

- `left` → starting position of the current window.
- `right` → ending position of the current window.

The `unordered_set` keeps track of characters currently present in the window.

---

## Algorithm

1. Initialize `left = 0`.
2. Create an empty `unordered_set`.
3. Traverse the string using the `right` pointer.
4. If `s[right]` is already present in the set:
   - Remove `s[left]` from the set.
   - Increment `left`.
   - Continue until the duplicate character is removed.
5. Insert `s[right]` into the set.
6. Calculate the current window length:
   ```text
   right - left + 1
   ```
7. Update `maxLength`.
8. Continue until the entire string is processed.
9. Return `maxLength`.

---

## Dry Run

### Input

```text
s = "abcabcbb"
```

Initial:

```text
left = 0
right = 0
maxLength = 0
set = {}
```

### Step 1

Character:

```text
a
```

Set:

```text
{a}
```

Window:

```text
"abc"
```

Current length:

```text
1
```

Maximum:

```text
1
```

---

### Step 2

Character:

```text
b
```

Set:

```text
{a, b}
```

Window:

```text
"ab"
```

Current length:

```text
2
```

Maximum:

```text
2
```

---

### Step 3

Character:

```text
c
```

Set:

```text
{a, b, c}
```

Window:

```text
"abc"
```

Current length:

```text
3
```

Maximum:

```text
3
```

---

### Step 4

Character:

```text
a
```

`a` is already present in the set.

So we remove characters from the left:

```text
a
```

and move `left` forward.

Now the window becomes:

```text
"bca"
```

Set:

```text
{b, c, a}
```

Current length:

```text
3
```

Maximum remains:

```text
3
```

The same process continues for the remaining characters.

Final answer:

```text
3
```

---

## Why Sliding Window?

A brute-force approach would generate every possible substring and check whether it contains duplicate characters.

This results in unnecessary repeated work.

Sliding Window maintains a valid range of unique characters and only moves the pointers forward.

Therefore, the same characters do not need to be repeatedly processed.

---

## Example of Window Movement

For:

```text
s = "abcabcbb"
```

The window initially expands:

```text
[a]
[a b]
[a b c]
```

When another `a` appears:

```text
[a b c a]
```

there is a duplicate.

So the left side of the window is moved forward:

```text
[a b c a]
 ↑
left
```

After removing the previous `a`:

```text
[b c a]
```

The window is valid again.

---

## Complexity Analysis

### Time Complexity

```text
O(n)
```

The `right` pointer moves from `0` to `n-1`.

The `left` pointer also moves only forward and never moves backward.

Therefore, each character is inserted into and removed from the set at most once.

So the total time complexity is:

```text
O(n)
```

---

### Space Complexity

```text
O(min(n, charset))
```

The `unordered_set` stores the characters currently present in the sliding window.

If the character set is fixed, the space can effectively be considered:

```text
O(1)
```

---

## Why This Approach Is Optimal

The string must be traversed to determine the longest substring, so `O(n)` time is asymptotically optimal.

The Sliding Window avoids the `O(n²)` brute-force approach.

Therefore:

```text
Time  = O(n)
Space = O(min(n, charset))
```

---

## Key Concepts

- Sliding Window
- Two Pointers
- `unordered_set`
- Hashing
- Duplicate Detection
- Substring
- Window Expansion
- Window Contraction
- Dynamic Window

---

## Interview Tips

- Remember: **substring must be contiguous**.
- Use Sliding Window for longest/shortest valid substring problems.
- Use a set when you need to quickly check whether a character already exists.
- When a duplicate appears, move `left` until the window becomes valid.
- Current window length:
  ```text
  right - left + 1
  ```
- `O(n)` is the optimal time complexity for this approach.

---

## Alternative Approach

Another efficient approach uses a frequency array or last-occurrence array.

For a fixed character set, an array can provide constant-time lookup without hash-table overhead.

However, the current:

```text
Sliding Window + unordered_set
```

approach is simple, efficient, and interview-friendly.

---

## Folder Structure

```text
Q10.Longest_Substring_Without_Repeating_Characters/
├── README.md
└── longest_substring_without_repeating_characters.cpp
```

---

## Learning Outcomes

After solving this problem, you will understand:

- How Sliding Window works.
- How Two Pointers maintain a dynamic range.
- How to detect duplicate characters efficiently.
- How to expand and shrink a window.
- How to solve substring problems in `O(n)` time.
- When to use `unordered_set` for duplicate detection.

---

## Status

✅ Solved
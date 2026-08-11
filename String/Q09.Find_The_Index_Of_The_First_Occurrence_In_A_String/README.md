# Q9. Find the Index of the First Occurrence in a String

## Problem Statement

Given two strings `haystack` and `needle`, return the index of the first occurrence of `needle` in `haystack`.

If `needle` is not found, return `-1`.

If `needle` is an empty string, return `0`.

**Difficulty:** Easy

**LeetCode:** 28

---

## Examples

### Example 1

```text
Input:
haystack = "sadbutsad"
needle = "sad"

Output:
0
```

Explanation:

The first occurrence of `"sad"` starts at index `0`.

---

### Example 2

```text
Input:
haystack = "leetcode"
needle = "leeto"

Output:
-1
```

Explanation:

`"leeto"` does not occur in `"leetcode"`.

---

### Example 3

```text
Input:
haystack = "mississippi"
needle = "issip"

Output:
4
```

Explanation:

The first occurrence of `"issip"` starts at index `4`.

---

## Approach

The problem is solved using a **Brute Force String Matching** approach.

We check every possible starting position in `haystack` where `needle` can fit.

For every starting position:

1. Compare the characters of `haystack` and `needle`.
2. If all characters match, return the current starting index.
3. If a mismatch occurs, move to the next starting position.
4. If no match is found, return `-1`.

---

## Algorithm

1. Store the lengths of both strings:
   - `n` = length of `haystack`
   - `m` = length of `needle`
2. Iterate through `haystack` from index `0` to `n - m`.
3. For each index `i`, start comparing `needle` from index `0`.
4. Continue comparison while characters match.
5. If all `m` characters match, return `i`.
6. If no complete match is found, return `-1`.

---

## Dry Run

### Input

```text
haystack = "sadbutsad"
needle = "but"
```

Indexes:

```text
s  a  d  b  u  t  s  a  d
0  1  2  3  4  5  6  7  8
```

`needle = "but"`

### Start at index 0

```text
s != b
```

Mismatch → move to next index.

### Start at index 1

```text
a != b
```

Mismatch.

### Start at index 2

```text
d != b
```

Mismatch.

### Start at index 3

```text
b == b  ✓
u == u  ✓
t == t  ✓
```

Complete match found.

Therefore:

```text
Output = 3
```

---

## Why `i <= n - m`?

Suppose:

```text
haystack length = 9
needle length = 3
```

The last possible starting position is:

```text
9 - 3 = 6
```

Therefore, the loop must check:

```text
0 → 6
```

If we go beyond `n - m`, there would not be enough characters remaining in `haystack` to match the complete `needle`.

---

## Complexity Analysis

### Time Complexity

```text
O(n × m)
```

In the worst case, we may compare up to `m` characters at each of the `n - m + 1` possible starting positions.

Where:

- `n` = length of `haystack`
- `m` = length of `needle`

### Space Complexity

```text
O(1)
```

Only a fixed number of variables are used and no extra data structure is required.

---

## Edge Case

### Empty Needle

If:

```text
needle = ""
```

the answer is:

```text
0
```

The current implementation naturally handles this case because `m = 0`.

---

## Key Concepts

- String Traversal
- Brute Force
- String Matching
- Nested Loops
- Character Comparison
- Index Searching
- Early Termination

---

## Interview Note

The current solution uses **Brute Force String Matching**.

It is simple and easy to understand:

```text
For every possible starting position:
    Compare needle with haystack
```

A more advanced solution is **KMP (Knuth-Morris-Pratt)**, which can reduce the worst-case time complexity to:

```text
O(n + m)
```

KMP is useful when efficient pattern matching is required.

---

## Folder Structure

```text
Q9.Find_First_Occurrence/
├── README.md
└── find_first_occurrence.cpp
```

---

## Learning Outcomes

After solving this problem, you will understand:

- How substring matching works.
- How to find the first occurrence of a pattern.
- How to calculate the last possible starting index.
- How nested loops can be used for brute-force pattern matching.
- Why early termination improves practical performance.
- The difference between brute-force matching and KMP.

---

## Status

✅ Solved
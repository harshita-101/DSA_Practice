# Q4. Longest Common Prefix

## Problem Statement

Write a function to find the **longest common prefix** string amongst an array of strings.

If there is no common prefix, return an empty string `""`.

**Difficulty:** Easy

**LeetCode:** 14

---

## Examples

### Example 1

```text
Input:
["flower","flow","flight"]

Output:
"fl"
```

---

### Example 2

```text
Input:
["dog","racecar","car"]

Output:
""
```

---

### Example 3

```text
Input:
["interview","internet","internal","interval"]

Output:
"inter"
```

---

## Approach

Take the **first string** as the reference string.

- Traverse each character of the first string.
- Compare the current character with the character at the same index in all remaining strings.
- If any string is shorter or a mismatch is found, return the prefix obtained so far.
- Otherwise, append the character to the answer.

---

## Algorithm

1. If the array is empty, return an empty string.
2. Initialize an empty string `ans`.
3. Traverse each character of the first string.
4. Compare that character with all remaining strings.
5. If a mismatch occurs or any string ends, return `ans`.
6. Otherwise, append the character to `ans`.
7. Return `ans`.

---

## Dry Run

### Input

```text
["flower","flow","flight"]
```

### Iteration 1

```text
Character = 'f'

flower  ✔
flow    ✔
flight  ✔

Prefix = "f"
```

---

### Iteration 2

```text
Character = 'l'

flower  ✔
flow    ✔
flight  ✔

Prefix = "fl"
```

---

### Iteration 3

```text
Character = 'o'

flower  ✔
flow    ✔
flight  ✘

Mismatch Found
```

Return

```text
"fl"
```

---

## Complexity Analysis

### Time Complexity

```
O(n × m)
```

where

- `n` = Number of strings
- `m` = Length of the shortest common prefix checked

### Space Complexity

```
O(1)
```

(Excluding the output string.)

---

## Key Concepts

- Strings
- Character Comparison
- Nested Loops
- Prefix Matching
- Early Termination

---

## Interview Tips

- Always check if the input vector is empty.
- Use the first string as the reference.
- Stop immediately when a mismatch is found.
- No extra data structures are required.

---

## Folder Structure

```
Q4.Longest_Common_Prefix/
├── README.md
└── longest_common_prefix.cpp
```

---

## Learning Outcomes

After solving this problem, you will understand:

- Character-by-character string comparison.
- Prefix matching techniques.
- Early termination optimization.
- Efficient string traversal.

---

## Status

✅ Solved
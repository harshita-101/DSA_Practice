# Q3. Valid Anagram

## Problem Statement

Given two strings `s` and `t`, return **true** if `t` is an anagram of `s`; otherwise, return **false**.

An **anagram** is a word or phrase formed by rearranging the letters of another word, using all the original characters exactly once.

**Note:** This solution assumes the input contains only lowercase English letters (`a-z`).

**Difficulty:** Easy

**LeetCode:** 242

---

## Examples

### Example 1

```text
Input:
s = "anagram"
t = "nagaram"

Output:
true
```

---

### Example 2

```text
Input:
s = "rat"
t = "car"

Output:
false
```

---

## Approach

Use a **Frequency Array** of size `26`.

- If the lengths of both strings are different, return `false`.
- Count the frequency of each character in the first string.
- Decrease the frequency while traversing the second string.
- If any frequency becomes negative, return `false`.
- If all frequencies are balanced, both strings are anagrams.

---

## Algorithm

1. Compare the lengths of both strings.
2. If lengths are different, return `false`.
3. Create a frequency array of size `26` initialized with `0`.
4. Traverse the first string and increment the frequency.
5. Traverse the second string and decrement the frequency.
6. If any frequency becomes negative, return `false`.
7. Return `true`.

---

## Dry Run

### Input

```text
s = "anagram"
t = "nagaram"
```

### Frequency after first string

```text
a → 3
n → 1
g → 1
r → 1
m → 1
```

### After processing second string

```text
All frequencies become 0
```

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

Since the frequency array size is fixed (`26`).

---

## Key Concepts

- Frequency Array
- Character Counting
- Strings
- Hashing Technique
- Early Termination

---

## Interview Tips

- First compare the lengths of both strings.
- A frequency array is more efficient than sorting.
- Return `false` immediately if any frequency becomes negative.
- This approach works only for lowercase English letters.

---

## Folder Structure

```
Q3.Valid_Anagram/
├── README.md
└── valid_anagram.cpp
```

---

## Learning Outcomes

After solving this problem, you will understand:

- Frequency Array technique.
- Character counting.
- Optimized string comparison.
- Early exit optimization.

---

## Status

✅ Solved
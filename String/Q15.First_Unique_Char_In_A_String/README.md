# First Unique Character in a String

## Problem Statement

Given a string `s`, find the index of the first non-repeating character.

A character is considered unique if it appears only once in the entire string.

If no unique character exists, return:

```text
-1
```

**Difficulty:** Easy  
**LeetCode:** 387

---

## Example

```text
Input:
s = "leetcode"

Output:
0
```

### Explanation

The character frequencies are:

```text
l → 1
e → 3
t → 1
c → 1
o → 1
d → 1
```

The first character with frequency `1` is:

```text
'l'
```

Its index is:

```text
0
```

---

## Another Example

```text
Input:
s = "aabb"

Output:
-1
```

### Explanation

Every character appears more than once:

```text
a → 2
b → 2
```

Therefore, there is no unique character.

---

## Approach

Use a **Hash Map** to store the frequency of every character.

The solution uses two traversals.

### Step 1: Count Character Frequencies

Traverse the complete string and store the frequency of each character.

```cpp
freq[val]++;
```

For example:

```text
s = "loveleetcode"
```

The frequency map stores the number of occurrences of each character.

---

### Step 2: Find the First Unique Character

Traverse the string again from left to right.

For every character, check:

```cpp
freq[s[i]] == 1
```

The first character whose frequency is `1` is the first unique character.

Return its index immediately.

If no such character exists, return:

```text
-1
```

---

## Algorithm

1. Create an `unordered_map` to store character frequencies.
2. Traverse the string and count the frequency of every character.
3. Traverse the string again from left to right.
4. Check whether the frequency of the current character is `1`.
5. If yes, return its index.
6. If no unique character is found, return `-1`.

---

## Dry Run

Consider:

```text
s = "loveleetcode"
```

### Step 1: Count Frequencies

```text
l → 2
o → 2
v → 1
e → 4
t → 1
c → 1
d → 1
```

### Step 2: Traverse the String

```text
Index 0 → l → Frequency = 2
Index 1 → o → Frequency = 2
Index 2 → v → Frequency = 1
```

The first unique character is:

```text
v
```

Its index is:

```text
2
```

### Output

```text
2
```

---

## Complexity

Let `n` be the length of the string.

| Time Complexity | Space Complexity |
|-----------------|------------------|
| O(n)            | O(n)             |

---

## Key Concepts

- String Traversal
- Hashing
- Frequency Counting
- `unordered_map`
- Character Frequency
- Two Pass Approach

---

## Status

✅ Solved
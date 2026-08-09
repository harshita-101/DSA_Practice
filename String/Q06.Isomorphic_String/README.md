# Q6. Isomorphic Strings

## Problem Statement

Given two strings `s` and `t`, determine whether they are **isomorphic**.

Two strings are isomorphic if the characters in `s` can be replaced to get `t`, while maintaining the same character pattern.

Each character must map to exactly one character, and two different characters cannot map to the same character.

**Difficulty:** Easy

**LeetCode:** 205

---

## Examples

### Example 1

```text
Input:
s = "egg"
t = "add"

Output:
true
```

Explanation:

```text
e → a
g → d
```

The mapping is consistent, so the strings are isomorphic.

---

### Example 2

```text
Input:
s = "foo"
t = "bar"

Output:
false
```

Explanation:

```text
f → b
o → a

o → r   ❌
```

The character `o` is mapped to two different characters.

---

### Example 3

```text
Input:
s = "paper"
t = "title"

Output:
true
```

Mapping:

```text
p → t
a → i
p → t
e → l
r → e
```

The mapping remains consistent.

---

## Approach

Use **Two-Way Character Mapping**.

We maintain two arrays:

```cpp
sToT
tToS
```

### `sToT`

Stores the mapping:

```text
character from s → character from t
```

### `tToS`

Stores the reverse mapping:

```text
character from t → character from s
```

Two-way mapping is necessary because the mapping must be **one-to-one**.

---

## Why Two Mappings Are Required?

Consider:

```text
s = "ab"
t = "cc"
```

If we only check `s → t`:

```text
a → c
b → c
```

It might appear valid.

But this is not allowed because two different characters cannot map to the same character.

The reverse mapping detects this:

```text
c → a
c → b   ❌
```

Therefore, the strings are not isomorphic.

---

## Algorithm

1. If the lengths of `s` and `t` are different, return `false`.
2. Create two arrays of size `128`, initialized with `-1`.
3. Traverse both strings simultaneously.
4. Get the ASCII values of the current characters.
5. Check whether the existing `s → t` mapping conflicts.
6. Check whether the existing `t → s` mapping conflicts.
7. Store both mappings.
8. If no conflict is found, return `true`.

---

## Dry Run

### Input

```text
s = "egg"
t = "add"
```

### Iteration 1

```text
s[i] = e
t[i] = a

e → a
a → e
```

Mapping stored.

---

### Iteration 2

```text
s[i] = g
t[i] = d

g → d
d → g
```

Mapping stored.

---

### Iteration 3

```text
s[i] = g
t[i] = d
```

Existing mappings:

```text
g → d
d → g
```

Both are consistent.

Return:

```text
true
```

---

## Complexity Analysis

### Time Complexity

```text
O(n)
```

where `n` is the length of the strings.

### Space Complexity

```text
O(1)
```

The mapping arrays have a fixed size of `128`.

---

## Key Concepts

- Hashing
- Character Mapping
- Two-Way Mapping
- ASCII
- String Traversal
- One-to-One Mapping

---

## Interview Tips

- Checking only `s → t` is not enough.
- Always ensure the mapping is one-to-one.
- Use two mappings or two frequency/index arrays.
- Check string lengths before processing.
- A fixed-size array provides `O(1)` lookup.

---

## Folder Structure

```text
Q6.Isomorphic_Strings/
├── README.md
└── isomorphic_strings.cpp
```

---

## Learning Outcomes

After solving this problem, you will understand:

- How character mapping works.
- Why one-way mapping can fail.
- How to maintain a reverse mapping.
- How fixed-size arrays can be used for constant-time lookup.
- How to solve string pattern-matching problems efficiently.

---

## Status

✅ Solved
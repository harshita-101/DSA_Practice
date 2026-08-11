# Q8. String Compression

## Problem Statement

Given an array of characters `chars`, compress it using the following rules:

- For each group of consecutive repeating characters, count its occurrences.
- If the group's length is `1`, store only the character.
- If the group's length is greater than `1`, store the character followed by its count.
- The compressed result must be stored **in-place** in the input array.
- Return the new length of the compressed array.
- Only constant extra space should be used.

**Difficulty:** Medium

**LeetCode:** 443

---

## Examples

### Example 1

```text
Input:
chars = ["a","a","b","b","c","c","c"]

Output:
6

Compressed array:
["a","2","b","2","c","3"]
```

Explanation:

```text
"aa"  → "a2"
"bb"  → "b2"
"ccc" → "c3"
```

Final compressed string:

```text
"a2b2c3"
```

---

### Example 2

```text
Input:
chars = ["a"]

Output:
1

Compressed array:
["a"]
```

Since the character occurs only once, its count is not written.

---

### Example 3

```text
Input:
chars = ["a","b","b","b","b","b","b","b","b","b","b","b","b"]

Output:
4

Compressed array:
["a","b","1","2"]
```

The character `b` occurs `12` times, so its count is stored as separate characters:

```text
"12"
```

---

## Approach

Use the **Two Pointer Technique**.

Two pointers are maintained:

- `read` → Finds and processes groups of consecutive characters.
- `write` → Stores the compressed result in the same input array.

The algorithm processes one group at a time.

### Example

```text
a a a b b c c c
```

Groups:

```text
aaa → a3
bb  → b2
ccc → c3
```

Compressed result:

```text
a3b2c3
```

---

## Algorithm

1. Initialize `read = 0` and `write = 0`.
2. While `read` is within the array:
   - Store the current character.
   - Count how many consecutive times it appears.
   - Move `read` to the beginning of the next group.
3. Write the current character at the `write` position.
4. If the count is greater than `1`:
   - If the count is a single digit, write it as a character.
   - If the count has multiple digits, write each digit separately.
5. Continue until all groups are processed.
6. Return `write`, which represents the new compressed length.

---

## Dry Run

### Input

```text
["a","a","b","b","c","c","c"]
```

Initial:

```text
read = 0
write = 0
```

### Group 1

```text
a a
```

Count:

```text
count = 2
```

Write:

```text
a 2
```

Now:

```text
write = 2
read = 2
```

---

### Group 2

```text
b b
```

Count:

```text
count = 2
```

Write:

```text
b 2
```

Now:

```text
write = 4
read = 4
```

---

### Group 3

```text
c c c
```

Count:

```text
count = 3
```

Write:

```text
c 3
```

Final compressed array:

```text
["a","2","b","2","c","3"]
```

Return:

```text
6
```

---

## Handling Counts Greater Than 9

If a character appears `12` times:

```text
count = 12
```

It cannot be stored as one character.

Instead:

```text
12
```

is stored as:

```text
'1'
'2'
```

So:

```text
bbbbbbbbbbbb
```

becomes:

```text
b12
```

---

## Why Two Pointers?

The two-pointer technique allows us to:

- Read the original groups using `read`.
- Write the compressed result using `write`.
- Modify the input array directly.
- Avoid creating another array for the result.

This makes the solution **in-place**.

---

## Complexity Analysis

### Time Complexity

```text
O(n)
```

Every character is processed a constant number of times.

The `read` pointer only moves forward and never goes backward.

### Space Complexity

```text
O(1)
```

Only a fixed number of variables are used.

The compression is performed directly inside the input array.

---

## Key Concepts

- Two Pointers
- In-Place Array Modification
- String Compression
- Run-Length Encoding
- Character Counting
- Consecutive Groups
- Digit Conversion

---

## Interview Tips

- Use separate `read` and `write` pointers.
- `read` identifies groups; `write` stores the compressed result.
- Do not create another vector for the compressed array.
- Remember that counts greater than `9` must be stored as multiple characters.
- Return `write`, not the original array size.
- The array elements after the returned length can be ignored.

---

## Folder Structure

```text
Q8.String_Compression/
├── README.md
└── string_compression.cpp
```

---

## Learning Outcomes

After solving this problem, you will understand:

- How to perform in-place modification.
- How the Two Pointer technique works.
- How to count consecutive characters.
- How to convert numeric counts into characters.
- How Run-Length Encoding works.
- How to achieve `O(n)` time and `O(1)` auxiliary space.

---

## Status

✅ Solved
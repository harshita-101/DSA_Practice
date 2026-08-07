# Q5. Reverse Words in a String

## Problem Statement

Given an input string `s`, reverse the order of the words.

A word is defined as a sequence of non-space characters.

The returned string should:

- Contain the words in reverse order.
- Have only one space between words.
- Have no leading or trailing spaces.

**Difficulty:** Medium

**LeetCode:** 151

---

## Examples

### Example 1

```text
Input:
"the sky is blue"

Output:
"blue is sky the"
```

---

### Example 2

```text
Input:
"  hello world  "

Output:
"world hello"
```

---

### Example 3

```text
Input:
"a good   example"

Output:
"example good a"
```

---

## Approach

1. Reverse the entire string.
2. Traverse the reversed string and extract each word.
3. Reverse every extracted word individually.
4. Append the word to the answer string.
5. Ignore multiple spaces.
6. Remove the leading space before returning the final answer.

---

## Algorithm

1. Reverse the complete string.
2. Traverse each character.
3. Build a word until a space is found.
4. Reverse the extracted word.
5. Add the word to the answer.
6. Skip extra spaces.
7. Remove the first extra space and return the result.

---

## Dry Run

### Input

```text
"the sky is blue"
```

### Step 1

Reverse the complete string.

```text
"eulb si yks eht"
```

---

### Step 2

Extract words.

```text
eulb
si
yks
eht
```

---

### Step 3

Reverse every word.

```text
blue
is
sky
the
```

---

### Step 4

Build the answer.

```text
" blue is sky the"
```

Remove the leading space.

Final Output

```text
"blue is sky the"
```

---

## Complexity Analysis

### Time Complexity

```
O(n)
```

### Space Complexity

```
O(n)
```

---

## Key Concepts

- String Manipulation
- Reversing Strings
- String Traversal
- Handling Multiple Spaces
- In-place Reversal

---

## Interview Tips

- Reverse the entire string first.
- Reverse each individual word.
- Ignore consecutive spaces.
- Remove leading and trailing spaces from the final answer.

---

## Folder Structure

```
Q5.Reverse_Words_in_a_String/
├── README.md
└── reverse_words_in_a_string.cpp
```

---

## Learning Outcomes

After solving this problem, you will understand:

- String reversal techniques.
- Word extraction.
- Efficient string traversal.
- Handling extra spaces.
- Building strings efficiently.

---

## Status

✅ Solved
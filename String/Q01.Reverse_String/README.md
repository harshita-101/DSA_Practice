# Q1. Reverse String

## Problem Statement

Write a function that reverses a given character array **in-place**.

You must modify the input array directly without using any extra array.

**Difficulty:** Easy

**LeetCode:** 344

---

## Example

### Example 1

```text
Input:
['h','e','l','l','o']

Output:
['o','l','l','e','h']
```

### Example 2

```text
Input:
['H','a','n','n','a','h']

Output:
['h','a','n','n','a','H']
```

---

## Approach

Use the **Two Pointer** technique.

- Initialize one pointer at the beginning.
- Initialize another pointer at the end.
- Swap both characters.
- Move the left pointer forward.
- Move the right pointer backward.
- Continue until both pointers meet.

---

## Algorithm

1. Initialize `left = 0`.
2. Initialize `right = n - 1`.
3. While `left < right`:
   - Swap `s[left]` and `s[right]`.
   - Increment `left`.
   - Decrement `right`.
4. The character array is reversed.

---

## Dry Run

Input

```text
h e l l o
```

Initial

```text
left = 0
right = 4
```

Iteration 1

```text
Swap h and o

o e l l h
```

Iteration 2

```text
Swap e and l

o l l e h
```

Pointers meet.

Final Output

```text
o l l e h
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

---

## Key Concepts

- Two Pointers
- In-place Reversal
- Character Array
- Swapping

---

## Interview Tips

- Do not use an extra array.
- The solution should modify the original array.
- Always use two pointers for the optimal solution.

---

## Folder Structure

```
Q1.Reverse_String/
├── README.md
└── reverse_string.cpp
```

---

## Learning Outcomes

After solving this problem, you will understand:

- Two Pointer technique.
- In-place array modification.
- Character array traversal.
- Efficient swapping.

---

## Status

✅ Solved
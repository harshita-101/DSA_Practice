# Q13. Longest Repeating Character Replacement

## Problem Statement

You are given a string `s` consisting of uppercase English letters and an integer `k`.

You can replace any character in the string at most `k` times.

Return the length of the longest substring that can be made to contain the same character after at most `k` replacements.

**Difficulty:** Medium

**LeetCode:** 424

---

## Examples

### Example 1

```text
Input:
s = "ABAB"
k = 2

Output:
4
```

Explanation:

Replace the two `B`s with `A`:

```text
"ABAB"
 ↓
"AAAA"
```

Only `2` replacements are required.

Therefore, the answer is:

```text
4
```

---

### Example 2

```text
Input:
s = "AABABBA"
k = 1

Output:
4
```

Explanation:

Consider the substring:

```text
"ABAB"
```

The most frequent character is `A`, which appears `2` times.

The substring length is:

```text
4
```

Required replacements:

```text
4 - 2 = 2
```

Since only one replacement is allowed, this window is not valid.

A valid longest window has length `4`, such as:

```text
"AABA"
```

Only one `B` needs to be replaced with `A`.

Therefore:

```text
Output = 4
```

---

## Approach

Use the **Sliding Window + Frequency Array** technique.

The main idea is to maintain a window where we can make all characters the same using at most `k` replacements.

For every window, keep track of:

- Frequency of every character.
- `maxFreq` → maximum frequency of a single character inside the window.

If:

```text
windowSize - maxFreq <= k
```

then the current window is valid.

Otherwise, shrink the window from the left.

---

## Key Formula

Suppose the current window is:

```text
"AABAB"
```

Frequency:

```text
A = 3
B = 2
```

The most frequent character is:

```text
A → 3
```

Window size:

```text
5
```

Characters that need to be replaced:

```text
5 - 3 = 2
```

Therefore:

```text
changes = windowSize - maxFreq
```

If:

```text
changes <= k
```

the window is valid.

---

## Algorithm

1. Create a frequency array of size `26`.
2. Initialize:
   ```text
   left = 0
   maxFreq = 0
   ans = 0
   ```
3. Traverse the string using the `right` pointer.
4. Increase the frequency of `s[right]`.
5. Update `maxFreq`.
6. Calculate:
   ```text
   windowSize = right - left + 1
   ```
7. Calculate the number of required replacements:
   ```text
   changes = windowSize - maxFreq
   ```
8. If:
   ```text
   changes > k
   ```
   shrink the window:
   ```text
   freq[s[left] - 'A']--
   left++
   ```
9. Update:
   ```text
   ans = max(ans, right - left + 1)
   ```
10. Return `ans`.

---

## Dry Run

### Input

```text
s = "AABABBA"
k = 1
```

Initial:

```text
left = 0
maxFreq = 0
ans = 0
```

---

### Step 1

Window:

```text
"A"
```

Frequency:

```text
A = 1
```

```text
windowSize = 1
maxFreq = 1
changes = 1 - 1 = 0
```

Valid window.

```text
ans = 1
```

---

### Step 2

Window:

```text
"AA"
```

Frequency:

```text
A = 2
```

```text
windowSize = 2
maxFreq = 2
changes = 2 - 2 = 0
```

Valid.

```text
ans = 2
```

---

### Step 3

Window:

```text
"AAB"
```

Frequency:

```text
A = 2
B = 1
```

Maximum frequency:

```text
maxFreq = 2
```

Window size:

```text
3
```

Required changes:

```text
3 - 2 = 1
```

Since:

```text
1 <= k
```

window is valid.

```text
ans = 3
```

---

### Step 4

Window:

```text
"AABA"
```

Frequency:

```text
A = 3
B = 1
```

Window size:

```text
4
```

Required changes:

```text
4 - 3 = 1
```

Valid.

```text
ans = 4
```

---

### Step 5

Window:

```text
"AABAB"
```

Frequency:

```text
A = 3
B = 2
```

Window size:

```text
5
```

Required changes:

```text
5 - 3 = 2
```

But:

```text
k = 1
```

So:

```text
2 > 1
```

Window becomes invalid.

Move `left` forward and remove the leftmost character.

---

### Continue

The window keeps shrinking and expanding as required.

The maximum valid window length remains:

```text
4
```

Therefore:

```text
Output = 4
```

---

## Why Sliding Window?

A brute-force approach would generate many substrings and calculate the number of replacements for each one.

That would take approximately:

```text
O(n²)
```

or more depending on how frequencies are calculated.

Sliding Window maintains the current window and its character frequencies while moving `left` and `right` only forward.

Therefore, the solution runs in linear time.

---

## Why `maxFreq`?

We only need to know the frequency of the most common character in the current window.

Suppose:

```text
window = "AABAB"
```

Frequency:

```text
A = 3
B = 2
```

If we want the entire window to become `A`:

```text
A A B A B
    ↑   ↑
```

Only the two `B`s need replacement.

Therefore:

```text
changes = windowSize - maxFreq
         = 5 - 3
         = 2
```

We don't need to actually perform the replacements.

We only calculate how many replacements would be required.

---

## Important Observation About `maxFreq`

In the implementation, `maxFreq` is not decreased when `left` moves.

For example:

```text
freq[s[left] - 'A']--;
left++;
```

but `maxFreq` remains unchanged.

This is intentional.

The stored `maxFreq` acts as the highest frequency seen while expanding the window. It may become slightly larger than the actual maximum frequency of the current window after shrinking, but this does not affect the correctness of the maximum-length answer.

This allows the algorithm to remain `O(n)` without repeatedly scanning the frequency array.

---

## Complexity Analysis

### Time Complexity

```text
O(n)
```

The `right` pointer moves from left to right once.

The `left` pointer also only moves forward.

The frequency array has only `26` characters.

Therefore:

```text
O(n)
```

---

### Space Complexity

```text
O(1)
```

The frequency array contains only `26` elements:

```text
int freq[26]
```

Since the alphabet size is fixed:

```text
O(26) = O(1)
```

---

## Why This Approach Is Optimal

The string needs to be traversed to determine the longest valid substring.

The Sliding Window processes each character efficiently without generating all possible substrings.

Therefore:

```text
Time  = O(n)
Space = O(1)
```

This is an optimal approach for this problem.

---

## Key Concepts

- Sliding Window
- Two Pointers
- Frequency Array
- Character Frequency
- Maximum Frequency
- Dynamic Window
- Window Expansion
- Window Contraction
- Greedy Observation
- String Manipulation

---

## Interview Tips

- This is a classic **Sliding Window** problem.
- Maintain the frequency of characters inside the current window.
- `maxFreq` represents the highest character frequency.
- Required replacements:
  ```text
  windowSize - maxFreq
  ```
- If:
  ```text
  changes > k
  ```
  shrink the window.
- If:
  ```text
  changes <= k
  ```
  the window is valid.
- Since only uppercase English letters are given, a `26`-size array is sufficient.
- The optimal complexity is:
  ```text
  O(n) time
  O(1) space
  ```

---

## Folder Structure

```text
Q13.Longest_Repeating_Character_Replacement/
├── README.md
└── longest_repeating_character_replacement.cpp
```

---

## Learning Outcomes

After solving this problem, you will understand:

- How Sliding Window works with a frequency array.
- How to maintain character frequencies inside a window.
- How `maxFreq` helps calculate required replacements.
- How to expand and shrink a window dynamically.
- How to solve substring problems in `O(n)` time.
- How to use a fixed-size array for constant extra space.

---

## Status

✅ Solved
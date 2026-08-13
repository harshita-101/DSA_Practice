# Q11. Group Anagrams

## Problem Statement

Given an array of strings `strs`, group all the anagrams together.

Two strings are anagrams if they contain the same characters with the same frequencies, but the order of characters can be different.

**Difficulty:** Medium

**LeetCode:** 49

---

## Examples

### Example 1

```text
Input:
["eat","tea","tan","ate","nat","bat"]

Output:
[
    ["eat","tea","ate"],
    ["tan","nat"],
    ["bat"]
]
```

Explanation:

```text
eat → a, e, t
tea → a, e, t
ate → a, e, t
```

These strings have the same character frequencies, so they belong to the same group.

Similarly:

```text
tan → a, n, t
nat → a, n, t
```

Therefore, they form another group.

---

### Example 2

```text
Input:
[""]

Output:
[[""]]
```

---

### Example 3

```text
Input:
["a"]

Output:
[["a"]]
```

---

## Approach

Use a **Frequency Array + Hash Map** approach.

For every string:

1. Create a frequency array of size `26`.
2. Count the frequency of every character.
3. Convert the frequency array into a unique string key.
4. Use the key in an `unordered_map`.
5. Store all strings having the same key in the same group.
6. Finally, collect all groups from the map into the answer.

---

## Why Frequency Array?

Consider:

```text
"eat"
```

Character frequencies:

```text
a → 1
e → 1
t → 1
```

For:

```text
"tea"
```

the frequencies are exactly the same:

```text
a → 1
e → 1
t → 1
```

Therefore, both strings can use the same key.

---

## Creating the Key

A frequency array cannot be conveniently used directly as an `unordered_map` key.

Therefore, convert the frequency values into a string.

For example:

```text
freq = [1,0,0,0,1,0,...,1,...]
```

can be represented as:

```text
"1#0#0#0#1#0#...#1#"
```

The `#` separator keeps individual frequency values separate.

Strings with the same character frequencies will generate the same key.

---

## Data Structure Used

```text
unordered_map<string, vector<string>>
```

The map stores:

```text
Key   → Frequency pattern
Value → Group of anagrams
```

Example:

```text
frequency key → ["eat", "tea", "ate"]

frequency key → ["tan", "nat"]

frequency key → ["bat"]
```

---

## Algorithm

1. Create an empty `unordered_map`.
2. Traverse every string in `strs`.
3. Create a fresh frequency array of size `26`.
4. Count each character using:
   ```text
   freq[s[i] - 'a']++
   ```
5. Create an empty string `key`.
6. Traverse all `26` frequency values.
7. Add each frequency to `key` with a separator.
8. Add the current string to:
   ```text
   mp[key]
   ```
9. After processing all strings, traverse the map.
10. Add each map value to the final answer.
11. Return the answer.

---

## Dry Run

### Input

```text
["eat","tea","tan","ate","nat","bat"]
```

### String 1: `"eat"`

Frequency:

```text
a = 1
e = 1
t = 1
```

Key:

```text
"1#0#0#0#1#...#1#"
```

Map:

```text
key1 → ["eat"]
```

---

### String 2: `"tea"`

Frequency:

```text
a = 1
e = 1
t = 1
```

Same key:

```text
key1
```

Map:

```text
key1 → ["eat", "tea"]
```

---

### String 3: `"tan"`

Frequency:

```text
a = 1
n = 1
t = 1
```

Different key:

```text
key2
```

Map:

```text
key1 → ["eat", "tea"]
key2 → ["tan"]
```

---

### String 4: `"ate"`

Frequency is the same as `"eat"`.

So:

```text
key1 → ["eat", "tea", "ate"]
```

---

### String 5: `"nat"`

Same frequency as `"tan"`:

```text
key2 → ["tan", "nat"]
```

---

### String 6: `"bat"`

Different frequency pattern:

```text
key3 → ["bat"]
```

Final groups:

```text
[
    ["eat","tea","ate"],
    ["tan","nat"],
    ["bat"]
]
```

---

## Why Hash Map?

The hash map allows us to quickly find the group corresponding to a frequency pattern.

Instead of comparing every pair of strings, we directly use the frequency pattern as a key.

This avoids unnecessary comparisons.

---

## Complexity Analysis

Let:

- `N` = number of strings.
- `K` = maximum length of a string.

### Time Complexity

```text
O(N × K)
```

For every string:

- Counting characters → `O(K)`
- Creating the frequency key → `O(26)` = `O(1)`
- Hash map insertion → `O(1)` average

Therefore:

```text
O(N × K)
```

on average.

---

### Space Complexity

```text
O(N × K)
```

The map stores all the input strings grouped by their frequency keys.

The final answer also contains all strings.

The frequency array itself uses:

```text
O(26) = O(1)
```

extra space per string.

---

## Comparison with Sorting Approach

### Sorting Approach

Each string is sorted before using it as a key.

```text
eat → aet
tea → aet
ate → aet
```

Time complexity:

```text
O(N × K log K)
```

### Frequency Approach

Character frequencies are counted directly.

Time complexity:

```text
O(N × K)
```

Therefore, the frequency-based approach is more efficient.

---

## Why This Approach Is Optimal

The frequency-based approach avoids sorting every string.

For lowercase English letters, only `26` frequency values need to be maintained.

Therefore, the overall average time complexity is:

```text
O(N × K)
```

This is the optimal asymptotic approach for this problem under the given character constraint.

---

## Key Concepts

- Hashing
- `unordered_map`
- Frequency Array
- Character Counting
- Anagram Detection
- Grouping
- String Encoding
- Hash Map Keys
- Vector of Vectors

---

## Interview Tips

- Anagrams have identical character frequencies.
- Use a frequency array when the character set is fixed.
- Convert the frequency pattern into a unique key.
- Use `unordered_map` to group strings with the same key.
- Do not compare every pair of strings.
- Sorting works, but frequency counting is more efficient for lowercase English letters.
- Remember that the order of groups returned by `unordered_map` is not guaranteed.

---

## Folder Structure

```text
Q11.Group_Anagrams/
├── README.md
└── group_anagrams.cpp
```

---

## Learning Outcomes

After solving this problem, you will understand:

- How to identify anagrams using frequency counts.
- How to create a unique key from character frequencies.
- How `unordered_map` can be used for grouping.
- How hashing reduces unnecessary comparisons.
- How to improve a sorting-based solution to a frequency-based solution.
- How to achieve `O(N × K)` average time complexity.

---

## Status

✅ Solved
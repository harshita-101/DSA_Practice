# Strings

This folder contains important **String Data Structure and Algorithm problems** solved in C++.

The problems are selected from commonly asked coding interview questions and are focused on building strong fundamentals in string manipulation, hashing, two pointers, sliding window, and pattern-based techniques.

---

## Problems Solved

| No. | Problem | Difficulty | Technique | Status |
| --- | --- | --- | --- | --- |
| Q1 | [Reverse String](./Q1.Reverse_String/) | Easy | Two Pointers | ✅ |
| Q2 | [Valid Palindrome](./Q2.Valid_Palindrome/) | Easy | Two Pointers | ✅ |
| Q3 | [Valid Anagram](./Q3.Valid_Anagram/) | Easy | Frequency Array | ✅ |
| Q4 | [Longest Common Prefix](./Q4.Longest_Common_Prefix/) | Easy | String Traversal | ✅ |
| Q5 | [Reverse Words in a String](./Q5.Reverse_Words_in_a_String/) | Medium | String Manipulation | ✅ |
| Q6 | [Isomorphic Strings](./Q6.Isomorphic_Strings/) | Easy | Two-Way Mapping | ✅ |
| Q7 | [Rotate String](./Q7.Rotate_String/) | Easy | String Concatenation + Search | ✅ |
| Q8 | [String Compression](./Q8.String_Compression/) | Medium | Two Pointers | ✅ |
| Q9 | [Find the Index of the First Occurrence in a String](./Q9.Find_First_Occurrence/) | Easy | Brute Force String Matching | ✅ |
| Q10 | [Longest Substring Without Repeating Characters](./Q10.Longest_Substring_Without_Repeating_Characters/) | Medium | Sliding Window + Hashing | ✅ |

---

## Topics Covered

### 1. String Traversal

- Character-by-character traversal
- Accessing characters using indexes
- Comparing characters
- Traversing strings using loops

### 2. Two Pointer Technique

- Reverse String
- Valid Palindrome
- String Compression
- Managing left and right pointers
- In-place modification

### 3. Frequency Array

- Character frequency counting
- Valid Anagram
- Fixed-size frequency arrays

### 4. Hashing and Mapping

- Character mapping
- Two-way mapping
- Isomorphic Strings
- Duplicate character detection
- `unordered_set`

### 5. Prefix Matching

- Longest Common Prefix
- Character comparison at the same index
- Prefix validation

### 6. String Manipulation

- Reversing strings
- Reversing words
- Removing extra spaces
- String concatenation
- In-place string compression
- Character conversion

### 7. Substring Search

- `find()`
- `string::npos`
- Rotation checking
- Searching for a pattern inside a string

### 8. In-Place Modification

- Modifying the input array directly
- Read and Write pointers
- Run-Length Encoding
- Consecutive character counting
- Handling multi-digit character counts

### 9. String Matching

- Brute Force String Matching
- Pattern Matching
- Comparing a pattern with a substring
- Finding the first occurrence of a pattern
- Early termination on character mismatch

### 10. Sliding Window

- Maintaining a dynamic window
- Two-pointer window expansion
- Window contraction
- Finding longest valid substrings
- Detecting duplicate characters
- Maintaining unique characters using a set

---

## Complexity Summary

| Problem | Time Complexity | Space Complexity |
| --- | --- | --- |
| Reverse String | O(n) | O(1) |
| Valid Palindrome | O(n) | O(1) |
| Valid Anagram | O(n) | O(1) |
| Longest Common Prefix | O(n × m) | O(1) |
| Reverse Words in a String | O(n) | O(n) |
| Isomorphic Strings | O(n) | O(1) |
| Rotate String | O(n²) | O(n) |
| String Compression | O(n) | O(1) |
| Find First Occurrence in a String | O(n × m) | O(1) |
| Longest Substring Without Repeating Characters | O(n) | O(min(n, charset)) |

> **Note:** For Longest Common Prefix, `n` represents the number of strings and `m` represents the length of the prefix being compared.

> **Note:** For Q10, the `unordered_set` stores characters currently present in the sliding window.

---

## Key Concepts

- String Traversal
- Character Arrays
- Two Pointers
- Sliding Window
- Frequency Counting
- Hashing

- `unordered_set`
- Character Mapping
- Prefix Matching
- String Reversal
- Word Extraction
- Substring Search
- String Concatenation
- Case Conversion
- Alphanumeric Character Checking
- In-Place Modification
- Run-Length Encoding
- Consecutive Character Counting
- Duplicate Detection
- Pattern Matching

---

## Folder Structure

```text
Strings/
│
├── README.md
│
├── Q1.Reverse_String/
│   ├── README.md
│   └── reverse_string.cpp
│
├── Q2.Valid_Palindrome/
│   ├── README.md
│   └── valid_palindrome.cpp
│
├── Q3.Valid_Anagram/
│   ├── README.md
│   └── valid_anagram.cpp
│
├── Q4.Longest_Common_Prefix/
│   ├── README.md
│   └── longest_common_prefix.cpp
│
├── Q5.Reverse_Words_in_a_String/
│   ├── README.md
│   └── reverse_words_in_a_string.cpp
│
├── Q6.Isomorphic_Strings/
│   ├── README.md
│   └── isomorphic_strings.cpp
│
├── Q7.Rotate_String/
│   ├── README.md
│   └── rotate_string.cpp
│
├── Q8.String_Compression/
│   ├── README.md
│   └── string_compression.cpp
│
├── Q9.Find_First_Occurrence/
│   ├── README.md
│   └── find_first_occurrence.cpp
│
└── Q10.Longest_Substring_Without_Repeating_Characters/
    ├── README.md
    └── longest_substring_without_repeating_characters.cpp
```

---

## Learning Goals

The main goals of this folder are:

- Build strong fundamentals in Strings.
- Learn commonly used string techniques.
- Understand when to use Two Pointers.
- Learn frequency-based approaches.
- Practice hashing and character mapping.
- Learn Sliding Window techniques.
- Learn in-place array modification.
- Understand consecutive character grouping.
- Improve problem-solving and optimization skills.
- Prepare for coding interviews and placement tests.

---

## Interview Preparation

The problems in this folder cover several frequently used interview patterns:

```text
String
 │
 ├── Two Pointers
 │     ├── Reverse String
 │     ├── Valid Palindrome
 │     └── String Compression
 │
 ├── Frequency Array
 │     └── Valid Anagram
 │
 ├── Prefix Matching
 │     └── Longest Common Prefix
 │
 ├── String Manipulation
 │     └── Reverse Words
 │
 ├── Character Mapping
 │     └── Isomorphic Strings
 │
 ├── Substring Search
 │     └── Rotate String
 │
 ├── String Matching
 │     └── Find First Occurrence in a String
 │
 └── Sliding Window
       └── Longest Substring Without Repeating Characters
```

---

## Upcoming Problems

- Q11. Group Anagrams
- Q12. Longest Palindromic Substring
- Q13. Longest Repeating Character Replacement
- Q14. Minimum Window Substring
- Q15. String Compression II

---

## Skills Practiced

```text
C++
├── Strings
├── Arrays
├── Vectors
├── Hashing
├── Two Pointers
├── Sliding Window
├── Frequency Counting
├── Character Mapping
├── Substring Searching
├── In-Place Modification
└── Run-Length Encoding
```

---


## Status

🚀 **In Progress**

More String problems will be added as the topic progresses.
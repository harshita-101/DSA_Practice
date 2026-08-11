# Strings

This folder contains important **String Data Structure and Algorithm problems** solved in C++.

The problems are selected from commonly asked coding interview questions and are focused on building strong fundamentals in string manipulation, hashing, two pointers, and pattern-based techniques.

---

## Problems Solved

| No. | Problem                                                      | Difficulty | Technique                     | Status |
| --- | ------------------------------------------------------------ | ---------- | ----------------------------- | ------ |
| Q1  | [Reverse String](./Q1.Reverse_String/)                       | Easy       | Two Pointers                  | ✅      |
| Q2  | [Valid Palindrome](./Q2.Valid_Palindrome/)                   | Easy       | Two Pointers                  | ✅      |
| Q3  | [Valid Anagram](./Q3.Valid_Anagram/)                         | Easy       | Frequency Array               | ✅      |
| Q4  | [Longest Common Prefix](./Q4.Longest_Common_Prefix/)         | Easy       | String Traversal              | ✅      |
| Q5  | [Reverse Words in a String](./Q5.Reverse_Words_in_a_String/) | Medium     | String Manipulation           | ✅      |
| Q6  | [Isomorphic Strings](./Q6.Isomorphic_Strings/)               | Easy       | Two-Way Mapping               | ✅      |
| Q7  | [Rotate String](./Q7.Rotate_String/)                         | Easy       | String Concatenation + Search | ✅      |
| Q8  | [String Compression](./Q8.String_Compression/)               | Medium     | Two Pointers                  | ✅      |

---

## Topics Covered

### 1. String Traversal

- Character-by-character traversal
- Accessing characters using indexes
- Comparing characters

### 2. Two Pointer Technique

- Reverse String
- Valid Palindrome
- String Compression

### 3. Frequency Array

- Character frequency counting
- Valid Anagram

### 4. Hashing and Mapping

- Character mapping
- Two-way mapping
- Isomorphic Strings

### 5. Prefix Matching

- Longest Common Prefix

### 6. String Manipulation

- Reversing strings
- Reversing words
- Removing extra spaces
- String concatenation
- In-place string compression

### 7. Substring Search

- `find()`
- `string::npos`
- Rotation checking

### 8. In-Place Modification

- Modifying the input array directly
- Read and Write pointers
- Run-Length Encoding
- Handling multi-digit character counts

---

## Complexity Summary

| Problem                   | Time Complexity | Space Complexity |
| ------------------------- | --------------- | ---------------- |
| Reverse String            | O(n)            | O(1)             |
| Valid Palindrome          | O(n)            | O(1)             |
| Valid Anagram             | O(n)            | O(1)             |
| Longest Common Prefix     | O(n × m)        | O(1)             |
| Reverse Words in a String | O(n)            | O(n)             |
| Isomorphic Strings        | O(n)            | O(1)             |
| Rotate String             | O(n²)           | O(n)             |
| String Compression        | O(n)            | O(1)             |

> **Note:** For Longest Common Prefix, `n` represents the number of strings and `m` represents the length of the prefix being compared.

> **Note:** String Compression uses an in-place Two Pointer approach with constant auxiliary space.

---

## Key Concepts

- String Traversal
- Character Arrays
- Two Pointers
- Frequency Counting
- Hashing
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
└── Q8.String_Compression/
    ├── README.md
    └── string_compression.cpp
```

---

## Learning Goals

The main goals of this folder are:

- Build strong fundamentals in Strings.
- Learn commonly used string techniques.
- Understand when to use Two Pointers.
- Learn frequency-based approaches.
- Practice hashing and character mapping.
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
 └── In-Place Modification
       └── String Compression
```

---

## Upcoming Problems

- Q9. Find the Index of the First Occurrence in a String
- Q10. Longest Substring Without Repeating Characters
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
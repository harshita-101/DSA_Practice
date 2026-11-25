# Q17. Maximum Number of Vowels in a Substring of Given Length

**LeetCode:** [1456. Maximum Number of Vowels in a Substring of Given Length](https://leetcode.com/problems/maximum-number-of-vowels-in-a-substring-of-given-length/)  
**Difficulty:** Medium  
**Topics:** String, Sliding Window, Two Pointers

## Problem Statement

Given a string `s` and an integer `k`, find the maximum number of vowels in any continuous substring of length `k`.

Vowels are: `a, e, i, o, u`.

**Example:**

```text
Input:
s = "abciiidef"
k = 3

Output:
3
```

**Explanation:**

The substring `"iii"` has 3 vowels, which is the maximum possible.

## Approach: Fixed Size Sliding Window

We use the Sliding Window technique to avoid checking every substring from scratch.

Instead of counting vowels repeatedly, we maintain the vowel count of the current window.

Two variables are used:

- `count`: Stores the number of vowels in the current window.
- `maxcount`: Stores the maximum number of vowels found so far.

### How Sliding Window Works

1. First, count the vowels in the initial window of size `k`.
2. Store this count in `maxcount`.
3. Move the window one position at a time.
4. Remove the outgoing character from the count if it is a vowel.
5. Add the incoming character to the count if it is a vowel.
6. Update `maxcount` after every window movement.
7. Return `maxcount`.

## Algorithm / Steps

1. Initialize `count = 0` and `maxcount = 0`.
2. Traverse the first `k` characters.
3. Check whether each character is a vowel.
4. Increment `count` if it is a vowel.
5. Set `maxcount = count`.
6. Start the second loop from index `k`.
7. Check the outgoing character at index `i-k`.
8. Decrease `count` if the outgoing character is a vowel.
9. Check the incoming character at index `i`.
10. Increase `count` if the incoming character is a vowel.
11. Update `maxcount = max(maxcount, count)`.
12. Return `maxcount`.

## Dry Run

**Input:**

```text
s = "abciiidef"
k = 3
```

| Window | Outgoing | Incoming | Vowel Count | Maximum |
|---|---|---|---:|---:|
| abc | - | - | 1 | 1 |
| bci | a | i | 1 | 1 |
| cii | b | i | 2 | 2 |
| iii | c | i | 3 | 3 |
| iid | i | d | 2 | 3 |
| ide | i | e | 2 | 3 |
| def | d | f | 1 | 3 |

**Final Output:**

```text
3
```

## C++ Implementation

```cpp
#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

int maxVowels(string s, int k) {
    int count = 0;
    int maxcount = 0;

    // First window
    for (int i = 0; i < k; i++) {
        if (s[i] == 'a' || s[i] == 'e' ||
            s[i] == 'i' || s[i] == 'o' ||
            s[i] == 'u') {
            count++;
        }
    }

    maxcount = count;

    // Sliding Window
    for (int i = k; i < s.length(); i++) {

        // Remove outgoing character
        if (s[i-k] == 'a' || s[i-k] == 'e' ||
            s[i-k] == 'i' || s[i-k] == 'o' ||
            s[i-k] == 'u') {
            count--;
        }

        // Add incoming character
        if (s[i] == 'a' || s[i] == 'e' ||
            s[i] == 'i' || s[i] == 'o' ||
            s[i] == 'u') {
            count++;
        }

        maxcount = max(maxcount, count);
    }

    return maxcount;
}
```

## Time and Space Complexity

| Complexity | Value | Explanation |
|---|---|---|
| Time Complexity | O(n) | Each character is processed at most once |
| Space Complexity | O(1) | Only constant extra variables are used |

## Key Concepts Learned

- Fixed Size Sliding Window
- Two Pointers
- String Traversal
- Character Checking
- Maintaining Window Count
- Optimizing Brute Force Approach


**Status:** Completed ✅
# Q26. Remove K Digits

**LeetCode Problem:** [402. Remove K Digits](https://leetcode.com/problems/remove-k-digits/)  
**Difficulty:** Medium  
**Topics:** Stack, Greedy, Monotonic Stack, String

---

## 📌 Problem Statement

Given a string `num` representing a non-negative integer and an integer `k`, remove exactly `k` digits from the number so that the resulting number is the smallest possible.

Return the smallest possible number as a string.

**Rules:**
- Remove exactly `k` digits.
- The relative order of the remaining digits must stay the same.
- Remove leading zeros from the resulting number.
- If all digits are removed or the result is empty, return `"0"`.

### Example 1

**Input:**
```text
num = "1432219", k = 3
```

**Output:**
```text
"1219"
```

**Explanation:**

Remove the digits `4`, `3`, and one `2` to obtain the smallest possible number, `"1219"`.

### Example 2

**Input:**
```text
num = "10200", k = 1
```

**Output:**
```text
"200"
```

**Explanation:**

Remove the digit `1`, resulting in `"0200"`. After removing the leading zero, the answer becomes `"200"`.

### Example 3

**Input:**
```text
num = "10", k = 2
```

**Output:**
```text
"0"
```

**Explanation:**

Both digits are removed, leaving an empty string. Therefore, return `"0"`.

---

## 💡 Approach: Greedy + Monotonic Stack

We use a **monotonic increasing stack** to obtain the smallest possible number after removing `k` digits.

The main idea is to remove a larger digit when a smaller digit appears after it. This helps create a smaller number because digits on the left have a greater impact on the number's value.

### What Do We Store in the Stack?

```cpp
stack<char> s;
```

We store digits as characters.

For example, if `num = "1432"`, the stack processes the digits one by one.

When the current digit is smaller than the stack's top digit, we remove the larger digit if we still have removals available.

### Algorithm

1. Create an empty stack and an empty string `ans`.
2. Traverse the input string from left to right.
3. While the stack is not empty, the top digit is greater than the current digit, and `k > 0`:
   - Pop the top digit.
   - Decrease `k` by one.
4. Push the current digit onto the stack.
5. After processing all digits, if `k > 0`, remove the remaining digits from the top of the stack.
6. Pop all remaining digits into `ans`.
7. Reverse `ans` because stack elements are retrieved in reverse order.
8. Remove leading zeros.
9. If no non-zero digit remains, return `"0"`. Otherwise, return the remaining substring.

### Why Do We Remove Larger Digits?

Consider:

```text
num = "1432", k = 1
```

If we remove `4`, the result becomes `"132"`.

If we remove `1`, the result becomes `"432"`.

Since `"132"` is smaller than `"432"`, removing the larger digit before a smaller digit helps minimize the number.

### Why Do We Remove Remaining Digits from the Top?

Consider:

```text
num = "12345", k = 2
```

No digit is removed during the main traversal because the digits are already increasing.

After processing all digits, `k = 2` remains.

We remove `5` and then `4` from the top, obtaining:

```text
"123"
```

Therefore, any remaining removals are performed from the top of the stack.

---

## 💻 C++ Solution

```cpp
#include <iostream>
#include <stack>
#include <string>
#include <algorithm>
using namespace std;

string removeKdigits(string num, int k)
{
    stack<char> s;
    string ans = "";

    // Process each digit
    for (int i = 0; i < num.length(); i++)
    {
        // Remove larger digits when a smaller digit appears
        while (!s.empty() && s.top() > num[i] && k > 0)
        {
            s.pop();
            k--;
        }

        // Push the current digit
        s.push(num[i]);
    }

    // Remove remaining digits from the top if needed
    while (k > 0 && !s.empty())
    {
        s.pop();
        k--;
    }

    // Build the answer from the stack
    while (!s.empty())
    {
        ans += s.top();
        s.pop();
    }

    // Reverse because stack elements are retrieved backward
    reverse(ans.begin(), ans.end());

    // Remove leading zeros
    int pos = ans.find_first_not_of('0');

    // If no non-zero digit exists, return "0"
    if (pos == string::npos)
        return "0";

    return ans.substr(pos);
}
```

**Note:** The `main()` function is included for local practice. For LeetCode submission, use the `Solution` class with the required `removeKdigits()` method and do not include `main()`.

---

## 🔍 Dry Run

**Input:**

```text
num = "1432219", k = 3
```

Initially, the stack is empty.

| Current Digit | Operation | Stack (bottom → top) | Remaining `k` |
|---:|---|---|---:|
| 1 | Push `1` | `1` | 3 |
| 4 | Push `4` | `1, 4` | 3 |
| 3 | Pop `4`, push `3` | `1, 3` | 2 |
| 2 | Pop `3`, push `2` | `1, 2` | 1 |
| 2 | Push `2` | `1, 2, 2` | 1 |
| 1 | Pop `2`, push `1` | `1, 2, 1` | 0 |
| 9 | Push `9` | `1, 2, 1, 9` | 0 |

After the traversal, the stack contains the digits `1, 2, 1, 9`.

The digits are popped into a string in reverse order:

```text
"9121"
```

After reversing:

```text
"1219"
```

There are no leading zeros to remove.

**Output:**

```text
"1219"
```

### Understanding the Removal of Remaining Digits

Consider another example:

```text
num = "12345", k = 2
```

All digits are pushed because each digit is greater than the previous digit.

After the main loop:

```text
Stack (bottom → top): 1, 2, 3, 4, 5
Remaining k = 2
```

Now remove digits from the top:

- Pop `5` → `k = 1`
- Pop `4` → `k = 0`

The remaining stack contains `1, 2, 3`.

**Final Output:**

```text
"123"
```

### Understanding Leading Zeros

Consider:

```text
num = "10200", k = 1
```

After removing `1`, the remaining digits form:

```text
"0200"
```

After removing leading zeros:

```text
"200"
```

If all remaining digits are zeros, or the string is empty, return `"0"`.

---

## ⏱️ Complexity Analysis

### Time Complexity: `O(n)`

Each digit is pushed onto the stack once and popped at most once. Reversing the answer and finding the first non-zero digit also take linear time.

Therefore, the overall time complexity is **`O(n)`**, where `n` is the length of `num`.

### Space Complexity: `O(n)`

In the worst case, the stack can store all `n` digits, and the result string can also contain up to `n` digits.

Therefore, the auxiliary space complexity is **`O(n)`**.

---

## 🧠 Key Concepts Learned

### 1. Monotonic Stack

A monotonic stack helps maintain digits in a useful order. When a smaller digit appears, larger preceding digits can be removed to minimize the number.

### 2. Greedy Approach

We make a locally optimal choice by removing a larger digit whenever a smaller digit appears to its right and removals remain.

### 3. Removing Remaining Digits

If `k` is still greater than zero after processing the entire string, remove digits from the top of the stack.

### 4. Reversing the Result

A stack follows Last In, First Out (LIFO), so popping digits produces them in reverse order. Reverse the string to restore their original relative order.

### 5. Handling Leading Zeros

Use `find_first_not_of('0')` to find the first non-zero digit. If it returns `string::npos`, return `"0"`.

### 6. Edge Cases

Always test:
- Increasing digits, such as `"12345"`.
- Decreasing digits, such as `"54321"`.
- Leading zeros in the result.
- `k` equal to the length of `num`.
- A result containing only zeros.

---

## 📊 Brute Force vs. Optimized Approach

| Feature | Brute Force | Greedy + Monotonic Stack |
|---|---|---|
| Approach | Try different possible removals | Remove larger preceding digits greedily |
| Time Complexity | Can be exponential if all removal combinations are explored | `O(n)` |
| Extra Space | Depends on implementation | `O(n)` |
| Efficiency | Repeats work across combinations | Processes each digit a limited number of times |
| Best Use | Understanding the search space | Efficient interview solution |

---

## Language

C++

## Status

✅ Solved

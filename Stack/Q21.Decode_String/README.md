## 1. Problem Statement

Given an encoded string, return its decoded string.

The encoding rule is:

`k[encoded_string]`

This means the string inside the square brackets should be repeated exactly `k` times.

The encoded string may contain nested brackets. You need to decode the innermost strings first.

**Note:**
- `k` is a positive integer.
- Input strings are always valid.
- Digits are only used as repeat counts.

## 2. Examples

**Example 1:**

Input:
```text
s = "3[a]"
```

Output:
```text
"aaa"
```

Explanation: The string `"a"` is repeated 3 times.

**Example 2:**

Input:
```text
s = "3[a2[c]]"
```

Output:
```text
"accaccacc"
```

Explanation:
- `2[c]` becomes `"cc"`.
- `a2[c]` becomes `"acc"`.
- `3[acc]` becomes `"accaccacc"`.

**Example 3:**

Input:
```text
s = "2[abc]3[cd]ef"
```

Output:
```text
"abcabccdcdcdef"
```

Explanation:
- `2[abc]` becomes `"abcabc"`.
- `3[cd]` becomes `"cdcdcd"`.
- Append `"ef"`.

---

## 3. Approach – Using Stack

We use a stack of pairs to handle nested brackets.

Each pair stores:

- `string`: Previous string before the opening bracket.
- `int`: Repeat count associated with that bracket.

We also maintain two variables:

- `currstr`: Stores the current decoded string.
- `num`: Stores the repeat count.

### 4. Algorithm

1. Initialize an empty current string, `num = 0`, and a stack of pairs.
2. Traverse the input string character by character.
3. If the character is a digit:
   - Convert it into an integer.
   - Build the repeat count using `num = num * 10 + digit`.
4. If the character is `[`:
   - Push the current string and repeat count into the stack.
   - Reset `currstr` and `num`.
5. If the character is `]`:
   - Get the previous string and repeat count from the stack.
   - Pop the stack.
   - Repeat the current string the required number of times.
   - Append the repeated string to the previous string.
6. Otherwise:
   - Append the character to the current string.
7. Return the final decoded string.

---

## 5. C++ Solution

```cpp
string decodeString(string s)
{
    string currstr = "";
    int num = 0;
    stack<pair<string, int>> st;

    for (int i = 0; i < s.length(); i++)
    {
        if (isdigit(s[i]))
        {
            num = num * 10 + (s[i] - '0');
        }

        else if (s[i] == '[')
        {
            st.push({currstr, num});
            currstr = "";
            num = 0;
        }

        else if (s[i] == ']')
        {
            string prevStr = st.top().first;
            int repeat = st.top().second;
            st.pop();

            string temp = "";

            for (int j = 0; j < repeat; j++)
            {
                temp += currstr;
            }

            currstr = prevStr + temp;
        }

        else
        {
            currstr += s[i];
        }
    }

    return currstr;
}

```

**Note:** LeetCode submissions require only the `Solution` class and its `decodeString()` method. The local `main()` function is included here for testing.

---

## 6. Dry Run

Input:
```text
3[a2[c]]
```

| Character | Operation | Current String |
|---|---|---|
| `3` | Store repeat count | `""` |
| `[` | Push `("", 3)` | `""` |
| `a` | Append character | `"a"` |
| `2` | Store repeat count | `"a"` |
| `[` | Push `("a", 2)` | `""` |
| `c` | Append character | `"c"` |
| `]` | Repeat `"c"` 2 times and join with `"a"` | `"acc"` |
| `]` | Repeat `"acc"` 3 times | `"accaccacc"` |

Output:
```text
accaccacc
```

---

## 7. Complexity Analysis

Let:
- `n` = Length of the encoded input string.
- `L` = Length of the decoded output string.

**Time Complexity:** O(n + L) for the character processing and output construction, with string concatenation costs depending on the implementation.

**Space Complexity:** O(n + L) for the stack and decoded strings, including the output.


---

**Language:** C++  
**Status:** ✅ Solved
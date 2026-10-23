# Q09. Remove All Adjacent Duplicates In String

**LeetCode Problem:** [1047. Remove All Adjacent Duplicates In String](https://leetcode.com/problems/remove-all-adjacent-duplicates-in-string/)  
**Difficulty:** Easy  
**Topics:** Stack, String

---

## 📌 Problem Statement

You are given a string `s` consisting of lowercase English letters.

A **duplicate removal** consists of choosing two adjacent and equal letters and removing them.

We repeatedly perform duplicate removals until no more removals are possible.

Return the final string after all possible duplicate removals.

The answer is guaranteed to be unique.

### Example 1

**Input:**
```text
s = "abbaca"
```

**Output:**
```text
"ca"
```

**Explanation:**

- Start with `"abbaca"`.
- Remove adjacent `"bb"` → `"aaca"`.
- Remove adjacent `"aa"` → `"ca"`.

No adjacent duplicates remain, so the final answer is `"ca"`.

### Example 2

**Input:**
```text
s = "azxxzy"
```

**Output:**
```text
"ay"
```

**Explanation:**

- Remove `"xx"` → `"azzy"`.
- Remove `"zz"` → `"ay"`.

No adjacent duplicates remain.

---

## 💡 Approach: Stack

We use a **stack** to remove adjacent duplicate characters efficiently.

The stack follows the **LIFO (Last In, First Out)** principle.

### How Does It Work?

We traverse the string from left to right and process each character.

- If the stack is empty, push the current character.
- If the stack's top character is equal to the current character, pop the top character.
- Otherwise, push the current character onto the stack.

After processing all characters, the stack contains the characters that remain after duplicate removal.

Since a stack returns elements in reverse order, we reverse the resulting string to obtain the correct answer.

### Algorithm

1. Create an empty stack of characters.
2. Traverse the input string character by character.
3. For each character:
   - If the stack is not empty and its top matches the current character, pop the top.
   - Otherwise, push the current character.
4. Create an empty string `ans`.
5. Pop all remaining characters from the stack and append them to `ans`.
6. Reverse `ans`.
7. Return the final string.

---

## 💻 C++ Solution

```cpp
#include<iostream>
#include<string>
#include<stack>
#include<algorithm>
using namespace std;

string removeDuplicates(string s) {

    stack<char> st;

    for (int i = 0; i < s.length(); i++) {
        if (!st.empty() && st.top() == s[i]) {
            st.pop();
        }
        else {
            st.push(s[i]);
        }
    }

    string ans = "";

    while (!st.empty()) {
        ans += st.top();
        st.pop();
    }

    reverse(ans.begin(), ans.end());

    return ans;
}

int main() {
    string s;

    cout << "Enter the string: ";
    cin >> s;

    string result = removeDuplicates(s);

    cout << "String after removing adjacent duplicates: "
         << result << endl;

    return 0;
}
```

**Note:** This code includes `main()` for local practice. For LeetCode submission, use the required `Solution` class and its `removeDuplicates()` method without `main()`.

---

## 🔍 Dry Run

**Input:**
```text
s = "abbaca"
```

Initially:

```text
Stack = Empty
```

| Step | Current Character | Operation | Stack (Bottom → Top) |
|---:|:---:|---|---|
| 1 | `a` | Stack is empty, so push | `a` |
| 2 | `b` | Top is different, so push | `a, b` |
| 3 | `b` | Top matches, so pop | `a` |
| 4 | `a` | Top matches, so pop | Empty |
| 5 | `c` | Stack is empty, so push | `c` |
| 6 | `a` | Top is different, so push | `c, a` |

After processing all characters:

```text
Stack (Bottom → Top) = c, a
```

Now we pop the remaining characters and append them to the answer string.

```text
First pop:  a  → ans = "a"
Second pop: c  → ans = "ac"
```

The stack reverses the order of the remaining characters, so we reverse the answer string.

```text
Before reverse: "ac"
After reverse:  "ca"
```

**Final Output:**
```text
ca
```

---

## 🧠 Why Do We Check `!st.empty()`?

Consider this condition:

```cpp
if (!st.empty() && st.top() == s[i])
```

We must ensure that the stack is not empty before accessing `st.top()`.

Calling `st.top()` on an empty stack is invalid and causes undefined behavior.

Therefore, we check `!st.empty()` first.

---

## 🔄 Why Do We Reverse the Answer?

A stack follows LIFO, which means the last character pushed is the first character popped.

For example, if the remaining stack contains the characters `c` and `a` from bottom to top, popping them produces `"ac"`.

But the correct string is `"ca"`.

Therefore, we reverse the answer:

```cpp
reverse(ans.begin(), ans.end());
```

The `reverse()` function is available through the `<algorithm>` header.

---

## ⏱️ Complexity Analysis

Let `n` be the length of the input string.

### Time Complexity: `O(n)`

- Traversing the input string takes `O(n)` time.
- Each character is pushed onto the stack at most once and popped at most once.
- Building the answer string takes `O(n)` time in total.
- Reversing the answer takes `O(n)` time.

Therefore, the overall time complexity is **`O(n)`**.

### Space Complexity: `O(n)`

- The stack can store up to `n` characters.
- The answer string can contain up to `n` characters.

Therefore, the auxiliary space complexity is **`O(n)`**.

---

## 📊 Brute Force vs. Stack Approach

| Feature | Brute Force | Stack Approach |
|---|---|---|
| Approach | Repeatedly search for adjacent duplicates | Process each character using a stack |
| Time Complexity | Can be `O(n²)` | `O(n)` |
| Space Complexity | Depends on implementation | `O(n)` |
| Efficiency | May repeatedly scan the string | Processes characters efficiently |
| Main Concept | String manipulation | Stack and LIFO |

---

## 🧠 Key Concepts Learned

### 1. Stack (LIFO)

The last character pushed onto the stack is the first one removed.

### 2. Adjacent Duplicate Removal

When the current character matches the stack's top, both adjacent equal characters are effectively removed.

### 3. Empty Stack Check

Always check whether the stack is empty before accessing its top element.

### 4. Building a String from a Stack

The remaining stack characters can be collected into a string by repeatedly using `top()` and `pop()`.

### 5. Reversing a String

Since the stack returns characters in reverse order, use `reverse()` to restore the correct order.

### 6. Efficient Processing

Each character is pushed and popped at most once, allowing the problem to be solved in linear time.

---

## 🔗 Connection with Previous Stack Problems

| Question | Problem | Main Concept |
|---|---|---|
| Q07 | Daily Temperatures | Monotonic Stack |
| Q08 | Online Stock Span | Monotonic Stack and Span |
| Q09 | Remove All Adjacent Duplicates In String | Stack and String Processing |

In Q07 and Q08, the stack helped us process previous elements efficiently.

In Q09, the stack helps us remove adjacent duplicates while traversing the string.

---

## ✅ Conclusion

The **Remove All Adjacent Duplicates In String** problem demonstrates how a stack can simplify string processing.

Instead of repeatedly searching for adjacent duplicates, we process each character once and remove a duplicate whenever it appears at the top of the stack.

**Key takeaway:** When processing a sequence, if the current element needs to be compared with the most recently retained element, a stack can be a useful solution.

**Status:** Solved  
**Language:** C++  
**Topic:** Stack / String  
**Difficulty:** Easy
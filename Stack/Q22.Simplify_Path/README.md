# Q10. Simplify Path

**LeetCode Problem:** [71. Simplify Path](https://leetcode.com/problems/simplify-path/)  
**Difficulty:** Medium  
**Topic:** Stack, String

## Problem Statement

You are given an absolute Unix-style file path. Your task is to simplify it and convert it into its canonical path.

Follow these rules:

1. A single period `.` represents the current directory and should be ignored.
2. Two periods `..` represent the parent directory and should move one directory up.
3. Multiple consecutive slashes `//` should be treated as a single slash `/`.
4. Any sequence of periods other than `.` or `..` is treated as a valid directory name.
5. The simplified path must start with `/`, must not end with `/` (unless it is the root directory), and must have only one slash between directory names.

## Examples

**Example 1:**

Input:
```text
/home/
```
Output:
```text
/home
```

**Example 2:**

Input:
```text
/home//foo/
```
Output:
```text
/home/foo
```

**Example 3:**

Input:
```text
/home/user/../docs
```
Output:
```text
/home/docs
```

**Example 4:**

Input:
```text
/../
```
Output:
```text
/
```

**Example 5:**

Input:
```text
/.../a/./b/../../c/
```
Output:
```text
/.../c
```

## Approach: Using Stack

We use a stack to keep track of valid directory names.

### Algorithm

1. Create a stack of strings to store directory names.
2. Traverse the input path character by character.
3. Build the current directory name in a string called `curr`.
4. Whenever `/` is encountered:
   - If `curr == ".."`, pop the top directory if the stack is not empty.
   - If `curr == "."` or `curr` is empty, ignore it.
   - Otherwise, push `curr` into the stack.
   - Reset `curr` to an empty string.
5. After the loop, process the remaining `curr` because the path may not end with `/`.
6. Pop all stack elements into a vector.
7. Traverse the vector in reverse order and construct the final path by adding `/` before each directory.
8. If the result is empty, return `/`.

## C++ Solution

```cpp

string simplifyPath(string path) {
    stack<string> s;
    string curr = "";

    for(int i = 0; i < path.length(); i++) {

        if(path[i] == '/') {

            if(curr == "..") {
                if(!s.empty()) {
                    s.pop();
                }
            }
            else if(curr == "." || curr == "") {
                // Ignore
            }
            else {
                s.push(curr);
            }

            curr = "";
        }
        else {
            curr += path[i];
        }
    }

    // Process remaining directory
    if(!curr.empty()) {
        if(curr == "..") {
            if(!s.empty()) {
                s.pop();
            }
        }
        else if(curr != ".") {
            s.push(curr);
        }
    }

    // Build final path
    vector<string> v;

    while(!s.empty()) {
        v.push_back(s.top());
        s.pop();
    }

    string ans = "";

    for(int i = v.size() - 1; i >= 0; i--) {
        ans += "/" + v[i];
    }

    if(ans == "") {
        return "/";
    }

    return ans;
}


```

**Note:** LeetCode requires only the `Solution` class and does not require `main()`. The `main()` function above is included for local testing.

## Dry Run

Input:
```text
/home/user/../docs
```

| Current Directory | Operation | Stack |
|---|---|---|
| `home` | Push | home |
| `user` | Push | home, user |
| `..` | Pop | home |
| `docs` | Push | home, docs |

After processing:

- Stack pop order: `docs`, `home`
- Reverse traversal: `home`, `docs`
- Final path: `/home/docs`

## Complexity Analysis

**Time Complexity: O(N)**

- Traversing the path takes O(N).
- Processing directories takes O(N) overall.
- Building the final path takes O(N).

**Space Complexity: O(N)**

- Stack stores directory names.
- Vector temporarily stores the directory names.

Here, N is the length of the input path.

## Key Concepts Learned

- Stack of strings
- String traversal
- Character-by-character processing
- Handling special directory names (`.` and `..`)
- LIFO (Last In, First Out)
- Building a canonical path
- Handling edge cases



**Status:** ✅ Solved
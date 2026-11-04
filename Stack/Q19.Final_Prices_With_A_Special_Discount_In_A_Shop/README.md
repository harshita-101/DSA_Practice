## Problem Statement

You are given an integer array `prices`, where `prices[i]` represents the price of the `i-th` item in a shop.

There is a special discount for each item:

- For each item `i`, find the first item to its right (`j > i`) whose price is less than or equal to `prices[i]`.
- If such an item exists, subtract `prices[j]` from `prices[i]`.
- Otherwise, the price remains unchanged.

Return an array containing the final prices after applying the discounts.

## Examples

**Example 1:**

Input:
```text
prices = [8,4,6,2,3]
```

Output:
```text
[4,2,4,2,3]
```

Explanation:

- Item 0: Price = 8, discount = 4 → 8 - 4 = 4
- Item 1: Price = 4, discount = 2 → 4 - 2 = 2
- Item 2: Price = 6, discount = 2 → 6 - 2 = 4
- Item 3: Price = 2, no discount → 2
- Item 4: Price = 3, no discount → 3

**Example 2:**

Input:
```text
prices = [1,2,3,4,5]
```

Output:
```text
[1,2,3,4,5]
```

Explanation:

There is no smaller or equal price to the right of any element, so no discount is applied.

**Example 3:**

Input:
```text
prices = [10,1,1,6]
```

Output:
```text
[9,0,1,6]
```

Explanation:

- 10 gets a discount of 1 → 10 - 1 = 9
- 1 gets a discount of 1 → 1 - 1 = 0
- 1 has no smaller or equal element to its right.
- 6 has no element to its right.

---

## Approach: Monotonic Stack

We use a **Monotonic Stack** to find the next smaller or equal element on the right side of each element.

Instead of storing prices in the stack, we store their indices.

### What Do We Store in the Stack?

We store the indices of elements whose discounts have not been found yet.

For example:

```text
prices = [8,4,6,2,3]
```

When we encounter a smaller or equal price, we use its value as the discount for the previous element at the top of the stack.

### Algorithm

1. Calculate the size of the array `n`.
2. Create an empty stack to store indices.
3. Initialize the answer vector with the original prices.
4. Traverse the `prices` array from left to right.
5. For every element, check:
   - The stack should not be empty.
   - The price at the index stored at the top of the stack should be greater than or equal to the current price.
6. If both conditions are true:
   - Update the answer at the previous element's index.
   - Subtract the current price from that previous price.
   - Pop the index from the stack.
7. Push the current index into the stack.
8. Return the final answer array.

### Why Do We Store Indices Instead of Prices?

We need to update the final price at the correct position in the answer array.

By storing indices, we can easily access the original price using:

```cpp
prices[st.top()]
```

We can also update the correct position using:

```cpp
ans[st.top()]
```
---

## C++ Solution

```cpp
#include <iostream>
#include <vector>
#include <stack>
using namespace std;

vector<int> finalPrices(vector<int> &prices)
{
    int n = prices.size();
    stack<int> st;
    vector<int> ans = prices;

    for (int i = 0; i < n; i++)
    {
        while (!st.empty() && prices[st.top()] >= prices[i])
        {
            ans[st.top()] = prices[st.top()] - prices[i];
            st.pop();
        }

        st.push(i);
    }

    return ans;
}
```

**Note:** For LeetCode submission, use the `Solution` class and omit the `main()` function.

---

## Dry Run

Input:

```text
prices = [8,4,6,2,3]
```

Initially:

```text
Stack = []
ans = [8,4,6,2,3]
```

| Step | Current Price | Stack (Bottom → Top) | Action |
|---|---:|---|---|
| 1 | 8 | [0] | Push index 0 |
| 2 | 4 | [1] | 8 gets discount 4; update ans[0] = 4 |
| 3 | 6 | [1,2] | Push index 2 |
| 4 | 2 | [3] | 6 gets discount 2; 4 gets discount 2 |
| 5 | 3 | [3,4] | Push index 4 |

Final Answer:

```text
ans = [4,2,4,2,3]
```

Output:

```text
[4,2,4,2,3]
```

---

## Complexity Analysis

Let `n` be the number of elements in the `prices` array.

| Complexity | Value | Explanation |
|---|---|---|
| Time Complexity | O(n) | Every index is pushed once and popped at most once. |
| Space Complexity | O(n) | The stack and answer array can store up to n elements. |

---

## Key Concepts Learned

- Stack operations: `push()`, `pop()`, `top()`, `empty()`.
- Monotonic Stack.
- Next Smaller or Equal Element to the Right.
- Storing indices instead of values.
- Using a stack to solve array problems efficiently.
- Updating an answer array using stored indices.
- Understanding how one element can provide discounts to multiple previous elements.

---

**Language:** C++  
**Status:** Solved ✅
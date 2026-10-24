# Q08. Online Stock Span

**LeetCode Problem:** [901. Online Stock Span](https://leetcode.com/problems/online-stock-span/)  
**Difficulty:** Medium  
**Topics:** Stack, Monotonic Stack, Design

---

## 📌 Problem Statement

Design a class `StockSpanner` that collects daily stock prices and returns the **span of the stock's price for the current day**.

The span is the number of consecutive days, including today, for which the stock price was less than or equal to today's price.

We count backward from the current day and stop as soon as we encounter a previous day's price that is greater than today's price.

### Example 1

**Input:**
```text
["StockSpanner", "next", "next", "next", "next", "next", "next", "next"]
[[], [100], [80], [60], [70], [60], [75], [85]]
```

**Output:**
```text
[null, 1, 1, 1, 2, 1, 4, 6]
```

**Explanation:**

- Day 1: Price = 100 → Span = 1
- Day 2: Price = 80 → Span = 1 because the previous price, 100, is greater.
- Day 3: Price = 60 → Span = 1 because the previous price, 80, is greater.
- Day 4: Price = 70 → Span = 2 because the previous price, 60, is less than or equal to 70, but 80 is greater.
- Day 5: Price = 60 → Span = 1 because 70 is greater.
- Day 6: Price = 75 → Span = 4 because the previous prices 60, 70, and 60 are less than or equal to 75, and their consecutive span includes four days in total.
- Day 7: Price = 85 → Span = 6 because all six previous prices are less than or equal to 85.

---

## 💡 Approach: Monotonic Stack

We use a **monotonic stack** to calculate the stock span efficiently.

Instead of checking every previous day's price individually, we store each price along with its span.

### What Do We Store in the Stack?

We use:

```cpp
stack<pair<int, int>> st;
```

Each pair contains:

- `first`: Stock price
- `second`: Span of that stock price

For example, `(70, 2)` means the stock price was 70 and its span was 2.

### Algorithm

1. Create an empty stack to store pairs of stock prices and their spans.
2. For each new stock price, initialize `span = 1` because the current day always counts.
3. While the stack is not empty and the price at the top is less than or equal to the current price:
   - Add the top element's span to the current span.
   - Remove the top element from the stack.
4. Push the current price and its calculated span onto the stack.
5. Return the calculated span.

### Why Do We Pop Previous Prices?

If a previous price is less than or equal to today's price, it contributes to today's span.

Its stored span allows us to count multiple previous days at once rather than checking them individually.

This makes the algorithm efficient.

---

## 💻 C++ Solution

```cpp
#include<iostream>
#include<stack>
using namespace std;

class StockSpanner {
    stack<pair<int, int>> st;

public:
    StockSpanner() {
    }

    int next(int price) {
        int span = 1;

        while (!st.empty() && st.top().first <= price) {
            span += st.top().second;
            st.pop();
        }

        st.push({price, span});

        return span;
    }
};

int main() {
    StockSpanner stock;

    int n;
    cout << "Enter the number of days: ";
    cin >> n;

    cout << "Enter the stock prices: ";

    for (int i = 0; i < n; i++) {
        int price;
        cin >> price;

        cout << stock.next(price) << " ";
    }

    cout << endl;

    return 0;
}
```

**Note:** The `main()` function is included for local practice. For LeetCode submission, submit only the `StockSpanner` class.

---

## 🔍 Dry Run

**Input:**

```text
100 80 60 70 60 75 85
```

Initially, the stack is empty.

| Day | Price | Operation | Span |
|---:|---:|---|---:|
| 1 | 100 | Stack is empty; push `(100, 1)` | 1 |
| 2 | 80 | 100 is greater than 80; push `(80, 1)` | 1 |
| 3 | 60 | 80 is greater than 60; push `(60, 1)` | 1 |
| 4 | 70 | Pop `(60, 1)` and add its span; push `(70, 2)` | 2 |
| 5 | 60 | 70 is greater than 60; push `(60, 1)` | 1 |
| 6 | 75 | Pop `(60, 1)`, `(70, 2)`, and `(80, 1)`; push `(75, 4)` | 4 |
| 7 | 85 | Pop `(75, 4)` and `(100, 1)`; push `(85, 6)` | 6 |

**Output:**

```text
1 1 1 2 1 4 6
```

### Understanding Day 6: Price = 75

Before processing 75, the relevant stack entries from top to bottom are:

```text
(60, 1)
(70, 2)
(80, 1)
(100, 1)
```

Start with:

```text
span = 1
```

- Pop `(60, 1)` → `span = 1 + 1 = 2`
- Pop `(70, 2)` → `span = 2 + 2 = 4`
- Stop at `(80, 1)` because 80 > 75.

Therefore, the span is **4**.

Notice that we add the stored spans instead of counting each day individually.

---

## ⏱️ Complexity Analysis

### Time Complexity: `O(1)` Amortized per Operation

A single call to `next()` can pop multiple elements, so an individual call may take `O(n)` time in the worst case.

However, every price is pushed onto the stack once and popped at most once.

Therefore, across `n` calls:

- Total time: `O(n)`
- Amortized time per call: `O(1)`

### Space Complexity: `O(n)`

In the worst case, the stack can store all previous prices and their spans.

Therefore, the auxiliary space complexity is `O(n)`.

---

## 🧠 Key Concepts Learned

### 1. Monotonic Stack

The stack maintains stock prices in strictly decreasing order from bottom to top.

When a new price is greater than or equal to the top price, we pop the smaller or equal price.

### 2. Stack of Pairs

We store both the stock price and its span:

```cpp
stack<pair<int, int>> st;
```

This allows us to skip multiple previous days efficiently.

### 3. Span Calculation

```cpp
span += st.top().second;
```

Instead of adding one for every previous day, we add the entire span of a popped entry.

### 4. Persistent State

The stack is a class member, so it retains information between calls to `next()`.

This is essential because each new stock price depends on previous prices.

### 5. Amortized Analysis

Although one call can pop several elements, each element is pushed once and popped at most once. This gives an overall linear time complexity.

---

## 📊 Brute Force vs. Optimized Approach

| Feature | Brute Force | Monotonic Stack |
|---|---|---|
| Approach | Scan previous prices one by one | Store prices with their spans |
| Total Time Complexity | `O(n²)` | `O(n)` |
| Amortized Time per Price | `O(n)` | `O(1)` |
| Extra Space | `O(1)` auxiliary space | `O(n)` |
| Efficiency | Repeats previous comparisons | Skips groups of previous days |

---

## 🔗 Connection with Daily Temperatures

Both problems use a monotonic stack, but they solve different tasks.

| Feature | Daily Temperatures | Online Stock Span |
|---|---|---|
| Goal | Find the next warmer day | Find the consecutive span of previous prices |
| Stack Stores | Indices | Price and span pairs |
| Traversal | Processes a complete array | Processes prices one at a time |
| Main Operation | Resolve previous answers when a warmer temperature appears | Pop previous prices less than or equal to the current price |
| Complexity | `O(n)` total | `O(n)` total for `n` calls |

---

## Language

C++

## Status

✅ Solved

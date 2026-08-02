# Q9. Sqrt(x)

## Problem Statement

Given a non-negative integer `x`, return the **integer square root** of `x`.

The integer square root is the largest integer `y` such that:

```
y × y ≤ x
```

The decimal part of the square root is discarded.

The solution should run in **O(log x)** time.

**Difficulty:** Easy

**LeetCode:** 69

---

## Examples

### Example 1

```text
Input:
x = 4

Output:
2
```

Explanation

```
2 × 2 = 4
```

---

### Example 2

```text
Input:
x = 8

Output:
2
```

Explanation

```
√8 = 2.828...

Integer part = 2
```

---

### Example 3

```text
Input:
x = 15

Output:
3
```

Explanation

```
3 × 3 = 9
4 × 4 = 16 (>15)

Answer = 3
```

---

## Approach

Use **Binary Search** because the answer always lies between `1` and `x`.

If

```
mid × mid == x
```

return `mid`.

If

```
mid × mid < x
```

then `mid` is a possible answer.
Store it in `ans` and search in the right half.

Otherwise search in the left half.

---

## Algorithm

1. Handle `x = 0` and `x = 1`.
2. Initialize:
   - low = 1
   - high = x
   - ans = 0
3. Calculate middle element.
4. If `mid² == x`, return `mid`.
5. If `mid² < x`
   - Store `mid` in `ans`
   - Search right half.
6. Otherwise search left half.
7. Return `ans`.

---

## Important Conditions

### Handle Edge Cases

```cpp
if (x == 0 || x == 1)
    return x;
```

---

### Calculate Mid

```cpp
long long mid = low + (high - low) / 2;
```

---

### Avoid Overflow

```cpp
long long square = mid * mid;
```

Using `long long` prevents integer overflow.

---

### Perfect Square

```cpp
if (square == x)
    return mid;
```

---

### Possible Answer

```cpp
else if (square < x)
{
    ans = mid;
    low = mid + 1;
}
```

Store the current answer and continue searching on the right.

---

### Search Left

```cpp
else
{
    high = mid - 1;
}
```

---

## Dry Run

Input

```text
x = 8
```

| low | high | mid | mid² | ans |
|----:|-----:|----:|------:|----:|
| 1 | 8 | 4 | 16 | 0 |
| 1 | 3 | 2 | 4 | 2 |
| 3 | 3 | 3 | 9 | 2 |

Loop ends.

Return

```text
2
```

---

## Complexity Analysis

**Time Complexity:** `O(log x)`

**Space Complexity:** `O(1)`

---

## Key Concepts

- Binary Search on Answer
- Floor Square Root
- Overflow Handling
- Search Space Reduction

---

## Interview Tips

- Always use

```cpp
long long square = mid * mid;
```

to avoid overflow.

- Store the current valid answer using an `ans` variable.

- Use

```cpp
mid = low + (high - low) / 2;
```

instead of

```cpp
(low + high) / 2
```

to avoid overflow.

---

## Folder Structure

```
Q9.Sqrt(x)/
├── README.md
└── sqrt.cpp
```

---

## Learning Outcomes

After solving this problem, you will understand:

- Binary Search on Answer
- Floor Value Problems
- Overflow Prevention
- Efficient Search Techniques

---

## Status

✅ Solved
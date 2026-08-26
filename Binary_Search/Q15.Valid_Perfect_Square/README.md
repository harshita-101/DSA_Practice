# Valid Perfect Square

## Problem Statement

Given a positive integer `num`, determine whether it is a **perfect square** without using any built-in square root function.

**Difficulty:** Easy  
**LeetCode:** 367

---

## Example

```text
Input:
num = 16

Output:
true
```

```text
Input:
num = 14

Output:
false
```

---

## Approach

Use **Binary Search** on the range:

```text
0 to num
```

For every `mid`, check:

```cpp
mid * mid
```

### Cases

**1. `mid * mid == num`**

A perfect square is found.

```cpp
return true;
```

**2. `mid * mid < num`**

The square is too small, so search on the right:

```cpp
low = mid + 1;
```

**3. `mid * mid > num`**

The square is too large, so search on the left:

```cpp
high = mid - 1;
```

`long long` is used for `mid` and `mid * mid` to avoid integer overflow.

---

## Algorithm

1. Initialize `low = 0` and `high = num`.
2. Calculate `mid`.
3. Compare `mid * mid` with `num`.
4. Move the search range accordingly.
5. Return `true` if an exact square is found.
6. Otherwise return `false`.

---

## Complexity

| Time Complexity | Space Complexity |
|-----------------|------------------|
| O(log n)        | O(1)             |

---

## Key Concepts

- Binary Search
- Search Space Reduction
- Integer Overflow Handling
- `long long`

---

## Status

✅ Solved
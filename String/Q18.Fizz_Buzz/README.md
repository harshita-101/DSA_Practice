# Fizz Buzz

## Problem Statement

Given an integer `n`, return a list of strings representing the numbers from `1` to `n`.

For each number:

- If it is divisible by both `3` and `5`, add `"FizzBuzz"`.
- If it is divisible only by `3`, add `"Fizz"`.
- If it is divisible only by `5`, add `"Buzz"`.
- Otherwise, add the number as a string.

**Difficulty:** Easy  
**LeetCode:** 412

---

## Example

```text
Input:
n = 15

Output:
["1","2","Fizz","4","Buzz","Fizz","7","8","Fizz","Buzz",
"11","Fizz","13","14","FizzBuzz"]
```

### Explanation

```text
3  → Fizz
5  → Buzz
6  → Fizz
10 → Buzz
15 → FizzBuzz
```

All other numbers are converted into strings.

---

## Approach

Traverse the numbers from `1` to `n`.

For every number, check its divisibility using the modulo operator `%`.

### Cases

**1. Divisible by both 3 and 5**

```cpp
i % 3 == 0 && i % 5 == 0
```

Add:

```text
FizzBuzz
```

---

**2. Divisible by 3**

```cpp
i % 3 == 0
```

Add:

```text
Fizz
```

---

**3. Divisible by 5**

```cpp
i % 5 == 0
```

Add:

```text
Buzz
```

---

**4. Not divisible by 3 or 5**

Convert the number into a string using:

```cpp
to_string(i)
```

---

## Algorithm

1. Create an empty vector of strings.
2. Traverse from `1` to `n`.
3. Check whether the current number is divisible by both `3` and `5`.
4. If yes, add `"FizzBuzz"`.
5. Otherwise, check whether it is divisible by `3`.
6. If yes, add `"Fizz"`.
7. Otherwise, check whether it is divisible by `5`.
8. If yes, add `"Buzz"`.
9. Otherwise, convert the number into a string and add it to the vector.
10. Return the final vector.

---

## Dry Run

Consider:

```text
n = 5
```

### i = 1

```text
Not divisible by 3 or 5

Add "1"
```

### i = 2

```text
Not divisible by 3 or 5

Add "2"
```

### i = 3

```text
Divisible by 3

Add "Fizz"
```

### i = 4

```text
Not divisible by 3 or 5

Add "4"
```

### i = 5

```text
Divisible by 5

Add "Buzz"
```

### Final Output

```text
["1", "2", "Fizz", "4", "Buzz"]
```

---

## Complexity

Let `n` be the given number.

| Time Complexity | Space Complexity |
|-----------------|------------------|
| O(n) | O(n) |

---

## Key Concepts

- Loops
- Conditional Statements
- Modulo Operator
- String Conversion
- `to_string()`
- Vectors

---

## Status

✅ Solved
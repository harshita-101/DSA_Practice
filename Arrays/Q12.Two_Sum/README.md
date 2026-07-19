# Q12. Two Sum

## Problem Statement

Given an array of integers `nums` and an integer `target`, return the indices of the two numbers such that they add up to the target.

You may assume that each input has exactly one solution, and you may not use the same element twice.

Return the answer in any order.

---

## Example 1

### Input

```text
nums = [2,7,11,15]
target = 9
```

### Output

```text
[0,1]
```

### Explanation

```text
nums[0] + nums[1] = 2 + 7 = 9
```

---

## Example 2

### Input

```text
nums = [3,2,4]
target = 6
```

### Output

```text
[1,2]
```

---

## Example 3

### Input

```text
nums = [3,3]
target = 6
```

### Output

```text
[0,1]
```

---

# Approach 1: Brute Force

## Idea

- Check every possible pair of elements.
- If their sum equals the target, return their indices.

## Algorithm

1. Traverse the array using two loops.
2. Compare every pair.
3. If the sum equals the target, return their indices.

### Time Complexity

```text
O(n²)
```

### Space Complexity

```text
O(1)
```

---

# Approach 2: HashMap (Optimal)

## Idea

- Traverse the array only once.
- For every element, calculate its complement.

```text
complement = target - nums[i]
```

- If the complement already exists in the HashMap, return both indices.
- Otherwise, store the current element and its index in the HashMap.

## Algorithm

1. Create an empty `unordered_map`.
2. Traverse the array.
3. Compute the complement.
4. Search for the complement in the map.
5. If found, return the stored index and current index.
6. Otherwise, store the current value and its index.
7. Continue until the answer is found.

### Time Complexity

```text
O(n)
```

### Space Complexity

```text
O(n)
```

---

# Why HashMap Works?

HashMap stores every visited element along with its index.

Instead of checking every pair, we directly search whether the required complement already exists.

Since searching in an `unordered_map` takes **O(1)** average time, the entire solution runs in **O(n)**.

---

# Concepts Used

- Arrays
- HashMap (`unordered_map`)
- Complement Technique
- One Pass Traversal

---

# Interview Tips

- Use **`unordered_map`** instead of `map` for average **O(1)** lookup.
- Always search for the complement **before** inserting the current element.
- Sorting cannot be used for the original Two Sum problem because it changes the original indices.

---

# Status

- ✅ Brute Force Completed
- ✅ Optimal (HashMap) Completed

---

## LeetCode

**Problem:** 1. Two Sum

**Difficulty:** Easy
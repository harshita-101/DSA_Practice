# Q12. Koko Eating Bananas

## Problem Statement

Koko loves to eat bananas.

There are `n` piles of bananas, where the `iᵗʰ` pile has `piles[i]` bananas.

The guards will return after `h` hours.

Koko can decide her eating speed `k` (bananas/hour).

Rules:

- In one hour, Koko chooses one pile.
- She eats at most `k` bananas from that pile.
- If the pile contains fewer than `k` bananas, she finishes that pile and waits until the next hour.

Return the **minimum integer eating speed** `k` so that Koko can finish all the bananas within `h` hours.

**Difficulty:** Medium

**LeetCode:** 875

---

## Examples

### Example 1

```text
Input:
piles = [3,6,7,11]
h = 8

Output:
4
```

Explanation

```
Speed = 4

Pile 3  -> 1 hour
Pile 6  -> 2 hours
Pile 7  -> 2 hours
Pile 11 -> 3 hours

Total = 8 hours
```

---

### Example 2

```text
Input:
piles = [30,11,23,4,20]
h = 5

Output:
30
```

---

### Example 3

```text
Input:
piles = [30,11,23,4,20]
h = 6

Output:
23
```

---

# Approach

The answer is not an index.

The answer is the **minimum eating speed**.

Possible speed range:

```
1 -------------- max(piles)
```

Use **Binary Search on Answer**.

For every speed:

- Calculate total hours required.
- If total hours ≤ h:
  - Current speed is valid.
  - Try a smaller speed.
- Otherwise:
  - Increase the speed.

---

# Helper Function

A helper function calculates the total hours required for a given eating speed.

```cpp
int calculateHours(vector<int>& piles, int speed)
```

Formula:

```cpp
hours += (pile + speed - 1) / speed;
```

This is the integer version of:

```
ceil(pile / speed)
```

---

# Algorithm

1. Set

```
low = 1
high = maximum pile
```

2. Perform Binary Search.
3. Find middle speed.
4. Calculate required hours.
5. If hours ≤ h
   - Store answer.
   - Search left.
6. Otherwise
   - Search right.
7. Return answer.

---

# Important Conditions

### Search Space

```cpp
low = 1;
high = *max_element(piles.begin(), piles.end());
```

---

### Calculate Total Hours

```cpp
hours += (pile + speed - 1) / speed;
```

---

### Valid Speed

```cpp
if(totalHours <= h)
{
    ans = mid;
    high = mid - 1;
}
```

---

### Invalid Speed

```cpp
else
{
    low = mid + 1;
}
```

---

# Dry Run

Input

```text
piles = [3,6,7,11]
h = 8
```

Initial

```
low = 1
high = 11
```

Iteration 1

```
mid = 6

Hours = 6

6 <= 8

Answer = 6

Search Left
```

Iteration 2

```
mid = 3

Hours = 10

10 > 8

Search Right
```

Iteration 3

```
mid = 4

Hours = 8

8 <= 8

Answer = 4
```

Return

```
4
```

---

# Complexity Analysis

### Time Complexity

```
O(n × log(maxPile))
```

where

- n = number of piles
- maxPile = maximum bananas in a pile

### Space Complexity

```
O(1)
```

---

# Key Concepts

- Binary Search on Answer
- Search Space
- Helper Function
- Ceiling Division
- Greedy Validation

---

# Interview Tips

- This is **not** normal Binary Search.
- We search on the **answer (speed)** instead of array indices.
- Always use a helper function to validate the current answer.
- Use integer ceiling division:

```cpp
(pile + speed - 1) / speed
```

instead of floating-point `ceil()`.

---

# Folder Structure

```
Q12.Koko_Eating_Bananas/
├── README.md
└── koko_eating_bananas.cpp
```

---

# Learning Outcomes

After solving this problem, you will understand:

- Binary Search on Answer.
- How to define the search space.
- Helper function pattern.
- Ceiling Division.
- Optimizing brute force using Binary Search.

---

# Status

✅ Solved
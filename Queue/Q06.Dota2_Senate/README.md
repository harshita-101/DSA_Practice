# Q08. Dota2 Senate

## Problem Statement

**LeetCode 649 – Dota2 Senate**

- **Difficulty:** Medium
- **Topic:** Queue, Simulation
- **Language:** C++

The Dota2 Senate consists of two parties:

- **Radiant (R)**
- **Dire (D)**

Each senator gets a turn in the given order. During their turn, a senator can ban one opponent senator.

A banned senator loses their right to vote and cannot take any further turns.

The process continues until all remaining senators belong to the same party.

Return the winning party: `"Radiant"` or `"Dire"`.

**Problem Link:** https://leetcode.com/problems/dota2-senate/

---

## Example

**Input:**
```text
senate = "RDD"
```

**Output:**
```text
Dire
```

**Explanation:**

1. Radiant at index 0 bans Dire at index 1.
2. Dire at index 2 gets the next turn and bans Radiant.
3. Only Dire senators remain.

Therefore, Dire wins.

---

## Approach: Two Queues

We use two separate queues to maintain the positions of Radiant and Dire senators.

1. `radiant` stores the indices of Radiant senators.
2. `dire` stores the indices of Dire senators.
3. Compare the front elements of both queues.
4. The senator with the smaller index gets the turn first.
5. The winning senator gets another turn in the next round, so add `n` to their index.
6. Continue until one queue becomes empty.

If the Radiant queue becomes empty, Dire wins. Otherwise, Radiant wins.

---

## Algorithm

1. Create two queues: `radiant` and `dire`.
2. Calculate the length of the input string.
3. Traverse the string and push each senator's index into the appropriate queue.
4. Run a loop while both queues are non-empty:
   - Store the front indices in `r` and `d`.
   - Remove both front elements.
   - If `r < d`, push `r + n` into the Radiant queue.
   - Otherwise, push `d + n` into the Dire queue.
5. Return the winning party based on which queue becomes empty.

---

## Dry Run

**Input:**
```text
RDD
```

String length: `n = 3`

### Initial Queues

| Radiant Queue | Dire Queue |
|---|---|
| [0] | [1, 2] |

### Iteration 1

- `r = 0`
- `d = 1`
- Since `r < d`, Radiant wins this turn.
- Remove both front elements.
- Push `r + n = 0 + 3 = 3` into Radiant.

Updated queues:

| Radiant Queue | Dire Queue |
|---|---|
| [3] | [2] |

### Iteration 2

- `r = 3`
- `d = 2`
- Since `d < r`, Dire wins this turn.
- Remove both front elements.
- Push `d + n = 2 + 3 = 5` into Dire.

Updated queues:

| Radiant Queue | Dire Queue |
|---|---|
| Empty | [5] |

The Radiant queue is empty, so **Dire wins**.

---

## C++ Code (Standalone Program)

```cpp

string predictPartyVictory(string senate)
{
    queue<int> radiant;
    queue<int> dire;
    int n = senate.length();

    for (int i = 0; i < n; i++)
    {
        if (senate[i] == 'R')
        {
            radiant.push(i);
        }
        else
        {
            dire.push(i);
        }
    }

    while (!radiant.empty() && !dire.empty())
    {
        int r = radiant.front();
        int d = dire.front();

        radiant.pop();
        dire.pop();

        if (r < d)
        {
            radiant.push(r + n);
        }
        else
        {
            dire.push(d + n);
        }
    }

    return radiant.empty() ? "Dire" : "Radiant";
}

```

---

## Complexity Analysis

| Complexity | Explanation |
|---|---|
| Time Complexity | O(n) – Each senator is processed a constant number of times. |
| Space Complexity | O(n) – Two queues store senator indices. |

---

## Key Concepts Learned

- Queue data structure
- FIFO (First In, First Out)
- Using two queues together
- Queue `front()`, `pop()` and `push()`
- Simulation of circular turn order
- Index-based comparison
- Handling the next round using `index + n`

## Important Interview Point

Why do we add `n` to the winning senator's index?

Because the senator gets another turn after the current round. Adding `n` represents their next turn in the circular sequence.

---

**Status: Solved**
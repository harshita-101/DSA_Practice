# Q09. Find the Winner of the Circular Game

## Problem Details

- **LeetCode Number:** 1823
- **Difficulty:** Medium
- **Topic:** Queue, Simulation
- **Language:** C++

**Problem Link:** https://leetcode.com/problems/find-the-winner-of-the-circular-game/

## Problem Statement

There are `n` friends sitting in a circle, numbered from `1` to `n`.

Starting from friend 1, count `k` friends in the clockwise direction. The friend on whom the counting ends is eliminated.

The counting continues from the next friend until only one friend remains.

Return the number of the winning friend.

## Example

**Input:**
```text
n = 5
k = 2
```

**Output:**
```text
3
```

**Explanation:**

Initially, the queue contains:

`[1, 2, 3, 4, 5]`

The elimination process:

1. Friend 2 is eliminated → `[3, 4, 5, 1]`
2. Friend 4 is eliminated → `[5, 1, 3]`
3. Friend 1 is eliminated → `[3, 5]`
4. Friend 5 is eliminated → `[3]`

Only friend 3 remains.

Therefore, the winner is **3**.

---

## Approach: Using Queue

We use a Queue to simulate the circular arrangement of friends.

A Queue follows the FIFO (First In, First Out) principle.

### Main Idea

1. Insert all friends from `1` to `n` into the queue.
2. Continue the process while more than one friend remains.
3. Move the front friend to the back of the queue `k-1` times.
4. Remove the next front friend because that friend is eliminated.
5. Repeat until only one friend remains.
6. Return the front element as the winner.

---

## Algorithm

1. Create a queue `q`.
2. Insert all friends from `1` to `n`.
3. Run a `while` loop while `q.size() > 1`.
4. Inside the loop:
   - Run a `for` loop from `0` to `k-2`.
   - Store the front element in `temp`.
   - Remove it using `pop()`.
   - Insert it at the back using `push(temp)`.
   - After completing the rotations, remove the next front element using `pop()`.
5. Return `q.front()`.

---

## C++ Code (Standalone Program)

```cpp

int findTheWinner(int n, int k)
{
    queue<int> q;

    for (int i = 1; i <= n; i++)
    {
        q.push(i);
    }

    while (q.size() > 1)
    {
        for (int i = 0; i < k - 1; i++)
        {
            int temp = q.front();
            q.pop();
            q.push(temp);
        }

        q.pop();
    }

    return q.front();
}

```

---

## Complexity Analysis

Let `n` be the number of friends and `k` be the counting interval.

| Complexity | Value | Explanation |
|---|---|---|
| Time | O(n × k) | Each elimination requires up to `k-1` queue rotations. |
| Space | O(n) | Queue stores all friends initially. |

---

## Key Concepts Learned

- Queue data structure
- FIFO principle
- `push()` operation
- `pop()` operation
- `front()` operation
- Circular queue simulation using a normal queue
- Iterative simulation
- Loop-based elimination

## Important Interview Points

**1. Why do we use a Queue?**

Because friends are arranged in a circular order, and we need to maintain their turn sequence.

**2. Why do we move `k-1` elements?**

Because the next friend at the front represents the kth friend and must be eliminated.

**3. Why do we use `q.size() > 1`?**

Because the game continues until only one friend remains.

**4. Why do we return `q.front()`?**

Because the last remaining friend is the winner.

---

**Status: Solved**
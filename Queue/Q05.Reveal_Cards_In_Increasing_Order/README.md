# Q07. Reveal Cards In Increasing Order

## Problem Statement

You are given an integer array `deck`, where each element represents a card.

You need to rearrange the cards so that when they are revealed using the following process, the revealed cards appear in increasing order.

**Reveal Process:**
1. Reveal the top card and remove it from the deck.
2. If cards remain, move the next top card to the bottom.
3. Repeat until all cards are revealed.

Return the initial arrangement of cards that produces an increasing reveal order.

## LeetCode Details

- **Problem Number:** 950
- **Problem Name:** Reveal Cards In Increasing Order
- **Difficulty:** Medium
- **Topic:** Queue, Array, Sorting, Simulation
- **Platform:** LeetCode
- **Link:** https://leetcode.com/problems/reveal-cards-in-increasing-order/

## Example

**Input:**
```text
deck = [17, 13, 11, 2, 3, 5, 7]
```

**Output:**
```text
[2, 13, 3, 11, 5, 17, 7]
```

**Explanation:**

The cards are arranged as `[2, 13, 3, 11, 5, 17, 7]`.

Following the reveal process:

- Reveal 2.
- Move 13 to the bottom.
- Reveal 3.
- Move 11 to the bottom.
- Reveal 5.
- Move 17 to the bottom.
- Reveal 7.

Continue until the cards are revealed in increasing order:

`[2, 3, 5, 7, 11, 13, 17]`

## Approach: Sorting + Queue of Indices

We use sorting and a queue to determine the correct position of each card.

Instead of storing actual card values in the queue, we store their indices.

### Steps

1. Sort the input array in ascending order.
2. Create a queue and insert all indices from `0` to `n-1`.
3. Create an answer vector of size `n`.
4. Initialize a variable `i = 0`.
5. While the queue is not empty:
   - Get the front index of the queue.
   - Place the current sorted card at that index in the answer vector.
   - Increment `i`.
   - Remove the front index.
   - If the queue is not empty, move its next front index to the back.
6. Return the answer vector.

## Algorithm

```text
1. Sort the deck.
2. Create an empty queue q.
3. Create an answer vector ans of size n.
4. Insert all indices into q.

5. Set i = 0.

6. While q is not empty:
      a. Get the front index.
      b. Store deck[i] at ans[index].
      c. Increment i.
      d. Remove the front index.
      e. If q is not empty:
             i. Store the next front index in temp.
            ii. Remove it.
           iii. Insert temp at the back.

7. Return ans.
```

## Dry Run

**Input:**

`deck = [17, 13, 11, 2, 3, 5, 7]`

After sorting:

`deck = [2, 3, 5, 7, 11, 13, 17]`

Initial queue:

`q = [0, 1, 2, 3, 4, 5, 6]`

| Step | Index | Card | Answer Vector |
|---|---:|---:|---|
| 1 | 0 | 2 | [2, _, _, _, _, _, _] |
| 2 | 2 | 3 | [2, _, 3, _, _, _, _] |
| 3 | 4 | 5 | [2, _, 3, _, 5, _, _] |
| 4 | 6 | 7 | [2, _, 3, _, 5, _, 7] |
| 5 | 3 | 11 | [2, _, 3, 11, 5, _, 7] |
| 6 | 1 | 13 | [2, 13, 3, 11, 5, _, 7] |
| 7 | 5 | 17 | [2, 13, 3, 11, 5, 17, 7] |

**Final Answer:**

`[2, 13, 3, 11, 5, 17, 7]`

## C++ Code

### Standalone Program (With main Function)

```cpp
#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;

vector<int> deckRevealedIncreasing(vector<int> &deck)
{
    sort(deck.begin(), deck.end());

    queue<int> q;
    vector<int> ans(deck.size());

    for (int i = 0; i < deck.size(); i++)
    {
        q.push(i);
    }

    int i = 0;

    while (!q.empty())
    {
        int index = q.front();

        ans[index] = deck[i];
        i++;

        q.pop();

        if (!q.empty())
        {
            int temp = q.front();
            q.pop();
            q.push(temp);
        }
    }

    return ans;
}

```

## Time and Space Complexity

| Operation | Complexity |
|---|---|
| Sorting the deck | O(n log n) |
| Queue insertion | O(n) |
| Queue processing | O(n) |
| Filling answer vector | O(n) |
| **Total Time Complexity** | **O(n log n)** |
| **Space Complexity** | **O(n)** |

## Key Concepts Learned

- Queue data structure
- FIFO (First In, First Out)
- Sorting an array
- Queue of indices
- `push()` and `pop()`
- `front()` operation
- Vector indexing
- Simulation technique
- Using temporary variables
- Time and Space Complexity

## Important C++ Functions

| Function | Purpose |
|---|---|
| `sort()` | Sorts the array in ascending order |
| `q.push()` | Inserts an element at the back |
| `q.front()` | Returns the front element |
| `q.pop()` | Removes the front element |
| `ans[index]` | Accesses a particular answer position |

## Language

C++


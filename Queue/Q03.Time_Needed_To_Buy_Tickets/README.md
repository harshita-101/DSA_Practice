# Q3. Time Needed to Buy Tickets

## Problem Statement
There are `n` people standing in a queue. Each person wants to buy a certain number of tickets.

- Each person buys exactly one ticket per second.
- After buying one ticket, if they still need more tickets, they go to the back of the queue.
- If they have purchased all their tickets, they leave the queue.

Given an integer array `tickets`, where `tickets[i]` represents the number of tickets required by the person at index `i`, and an integer `k`, return the total time needed for the person at index `k` to finish buying their tickets.

## LeetCode
- **Problem Number:** 2073
- **Difficulty:** Easy
- **Link:** https://leetcode.com/problems/time-needed-to-buy-tickets/

## Example

**Input:**
```text
tickets = [2,3,2], k = 2
```

**Output:**
```text
6
```

**Explanation:**

Person at index `2` needs 2 tickets.

The queue changes after every second:

| Time | Queue / Action |
|---|---|
| 0 | P0(2), P1(3), P2(2) |
| 1 | P1(3), P2(2), P0(1) |
| 2 | P2(2), P0(1), P1(2) |
| 3 | P0(1), P1(2), P2(1) |
| 4 | P1(2), P2(1) |
| 5 | P2(1), P1(1) |
| 6 | P1(1) — P2 completes at second 5 |

**Final Answer:** 6 seconds.

## Approach: Queue Simulation

We use a queue to simulate the ticket-buying process.

1. Create a queue and insert all person indexes from `0` to `n-1`.
2. Initialize `time = 0`.
3. Run a while loop until the person at index `k` has purchased all tickets.
4. Get the front person's index using `q.front()`.
5. Remove that person using `q.pop()`.
6. Decrease their remaining tickets by one.
7. Increase the time by one.
8. If the person still needs tickets, insert their index at the back using `q.push()`.
9. Return the total time.

## Algorithm

1. Create an empty queue `q`.
2. Insert all indexes into the queue.
3. Initialize `time = 0`.
4. While `tickets[k] > 0`:
   - Store the front index in `i`.
   - Remove the front person.
   - Decrease `tickets[i]` by one.
   - Increment `time`.
   - If `tickets[i] > 0`, push `i` back into the queue.
5. Return `time`.

## C++ Code

```cpp
#include <iostream>
#include <queue>
#include <vector>
using namespace std;

int timeRequiredToBuy(vector<int> &tickets, int k)
{
    queue<int> q;
    int time = 0;

    for (int i = 0; i < tickets.size(); i++)
    {
        q.push(i);
    }

    while (tickets[k] > 0)
    {
        int i = q.front();
        q.pop();

        tickets[i]--;
        time++;

        if (tickets[i] > 0)
        {
            q.push(i);
        }
    }

    return time;
}

int main()
{
    int n;
    cout << "Enter the size of the tickets array: ";
    cin >> n;

    vector<int> tickets(n);

    cout << "Enter the elements of the tickets array: ";
    for (int i = 0; i < n; i++)
    {
        cin >> tickets[i];
    }

    int k;
    cout << "Enter the index of the person: ";
    cin >> k;

    int result = timeRequiredToBuy(tickets, k);

    cout << "Time needed to buy tickets: " << result << endl;

    return 0;
}
```

## Complexity Analysis

- **Time Complexity:** O(S), where S is the total number of tickets purchased up to the completion of person `k`.
- **Space Complexity:** O(n), where n is the number of people in the queue.

## Key Concepts Learned

- Queue (FIFO – First In, First Out)
- Queue operations: `push()`, `pop()`, `front()`
- Simulation
- Array and Queue
- While loop and conditional statements

## Language
C++

## LeetCode Status
- Problem: 2073
- Difficulty: Easy
- Status: Solved

## Progress
**Q3 – Time Needed to Buy Tickets: Completed ✅**
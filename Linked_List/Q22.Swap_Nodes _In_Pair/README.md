# LeetCode 24 – Swap Nodes in Pairs

## Problem Statement
Given the head of a linked list, swap every two adjacent nodes and return the modified list.

You must swap the nodes themselves, not just their values. If the list contains an odd number of nodes, the last node remains unchanged.

**LeetCode:** [24. Swap Nodes in Pairs](https://leetcode.com/problems/swap-nodes-in-pairs/)


## Example 1

**Input:**
```text
head = [1,2,3,4]
```

**Output:**
```text
[2,1,4,3]
```

**Explanation:**
- Swap nodes `1` and `2`.
- Swap nodes `3` and `4`.

## Example 2

**Input:**
```text
head = [1,2,3,4,5]
```

**Output:**
```text
[2,1,4,3,5]
```

**Explanation:**
The first four nodes are swapped in pairs. The last node `5` remains unchanged.


## Approach: Iterative Pointer Manipulation

1. Handle edge cases where the list is empty or contains only one node.
2. Store the new head as the second node of the first pair.
3. Use three pointers:
   - `first`: the first node of the current pair.
   - `second`: the second node of the current pair.
   - `nextPair`: the first node of the next pair.
4. Connect the previous pair's last node to `second`, if a previous pair exists.
5. Reverse the current pair by setting `second->next = first`.
6. Connect `first` to `nextPair`.
7. Update `prevPair` and move `first` to the next pair.
8. Return the new head.


## Code

ListNode *swapPairs(ListNode *head)
{
    if (head == NULL || head->next == NULL)
    {
        return head;
    }

    ListNode *first = head;
    ListNode *newhead = head->next;
    ListNode *prevPair = NULL;

    while (first != NULL && first->next != NULL)
    {
        ListNode *second = first->next;
        ListNode *nextPair = first->next->next;

        if (prevPair != NULL)
        {
            prevPair->next = second;
        }

        second->next = first;
        first->next = nextPair;
        prevPair = first;
        first = nextPair;
    }
    return newhead;
}


## Complexity Analysis

Let `n` be the number of nodes in the linked list.

- **Time Complexity:** `O(n)` — each node is processed a constant number of times.
- **Auxiliary Space Complexity:** `O(1)` — the solution uses a constant number of pointers.


## Key Concepts Learned

- Singly linked lists
- Pointer manipulation
- Swapping adjacent nodes
- Maintaining linked list connections
- Iterative approach
- Handling odd-length lists and edge cases


## Language
C++


## Status
✅ Solved
# Reverse Linked List II

## Problem Statement

Given the head of a singly linked list and two integers `left` and `right`, reverse the nodes of the list from position `left` to position `right`.

The remaining part of the linked list should remain unchanged.

### LeetCode

- **Problem:** 92. Reverse Linked List II
- **Difficulty:** Medium

---

## Example

### Example 1

**Input:**
```text
1 → 2 → 3 → 4 → 5
left = 2
right = 4
```

**Output:**
```text
1 → 4 → 3 → 2 → 5
```

### Example 2

**Input:**
```text
5
left = 1
right = 3
```

**Output:**
```text
3 → 2 → 1
```

---

## Approach

We only need to reverse the portion between `left` and `right`.

A **dummy node** is used before the head to make the pointer manipulation easier, especially when `left = 1`.

### Main Idea

Suppose:

```text
1 → 2 → 3 → 4 → 5
    ↑       ↑
  left    right
```

We need to reverse:

```text
2 → 3 → 4
```

into:

```text
4 → 3 → 2
```

Final list:

```text
1 → 4 → 3 → 2 → 5
```

Instead of reversing the complete portion in the usual way, we repeatedly take the node after `current` and move it immediately after `prev`.

---

## Algorithm

```text
Create a dummy node
dummy → head

Set prev = dummy

Move prev to the node just before left

Set current = prev->next

Repeat right - left times:

    Store current->next in nextNode

    Remove nextNode from its current position

    Insert nextNode after prev

Return dummy->next
```

---

## Dry Run

Consider:

```text
1 → 2 → 3 → 4 → 5
left = 2
right = 4
```

Initially:

```text
dummy → 1 → 2 → 3 → 4 → 5
          ↑
         prev
```

`current = 2`

### First iteration

Take `3` and move it before `2`:

```text
1 → 3 → 2 → 4 → 5
```

### Second iteration

Take `4` and move it before `3`:

```text
1 → 4 → 3 → 2 → 5
```

Final answer:

```text
1 → 4 → 3 → 2 → 5
```

---

## Code

```cpp
#include <iostream>
#include <list>
using namespace std;

struct ListNode
{
    int val;
    ListNode *next;

    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

ListNode *reverseBetween(ListNode *head, int left, int right)
{
    if (head == NULL || left == right)
        return head;

    ListNode *dummy = new ListNode(0);
    dummy->next = head;

    ListNode *prev = dummy;

    for (int i = 1; i < left; i++)
    {
        prev = prev->next;
    }

    ListNode *current = prev->next;

    for (int i = 0; i < right - left; i++)
    {
        ListNode *nextNode = current->next;

        current->next = nextNode->next;

        nextNode->next = prev->next;

        prev->next = nextNode;
    }

    return dummy->next;
}

```

---

## Complexity

### Time Complexity

**O(n)**

We traverse the linked list to reach `left` and then perform the required reversals.

### Space Complexity

**O(1)**

Only a constant number of pointers are used.

---

## Key Concepts

- Linked List
- Pointer Manipulation
- Dummy Node
- Partial Reversal
- In-place Reversal
- `left` and `right` Positions
- Constant Extra Space

---

## Status

✅ Solved

**LeetCode:** 92  
**Difficulty:** Medium
# Linked List Cycle II

## Problem Statement

Given the head of a linked list, return the node where the cycle begins.

If there is no cycle, return `NULL`.

A cycle exists when a node in the linked list can be reached again by continuously following the `next` pointer.

**LeetCode:** 142
**Difficulty:** Medium

---

## Example

### Example 1

**Input:**

```text
head = [3,2,0,-4]
pos = 1
```

**Output:**

```text
Node with value 2
```

The tail node `-4` points back to the node containing `2`, so the cycle starts at `2`.

### Example 2

**Input:**

```text
head = [1,2]
pos = 0
```

**Output:**

```text
Node with value 1
```

The tail node points back to the first node.

### Example 3

**Input:**

```text
head = [1]
pos = -1
```

**Output:**

```text
NULL
```

There is no cycle.

---

## Approach

This problem can be solved using **Floyd's Cycle Detection Algorithm** with two pointers.

Two pointers are used:

* `slow` → moves one node at a time.
* `fast` → moves two nodes at a time.

### Step 1: Detect the Cycle

Move `slow` by one step and `fast` by two steps.

If `slow` and `fast` meet, a cycle exists.

If `fast` reaches `NULL`, there is no cycle.

### Step 2: Find the Starting Node

After detecting a cycle:

* Reset `slow` to `head`.
* Keep `fast` at the meeting point.
* Move both pointers one step at a time.

The point where they meet again is the **starting node of the cycle**.

---

## Algorithm

1. Initialize `slow = head`.
2. Initialize `fast = head`.
3. Move `slow` one step and `fast` two steps.
4. If `slow == fast`, a cycle exists.
5. If `fast == NULL` or `fast->next == NULL`, return `NULL`.
6. Reset `slow = head`.
7. Move both `slow` and `fast` one step at a time.
8. When `slow == fast`, return that node.
9. The returned node is the starting point of the cycle.

---

## Dry Run

Consider:

```text
3 → 2 → 0 → -4
    ↑         |
    |_________|
```

The cycle starts at `2`.

### Step 1: Detect Cycle

Initially:

```text
slow = 3
fast = 3
```

After moving:

```text
slow = 2
fast = 0
```

Continue moving until both pointers meet.

```text
slow = -4
fast = -4
```

A cycle is detected.

### Step 2: Find Cycle Start

Reset:

```text
slow = head
slow = 3
fast = -4
```

Move both one step:

```text
slow = 2
fast = 2
```

Both pointers meet at `2`.

Therefore, the cycle starts at node `2`.

---

## Code

```
class Solution
{
public:
    ListNode *detectCycle(ListNode *head)
    {
        ListNode *slow = head;
        ListNode *fast = head;

        bool isCycle = false;

        while (fast != NULL && fast->next != NULL)
        {
            slow = slow->next;
            fast = fast->next->next;

            if (slow == fast)
            {
                isCycle = true;
                break;
            }
        }

        if (!isCycle)
        {
            return NULL;
        }

        slow = head;

        while (slow != fast)
        {
            slow = slow->next;
            fast = fast->next;
        }

        return slow;
    }
};
```

---

## Complexity

* **Time Complexity:** O(n)
* **Space Complexity:** O(1)

The linked list is traversed using two pointers and no extra data structure is used.

---

## Key Concepts

* Singly Linked List
* Fast and Slow Pointers
* Floyd's Cycle Detection Algorithm
* Cycle Detection
* Finding Cycle Starting Point
* Two Pointer Technique
* Pointer Manipulation

---

## Status

✅ Solved

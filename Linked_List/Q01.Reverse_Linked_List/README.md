# Reverse Linked List

## Problem Statement

Given the head of a singly linked list, reverse the linked list and return the reversed list.

**LeetCode:** 206
**Difficulty:** Easy

---

## Example

### Example 1

**Input:**
`head = [1,2,3,4,5]`

**Output:**
`[5,4,3,2,1]`

### Example 2

**Input:**
`head = [1,2]`

**Output:**
`[2,1]`

### Example 3

**Input:**
`head = []`

**Output:**
`[]`

---

## Approach

This problem can be solved using an **iterative approach** with three pointers:

* `prev` → stores the previous node.
* `curr` → points to the current node.
* `nextNode` → stores the next node temporarily.

Initially:

* `prev = NULL`
* `curr = head`

For every node, reverse its `next` pointer so that it points to the previous node.

The important part is to store the original next node before changing the current node's link. This prevents losing the remaining part of the linked list.

---

## Algorithm

1. Initialize `prev = NULL`.
2. Set `curr = head`.
3. Traverse the linked list while `curr` is not `NULL`.
4. Store `curr->next` in `nextNode`.
5. Change `curr->next` to `prev`.
6. Move `prev` to `curr`.
7. Move `curr` to `nextNode`.
8. Continue until the entire list is reversed.
9. Return `prev` as the new head.

---

## Dry Run

Consider:

`1 → 2 → 3 → NULL`

### Step 1

Initially:

`prev = NULL`

`curr = 1`

Store next node:

`nextNode = 2`

Reverse the link:

`1 → NULL`

Move pointers:

`prev = 1`

`curr = 2`

### Step 2

Store:

`nextNode = 3`

Reverse:

`2 → 1 → NULL`

Move pointers:

`prev = 2`

`curr = 3`

### Step 3

Store:

`nextNode = NULL`

Reverse:

`3 → 2 → 1 → NULL`

Move pointers:

`prev = 3`

`curr = NULL`

Since `curr = NULL`, traversal ends.

Therefore, `prev` is the new head.

**Reversed List:**

`3 → 2 → 1 → NULL`

---

## Code

```
class Solution
{
public:
    ListNode* reverseList(ListNode* head)
    {
        ListNode* prev = NULL;
        ListNode* curr = head;

        while (curr != NULL)
        {
            ListNode* nextNode = curr->next;
            curr->next = prev;
            prev = curr;
            curr = nextNode;
        }

        return prev;
    }
};
```

---

## Complexity

* **Time Complexity:** O(n)
* **Space Complexity:** O(1)

Where `n` is the number of nodes in the linked list.

---

## Key Concepts

* Linked List
* Pointer Manipulation
* Iterative Approach
* Three Pointer Technique
* In-place Reversal

---

## Status

✅ Solved

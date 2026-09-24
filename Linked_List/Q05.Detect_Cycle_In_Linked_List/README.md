# Linked List Cycle

## Problem Statement

Given the head of a singly linked list, determine if the linked list contains a cycle.

A cycle exists if there is a node in the linked list that can be reached again by continuously following the `next` pointer.

Return `true` if a cycle exists, otherwise return `false`.

**LeetCode:** 141
**Difficulty:** Easy

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
true
```

The last node points back to the node containing `2`, creating a cycle.

### Example 2

**Input:**

```text
head = [1,2]
pos = 0
```

**Output:**

```text
true
```

The last node points back to the first node.

### Example 3

**Input:**

```text
head = [1]
pos = -1
```

**Output:**

```text
false
```

There is no cycle in the linked list.

---

## Approach

This problem can be solved using the **Fast and Slow Pointer** technique, also known as **Floyd's Cycle Detection Algorithm**.

Two pointers are used:

* `slow` → moves one node at a time.
* `fast` → moves two nodes at a time.

If there is a cycle, the `fast` pointer will eventually meet the `slow` pointer.

If there is no cycle, `fast` will reach `NULL` or `fast->next` will become `NULL`.

---

## Algorithm

1. Initialize `slow = head`.
2. Initialize `fast = head`.
3. Traverse the linked list while `fast` and `fast->next` are not `NULL`.
4. Move `slow` one step forward.
5. Move `fast` two steps forward.
6. If `slow == fast`, a cycle exists, so return `true`.
7. If the loop ends, no cycle exists, so return `false`.

---

## Dry Run

Consider:

```text
3 → 2 → 0 → -4
    ↑         |
    |_________|
```

Initially:

```text
slow = 3
fast = 3
```

### Step 1

```text
slow = 2
fast = 0
```

### Step 2

```text
slow = 0
fast = 2
```

### Step 3

```text
slow = -4
fast = -4
```

Both pointers meet at the same node.

Therefore:

```text
Cycle = true
```

---

## Code

```
bool hasCycle(ListNode *head)
{
    ListNode *slow = head;
    ListNode *fast = head;

    while (fast != NULL && fast->next != NULL)
    {
        slow = slow->next;
        fast = fast->next->next;

        if (slow == fast)
        {
            return true;
        }
    }

    return false;
}
```

---

## Complexity

* **Time Complexity:** O(n)
* **Space Complexity:** O(1)

The linked list is traversed using two pointers, and no extra data structure is required.

---

## Key Concepts

* Singly Linked List
* Fast and Slow Pointers
* Floyd's Cycle Detection Algorithm
* Two Pointer Technique
* Cycle Detection
* Pointer Manipulation

---

## Status

✅ Solved

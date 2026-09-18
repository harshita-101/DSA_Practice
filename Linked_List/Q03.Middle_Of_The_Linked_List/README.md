# Middle of the Linked List

## Problem Statement

Given the head of a singly linked list, return the **middle node** of the linked list.

If there are two middle nodes, return the **second middle node**.

**LeetCode:** 876
**Difficulty:** Easy

---

## Example

### Example 1

**Input:**

```text
head = [1,2,3,4,5]
```

**Output:**

```text
[3,4,5]
```

The middle node is `3`.

### Example 2

**Input:**

```text
head = [1,2,3,4,5,6]
```

**Output:**

```text
[4,5,6]
```

There are two middle nodes (`3` and `4`), so the second middle node `4` is returned.

---

## Approach

This problem can be solved using the **Fast and Slow Pointer** technique.

Two pointers are used:

* `slow` → moves one node at a time.
* `fast` → moves two nodes at a time.

When `fast` reaches the end of the linked list, `slow` reaches the middle node.

For an even number of nodes, `slow` points to the **second middle node**, which satisfies the problem requirement.

---

## Algorithm

1. Initialize `slow = head`.
2. Initialize `fast = head`.
3. Traverse the linked list while `fast` and `fast->next` are not `NULL`.
4. Move `slow` one step forward.
5. Move `fast` two steps forward.
6. When the loop ends, `slow` points to the middle node.
7. Return `slow`.

---

## Dry Run

Consider:

```text
1 → 2 → 3 → 4 → 5 → NULL
```

Initially:

```text
slow = 1
fast = 1
```

### Step 1

```text
slow = 2
fast = 3
```

### Step 2

```text
slow = 3
fast = 5
```

Now `fast->next` is `NULL`, so the loop stops.

Therefore:

```text
slow = 3
```

The middle node is `3`.

---

## Code

```
ListNode* middleNode(ListNode* head)
{
    ListNode* slow = head;
    ListNode* fast = head;

    while (fast != NULL && fast->next != NULL)
    {
        slow = slow->next;
        fast = fast->next->next;
    }

    return slow;
}
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
* Two Pointer Technique
* Finding Middle Node
* Pointer Traversal

---

## Status

✅ Solved

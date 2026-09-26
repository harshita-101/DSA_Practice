# Remove Linked List Elements

## Problem Statement

Given the head of a linked list and an integer `val`, remove all the nodes from the linked list whose `Node.val == val`.

Return the new head of the linked list.

**LeetCode:** 203
**Difficulty:** Easy

---

## Example

### Example 1

**Input:**

```text
head = [1,2,6,3,4,5,6]
val = 6
```

**Output:**

```text
[1,2,3,4,5]
```

### Example 2

**Input:**

```text
head = []
val = 1
```

**Output:**

```text
[]
```

### Example 3

**Input:**

```text
head = [7,7,7,7]
val = 7
```

**Output:**

```text
[]
```

---

## Approach

This problem can be solved using a **Dummy Node**.

A dummy node is created before the actual head of the linked list:

```text
dummy → head
```

This makes it easier to remove nodes, including the original head, without needing separate logic.

A `current` pointer is used to traverse the linked list.

For every node:

* If `current->next->val == val`, skip that node by changing the `next` pointer.
* Otherwise, move `current` to the next node.

When a node is deleted, `current` is **not moved**, because the next node may also contain the same value.

---

## Algorithm

1. Create a dummy node.
2. Connect `dummy->next` to `head`.
3. Set `current = dummy`.
4. Traverse while `current->next != NULL`.
5. Check whether `current->next->val == val`.
6. If the value matches:

   * Skip the node using `current->next = current->next->next`.
7. Otherwise:

   * Move `current` to `current->next`.
8. Return `dummy->next` as the new head.

---

## Dry Run

Consider:

```text
1 → 2 → 6 → 3 → 4 → 5 → 6 → NULL
```

`val = 6`

### Step 1

Create dummy:

```text
dummy → 1 → 2 → 6 → 3 → 4 → 5 → 6
  ↑
current
```

### Step 2

`current->next` is `1`.

`1 != 6`, so move `current`.

```text
dummy → 1 → 2 → 6 → 3 → 4 → 5 → 6
          ↑
        current
```

### Step 3

`current->next` is `2`.

`2 != 6`, so move `current`.

### Step 4

`current->next` is `6`.

Since:

```text
6 == val
```

skip this node.

```text
1 → 2 → 3 → 4 → 5 → 6
```

### Step 5

Continue the same process.

The last `6` is also removed.

Final list:

```text
1 → 2 → 3 → 4 → 5 → NULL
```

---

## Code

```
ListNode *removeElements(ListNode *head, int val)
{
    ListNode *dummy = new ListNode(0);
    dummy->next = head;

    ListNode *current = dummy;

    while (current->next != NULL)
    {
        if (current->next->val == val)
        {
            current->next = current->next->next;
        }
        else
        {
            current = current->next;
        }
    }

    return dummy->next;
}
```

---

## Complexity

* **Time Complexity:** O(n)
* **Space Complexity:** O(1)

The linked list is traversed once and only a few pointer variables are used.

---

## Key Concepts

* Singly Linked List
* Dummy Node
* Pointer Manipulation
* Node Deletion
* Linked List Traversal
* Handling Head Node
* In-place Modification

---

## Status

✅ Solved

# Remove Duplicates from Sorted List

## Problem Statement

Given the head of a **sorted singly linked list**, delete all duplicates such that each element appears only once.

Return the linked list after removing the duplicate nodes.

**LeetCode:** 83  
**Difficulty:** Easy

---

## Example

### Example 1

**Input:**

```text
1 → 1 → 2
```

**Output:**

```text
1 → 2
```

### Example 2

**Input:**

```text
1 → 1 → 2 → 3 → 3
```

**Output:**

```text
1 → 2 → 3
```

### Example 3

**Input:**

```text
1 → 1 → 1 → 1
```

**Output:**

```text
1
```

---

## Approach

Since the linked list is already **sorted**, duplicate values will always be next to each other.

We use one pointer called `current`.

For every node, compare:

```text
current->val
```

with:

```text
current->next->val
```

### If both values are equal

The next node is a duplicate, so skip it:

```cpp
current->next = current->next->next;
```

We **do not move `current`** because there may be more duplicate nodes.

### If values are different

Move `current` to the next node:

```cpp
current = current->next;
```

---

## Algorithm

1. Set `current = head`.
2. Traverse while `current` and `current->next` are not `NULL`.
3. Compare the current node with the next node.
4. If both values are equal, skip the duplicate node.
5. Otherwise, move `current` forward.
6. Return `head`.

---

## Dry Run

Consider:

```text
1 → 1 → 2 → 3 → 3
```

### Step 1

```text
current = 1
next = 1
```

Both are equal.

Remove duplicate:

```text
1 → 2 → 3 → 3
```

`current` stays at `1`.

### Step 2

```text
current = 1
next = 2
```

Values are different.

Move:

```text
current → 2
```

### Step 3

```text
current = 2
next = 3
```

Values are different.

Move:

```text
current → 3
```

### Step 4

```text
current = 3
next = 3
```

Duplicate found.

Remove duplicate:

```text
1 → 2 → 3
```

Final result:

```text
1 → 2 → 3
```

---

## Code

```cpp
ListNode *deleteDuplicates(ListNode *head)
{
    ListNode *current = head;

    while (current != NULL && current->next != NULL)
    {
        if (current->val == current->next->val)
        {
            current->next = current->next->next;
        }
        else
        {
            current = current->next;
        }
    }

    return head;
}
```

---

## Complexity

- **Time Complexity:** `O(n)`
- **Space Complexity:** `O(1)`

The linked list is traversed only once and no extra data structure is used.

---

## Key Concepts

- Singly Linked List
- Pointer Manipulation
- Sorted Linked List
- Removing Duplicate Nodes
- In-place Modification
- Two Consecutive Node Comparison
- Constant Extra Space

---

## Status

✅ Solved
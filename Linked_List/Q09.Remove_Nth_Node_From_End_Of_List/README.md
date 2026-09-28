# Remove Nth Node From End of List

## Problem Statement

Given the head of a linked list, remove the `n`th node from the end of the list and return its head.

**LeetCode:** 19
**Difficulty:** Medium

---

## Example

### Example 1

**Input:**

```text
head = [1,2,3,4,5]
n = 2
```

**Output:**

```text
[1,2,3,5]
```

The 2nd node from the end is `4`, so it is removed.

### Example 2

**Input:**

```text
head = [1]
n = 1
```

**Output:**

```text
[]
```

### Example 3

**Input:**

```text
head = [1,2]
n = 1
```

**Output:**

```text
[1]
```

---

## Approach

This problem can be solved using the **Two Pointer Technique** with a **Dummy Node**.

We use two pointers:

* `slow`
* `fast`

Both initially point to the dummy node.

The dummy node is placed before the actual head:

```text
dummy → 1 → 2 → 3 → 4 → 5
```

This makes removing the first node easier when `n` is equal to the length of the list.

---

## Algorithm

1. Create a dummy node.
2. Connect `dummy->next` to `head`.
3. Initialize:

   ```text
   slow = dummy
   fast = dummy
   ```
4. Move `fast` exactly `n` steps forward.
5. Move both `slow` and `fast` one step at a time while:

   ```text
   fast->next != NULL
   ```
6. At this point, `slow` is immediately before the node that needs to be removed.
7. Remove the node using:

   ```text
   slow->next = slow->next->next
   ```
8. Return:

   ```text
   dummy->next
   ```

---

## Dry Run

Consider:

```text
1 → 2 → 3 → 4 → 5
```

and:

```text
n = 2
```

### Step 1: Create Dummy

```text
dummy → 1 → 2 → 3 → 4 → 5
  ↑
slow
fast
```

### Step 2: Move Fast `n` Steps

After moving `fast` 2 steps:

```text
dummy → 1 → 2 → 3 → 4 → 5
  ↑         ↑
 slow      fast
```

### Step 3: Move Both Pointers

Move both one step at a time until `fast->next == NULL`.

Finally:

```text
dummy → 1 → 2 → 3 → 4 → 5
              ↑       ↑
            slow     fast
```

`slow->next` is `4`.

### Step 4: Remove Node

Before:

```text
3 → 4 → 5
```

After:

```text
3 → 5
```

Final list:

```text
1 → 2 → 3 → 5
```

---

## Code

```cpp
ListNode *removeNthFromEnd(ListNode *head, int n)
{
    ListNode *dummy = new ListNode(0);
    dummy->next = head;

    ListNode *slow = dummy;
    ListNode *fast = dummy;

    for (int i = 0; i < n; i++)
    {
        fast = fast->next;
    }

    while (fast->next != NULL)
    {
        slow = slow->next;
        fast = fast->next;
    }

    slow->next = slow->next->next;

    return dummy->next;
}
```

---

## Complexity

* **Time Complexity:** `O(n)`
* **Space Complexity:** `O(1)`

The linked list is traversed using two pointers and no extra data structure is required.

---

## Key Concepts

* Singly Linked List
* Two Pointer Technique
* Fast and Slow Pointers
* Dummy Node
* Node Deletion
* Pointer Manipulation
* One-Pass Linked List Traversal

---

## Status

✅ Solved

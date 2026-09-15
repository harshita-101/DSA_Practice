# Delete Node in a Linked List

## Problem Statement

There is a singly linked list with a given node that needs to be deleted.

You are given access to the node that needs to be deleted, but you are **not given access to the head of the linked list**.

Delete the given node from the linked list.

**LeetCode:** 237
**Difficulty:** Medium

---

## Example

### Example 1

**Input:**

```text
head = [4,5,1,9]
node = 5
```

**Output:**

```text
[4,1,9]
```

### Example 2

**Input:**

```text
head = [4,5,1,9]
node = 1
```

**Output:**

```text
[4,5,9]
```

---

## Approach

Since the head of the linked list is not given, we cannot directly find the previous node.

Instead, copy the value of the **next node** into the current node.

Then skip the next node by changing the current node's `next` pointer.

For example:

```text
4 → 5 → 1 → 9
    ↑
   node
```

Copy the next node's value:

```text
4 → 1 → 1 → 9
    ↑
   node
```

Then skip the duplicate node:

```text
4 → 1 → 9
```

Thus, the given node is effectively deleted.

---

## Algorithm

1. Access the given node.
2. Copy the value of `node->next` into `node`.
3. Move `node->next` to `node->next->next`.
4. The given node is now effectively removed from the linked list.

---

## Dry Run

Consider:

```text
4 → 5 → 1 → 9
    ↑
   node
```

### Step 1

Copy the next node's value:

```text
node->val = node->next->val
```

The list becomes conceptually:

```text
4 → 1 → 1 → 9
```

### Step 2

Skip the next node:

```text
node->next = node->next->next
```

Final list:

```text
4 → 1 → 9
```

Therefore, node `5` is deleted.

---

## Code

```
struct ListNode
{
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

void deleteNode(ListNode *node)
{
    node->val = node->next->val;
    node->next = node->next->next;
}
```

---

## Complexity

* **Time Complexity:** O(1)
* **Space Complexity:** O(1)

Only the given node and its next node are accessed, so no traversal of the linked list is required.

---

## Key Concepts

* Singly Linked List
* Pointer Manipulation
* Node Deletion
* Linked List Traversal
* In-place Modification

---

## Status

✅ Solved

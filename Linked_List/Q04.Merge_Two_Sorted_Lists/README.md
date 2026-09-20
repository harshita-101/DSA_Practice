# Merge Two Sorted Lists

## Problem Statement

You are given the heads of two sorted singly linked lists, `list1` and `list2`.

Merge the two lists into one **sorted linked list** by reusing the existing nodes and return the head of the merged linked list.

**LeetCode:** 21  
**Difficulty:** Easy

---

## Example

### Example 1

**Input:**
```text
list1 = [1,3,5]
list2 = [2,4,6]
```

**Output:**
```text
[1,2,3,4,5,6]
```

### Example 2

**Input:**
```text
list1 = []
list2 = [1,2,3]
```

**Output:**
```text
[1,2,3]
```

### Example 3

**Input:**
```text
list1 = [1,2,4]
list2 = [1,3,4]
```

**Output:**
```text
[1,1,2,3,4,4]
```

---

## Approach

This problem can be solved using **recursion**.

Since both linked lists are already sorted, compare the values of the current nodes of both lists.

- If `list1->val` is smaller or equal, keep `list1` as the current node and recursively merge the remaining part of `list1` with `list2`.
- Otherwise, keep `list2` as the current node and recursively merge `list1` with the remaining part of `list2`.

If either list becomes `NULL`, return the other list because it is already sorted.

The existing nodes are reused instead of creating new nodes.

---

## Algorithm

1. Check if either linked list is `NULL`.
2. If `list1` is `NULL`, return `list2`.
3. If `list2` is `NULL`, return `list1`.
4. Compare `list1->val` and `list2->val`.
5. If `list1->val <= list2->val`:
   - Keep `list1`.
   - Recursively merge `list1->next` with `list2`.
6. Otherwise:
   - Keep `list2`.
   - Recursively merge `list1` with `list2->next`.
7. Return the selected node.

---

## Dry Run

Consider:

```text
List 1: 1 → 3 → 5
List 2: 2 → 4 → 6
```

### Step 1

Compare `1` and `2`.

`1 < 2`

Choose `1`.

```text
1 → ?
```

### Step 2

Compare `3` and `2`.

`2 < 3`

Choose `2`.

```text
1 → 2 → ?
```

### Step 3

Compare `3` and `4`.

Choose `3`.

```text
1 → 2 → 3 → ?
```

Continue the same process.

Final merged list:

```text
1 → 2 → 3 → 4 → 5 → 6 → NULL
```

---

## Code

    ListNode *mergeTwoLists(ListNode *list1, ListNode *list2)
    {
        if (list1 == NULL || list2 == NULL)
        {
            return list1 == NULL ? list2 : list1;
        }

        if (list1->val <= list2->val)
        {
            list1->next = mergeTwoLists(list1->next, list2);
            return list1;
        }
        else
        {
            list2->next = mergeTwoLists(list1, list2->next);
            return list2;
        }
    }

---

## Complexity

- **Time Complexity:** O(n + m)
- **Space Complexity:** O(n + m) due to recursion stack.

Where:

- `n` = number of nodes in `list1`
- `m` = number of nodes in `list2`

Each node is processed once.

---

## Key Concepts

- Singly Linked List
- Recursion
- Pointer Manipulation
- Merging Sorted Lists
- Comparing Node Values
- Reusing Existing Nodes

---

## Status

✅ Solved
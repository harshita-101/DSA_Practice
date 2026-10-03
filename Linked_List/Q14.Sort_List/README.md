# Sort List

## Problem Statement

Given the head of a linked list, return the list after sorting it in ascending order.

**LeetCode:** 148
**Difficulty:** Medium

---

## Example

### Example 1

**Input:**

```text
4 → 2 → 1 → 3
```

**Output:**

```text
1 → 2 → 3 → 4
```

### Example 2

**Input:**

```text
-1 → 5 → 3 → 4 → 0
```

**Output:**

```text
-1 → 0 → 3 → 4 → 5
```

### Example 3

**Input:**

```text
1
```

**Output:**

```text
1
```

---

## Approach

This problem can be solved efficiently using **Merge Sort**.

Merge Sort is suitable for linked lists because we can divide the list into two halves and merge the sorted halves without requiring random access.

The solution has three main steps:

1. Find the middle of the linked list.
2. Split the linked list into two halves.
3. Recursively sort both halves and merge them.

---

## Algorithm

1. If the list is empty or contains only one node, return `head`.
2. Use the **slow and fast pointer technique** to find the middle.
3. Split the list into two separate lists.
4. Recursively call `sortList()` on both halves.
5. Merge the two sorted halves using a **dummy node**.
6. Return the merged sorted list.

---

## Dry Run

Consider:

```text
4 → 2 → 1 → 3
```

### Step 1: Find Middle

The list is divided into:

```text
4 → 2

1 → 3
```

### Step 2: Sort Both Halves

First half:

```text
4 → 2
```

becomes:

```text
2 → 4
```

Second half:

```text
1 → 3
```

becomes:

```text
1 → 3
```

### Step 3: Merge

Compare the nodes:

```text
2 and 1 → choose 1
2 and 3 → choose 2
4 and 3 → choose 3
```

Final result:

```text
1 → 2 → 3 → 4
```

---

## Merge Using Dummy Node

A dummy node is used to simplify the merging process.

```text
dummy → 1 → 2 → 3 → 4
          ↑
       actual head
```

At the end:

```cpp
return dummy->next;
```

The dummy node itself is not part of the answer.

---

## Code

```cpp
ListNode *mergeTwoLists(ListNode *list1, ListNode *list2)
{
    ListNode *dummy = new ListNode(0);
    ListNode *current = dummy;

    while (list1 != NULL && list2 != NULL)
    {
        if (list1->val <= list2->val)
        {
            current->next = list1;
            list1 = list1->next;
        }
        else
        {
            current->next = list2;
            list2 = list2->next;
        }

        current = current->next;
    }

    if (list1 != NULL)
        current->next = list1;
    else
        current->next = list2;

    return dummy->next;
}

ListNode *sortList(ListNode *head)
{
    if (head == NULL || head->next == NULL)
        return head;

    ListNode *slow = head;
    ListNode *fast = head->next;

    while (fast != NULL && fast->next != NULL)
    {
        slow = slow->next;
        fast = fast->next->next;
    }

    ListNode *second = slow->next;
    slow->next = NULL;

    ListNode *left = sortList(head);
    ListNode *right = sortList(second);

    return mergeTwoLists(left, right);
}
```

---

## Complexity

* **Time Complexity:** `O(n log n)`
* **Space Complexity:** `O(log n)`

The `O(log n)` extra space is used by the recursive calls.

---

## Key Concepts

* Singly Linked List
* Merge Sort
* Recursion
* Slow and Fast Pointers
* Divide and Conquer
* Dummy Node
* Merging Sorted Lists
* Pointer Manipulation

---

## Status

✅ Solved

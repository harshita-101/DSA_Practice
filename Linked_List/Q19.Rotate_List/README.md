# Rotate List

## Problem Statement

Given the head of a singly linked list and an integer `k`, rotate the list to the right by `k` positions.

### LeetCode
- **Problem:** 61. Rotate List
- **Difficulty:** Medium

---

## Example

### Example 1

**Input:**
```text
1 → 2 → 3 → 4 → 5
k = 2
```

**Output:**
```text
4 → 5 → 1 → 2 → 3
```

### Example 2

**Input:**
```text
0 → 1 → 2
k = 4
```

**Output:**
```text
2 → 0 → 1
```

---

## Approach

We can solve this problem using the length of the linked list and pointer manipulation.

### Main Idea

1. If the list is empty or contains only one node, return the original list.
2. Calculate the length of the linked list and find the last node (`tail`).
3. Reduce unnecessary rotations using `k = k % length`.
4. If `k == 0`, return the original list.
5. Find the node at position `length - k`.
6. Connect the last node to the original head.
7. Set the new head to the node after the break point.
8. Set the break point's `next` to `NULL`.

---

## Algorithm

```text
If head is NULL or head->next is NULL:
    Return head

Calculate length and find tail

k = k % length

If k == 0:
    Return head

Set current = head
Move current to position length - k

Connect tail->next to head
Update head to current->next
Set current->next to NULL

Return head
```

---

## Dry Run

**Input:**
```text
1 → 2 → 3 → 4 → 5
k = 2
```

### Step 1: Calculate Length

```text
length = 5
tail = 5
```

### Step 2: Calculate Effective Rotation

```text
k = k % length
k = 2 % 5 = 2
```

### Step 3: Find Break Point

```text
length - k = 5 - 2 = 3
```

The break point is node `3`.

```text
1 → 2 → 3 | 4 → 5
```

### Step 4: Connect Tail to Original Head

```text
5 → 1 → 2 → 3 → 4 → 5
```

### Step 5: Update Head and Break the List

The new head is node `4`, and node `3` points to `NULL`.

**Final Output:**
```text
4 → 5 → 1 → 2 → 3
```

---

## Code

```cpp

ListNode* rotateRight(ListNode* head, int k)
{
    if (head == NULL || head->next == NULL)
        return head;

    int length = 1;
    ListNode *tail = head;

    while (tail->next != NULL)
    {
        length++;
        tail = tail->next;
    }

    k = k % length;

    if (k == 0)
        return head;

    int pos = 1;
    ListNode *current = head;

    while (pos < length - k)
    {
        current = current->next;
        pos++;
    }

    tail->next = head;
    head = current->next;
    current->next = NULL;

    return head;
}

```

---

## Complexity

### Time Complexity: O(n)

The linked list is traversed a constant number of times to calculate its length and find the break point.

### Space Complexity: O(1)

Only a constant number of pointers and variables are used.

---

## Key Concepts

- Linked List Traversal
- Length Calculation
- Modulo Operator (`%`)
- Two-Pointer Technique
- Pointer Manipulation
- Circular Connection
- Updating the Head
- Edge Case Handling

---

## Status

✅ Solved

**LeetCode:** 61  
**Difficulty:** Medium
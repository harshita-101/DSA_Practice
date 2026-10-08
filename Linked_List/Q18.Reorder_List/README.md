# Reorder List

## Problem Statement

Given the head of a singly linked list, reorder the list in the following pattern:

```text
L0 → L1 → L2 → L3 → ... → Ln
```

should become:

```text
L0 → Ln → L1 → Ln-1 → L2 → Ln-2 → ...
```

You must reorder the list **in-place** without changing the values inside the nodes.

### LeetCode

- **Problem:** 143. Reorder List
- **Difficulty:** Medium

---

## Example

### Example 1

**Input:**
```text
1 → 2 → 3 → 4
```

**Output:**
```text
1 → 4 → 2 → 3
```

### Example 2

**Input:**
```text
1 → 2 → 3 → 4 → 5
```

**Output:**
```text
1 → 5 → 2 → 4 → 3
```

---

## Approach

The problem can be solved in **3 steps**:

1. Find the middle of the linked list using **slow and fast pointers**.
2. Reverse the second half of the list.
3. Merge the first and reversed second half alternately.

### Example

Original list:

```text
1 → 2 → 3 → 4 → 5
```

After finding middle:

```text
1 → 2 → 3 | 4 → 5
```

After reversing second half:

```text
First:  1 → 2 → 3
Second: 5 → 4
```

After alternate merging:

```text
1 → 5 → 2 → 4 → 3
```

---

## Algorithm

### Step 1: Find Middle

Use two pointers:

```text
slow → 1 step
fast → 2 steps
```

When `fast` reaches the end, `slow` reaches the middle.

### Step 2: Split the List

```cpp
ListNode* first = head;
ListNode* second = slow->next;
slow->next = NULL;
```

Now the list is divided into two halves.

### Step 3: Reverse Second Half

Use the standard three-pointer reversal:

```text
prev
curr
nextNode
```

After reversal:

```text
First:  1 → 2 → 3
Second: 5 → 4
```

### Step 4: Merge Alternately

Take one node from `first`, then one from `second`.

```text
1 → 5 → 2 → 4 → 3
```

Temporary pointers are used so that we don't lose the remaining nodes.

---

## Dry Run

Input:

```text
1 → 2 → 3 → 4 → 5
```

### Find Middle

```text
1 → 2 → 3 → 4 → 5
        ↑
       slow
```

Middle = `3`

Split:

```text
First:  1 → 2 → 3
Second: 4 → 5
```

### Reverse Second Half

```text
Second:
4 → 5

After reverse:

5 → 4
```

### Merge

First iteration:

```text
1 → 5 → 2 → 3
```

Second iteration:

```text
1 → 5 → 2 → 4 → 3
```

Final:

```text
1 → 5 → 2 → 4 → 3
```

---

## Code

```cpp

struct ListNode
{
    int val;
    ListNode *next;

    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

void reorderList(ListNode* head)
{
    ListNode* slow = head;
    ListNode* fast = head;

    // Step 1: Find middle
    while (fast != NULL && fast->next != NULL)
    {
        slow = slow->next;
        fast = fast->next->next;
    }

    // Step 2: Split the list
    ListNode* first = head;
    ListNode* second = slow->next;

    slow->next = NULL;

    // Step 3: Reverse second half
    ListNode* prev = NULL;
    ListNode* curr = second;

    while (curr != NULL)
    {
        ListNode* nextNode = curr->next;

        curr->next = prev;
        prev = curr;
        curr = nextNode;
    }

    second = prev;

    // Step 4: Merge alternately
    while (second != NULL)
    {
        ListNode* temp1 = first->next;
        ListNode* temp2 = second->next;

        first->next = second;
        second->next = temp1;

        first = temp1;
        second = temp2;
    }
}

---

## Complexity

### Time Complexity

**O(n)**

The list is traversed a constant number of times:

- Find middle → `O(n)`
- Reverse second half → `O(n)`
- Merge → `O(n)`

Overall:

```text
O(n)
```

### Space Complexity

**O(1)**

Only a constant number of pointers are used.

---

## Key Concepts

- Slow and Fast Pointers
- Finding Middle of Linked List
- Splitting Linked List
- Reversing Linked List
- In-place Modification
- Alternate Merging
- Pointer Manipulation
- Dummy-free Linked List Reordering

---

## Status

✅ Solved

**LeetCode:** 143  
**Difficulty:** Medium
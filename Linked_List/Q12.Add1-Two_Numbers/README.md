# Add Two Numbers

## Problem Statement

You are given two non-empty linked lists representing two non-negative integers.

The digits are stored in **reverse order**, and each node contains a single digit.

Add the two numbers and return the sum as a linked list.

You may assume that the two numbers do not contain any leading zeros, except for the number `0` itself.

**LeetCode:** 2
**Difficulty:** Medium

---

## Example

### Example 1

**Input:**

```text
l1 = 2 → 4 → 3
l2 = 5 → 6 → 4
```

These represent:

```text
342 + 465 = 807
```

**Output:**

```text
7 → 0 → 8
```

---

### Example 2

**Input:**

```text
l1 = 0
l2 = 0
```

**Output:**

```text
0
```

---

### Example 3

**Input:**

```text
l1 = 9 → 9 → 9 → 9
l2 = 9 → 9 → 9
```

**Output:**

```text
8 → 9 → 9 → 0 → 1
```

---

## Approach

The numbers are already stored in **reverse order**, so we can add the digits directly from the beginning of both linked lists.

For every pair of digits:

```text
sum = digit1 + digit2 + carry
```

Then:

```text
digit = sum % 10
carry = sum / 10
```

A **dummy node** is used to simplify the creation of the result linked list.

If one linked list becomes `NULL`, its value is considered `0`.

The loop continues while:

```text
l1 != NULL || l2 != NULL || carry != 0
```

This also handles the final carry.

---

## Algorithm

1. Create a dummy node.
2. Set `current = dummy`.
3. Initialize `carry = 0`.
4. Traverse both linked lists.
5. Get the values of the current nodes.
6. If a list is exhausted, use `0`.
7. Calculate:

   ```text
   sum = val1 + val2 + carry
   ```
8. Calculate the digit:

   ```text
   digit = sum % 10
   ```
9. Update carry:

   ```text
   carry = sum / 10
   ```
10. Create a new node containing `digit`.
11. Attach it to the result list.
12. Move `l1` and `l2` to their next nodes.
13. Return `dummy->next`.

---

## Dry Run

Consider:

```text
l1 = 2 → 4 → 3
l2 = 5 → 6 → 4
```

### Step 1

```text
2 + 5 + 0 = 7
```

```text
digit = 7
carry = 0
```

Result:

```text
7
```

### Step 2

```text
4 + 6 + 0 = 10
```

```text
digit = 0
carry = 1
```

Result:

```text
7 → 0
```

### Step 3

```text
3 + 4 + 1 = 8
```

```text
digit = 8
carry = 0
```

Result:

```text
7 → 0 → 8
```

Therefore:

```text
342 + 465 = 807
```

---

## Code

```cpp
ListNode *addTwoNumbers(ListNode *l1, ListNode *l2)
{
    ListNode *dummy = new ListNode(0);
    ListNode *current = dummy;

    int carry = 0;

    while (l1 != NULL || l2 != NULL || carry != 0)
    {
        int val1 = (l1 != NULL) ? l1->val : 0;
        int val2 = (l2 != NULL) ? l2->val : 0;

        int sum = val1 + val2 + carry;

        int digit = sum % 10;
        carry = sum / 10;

        ListNode *newNode = new ListNode(digit);

        current->next = newNode;
        current = current->next;

        if (l1 != NULL)
            l1 = l1->next;

        if (l2 != NULL)
            l2 = l2->next;
    }

    return dummy->next;
}
```

---

## Complexity

* **Time Complexity:** `O(max(m, n))`
* **Space Complexity:** `O(max(m, n))`

Where `m` and `n` are the lengths of the two linked lists.

The extra space is used for the result linked list.

---

## Key Concepts

* Singly Linked List
* Dummy Node
* Two Pointer Traversal
* Carry Handling
* Linked List Construction
* Digit Addition
* Modulo and Division

---

## Status

✅ Solved

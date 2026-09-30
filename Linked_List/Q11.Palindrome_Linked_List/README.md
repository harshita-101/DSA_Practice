# Palindrome Linked List

## Problem Statement

Given the head of a singly linked list, determine whether the linked list is a **palindrome**.

A linked list is a palindrome if it reads the same forward and backward.

---

## LeetCode

**Problem:** 234 - Palindrome Linked List
**Difficulty:** Easy

---

## Example

### Example 1

**Input:**

```text
1 → 2 → 2 → 1
```

**Output:**

```text
true
```

The linked list reads the same from both directions.

### Example 2

**Input:**

```text
1 → 2
```

**Output:**

```text
false
```

### Example 3

**Input:**

```text
1 → 2 → 3 → 2 → 1
```

**Output:**

```text
true
```

---

## Approach

The solution uses:

* **Slow and Fast Pointers**
* **Linked List Reversal**
* **Two Pointer Comparison**

The linked list is divided into two halves using the slow and fast pointers.

Then the second half is reversed and compared with the first half.

---

## Algorithm

1. Initialize `slow` and `fast` pointers at `head`.
2. Move `slow` one step and `fast` two steps at a time.
3. When `fast` reaches the end, `slow` reaches the middle of the list.
4. Reverse the second half of the linked list.
5. Initialize:

   ```text
   left = head
   right = reversed second half
   ```
6. Compare the values of both halves.
7. If any values are different, return `false`.
8. If all values match, return `true`.

---

## Dry Run

Consider:

```text
1 → 2 → 2 → 1
```

### Step 1: Find Middle

Using slow and fast pointers:

```text
1 → 2 → 2 → 1
        ↑
       slow
```

### Step 2: Reverse Second Half

Original second half:

```text
2 → 1
```

After reversing:

```text
1 → 2
```

### Step 3: Compare

```text
First Half:     1 → 2
Second Half:    1 → 2
```

Comparison:

```text
1 == 1 ✓
2 == 2 ✓
```

Therefore:

```text
true
```

---

## Code

```cpp
bool isPalindrome(ListNode *head)
{
    ListNode *slow = head;
    ListNode *fast = head;

    while (fast != NULL && fast->next != NULL)
    {
        slow = slow->next;
        fast = fast->next->next;
    }

    ListNode *prev = NULL;
    ListNode *curr = slow;

    while (curr != NULL)
    {
        ListNode *next = curr->next;
        curr->next = prev;
        prev = curr;
        curr = next;
    }

    ListNode *left = head;
    ListNode *right = prev;

    while (right != NULL)
    {
        if (left->val != right->val)
        {
            return false;
        }

        left = left->next;
        right = right->next;
    }

    return true;
}
```

---

## Complexity

* **Time Complexity:** `O(n)`
* **Space Complexity:** `O(1)`

The linked list is traversed a constant number of times, and no extra data structure is used.

---

## Key Concepts

* Singly Linked List
* Slow and Fast Pointers
* Two Pointer Technique
* Finding Middle of Linked List
* Reversing a Linked List
* Palindrome Checking
* In-place Manipulation

---

## Status

✅ Solved

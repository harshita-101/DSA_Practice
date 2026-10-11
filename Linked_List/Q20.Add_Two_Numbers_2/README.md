# LeetCode 445 – Add Two Numbers II

## Problem Statement
You are given two non-empty linked lists representing two non-negative integers. The digits are stored in **forward order**, and each node contains a single digit.

Add the two numbers and return their sum as a linked list.

**LeetCode:** [445. Add Two Numbers II](https://leetcode.com/problems/add-two-numbers-ii/)

## Example 1

**Input:**
```text
l1 = [7,2,4,3]
l2 = [5,6,4]
```

**Output:**
```text
[7,8,0,7]
```

**Explanation:**
```text
7243 + 564 = 7807
```

## Approach: Reverse, Add, Reverse

1. Reverse both input linked lists using a `reverseList()` helper function.
2. Traverse both reversed lists and add their corresponding digits along with the carry.
3. Calculate the current digit using `sum % 10`.
4. Update the carry using `sum / 10`.
5. Create a new node for each calculated digit and attach it to the result list using a dummy node.
6. Continue while either list has remaining nodes or the carry is non-zero.
7. Reverse the result list to restore the digits to forward order.
8. Return the head of the final result list.

## Algorithm

- Initialize `carry = 0`.
- Read the current digit from each list; use `0` if a list has ended.
- Calculate `sum = val1 + val2 + carry`.
- Create a node containing `sum % 10`.
- Update `carry = sum / 10`.
- Move the pointers forward safely.
- Reverse and return the final result.

## Code

ListNode *reverseList(ListNode *head)
{
    ListNode *prev = NULL;
    ListNode *curr = head;

    while (curr != NULL)
    {
        ListNode *nextNode = curr->next;
        curr->next = prev;
        prev = curr;
        curr = nextNode;
    }

    return prev;
}

ListNode *addTwoNumbers(ListNode *l1, ListNode *l2)
{

    ListNode *curr1 = reverseList(l1);
    ListNode *curr2 = reverseList(l2);
    int carry = 0;
    int sum = 0;
    ListNode *dummy = new ListNode(0);
    ListNode *current = dummy;

    while (curr1 != NULL || curr2 != NULL || carry != 0)
    {
        int val1 = (curr1 != NULL) ? curr1->val : 0;
        int val2 = (curr2 != NULL) ? curr2->val : 0;
        sum = val1 + val2 + carry;
        int digit = sum % 10;
        carry = sum / 10;

        ListNode *newNode = new ListNode(digit);
        current->next = newNode;
        current = current->next;
        if (curr1 != NULL)
        {
            curr1 = curr1->next;
        }
        if (curr2 != NULL)
        {
            curr2 = curr2->next;
        }
    }

    ListNode *list = reverseList(dummy->next);

    return list;
}


## Complexity Analysis

Let `n` and `m` be the lengths of the two input linked lists.

- **Time Complexity:** `O(n + m)`
- **Auxiliary Space Complexity:** `O(n + m)` for the newly created result list.

The input linked lists are modified because they are reversed during the algorithm.

## Key Concepts Learned

- Singly linked lists
- Linked list reversal
- Pointer manipulation
- Dummy node technique
- Digit-by-digit addition
- Carry handling
- Handling lists of different lengths
- Reusing helper functions

## Language
C++

## Status

✅ Solved

**LeetCode:** 445  
**Difficulty:** Medium
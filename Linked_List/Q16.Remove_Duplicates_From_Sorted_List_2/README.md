# Remove Duplicates from Sorted List II

## Problem Statement

Given the head of a **sorted linked list**, delete all nodes that have duplicate numbers, leaving only numbers that appear **exactly once**.

Return the linked list after removing all duplicates.

### LeetCode

- **Problem:** 82. Remove Duplicates from Sorted List II
- **Difficulty:** Medium

---

## Example

### Example 1

**Input:**
```text
1 → 2 → 3 → 3 → 4 → 4 → 5
```

**Output:**
```text
1 → 2 → 5
```

### Example 2

**Input:**
```text
1 → 1 → 1 → 2 → 3
```

**Output:**
```text
2 → 3
```

### Example 3

**Input:**
```text
1 → 1 → 2 → 3 → 3
```

**Output:**
```text
2
```

---

## Approach

Since the linked list is **sorted**, duplicate values will always be next to each other.

We use a **dummy node** before the head so that duplicates at the beginning of the list can also be removed easily.

### Main Idea

1. Create a dummy node pointing to `head`.
2. Use `current` to traverse the list.
3. Check whether `current->next` and `current->next->next` have the same value.
4. If they are equal, a duplicate sequence is found.
5. Store that duplicate value.
6. Use an inner `while` loop to remove **all nodes** having that value.
7. If there is no duplicate, move `current` forward.
8. Return `dummy->next`.

---

## Algorithm

```text
Create dummy node
dummy → head

Set current = dummy

While current->next is not NULL:

    If current->next and current->next->next exist
    and their values are equal:

        Store the duplicate value

        While current->next exists
        and current->next has the duplicate value:

            Remove current->next

    Else:

        Move current to the next node

Return dummy->next
```

---

## Dry Run

Consider:

```text
1 → 2 → 3 → 3 → 3 → 4
```

Initially:

```text
dummy → 1 → 2 → 3 → 3 → 3 → 4
         ↑
      current
```

Move `current` until a duplicate is found.

```text
3 == 3
```

So:

```text
duplicate = 3
```

The inner `while` removes every `3`:

```text
1 → 2 → 3 → 3 → 3 → 4
        ↓
1 → 2 → 4
```

Final result:

```text
1 → 2 → 4
```

---

## Code

```cpp
#include <iostream>
#include <list>
using namespace std;

struct ListNode
{
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

ListNode *deleteDuplicates(ListNode *head)
{
    ListNode *dummy = new ListNode(0);
    dummy->next = head;

    ListNode *current = dummy;

    while (current->next != NULL)
    {
        if (current->next->next != NULL &&
            current->next->val == current->next->next->val)
        {
            int duplicate = current->next->val;

            while (current->next != NULL &&
                   current->next->val == duplicate)
            {
                current->next = current->next->next;
            }
        }
        else
        {
            current = current->next;
        }
    }

    return dummy->next;
}

int main()
{
    int n;
    cout << "Enter the value of nodes in List: ";
    cin >> n;

    if (n < 0)
    {
        cout << "List is empty.";
        return 0;
    }

    ListNode *head = nullptr;
    ListNode *tail = nullptr;

    cout << "Enter the elements: ";

    for (int i = 0; i < n; i++)
    {
        int val;
        cin >> val;

        ListNode *newNode = new ListNode(val);

        if (head == nullptr)
        {
            head = newNode;
            tail = newNode;
        }
        else
        {
            tail->next = newNode;
            tail = newNode;
        }
    }

    head = deleteDuplicates(head);

    cout << "Linked List after removing duplicates: ";

    ListNode *temp = head;

    while (temp != NULL)
    {
        cout << temp->val << " ";
        temp = temp->next;
    }

    cout << endl;

    return 0;
}
```

---

## Complexity

### Time Complexity

**O(n)**

Each node is visited and removed at most once.

### Space Complexity

**O(1)**

Only a few pointers are used. No extra data structure is required.

---

## Key Concepts

- Sorted Linked List
- Dummy Node
- Two Pointer Traversal
- Nested `while` Loop
- Removing Consecutive Duplicates
- Pointer Manipulation
- Handling Duplicate Head Nodes

---

## Difference from LeetCode 83

| Problem | What happens to duplicates? |
|---|---|
| **83. Remove Duplicates from Sorted List** | Keep **one copy** |
| **82. Remove Duplicates from Sorted List II** | Remove **all copies** |

Example:

```text
Input:
1 → 1 → 2 → 3 → 3
```

**LeetCode 83:**
```text
1 → 2 → 3
```

**LeetCode 82:**
```text
2
```

---

## Status

✅ Solved

**LeetCode:** 82  
**Difficulty:** Medium
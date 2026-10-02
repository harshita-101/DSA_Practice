# Odd Even Linked List

## Problem Statement

Given the head of a singly linked list, group all the nodes with **odd indices** together followed by the nodes with **even indices**.

The first node is considered to have index `1`.

The relative order of the nodes inside the odd and even groups should remain the same.

**Important:**
The problem asks for rearranging the nodes, not their values.

**LeetCode:** 328
**Difficulty:** Medium

---

## Example

### Example 1

**Input:**

```text id="8c3x6y"
1 → 2 → 3 → 4 → 5
```

**Output:**

```text id="9t4qpl"
1 → 3 → 5 → 2 → 4
```

---

### Example 2

**Input:**

```text id="6x3p9a"
2 → 1 → 3 → 5 → 6 → 4 → 7
```

**Output:**

```text id="n6l8x2"
2 → 3 → 6 → 7 → 1 → 5 → 4
```

---

## Approach

Use two pointers to maintain the odd and even positioned nodes.

Three pointers are used:

```text id="k0a1dy"
odd
even
evenHead
```

* `odd` keeps track of the current odd-position node.
* `even` keeps track of the current even-position node.
* `evenHead` stores the first even-position node so that we can attach the even list at the end.

For example:

```text id="u9x8p4"
1 → 2 → 3 → 4 → 5
↑   ↑
odd even
```

After rearranging:

```text id="p7d3qa"
1 → 3 → 5
```

and:

```text id="e4r9kw"
2 → 4
```

Finally, connect:

```text id="x2v6mb"
5 → 2
```

Result:

```text id="c8j4zn"
1 → 3 → 5 → 2 → 4
```

---

## Algorithm

1. Handle the empty list and single-node list.
2. Initialize:

   ```text
   odd = head
   even = head->next
   evenHead = even
   ```
3. Traverse while `even` and `even->next` are not `NULL`.
4. Connect the current odd node to the next odd node.
5. Connect the current even node to the next even node.
6. Move both `odd` and `even` pointers forward.
7. After the loop, connect the odd list with the even list:

   ```text
   odd->next = evenHead
   ```
8. Return `head`.

---

## Dry Run

Consider:

```text id="3q8n2m"
1 → 2 → 3 → 4 → 5
```

Initial:

```text id="4q9w7e"
odd      = 1
even     = 2
evenHead = 2
```

### First Iteration

Connect the next odd node:

```text id="x3d8k1"
1 → 3
```

Connect the next even node:

```text id="j8f2qa"
2 → 4
```

Move pointers:

```text id="0p6w3s"
odd  = 3
even = 4
```

### Second Iteration

Connect:

```text id="v4q9sm"
3 → 5
```

Even list:

```text id="m7k2pc"
4 → NULL
```

After moving pointers, the loop ends.

Now connect:

```text id="b5x8nr"
5 → 2
```

Final list:

```text id="z2m7qa"
1 → 3 → 5 → 2 → 4
```

---

## Code

```cpp
ListNode* oddEvenList(ListNode* head)
{
    if (head == NULL || head->next == NULL)
        return head;

    ListNode* odd = head;
    ListNode* even = head->next;
    ListNode* evenHead = even;

    while (even != NULL && even->next != NULL)
    {
        odd->next = odd->next->next;
        even->next = even->next->next;

        odd = odd->next;
        even = even->next;
    }

    odd->next = evenHead;

    return head;
}
```

---

## Complexity

* **Time Complexity:** `O(n)`
* **Space Complexity:** `O(1)`

The list is traversed once and only a constant number of pointers are used.

---

## Key Concepts

* Singly Linked List
* Two Pointer Technique
* Pointer Manipulation
* Odd and Even Positions
* In-place Linked List Rearrangement
* Maintaining Relative Order
* Constant Extra Space

---

## Status

✅ Solved

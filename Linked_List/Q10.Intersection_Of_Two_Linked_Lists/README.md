# Intersection of Two Linked Lists

## Problem Statement

Given the heads of two singly linked lists, find the node at which the two linked lists intersect.

If the two linked lists do not intersect, return `NULL`.

**Important:**
Intersection means both linked lists point to the **same node in memory**, not just nodes having the same value.

---

## LeetCode

**Problem:** 160 - Intersection of Two Linked Lists
**Difficulty:** Easy

---

## Example

### Example 1

**Input:**

```text
List A: 4 → 1 → 8 → 4 → 5
List B: 5 → 6 → 1 → 8 → 4 → 5
```

**Output:**

```text
8
```

The node with value `8` is the intersection node.

---

### Example 2

**Input:**

```text
List A: 1 → 9 → 1 → 2 → 4
List B:       3 → 2 → 4
```

**Output:**

```text
2
```

---

### Example 3

**Input:**

```text
List A: 2 → 6 → 4
List B: 1 → 5
```

**Output:**

```text
NULL
```

The two linked lists do not intersect.

---

## Approach

Use the **Two Pointer Technique**.

Create two pointers:

```text
pA = headA
pB = headB
```

Move both pointers one step at a time.

When a pointer reaches the end of its linked list, move it to the head of the other linked list.

```text
pA = (pA == NULL) ? headB : pA->next;

pB = (pB == NULL) ? headA : pB->next;
```

Because both pointers traverse both lists, they travel the same total distance.

Eventually:

```text
pA == pB
```

If there is an intersection, both point to the intersection node.

If there is no intersection, both eventually become `NULL`.

---

## Algorithm

1. Initialize `pA` with `headA`.
2. Initialize `pB` with `headB`.
3. Run a loop while `pA != pB`.
4. Move `pA` to its next node.
5. If `pA` becomes `NULL`, move it to `headB`.
6. Move `pB` to its next node.
7. If `pB` becomes `NULL`, move it to `headA`.
8. When `pA == pB`, return `pA`.

---

## Dry Run

Consider:

```text
List A: 4 → 1 → 8 → 4 → 5
List B: 5 → 6 → 1 → 8 → 4 → 5
```

The lists share the same nodes from `8` onwards:

```text
A: 4 → 1 ─────┐
              ↓
              8 → 4 → 5
              ↑
B: 5 → 6 → 1 ─┘
```

Initially:

```text
pA = headA
pB = headB
```

Both pointers move through their respective lists.

When `pA` reaches `NULL`, it starts from `headB`.

When `pB` reaches `NULL`, it starts from `headA`.

After traversing both lists, both pointers meet at:

```text
8
```

Therefore, the intersection node is `8`.

---

## Code

```cpp
ListNode *getIntersectionNode(ListNode *headA, ListNode *headB)
{
    ListNode *pA = headA;
    ListNode *pB = headB;

    while (pA != pB)
    {
        pA = (pA == NULL) ? headB : pA->next;
        pB = (pB == NULL) ? headA : pB->next;
    }

    return pA;
}
```

---

## Complexity

* **Time Complexity:** `O(m + n)`
* **Space Complexity:** `O(1)`

Where `m` and `n` are the lengths of the two linked lists.

---

## Key Concepts

* Singly Linked List
* Two Pointer Technique
* Pointer Manipulation
* Intersection of Linked Lists
* Memory Address Comparison
* `NULL` Handling
* Constant Extra Space

---

## Status

✅ Solved

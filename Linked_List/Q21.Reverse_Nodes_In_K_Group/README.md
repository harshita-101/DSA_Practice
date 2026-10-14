# LeetCode 25 – Reverse Nodes in k-Group

## Problem Statement
Given the head of a linked list, reverse the nodes of the list `k` at a time and return the modified list.

If the number of nodes remaining is less than `k`, those nodes must remain in their original order.

**LeetCode:** [Reverse Nodes in k-Group](https://leetcode.com/problems/reverse-nodes-in-k-group/)

## Example 1

**Input:**
```text
head = [1,2,3,4,5], k = 2
```

**Output:**
```text
[2,1,4,3,5]
```

**Explanation:**
- Reverse `[1,2]` to get `[2,1]`.
- Reverse `[3,4]` to get `[4,3]`.
- The remaining node `[5]` stays unchanged.

## Example 2

**Input:**
```text
head = [1,2,3,4,5], k = 3
```

**Output:**
```text
[3,2,1,4,5]
```

**Explanation:**
The first three nodes are reversed. The remaining two nodes are fewer than `k`, so they remain unchanged.

## Approach: Iterative Reversal + Recursion

1. Handle edge cases when the list is empty or `k = 1`.
2. Traverse up to `k` nodes to verify that a complete group is available.
3. If fewer than `k` nodes remain, return the original head without reversing them.
4. Reverse the current group using three pointers: `prev`, `curr`, and `nextNode`.
5. Save the original first node of the group as `groupStart`.
6. Recursively reverse the remaining groups and connect them using `groupStart->next`.
7. Return `prev`, the new head of the reversed group.

## Algorithm

- Check whether at least `k` nodes are available.
- Reverse exactly `k` nodes.
- Connect the reversed group to the recursively processed remaining list.
- Leave any incomplete final group unchanged.

## Complexity Analysis

Let `n` be the number of nodes in the linked list.

- **Time Complexity:** `O(n)` — each node is processed a constant number of times.
- **Auxiliary Space Complexity:** `O(n/k)` — recursion stack space for processing groups of size `k`.

## Key Concepts Learned

- Singly linked lists
- Pointer manipulation
- Reversing nodes in groups
- Recursion
- Connecting reversed sublists
- Handling incomplete groups
- Edge case handling

## Language
C++

## Status
✅ Solved
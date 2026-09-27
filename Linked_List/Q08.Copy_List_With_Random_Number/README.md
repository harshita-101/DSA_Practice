# Copy List with Random Pointer

## Problem Statement

A linked list is given where each node contains:

* `val` — the value of the node.
* `next` — pointer to the next node.
* `random` — pointer to any node in the linked list or `NULL`.

Create a **deep copy** of the linked list and return the head of the copied list.

The copied list must contain completely new nodes, while preserving the same `next` and `random` relationships as the original list.

## LeetCode

**Problem:** 138 - Copy List with Random Pointer
**Difficulty:** Medium

## Example

### Input

```text
Nodes: [7, 13, 11, 10, 1]
Random: [1, 0, 4, 2, 0]
```

### Output

```text
[7, 13, 11, 10, 1]
```

with the same random pointer relationships as the original list.

## Approach

Use an `unordered_map` to store the relationship between each original node and its copied node.

```text
Original Node → Copied Node
```

The solution is performed in two passes:

1. Create a copy of every node and store the mapping.
2. Use the mapping to connect the `random` pointers.

## Algorithm

1. If `head == NULL`, return `NULL`.
2. Create an `unordered_map<Node*, Node*>`.
3. Traverse the original linked list.
4. Create a new node for every original node.
5. Store the mapping:

   ```text
   original node → copied node
   ```
6. Connect the `next` pointers of the copied nodes.
7. Traverse the original list again.
8. For every node:

   * If `random == NULL`, keep copied random as `NULL`.
   * Otherwise, use the map to find the corresponding copied random node.
9. Return the head of the copied linked list.

## Dry Run

Consider:

```text
Original:

7 → 13 → 11 → 10 → 1

Random:
7  → 13
13 → 7
11 → 1
10 → 11
1  → 7
```

### Step 1: Create copied nodes

```text
Original     Copy
7       →    7
13      →    13
11      →    11
10      →    10
1       →    1
```

The map stores:

```text
7  → copied 7
13 → copied 13
11 → copied 11
10 → copied 10
1  → copied 1
```

### Step 2: Connect random pointers

For node `7`:

```text
7.random = 13
```

Using the map:

```text
copy[7].random = copy[13]
```

Similarly, all other random pointers are connected.

Final copied list:

```text
7 → 13 → 11 → 10 → 1
↓    ↓    ↓    ↓    ↓
13   7    1    11   7
```

## Code

See `copy_list_with_random_number.cpp` for the complete C++ implementation.

## Complexity

### Time Complexity

```text
O(n)
```

The linked list is traversed a constant number of times.

### Space Complexity

```text
O(n)
```

The `unordered_map` stores a mapping for every node.

## Key Concepts

* Linked List
* Deep Copy
* Random Pointer
* Hash Map
* Pointer Mapping
* Two-Pass Approach
* Dynamic Memory Allocation

## Status

✅ Solved

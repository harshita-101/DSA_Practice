# Q11. Design Front Middle Back Queue

**LeetCode:** [1670. Design Front Middle Back Queue](https://leetcode.com/problems/design-front-middle-back-queue/)  
**Difficulty:** Medium  
**Topic:** Queue, Deque, Design, STL

## Problem Statement

Design a queue that supports insertion and deletion at three positions:

- Front
- Middle
- Back

Implement the following operations:

| Function | Description |
|---|---|
| `pushFront(val)` | Insert an element at the front |
| `pushMiddle(val)` | Insert an element at the middle |
| `pushBack(val)` | Insert an element at the back |
| `popFront()` | Remove and return the front element |
| `popMiddle()` | Remove and return the middle element |
| `popBack()` | Remove and return the last element |

If the queue is empty, all pop operations must return `-1`.

**Important:** If there are two middle positions, choose the frontmost middle position for deletion.

## Approach: Two Deques

We use two STL deques:

- `left` stores the first half of the elements.
- `right` stores the second half of the elements.

### Balance Condition

We maintain this condition after every operation:

```cpp
left.size() == right.size()
```

OR

```cpp
left.size() == right.size() + 1
```

This means `left` can contain either the same number of elements as `right` or exactly one extra element.

### Why Two Deques?

A deque supports insertion and deletion from both ends in O(1) time.

Using two deques allows us to perform all six operations efficiently without shifting elements.

## Algorithm

### 1. pushFront(val)

1. Insert the value at the front of `left`.
2. Call `balance()` to maintain the size condition.

### 2. pushMiddle(val)

1. If `left` has more elements than `right`, move the last element of `left` to the front of `right`.
2. Insert the new value at the back of `left`.

### 3. pushBack(val)

1. Insert the value at the back of `right`.
2. Call `balance()`.

### 4. popFront()

1. If both deques are empty, return `-1`.
2. Remove the first element of `left`.
3. Call `balance()`.
4. Return the removed element.

### 5. popMiddle()

1. If both deques are empty, return `-1`.
2. Remove and return the last element of `left`.
3. Call `balance()`.

The last element of `left` represents the frontmost middle element.

### 6. popBack()

1. If both deques are empty, return `-1`.
2. If `right` is not empty, remove its last element.
3. Otherwise, remove the last element of `left`.
4. Call `balance()` and return the removed element.

## Balance Function

The `balance()` function maintains the size condition.

```cpp
void balance() {
    if (left.size() > right.size() + 1) {
        right.push_front(left.back());
        left.pop_back();
    }
    else if (left.size() < right.size()) {
        left.push_back(right.front());
        right.pop_front();
    }
}
```

## Dry Run

Consider the following operations:

| Operation | Left | Right |
|---|---|---|
| `pushFront(1)` | [1] | [] |
| `pushBack(2)` | [1] | [2] |
| `pushMiddle(3)` | [1, 3] | [2] |
| `pushMiddle(4)` | [1, 4] | [3, 2] |

Combined queue:

```text
[1, 4, 3, 2]
```

Now perform deletion operations:

| Operation | Returned Value | Queue |
|---|---:|---|
| `popFront()` | 1 | [4, 3, 2] |
| `popMiddle()` | 3 | [4, 2] |
| `popMiddle()` | 4 | [2] |
| `popBack()` | 2 | [] |
| `popFront()` | -1 | [] |

## C++ Implementation

```cpp
#include<iostream>
#include<deque>
using namespace std;

class FrontMiddleBackQueue {
    deque<int> left;
    deque<int> right;

    void balance() {
        if (left.size() > right.size() + 1) {
            right.push_front(left.back());
            left.pop_back();
        }
        else if (left.size() < right.size()) {
            left.push_back(right.front());
            right.pop_front();
        }
    }

public:
    FrontMiddleBackQueue() {
    }

    void pushFront(int val) {
        left.push_front(val);
        balance();
    }

    void pushMiddle(int val) {
        if (left.size() > right.size()) {
            right.push_front(left.back());
            left.pop_back();
        }

        left.push_back(val);
    }

    void pushBack(int val) {
        right.push_back(val);
        balance();
    }

    int popFront() {
        if (left.empty() && right.empty()) {
            return -1;
        }

        int val = left.front();
        left.pop_front();

        balance();
        return val;
    }

    int popMiddle() {
        if (left.empty() && right.empty()) {
            return -1;
        }

        int val = left.back();
        left.pop_back();

        balance();
        return val;
    }

    int popBack() {
        if (left.empty() && right.empty()) {
            return -1;
        }

        int val;

        if (!right.empty()) {
            val = right.back();
            right.pop_back();
        }
        else {
            val = left.back();
            left.pop_back();
        }

        balance();
        return val;
    }
};

```

## Sample Input

```text
8
1 1
3 2
2 3
2 4
4
5
6
4
```

## Sample Output

```text
1
3
2
-1
```

## Complexity Analysis

| Operation | Time Complexity |
|---|---|
| `pushFront()` | O(1) |
| `pushMiddle()` | O(1) |
| `pushBack()` | O(1) |
| `popFront()` | O(1) |
| `popMiddle()` | O(1) |
| `popBack()` | O(1) |
| `balance()` | O(1) |

**Space Complexity:** O(n), where n is the total number of elements.

## Key Concepts Learned

- STL Deque
- Two-deque approach
- Insertion and deletion from both ends
- Middle insertion and deletion
- Balancing two data structures
- Maintaining size invariants
- Efficient O(1) operations


**Status:** Completed ✅
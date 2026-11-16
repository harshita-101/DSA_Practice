## Problem Statement

Design a Circular Double-Ended Queue (Deque) with a fixed capacity `k`.

A Deque allows insertion and deletion from both ends:

- `insertFront(value)` – Insert an element at the front.
- `insertLast(value)` – Insert an element at the rear.
- `deleteFront()` – Delete the front element.
- `deleteLast()` – Delete the rear element.
- `getFront()` – Return the front element.
- `getRear()` – Return the rear element.
- `isEmpty()` – Check whether the deque is empty.
- `isFull()` – Check whether the deque is full.

Return `false` when insertion or deletion is not possible.

## Approach: Circular Array with Count

We use a vector to implement the deque.

### Variables Used

| Variable | Purpose |
|---|---|
| `arr` | Stores deque elements |
| `front` | Tracks the front index |
| `rear` | Tracks the rear index |
| `capacity` | Maximum capacity of deque |
| `count` | Current number of elements |

### Circular Index Formulas

**Move front backward:**
```cpp
front = (front - 1 + capacity) % capacity;
```

**Move front forward:**
```cpp
front = (front + 1) % capacity;
```

**Move rear forward:**
```cpp
rear = (rear + 1) % capacity;
```

**Move rear backward:**
```cpp
rear = (rear - 1 + capacity) % capacity;
```

The modulo operator helps us wrap around the array when an index reaches either end.

## Algorithm

1. Initialize `front` and `rear` to `-1`.
2. Initialize `count` to `0`.
3. Before insertion, check whether the deque is full.
4. Before deletion, check whether the deque is empty.
5. If inserting the first element, set both `front` and `rear` to `0`.
6. Update the appropriate index using circular formulas.
7. Increase `count` after insertion and decrease it after deletion.
8. If the last element is deleted, reset both indices to `-1`.

## Example Dry Run

**Capacity = 3**

Operations:

| Operation | Result | Deque |
|---|---|---|
| `insertLast(1)` | true | [1] |
| `insertLast(2)` | true | [1, 2] |
| `insertFront(3)` | true | [3, 1, 2] |
| `insertFront(4)` | false | [3, 1, 2] |
| `getRear()` | 2 | [3, 1, 2] |
| `isFull()` | true | [3, 1, 2] |
| `deleteLast()` | true | [3, 1] |
| `insertFront(4)` | true | [4, 3, 1] |
| `getFront()` | 4 | [4, 3, 1] |

## C++ Implementation

```cpp
#include<iostream>
#include<vector>
using namespace std;

class MyCircularDeque {
    vector<int> arr;
    int front;
    int rear;
    int capacity;
    int count;

public:
    MyCircularDeque(int k) {
        capacity = k;
        arr.resize(k);
        front = -1;
        rear = -1;
        count = 0;
    }

    bool insertFront(int value) {
        if (isFull()) {
            return false;
        }

        if (count == 0) {
            front = rear = 0;
        }
        else {
            front = (front - 1 + capacity) % capacity;
        }

        arr[front] = value;
        count++;
        return true;
    }

    bool insertLast(int value) {
        if (isFull()) {
            return false;
        }

        if (count == 0) {
            front = rear = 0;
        }
        else {
            rear = (rear + 1) % capacity;
        }

        arr[rear] = value;
        count++;
        return true;
    }

    bool deleteFront() {
        if (isEmpty()) {
            return false;
        }

        if (count == 1) {
            front = rear = -1;
        }
        else {
            front = (front + 1) % capacity;
        }

        count--;
        return true;
    }

    bool deleteLast() {
        if (isEmpty()) {
            return false;
        }

        if (count == 1) {
            front = rear = -1;
        }
        else {
            rear = (rear - 1 + capacity) % capacity;
        }

        count--;
        return true;
    }

    int getFront() {
        if (isEmpty()) {
            return -1;
        }
        return arr[front];
    }

    int getRear() {
        if (isEmpty()) {
            return -1;
        }
        return arr[rear];
    }

    bool isEmpty() {
        return count == 0;
    }

    bool isFull() {
        return count == capacity;
    }
};

```

## Output

```text
true
true
true
false
2
true
true
true
4
```

## Complexity Analysis

| Operation | Time Complexity |
|---|---|
| `insertFront()` | O(1) |
| `insertLast()` | O(1) |
| `deleteFront()` | O(1) |
| `deleteLast()` | O(1) |
| `getFront()` | O(1) |
| `getRear()` | O(1) |
| `isEmpty()` | O(1) |
| `isFull()` | O(1) |

**Space Complexity:** O(k), where `k` is the deque capacity.

## Key Concepts Learned

- Difference between Queue and Deque.
- Circular array implementation.
- Insertion and deletion from both ends.
- Front and rear pointer management.
- Modulo operator for circular indexing.
- Handling empty and full conditions.
- Maintaining element count.


**Status:** Completed ✅
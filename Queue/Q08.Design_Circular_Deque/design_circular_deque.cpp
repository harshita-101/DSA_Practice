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


int main() {
    MyCircularDeque dq(3);

    cout << boolalpha;

    cout << dq.insertLast(1) << endl;   // true
    cout << dq.insertLast(2) << endl;   // true
    cout << dq.insertFront(3) << endl;  // true
    cout << dq.insertFront(4) << endl;  // false (Deque full)

    cout << dq.getRear() << endl;       // 2
    cout << dq.isFull() << endl;        // true

    cout << dq.deleteLast() << endl;    // true
    cout << dq.insertFront(4) << endl;  // true

    cout << dq.getFront() << endl;      // 4

    return 0;
}
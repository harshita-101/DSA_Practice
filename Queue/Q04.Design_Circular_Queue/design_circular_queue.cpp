
#include <iostream>
#include <vector>
using namespace std;

class MyCircularQueue {
private:
    vector<int> arr;
    int front, rear, capacity, count;

public:
    MyCircularQueue(int k) {
        arr.resize(k);
        front = -1;
        rear = -1;
        capacity = k;
        count = 0;
    }

    bool enQueue(int value) {
        if (isFull()) {
            return false;
        }

        if (isEmpty()) {
            front = 0;
            rear = 0;
        }
        else {
            rear = (rear + 1) % capacity;
        }

        arr[rear] = value;
        count++;

        return true;
    }

    bool deQueue() {
        if (isEmpty()) {
            return false;
        }

        if (count == 1) {
            front = -1;
            rear = -1;
        }
        else {
            front = (front + 1) % capacity;
        }

        count--;
        return true;
    }

    int Front() {
        if (isEmpty()) return -1;
        return arr[front];
    }

    int Rear() {
        if (isEmpty()) return -1;
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
    int k, n;

    cout << "Enter queue capacity: ";
    cin >> k;

    if (k <= 0) {
        cout << "Invalid capacity!" << endl;
        return 0;
    }

    MyCircularQueue q(k);

    cout << "Enter number of operations: ";
    cin >> n;

    cout << "\nOperations:\n";
    cout << "1. Enqueue\n";
    cout << "2. Dequeue\n";
    cout << "3. Get Front\n";
    cout << "4. Get Rear\n";
    cout << "5. Check Empty\n";
    cout << "6. Check Full\n";

    for (int i = 0; i < n; i++) {
        int choice, value;

        cout << "\nEnter operation: ";
        cin >> choice;

        switch (choice) {
            case 1:
                cout << "Enter value: ";
                cin >> value;

                cout << (q.enQueue(value) ? "Inserted successfully" : "Queue is Full") << endl;
                break;

            case 2:
                cout << (q.deQueue() ? "Deleted successfully" : "Queue is Empty") << endl;
                break;

            case 3:
                cout << "Front: " << q.Front() << endl;
                break;

            case 4:
                cout << "Rear: " << q.Rear() << endl;
                break;

            case 5:
                cout << (q.isEmpty() ? "Queue is Empty" : "Queue is Not Empty") << endl;
                break;

            case 6:
                cout << (q.isFull() ? "Queue is Full" : "Queue is Not Full") << endl;
                break;

            default:
                cout << "Invalid operation!" << endl;
        }
    }

    return 0;
}

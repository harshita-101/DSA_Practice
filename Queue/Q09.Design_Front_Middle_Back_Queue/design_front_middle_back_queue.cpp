
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

        int val;

        if (left.size() == right.size()) {
            val = left.back();
            left.pop_back();
        }
        else {
            val = left.back();
            left.pop_back();
        }

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

int main() {
    FrontMiddleBackQueue q;

    int n;
    cout << "Enter number of operations: ";
    cin >> n;

    while (n--) {
        int op, val;

        cout << "\n1.pushFront  2.pushMiddle  3.pushBack";
        cout << "\n4.popFront   5.popMiddle  6.popBack\n";

        cout << "Enter operation: ";
        cin >> op;

        switch (op) {
            case 1:
                cin >> val;
                q.pushFront(val);
                break;

            case 2:
                cin >> val;
                q.pushMiddle(val);
                break;

            case 3:
                cin >> val;
                q.pushBack(val);
                break;

            case 4:
                cout << q.popFront() << endl;
                break;

            case 5:
                cout << q.popMiddle() << endl;
                break;

            case 6:
                cout << q.popBack() << endl;
                break;

            default:
                cout << "Invalid operation\n";
        }
    }

    return 0;
}
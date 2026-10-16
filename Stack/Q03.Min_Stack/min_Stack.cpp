#include <iostream>
#include <stack>
using namespace std;

class MinStack {
public:
    stack<int> st;
    stack<int> minSt;

    MinStack() {
    }

    void push(int value) {
        st.push(value);

        if (minSt.empty() || value <= minSt.top()) {
            minSt.push(value);
        }
    }

    void pop() {
        if (st.top() == minSt.top()) {
            minSt.pop();
        }

        st.pop();
    }

    int top() {
        return st.top();
    }

    int getMin() {
        return minSt.top();
    }
};

int main() {
    MinStack st;
    int choice, value;

    do {
        cout << "\n1. Push";
        cout << "\n2. Pop";
        cout << "\n3. Top";
        cout << "\n4. Get Minimum";
        cout << "\n5. Exit";
        cout << "\nEnter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1:
                cout << "Enter value: ";
                cin >> value;
                st.push(value);
                cout << "Element pushed successfully." << endl;
                break;

            case 2:
                if (!st.st.empty()) {
                    cout << "Popped element: " << st.top() << endl;
                    st.pop();
                } else {
                    cout << "Stack is empty!" << endl;
                }
                break;

            case 3:
                if (!st.st.empty()) {
                    cout << "Top element: " << st.top() << endl;
                } else {
                    cout << "Stack is empty!" << endl;
                }
                break;

            case 4:
                if (!st.st.empty()) {
                    cout << "Minimum element: " << st.getMin() << endl;
                } else {
                    cout << "Stack is empty!" << endl;
                }
                break;

            case 5:
                cout << "Exiting program..." << endl;
                break;

            default:
                cout << "Invalid choice!" << endl;
        }

    } while (choice != 5);

    return 0;
}
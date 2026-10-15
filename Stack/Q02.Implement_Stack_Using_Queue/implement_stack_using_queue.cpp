
#include <iostream>
#include <queue>
using namespace std;

class MyStack {
public:
    queue<int> q;

    MyStack() {
    }

    void push(int x) {
        q.push(x);

        int n = q.size();

        for (int i = 0; i < n - 1; i++) {
            q.push(q.front());
            q.pop();
        }
    }

    int pop() {
        int temp = q.front();
        q.pop();
        return temp;
    }

    int top() {
        return q.front();
    }

    bool empty() {
        return q.empty();
    }
};

int main() {
    MyStack st;

    st.push(1);
    st.push(2);
    st.push(3);

    cout << "Top element: " << st.top() << endl;

    cout << "Popped element: " << st.pop() << endl;

    cout << "Top element after pop: " << st.top() << endl;

    cout << "Is stack empty? "
         << (st.empty() ? "Yes" : "No") << endl;

    return 0;
}

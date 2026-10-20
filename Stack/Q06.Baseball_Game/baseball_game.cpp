#include <iostream>
#include <stack>
#include <string>
#include <vector>
using namespace std;

int calPoints(vector<string> &operations)
{
    stack<int> st;

    for (string c : operations)
    {
        if (c == "C")
        {
            st.pop();
        }
        else if (c == "D")
        {
            st.push(2 * st.top());
        }
        else if (c == "+")
        {
            int n = st.top();
            st.pop();

            int sum = n + st.top();
            st.push(n);
            st.push(sum);
        }
        else
        {
            st.push(stoi(c));
        }
    }

    int total = 0;
    while (!st.empty())
    {
        total += st.top();
        st.pop();
    }
    return total;
}

int main()
{
    int n;
    cout<<"Enter the number of operations: ";
    cin>>n;

    vector<string> operations(n);
    cout<<"Enter the operations: ";
    for(int i=0; i<n; i++){
        cin>>operations[i];
    }

    cout<<"Total points: "<<calPoints(operations)<<endl;
    return 0;
}
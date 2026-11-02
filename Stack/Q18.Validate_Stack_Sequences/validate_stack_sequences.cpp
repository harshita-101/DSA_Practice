#include <iostream>
#include <vector>
#include <stack>
using namespace std;

bool validateStackSequences(vector<int> &pushed, vector<int> &popped)
{
    stack<int> st;
    int j = 0;

    for (int i = 0; i < pushed.size(); i++)
    {
        st.push(pushed[i]);
        while (!st.empty() && st.top() == popped[j])
        {
            st.pop();
            j++;
        }
    }
    if (st.empty() && j == popped.size())
    {
        return true;
    }
    return false;
}

int main()
{
    int n, m;
    cout << "Enter the size of pushed sequence: ";
    cin >> n;

    vector<int> pushed(n);
    for (int i = 0; i < n; i++)
    {
        cin >> pushed[i];
    }

    cout << "Enter the size of popped sequence: ";
    cin >> m;

    vector<int> popped(m);
    for (int i = 0; i < m; i++)
    {
        cin >> popped[i];
    }

    if (validateStackSequences(pushed, popped))
    {
        cout << "The popped sequence is valid for the given pushed sequence." << endl;
    }
    else
    {
        cout << "The popped sequence is not valid for the given pushed sequence." << endl;
    }

    return 0;
}
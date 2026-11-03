#include <iostream>
#include <stack>
using namespace std;

int minAddToMakeValid(string s)
{
    stack<char> st;

    for (int i = 0; i < s.length(); i++)
    {
        if (!st.empty() && (st.top() == '(' && s[i] == ')'))
        {
            st.pop();
        }
        else
        {
            st.push(s[i]);
        }
    }

    return st.size();
}

int main()
{
    string s;
    cin >> s;

    cout << minAddToMakeValid(s) << endl;

    return 0;
}
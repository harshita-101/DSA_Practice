#include <iostream>
#include <vector>
#include <stack>
#include <string>
using namespace std;

int evalRPN(vector<string>& tokens)
{
    stack<int> st;

    for (const string& c : tokens)
    {
        if (c == "+" || c == "-" || c == "*" || c == "/")
        {
            int b = st.top();
            st.pop();

            int a = st.top();
            st.pop();

            if (c == "+")
                st.push(a + b);
            else if (c == "-")
                st.push(a - b);
            else if (c == "*")
                st.push(a * b);
            else
                st.push(a / b);
        }
        else
        {
            st.push(stoi(c));
        }
    }

    return st.top();
}

int main()
{
    int n;

    cout << "Enter number of tokens: ";
    cin >> n;

    vector<string> tokens(n);

    cout << "Enter tokens separated by spaces: ";
    for (int i = 0; i < n; i++)
    {
        cin >> tokens[i];
    }

    cout << "Result: " << evalRPN(tokens) << endl;

    return 0;
}
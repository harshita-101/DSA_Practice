#include <iostream>
#include <stack>
#include <string>
#include <cctype>
using namespace std;

int calculate(string s)
{
    long long result = 0;
    long long num = 0;
    int sign = 1;

    stack<long long> st;

    for (int i = 0; i < s.size(); i++)
    {
        if (isdigit(s[i]))
        {
            num = num * 10 + (s[i] - '0');
        }
        else if (s[i] == '+')
        {
            result += num * sign;
            num = 0;
            sign = 1;
        }
        else if (s[i] == '-')
        {
            result += num * sign;
            num = 0;
            sign = -1;
        }
        else if (s[i] == '(')
        {
            st.push(result);
            st.push(sign);

            result = 0;
            sign = 1;
        }
        else if (s[i] == ')')
        {
            result += num * sign;
            num = 0;

            long long prevSign = st.top();
            st.pop();

            long long prevResult = st.top();
            st.pop();

            result = prevResult + prevSign * result;
        }
    }

    result += num * sign;

    return (int)result;
}

int main()
{
    string s;

    cout << "Enter the expression: ";
    getline(cin, s);

    cout << "Result: " << calculate(s) << endl;

    return 0;
}

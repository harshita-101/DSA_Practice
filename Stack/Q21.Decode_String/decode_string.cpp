
#include <iostream>
#include <stack>
#include <string>
using namespace std;

string decodeString(string s)
{
    string currstr = "";
    int num = 0;
    stack<pair<string, int>> st;

    for (int i = 0; i < s.length(); i++)
    {

        if (isdigit(s[i]))
        {
            num = num * 10 + (s[i] - '0');
        }

        else if (s[i] == '[')
        {
            st.push({currstr, num});
            currstr = "";
            num = 0;
        }

        else if (s[i] == ']')
        {
            string prevStr = st.top().first;
            int repeat = st.top().second;
            st.pop();

            string temp = "";

            for (int j = 0; j < repeat; j++)
            {
                temp += currstr;
            }

            currstr = prevStr + temp;
        }

        else
        {
            currstr += s[i];
        }
    }

    return currstr;
}

int main()
{
    string s;
    cin >> s;

    cout << decodeString(s) << endl;

    return 0;
}

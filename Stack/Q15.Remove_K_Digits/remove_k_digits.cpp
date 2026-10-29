#include <iostream>
#include <stack>
#include <string>
#include <algorithm>
using namespace std;

string removeKdigits(string num, int k)
{
    stack<char> s;
    string ans = "";

    for (int i = 0; i < num.length(); i++)
    {
        while (s.size() > 0 && s.top() > num[i] && k > 0)
        {
            s.pop();
            k--;
        }
        s.push(num[i]);
    }

    while (k > 0 && !s.empty())
    {
        s.pop();
        k--;
    }

    while (!s.empty())
    {
        ans += s.top();
        s.pop();
    }

    reverse(ans.begin(), ans.end());
    int pos = ans.find_first_not_of('0');
    if (pos == string::npos)
        return "0";

    return ans.substr(pos);
}

int main()
{

    string num;
    cout << "Enter the string: ";
    cin >> num;

    int k;
    cout << "Enter the number of digits to remove: ";
    cin >> k;

    string result = removeKdigits(num, k);
    cout << "The smallest number after removing " << k << " digits is: " << result << endl;

    return 0;
}
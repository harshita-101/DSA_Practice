#include <iostream>
#include <string>
#include <stack>
#include <sstream>
#include<algorithm>
using namespace std;

string makeGood(string s)
{
    stack<char> st;
    string ans = "";
    for (int i = 0; i < s.length(); i++)
    {
        if (st.size() > 0 && abs(s[i] - st.top()) == 32)
        {
            st.pop();
        }
        else
        {
            st.push(s[i]);
        }
    }

    while (!st.empty())
    {
        ans += st.top();
        st.pop();
    }
    reverse(ans.begin(), ans.end());

    return ans;
}

int main(){
    string n;
    cin>>n;

    string result = makeGood(n);
    cout<<result<<endl;

    return 0;
}
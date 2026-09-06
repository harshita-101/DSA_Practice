#include <iostream>
#include <string>
using namespace std;
int romanToInt(string s)
{
    int n = s.length();
    int ans = 0;
    for (int i = 0; i < n; i++)
    {
        int currentVal = value(s[i]);
        if (i < n - 1)
        {
            int nextVal = value(s[i + 1]);
            if (currentVal < nextVal)
            {
                ans = ans - currentVal;
            }
            else
            {
                ans = ans + currentVal;
            }
        }
        else
        {
            ans = ans + currentVal;
        }
    }
    return ans;
}
int value(char c)
{
    switch (c)
    {
    case 'I':
        return 1;

    case 'V':
        return 5;

    case 'X':
        return 10;

    case 'L':
        return 50;

    case 'C':
        return 100;

    case 'D':
        return 500;

    case 'M':
        return 1000;

    default:
        return 0;
    }
}

int main(){
    string s;
    cout<<"Enter the Roman numeral: ";
    cin>>s;
    int result = romanToInt(s);
    cout<<"The integer value is: "<<result<<endl;

    return 0;
}
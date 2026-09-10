#include <iostream>
#include <string>
using namespace std;

int titleToNumber(string columnTitle)
{

    int ans = 0;

    for (int i = 0; i < columnTitle.size(); i++)
    {
        int value = columnTitle[i] - 'A' + 1;
        ans = ans * 26 + value;
    }
    return ans;
}

int main()
{
    string columnTitle;
    cin >> columnTitle;

    cout << titleToNumber(columnTitle) << endl;
    return 0;
}
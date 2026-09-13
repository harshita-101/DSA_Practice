#include <iostream>
using namespace std;

string intToRoman(int num)
{
    string ronum[] = {"M", "CM", "D", "CD", "C", "XC", "L", "XL", "X", "IX", "V", "IV", "I"};
    int romnum[] = {1000, 900, 500, 400, 100, 90, 50, 40, 10, 9, 5, 4, 1};
    string ans = "";
    for (int i = 0; i < 13; i++)
    {
        if (num == 0)
            break;
        int times = num / romnum[i];
        while (times--)
        {
            ans = ans + ronum[i];
        }
        num = num % romnum[i];
    }
    return ans;
}

int main()
{
    int num;
    cout << "Enter the number: ";
    cin >> num;
    cout << "Roman numeral: " << intToRoman(num);
    return 0;
}
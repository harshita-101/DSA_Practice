#include <iostream>
using namespace std;

int fib(int n)
{
    if (n == 0)
        return 0;
    else if (n == 1)
        return 1;
    int a = 0, b = 1;
    for (int i = 2; i <= n; i++)
    {
        int c = a + b;
        a = b;
        b = c;
    }
    return b;
}

int main()
{
    int n;
    cout << "Enter the valude of n: ";
    cin >> n;
    cout << "The " << n << "th Fibonacci number is: " << fib(n) << endl;

    return 0;
}
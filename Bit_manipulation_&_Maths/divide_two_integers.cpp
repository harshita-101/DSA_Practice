#include <iostream>
#include <climits>
using namespace std;

int divide(int dividend, int divisor)
{
    if (dividend == INT_MIN && divisor == -1)
        return INT_MAX;

    long long a = abs((long long)dividend);
    long long b = abs((long long)divisor);

    long long count = 0;

    while (a >= b)
    {
        long long temp = b;
        long long c = 1;

        while (a >= temp + temp)
        {
            temp += temp;
            c += c;
        }

        a = a - temp;
        count += c;
    }

    if ((dividend < 0) != (divisor < 0))
        count = -count;

    return count;
}

int main()
{
    int dividend, divisor;
    cout << "Enter dividend: ";
    cin >> dividend;
    cout << "Enter divisor: ";
    cin >> divisor;

    int result = divide(dividend, divisor);
    cout << "Result of division: " << result << endl;

    return 0;
}
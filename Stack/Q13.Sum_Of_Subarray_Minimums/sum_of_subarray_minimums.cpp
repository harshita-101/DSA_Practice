#include <iostream>
#include <vector>
#include <stack>
using namespace std;

int sumSubarrayMins(vector<int> &arr)
{
    int n = arr.size();
    stack<int> s;
    vector<int> prev(n);
    vector<int> next(n);

    for (int i = 0; i < n; i++)
    {
        while (s.size() > 0 && arr[s.top()] >= arr[i])
        {
            s.pop();
        }
        prev[i] = s.empty() ? -1 : s.top();
        s.push(i);
    }

    while (!s.empty())
    {
        s.pop();
    }

    for (int i = n - 1; i >= 0; i--)
    {
        while (s.size() > 0 && arr[s.top()] > arr[i])
        {
            s.pop();
        }
        next[i] = s.empty() ? n : s.top();
        s.push(i);
    }

    long long sum = 0;
    const int mod = 1e9 + 7;

    for (int i = 0; i < n; i++)
    {
        int left = i - prev[i];
        int right = next[i] - i;
        sum = (sum + (1LL * arr[i] * left * right) % mod) % mod;
    }

    return sum;
}

int main()
{
    int n;
    cout << "Enter array size: ";
    cin >> n;

    vector<int> arr(n);
    cout << "Enter array elements: ";
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }

    cout << "Sum of Subarray Minimums: " << sumSubarrayMins(arr) << endl;

    return 0;
}
#include <iostream>
#include <vector>
#include <stack>
using namespace std;

vector<int> finalPrices(vector<int> &prices)
{
    int n = prices.size();
    stack<int> st;
    vector<int> ans = prices;

    for (int i = 0; i < n; i++)
    {
        while (!st.empty() && prices[st.top()] >= prices[i])
        {
            ans[st.top()] = prices[st.top()] - prices[i];
            st.pop();
        }
        st.push(i);
    }

    return ans;
}

int main()
{
    int n;
    cout << "Enter the size of the array: ";
    cin >> n;

    vector<int> prices(n);
    cout << "Enter the elements of the array: ";
    for (int i = 0; i < n; i++)
    {
        cin >> prices[i];
    }

    vector<int> result = finalPrices(prices);
    cout << "Final prices after discount: ";
    for (int val : result)
    {
        cout << val << " ";
    }

    return 0;
}
#include <iostream>
#include <vector>
#include <stack>
using namespace std;

long long subArrayRanges(vector<int> &nums)
{
    int n = nums.size();
    stack<int> s;
    long long maxSum = 0;
    long long minSum = 0;

    for (int i = 0; i <= n; i++)
    {
        while (s.size() > 0 && (i == n || nums[i] >= nums[s.top()]))
        {
            int index = s.top();
            s.pop();
            int prevGreater = s.empty() ? -1 : s.top();
            int left = index - prevGreater;
            int right = i - index;
            maxSum += 1LL * nums[index] * left * right;
        }

        if (i < n)
        {
            s.push(i);
        }
    }

    while (!s.empty())
    {
        s.pop();
    }

    for (int i = 0; i <= n; i++)
    {
        while (s.size() > 0 && (i == n || nums[i] <= nums[s.top()]))
        {
            int index = s.top();
            s.pop();
            int prevGreater = s.empty() ? -1 : s.top();
            int left = index - prevGreater;
            int right = i - index;
            minSum += 1LL * nums[index] * left * right;
        }

        if (i < n)
        {
            s.push(i);
        }
    }
    return maxSum - minSum;
}

int main(){
    int n;
    cout<<"Enter the size of the array: ";
    cin>>n;

    vector<int> nums(n);
    cout<<"Enter the elements of the array: ";
    for(int i=0; i<n; i++){
        cin>>nums[i];
    }
    cout<<"The sum of subarray ranges is: "<<subArrayRanges(nums)<<endl;

    return 0;
}
#include<iostream>
#include<vector>
#include<deque>
#include<algorithm>
using namespace std;

long long continuousSubarrays(vector<int>& nums) {
    int left = 0;
    long long ans = 0;

    deque<int> maxDeque;
    deque<int> minDeque;

    for (int right = 0; right < nums.size(); right++) {

        while (!maxDeque.empty() && nums[maxDeque.back()] <= nums[right]) {
            maxDeque.pop_back();
        }
        maxDeque.push_back(right);

        while (!minDeque.empty() && nums[minDeque.back()] >= nums[right]) {
            minDeque.pop_back();
        }
        minDeque.push_back(right);

        while (!maxDeque.empty() && !minDeque.empty() &&
               nums[maxDeque.front()] - nums[minDeque.front()] > 2) {

            if (maxDeque.front() == left) {
                maxDeque.pop_front();
            }

            if (minDeque.front() == left) {
                minDeque.pop_front();
            }

            left++;
        }

        ans += right - left + 1;
    }

    return ans;
}

int main() {
    int n;

    cout << "Enter array size: ";
    cin >> n;

    vector<int> nums(n);

    cout << "Enter array elements: ";
    for (int i = 0; i < n; i++) {
        cin >> nums[i];
    }

    cout << "Total valid subarrays: "
         << continuousSubarrays(nums) << endl;

    return 0;
}
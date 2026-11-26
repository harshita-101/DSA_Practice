#include <iostream>
#include <vector>
#include <deque>
using namespace std;

vector<int> maxSlidingWindow(vector<int>& nums, int k) {
    int n = nums.size();
    vector<int> ans;
    deque<int> dq;

    for(int i = 0; i < n; i++) {

        // Remove outdated index
        if(!dq.empty() && dq.front() <= i-k) {
            dq.pop_front();
        }

        // Maintain decreasing order
        while(!dq.empty() && nums[dq.back()] <= nums[i]) {
            dq.pop_back();
        }

        dq.push_back(i);

        // Store maximum of current window
        if(i >= k-1) {
            ans.push_back(nums[dq.front()]);
        }
    }

    return ans;
}

int main() {
    int n, k;

    cout << "Enter array size: ";
    cin >> n;

    vector<int> nums(n);

    cout << "Enter array elements: ";
    for(int i = 0; i < n; i++) {
        cin >> nums[i];
    }

    cout << "Enter window size: ";
    cin >> k;

    if(k <= 0 || k > n) {
        cout << "Invalid window size";
        return 0;
    }

    vector<int> result = maxSlidingWindow(nums, k);

    cout << "Maximum elements in each window: ";
    for(int x : result) {
        cout << x << " ";
    }

    return 0;
}


#include <iostream>
#include <vector>
#include <deque>
#include <algorithm>
#include <climits>
using namespace std;

int shortestSubarray(vector<int>& nums, int k) {
    vector<long long> prefix(nums.size() + 1);
    deque<int> dq;
    int ans = INT_MAX;

    // Step 1: Build Prefix Sum
    for (int i = 0; i < nums.size(); i++) {
        prefix[i + 1] = prefix[i] + nums[i];
    }

    // Step 2: Find Shortest Subarray
    for (int i = 0; i < prefix.size(); i++) {

        // Condition 1: Check valid subarray
        while (!dq.empty() && 
               prefix[i] - prefix[dq.front()] >= k) {

            ans = min(ans, i - dq.front());
            dq.pop_front();
        }

        // Condition 2: Maintain increasing prefix sums
        while (!dq.empty() && 
               prefix[dq.back()] >= prefix[i]) {

            dq.pop_back();
        }

        // Add current index
        dq.push_back(i);
    }

    return ans == INT_MAX ? -1 : ans;
}

int main() {
    int n, k;

    cout << "Enter array size: ";
    cin >> n;

    vector<int> nums(n);

    cout << "Enter array elements: ";
    for (int i = 0; i < n; i++) {
        cin >> nums[i];
    }

    cout << "Enter target sum k: ";
    cin >> k;

    cout << "Shortest subarray length: "
         << shortestSubarray(nums, k) << endl;

    return 0;
}

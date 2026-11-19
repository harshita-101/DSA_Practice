#include<iostream>
#include<vector>
#include<deque>
#include<algorithm>
using namespace std;

class Solution {
public:
    int longestSubarray(vector<int>& nums, int limit) {
        int left = 0;
        int ans = 0;
        deque<int> maxDeque;
        deque<int> minDeque;

        for (int right = 0; right < nums.size(); right++){
            while (!maxDeque.empty() && nums[maxDeque.back()] <= nums[right]) {
                maxDeque.pop_back();
            }

            maxDeque.push_back(right);

            while (!minDeque.empty() && nums[minDeque.back()] >= nums[right]) {
                minDeque.pop_back();
            }

            minDeque.push_back(right);

            while (!maxDeque.empty() && !minDeque.empty() && nums[maxDeque.front()] - nums[minDeque.front()] > limit) {

                if (maxDeque.front() == left) {
                    maxDeque.pop_front();
                }

                if (minDeque.front() == left) {
                    minDeque.pop_front();
                }

                left++;
            }

            ans = max(ans, right - left + 1);
        }
        return ans;
    }
};

int main() {
    Solution s;

    int n, limit;

    cout << "Enter array size: ";
    cin >> n;

    vector<int> nums(n);

    cout << "Enter array elements: ";
    for (int i = 0; i < n; i++) {
        cin >> nums[i];
    }

    cout << "Enter limit: ";
    cin >> limit;

    int result = s.longestSubarray(nums, limit);

    cout << "Longest valid subarray length: " << result << endl;

    return 0;
}
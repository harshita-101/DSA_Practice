
#include <iostream>
#include <vector>
using namespace std;

vector<int> productExceptSelf(vector<int>& nums) {
    int n = nums.size();

    vector<int> ans(n, 1);

    int prefix = 1;

    for (int i = 0; i < n; i++) {
        ans[i] = prefix;
        prefix *= nums[i];
    }

    int suffix = 1;

    for (int i = n - 1; i >= 0; i--) {
        ans[i] *= suffix;
        suffix *= nums[i];
    }

    return ans;
}

int main() {
    vector<int> nums = {1, 2, 3, 4};

    vector<int> ans = productExceptSelf(nums);

    for (int x : ans) {
        cout << x << " ";
    }

    return 0;
}

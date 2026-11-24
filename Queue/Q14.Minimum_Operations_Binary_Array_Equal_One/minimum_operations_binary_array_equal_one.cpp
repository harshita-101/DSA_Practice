
#include <iostream>
#include <vector>
using namespace std;

int minOperations(vector<int>& nums) {
    int count = 0;
    int n = nums.size();

    for (int i = 0; i < n; i++) {
        if (nums[i] == 0) {
            if (i + 2 < n) {
                nums[i] = !nums[i];
                nums[i + 1] = !nums[i + 1];
                nums[i + 2] = !nums[i + 2];

                count++;
            }
            else {
                return -1;
            }
        }
    }

    return count;
}

int main() {
    int n;

    cout << "Enter array size: ";
    cin >> n;

    vector<int> nums(n);

    cout << "Enter binary array elements: ";
    for (int i = 0; i < n; i++) {
        cin >> nums[i];
    }

    cout << "Minimum operations: " << minOperations(nums) << endl;

    return 0;
}

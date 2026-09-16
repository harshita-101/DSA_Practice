#include<iostream>
#include<vector>
#include<unordered_set>
using namespace std;

int findMissingPositive(vector<int>& nums) {
    unordered_set<int> s(nums.begin(), nums.end());
    int missing = 1;
    while (s.count(missing)) {
        missing++;
    }
    return missing;
}

int main(){
    int n;
    cout<<"Enter the number of elements in the array: ";
    cin>>n;

    vector<int> nums(n);
    cout<<"Enter the elements of the array: ";
    for(int i=0; i<n; i++){
        cin>>nums[i];
    }
    int missing = findMissingPositive(nums);
    cout<<"The smallest missing positive integer is: "<<missing<<endl;
    return 0;
}
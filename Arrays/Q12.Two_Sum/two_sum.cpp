#include<iostream>
#include<vector>
#include <unordered_map>
using namespace std;

vector<int> twoSum(vector<int> &nums, int target){
    unordered_map<int , int> mp;
    int n = nums.size();

    for(int i=0; i<n; i++){
        int diff = target - nums[i];
        if(mp.find(diff) != mp.end()){
            return {mp[diff], i};
        }
        mp[nums[i]] = i;
    }
    return {-1, -1};
}

int main(){
    int n, target;
    cout<<"Enter the size of the array: ";
    cin>>n;
    vector<int> nums(n);
    cout<<"Enter the elements of the array: ";
    for(int i=0; i<n; i++){
        cin>>nums[i];
    }
    cout<<"Enter the target value: ";
    cin>>target;
    vector<int> result = twoSum(nums, target);
    if(result[0] != -1){
        cout<<"The indices of the target number in the array are: "<<result[0]<<" and "<<result[1]<<endl;
    }
    else{
        cout<<"No two sum solution found."<<endl;
    }
    return 0;
}
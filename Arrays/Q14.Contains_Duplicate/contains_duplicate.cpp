#include<iostream>
#include<vector>
#include<unordered_set>
using namespace std;

bool containsDuplicate(vector<int>& nums) {
    unordered_set<int> s;

    for(int i =0; i< nums.size(); i++){
        if(s.find(nums[i]) != s.end()){
            return true;
        }
        else{
            s.insert(nums[i]);
        }
    }
    return false;
}

int main()
{
    int n;
    cout<<"Enter the size of the array: ";
    cin>>n;
    vector<int> nums(n);
    cout<<"Enter the elements of the array: ";
    for(int i=0; i<n; i++){
        cin>>nums[i];
    }
    if(containsDuplicate(nums)){
        cout<<"The array contains duplicate elements."<<endl;
    }
    else{
        cout<<"The array does not contain duplicate elements."<<endl;
    }
    return 0;
}
#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

int splitArray(vector<int>& nums, int k) {
    int n = nums.size();
    int low = *max_element(nums.begin(), nums.end());
    int high = 0;
    for(int i=0; i<n; i++){
        high+= nums[i];
    }

    while(low <= high){
        int mid = low + (high - low)/2;
        int currentSum = 0;
        int subarrays = 1;

        for(int i=0; i<n; i++){
            if(currentSum + nums[i] <= mid){
                currentSum += nums[i];
            }
            else{
                subarrays++;
                currentSum = nums[i];
            }
        }
        if(subarrays <= k){
            high = mid - 1;
        }
        else{
            low = mid + 1;
        }
    }
    return low;
}

int main(){
    int n,k;
    cout<<"Enter the size of the array: ";
    cin>>n;

    vector<int> nums(n);
    cout<<"Enter the values of array: ";
    for(int i=0; i<n; i++){
        cin>>nums[i];
    }

    cout<<"Enter the value of k : ";
    cin>>k;

    int result = splitArray(nums, k);
    cout<<result;

    return 0;
}
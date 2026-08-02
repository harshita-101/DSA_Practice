#include<iostream>
#include<vector>
using namespace std;

int searchInsert(vector<int>& nums, int target) {
    int n=nums.size();
    int l=0;
    int r=n-1;
    while(l<=r){
        int mid= l+(r-l)/2;

        if(nums[mid]==target)
        return mid;
        else if(nums[mid]<target)
        l=mid+1;
        else
        r=mid-1; 
    }
    return l;
}

int main(){
    int n,target;
    cout<<"Enter the size of array: ";
    cin>>n;
    
    // sorted array
    vector<int> arr(n);
    cout<<"Enter the elements of array: ";
    for(int i=0; i<n; i++){
        cin>>arr[i];
    }
    cout<<"Enter the target value: ";
    cin>>target;

    int value = searchInsert(arr,target);

    cout<<"Insert Position: "<<value<<endl;
    return 0;
}
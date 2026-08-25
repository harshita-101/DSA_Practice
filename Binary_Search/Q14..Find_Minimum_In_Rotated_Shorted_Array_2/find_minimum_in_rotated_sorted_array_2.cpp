#include<iostream>
#include<vector>
#include<climits>
using namespace std;

int findMin(vector<int>& nums) {
    int low =0;
    int high = nums.size()-1;

    while (low < high) {
        int mid = low + (high - low) / 2;

        if (nums[mid] < nums[high])
            high = mid;
        else if (nums[mid] > nums[high])
            low = mid + 1;
        else
            high--;
    }
    return nums[low];
}

int main(){
    int n;
    cout<<"Enter the size of array: ";
    cin>>n;

    vector<int> arr(n);
    cout<<"Enter the elements of the array: "<<endl;
    for(int i=0; i<n; i++){
        cin>>arr[i];
    }

    cout<<findMin(arr)<<endl;

    return 0;
}
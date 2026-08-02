#include<iostream>
#include<vector>
using namespace std;

int firstOccurence(vector<int> &arr, int target){
    int low = 0;
    int high = arr.size() - 1;
    int ans = -1;

    while(low<=high){
        int mid = low + (high - low) / 2;
        if(arr[mid] == target)
        {
            ans = mid;
            high = mid - 1;
        }
        else if(arr[mid] < target)
        {
            low = mid + 1;
        }
        else
        {
            high = mid - 1;
        }
    }
    return ans;
}

int lastOccurence(vector<int> &arr, int target){
    int low = 0;
    int high = arr.size() - 1;
    int ans = -1;

    while(low<=high){
        int mid = low + (high - low) / 2;
        if(arr[mid] == target)
        {
            ans = mid;
            low = mid + 1;
        }
        else if(arr[mid] < target)
        {
            low = mid + 1;
        }
        else
        {
            high = mid - 1;
        }
    }
    return ans;
}

int main(){
    int n,target;
    cout<<"Enter the size of array: ";
    cin>>n;
    vector<int> arr(n);
    cout<<"Enter the elements of array: ";
    for(int i=0; i<n; i++){
        cin>>arr[i];
    }
    cout<<"Enter the value of target: ";
    cin>>target;
    cout<<"["<<firstOccurence(arr,target)<<","<<lastOccurence(arr,target)<<"]";
    return 0;
}
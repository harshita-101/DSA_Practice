#include<iostream>
#include<vector>
using namespace std;

int search(vector<int> &arr, int target){
    int n = arr.size();
    int low =0;
    int high = n-1;

    while(low<=high){
        int mid = low + (high - low)/2;
        if(arr[mid]==target){
            return mid;
        }
        if(arr[low]<= arr[mid]){
            if(arr[low] <= target && target < arr[mid]){
                high = mid-1;
            }
            else{
                low = mid+1;
            }
        }
        else{
            if(arr[mid] < target && target <= arr[high]){
                low = mid+1;
            }
            else{
                high = mid-1;
            }
        }

    }

    return -1;
}

int main(){
    int n, target;
    cout<<"Enter the size of the array: ";
    cin>>n;

    vector<int> arr(n);
    cout<<"Enter the elements of array: "<<endl;
    for(int i=0; i<n; i++){
        cin>>arr[i];
    }

    cout<<"Enter the value of target: ";
    cin>>target;

    cout<<search(arr,target)<<endl;
    return 0;
}
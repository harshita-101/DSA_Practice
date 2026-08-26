#include<iostream>
#include<vector>
using namespace std;

int findKthPositive(vector<int>& arr, int k) {
    int n = arr.size();
    int low = 0, high = n-1;
    int missing = 0;

    while(low <= high){
        int mid = low + (high - low) /2;
        missing = arr[mid] - (mid+1);
        if(missing < k){
            low = mid +1;
        }
        else{
            high = mid -1;
        }
    }
    return low + k;
}

int main(){
    int n, k;
    cout<<"Enter the size of the array: ";
    cin>>n;
    vector<int> arr(n);
    cout<<"Enter the elements of the array: ";
    for(int i=0; i<n; i++){
        cin>>arr[i];
    }
    cout<<"Enter the value of k: ";
    cin>>k;
    int result = findKthPositive(arr, k);
    cout<<"The "<<k<<"th missing positive number is: "<<result<<endl;
    return 0;
}
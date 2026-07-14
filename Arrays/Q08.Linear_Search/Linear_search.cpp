#include<iostream>
#include<vector>
using namespace std;

int LinearSearch(vector<int> &arr, int target){
    int n = arr.size();

    for(int i=0; i<n; i++){
        if(arr[i] == target){
            return i;
        }
    }
    return -1;
}

int main(){
    int n, target;
    cout<<"Enter the size of array: ";
    cin>>n;
    vector<int> arr(n);
    for(int i=0; i<n; i++){
        cin>>arr[i];
    }
    cout<<"Enter the target element to find: ";
    cin>>target;
    int result = LinearSearch(arr, target);
    if(result != -1){
        cout<<"Element found at index: "<<result<<endl;
    }
    else{
        cout<<"Element is not found in the array."<<endl;
    }
    return 0;
}
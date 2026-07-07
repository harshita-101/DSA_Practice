#include<iostream>
#include<vector>
using namespace std;

bool is_sorted(vector<int> &arr){
    int n = arr.size();
    for(int i=0; i<n-1; i++){
        if(arr[i]>arr[i+1]){
            return false;
        }
    }
    return true;
}

int main(){
    int n;
    cout<<"Enter size of array: ";
    cin>>n;
    vector<int> arr(n);
    for(int i=0; i<n; i++){
        cin>>arr[i];
    }
    bool ans = is_sorted(arr);
    if(ans){
        cout<<"Array is sorted";
    }
    else{
        cout<<"Array is not sorted";
    }
    return 0;
}
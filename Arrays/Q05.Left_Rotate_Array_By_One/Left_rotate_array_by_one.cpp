#include<iostream>
#include<vector>
using namespace std;

void left_rotate_by_one(vector<int>& arr){
    int n = arr.size();
    int temp = arr[0];
    for(int i=0; i<n-1; i++){
        arr[i] = arr[i+1];

    }
    arr[n-1] = temp;
}

int main(){
    int n;
    cin >> n;
    vector<int> arr(n);
    for(int i=0; i<n; i++){
        cin>>arr[i];
    }
    left_rotate_by_one(arr);
    for(int i=0; i<n; i++){
        cout<<arr[i]<<" ";
    }
    return 0;
}


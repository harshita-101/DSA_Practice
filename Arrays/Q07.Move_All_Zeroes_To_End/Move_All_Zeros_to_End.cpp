#include<iostream>
#include<vector>
using namespace std;

void moveZeros(vector<int> &arr){
    int n = arr.size();
    int j=0;
    for(int i=0; i<n; i++){
        if(arr[i] != 0){
            arr[j] = arr[i];
            j++;
        }
    }
    for(int i=j; i<n; i++){
        arr[i] =0;
    }
}

int main(){
    int n;
    cout<<"Enter the size of array: ";
    cin>>n;
    vector<int> arr(n);
    cout<<"Enter the elements of array: ";
    for(int i=0; i<n; i++){
        cin>>arr[i];
    }
    moveZeros(arr);
    cout<<"Array after moving zeros to the end: ";
    for(int i=0; i<n; i++){
        cout<<arr[i]<<" ";
    }
    return 0;
}
#include<iostream>
#include<vector>
using namespace std;

void leftRotate(vector<int> &arr,  int d){ 
    int n = arr.size();
    if(n==0) return; // check for empty array
    if(d==0) return; // check for zero rotation

    d = d%n;                      // In case d is greater than n
    vector<int> temp(arr.begin(), arr.begin() + d);

    for(int i= d; i<n; i++){
        arr[i-d] = arr[i];
    }
    int j=0;
    for(int i= n-d; i<n; i++){
        arr[i] = temp[j];
        j++;
    }
    return;
}

int main(){
    int n, d;
    cout<<"Enter the size of array: ";
    cin>>n;
    vector<int> arr(n);
    cout<<"Enter the elements of array: ";
    for(int i=0; i<n; i++){
        cin>>arr[i];
    }
    cout<<"Enter the number of places to rotate: ";
    cin>>d;
    leftRotate(arr,d);
    cout<<"Array after left Rotation: ";
    for(int i=0; i<n; i++){
        cout<<arr[i]<<" ";
    }
    cout<<endl;
    return 0;
}
#include<iostream>
#include<vector>
using namespace std;

int find_duplicate(vector<int> &arr){
    int n = arr.size();
    int i=0;
    for(int j=1; j<n; j++){
        if(arr[i] !=arr[j]){
            i++;
            arr[i] = arr[j];
        }
    }
    return i+1;
}

int main(){
    int n;
    cout<<"Enter the size of array1: ";
    cin>>n;
    vector<int> arr(n);
    for(int i=0; i<n; i++){
        cin>>arr[i];
    }
    int ans = find_duplicate(arr);
    cout<<"Size of array after removing duplicates: "<<ans<<endl;
    return 0;
}
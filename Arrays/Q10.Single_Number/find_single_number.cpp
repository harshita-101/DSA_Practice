#include<iostream>
#include<vector>
using namespace std;

int findSingleNumber(vector<int> &arr){
    int n = arr.size();
    int ans =0;
    for(int i=0; i<n; i++){
        ans = ans ^ arr[i];
    }
    return ans;
}
int main(){
    int n;
    cout<<"Enter the number of elements:";
    cin>>n;

    vector<int> arr(n);
    cout<<"Enter numbers:";

    for(int i=0; i<n; i++){
        cin>>arr[i];
    }

    int ans = findSingleNumber(arr);
    cout<<"Unique value is: "<<ans;
    return 0;
}
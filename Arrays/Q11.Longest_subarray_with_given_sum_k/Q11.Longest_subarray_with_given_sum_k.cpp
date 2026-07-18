#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

int LongestSubarraywithSum(vector<int> &arr, int k){
    int n = arr.size();
    int maxLength =0;
    int sum =0;
    int l=0;
    for(int r=0; r<n; r++){
        sum += arr[r];
        while(sum>k){
            sum -= arr[l];
            l++;
        }
        if(sum == k)
        {
            maxLength = max(maxLength, r - l + 1);
        }
   }
    return maxLength;
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
    int k;
    cout<<"Enter the value of k: ";
    cin>>k;
    int Length = LongestSubarraywithSum(arr, k);
    cout<<"The length of Longest Subarray with sum "<<k<<" is: "<<Length<<endl;
    return 0;
}
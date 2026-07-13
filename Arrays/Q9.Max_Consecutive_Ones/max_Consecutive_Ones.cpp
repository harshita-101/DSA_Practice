#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

int maxConsecutiveOnes(vector<int> &arr){
    int n = arr.size();
    int count =0;
    int maxCount =0;
    for(int i=0; i<n; i++){
        if(arr[i] == 1){
            count++;
            maxCount = max(maxCount, count);
        }
        else{
            count = 0;
        }
    }
    return maxCount;
}

int main(){
    int n;
    cout<<"Enter the size of array: ";
    cin>>n;
    vector<int> arr(n);
    cout<<"Enter the elements of array: "<<endl;
    for(int i=0; i<n; i++){
        cin>>arr[i];
    }
    int result = maxConsecutiveOnes(arr);
    cout<<"Maximum number of consecutive 1's: "<<result<<endl;

    return 0;
}
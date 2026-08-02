#include<iostream>
#include<vector>
using namespace std;

int findMin(vector<int> &arr){
    int low =0;
    int high = arr.size()-1;
    int ans = INT_MAX;

    while(low <= high){
        int mid = low + (high-low)/2;
        if(arr[low] <= arr[high]){
            ans = arr[low];
            break;
        }
        if(arr[low] <= arr[mid]){
            ans = min(ans, arr[low]);
            low = mid + 1;
        }
        else{
            ans = min(ans, arr[mid]);
            high = mid - 1;
        }
    }
    return ans;

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
    
    cout<<findMin(arr)<<endl;
    return 0;
}
#include<iostream>
#include<vector>
using namespace std;

int rotationCount(vector<int> &arr) {
    int low = 0;
    int high = arr.size() - 1;
    int ans = 0;

    while (low <= high) {
        int mid = low + (high - low) / 2;

        if (arr[low] <= arr[high]) {
            if (arr[low] < arr[ans])
                ans = low;
            break;
        }

        if (arr[low] <= arr[mid]) {
            if (arr[low] < arr[ans])
                ans = low;
            low = mid + 1;
        }
        else {
            if (arr[mid] < arr[ans])
                ans = mid;
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
    
    cout<<rotationCount(arr)<<endl;
    return 0;
}
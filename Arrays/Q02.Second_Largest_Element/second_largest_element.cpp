#include<iostream>
#include <climits>
using namespace std;

int second_largest_element(int arr[], int n){
    int largest = arr[0];
    int second_largest = INT_MIN;
    bool found = false;
    for(int i=1; i<n; i++){
        if(arr[i] < largest && arr[i] > second_largest){
            second_largest = arr[i];
            found = true;
        }
        else if(arr[i]> largest){
            second_largest = largest;
            largest = arr[i];
            found = true;
        }
        
    }
    if(!found){
        return -1;
    }
    return second_largest;
}
int main(){
    int n;
    cout<<"Enter size of array: ";
    cin>>n;
    if(n<2){
        cout<<"Array should have atleast 2 elements";
        return 0;
    }
    int arr[n];
    for(int i=0; i<n; i++){
        cin>>arr[i];
    }
    int ans = second_largest_element(arr,n);
    cout<<"Second largest element in array is: "<<ans;
    return 0;
}
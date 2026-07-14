#include<iostream>
using namespace std;

int largest_element(int arr[], int n){
    int max = arr[0];
    for(int i=0; i<n;  i++){
        if(arr[i] > max){
            max  = arr[i];
        }
    }
    return max;
}
int main(){
    int n;
    cout<<"Enter size of array: ";
    cin>>n;
    int arr[n];
    cout<<"Enter elemnets of array: ";
    for(int i=0; i<n; i++){
        cin>>arr[i];
    }
    int ans = largest_element(arr,n);
    cout<<"Largest element in array is : "<<ans;
    return 0;
}
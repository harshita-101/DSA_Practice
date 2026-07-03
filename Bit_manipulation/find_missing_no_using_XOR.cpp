#include<iostream>
using namespace std;

int main(){

    int n, ans=0;
    cout<<"Enter the size of array: ";
    cin >> n;
    int arr[n];
    for(int i = 0; i < n; i++){
        cin >> arr[i];
        ans ^= arr[i];
    }
    for(int i=0; i<=n; i++){
        ans ^= i;
    }
    cout << ans << endl;
    return 0;
}
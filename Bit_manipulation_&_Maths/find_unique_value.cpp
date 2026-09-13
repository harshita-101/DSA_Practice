#include<iostream>
using namespace std;

int main(){
    int arr[5], ans =0;
    cout<<"Enter numbers:";

    for(int i=0; i<5; i++){
        cin>>arr[i];
        ans = ans ^ arr[i];
    }
    cout<<"Unique value is: "<<ans;
    return 0;
}
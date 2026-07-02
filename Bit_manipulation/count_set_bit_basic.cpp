#include<iostream>
using namespace std;

int main(){
    int num, count =0;
    cout<<"Enter a number: ";
    cin>>num;
    while(num!=0){
        if(num & 1){
            count++;
        }
        num = num>>1;
    }
    cout<<"Number of set bits: "<<count;
    return 0;
}
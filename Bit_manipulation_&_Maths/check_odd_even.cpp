#include<iostream>
using namespace std;

int main()
{
    int num;
    cout<<"Enter a number: ";
    cin>>num;
    if(num & (1<<0)){
        cout<<"Odd number";
    }
    else{
        cout<<"Even number";
    }
    return 0;
}
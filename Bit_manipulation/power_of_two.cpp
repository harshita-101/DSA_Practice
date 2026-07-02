#include<iostream>
using namespace std;

int main()
{
    int num;
    cout<<"Enter a number: ";
    cin>>num;
    if((num & (num-1)) == 0 && num != 0){
        cout<<"Power of two";
    }
    else{
        cout<<"Not a power of two";
    }
    return 0;
}
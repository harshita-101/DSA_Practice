#include<iostream>
using namespace std;

int main() {
    int value, n, i;
    cin>>n>>i>>value;
    if(value == 1){
        n = n | (1<<i);
    }
    else{
        n = n & (~(1<<i));
    }
    cout<<n;
    return 0;
}
#include<iostream>
#include<vector>
using namespace std;

bool isPerfectSquare(int num) {
    long long low = 0;
    long long high = num;

    while(low <= high){
        long long mid = low + (high - low) / 2;

        if(mid * mid == num){
            return true;
        }
        else if(mid * mid < num){
            low = mid + 1;
        }
        else{
            high = mid -1;
        }
    }
    return false;
}

int main(){
    int num;
    cout<<"Enter a number: ";
    cin>>num;

    if(isPerfectSquare(num)){
        cout<<num<<" is a Perfect Square."<<endl;
    }
    else{
        cout<<num<<" is not a Perfect Square."<<endl;
    }
    return 0;
}
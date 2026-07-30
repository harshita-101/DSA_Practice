#include<iostream>
#include<vector>
using namespace std;

int mySqrt(int x) {
    if (x == 0 || x == 1)
        return x;

    int low = 1;
    int high = x;
    int ans = 0;

    while (low <= high) {
        long long mid = low + (high - low) / 2;
        long long square = mid * mid;

        if (square == x) {
            return mid;
        }
        else if (square < x) {
            ans = mid;          // Possible answer
            low = mid + 1;
        }
        else {
            high = mid - 1;
        }
    }

    return ans;
}

int main(){
    int x;
    cout<<"Enter the value of x: ";
    cin>>x;
    
    cout<<mySqrt(x)<<endl;
    return 0;
}
#include <iostream>
using namespace std;

int main() {
    int n, i;
    // cout<<"Enter a number and i: ";
    cin >> n >> i;

    if (n & (1 << i))
        cout << "Bit is set";
    else
        cout << "Bit is not set";

    return 0;
}
#include<iostream>
using namespace std;

class DataStream {
    int value;
    int k;
    int count;
public:
    DataStream(int value, int k) {
        this->value = value;
        this->k = k;
        count = 0;
    }
    
    bool consec(int num) {
        if(num == value){
            count++;
        }
        else{
            count = 0;
        }
        return count >= k;
    }
};

int main() {
    int value, k, n;

    cout << "Enter value: ";
    cin >> value;

    cout << "Enter k: ";
    cin >> k;

    DataStream ds(value, k);

    cout << "Enter number of calls: ";
    cin >> n;

    cout << boolalpha;

    for (int i = 0; i < n; i++) {
        int num;

        cout << "Enter number: ";
        cin >> num;

        cout << ds.consec(num) << endl;
    }

    return 0;
}
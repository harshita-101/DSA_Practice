#include<iostream>
#include<stack>
using namespace std;

class StockSpanner {
    stack<pair<int, int>> st;
public:
    StockSpanner() {
        
    }
    
    int next(int price) {
        int span = 1;

        while (!st.empty() && st.top().first <= price) {
            span += st.top().second;
            st.pop();
        }

        st.push({price, span});

        return span;
    }
};

int main() {
    StockSpanner stock;

    int n;
    cout << "Enter the number of days: ";
    cin >> n;

    cout << "Enter the stock prices: ";

    for (int i = 0; i < n; i++) {
        int price;
        cin >> price;

        cout << stock.next(price) << " ";
    }

    cout << endl;

    return 0;
}
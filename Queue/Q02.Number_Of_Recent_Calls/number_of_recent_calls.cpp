#include<iostream>
#include<queue>
using namespace std;

queue<int> q;

int ping(int t) {
    q.push(t);

    while(!q.empty() && q.front() < t - 3000) {
        q.pop();
    }

    return q.size();
}

int main() {
    int n, t;

    cout << "Enter number of requests: ";
    cin >> n;

    cout << "Enter timestamps: ";

    for(int i = 0; i < n; i++) {
        cin >> t;

        cout << ping(t) << endl;
    }

    return 0;
}
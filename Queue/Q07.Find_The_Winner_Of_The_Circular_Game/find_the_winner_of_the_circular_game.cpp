#include <iostream>
#include <queue>
using namespace std;

int findTheWinner(int n, int k)
{
    queue<int> q;

    for (int i = 1; i <= n; i++)
    {
        q.push(i);
    }

    while (q.size() > 1)
    {
        for (int i = 0; i < k - 1; i++)
        {
            int temp = q.front();
            q.pop();
            q.push(temp);
        }
        q.pop();
    }

    return q.front();
}

int main()
{
    int n, k;
    cout<<"Enter the number of players (n): ";
    cin>>n;
    cout<<"Enter the step count (k): ";
    cin>>k;

    int winner = findTheWinner(n, k);
    cout<<"The winner is the player at position: "<<winner<<endl;

    return 0;
}
#include <iostream>
#include <queue>
#include<vector>
using namespace std;

int timeRequiredToBuy(vector<int> &tickets, int k)
{
    queue<int> q;
    int time = 0;

    for (int i = 0; i < tickets.size(); i++)
    {
        q.push(i);
    }

    while (tickets[k] > 0)
    {
        int i = q.front();
        q.pop();
        tickets[i]--;
        time++;

        if (tickets[i] > 0)
        {
            q.push(i);
        }
    }
    return time;
}

int main(){
    int n;
    cout<<"Enter the size of the tickets array: ";
    cin>>n;
    vector<int> tickets(n);
    cout<<"Enter the elements of the tickets array: ";
    for(int i=0; i<n; i++){
        cin>>tickets[i];
    }
    int k;
    cout<<"Enter the index of the person: ";
    cin>>k;

    int result = timeRequiredToBuy(tickets, k);
    cout<<"Time needed to buy tickets: "<<result<<endl;

    return 0;
}
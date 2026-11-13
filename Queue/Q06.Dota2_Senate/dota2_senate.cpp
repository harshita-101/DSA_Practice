#include <iostream>
#include <string>
#include <queue>
using namespace std;

string predictPartyVictory(string senate)
{
    queue<int> radiant;
    queue<int> dire;
    int n = senate.length();

    for (int i = 0; i < n; i++)
    {
        if (senate[i] == 'R')
        {
            radiant.push(i);
        }
        else
        {
            dire.push(i);
        }
    }

    while (!radiant.empty() && !dire.empty())
    {
        int r = radiant.front();
        int d = dire.front();

        radiant.pop();
        dire.pop();

        if (r < d)
        {
            radiant.push(r + n);
        }
        else
        {
            dire.push(d + n);
        }
    }

    return radiant.empty() ? "Dire" : "Radiant";
}

int main()
{
    string senate;
    cout<<"Enter the senate string: ";
    cin>>senate;

    string result = predictPartyVictory(senate);
    cout<<"The winning party is: "<<result<<endl;

    return 0;
}
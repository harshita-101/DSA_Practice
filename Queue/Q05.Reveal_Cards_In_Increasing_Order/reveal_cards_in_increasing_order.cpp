#include <iostream>
#include <vector>
#include <queue>
using namespace std;

vector<int> deckRevealedIncreasing(vector<int> &deck)
{
    sort(deck.begin(), deck.end());
    queue<int> q;
    vector<int> ans(deck.size());

    for (int i = 0; i < deck.size(); i++)
    {
        q.push(i);
    }

    int i = 0;

    while (!q.empty())
    {
        int index = q.front();
        ans[index] = deck[i];
        i++;
        q.pop();

        if (!q.empty())
        {
            int temp = q.front();
            q.pop();
            q.push(temp);
        }
    }

    return ans;
}

int main()
{
    int n;
    cout<<"Enter the size of the deck: ";
    cin>>n;

    vector<int> deck(n);
    cout<<"Enter the cards in the deck: ";
    for (int i = 0; i < n; i++)
    {
        cin>>deck[i];
    }

    vector<int> result = deckRevealedIncreasing(deck);

    cout<<"The cards revealed in increasing order are: ";
    for (int val : result)
    {
        cout<<val<<" ";
    }
    cout<<endl;

    return 0;
}
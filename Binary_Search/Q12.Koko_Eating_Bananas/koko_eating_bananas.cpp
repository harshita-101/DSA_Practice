#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

long long calculateHours(vector<int>& piles, int speed){
    long long hours = 0;

    for(int pile : piles){
        hours += (pile + speed -1LL)/speed;
    }
    return hours;
}

int minEatingSpeed(vector<int> &piles, int h){
    int low =1;
    int high = *max_element(piles.begin(), piles.end());
    int ans = -1;

    while(low <= high){
        int mid = low + (high - low) / 2;

        long long totalHours = calculateHours(piles, mid);
        if(totalHours <= h)
        {
            ans = mid;
            high = mid - 1;
        }
        else
        {
            low = mid + 1;
        }
    }
    return ans;
}

int main(){
    int n,h;
    cout<<"Enter the size of the piles array: ";
    cin>>n;

    vector<int> piles(n);
    cout<<"Enter the elements of the piles array: ";
    for(int i=0; i<n; i++){
        cin>>piles[i];
    }

    cout<<"Enter the total hours: ";
    cin>>h;

    cout<<minEatingSpeed(piles, h)<<endl;
    return 0;
}
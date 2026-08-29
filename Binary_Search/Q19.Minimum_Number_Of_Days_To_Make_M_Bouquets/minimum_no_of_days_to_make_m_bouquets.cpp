#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

int minDays(vector<int>& bloomDay, int m, int k){
    int n = bloomDay.size();
    int low = *min_element(bloomDay.begin(), bloomDay.end());
    int high = *max_element(bloomDay.begin(), bloomDay.end());

    if((long long)m*k > n) return -1;

    while(low <= high){
        int mid = low + (high - low)/2;
        int consecutive = 0;
        int bouquets = 0;

        for(int i=0; i<n; i++){
            if(bloomDay[i] <= mid){
                consecutive++;
            }
            else{
                consecutive = 0;
            }
            if(consecutive == k){
                bouquets++;
                consecutive = 0;
            }
        }
        if(bouquets >= m){
            high = mid - 1;
        }
        else{
            low = mid + 1;
        }
    }
    return low;
}

int main(){
    int n, m, k;
    cout<<"Enter the size of the array: ";
    cin>>n;

    vector<int> bloomDay(n);
    for(int i=0; i<n; i++){
        cin>>bloomDay[i];
    }

    cout<<"Enter the no of required bouquets: ";
    cin>>m;

    cout<<"Enter the value of consecutive k place: ";
    cin>>k;

    int result = minDays(bloomDay, m, k);
    cout<<result;

    return 0;
}
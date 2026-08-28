#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

int shipWithinDays(vector<int>& weights, int days) {
    int n = weights.size();
    int low = *max_element(weights.begin(), weights.end());
    int high = 0;

    for(int i=0; i<n; i++){
        high += weights[i];
    }

    while(low <= high){
        int mid = low + (high - low) /2;
        int currentWeight = 0;
        int requiredDays = 1;

        for(int i=0; i<n; i++){
            if(currentWeight + weights[i] <= mid){
                currentWeight += weights[i];
            }
            else{
                requiredDays++;
                currentWeight = weights[i];
            }
        }
        if(requiredDays <= days){
            high = mid -1;
        }
        else{
            low = mid + 1;
        }
    }
    return low;
}

int main(){
    int n, days;
    cout<<"Enter the size of array: ";
    cin>>n;

    vector<int> weights(n);
    cout<<"Enter the elements of weight array: ";
    for(int i=0; i<n; i++){
        cin>>weights[i];
    }

    cout<<"Enter the days: ";
    cin>>days;

    int result = shipWithinDays(weights, days);
    cout<<result;

    return 0;
}
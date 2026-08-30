#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

int maxDistance(vector<int>& position, int m) {
    int n = position.size();
    sort(position.begin(), position.end());
    int low = 1;
    int high = position[n-1] - position[0];

    while(low <= high){
        int mid = low + (high-low)/2;
        int count = 1;
        int lastposition = position[0];

        for(int i=1; i<n; i++){
            if(position[i] - lastposition >= mid){
                count++;
                lastposition = position[i];
            }
        }
        if(count >= m){
            low = mid +1;
        }
        else{
            high = mid-1;
        }
    }
    return high;
}

int main(){
    int n ,m;
    cout<<"Enter the size of the array: ";
    cin>>n;

    vector<int> position(n);
    cout<<"Enter the position: ";
    for(int i=0; i<n; i++){
        cin>>position[i];
    }

    cout<<"Enter the no of balls to placed: ";
    cin>>m;

    return 0;
}
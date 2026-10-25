#include<iostream>
#include<vector>
using namespace std;

int trap(vector<int>& height){
    int n = height.size();
    if(n == 0) return 0;

    vector<int> leftMax(n), rightMax(n);
    leftMax[0] = height[0];
    rightMax[n-1] = height[n-1];

    for(int i=1; i<n; i++){
        leftMax[i] = max(leftMax[i-1], height[i]);
    }

    for(int i = n-2; i>=0; i--){
        rightMax[i] = max(rightMax[i+1], height[i]);
    }

    int ans = 0;
    for(int i=0; i<n; i++){
        ans += min(leftMax[i], rightMax[i]) - height[i];
    }

    return ans;
}

int main(){
    int n;
    cout<<"Enter the size of the array: ";
    cin>>n;

    vector<int> height(n);
    cout<<"Enter the heights of the bars: ";
    for(int i=0; i<n; i++){
        cin>>height[i];
    }
    cout<<"The amount of water that can be trapped is: "<<trap(height)<<endl;
    return 0;
}
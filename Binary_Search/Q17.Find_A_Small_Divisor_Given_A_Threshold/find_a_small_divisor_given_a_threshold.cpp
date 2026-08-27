#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

int smallestDivisor(vector<int>& nums, int threshold) {
    int  low = 1;
    int high = *max_element(nums.begin(), nums.end());

    while(low <= high){
        int mid = low + (high - low) /2;
        int sum = 0;

        for(int i =0; i<nums.size(); i++){
            sum = sum + ((nums[i] + mid -1)/mid);
        }

        if(sum <= threshold){
            high = mid-1;
        }
        else{
            low = mid+1;
        }
    }
    return low;
}

int main(){
    int n, threshold;
    cout<<"Enter the number of elements in the array: ";
    cin>>n;
    vector<int> nums(n);
    cout<<"Enter the elements of the array: ";
    for(int i=0; i<n; i++){
        cin>>nums[i];
    }
    cout<<"Enter the threshold: ";
    cin>>threshold;
    int result = smallestDivisor(nums, threshold);
    cout<<"The smallest divisor is: "<<result<<endl;

    return 0;
}
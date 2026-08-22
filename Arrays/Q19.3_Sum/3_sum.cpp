#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

vector<vector<int>> threeSum(vector<int>& nums){
    int n = nums.size();
    vector<vector<int>> ans;

    sort(nums.begin(), nums.end());

    for(int i=0; i<n; i++){
        int j = i+1;
        int k = n-1;

        while(j<k){
            int sum = nums[i] + nums[j] + nums[k];
            if(sum > 0){
                k--;
            }
            else if(sum < 0){
                j++;
            }
            else{
                ans.push_back({nums[i], nums[j], nums[k]});
                j++; k--;

                while(j<k && nums[j] == nums[j-1]) j++;
            }
        }
    }
    return ans;
}

int main(){
    int n;
    cout<<"Enter the number of elements: ";
    cin>>n;
    vector<int> nums(n);
    cout<<"Enter the elements: ";
    for(int i=0; i<n; i++){
        cin>>nums[i];
    }
    vector<vector<int>> result = threeSum(nums);
    for(const auto& triplet : result){
        for(int num : triplet){
            cout<<num<<" ";
        }
        cout<<endl;
    }
    return 0;
}
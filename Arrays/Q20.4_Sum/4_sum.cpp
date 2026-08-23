#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

vector<vector<int>> fourSum(vector<int>& nums, int target) {
    vector<vector<int>> ans;
    int n = nums.size();

    sort(nums.begin(), nums.end());

    for(int i=0; i<n; i++){
        if(i > 0 && nums[i] == nums[i-1]) continue;
        for(int j=i+1; j<n; j++){
            int p = j+1, q = n-1;
            if(j > i+1 && nums[j] == nums[j-1]) continue;

            while(p<q){
                long long sum = (long long)nums[i] + (long long)nums[j] + (long long)nums[p] + (long long)nums[q];

                if(sum < target){
                    p++;
                } 
                else if(sum > target){
                    q--;
                }
                else{
                    ans.push_back({nums[i], nums[j], nums[p], nums[q]});
                    p++;
                    q--;

                    while(p<q && nums[p] == nums[p-1]) p++;
                }
            }
        }
    }
    return ans;
}

int main(){
    int n , target;
    cout<<"Enter the size of the array: ";
    cin>>n;

    vector<int> nums(n);
    cout<<"Enter the elements of the array: ";
    for(int i=0; i<n; i++){
        cin>>nums[i];
    }
    cout<<"Enter the target sum: ";
    cin>>target;

    vector<vector<int>> result = fourSum(nums, target);
    cout<<"The unique quadruplets that sum up to the target are: "<<endl;
    for(auto &quadruplet : result){
        cout<<"[";
        for(int i=0; i<quadruplet.size(); i++){
            cout<<quadruplet[i];
            if(i < quadruplet.size() - 1) cout<<", ";
        }
        cout<<"]"<<endl;
    }
    return 0;
}
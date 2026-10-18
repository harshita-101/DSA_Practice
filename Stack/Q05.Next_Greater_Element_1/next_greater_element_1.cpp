#include<iostream>
#include<stack>
#include<vector>
#include<unordered_map>
using namespace std;

vector<int> nextGreaterElement(vector<int>& nums1, vector<int> nums2){
    unordered_map<int, int> m;
    stack<int> s;

    for(int i = nums2.size()-1; i>=0; i--){
        while(s.size() > 0 && s.top() <= nums2[i]){
            s.pop();
        }
        if(s.empty()){
            m[nums2[i]] = -1;
        }
        else{
            m[nums2[i]] = s.top();
        }

        s.push(nums2[i]);
    }

    vector<int> ans;
    for(int i = 0; i<nums1.size(); i++){
        ans.push_back(m[nums1[i]]);
    }
    return ans;
}

int main(){
    int n1, n2;
    cout<<"Enter the size of nums1: ";
    cin>>n1;
    cout<<"Enter the size of nums2: ";
    cin>>n2;

    vector<int> nums1(n1), nums2(n2);
    cout<<"Enter the elements of nums1: ";
    for(int i =0; i<n1; i++){
        cin>>nums1[i];
    }

    cout<<"Enter the elements of nums2: ";
    for(int i=0; i<n2; i++){
        cin>>nums2[i];
    }

    vector<int> ans = nextGreaterElement(nums1, nums2);
    cout<<"Next greater elements are: ";
    for(int val : ans){
        cout<<val<<" ";
    }
    cout<<endl;

    return 0;
}
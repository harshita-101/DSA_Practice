#include<iostream>
#include<vector>
#include<unordered_set>
using namespace std;

vector<int> intersection(vector<int>& nums1, vector<int>& nums2) {
    unordered_set<int> s;
    unordered_set<int> ans;
    vector<int> result;
    for(int i=0; i< nums1.size(); i++){
        s.insert(nums1[i]);
    }

    for(int i=0; i<nums2.size(); i++){

        if(s.find(nums2[i]) != s.end()){
            ans.insert(nums2[i]);
        }
            
    }

    for(int x : ans){
        result.push_back(x);
    }
    return result;
}

int main(){
    int n, m;
    cout<<"Enter the size of first array: ";
    cin>>n;
    cout<<"Enter the size of second array: ";
    cin>>m;

    vector<int> nums1(n);
    cout<<"Enter the element of first array: "<<endl;
    for(int i=0; i<n; i++){
        cin>>nums1[i];
    }

    vector<int> nums2(m);
    cout<<"Enter the element of second array: "<<endl;
    for(int i=0; i<m; i++){
        cin>>nums2[i];
    }

    vector<int> result = intersection(nums1, nums2);

    for(int x : result){
        cout << x << " ";
    }
    cout << endl;

    return 0;

}
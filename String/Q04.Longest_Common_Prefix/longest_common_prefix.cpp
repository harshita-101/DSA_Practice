#include<iostream>
#include<vector>
#include<string>
using namespace std;

string longestCommonPrefix(vector<string>& strs) {
    if(strs.empty())
    return "";
    string ans = "";

    for(int i=0; i<strs[0].size(); i++){
        char ch = strs[0][i];

        for(int j=1; j<strs.size(); j++){
            if(i >= strs[j].size() || strs[j][i] != ch)
            return ans;
        }
        ans += ch;
    }
    return ans;
}

int main(){
    int n;
    cout<<"Enter the number of strings: ";
    cin>>n;
    vector<string> strs(n);
    cout<<"Enter the strings: ";
    for(int i=0; i<n; i++){
        cin>>strs[i];
    }
    cout<<"Longest Common Prefix: "<<longestCommonPrefix(strs)<<endl;
    return 0;
}
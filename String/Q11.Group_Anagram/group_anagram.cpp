#include<iostream>
#include<vector>
#include<string>
#include<unordered_map>
using namespace std;

vector<vector<string>> groupAnagrams(vector<string>& strs) {
    unordered_map<string, vector<string>> mp;
    vector<vector<string>> ans;

    for(string s : strs){

        vector<int> freq(26, 0);
        string key = "";

        for(int i = 0; i < s.length(); i++){
            freq[s[i] - 'a']++;
        }

        for(int i = 0; i < 26; i++){
            key += to_string(freq[i]) + "#";
        }

        mp[key].push_back(s);
    }

    for(auto& pair : mp){
        ans.push_back(pair.second);
    }
    return ans;
}

int main(){
    int n;
    cout<<"Enter the number of strings: ";
    cin>>n;
    cin.ignore(); // To ignore the newline character after reading n
    vector<string> strs(n);
    cout<<"Enter the strings (lowercase): "<<endl;
    for(int i=0; i<n; i++){
        getline(cin, strs[i]);
    }
    vector<vector<string>> result = groupAnagrams(strs);

    cout<<"Grouped Anagrams: "<<endl;
    for(const auto& group : result){
        for(const auto& str : group){
            cout<<str<<" ";
        }
        cout<<endl;
    }

    return 0;
}
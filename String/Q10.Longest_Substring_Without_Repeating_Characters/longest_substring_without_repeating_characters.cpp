#include<iostream>
#include<string>
#include<vector>
#include<unordered_set>
using namespace std;

int lengthOfLongestSubstring(string s) {
    int left = 0;
    int n = s.length();
    unordered_set<char> st;
    int maxLength =0;
    for (int right = 0; right < n; right++) {

        while(st.find(s[right]) != st.end())
        {
            st.erase(s[left]);
            left++;
        }

        st.insert(s[right]);
            
        maxLength = max(maxLength, right - left + 1);
    }
    return maxLength;
}

int main(){
    string s;
    cout<<"Enter the string: ";
    cin>>s;
    int length = lengthOfLongestSubstring(s);
    cout<<length<<endl;
    return 0;
}
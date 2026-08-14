#include<iostream>
#include<vector>
#include<string>
using namespace std;

string longestPalindrome(string s) {
    int maxlength =1;
    int start = 0;

    for(int i=0; i<s.length(); i++){
        int left = i;
        int right = i;
        //odd center
        while(left >= 0 && right < s.length() && s[left] == s[right]){
            int currentlength = right - left + 1;
            if(currentlength > maxlength){
                maxlength = currentlength;
                start = left;
            }
            left--;
            right++;
        }

        left = i;
        right = i+1;
        //even center
        while(left >= 0 && right < s.length() && s[left] == s[right]){
            int currentlength = right - left + 1;
            if(currentlength > maxlength){
                maxlength = currentlength;
                start = left;
            }
            left--;
            right++;
        }
    }
    return s.substr(start, maxlength);
}

int main(){
    string s;
    cin>>s;
    string result = longestPalindrome(s);
    cout<<result;

    return 0;
}

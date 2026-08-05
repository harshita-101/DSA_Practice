#include<iostream>
#include<string>
#include<vector>
using namespace std;

bool isAnagram(string s, string t) {
    vector<int> freq(26, 0);

    if(s.length() != t.length()){
        return false;
    }
        
    for(int i=0; i< s.length(); i++){
        freq[s[i] - 'a']++;
    }

    for(int i=0; i< t.length(); i++){
        freq[t[i] - 'a']--;
        if(freq[t[i] - 'a'] < 0)
        return false;
    }
        
    return true; 
}

int main(){
    string s,t;
    cout << "Enter the first lowercase string: ";
    getline(cin, s);
    cout<<"Enter the second lowercase string: ";
    getline(cin, t);
    if(isAnagram(s,t)){
        cout << "\"" << s << "\" and \"" << t << "\" are anagrams." << endl;
    }
    else{
        cout << "\"" << s << "\" and \"" << t << "\" are not anagrams." << endl;
    }
    return 0;
}

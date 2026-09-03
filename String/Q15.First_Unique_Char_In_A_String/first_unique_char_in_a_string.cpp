#include <iostream>
#include <string>
#include <unordered_map>
using namespace std;

int firstUniqChar(string s)
{
    unordered_map<char, int> freq;

    for (char val : s)
    {
        freq[val]++;
    }
    for (int i = 0; i < s.size(); i++)
    {
        if (freq[s[i]] == 1)
        {
            return i;
        }
    }
    return -1;
}

int main(){
    string s;
    cout<<"Enter a string: ";
    cin>>s;
    int ans = firstUniqChar(s);
    if(ans != -1){
        cout<<"First unique charcter in string is : "<<s[ans]<<" at index "<<ans;
    }
    else{
        cout<<"No unique character found in the string.";
    }
    return 0;
}
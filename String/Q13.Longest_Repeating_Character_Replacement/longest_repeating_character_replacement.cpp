#include<iostream>
#include<string>
using namespace std;

int characterReplacement(string s, int k) {
    int freq[26] = {0};
    int maxFreq = 0;
    int left = 0;
    int ans = 0;

    for(int right = 0; right < s.size(); right++){
        freq[s[right] - 'A']++;
        maxFreq = max(maxFreq, freq[s[right] - 'A']);

        int windowSize = right - left + 1;
        int changes = windowSize - maxFreq;

        if(changes > k){
            freq[s[left] - 'A']--;
            left++;
        }
        ans = max(ans, right - left + 1);
    }
    return ans;
}

int main(){
    string s;
    cout<<"Enter the string: ";
    cin>>s;
    int k;
    cout<<"Enter the number of replacements allowed (k): ";
    cin>>k;
    int result = characterReplacement(s, k);
    cout<<"The length of the longest substring after replacements is: "<<result<<endl;
    
    return 0;
}
#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;

vector<int> findAnagrams(string s, string p)
{
    unordered_map<char, int> freq1;
    unordered_map<char, int> freq2;
    vector<int> ans;
    for (char val : p)
    {
        freq1[val]++;
    }

    int left = 0;
    for (int right = 0; right < s.size(); right++)
    {
        freq2[s[right]]++;
        int windowSize = right - left + 1;
        if (windowSize > p.size())
        {
            freq2[s[left]]--;
            if (freq2[s[left]] == 0)
            {
                freq2.erase(s[left]);
            }
            left++;
        }
        if (right - left + 1 == p.size())
        {
            if (freq1 == freq2)
            {
                ans.push_back(left);
            }
        }
    }
    return ans;
}

int main()
{
    string s, p;
    cout<<"Enter the string a: ";
    cin>>s;
    cout<<"Enter the string p: ";
    cin>>p;
    vector<int> result = findAnagrams(s, p);
    for (int index : result)
    {
        cout << index << " ";
    }
    return 0;
}
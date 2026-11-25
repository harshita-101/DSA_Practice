
#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

int maxVowels(string s, int k) {
    int count = 0;
    int maxcount = 0;

    // First window
    for (int i = 0; i < k; i++) {
        if (s[i] == 'a' || s[i] == 'e' ||
            s[i] == 'i' || s[i] == 'o' ||
            s[i] == 'u') {
            count++;
        }
    }

    maxcount = count;

    // Sliding Window
    for (int i = k; i < s.length(); i++) {

        // Remove outgoing character
        if (s[i-k] == 'a' || s[i-k] == 'e' ||
            s[i-k] == 'i' || s[i-k] == 'o' ||
            s[i-k] == 'u') {
            count--;
        }

        // Add incoming character
        if (s[i] == 'a' || s[i] == 'e' ||
            s[i] == 'i' || s[i] == 'o' ||
            s[i] == 'u') {
            count++;
        }

        maxcount = max(maxcount, count);
    }

    return maxcount;
}

int main() {
    string s;
    int k;

    cout << "Enter string: ";
    cin >> s;

    cout << "Enter window size k: ";
    cin >> k;

    cout << "Maximum vowels: " << maxVowels(s, k) << endl;

    return 0;
}

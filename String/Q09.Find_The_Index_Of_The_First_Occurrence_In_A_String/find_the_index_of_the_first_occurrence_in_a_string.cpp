#include<iostream>
#include<string>
using namespace std;

int strStr(string haystack, string needle) {
    int n = haystack.length();
    int m = needle.length();

    for(int i=0; i<= n-m; i++){
        int j =0;
        while(j<m){
            if(haystack[i+j] != needle[j]){
                break;
            }
            j++;
        }
        if(j==m){
            return i;
        }
    }
    return -1;
}

int main(){
    string haystack, needle;
    cout<<"Enter the haystack string: ";
    getline(cin, haystack);
    cout<<"Enter the needle string: ";
    getline(cin, needle);
    int index = strStr(haystack, needle);
    cout<<"The index of the first occurrence of the needle in the haystack is: "<<index<<endl;

    return 0;
}
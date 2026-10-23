#include<iostream>
#include<string>
#include<stack>
#include<algorithm>
using namespace std;

string removeDuplicates(string s){

    stack<char> st;

    for(int i=0; i<s.length(); i++){
        if(!st.empty() && st.top() == s[i]){
            st.pop();
        }
        else{
            st.push(s[i]);
        }
    }

    string ans = "";
    while(!st.empty()){
        ans += st.top();
        st.pop();
    }

    reverse(ans.begin(), ans.end());

    return ans;
}

int main(){
    string s;
    cout<<"Enter the string: ";
    cin>>s;

    string result = removeDuplicates(s);
    cout<<"String after removing adjacent duplicates: "<<result<<endl;

    return 0;
}
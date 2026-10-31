#include<iostream>
#include<string>
#include<stack>
#include<algorithm>
using namespace std;

bool backspaceCompare(string s, string t) {
        stack<char> st;
        string s1 = "";
        string t1 = "";

        for(int i=0; i<s.length(); i++){
            if(!st.empty() && s[i] == '#'){
                st.pop();
            }
            else if(st.empty() && s[i] == '#'){
                continue;
            }
            else{
                st.push(s[i]);
            }
        }

        while(!st.empty()){
            s1 += st.top();
            st.pop();
        }

        for(int i=0; i<t.length(); i++){
            if(!st.empty() && t[i] == '#'){
                st.pop();
            }
            else if(st.empty() && t[i] == '#'){
                continue;
            }
            else{
                st.push(t[i]);
            }
        }

        while(!st.empty()){
            t1 += st.top();
            st.pop();
        }

        reverse(s1.begin(), s1.end());
        reverse(t1.begin(), t1.end());
        if(s1 == t1){
            return true;
        }

        return false;
    }

int main(){
    string s, t;
    cin>>s;
    cin>>t;

    bool result = backspaceCompare(s, t);

    return 0;
}
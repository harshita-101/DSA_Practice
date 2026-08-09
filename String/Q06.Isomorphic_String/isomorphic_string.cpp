#include<iostream>
#include<string>
#include<vector>
using namespace std;

bool isIsomorphic(string s, string t){
    if(s.length() != t.length()){
        return false;
    }

    vector<int> sToT(128, -1);
    vector<int> tToS(128, -1);

    for(int i = 0; i < s.length(); i++)
    {
        int a = s[i];
        int b = t[i];

        if(sToT[a] != -1 && sToT[a] != b)
            return false;

        if(tToS[b] != -1 && tToS[b] != a)
            return false;

        sToT[a] = b;
        tToS[b] = a;
    }
    return true;

}

int main(){
    string s,t;
    cout<<"Enter the first string: ";
    cin>>s;
    cout<<"Enter the second string: ";
    cin>>t;

    if(isIsomorphic(s,t)){
        cout<<"True"<<endl;
    }
    else{
        cout<<"False"<<endl;
    }
    return 0;
    
}
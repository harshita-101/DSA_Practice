#include<iostream>
#include<string>
using namespace std;

bool rotateString(string s, string goal) {
    if(s.length() != goal.length()){
        return false;
    }

    string combined = s+s;
        
    if (combined.find(goal) != string::npos)
        return true;
        
    else
        return false;
}

int main(){
    string s, goal;
    cout<<"Enter the original string: ";
    cin>>s;
    cout<<"Enter the goal string: ";
    cin>>goal;
    if(rotateString(s,goal)){
        cout<<"True"<<endl;
    }
    else{
        cout<<"False"<<endl;
    }
    return 0;
}
#include<iostream>
#include<climits>
#include<string>
using namespace std;

int myAtoi(string s){
    int n = s.length();
    int i = 0;
    long long num = 0;
    int sign = 1;

    while(i<n && s[i] == ' '){
        i++;
    }
    if(i==n){
        return 0;
    }
    if(s[i] == '-'){
        sign = - 1;
        i++;
    }
    else if(s[i] == '+'){
        i++;
    }
    while(i <n && ('0'<=s[i] && s[i]<='9')){
        int value = s[i] - '0';
        num = num * 10 + value;
        i++;
    }
    if(num > INT_MAX){
        if(sign == +1){
            return INT_MAX;
        }
        else{
            return INT_MIN;
        }
    }
    num = sign * num;

    return num;
}

int main(){
    string s;
    cout<<"Enter the string: ";
    cin>>s;
    int result = myAtoi(s);
    cout<<"The integer value is: "<<result<<endl;

    return 0;
}
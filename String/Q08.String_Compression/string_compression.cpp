#include<iostream>
#include<vector>
#include<string>
using namespace std;

int compress(vector<char>& chars) {
    int read = 0;
    int write = 0;

    while(read < chars.size()){
        int count =0;
        char currChar = chars[read];
            
        while(read < chars.size() && chars[read] == currChar){
            count++;
            read++;
        }

        if(count > 1){
            chars[write] = currChar;
            write++;

            if(count <= 9){
                chars[write] = '0' + count;
                write ++;
            }
            else{
                string num = to_string(count);

                for(char digit : num){
                    chars[write] = digit;
                    write++;
                }  
            }
        }
        else{
            chars[write] = currChar;
            write++;
        }
            
    }
    return write;
}

int main(){
    int n;
    cout<<"Enter the number of characters: ";
    cin>>n;
    vector<char> chars(n);
    cout<<"Enter the characters: ";
    for(int i=0; i<n; i++){
        cin>>chars[i];
    }
    int result  = compress(chars);
    cout<<result;

    return 0;

}
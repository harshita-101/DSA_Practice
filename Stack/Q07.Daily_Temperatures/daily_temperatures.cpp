#include<iostream>
#include<stack>
#include<vector>
using namespace std;

vector<int> dailyTemperatures(vector<int>& temperatures){

    int n = temperatures.size();
    vector<int> ans(n,0);
    stack<int> st;;

    for(int i=0; i<n; i++){
        while(!st.empty() && temperatures[st.top()] < temperatures[i]){
            int prev = st.top();
            st.pop();
            ans[prev] = i - prev;
        }

        st.push(i);
    }
    return ans;
}

int main(){
    int n;
    cout<<"Enter the size of the array: ";
    cin>>n;

    vector<int> temperatures(n);
    cout<<"Enter the elements of the array: ";
    for(int i=0; i<n; i++){
        cin>>temperatures[i];
    }

    vector<int> result = dailyTemperatures(temperatures);
    for(int val : result){
        cout<<val<<" ";
    }
    cout<<endl;

    return 0;
}
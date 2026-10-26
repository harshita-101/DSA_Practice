#include<iostream>
#include<vector>
#include<stack>
#include<algorithm>
using namespace std;

int largestRectangleArea(vector<int> & heights){
    int n = heights.size();
    stack<int> s;
    vector<int> left(n , 0);
    vector<int> right(n, 0);
    int ans = 0;

    for(int i = n-1; i>=0; i--){
        while(s.size() > 0 && heights[s.top()] >= heights[i]){
            s.pop();
        }

        right[i] = s.empty() ? n : s.top();
        s.push(i);
    }

    for(int i = 0; i < n; i++){
        while(s.size() > 0 && heights[s.top()] >= heights[i]){
            s.pop();
        }

        left[i] = s.empty() ? -1 : s.top();
        s.push(i);
    }

    for(int i =0; i<n; i++){
        int width = right[i] - left[i] - 1;
        int currArea = heights[i] * width;
        ans = max(ans, currArea);
    }

    return ans;
}

int main(){
    int n;
    cout<<"Enter the size of the array: ";
    cin>>n;
    vector<int> heights(n);
    cout<<"Enter the elements of the array: ";
    for(int i = 0; i<n; i++){
        cin>>heights[i];
    }
    cout<<"The largest rectangle in the histogram is: "<<largestRectangleArea(heights)<<endl;

    return 0;
}
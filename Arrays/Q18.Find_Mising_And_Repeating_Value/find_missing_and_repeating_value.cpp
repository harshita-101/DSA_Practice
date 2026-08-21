#include<iostream>
#include<vector>
#include<unordered_set>
using namespace std;

vector<int> findMissingAndRepeatedValues(vector<vector<int>>& grid){
    vector<int> ans;
    unordered_set<int> s;
    int n = grid.size();
    int a, b;
    int expSum = 0, actSum = 0;

    for(int i=0; i<n; i++){
        for(int j=0; j<n; j++){
            actSum += grid[i][j];

            if(s.find(grid[i][j]) != s.end()){
                a = grid[i][j];
                ans.push_back(a);
            }
            s.insert(grid[i][j]);
        }
    }
    expSum = (n*n) * (n*n + 1) / 2;
    b = expSum + a - actSum;
    ans.push_back(b);

    return ans;
}

int main(){
    int n;
    cout<<"Enter the size of the grid: ";
    cin>>n;
    vector<vector<int>> grid(n, vector<int>(n));
    cout<<"Enter the elements of the grid: ";
    for(int i=0; i<n; i++){
        for(int j=0; j<n; j++){
            cin>>grid[i][j];
        }
    }
    vector<int> result = findMissingAndRepeatedValues(grid);
    cout<<"The missing value is: "<<result[1]<<endl;
    cout<<"The repeating value is: "<<result[0]<<endl;
    return 0;
}
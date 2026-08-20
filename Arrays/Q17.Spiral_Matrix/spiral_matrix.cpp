#include<iostream>
#include<vector>
using namespace std;

vector<int> spiralOrder(vector<vector<int>>& matrix) {
    int m = matrix.size();
    int n = matrix[0].size();
    int srow = 0, erow= m-1, scol = 0, ecol = n-1;
    vector<int> ans;

    while(srow <= erow && scol <= ecol){
            //top
        for(int j = scol; j<= ecol; j++){
            ans.push_back(matrix[srow][j]);
        }
            //right
        for(int i = srow+1; i<=erow; i++){
            ans.push_back(matrix[i][ecol]);
        }
            //bottom
        for(int j = ecol-1; j>=scol; j--){
            if(srow == erow){
                break;
            }
            ans.push_back(matrix[erow][j]);
        }
            //left
        for(int i = erow-1; i>=srow+1; i--){
            if(scol == ecol){
                break;
            }
            ans.push_back(matrix[i][scol]);
        }
        srow++;
        scol++;
        erow--;
        ecol--;
    }

    return ans;
}

int main(){
    int m, n;
    cout<<"Enter the number of rows and columns: ";
    cin>>m>>n;
    vector<vector<int>> matrix(m, vector<int>(n));
    cout<<"Enter the elements of the matrix: ";
    for(int i=0; i<m; i++){
        for(int j=0; j<n; j++){
            cin>>matrix[i][j];
        }
    }
    vector<int> result = spiralOrder(matrix);
    cout<<"Spiral order: ";
    for(int x : result){
        cout<<x<<" ";
    }
    cout<<endl;
    return 0;
}
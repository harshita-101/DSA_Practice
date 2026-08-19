#include<iostream>
#include<vector>
using namespace std;

int diagonalSum(vector<vector<int>>& mat) {
    int n = mat.size();
    int sum = 0;
    for(int i =0; i<n; i++){
        if(i == n-i-1){
            sum += mat[i][i];  
        }
        else{
            sum += mat[i][i];
            sum += mat[i][n-i-1];
        }
    }
    return sum;
}

int main(){
    int m,n;
    cout<<"Enter the number of rows and columns: ";
    cin>>m>>n;
    vector<vector<int>> mat(m, vector<int>(n));

    cout<<"Enter the elements of the matrix: ";
    for(int i=0; i<m; i++){
        for(int j=0; j<n; j++){
            cin>>mat[i][j];
        }
    }
    cout<<"The diagonal sum is: "<<diagonalSum(mat)<<endl;
    return 0;
}
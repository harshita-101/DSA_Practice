#include<iostream>
#include<vector>
using namespace std;

bool searchMatrix(vector<vector<int>>& matrix, int target) {
    int rows = matrix.size();
    int cols = matrix[0].size();

    int low = 0;
    int high = rows * cols - 1;

    while(low<= high){
        int mid = low + (high - low) / 2;

        int row = mid / cols;
        int col = mid % cols;

        if(matrix[row][col] == target){
            return true;
        }
        else if(matrix[row][col] < target){
            low = mid + 1;
        }
        else{
            high = mid - 1;
        }
    }
    return false;
}

int main() {
    int rows, cols, target;

    cout << "Enter number of rows: ";
    cin >> rows;

    cout << "Enter number of columns: ";
    cin >> cols;

    vector<vector<int>> matrix(rows, vector<int>(cols));

    cout << "Enter the elements of the matrix:\n";
    for(int i = 0; i < rows; i++) {
        for(int j = 0; j < cols; j++) {
            cin >> matrix[i][j];
        }
    }

    cout << "Enter target: ";
    cin >> target;

    if(searchMatrix(matrix, target))
        cout << "Target Found";
    else
        cout << "Target Not Found";

    return 0;
}
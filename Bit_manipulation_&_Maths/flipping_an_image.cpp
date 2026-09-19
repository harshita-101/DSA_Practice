#include <iostream>
#include <vector>
#include<algorithm>
using namespace std;

vector<vector<int>> flipAndInvertImage(vector<vector<int>> &image)
{
    for (int i = 0; i < image.size(); i++)
    {
        for (int j = 0; j < image.size(); j++)
        {
            if (image[i][j] == 0)
                image[i][j] = 1;
            else
                image[i][j] = 0;
        }
        reverse(image[i].begin(), image[i].end());
    }
    return image;
}

int main()
{
    int n;
    cout<<"Enter the number of rows and columns: ";
    cin>>n;
    vector<vector<int>> image(n, vector<int>(n));
    cout<<"Enter the elements of the image (0 or 1): ";
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            cin>>image[i][j];
        }
    }
    image = flipAndInvertImage(image);
    cout<<"The flipped and inverted image is: "<<endl;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            cout<<image[i][j]<<" ";
        }
        cout<<endl;
    }
    return 0;
}
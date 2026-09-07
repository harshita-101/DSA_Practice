#include <iostream>
#include <vector>
using namespace std;

int removeDuplicates(vector<int> &nums)
{
    int k = 0;

    for (int i = 0; i < nums.size(); i++)
    {

        if (k < 2 or nums[i] != nums[k - 2])
        {
            nums[k] = nums[i];
            k++;
        }
    }
    return k;
}

int main()
{
    int n;
    cout<<"Enter the number of elements in the array: ";
    cin>>n;
    vector<int> nums(n);
    cout<<"Enter the elements of the array: ";
    for(int i=0; i<n; i++)
    {
        cin>>nums[i];
    }
    int k = removeDuplicates(nums);
    cout<<"The number of unique elements in the array is: "<<k<<endl;
    cout<<"The array after removing duplicates is: ";
    for(int i=0; i<k; i++)
    {
        cout<<nums[i]<<" ";
    }
    cout<<endl;
    return 0;
}
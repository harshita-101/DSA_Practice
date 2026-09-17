#include <iostream>
#include <vector>
#include<algorithm>
using namespace std;

double findMedianSortedArrays(vector<int> &nums1, vector<int> &nums2)
{
    vector<int> arr = nums1;
    arr.insert(arr.end(), nums2.begin(), nums2.end());

    sort(arr.begin(), arr.end());

    int n = arr.size();
    int mid = n / 2;

    if (n % 2 == 1)
        return arr[mid];

    return (arr[mid - 1] + arr[mid]) / 2.0;
}

int main()
{
    int n1, n2;
    cout<<"Enter the size of the first array: ";
    cin>>n1;
    cout<<"Enter the size of the second array: ";
    cin>>n2;
    
    vector<int> nums1(n1), nums2(n2);
    cout<<"Enter the elements of the first array: ";
    for(int i=0; i< n1; i++){
        cin>>nums1[i];
    }
    cout<<"Enter the elements of the second array: ";
    for(int i=0; i< n2; i++){
        cin>>nums2[i];
    }
    double median = findMedianSortedArrays(nums1, nums2);
    cout<<"The median of the two sorted arrays is: "<<median<<endl;
    return 0;
}
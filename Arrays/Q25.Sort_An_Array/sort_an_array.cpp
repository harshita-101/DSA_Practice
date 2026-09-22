#include <iostream>
#include <vector>
using namespace std;

#include <iostream>
#include <vector>
using namespace std;

int partition(vector<int>& nums, int low, int high)
{
    int pivot = nums[high];
    int i = low - 1;

    for (int j = low; j < high; j++)
    {
        if (nums[j] < pivot)
        {
            i++;
            swap(nums[i], nums[j]);
        }
    }

    swap(nums[i + 1], nums[high]);

    return i + 1;
}

void quickSort(vector<int>& nums, int low, int high)
{
    if (low >= high)
        return;

    int pivotIndex = partition(nums, low, high);

    quickSort(nums, low, pivotIndex - 1);
    quickSort(nums, pivotIndex + 1, high);
}

vector<int> sortArray(vector<int>& nums)
{
    quickSort(nums, 0, nums.size() - 1);
    return nums;
}

int main()
{
    int n;

    cout << "Enter the size of array: ";
    cin >> n;

    vector<int> nums(n);

    cout << "Enter the elements: ";
    for (int i = 0; i < n; i++)
    {
        cin >> nums[i];
    }

    sortArray(nums);

    cout << "Sorted array: ";

    for (int x : nums)
    {
        cout << x << " ";
    }

    return 0;
}
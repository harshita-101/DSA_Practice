#include <iostream>
#include <vector>
using namespace std;

vector<int> twoSum(vector<int> &numbers, int target)
{
    int n = numbers.size();
    int low = 0;
    int high = n - 1;

    while (low <= high)
    {
        if (numbers[low] + numbers[high] == target)
        {
            break;
        }
        else if (numbers[low] + numbers[high] > target)
        {
            high = high - 1;
        }
        else
        {
            low = low + 1;
        }
    }
    return {low + 1, high + 1};
}

int main(){
    int n;
    cin>>n;
    vector<int> numbers(n);
    for(int i=0; i<n; i++){
        cin>>numbers[i];
    }
    int target;
    cin>>target;
    vector<int> result = twoSum(numbers, target);
    cout<<result[0]<<" "<<result[1]<<endl;
    return 0;
}
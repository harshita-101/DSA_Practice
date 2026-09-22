# Sort an Array

## Problem Statement

Given an array of integers `nums`, sort the array in ascending order and return the sorted array.

The solution uses the **Quick Sort** algorithm instead of the built-in sorting function.

**LeetCode:** 912  
**Difficulty:** Medium

---

## Example

### Example 1

**Input:**
`nums = [5,2,3,1]`

**Output:**
`[1,2,3,5]`

### Example 2

**Input:**
`nums = [5,1,1,2,0,0]`

**Output:**
`[0,0,1,1,2,5]`

---

## Approach

The solution uses **Quick Sort**, which follows the **Divide and Conquer** technique.

A pivot element is selected from the array. In this implementation, the last element is selected as the pivot.

The `partition()` function rearranges the array so that:

- Elements smaller than the pivot are placed on the left.
- The pivot is placed at its correct position.
- Elements greater than or equal to the pivot remain on the right.

After partitioning, Quick Sort is recursively applied to the left and right parts of the array.

---

## Algorithm

### Partition

1. Select the last element as the pivot.
2. Initialize `i = low - 1`.
3. Traverse the array from `low` to `high - 1`.
4. If the current element is smaller than the pivot:
   - Increment `i`.
   - Swap `nums[i]` and `nums[j]`.
5. After traversal, place the pivot at `i + 1`.
6. Return the pivot index.

### Quick Sort

1. If `low >= high`, stop recursion.
2. Partition the array.
3. Recursively sort the left part.
4. Recursively sort the right part.
5. Return the sorted array.

---

## Dry Run

Consider:

`nums = [5,2,3,1]`

### Step 1: Choose Pivot

Last element:

`pivot = 1`

Compare the elements with `1`.

No element is smaller than `1`.

Place pivot at its correct position:

`[1,2,3,5]`

Pivot index:

`0`

Now sort the right part:

`[2,3,5]`

### Step 2: Choose Pivot

Pivot:

`5`

Both `2` and `3` are smaller than `5`.

After partitioning:

`[2,3,5]`

Pivot index:

`3`

### Step 3: Sort Remaining Part

The remaining subarray:

`[2,3]`

Pivot:

`3`

`2 < 3`, so the array remains:

`[2,3]`

Final sorted array:

`[1,2,3,5]`

---

## Code

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

---

## Complexity

Let `n` be the number of elements in the array.

- **Best/Average Time Complexity:** O(n log n)
- **Worst Time Complexity:** O(n²)
- **Space Complexity:** O(log n) average due to recursion stack.
- **Auxiliary Array Space:** O(1)

The worst case occurs when the chosen pivot repeatedly becomes the smallest or largest element, creating highly unbalanced partitions.

---

## Key Concepts

- Quick Sort
- Divide and Conquer
- Partitioning
- Pivot
- Recursion
- In-place Sorting
- Time and Space Complexity

---

## Status

✅ Solved
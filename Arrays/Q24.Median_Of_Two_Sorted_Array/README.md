# Median of Two Sorted Arrays

## Problem Statement

Given two sorted integer arrays `nums1` and `nums2`, find the median of the two arrays after combining them.

The median is:

- The middle element when the total number of elements is odd.
- The average of the two middle elements when the total number of elements is even.

**LeetCode:** 4  
**Difficulty:** Hard

---

## Example

### Example 1

**Input:**
`nums1 = [1,3]`  
`nums2 = [2]`

**Output:**
`2.0`

### Example 2

**Input:**
`nums1 = [1,2]`  
`nums2 = [3,4]`

**Output:**
`2.5`

### Example 3

**Input:**
`nums1 = [0,0]`  
`nums2 = [0,0]`

**Output:**
`0.0`

---

## Approach

The given arrays are sorted, but in this approach we first combine both arrays into a single vector.

Steps:

1. Copy all elements of `nums1` into `arr`.
2. Insert all elements of `nums2` into `arr`.
3. Sort the combined array.
4. Find the middle index using `n / 2`.
5. If the total number of elements is odd, return the middle element.
6. If the total number of elements is even, calculate the average of the two middle elements.

For an even-sized array:

`Median = (arr[mid - 1] + arr[mid]) / 2.0`

Using `2.0` ensures that the result is calculated as a `double`.

---

## Algorithm

1. Create a vector `arr` and copy `nums1` into it.
2. Append all elements of `nums2` to `arr`.
3. Sort `arr`.
4. Calculate `n = arr.size()`.
5. Calculate `mid = n / 2`.
6. If `n` is odd, return `arr[mid]`.
7. Otherwise, return `(arr[mid - 1] + arr[mid]) / 2.0`.
8. Print the median.

---

## Dry Run

Consider:

`nums1 = [1,2]`  
`nums2 = [3,4]`

### Step 1: Combine Arrays

`arr = [1,2,3,4]`

### Step 2: Sort

`arr = [1,2,3,4]`

### Step 3: Find Middle

`n = 4`

`mid = 4 / 2 = 2`

Since `n` is even, we take:

`arr[mid - 1] = arr[1] = 2`

`arr[mid] = arr[2] = 3`

### Step 4: Calculate Median

`Median = (2 + 3) / 2.0`

`Median = 2.5`

Therefore:

`Output = 2.5`

---

## Code

    #include <iostream>
    #include <vector>
    #include <algorithm>
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

        cout << "Enter the size of the first array: ";
        cin >> n1;

        cout << "Enter the size of the second array: ";
        cin >> n2;

        vector<int> nums1(n1), nums2(n2);

        cout << "Enter the elements of the first array: ";
        for (int i = 0; i < n1; i++)
        {
            cin >> nums1[i];
        }

        cout << "Enter the elements of the second array: ";
        for (int i = 0; i < n2; i++)
        {
            cin >> nums2[i];
        }

        double median = findMedianSortedArrays(nums1, nums2);

        cout << "The median of the two sorted arrays is: "
             << median << endl;

        return 0;
    }

---

## Complexity

Let `n` and `m` be the sizes of `nums1` and `nums2`.

- **Time Complexity:** O((n + m) log(n + m))
- **Space Complexity:** O(n + m)

The combined array requires `O(n + m)` extra space, and sorting takes `O((n + m) log(n + m))`.

---

## Key Concepts

- Arrays
- Vectors
- Array Merging
- Sorting
- Median
- Even and Odd Length
- Basic Mathematical Calculation

---

## Status

✅ Solved
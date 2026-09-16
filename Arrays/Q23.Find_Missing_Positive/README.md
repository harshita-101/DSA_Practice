# First Missing Positive

## Problem Statement

Given an unsorted integer array `nums`, find the smallest missing positive integer.

The answer must be a **positive integer**.

**LeetCode:** 41  
**Difficulty:** Hard

---

## Example

### Example 1

**Input:**
`nums = [1,2,0]`

**Output:**
`3`

### Example 2

**Input:**
`nums = [3,4,-1,1]`

**Output:**
`2`

### Example 3

**Input:**
`nums = [7,8,9,11,12]`

**Output:**
`1`

---

## Approach

This approach uses an **unordered_set** to store all elements of the array.

Then start checking from `1` because we need the **smallest positive integer**.

For every positive integer:

- If it exists in the set, move to the next integer.
- If it does not exist, that integer is the smallest missing positive number.

For example:

`nums = [3,4,-1,1]`

Set contains:

`{3,4,-1,1}`

Check:

`1 → Present`  
`2 → Missing`

Therefore, the answer is `2`.

---

## Algorithm

1. Create an `unordered_set`.
2. Insert all elements of `nums` into the set.
3. Initialize `missing = 1`.
4. Check whether `missing` exists in the set.
5. If it exists, increment `missing`.
6. Continue until an integer is not found.
7. Return `missing`.

---

## Dry Run

Consider:

`nums = [3,4,-1,1]`

After inserting elements into the set:

`{3,4,-1,1}`

Start:

`missing = 1`

### Check 1

`1` is present.

So:

`missing = 2`

### Check 2

`2` is not present.

Therefore:

`Answer = 2`

---

## Code

    #include<iostream>
    #include<vector>
    #include<unordered_set>
    using namespace std;

    int findMissingPositive(vector<int>& nums) {
        unordered_set<int> s(nums.begin(), nums.end());
        int missing = 1;

        while (s.count(missing)) {
            missing++;
        }

        return missing;
    }

    int main(){
        int n;
        cout<<"Enter the number of elements in the array: ";
        cin>>n;

        vector<int> nums(n);

        cout<<"Enter the elements of the array: ";
        for(int i=0; i<n; i++){
            cin>>nums[i];
        }

        int missing = findMissingPositive(nums);

        cout<<"The smallest missing positive integer is: "
            <<missing<<endl;

        return 0;
    }

---

## Complexity

Let `n` be the number of elements in the array.

- **Time Complexity:** O(n) average
- **Space Complexity:** O(n)

The `unordered_set` stores the elements of the array.

---

## Key Concepts

- Hash Table
- `unordered_set`
- Array Traversal
- Positive Integer Search
- Hashing
- Missing Element

---

## Status

✅ Solved
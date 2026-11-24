## Problem Statement

Given a binary array `nums`, an operation consists of selecting exactly 3 consecutive elements and flipping them.

Flipping means:
- `0` becomes `1`
- `1` becomes `0`

Find the minimum number of operations required to make all elements equal to `1`.

If it is impossible, return `-1`.

**Example:**

```text
Input:
nums = [0, 1, 1, 1, 0, 0]

Output:
3
```

## Approach: Greedy

We use a Greedy approach and traverse the array from left to right.

- If the current element is `1`, move to the next index.
- If the current element is `0`, flip the current element and the next two elements.
- Before flipping, check whether three elements are available.
- If three elements are not available, return `-1`.
- Increase the operation count after every flip.

**Why Greedy?**

When we encounter `0` at index `i`, we must flip starting from that index. Otherwise, we would not be able to change it later without affecting an already processed element.

## Algorithm / Steps

1. Initialize `count = 0`.
2. Calculate the array size `n`.
3. Traverse the array using a `for` loop.
4. Check whether the current element is `0`.
5. If it is `0`, check whether `i + 2 < n`.
6. If three elements are available:
   - Flip `nums[i]`.
   - Flip `nums[i + 1]`.
   - Flip `nums[i + 2]`.
   - Increment `count`.
7. Otherwise, return `-1`.
8. Return the total operation count.

## Dry Run

**Input:**

```text
nums = [0, 0, 0, 0, 0, 0]
```

**Initial Array:**

```text
[0, 0, 0, 0, 0, 0]
```

**Operation 1:** Flip indices 0, 1, 2.

```text
[1, 1, 1, 0, 0, 0]
```

**Operation 2:** Flip indices 3, 4, 5.

```text
[1, 1, 1, 1, 1, 1]
```

All elements are now equal to `1`.

**Output:**

```text
2
```

## C++ Implementation

```cpp

int minOperations(vector<int>& nums) {
    int count = 0;
    int n = nums.size();

    for (int i = 0; i < n; i++) {
        if (nums[i] == 0) {
            if (i + 2 < n) {
                nums[i] = !nums[i];
                nums[i + 1] = !nums[i + 1];
                nums[i + 2] = !nums[i + 2];

                count++;
            }
            else {
                return -1;
            }
        }
    }

    return count;
}

```

## Time and Space Complexity

| Complexity | Value | Explanation |
|---|---|---|
| Time Complexity | O(n) | Array is traversed once |
| Space Complexity | O(1) | Only constant extra variables are used |

## Key Concepts Learned

- Greedy Algorithm
- Array Traversal
- Bit Manipulation
- Boolean NOT Operator (`!`)
- In-place Array Modification
- Boundary Condition Checking


**Status:** Completed ✅
/**
 * @author : Rohit
 * @date   : 2025-02-12
 * @problem: Intersection of Two Arrays
 * @link   : https://leetcode.com/problems/intersection-of-two-arrays/
 * @level  : Easy
 *
 * @description
 * Given two integer arrays `nums1` and `nums2`, return an array of **their intersection**.
 * Each element in the result **must be unique**, and the result can be returned in **any order**.
 *
 * @approach
 * **Binary Search + Sorting Approach**
 * 1. **Sort the larger array**: We will perform binary search on the sorted array.
 * 2. **Binary Search for Intersection:** Iterate over the smaller array and search each element in the larger array.
 *    - If found, store in an unordered set (to keep unique values).
 * 3. **Convert set to vector** and return the result.
 *
 * @complexity
 * - **Sorting Complexity:** O(n log n) (for sorting the larger array)
 * - **Binary Search Complexity:** O(m log n) (for searching elements)
 * - **Overall Complexity:** **O(n log n + m log n)** where `n` is the larger array and `m` is the smaller one.
 * - **Space Complexity:** O(n) (for storing unique elements in a set)
 *
 * @example
 * **Input:**
 * ```
 * nums1 = [4,9,5], nums2 = [9,4,9,8,4]
 * ```
 * **Output:**
 * ```
 * [4,9]
 * ```
 * **Explanation:**
 * - Common unique elements: `{4,9}`
 *
 * @edge-cases
 * - **No intersection:** `[1, 2, 3]`, `[4, 5, 6]` → Output: `[]`
 * - **Identical arrays:** `[1,2,3]`, `[1,2,3]` → Output: `[1,2,3]`
 * - **Single common element:** `[1,2,3]`, `[3,4,5]` → Output: `[3]`
 */

class Solution
{
public:
    int bS(vector<int> &arr, int target)
    {
        int n = arr.size();
        int low = 0;
        int high = n - 1;

        while (low <= high)
        {
            int mid = (low + high) / 2;

            if (arr[mid] == target)
            {
                return arr[mid];
            }
            else if (arr[mid] < target)
            {
                low = mid + 1;
            }
            else
            {
                high = mid - 1;
            }
        }
        return -1;
    }

    vector<int> intersection(vector<int> &nums1, vector<int> &nums2)
    {
        int n = nums1.size();
        int m = nums2.size();
        unordered_set<int> set1;

        if (n > m)
        {
            sort(nums1.begin(), nums1.end());
        }
        else
        {
            sort(nums2.begin(), nums2.end());
        }

        if (n > m)
        {
            for (int num : nums2)
            {
                int found = bS(nums1, num);
                if (found != -1)
                {
                    set1.insert(found);
                }
            }
        }
        else
        {
            for (int num : nums1)
            {
                int found = bS(nums2, num);
                if (found != -1)
                {
                    set1.insert(found);
                }
            }
        }

        vector<int> result(set1.begin(), set1.end());
        return result;
    }
};
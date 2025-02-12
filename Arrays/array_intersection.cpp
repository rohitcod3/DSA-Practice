/**
 * @author : Rohit
 * @date   : 2025-01-29  // (Ensure to update dynamically)
 * @problem: Intersection of Two Arrays
 * @link   : https://leetcode.com/problems/intersection-of-two-arrays/
 * @level  : Easy
 *
 * @description
 * Given two integer arrays `nums1` and `nums2`, return an array of **their intersection**.
 * Each element in the result **must be unique**, and the result can be returned in **any order**.
 *
 * @approach
 * **Two-Pointer Approach (Sorting + Set)**
 * 1. **Sort both arrays** (`nums1` and `nums2`) → O(n log n + m log m)
 * 2. **Use two pointers** (`i` for `nums1`, `j` for `nums2`):
 *    - If `nums1[i] == nums2[j]`, add to the set and increment both pointers.
 *    - If `nums1[i] < nums2[j]`, increment `i` to move forward.
 *    - If `nums1[i] > nums2[j]`, increment `j` to move forward.
 * 3. **Convert set to vector** to return unique elements.
 *
 * @complexity
 * - **Sorting Complexity:** O(n log n + m log m)
 * - **Two-Pointer Traversal Complexity:** O(n + m)
 * - **Overall Complexity:** **O(n log n + m log m)**
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
    vector<int> intersection(vector<int> &nums1, vector<int> &nums2)
    {
        int n = nums1.size();
        int m = nums2.size();
        int i = 0;
        int j = 0;
        unordered_set<int> set1;

        sort(nums1.begin(), nums1.end());
        sort(nums2.begin(), nums2.end());

        while (i < n && j < m)
        {
            if (nums1[i] == nums2[j])
            {
                set1.insert(nums1[i]);
                i++;
                j++;
            }
            else if (nums1[i] < nums2[j])
            {
                i++;
            }
            else
            {
                j++;
            }
        }

        vector<int> result(set1.begin(), set1.end());
        return result;
    }
};
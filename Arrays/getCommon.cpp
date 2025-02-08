/**
 * @author : Rohit
 * @date   : 2025-02-08
 * @problem: Find the Smallest Common Element in Two Sorted Arrays
 * @link   : https://leetcode.com/problems/minimum-common-value/
 * @level  : Easy
 *
 * @description
 * Given two **sorted** arrays `nums1` and `nums2`, this function finds the **smallest common element** between them.
 * If no common element exists, it returns `-1`.
 *
 * @approach
 * - **Two-pointer technique**:
 *   - Start two pointers `i` and `j` at the beginning of both arrays.
 *   - If `nums1[i] == nums2[j]`, return `nums1[i]` (smallest common element found).
 *   - If `nums1[i] < nums2[j]`, increment `i` (move forward in `nums1`).
 *   - Otherwise, increment `j` (move forward in `nums2`).
 * - The **sorted nature** of arrays ensures that we find the smallest common element **efficiently**.
 *
 * @complexity
 * - **Time Complexity:** O(n + m), where `n` and `m` are the lengths of `nums1` and `nums2`.
 * - **Space Complexity:** O(1), since no extra space is used.
 *
 * @example
 * **Input:**
 * ```
 * nums1 = [1, 2, 3, 6]
 * nums2 = [2, 4, 6, 8]
 * ```
 * **Output:**
 * ```
 * 2
 * ```
 * **Explanation:**
 * - The common elements are `[2, 6]`, and the **smallest** common element is `2`.
 *
 * @edge-cases
 * - If no common element exists, return `-1`.
 * - If arrays have only one element and they match, return that element.
 * - If arrays have different lengths, handle cases where one array is completely traversed.
 */

class Solution
{
public:
    int getCommon(vector<int> &nums1, vector<int> &nums2)
    {
        int i = 0;
        int j = 0;
        while (i < nums1.size() && j < nums2.size())
        {
            if (nums1[i] == nums2[j])
                return nums1[i];

            if (nums1[i] < nums2[j])
            {
                i++;
            }
            else
            {
                j++;
            }
        }
        return -1;
    }
};
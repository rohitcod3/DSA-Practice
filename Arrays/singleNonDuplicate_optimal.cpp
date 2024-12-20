/**
 * @author : Rohit
 * @date   : 2024-12-15
 * @problem: Single Element in a Sorted Array
 * @link   : https://leetcode.com/problems/single-element-in-a-sorted-array/
 * @level  : Medium
 *
 * @description
 * This function finds the single non-duplicate element in a given sorted array `nums`.
 * Each element in the array appears exactly twice except for one element, which appears only once.
 * It uses the XOR bitwise operation to achieve an efficient (O(n)) time complexity and ( O(1) ) space complexity.
 *
 * @approach
 * 1. **XOR Property**:
 *    - XORing a number with itself results in `0`: \( x \oplus x = 0 \).
 *    - XORing a number with `0` results in the number itself: \( x \oplus 0 = x).
 *    - XOR is commutative and associative, so the order of operations does not matter.
 * 2. **Traverse the Array**:
 *    - Iterate through the array and XOR all elements.
 *    - Elements that appear twice cancel each other out, leaving only the single element that appears once.
 * 3. **Return the Result**:
 *    - The resulting value after XORing all elements is the unique element.
 *
 * @complexity
 * Time Complexity: O(n), where `n` is the size of the array.
 * - Single traversal of the array.
 * Space Complexity: O(1), as no additional data structures are used.
 *
 * @example
 * Input: nums = [1, 1, 2, 2, 3]
 * Output: 3
 * Explanation:
 * - Elements 1 and 2 appear twice, so they cancel out.
 * - The single non-duplicate element is 3.
 *
 * Input: nums = [0, 0, 1]
 * Output: 1
 * Explanation:
 * - Element 0 appears twice, so it cancels out.
 * - The single non-duplicate element is 1.
 */

class Solution
{
public:
    int singleNonDuplicate(vector<int> &nums)
    {
        int n = nums.size();
        int XOR = 0;

        for (int i = 0; i < n; i++)
        {
            XOR = XOR ^ nums[i];
        }
        return XOR;
    }
};
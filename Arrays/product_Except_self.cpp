/**
 * @author : Rohit
 * @date   : 2025-02-13
 * @problem: Product of Array Except Self
 * @link   : https://leetcode.com/problems/product-of-array-except-self/
 * @level  : Medium
 *
 * @description
 * Given an integer array `nums`, return an array `answer` such that `answer[i]` is **the product of all elements** in `nums` **except nums[i]`.
 * The algorithm must run in `O(n)`.
 *
 * @approach
 * **Using Division with Zero Handling**
 * 1. **Compute the total product of nonzero elements**.
 * 2. **Count the number of zeros**:
 *    - If **more than one zero exists**, every index must be `0` in the result.
 *    - If **one zero exists**, only the position of `0` will have a nonzero value, the rest will be `0`.
 *    - Otherwise, apply the **division rule** to compute results normally.
 *
 * @complexity
 * - **Time Complexity:** O(n) (One pass for computing product, another for result array)
 * - **Space Complexity:** O(1) (excluding output storage)
 *
 * @example
 * **Input:** nums = `[1,2,3,4]`
 * **Output:** `[24,12,8,6]`
 * **Explanation:** Each index stores the product of all elements except `nums[i]`.
 *
 * **Edge Cases:**
 * - **Contains one zero:** `[0,1,2,3]` → Output: `[6,0,0,0]`
 * - **Multiple zeros:** `[0,0,3,4]` → Output: `[0,0,0,0]`
 * - **Single-element array:** `[1]` → Output: `[1]`
 */

class Solution
{
public:
    vector<int> productExceptSelf(vector<int> &nums)
    {
        int n = nums.size();

        int count_zero = 0;
        int product_without_zero = 1;

        for (int &num : nums)
        {
            if (num == 0)
            {
                count_zero++;
            }
            else
            {
                product_without_zero *= num;
            }
        }
        vector<int> result(n);

        for (int i = 0; i < n; i++)
        {
            int num = nums[i];

            if (num != 0)
            {
                if (count_zero > 0)
                {
                    result[i] = 0;
                }
                else
                {
                    result[i] = product_without_zero / nums[i];
                    a
                }
            }
            else
            { // num == 0
                if (count_zero > 1)
                {
                    result[i] = 0;
                }
                else
                {
                    result[i] = product_without_zero;
                }
            }
        }
        return result;
    }
};
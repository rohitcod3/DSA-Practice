/**
 * @author : Rohit
 * @date   : 2025-02-14
 * @problem: Product of Array Except Self (Prefix & Suffix Multiplication)
 * @link   : https://leetcode.com/problems/product-of-array-except-self/
 * @level  : Medium
 *
 * @description
 * Given an integer array `nums`, return an array `answer` where `answer[i]` is the product of all elements in `nums` **except nums[i]`, without using division.
 * The algorithm must run in **O(n)**.
 *
 * @approach
 * **Using Prefix & Suffix Multiplication**
 * 1. **Compute Prefix Products:**
 *    - `result[i] = result[i-1] * nums[i-1]`
 *    - This stores the product of all elements to the **left** of `nums[i]`.
 * 2. **Compute Suffix Products (in reverse pass):**
 *    - Multiply `result[i]` with a running `rightProduct`, which stores the product of elements to the **right**.
 *    - Update `rightProduct` for the next iteration.
 *
 * @complexity
 * - **Time Complexity:** O(n) (Two passes: prefix + suffix)
 * - **Space Complexity:** O(1) (Modifies `result` in-place)
 *
 * @example
 * **Input:** nums = `[1,2,3,4]`
 * **Output:** `[24,12,8,6]`
 * **Explanation:**
 * - Prefix Pass: `[1, 1, 2, 6]`
 * - Suffix Pass: `[24,12,8,6]` (by multiplying with `rightProduct`).
 *
 * **Edge Cases:**
 * - **Contains zero:** `[0,1,2,3]` → Output: `[6,0,0,0]`
 * - **All ones:** `[1,1,1,1]` → Output: `[1,1,1,1]`
 */

class Solution
{
public:
    vector<int> productExceptSelf(vector<int> &nums)
    {
        int n = nums.size();

        vector<int> result(n);

        result[0] = 1;
        for (int i = 1; i < n; i++)
        {
            result[i] = nums[i - 1] * result[i - 1];
        }

        int rightProduct = 1;

        for (int i = n - 1; i >= 0; i--)
        {
            result[i] = result[i] * rightProduct;
            rightProduct *= nums[i];
        }
        return result;
    }
};
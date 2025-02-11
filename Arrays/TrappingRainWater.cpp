/**
 * @author : Rohit
 * @date   : 2025-02-11
 * @problem: Trapping Rain Water
 * @link   : https://leetcode.com/problems/trapping-rain-water/
 * @level  : Hard
 *
 * @description
 * Given an elevation map represented by an array `height` where `height[i]` represents the height
 * of a bar, this function computes **the total water trapped** between the bars after raining.
 *
 * @approach
 * **Prefix Maximum Arrays Approach**
 * 1. **Precompute Left Max Array:** Store the max height encountered from **left to right**.
 * 2. **Precompute Right Max Array:** Store the max height encountered from **right to left**.
 * 3. **Calculate Trapped Water:** For each bar at index `i`:
 *    - Compute **minimum of left and right max heights**.
 *    - Subtract the height of the current bar from this value.
 *    - Add the result to `sum` (only positive values contribute).
 *
 * @complexity
 * - **Time Complexity:** O(n) - Two passes for prefix arrays + one for final sum.
 * - **Space Complexity:** O(n) - Two extra arrays (`leftMax` and `rightMax`).
 *
 * @example
 * **Input:**
 * ```
 * height = [0,1,0,2,1,0,1,3,2,1,2,1]
 * ```
 * **Output:**
 * ```
 * 6
 * ```
 * **Explanation:**
 * - Left max:  `[0,1,1,2,2,2,2,3,3,3,3,3]`
 * - Right max: `[3,3,3,3,3,3,3,3,2,2,2,1]`
 * - Water trapped: `6` units
 *
 * @edge-cases
 * - **No trapping possible:** `[0, 1, 2, 3] → Output: 0`
 * - **Flat surface:** `[1, 1, 1, 1] → Output: 0`
 * - **High walls with a dip:** `[3, 0, 3] → Output: 3`
 */

class Solution
{
public:
    vector<int> getLeftMaxArray(vector<int> &height, int &n)
    {
        vector<int> leftMax(n);
        leftMax[0] = height[0];

        for (int i = 1; i < n; i++)
        {
            leftMax[i] = max(leftMax[i - 1], height[i]);
        }
        return leftMax;
    }

    vector<int> getRightMaxArray(vector<int> &height, int &n)
    {
        vector<int> rightMax(n);
        rightMax[n - 1] = height[n - 1];

        for (int i = n - 2; i >= 0; i--)
        {
            rightMax[i] = max(rightMax[i + 1], height[i]);
        }
        return rightMax;
    }
    int trap(vector<int> &height)
    {
        int n = height.size();
        vector<int> leftMax = getLeftMaxArray(height, n);
        vector<int> rightMax = getRightMaxArray(height, n);

        int sum = 0;

        for (int i = 0; i < n; i++)
        {

            int h = min(leftMax[i], rightMax[i]) - height[i];

            sum += h;
        }
        return sum;
    }
};
/**
 * @author : Rohit
 * @date   : 2025-02-20
 * @problem: Container With Most Water (Max Area)
 * @link   : https://leetcode.com/problems/container-with-most-water/
 * @level  : Medium
 *
 * @description
 * Given an array of non-negative integers `height` representing the heights of vertical lines drawn
 * on the x-axis, this function computes the maximum area of water a container can store.
 * The container is formed by two lines and the x-axis. The area is determined by the shorter line and
 * the distance between the two lines.
 *
 * @approach
 * 1. **Two-Pointer Technique:**
 *    - Initialize two pointers: `i` at the start and `j` at the end of the array.
 * 2. **Calculate Area:**
 *    - For the current pair, compute:
 *         width = j - i
 *         height = min(height[i], height[j])
 *         area = width * height
 *    - Update the maximum area (`maxWater`) encountered.
 * 3. **Adjust Pointers:**
 *    - Move the pointer at the smaller height inward:
 *         - If height[i] > height[j], decrement `j`.
 *         - Otherwise, increment `i`.
 * 4. **Return Result:**
 *    - After the loop terminates, `maxWater` holds the maximum area.
 *
 * @complexity
 * - **Time Complexity:** O(n), where n is the number of elements in `height`.
 *   - Each element is processed at most once.
 * - **Space Complexity:** O(1), as the algorithm uses a constant amount of extra space.
 *
 * @example
 * **Input:** height = [1,8,6,2,5,4,8,3,7]
 * **Output:** 49
 * **Explanation:**
 * - The container formed by the lines at index 1 (height=8) and index 8 (height=7) yields the maximum area.
 *
 * **Edge Cases:**
 * - **All equal heights:** [5,5,5,5] → Maximum area is computed using the farthest lines.
 * - **Single high pillar:** [1,2,100,2,1] → The area is limited by the lower heights at the edges.
 */
class Solution
{
public:
    int maxArea(vector<int> &height)
    {
        int n = height.size();
        int i = 0, j = n - 1;
        int maxWater = 0;

        while (i < j)
        {
            int width = j - i;
            int h = min(height[i], height[j]);
            int area = width * h;
            maxWater = max(maxWater, area);

            if (height[i] > height[j])
            {
                j--;
            }
            else
            {
                i++;
            }
        }
        return maxWater;
    }
};

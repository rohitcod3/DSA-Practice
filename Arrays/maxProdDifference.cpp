/**
 * @author : Rohit
 * @date   : 2024-11-30
 * @problem: Maximum Product Difference Between Two Pairs
 * @link   : https://leetcode.com/problems/maximum-product-difference-between-two-pairs/
 * @level  : Easy
 *
 * @description
 * This function calculates the maximum product difference between two pairs of elements in the array `nums`.
 * The product difference is defined as:
 *   (Product of two largest elements) - (Product of two smallest elements).
 *
 * @approach
 * 1. Initialize variables to track the largest, second largest, smallest, and second smallest elements:
 *    - `largest` and `secondLargest` track the two largest elements.
 *    - `smallest` and `secondSmallest` track the two smallest elements.
 * 2. Traverse the array:
 *    - Update the largest and second largest elements as needed.
 *    - Update the smallest and second smallest elements as needed.
 * 3. Return the product difference:
 *    - `(largest * secondLargest) - (smallest * secondSmallest)`.
 *
 * @complexity
 * Time Complexity: O(n) - Single traversal of the array to identify largest and smallest elements.
 * Space Complexity: O(1) - No additional space used beyond a few variables.
 *
 * @example
 * Input: nums = [5, 6, 2, 7, 4]
 * Output: 34
 * Explanation:
 * - Largest elements: 7, 6
 * - Smallest elements: 2, 4
 * - Product difference: (7 * 6) - (2 * 4) = 42 - 8 = 34.
 *
 */

class Solution
{
public:
    int maxProductDifference(vector<int> &nums)
    {
        int n = nums.size();
        int largest = INT_MIN;
        int secondLargest = INT_MIN;

        int smallest = INT_MAX;
        int secondSmallest = INT_MAX;

        for (int &num : nums)
        {

            if (num > largest)
            {
                secondLargest = largest;
                largest = num;
            }
            else
            {
                secondLargest = max(secondLargest, num);
            }

            // to track second smallest

            if (num < smallest)
            {
                secondSmallest = smallest;
                smallest = num;
            }
            else
            {
                secondSmallest = min(secondSmallest, num);
            }
        }

        return (largest * secondLargest) - (smallest * secondSmallest);
    }
};
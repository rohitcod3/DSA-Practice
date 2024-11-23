/**
 * @author : Rohit
 * @date   : 2024-11-21
 * @problem: Majority Element
 * @link   : https://leetcode.com/problems/majority-element/
 * @level  : Easy
 *
 * @description
 * This function finds the majority element in an array `v`, where the majority element is defined as an element
 * that appears more than `n/2` times. If no such element exists, the function returns -1.
 * The solution uses the Boyer-Moore Voting Algorithm to find a candidate element in O(n) time
 * and O(1) space. It then verifies if the candidate is indeed the majority element.
 *
 * @approach
 * 1. Applying Boyer-Moore's Voting Algorithm
 * 2. Verifying the Candidate
 *
 *
 * 1. Boyer-Moore Voting Algorithm:
 *    - Maintain a count (`cnt`) and a candidate element (`el`).
 *    - Traverse the array:
 *      - If `cnt` is 0, set the current element as the candidate and reset `cnt` to 1.
 *      - If the current element matches the candidate, increment `cnt`.
 *      - Otherwise, decrement `cnt`.
 * 2. Verify the Candidate:
 *    - Count the occurrences of the candidate in the array.
 *    - If the count exceeds `n/2`, return the candidate as the majority element.
 *    - Otherwise, return -1.
 *
 * @complexity
 * Time Complexity: O(n) - One pass to find the candidate, another to verify it.
 * Space Complexity: O(1) - No additional space used.
 */

class Solution
{
public:
    int majorityElement(vector<int> &nums)
    {
        int cnt = 0;
        int el;
        int n = nums.size();
        for (int i = 0; i < n; i++)
        {
            if (cnt == 0)
            {
                cnt = 1;
                el = nums[i];
            }
            else if (nums[i] == el)
            {
                cnt++;
            }
            else
            {
                cnt--;
            }
        }
        int cnt1 = 0;
        for (int i = 0; i < n; i++)
        {
            if (nums[i] == el)
                cnt1++;
        }
        if (cnt1 > n / 2)
        {
            return el;
        }
        return -1;
    }
};
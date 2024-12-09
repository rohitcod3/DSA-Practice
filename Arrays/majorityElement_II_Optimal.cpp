/**
 * @author : Rohit
 * @date   : 2024-21-09
 * @problem: Majority Element II
 * @link   : https://leetcode.com/problems/majority-element-ii/
 * @level  : Medium
 *
 * @description
 * This function finds all elements in the array `nums` that appear more than `n/3` times,
 * where `n` is the size of the array. It uses the Boyer-Moore Voting Algorithm, which
 * identifies up to two potential candidates and validates their actual counts.
 *
 * @approach
 * 1. **Candidate Selection (Phase 1)**:
 *    - Use two counters (`cnt1`, `cnt2`) and two elements (`el1`, `el2`) to track candidates.
 *    - Iterate through the array:
 *      - Assign or increment counts for candidates.
 *      - Decrement both counters if no match is found.
 * 2. **Validation (Phase 2)**:
 *    - Reset counters and count the actual occurrences of `el1` and `el2`.
 *    - Add candidates to the result list if their counts exceed `n/3`.
 *
 * @complexity
 * Time Complexity: O(n), as the array is traversed twice (once for selection, once for validation).
 * Space Complexity: O(1), as only a few variables are used for tracking candidates and counts.
 *
 * @example
 * Input: nums = [3, 2, 3]
 * Output: [3]
 * Explanation:
 * - Element 3 appears more than n/3 = 3/3 = 1 times.
 *
 * Input: nums = [1, 1, 1, 3, 3, 2, 2, 2]
 * Output: [1, 2]
 * Explanation:
 * - Elements 1 and 2 both appear more than n/3 = 8/3 = 2.66 times.
 */

vector<int> majorityElement(vector<int> &nums)
{
    int cnt1 = 0, cnt2 = 0;
    int el1 = INT_MIN, el2 = INT_MIN;

    // Phase 1: Candidate Selection
    for (int i = 0; i < nums.size(); i++)
    {
        if (cnt1 == 0 && nums[i] != el2)
        {
            cnt1 = 1;
            el1 = nums[i];
        }
        else if (cnt2 == 0 && nums[i] != el1)
        {
            cnt2 = 1;
            el2 = nums[i];
        }
        else if (el1 == nums[i])
        {
            cnt1++;
        }
        else if (el2 == nums[i])
        {
            cnt2++;
        }
        else
        {
            cnt1--;
            cnt2--;
        }
    }

    // Phase 2: Validation
    vector<int> ls;
    cnt1 = 0, cnt2 = 0;

    for (int i = 0; i < nums.size(); i++)
    {
        if (el1 == nums[i])
            cnt1++;
        if (el2 == nums[i])
            cnt2++;
    }

    int mini = (int)(nums.size() / 3) + 1;
    if (cnt1 >= mini)
        ls.push_back(el1);
    if (cnt2 >= mini)
        ls.push_back(el2);

    return ls;
}

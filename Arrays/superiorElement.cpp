/**
 * @author : Rohit
 * @date   : 2024-11-29
 * @problem: Superior Elements
 * @link   : (https://www.naukri.com/code360/problems/superior-elements_6783446?leftPanelTabValue=SUBMISSION)
 * @level  : Easy
 *
 * @approach
 * 1. Initialize `maxi` to `INT_MIN`.
 * 2. Traverse the array from right to left:
 *    - If the current element is greater than `maxi`, add it to the result array.
 *    - Update `maxi` with the maximum of the current element and `maxi`.
 * 3. Sort the result array in ascending order before returning it.
 *
 * @complexity
 * Time Complexity:
 * - Traversal: O(n)
 * - Sorting: O(n log n), where `n` is the number of superior elements.
 * Space Complexity: O(n), where `n` is the size of the result array.
 *
 * @example
 * Input: a = [2, 4, 3, 1, 5]
 * Output: [3, 5]
 * Explanation:
 * - Superior elements: 5 (greater than all elements to its right)
 * - Sorted result: [5].
 */

vector<int> superiorElements(vector<int> &a)
{
    vector<int> ans;
    int maxi = INT_MIN;
    int n = a.size();
    for (int i = n - 1; i >= 0; i--)
    {
        if (a[i] > maxi)
        {
            ans.push_back(a[i]);
        }
        maxi = max(maxi, a[i]);
    }

    sort(ans.begin(), ans.end());
    return ans;
}

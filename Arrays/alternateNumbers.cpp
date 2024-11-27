/**
 * @author : Rohit
 * @date   : 2024-11-21
 * @problem: Alternate Numbers with Positive and Negative Values
 * @link   : (https://www.naukri.com/code360/problems/alternate-numbers_6783445?leftPanelTabValue=PROBLEM)
 * @level  : Easy
 *
 * @description
 * This function rearranges the elements of an array such that positive and negative integers alternate,
 * while preserving their relative order. If there are extra positive or negative numbers, they are appended
 * at the end of the array in their original order.
 *
 * @approach
 * 1. Separate the array into two vectors, `pos` (for positive integers) and `neg` (for negative integers).
 * 2. Compare the sizes of `pos` and `neg`:
 *    - If `pos` is larger:
 *      - Alternate elements from `pos` and `neg` into the array until `neg` is exhausted.
 *      - Append the remaining positive integers to the end of the array.
 *    - If `neg` is larger:
 *      - Alternate elements from `pos` and `neg` into the array until `pos` is exhausted.
 *      - Append the remaining negative integers to the end of the array.
 * 3. Return the rearranged array.
 *
 * @complexity
 * Time Complexity: O(n) - Single traversal to separate positive and negative numbers, and another traversal for rearranging.
 * Space Complexity: O(n) - Additional space for the `pos` and `neg` vectors.
 *
 * @example
 * Input: a = [3, -1, 2, -2, 5, -4, -6]
 * Output: [3, -1, 2, -2, 5, -4, -6]
 * Explanation: Positive and negative integers alternate, and the remaining negative number is appended at the end.
 */

vector<int> alternateNumbers(vector<int> &a)
{
    int n = a.size();
    vector<int> pos, neg;
    for (int i = 0; i < n; i++)
    {
        if (a[i] > 0)
        {
            pos.push_back(a[i]);
        }
        else
        {
            neg.push_back(a[i]);
        }
    }

    if (pos.size() > neg.size())
    {
        for (int i = 0; i < neg.size(); i++)
        {
            a[2 * i] = pos[i];
            a[2 * i + 1] = neg[i];
        }
        int index = neg.size() * 2;
        for (int i = neg.size(); i < pos.size(); i++)
        {
            a[index] = pos[i];
            index++;
        }
    }
    else
    {
        for (int i = 0; i < pos.size(); i++)
        {
            a[2 * i] = pos[i];
            a[2 * i + 1] = neg[i];
        }
        int index = pos.size() * 2;
        for (int i = pos.size(); i < neg.size(); i++)
        {
            a[index] = neg[i];
            index++;
        }
    }
    return a;
}
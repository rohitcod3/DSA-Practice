/**
 * @author : Rohit
 * @link   : https://www.naukri.com/code360/problems/reading_6845742?leftPanelTabValue=SUBMISSION
 * @level  : Easy
 *
 * @description
 * This function checks if there exist two numbers in a sorted array that add up to a given target.
 * It uses a two-pointer approach for an efficient solution.
 *
 * @approach
 * 1. Sort the input array.
 * 2. Use two pointers, starting at the beginning (left) and the end (right) of the array.
 * 3. Adjust pointers based on the sum of the numbers at the two indices.
 *    - If the sum equals the target, return "YES".
 *    - If the sum is less than the target, move the left pointer forward.
 *    - If the sum is greater than the target, move the right pointer backward.
 * 4. Return "NO" if no such pair is found.
 *
 * Time Complexity: O(n log n) (for sorting) + O(n) (for two-pointer traversal) = O(n log n)
 * Space Complexity: O(1) (in-place operations with no additional data structures)
 */

string read(int n, vector<int> book, int target)
{
    int left = 0, right = n - 1;
    sort(book.begin(), book.end());

    while (left < right)
    {
        int sum = book[left] + book[right];
        if (sum == target)
        {
            return "YES";
        }
        else if (sum < target)
            left++;
        else
            right--;
    }
    return "NO";
}
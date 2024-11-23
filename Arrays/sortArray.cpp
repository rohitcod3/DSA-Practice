/**
 * @author : Rohit
 * @date   : 2024-11-22
 * @problem: Sort Array of 0s, 1s, and 2s
 * @link   : (https://www.naukri.com/code360/problems/sort-an-array-of-0s-1s-and-2s_892977?leftPanelTabValue=PROBLEM)
 * @level  : Easy
 *
 * @complexity
 * Used the Dutch National Flag algorithm for efficient sorting.
 * Time Complexity: O(n) - Single pass through the array.
 * Space Complexity: O(1) - In-place sorting without extra space.
 * Handles arrays with mixed 0s, 1s, and 2s effectively.
 */

void sortArray(vector<int> &arr, int n)
{
    int low = 0, mid = 0, high = n - 1;
    while (mid <= high)
    {
        if (arr[mid] == 0)
        {
            swap(arr[low], arr[mid]);
            low++;
            mid++;
        }
        else if (arr[mid] == 1)
        {
            mid++;
        }
        else
        {
            swap(arr[mid], arr[high]);
            high--;
        }
    }
}

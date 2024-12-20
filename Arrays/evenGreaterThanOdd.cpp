/**
 * @author : Rohit
 * @date   : 2024-12-21
 * @problem: Rearrange Array Alternately
 * @link   : https://www.geeksforgeeks.org/rearrange-array-such-that-even-positioned-are-greater-than-odd/
 * @level  : Easy
 *
 * @description
 * This function rearranges the elements of the input array `arr` alternately such that:
 * - The smaller value is placed at odd indices.
 * - The larger value is placed at even indices.
 * - Each value at an even index is greater than the previous value at the odd index.
 *
 * The input array is first sorted, and then elements are placed alternately using two pointers:
 * - One pointer (`left`) starts at the smallest element.
 * - Another pointer (`right`) starts at the largest element.
 * - The smaller element is placed at the odd index, and the larger element is placed at the even index.
 *
 * @approach
 * 1. **Sort the Array**:
 *    - Sort the array to ensure smallest and largest elements are easily accessible.
 * 2. **Two Pointer Traversal**:
 *    - Use a `left` pointer starting at the smallest element and a `right` pointer starting at the largest.
 *    - Traverse the array, placing elements alternately using these two pointers:
 *      - Odd indices get the smallest elements.
 *      - Even indices get the largest elements.
 * 3. **Construct Result**:
 *    - Store the rearranged elements in a new array and return it.
 *
 * @complexity
 * Time Complexity: O(n log n), where `n` is the size of the array.
 * - Sorting takes \( O(n \log n) \).
 * - Rearranging the elements takes \( O(n) \).
 * Space Complexity: O(n), for the result array.
 *
 * @example
 * Input: arr = [1, 3, 2, 4, 5, 6]
 * Output: [1, 6, 2, 5, 3, 4]
 * Explanation:
 * - After sorting: [1, 2, 3, 4, 5, 6].
 * - Arrange alternately: [1 (smallest), 6 (largest), 2 (next smallest), 5 (next largest), ...].
 *
 * Input: arr = [10, 20, 30, 40]
 * Output: [10, 40, 20, 30]
 * Explanation:
 * - After sorting: [10, 20, 30, 40].
 * - Arrange alternately: [10 (smallest), 40 (largest), 20 (next smallest), 30 (next largest)].
 */

class Solution
{
public:
    vector<int> rearrangeArray(vector<int> &arr)
    {
        int n = arr.size();
        sort(arr.begin(), arr.end());

        vector<int> result(n);
        int left = 0;
        int right = n - 1;

        for (int i = 0; i < n; i++)
        {
            if ((i + 1) % 2 == 0)
            {
                result[i] = arr[right--];
            }
            else
            {
                result[i] = arr[left++];
            }
        }
        return result;
    }
};

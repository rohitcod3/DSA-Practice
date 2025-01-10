/**
 * @author : Rohit
 * @date   : 2025-01-09
 * @problem: Median of Two Sorted Arrays (Optimized Approach)
 * @link   : https://leetcode.com/problems/median-of-two-sorted-arrays/
 * @level  : Hard
 *
 * @description
 * This function finds the median of two sorted arrays `nums1` and `nums2` without fully merging them.
 *
 * The median is determined by iterating through both arrays simultaneously and keeping track of the middle elements.
 *
 * @approach
 * 1. **Track Median Elements**:
 *    - Use two pointers `i` and `j` to iterate through `nums1` and `nums2`.
 *    - Maintain a `cnt` variable to track the position in the merged sorted sequence.
 *    - Identify the two middle elements:
 *      - `ind1 = n / 2` (middle index if the total length is odd).
 *      - `ind2 = (n / 2) - 1` (second middle index if the total length is even).
 * 2. **Iterate Through Both Arrays**:
 *    - Compare elements from both arrays and increment the pointer of the smaller element.
 *    - Assign `el1` and `el2` when `cnt` matches `ind1` and `ind2`.
 * 3. **Handle Remaining Elements**:
 *    - If one array is exhausted, continue iterating through the other to find `el1` and `el2`.
 * 4. **Calculate Median**:
 *    - If the total number of elements is odd, return `el1` as the median.
 *    - If even, return the average of `el1` and `el2`.
 *
 * @complexity
 * Time Complexity: O(n1 + n2), where `n1` and `n2` are the sizes of `nums1` and `nums2`.
 * Space Complexity: O(1), as no additional data structures are used.
 *
 * @example
 * Input: nums1 = [1, 3], nums2 = [2]
 * Output: 2.0
 * Explanation:
 * - Merged sequence: [1, 2, 3].
 * - Median: 2.
 *
 * Input: nums1 = [1, 2], nums2 = [3, 4]
 * Output: 2.5
 * Explanation:
 * - Merged sequence: [1, 2, 3, 4].
 * - Median: (2 + 3) / 2 = 2.5.
 */

double median(vector<int> &nums1, vector<int> &nums2)
{
    int i = 0;
    int j = 0;
    int cnt = 0;
    int n1 = nums1.size();
    int n2 = nums2.size();
    int n = n1 + n2;
    int ind1 = n / 2;
    int ind2 = (n / 2) - 1;
    int el1 = -1, el2 = -1;

    while (i < n1 && j < n2)
    {

        if (nums[i] < nums[j])
        {
            if (cnt == ind1)
                el1 = nums[i];
            if (cnt == ind2)
                el2 = nums[i];
            cnt++;
            i++;
        }
        else
        {
            if (cnt == ind1)
                el1 = nums[j];
            if (cnt == ind2)
                el2 = nums[j];
            cnt++;
            j++;
        }
    }

    while (i < n1)
    {
        if (cnt == ind1)
            el1 = nums[i];
        if (cnt == ind2)
            el2 = nums[i];
        i++;
        cnt++;
    }

    while (j < n2)
    {
        if (cnt == ind1)
            el1 = nums[j];
        if (cnt == ind2)
            el2 = nums[j];
        cnt++;
        j++;
    }

    if (n % 2 == 1)
    {
        return ind2;
    }

    return (double)((double)(el1 + el2)) / 2.0;
}
/**
 * @author : Rohit
 * @date   : 2024-11-27
 * @problem: Destination City
 * @link   : https://leetcode.com/problems/destination-city/
 * @level  : Easy
 *
 * @description
 * This function finds the destination city in a list of paths, where each path is represented as a pair of strings
 * [source, destination]. A destination city is defined as the city that is not a source city in any path.
 *
 * @approach
 * 1. Use an unordered map (`mpp`) to track all source cities:
 *    - Traverse the paths and mark all source cities with a value (e.g., 1) in the map.
 * 2. Traverse the paths again and check each destination city:
 *    - If the destination city does not exist as a source in the map, return it as the destination city.
 * 3. If no such city is found (edge case), return an empty string.
 *
 * @complexity
 * Time Complexity: O(n) - Two traversals of the paths list.
 * Space Complexity: O(n) - Space used by the unordered map to store source cities.
 *
 * @example
 * Input: paths = [["London", "New York"], ["New York", "Los Angeles"], ["Los Angeles", "San Francisco"]]
 * Output: "San Francisco"
 * Explanation: San Francisco is not a source city in any of the paths.
 */

class Solution
{
public:
    string destCity(vector<vector<string>> &paths)
    {
        unordered_map<string, int> mpp;

        for (auto &path : paths)
        {
            string source = path[0];

            mpp[source] = 1;
        }

        for (auto &path : paths)
        {
            string dest = path[1];

            if (mpp[dest] != 1)
            {
                return dest;
            }
        }
        return "";
    }
};
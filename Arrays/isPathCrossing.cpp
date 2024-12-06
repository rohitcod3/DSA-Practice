/**
 * @author : Rohit
 * @date   : 2024-12-06
 * @problem: Path Crossing
 * @link   : https://leetcode.com/problems/path-crossing/
 * @level  : Easy
 *
 * @description
 * This function determines if a given path crosses itself.
 * The path is described as a string where:
 * - 'N' represents moving north (incrementing `y`).
 * - 'S' represents moving south (decrementing `y`).
 * - 'E' represents moving east (incrementing `x`).
 * - 'W' represents moving west (decrementing `x`).
 *
 * If the path revisits a coordinate already visited, the function returns `true`. Otherwise, it returns `false`.
 *
 * @approach
 * 1. Use a set to store visited coordinates.
 * 2. Start at the origin (0, 0) and process each character in the path:
 *    - Update the current position (`x`, `y`) based on the direction.
 *    - Convert the position into a string key (e.g., "x_y") to uniquely identify it.
 *    - Check if the key exists in the set:
 *      - If yes, the path crosses itself. Return `true`.
 *      - Otherwise, add the key to the set.
 * 3. If the loop completes without finding a crossing, return `false`.
 *
 * @complexity
 * Time Complexity: O(n), where `n` is the length of the path string.
 * Space Complexity: O(n), for storing up to `n` unique coordinates in the set.
 *
 */

class Solution
{
public:
    bool isPathCrossing(string path)
    {
        unordered_set<string> st;
        int x = 0;
        int y = 0;
        string key = to_string(x) + "_" + to_string(y);
        st.insert(key);

        for (char &ch : path)
        {
            if (ch == 'E')
            {
                x++;
            }
            else if (ch == 'W')
            {
                x--;
            }
            else if (ch == 'N')
            {
                y++;
            }
            else
            {
                y--;
            }
            key = to_string(x) + "_" + to_string(y);
            if (st.find(key) != st.end())
            {
                return true;
            }

            st.insert(key);
        }

        return false;
    }
};
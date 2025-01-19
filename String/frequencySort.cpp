
/**
 * @author : Rohit
 * @date   : 2025-01-19
 * @problem: Sort Characters by Frequency
 * @link   : https://leetcode.com/problems/sort-characters-by-frequency/
 * @level  : Medium
 *
 * @description
 * This function sorts the characters in a string `s` based on their frequency in descending order.
 * Characters with higher frequency appear earlier in the result string. If two characters have the same frequency, their order does not matter.
 *
 * @approach
 * 1. **Frequency Map**:
 *    - Use an unordered_map to store the frequency of each character in the string `s`.
 * 2. **Convert Map to Vector**:
 *    - Transfer the frequency map into a vector of pairs for sorting.
 * 3. **Custom Sorting**:
 *    - Sort the vector in descending order based on the frequency of characters using a custom comparator.
 * 4. **Reconstruct the String**:
 *    - Append each character to the result string as many times as its frequency.
 *
 * @complexity
 * Time Complexity: O(n + k log k), where `n` is the length of the string and `k` is the number of unique characters.
 * - Building the frequency map takes O(n).
 * - Sorting the frequency vector takes O(k log k).
 * Space Complexity: O(k), for the frequency map and the vector.
 *
 * @example
 * Input: s = "tree"
 * Output: "eert"
 * Explanation:
 * - 'e' appears twice, and 'r' and 't' appear once each.
 * - The result is "eert", but "eetr" is also valid.
 *
 * Input: s = "cccaaa"
 * Output: "aaaccc"
 * Explanation:
 * - 'c' appears 3 times, and 'a' appears 3 times.
 * - The order of 'a' and 'c' doesn't matter as long as they are grouped together.
 */
class Solution
{
public:
    string frequencySort(string s)
    {
        unordered_map<char, int> freqMap;
        for (char c : s)
            freqMap[c]++;
        vector<pair<char, int>> freqVector(freqMap.begin(), freqMap.end());
        sort(freqVector.begin(), freqVector.end(), [](pair<char, int> &a, pair<char, int> &b)
             { return b.second < a.second; });

        string result;

        for (auto &[ch, freq] : freqVector)
            result.append(freq, ch);
        return result;
    }
};
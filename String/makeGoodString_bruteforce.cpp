/*
* I was wondering how I can solve this problem with a *brute force approach , just to practice with the
*loops so I came up with this o(n^2) time complexicty *solution
*
*
*Problem link: https://leetcode.com/problems/make-the-string-great/
*
*
* Approach: The while loop keeps looping until all the *adjacent elements with the condition s[i] and s[i+1] *with one being lowercase and the other being uppercase *and vice versa are removed and the inner for loop *keeps iterating over the new string after removing the *elements which satify this condition, until there *aren't any left.
*
*
*Example 1:
*
*Input: s = "leEeetcode"
*Output: "leetcode"
*Explanation: In the first step, either you choose i = *1 or i = 2, both will result "leEeetcode" to be *reduced to "leetcode".
*Example 2:

*Input: s = "abBAcC"
*Output: ""
*Explanation: We have many possible scenarios, and all *lead to the same answer. For example:
*"abBAcC" --> "aAcC" --> "cC" --> ""
*"abBAcC" --> "abBA" --> "aA" --> ""
*
*
*/

string makeStringGood(string s)
{
    bool changed = true;

    while (changed)
    {
        changed = false;

        for (int i = 0; i < s.length() - 1; i++)
        {
            if (abs(s[i] - s[i + 1]) == 32)
            {
                s.erase(i, 2);
                changed = true;
                break;
            }
        }
    }
    return s;
}
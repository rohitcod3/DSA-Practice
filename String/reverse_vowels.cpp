// In order to reverse vowels in a string, we implement two pointers,the moment both pointer have a vowel, we swap them and move i and reduce j pointer.
//
// T.C => O(n)
//
// S.C => O(1)
//
// Link: https://leetcode.com/problems/reverse-vowels-of-a-string/
//
// Diffculity: Easy
//

class Solution
{
public:
    bool isVowel(char &ch)
    {
        if (ch == 'a' || ch == 'e' || ch == 'i' || ch == 'o' || ch == 'u' || ch == 'A' || ch == 'E' || ch == 'I' || ch == 'O' || ch == 'U')
            return true;
        return false;
    }
    string reverseVowels(string s)
    {
        int n = s.length();
        int i = 0;
        int j = n - 1;
        while (i < j)
        {
            if (!isVowel(s[i]))
            {
                i++;
            }
            else if (!isVowel(s[j]))
            {
                j--;
            }
            else
            {
                swap(s[i], s[j]);
                i++;
                j--;
            }
        }
        return s;
    }
};
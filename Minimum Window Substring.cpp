/*
Minimum Window Substring
Given a string S and a string T, find the minimum window in S which will contain all the characters in T in complexity O(n).

Example:

Input: S = "ADOBECODEBANC", T = "ABC"
Output: "BANC"
Note:

If there is no such window in S that covers all characters in T, return the empty string "".
If there is such window, you are guaranteed that there will always be only one unique minimum window in S.
*/
string minWindow(string str, string pat) {
    if (str.size() < pat.size())
    {
        return "";
    }

    unordered_map<char, int> s; //Hashmap for string elements
    unordered_map<char, int> p; //Hashmap for pattern elements

    for (int i = 0; i < pat.size(); i++)
    {
        p[pat[i]]++;
    }

    int i = 0; //Start index for current window in consideration
    int startIndex = -1;
    int minLen = INT_MAX;
    int c = 0;

    for (int j = 0; j < str.size(); j++)
    {
        s[str[j]]++;

        if (p[str[j]] != 0 and s[str[j]] <= p[str[j]])
        {
            c++;
        }

        if (c == pat.size())
        {
            while (s[str[i]] > p[str[i]] or p[str[i]] == 0)
            {
                if (s[str[i]] > p[str[i]])
                {
                    s[str[i]]--;
                }
                i++;
            }

            int windowSize = j - i + 1;
            if (minLen > windowSize)
            {
                minLen = windowSize;
                startIndex = i;
            }
        }
    }

    if (startIndex == -1)
    {
        return "";
    }

    return str.substr(startIndex, minLen);
}

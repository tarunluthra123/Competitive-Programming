int lengthOfLongestSubstring(string s)
{
    int maxLen = 0;
    int start = 0;
    vector<int> positions(256, -1);
    for (int i = 0; i < s.size(); i++)
    {
        if (positions[s[i]] != -1)
        {
            maxLen = max(maxLen, i - start);
            int j = start;
            for (; j <= positions[s[i]]; j++)
            {
                positions[s[j]] = -1;
            }
            start = j;
        }

        positions[s[i]] = i;
    }

    return max(maxLen, int(s.size()) - start);
}

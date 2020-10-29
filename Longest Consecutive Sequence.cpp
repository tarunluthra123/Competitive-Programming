/*
https://leetcode.com/problems/longest-consecutive-sequence/
Given an unsorted array of integers, find the length of the longest consecutive elements sequence.

Your algorithm should run in O(n) complexity.

Example:

Input: [100, 4, 200, 1, 3, 2]
Output: 4
Explanation: The longest consecutive elements sequence is [1, 2, 3, 4]. Therefore its length is 4.
*/
class Solution {
public:
    int longestConsecutive(vector<int>& v) {
        int n = v.size();
        unordered_set<int> s;
        for (int i = 0; i < n; i++)
        {
            s.insert(v[i]);
        }

        int ans = 0;
        for (int i = 0; i < n; i++)
        {
            if (s.find(v[i] - 1) != s.end())
            {
                continue;
            }
            else
            {
                int x = v[i];
                int c = 0;
                while (s.find(x) != s.end())
                {
                    x++;
                    c++;
                }
                ans = max(ans, c);
            }
        }

        return ans;
    }
};

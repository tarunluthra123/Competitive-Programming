class Solution:
    def lengthOfLongestSubstring(self, s: str) -> int:
        maxLen = 0
        start = 0
        positions = {}
        for i in range(len(s)):
            if s[i] in positions and positions[s[i]] != -1:
                maxLen = max(maxLen, i - start)
                j = start
                while j <= positions[s[i]]:
                    positions[s[j]] = -1
                    j += 1
                start = j
            positions[s[i]] = i

        return max(maxLen, len(s) - start)

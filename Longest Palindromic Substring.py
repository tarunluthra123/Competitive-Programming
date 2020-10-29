class Solution:
    def longestPalindrome(self, s: str) -> str:
        if len(s) == 0:
            return ""
        ans = []
        maxLen = 0
        for i in range(len(s)):
            j = 0
            while i + j < len(s) and i - j >= 0 and s[i + j] == s[i - j]:
                j += 1
            now = j + 1
            # print('i=',i,'j=',j)
            if now > maxLen:
                ans = [i - j + 1, i + j]
                maxLen = now
                # print('updated',i,j,s[i])
            j = 0
            while i + j + 1 < len(s) and i - j >= 0 and s[i + j + 1] == s[i - j]:
                j += 1
            # print('i=',i,'j=',j)
            now = j + 1
            if now >= maxLen:
                ans = [i - j + 1, i + j + 1]
                maxLen = now

        # print(ans)
        res = s[ans[0]:ans[1]]
        return res

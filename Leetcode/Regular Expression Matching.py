class Solution:
    def isMatch(self, s: str, p: str) -> bool:
        if s is None or p is None:
            return False
        dp = [[False]*(len(p)+1) for i in range(len(s)+1)]
        dp[0][0] = True
        # print(len(dp),len(dp[0]))
        for i in range(len(p)):
            if p[i] == '*' and dp[0][i-1]:
                dp[0][i+1] = True

        for i in range(1, len(p)):
            if p[i] == '*' and dp[0][i-1]:
                dp[0][i+1] = True

        for i in range(len(s)):
            for j in range(len(p)):
                if p[j] == '.':
                    dp[i+1][j+1] = dp[i][j]
                if p[j] == s[i]:
                    dp[i+1][j+1] = dp[i][j]
                if p[j] == '*':
                    if p[j-1] != s[i] and p[j-1] != '.':
                        dp[i+1][j+1] = dp[i+1][j-1]
                    else:
                        dp[i+1][j+1] = (dp[i+1][j] or dp[i]
                                        [j+1] or dp[i+1][j-1])

        return dp[len(s)][len(p)]

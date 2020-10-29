class Solution:
    def uniquePaths(self, m: int, n: int) -> int:
        dp = [[0]*n for _ in range(m)]
        dp[0][0]=1
        for i in range(m)[1:]:
            dp[i][0] = dp[i-1][0]
        for j in range(n)[1:]:
            dp[0][j] = dp[0][j-1]
        for i in range(m)[1:]:
            for j in range(n)[1:]:
                dp[i][j] = dp[i-1][j] + dp[i][j-1]
        return dp[m-1][n-1]
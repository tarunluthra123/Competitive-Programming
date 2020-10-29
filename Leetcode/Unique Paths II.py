class Solution:
    def uniquePathsWithObstacles(self, a: List[List[int]]) -> int:
        if len(a) == 0:
            return 0
        r, c = len(a), len(a[0])
        dp = [[0 for j in range(c)] for i in range(r)]
        if a[0][0] != 1:
            dp[0][0] = 1
        for i in range(r):
            for j in range(c):
                if i > 0 and a[i-1][j] == 0:
                    dp[i][j] = dp[i - 1][j]
                if j > 0 and a[i][j - 1] == 0:
                    dp[i][j] += dp[i][j - 1]

        if a[i][j] == 0:
            return dp[i][j]
        else:
            return 0

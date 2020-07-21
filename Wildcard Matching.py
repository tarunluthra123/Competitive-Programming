class Solution:
    def isMatch(self, s: str, p: str) -> bool:
        if s == p:
            return True
        if len(p) == 0:
            return False

        i = 0
        while i < len(p)-1:
            if p[i] == '*' and p[i + 1] == '*':
                j = i+1
                while j < len(p) and p[i] == p[j]:
                    j += 1
                p = p[0:i]+p[j-1:]
            i += 1

        return self.wildcard(s, p)

    def wildcard(self, s: str, p: str) -> bool:
        r = len(s)
        c = len(p)

        dp = [[False] * (c+1) for i in range(r+1)]
        # dp[i][j] denotes if the text till i and pattern till j match

        dp[0][0] = True
        # Base case - Strings of 0 length always match

        # If first character of pattern is * then mark(0, 1) as true since * can be mapped with empty sequence as well
        if p[0] == '*':
            dp[0][1] = True

        i = 0
        while i < c and p[i] == '*':
            dp[i][1] = True
            i += 1

        for i in range(1, r + 1):
            for j in range(1, c + 1):
                if s[i - 1] == p[j - 1]:
                    # If current character of each string matches then mark this as however its previous state was
                    dp[i][j] = dp[i-1][j-1]
                elif p[j-1] == '?':
                    # Since ? can be mapped with all characters, do the same for this as well
                    dp[i][j] = dp[i-1][j-1]
                elif p[j-1] == '*':
                    # Since * can be mapped with all strings, mark current state as OR of both previous states
                    dp[i][j] = dp[i-1][j] or dp[i][j-1]
                else:
                    # Since no matching took place, mark this cell as false
                    dp[i][j] = False

        return dp[r][c]

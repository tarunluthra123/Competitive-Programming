class Solution:
    def numDecodings(self, s: str) -> int:
        if len(s)==0 or s[0]=='0':
            return 0
        self.dp = {}
        ans = self.decode(s)
        return ans
    
    def decode(self, s: str) -> int:
        if len(s)==0:
            return 1
        if len(s) in self.dp:
            return self.dp[len(s)]
        ans = 0
        if s[0]!='0':
            ans = self.decode(s[1:])
        if len(s)>=2 and 10<=int(s[0:2])<=26:
            ans += self.decode(s[2:])
        self.dp[len(s)] = ans
        return ans
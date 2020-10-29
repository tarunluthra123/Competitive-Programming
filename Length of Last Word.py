class Solution:
    def lengthOfLastWord(self, s: str) -> int:
        s = s.strip()
        if len(s)==0:
            return 0
        ans = 0
        for c in reversed(s):
            if c.isspace():
                break
            ans += 1
        return ans
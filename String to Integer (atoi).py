class Solution:
    def myAtoi(self, s: str) -> int:
        s = s.strip()
        if len(s) == 0:
            return 0
        i = 0
        digits = ['0', '1', '2', '3', '4', '5', '6', '7', '8', '9']
        symbols = ['+', '-']
        a = symbols+digits
        if s[0] not in a:
            return 0
        if i >= len(s) or (len(s) == 1 and s[0] in symbols):
            return 0

        negative = False
        if s[i] == '+':
            i += 1
        elif s[i] == '-':
            i += 1
            negative = True
        if not s[i] in digits:
            return 0

        ans = ""

        while i < len(s) and s[i] in digits:
            ans += s[i]
            i += 1

        ans = int(ans)
        if negative:
            ans *= -1
        limit = 1 << 31
        if ans < -limit:
            return -limit
        elif ans > limit-1:
            return limit-1
        return ans

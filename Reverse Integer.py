class Solution:
    def reverse(self, x: int) -> int:
        negative = x < 0
        x = abs(x)
        ans = 0
        while x > 0:
            ans = ans*10 + x % 10
            x //= 10
        if negative:
            ans *= -1
        limit = 1 << 31
        if ans < -limit or ans > limit-1:
            return 0
        return ans

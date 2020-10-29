class Solution:
    def myPow(self, x: float, n: int) -> float:
        if n == 0:
            return 1
        if n == 1:
            return x
        if n < 0:
            x = 1/x
            n = -n
        smallAns = self.myPow(x, n//2)
        smallAns *= smallAns
        if n % 2 == 1:
            return smallAns*x
        return smallAns

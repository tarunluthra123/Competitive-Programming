class Solution:
    def divide(self, dividend: int, divisor: int) -> int:
        neg = (dividend < 0) is not (divisor < 0)
        dividend, divisor, res, temp = abs(dividend), abs(divisor), 0, 0
        for i in range(31, -1, -1):
            if (temp + (divisor << i) <= dividend):
                temp += divisor << i
                res |= 1 << i

        if neg:
            return -res
        if res >= (1 << 31):
            return (1 << 31) - 1
        return res

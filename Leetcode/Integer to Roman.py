class Solution:
    def intToRoman(self, num: int) -> str:
        values = [1000, 900, 500, 400, 100, 90, 50, 40, 10, 9, 5, 4, 1]
        roman = ["M", "CM", "D", "CD", "C", "XC",
                 "L", "XL", "X", "IX", "V", "IV", "I"]
        res = ""
        while num > 0:
            for i in range(len(values)):
                if num >= values[i]:
                    res += roman[i]
                    num -= values[i]
                    break
        return res

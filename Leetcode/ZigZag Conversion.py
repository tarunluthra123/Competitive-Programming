class Solution:
    def convert(self, s: str, numRows: int) -> str:
        if len(s) == 0 or numRows == 1 or numRows >= len(s):
            return s
        x = 2 * numRows - 2
        ans = ""
        for i in range(numRows):
            ans += s[i]
            r = x
            j = i + r

            while j < len(s):
                if r != 0:
                    ans += s[j]
                r = (2 * numRows - 2) - r
                j += r

            x = x - 2
            # print(ans)
        return ans

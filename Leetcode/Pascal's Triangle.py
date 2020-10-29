from math import factorial as f


class Solution(object):
    def generate(self, n):
        """
        :type numRows: int
        :rtype: List[List[int]]
        """
        def nCr(n, r):
            num = f(n)
            den = f(r)*f(n-r)
            return num//den
        res = []
        for i in range(n):
            row = []
            for j in range(i+1):
                row += [nCr(i, j)]
            res += [row]
        return res

from math import factorial as f


class Solution(object):
    def getRow(self, rowIndex):
        """
        :type rowIndex: int
        :rtype: List[int]
        """
        def nCr(n, r):
            num = f(n)
            den = f(r)*f(n-r)
            return num//den
        res = []
        for j in range(rowIndex+1):
            res += [nCr(rowIndex, j)]
        return res

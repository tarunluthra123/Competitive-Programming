class Solution(object):
    def maxProfit(self, prices):
        """
        :type prices: List[int]
        :rtype: int
        """
        h1 = h2 = -(1 << 32)
        r1 = r2 = 0
        for x in prices:
            r2 = max(r2, h2+x)
            h2 = max(h2, r1-x)
            r1 = max(r1, h1+x)
            h1 = max(h1, -x)
        return r2

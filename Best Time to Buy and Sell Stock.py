class Solution(object):
    def maxProfit(self, prices):
        """
        :type prices: List[int]
        :rtype: int
        """
        ans = 0
        if len(prices) == 0:
            return 0
        p = prices[0]
        q = prices[0]
        for x in prices:
            if x < p:
                p = q = x
            if x > q:
                q = x
            ans = max(ans, q-p)
        return ans

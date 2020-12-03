class Solution(object):
    def combinationSum3(self, k, n):
        """
        :type k: int
        :type n: int
        :rtype: List[List[int]]
        """
        res = []
        def rec(start,k,p=[]):
            if k==0 and sum(p)==n:
                res.append(p)
            for i in range(start,10):
                if i+sum(p)<=n:
                    rec(i+1,k-1,p+[i])

        rec(1,k)
        return res
        

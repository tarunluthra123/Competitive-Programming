class Solution:
    def maxSubArray(self, a: List[int]) -> int:
        cs = 0
        ms = 0
        flag = False
        for x in a:
            cs += x
            if cs < 0:
                cs = 0
            ms = max(ms,cs)
            if x>=0:
                flag = True
        if not flag:
            return max(a)
        return ms
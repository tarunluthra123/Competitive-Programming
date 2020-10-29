class Solution:
    def subsetsWithDup(self, nums: List[int]) -> List[List[int]]:
        res = set()
        nums.sort()
        for i in range((1<<len(nums))):
            k,p = 0,[]
            while i>0:
                if i&1:
                    p += [nums[k]]
                k+=1
                i=i>>1
            res.add(tuple(p))
        return res
            
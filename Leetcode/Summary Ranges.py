class Solution(object):
    def summaryRanges(self, nums):
        """
        :type nums: List[int]
        :rtype: List[str]
        """
        res = []
        i = 0
        while i<len(nums):
            j=1
            while i+j<len(nums) and nums[i+j]-nums[i+j-1]==1:
                j+=1
            if j==1:
                res += [str(nums[i])]
            else:
                res += [str(nums[i])+"->"+str(nums[i+j-1])]
            i += j
        return res

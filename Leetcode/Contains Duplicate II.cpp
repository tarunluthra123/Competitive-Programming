class Solution(object):
    def containsNearbyDuplicate(self, nums, k):
        """
        :type nums: List[int]
        :type k: int
        :rtype: bool
        """
        d = {}
        for i in range(len(nums)):
            x = nums[i]
            if x in d:
                prev = d[x]
                if i-prev<=k:
                    return True
            d[x] = i
        return False

        

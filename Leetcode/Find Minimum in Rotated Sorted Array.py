class Solution(object):
    def findMin(self, nums):
        """
        :type nums: List[int]
        :rtype: int
        """
        # return min(nums)
        s,e = 0,len(nums)-1
        while s<e:
            if nums[s]<nums[e]:
                return nums[s]

            mid = (s+e)/2

            if nums[mid]>=nums[s]:
                s=mid+1
            else:
                e=mid

        return nums[s]

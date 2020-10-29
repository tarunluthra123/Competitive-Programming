class Solution(object):
    def moveZeroes(self, nums):
        """
        :type nums: List[int]
        :rtype: None Do not return anything, modify nums in-place instead.
        """
        i = -1
        j = 0

        while j < len(nums):
            if nums[j] != 0:
                i += 1
                nums[i], nums[j] = nums[j], nums[i]
            j += 1

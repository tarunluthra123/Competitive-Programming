class Solution:
    def removeDuplicates(self, nums: List[int]) -> int:
        if len(nums) == 0:
            return 0
        prev = nums[0]
        i = 1
        while i < len(nums):
            if nums[i] == prev:
                nums.pop(i)
                i -= 1
            prev = nums[i]
            i += 1
        return len(nums)

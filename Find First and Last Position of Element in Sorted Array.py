import bisect


class Solution:
    def searchRange(self, nums: List[int], target: int) -> List[int]:
        left, right = bisect.bisect_left(
            nums, target), bisect.bisect_right(nums, target)
        if nums and left < len(nums) and nums[left] == target and right > 0 and nums[right-1] == target:
            return [left, right-1]
        return [-1, -1]

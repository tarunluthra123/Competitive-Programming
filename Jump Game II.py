class Solution:
    def jump(self, nums: List[int]) -> int:
        steps, currentMax, nextMax = 0, 0, 0
        for i in range(len(nums)):
            if i > currentMax:
                steps += 1
                currentMax = nextMax
            nextMax = max(nextMax, i + nums[i])
        return steps

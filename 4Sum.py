class Solution:
    def fourSum(self, nums: List[int], target: int) -> List[List[int]]:
        nums.sort()
        res = set()
        length = len(nums)
        for i in range(length):
            if not (i == 0 or (i > 0 and nums[i] != nums[i-1])):
                continue
            for j in range(i + 1, length):
                start = j+1
                end = len(nums)-1
                while start < end:
                    if nums[i]+nums[j]+nums[start]+nums[end] == target:
                        res.add((nums[i], nums[j], nums[start], nums[end]))
                        while start < end and nums[start] == nums[start+1]:
                            start += 1
                        while start < end and nums[end] == nums[end-1]:
                            end -= 1
                        start += 1
                        end -= 1
                    elif nums[i]+nums[j]+nums[start]+nums[end] > target:
                        end -= 1
                    else:
                        start += 1
        res = list(res)
        return res

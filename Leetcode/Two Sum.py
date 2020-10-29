class Solution:
    def twoSum(self, nums: List[int], target: int) -> List[int]:
        s = {k: v for v, k in enumerate(nums)}
        print(s)
        for i in range(len(nums)):
            x = nums[i]
            y = target - x
            if (y in s) and (s[y] != i):
                return i,s[y]
            
                
    
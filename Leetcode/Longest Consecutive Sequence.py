class Solution(object):
    def longestConsecutive(self, nums):
        """
        :type nums: List[int]
        :rtype: int
        """
        s = set(nums)
        ans = 0
        for x in nums:
            if x-1 not in s:
                now = 0
                while x in s:
                    x += 1
                    now += 1
                ans = max(ans, now)

        return ans

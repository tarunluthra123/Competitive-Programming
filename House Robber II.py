class Solution(object):
    def rob(self, nums):
        """
        :type nums: List[int]
        :rtype: int
        """
        n = len(nums)
        if n == 0:
            return 0
        if n == 1:
            return nums[0]
        dp = [0]*n
        dp[0] = nums[0]
        dp[1] = max(nums[0], nums[1])
        for i in range(2, n-1):
            dp[i] = max(dp[i-2]+nums[i], dp[i-1])

        q1 = max(dp[n-1], dp[n-2])
        q2 = 0

        if n >= 3:
            dp = [0]*n
            dp[1] = nums[1]
            dp[2] = max(nums[1], nums[2])
            for i in range(3, n):
                dp[i] = max(dp[i-2]+nums[i], dp[i-1])

            q2 = dp[n-1]
        return max(q1, q2)

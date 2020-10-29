class Solution:
    def trap(self, height: List[int]) -> int:
        left, right = {}, {}
        n = len(height)
        left[0] = 0
        for i in range(1, n):
            left[i] = max(left[i - 1], height[i-1])
        right[n-1] = 0
        for i in range(n - 2, -1, -1):
            right[i] = max(right[i + 1], height[i+1])
        ans = 0
        for i in range(n):
            ans += max(0, min(left[i], right[i]) - height[i])
        # print(left,right)
        return ans

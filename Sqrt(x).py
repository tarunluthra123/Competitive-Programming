class Solution:
    def mySqrt(self, x: int) -> int:
        if x==1:
            return 1
        s,e = 0, x//2
        ans = 0
        while s<=e:
            mid = (s+e)//2
            if mid*mid <= x:
                ans = mid
                s = mid+1
            else:
                e = mid-1
        return int(ans)
                
        
class Solution:
    def majorityElement(self, nums: List[int]) -> int:
        x,c = 0,0
        for n in nums:
            if n==x:
                c+=1
            else:
                c-=1
            if c<=0:
                x = n
                c = 1
        return x
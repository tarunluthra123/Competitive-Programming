class Solution:
    def sortColors(self, nums: List[int]) -> None:
        """
        Do not return anything, modify nums in-place instead.
        """
        i,j,k = -1,len(nums)-1,0
        while k<=j:
            if nums[k]==0:
                i+=1
                nums[i],nums[k]= nums[k],nums[i]
                k+=1
            elif nums[k]==2:
                nums[j],nums[k] = nums[k],nums[j]
                j-=1
            else:
                k += 1
        
        
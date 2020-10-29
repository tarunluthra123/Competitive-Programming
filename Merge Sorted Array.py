class Solution:
    def merge(self, nums1: List[int], m: int, nums2: List[int], n: int) -> None:
        """
        Do not return anything, modify nums1 in-place instead.
        """
        if n==0:
            return
        i,j = 0,0
        for num in nums1[:m]:
            while j<n and nums2[j]<=num:
                nums1[i] = nums2[j]
                i,j = i+1,j+1
            nums1[i]=num
            i+=1
        # print(nums1,i,j)
        while j<len(nums2):
            nums1[i] = nums2[j]
            i,j = i+1,j+1
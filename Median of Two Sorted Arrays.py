class Solution:
    def findMedianSortedArrays(self, nums1: List[int], nums2: List[int]) -> float:
        a = sorted(nums1 + nums2)
        l = len(a)
        p = l // 2
        if l % 2 == 0:
            return (a[p] + a[p - 1]) / 2
        else:
            return a[p]

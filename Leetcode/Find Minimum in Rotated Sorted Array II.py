class Solution(object):
    def findMin(self, num):
        """
        :type nums: List[int]
        :rtype: int
        """
        s, e = 0, len(num)-1
        while s<e:
            mid = (s+e)//2

            if num[mid] > num[e]:
                s = mid + 1
            elif num[mid] < num[e]:
                e = mid
            else:
                e-=1

        return num[s]

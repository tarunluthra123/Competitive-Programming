class Solution:
    def setZeroes(self, a: List[List[int]]) -> None:
        """
        Do not return anything, modify matrix in-place instead.
        """
        p,q = set(),set()
        for i in range(len(a)):
            for j in range(len(a[i])):
                if a[i][j]==0:
                    p.add(i)
                    q.add(j)
        
        for i in range(len(a)):
            for j in range(len(a[i])):
                if i in p or j in q:
                    a[i][j] = 0
                    
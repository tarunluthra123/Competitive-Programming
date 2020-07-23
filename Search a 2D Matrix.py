class Solution:
    def searchMatrix(self, matrix: List[List[int]], target: int) -> bool:
        if len(matrix)==0:
            return False
        r,c = len(matrix),len(matrix[0])
        i,j = 0, c-1
        while i<r and j>=0:
            if matrix[i][j]==target:
                return True
            elif matrix[i][j] > target:
                j-=1
            else:
                i+=1
                
        return False
        
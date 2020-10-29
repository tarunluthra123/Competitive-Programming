class Solution:
    def generateMatrix(self, n: int) -> List[List[int]]:
        if n == 0:
            return []
        res = [[0 for i in range(n)] for i in range(n)]
        startRow, endRow, startCol, endCol, number = 0, n-1,   0,   n-1, 1
        while number <= (n*n):
            for i in range(startCol, endCol+1):
                res[startRow][i] = number
                number += 1
            startRow += 1

            for i in range(startRow, endRow+1):
                res[i][endCol] = number
                number += 1
            endCol -= 1

            if startRow <= endRow:
                for i in range(endCol, startCol-1, -1):
                    res[endRow][i] = number
                    number += 1
                endRow -= 1

            if startCol <= endCol:
                for i in range(endRow, startRow-1, -1):
                    res[i][startCol] = number
                    number += 1
                startCol += 1

        return res

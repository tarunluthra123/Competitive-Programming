class Solution:
    def spiralOrder(self, a: List[List[int]]) -> List[int]:
        m = len(a)
        if m == 0:
            return []
        n = len(a[0])
        res = []
        startRow, endRow, startCol, endCol = 0, m-1,   0,   n-1
        while startRow <= endRow and startCol <= endCol:
            for i in range(startCol, endCol+1):
                res.append(a[startRow][i])
            startRow += 1

            for i in range(startRow, endRow+1):
                res.append(a[i][endCol])
            endCol -= 1

            if startRow <= endRow:
                for i in range(endCol, startCol-1, -1):
                    res.append(a[endRow][i])
                endRow -= 1

            if startCol <= endCol:
                for i in range(endRow, startRow-1, -1):
                    res.append(a[i][startCol])
                startCol += 1

        return res

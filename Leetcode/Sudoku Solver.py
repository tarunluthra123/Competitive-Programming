class Solution:
    def sudoku(self, mat, i, j):
        n = 9
        if i == n:
            return True

        if j == n:
            return self.sudoku(mat, i + 1, 0)

        if mat[i][j] != ".":
            return self.sudoku(mat, i, j+1)
        else:
            for no in range(1, 10):
                if(self.canPlace(mat, i, j, no)):
                    mat[i][j] = str(no)
                    solveHua = self.sudoku(mat, i, j+1)
                    if solveHua:
                        return True

            mat[i][j] = "."
            return False

    def canPlace(self, mat, x, y, val):
        n = 9
        val = str(val)
        for i in range(n):
            if mat[x][i] == val:
                return False

        for i in range(n):
            if mat[i][y] == val:
                return False

        sx = (x//3)*3
        sy = (y // (n // 3)) * (n // 3)

        for i in range(sx, sx + 3):
            for j in range(sy, sy + (n // 3)):
                if mat[i][j] == val:
                    return False

        return True

    def solveSudoku(self, board: List[List[str]]) -> None:
        """
        Do not return anything, modify board in-place instead.
        """
        self.sudoku(board, 0, 0)

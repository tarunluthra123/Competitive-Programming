class Solution:
    def solveNQueens(self, n: int) -> List[List[str]]:
        self.n = n
        self.DONE = (1 << n) - 1
        self.res = []
        board = [['.' for i in range(n)] for j in range(n)]
        self.solve(0, 0, 0, 0, board)
        # print(self.res)
        return self.res

    def getPosition(self, n):
        ans = 0
        while n > 0:
            ans += 1
            n = n >> 1
        return ans - 1

    def solve(self, rowMask, ld, rd, row, board):
        if rowMask == self.DONE:
            mat = []
            for row in board:
                mat.append("".join(row))
            # print(mat)
            self.res.append(mat)
            return

        safe = self.DONE & (~(rowMask | ld | rd))

        while safe > 0:
            p = safe & (-safe)
            #p will give you the column
            col = self.getPosition(p)
            board[row][col] = 'Q'
            safe = safe - p
            self.solve(rowMask | p, (ld | p) << 1, (rd | p) >> 1, row+1, board)
            board[row][col] = '.'
